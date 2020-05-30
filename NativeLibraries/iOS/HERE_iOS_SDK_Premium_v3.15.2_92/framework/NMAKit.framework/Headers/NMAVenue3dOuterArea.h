/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dArea.h"

@class NMAVenue3dSpace;



/**
 * The NMAVenue3dOuterArea represents the physical outer area of the NMAVenue3dLevel in the NMAVenue3dVenue.
 *
 * There may be several outer areas for the level, depending on the physical appearance of the building.
 * This class can be used to get NMAVenue3dSpace objects related to this
 * outer area.
 * 
 * NMAVenue3dOuterArea cannot be instantiated directly. Instead, it can be obtained by calling `NMAVenue3dLevel::outerAreas`.
 *
 * See also `NMAVenue3dVenue`
 *
 * See also `NMAVenue3dLevel`
 *
 * See also `NMAVenue3dSpace`
 *
 * See also `NMAVenue3dVenue`
 */
@interface NMAVenue3dOuterArea : NMAVenue3dArea

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The array of NMAVenue3dSpace objects for this NMAVenue3dOuterArea.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAVenue3dSpace *> *spaces;

/**
 * Returns the space inside the outer area at a given position.
 *
 * @param   position    The position at which to return the space.
 *
 * @return  The space or nil.
 */
- (nullable NMAVenue3dSpace *)spaceAtPosition:(nonnull NMAGeoCoordinates *)position
NS_SWIFT_NAME(space(at:));

/**
 * Returns spaces intersecting a circle with a given radius around a given position.
 *
 * @param position  The position around which to search.
 * @param radius    The radius around the position within which to search.
 *
 * @returns         A (possibly empty) array of nearby spaces.
 */
 - (nonnull NSArray<NMAVenue3dSpace *> *)nearbySpacesAroundPosition:(nonnull NMAGeoCoordinates *)position
                                                       withinRadius:(float)radius
NS_SWIFT_NAME(nearbySpaces(around:radius:));

@end
