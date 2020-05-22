/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;
@class NMAFTCRManeuver;
@class NMAFTCRRouteLink;


/**
 * A constant used to indicate the whole route should be used in route leg selection.
 */
FOUNDATION_EXPORT const NSInteger NMAFTCRRouteSublegWhole;

/**
 * Represents a distinct fleet telematics custom path connecting two or more waypoints
 * `NMAGeoCoordinates`. The `NMAFTCRRoute` consists of a list of maneuvers and route links.
 *
 * IMPORTANT: Fleet Telematics Custom Route is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * See also `NMAFTCRRouter`.
 */
@interface NMAFTCRRoute : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Smallest `NMAGeoBoundingBox` that contains the entire route.
 */
@property (nonatomic, readonly, strong, nullable) NMAGeoBoundingBox *boundingBox;

/**
 * The `NSArray` of `NMAGeoCoordinates` represents the geometry of the `NMAFTCRRoute`. The geometry
 * is a returned as an array of `NMAGeoCoordinates` that can be used to create a polyline.
 */
@property (nonatomic, readonly, strong, nullable) NSArray<NMAGeoCoordinates *> *geometry;

/**
 * Array of all maneuvers that travelers will encounter along the route.
 */
@property (nonatomic, readonly, strong, nullable) NSArray<NMAFTCRManeuver *> *maneuvers;

/**
 * Array of all links in the route.
 */
@property (nonatomic, readonly, strong, nullable) NSArray<NMAFTCRRouteLink *> *routeLinks;

/**
 * Estimated total travel distance for the route, in meters.
 */
@property (nonatomic, readonly) NSUInteger length;

/**
 * Estimated base time to the final destination, considering transport mode but not traffic
 * conditions.
 */
@property (nonatomic, readonly) NSUInteger baseTime;

/**
 * Estimated total travel time in seconds optionally considering traffic depending on
 * the request parameters.
 */
@property (nonatomic, readonly) NSUInteger travelTime;

/**
 * Estimated traffic time to the final destination, considering traffic and transport mode.
 */
@property (nonatomic, readonly) NSUInteger trafficTime;

@end
