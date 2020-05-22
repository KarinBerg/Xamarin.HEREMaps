/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMATransitAccess;
@class NMATransitLine;
@class NMATransitManager;
@class NMATransitObject;
@class NMATransitStop;
@class NMATransitSystem;


/**
 * Represents values describing the types of transit that an application user
 * might take.
 */
typedef NS_ENUM(NSUInteger, NMATransitType) {
    /** A public bus. */
    NMATransitTypePublicBus,
    /** A tourist bus. */
    NMATransitTypeTouristicBus,
    /** An intercity bus. */
    NMATransitTypeIntercityBus,
    /** An express bus. */
    NMATransitTypeExpressBus,
    /** A metro railway. */
    NMATransitTypeMetroRail,
    /**
     * A regional railway. Usually represents in-city services (such as
     * commuter rail, RER, SBahn) that have a high frequency and lower speed.
     */
    NMATransitTypeLightRail,
    /**
     * A regional train. Usually represents intercity services (such as
     * an Amtrak, DB, SNCF) that are infrequent and travel at high speeds.
     */
    NMATransitTypeRegionalRail,
    /** A regional train. */
    NMATransitTypeRegionalTrain,
    /** An intercity train. */
    NMATransitTypeIntercityTrain,
    /** A high-speed train. */
    NMATransitTypeHighSpeedTrain,
    /** Monorail! */
    NMATransitTypeMonorail,
    /** Aerial transit. */
    NMATransitTypeAerial,
    /** Inclined transit. */
    NMATransitTypeInclined,
    /** A water taxi or ferry. */
    NMATransitTypeWater,
    /** An airline. */
    NMATransitTypeAirline,
    /** An unknown transit type. */
    NMATransitTypeUnknown
};

/**
 * Possible result codes of NMATransitManager upon completion of an operation.
 */
typedef NS_ENUM(NSUInteger, NMATransitManagerError) {
    NMATransitManagerErrorNone,
    NMATransitManagerErrorBusy,
    NMATransitManagerErrorInvalidParameters,
    /** NMATransitManagerErrorNotFound returns when there is no connectivity and no cached data. */
    NMATransitManagerErrorNotFound,
    NMATransitManagerErrorUnknown
};

/**
 * A delegate protocol to be implemented by classes using the NMATransitManager,
 * used to receive the results of information requests.
 *
 * All NMATransitManager requests will result in a didCompleteWithError: callback being
 * sent. In the case of an operation failure, this is the only callback sent. If an
 * operation is successful, the delegate will also receive one of the "didGet..."
 * callbacks, depending on which type of information was requested.
 */
@protocol NMATransitManagerDelegate<NSObject>
@optional
/**
 * Called by NMATransitManager after successfully completing a request for
 * NMATransitAccess information (e.g. requestAccessInfoForId:).
 *
 * @param transitManager The NMATransitManager singleton
 * @param access The NMATransitAccess object requested
 * @param uniqueId The identifying string used to make the original request
 */
- (void)transitManager:(nonnull NMATransitManager *)transitManager didGetAccessInfo:(nonnull NMATransitAccess *)access forId:(nonnull NSString *)uniqueId;

/**
 * Called by NMATransitManager after successfully completing a request for
 * NMATransitLine information (e.g. requestLineInfoForId:).
 *
 * @param transitManager The NMATransitManager singleton
 * @param line The NMATransitLine object requested
 * @param uniqueId The identifying string used to make the original request
 */
- (void)transitManager:(nonnull NMATransitManager *)transitManager didGetLineInfo:(nonnull NMATransitLine *)line forId:(nonnull NSString *)uniqueId;

/**
 * Called by NMATransitManager after successfully completing a request for
 * NMATransitStop information (e.g. requestStopInfoForId:).
 *
 * @param transitManager The NMATransitManager singleton
 * @param stop The NMATransitStop object requested
 * @param uniqueId The identifying string used to make the original request
 */
- (void)transitManager:(nonnull NMATransitManager *)transitManager didGetStopInfo:(nonnull NMATransitStop *)stop forId:(nonnull NSString *)uniqueId;

/**
 * Called by NMATransitManager after successfully completing a request for
 * NMATransitSystem information (e.g. requestSystemInfoForId:).
 *
 * @param transitManager The NMATransitManager singleton
 * @param system The NMATransitSystem object requested
 * @param uniqueId The identifying string used to make the original request
 */
- (void)transitManager:(nonnull NMATransitManager *)transitManager didGetSystemInfo:(nonnull NMATransitSystem *)system forId:(nonnull NSString *)uniqueId;

/**
 * Called upon completion of an NMATransitManager operation, whether or not
 * the operation was successful.
 *
 * @param transitManager The NMATransitManager singleton
 * @param error An error object if the operation failed, otherwise nil
 */
- (void)transitManager:(nonnull NMATransitManager *)transitManager didCompleteWithError:(nullable NSError *)error;

@end


/**
 *
 * A singleton object used to obtain public transit infrastructure information.
 *
 * The NMATransitManager may be used to obtain information about public transit systems,
 * lines, stops, and accesses. This can be done via unique identifying strings
 * or objects obtained from an NMAMapView (via gesture or programmatic
 * object selection).
 *
 * @note The NMATransitManager is a singleton and should only be accessed using the
 * sharedTransitManager class method.
 * @note Requests made through the NMATransitManager are asynchronous. Cocurrent
 * requests are not supported.
 */
@interface NMATransitManager : NSObject

/**
 * Used to access the shared NMATransitManager singleton object.
 */
+ (nonnull NMATransitManager *)sharedTransitManager
NS_SWIFT_NAME(sharedInstance());

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * An object implementing the NMATransitManagerDelegate protocol which will
 * receive the results of information requests.
 */
@property (nonatomic, weak, nullable) id<NMATransitManagerDelegate> delegate;

/**
 * Starts a request for the NMATransitAccess object associated with the given
 * identifying string.
 *
 * @param uniqueId The identifier to use when requesting access.
 */
- (void)requestAccessInfoForId:(nonnull NSString *)uniqueId;

/**
 * Starts a request for the NMATransitLine object associated with the given
 * identifying string.
 *
 * @param uniqueId The identifier to use when requesting a transit line.
 */
- (void)requestLineInfoForId:(nonnull NSString *)uniqueId;

/**
 * Starts a request for the NMATransitStop object associated with the given
 * identifying string.
 *
 * @param uniqueId The identifier to use when requesting transit stop info.
 */
- (void)requestStopInfoForId:(nonnull NSString *)uniqueId;

/**
 * Starts a request for the NMATransitSystem object associated with the given
 * identifying string.
 *
 * @param uniqueId The identifier to use when requesting transit system info.
 */
- (void)requestSystemInfoForId:(nonnull NSString *)uniqueId;

/**
 * Starts a request for the transit information associated with the given
 * NMATransitObject.
 *
 * @note The NMATransitObject may represent a line, access, or stop.
 *
 * See also `NMATransitObject`
 */
- (void)requestInfoForObject:(nonnull NMATransitObject *)object
NS_SWIFT_NAME(requestInfo(forObject:));

@end
