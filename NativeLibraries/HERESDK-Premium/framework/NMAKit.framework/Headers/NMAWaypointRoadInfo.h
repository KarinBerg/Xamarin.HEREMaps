/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAWaypoint;
@class NMAGeoCoordinates;


/**
 * Enum representing side of the road according to direction of travel.
 * Used for indicating position's relation to a road.
 */
typedef NS_ENUM(NSUInteger, NMARoadSide) {
    /** Indicates that a position relative to the road is undefined. */
    NMARoadSideUndefined,

    /**
     * Indicates position that is geometrically on the left side, but at a distance that is too
     * short or too long to say for sure.
     */
    NMARoadSideUnknownLeft,

    /**
     * Indicates position that is geometrically on the right side, but at a distance that is too
     * short or too long to say for sure.
     */
    NMARoadSideUnknownRight,

    /** Indicates location on the left side of the road, according to direction of travel. */
    NMARoadSideLeft,

    /** Indicates location on the right side of the road, according to direction of travel. */
    NMARoadSideRight
};


/**
 *
 * Exposes additional information about a route waypoint
 *
 */
@interface NMAWaypointRoadInfo : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Indicates position of a corresponding waypoint relative to the road.
 *
 * See also `NMARoadSide`
 */
@property (nonatomic, readonly) NMARoadSide roadSide;

/**
 * Waypoint's position matched to the route.
 *
 * See also `NMAGeoCoordinates`
 */
@property (nonatomic, readonly, nullable) NMAGeoCoordinates *matchedCoordinates;

@end
