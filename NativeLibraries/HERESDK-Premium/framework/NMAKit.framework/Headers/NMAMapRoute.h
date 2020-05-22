/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIColor.h>

#import "NMAMapObject.h"

@class NMARoute;

/**
 * Render style of the route.
 *
 * @note Route render style is defined per map scheme.
 */
typedef NS_ENUM(NSUInteger, NMAMapRouteRenderType) {
    /**
     * Predefined "Primary" route style with fixed color.
     */
    NMAMapRouteRenderTypePrimary = 1,
    /**
     * Predefined "Secondary" route stlye with fixed color.
     *
     * Designed for rendering alternate routes.
     */
    NMAMapRouteRenderTypeSecondary = 2,
    /**
     * Configurable custom route style.
     *
     * Use this render type to customize the route colors.
     */
    NMAMapRouteRenderTypeUserDefined = 3

};


/**
 * Represents a NMAMapObject in the shape of a route that can be displayed on a map.
 *
 * In order to display the route object on the map, the route object needs to be added to
 * an NMAMapView by calling addMapObject:.
 *
 * The NMAViewObject location property for a NMAMapRoute returns the coordinates of the
 * first waypoint.
 *
 * See also `NMARoute`
 */
@interface NMAMapRoute : NMAMapObject

/**
 * A convenience constructor for NMAMapRoute.
 *
 * This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @param route The route object from which to construct the NMAMapRoute.
 */
+ (nullable instancetype)mapRouteWithRoute:(nonnull NMARoute *)route
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * A constructor for NMAMapRoute.
 *
 * This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @param route The route object from which to construct the NMAMapRoute.
 */
- (nullable instancetype)initWithRoute:(nonnull NMARoute *)route
NS_SWIFT_NAME(init(_:));

/**
 * Use mapRouteWithRoute to instantiate a NMAMapRoute.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Indicates whether the maneuver number is displayed on the `NMAMapRoute`.
 */
@property (nonatomic) BOOL maneuverNumberDisplayed;

/**
 * The `UIColor` representing the color of the `NMAMapRoute`.
 *
 * Setting this property will change the color of the route and change `renderType`
 * to `NMAMapRouteRenderTypeUserDefined`.
 *
 * If `renderType` is set to `NMAMapRouteRenderTypeUserDefined` getting this property
 * will return the value you set.
 *
 * If `renderType` is not `NMAMapRouteRenderTypeUserDefined` getting this property will return nil
 * if the `NMAMapRoute` has not been added to a map. After being added to the map it will return
 * the pre-defined value for the current map scheme.
 *
 * See `renderType` for the default render type and hence default behaviour of this property.
 *
 * @note Alpha-value transparency is supported.
 */
@property (nonatomic, strong, nullable) UIColor *color;

/**
 * The `UIColor` representing the traveled color of the `NMAMapRoute`.
 *
 * Setting this property will change the traveled color of the route and change `renderType`
 * to `NMAMapRouteRenderTypeUserDefined`.
 *
 * If `renderType` is set to `NMAMapRouteRenderTypeUserDefined` getting this property
 * will return the value you set.
 *
 * If `renderType` is not `NMAMapRouteRenderTypeUserDefined` getting this property will return nil
 * if the `NMAMapRoute` has not been added to a map. After being added to the map it will return
 * the pre-defined value for the current map scheme.
 *
 * `traveledColor` is not supported by `NMATransitRoute` and `NMAUrbanMobilityRoute`.
 *
 * See `renderType` for the default render type and hence default behaviour of this property.
 *
 * @note Alpha-value transparency is supported.
 */
@property (nonatomic, strong, nullable) UIColor *traveledColor;

/**
 * The `UIColor` representing the upcoming color of the `NMAMapRoute`.
 *
 * Upcoming is the part of the route from next waypoint to final destination.
 * Setting this property will change the upcoming color of the route
 * and change `renderType` to `NMAMapRouteRenderTypeUserDefined`.
 *
 * If `renderType` is set to `NMAMapRouteRenderTypeUserDefined` getting this property
 * will return the value you set.
 *
 * If `renderType` is not `NMAMapRouteRenderTypeUserDefined` getting this property will return nil
 * if the `NMAMapRoute` has not been added to a map. After being added to the map it will return
 * the pre-defined value for the current map scheme.
 *
 * `upcomingColor` is not supported by `NMATransitRoute` and `NMAUrbanMobilityRoute`.
 *
 * See `renderType` for the default render type and hence default behaviour of this property.
 *
 * @note Alpha-value transparency is supported.
 */
@property (nonatomic, strong, nullable) UIColor *upcomingColor;

/**
 * The `UIColor` representing the outline color of the `NMAMapRoute`.
 *
 * Setting this property will change the outline color of the route and change `renderType`
 * to `NMAMapRouteRenderTypeUserDefined`. The outline color will be applied to upcoming
 * and traveled portions of a route.
 *
 * If `renderType` is set to `NMAMapRouteRenderTypeUserDefined` getting this property
 * will return the value you set, otherwise nil.
 *
 * `outlineColor` is rendered as a solid line, which is wider than the route line.
 * Hence, transparent route colors will be blended with the underlying outline color.
 *
 * `outlineColor` is not supported by `NMATransitRoute` and `NMAUrbanMobilityRoute`.
 *
 * See `renderType` for the default render type and hence default behaviour of this property.
 *
 * @note Alpha-value transparency is supported.
 */
@property (nonatomic, strong, nullable) UIColor *outlineColor;

/**
 * The `UIColor` representing the text color of the `NMAMapRoute`.
 *
 * Setting this property will change the text color on the route and change `renderType`
 * to `NMAMapRouteRenderTypeUserDefined`. The text color will be applied to upcoming
 * and traveled portions of a route.
 *
 * If `renderType` is set to `NMAMapRouteRenderTypeUserDefined` getting this property
 * will return the value you set, otherwise nil.
 *
 * `textColor` is not supported by `NMATransitRoute` and `NMAUrbanMobilityRoute`.
 *
 * See `renderType` for the default render type and hence default behaviour of this property.
 *
 * @note Alpha-value transparency is supported.
 */
@property (nonatomic, strong, nullable) UIColor *textColor;

/**
 * The `UIColor` representing the text outline color of the `NMAMapRoute`.
 *
 * Setting this property will change the text outline color on the route and change `renderType`
 * to `NMAMapRouteRenderTypeUserDefined`. The text outline color will be applied to upcoming
 * and traveled portions of a route.
 *
 * If `renderType` is set to `NMAMapRouteRenderTypeUserDefined` getting this property
 * will return the value you set, otherwise nil.
 *
 * `textOutlineColor` is not supported by `NMATransitRoute` and `NMAUrbanMobilityRoute`.
 *
 * See `renderType` for the default render type and hence default behaviour of this property.
 *
 * @note Alpha-value transparency is supported.
 */
@property (nonatomic, strong, nullable) UIColor *textOutlineColor;

/**
 * The `UIColor` representing the maneuver number color of the `NMAMapRoute`.
 *
 * Setting this property will change the maneuver number text color and border of its square.
 * `renderType` will be changed to `NMAMapRouteRenderTypeUserDefined`.
 *
 * If `renderType` is set to `NMAMapRouteRenderTypeUserDefined` getting this property
 * will return the value you set.
 *
 * `maneuverNumberColor` is rendered only if `maneuverNumberDisplayed` is set to YES.
 *
 * `maneuverNumberColor` is not supported by `NMATransitRoute` and `NMAUrbanMobilityRoute`.
 *
 * See `renderType` for the default render type and hence default behaviour of this property.
 *
 * @note Alpha-value transparency is supported.
 */
@property (nonatomic, strong, nullable) UIColor *maneuverNumberColor;

/**
 * The `NMAMapRoute`RenderType associated with `NMAMapRoute`.
 *
 * Setting `color` or `traveledColor` or `upcomingColor` or `outlineColor` or `maneuverNumberColor`
 * properties will reset `NMAMapRouteRenderType` to `NMAMapRouteRenderTypeUserDefined`.
 *
 * Setting `renderType` to a value other than `NMAMapRouteRenderTypeUserDefined` will reset any color
 * previously set by `color`, `traveledColor`, `upcomingColor` and `outlineColor` properties.
 *
 * Default value is `NMAMapRouteRenderTypePrimary`.
 *
 * @note `NMAMapRoute` must be added to a `NMAMapView` before setting this property.
 * Otherwise, except for `NMAMapRouteRenderTypeUserDefined` type, the property value will not change.
 */
@property (nonatomic, assign) NMAMapRouteRenderType renderType;

/**
 * The NMARoute represented by the NMAMapRoute.
 */
@property (nonatomic, strong, nonnull) NMARoute *route;

/**
 * Indicates whether the route object is displaying traffic information.
 *
 * YES will display traffic if the following are set: [NMAMapView setTrafficVisible:YES] and
 * [NMAMapView showTrafficLayers:NMATrafficLayerOnRoute]. NO will hide traffic on route rendering
 * for this route. By default traffic on route is disabled.
 *
 * @note Truck routes and public transport timetable routes are not supported.
 */
@property (nonatomic, getter = isTrafficEnabled) BOOL trafficEnabled;

/**
 * The `NSUInteger` z-index (stacking order) for the NMAMapRoute within its
 * containing NMAMapView. It only applies within the multiple NMAMapRoute objects
 * added to a Map.
 *
 * Must be in the range [NMAMapObjectMinimumZIndex, NMAMapObjectMaximumZIndex]. The
 * property will be clamped to this range if invalid values are specified.
 *
 * @note Objects with the highest value are placed at the top of the stacking order.
 */
@property (nonatomic) NSUInteger zIndex;



@end
