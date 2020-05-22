/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAProxyObject.h"

@class NMAGeoBoundingBox;
@class NMAMapMarker;



/**
 * Cluster map proxy object. Returned when using NMAMapView:objectsAtPoint.
 */
@interface NMAClusterViewObject : NMAProxyObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Array of `NMAMapMarker` instances stored in this cluster.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAMapMarker *> *markers;

/**
 * Bounding box of the cluster.
 */
@property (nonatomic, readonly, nonnull) NMAGeoBoundingBox *boundingBox;

@end
