/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>

#import "NMAManeuver.h"
#import "NMATransitManager.h"


/**
 * Styles used to render transit lines on a map.
 */
typedef NS_ENUM(NSUInteger, NMATransitLineStyle) {
    /** Solid line */
    NMATransitLineStyleSolid,
    /** Dotted line */
    NMATransitLineStyleDotted,
    /** Dashed line */
    NMATransitLineStyleDashed,
    /** Undefined */
    NMATransitLineStyleUndefined
};


/**
 * Represents a transit maneuver, which describes a section of a `NMARoute` that
 * involves taking some form of public transport.
 *
 * 
 * Each continuous trip on a transit vehicle is represented by one `NMATransitManeuver`.
 * If the route requires a line change or a transfer to a different transit vehicle, the
 * new transit trip will be represented by another `NMATransitManeuver`.
 */
@interface NMATransitManeuver : NMAManeuver

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The name of the first stop on the transit maneuver.
 *
 * This is the same as the name of the departure stop of the first NMATransitRouteElement.
 *
 * @note The stop name will be nil if unavailable.
 *
 * @note It is localized to the locale of the region.
 */
@property (nonatomic, readonly, nullable) NSString *departureStopName;

/**
 * The name of the last stop on the transit maneuver.
 *
 * This is the same as the name of the arrival stop of the last NMATransitRouteElement.
 *
 * @note The stop name will be nil if unavailable.
 *
 * @note It is localized to the locale of the region.
 */
@property (nonatomic, readonly, nullable) NSString *arrivalStopName;

/**
 * The terminus stop name of the transit line for the NMATransitManeuver.
 *
 * @note Only available in online mode.
 *
 * @note It is localized to the locale of the region.
 */
@property (nonatomic, readonly, nullable) NSString *terminusStopName;

/**
 * The line name for the NMATransitManeuver.
 *
 * For example, "1", "2", "3", "4", "5", ... for New York City Transit-Subway.
 *
 * @note  It is localized to the locale of the region.
 */
@property (nonatomic, readonly, nullable) NSString *lineName;

/**
 * The style in which the line is drawn on typical maps of the local
 * public transit operator.
 *
 * @note NMATransitLineStyleUndefined will be returned when undefined.
 */
@property (nonatomic, readonly) NMATransitLineStyle lineStyle;

/**
 * The primary color of the NMATransitManeuver in the local
 * public transit operator's color scheme.
 *
 * @note Color will be valid if line style is
 *       not undefined otherwise it will be transparent.
 */
@property (nonatomic, readonly, nullable) UIColor *primaryLineColor;

/**
 * The secondary color of the NMATransitManeuver in the local
 * public transit operator's color scheme.
 *
 * @note Color will be valid if line style is
 *       dotted or dashed otherwise it will be transparent.
 */
@property (nonatomic, readonly, nullable) UIColor *secondaryLineColor;

/**
 * The name of the system operating the NMATransitManeuver.
 *
 * For example,  "New York City Transit-Subway".
 *
 * @note It is localized to the locale of the region.
 */
@property (nonatomic, readonly, nullable) NSString *systemOfficialName;

/**
 * The name, in a shorter or abbreviated version if available, of the
 * system operating the NMATransitManeuver.
 *
 * For example, "NYC Transit-Subway".
 *
 * @note It is localized to the locale of the region.
 */
@property (nonatomic, readonly, nullable) NSString *systemShortName;

/**
 * The `NMATransitType` of the transit system offering service
 * for the NMATransitManeuver.
 */
@property (nonatomic, readonly) NMATransitType transitType;

/**
 * The type of the line as a string in the public transit
 * operator's vocabulary.
 *
 * For example, "TRANSIT_CATEGORY_RAIL_CITYMETRO" for `NMATransitMetroRail`.
 *
 * @note It is localized to the locale of the region.
 */
@property (nonatomic, readonly, nullable) NSString *transitTypeName;

/**
 * The estimated transit travel time, in seconds, for the
 * NMATransitManeuver.
 */
@property (nonatomic, readonly) NSTimeInterval transitTravelTime;

@end
