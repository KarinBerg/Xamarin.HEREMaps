/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Result of `NMATollCostRequest`.
 */
@interface NMATollCostResult : NSObject

/**
 * Do not directly instantiate an instance of this class.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Gets the total toll cost of given `NMARoute`. The default currency is EUR.
 *
 * See also `NMATollCostOptions#currency.`
 */
@property (nonatomic, strong, readonly, nonnull) NSDecimalNumber * tollCost;

/**
 * Gets the toll cost for each country the route traverses. The default currency is EUR.
 * It is a dictionary of ISO 3166 Alpha-3 country code and toll cost.
 *
 * See also `NMATollCostOptions#currency.`
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary<NSString*, NSDecimalNumber*> * countryTollMap;

/**
 * Gets the toll cost for each toll system the route traverses. The default currency is EUR.
 * Please note that the toll system names will not be localized.
 *
 * See also `NMATollCostOptions#currency.`
 */
@property (nonatomic, strong, readonly, nonnull) NSDictionary<NSString*, NSDecimalNumber*> * tollSystemMap;

@end
