/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dBaseLocation.h"

@class NMAVenue3dSpace;
@class NMAVenue3dController;


/**
 * Defines an indoor location used as either start or endpoint in indoor routing.
 *
 * See also `NMAVenue3dSpaceLocation`
 *
 * See also `NMAVenue3dOutdoorLocation`
 *
 * See also `NMAVenue3dRoutingController`
 */

@interface NMAVenue3dSpaceLocation : NMAVenue3dBaseLocation

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Constructs an NMASpaceLocation with the specified indoor space and venue controller
 * of the venue the space is located.
 *
 * @param space A space object
 * @param venue A venue controller object
 */
+ (nullable instancetype)spaceLocationWithSpace:(nonnull NMAVenue3dSpace *)space
                                        inVenue:(nonnull NMAVenue3dController *)venue
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Constructs an NMASpaceLocation with the specified indoor space and venue controller
 * of the venue the space is located.
 *
 * @param space A space object
 * @param venue A venue controller object
 */
- (nullable instancetype)initWithSpace:(nonnull NMAVenue3dSpace *)space
                               inVenue:(nonnull NMAVenue3dController *)venue
NS_SWIFT_NAME(init(at:in:));

@end
