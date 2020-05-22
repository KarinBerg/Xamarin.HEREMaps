/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;


/**
 *
 * Represents a transit stop for some form of public transport.
 */
@interface NMATransitRouteStop : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The id of the transit stop for future use. Identifier is not supported for
 * public transport timetable route stops.
 */
@property (nonatomic, readonly, nullable) NSString *identifier;

/**
 * The name of the transit stop.
 *
 * @note  It is localized to the locale of the region.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The geo coordinates of the transit stop.
 */
@property (nonatomic, readonly, nullable) NMAGeoCoordinates *coordinates;

@end
