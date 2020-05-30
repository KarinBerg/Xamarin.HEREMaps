/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMARoadElement;
@class NMATruckRestriction;


/**
 * Represents information about truck restrictions on a road.
 */
@interface NMATruckRestrictionsInfo : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Road element corresponding to these truck restrictions.
 */
@property (nonatomic, readonly, nonnull) NMARoadElement *roadElement;

/**
 * The distance to these restrictions, in meters.
 */
@property (nonatomic, readonly) NSUInteger distance;

/**
 * Array of `NMATruckRestriction` objects corresponding to these restrictions.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMATruckRestriction *> *truckRestrictions;

@end
