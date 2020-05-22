/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAReverseGeocodeRequest.h"

@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;
@class NMAGeocodeRequest;
@class NMAAddress;



/**
 * Represents a factory used to instantiate geocoder requests.
 *
 * A `NMAGeocoder` enables searching for location data by way of the following
 * search services:
 *
 * 1. Structured Address Geocode - matches a `NMAAddress` to its correct
 *     `NMAPlaceLocation` on the map (its latitude and longitude).
 *
 * 2. One box Geocode - matches a free text query (and location context) to
 *     its correct `NMAPlaceLocation` on the map (its latitude and longitude).
 *
 * 3. Reverse Geocode - retrieves a `NMAPlaceLocation`
 *     based on a given `NMAGeoCoordinates`.
 *
 * @note `NMAGeocoder` requires valid authentication credentials to be set via
 * `NMAApplicationContext`. If valid credentials are not present an attempt to
 * call sharedNMAGeocoder will result in a runtime assert.
 */
@interface NMAGeocoder : NSObject

/**
 * Returns the `NMAGeocoder` singleton instance.
 *
 * @note Use this method to obtain a `NMAGeocoder` instance. Do not call
 * init directly.
 *
 * @return shared `NMAGeocoder` instance
 */
+ (nonnull NMAGeocoder *)sharedGeocoder NS_SWIFT_NAME(sharedInstance());

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Creates a reverse geocoder request that resolves a
 * NMAGeoCoordinates context into a NMAPlaceLocation.
 * After creating the request, [request startWithListener:(id<NMAResultListener>)] needs
 * to be called to start the search.
 *
 * @param geoCoordinates A query NMAGeoCoordinates context
 * @return The NMAReverseGeocodeRequest
 */
- (nonnull NMAReverseGeocodeRequest *)createReverseGeocodeRequestWithGeoCoordinates:(nonnull NMAGeoCoordinates *)geoCoordinates
NS_SWIFT_NAME(createReverseGeocodeRequest(coordinates:));

/**
 * Creates a reverse geocoder request that resolves a
 * NMAGeoCoordinates context into a NMAPlaceLocation using geocode mode.
 * After creating the request, [request startWithListener:(id<NMAResultListener>)] needs
 * to be called to start the search.
 *
 * @param geoCoordinates A query NMAGeoCoordinates context
 * @param geocodeMode Reverse Geocode mode
 * @param bearing Used only in NMAReverseGeocodeModeTrackPosition mode.
 *                 Expresses the direction in which an asset is heading in degrees
 *                 starting at true north and continuing clockwise around the compass.
 *
 * @return The NMAReverseGeocodeRequest
 */
- (nonnull NMAReverseGeocodeRequest *)createReverseGeocodeRequestWithGeoCoordinates:(nonnull NMAGeoCoordinates *)geoCoordinates
                                                                               mode:(NMAReverseGeocodeMode)geocodeMode
                                                                            bearing:(float)bearing
NS_SWIFT_NAME(createReverseGeocodeRequest(coordinates:mode:bearing:));

/**
 * Creates a geocoder request that resolves a free text query
 * into an array of NMAPlaceLocation.
 * After creating the request, [request startWithListener:(id<NMAResultListener>)] needs
 * to be called to start the search.
 *
 * @param query Query text specifying the search item to locate
 * @param searchArea NMAGeoBoundingBox representing the search area.
 *                 Note that the search area may be ignored if the query text already
 *                 specifies a search area, such as a state.
 *
 * @return The NMAGeocodeRequest
 */
- (nonnull NMAGeocodeRequest *)createGeocodeRequestWithQuery:(nullable NSString *)query
                                                  searchArea:(nullable NMAGeoBoundingBox *)searchArea
NS_SWIFT_NAME(createGeocodeRequest(query:searchArea:));

/**
 * Creates a geocoder request that resolves a free text query
 * into an array of NMAPlaceLocation.
 * After creating the request, [request startWithListener:(id<NMAResultListener>)] needs
 * to be called to start the search.
 *
 * @param query Query text specifying the search item to locate
 * @param searchRadius Radius in meters, in which the search should be performed
 * @param searchCenter NMAGeoCoordinates object representing the location
 *                 context used to search for results that are
 *                 appropriate to the query parameter.  Note that this search
 *                 location can be overridden if the query text already specifies a
 *                 search area, such as a state.
 *
 * @return The NMAGeocodeRequest
 */
- (nonnull NMAGeocodeRequest *)createGeocodeRequestWithQuery:(nullable NSString *)query
                                                searchRadius:(NSInteger)searchRadius
                                                searchCenter:(nullable NMAGeoCoordinates *)searchCenter
NS_SWIFT_NAME(createGeocodeRequest(query:searchRadius:searchCenter:));

@end
