/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "NMAMapView.h"

@class NMAGeoCoordinates;


/**
 * A UIView subclass used to display graphics content at a fixed
 * geographical location on the map.
 *
 * The NMAMapOverlay class can be used to display custom UIView-based content
 * at a fixed location on the map. To use, create a NMAMapOverlay and add one
 * or more custom UIViews as subviews of the overlay. Then, give the overlay
 * a NMAGeoCoordinates location and add it to a map. The overlay will
 * automatically be repositioned on the screen as the map moves.
 *
 * The NMAMapOverlay will automatically be resized and repositioned when
 * subviews are added or removed; however, changes to the size or content
 * of existing subviews will not be detected. Any such changes should be
 * followed by an invocation of the -refresh method.
 *
 * To ensure overlays are not drawn outside the bounds of the NMAMapView
 * to which they are added set the NMAMapView clipsToBounds property to YES.
 *
 * There is slightly more overhead involved in positioning an overlay as
 * compared to a NMAMapMarker, so for use cases which only require static
 * images, markers should be used. NMAMapOverlay should be used if features
 * provide by UIView are required, such as Core Animation or dynamic content.
 *
 * In some cases, the NMAMapOverlay may be static for most of its life with
 * the occasional need to be animated or otherwise dynamic. For these cases,
 * the property "displayedAsMarker" can be used to replace the NMAMapOverlay
 * with a NMAMapMarker displaying a "snapshot" of the overlay.
 *
 * @note NMAMapOverlay automatically adjusts the values of its UIView center,
 * bounds, and frame properties to ensure that the overlay is always in the
 * correct position and always large enough to encompass all of its subviews.
 * Thus, it is not recommended to modify these properties directly.
 *
 * @note It is not recommended to subclass NMAMapOverlay.
 */
@interface NMAMapOverlay : UIView<NMAMapViewDelegate>

/**
 * A convenience method to construct a NMAMapOverlay with a subview.
 */
+ (nonnull instancetype)mapOverlayWithSubview:(nonnull UIView *)subview
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * A convenience method to construct a NMAMapOverlay with a subview
 * and location.
 */
+ (nonnull instancetype)mapOverlayWithSubview:(nonnull UIView *)subview geoCoordinates:(nonnull NMAGeoCoordinates *)coordinates
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * The `NMAGeoCoordinates` for the `NMAMapOverlay` center.
 */
@property (nonatomic, strong, nonnull) NMAGeoCoordinates *coordinates;

/**
 * The `CGPoint` offset of the `NMAMapOverlay` from its anchored location.
 *
 * Use this property to reposition a `NMAMapOverlay` as needed.
 * The x and y offset values are measured in points.
 * Positive offset values move the `NMAMapOverlay` down and to the right,
 * while negative values move it up and to the left.
 *
 * If no offset is provided, the `NMAMapOverlay` is centered on its
 * anchor; that is, the center of the marker image is located at the
 * map-space representation of the marker's world-space location (its
 * anchor, an `NMAGeoCoordinates`).
 *
 */
@property (nonatomic) CGPoint anchorOffset;

/**
 * Display the NMAMapOverlay on the map as an equivalent NMAMapMarker.
 *
 * Set this property to YES to replace the NMAMapOverlay with an identical-
 * looking NMAMapMarker. The property can be set back to NO at any time to
 * go back to displaying the overlay.
 *
 * Defaults to NO.
 *
 * @note The displayed marker is static snapshot of the overlay at the time
 * when this property is changed from NO to YES. It will not reflect changes
 * made to the overlay after setting this property to YES. To update the
 * marker, call the refresh method.
 */
@property (nonatomic) BOOL displayedAsMarker;

/**
 * The `NSUInteger` z-index for the `NMAMapOverlay` in
 * `NMAMapOverlayTypeMapMarker` mode.
 */
@property (nonatomic) NSUInteger zMarkerIndex;

/**
 * Initializes a `NMAMapOverlay` instance with the specified
 * UIView subview.
 *
 * @param subview The subview to be displayed on the map
 * @return The `NMAMapOverlay`
 */
- (nonnull instancetype)initWithSubview:(nonnull UIView *)subview
NS_SWIFT_NAME(init(_:));

/**
 * Initializes a `NMAMapOverlay` instance with the specified
 * UIView subview and NMAGeoCoordinates location.
 *
 * @param subview The subview to be displayed on the map
 * @param coordinates The location at which to display the overlay
 * @return The `NMAMapOverlay`
 */
- (nonnull instancetype)initWithSubview:(nonnull UIView *)subview geoCoordinates:(nonnull NMAGeoCoordinates *)coordinates NS_DESIGNATED_INITIALIZER
NS_SWIFT_NAME(init(_:_:));

/**
 * A convenience function to set where the `NMAMapOverlay` is attached to its
 * anchor
 *
 * @param position A `NMAnchorLocation` for anchoring the marker icon.
 * @return The `CGPoint` offset value that was applied to the anchorOffset property
 */
- (CGPoint)setAnchorOffsetUsingLayoutPosition:(NMALayoutPosition)position
NS_SWIFT_NAME(setAnchorOffset(_:));

/**
 * Updates the size and position of the NMAMapOverlay. Should be invoked
 * when the content of the overlay has changed.
 */
- (void)refresh;

@end
