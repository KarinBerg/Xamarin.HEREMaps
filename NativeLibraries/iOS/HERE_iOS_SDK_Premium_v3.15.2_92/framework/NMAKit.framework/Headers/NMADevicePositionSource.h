/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "NMAPositionDataSource.h"

@class CLLocationManager;


/**
 *  Possible methods for determining device position change.
 */
typedef NS_ENUM(NSUInteger, NMADevicePositioningMethod) {
    /** Equivalent to [CLLocationManager startUpdatingLocation] */
    NMADevicePositioningMethodGPS,
    /** Equivalent to [CLLocationManager startMonitoringSignificantLocationChanges] */
    NMADevicePositioningMethodSignificantChanges
};


/**
 * A position data source which gets updates from CLLocationManager.
 *
 * NMADevicePositionSource provides basic usage of CLLocationManager to the
 * NMAPositioningManager. The properties of the CLLocationManager instance may be
 * customized as needed, otherwise the default values are used.
 *
 * @note More advanced usage of CLLocationManager may be achieved by subclassing
 * NMADevicePositionSource. Any of the `CLLocationManagerDelegate` methods may be
 * freely implemented, except locationManager:didUpdateLocations: and
 * locationManager:didFailWithError:. If either of these methods is implemented,
 * the superclass method should be invoked at some point in the subclass implementation.
 */
@interface NMADevicePositionSource : NSObject<NMAPositionDataSource, CLLocationManagerDelegate>

/**
 * Initialize an NMADevicePositionSource instance
 */
- (nonnull instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * The CLLocationManager instance used to generate position updates.
 */
@property (nonatomic, readonly, nonnull) CLLocationManager *locationManager;

/**
 * A convenience method to set the frequency of position updates.
 *
 * The device positioning method controls how CLLocationManger generates its updates. Refer to
 * the CLLocationManager API reference for an explanation of the update methods.
 *
 * Defaults to NMADevicePositioningMethodGPS
 *
 * See also `NMADevicePositioningMethod`
 */
- (void)setPositioningMethod:(NMADevicePositioningMethod)method;

@end
