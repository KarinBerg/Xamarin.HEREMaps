/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMASchoolZoneNotification;
@class NMASchoolZoneWarner;
@class NMARoadElement;
@class NMASchoolZoneInfo;

/**
 * NMASchoolZoneWarner delegate providing school zone warnings relevant to the current navigation
 * session.
 */
@protocol NMASchoolZoneWarnerDelegate<NSObject>
@optional

/**
 * Warning notification of school zone ahead for the current navigation session.
 *
 * Callback will be triggered in about 100 meters before `NMARoadElement` with school zone.
 *
 * @param schoolZoneWarner `NMASchoolZoneWarner` singleton instance.
 * @param schoolZoneNotification `NMASchoolZoneNotification` representing school zone.
 */
- (void)schoolZoneWarner:(nonnull NMASchoolZoneWarner *)schoolZoneWarner
     didDetectSchoolZone:(nonnull NMASchoolZoneNotification *)schoolZoneNotification;

/**
 * Warning notification of school zone update for the current navigation session.
 *
 * This callback is triggered in following cases:
 *
 * 1. On entering school zone. In this case `NMASchoolZoneInfo` instance is returned.
 *
 * 2. On leaving school zone. In this case nil is returned.
 *
 * @param schoolZoneWarner `NMASchoolZoneWarner` singleton instance.
 * @param schoolZoneInfo `NMASchoolZoneInfo` representing school zone.
 */
- (void)schoolZoneWarner:(nonnull NMASchoolZoneWarner *)schoolZoneWarner
     didUpdateSchoolZone:(nonnull NMASchoolZoneInfo *)schoolZoneInfo;

@end

#pragma mark -


/**
 * Provides school zone warning notifications for the current navigation session.
 *
 * Notifications are generated when NMANavigationManager performs turn-by-turn navigating
 * (`NMANavigationModeTurnByTurn`) for `NMATransportModeCar` or `NMATransportModeTruck` transport
 * modes.
 * The default distance for triggering this warning is 100 meters from the school zone.
 *
 * @note This class should not be initialized directly. An instance should be obtained via
 * [NMANavigationManager schoolZoneWarner].
 */
@interface NMASchoolZoneWarner : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Delegate for notification of school zones relevant to the current navigation session.
 */
@property (nonatomic, weak, nullable) id<NMASchoolZoneWarnerDelegate> delegate;

/**
 * Obtains school zone information for specific road element.
 *
 * @note Use `schoolZoneInfoForRoadElement:time:` to get school zone for specific time.
 *
 * @param roadElement Road element to check for school zone.
 * @return `NMASchoolZoneInfo` for road element or nil if there is no school zone in the
 * provided road element.
 */
+ (nullable NMASchoolZoneInfo *)schoolZoneInfoForRoadElement:(nonnull NMARoadElement *)roadElement
NS_SWIFT_NAME(schoolZoneInfo(roadElement:));

/**
 * Obtains school zone information for specific road element for specific time.
 *
 * @param roadElement Road element to check for school zone.
 * @param time Time to check for school zone.
 * @return `NMASchoolZoneInfo` for road element or nil if there is no school zone in the
 * provided road element. Return nil if school zone is not active for provided time.
 */
+ (nullable NMASchoolZoneInfo *)schoolZoneInfoForRoadElement:(nonnull NMARoadElement *)roadElement
                                                        time:(nonnull NSDate *)time
NS_SWIFT_NAME(schoolZoneInfo(roadElement:time:));

/**
 * Starts the school zone warner delegate callbacks.
 *
 * It will be started by default if there is an active navigation session
 * (`[NMANavigationManager navigationState]` is `NMANavigationStateRunning`).
 */
- (void)start;

/**
 * Stops the school zone warner delegate callbacks.
 */
- (void)stop;

@end
