/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARoute.h"
#import "NMAUrbanMobilityArrival.h"
#import "NMAUrbanMobilityDeparture.h"
@class NMAUrbanMobilityRouteSection;
@class NMAUrbanMobilityTariff;


/**
 * Represents a wrapper of type NMARoute over the NMAUrbanMobilityRoute object.
 *
 * IMPORTANT: Urban Mobility routing is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMARoute (NMAUrbanMobilityRoute)

/**
 * A unique id for this route.
 */
@property (nonatomic, readonly, nullable) NSString *routeId;

/**
 * The number of times a public transport change is done on this route.
 */
@property (nonatomic, readonly) NSUInteger changes;

/**
 * The duration in seconds of the route.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 * Information about arrival, see `NMAUrbanMobilityArrival` class for details.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityArrival *arrival;

/**
 * Information about departure, see `NMAUrbanMobilityDeparture` class for details.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityDeparture *departure;

/**
 * Array of `NMAUrbanMobilityRouteSection` of the route. Can include different types `NMAUrbanMobilityTransportType` of transport, like walk or subway.
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityRouteSection *> *sections;

/**
 * Array of `NMAUrbanMobilityTariff` representing different options you can purchase for just one route.
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityTariff *> *tariffOptions;

@end
