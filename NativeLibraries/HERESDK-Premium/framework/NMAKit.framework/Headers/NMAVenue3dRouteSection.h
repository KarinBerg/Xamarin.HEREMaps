/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


/**
 * Represents values that describe the route sections types used in indoor routing.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dRouteSectionType) {
    /**
     * Route section is inside a venue.
     */
    NMAVenue3dRouteSectionTypeVenue,

    /**
     * Route section is outside a venue.
     */
    NMAVenue3dRouteSectionTypeOutdoor,

    /**
     * Route section describes a direct line from the start to the end point of the section,
     * where there is no turn-by-turn routing data available. This occurs
     * in sections where one end is inside a venue and other end is outside a venue.
     */
    NMAVenue3dRouteSectionTypeLink
};


/**
 * Base class for indoor route sections. Indoor route can contain
 *        sections that are inside venue, outside venue, and link sections
 *        that typically connect indoor and outdoor locations.
 *
 * See also `NMAVenue3dVenueRouteSection`
 *
 * See also `NMAVenue3dOutdoorRouteSection`
 *
 * See also `NMAVenue3dLinkRouteSection`
 */
@interface NMAVenue3dRouteSection : NSObject

@end
