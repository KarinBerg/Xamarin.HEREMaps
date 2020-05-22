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
 * Represents a bounding box that defines a rectangular area in a
 * geographic coordinate system.
 *
 * Although the bounding box is specified by its top-left and bottom-right corner,
 * the box is not necessarily the smallest rectangle spanned by these two points.
 * It is possible to define bounding boxes that are wider than 180 degrees or higher than
 * 90 degrees (e.g. by set ting the longitude of top-left corner to a bigger value than
 * the longitude of the bottom-right corner).
 *
 * For example, a bounding box with a longitude of -180 degrees for the
 * top- left corner and a longitude of 180 degrees for the bottom-right corner
 * will construct an area the encircles the globe, whereas a bounding box
 * with the same longitude values for both corners will construct a
 * bounding box with a width of 0 degrees.
 */
@interface NMAGeoBoundingBox : NSObject<NSCoding>

/**
 * Constructs a `NMAGeoBoundingBox` from NMAGeoCoordinates defining its top left and
 * bottom right corners.
 *
 * @param topLeft The NMAGeoCoordinates representing the top left corner of the bounding box
 * @param bottomRight The NMAGeoCoordinates representing the bottom right corner of the bounding box
 * @return The `NMAGeoBoundingBox`
 */
+ (nullable instancetype)geoBoundingBoxWithTopLeft:(nonnull NMAGeoCoordinates *)topLeft bottomRight:(nonnull NMAGeoCoordinates *)bottomRight
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Constructs a `NMAGeoBoundingBox` from NMAGeoCoordinates defining its top right and
 * bottom left corners.
 *
 * @param topRight The NMAGeoCoordinates representing the top right corner of the bounding box
 * @param bottomLeft The NMAGeoCoordinates representing the bottom left corner of the bounding box
 * @return The `NMAGeoBoundingBox`
 */
+ (nullable instancetype)geoBoundingBoxWithTopRight:(nonnull NMAGeoCoordinates *)topRight bottomLeft:(nonnull NMAGeoCoordinates *)bottomLeft
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Constructs a `NMAGeoBoundingBox` from a NMAGeoCoordinates center point and a height and width
 * in degrees.
 *
 * @note If the specified values produce a box with top edge latitude > 90 or bottom edge latitude < -90,
 * the box will be clamped to that range. If the top edge latitude is less than the bottom edge latitude,
 * nil will be returned.
 *
 * @param center The NMAGeoCoordinates representing the center of the bounding box
 * @param width The width of the bounding box in degrees longitude
 * @param height The height of the bounding box in degrees latitude
 * @return The `NMAGeoBoundingBox` if the inputs are valid, else nil
 */
+ (nullable instancetype)geoBoundingBoxWithCenter:(nonnull NMAGeoCoordinates *)center width:(float)width height:(float)height
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Constructs a `NMAGeoBoundingBox` which contains all coordinates in an array.
 *
 * The constructed NMAGeoBoundingBox will be the smallest possible box which contains all
 * the NMAGeoCoordinates in the input array.
 *
 * @param coordinates A `NSArray` of NMAGeoCoordinates defining the new `NMAGeoBoundingBox`
 * @return The `NMAGeoBoundingBox`
 */
+ (nullable instancetype)geoBoundingBoxContainingGeoCoordinates:(nonnull NSArray<NMAGeoCoordinates *> *)coordinates
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Constructs a `NMAGeoBoundingBox` which contains all bounding boxes in an array.
 *
 * The constructed NMAGeoBoundingBox will be the smallest possible box which contains all
 * the NMAGeoBoundingBoxes in the input array.
 * 
 *
 * @param boxes A `NSArray` of NMAGeoBoundingBox defining the new `NMAGeoBoundingBox`
 * @return The `NMAGeoBoundingBox`
 */
+ (nullable instancetype)geoBoundingBoxContainingGeoBoundingBoxes:(nonnull NSArray<NMAGeoBoundingBox *> *)boxes
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Initialize an NMAGeoBoundingBox instance.
 */
- (nonnull instancetype)init;

/**
 * Initializes a `NMAGeoBoundingBox` instance with specified top-left
 * and bottom-right `NMAGeoCoordinates`.
 *
 * @param topLeft A top-left `NMAGeoCoordinates` value for the new
 *                `NMAGeoBoundingBox`
 * @param bottomRight A bottom-right `NMAGeoCoordinates` value for the new
 *                    `NMAGeoBoundingBox`
 * @return The `NMAGeoBoundingBox`
 */
- (nullable instancetype)initWithTopLeft:(nonnull NMAGeoCoordinates *)topLeft bottomRight:(nonnull NMAGeoCoordinates *)bottomRight
NS_SWIFT_NAME(init(topLeft:bottomRight:));

/**
 * Initializes a `NMAGeoBoundingBox` from NMAGeoCoordinates defining its top right and
 * bottom left corners.
 *
 * @param topRight The NMAGeoCoordinates representing the top right corner of the bounding box
 * @param bottomLeft The NMAGeoCoordinates representing the bottom left corner of the bounding box
 * @return The `NMAGeoBoundingBox`
 */
- (nullable instancetype)initWithTopRight:(nonnull NMAGeoCoordinates *)topRight bottomLeft:(nonnull NMAGeoCoordinates *)bottomLeft
NS_SWIFT_NAME(init(topRight:bottomLeft:));

/**
 * Initializes a `NMAGeoBoundingBox` from a NMAGeoCoordinates center point and a height and width
 * in degrees.
 *
 * @note If the specified values produce a box with top edge latitude > 90 or bottom edge latitude < -90,
 * the box will be clamped to that range. If the top edge latitude is less than the bottom edge latitude,
 * nil will be returned.
 *
 * @param center The NMAGeoCoordinates representing the center of the bounding box
 * @param width The width of the bounding box in degrees longitude
 * @param height The height of the bounding box in degrees latitude
 * @return The `NMAGeoBoundingBox` if the inputs are valid, else nil
 */
- (nullable instancetype)initWithCenter:(nonnull NMAGeoCoordinates *)center width:(float)width height:(float)height
NS_SWIFT_NAME(init(center:width:height:));

/**
 * Initializes a `NMAGeoBoundingBox` which contains all coordinates in an array.
 *
 * The constructed NMAGeoBoundingBox will be the smallest possible box which contains all
 * the NMAGeoCoordinates in the input array.
 *
 * @param coordinates A `NSArray` of NMAGeoCoordinates defining the new `NMAGeoBoundingBox`
 * @return The `NMAGeoBoundingBox`
 */
- (nullable instancetype)initContainingGeoCoordinates:(nonnull NSArray<NMAGeoCoordinates *> *)coordinates
NS_SWIFT_NAME(init(coordinates:));


/**
 * Initializes a `NMAGeoBoundingBox` which contains all bounding boxes in an array.
 *
 * The constructed NMAGeoBoundingBox will be the smallest possible box which contains all
 * the NMAGeoBoundingBoxes in the input array.
 *
 * @param boxes A `NSArray` of NMAGeoBoundingBox defining the new `NMAGeoBoundingBox`
 * @return The `NMAGeoBoundingBox`
 */
- (nullable instancetype)initContainingGeoBoundingBoxes:(nonnull NSArray<NMAGeoBoundingBox *> *)boxes
NS_SWIFT_NAME(init(boundingBoxes:));

/**
 * The `NMAGeoBoundingBox` width, in degrees.
 */
@property (nonatomic, readonly) double width;

/**
 * The `NMAGeoBoundingBox` height, in degrees.
 */
@property (nonatomic, readonly) double height;

/**
 * The `NMAGeoCoordinates` representing the top-left corner of the `NMAGeoBoundingBox`.
 */
@property (nonatomic, nonnull) NMAGeoCoordinates *topLeft;

/**
 * The `NMAGeoCoordinates` representing the top-left-front corner of the
 * `NMAGeoBoundingBox`. The altitude of this geocoordinate will be valid only when the
 * `NMAGeoBoundingBox` was created with this information.
 */
@property (nonatomic, readonly, nonnull) NMAGeoCoordinates *topLeftFront;

/**
 * The `NMAGeoCoordinates` representing the top-right corner of the `NMAGeoBoundingBox`.
 */
@property (nonatomic, nonnull) NMAGeoCoordinates *topRight;

/**
 * The `NMAGeoCoordinates` representing the bottom-left corner of the `NMAGeoBoundingBox`.
 */
@property (nonatomic, nonnull) NMAGeoCoordinates *bottomLeft;

/**
 * The `NMAGeoCoordinates` representing the bottom-right corner of the `NMAGeoBoundingBox`.
 */
@property (nonatomic, nonnull) NMAGeoCoordinates *bottomRight;

/**
 * The `NMAGeoCoordinates` representing the bottom-right-back corner of the
 * `NMAGeoBoundingBox`. The altitude of this geocoordinate will be valid only when the
 * `NMAGeoBoundingBox` was created with this information.
 */
@property (nonatomic, readonly, nonnull) NMAGeoCoordinates *bottomRightBack;

/**
 * The `NMAGeoCoordinates` representing the center of the `NAMGeoBoundingBox`.
 */
@property (nonatomic, readonly, weak, nullable) NMAGeoCoordinates *center;

/**
 * The `NAMGeoBoundingBox` area size, in square meters.
 */
@property (nonatomic, readonly, assign) double areaSize;

/**
 * Indicates whether this NMAGeoBoundingBox crosses the international date line
 */
@property (nonatomic, readonly) BOOL crossesInternationalDateLine;

/**
 * Determines whether the specified `NMAGeoCoordinates` object is contained
 * within this `NMAGeoBoundingBox` (boundary included).
 *
 * @param coordinates A `NMAGeoCoordindates` object to check for containment
 *                    within this `NMAGeoBoundingBox`
 * @return YES if contained within the `NMAGeoBoundingBox`, NO otherwise
 */
- (BOOL)containsGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates;

/**
 * Determines whether the specified `NMAGeoBoundingBox` is covered entirely
 * by this `NMAGeoBoundingBox` (boundary included).
 *
 * @param boundingBox A `NMAGeoBoundingBox` to check for containment within
 *                    this `NMAGeoBoundingBox`
 * @return YES if contained within the `NMAGeoBoundingBox`, NO otherwise
 */
- (BOOL)containsGeoBoundingBox:(nonnull NMAGeoBoundingBox *)boundingBox;

/**
 * Determines whether the intesection of this `NMAGeoBoundingBox` and the
 * specified `NMAGeoBoundingBox` is non-empty.
 *
 * @param boundingBox A `NMAGeoBoundingBox` to check for intersection with this
 *                    `NMAGeoBoundingBox`
 * @return YES if the intersection of `NMAGeoBoundingBox` objects is non-empty,
 *         NO otherwise
 */
- (BOOL)intersectsGeoBoundingBox:(nonnull NMAGeoBoundingBox *)boundingBox;

/**
 * Computes the intersection of this and another NMAGeoBoundingBox.
 *
 * @note The interection may have zero area.
 *
 * @param boundingBox The NMAGeoBoundingBox to intersect with
 * @return The NMAGeoBoundingBox representing the intersection, or nil if the
 *          boxes do not uniquely intersect
 */
- (nullable NMAGeoBoundingBox *)intersectionWithGeoBoundingBox:(nonnull NMAGeoBoundingBox *)boundingBox;

/**
 * Determines whether the size of the enclosed `NMAGeoBoundingBox` is 0.
 *
 * @return YES if the size of the enclosed area is 0, NO otherwise
 */
- (BOOL)isEmpty;

/**
 * Determines whether this NMAGeoBoundingBox is equal to another.
 *
 * @return YES if the bounding boxes are equal, NO otherwise
 */
- (BOOL)isEqualToGeoBoundingBox:(nonnull NMAGeoBoundingBox *)boundingBox
NS_SWIFT_NAME(isEqual(_:));

@end
