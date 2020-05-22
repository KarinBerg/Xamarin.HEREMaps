/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMATypes.h"

@class NMAImage;
@class NMAMapView;
@class NMAMapObject;
@class UIColor;


/**
 * The types of position that the NMAPositionIndicator can use.
 */
typedef NS_ENUM(NSUInteger, NMAPositionIndicatorType) {
    /** The position indicator uses the NMAPositioningManager rawPosition property. */
    NMAPositionIndicatorTypeRaw,
    /** The position indicator uses the NMAPositioningManager mapMatchedPosition property. */
    NMAPositionIndicatorTypeMapMatched,
    /** The position indicator uses the NMAPositioningManager currentPosition property. */
    NMAPositionIndicatorTypeCurrent
};


/**
 * Used to provide a visual indication of the user's current position.
 *
 * Each instance of NMAMapView automatically has a NMAPositionIndicator created
 * for it. The position indicator is hidden by default; it can be displayed by
 * change its visible property to YES.
 *
 * By default, the position indicator displays an NMAMapMarker showing a green
 * circle, but the displayed object can be set to a custom NMAMapObject through
 * the displayObject property. The default render layer of the position indicator
 * is `NMAMapLayerTypeForeground`.
 *
 * The accuracy of the current position is indicated by a circle surrounding the
 * indicator object. The visibility of the accuracy indicator is controlled via
 * the accuracyIndicatorVisible property, and its color may be changed by setting
 * the accuracyIndicatorColor.
 *
 * @note The NMAPositionIndicator requires NMAPositioningManager position updates
 * to function correctly, and will automatically start the positioning service
 * when required.
 */
@interface NMAPositionIndicator : NSObject

/**
 * The NMAMapObject displayed at the current position.
 *
 * @note Supported object types are NMAMapMarker, NMAMapLocalModel, and
 * NMAMapCircle; other object types will be ignored.
 *
 * @note Set to nil to restore the default display object.
 */
@property (nonatomic, nullable) NMAMapObject *displayObject;

/**
 * Indicates whether the NMAPositionIndicator is visible.
 *
 * @note The getter is `isVisible`.
 *
 * @note Setting visible to YES will start NMAPositioningManager positioning
 * if it is not already active.
 */
@property (nonatomic, getter = isVisible) BOOL visible;

/**
 * The color of the position indicator specified as an HSB hue.
 *
 * @note Only affects the default display object.
 */
@property (nonatomic) float hue;

/**
 * Indicates whether the NMAPositionIndicator accuracy indicator
 * (the surrounding circle) is visible.
 *
 * @note The getter is `isAccuracyIndicatorVisible`.
 */
@property (nonatomic, getter = isAccuracyIndicatorVisible) BOOL accuracyIndicatorVisible;

/**
 * The color of the accuracy indicator circle.
 */
@property (nonatomic, nonnull) UIColor *accuracyIndicatorColor;

/**
 * The type of positioning used to place the NMAPositionIndicator.
 *
 * The position indicator can be configured to use any of the positioning properties
 * of NMAPositioningManager: rawPosition, mapMatchedPosition, or currentPosition.
 *
 * @note The default value is NMAPositionIndicatorTypeCurrent.
 *
 * @note If NMAPositionIndicatorTypeMapMatched is selected and map matching is not
 * enabled in the NMAPositioningManager, the indicator will not be shown.
 */
@property (nonatomic) NMAPositionIndicatorType type;

/**
 * Indicates whether the position indicator is automatically reoriented to
 * track the course of the current position.
 *
 * If course tracking is enabled, the (yaw) rotation of the model will be automatically
 * modified. To avoid interference, it should not be manually adjusted. If the model
 * orientation needs to be adjusted to face it the right way, use the orientationOffset
 * property.
 *
 * @note The default value is YES.
 *
 * @note Only applies to display objects of type NMAMapLocalModel (including the
 * default display object).
 *
 * See also `orientationOffset`
 */
@property (nonatomic) BOOL tracksCourse;

/**
 * The rotation offset in degrees used to orient custom display models.
 *
 * If a custom NMAMapLocalModel is set as the displayObject of the position indicator,
 * it is implicitly assumed that the model is defined "facing" north. If this is not
 * the case, the model's offset from north should be specified here to ensure that it
 * will be oriented the right way. The offset is measured clockwise from north; for
 * example, if the model is facing east, the offset should be set to 90.
 *
 * @note This value should be left at zero when using the default display object.
 */
@property (nonatomic) float orientationOffset;

/**
 * Sets the NMAMapObject to be displayed and rendered in the specified layer.
 * The default render layer is `NMAMapLayerTypeForeground`.
 *
 * @note Supported object types are NMAMapMarker, NMAMapLocalModel, and
 * NMAMapCircle; other object types will be ignored.
 *
 * @note The layer of the accuracy indicator circle will also be changed to the specified layer.
 *
 * @note Set to nil to restore the default display object.
 */
- (void)setDisplayObject:(NMAMapObject * _Nullable)displayObject toLayer:(NMAMapLayerType)layer
NS_SWIFT_NAME(set(displayObject:toLayer:));

@end
