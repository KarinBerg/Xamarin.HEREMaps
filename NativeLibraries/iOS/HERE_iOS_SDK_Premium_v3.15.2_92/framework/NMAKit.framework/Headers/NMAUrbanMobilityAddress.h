/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;
@class NMAAddress;



/**
 * Geo coordinates and address information of a geographic location.
 *
 * @note Address information might not be available.
 *
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * See also `NMAAddress`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityAddress : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Geo coordinates of the geographic location.
 */
@property (nonatomic, readonly, nullable) NMAGeoCoordinates *location;

/**
 * The name of the place.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The country name.
 */
@property (nonatomic, readonly, nullable) NSString *country;

/**
 * The country code.
 *
 * @note The country code defined in "ISO 3166-1 alpha-3" three letter format.
 */
@property (nonatomic, readonly, nullable) NSString *countryCode;

/**
 * The state name.
 */
@property (nonatomic, readonly, nullable) NSString *state;

/**
 * The postal code.
 */
@property (nonatomic, readonly, nullable) NSString *postalCode;

/**
 * The district name.
 */
@property (nonatomic, readonly, nullable) NSString *district;

/**
 * The street name.
 */
@property (nonatomic, readonly, nullable) NSString *street;

/**
 * The house number.
 */
@property (nonatomic, readonly, nullable) NSString *houseNumber;

/**
 * The city name.
 */
@property (nonatomic, readonly, nullable) NSString *city;

@end
