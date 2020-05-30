/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAMaterial.h"

@class NMAImage;
@class UIColor;



/**
 * A simple colored material for 3D map objects that can be used in conjunction
 * with a model texture to change the color of the texture.
 */
@interface NMAPhongMaterial : NMAMaterial

/**
 * Creates an NMAPhongMaterial with the specified diffuse and ambient colors.
 */
+ (nonnull instancetype)materialWithDiffuseColor:(nonnull UIColor *)diffuseColor ambientColor:(nonnull UIColor *)ambientColor
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Initializes a `NMAPhongMaterial` instance with the default diffuse and ambient colors.
 *
 * @return The `NMAPhongMaterial`
 */
- (nonnull instancetype)init;

/**
 * Initializes a `NMAPhongMaterial` instance with the default diffuse and ambient colors.
 *
 * @return The `NMAPhongMaterial`
 */
+ (nonnull instancetype)new;

/**
 * Initializes a `NMAPhongMaterial` instance with the specified diffuse and ambient colors.
 *
 * @param diffuseColor A UIColor representing the specified diffuse color
 * @param ambientColor A UIColor representing the specified ambient color
 * @return The `NMAPhongMaterial`
 */
- (nonnull instancetype)initWithDiffuseColor:(nonnull UIColor *)diffuseColor ambientColor:(nonnull UIColor *)ambientColor;

/**
 * The diffuse color of the material.
 *
 * @note The default value (in RGBA) is 0xFFFFFFFF.
 */
@property (nonatomic, strong, nonnull) UIColor *diffuseColor;

/**
 * The ambient color of the material
 *
 * @note The default value (in RGBA) is 0x000000FF.
 */
@property (nonatomic, strong, nonnull) UIColor *ambientColor;

@end
