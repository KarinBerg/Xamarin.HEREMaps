/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "NMAMapObject.h"
#import "NMATypes.h"

@class NMAGeoCoordinates;
@class NMAImage;


/**
 *
 * Represents a marker used to display an icon on a geographical position on a map.
 * The map handles proper placement of icons on the screen as well as
 * panning and rotation.
 *
 * @note Application users can select `NMAMapMarker` objects.
 */
@interface NMAMapMarker : NMAMapObject

/**
 * A convenience method to construct an NMAMapMarker at the specified
 * coordinates.
 *
 * @param coordinates The NMAGeoCoordinates at which to create the map marker.
 */
+ (nonnull instancetype)mapMarkerWithGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * A convenience method to construct an NMAMapMarker at the specified
 * coordinates and with an NMAImage icon.
 *
 * @param coordinates The NMAGeoCoordinates at which to create the map marker.
 * @param icon The NMAImage to use for the marker icon.
 */
+ (nonnull instancetype)mapMarkerWithGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates icon:(nonnull NMAImage *)icon
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * A convenience method to construct an NMAMapMarker at the specified
 * coordinates and with a UIImage icon.
 *
 * @param coordinates The NMAGeoCoordinates at which to create the map marker.
 * @param image The UIImage to use for the marker icon.
 */
+ (nonnull instancetype)mapMarkerWithGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates image:(nonnull UIImage *)image
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * The geographical coordinates at which the `NMAMapMarker` is displayed on a map.
 *
 * @note If the coordinates have a positive altitude value, the marker will be displayed
 * above the plane of the map. Conversely, negative altitude values will hide the marker
 * below the map. Set the altitude to zero to display the marker in the plane of the map.
 *
 * @note The NMAViewObject "location" property will return these coordinates;
 */
@property (nonatomic, strong, nonnull) NMAGeoCoordinates *coordinates;

/**
 * The NMAImage displayed at the marker location.
 */
@property (nonatomic, strong, nullable) NMAImage *icon;

/**
 * Sets whether this marker is draggable or not. By default, the marker is not draggable.
 */
@property (nonatomic, getter=isDraggable) BOOL draggable;

/**
 * Sets whether this marker has offset from the tap coordinate during dragging to avoid
 * overlapping marker image by user's finger. By default, dragging offset is enabled.
 */
@property (nonatomic, getter=isDraggingOffsetEnabled) BOOL draggingOffsetEnabled;

/**
 * The `CGPoint` offset of the `NMAMapMarker` from its anchored location.
 *
 * Use this property to reposition a `NMAMapMarker` as needed.
 * The x and y offset values are measured in points.
 * Positive offset values move the `NMAMapMarker` down and to the right,
 * while negative values move it up and to the left.
 *  If no offset is provided, the `NMAMapMarker` is centered on its
 * anchor; that is, the center of the marker image is located at the
 * map-space representation of the marker's world-space location (its
 * anchor, an `NMAGeoCoordinates`).
 */
@property (nonatomic) CGPoint anchorOffset;

/**
 * Initializes a `NMAMapMarker` instance with the specified `NMAGeoCoordinates`
 * and `NMAImage` for the displayed icon.
 *
 * @param coordinates A `NMAGeoCoordinates` representing the map coordinates for displaying
 *               the `NMAMapMarker`
 * @return The `NMAMapMarker`
 */
- (nonnull instancetype)initWithGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates
NS_SWIFT_NAME(init(geoCoordinates:));

/**
 * Initializes a `NMAMapMarker` instance with the specified `NMAGeoCoordinates`
 * and `NMAImage` for the displayed icon.
 *
 * @param coordinates A `NMAGeoCoordinates` representing the map coordinates for displaying
 *               the `NMAMapMarker`
 * @param icon A `NMAImage` representing the icon for the `NMAMapMarker`
 * @return The `NMAMapMarker`
 */
- (nonnull instancetype)initWithGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates icon:(nonnull NMAImage *)icon NS_DESIGNATED_INITIALIZER
NS_SWIFT_NAME(init(geoCoordinates:icon:));

/**
 * Initializes a `NMAMapMarker` instance with the specified `NMAGeoCoordinates`
 * and `NMAImage` for the displayed icon.
 *
 * @param coordinates A `NMAGeoCoordinates` representing the map coordinates for displaying
 *               the `NMAMapMarker`
 * @param image A UIImage to use to create the NMAImage marker of the icon.
 * @return The `NMAMapMarker`
 */
- (nonnull instancetype)initWithGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates image:(nonnull UIImage *)image
NS_SWIFT_NAME(init(geoCoordinates:image:));

/**
 * A convenience function to set where the `NMAMapMarker` is attached to its
 * anchor
 *
 * @param position A `NMAnchorLocation` for anchoring the marker icon.
 * @return The `CGPoint` offset value that was applied to the anchorOffset property
 */
- (CGPoint)setAnchorOffsetUsingLayoutPosition:(NMALayoutPosition)position
NS_SWIFT_NAME(setAnchorOffset(_:));

/**
 * Sets the preferred icon size at a certain zoom level.
 *
 * @note This method only affects rendering of SVG icons by
 * overriding the default rendering size.
 *
 * @param size The preferred icon size in points (not pixels).
 * @param zoomLevel Target map zoom level.
 */
- (void)setSize:(CGSize)size forZoomLevel:(NSUInteger)zoomLevel
NS_SWIFT_NAME(setSize(_:forZoomLevel:));

/**
 * Sets the preferred icon size in a certain zoom level range.
 *
 * @note This method only affects rendering of SVG icons.
 *
 * @param size The preferred icon size in points (not pixels).
 * @param zoomRange NSRange for the zoom level.
 */
- (void)setSize:(CGSize)size forZoomRange:(NSRange)zoomRange
NS_SWIFT_NAME(setSize(_:forZoomRange:));

/**
 * Resets the icon size to the default zoom values from the map.
 */
- (void)resetIconSize;

@end
