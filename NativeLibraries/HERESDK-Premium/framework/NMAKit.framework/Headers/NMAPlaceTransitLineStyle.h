/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Represents the styling guideline information for the public transport
 * line. All colors are in hex format
 */
@interface NMAPlaceTransitLineStyle : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Gets the color value assigned to a line (hex format).
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *color;

/**
 * Gets the text color that should get used when the line color is used
 * as background color (hex format).
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *textColor;

/**
 * Gets the color of the border around the line name (hex format).
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *outlineColor;

/**
 * Gets the shape style identifying the icon for the line (for example, a rectangle).
 *
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *iconShape;

@end
