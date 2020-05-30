/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * Normal scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeNormalDay;

/**
 * Normal scheme presented in "night" colors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeNormalNight;

/**
 * Normal scheme presented in "day" with less color palette.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeReducedDay;

/**
 * Normal scheme presented in "night" with less color palette.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeReducedNight;

/**
 * Normal scheme presented in "day" colors, with highlighted transit lines.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeNormalDayTransit;

/**
 * Normal scheme presented in "night" colors, with highlighted transit
 * lines.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeNormalNightTransit;

/**
 * Terrain bitmap scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeTerrainDay;

/**
 * Satellite tile scheme presented in "day" colors.
 *
 * @note No roads are shown. For satellite and roads use `NMAMapSchemeHybridDay`
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeSatelliteDay;

/**
 * Satellite tile scheme presented in "night" colors.
 *
 * @note No roads are shown.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeSatelliteNight;

/**
 * Satellite tile scheme presented in "day" colors, with roads.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridDay;

/**
 * Satellite tile scheme presented in "day" colors, with roads, that is suitable for
 * use cases in which map still has a high relevance but is used as background for overlays
 * (like venue maps).
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridGreyDay;

/**
 * Satellite tile scheme presented in "night" colors, with roads.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridNight;

/**
 * Satellite tile scheme presented in "night" colors, with roads, that is suitable for
 * use cases in which map still has a high relevance but is used as background for overlays
 * (like venue maps).
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridGreyNight;

/**
 * Satellite tile scheme presented in "day" with roads but less color palette.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridReducedDay;

/**
 * Satellite tile reduced scheme presented in "night" colors, with roads.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridReducedNight;

/**
 * Normal scheme suitable for single maneuver overview. This scheme is useful for guidance
 * and routing use cases. This scheme can be used for day and night since it has a strong
 * contrast.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeManeuverDay;

/**
 * Satellite tile scheme presented in "day" colors, with roads and
 * highlighted transit lines.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridDayTransit;

/**
 * Satellite tile scheme presented in "night" colors, with roads and
 * highlighted transit lines.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridNightTransit;

/**
 * Car navigation scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeCarNavigationDay;

/**
 * Car navigation scheme presented in "day" colors that is suitable for use cases in which map still
 * has a high relevance but is used as background for overlays (like venue maps).
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeCarNavigationDayGrey;

/**
 * Car navigation scheme presented in "night" colors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeCarNavigationNight;

/**
 * Car navigation scheme presented in "night" colors that is suitable for use cases in which map still
 * has a high relevance but is used as background for overlays (like venue maps).
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeCarNavigationNightGrey;

/**
 * Satellite tile car navigation scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridCarNavigationDay;

/**
 * Satellite tile pedestrian navigation scheme presented in "day" colors.
 *
 * @note When using this scheme it is recommended to enable pedestrian features
 * on the map view, see `NMAMapView#showPedestrianFeature:(NMAMapPedestrianFeatureType)`
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridPedestrianDay;

/**
 * Satellite tile pedestrian navigation scheme presented in "night" colors.
 *
 * @note When using this scheme it is recommended to enable pedestrian features
 * on the map view, see `NMAMapView#showPedestrianFeature:(NMAMapPedestrianFeatureType)`
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridPedestrianNight;

/**
 * Satellite tile car navigation scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridCarNavigationNight;

/**
 * Pedestrian navigation scheme presented in "day" colors.
 *
 * @note When using this scheme it is recommended to enable pedestrian features on the map view,
 * see `NMAMapView#showPedestrianFeature:(NMAMapPedestrianFeatureType)`.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemePedestrianDay;

/**
 * Pedestrian navigation scheme presented in "night" colors.
 *
 * @note When using this scheme it is recommended to enable pedestrian features on the map view,
 * see `NMAMapView#showPedestrianFeature:(NMAMapPedestrianFeatureType)`.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemePedestrianNight;

/**
 * Truck scheme presented in "day" colors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeTruckDay;

/**
 * Truck scheme presented in "night" colors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeTruckNight;

/**
 * Satellite tile scheme presented in "day" colors with truck related attributes
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridTruckDay;

/**
 * Satellite tile scheme presented in "night" colors with truck related attributes
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridTruckNight;

/**
 * Normal scheme presented in "day" colors that is suitable for truck guidance.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeTruckNavigationDay;

/**
 * Normal scheme presented in "night" colors that is suitable for truck guidance.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeTruckNavigationNight;

/**
 * Satellite tile scheme presented in "day" colors, with visible roads, that is suitable for
 * for truck guidance.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridTruckNavigationDay;

/**
 * Satellite tile scheme presented in "night" colors, with visible roads, that is suitable
 * for truck guidance.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridTruckNavigationNight;

/**
 * Traffic optimized version of NMAMapSchemeNormalDay.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeNormalDayWithTraffic;

/**
 * Traffic optimized version of NMAMapSchemeNormalNight.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeNormalNightWithTraffic;

/**
 * Traffic optimized version of NMAMapSchemeHybridDay.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridDayWithTraffic;

/**
 * Traffic optimized version of NMAMapSchemeHybridNight.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridNightWithTraffic;

/**
 * Traffic optimized version of NMAMapSchemeCarNavigationDay.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeCarNavigationDayWithTraffic;

/**
 * Traffic optimized version of NMAMapSchemeCarNavigationNight.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeCarNavigationNightWithTraffic;

/**
 * Traffic optimized version of NMAMapSchemeHybridCarNavigationDay.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridCarNavigationDayWithTraffic;

/**
 * Traffic optimized version of NMAMapSchemeHybridCarNavigationNight.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAMapSchemeHybridCarNavigationNightWithTraffic;
