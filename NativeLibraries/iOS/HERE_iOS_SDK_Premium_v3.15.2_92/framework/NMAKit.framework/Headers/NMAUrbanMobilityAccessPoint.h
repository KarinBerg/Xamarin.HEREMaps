/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;



/**
 * Access point of a transit station.
 *
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * See also `NMAUrbanMobilityTransitStation`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityAccessPoint : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Unique ID of the access point.
 */
@property (nonatomic, readonly, nonnull) NSString *accessPointId;

/**
 * Name of the access point.
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 * Geo coordinates of the access point.
 */
@property (nonatomic, readonly, nonnull) NMAGeoCoordinates *location;

@end
