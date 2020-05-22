/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoPosition;
@class NMAGeoCoordinates;
@class NMARoadElement;
@protocol NMAPositionDataSource;


/** NMAPositioningManager Notifications */

/**
 * Indicates that the NMAPositioningManager currentPosition has changed.
 *
 * In order to receive this notification, register with NSNotificationCenter using this notification name and the
 * [NMAPositioningManager sharedPositioningManager] instance as the object (notification sender).
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPositioningManagerDidUpdatePositionNotification;

/**
 * Indicates that the NMAPositioningManager currentPosition has been lost.
 *
 * In order to receive this notification, register with NSNotificationCenter using this notification name and the
 * [NMAPositioningManager sharedPositioningManager] instance as the object (notification sender).
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPositioningManagerDidLosePositionNotification;

/**
 * Positioning methods used with the default position source (NMADevicePositionSource). Not applicable
 * for other types of position source.
 */
typedef NS_ENUM(NSUInteger, NMALocationTrackingMethod) {
    /** Device positioning is not active. */
    NMALocationTrackingMethodNone = 0,
    /** Position provided by CLLocationManager::startUpdatingLocation. */
    NMALocationTrackingMethodGPS,
    /** Position provided by CLLocationManager::startMonitoringSignificantLocationChanges.  */
    NMALocationTrackingMethodSignificantChanges
};

/**
 * The types of position matching that can be performed by the NMAPositioningManager.
 */
typedef NS_ENUM(NSUInteger, NMAMapMatchMode) {
    /** The raw position is matched only to roads which support automobile traffic. */
    NMAMapMatchModeCar,
    /** The raw position is matched only to roads which support pedestrian traffic, e.g. including footpahs and excluding freeways. */
    NMAMapMatchModePedestrian,
    /** The raw position is matched only to roads which support truck traffic. */
    NMAMapMatchModeTruck,
    /** The raw position is matched only to roads which support scooter traffic. */
    NMAMapMatchModeScooter
};

/**
 * Specifies the type of position logging currently enabled
 */
typedef NS_OPTIONS(NSInteger, NMAPositionLogType) {
    /** No logging */
    NMAPositionLogTypeNone        = 0,
    /** Logs data source input positions to "*_ios_source.gpx" */
    NMAPositionLogTypeDataSource  = 1 << 0,
    /** Logs currentPosition property updates to "*_ios_current.gpx" */
    NMAPositionLogTypeCurrent     = 1 << 1,
    /** Logs rawPosition property updates to "*_ios_raw.gpx" */
    NMAPositionLogTypeRaw         = 1 << 2,
    /** Logs mapMatchedPosition property updates to "*_ios_matched.gpx" */
    NMAPositionLogTypeMatched     = 1 << 3,
    /** Logs everything */
    NMAPositionLogTypeAll         = 0xFF
};

/**
 * Represents an interface for coordinates shifting module.
 */
@protocol NMAGeoShiftableDelegate<NSObject>

@required

/**
 * Shifts input coordinates and returns result.
 */
- (nonnull NMAGeoPosition *)shift:(nonnull NMAGeoPosition *)position;

@end


/**
 * Manages positioning services for the NMA SDK.
 *
 * This is a singleton class and thus should never be retained, released, or
 * instantiated. The singleton instance is accessed via the
 * sharedPositioningManager method.
 *
 *
 * Use the startPositioning method to begin tracking position, and stopPositioning
 * to stop. By default, position data comes from an instance of NMADevicePositionSource,
 * which uses CLLocationManager to determine position. Any custom source of position
 * data can be used instead by subclassing NMAPositionDataSource and installing an
 * instance of the subclass in the NMAPositioningManager dataSource property.
 *
 * Two types of position are available from the positioning manager: the raw position
 * and the map-matched position. The raw position is simply passed straight through from
 * the positioning manager's data source. The map-matched position is the estimated position
 * on the road network based on the raw position input. When either type of position changes,
 * a NMAPositioningManagerDidUpdatePositionNotification will be sent out. If the raw position
 * is lost, a NMAPositioningManagerDidLosePositionNotification is sent.
 *
 * @note Certain other SDK features may require the use of the positioning manager;
 * if these features are accessed, the positioning manager will be enabled
 * automatically (for example, the NMAPositionIndicator of a NMAMapView).
 *
 * @note NMAPositioningManager requires valid authentication credentials to be set via
 * NMAApplicationContext. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.
 */
@interface NMAPositioningManager : NSObject

/**
 * Returns the NMAPositioningManager singleton instance.
 *
 * @note Use this method to obtain a NMAPositioningManager instance. Do not call
 * init directly.
 *
 * @return shared NMAPositioningManager instance
 */
+ (nonnull NMAPositioningManager *)sharedPositioningManager
NS_SWIFT_NAME(sharedInstance());

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The current provider of raw position data for the positioning manager.
 *
 * If positioning is started with a nil dataSource, a default instance of
 * NMADevicePositionSource is created and installed. This instance can then be
 * accessed and configured using the dataSource property. Similarly, if the dataSource
 * is set to nil while positioning is active, a default position source is installed.
 *
 * @note It is NOT recommended to change data source whilst the app is backgrounded
 * as some attributes of the data source (such as enabling background updates) may not
 * be reliably configurable in the background.
 */
@property (nonatomic, nullable) id<NMAPositionDataSource> dataSource;

/**
 * Indicates whether the NMAPositioningManager is currently broadcasting
 * position updates.
 */
@property (nonatomic, readonly, getter = isActive) BOOL active;

/**
 * The latest unprocessed position received from the current dataSource.
 *
 * @note Will be nil if the latest update from the current dataSource did not
 * return a valid position.
 */
@property (nonatomic, readonly, nullable) NMAGeoPosition *rawPosition;

/**
 * The best esimated position on the road network based on the current rawPosition.
 *
 * When a new raw position is received and map matching is enabled, the position
 * is processed to estimate where on the road network the user is likely to be.
 * If the user is in a car on a known road, this position is likely to be more
 * accurate than the raw position. Map matching can be disabled by setting the
 * mapMatchingEnabled property to NO.
 *
 * @note Will be nil if map matching could not be performed, or if mapMatchingEnabled
 * is set to NO.
 */
@property (nonatomic, readonly, nullable) NMAGeoPosition *mapMatchedPosition;

/**
 * The best estimate for the user's current position.
 *
 * The currentPosition will be equal to either the rawPosition or the
 * mapMatchedPosition, depending on availability, SDK usage, and circumstances.
 *
 * If SDK services such as navigation which require the use of map matching are
 * active, the currentPosition will typically be the map-matched position.
 *
 * @note Will be nil if the positioning manager is not active or does not
 * have a valid position.
 */
@property (nonatomic, readonly, nullable) NMAGeoPosition *currentPosition;

/**
 * Controls whether or not map matching is performed.
 *
 * The Map Matching is not enabled if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @note The default value is NO.
 */
@property (nonatomic) BOOL mapMatchingEnabled;

/**
 * The mode in which raw position data is matched to the road network.
 *
 * If the mode is NMAMapMatchModeCar, the raw position data will only be matched
 * to roads which are accessible by a car. If the mode is NMAMapMatchModePedestrian,
 * the data will only be matched to roads or paths which are accessible on foot.
 *
 * See also `NMAMapMatchMode`
 *
 * @note Attempts to set NMAMapMatchModePedestrian will be ignored when the position
 * data source is derived from NMAPositionDataSourceAutomotive as this position source
 * type does not support pedestrian map matching.
 */
@property (nonatomic) NMAMapMatchMode mapMatchMode;

/**
 * Enables position broadcasting.
 *
 * When positioning is started, the current dataSource will receive a start callback.
 * If no dataSource is set, a default instance of NMADevicePositionSource is created
 * and installed as the source.
 *
 * @return YES if positioning was successfully started, NO if positioning
 * was already in progress or if positioning failed to start.
 *
 * See also `NMAPositionDataSource`
 */
- (BOOL)startPositioning;

/**
 * Disables position broadcasting.
 *
 * When positioning is stopped, the current dataSource will receive a
 * stop callback.
 *
 * See also `NMAPositionDataSource`
 */
- (void)stopPositioning;

/**
 * Get the road element of the current position.
 * Nil if not valid.
 *
 * @return Road element of the current position.
 */
- ( nullable NMARoadElement *)currentRoadElement;

/**
 * Used by the dataSource to indicate that a new position update is
 * available.
 *
 * When the current dataSource has a new position update ready, it calls this
 * method passing itself as the parameter. Only one position source may be
 * active at a time, so the parameter should match the current dataSource.
 * Objects other than the current dataSource should not call this method.
 */
- (void)dataSourceDidUpdatePosition:(nonnull id<NMAPositionDataSource>)dataSource;

/**
 * Configures position update logging.
 *
 * NMAPositionLogTypeDataSource will log "input positions" from the current NMAPositionDataSource
 * to a file ending with the suffix "_ios_source". This GPX file is suitable for playback via
 * NMALoggedPositionSource. In addition, if the current NMAPositionDataSource supports source
 * specific logging then an additional GPX log will be written. For example, NMADevicePositionSource
 * will log detailed CLLocationManager state information to a file ending with the suffix "_ios_cl".
 *
 * NMAPositionLogTypeCurrent, NMAPositionLogTypeRaw, and NMAPositionLogTypeMatched will
 * log the results of processing the input position from the data source. The content of these logs
 * represents the historical values of the rawPosition, mapMatchedPosition, and currentPosition
 * properties. GPX logs produced for these logging types are for analysis only and are not suitable
 * for playback via NMALoggedPositionSource.
 *
 * GPX logs will be written to the Documents directory of the application. Logs will be prefixed
 * with a timestamp representing the time logging was enabled and suffix indicating the log type
 * (see NMAPositionLogType).
 *
 * To ensure log files are flushed to disk make sure logging is disabled prior to application exit.
 *
 * Defaults to NMAPositionLogTypeNone (no logging).
 *
 * @note IMPORTANT: Logging should NOT be permanently enabled in production builds submitted to the
 * App Store.
 */
@property (nonatomic) NMAPositionLogType logType;

/**
 * Enables probe data collection.
 *
 * If enabled, the SDK will start sending anonymous location information when current
 * user's speed is above certain value. Calculation of speed is based on location data.
 *
 * This data is used to help improve the accuracy of traffic information provided through
 * the SDK.
 *
 * By default this property is disabled.
 *
 * @note Note, probe data collection will start when `NMAPositioningManager` is active.
 * @note
 * Probe data collection cannot be enabled if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 */
@property (nonatomic, getter = isProbeCollectionEnabled) BOOL probeCollectionEnabled;

/**
 * A handler for the coordinates shift module.
 */
@property (nonatomic, weak, nullable) id<NMAGeoShiftableDelegate> geoShiftableDelegate;

@end
