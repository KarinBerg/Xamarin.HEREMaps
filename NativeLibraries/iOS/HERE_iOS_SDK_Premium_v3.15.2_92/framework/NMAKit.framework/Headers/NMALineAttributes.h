/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAMapPolyline.h"


/** Defines types of cap styles for a line. */
typedef NS_ENUM(NSUInteger, NMALineCapStyle) {
    /**
     * Makes the ends of the line flush with each end of the path (no protrusion
     * from the path ends).
     */
    NMALineCapStyleButt,
    /**
     * Makes the ends of the line rounded, protruding from each path end with a
     * radius equal to half the thickness of the line.
     */
    NMALineCapStyleRound,
};


/**
 * Line/Shape outline attributes. Specifies the drawing attributes of a line or the outline of a shape.
 */
@interface NMALineAttributes : NSObject

/**
 * Constructs a default LineAttributes object having 1 px line width, BLUE color, ROUND_CAP Line ending styles
 * and false perspective.
 */
- (nonnull instancetype)init;

/**
 * Constructs a LineAttributes object from passed parameters.
 *
 * @param widthInPixel Width in pixels of the line. The value will be clipped to the valid range [0,100].
 * @param color Color of the line.
 * @param capStyle The line ending styles.
 * @param perspective if true, the line looks thinner further away when the map is tilted.
 */
- (nonnull instancetype)initWithWidth:(NSUInteger)widthInPixel
                        color:(nonnull UIColor *)color
                     capStyle:(NMALineCapStyle)capStyle
                  perspective:(BOOL)perspective;

/**
 * Line width, in pixels, an int value within the [0..100] range. By default, the line width is 1.
 */
@property (nonatomic, readwrite) NSUInteger lineWidth;

/**
 * Line color. The default line color is BLUE.
 *
 */
@property (nonatomic, readwrite, nonnull) UIColor *lineColor;

/**
 * Sets the appearance as either a dashed or solid line. By default, line is solid.
 *
 * @note The getter is `isDashed`.
 */
@property (nonatomic, readwrite, getter = isDashed) BOOL dashed;

/**
 * Sets a length for the primary dash segment of a dashed line. By default, the
 * primary dash length is 1.
 */
@property (nonatomic, readwrite) NSUInteger dashPrimaryLength;

/**
 * Sets a length for the secondary (empty) dash segments of a dashed line. By
 * default, the secondary dash length is 1.
 */
@property (nonatomic, readwrite) NSUInteger dashSecondaryLength;

/**
 * Line end rendering cap style.
 */
@property (nonatomic, readwrite) NMALineCapStyle capStyle;

/**
 * Perspective. if YES, The line looks thinner further away when the map is tilted.
 */
@property (nonatomic, readwrite) BOOL renderedWithPerspective;

@end
