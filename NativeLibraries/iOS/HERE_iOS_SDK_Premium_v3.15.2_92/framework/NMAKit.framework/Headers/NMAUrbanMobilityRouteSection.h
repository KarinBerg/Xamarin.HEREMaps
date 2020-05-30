/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilityDeparture.h"
#import "NMAUrbanMobilityArrival.h"
@class NMAUrbanMobilityManeuver;
@class NMAUrbanMobilityLink;
@class NMAUrbanMobilityAlert;
@class NMAUrbanMobilityFare;
@class NMAUrbanMobilityIntermediateStop;


/**
 * Represents information about a single section/segment of a `NMAUrbanMobilityRoute`, which is covered
 * by a single `NMAUrbanMobilityRouteSectionTransit` section or is a pedestrian `NMAUrbanMobilityRouteSectionWalk` section.
 *
 * IMPORTANT: Urban Mobility routing is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityRouteSection : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * A unique id for this section.
 */
@property (nonatomic, readonly, nonnull) NSString *sectionId;

/**
 * Array of%NMAGeoCoordinates representing the geometry of this section.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAGeoCoordinates *> *geometry;

/**
 * Array of `NMAUrbanMobilityDeparture` containing relevant departure object.
 */
@property (nonatomic, readonly, nonnull) NMAUrbanMobilityDeparture *departure;

/**
 * Array of `NMAUrbanMobilityArrival` containing relevant departure object.
 */
@property (nonatomic, readonly, nonnull) NMAUrbanMobilityArrival *arrival;

/**
 * Distance in meters to cover by this section.
 */
@property (nonatomic, readonly) NSUInteger distance;

/**
 * Expected duration in seconds to cover that distance.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 * Indicate if departure/arrival times are uncertain. It is true for estimated values and
 * false if it comes from real time or time table data.
 *
 * @return YES if departure/arrival time is uncertain (i.e. value is estimated),
 * NO otherwise (i.e. value is from time table or real time)
 */
@property (nonatomic, readonly, getter = isTimeUncertain) BOOL timeUncertain;

/**
 * Array of `NMAUrbanMobilityManeuver` for this section.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityManeuver *> *maneuvers;

/**
 * Array of `NMAUrbanMobilityLink` related to this section.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityLink *> *operatorDisclaimers;

/**
 * Array of associated `NMAUrbanMobilityAlert`.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityAlert *> *alerts;

/**
 * The array of `NMAUrbanMobilityFare` required for this particular segment.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityFare *> *fares;

/**
 * The list of `NMAUrbanMobilityIntermediateStop` that are part of this transit stop.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityIntermediateStop *> *intermediateStops;

/**
 * Type of transport which serves the departure (Bus, Tram, Train, etc).
 */
@property (nonatomic, readonly) NMAUrbanMobilityTransportType transportType;

@end

