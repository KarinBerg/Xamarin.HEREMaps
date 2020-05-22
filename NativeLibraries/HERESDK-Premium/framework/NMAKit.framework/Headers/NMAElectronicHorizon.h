/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAElectronicHorizonDelegate.h"
#import "NMAEHMapAccessor.h"

@class NMARoute;

/**
 * The error domain for NMAElectronicHorizon errors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull kNMAElectronicHorizonErrorDomain;



/**
 * `NMAEHElectronicHorizon` uses the vehicle position, the ingested map topography and other
 * related road attributes, to calculate the most probable, as well as alternative paths,
 * structured as a `NMAEHPathTree` of roads bundling information on form of ways, roundabouts,
 * carriageways, as well as interchange and service roads to efficiently prepare a driver.
 *
 * While online and offline prediction is supported to provide a forecast for over several
 * kilometers ahead, usage of pre-downloaded map data is highly recommended.
 * Offline maps require the `NMAMapDataGroupADAS` and `NMAMapDataGroupLinkGDBIdPVId` data groups
 * to be enabled.
 */
@interface NMAElectronicHorizon : NSObject

/**
 * Receives event callbacks containing information about the tree.
 *
 * See also `NMAElectronicHorizonDelegate`
 */
@property (nonatomic, weak, nullable, readwrite) id<NMAElectronicHorizonDelegate> delegate;

/**
 * An instance of `NMAEHMapAccessor`, which can be used to access
 * the information about any link.
 */
@property (nonatomic, strong, readonly, nonnull) NMAEHMapAccessor *mapAccessor;

/**
 * Initialize a `NMAElectronicHorizon` instance
 */
- (nonnull instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Updates electronic horizon with a new position. After calling update, the path tree might be
 * changed in parts or as a whole.
 *
 * @return error if the operation was not successful, otherwise nil.
 */
- (nullable NSError *)update;

/**
 * Sets trailing distance to remove links when they are fully beyond the threshold starting
 * off from the vehicle's current position.
 *
 * @param distance The distance in centimeters.
 *
 * @note The default trailing distance is 10'000 centimeters (100 meters).
 *
 * @return error if the operation was not successful, otherwise nil.
 */
- (nullable NSError *)setTrailingDistanceInCentimeters:(NSInteger)distance;

/**
 * Sets look-ahead distances to limit the length of the predicted main path and its side
 * paths.
 *
 * The first value defines the threshold for the main path. If nothing is set, the default
 * look-ahead distance is 800'000 centimeters (8 kilometers).
 *
 * The subsequent values define the threshold of the side paths (children). A child path
 * starts to branch from a parent path, which is determined by the preceding value. A look-ahead
 * distance always starts from the vehicle's current position to the beginning of the last link
 * that exceeds the distance. Links beyond this threshold will not be used for building
 * the path.
 *
 * If n is the number of distances set, then electronic horizon will always try to provide
 * n + 1 side paths. By default, the last paths are stubs and will contain only the first link
 * of the related road segment.
 *
 * @param distances An array of distances in centimeters from which
 * the number of side paths is determined.
 *
 * @return error if the operation was not successful, otherwise nil.
 */
- (nullable NSError *)setLookAheadDistancesInCentimeters:(nonnull NSArray<NSNumber *> *)distances;

/**
 * Sets a route to follow. Electronic horizon will take the route into account
 * when building the most probable path.
 *
 * @param route Route to follow.
 *
 * @return error if the operation was not successful, otherwise nil.
 *
 * @note Only the routes with transport mode `NMATransportModeCar`
 * or `NMATransportModeTruck` are supported. */
- (nullable NSError *)setRoute:(nonnull NMARoute *)route;

@end
