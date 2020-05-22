/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Defines constraints used to filter results based on their address.
 */
@interface NMAAddressFilter : NSObject

/**
 * Initializes an NMAAddressFilter instance.
 */
- (nonnull instancetype)init;

/**
 * The country code.
 */
@property (nullable, nonatomic) NSString *countryCode;

/**
 * The state code.
 */
@property (nullable, nonatomic) NSString *stateCode;

/**
 * The county.
 */
@property (nullable, nonatomic) NSString *county;

/**
 * The district.
 */
@property (nullable, nonatomic) NSString *district;

/**
 * The city.
 */
@property (nullable, nonatomic) NSString *city;

/**
 * The zip code.
 */
@property (nullable, nonatomic) NSString *zipCode;

@end
