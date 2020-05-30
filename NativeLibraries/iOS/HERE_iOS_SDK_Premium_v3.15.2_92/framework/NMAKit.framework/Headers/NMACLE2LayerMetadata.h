/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * The Custom Location Extensions 2 group provides classes and protocols
 * that support advanced custom location searches.
 */

/**
 * Encapsulates metadata describing a CLE2 layer.
 */
@interface NMACLE2LayerMetadata : NSObject

/**
 * The id (name) of the layer
 */
@property (nullable, nonatomic, readonly) NSString *layerId;

/**
 * For layers on remote CLE2 service this indicates
 * time of last modification of any data contained within the layer.
 * For layers stored locally, this is a timestamp of a CLE2 layer
 * as it was at the time it was downloaded from remote CLE2 service.
 * Layers that were created and stored locally do not have a timestamp.
 */
@property (nullable, nonatomic, readonly) NSDate *timestamp;

@end
