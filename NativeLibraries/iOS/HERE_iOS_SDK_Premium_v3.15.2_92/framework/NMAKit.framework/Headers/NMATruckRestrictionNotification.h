/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMATruckRestrictionWarner.h"

@class NMATruckRestriction;
@class NMATruckRestrictionsInfo;


/**
 * Represents truck restriction notification object.
 */
@interface NMATruckRestrictionNotification : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Array of `NMATruckRestriction` objects associated with the truck restriction notification.
 *
 * DEPRECATED As of SDK 3.14. Use `NMATruckRestrictionNotification::truckRestrictionsInfos` instead.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMATruckRestriction *> *truckRestrictions DEPRECATED_ATTRIBUTE;

/**
 * Array of `NMATruckRestrictionsInfo` objects associated with the truck restriction notification.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMATruckRestrictionsInfo *> *truckRestrictionsInfos;

/**
 * Indicates if truck restriction is on route.
 */
@property (nonatomic, readonly) BOOL isOnRoute;

@end
