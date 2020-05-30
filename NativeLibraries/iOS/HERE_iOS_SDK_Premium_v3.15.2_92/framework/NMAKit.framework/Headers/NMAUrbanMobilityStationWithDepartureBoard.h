/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilityStation.h"


@class NMAUrbanMobilityDepartureBoard;


/**
 * Extension for class NMAUrbanMobilityStation, used for Multi Departures Board.
 *
 * IMPORTANT: Urban Mobility Departure Board is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityStationWithDepartureBoard : NMAUrbanMobilityStation

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Departure Board `NMAUrbanMobilityDepartureBoard` is used for hold lists of objects parsed from response for `NMAUrbanMobilityMultiBoardRequest`.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityDepartureBoard *departureBoard;

@end
