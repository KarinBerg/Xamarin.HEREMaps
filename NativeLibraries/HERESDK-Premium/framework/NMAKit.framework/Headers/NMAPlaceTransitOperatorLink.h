/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMALink;


/**
 * Represents an additional link associated with transit operator.
 */
@interface NMAPlaceTransitOperatorLink : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The `NSString` of operator link text.
 */
@property (nullable, nonatomic, readonly) NSString *text;

/**
 * The `NMALink` to the operator information.
 */
@property (nullable, nonatomic, readonly) NMALink *url;

@end
