/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMARoutingMode.h"
#import "NMARouteTta.h"
#import "NMADynamicPenalty.h"

@class NMAGeoBoundingBox;
@class NMAWaypoint;
@class NMAManeuver;
@class NMAMapPolyline;
@class NMARouteConsumption;
@class NMARouteConsumptionParameters;
@class NMARouteElement;
@class NMAGeoCoordinates;
@class NMARoute;
@class NMARoutingZone;


/**
 * A constant used to indicate the whole route should be used in route leg selection.
 */
FOUNDATION_EXPORT const NSInteger NMARouteSublegWhole;

/**
 * Route general error codes.
 * Used to identify reason of failure during method execution on NMARoute object.
 */
typedef NS_ENUM(NSUInteger, NMARouteError) {
    /** Parameter provided is nil, uninitialized or empty */
    NMARouteErrorInvalidParameter = 1,
    /** Operation is not supported in this mode */
    NMARouteErrorNotSupported,
    /** Generic error */
    NMARouteErrorUnknown
};

/**
 * Route Serialization Errors
 *
 * IMPORTANT: NMARoute serialization is a Beta feature. The related classes are subject to
 * change without notice.
 */
typedef NS_ENUM(NSUInteger, NMARouteSerializationError) {
    /** Parameter provided is nil, uninitialized or empty */
    NMARouteSerializationErrorInvalidParameter,
    /** Map version from serialized route does not match current map version */
    NMARouteSerializationErrorMapVersionMismatch,
    /** Data provided for deserialization is corrupted */
    NMARouteSerializationErrorDataCorrupted,
    /** Transport mode not supported for current operation */
    NMARouteSerializationErrorTransportModeNotSupported,
    /** Generic error */
    NMARouteSerializationErrorUnknown
};

/**
 * Represents values describing the possible unit system for route instructions.
 */
typedef NS_ENUM(NSUInteger, NMARouteInstructionsUnitSystem) {
    /** Metric units */
    NMARouteInstructionsUnitSystemMetric,
    /** Imperial units */
    NMARouteInstructionsUnitSystemImperial
};

/**
 * Completion block used to handle the results of route serialization requests.
 *
 * @param data NSData object containing the serialized route, nil on failure.
 * @param error nil if serialization completed successfully, otherwise an `NMARouteSerializationError`
 *              indicating the failure reason.
 */
typedef void(^NMARouteSerializationCompletionBlock)(NSData * _Nullable data, NSError * _Nullable error);

/**
 * Completion block used to handle the results of route deserialization requests.
 *
 * @param route NMARoute object from the serialized data, nil on failure.
 * @param error nil if deserialization completed successfully, otherwise an `NMARouteSerializationError`
 *              indicating the failure reason.
 */
typedef void(^NMARouteDeserializationCompletionBlock)(NMARoute * _Nullable route, NSError * _Nullable error);


/**
 * Represents a path (a collection of maneuvers) connecting two or more waypoints.
 *
 * Waypoints may be thought of as the input to a route calculation whereas maneuvers are
 * the results of calculating a route.
 */
@interface NMARoute : NSObject

/**
 * Create an NMARoute from a previously serialized route asynchronously
 *
 * This method passes nil to the callback if the deserialization fails. The deserialization fails when
 * the map version from which the NMARoute was serialized does not match current map version,
 * the SDK version from which the NMARoute was serialized is not compatible with current SDK
 * version, or when the input data is invalid or corrupted.
 *
 * IMPORTANT: NMARoute serialization is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * @param data NSData to be deserialized into a NMARoute.
 * @param completionBlock the block to execute on completion of deserializtion
 */
+ (void)routeFromSerializedRoute:(nonnull NSData *)data withCompletion:(nonnull NMARouteDeserializationCompletionBlock)completionBlock
NS_SWIFT_NAME(route(fromSerializedRoute:_:));

/**
 * NMARoute is generated from route calculation or route deserialization. Please see
 * `NMACoreRouter::calculateRouteWithStops:routingMode:completionBlock:`
 * and `NMARoute::routeFromSerializedRoute:withCompletion:`.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * NMARoute is generated from route calculation or route deserialization. Please see
 * `NMACoreRouter::calculateRouteWithStops:routingMode:completionBlock:`
 * and `NMARoute::routeFromSerializedRoute:withCompletion:`.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The starting NMAWaypoint for the `NMARoute`.
 */
@property (nonatomic, readonly, weak, nullable) NMAWaypoint *start;

/**
 *  The destination NMAWaypoint for the `NMARoute`.
 */
@property (nonatomic, readonly, weak, nullable) NMAWaypoint *destination;

/**
 *  Array of NMAWaypoint for all waypoints of the `NMARoute`.
 */
@property (nonatomic, readonly, strong, nullable) NSArray <NMAWaypoint *> *waypoints;

/**
 * Array of permanent link ids of the `NMARoadElement` objects contained in this route.
 * It will return an empty array for public transport route.
 *
 * See also `NMARoadElement::permanentLinkId`
 */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *permanentLinkIds;

/**
 * Array of permanent link ids of the `NMARoadElement` objects contained in this route
 * with their travel directions. It will return an empty array for public transport route.
 *
 * See also `NMARoadElement::permanentDirectedLinkId`
 */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *permanentDirectedLinkIds;

/**
 * The length of the `NMARoute`, in meters. This is the actual distance
 * covered if you were to travel the route.
 */
@property (nonatomic, readonly) NSUInteger length;

/**
 * The length of the leg of the `NMARoute`, in meters. This is the actual distance
 * covered if you were to travel the route.
 *
 * @param subleg The index of the subleg on the `NMARoute` to be used for this calculation. If
 * `NMARouteSublegWhole` is provided, the result is the length of the whole `NMARoute`.
 *
 * @note `lengthForSubleg` is not supported by `NMAUrbanMobilityRoute`.
 */
- (NSUInteger)lengthForSubleg:(NSUInteger)subleg
NS_SWIFT_NAME(length(forSubleg:));

/**
 *  Returns the number of sub-legs the route has
 * a subleg is the part of a route between two stop waypoints.
 */
@property (nonatomic, readonly) NSUInteger sublegCount;

/**
 * Return the anticipated energy consumption for driving this route
 *
 * IMPORTANT: Consumption calculation is a Beta feature. The related classes and
 * methods are subject to change without notice.
 *
 * @param consumptionParameters Consumption parameters specific to the vehicle that is to
 * drive the route
 * @param dynamicPenalty Restriction factors for a given area that will influence consumption.
 * If there is no penalty in the route the value should be nil.
 * @return NMARouteConsumption instance containing data about route consumption, or nil
 * if the route type does not support consumption information (e.g. a transit route)
 */
-(nullable NMARouteConsumption*) consumptionWithParameters:(nonnull NMARouteConsumptionParameters*)consumptionParameters
                                            dynamicPenalty:(nullable NMADynamicPenalty*)dynamicPenalty
NS_SWIFT_NAME(consumption(with:dynamicPenalty:));

/**
 * The last reachable waypoint given a specific consumption model
 *
 * The NMARouteConsumption object passed to this method should have been previously
 * obtained from the `consumptionWithParameters:dynamicPenalty:` method.
 * In the case that consumptionWithParameters:dynamicPenalty: was called with the default
 * values provided by NMARouteConsumptionParameters, an appropriate value for the capacity
 * paramter would be 300000. This would represent a vehicle with maximum capacity.
 * A lower value would correspond to a vehicle with lower remaining capacity which
 * would not be able to travel as far.
 *
 * IMPORTANT: Consumption calculation is a Beta feature. The related classes and
 * methods are subject to change without notice.
 *
 * @param routeConsumption Specifies the parameters of consumption for a given
 * vehicle.
 * @param capacity Available capacity at the beginning of the route.
 * @return the coordinates of the last reachable position.
 */
-(nullable NMAGeoCoordinates*) lastReachablePositionWithConsumption:(nonnull NMARouteConsumption*)routeConsumption
                                                    currentCapacity:(NSInteger)capacity
NS_SWIFT_NAME(lastReachablePosition(with:currentCapacity:));


/**
 * The smallest NMAGeoBoundingBox that contains the entire `NMARoute`.
 */
@property (nonatomic, readonly, strong, nullable) NMAGeoBoundingBox *boundingBox;

/**
 * Array of NMAManeuver to represent all the maneuvers that travelers will
 * encounter along the `NMARoute`.
 * In case of calculation `NMAUrbanMobilityRoute`, this returns nil.
 * Instead, you can find array of `NMAUrbanMobilityManeuver` in every `NMAUrbanMobilityRoute::NMAUrbanMobilityRouteSectionWalk`.
 */
@property (nonatomic, readonly, strong, nullable) NSArray<NMAManeuver *> *maneuvers;

/**
 * The NSArray of `NMAGeoCoordinates` representing, in order, the
 * polyline of the route.
 *
 * No elevation profile of the route is available. The `NMAGeoCoordinates` altitude property will
 * return -FLT_MAX (representing an unknown altitude).
 */
@property (nonatomic, readonly, strong, nullable) NSArray<NMAGeoCoordinates *> *geometry;

/**
 * The NSArray of `NMAGeoCoordinates` (with elevation data, if available) representing, in order, the
 * polyline of the route.
 *
 * An elevation profile of the route can be determined if the
 * altitude property of the `NMAGeoCoordinates` does not return
 * -FLT_MAX (representing an unknown altitude).
 */
@property (nonatomic, readonly, strong, nullable) NSArray<NMAGeoCoordinates *> *geometryWithElevationData;

/**
 * The list of NMARouteElement (or instances of classes derived from it) within the route object.
 *
 * Note that if this is a transit route, this will be an array of NMATransitRouteElement.
 * Otherwise, this is a list of NMARoadElement.
 */
@property (nonatomic, readonly, strong, nullable) NSArray<NMARouteElement *> *routeElements;

/**
 * The NMARoutingMode for the `NMARoute`.
 */
@property (nonatomic, readonly, strong, nonnull) NMARoutingMode *routingMode;

/**
 * A user-defined tag to identify the `NMARoute`
 *
 * @note The default value for userTag is empty string.
 */
@property (nonatomic, strong, nullable) NSString *userTag;

/**
 * Gets the estimated time to arrival, taking into account traffic conditions
 * at the time of the route calculation and does not change with time.
 *
 * @note If the route was originally calculated without setting a traffic penalty mode
 * or originally calculated with a traffic penalty mode other than `NMATrafficPenaltyModeOptimal`,
 * this method will return the estimated time to arrival without considering traffic conditions.
 *
 * @note This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @param subleg The index of the subleg on the `NMARoute` to be used for this calculation. If
 * `NMARouteSublegWhole` is provided, the result is the NMARouteTta object of traveling the whole NMARoute.
 *
 * @return `NMARouteTta` object of traveling the specified subLeg of the `NMARoute`.
 */
- (nullable NMARouteTta *)ttaIncludingTrafficForSubleg:(NSUInteger)subleg;

/**
 * Gets the estimated time to arrival with traffic conditions, where the traffic conditions are taken
 * from traffic data downloaded to the device. The caller is recommended to download traffic for the route
 * first using the `NMATrafficManager` class (and wait for it to complete) prior to calling this method.
 *
 * @note If the route was originally calculated without setting a traffic penalty mode or originally
 * calculated with a traffic penalty mode other than `NMATrafficPenaltyModeOptimal`, this method
 * will return the estimated time to arrival without considering traffic conditions.
 * This method should be used in cases where the time elapsed since a route was returned is large enough
 * to make the time to arrival (as obtained using `ttaIncludingTraffic`),
 * no longer accurate given changing traffic conditions. This method will provide a more
 * up-to-date time to arrival estimate provided traffic data is first downloaded
 * for the route using the `NMATrafficManager` class.
 *
 * @note This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @param subleg The index of the subleg on the `NMARoute` to be used for this calculation. If
 * `NMARouteSublegWhole` is provided, the result is the NMARouteTta object of traveling the whole NMARoute.
 *
 * @return `NMARouteTta` object of traveling the specified subLeg of the `NMARoute`.
 */
- (nullable NMARouteTta *)ttaUsingDownloadedTrafficForSubleg:(NSUInteger)subleg;

/**
 * Gets the estimated time to arrival without considering traffic conditions.
 *
 * @param subleg The index of the subleg on the `NMARoute` to be used for this calculation. If
 * `NMARouteSublegWhole` is provided, the result is the NMARouteTta object of traveling the whole NMARoute.
 */
- (nullable NMARouteTta *)ttaExcludingTrafficForSubleg:(NSUInteger)subleg;

/**
 * Serialize an NMARoute object asynchronously
 *
 * This method does not serialize invalid routes or routes calculated with
 * `NMATransportModePublicTransport` or `NMATransportModeUrbanMobility`.
 * Instead, nil is returned.
 *
 * IMPORTANT: NMARoute serialization is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * @param completionBlock the block to execute on completion of the serialization
 */
- (void)serializedRouteWithCompletionBlock:(nonnull NMARouteSerializationCompletionBlock)completionBlock
NS_SWIFT_NAME(serializedRoute(_:));

/**
 * Gets the list of `NMARouteElement` belonging to the maneuver object.
 *
 * @param maneuver The `NMAManeuver` to get the list of `NMARouteElement` objects for.
 * @param error A pointer to an error object. If an error occurs, the method will return nil and
 * update your error pointer to an error object describing the problem. If you're not interested
 * in the error object, just pass nil for the `error:` parameter.
 *
 * @return The array of `NMARouteElement` objects belonging to this `NMAManeuver`
 * or nil if error occurs.
 *
 * @note `routeElementsFromManeuver` is not supported by `NMATransitRoute`.
 */
- (nullable NSArray<NMARouteElement *> *)routeElementsFromManeuver:(nonnull NMAManeuver *)maneuver
                                                             error:( NSError *_Nullable *_Nullable)error
NS_SWIFT_NAME(routeElementsFrom(maneuver:));

/**
 * Gets the list of `NMARouteElement` for a given duration (in seconds) from the start of the route.
 *
 * @param duration The number of seconds from the beginning of the route.
 * @param error A pointer to an error object. If an error occurs, the method will return nil and
 * update your error pointer to an error object describing the problem. If you're not interested
 * in the error object, just pass nil for the `error:` parameter.
 *
 * @return The array of `NMARouteElement` objects within the given duration, or nil if error occurs.
 *
 * @note `routeElementsFromDuration` is not supported by `NMATransitRoute`.
 */
- (nullable NSArray<NMARouteElement *> *)routeElementsFromDuration:(NSTimeInterval)duration
                                                             error:(NSError *_Nullable *_Nullable)error
NS_SWIFT_NAME(routeElementsFrom(duration:));

/**
 * Gets the list of `NMARouteElement` for a given duration (in seconds) from the start of the route.
 *
 * @param startTime The number of seconds into the route to start getting list of `RouteElement` objects.
 * @param duration The number of seconds from the given start of the route.
 * @param error A pointer to an error object. If an error occurs, the method will return nil and
 * update your error pointer to an error object describing the problem. If you're not interested
 * in the error object, just pass nil for the `error:` parameter.
 *
 * @return The array of `NMARouteElement` objects within the given duration, or nil if error occurs.
 *
 * @note `routeElementsFromStartTime` is not supported by `NMATransitRoute`.
 */
- (nullable NSArray<NMARouteElement *> *)routeElementsFromStartTime:(NSTimeInterval)startTime
                                                           duration:(NSTimeInterval)duration
                                                              error:(NSError * _Nullable *_Nullable)error
NS_SWIFT_NAME(routeElementsFrom(startTime:duration:));

/**
 * Gets the list of `NMARouteElement` for a given distance (in meters) within the route.
 *
 * @param length The number of meters from the beginning of the route.
 * @param error A pointer to an error object. If an error occurs, the method will return nil and
 * update your error pointer to an error object describing the problem. If you're not interested
 * in the error object, just pass nil for the `error:` parameter.
 *
 * @return The array of `NMARouteElement` objects within the given distance, or nil if error occurs.
 *
 * @note `routeElementsFromLength` is not supported by `NMATransitRoute`.
 */
- (nullable NSArray<NMARouteElement *> *)routeElementsFromLength:(NSUInteger)length
                                                           error:(NSError *_Nullable *_Nullable)error
NS_SWIFT_NAME(routeElementsFrom(length:));

/**
 * Gets the list of `NMARouteElement` for a given distance (in meters) within the route.
 *
 * @param startDistance The number of meters into the route to start getting list of `RouteElement`
 * objects.
 * @param length The number of meters from the beginning of the route.
 * @param error A pointer to an error object. If an error occurs, the method will return nil and
 * update your error pointer to an error object describing the problem. If you're not interested
 * in the error object, just pass nil for the `error:` parameter.
 *
 * @return The array of `NMARouteElement` objects within the given distance, or nil if error occurs.
 *
 * @note `routeElementsFromStartDistance` is not supported by `NMATransitRoute`.
 */
- (nullable NSArray<NMARouteElement *> *)routeElementsFromStartDistance:(NSUInteger)startDistance
                                                                 length:(NSUInteger)length
                                                                  error:(NSError *_Nullable *_Nullable)error
NS_SWIFT_NAME(routeElementsFrom(startDistance:length:));

/**
 * Returns the distance between two points on the route.
 *
 * @param fromRouteElement Index of the route element of the start point.
 * @param fromPosition Position of the start point.
 * @param toRouteElement Index of the route element of the end point.
 * @param toPosition Position of the end point.
 *
 * @return the distance between the start and the end point. Returns UINT_MAX if an error occured.
 * Returns zero if the end point is placed before the start point.
 *
 * @note `distanceFromRouteElement` is not supported by `NMATransitRoute` and
 * `NMAUrbanMobilityRoute`.
 */
- (NSUInteger)distanceFromRouteElement:(NSUInteger)fromRouteElement
                          fromPosition:(nonnull NMAGeoCoordinates *)fromPosition
                        toRouteElement:(NSUInteger)toRouteElement
                            toPosition:(nonnull NMAGeoCoordinates *)toPosition
NS_SWIFT_NAME(distance(fromRouteElement:fromPosition:toRouteElement:toPosition:));

/**
 * Gets the list of all routing zones used in the route.
 *
 * See also `NMARoutingZone`. See also `NMARoutingMode.excludeRoutingZones` property to exclude
 * certain zones from route calculation.
 *
 * @note Routing zones are supported only for `NMATransportModeCar`, `NMATransportModeTruck` and
 * `NMATransportModeScooter` transport modes.
 *
 * @note IMPORTANT: this is a BETA feature, and is subject to change without notice.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMARoutingZone *> *routingZones;

/**
 * Gets the complete list of maneuvers instructions along the route.
 *
 * @param language Desired language for instructions strings.
 * @param unitSystem Desired measurement unit system.
 *
 * @return An array of maneuvers instructions.
 *
 * @note language should be a valid code according to the IETF BCP-47 standard
 * (see http://tools.ietf.org/html/bcp47 ).
 */
- (nonnull NSArray<NSString *> *)instructionsForLanguage:(nonnull NSString *)language
                                              unitSystem:(NMARouteInstructionsUnitSystem)unitSystem
NS_SWIFT_NAME(instructions(forLanguage:unitSystem:));


@end
