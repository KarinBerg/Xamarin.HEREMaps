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
 * Represents an access point (entrance) to a public transit stop.
 *
 * Each access is associated with a unique NMATransitStop; the stop can be
 * determined through the stopId property.
 *
 * @note Some accesses may not have complete information available.
 */
@interface NMATransitAccess : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The unique identifying string of the access.
 */
@property (nonatomic, readonly, nonnull) NSString *uniqueId;

/**
 * The name of the access.
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 * The geographical location of the access.
 */
@property (nonatomic, readonly, nullable) NMAGeoCoordinates *location;

/**
 * The uniqueId of NMATransitStop associated with this access.
 */
@property (nonatomic, readonly, nonnull) NSString *stopId;

/**
 * Indicates whether the given NMATransitType is available from this access.
 */
- (BOOL)hasTransitType:(NMATransitType)type;

@end
