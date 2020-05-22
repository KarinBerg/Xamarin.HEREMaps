/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dRouteSection.h"

@class NMARoute;
@class NMAGeoBoundingBox;



/**
 * Represents route section outside a venue. An Indoor route can contain
 *        sections that are inside venue, outside venue, and link sections
 *        that typically connect indoor and outdoor locations.
 *
 * See also `NMAVenue3dVenueRouteSection`
 *
 * See also `NMAVenue3dLinkRouteSection`
 */
@interface NMAVenue3dOutdoorRouteSection : NMAVenue3dRouteSection

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The NMARoute object.
 */
@property (nonatomic, readonly, nonnull) NMARoute *route;

/**
 * The bounding box of this NMAVenue3dOutdoorRouteSection
 */
@property (nonatomic, readonly, nonnull) NMAGeoBoundingBox *boundingBox;

@end
