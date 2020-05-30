/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "NMARoutingMode.h"
#import "NMAVenue3dRouteSection.h"

@class NMAMapObject;


/**
 * Defines style options for the key points of the NMAVenue3dCombinedRoute.
 *
 * Defines the pack of NMAMapObject prototypes that are used for customizing the map objects,
 * which are displayed on the key points of the NMAVenue3dCombinedRoute.
 * By default all the prototypes are nil, which means that default NMAMapMarker objects will be used
 * for those prototypes.
 *
 * The term "prototype" means that the provided NMAMapObject will not be used directly on the map,
 * but instead each time when this instance of NMAVenue3dRouteStyleOptions is passed to
 * NMAVenue3dRoutingController::showRoute:, copy of this prototype will be created and this copy will
 * be displayed on the specific point along the route.
 *
 * @note All the NMAMapObject prototypes accept only objects, which are inherited from
 * NMAMapMarker or NMAMapLocalModel classes; attemps to set other objects will be ignored.
 *
 * See also `NMAVenue3dRoutingController::showRoute:`
 */
@interface NMAVenue3dRouteStyleOptions : NSObject

/**
 * The NMAMapObject prototype at the start location of the NMAVenue3dCombinedRoute.
 *
 * @note Acceptable types are NMAMapMarker and NMAMapLocalModel.
 * @note If nil is specified, the default map object will be displayed on this location.
 */
@property( nonatomic, readwrite, nullable ) NMAMapObject *startRouteMapObject;

/**
 * The NMAMapObject prototype at the end location of the NMAVenue3dCombinedRoute.
 *
 * @note Acceptable types are NMAMapMarker and NMAMapLocalModel.
 * @note If nil is specified, the default map object will be displayed on this location.
 */
@property( nonatomic, readwrite, nullable ) NMAMapObject *endRouteMapObject;

/**
 * The NMAMapObject prototype at the start location of the NMAVenue3dOutdoorRouteSection section
 * of the NMAVenue3dCombinedRoute route.
 *
 * @note Acceptable types are NMAMapMarker and NMAMapLocalModel.
 * @note If nil is specified, the default map object will be displayed on this location.
 */
@property( nonatomic, readwrite, nullable ) NMAMapObject *enterCarMapObject;

/**
 * The NMAMapObject prototype at the end location of the NMAVenue3dOutdoorRouteSection
 * of the NMAVenue3dCombinedRoute, i.e. at the start of the NMAVenue3dLinkRouteSection section.
 *
 * @note Acceptable types are NMAMapMarker and NMAMapLocalModel.
 * @note If nil is specified, the default map object will be displayed on this location.
 */
@property( nonatomic, readwrite, nullable ) NMAMapObject *leaveCarMapObject;

/**
 * Specifies the NMAMapObject prototype for the waypoint at specified index.
 *
 * @param mapObject
 *          The NMAMapObject prototype for the waypoint with the given index.
 *          Acceptable types are NMAMapMarker and NMAMapLocalModel; attemps to set other objects
 *          will be ignored and NO will be returned. Note that if nil is specified,
 *          the default map object will be displayed at that waypoint.
 * @param waypointIndex
 *          The index of the waypoint of the route (excluding start and end locaions).
 *          Should be in range from 0 to 8 (inclusive). NMAVenue3dCombinedRoute#getWaypoints
 *          NMAVenue3dRoutingController#calculateRouteWithPoints
 *
 * @return YES if the map object changed successully and NO otherwise.
 */
- (BOOL)setMapObject:(nullable NMAMapObject *)mapObject forWaypoint:(NSUInteger)waypointIndex
NS_SWIFT_NAME(setMapObject(mapObject:waypointIndex:));

/**
 * Returns the NMAMapObject, which is used as prototype at specific waypoint index on the route.
 *
 * @param waypointIndex The index of the waypoint. Should be in the range from 0 to 8 (inclusive).
 *
 * @return The NMAMapObject prototype associated with the waypoint at the given index.
 */
- (nullable NMAMapObject *)mapObjectForWaypoint:(NSUInteger)waypointIndex
NS_SWIFT_NAME(mapObjectForWaypoint(_:));

/**
 * The size in points of the default icon for the start location of the route.
 *
 * @note Changing this size to CGSizeZero will revert the icon's size to the default one.
 */
@property( nonatomic, readwrite ) CGSize startRouteDefaultIconSize;

/**
 * The size in points of the default icon for the end location of the route.
 *
 * @note Changing this size to CGSizeZero will revert the icon's size to the default one.
 */
@property( nonatomic, readwrite ) CGSize endRouteDefaultIconSize;

/**
 * The size in points of the default icon for the connector location of the link and
 * outdoor sections (i.e. enter car icon).
 *
 * @note Changing this size to CGSizeZero will revert the icon's size to the default one.
 */
@property( nonatomic, readwrite ) CGSize enterCarDefaultIconSize;

/**
 * The size in points of the default icon for the connector location of the outdoor and
 * link sections (i.e. leave car icon).
 *
 * @note Changing this size to CGSizeZero will revert the icon's size to the default one.
 */
@property( nonatomic, readwrite ) CGSize leaveCarDefaultIconSize;

/**
 * The size in points of the default icons for the connectors of the route inside the building.
 * By connectors this means the NMAVenue3dRouteManeuver objects of the
 * NMAVenue3dVenueRouteSection.
 *
 * @note Changing this size to CGSizeZero will revert the icons' sizes to the default one.
 */
@property( nonatomic, readwrite ) CGSize connectorsDefaultIconSize;

/**
 * The size in points of the default icons for the waypoints along the route.
 *
 * @note Changing this size to CGSizeZero will revert the icons' size to the default one.
 */
@property( nonatomic, readwrite ) CGSize waypointsDefaultIconSize;

@end
