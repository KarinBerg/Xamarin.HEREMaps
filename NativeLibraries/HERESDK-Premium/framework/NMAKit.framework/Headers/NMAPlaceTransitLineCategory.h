/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Represents the category information for the public transport line.
 */
@interface NMAPlaceTransitLineCategory : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Gets the category unique identifier.
 */
@property (nullable, nonatomic, readonly) NSString *uniqueId;

/**
 * Gets the localized name of the category.
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *title;

/**
 * Gets the locally used name for the category.
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *localName;

/**
 * Gets the icon for the category.
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *iconUrl;

@end
