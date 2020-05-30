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
 * Represents a custom geometry search request to retrieve all user-defined geometries
 * along with its attribute on a specified layer.
 *
 * A new `NMACLE2AttributeRequest` should be created for each distinct search.
 *
 * @note this class is currently only supported in online mode.
 */
@interface NMACLE2AttributeRequest : NMACLE2Request

/**
 * Creates an Attribute Search Request. This method returns nil if initialization failed.
 *
 * @param layerId Layer name to search.
 * @param query A JavaScript expression as a string being evaluated for each geometry.
 *
 * @note The query assures that only expressions that evaluate to true are returned.
 * An example of a query is: "RATING > 3 && NAME != 'MyPlace23'"
 *
 */
- (nullable instancetype)initWithLayer:(nonnull NSString *)layerId query:(nonnull NSString *)query;

/**
 * Creates an Attribute Search Request that searches through multiple layers.
 * This method returns nil if initialization failed.
 *
 * @param layerIds An `NSArray` with names specifying the layers to search.
 * @param query A JavaScript expression as a string being evaluated for each geometry.
 *
 * @note the query assures that only expression which evaluates to true will be returned.
 *
 */
- (nullable instancetype)initWithLayers:(nonnull NSArray<NSString *> *)layerIds query:(nonnull NSString *)query;

@end
