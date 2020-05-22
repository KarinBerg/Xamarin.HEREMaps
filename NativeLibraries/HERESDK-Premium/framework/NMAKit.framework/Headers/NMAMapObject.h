/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMAUserObject.h"
#import "NMATypes.h"

@class NMAGeoBoundingBox;
@class NMAMapObject;
@class NMAMapContainer;

/**
 * Defines types of NMAMapObject objects that an application can add to
 * a map.
 */
typedef NS_ENUM(NSUInteger, NMAMapObjectType) {
    /** A point. */
    NMAMapObjectTypePoint,
    /** A map marker. */
    NMAMapObjectTypeMarker,
    /** A map labeled marker */
    NMAMapObjectTypeLabeledMarker,
    /** A polygon. */
    NMAMapObjectTypePolygon,
    /** A polyline. */
    NMAMapObjectTypePolyline,
    /** A route. */
    NMAMapObjectTypeRoute,
    /** A safety spot. */
    NMAMapObjectTypeSafetySpot,
    /** A map container to hold other map objects. */
    NMAMapObjectTypeContainer,
    /** A circle. */
    NMAMapObjectTypeCircle,
    /** A reserved object. */
    NMAMapObjectTypeReserved,
    /** An unknown object. */
    NMAMapObjectTypeUnknown
};


/**
 * Represents a base class for all visible objects shown on a map.
 *
 * This class serves as a generalization (or base) for several more
 * specified map object types, bundling their common properties. Objects
 * implementing this interface can be grouped within a NMAMapContainer by way of
 * the NMAMapContainer::addMapObject(NMAMapObject) method.
 * @note This class serves as a base class to other map object types and should not be
 * instantiated directly.
 */
@interface NMAMapObject : NMAUserObject

/**
 * Control the map layer (`NMAMapLayerType`) at which the object is rendered.
 *
 * @note This property is valid only after the object is added to a `NMAMapView`. Setting the
 * property will move the object to the new layer in the map view.
 */
@property (nonatomic, readwrite) NMAMapLayerType mapLayerType;

/**
 * The `NSUInteger` z-index (stacking order) for the NMAMapObject within its
 * containing NMAMapContainer, or within the NMAMapView if the object was added to
 * NMAMapView directly.
 *
 * Must be in the range NMAMapObjectMinimumZIndex..NMAMapObjectMaximumZIndex. The
 * property will be clamped to this range if invalid values are specified.
 *
 * @note Objects with the highest value are placed at the top of the stacking order.
 */
@property (nonatomic) NSUInteger zIndex;

/**
 * Indicates whether the visibility of the `NMAMapObject` on the map is enabled.
 * Whether the map object is actually visible depends on whether the
 * visible mask is set for the desired zoom level.
 *
 * @note The getter is `isVisible`.
 *
 * @note To customize the visibility of the map object for certain zoom levels,
 * please refer to `setVisibility:atZoomLevel` or
 * `setVisibility:fromZoomLevel:toZoomLevel`
 */
@property (nonatomic, getter = isVisible) BOOL visible;

/**
 * The map object's type.
 */
@property (nonatomic, readonly) NMAMapObjectType type;

/**
 * The map object's container. This will be nil if the map object does not belong
 * to a container or was added to an NMAMapView directly.
 */
@property (nonatomic, readonly, weak, nullable) NMAMapContainer *parent;

/**
 * Returns the unique ID value of the `NMAMapObject`.
 *
 * @note This value will be consistent for the lifetime of the object.
 *
 * @return The unique ID
 */
- (NSUInteger)uniqueId;

/**
 * Determines whether the map object is set to visible at the specified zoom level
 * when the map object's visible property is set to YES.
 *
 * By default, the visibility flags for all zoom levels are set to YES.
 *
 * @param zoomLevel for checking whether the map object is visible. Will be clamped to
 *        the range NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel. This
 *        is rounded off to the nearest integer. e.g. 14.1 means [14..15)
 */
- (BOOL)isVisibleAtZoomLevel:(float)zoomLevel
NS_SWIFT_NAME(isVisible(atZoomLevel:));

/**
 * Sets the visibility of the map object at a specific zoom level.
 *
 * By default, the map object is visible at all zoom levels. Each zoom level
 * retains its own visibility state.
 * @param visible indicates whether the map object should be visible.
 * @param zoomLevel for applying the specified visibility. Will be clamped to
 *        the range NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel. This
 *        is rounded off to the nearest integer. e.g. 14.1 means [14..15)
 *
 * @note This will take effect if/when the map object's visibile property is set YES.
 */
- (void)setVisibility:(BOOL)visible atZoomLevel:(float)zoomLevel
NS_SWIFT_NAME(setVisibility(_:atZoomLevel:));

/**
 * Sets the visibility of the map object for a range of zoom levels.
 *
 * By default, the map object is visible at all zoom levels. Each zoom level
 * retains its own visibility state. If you make the following calls:
 * \code
 * #1. visible property is set to YES
 *
 * |111111111111111111111|
 *
 * #2. setVisible:NO fromZoomLevel:10 toZoomLevel:16
 *
 *            10    16
 *           |0000000|
 *
 * #3. setVisible:YES fromZoomLevel:5 toZoomLevel:13
 *
 *       5       13
 *      |111111111|
 *
 * #4. setVisible:NO atZoomLevel:20
 *
 * The result will be that this map object will be invisible at zoom levels 14-16 and 20 and
 * visible at the others.
 *
 *       5        14 17 20
 * |111111111111110001110|
 * \endcode
 *
 * @param visible indicates whether the map object should be visible.
 * @param fromZoomLevel clamped to range NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel,
 * rounded off to the nearest integer.
 * @param toZoomLevel clamped to range NMAMapViewMinimumZoomLevel..NMAMapViewMaximumZoomLevel,
 * rounded off to the nearest integer.
 *
 * @note This will take effect if/when the map object's visibile property is set YES.
 */
- (void)setVisibility:(BOOL)visible fromZoomLevel:(float)fromZoomLevel toZoomLevel:(float)toZoomLevel
NS_SWIFT_NAME(setVisibility(_:fromZoomLevel:to:));

@end
