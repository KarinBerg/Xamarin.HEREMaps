/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoBoundingBox;
@class NMAMapDataPrefetcher;
@class NMARoute;


/**
 * Prefetch Status
 */
typedef NS_ENUM(NSUInteger, NMAPrefetchStatus) {
    /** The prefetch request is still in progress */
    NMAPrefetchStatusInProgress,
    /** The prefetch request is successful */
    NMAPrefetchStatusSuccess,
    /** The prefetch request has failed to complete */
    NMAPrefetchStatusFailure,
    /** The prefetch request has been cancelled */
    NMAPrefetchStatusCancelled
};

/**
 * Request Errors
 */
typedef NS_ENUM(NSUInteger, NMAPrefetchRequestError) {
    /** No errors dispatching the request */
    NMAPrefetchRequestErrorNone = 0,
    /** An unknown error has occured submitting the request */
    NMAPrefetchRequestErrorUnknown,
    /** The number of requests is at max capacity */
    NMAPrefetchRequestErrorBusy,
    /** The request is invalid due to invalid parameters */
    NMAPrefetchRequestErrorInvalidParameters,
    /** This feature must be enabled. See license. */
    NMAPrefetchRequestErrorOperationNotAllowed,
    /** The route area size is too big. */
    NMAPrefetchRequestErrorRouteAreaTooBig
};

/**
 * An interface for responding to prefetching events sent by the
 * NMAMapdataPrefetcher.
 */
@protocol NMAMapDataPrefetcherListener<NSObject>
@optional

/**
 * Called when there is a progress update for a prefetch request.
 *
 * @param prefetcher The NMAMapDataPrefetcher singleton.
 * @param progress Amount of work completed for the request represented as a value
 *          in the range of [0..1].
 * @param requestId The id of the prefetch request.
 *
 */
- (void)prefetcher:(nonnull NMAMapDataPrefetcher *)prefetcher
 didUpdateProgress:(float)progress
      forRequestId:(NSInteger)requestId
NS_SWIFT_NAME(prefetcher(_:didUpdateProgress:forRequestId:));
/**
 * Called when there is a status update for a prefetch request.
 *
 * @param prefetcher The NMAMapDataPrefetcher singleton
 * @param status The current status of the reuqest.
 * @param requestId The id of the prefetch request.
 *
 */
- (void)prefetcher:(nonnull NMAMapDataPrefetcher *)prefetcher
   didUpdateStatus:(NMAPrefetchStatus)status
      forRequestId:(NSInteger)requestId
NS_SWIFT_NAME(prefetcher(_:didUpdateStatus:forRequestId:));
/**
 * Called when there is an attempt to purge the cache.
 *
 * @param prefetcher The NMAMapDataPrefetcher singleton.
 * @param success True if the attempt to clear any unused cached map data was successful or
 *                  false otherwise.
 *
 */
- (void)prefetcher:(nonnull NMAMapDataPrefetcher *)prefetcher
     didPurgeCache:(BOOL)success;
/**
 * Called when data size estimation for a fetch is completed.
 *
 * @param prefetcher The NMAMapDataPrefetcher singleton.
 * @param dataSizeKB The estimated size of the fetch request in KB. The size will be 0 on if
 *                      the attempt at estimation was not successful.
 * @param requestId The id of the prefetch request.
 * @param success YES if the attempt to get an estimation was successful.
 *
 */
- (void)prefetcher:(nonnull NMAMapDataPrefetcher *)prefetcher
       didEstimate:(NSInteger)dataSizeKB
      forRequestId:(NSInteger)requestId
       withSuccess:(BOOL)success
NS_SWIFT_NAME(prefetcher(_:didEstimateSize:forRequestId:withSuccess:));
@end


/**
 * `NMAMapDataPrefetcher` is a class is used to prefetch map data for an area of interest.
 * This is similar to the NMAMapLoader except the map data of interest is specified by a
 * NMAGeoBoundingBox or NMARoute, rather than NMAMapPackages. This allows scenarios such
 * as guidance to work in a specific area reliably even though the network might be offline
 * at that time.
 *
 * @note Prefetched map data for a route might be not enough to recreate the route with other
 * parameters (example: if map data was prefetched for car route, creating same route for truck
 * can be failed). NMARoutingErrorGraphDisconnected will be returned.
 *
 */
@interface NMAMapDataPrefetcher : NSObject

/**
 * Returns the NMAMapDataPrefetcher singleton instance.
 *
 * @note Use this method to obtain a NMAMapDataPrefetcher instance.
 *
 * @return shared NMAMapDataPrefetcher instance
 */
+ (nonnull NMAMapDataPrefetcher *)sharedMapDataPrefetcher
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
 * Prefetch the map data for an area bounded by a box. While fetching valid requests,
 * the prefetcher will notify callbacks:
 * onProgressNotification - multiple times.
 * onStatusNotification - during the duration of the fetch with the NMAPrefetchStatusInProgress.
 * onStatusNotification - when the fetch ended with a NMAPrefetchStatus of
 * NMAPrefetchStatusSuccess, NMAPrefetchStatusFailure or NMAPrefetchStatusCancelled
 * See `NMAMapDataPrefetcherListener`.
 *
 * The same data groups as NMAMapLoader are fetched by NMAMapDataPrefetcher.
 * To specify which data groups to fetch:
 * See `NMAMapLoader::selectDataGroup:`
 * See `NMAMapLoader::deselectDataGroup:`
 *
 * @param boundingBox An area to fetch the map data for.
 * @param error an NMAPrefetchRequestError is provided to indicate any failures
 *          submitting a request.
 * @return a request id. For any invalid request, the id will be less than 0.
 */
- (NSInteger)fetchMapDataForBoundingBox:(nonnull NMAGeoBoundingBox *)boundingBox
                                  error:(NMAPrefetchRequestError *_Nullable)error
NS_SWIFT_NAME(fetchMapDataForBoundingBox(_:error:));

/**
 * Prefetch the map data for an area by specifying a route. While fetching valid requests,
 * the prefetcher will notify callbacks:
 * onProgressNotification - multiple times.
 * onStatusNotification - during the duration of the fetch with the NMAPrefetchStatusInProgress.
 * onStatusNotification - when the fetch as ended with a NMAPrefetchStatus of
 * NMAPrefetchStatusSuccess, NMAPrefetchStatusFailure or NMAPrefetchStatusCancelled.
 * See `NMAMapDataPrefetcherListener`.
 *
 * The same data groups as NMAMapLoader are fetched by NMAMapDataPrefetcher.
 * To specify which data groups to fetch:
 * See `NMAMapLoader::selectDataGroup:`
 * See `NMAMapLoader::deselectDataGroup:`
 *
 * @note Not supported for `NMATransitRoute` and `NMAUrbanMobilityRoute` routes.
 * The method will fail with an NMAPrefetchRequestErrorInvalidParameters error.
 *
 * @param route Route to fetch map data around.
 * @param radius Distance around route to fetch map data for in meters. Data is fetched
 *             as a series of circular areas with their centers along the route with
 *             the specified radius. The absolute minimum distance is 500m, otherwise
 *             NMAPrefetchRequestErrorInvalidParameters will be returned.
 * @param error an NMAPrefetchRequestError is provided to indicate any failures
 *          submitting a request.
 * @return a request id. For any invalid request, the id will be less than 0.
 */
- (NSInteger)fetchMapDataForRoute:(nonnull NMARoute *)route
                           radius:(NSUInteger)radius
                            error:(NMAPrefetchRequestError *_Nullable)error
NS_SWIFT_NAME(fetchMapDataForRoute(_:radius:error:));

/**
 * Estimate the data size for fetching the map data for an area bounded by a box. When the data size
 * estimation is completed, the prefetcher will notify the listeners with the size in KB if
 * successful.
 * See `NMAMapDataPrefetcherListener::prefetcher:didEstimate:forRequestId:withSuccess:`.
 *
 * The same data groups as NMAMapLoader are fetched by NMAMapDataPrefetcher and are the same
 * data groups used for the estimation.
 * To specify which data groups to fetch:
 * See `NMAMapLoader::selectDataGroup:`
 * See `NMAMapLoader::deselectDataGroup:`
 *
 * @param boundingBox An area to fetch the map data for.
 * @param error an NMAPrefetchRequestError is provided to indicate any failures
 *          submitting a request.
 * @return a request id. For any invalid request, the id will be less than 0.
 */
- (NSInteger)estimateMapDataSizeForBoundingBox:(nonnull NMAGeoBoundingBox *)boundingBox
                                         error:(NMAPrefetchRequestError *_Nullable)error
NS_SWIFT_NAME(estimateMapDataSizeForBoundingBox(_:error:));

/**
 * Estimate the data size for fetching the map data for an area by specifying a route. When the data
 * size estimation is completed, the prefetcher will notify the listeners with the size in KB if
 * successful.
 * See `NMAMapDataPrefetcherListener::prefetcher:didEstimate:forRequestId:withSuccess:`.
 *
 * The same data groups as NMAMapLoader are fetched by NMAMapDataPrefetcher and are the same
 * data groups used for the estimation.
 * To specify which data groups to fetch:
 * See `NMAMapLoader::selectDataGroup:`
 * See `NMAMapLoader::deselectDataGroup:`
 *
 * @note Not supported for `NMATransitRoute` and `NMAUrbanMobilityRoute` routes.
 * The method will fail with an NMAPrefetchRequestErrorInvalidParameters error.
 *
 * @param route Route to fetch map data around.
 * @param radius Distance around route to fetch map data for in meters. Data is fetched
 *             as a series of circular areas with their centers along the route with
 *             the specified radius. The absolute minimum distance is 500m, otherwise
 *             NMAPrefetchRequestErrorInvalidParameters will be returned.
 * @param error an NMAPrefetchRequestError is provided to indicate any failures
 *          submitting a request.
 * @return a request id. For any invalid request, the id will be less than 0.
 */
- (NSInteger)estimateMapDataSizeForRoute:(nonnull NMARoute *)route
                                  radius:(NSUInteger)radius
                                   error:(NMAPrefetchRequestError *_Nullable)error
NS_SWIFT_NAME(estimateMapDataSizeForRoute(_:radius:error:));

/**
 * Cancel the prefetch request. On cancelling a request, the prefetcher will notify the listeners with
 * the status NMAPrefetchStatusCancelled. See
 * `NMAMapDataPrefetcherListener::prefetcher:didUpdateStatus:forRequestId:`.
 * @param requestId Request the prefetch.
 */
- (void)cancel:(NSInteger)requestId
NS_SWIFT_NAME(cancel(_:));

/**
 * Cancel all pending prefetch requests. On cancelling a request, the prefetcher will notify the
 * listeners with the status NMAPrefetchStatusCancelled. See
 * `NMAMapDataPrefetcherListener::prefetcher:didUpdateStatus:forRequestId:`.
 */
- (void)cancelAll;

/**
 * Clears any cached map data that has been prefetched or downloaded automatically by NMAMapView
 * that is currently not in use. This doesn't include NMAMapPackages downloaded by NMAMapLoader.
 * The NMAMapDataPrefetcher will notify the listeners if clear was successful or not.
 * See `NMAMapDataPrefetcherListener::didPurgeCache:`.
 */
- (void)clearMapDataCache;

/**
 * Add a listener to the prefetcher.
 * @param listener Any events for any requests will be passed to this listeners.
 */
- (void)addListener:(nonnull id<NMAMapDataPrefetcherListener>)listener
NS_SWIFT_NAME(addListener(_:));

/**
 * Remove a listener from the prefetcher.
 * @param listener The progress listener to be removed.
 */
- (void)removeListener:(nonnull id<NMAMapDataPrefetcherListener>)listener
NS_SWIFT_NAME(removeListener(_:));

@end
