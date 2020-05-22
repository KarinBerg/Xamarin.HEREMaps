/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAPlaceLocation;

/**
 * Represents an invalid reverse geocoding result distance
 */
FOUNDATION_EXPORT const float NMAReverseGeocodeResultInvalidDistance;


/**
 * Represents the result of a reverse geocoding request.
 *
 * The data of a reverse geocoding result is represented by an instance of
 * `NMAPlaceLocation`, accessed via the location property. The distance
 * between the result and the original search location is give by the
 * distance property.
 */
@interface NMAReverseGeocodeResult : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The location data of the reverse geocode result.
 */
@property (nullable, nonatomic, readonly) NMAPlaceLocation *location;

/**
 * The distance between the result and the search input coordinates.
 *
 * Contains `NMAReverseGeocodeResultInvalidDistance` if the distance is invalid.
 */
@property (nonatomic, readonly) float distance;

@end
