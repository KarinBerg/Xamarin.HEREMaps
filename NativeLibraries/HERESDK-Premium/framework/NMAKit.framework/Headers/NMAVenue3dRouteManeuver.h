/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAManeuver.h"

@class NMAVenue3dSpace;
@class NMAGeoCoordinates;
@class NMAMapObject;


/**
 * Represents values that describe the possible enter/exit actions.
 *
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dRouteActionType) {
    /**
     * No action.
     */
    NMAVenue3dRouteActionTypeNone,

    /**
     * Enter action.
     */
    NMAVenue3dRouteActionTypeEnter,

    /**
     * Exit action.
     */
    NMAVenue3dRouteActionTypeExit
};

/**
 * Represents values that describe the vertical directionality of a maneuver.
 *
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dRouteLevelChangeType) {
    /**
     * No level change.
     */
    NMAVenue3dRouteLevelChangeTypeNone,

    /**
     * A maneuver moves up.
     */
    NMAVenue3dRouteLevelChangeTypeUp,

    /**
     * A maneuver moves down.
     */
    NMAVenue3dRouteLevelChangeTypeDown
};

/**
 * Represents values that describe a connector type from one space to other.
 *
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dRouteConnectorType) {
    /**
     * An elevator.
     */
    NMAVenue3dRouteConnectorTypeElevator,

    /**
     * An escalator.
     */
    NMAVenue3dRouteConnectorTypeEscalator,

    /**
     * Stairs.
     */
    NMAVenue3dRouteConnectorTypeStairs,

    /**
     * A skywalk.
     */
    NMAVenue3dRouteConnectorTypeSkywalk,

    /**
     * A Shuttle.
     */
    NMAVenue3dRouteConnectorTypeShuttle,

    /**
     * A Moving sidewak.
     */
    NMAVenue3dRouteConnectorTypeMovingSidewalk,

    /**
     * A Ramp.
     */
    NMAVenue3dRouteConnectorTypeRamp,

    /**
     * An other category.
     */
    NMAVenue3dRouteConnectorTypeOtherCategory,

    /**
     * Not a connector.
     */
    NMAVenue3dRouteConnectorTypeNotConnector
};


/**
 * Describes a single route maneuver of indoor route section.
 *
 * See also `NMAVenue3dVenueRouteSection`
 */
@interface NMAVenue3dRouteManeuver : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Returns a target maneuver for a series of connectors of the
 * same type (elevator, escalator etc.) which are going in the
 * same direction. We accept some links between connectors, like
 * in case of stairs or escalators.
 * For example, if the user enters an elevator, then the target
 * maneuver will be the exit from it. Otherwise returns nil.
 */
@property (nonatomic, readonly, nullable) NMAVenue3dRouteManeuver *targetManeuver;

/**
 * The bounding box of venue route section
 * this NMAVenue3dRouteManeuver belongs to.
 */
@property (nonatomic, readonly, nonnull) NMAGeoBoundingBox *boundingBox;

/**
 * NMAVenue3dRouteActionType for this NMAVenue3dRouteManeuver object.
 */
@property (nonatomic, readwrite) NMAVenue3dRouteActionType routeActionType;

/**
 * NMAVenue3dRouteLevelChangeType for this NMAVenue3dRouteManeuver object.
 */
@property (nonatomic, readonly) NMAVenue3dRouteLevelChangeType levelChangeType;

/**
 * The `NMAManeuverTurn` to take for the maneuver.
 *
 * @note If the turn for the maneuver is undefined, attempts to read this
 * property will return NMAManeuverTurnUndefined.
 */
@property (nonatomic, readonly) NMAManeuverTurn turn;

/**
 * NMAVenue3dRouteConnectorType for this NMAVenue3dRouteManeuver object.
 *
 */
@property (nonatomic, readwrite) NMAVenue3dRouteConnectorType routeConnectorType;

/**
 * NMAVenue3dSpace object related to this NMAVenue3dRouteManeuver object.
 */
@property (nonatomic, readwrite, nullable) NMAVenue3dSpace *space;

/**
 * Geocoordinates of the maneuver.
 */
@property (nonatomic, readonly, nonnull) NMAGeoCoordinates *geoCoordinates;

/**
 * Geometry of the maneuver.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAGeoCoordinates *> *geometry;

/**
 * Distance of the maneuver from the start of the route.
 */
@property (nonatomic, readonly) float distanceFromStart;

/**
 * Distance of the maneuver from the previous maneuver.
 */
@property (nonatomic, readonly) float distanceFromPreviousManeuver;

/**
 * Distance from this maneuver to the next maneuver.
 */
@property (nonatomic, readonly) float distanceToNextManeuver;

/**
 * Floor index of the location of the maneuver.
 */
@property (nonatomic, readonly) NSInteger floorIndex;

/**
 * The angle in degrees from end of the start road to the start of the end road. Angle has a value from 0,
 * 360, north is up, clockwise. A returned value of zero represents the end road that continues in the same
 * direction as the start road.
 */
@property (nonatomic, readonly) NSInteger angle;

/**
 * The angle (from north) at the start of the maneuver, in degrees.
 *
 * @note Zero represents true-north, with increasing
 * values representing a clockwise progression of map orientation.
 */
@property (nonatomic, readonly) NSInteger mapOrientation;

/**
 * The radius in meters inside of which POIs for natural guidance are searched.
 */
+ (float) naturalGuidanceRadius;

/**
 * Sets the natural guidance radius.
 *
 * @param radius    The radius in meters around the position of a maneuver in which
 *                  POIs for natural guidance are searched.
 */
+ (void) setNaturalGuidanceRadius:(float)radius;

/**
 * The blacklist of the venue-specific category identifiers, which will not be taken
 * into consideration, when searching for the natural guidance POI for the
 * NMAVenue3dRouteManeuver objects.
 */
+ (nonnull NSSet<NSString *> *) naturalGuidanceBlacklist;

/**
 * Removes the specific category id from the natural guidance blacklist of the categories.
 *
 * @param categoryId Venue-specific category identifier.
 *
 * @note The natural guidance POIs of previously constructed NMAVenue3dRouteManeuver objects
 * will not be affected by changing this blacklist - you have to recalculate the
 * NMAVenue3dCombinedRoute in order to see changes.
 */
+ (void) addCategoryToNaturalGuidanceBlacklist:(nonnull NSString *)categoryId
NS_SWIFT_NAME(addCategoryToNaturalGuidanceBlacklist(categoryId:));

/**
 * Blacklist specific category id, which will be discarded from searching for the
 * natural guidance POI for the NMAVenue3dRouteManeuver objects.
 *
 * @param categoryId Venue-specific category identifier.
 *
 * @note The natural guidance POIs of previously constructed NMAVenue3dRouteManeuver objects
 * will not be affected by changing this blacklist - you have to recalculate the
 * NMAVenue3dRouteManeuver in order to see changes.
 */
+ (void) removeCategoryFromNaturalGuidanceBlacklist:(nonnull NSString *)categoryId
NS_SWIFT_NAME(removeCategoryFromNaturalGuidanceBlacklist(categoryId:));

/**
 * The name of the POI used for natural guidance, or the empty string.
 */
@property (nonatomic, readonly, nonnull) NSString* naturalGuidancePOI;

/**
 * The map object, which is displayed on the geoCoordinates of this maneuver.
 */
- (nullable NMAMapObject*)mapObject;

/**
 * Sets the current map object, which will be displayed on the geoCoordinates of maneuver.
 *
 * @param mapObject The `NMAMapObject` instance, which will be displayed on the geoposition of
 *                  this maneuver. Acceptable types are: `NMAMapMarker` and `NMAMapLocalModel`;
 *                  attempts to pass other objects will be ignored and NO will be returned.
 *                  If mapObject is nil, the default mapObject will be used, depending on the
 *                  maneuver's connector type (`NMAVenue3dRouteManeuver::routeConnectorType`).
 *
 * @return Whether the changing of maneuver was successful.
 */
- (BOOL)setMapObject:(nullable NMAMapObject*)mapObject;

@end
