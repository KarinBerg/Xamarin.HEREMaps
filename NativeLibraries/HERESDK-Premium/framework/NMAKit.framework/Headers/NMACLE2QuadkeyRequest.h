/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMACLE2Request.h"
#import "NMACLE2ResultListener.h"


/**
 * Represents a custom location search request that searches by quadkey tile.
 *
 * A quadkey is a number consisting of digits 0-3 that each subdivide the Mercator
 * projected flat world map into quadrants. Use this search to retrieve geometries
 * that overlap exactly certain tiles of a quadkey-tile.
 *
 * For details on how the map is devided to form quadkeys see QuadKey basic concepts at
 * https://developer.here.com/rest-apis/documentation/venue-maps/topics/key-concepts.html
 *
 * A new `NMACLE2QuadkeyRequest` should be created for each distinct search.
 */
@interface NMACLE2QuadkeyRequest : NMACLE2Request

/**
 * Creates a Quadkey Search Request.
 *
 * @param layerId Name of the layer specifying the layer to search.
 * @param quadKey The quadKey to search in. Quadkey example: 12021023322201
 * @note Returns nil if initialization failed.
 */
- (nullable instancetype)initWithLayer:(nonnull NSString *)layerId quadKey:(nonnull NSString *)quadKey
NS_SWIFT_NAME(init(layerId:quadKey:));

/**
 * Creates a Quadkey Search Request that searches through multiple layers.
 *
 * @param layerIds An `NSArray` with names specifying the layers to search.
 * @param quadKey The quadKey to search in. Quadkey example: 12021023322201
 * @note Returns nil if initialization failed. The query assures that only expression
 * which evaluates to true will be returned.
 */
- (nullable instancetype)initWithLayers:(nonnull NSArray<NSString *> *)layerIds quadKey:(nonnull NSString *)quadKey
NS_SWIFT_NAME(init(layerIds:quadKey:));

@end
