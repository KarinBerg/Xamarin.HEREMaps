/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMARoadElement;
@class NMARoutingMode;
@class NMARoutingZone;
@class NMARoutingZoneWarner;
@class NMARoutingZoneNotification;

/**
 * `NMARoutingZoneWarner` delegate providing routing zone warnings
 * relevant to the current navigation session.
 */
@protocol NMARoutingZoneWarnerDelegate<NSObject>
@optional

/**
 * Warning notification of routing zones ahead for the current navigation session.
 *
 * Callback will be triggered in about 200 meters before each `NMARoadElement` with routing zone.
 *
 * @param routingZoneWarner `NMARoutingZoneWarner` singleton instance.
 * @param notification `NMARoutingZoneNotification` representing restricted routing zones.
 */
- (void)routingZoneWarner:(nonnull NMARoutingZoneWarner *)routingZoneWarner
     didDetectRoutingZone:(nonnull NMARoutingZoneNotification *)notification;

/**
 * Warning notification of routing zone update for the current navigation session.
 *
 * This callback is triggered in following cases:
 *
 * 1. On entering routing zone restriction. In this case list of `NMARoutingZone` is returned.
 *
 * 2. On leaving routing zone restrictions. In this case nil is returned.
 *
 * @param routingZoneWarner `NMARoutingZoneWarner` singleton instance.
 * @param routingZones The list of updated routing zone restrictions.
 */
- (void)routingZoneWarner:(nonnull NMARoutingZoneWarner *)routingZoneWarner
     didUpdateRoutingZone:(nullable NSArray<NMARoutingZone *> *)routingZones;

@end

#pragma mark -


/**
 * Provides information about routing zones.
 *
 * @note This class should not be initialized directly. An instance should be obtained via
 * `[NMANavigationManager routingZoneWarner]`.
 */
@interface NMARoutingZoneWarner : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Delegate for notification of routing zone restrictions relevant to the current navigation session.
 */
@property (nonatomic, weak, nullable) id<NMARoutingZoneWarnerDelegate> delegate;

/**
 * Returns a list of routing zones for road element.
 *
 * @param roadElement Road element to check for routing zones.
 * @return The array of all routing zones in the current road element or nil
 * if there is no routing zones.
 */
+ (nullable NSArray<NMARoutingZone *> *)routingZonesForRoadElement:(nonnull NMARoadElement *)roadElement
NS_SWIFT_NAME(routingZones(roadElement:));

/**
 * Returns a list of routing zones for road element and specific routing mode.
 *
 * @param roadElement Road element to check for routing zones.
 * @param routingMode Routing mode with routing options applied.
 *
 * @return The array of all routing zones in the current road element or nil
 * if there is no routing zones.
 */
+ (nullable NSArray<NMARoutingZone *> *)routingZonesForRoadElement:(nonnull NMARoadElement *)roadElement
                                                       routingMode:(nonnull NMARoutingMode *)routingMode
NS_SWIFT_NAME(routingZones(roadElement:routingMode:));

/**
 * Starts the routing zone warner delegate callbacks.
 *
 * It will be started by default if there is an active navigation session
 * (`[NMANavigationManager navigationState]` is `NMANavigationStateRunning`).
 */
- (void)start;

/**
 * Stops the routing zone warner delegate callbacks.
 */
- (void)stop;

@end
