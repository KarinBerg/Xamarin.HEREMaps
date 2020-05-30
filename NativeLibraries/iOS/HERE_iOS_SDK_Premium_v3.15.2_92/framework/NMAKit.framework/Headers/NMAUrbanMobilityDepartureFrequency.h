/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobility.h"



/**
 * Frequency information for a transit departure.
 *
 * IMPORTANT: Urban Mobility Departure Board is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * See also `NMAUrbanMobilityDeparture`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityDepartureFrequency : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The scheduled maximum interval in minutes. `NMAUrbanMobilityValueNotAvailable` if value not available.
 */
@property (nonatomic, readonly) NSUInteger maxScheduledInterval;

/**
 * The scheduled minimum interval in minutes. `NMAUrbanMobilityValueNotAvailable` if value not available.
 */
@property (nonatomic, readonly) NSUInteger minScheduledInterval;

/**
 * The actual maximum interval in minutes. `NMAUrbanMobilityValueNotAvailable` if value not available.
 */
@property (nonatomic, readonly) NSUInteger maxRealTimeInterval;

/**
 * The actual minimum interval in minutes. `NMAUrbanMobilityValueNotAvailable` if value not available.
 */
@property (nonatomic, readonly) NSUInteger minRealTimeInterval;

@end
