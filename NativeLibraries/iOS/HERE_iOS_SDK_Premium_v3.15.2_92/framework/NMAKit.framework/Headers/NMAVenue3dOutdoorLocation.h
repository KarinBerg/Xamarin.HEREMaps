/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dBaseLocation.h"

@class NMAGeoCoordinates;



/**
 * Defines an outdoor location used as either start or endpoint in indoor routing.
 *
 * See also `NMAVenue3dSpaceLocation`
 *
 * See also `NMAVenue3dOutdoorLocation`
 *
 * See also `NMAVenue3dRoutingController`
 */
@interface NMAVenue3dOutdoorLocation : NMAVenue3dBaseLocation

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Constructs an NMAOutdoorLocation with the specified geocoordinates.
 *
 * @param geoCoordinates A geocoordinate object
 */
+ (nonnull instancetype)outdoorLocationWithGeoCoordinates:(nonnull NMAGeoCoordinates *)geoCoordinates
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Initializes an NMAOutdoorLocation with the specified geocoordinates.
 *
 * @param geoCoordinates A geocoordinate object
 */
- (nonnull instancetype)initWithGeoCoordinates:(nonnull NMAGeoCoordinates *)geoCoordinates
NS_SWIFT_NAME(init(at:));

@end
