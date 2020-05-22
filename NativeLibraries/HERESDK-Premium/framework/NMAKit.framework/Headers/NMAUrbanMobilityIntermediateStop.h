/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


@class NMAUrbanMobilityStation;


/**
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityIntermediateStop : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The station object.
 */
@property (nonatomic, readonly, nullable)  NMAUrbanMobilityStation *station;

/**
 * The departure time from the intermediate station.
 */
@property (nonatomic, readonly, nullable) NSDate *scheduledDepartureTime;

/**
 * The arrival in the intermediate station.
 */
@property (nonatomic, readonly, nullable) NSDate *scheduledArrivalTime;

/**
 * Actual departure time from the intermediate station if real time information is avaialble.
 */
@property (nonatomic, readonly, nullable) NSDate *actualDepartureTime;

/**
 * Actual arrival time in the intermediate station if real time information is avaialble.
 */
@property (nonatomic, readonly, nullable) NSDate *actualArrivalTime;

@end
