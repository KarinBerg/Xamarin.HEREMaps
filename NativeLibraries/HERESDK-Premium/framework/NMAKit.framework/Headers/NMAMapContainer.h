/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAMapObject.h"

@class NMAGeoCoordinates;



/**
 * A container of NMAMapObject instances, containers can be added to a NMAMapView
 * instance.
 *
 * Applications can, as necessary, add or remove certain
 * types of `NMAMapObject` objects to or from a `NMAMapContainer` (refer to
 * `addMapObject:` for details). A `NMAMapContainer` is also
 * useful for grouping together `NMAMapObject` objects to allow application operations
 * on entire groups of map objects without requiring an iterative approach to
 * inspecting or changing the state of each individual `NMAMapObject` (e.g. for changing
 * their visibility).
 *
 * @note The zOrder of an NMAMapObject instance in a container is relative only to other
 * NMAMapObject instances within the same container. Note that containers are derived
 * from NMAMapObject also have zOrder.
 *
 * @note You can use the visible property to control whether the objects in 
 * the container are visible. If the property set to true, then
 * the visibility settings of each map object in the container are used. However,
 * unlike other map objects, `NMAMapContainer` does not support the use of
 * visibility masks, so you cannot set container visibility on a zoom level basis.
 */
@interface NMAMapContainer : NMAMapObject

/**
 * The `NSArray` of NMAMapObject objects within the `NMAMapContainer`.
 */
@property (nonatomic, readonly, weak, nullable) NSArray<NMAMapObject *> *mapObjects;

/**
 * Adds a `NMAMapObject` to the `NMAMapContainer`.
 *
 * `NMAMapObject` types that can be added to a `NMAMapContainer` include:
 *
 * 1. `NMAMapMarker`
 *
 * 2. `NMAMapLabeledMarker`
 *
 * 3. `NMAMapCircle`
 *
 * 4. `NMAMapPolygon`
 *
 * 5. `NMAMapPolyline`
 *
 * @note Attempts to add an object twice to the same container will be ignored.
 *
 * @note `NMAMapRoute` and `NMAMapContainer` cannot be added to a container.
 * `NMAMapRoute` needs to be added directly to the `NMAMapView`
 * (see `NMAMapView::addMapObject:`).
 *
 * @param aMapObject A `NMAMapObject` to be added to the `NMAMapContainer`.
 *
 * @return YES if the `NMAMapObject` was added successfully, NO otherwise.
 *
 * See also `removeMapObject:`
 */
- (BOOL)addMapObject:(nonnull NMAMapObject *)aMapObject
NS_SWIFT_NAME(add(_:));

/**
 * Removes the specified `NMAMapObject` from the `NMAMapContainer`.
 *
 * @note If the specified `NMAMapObject` is not contained within the `NMAMapContainer`,
 * the container will be unchanged.
 *
 * @param aMapObject A `NMAMapObject` to remove from the `NMAMapContainer`.
 *
 * @return YES if the `NMAMapObject` was removed successfully, NO otherwise.
 *
 * See also `removeAllMapObjects`
 */
- (BOOL)removeMapObject:(nonnull NMAMapObject *)aMapObject
NS_SWIFT_NAME(remove(_:));

/**
 * Removes all NMAMapObject objects from the `NMAMapContainer`.
 *
 * @return YES if all `NMAMapObject` objects were removed successfully, NO otherwise.
 */
- (BOOL)removeAllMapObjects;

@end
