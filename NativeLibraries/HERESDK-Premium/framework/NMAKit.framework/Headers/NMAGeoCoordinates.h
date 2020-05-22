/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * Indicates unknown altitude value.
 */
FOUNDATION_EXPORT float const NMAGeoCoordinatesUnknownAltitudeValue;

/**
 * Indicates invalid value.
 */
FOUNDATION_EXPORT double const NMAGeoCoordinatesInvalidValue;



/**
 * Represents WGS84 coordinates with double precision. A `NMAGeoCoordinates`
 * encapsulates a latitude and longitude value, plus an optional altitude value.
 *
 * @note Although `NMAGeoCoordinates` are accepted and handled with double
 * precision (about 15 significant digits), the real precision of rendering
 * operations such as NMAMapView::setCenterAt might be lower due to internal conversions.
 * Overall precision of `NMAGeoCoordinates` can be assured for only six digits
 * following the decimal point.
 */
@interface NMAGeoCoordinates : NSObject<NSCoding>

/**
 * Constructs a NMAGeoCoordinates with the specified latitude and longitude.
 *
 * @param latitude An initial latitude value
 * @param longitude An initial longitude value
 */
+ (nonnull instancetype)geoCoordinatesWithLatitude:(double)latitude longitude:(double)longitude
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Constructs a NMAGeoCoordinates with the specified latitude, longitude,
 * and altitude.
 *
 * @param latitude An initial latitude value
 * @param longitude An initial longitude value
 * @param altitude An initial altitude value
 */
+ (nonnull instancetype)geoCoordinatesWithLatitude:(double)latitude longitude:(double)longitude altitude:(double)altitude
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Initializes an `NMAGeoCoordinates` instance with latitude 0 and longitude 0
 */
- (nonnull instancetype)init;

/**
 * Initializes an `NMAGeoCoordinates` instance with specified latitude and
 * longitude values and NMAGeoCoordinatesUnknownAltitudeValue altitude.
 *
 * @param latitude An initial latitude value. Values outside of [-90, 90] will
 * be clamped to that range (100 becomes 90).
 * @param longitude An initial longitude value. Values outside of [-180, 180]
 * will be wrapped to that range (200 becomes -160).
 * @return The `NMAGeoCoordinates` instance, or nil if initialization failed
 */
- (nonnull instancetype)initWithLatitude:(double)latitude longitude:(double)longitude;

/**
 * Initializes an `NMAGeoCoordinates` instance with specified values for
 * the initial latitude, longitude and altitude.
 *
 * @param latitude An initial latitude value
 * @param longitude An initial longitude value
 * @param altitude An initial altitude value
 * @return The `NMAGeoCoordinates` instance, or nil if initialization failed
 */
- (nonnull instancetype)initWithLatitude:(double)latitude longitude:(double)longitude altitude:(float)altitude;

/**
 * The latitude, as measured in degrees, representing north-south coordinate
 * (y-axis on a map).
 *
 * @note The latitude must be in the range [-90, 90]. Values outside this range
 * will be clamped.
 */
@property (nonatomic) double latitude;

/**
 * The longitude, as measured in degrees, representing east-west coordinate
 * (x-axis on a map).
 *
 * @note The longitude must be in the range [-180, 180]. Values outside this range
 * will be wrapped. For example, a value of 200 degrees will be wrapped to -160.
 */
@property (nonatomic) double longitude;

/**
 * The altitude of the NMAGeoCoordinates measured in meters above sea-level.
 *
 * By default, the plane of the map is at 0 meters. Thus, geocoordinates with positive
 * altitudes represent points above the plane of the map, while negative altitudes are
 * below the plane of the map. Map objects with these coordinates will be displayed
 * accordingly.
 *
 * @note Valid values are in the range [-10000.0, 10000.0]. If an invalid value is
 * specified, it will be adjusted to the closest possible valid value (e.g. a
 * specified value of -10200.0 will be set to -10000.0).
 *
 * @note NMAGeoCoordinatesUnknownAltitudeValue if altitude is unknown.
 */
@property (nonatomic) float altitude;

/**
 * Calculates (using the Haversine formula) the distance in meters between
 * this `NMAGeoCoordinates` instance and the specified `NMAGeoCoordinates`.
 *
 * @param coordinates A second `NMAGeoCoordinates` some distance away
 * @return The distance between the `NMAGeoCoordinates`, or NMAGeoCoordinatesInvalidValue if
 *         the coordinates parameter is nil
 */
- (double)distanceTo:(nonnull NMAGeoCoordinates *)coordinates;


/**
 * Calculates the heading in degrees from this `NMAGeoCoordinates` instance
 * to the specified `NMAGeoCoordinates` instance.
 *
 * @param coordinates NMAGeoCoordinates to which to the heading is calculated.
 * @return Heading from this coordinate to the given coordinate, in degrees.
 *         0 = north, increasing clockwise. If coordinates is nil,
 *         NMAGeoCoordinatesInvalidValue will be returned to indicate an error.
 */
- (double)headingTo:(nonnull NMAGeoCoordinates *)coordinates;

/**
 * Determines whether this NMAGeoCoordinates is equal to another.
 *
 * Coordinates are considered equal if the distance between them is <= 1M. Altitude is
 * not considered.
 *
 * @return YES if the coordinates are equal, NO otherwise
 */
- (BOOL)isEqualToGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates
NS_SWIFT_NAME(isEqual(_:));

@end
