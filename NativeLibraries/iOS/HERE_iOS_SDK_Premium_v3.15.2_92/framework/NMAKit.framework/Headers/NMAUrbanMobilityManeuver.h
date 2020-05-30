/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */
@class NMAGeoBoundingBox;
@class NMAGeoCoordinates;
#import "NMAManeuver.h"


/**
 * Defines types of direction for a NMAUrbanMobilityManeuver.
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityManeuverDirection) {
    /** An undefined direction. */
    NMAUrbanMobilityManeuverDirectionUndefined = 0,
    /** Direction forward. */
    NMAUrbanMobilityManeuverDirectionForward,
    /** Direction right. */
    NMAUrbanMobilityManeuverDirectionRight,
    /** Direction left. */
    NMAUrbanMobilityManeuverDirectionLeft,
    /** Direction bear right. */
    NMAUrbanMobilityManeuverDirectionBearRight,
    /** Direction light right. */
    NMAUrbanMobilityManeuverDirectionLightRight,
    /** Direction hard right. */
    NMAUrbanMobilityManeuverDirectionHardRight,
    /** Direction uturn right. */
    NMAUrbanMobilityManeuverDirectionUturnRight,
    /** Direction uturn left. */
    NMAUrbanMobilityManeuverDirectionUturnLeft,
    /** Direction hard left. */
    NMAUrbanMobilityManeuverDirectionHardLeft,
    /** Direction light left. */
    NMAUrbanMobilityManeuverDirectionLightLeft,
    /** Direction bear left. */
    NMAUrbanMobilityManeuverDirectionBearLeft
} DEPRECATED_ATTRIBUTE;


/**
 *
 * Contains all information about walk maneuver, which is a part of journey.
 *
 * IMPORTANT: Urban Mobility routing is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityManeuver : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Gets maneuver direction hint. Can be used to display the appropriate arrow icon for the
 * maneuver.
 * @return `NMAUrbanMobilityManeuverDirection` hint.
 */
@property (nonatomic, readonly) NMAUrbanMobilityManeuverDirection direction;

/**
 * Name of the next road in the route that the maneuver is heading toward.
 * nil if not available.
 *
 * @note  It is localized to the locale of the region.
 * If given language is not supported English version is returned.
 */
@property (nonatomic, readonly, nullable) NSString *nextRoadName;

/**
 * Number of the road (such as A5, B49, etc.) towards which the maneuver is heading.
 * nil if not available.
 *
 * @note  It is localized to the locale of the region.
 * If given language is not supported English version is returned.
 */
@property (nonatomic, readonly, nullable) NSString *nextRoadNumber;

/**
 * Gets verbal description of maneuver.
 *
 * @note  It is localized to the locale of the region.
 * If given language is not supported English version is returned.
 */
@property (nonatomic, readonly, nullable) NSString *instruction;

/**
 * Gets the action for this maneuver. Does not always indicate a direction.
 * @return `NMAManeuverAction` to be taken.
 */
@property (nonatomic, readonly) NMAManeuverAction action;

/**
 * Gets duration - the amount of time in seconds for a single maneuver.
 * @return duration in seconds.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 * The distance from the start of the route to the maneuver, in meters.
 */
@property (nonatomic, readonly) NSUInteger distance;

/**
 * Array of `NMAGeoCoordinates` representing the geometry of this section.
 */
@property (nonatomic, readonly, nullable) NSArray<NMAGeoCoordinates *> *geometry;

/**
 * Gets the `NMAGeoBoundingBox` of the maneuver - the smallest rectangle that contains
 * maneuver geometry.
 * @return `NMAGeoBoundingBox` that contains maneuver geometry.
 */
@property (nonatomic, readonly, nullable) NMAGeoBoundingBox *boundingBox;

@end
