/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#ifndef NMASDK_NMATypes_h
#define NMASDK_NMATypes_h

/**
 * The Common group includes classes, protocols, and enumerations
 * that are generally used by other packages in the iOS SDK.
 * Some important classes in this group are
 * `NMAGeoCoordinates` and `NMAPositioningManager`.
 *
 */

/**
 *  The minimum Z Index for an NMAMapObject
 */
FOUNDATION_EXPORT const NSUInteger NMAMapObjectMinimumZIndex;

/**
 *  The maximum Z Index for an NMAMapObject
 */
FOUNDATION_EXPORT const NSUInteger NMAMapObjectMaximumZIndex;


/**
 * Lower limit of the NMAMapView zoomLevel property.
 */
FOUNDATION_EXPORT const float NMAMapViewMinimumZoomLevel;

/**
 * Upper limit of the NMAMapView zoomLevel property.
 */
FOUNDATION_EXPORT const float NMAMapViewMaximumZoomLevel;


/**
 *  Represents fixed locations or regions within a bounding rectangle.
 */
typedef NS_ENUM(NSUInteger, NMALayoutPosition) {
    NMALayoutPositionTopLeft,
    NMALayoutPositionTopCenter,
    NMALayoutPositionTopRight,
    NMALayoutPositionCenterLeft,
    NMALayoutPositionCenter,
    NMALayoutPositionCenterRight,
    NMALayoutPositionBottomLeft,
    NMALayoutPositionBottomCenter,
    NMALayoutPositionBottomRight
};


/**
 * Represents the display order of the various rendering layers of a map.
 *
 * Objects at NMAMapLayerTypeForeground are rendered on top of objects at NMAMapLayerTypePointOfInterest
 * which are rendered on top of objects at NMAMapLayerTypeRoad and so on.
 *
 * Objects within each layer may be further organized by a Z Index that dictates the ordering
 * within the layer. For examples, NMAMapObject objects that you create via the various NMAMapObject
 * dervied classes reside at NMAMapLayerTypeForeground and their Z Index can be set via the
 * NMAMapObject#zIndex: property.
 */
typedef NS_ENUM(NSUInteger, NMAMapLayerType) {
    /**
     * Objects at this layer are placed on top of any other objects (they appear closer to the viewer
     * than other objects).
     *
     * @note NMAMapObject objects that you create via the various NMAMapObject dervied classes reside
     * at this layer.
     */
    NMAMapLayerTypeForeground,

    /**
     * Objects at this layer are used to augment Point of Interest information.
     *
     * @note `NMAMapTileLayer` (if available) objects can not currently be placed at this layer.
     */
    NMAMapLayerTypePointOfInterest,

    /**
     * Objects at this layer are used to augment Transit Stop information. Transit stops are rendered
     * on top of roads .
     *
     * @note `NMAMapTileLayer` (if available) objects can not currently be placed at this layer.
     */
    NMAMapLayerTypeTransitStop,

    /**
     * Objects at this layer add some information to the road network. For example, traffic or traffic
     * incident markers would be added at this level. Objects at this level  appear on top of roads.
     */
    NMAMapLayerTypeRoad,

    /**
     * Objects at this layer add information to area features. For example, heat maps would be added at
     * this layer. Objects at this layer appear on top of the map background but underneath roads.
     */
    NMAMapLayerTypeArea,

    /**
     * Objects at this layer are placed directly over (on top of or in front of) objects at
     * the NMAMapLayerTypeReplacement layer. Use this layer for opaque or transparent objects
     * that should appear on top of the basic map data.
     */
    NMAMapLayerTypeBackground,

    /**
     * Objects at this layer are intended replace the basic map data. For example, custom satellite
     * data would be rendered at this layer. Note that placing objects at this layer does not
     * disable rendering of the basic map data.
     */
    NMAMapLayerTypeReplacement
};


/**
 *  Represents supported pixel formats for render buffers and bitmaps
 */
typedef NS_ENUM(NSUInteger, NMAPixelFormat) {
    /** Format is unknown.                    */
    NMAPixelFormatUnknown,
    /** Format is RGBA (4 bytes per pixel)    */
    NMAPixelFormatRGBA,
    /** Format is BGRA (4 bytes per pixel)    */
    NMAPixelFormatBGRA,
    /** Format is RGB (3 bytes per pixel)     */
    NMAPixelFormatRGB,
    /** Format is R5G6B5 (2 bytes per pixel)  */
    NMAPixelFormatR5G6B5
};

/**
 * Error codes that may be returned from places search requests.
 */
typedef NS_ENUM(NSUInteger, NMARequestError) {
    /** No error.                                                   */
    NMARequestErrorNone = 0,
    /** Unknown error.                                              */
    NMARequestErrorUnknown,
    /** Request is missing an address parameter.                    */
    NMARequestErrorAddressMissing,
    /** Location context is invalid.                                */
    NMARequestErrorLocationContextInvalid,
    /** Request is missing location context parameter.              */
    NMARequestErrorLocationContextMissing,
    /** Request is missing a country code in the address parameter. */
    NMARequestErrorCountryCodeMissing,
    /** Request missing search text parameter.                      */
    NMARequestErrorSearchTextMissing,
    /** Invalid query parameter.                                    */
    NMARequestErrorInvalidParameter,
    /** Network communications error.                               */
    NMARequestErrorNetworkCommunication,
    /** Backend server unreachable.                                 */
    NMARequestErrorNetworkServer,
    /** Request input missing.                                      */
    NMARequestErrorNetworkEmptyInput,
    /** HERE Application ID and Application Code are missing or invalid.  */
    NMARequestErrorInvalidCredentials,
    /** Request failed due to an HTTP error.                        */
    NMARequestErrorHttp,
    /** Unknown network error.                                      */
    NMARequestErrorNetworkUnknown,
    /** Functionality not supported                                 */
    NMARequestErrorNotSupported,
    /**
     * An entity is not ready. All poll functions return this when one needs to
     * poll again.  Also if an operation is in progress
     */
    NMARequestErrorNotReady,
    /** When something was not found                                */
    NMARequestErrorNotFound,
    /** When resource already exists                                */
    NMARequestErrorAlreadyExists,
    /** Out of memory                                               */
    NMARequestErrorOutOfMemory,
    /** When operation fails (e.g.extracting of file failed)        */
    NMARequestErrorOperationFailed,
    /** Operation aborted by user                                   */
    NMARequestErrorAborted,
    /** Search index failure                                        */
    NMARequestErrorFinderIndexFailure,
    /** Resource moved (e.g. resource URI changed)                  */
    NMARequestErrorMovedPermanently,
    /** Resource contend remains the same                           */
    NMARequestErrorNotModified,
    /** Invalid request (places component might need to be updated) */
    NMARequestErrorBadRequest,
    /** Resource no longer exists                                   */
    NMARequestErrorResourceGone,
    /** An error occured during document parsing (json, etc.)       */
    NMARequestErrorParse,
    /** Request timeout                                             */
    NMARequestErrorTimeout,
    /** Access to this operation is denied. Contact your HERE representative for more information.      */
    NMARequestErrorOperationNotAllowed
};


/**
 * Defines the color of the route.
 * Color is pre-defined by the map scheme according to the type.
 */
typedef NS_ENUM(NSUInteger, NMARouteDisplayType) {
    /**
     * The "default" type of the route.
     */
    NMARouteDisplayTypePrimary,
    /**
     * Secondary route can be used for example to show
     * another route with different settings or dynamic penalties.
     */
    NMARouteDisplayTypeSecondary,
    /**
     * The route color is set by the user
     */
    NMARouteDisplayTypeUserDefined
};

/**
 *  Defines the pedestrian map feature type used to show or hide map features that pedestrians may
 * encounter while walking.
 */
typedef NS_ENUM(NSInteger, NMAMapPedestrianFeatureType) {
    /** Crosswalk                */
    NMAMapPedestrianFeatureTypeCrosswalk,
    /** Stairway                 */
    NMAMapPedestrianFeatureTypeStairs,
    /** Escalator                */
    NMAMapPedestrianFeatureTypeEscalator,
    /** Elevator                 */
    NMAMapPedestrianFeatureTypeElevator,
    /** Tunnel                   */
    NMAMapPedestrianFeatureTypeTunnel,
    /** Bridge                   */
    NMAMapPedestrianFeatureTypeBridge,
    /** All pedestrian features  */
    NMAMapPedestrianFeatureTypeAll
};

/**
 *  Defines the fleet map feature type used to show or hide map features important to fleet vehicles.
 */
typedef NS_ENUM(NSInteger, NMAMapFleetFeatureType) {
    NMAMapFleetFeatureTypeEnvironmentalZones,
    NMAMapFleetFeatureTypeCongestionZones,
    NMAMapFleetFeatureTypeTruckRestrictions,
    NMAMapFleetFeatureTypeAll
};

/**
 * Custom pattern styles.
 *
 * IMPORTANT: This is a Beta API, and is subject to change without notice
 */
typedef NS_ENUM(NSUInteger, NMAPatternStyle) {
    /** \brief No pattern                                    */
    NMAPatternStyleNone,
    /** \brief Dashed pattern                                */
    NMAPatternStyleDash,
    /** \brief Blend custom pattern with the current color   */
    NMAPatternStyleCustomBlend,
    /** \brief Use custom pattern only                       */
    NMAPatternStyleCustomFill
};

#endif
