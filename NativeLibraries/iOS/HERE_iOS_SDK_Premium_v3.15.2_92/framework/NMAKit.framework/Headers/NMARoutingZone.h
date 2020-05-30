/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMARoutingZoneRestriction.h"

/**
 * Defines possible routing zone types used for zone exclusions from route during calculation.
 */
typedef NS_ENUM(NSUInteger, NMARoutingZoneType) {
    /** Vignette toll system. */
    NMARoutingZoneTypeVignette = 0,
    /** Congestion pricing or city maut toll system. */
    NMARoutingZoneTypeCongestionPricing = 1,
    /** Administrative class of road. */
    NMARoutingZoneTypeAdministrativeClass = 2,
    /** Environmental zones (mainly in cities). */
    NMARoutingZoneTypeEnvironmental = 3,
};


/**
 * Class provides basic information about the routing zone and can be passed as an option to
 * routing.
 *
 * Use `NMARoute.routingZones` to get routing zones used in the route.
 * Use `NMARoutingMode.excludeRoutingZones` to avoid certain routing zones during route calculation.
 *
 * @note Routing zones are supported only for `NMATransportModeCar`, `NMATransportModeTruck` and
 * `NMATransportModeScooter` transport modes.
 *
 * @note IMPORTANT: Routing zones is a Beta feature. The related classes are subject to change
 * without notice
 */
@interface NMARoutingZone : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Gets the identifier.
 */
@property (nonatomic, nonnull, readonly) NSString *identifier;

/**
 * Gets the name of the routing zone.
 */
@property (nonatomic, nonnull, readonly) NSString *name;

/**
 * Gets list of restrictions in current routing zone.
 */
@property (nonatomic, nonnull, readonly) NSArray<NMARoutingZoneRestriction *> *restrictions;

/**
 * Returns the type of the routing zone.
 */
@property (nonatomic, readonly) NMARoutingZoneType type;

@end
