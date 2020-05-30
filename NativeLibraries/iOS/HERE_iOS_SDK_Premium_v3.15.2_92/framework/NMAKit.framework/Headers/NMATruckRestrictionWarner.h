/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMATruckRestriction;
@class NMATruckRestrictionNotification;
@class NMATruckRestrictionWarner;
@class NMARoutingMode;
@class NMARoadElement;

/**
 * NMATruckRestrictionWarner delegate providing truck restriction warnings
 * relevant to the current navigation session.
 */
@protocol NMATruckRestrictionWarnerDelegate<NSObject>
@optional

/**
 * Warning notification of truck restriction ahead for the current navigation session.
 *
 * Callback will be triggered in about 200 meters before each `NMARoadElement` with restriction.
 *
 * No callback if access to this operation is denied. Contact your HERE representative
 * for more information.
 *
 * @note This callback can be triggered even after entering truck restiction, in case
 * new truck restricitions appear ahead.
 * @param truckWarner `NMATruckRestrictionWarner` instance.
 * @param truckNotification `NMATruckRestrictionNotification` representing truck restriction.
 */
- (void)truckRestrictionWarner:(nonnull NMATruckRestrictionWarner *)truckWarner
     didDetectTruckRestriction:(nonnull NMATruckRestrictionNotification *)truckNotification;

/**
 * Warning notification of entering truck restriction for the current navigation session.
 *
 * This callback is triggered in following cases:
 *
 * 1. On entering truck restriction. In this case list of entered `NMATruckRestriction` is returned.
 *
 * 2. On active (entered) truck restriction change.
 * It means either new truck restrictions appear or leaving some of current truck restrictions.
 * In this case list of active truck restrictions are returned.
 *
 * 3. On leaving all truck restrictions. In this case nil is returned.
 *
 * No callback if access to this operation is denied. Contact your HERE representative
 * for more information.
 *
 * @param truckWarner `NMATruckRestrictionWarner` instance.
 * @param truckRestrictions The list of updated truck restrictions.
 */
- (void)truckRestrictionWarner:(nonnull NMATruckRestrictionWarner *)truckWarner
     didUpdateTruckRestriction:(nullable NSArray<NMATruckRestriction *> *)truckRestrictions;

@end

#pragma mark -


/**
 * Provides truck restriction for the current navigation session or created route.
 *
 * @note This class should not be initialized directly. An instance should be obtained via
 * `NMANavigationManager.truckRestrictionWarner`.
 */
@interface NMATruckRestrictionWarner : NSObject

/**
 * Gets all truck restrictions for the NMARoadElement.
 *
 * @note To get truck restriction for specific `NMARoutingMode` use
 * `truckRestrictionsForRoadElement:routingMode:`.
 *
 * @param roadElement NMARoadElement road element which may contain truck restriction.
 * @return The array of all truck restrictions for road element.
 */
+ (nullable NSArray<NMATruckRestriction *> *)truckRestrictionsForRoadElement:(nonnull NMARoadElement *)roadElement
NS_SWIFT_NAME(truckRestrictions(roadElement:));

/**
 * Gets the truck restrictions for specific road element and routing mode.
 *
 * @note Truck restrictions available only in `NMATransportModeTruck`.
 *
 * @param roadElement NMARoadElement road element which may contain truck restriction.
 * @param mode NMARoutingMode with truck transport mode.
 * @return The array of all truck restrictions for road element considering routing mode.
 */
+ (nullable NSArray<NMATruckRestriction *> *)truckRestrictionsForRoadElement:(nonnull NMARoadElement *)roadElement
                                                                 routingMode:(nonnull NMARoutingMode *)mode;

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Delegate for notification of truck restrictions relevant to the current navigation session.
 */
@property (nonatomic, weak, nullable) id<NMATruckRestrictionWarnerDelegate> delegate;

/**
 * Starts the truck restriction warner delegate callbacks.
 *
 * It will be started by default if there is an active navigation session
 * (`NMANavigationManager.navigationState` is `NMANavigationStateRunning`).
 */
- (void)start;
/**
 * Stops the truck restriction warner delegate callbacks.
 */
- (void)stop;

@end
