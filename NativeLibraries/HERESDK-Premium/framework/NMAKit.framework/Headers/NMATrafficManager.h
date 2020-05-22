/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;
@class NMARoute;
@class NMARouteElement;
@class NMATrafficEvent;


/**
 * Error codes indicating the result of a traffic event request.
 */
typedef NS_ENUM(NSInteger, NMATrafficRequestError) {
    /** No error. */
    NMATrafficRequestErrorNone,
    /** Invalid parameters were given to the request, e.g. a nil route. */
    NMATrafficRequestErrorInvalidParameters,
    /** The traffic request operation cannot be performed at this time. */
    NMATrafficRequestErrorInvalidOperation,
    /** An unknown error occurred. */
    NMATrafficRequestErrorUnknown
};

/**
 * A completion block used to handle the result of a traffic event request.
 *
 * @param events An NSArray of NMATrafficEvent objects
 * @param error NMATrafficRequestErrorNone if the request was successful, otherwise
 *              an error code indicating the nature of the failure.
 */
typedef void (^NMATrafficCompletionBlock)(NSArray<NMATrafficEvent *> * _Nullable events, NMATrafficRequestError error);

/**
 * An interface for responding to traffic events sent by the
 * NMATrafficManager.
 */
@protocol NMATrafficManagerObserver<NSObject>

@required

/**
 * Called when traffic data request is finished.
 *
 * @note This callback is not invoked if the app moves into the background after
 * the traffic request is issued. The callback won't be invoked when the app moves
 * back to the foreground, either. In that case, issue another traffic request
 * to get the callback to notify that there is up-to-date traffic info.
  */
- (void)trafficDataDidFinish;

@end


/**
 * Manages traffic services for the NMA SDK.
 *
 * By default, new traffic is automatically requested each time the map is moved (such as by
 * panning, zooming, or with map movement during navigation). If the map is not moved, new traffic
 * will be requested at a rate equal to the value set using the setRefreshInterval
 * method.
 *
 * This is a singleton class and thus should never be retained, released, or
 * instantiated. The singleton instance is accessed via the
 * sharedTrafficManager method.
 */
@interface NMATrafficManager : NSObject

/**
 * Returns the NMATrafficManager singleton instance.
 *
 * @note Use this method to obtain a NMATrafficManager instance. Do not call
 * init directly.
 *
 * @return shared NMATrafficManager instance
 */
+ (nonnull NMATrafficManager *)sharedTrafficManager
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
 * Sets the interval at which traffic data is refreshed.
 *
 * This method MUST be called before the HERE SDK uses any traffic in the current app session - e.g.
 * before sharedTrafficManager is called, before traffic is enabled on an NMAMapView and before routing
 * with traffic is performed. If this method is called too late then NO will be returned.
 *
 * Traffic refresh interval defaults to a value determined by the HERE traffic servers.
 * This is typically every 60 seconds.
 *
 * @param refreshInterval the refresh interval in seconds. Must be within the range 60..300.
 * @return YES if the interval was set successfully, NO if traffic is already initialized or if
 * refreshInterval is outside the valid range.
 *
 * @note Refresh interval not applicable when traffic is initialized in manual mode -
 * e.g. when calling [[NMATrafficManager sharedTrafficManager] disableTrafficAutoUpdate];
 */
+ (BOOL)setRefreshInterval:(NSTimeInterval)refreshInterval;

/**
 * Disables traffic automatic updates. It is enabled by default.
 *
 * This method MUST be called before the HERE SDK uses any traffic in the current app session - e.g.
 * before traffic is enabled on an NMAMapView or before routing with traffic is performed.
 * If this method is called too late then NO will be returned.
 *
 * @note Once traffic engine starts with either auto or manual, user can not change it back.
 */
- (BOOL)disableTrafficAutoUpdate;

/**
 * Indicates whether traffic automatic updates are enabled. Default is YES.
 */
- (BOOL)isTrafficAutoUpdateEnabled;

/**
 * Add a NMATrafficManagerObserver
 *
 * @param observer to be added
 */
- (void)addObserver:(nonnull id<NMATrafficManagerObserver>)observer
NS_SWIFT_NAME(add(observer:));

/**
 * Remove a NMATrafficManagerObserver
 *
 * @param observer to be removed
 */
- (void)removeObserver:(nonnull id<NMATrafficManagerObserver>)observer
NS_SWIFT_NAME(remove(observer:));

/**
 * Request traffic information for given route with a default radius (5km) around each waypoint.
 *
 * This method downloads the latest traffic information available along the specified
 * route, so a data connection is required. Once downloaded, the traffic information
 * can be viewed on a map or individual traffic events can be retrieved via the
 * getTrafficEventsOnRoute:withCompletion and getTrafficEventsOnRouteElements:withCompletion
 * methods.
 *
 * This method returns nil if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @param route The route on which to query traffic events.
 * @return requestId A request identifier if traffic is successfully requested,
 *                   nil if the request fails.
 *
 * @note Traffic requests may fail if too many are made in a short period of time.
 */
- (nullable NSNumber *)requestTrafficOnRoute:(nonnull NMARoute *)route;

/**
 * Request traffic information for given route and radius around each waypoint.
 * Using a radius greater than 10km can impact performance.
 *
 * This method downloads the latest traffic information available along the specified
 * route, so a data connection is required. Once downloaded, the traffic information
 * can be viewed on a map or individual traffic events can be retrieved via the
 * getTrafficEventsOnRoute:withCompletion and getTrafficEventsOnRouteElements:withCompletion
 * methods.
 *
 * This method returns nil if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @param route The route on which to query traffic events.
 * @param radius Distance (in km) of the request radius.
 * @return requestId A request identifier if traffic is successfully requested,
 *                   nil if the request fails.
 *
 * @note Traffic requests may fail if too many are made in a short period of time.
 */
- (nullable NSNumber *)requestTrafficOnRoute:(nonnull NMARoute *)route radius:(NSUInteger)radius;

/**
 * Request traffic with given center coordinates and the default radius (5km).
 *
 * This method returns nil if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @param coordinates used as to query traffic events.
 * @return requestId if traffic is successfully requested, nil if it fails.
 *
 * @note This could fail if this is called too frequently.
 */
- (nullable NSNumber *)requestTrafficAtGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates;

/**
 * Request traffic with given center coordinates and radius.
 * Using a radius greater than 10km can impact performance
 *
 * This method returns nil if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @param coordinates used to query traffic events.
 * @param radius of the request (in km).
 * @return requestId if traffic is successfully requested, nil if it fails.
 *
 * @note This could fail if this is called too frequently.
 */
- (nullable NSNumber *)requestTrafficAtGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates
                                               radius:(NSUInteger)radius;

/**
 * Cancel a traffic request.
 *
 * @param requestId id of the traffic request.
 */
- (void)cancelRequest:(nonnull NSNumber *)requestId;

/**
 * Retrieve the traffic events on a given route.
 *
 * This method retrieves traffic events for a route that have been previously
 * downloaded, for example by calling requestTrafficOnRoute or displaying the
 * traffic on a map.
 *
 * The results are delivered asynchronously via an NMATrafficCompletionBlock.
 * The block will contain a list of NMATrafficEvent objects if the request was
 * successful, or a nil array and an NMATrafficRequestError code if the request
 * failed.
 *
 * For example:
 * @code
 *  [[NMATrafficManager sharedTrafficManager] requestTrafficOnRoute:myRoute];
 *
 *  (...wait for the trafficDataDidFinish method of NMATrafficManagerObserver)
 *
 *  - (void)trafficDataDidFinish {
 *      [[NMATrafficManager sharedTrafficManager] getTrafficEventsOnRoute:myRoute
 *          withCompletion: ^(NSArray *eventList, NMATrafficRequestError error) {
 *              if (error == NMATrafficRequestErrorNone) {
 *                  for (NMATrafficEvent *event in eventList) {
 *                      // do something with the traffic event
 *                  }
 *              }
 *          }];
 * }
 * @endcode
 */
- (void)getTrafficEventsOnRoute:(nonnull NMARoute *)route
                 withCompletion:(nonnull NMATrafficCompletionBlock)completionBlock
NS_SWIFT_NAME(getTrafficEvents(onRoute:withCompletion:));

/**
 * Retrieve the traffic events for a given list of route elements.
 *
 * The results are delivered asynchronously via an NMATrafficCompletionBlock.
 * The block will contain a list of NMATrafficEvent objects if the request was
 * successful, or a nil array and an NMATrafficRequestError code if the request
 * failed.
 *
 * See also `getTrafficEventsOnRoute:withCompletion:`
 */
- (void)getTrafficEventsOnRouteElements:(nonnull NSArray<NMARouteElement*> *)routeElements
                         withCompletion:(nonnull NMATrafficCompletionBlock)completionBlock
NS_SWIFT_NAME(getTrafficEvents(onRouteElements:withCompletion:));

@end
