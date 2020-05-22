/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMACLE2ResultListener.h"

@class NMACLE2Request;
@class NMACLE2Result;

/**
 * The Custom Location Extensions 2 group provides classes and protocols
 * that support advanced custom location searches.
 */

/**
 * The error domain for NMACLE2Request.
 */
FOUNDATION_EXPORT NSString *const _Nonnull kNMACLE2ErrorDomain;

/**
 * The possible NMACLE2Request error codes.
 */
typedef NS_ENUM(NSUInteger, NMACLE2Error) {
    NMACLE2ErrorNone NS_SWIFT_NAME(none),                                   //Not an error
    NMACLE2ErrorInvalidParameter NS_SWIFT_NAME(invalidParameter),           //Invalid parameter(s) provided
    NMACLE2ErrorInProgress NS_SWIFT_NAME(inProgress),                       //Request already in progress
    NMACLE2ErrorCancelled NS_SWIFT_NAME(cancelled),                         //The request was aborted
    NMACLE2ErrorNetworkCommunication NS_SWIFT_NAME(networkCommunication),   //Network connection error
    NMACLE2ErrorOperationNotAllowed NS_SWIFT_NAME(operationNotAllowed),     //Missing permission or license
    NMACLE2ErrorDataManagerFailed NS_SWIFT_NAME(dataManagerFailed),         //Local storage request failed
    NMACLE2ErrorServerFailed NS_SWIFT_NAME(serverFailed),                   //Error from the server
    NMACLE2ErrorPartialSuccess NS_SWIFT_NAME(partialSuccess),               //Invalid geometries detected
    NMACLE2ErrorUnknown NS_SWIFT_NAME(unknown)
};

/**
 * Specifies the geometry representation in the result.
 *
 * @note When a geometry is uploaded to CLE, they are tiled for fast look-up.
 * This property allows specifying whether the original uploaded geometry is
 * required (NMACLE2GeometryFull), or the if the geometry whithin the tile is
 * sufficient (NMACLE2GeometryLocal), or if no geometry information is needed
 * at all (NMACLE2GeometryNone). The later would be the use-case where it is only
 * interesting to know whether a geometry falls within the specified search, and
 * if results are found, what are its attributes (without retrieving the geometry
 *  information itself).
 */
typedef NS_ENUM(NSUInteger, NMACLE2GeometryType) {
    NMACLE2GeometryFull NS_SWIFT_NAME(full),
    NMACLE2GeometryLocal NS_SWIFT_NAME(local),
    NMACLE2GeometryNone NS_SWIFT_NAME(none)
};

/**
 * Specifies the request mode
 *
 * NMACLE2ConnectivityModeOnline: Local storage will not be considered at all; Default behaviour.
 * NMACLE2ConnectivityModeOffline: Use local storage only
 * NMACLE2ConnectivityModeAutomatic: Attemps online and falls back to offline if failed.
 *
 * @note By default, the offline features are disabled therefore the local storage contains no data.
 * There are two ways to insert geometries in local storage to make them available for offline searches:
 * 1 - Enable caching when performing one or more requests (e.g., using the NMACLE2ProximityRequest).
 * 2 - Download one or more layers.
 */
typedef NS_ENUM(NSUInteger, NMACLE2ConnectivityMode) {
    NMACLE2ConnectivityModeOnline NS_SWIFT_NAME(online),
    NMACLE2ConnectivityModeOffline NS_SWIFT_NAME(offline),
    NMACLE2ConnectivityModeAutomatic NS_SWIFT_NAME(automatic)
};

/**
 * A typedef of a block parameter signature used with `NMARequest::startWithBlock:`.
 *
 * @note The block will be called on the main queue.
 *
 * @param request The search request being completed.
 * @param result The search results. It can be nil if no results are found or an error
 * is encountered.
 * @param error The error if the request failed, or nil if the request was successful.
 */
typedef void (^NMACLE2RequestCompletionBlock)(NMACLE2Request *_Nonnull request, NMACLE2Result *_Nonnull result, NSError *_Nullable error);

/**
 *
 * Represents a base interface for a search request.
 */
@interface NMACLE2Request : NSObject

/**
 * Specifies the geometry type given in the result.
 * If the request was executed in offline mode, this parameter will be ignored.
 * Caching (if enabled) is not performed if geometryType is "local".
 */
@property (readwrite, nonatomic) NMACLE2GeometryType geometryType;

/**
 * Set or get how the query should be performed. See `NMACLE2ConnectivityMode`.
 * If not set, the default is NMACLE2ConnectivityModeOnline
 */
@property (readwrite, nonatomic) NMACLE2ConnectivityMode connectivityMode;

/**
 * Set if received geometries should be stored locally. Default is NO.
 */
@property (readwrite, nonatomic) BOOL cachingEnabled;

/**
 * Specifies the filter(s) to be used for a custom location request. When specified, only
 * geometries where expression evaluates to true will be returned.
 *
 * The string should be a JavaScript expression which will be evaluated for each geometry.
 *
 * An example query is:
 *
 * @code
 * "RATING > 3 &amp;amp;&amp;amp; NAME != 'MyPlace23'" where
 * RATING and NAME are column/field names.
 * @endcode
 */
@property (nullable, readwrite, nonatomic) NSString * query;

/**
 * Invokes an asynchronous query request with a specified listener.
 *
 * @param listener A listener to listen for search results
 * @return `NMACLE2ErrorInvalidParameter` if no listener is passed, nil otherwise
 *
 * See also `startWithBlock:`
 *
 * @note NMARequestErrorOperationNotAllowed indicates access to this operation is denied. Contact
 * your HERE representative for more information.
 */
- (nullable NSError *)startWithListener:(nonnull id<NMACLE2ResultListener>)listener;

/**
 * Invokes an asynchronous query request with a specified block.
 *
 * @param block A block to be executed upon completion of the request (runs by default on main queue).
 * @return `NMACLE2ErrorInvalidParameter` if no listener is passed, nil otherwise
 *
 * See also `NMACLE2RequestCompletionBlock`
 *
 * See also `startWithListener:`
 *
 * @note NMARequestErrorOperationNotAllowed indicates access to this operation is denied. Contact
 * your HERE representative for more information.
 *
 */
- (nullable NSError *)startWithBlock:(NMACLE2RequestCompletionBlock _Nonnull)block;

/**
 * Cancels a previously triggered request execution. Cancelled requests will have their
 * completion handler or listener called with the respective NMACLE2Error.
 */
- (void)cancel;

@end

