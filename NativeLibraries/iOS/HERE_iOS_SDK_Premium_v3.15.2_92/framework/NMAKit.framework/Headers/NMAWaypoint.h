/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>

@class NMAGeoCoordinates;
@class NMAWaypointRoadInfo;


/**
 * Waypoint types
 */
typedef NS_ENUM(NSUInteger, NMAWaypointType) {
    /**
     * A maneuver is generated for a STOP waypoint. After the
     * STOP waypoint, route is allowed to continue in the
     * opposite direction, i.e. to turn back.
     *
     * During Guidance, "You have reached your stopover" will
     * be announced if supported by the selected voice skin.
     * Furthermore, this will trigger the following methods inside
     * the NMANavigationManagerDelegate:
     * NMANavigationManagerDelegate::navigationManager:didReachStopover and
     * NMANavigationManagerDelegate::navigationManager:hasCurrentManeuver:nextManeuver.
     *
     * The first and the last waypoint to be used for route
     * calculation must be of NMAStopWaypoint type.
     */
    NMAStopWaypoint,

    /**
     * No maneuver is generated for a pass-through waypoint. After the
     * pass-through waypoint, route will continue in the same direction
     * as when it's approached.
     *
     * Pass-through waypoints will "force" the route to pass through them,
     * but they will not cause any guidance, announcement or
     * maneuvers.
     *
     * Pass-through waypoints are not considered during Guidance triggered
     * re-routing nor do they trigger any methods upon arrival at
     * the waypoint.
     *
     * This is only supported by NMATransportModeCar. It's ignored
     * for other transport modes.
     */
    NMAViaWaypoint
};

/**
 * Specify waypoint direction together with identifier to enforce some direction.
 *
 * See also `NMAWaypoint::course`.
 */
typedef NS_ENUM( NSUInteger, NMAWaypointDirection) {
    NMAWaypointDirectionAny, /// Do not enforce direction, pick any
    NMAWaypointDirectionPositive, /// Enforce positive direction
    NMAWaypointDirectionNegative /// Enforce negative direction
};

/**
 * Indicates unknown waypoint course value.
 */
FOUNDATION_EXPORT CGFloat const NMAUnknownWaypointCourse;


/**
 *
 * Waypoints define a route's stopovers, including its start point it's
 * destination point and any points in between.
 *
 * Each waypoint represents a position along an `NMARoute`, this includes:
 *
 * 1. The original (input) coordinates specified as part of a search request
 *
 * 2. The navigable (input) coordinates representing the coordinates on the road
 */
@interface NMAWaypoint : NSObject

/**
 * Initializes an NMAWaypoint instance of type NMAStopWaypoint with the specified coordinates.
 *
 * @param position Coordinates of the waypoint, must not be nil.
 * @return NMAWaypoint instance.
 */
- (nonnull instancetype)initWithGeoCoordinates:(nonnull NMAGeoCoordinates *)position;

/**
 * Initializes an NMAWaypoint instance with the specified geocoordinates and type.
 *
 * @param position Coordinates of the waypoint, must not be nil.
 * @param type Waypoint type.
 * @return NMAWaypoint instance.
 */
- (nonnull instancetype)initWithGeoCoordinates:(nonnull NMAGeoCoordinates *)position
                                  waypointType:(NMAWaypointType)type;

/**
 * Initializes an NMAWaypoint instance with the specified geocoordinates and type.
 *
 * @param position Coordinates of the waypoint, must not be nil.
 * @param type Waypoint type.
 * @return NMAWaypoint instance.
 */
- (nonnull instancetype)initWithGeoCoordinates:(nonnull NMAGeoCoordinates *)position
                                    identifier:(nonnull NSString *)uniqueId
                             waypointDirection:(NMAWaypointDirection)direction
                                  waypointType:(NMAWaypointType)type;
/**
 * Initializes a STOP NMAWaypoint instance.
 *
 * Set at least the originalPosition property for this waypoint to be useful.
 */
- (nonnull instancetype)init;

/**
 * The NMAGeoCoordinates representing the original position of the
 * NMAWaypoint - typically the exact coordinates of a building.
 *
 * The original position is required for a route calculation.
 * By default, this is set to be the same as the geocoordinates provided during construction of this
 * NMAWaypoint.
 *
 * Working together with the navigable position, the original position is used by the HERE SDK
 * for determining the side of street during arrival, and to let the calculated route approach
 * the correct side of street, especially when there there is a physical or logical lane divider
 * on the road.
 *
 * Attempts to set the property to nil will be ignored.
 *
 * See also `NMAPlaceLocation`.
 */
@property (nonatomic, nonnull) NMAGeoCoordinates *originalPosition;

/**
 * The NMAGeoCoordinates representing the suggested navigable position of the
 * NMAWaypoint - typically the coordinates on the road closest to
 * the original position - to be used in a route calculation.
 *
 * For a waypoint that is not on a road, the navigable position acts as a road location hint for
 * a route calculation. However, there's no guarantee that any location can work as a navigable
 * position. It is best to only use a navigable position when you have a trusted source, such as
 * from search results.
 *
 * Working together with the navigable position, the original position is used by the HERE SDK
 * for determining the side of street during arrival, and to let the calculated route approach
 * the correct side of street, especially when there there is a physical or logical lane divider
 * on the road.
 *
 * By default, the navigable position is set to be same as the geocoordinates provided
 * during construction of this NMAWaypoint.
 *
 * Attempts to set the property to nil will be ignored.
 *
 * See also `NMAPlaceLocation`.
 */
@property (nonatomic, nonnull) NMAGeoCoordinates *navigablePosition;

/** Gets the identifier. */
@property (nonatomic, nonnull, readonly) NSString *identifier;

/**
 * Gets the direction for waypoint.
 *
 * See also `NMAWaypoint::course`.
 */
@property (nonatomic, readonly) NMAWaypointDirection waypointDirection;

/**
 * Sets the road element identifier and direction. This information will be used in route calculation.
 *
 * @param identifier - Road element identifier
 * @param direction  - Direction to be enforeced
 */
- (void)setIdentifier:(nonnull NSString *)identifier waypointDirection:(NMAWaypointDirection)direction;

/**
 * The direction to take when leaving a waypoint, in degrees.
 *
 * Angle has a value from 0 to 360 where north is up, clockwise.
 * If a value is greater than or equal 360, the modulus of 360 is used.
 * Negative degrees are converted to corresponding positive values.
 *
 * Defaults to `NMAUnknownWaypointCourse`.
 */
@property (nonatomic) CGFloat course;

/**
 * The NMAGeoCoordinates representing the mapped matched position
 * of the NMAWaypoint - the coordinates adjusted by the routing
 * engine so that they fall upon a road.
 *
 * This is different than the navigablePosition because this is a value that is
 * generated during the routing calculation.
 *
 * @note This is nil before route calculation. This is only available
 * after route calculation.
 */
@property (nonatomic, readonly, nullable) NMAGeoCoordinates *mappedPosition;

/**
 * The NMAWaypointRoadInfo representing additional information about
 * an NMAWaypoint, obtained during route calculation.
 *
 * @note This is nil before route calculation. This is only available
 * after route calculation.
 */
@property (nonatomic, readonly, nullable) NMAWaypointRoadInfo *roadInfo;

/**
 * Determines the waypoint type.
 *
 * @note The default value is NMAStopWaypoint.
 *
 * See also `NMAWaypointType`
 */
@property (nonatomic) NMAWaypointType waypointType;

/**
 * Specifies time in seconds which will be spent waiting at this waypoint. Applicable only for
 * waypoints with type `NMAStopWaypoint`.
 *
 * @note Negative values are not allowed and will be ignored. 0 - is a default value.
 */
@property (nonatomic) NSInteger waitingTime;

/**
 * Specifies a radius for the fuzzy matching.
 *
 * It allows creation of an optimal route that pass over the waypoint within the specified
 * radius. The waypoint will be moved onto the closer street segment on the route. This might
 * be useful when a waypoint is only known approximately (e.g. DragNDrop, estimated
 * coordinates). Since this is a costly operation we advise to use values less than 200 meters.
 * The algorithm itself has a limit of how many street segments it considers for lookup.
 *
 * @note The fuzzy matching is enabled if the radius is greater than 0. Disabled by default.
 *       Values which are not in range [0, 1000] will be ignored.
 */
@property (nonatomic) NSInteger fuzzyMatchingRadius;

/**
 * Specifies a radius for the junction snapping. After a route is created, it will be checked
 * whether any endpoint of a route segment is within the specified radius to the waypoint. And
 * if the endpoint is a junction that waypoint will be moved onto the junction, potentially
 * eliminating short maneuvers, e.g. "Turn left and follow for 3m".
 *
 * @note The junction snapping is enabled if the radius is greater than 0. Disabled by default.
 *       Values which are not in range [0, 1000] will be ignored.
 */
@property (nonatomic) NSInteger junctionSnappingRadius;

/**
 * Specifies a radius for the selective matching.
 *
 * After a route is created, a route segment that is visible on the lowest zoom level within the
 * specified radius to the waypoint will be selected. The waypoint will be shifted to this segment.
 * If there is more than one segment, arbitrary segment will be chosen. Selective matching behavior
 * is useful for DragNDrop and snapping to more important streets. The radius should be set
 * depending on the zoom level and coordinate, e.g. to allow approximately 5 pixel snapping.
 *
 * @note The selective matching is enabled if the radius is greater than 0. Disabled by default.
 *       Values which are not in range [0, 1000] will be ignored.
 */
@property (nonatomic) NSInteger selectiveMatchingRadius;

/**
 * Sets a street name that helps to select the right road in complex intersection scenarios such
 * as a bridge crossing another road or in case of off-road locations near highways. A common
 * use case for this scenario is when the user specifies a waypoint by selecting a place or a
 * location after a search. To avoid the waypoint being matched to a highway in an off-road
 * scenario, it is sufficient to specify an off-road location as a street position without an
 * optional street name.
 *
 * @param hint The hint for matching.
 */
- (void)setStreetNameHint:(nonnull NSString *)hint;

@end
