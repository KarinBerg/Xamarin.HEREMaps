/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMACLE2Request.h"
#import "NMACLE2ResultListener.h"

@class NMAGeoCoordinates;
@class NMARoute;
@class NMAGeoPolygon;


/**
 * Represents a custom location search request that searches along a
 * route specified by a sequence of coordinates and radius.
 *
 * A new `NMACLE2CorridorRequest` should be created for each distinct search.
 */
@interface NMACLE2CorridorRequest : NMACLE2Request

/**
 * Creates a Corridor Search Request.
 *
 * @param layerId Name of the layer specifying the layer to search.
 * @param coordinatesArray Specify the `NMAGeoCoordinates` of the polyline used as the search center line.
 * @param radius An NSInteger specifying the search radius in meters. All geometries overlapping the
 * corridor polygon will be returned.
 *
 * @note A coordinatesArray size is limited by the maximum URI length of HTTP Get request.
 * In case you need to create a corridor with multiple points exceeding maximum allowed
 * URI length, you have to divide corridor into few parts.
 *
 * @note Returns nil if initialization failed.
 */
- (nullable instancetype)initWithLayer:(nonnull NSString *)layerId
                              corridor:(nonnull NSArray<NMAGeoCoordinates *> *)coordinatesArray
                                radius:(NSInteger)radius;

/**
 * Creates a Corridor Search Request that searches through multiple layers.
 *
 * @param layerIds An `NSArray` with names specifying the layers to search.
 * @param coordinatesArray Specify the `NMAGeoCoordinates` of the polyline used as the search center line.
 * @param radius An NSInteger specifying the search radius in meters.
 *
 * @note A coordinatesArray size is limited by the maximum URI length of HTTP Get request.
 * In case you need to create a corridor with multiple points exceeding maximum allowed
 * URI length, you have to divide corridor into few parts.
 *
 * @note Returns nil if initialization failed.
 */
- (nullable instancetype)initWithLayers:(nonnull NSArray<NSString *> *)layerIds
                               corridor:(nonnull NSArray<NMAGeoCoordinates *> *)coordinatesArray
                                 radius:(NSInteger)radius;

/**
 * Creates a Corridor Search Request from a given `NMARoute`.
 *
 * @param layerId Name of the layer specifying the layer to search.
 * @param route Specify the `NMARoute` to be used as the search center line.
 * @param radius An NSInteger specifying the search radius in meters. All geometries overlapping the
 * corridor polygon will be returned.
 * @note Returns nil if initialization failed.
 *
 */
- (nullable instancetype)initWithLayer:(nonnull NSString *)layerId
                                 route:(nonnull NMARoute *)route
                                radius:(NSInteger)radius;

/**
 * Creates a Corridor Search Request that searches through multiple layers from a given `NMARoute`.
 *
 * @param layerIds An `NSArray` with names specifying the layers to search.
 * @param route Specify the `NMARoute` used as the search center.
 * @param radius An NSInteger specifying the search radius in meters.
 * @note Returns nil if initialization failed.
 *
 */
- (nullable instancetype)initWithLayers:(nonnull NSArray<NSString *> *)layerIds
                                  route:(nonnull NMARoute *)route
                                 radius:(NSInteger)radius;

@end
