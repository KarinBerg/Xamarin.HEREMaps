/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dSpatialObject.h"

@class NMAGeoBoundingBox;



/**
 * NMAVenue3dVenueInfo contains identification and location information for a venue.
 *
 * This class is returned by search methods
 * `NMAVenue3dService::venuesInGeoBoundingBox:` and
 * `NMAVenue3dService::venueWithId:`.
 * The NMAMapView can be centered based on geocoordinates of the venue returned by `boundingBox`.
 * A venue can be opened using the venue identifier returned by `NMAVenue3dSpatialObject::uniqueId`.
 */
@interface NMAVenue3dVenueInfo : NMAVenue3dSpatialObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The NMAGeoBoundingBox of the venue. A NMAGeoBoundingBox is an area defined by minimum and
 * maximum longitudes and latitudes of the venue.
 */
@property (nonatomic, readonly, nonnull) NMAGeoBoundingBox *boundingBox;

/**
 * The name of the venue.
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 * Returns true if the venue is located in an alternative source.
 * More information about primary and alternative sources can be found in
 * `NMAVenue3dService::combinedContent`.
 */
@property (nonatomic, readonly) BOOL isAlternativeSource;

@end
