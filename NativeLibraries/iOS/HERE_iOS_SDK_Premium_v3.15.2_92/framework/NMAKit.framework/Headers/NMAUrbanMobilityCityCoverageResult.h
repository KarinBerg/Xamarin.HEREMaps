/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAUrbanMobilityCitySearchResult.h"
@class NMAUrbanMobilityCity;



/**
 * Lists of `NMAUrbanMobilityCity` where were have transit coverage, as well as list of transit operators,
 * from a given location, within a certain radius. Used in `NMAUrbanMobilityCitySearchRequest`.
 *
 * IMPORTANT: Urban Mobility Coverage Search is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityCityCoverageResult : NMAUrbanMobilityCitySearchResult

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * List of `NMAUrbanMobilityCity`
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityCity *> *nearbyCities;

@end
