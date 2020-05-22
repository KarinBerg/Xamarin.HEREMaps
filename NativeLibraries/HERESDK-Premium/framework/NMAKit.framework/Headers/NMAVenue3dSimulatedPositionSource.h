/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAPositionDataSource.h"


@class NMAVenue3dVenueRouteSection;
@class NMAVenue3dLinkRouteSection;

/**
 * The possible states of NMAVenue3dSimulatedPositionSource.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dSimulationState) {
    /** No simulation is in progress */
    NMAVenue3dSimulationStateIdle = 0,
    /** Simulation is in progress and active */
    NMAVenue3dSimulationStateRunning,
    /** Simulation is in progress but not currently active */
    NMAVenue3dSimulationStatePaused
};


/**
 *
 * Represents a position data source, which is able to simulate indoor positioning
 *        based on provided NMAVenue3dVenueRouteSection object.
 *
 * IMPORTANT: Venue3D Simulated Position Source is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * See also `NMAVenue3dVenueRouteSection`
 *
 * See also `NMAVenue3dNavigationManager`
 */
@interface NMAVenue3dSimulatedPositionSource : NSObject <NMAPositionDataSource>

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Returns the interval between two updates of postion and, in case of error, returns -DBL_MAX.
 */
@property( nonatomic, readwrite ) NSTimeInterval updatesInterval;

/**
 * Instantiates a new NMAVenue3dSimulatedPositionSource object using the specified
 * venue route section with the constant speed.
 *
 * @param routeSection The venue route section to navigate.
 * @param speed The speed in meters per second (m/s).
 * @param distortionEnabled Specifies whether position will be distorted with some random factor.
 */
+ (nonnull instancetype)positionSourceWithRouteSection:
                            (nonnull NMAVenue3dVenueRouteSection*)routeSection
                                                 speed:(double)speed
                                     distortionEnabled:(BOOL)distortionEnabled
NS_SWIFT_UNAVAILABLE( "Use corresponding instance initializer" );

/**
 * Instantiates a new NMAVenue3dSimulatedPositionSource object using the specified
 * link route section with the constant speed.
 *
 * @param linkSection The link route section to navigate.
 * @param speed The speed in meters per second (m/s).
 * @param distortionEnabled Specifies whether position will be distorted with some random factor.
 */
+ (nonnull instancetype)positionSourceWithLinkSection:(nonnull NMAVenue3dLinkRouteSection*)linkSection
                                                speed:(double)speed
                                    distortionEnabled:(BOOL)distortionEnabled
NS_SWIFT_UNAVAILABLE( "Use corresponding instance initializer" );

/**
 * Initializes a new NMAVenue3dSimulatedPositionSource object using the specified
 * venue route section with the constant speed.
 *
 * @param routeSection The venue route section to navigate.
 * @param speed The speed in meters per second (m/s).
 * @param distortionEnabled Specifies whether position will be distorted with some random factor.
 */
- (nonnull instancetype)initWithRouteSection:(nonnull NMAVenue3dVenueRouteSection*)routeSection
                                       speed:(double)speed
                           distortionEnabled:(BOOL)distortionEnabled
NS_SWIFT_NAME(init(routeSection:speed:distortionEnabled:));

/**
 * Initializes a new NMAVenue3dSimulatedPositionSource object using the specified
 * link route section with the constant speed.
 *
 * @param linkSection The link route section to navigate.
 * @param speed The speed in meters per second (m/s).
 * @param distortionEnabled Specifies whether position will be distorted with some random factor.
 */
- (nonnull instancetype)initWithLinkSection:(nonnull NMAVenue3dLinkRouteSection*)linkSection
                                      speed:(double)speed
                          distortionEnabled:(BOOL)distortionEnabled
NS_SWIFT_NAME(init(linkSection:speed:distortionEnabled:));

/**
 * Returns the current state of the simulation related to the tracked route.
 */
@property (nonatomic, readonly) NMAVenue3dSimulationState navigationState;

/**
 * When set to YES, the current simulation will be paused (if any). When set
 * to NO, the current simulation will resume if previously paused. This has no
 * effect if there is no simulation currently in progress.
 */
@property (nonatomic, getter = isPaused) BOOL paused;

@end
