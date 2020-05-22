/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Represents address information for a geographic location.
 *
 * See also `NMAPlaceLocation`
 */
@interface NMAAddress : NSObject

/**
 * Initializes an NMAAddress instance.
 */
- (nonnull instancetype)init;

/**
 * The floor number in a multi-story building.
 */
@property (nullable, nonatomic) NSString *floorNumber;

/**
 * The house number.
 */
@property (nullable, nonatomic) NSString *houseNumber;

/**
 * The suite number or unit name.
 */
@property (nullable, nonatomic) NSString *suiteNumberOrName;

/**
 * The street name.
 */
@property (nullable, nonatomic) NSString *street;

/**
 * The district name.
 */
@property (nullable, nonatomic) NSString *district;

/**
 * The county name.
 */
@property (nullable, nonatomic) NSString *county;

/**
 * The city name.
 */
@property (nullable, nonatomic) NSString *city;

/**
 * The state name.
 */
@property (nullable, nonatomic) NSString *state;

/**
 * The postal code.
 */
@property (nullable, nonatomic) NSString *postalCode;

/**
 * The country code.
 *
 * @note The country code defined in "ISO 3166-1 alpha-3" three letter format.
 */
@property (nullable, nonatomic) NSString *countryCode;

/**
 * The country name.
 */
@property (nullable, nonatomic) NSString *countryName;

/**
 * The descriptive label for the `NMAAddress`.
 */
@property (nullable, nonatomic) NSString *label;

/**
 * The `NSString` representation of the address formatted according to local standards.
 */
@property (nullable, nonatomic) NSString *formattedAddress;

/**
 * Gets the `NSDictionary` containing all additional key-value
 * `NMAAddress` data.
 *
 * @return The `NSDictionary` of additional key-value data
 */
- (nonnull NSDictionary<NSString *, NSString *> *)additionalData;

@end
