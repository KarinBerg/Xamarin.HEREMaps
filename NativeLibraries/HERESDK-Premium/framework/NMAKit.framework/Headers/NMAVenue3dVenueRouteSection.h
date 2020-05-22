/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dRouteSection.h"
#import "NMAVenue3dLevel.h"
#import "NMAVenue3dVenue.h"

@class NMAVenue3dRouteManeuver;



/**
 * Represents route section inside a venue. Indoor route can contain
 *        sections that are inside venue, outside venue, and link sections
 *        that typically connect indoor and outdoor locations.
 *
 * See also `NMAVenue3dOutdoorRouteSection`
 *
 * See also `NMAVenue3dLinkRouteSection`
 */
@interface NMAVenue3dVenueRouteSection : NMAVenue3dRouteSection

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The bounding box of this NMAVenue3dVenueRouteSection
 * Returned bounding box will contain information about altitude.
 */
@property (nonatomic, readonly, nonnull) NMAGeoBoundingBox *boundingBox;

/**
 * The bounding box of this NMAVenue3dVenueRouteSection
 * on NMAVenue3dLevel. Returns null if the route does not
 * touch the given level.
 */
- (nullable NMAGeoBoundingBox *)boundingBox:(nonnull NMAVenue3dLevel *)level;

/**
 * The NMAVenue3dVenue object this NMAVenue3dVenueRouteSection is in.
 */
@property (nonatomic, readonly, nonnull) NMAVenue3dVenue *venue;

/**
 * The array of NMAVenue3dRouteManeuver objects for this route section.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAVenue3dRouteManeuver *> *routeManeuvers;

@end
