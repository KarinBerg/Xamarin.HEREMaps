/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dSpatialObject.h"

@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;
@class NMAGeoPolygon;



/**
 * An NMAVenue3dArea object conceptually represents a physical area within a NMAVenue3dVenue.
 *
 * The area can be of either NMAVenue3dOuterArea or NMAVenue3dSpace type, which both have
 * a bounding box and center coordinates, and possibly a polygon.
 * The NMAVenue3dArea class encapsulates these parameters.
 *
 * This class can not be instantiated directly. Subclasses NMAVenue3dOuterArea and NMAVenue3dSpace can be
 * obtained by methods of NMAVenue3dLevel.
 *
 * See also `NMAVenue3dVenue`
 *
 * See also `NMAVenue3dLevel`
 *
 * See also `NMAVenue3dOuterArea`
 *
 * See also `NMAVenue3dSpace`
 */
@interface NMAVenue3dArea : NMAVenue3dSpatialObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The NMAGeoCoordinates representing the center of the bounding box of the NMAVenue3dArea.
 *
 * See also `NMAGeoCoordinates`
 */
@property (nonatomic, readonly, nonnull) NMAGeoCoordinates *geoCenter;

/**
 * The NMAGeoBoundingBox representing the area of the NMAVenue3dArea.
 *
 * See also `NMAGeoBoundingBox`
 */
@property (nonatomic, readonly, nonnull) NMAGeoBoundingBox *boundingBox;

/**
 * The NMAGeoPolygon surrounding tthe NMAVenue3dArea.
 *
 * See also `NMAGeoPolygon`
 */
@property (nonatomic, readonly, nullable) NMAGeoPolygon *polygon;

/**
 * The NSString representing the human-readable name related to the holder
 * of the spatial area. This can be, for example, the name of a shop.
 */
@property (nonatomic, readonly, nullable) NSString *name;

@end
