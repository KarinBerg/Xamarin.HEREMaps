/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMARoutingMode.h"
#import "NMARoute.h"
#import "NMARoutingError.h"
#import "NMAManeuver.h"

@class NMAGeoCoordinates;
@class NMAGeoPosition;
@class NMAManeuver;
@class NMAMapView;
@class NMANavigationManager;
@class NMARoadElement;
@class NMARoute;
@class NMARouteResult;
@class NMAVoicePackage;
@class NMATrafficWarner;
@class NMATrafficNotification;
@class NMASafetySpotWarner;
@class NMASafetySpotNotification;
@class NMALaneInformation;
@class NMATruckRestrictionWarner;
@class NMAImage;
@class NMASchoolZoneWarner;
@class NMARoutingZoneWarner;

/**
 * The Navigation group includes classes, protocols, and enumerations
 * related to guidance and turn-by-turn navigation.
 * The key class to this group is `NMANavigationManager`.
 */

/**
 * The error domain for Navigation Manager.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMANavigationManagerErrorDomain;

/**
 * Unsigned integer, 64 bit wide
 */
typedef unsigned long long NMAUint64;

/**
 * Indicates failure of a computation for a 64-bit value.
 */
FOUNDATION_EXPORT NMAUint64 const NMANavigationManagerInvalidValue;

/**
 * This notification is sent whenever the NMANavigationManager navigationState
 * property changes.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMANavigationManagerStateChangedNotification;

/**
 * This is the key for extracting signpost from realistic view
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMANavigationManagerSignpostKey;

/**
 * This is the key for extracting junction view from realistic view
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMANavigationManagerJunctionViewKey;

/**
 * This is the key for extracting 16x9 realistic view
 */
FOUNDATION_EXPORT const id _Nonnull NMARealisticView16x9Key;

/**
 * This is the key for extracting 3x5 realistic view
 */
FOUNDATION_EXPORT const id _Nonnull NMARealisticView3x5Key;

/**
 * This is the key for extracting 5x3 realistic view
 */
FOUNDATION_EXPORT const id _Nonnull NMARealisticView5x3Key;

/**
 * This is the key for extracting 4x3 realistic view
 */
FOUNDATION_EXPORT const id _Nonnull NMARealisticView4x3Key;

/**
 * The possible states of NMANavigationManager.
 */
typedef NS_ENUM(NSUInteger, NMANavigationState) {
    /** No navigation is in progress */
    NMANavigationStateIdle = 0,
    /** Navigation (guidance or tracking) is in progress and active */
    NMANavigationStateRunning,
    /** Navigation is in progress but not currently active */
    NMANavigationStatePaused
};

/**
 * The possible modes of NMANavigationManager.
 */
typedef NS_ENUM(NSUInteger, NMANavigationMode) {
    /**
     * Navigation is not running
     */
    NMANavigationModeNone = 0,
    /**
     * Navigation is running in turn-by-turn mode
     * (following a route using GPS data, recalculation
     * will occur if position deviates from route)
     */
    NMANavigationModeTurnByTurn,
    /**
     * Navigation is running in tracking mode
     * (Not following a route, GPS data drives map movement)
     */
    NMANavigationModeTracking
};

/**
 * The orientation that is used when map tracking is enabled.
 */
typedef NS_ENUM(NSUInteger, NMAMapTrackingOrientation) {
    /** The map will be oriented with the current heading toward the top of the screen */
    NMAMapTrackingOrientationDynamic,
    /** The map will be oriented with north toward the top of the screen */
    NMAMapTrackingOrientationNorthUp,
};

/**
 * The tilt that is used when map tracking is enabled.
 */
typedef NS_ENUM(NSUInteger, NMAMapTrackingTilt) {
    /** The map will be automatically tilted to a 2D perspective */
    NMAMapTrackingTilt2D,
    /** The map will be automatically tilted to a 3D perspective */
    NMAMapTrackingTilt3D,
    /** The map tilt will not be changed */
    NMAMapTrackingTiltCustom
};

/**
 * Distance measurement unit systems
 */
typedef NS_ENUM(NSUInteger, NMAMeasurementSystem) {
    /** Meter and kilometer */
    NMAMeasurementSystemMetric = 0,
    /** Miles and yards     */
    NMAMeasurementSystemImperial,
    /** Miles and feet      */
    NMAMeasurementSystemImperialUS
};

/**
 * Realistic view aspect ratio
 */
typedef NS_OPTIONS(NSUInteger, NMARealisticViewAspectRatio) {
    NMARealisticView16x9 = 0x1,
    NMARealisticView3x5 = 0x2,
    NMARealisticView5x3 = 0x4,
    NMARealisticView4x3 = 0x8
};

/**
 * Realistic view modes
 */
typedef NS_ENUM(NSUInteger, NMARealisticViewMode) {
    NMARealisticViewOff,
    NMARealisticViewDay,
    NMARealisticViewNight
};

/**
 * Navigation Errors
 */
typedef NS_ENUM(NSUInteger, NMANavigationError) {
    NMANavigationErrorNone,
    /** Guidance is not ready for use */
    NMANavigationErrorGuidanceNotReady,
    /** Guidance Polling must be continued */
    NMANavigationErrorNotReady,
    /** Failed to start Positioning Manager */
    NMANavigationErrorPositioningFailed,
    /** Out of Memory */
    NMANavigationErrorOutOfMemory,
    /** Invalid Parameters */
    NMANavigationErrorInvalidParameters,
    /** Operation not allowed at the time of the call */
    NMANavigationErrorInvalidOperation,
    /** When something was not found (e.g. voice skins) */
    NMANavigationErrorNotFound,
    /** Operation aborted */
    NMANavigationErrorAborted,
    /** The current SDK does not allow the operation */
    NMANavigationErrorOperationNotAllowed,
    /** HERE Developer credentials are invalid or were not provided */
    NMANavigationErrorInvalidCredentials,
    /** The current position data source does not support pedestrian navigation */
    NMANavigationErrorPedestrianNavigationNotAvailable,
    /** Generic error */
    NMANavigationErrorUnknown
};

/**
 * Options for the NMANavigationManager natural guidance feature, set using
 * the `NMANavigationManager::setNaturalGuidanceMode:` method.
 */
typedef NS_OPTIONS(NSUInteger, NMANaturalGuidanceOption) {
    NMANaturalGuidanceNone            = 0,
    /** Natural guidance for traffic lights. */
    NMANaturalGuidanceTrafficLight    = 0x01,
    /**
     * Natural guidance for landmarks.
     *
     * @note Supported only if `NMAVoicePackage::language` matches
     * `NMAMapView::displayLanguage`.
     */
    NMANaturalGuidanceLandmark       = 0x04,
};

/**
 * Options for the NMANavigationManager traffic avoidance feature, set using
 * the NMANavigationManager::setTrafficAvoidanceMode:(NSUInteger) method.
 */
typedef NS_ENUM(NSUInteger, NMATrafficAvoidanceMode) {
    /**
     * Route recalculated periodically due to traffic on route.
     * Updates automatically if the new route is better than existing one.
     *
     * See also `NMANavigationManager::setRouteRequestInterval:`
     */
    NMATrafficAvoidanceDynamic,
    /**
     * Traffic on route avoidance must be confirmed by the user.
     */
    NMATrafficAvoidanceManual,
    /**
     * Disable use of traffic for rerouting purpose.
     */
    NMATrafficAvoidanceDisabled
};

/**
 * States used to describe the current route re-calculation due to traffic's status.
 *
 * @note It is only applicable with traffic avoidance mode.
 *
 * See also `NMANavigationManager::setTrafficAvoidanceMode:`
 *
 * See also `NMATrafficAvoidanceMode`
 */
typedef NS_ENUM(NSUInteger, NMATrafficEnabledRoutingState) {
    /**
     * Route re-calculation due to traffic is disabled, when traffic avoidance mode is set
     * to NMATrafficAvoidanceDisabled.
     */
    NMATrafficEnabledRoutingStateOff,
    /**
     * Route re-calculation due to traffic is enabled and not currently in use.
     */
    NMATrafficEnabledRoutingStateOn,

    /**
     * Route re-calculation is enabled but re-routing cannot be processed. For example, the
     * application is currently offline.
     */
    NMATrafficEnabledRoutingStateNotAvailable
};

/**
 * TTS output format in which the text should be generated.
 *
 * See also `NMANavigationManagerDelegate::navigationManager:shouldPlayVoiceFeedbackWithText:`
 */
typedef NS_ENUM(NSUInteger, NMATTSOutputFormat) {
    /** The text won't include any phonemes and escape sequences. */
    NMATTSOutputFormatRaw = 0,

    /** The text will include phonemes in a format supported by Nuance TTS. */
    NMATTSOutputFormatNuance = 1
};

/**
 * Configures the audio events that will be played during Navigation.
 */
typedef NS_OPTIONS(NSUInteger, NMANavigationAudioEvent) {
    /**
     * Safety spot audio event (played when approaching a safety spot).
     *
     * An example of a safety spot is a speed camera or a red light camera.
     *
     * Only played when NMANavigationManager is navigating a route (navigationMode
     * NMANavigationModeTurnByTurn) using an appropriate transport mode (e.g. neither
     * `NMATransportModePedestrian` nor `NMATransportModeBike`).
     *
     * This audio event is disabled by default.
     *
     * @note Not played if access to this operation is denied. Contact your HERE representative for
     * more information.
     */
    NMANavigationAudioEventSafetySpot = 0x20
};

/**
 * An interface for responding to navigation events sent by the
 * NMANavigationManager.
 */
@protocol NMANavigationManagerDelegate<NSObject>
@optional

/**
 * Called when the destination of turn-by-turn navigation is reached.
 *
 * When the destination is reached, NMANavigationManager -stop is automatically
 * called. When this callback is received, the navigation manager state will be
 * NMANavigationStateIdle.
 */
- (void)navigationManagerDidReachDestination:(nonnull NMANavigationManager*)navigationManager;

/**
 * Called when the current (upcoming) maneuver is updated.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param currentManeuver The current (upcoming) maneuver to be made.
 * @param nextManeuver The maneuver to be made AFTER THE CURRENT MANEUVER.
 *
 * @note The "current" maneuver is the upcoming, or next, maneuver to be taken. The "next" maneuver is
 * actually the maneuver to be taken after the current maneuver.
 *
 * @note If the "current" maneuver is also a stopover,
 * NMANavigationManagerDelegate::navigationManager:didReachStopover
 * will also be called.
 */
- (void)navigationManager:(nonnull NMANavigationManager*)navigationManager
       hasCurrentManeuver:(nullable NMAManeuver *)currentManeuver
             nextManeuver:(nullable NMAManeuver *)nextManeuver
NS_SWIFT_NAME(navigationManager(_:didUpdateManeuvers:_:));

/**
 * Called when a route stopover has been reached.
 *
 * @note Note that, in addition to this,
 * NMANavigationManagerDelegate::navigationManager:hasCurrentManeuver:nextManeuver
 * will also be called. Furthermore, note that an NMAWaypoint of type
 * NMAViaWaypoint is not considered to be a route stopover.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param stopover The stopover reached.
 *
 */
- (void)navigationManager:(nonnull NMANavigationManager*)navigationManager
         didReachStopover:(nonnull NMAWaypoint *)stopover;

/**
 * Called when a change is made to the route being navigated.
 *
 * This can occur as a result of calling [NMANavigationManager setRoute:], after succesfully
 * rerouting due to the user leaving the current route (see
 * navigationManager:navigationManagerWillReroute), or when navigation manager is stopped.
 *
 * Note that when a new route is received due to rerouting the violated options of the
 * routeResult may addtionally contain NMARoutingViolatedOptionStartDirection if the new route
 * does not follow the current direction of travel.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param routeResult NMARouteResult representing the route that was set.
 */
- (void)navigationManager:(nonnull NMANavigationManager*)navigationManager
 didUpdateRouteWithResult:(nonnull NMARouteResult *)routeResult
NS_SWIFT_NAME(navigationManager(_:didUpdateRoute:));

/**
 * Used to retrieve information about the lane configuration while navigating. The callback occurs
 * when the user has arrived at a point in the route where lane information should be presented
 * (e.g. before a highway exit) and provides upcoming lane configuration.
 *
 * Called when new information about lanes is available. This method is called whenever
 * the current available lane information changes. No available lane information is indicated
 * by a count of zero for the laneInformationList (e.g. lane information should stop being displayed).
 *
 * The lanes are ordered from left (index = 0) to right (index = laneInformationList.count - 1).
 *
 * No callback if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @note Information about lanes requires extra map data for a route. The application must first
 * download the required map data using `NMAMapDataPrefetcher` or `NMAMapLoader`.
 * Otherwise, lane information will not be returned properly.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param laneInformations An array of `NMALaneInformation` objects. An empty array indicates that
 * no lane information is available and lane information should stop being shown. The lanes are ordered
 * from left (index = 0) to right (index= laneInformationList.count - 1).
 * @param roadElement The NMARoadElement that the NMALaneInformation is associated with. nil if not
 * available or if laneInformationList is empty.
 */
- (void)navigationManager:(nonnull NMANavigationManager*)navigationManager
 didUpdateLaneInformation:(nonnull NSArray<NMALaneInformation *> *)laneInformations
              roadElement:(nullable NMARoadElement *)roadElement;

/**
 * Called when realistic views for the current (upcoming) maneuver are available.
 *
 * Here is an example of how to get signpost/junction view with aspect ratio 16x9:
 *
 * \code
 * NSDictionary* realisticView = [realisticViews objectForKey:NMARealisticView16x9Key];
 * NMAImage* signpost = [realisticView objectForKey:NMANavigationManagerSignpostKey];
 * NMAImage* junctionView = [realisticView objectForKey:NMANavigationManagerJunctionViewKey];
 * \endcode
 *
 * This callback will not be made if access to this operation is denied. Contact your HERE representative for
 * more information.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param realisticViews A dictionary of realistic view objects containing a junction view and/or a 2D signpost for the
 *        current (upcoming) maneuver using aspect ratio as the key.
 *
 * @note The "current" maneuver is the upcoming, or next, maneuver to be taken. The "next" maneuver is
 * actually the maneuver to be taken after the current maneuver.
 */
- (void)                    navigationManager:(nonnull NMANavigationManager*)navigationManager
    didUpdateRealisticViewsForCurrentManeuver:(nonnull NSDictionary<NSNumber *, NSDictionary<NSString *, NMAImage *> *> *)realisticViews;

/**
 * Called when realistic views for the next maneuver AFTER THE CURRENT MANEUVER are available.
 *
 * Here is an example of how to get signpost/junction view with aspect ratio 16x9:
 *
 * \code
 * NSDictionary* realisticView = [realisticViews objectForKey:NMARealisticView16x9Key];
 * NMAImage* signpost = [realisticView objectForKey:NMANavigationManagerSignpostKey];
 * NMAImage* junctionView = [realisticView objectForKey:NMANavigationManagerJunctionViewKey];
 * \endcode
 *
 * This may be used as an advance notification. Assuming there are maneuvers A and B and there is a realistic view
 * for maneuver B. When A is the current (upcoming) maneuver, a realistic view for maneuver B will be provided in this
 * navigationManager:didUpdateRealisticViewsForNextManeuver callback. When maneuver B becomes the current (upcoming)
 * maneuver, the realistic view for maneuver B will be provided again in the
 * navigationManager:didUpdateRealisticViewsForCurrentManeuver callback.
 *
 * This callback will not be made if access to this operation is denied. Contact your HERE representative for
 * more information.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param realisticViews A dictionary of realistic view objects containing a junction view and/or a 2D signpost for the
 *        next maneuver AFTER THE CURRENT MANEUVER using aspect ratio as the key.
 *
 * @note The "current" maneuver is the upcoming, or next, maneuver to be taken. The "next" maneuver is
 * actually the maneuver to be taken after the current maneuver.
 */
- (void)                 navigationManager:(nonnull NMANavigationManager*)navigationManager
    didUpdateRealisticViewsForNextManeuver:(nonnull NSDictionary<NSNumber *, NSDictionary<NSString *, NMAImage *> *> *)realisticViews;

/**
 * Called when all realistic views supplied before this callback are invalidated.
 *
 * If 2 maneuvers are close to each other and both has realistic views, it is not guaranteed that a
 * navigationManagerDidInvalidateRealisticViews callback will be issued between maneuvers. When this
 * callback is received, it is important that application discards all realistic views received.
 *
 * No callback if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @note In general, a realistic view for the next maneuver is received before a realistic
 * view for the current (upcoming) maneuver. Take maneuvers A, B, and C. When A is the current (upcoming) maneuver,
 * a realistic view for the next maneuver B is supplied. As the user moves ahead, B becomes the current (upcoming)
 * maneuver. As the user is close to maneuver B, a realistic view for the current (upcoming) maneuver B is supplied again.
 * As the user moves onto maneuver C, navigationManagerDidInvalidateRealisticViews is received so that application can
 * remove all realistic views supplied this far.
 *
 * @param navigationManager The NMANavigationManager singleton.
 *
 * @note The "current" maneuver is the upcoming, or next, maneuver to be taken. The "next" maneuver is
 * actually the maneuver to be taken after the current maneuver.
 */
- (void)navigationManagerDidInvalidateRealisticViews:(nonnull NMANavigationManager*)navigationManager;

/**
 * Called when a speed limit warning is issued.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param isSpeeding A boolean value indicating the current speeding status; YES if the user is speeding.
 * @param speed The current speed of the user in meters/second.
 * @param speedLimit The speed limit in meters/second or 0 if the information is not
 *        available.
 */
- (void)  navigationManager:(nonnull NMANavigationManager*)navigationManager
    didUpdateSpeedingStatus:(BOOL)isSpeeding
            forCurrentSpeed:(float)speed
                 speedLimit:(float)speedLimit;

/**
 * Called when the navigation manager loses its position.
 *
 * When the raw position (e.g. GPS) is lost, navigation may continue for a time
 * if the current position can be successfully estimated. This may occur for example
 * when traveling through a tunnel. This callback will not be sent until the position
 * can no longer be estimated. Thus, it may occur some time after the didLosePosition
 * notification from NMAPositioningManager.
 *
 * @param navigationManager The NMANavigationManager singleton.
 */
- (void)navigationManagerDidLosePosition:(nonnull NMANavigationManager*)navigationManager;

/**
 * Called when the navigation manager finds its position.
 *
 * @param navigationManager The NMANavigationManager singleton.
 */
- (void)navigationManagerDidFindPosition:(nonnull NMANavigationManager*)navigationManager;

/**
 * Called when rerouting is triggered due to the user leaving the current route
 *
 * If a new route is successfully calculated it is immediately applied to the current
 * navigation session and navigationManager:didUpdateRouteWithResult: is called. If
 * rerouting fails navigationManager:didUpdateRouteWithResult: is not called.
 *
 * @param navigationManager The NMANavigationManager singleton.
 */
- (void)navigationManagerWillReroute:(nonnull NMANavigationManager*)navigationManager;

/**
 * Called when rerouting, due to the user leaving the current route, has finished.
 *
 * This method just means an attempt to reroute finished and does not guarantee that
 * a new route was successfully created.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param error A routing calculation error (can be `NMARoutingErrorNone`)
 */
- (void)navigationManager:(nonnull NMANavigationManager*)navigationManager
      didRerouteWithError:(NMARoutingError)error
NS_SWIFT_NAME(navigationManager(_:didRerouteWithError:));

/**
 * Called when the navigation manager has found an improved route.
 *
 * When the navigation manager traffic avoidance mode is manual, the navigation
 * manager will search for faster routes, but will not automatically switch to
 * them.
 *
 * When a new route is found, it is up to the navigation manager delegate to
 * determine whether or not to use it. To use the new route, call
 * NMANavigationManager::setRoute: with the new route.
 *
 * The new route may be set after returning from this callback, but it is not
 * recommended to wait more than a few seconds before switching the route since
 * a delay might cause the user to receive an invalid instruction from the old
 * route or miss the first instruction from the new route.
 *
 * @note This callback is only sent when NMATrafficAvoidanceManual is in use.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param routeResult The newly calculated NMARouteResult.
 */
       - (void)navigationManager:(nonnull NMANavigationManager*)navigationManager
 didFindAlternateRouteWithResult:(nonnull NMARouteResult *)routeResult
NS_SWIFT_NAME(navigationManager(_:didFindAlternateRoute:));

/**
 * Called when the traffic avoidance routing state changes.
 *
 * @note This callback is only sent when traffic avoidance is enabled or was just
 * disabled.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param state An enum NMATrafficEnabledRoutingState representing the current
 *              traffic enabled routing state.
 *
 * See also `NMANavigationManager::setTrafficAvoidanceMode:`
 *
 * See also `NMATrafficEnabledRoutingState`
 */
- (void)navigationManager:(nonnull NMANavigationManager*)navigationManager
    didChangeRoutingState:(NMATrafficEnabledRoutingState)state
NS_SWIFT_NAME(navigationManager(_:didChangeRoutingState:));

/**
 * Called when the navigation manager has audio feedback to play.
 *
 * If the delegate returns NO, the pending feedback will not be played. If the delegate
 * returns YES or this method is not implemented, the feedback will be played. This
 * method will be called once for each voice instruction or other non-voice audio feedback
 * (e.g. speed warning beeps).
 *
 * This method can be used to play voice commands using a custom TTS (text to speech)
 * engine. To accomplish this you should write a new NMAAudioOutput class that plays text using
 * the custom engine. When this method is called create an instance of your custom
 * NMAAudioOutput, pass it to [NMAAudioManager playOutput:] and then return NO. This will ensure
 * your custom TTS output is correctly synced with non-voice audio feedback.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param text The text to be spoken. This will be nil for non-voice audio feedback or if the
 * NMAVoicePackage in use does not support generating text strings from voice commands.
 * @return YES to have the voice feedback played by NMANavigationManager. NO to prevent
 * NMANavigationManager playing the voice feedback.
 */
- (BOOL)          navigationManager:(nonnull NMANavigationManager*)navigationManager
    shouldPlayVoiceFeedbackWithText:(nullable NSString *)text
NS_SWIFT_NAME(navigationManager(_:shouldPlayVoiceFeedback:));
/**
 * Called when navigation manager will play audio feedback.
 *
 * @param text The text to be spoken. This will be nil for non-voice audio feedback or if the
 * NMAVoicePackage in use does not support generating text strings from voice commands.
 * @param navigationManager The NMANavigationManager singleton.
 */
- (void)        navigationManager:(nonnull NMANavigationManager*)navigationManager
    willPlayVoiceFeedbackWithText:(nullable NSString *)text
NS_SWIFT_NAME(navigationManager(_:willPlayVoiceFeedback:));

/**
 * Called when navigation manager has finished playing audio feedback.
 *
 * @param text The text that was spoken. This will be nil for non-voice audio feedback or if the
 * NMAVoicePackage in use does not support generating text strings from voice commands.
 * @param navigationManager The NMANavigationManager singleton.
 */
- (void)       navigationManager:(nonnull NMANavigationManager*)navigationManager
    didPlayVoiceFeedbackWithText:(nullable NSString *)text
NS_SWIFT_NAME(navigationManager(_:didPlayVoiceFeedback:));

/**
 * Called when navigation manager suspends due to insufficient map data.
 *
 * In order to operate NMANavigationManager relies on a constant stream of map matched positions from
 * NMAPositioningManager. One reason that map matching can fail is if map data for the current location
 * is not available. If this situation arises then this callback will be made.
 *
 * If NMAMapView has never been used to view a particular location since your app was installed (note
 * that map data is cached across app launches), NMAMapLoader has not been used to download an
 * NMAMapPackage for this location, no network connection is available and navigation progresses to
 * this location then the scenario described above will occur.
 *
 * To guarantee that navigation never encounters problems in poor network conditions use NMAMapLoader
 * to download map data for the region being navigated.
 *
 * Once map data is available again, navigationManagerDidResumeDueToMapDataAvailability will be called.
 *
 * @param navigationManager The NMANavigationManager singleton.
 */
- (void) navigationManagerDidSuspendDueToInsufficientMapData:(nonnull NMANavigationManager*)navigationManager
NS_SWIFT_NAME(navigationManagerDidSuspendDueToInsufficientMapData(_:));

/**
 * Called when navigation manager resumes after previously suspending due to a lack of map data.
 *
 * This may be used as a notification that the map data for guidance is available again after previously
 * being unavailable for the current location.
 *
 * This callback is only made if navigationManagerDidSuspendDueToInsuffucientMapData was previously
 * called.
 *
 * This callback will not be made if guidance is stopped before map data becomes available again.
 *
 * @param navigationManager The NMANavigationManager singleton.
 */
- (void) navigationManagerDidResumeDueToMapDataAvailability:(nonnull NMANavigationManager*)navigationManager
NS_SWIFT_NAME(navigationManagerDidResumeDueToMapDataAvailability(_:));

/**
 * Called when the navigation manager has found alternative routes for current one
 * during navigation with traffic avoidance mode enabled.
 *
 * When new routes are found, it is up to the navigation manager delegate to
 * determine whether or not to use it. To use any from new routes, call
 * NMANavigationManager::setRoute: with a new route.
 *
 * A new route from found routes may be set after returning from this callback,
 * but it is not recommended to wait more than a few seconds before switching
 * the route since a delay might cause the user to receive an invalid instruction
 * from the old route or miss the first instruction from the new route.
 *
 * @note This callback is only sent when traffic avoidance mode is not
 * NMATrafficAvoidanceDisabled. Every next callback invocation means that previously
 * returned alternative routes have been passed or recalculated. If callback returns
 * RouteResults with empty routes it means that all previous routes are stale
 * and there is no new alternative routes anymore for now. Alternative routes strategy
 * is not supported for multiple waypoints routes.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param routeResult The newly calculated NMARouteResult.
 */
- (void) navigationManager:(nonnull NMANavigationManager*)navigationManager
    didFindAlternateRoutes:(nonnull NMARouteResult *)routeResult
NS_SWIFT_NAME(navigationManager(_:didFindAlternateRoutes:));

/**
* Called when crossing a border between countries.
*
* @param navigationManager The NMANavigationManager singleton.
* @param previousCountry The 3-letter country code you are leaving.
* @param nextCountry The 3-letter country code you are entering.
*/

- (void) navigationManager:(nonnull NMANavigationManager*)navigationManager
          didUpdateCountry:(nonnull NSString *)previousCountry
               nextCountry:(nonnull NSString *)nextCountry
NS_SWIFT_NAME(navigationManager(_:didUpdateCountry:_:));

@end


/**
 * `NMANavigationManager` is a navigation manager class that provides guidance
 * advice and information along a route.
 *
 * Application developers using this API
 * are required to thoroughly test their applications in all expected usage scenarios to ensure safe
 * and correct behaviour. Application developers are responsible for warning their users of the
 * following obligations:
 *
 * 1. Do not follow instructions which may lead to an unsafe or illegal situation.
 *
 * 2. Obey all local laws.
 *
 * 3. Be aware that using a mobile phone or some of its features while driving may be prohibited.
 *
 * 4. Always keep hands free to operate the vehicle while driving.
 *
 * 5. First consideration while driving should be road safety.
 *
 * @note NMANavigationManager requires valid authentication credentials to be set via
 * NMAApplicationContext. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.
 */
@interface NMANavigationManager : NSObject

/**
 * Returns the NMANavigationManager singleton instance.
 *
 * @note Use this method to obtain a NMANavigationManager instance.
 *
 * @return shared NMANavigationManager instance
 */
+ (nonnull NMANavigationManager *)sharedNavigationManager
NS_SWIFT_NAME(sharedInstance());

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Receives event callbacks containing information about the current
 * navigation session.
 *
 * See also `NMANavigationManagerDelegate`
 */
@property (nonatomic, weak, nullable) id<NMANavigationManagerDelegate> delegate;

/**
 * Returns the current state of the navigation related to the tracked route.
 *
 * @note When this property changes, NMANavigationManager sends a notification with
 * the name given by NMANavigationManagerStateChangedNotification.
 */
@property (nonatomic, readonly) NMANavigationState navigationState;

/**
 * Returns the current mode of the navigation manager.
 */
@property (nonatomic, readonly) NMANavigationMode navigationMode;

#pragma mark - Map Tracking

/**
 * The NMAMapView used for the current navigation.
 *
 * If a map view is specified when navigation is started, that map view will be used
 * to display maneuver arrows (for turn-by-turn navigation) and to track the current
 * position (if mapTrackingEnabled is set to YES).
 *
 * @note Will be nil if no map was specified for the current navigation session.
 *
 * @note Changes made to this property while navigation is active will not be reflected
 * until the next navigation session is started.
 */
@property (nonatomic, weak, nullable) NMAMapView * map;

/**
 * Allows the NMANavigationManager to automatically update map position as
 * navigation progresses.
 *
 * @note The default value is YES.
 */
@property (nonatomic) BOOL mapTrackingEnabled;

/**
 * Determines how the map is oriented during navigation map tracking.
 *
 * @note The default value is NMAMapTrackingOrientationDynamic.
 *
 * See also `NMAMapTrackingOrientation`
 */
@property (nonatomic) NMAMapTrackingOrientation mapTrackingOrientation;

/**
 * Controls whether the map zoom level is adjusted during navigation map tracking.
 *
 * If map tracking autozoom is enabled, the zoom level of the map will be adjusted based
 * on the user's current movement speed. For example, the map will zoom out to show more
 * area when the user moves faster, and zoom in again when the user slows down. If autozoom
 * is disabled, the zoom level will be left at whatever it was when navigation began (and
 * it can be manually modified during navigation).
 *
 * @note The default value is YES.
 */
@property (nonatomic) BOOL mapTrackingAutoZoomEnabled;

/**
 * Controls how the map is tilted when map tracking is enabled.
 *
 * In 2D and 3D modes, the map will automatically be tilted back appropriately when
 * the tilt value is changed. In Custom mode, the tilt will not be changed. Use custom
 * mode to allow the map to be manually tilted during navigation or to set the tilt to
 * a fixed custom value.
 *
 * @note The default value is NMAMapTrackingTilt3D.
 */
@property (nonatomic) NMAMapTrackingTilt mapTrackingTilt;

/**
 * The maximum map tracking refresh rate (FPS) used by software rendering when the application
 * is backgrounded.
 *
 * If the backgroundNavigationEnabled and mapTrackingEnabled properties are enabled then
 * map tracking runs in the background, using software rendering, to ensure that map data is
 * downloaded and that navigation does not suspend due to a lack of map data. See
 * navigationManagerDidSuspendDueToInsufficientMapData:
 *
 * This property is provided to balance CPU usage and FPS whilst the app is backgrounded and
 * software rendered bitmaps are being produced (see [NMAMapView softwareRenderToBitmap]).
 * iOS will kill an app if it's CPU usage is above a certain threshold whilst backgrounded. At
 * the time of writing if an App uses an average of 80% CPU over 60 seconds it will be killed.
 * You should tune this property by testing on devices with the lowest hardware specification
 * that you intend to support. The size of the map view also greatly affects CPU usage and the
 * achievable FPS.
 *
 * The following metrics were collected from an iPhone5s running navigation in the background
 * with traffic for the route being refreshed every 60 seconds. The map size is in points:
 *
 *   - Map size 300x300 and max refresh rate of 8 FPS renders at 6.9 FPS with 27% average CPU.
 *   - Map size 300x300 and max refresh rate of 11 FPS renders at 9.3 FPS with 35% average CPU.
 *   - Map size 300x300 and max refresh rate of 16 FPS renders at 12.4 FPS with 44% average CPU.
 *
 *   - Map size 260x400 and max refresh rate of 11 FPS renders at 9.2 FPS with 39% average CPU.
 *
 *   - Map size 300x400 and max refresh rate of 10 FPS renders at 8.2 FPS with 38% average CPU.
 *   - Map size 300x400 and max refresh rate of 20 FPS renders at 10.8 FPS with 47% average CPU.
 *
 *   - Map size full screen and max refresh rate of 20 FPS renders at 8 FPS with 47% average CPU.
 *
 * The amount of detail rendered on the map affects CPU usage so disable all features that are
 * not required. Also consider that in urban areas there is generally more detail on the map
 * and this is something that you cannot necessarily control so err on the side of a lower maximum
 * refresh rate to avoid unexpectedly high CPU usage.
 *
 * Defaults to 1 FPS. Note that this property has no effect when the application is running in
 * the foreground. In the foreground navigation uses a maximum refresh rate of 20 FPS.
 *
 * The frequency should be set to a factor of 60. Other values will be accepted but may
 * provide a less optimal user experience in terms of the smoothness of map scrolling and
 * animation. Values less than 1 will be clamped to 1.
 *
 * IMPORTANT: Software Rendering is a Beta feature, and associated methods and behaviours
 * are subject to change without notice.
 *
 * @note It is not recommended to change this property unless you are grabbing software rendered
 * bitmaps of the map view whilst running in the background. See the softwareRenderToBitmap
 * property of NMAMapView.
 */
@property (nonatomic) float backgroundMapTrackingMaximumRefreshRate;

#pragma mark -

/**
 * Returns the current (upcoming) maneuver on the route, or nil, if this information
 * is not available because the information is not ready yet, or there are no more maneuvers on the
 * route.
 *
 * @note The currentManeuver property represents the upcoming, or next, maneuver to be taken. The
 * nextManeuver property is actually the maneuver to be taken after the current maneuver.
 */
@property (nonatomic, readonly, nullable) NMAManeuver * currentManeuver;

/**
 * Returns the next maneuver on the route AFTER THE CURRENT MANEUVER , or nil if there is none.
 *
 * @note The currentManeuver property represents the upcoming, or next, maneuver to be taken. The
 * nextManeuver property is actually the maneuver to be taken after the current maneuver.
 */
@property (nonatomic, readonly, nullable) NMAManeuver * nextManeuver;

/**
 * Returns the distance from current position to the current (upcoming) maneuver in meters,
 * or NMANavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) NMAUint64 distanceToCurrentManeuver;

/**
 * Returns the distance from current position to the next maneuver AFTER THE CURRENT MANEUVER
 * in meters, or NMANavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) NMAUint64 distanceToNextManeuver;

/**
 * Returns the distance from current position to the end of route in meters,
 * or NMANavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) NMAUint64 distanceToDestination;

/**
 * Returns the distance from route start to the current position in meters,
 * or NMANavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) NMAUint64 distanceFromStart;

/**
 * Returns the average speed of distance travelled in meters/sec or 0 if it
 * cannot be calculated.
 */
@property (nonatomic, readonly) double averageSpeed;

/**
 * Returns the number of seconds that remain to travel to the destination,
 * or -DBL_MAX (see float.h) on error.
 *
 * @note The time interval returned will not include any delays due to traffic
 */
@property (nonatomic, readonly) NSTimeInterval timeToArrival;

/**
 * Returns the Time To Arrival (TTA) in seconds or -DBL_MAX (see float.h) on error.
 *
 * This method returns -DBL_MAX if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @note IMPORTANT: To ensure the time interval returned considers all traffic remaining on the
 * route see the prerequisites described in `-[NMARoute ttaUsingDownloadedTrafficForSubleg]`
 *
 * @param mode NMATrafficPenaltyMode used for calculation.
 * @param wholeRoute YES to return the TTA for the whole route, NO to return the TTA
 * for the next stopover waypoint.
 */
- (NSTimeInterval)timeToArrivalWithTraffic:(NMATrafficPenaltyMode)mode wholeRoute:(BOOL)wholeRoute;

/**
 * Returns the Time To Arrival (TTA) in seconds or -DBL_MAX (see float.h) on error.
 *
 * This method returns -DBL_MAX if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @note IMPORTANT: To ensure the time interval returned considers all traffic remaining on the
 * route see the prerequisites described in `-[NMARoute ttaUsingDownloadedTrafficForSubleg]`
 *
 * @param subleg The subleg number to use or `NMARouteSublegWhole` for the whole route.
 * @param mode NMATrafficPenaltyMode used for calculation.
 */
- (NSTimeInterval)timeToArrivalForSubleg:(NSUInteger)subleg mode:(NMATrafficPenaltyMode)mode
NS_SWIFT_NAME(timeToArrival(forSubleg:mode:));

/**
 * When set to YES, the current navigation will be paused (if any). When set
 * to NO, the current navigation will resume if previously paused. This has no
 * effect if there is no navigation currently in progress.
 */
@property (nonatomic, getter = isPaused) BOOL paused;

/**
 * Controls whether speed warnings are enabled.
 *
 * If set, navigationManager:didUpdateSpeedingStatus:forCurrentSpeed:speedLimit:
 * will be sent to the delegate when speeding is detected or when a correction is made.
 */
@property (nonatomic, getter = isSpeedWarningEnabled) BOOL speedWarningEnabled;

/**
 * The current low speed offset in meters/second.
 *
 * See also `setLowSpeedOffset:highSpeedOffset:speedBoundary:`
 */
@property (nonatomic, readonly) float lowSpeedOffset;

/**
 * The current high speed offset in meters/second.
 *
 * See also `setLowSpeedOffset:highSpeedOffset:speedBoundary:`
 */
@property (nonatomic, readonly) float highSpeedOffset;

/**
 * The current speed boundary in meters/second.
 *
 * See also `setLowSpeedOffset:highSpeedOffset:speedBoundary:`
 */
@property (nonatomic, readonly) float speedBoundary;

/**
 * Controls whether navigation is paused when the application is sent to the background.
 *
 * Defaults to NO (Background navigation is disabled).
 *
 * When background navigation is enabled navigation will continue to run in the background until
 * completed. If you would like navigation to stop automatically after the device remains stationary
 * in the background for a period of time (15 to 20 minutes) you may need to configure the data source
 * directly. For example, in the case of NMADevicePositionSource:
 *
 * \code
 *      NMADevicePositionSource* posSource = (NMADevicePositionSource*)[NMAPositioningManager sharedPositioningManager].dataSource;
 *      if([posSource isKindOfClass:[NMADevicePositionSource class]]){
 *          posSource.locationManager.pausesLocationUpdatesAutomatically = YES;
 *      }
 * \endcode
 *
 * Note that if navigation is automatically stopped in the background due to the configuration shown
 * above then it will not restart automatically.
 *
 * This property must be set whilst the app is in the foreground and has at least a CLAuthorizationStatus
 * of kCLAuthorizationStatusAuthorizedWhenInUse. Changing the property whilst the app is in the background
 * will have undefined behaviour and may not reliably enable the background position updates required by
 * navigation.
 *
 * @note The current NMAPositioningManager dataSource must support background position updates in order
 * to navigate in the background. All position data sources supplied with the Here SDK support background
 * position updates. If the current position data source does not support background position updates
 * then background navigation will not work even though this property may be set to YES.
 *
 * See also `NMAPositionDataSource::setBackgroundUpdatesEnabled:`
 */
@property (nonatomic) BOOL backgroundNavigationEnabled;

/**
 * Controls whether navigation may be started when the app is in the background.
 *
 * Defaults to NO (Navigation can not be started in the background and calls to
 * startTurnByTurnNavigationWithRoute: or startTrackingWithTransportMode: will return an error of
 * NMANavigationErrorInvalidOperation).
 *
 * This property must be set whilst the app is in the foreground and has at least a CLAuthorizationStatus
 * of kCLAuthorizationStatusAuthorizedWhenInUse. Changing the property whilst the app is in the background
 * will have undefined behaviour and may not reliably enable the background position updates required by
 * navigation.
 *
 * IMPORTANT: Even with this property set to YES if your app enters the background and then enters the
 * suspended state you may not be able to reliably start navigation in the background if the app resumes
 * background execution without returning to the foreground first (e.g. background execution resumes to
 * "silently" handle a push notification or a file download completing). To guarantee navigation can be
 * started after background suspension you must explicitly start positioning via a call to
 * [NMAPositioningManager startPositioning] in the foreground. This will mean your app will be constantly
 * waking to handle position updates in the background which will have a side effect of consuming more power.
 *
 * ONLY THE COMBINATION OF EXPLICITLY STARTING NMAPositioningManager, SETTING backgroundNavigationEnabled TO
 * YES AND SETTING backgroundNavigationStartEnabled TO YES IN THE FOREGROUND WILL ALLOW NAVIGATION TO BE
 * RELIABLY STARTED, AND RESTARTED AFTER STOPPING, IN THE BACKGROUND.
 *
 * @note The current NMAPositioningManager dataSource must support background position updates in order
 * to navigate in the background. All position data sources supplied with the Here SDK support background
 * position updates. If the current position data source does not support background position updates
 * then background navigation will not work even though this property may be set to YES.
 *
 * See also `backgroundNavigationEnabled`
 */
@property (nonatomic) BOOL backgroundNavigationStartEnabled;

/**
 * Determines the type of realistic views (if any) that are provided during
 * navigation.
 *
 * If realistic views are enabled, when a realistic view for the current (upcoming) or next maneuver
 * becomes available or unavailable the following callbacks may be issued:
 * navigationManager:didUpdateRealisticViewsForNextManeuver
 * navigationManager:didUpdateRealisticViewsForCurrentManeuver
 * navigationManagerDidInvalidateRealisticViews
 *
 * The default value is NMARealisticViewOff. If realistic views are enabled, the
 * desired aspect ratios must also be set using the realisticViewAspectRatios
 * property.
 *
 * The realistic view mode may be changed during active navigation. If it is
 * disabled, a navigationManagerDidInvalidateRealisticViews callback will be sent
 * to inform the delegate to dismiss any realistic views that have previously
 * been displayed.
 *
 * Similarly, if the realistic view type is changed (e.g. from day to night), the
 * delegate will receive a callback to invalidate the old views followed by
 * callbacks with views of the new type.
 *
 * The realistic view mode cannot be changed if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @note This feature is only available for turn-by-turn drive navigation.
 *
 * See also `NMANavigationManager::realisticViewAspectRatios`
 */
@property (nonatomic) NMARealisticViewMode realisticViewMode;

/**
 * A bit mask defining the desired realistic view aspect ratios.
 *
 * The available aspect ratios are defined by the NMARealisticViewAspectRatio
 * enum. A value of 0 (the default) indicates that no realistic views will be
 * provided.
 *
 * The realistic view aspect ratios cannot be changed if access to this operation
 * is denied. Contact your HERE representative for more information.
 *
 * Changes made to this property during active navigation may not be reflected
 * until the next navigation session, so it is recommended to configure the
 * realistic views before starting navigation.
 *
 * @note Performance may be impacted if all supported aspect ratios are requested.
 */
@property (nonatomic) NMARealisticViewAspectRatio realisticViewAspectRatios;

/**
 * Starts a turn-by-turn navigation session using the specified route.
 *
 * Only one navigation session of any type is allowed at a time. Attempts to start
 * another navigation session when the current navigationState is not NMANavigationStateIdle
 * will fail.
 *
 * When navigation is started, the NMANavigationManager will automatically update some
 * positioning settings to provide the best experience. This includes the mapMatchMode of
 * NMAPositioningManager (inferred from the transportMode of the route) and the CLLocationManager
 * settings of the NMADevicePositionSource if applicable. Settings are restored to their previous
 * values when navigation is completed.
 *
 * Public transit navigation is not currently supported.
 *
 * Navigation requires use of the NMAPositioningManager service; it will be automatically started
 * if it is not already running.
 *
 * IMPORTANT: Navigation for route that was calculated for `NMATransportModeBike` is
 * a Beta feature, and is subject to change without notice.
 *
 * @param route The route to navigate.
 *
 * @return nil if started successfully, otherwise an NSError object with an error code
 * indicating the failure reason. A partial list of the most common reasons is:
 *     NMANavigationErrorInvalidOperation - if a navigation session is currently active, if the
 *         provided route includes public transit elements, or if the application is currently in
 *         the background and backgroundNavigationStartEnabled is set to NO.
 *     NMANavigationErrorInvalidParameters - if the route parameter is nil.
 *     NMANavigationErrorOperationNotAllowed - if the SDK does not allow this type of navigation,
 *          or if access to this operation is denied. Contact your HERE representative for more
 *          information.
 */
- (nullable NSError *)startTurnByTurnNavigationWithRoute:(nonnull NMARoute*)route
NS_SWIFT_NAME(startTurnByTurnNavigation(_:));

/**
 * Starts a position tracking navigation session.
 *
 * Tracking mode provides a similar experience to turn-by-turn navigation, but without
 * the guidance arrows and voice commands. The NMAMapView instance will be updated to
 * follow the user's position (if mapTrackingEnabled is YES) and speed warnings will be
 * sent to the navigation delegate.
 *
 * See startTurnByTurnNavigationWithRoute: for more information.
 *
 * @param transportMode The transportation mode to use for tracking. The mode used will
 * affect the settings of the NMAPositioningManager and NMADevicePositionSource when
 * navigation is started.
 *
 * @return nil if successful, otherwise an NSError object with error code indicating
 * the failure reason.
 */
- (nullable NSError *)startTrackingWithTransportMode:(NMATransportMode)transportMode
NS_SWIFT_NAME(startTracking(_:));

/**
 * stop the current navigation started via startTurnByTurnNavigationWithRoute or
 * startTracking.
 */
- (void)stop;

/**
 * Set the offset values for the speed warning feature.
 *
 * The speeding status of the user is determined by comparing the current speed
 * to the current speed limit with an offset. If the user's speed is greater than
 * the speed limit plus the offset, a speed warning is issued.
 *
 * To allow different offsets and low and high speeds, a speed boundary is used
 * to divide speed limits into two groups. The low speed offset is then used for
 * speed limits less than the speed boundary, and the high speed offset is used
 * for speed limits greater than the speed boundary.
 *
 * For example, suppose the low speed offset is 10km/h and the speed boundary is
 * 80km/h. If the speed limit of the current road is 50km/h, the user will be
 * considered speeding at any speed higher than 60km/h and a warning will be
 * issued.
 *
 * @param lowSpeedOffset Offset at low speeds in meters/second.
 * @param highSpeedOffset Offset at high speeds in meters/second.
 * @param speedBoundary Boundary between low and high speeds in meters/second. The
 * lowSpeedOffset is used below this boundary, and the highSpeedOffset is used above it.
 *
 * @return nil if successful, otherwise an NSError object containing error
 * information.
 *
 * See also `speedWarningEnabled`
 */
- (nullable NSError *)setLowSpeedOffset:(float)lowSpeedOffset
                        highSpeedOffset:(float)highSpeedOffset
                          speedBoundary:(float)speedBoundary;

#pragma mark - Voice Feedback
/**
 * The voice package used for navigation.
 *
 * The default package is English (US). Setting the voice package to nil
 * restores the default package.
 *
 * @note The voicePackageMeasurementSystem property will be set to NMAMeasurementSystemMetric
 * if the new voicePackage does not support the current voicePackageMeasurementSystem.
 *
 * See also `voicePackageMeasurementSystem`
 */
@property (nonatomic, null_resettable) NMAVoicePackage * voicePackage;

/**
 * The TTS text output format.
 *
 * Default format is raw (pure text without phonemes and escape sequences).
 * This property has effect only when TTS NMAVoicePackage is in use.
 *
 * See also `NMANavigationManagerDelegate::navigationManager:shouldPlayVoiceFeedbackWithText:`
 */
@property (nonatomic) NMATTSOutputFormat ttsOutputFormat;

/**
 * Determines whether to enable navigation voice. If set to NO,
 * navigation will be running without voice commands, (only speed warnings will be heard
 * during the navigation assuming that the speed warnings are enabled).
 *
 * @note navigation voice is enabled by default.
 * @note if you disabled the voice for the walk navigation you will not hear any beeps or vibrations
 * except when you reach your destination you will hear that once.
 */
@property (nonatomic, getter = isVoiceEnabled) BOOL voiceEnabled;

/**
 * Determines whether to enable device vibration for walk navigation. If set to NO,
 * navigation will be running without vibration.
 *
 * @note vibration is enabled by default.
 * @note voiceEnabled should be YES, in order to this property to take effect.
 */
@property (nonatomic, getter = isVibrationEnabled) BOOL vibrationEnabled;

/**
 * Determines whether to enable beeps for walk navigation. If set to NO,
 * navigation will be running without beeps.
 *
 * @note beeps is enabled by default.
 * @note voiceEnabled should be YES, in order to this property to take effect.
 */
@property (nonatomic, getter = isBeepsEnabled) BOOL beepsEnabled;

/**
 * Determines whether to enable speed warning audio feedback. If set to YES,
 * speed warnings will be heard during the navigation.
 *
 * @note speedWarningAudioFeedbackEnabled is enabled by default.
 *
 */
@property (nonatomic, getter = isSpeedWarningAudioFeedbackEnabled) BOOL speedWarningAudioFeedbackEnabled;

/**
 * The measure unit used for voice guidance.  See NMAMeasurementSystem for
 * possible values. Default is NMAMeasurementSystemMetric. This property will not be changed if
 * the new voicePackageMeasurementSystem is not supported by the currently selected voicePackage.
 *
 * @note Please note that changing this property does not affect all measurements APIs.
 * Only voice guidance will be affected.
 *
 * See also `voicePackage`
 */
@property (nonatomic) NMAMeasurementSystem voicePackageMeasurementSystem;

/**
 * Checks if voice prompts for certain maneuver is enabled.
 *
 * Voice prompts are enabled for all maneuvers by default.
 *
 * @param action Maneuver to be checked.
 *
 * @return True if voice prompts for this maneuver type is enabled or false otherwise.
 */
- (BOOL)isVoiceEnabledForManeuverAction:(NMAManeuverAction)action
NS_SWIFT_NAME(isVoiceEnabled(forManeuverAction:));

/**
 * Enables/disables voice prompts for certain maneuver.
 *
 * @param action Maneuver voice prompt to be enabled/disabled.
 * @param enabled State for maneuver voice prompt.
 *
 * @note voiceEnabled should be YES, in order to this property to take effect.
 * @return true if operation was successful or false otherwise.
 */
- (BOOL)setVoiceEnabled:(BOOL)enabled forManeuverAction:(NMAManeuverAction)action
NS_SWIFT_NAME(setVoiceEnabled(_:forManeuverAction:));

/**
 * Enables/disables voice prompt for all maneuver actions. See `NMAManeuverAction`.
 *
 * @param enabled State for all maneuvers voice prompts.
 *
 * @note all maneuver actions are enabled by default.
 *
 * @return true if operation was successful or false otherwise.
 */
- (BOOL)setVoiceEnabledForAllManeuverActions:(BOOL)enabled;

/**
 * Plays the most current (i.e. last) voice command if possible.
 *
 * @note This method will immediately stop any current audio and clear the NMAAudioManager queue
 * before repeating the last voice command.
 */
- (void)playVoiceCommand;

/**
 * Immediately stops any current audio and clears the NMAAudioManager queue.
 */
- (void)cancelVoiceFeedback;
#pragma mark -

/**
 * Sets the natural guidance mode for use with turn-by-turn navigation.
 *
 * Natural guidance augments the standard turn-by-turn instructions by providing guidance in a simpler,
 * more intuitive way.
 *
 * For example, if the NMANaturalGuidanceTrafficLight option is enabled the user will hear instructions
 * similar to "turn right at the next traffic light".
 *
 * @note Natural guidance is disabled by default.
 *
 * @param mode An OR combination of one or more NMANaturalGuidanceOption values. Pass NMANaturalGuidanceOptionNone
 *             to disable natural guidance.
 *
 * @return NMANavigationErrorNone if the natural guidance mode was set successfully,
 *         NMANavigationErrorInvalidOperation if the mode could not be set.
 *
 * See also `NMANaturalGuidanceOption`
 */
- (NMANavigationError)setNaturalGuidanceMode:(NMANaturalGuidanceOption)mode;

/**
 * The current natural guidance mode used for turn-by-turn navigation.
 *
 * @return An OR combination of NMANaturalGuidanceOption values which comprise the mode.
 */
@property (nonatomic, readonly) NMANaturalGuidanceOption naturalGuidanceMode;

/**
 * Sets the navigation traffic avoidance behaviour.
 *
 * If the traffic avoidance mode is dynamic, the navigation manager will
 * automatically update the guidance route to avoid traffic events.
 *
 * If the traffic avoidance mode is manual, the navigation manager delegate will
 * be prompted when a faster route is found and have the option to accept or
 * reject it.
 *
 * Traffic avoidance is disabled by default.
 *
 * The traffic avoidance mode cannot be set if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @note: In order to use traffic avoidance mode your device must be online and the traffic data must be
 * downloaded using [NMATrafficManager requestTrafficOnRoute:] or by enabling traffic visualization on
 * NMAMapView using the trafficVisible property.
 *
 * @param mode The desired NMATrafficAvoidanceMode.
 *
 * @return NMANavigationErrorNone if the traffic avoidance mode was set successfully, otherwise one of
 *         the other error codes in NMANavigationError.
 *
 * See also `NMATrafficAvoidanceMode.`
 */
- (NMANavigationError)setTrafficAvoidanceMode:(NMATrafficAvoidanceMode)mode;

/**
 * The current traffic avoidance mode.
 *
 * See also `NMANavigationManager::setTrafficAvoidanceMode:`
 */
@property (nonatomic, readonly) NMATrafficAvoidanceMode trafficAvoidanceMode;

/**
 * Sets the navigation route request interval.
 *
 * The route request interval controls how frequently the navigation manager
 * will search for a better route to avoid traffic.
 *
 * The default value is 300 seconds (5 minutes).
 *
 * @note This value is only applicable when traffic avoidance is enabled.
 *
 * @param interval The route request interval in seconds.
 *
 * @return NMANavigationErrorNone if operation was successful, otherwise one of
 *         the other error codes in NMANavigationError.
 */
- (NMANavigationError)setRouteRequestInterval:(NSUInteger)interval;

/**
 * The time that the navigation manager waits between subsequent checks for a
 * faster route.
 *
 * The route request interval may be set using NMANavigationManager::setRouteRequestInterval.
 *
 * @note This property is only applicable when traffic avoidance is enabled.
 *
 * See also `NMANavigationManager::trafficAvoidanceMode`
 */
@property (nonatomic, readonly) NSUInteger routeRequestInterval;

/**
 * Sets the route used for turn-by-turn navigation.
 *
 * Typically, the navigation route should be set once when guidance begins using
 * the startTurnByTurnNavigationWithRoute: method and not changed while guidance
 * is ongoing. However, in some cases a new or better route may be made available
 * during guidance, for example when using the traffic avoidance feature in manual
 * mode. In these cases, this method may be using to update the route during
 * active guidance.
 *
 * @param route The new route navigation manager should use
 *
 * @return NMANavigationErrorNone if operation was successful, otherwise one of
 *         the other error codes in NMANavigationError.
 *         Returns NMANavigationErrorInvalidOperation if turn-by-turn guidance
 *         is not currently active.
 *         Returns NMANavigationErrorInvalidParameters if route is nil or not a
 *         car route.
 */
- (NMANavigationError)setRoute:(nonnull NMARoute*)route;

/**
 * NMATrafficWarner instance providing realtime notifications of traffic flows and
 * events during an active navigation session (NMANavigationStateRunning).
 *
 * This method returns a nil object if access to this operation is denied. Contact
 * your HERE representative for more information.
 */
@property (nonatomic, readonly, nullable) NMATrafficWarner *trafficWarner;

/**
 * NMASafetySpotWarner instance providing realtime notifications of safety spots
 * during an active navigation session (NMANavigationStateRunning).
 *
 * An example of a safety spot is a speed camera or a red light camera.
 *
 * Notifications are only generated when NMANavigationManager is navigating a route
 * (navigationMode NMANavigationModeTurnByTurn) using an appropriate transport mode
 * (e.g. neither `NMATransportModePedestrian` nor `NMATransportModeBike`).
 *
 * This method returns a nil object if access to this operation is denied. Contact
 * your HERE representative for more information.
 */
@property (nonatomic, readonly, nullable) NMASafetySpotWarner *safetySpotWarner;

/**
 * NMATruckRestrictionWarner instance providing realtime notifications of truck restrictions
 * during an active navigation session (NMANavigationStateRunning).
 *
 * Notification can be generated in two cases:
 *
 * 1) For routes that were calculated with `NMATruckRestrictionsModePenalizeViolations` option.
 * Following routes can contain violated truck restrictions. In this case, a notification will warn
 * that restrictions are on the current route ahead and
 * property `NMATruckRestrictionNotification.isOnRoute` for the notification will return `YES`.

 * 2) During rerouting, if the road in front contains violated truck restrictions.
 * In this case, a notification will warn that rerouting is initialized by restrictions ahead and
 * the property `NMATruckRestrictionNotification.isOnRoute` for the notification will return `NO`.
 *
 * This property returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 */
@property (nonatomic, readonly, nullable) NMATruckRestrictionWarner *truckRestrictionWarner;

/**
 * NMASchoolZoneWarner instance provides realtime notifications about school zones ahead
 * during an active navigation session `NMANavigationStateRunning`.
 *
 * Notifications are generated when NMANavigationManager performs turn-by-turn navigating
 * (`NMANavigationModeTurnByTurn`) for `NMATransportModeCar` or `NMATransportModeTruck` transport
 * modes.
 *
 * This method returns a nil object if access to this operation is denied. Contact
 * your HERE representative for more information.
 */
@property (nonatomic, readonly, nullable) NMASchoolZoneWarner *schoolZoneWarner;

/**
 * `NMARoutingZoneWarner` instance provides realtime notifications about routing zone
 * restrictions during an active navigation session `NMANavigationStateRunning`.
 *
 * Notifications are generated every time the current (upcoming) maneuver is updated.
 */
@property (nonatomic, readonly, nullable) NMARoutingZoneWarner *routingZoneWarner;

/**
 * Enable or disable audio events during navigation.
 *
 * Safety spot events (NMANavigationAudioEventSafetySpot) are disabled by default.
 *
 * @note In addition to be being enabled some audio events also require access to the
 * operation (permission), see NMANavigationAudioEvent.
 */
@property (nonatomic) NMANavigationAudioEvent enabledAudioEvents;

/**
 * The three-letter country code (defined in ISO 3166-1) from the current location.
 *
 * This method returns a nil object if the information is not available, if navigation has not been
 * started or if access to this operation is denied (Contact your HERE representative for more
 * information.
 */
@property (nonatomic, readonly, nullable) NSString *countryCode;

/**
 * Returns the remaining distance to the given position on route.
 *
 * @param routeElementIndex     Index of the route element
 * @param positionOnElement     Position on the route element
 *
 * @return the distance in meters. Returns `NMANavigationManagerInvalidValue` if an error occured or
 * if the given position has been already reached.
 */
- (NMAUint64)remainingDistanceToRouteElement:(NSUInteger)routeElementIndex
                           positionOnElement:(nonnull NMAGeoCoordinates *)positionOnElement
NS_SWIFT_NAME(remainingDistance(toRouteElement:positionOnElement:));

/**
 * Returns the remaining distance to the end of route or of route subleg.
 *
 * @param subleg    The subleg number to use or `NMARouteSublegWhole` for the whole route.
 *
 * @return the distance in meters. Returns `NMANavigationManagerInvalidValue` if an error occured or
 * if the end of given route leg has been already reached.
 */
- (NMAUint64)remainingDistanceToSubleg:(NSUInteger)subleg
NS_SWIFT_NAME(remainingDistance(toSubleg:));

/**
 * Returns current route leg.
 *
 * @return the current route leg. Returns ULONG_MAX if an error occured.
 */
@property (nonatomic, readonly) NSUInteger currentRouteLeg;

/**
 * Sets the distance threshold that will be used to consider that stop waypoint and/or
 * destination has been reached. This value will be used for all subsequent
 * `startNavigation` with arbitrary `NMATransportMode`.
 *
 * @note Default value is 5 meters.
 *
 * @param distance The distance from the current position to the upcoming stopover in
 * meters when SDK should trigger `onStopoverReached` callback.
 *
 * @return `NMANavigationErrorInvalidParameters` if distance is equal 0.
 */
- (NMANavigationError)setDistanceToTriggerStopoverReached:(NSUInteger)distance
NS_SWIFT_NAME(setDistanceToTriggerStopoverReached(distance:));

/**
 * Sets the distance threshold that will be used to consider that stop waypoint and/or
 * destination has been reached with u-turn. SDK will trigger `onStopoverReached` if driver
 * makes a u-turn within provided distance to the upcoming stopover. This value will be used for
 * all subsequent navigations with arbitrary `NMATransportMode`.
 *
 * @note Default value is 50 meters.
 *
 * @param distance The distance from the current position to the upcoming stopover in meters when
 * SDK should trigger `onStopoverReached` callback.
 *
 * @return `NMANavigationErrorInvalidParameters` if distance is equal 0.
 */
- (NMANavigationError)setDistanceWithUTurnToTriggerStopoverReached:(NSUInteger)distance
NS_SWIFT_NAME(setDistanceWithUTurnToTriggerStopoverReached(distance:));

/**
 * Sets the distance threshold along with stop time that will be used to consider that stop
 * waypoint and/or destination has been reached. Driver's stop time should be higher than
 * provided time and within provided distance to the upcoming stopover in order to make SDK
 * trigger callback. This value will be used for all subsequent navigations with arbitrary
 * `NMATransportMode`.
 *
 * @note Default time is 3 sec. Default distance for `NMATransportModePedestrian` is 10 meters,
 * for others is 30 meters.
 *
 * @param distance The distance from the current position to the upcoming stopover in meters when
 * SDK should trigger `onStopoverReached` callback.
 * @param time The time in seconds that driver stops and waits within provided distance to the
 * upcoming stopover.
 *
 * @return `NMANavigationErrorInvalidParameters` if distance or time is equal 0.
 */
- (NMANavigationError)setDistanceAndStopTimeToTriggerStopoverReached:(NSUInteger)distance
                                                            stopTime:(NSUInteger)time
NS_SWIFT_NAME(setDistanceAndStopTimeToTriggerStopoverReached(distance:stopTime:));
@end

