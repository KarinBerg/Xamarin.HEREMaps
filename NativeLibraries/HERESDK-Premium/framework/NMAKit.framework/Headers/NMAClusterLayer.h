/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAClusterTheme;
@class NMAMapMarker;



/**
 * `NMAClusterLayer` is a container of `NMAMapMarker`.
 * Once added to the layer markers will start to cluster when the layer is attached to the map.
 * @note It should be some delay between operations of adding and removing a marker due to
 * asynchronous nature of these operations. Otherwise might occur situation when you try to remove
 * not added marker yet and it gets shown in a little while on a map.
 */
@interface NMAClusterLayer : NSObject

/**
 * Theme used during cluster markers rendering.
 */
@property (nonatomic, nonnull) NMAClusterTheme *theme;

/**
 * Array of `NMAMapMarker` instances stored in this layer.
 */
@property (nonatomic, readonly, nonnull) NSArray *markers;

/**
 * Initialize a `NMAClusterLayer` instance
 */
- (nonnull instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Constructs an empty `NMAClusterLayer`.
 */
+ (nonnull instancetype)clusterLayer
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Adds a marker to this layer.
 *
 * @param marker `NMAMapMarker` to be added.
 *
 * @return YES if the marker was successfully added.
 */
- (BOOL)addMarker:(nonnull NMAMapMarker *)marker;

/**
 * Adds an array of markers to this layer.
 *
 * @param markers Array of `NMAMapMaker` instances.
 *
 * @return YES if at least one marker was successfully added.
 */
- (BOOL)addMarkers:(nonnull NSArray<NMAMapMarker *> *)markers;

/**
 * Removes a marker from this layer.
 *
 * @param marker `NMAMapMarker` to be removed.
 *
 * @return YES if the marker was successfully removed.
 */
- (BOOL)removeMarker:(nonnull NMAMapMarker *)marker;

/**
 * Removes an array of markers from this layer.
 *
 * @param markers Array of `NMAMapMaker` instances.
 *
 * @return YES if at least one marker was successfully removed.
 */
- (BOOL)removeMarkers:(nonnull NSArray<NMAMapMarker *> *)markers;
@end
