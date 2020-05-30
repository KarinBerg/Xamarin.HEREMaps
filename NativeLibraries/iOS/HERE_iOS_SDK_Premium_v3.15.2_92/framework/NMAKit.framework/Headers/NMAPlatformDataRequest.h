/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@protocol NMAPlatformDataRequestListener;
@class NMAPlatformDataRequest;
@class NMAPlatformDataResult;
@class NMAGeoBoundingBox;
@class NMARoute;


/**
 * The error domain for NMAPlatformDataRequest errors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull kNMAPlatformDataRequestErrorDomain;

/**
 * Defines the possible errors when performing a PDE request.
 */
typedef NS_ENUM(NSUInteger, NMAPlatformDataRequestError) {
    /** Parameters passed to the PDE API are not valid. */
    NMAPlatformDataRequestErrorInvalidParameters = 0,
    /**
     * Access to the PDE API is denied. Contact your HERE
     *         representative for more information. */
    NMAPlatformDataRequestErrorNoPermission = 1,
    /** Connection problem occurred. */
    NMAPlatformDataRequestErrorConnectionError = 2,
    /** Server reported error. */
    NMAPlatformDataRequestErrorServerError = 3
};

/**
 * A completion block used to handle the result of a platform data request.
 *
 * @param request The request object which started the data retrieval.
 * @param result The data retrieved.
 * @param error If an error occurs, the NSError object contains data on it and otherwise
 *              it is nil.
 */
typedef void (^NMAPlatformDataRequestCompletionBlock)(NMAPlatformDataRequest * _Nonnull request,
                                                      NMAPlatformDataResult * _Nonnull result,
                                                      NSError* _Nullable error);

/**
 * Represents an event listener that reports information about query
 * progress changes and query completion.
 *
 * Methods of this protocol are called on the main queue.
 */
@protocol NMAPlatformDataRequestListener<NSObject>

@required

/**
 * A callback method used to pass the result of a platform data request.
 *
 * @param request The request object which started the data retrieval.
 * @param result The result returned.
 * @param error If an error occurs, the NSError object contains data on it and otherwise
 *              it is nil.
 */
      - (void)request:(nonnull NMAPlatformDataRequest *)request
didCompleteWithResult:(nonnull NMAPlatformDataResult *)result
                error:(nullable NSError *)error;

@end


/**
 * Runs the data requests with the specified
 * parameters.
 */
@interface NMAPlatformDataRequest : NSObject

/**
 * Do not use.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Creates a data request with the specified layers and GeoBounding box.
 *
 * @param layers The layers to search for inside the specified GeoBoundingBox.
 * @param geoBoundingBox The GeoBoundingBox to be searched for the layers specifed.
 *
 * @return If the parameters are valid, an NMAPlatformDataRequest object configured with
 *         the parameters and nil otherwise.
 */
- (nullable instancetype)initWithLayers:(nonnull NSSet<NSString *> *)layers geoBoundingBox:(nonnull NMAGeoBoundingBox *)geoBoundingBox;

/**
 * Creates a data request with the specified layers and permanent link ids.
 *
 * @param layers The layers from which the data should be fetched, this request works only for road geometry layers.
 * @param linkIds The permanent link ids to be searched in the layers specifed.
 *
 * @return If the parameters are valid, an NMAPlatformDataRequest object configured with
 *         the parameters and nil otherwise.
 */
- (nullable instancetype)initWithLayers:(nonnull NSSet<NSString *> *)layers linkIds:(nonnull NSSet<NSNumber *> *)linkIds;

/**
 * Creates a data request with the specified static layer. Note that a static layer
 * doesn't require any bounding box or link ids to collect data.
 *
 * @param layer The name of the static layer.
 *
 * @return If the parameter is valid, an NMAPlatformDataRequest object configured with
 *         the parameter and nil otherwise.
 */
- (nullable instancetype)initWithStaticLayer:(nonnull NSString *)layer;

/**
 * Invokes the data request with the specified listener.
 *
 * @param requestListener A listener to listen for the data results.
 *
 * See also `startWithBlock:`
 */
- (void)startWithListener:(nonnull id<NMAPlatformDataRequestListener>)requestListener;

/**
 * Invokes the data request with the block.
 *
 * @param block A block to run when the data received.
 *
 * See also `NMAPlatformDataRequestCompletionBlock`
 *
 * See also `startWithListener:`
 */
- (void)startWithBlock:(nonnull NMAPlatformDataRequestCompletionBlock)block;

@end
