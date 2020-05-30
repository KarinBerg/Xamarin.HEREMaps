/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobility.h"

@class NMAGeoCoordinates;
@class NMAUrbanMobilityAddress;
@class NMAUrbanMobilityTransport;



/**
 *
 * Represents a physical place like transit station, airport etc..
 *
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * See also `NMAUrbanMobilityTransport`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityPlace : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Address of this place.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityAddress *address;

/**
 * Describes whether or not the blind guidance is available at the place.
 */
@property (nonatomic, readonly) NMAUrbanMobilityFeatureAvailability blindGuideAvailability;

/**
 * Describes whether or not the elevator is available at the place.
 */
@property (nonatomic, readonly) NMAUrbanMobilityFeatureAvailability elevatorAvailability;

/**
 * Describes whether or not the escalator is available at the place.
 */
@property (nonatomic, readonly) NMAUrbanMobilityFeatureAvailability escalatorAvailability;

/**
 * Transports which run through this place (an array of `NMAUrbanMobilityTransport`).
 *
 * @return array of `NMAUrbanMobilityTransport`
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityTransport *> *transports;

/**
 * Distance (in meters) between the place and current location or
 * `NMAUrbanMobilityValueNotAvailable` if information is not available.
 *
 * @note It is available only when this NMAUrbanMobilityPlace comes from `NMAUrbanMobilityStationSearchCompletionBlock`
 * when you search `NMAUrbanMobilityStation` around you. It implied that your current location
 * was specified when searching nearby stations with `NMAUrbanMobilityStationSearchRequest`.
 */
@property (nonatomic, readonly) NSUInteger distanceFromCurrentLocation;

/**
 * Expected time, in seconds, to reach the station from your current location or
 * `NMAUrbanMobilityValueNotAvailable` if information is not available.
 *
 * @note  It is available only when this NMAUrbanMobilityPlace comes from `NMAUrbanMobilityStationSearchCompletionBlock`
 * when you search `NMAUrbanMobilityStation` around you. It implied that your current location
 * was specified when searching nearby stations with `NMAUrbanMobilityStationSearchRequest`.
 */
@property (nonatomic, readonly) NSTimeInterval durationFromCurrentLocation;

/**
 * Additional info about place.
 */
@property (nonatomic, readonly, nullable) NSString *info;

@end
