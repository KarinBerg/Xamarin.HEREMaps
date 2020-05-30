/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dBaseLocation.h"

@class NMAVenue3dLevel;
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

@interface NMAVenue3dLevelLocation : NMAVenue3dBaseLocation

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Constructs an NMAVenue3dLevelLocation object.
 *
 * @param level A Level object
 * @param geoCoordinates A geocoordinate object
 * @param controler A VenueControler object representing a venue where the space is located
 */
+ (nullable instancetype)levelLocationOnLevel:(nonnull NMAVenue3dLevel *)level
                            withGeoCoordinate:(nonnull NMAGeoCoordinates *)geoCoordinates
                                      inVenue:(nonnull NMAVenue3dController *)controler
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Constructs an NMAVenue3dLevelLocation object.
 *
 * @param level A Level object
 * @param geoCoordinates A geocoordinate object
 * @param venue A VenueControler object representing a venue where the space is located
 */
- (nullable instancetype)initOnLevel:(nonnull NMAVenue3dLevel *)level
                   withGeoCoordinate:(nonnull NMAGeoCoordinates *)geoCoordinates
                             inVenue:(nonnull NMAVenue3dController *)venue
NS_SWIFT_NAME(init(on:at:in:));

@end
