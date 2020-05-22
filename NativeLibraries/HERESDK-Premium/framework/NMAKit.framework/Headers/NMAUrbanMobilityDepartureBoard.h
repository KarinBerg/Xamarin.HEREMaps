/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAUrbanMobilityDeparture;
@class NMAUrbanMobilityTransport;
@class NMAUrbanMobilityOperator;
@class NMAUrbanMobilityLink;



/**
 * Represents departure information for a public transport at a given stop/station.
 *
 * IMPORTANT: Urban Mobility Departure Board is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityDepartureBoard : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Returns an array of `NMAUrbanMobilityDeparture`.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityDeparture *> *departures;

/**
 * Returns an array of `NMAUrbanMobilityTransport`, transports serving departures shown in current departure list .
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityTransport *> *transports;

/**
 * Returns an array of `NMAUrbanMobilityOperator`, operators operating on this stop/station.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityOperator *> *operators;

/**
 * Returns an array of associated operators disclaimers (`NMAUrbanMobilityLink`).
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityLink *> *operatorDisclaimers;

@end
