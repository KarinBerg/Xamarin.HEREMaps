/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;


/**
 * The base class for all objects displayed in an NMA SDK view.
 *
 * All objects displayed by an NMA view (such as NMAMapView if available)
 * have NMAViewObject as their base class. All such objects fall into
 * one of two categories: proxy objects, created by the SDK, and user objects, created
 * by the client application. These objects additionally inherit from NMAProxyObject
 * and NMAUserObject, respectively.
 *
 * See also `NMAProxyObject,` NMAUserObject
 */
@interface NMAViewObject : NSObject

/**
 *  Determines whether the specified `NMAViewObject` object is equal to this
 * `NMAViewObject`.
 *
 * @param aViewObject A `NMAViewObject` to compare with this `NMAViewObject`
 *                    for equality
 * @return YES if the `NMAViewObject` internal instances are equal, NO otherwise
 */
- (BOOL)isEqual:(nullable id)aViewObject;

/**
 *  Determines whether this `NMAViewObject` exists within the
 * specified `NSArray` of `NMAViewObject` objects.
 *
 * @param objects An array of `NMAViewObject` objects to check for
 *                the existence of this `NMAViewObject`
 * @return YES if this `NMAViewObject` exists within the specified
 *         `NSArray`, NO otherwise
 */
- (BOOL)isInArray:(nonnull NSArray<NMAViewObject *> *)objects
NS_SWIFT_NAME(isIn(_:));

/**
 * The geographical location of the view object.
 *
 * The meaning of the location for a particular object depends on that
 * object's type. Objects that don't have a location will return nil.
 * The meaning of the location for certain view objects is as follows:
 *
 * `NMAMapView` objects:
 *
 * 1. `NMAMapCircle`           - the center of the circle
 *
 * 2. `NMAMapContainer`        - no location
 *
 * 3. `NMAMapMarker`           - same as coordinates property
 *
 * 4. `NMAMapPolygon`          - the first vertex
 *
 * 5. `NMAMapPolyline`         - the first vertex
 *
 * 6. `NMAMapRoute`            - the first waypoint of the route
 */
- (nullable NMAGeoCoordinates *)location;

@end
