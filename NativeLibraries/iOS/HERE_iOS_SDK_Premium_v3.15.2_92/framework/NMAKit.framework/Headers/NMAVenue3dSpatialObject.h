/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */



/**
 * Represents a physical space in a map. This space is defined by a unique identifier of the space.
 *
 * See also `NMAVenue3dArea`
 *
 * See also `NMAVenue3dOuterArea`
 *
 * See also `NMAVenue3dSpace`
 *
 * See also `NMAVenue3dVenue`
 */
@interface NMAVenue3dSpatialObject : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The string which uniquely identifies this NMAVenue3dSpatialObject.
 */
@property (nonatomic, readonly, nonnull) NSString *uniqueId;

@end
