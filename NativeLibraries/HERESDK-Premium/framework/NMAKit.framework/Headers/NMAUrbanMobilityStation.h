/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilityPlace.h"



/**
 * Public transport station.
 *
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * See also `NMAUrbanMobilityDepartureBoard`
 *
 * See also `NMAUrbanMobilityPlace`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityStation : NMAUrbanMobilityPlace

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Unique ID of the station.
 */
@property (nonatomic, readonly, nonnull) NSString *stationId;

/**
 * YES if the departure board is available for this station.
 *
 * See also `NMAUrbanMobilityDepartureBoard`
 */
@property (nonatomic, readonly, getter = isDepartureBoardAvailable) BOOL departureBoardAvailable;

@end
