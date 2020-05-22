/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMACLE2Request.h"
#import "NMACLE2ResultListener.h"

@class NMAGeoBoundingBox;


/**
 * Represents a custom location search request that searches within a `NMAGeoBoundingBox`
 *
 * A new `NMACLE2BoundingBoxRequest` should be created for each distinct search.
 */
@interface NMACLE2BoundingBoxRequest : NMACLE2Request

/**
 * Creates a Bounding Box Search Request.
 *
 * @param layerId Name of the layer specifying the layer to search.
 * @param boundingBox Specify the `NMAGeoBoundingBox` used for the search.
 * @note Returns nil if initialization failed.
 *
 */
- (nullable instancetype)initWithLayer:(nonnull NSString *)layerId
                           boundingBox:(nonnull NMAGeoBoundingBox *)boundingBox;

/**
 * Creates a Bounding Box Search Request that searches through multiple layers.
 *
 * @param layerIds An `NSArray` with names specifying the layers to search.
 * @param boundingBox Specify the `NMAGeoBoundingBox` used for the search.
 * @note Returns nil if initialization failed.
 *
 */
- (nullable instancetype)initWithLayers:(nonnull NSArray<NSString *> *)layerIds
                            boundingBox:(nonnull NMAGeoBoundingBox *)boundingBox;

@end
