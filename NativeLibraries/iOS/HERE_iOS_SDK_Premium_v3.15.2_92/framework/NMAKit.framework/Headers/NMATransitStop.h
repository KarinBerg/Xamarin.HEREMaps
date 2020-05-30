/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMATransitManager.h"

@class NMAGeoCoordinates;



/**
 * Represents a public transit stop.
 *
 * @note Some stops may not have complete information available.
 */
@interface NMATransitStop : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The unique identifying string of the stop.
 */
@property (nonatomic, readonly, nonnull) NSString *uniqueId;

/**
 * The officially published name of the stop.
 */
@property (nonatomic, readonly, nonnull) NSString *officialName;

/**
 * The local name of the stop, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *informalName;

/**
 * The geographical location of the stop.
 */
@property (nonatomic, readonly, nullable) NMAGeoCoordinates *location;

/**
 * A list of NSString objects representing the uniqueIds of all
 * NMATransitLines associated with this stop.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *lineIds;

/**
 * A list of NSString objects representing the uniqueIds of all
 * NMATransitSystems associated with this stop.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *systemIds;

/**
 * Indicates whether the given NMATransitType is available at this stop.
 */
- (BOOL)hasTransitType:(NMATransitType)type;

@end
