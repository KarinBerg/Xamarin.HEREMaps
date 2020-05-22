/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARoutingError.h"

@class NMAVenue3dBaseLocation;
@class NMAVenue3dRouteSection;


/**
 * Defines a location type in indoor routing.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dRoutingError) {
    /**
     * No Error
     */
    NMAVenue3dRoutingErrorNoError,

    /**
     * Problem with arguments
     */
    NMAVenue3dRoutingErrorArguments,

    /**
     * Internal problem in HereSDK or data problem
     */
    NMAVenue3dRoutingErrorInternal,

    /**
     * Problem with core map routing
     */
    NMAVenue3dRoutingErrorCoreMap,

    /**
     * Unknown problem
     */
    NMAVenue3dRoutingErrorUnknown,
};


/**
 *
 * Describes route from start to end point. The route is split into one or more
 * route sections.
 *
 * See also `NMAVenue3dRoutingController`
 */
@interface NMAVenue3dCombinedRoute : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The array of NMAVenue3dRouteSection objects for this route.
 *
 * This information can be used to check type of turn-by-turn information available for each route
 * section of the combined route.
 *
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAVenue3dRouteSection *> *routeSections;

/**
 * Returns @c YES if the returned route does no use any accessors set to be avoided
 * in NMAVenue3dRouteOptions.
 *
 * In certain cases no route can be created that satisfies all route options when it comes
 * to use of elevators, escalators, stairs and ramps. If any of these are set to be
 * avoided, this methdod can be used to check if the calculated route still uses
 * any of these accessors.
 */
- (BOOL)conformsConnectorOptions;

/**
 * Returns @c YES if the returned route for every outdoor section except to/from parking,
 * is the mode user has requested.
 *
 * In certain cases pedestrian mode is preferred over drive mode when distance to/from street is
 * greater than the direct walking distance and drive distance is less than a certain threshold
 * (ex. 2m).
 * This method can be used to check if any segment is of pedestrian type in drive mode.
 */
- (BOOL)conformsModeOptions;

/**
 * Returns NMAVenue3dRoutingError indicating route computation result.
 */
- (NMAVenue3dRoutingError)getError
NS_SWIFT_NAME(error());

 /**
 * Returns NMARoutingError, indicating inner core map error.
 * This function should be used only when the method NMAVenue3dCombinedRoute::getError
 * returns the error code NMAVenue3dRoutingErrorCoreMap.
 */
- (NMARoutingError)getCoreMapError
NS_SWIFT_NAME(coreMapError());

/**
 * Returns a NMAVenue3dBaseLocation associated with start point of the route.
 */
- (nonnull NMAVenue3dBaseLocation *)getStart
NS_SWIFT_NAME(start());

/**
 * Returns a NMAVenue3dBaseLocation associated with end point of the route.
 */
- (nonnull NMAVenue3dBaseLocation *)getEnd
NS_SWIFT_NAME(end());

/**
 * Returns the array of NMAVenue3dBaseLocation objects associated with waypoints on the route
 * including start and end points.
 */
- (nonnull NSArray<NMAVenue3dBaseLocation *> *)getWaypoints
NS_SWIFT_NAME(waypoints());

/**
 * Returns the length of the route in meters.
 */
- (NSInteger)getLength
NS_SWIFT_NAME(length());

@end
