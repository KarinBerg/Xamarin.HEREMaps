/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAIsolineError.h"

@class NMAGeoCoordinates;
@class NMARoutingMode;
@class NMAIsoline;
@class NMAIsolineOptions;

/**
 * The possible types of connectivity for route calculation
 */
typedef NS_ENUM(NSUInteger, NMAIsolineRouterConnectivity) {
    /**
     * Isoline is calculated based on the current online status [NMAApplicationContext isOnline],
     * which depends on the current network access and could be forced to offline using
     * [NMAApplicationContext setNetworkAccessAllowed:NO]
     * If the SDK is online, then an online isoline calculation will be made.
     * If the SDK is offline, then an offline isoline calculation is performed.
     */
    NMAIsolineRouterConnectivityDefault,
    /**
     * Attempts offline isoline calculation regardless whether there is enough map
     * data on the device. If there is not enough map data the request might
     * fail. If it fails, it will not try online.
     */
    NMAIsolineRouterConnectivityOffline,
    /**
     * Attempts online isoline calculation regardless whether device is online or
     * whether the HERE SDK is allowed to access network. If the device is
     * offline, the request will fail. If it fails, it will not try offline.
     */
    NMAIsolineRouterConnectivityOnline
};

/**
 * Specifies type of range. Possible values are distance and time.
 */
typedef NS_ENUM(NSUInteger, NMAIsolineRangeType) {
    /**
     * Undefined.
     */
    NMAIsolineRangeTypeUndefined,
    /**
     * Distance.
     */
    NMAIsolineRangeTypeDistance,
    /**
     * Balanced.
     */
    NMAIsolineRangeTypeTime
};


/**
 * A completion block used to handle the result of a isoline request.
 *
 * @param isolines The result of the isoline calculation (can be nil if `NMAIsolineError`
 * error param is not `NMAIsolineErrorNone`)
 *
 * @param error A isoline calculation error.
 * See `NMAIsolineError` for possible error codes.
 */
typedef void(^NMAIsolineCalculateResultBlock)(NSArray <NMAIsoline *> * _Nullable isolines, NMAIsolineError error);


/**
 */

/**
 * Isoline calculation executor. Defines concrete calculation method and response listener.
 *
 * NMAIsolineRouter requires valid authentication credentials to be set via
 * NMAApplicationContext. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.
 */
@interface NMAIsolineRouter : NSObject

/**
 * Default initializer that initializes a `NMAIsolineRouter` instance with `NMAIsolineRouterConnectivityDefault`
 * for route calculation.
 *
 * @return The `NMAIsolineRouter`
 */
- (nonnull instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * This determines whether isoline is calculated online or offline. Default is
 * `NMAIsolineRouterConnectivityDefault`.
 *
 * If set to offline, it will attempt to calculate the isoline offline
 * regardless of the routing type and regardless of whether there is
 * enough map data for the isoline calculation, if fails, it will not
 * make another attempt online.
 *
 * If set to online, it will attempt to calculate the isoline
 * online regardless of the routing type and regardless of the current
 * device connectivity. If it fails, it will not make another attempt
 * offline.
 *
 * If this is changed after calling calculateFromPoint or calculateFromPoint
 * the change will not take effect for the current isoline calculation.
 */
@property (nonatomic) NMAIsolineRouterConnectivity connectivity;

/**
 * Starts a isoline calculation with the given staring point, `NMARoutingMode`
 * and `NMAIsolineOptions`
 *
 * This method returns nil and a isoline will not be calculated if access to this
 * operation is denied. Contact your HERE representative for more information.
 *
 * @param point The start waypoint for isoline.
 * @param mode The `NMARoutingMode` is used for isoline calculation.
 * @param options The `NMAIsolineOptions` is used for isoline calculation.
 * @param type The `NMAIsolineRangeType` is used for isoline calculation.
 * @param ranges The array of ranges is used for isoline calculation.
 *
 * @return `YES` if isoline calculation is successfully started, `NO` otherwise.
 *
 * @note If the SDK/device becomes offline and you do not have offline permission
 * for the transport mode being requested, this operation will be denied.
 */
- (BOOL)calculateFrom:(nonnull NMAGeoCoordinates *)point
          routingMode:(nonnull NMARoutingMode *)mode
       isolineOptions:(nonnull NMAIsolineOptions *)options
            rangeType:(NMAIsolineRangeType)type
               ranges:(nonnull NSArray *)ranges
      completionBlock:(nullable NMAIsolineCalculateResultBlock)completion;

/**
 * Starts a isoline calculation with the given destination point, `NMARoutingMode`
 * and `NMAIsolineOptions`
 *
 * This method returns nil and a isoline will not be calculated if access to this
 * operation is denied. Contact your HERE representative for more information.
 *
 * @param destination The destination waypoint for isoline.
 * @param mode The `NMARoutingMode` is used for isoline calculation.
 * @param options The `NMAIsolineOptions` is used for isoline calculation.
 * @param type The `NMAIsolineRangeType` is used for isoline calculation.
 * @param ranges The array of ranges is used for isoline calculation.
 *
 * @return `YES` if isoline calculation is successfully started, `NO` otherwise.
 *
 * @note If the SDK/device becomes offline and you do not have offline permission
 * for the transport mode being requested, this operation will be denied.
 */
- (BOOL)calculateTo:(nonnull NMAGeoCoordinates *)destination
        routingMode:(nonnull NMARoutingMode *)mode
     isolineOptions:(nonnull NMAIsolineOptions *)options
          rangeType:(NMAIsolineRangeType)type
             ranges:(nonnull NSArray *)ranges
    completionBlock:(nullable NMAIsolineCalculateResultBlock)completion;

/**
 * Indicates whether or not the NMAIsolineRouter is currently calculating a route.
 *
 * @note Any requests made while the NMAIsolineRouter is busy will fail.
 */
@property (nonatomic, getter = isBusy) BOOL busy;

/**
 * Cancels the current isoline calculation.
 * @return YES if the cancellation can be processed, NO otherwise
 */
- (BOOL)cancel;

@end
