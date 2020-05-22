/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMATransitManager.h"

@class UIColor;



/**
 * Represents a public transit line, for example a subway or metro rail.
 *
 * @note Some lines may not have complete information available.
 */
@interface NMATransitLine : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The unique identifying string of the line.
 */
@property (nonatomic, readonly, nonnull) NSString *uniqueId;

/**
 * The officially published name of the line.
 */
@property (nonatomic, readonly, nonnull) NSString *officialName;

/**
 * The local or colloquial name of the line, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *informalName;

/**
 * A shortened name for the line, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *shortName;

/**
 * The transportation type of the line.
 *
 * See also `NMATransitType`
 */
@property (nonatomic, readonly) NMATransitType transitType;

/**
 * The color associated with the line if available, otherwise nil.
 */
@property (nonatomic, readonly, nullable) UIColor *color;

/**
 * The uniqueId of the system of which this line is a part.
 */
@property (nonatomic, readonly, nonnull) NSString *systemId;

@end
