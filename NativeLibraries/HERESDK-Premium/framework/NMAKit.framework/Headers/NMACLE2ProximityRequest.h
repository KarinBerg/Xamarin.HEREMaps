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
@class NMAGeoPolygon;


/**
 * Represents a custom location search request that uses the area around a location to retrieve
 * user-defined geometries.
 *
 * A new `NMACLE2ProximityRequest` should be created for each distinct search.
 */
@interface NMACLE2ProximityRequest : NMACLE2Request

/**
 * Creates a Proximity Search Request.
 *
 * @param layerId Name of the layer specifying the layer to search.
 * @param coordinates Specify the `NMAGeoCoordinates` used as the search center.
 * @param radius An NSInteger specifying the search radius in meters.
 * @note Returns nil if initialization failed.
 *
 */
- (nullable instancetype)initWithLayer:(nonnull NSString *)layerId
                                center:(nonnull NMAGeoCoordinates *)coordinates
                                radius:(NSInteger)radius;

/**
 * Creates a Proximity Search Request that searches through multiple layers.
 *
 * @param layerIds An `NSArray` with names specifying the layers to search.
 * @param coordinates Specify the `NMAGeoCoordinates` used as the search center.
 * @param radius An NSInteger specifying the search radius in meters.
 * @note Returns nil if initialization failed.
 *
 */
- (nullable instancetype)initWithLayers:(nonnull NSArray<NSString *> *)layerIds
                                 center:(nonnull NMAGeoCoordinates *)coordinates
                                 radius:(NSInteger)radius;

@end
