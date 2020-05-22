/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAMapPolyline;
@class NMALineAttributes;



/**
 * Represent a ARPolyline that users can add to a `NMAARController`. This class also provide
 * features to customize polyline attributes such as width of line, color and so on.
 *
 */
@interface NMAARPolylineObject : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Create NMAARPolylineObject from NMAMapPolyline.
 *
 * @param polyline NMAMapPolyline rendered by this NMAARPolylineObject.
 *
 */
- (nonnull instancetype)initWithPolyline:(nonnull NMAMapPolyline *)polyline;

/**
 * Create NMAARPolylineObject with a NMAMapPolyline and a NMALineAttributes.
 *
 * @param polyline NMAMapPolyline rendered by this NMAARPolylineObject.
 *
 * @param lineAttributes attributes (such as width, color, line end cap style) to use when the line is rendered.
 *
 */
- (nonnull instancetype)initWithPolyline:(nonnull NMAMapPolyline *)polyline
                          lineAttributes:(nonnull NMALineAttributes *)lineAttributes;

/**
 * The unique ID of the NMAARPolylineObject.
 *
 * @note This value will be consistent for the lifetime of the object.
 */
@property (nonatomic, readonly) NSUInteger uniqueId;

/**
 * NMAMapPolyline rendered by this NMAARPolylineObject.
 */
@property (nonatomic, readwrite, nonnull) NMAMapPolyline *polyline;

/**
 * NMALineAttributes rendered by this NMAARPolylineObject.
 */
@property (nonatomic, readwrite, nonnull) NMALineAttributes *lineAttributes;

@end
