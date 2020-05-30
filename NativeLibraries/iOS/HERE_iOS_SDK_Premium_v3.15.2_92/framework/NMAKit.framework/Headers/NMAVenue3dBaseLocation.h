/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAVenue3dArea;
@class NMAGeoCoordinates;


/**
 * Defines a location type in indoor routing.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dBaseLocationType) {
    /**
     * Space location
     */
    NMAVenue3dBaseLocationTypeSpace,

    /**
     * Outdoor location - point on the map
     */
    NMAVenue3dBaseLocationTypeOutdoor,

    /**
     * Level location - point on level inside venue
     */
    NMAVenue3dBaseLocationTypeLevel,

    /**
     * undefined - error
     */
    NMAVenue3dBaseLocationTypeOther
};


/**
 *
 * Defines a location used in indoor routing.
 *
 * See also `NMAVenue3dSpaceLocation`
 *
 * See also `NMAVenue3dOutdoorLocation`
 *
 * See also `NMAVenue3dRoutingController`
 */
@interface NMAVenue3dBaseLocation : NSObject

/**
 * Sets the parking location.
 *
 * @param location  The parking location to set.
 */
- (void)setParkingLocation:(nonnull NMAVenue3dBaseLocation*)location;

/**
 * Returns information on the validity of the location.
 *
 * @return YES if the location is valid and NO otherwise.
 */
- (BOOL)isValid;

/**
 * Returns the NMAVenue3dArea associated with the location.
 * If the location relates to a Space, returns an NMAVenue3dSpace object.
 * If the location relates to an OuterArea, returns an NMAVenue3dOuterArea object.
 * Otherwise returns nil.
 *
 * @return The Area associated with the location or nil.
 */
- (nullable NMAVenue3dArea *)getArea NS_SWIFT_NAME(area());

/**
 * Returns the NMAGeoCoordinates associated with the location.
 *
 * @return The NMAGeoCoordinates associated with the location
 */
- (nullable NMAGeoCoordinates *)getGeoCoordinate NS_SWIFT_NAME(geoCoordinate());

/**
 * Returns the NMAVenue3dBaseLocationType of the location.
 *
 * @return The NMAVenue3dBaseLocationType of the location.
 */
- (NMAVenue3dBaseLocationType)getType NS_SWIFT_NAME(type());

@end
