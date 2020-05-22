/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARoutingMode.h"

/**
 * The Urban Mobility group provides classes, callbacks, and enumerations
 * that can be used to enable Urban Mobility functionality such as
 * searching for nearby transit stations and requesting departure boards.
 *
 * IMPORTANT: Urban Mobility routing is a Beta feature. The related classes are subject to
 * change without notice.
 */

FOUNDATION_EXPORT const NSUInteger NMARoutingModeDefaultMaximumChanges DEPRECATED_ATTRIBUTE;

/**
 * Urban Mobility Routing types
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityRoutingTypeOption) {
    /**
     * Return all form of routing. Timetable if available,
     * and fall back to simple routing when not available.
     */
    NMAUrbanMobilityRoutingTypeAll NS_SWIFT_NAME(all) = 0,
    /**
     * Return only time table type of results.
     */
    NMAUrbanMobilityRoutingTypeTimeTable NS_SWIFT_NAME(timeTable) = 1,
    /**
     * Return only simple routing results.
     */
    NMAUrbanMobilityRoutingTypeSimpleRouting NS_SWIFT_NAME(simpleRouting) = 2,
    /**
     * Return only real time routing results.
     */
    NMAUrbanMobilityRoutingTypeRealTimeRouting NS_SWIFT_NAME(realTimeRouting) = 3
} DEPRECATED_ATTRIBUTE;

/**
 * Urban Mobility distance units
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_OPTIONS(NSUInteger, NMAUrbanMobilityUnits) {
    /**
     * Use metric units
     */
    NMAUrbanMobilityUnitsMetric NS_SWIFT_NAME(metric),
    /**
     * Use imperial units
     */
    NMAUrbanMobilityUnitsImperial NS_SWIFT_NAME(imperial)
} DEPRECATED_ATTRIBUTE;

/**
 * Urban Mobility Routing Options
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_OPTIONS(NSUInteger, NMAUrbanMobilityOption) {
    /**
     * Use high speed trains.
     */
    NMAUrbanMobilityOptionHighSpeedTrains           = 1 << 0,
    /**
     * Use euro city trains.
     */
    NMAUrbanMobilityOptionIntercityEurocityTrains   = 1 << 1,
    /**
     * Use interregional fast trains.
     */
    NMAUrbanMobilityOptionInterregionalFastTrains   = 1 << 2,
    /**
     * Use regional trains.
     */
    NMAUrbanMobilityOptionRegionalTrains            = 1 << 3,
    /**
     * Use city trains.
     */
    NMAUrbanMobilityOptionCityTrains                = 1 << 4,
    /**
     * Use busses.
     */
    NMAUrbanMobilityOptionBusses                    = 1 << 5,
    /**
     * Use boat or ferries.
     */
    NMAUrbanMobilityOptionBoatFerries               = 1 << 6,
    /**
     * Use metro or subway.
     */
    NMAUrbanMobilityOptionMetroSubway               = 1 << 7,
    /**
     * Use trams.
     */
    NMAUrbanMobilityOptionTram                      = 1 << 8,
    /**
     * Use ordered service as taxi.
     */
    NMAUrbanMobilityOptionOrderedServiceTaxi        = 1 << 9,
    /**
     * Use inclined.
     */
    NMAUrbanMobilityOptionInclinedFunicular         = 1 << 10,
    /**
     * Use aerial cable car.
     */
    NMAUrbanMobilityOptionAerialCableCar            = 1 << 11,
    /**
     * Use rapid bus.
     */
    NMAUrbanMobilityOptionRapidBus                  = 1 << 12,
    /**
     * Use monorail.
     */
    NMAUrbanMobilityOptionMonorail                  = 1 << 13,
    /**
     * Use Airplane.
     */
    NMAUrbanMobilityOptionAirplane                  = 1 << 14,
    /**
     * Undefined.
     */
    NMAUrbanMobilityOptionUndefined                 = 1 << 15,
} DEPRECATED_ATTRIBUTE;


/**
 * Contains options used when calculating an urban mobility route.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMARoutingMode (NMAUrbanMobilityRoutingMode)

/**
 * Urban Mobility routing type.
 */
@property (nonatomic) NMAUrbanMobilityRoutingTypeOption urbanMobilityRoutingType;

/**
 * The OR-ed `NMAUrbanMobilityOption` values for the `NMARoutingMode`.
 *
 * @note The default value is `NMAUrbanMobilityValueNotAvailable`, what means that backend server will use it's default behaviour.
 *
 */
@property (nonatomic) NMAUrbanMobilityOption urbanMobilityRoutingOptions;

/**
 * The walking speed in m/h that the user is having.
 */
@property (nonatomic) NSUInteger walkSpeed;

/**
 * The maximum walking distance to cover on foot to the nearest station.
 */
@property (nonatomic) NSUInteger walkDistance;

/**
 * Specifies if the number of returned connections must be strict, regarding to backward/forward parameters.
 * YES if true, NO otherwise.
 */
@property (nonatomic, getter=isStrict) BOOL strict;

/**
 * The desired arrival time, used for route calculation. If it's nil, departure time is used for route calculation.
 */
@property (nonatomic, nullable) NSDate *arrivalTime;

/**
 * The maximum number of vehicle changes allowed during the trip.
 * For Urban Mobility mode it specifies the maximum number of changes or transfers allowed in a route.
 * Allowed values are: 0 to 6. For values greater than 6, backend server returns error when a route is calculated.
 * The default value is NMARoutingModeDefaultMaximumChanges. If the default value is used, then no limit is applied to number of changes.
 * The backend server decides about the number of changes that are allowed.
 */
@property (nonatomic) NSUInteger maximumChanges;


/**
* Units of measurement used, for example, in guidance instructions. The possible values are:
* • metric
* • imperial
* The default is metric.
*/
@property (nonatomic) NMAUrbanMobilityUnits units;

@end
