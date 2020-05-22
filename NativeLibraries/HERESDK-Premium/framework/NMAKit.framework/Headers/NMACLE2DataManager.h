/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMACLE2OperationResult;

@class NMACLE2Task<__covariant ResultType>;
@class NMACLE2Geometry;
@class NMACLE2LayerMetadata;


/**
 * Indicates type of data operation that can be performed on CLE2 data.
 */
typedef NS_ENUM(NSUInteger, NMACLE2OperationType) {
    /** Indicates an operation that creates new data. */
    NMACLE2OperationTypeCreate,

    /** Indicates an operation that updates existing data. */
    NMACLE2OperationTypeUpdate,

    /** Indicates an operation that deletes existing data. */
    NMACLE2OperationTypeDelete
};

/**
 * Used to make distinction between local storage and CLE service (server).
 */
typedef NS_ENUM(NSUInteger, NMACLE2StorageType) {
    /** Indicates local storage. */
    NMACLE2StorageTypeLocal,

    /** Indicates storage on remote CLE service. */
    NMACLE2StorageTypeRemote,
};

/**
 * This class is responsible for managing layer data for CLE2 offline use.
 *
 * To download a full layer, use downloadLayerTask.
 * To store a subset of geometries, create a `NMACLE2Request` and set its
 * cachingEnabled property to true.
 * Multiple layers are supported. To download another layer, simply use the
 * downloadLayerTask with the next layer to be downloaded.
 *
 * @note NMACLE2DataManager is a singleton which must be obtained using the
 * sharedManager method.
 */
@interface NMACLE2DataManager : NSObject

/**
 * Returns the `NMACLE2DataManager` singleton instance.
 *
 * This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @note Use this method to obtain a `NMACLE2DataManager` instance. Do not call
 * init directly.
 *
 * @return shared `NMACLE2DataManager` instance.
 */
+ (nullable instancetype)sharedManager NS_SWIFT_NAME(sharedInstance());

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)new NS_UNAVAILABLE;

#pragma mark Interacting with the CLE2 service

/**
 * Creates a task to download a new layer from the service to local storage.
 * When started, this operation will check if locally stored layer exists and if it's out of
 * date before downloading data from the service. As such, no unnecessary download will take place
 * if local data is up to date with the service.
 *
 * Upon success, all data stored locally for the specified layer are the same as on the server
 * at the time of download.
 *
 * @param layerId The od of a layer to download.
 * @return NMACLE2Task A cancellable task object representing this operation.
 */
- (nonnull NMACLE2Task<NMACLE2OperationResult *> *)downloadLayerTask:(nonnull NSString *)layerId;

/**
 * Creates a task for uploading a new layer to the server.
 *
 * @param layerId The respective layer name.
 * @param geometriesArray The geometries of the layer.
 * @return NMACLE2Task A cancellable operation.
 */
- (nonnull NMACLE2Task<NMACLE2OperationResult *> *)uploadLayerTask:(nonnull NSString *)layerId
                                                    withGeometries:(nonnull NSArray<NMACLE2Geometry *> *)geometriesArray;

/**
 * Creates a task to either create, remove or update geometry in a layer.
 *
 * @note In case of remote storage, the specified layer needs to exist. To create a new layer
 *       on remote CLE service, use uploadLayerTask.
 * @note In case on local storage, create operation (NMACLE2OperationTypeCreate) will cause new
 *       layer to be created in local storage if it does not already exist.
 *
 * @param operationType Type of operation to perform.
 * @param layerId Id of layer to operate on.
 * @param geometriesArray Data to use for operation, ie. new geometries to be inserted.
 * @return NMACLE2Task A cancellable task object representing this operation.
 */
- (nonnull NMACLE2Task<NMACLE2OperationResult *> *)geometryTask:(NMACLE2OperationType)operationType
                                                        onLayer:(nonnull NSString *)layerId
                                                 withGeometries:(nonnull NSArray<NMACLE2Geometry *> *)geometriesArray
                                                      inStorage:(NMACLE2StorageType)storage;

/**
 * Creates a task for listing all CLE layers stored locally or remotely in the service, along with
 * their metadata. The result is a dictionary where layer ID is key and metadata contains the information
 * of the respective layer.
 *
 * @param storageArea Indicates whether the operation affects local storage or data stored in CLE service.
 * @return NMACLE2Task A cancellable task object representing this operation.
 */
- (nonnull NMACLE2Task<NSDictionary<NSString *, NMACLE2LayerMetadata *> *> *)listLayersTaskInStorage:(NMACLE2StorageType)storageArea;

/**
 * Creates a task that deletes specified layers.
 *
 * @note This will delete all geometries contained in the specified layer(s).
 */
- (nonnull NMACLE2Task<NMACLE2OperationResult *> *)deleteLayersTask:(nonnull NSArray<NSString *> *)layerIds
                                                        fromStorage:(NMACLE2StorageType)storageType;

/**
 * Creates a task that deletes all locally stored data.
 */
- (nonnull NMACLE2Task<NMACLE2OperationResult *> *)purgeLocalStorageTask;

/**
 * Creates a task for retrieving all geometries locally stored in specified layers.
 *
 *  @param layerIds The list of layer ids to be queried.
 */
- (nonnull NMACLE2Task<NSMutableArray<NMACLE2Geometry *> *> *)fetchLocalLayersTask:(nonnull NSArray<NSString *> *)layerIds;

/**
 * Retrieves the total number of geometries stored locally.
 *
 * Includes geometries that were cached when a request is made with cacheEnabled
 * plus all geometries downloaded with downloadLayerTask.
 *
 * @param error Reference error object to get the error if any.
 *
 * @note The return value is nil the operation failed; See `NMACLE2Request` for possible
 * error codes (`NMACLE2Error`).
 *
 */
- (nullable NSNumber *)numberOfStoredGeometriesOnError:(NSError *_Nullable *_Nullable)error
NS_SWIFT_NAME(numberOfStoredGeometries());

/**
 * Retrieves the total number of geometries stored locally in a specific layer.
 *
 * Includes geometries that were cached when a request is made with cacheEnabled
 * plus all geometries downloaded with downloadLayerTask.
 *
 * @param layerId The layer id to be queried.
 * @param error Reference error object to get the error if any.
 *
 * @note The return value is nil the operation failed; See `NMACLE2Request` for possible
 * error codes (`NMACLE2Error`).
 *
 */
- (nullable NSNumber *)numberOfStoredGeometriesinLayer:(nonnull NSString *)layerId
                                               onError:(NSError *_Nullable *_Nonnull)error;

@end
