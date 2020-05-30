/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;
@class NMAVenue3dService;
@class NMAVenue3dAccount;
@class NMAVenue3dVenue;
@class NMAVenue3dVenueInfo;


/**
 * Represents values that describe the initialization status of the NMAVenue3dService
 *
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dServiceVenueLoadStatus) {
    /**
     * The venue service successfully downloaded the venue.
     */
    NMAVenue3dServiceVenueLoadStatusOnlineSuccess,

    /**
     * The venue service successfully returned venue from cache.
     */
    NMAVenue3dServiceVenueLoadStatusOfflineSuccess,

    /**
     * The venue service failed to deliver the venue. The details why venue service failed is unknown.
     */
    NMAVenue3dServiceVenueLoadStatusFailed,
};

/**
 * Represents values that describe the initialization status of the NMAVenue3dService
 *
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dServiceInitializationStatus) {
    /**
     * The venue service is ready to be used.
     */
    NMAVenue3dServiceInitializationStatusOnlineSuccess,

    /**
     * The NMAVenue3dService failed to authenticate on the server, but
     * successfully initialized previously cached data.
     */
    NMAVenue3dServiceInitializationStatusOfflineSuccess,

    /**
     * The NMAVenue3dService failed to authenticate on the server and
     * there is no previously cached data.
     */
    NMAVenue3dServiceInitializationStatusAuthenticationFailed,

    /**
     * The NMAVenue3dService failed to initialize styles.
     */
    NMAVenue3dServiceInitializationStatusStyleInitializationFailed,

    /**
     * The NMAVenue3dService failed to initialize icons.
     */
    NMAVenue3dServiceInitializationStatusIconInitializationFailed,

    /**
     * The NMAVenue3dService failed to initialize index file.
     */
    NMAVenue3dServiceInitializationStatusIndexInitializationFailed,

    /**
     * The NMAVenue3dService failed to authenticate on the server. If
     * NMAVenue3dServiceInitializationStatusOfflineSuccess has been previously
     * received, the previously cached data is in use. Otherwise NMAVenue3dService
     * failed to initialise.
     */
    NMAVenue3dServiceInitializationStatusOnlineFailed,

    /**
     * The initialization wasn't started.
     */
    NMAVenue3dServiceInitializationStatusNotStarted,

    /**
     * The initialization in progress.
     */
    NMAVenue3dServiceInitializationStatusInProgress,

    /**
     * The NMAVenue3dService is locked with the method
     * `NMAVenue3dService::stopAndClearCacheWithCallback:` .
     *
     * NMAVenue3dService can't be started until
     * status will be changed to NMAVenue3dServiceInitializationStatusNotStarted.
     */
    NMAVenue3dServiceInitializationStatusLocked
};

/**
 * Represents a interface that offers listeners and callback methods related to
 * getting venue.
 *
 * @note Methods of this protocol are called on the main queue.
 *
 */
@protocol NMAVenue3dServiceListener<NSObject>

@optional

/**
 * NMAVenue3dService initialization callback.
 *
 * @param venueService
 *            The NMAVenue3dService object initialized.
 * @param result
 *            The NMAVenue3dServiceInitializationStatus enum which represent current status of
 *            the service.
 */
- (void)venueServiceDidInitialize:(nonnull NMAVenue3dService *)venueService
                       withResult:(NMAVenue3dServiceInitializationStatus)result
NS_SWIFT_NAME(venueService(_:didInitializeWithResult:));

/**
 * NMAVenue3dVenue loading completed callback.
 *
 * If the venue exists in the cache, and there is an updated version available online,
 * this callback function is called two times. You can compare object pointers or unique
 * venue Ids to find out if the venue is an updated version of an already cached (from before) venue.
 *
 * @param venueService
 *            The NMAVenue3dService object returns venue.
 * @param venueInfo
 *            The NMAVenue3dVenueInfo object related to requested NMAVenue3dVenue.
 * @param venue
 *            The loaded NMAVenue3dVenue or nil if the venue loading fails.
 * @param status
 *            The NMAVenue3dServiceVenueLoadStatus of the NMAVenue3dVenue.
 */
- (void)venueService:(nonnull NMAVenue3dService *)venueService
         didGetVenue:(nonnull NMAVenue3dVenue *)venue
       withVenueInfo:(nonnull NMAVenue3dVenueInfo *) venueInfo
          withStatus:(NMAVenue3dServiceVenueLoadStatus) status
NS_SWIFT_NAME(venueService(_:didGetVenue:info:status:));

/**
 * This callback method is triggered when when all venues have been loaded.
 *
 * @param venueService
 *            The NMAVenue3dService.
 */
- (void)venueServiceDidLoadVenues:(nonnull NMAVenue3dService *)venueService
NS_SWIFT_NAME(venueServiceDidLoadVenues(_:));

@end

/**
 * Represents a listener to provide notification of the venue authentication event.
 *
 */
@protocol NMAVenue3dAuthenticationListener<NSObject>

@required

/**
 * NMAVenue3dService authentication callback.
 *
 * @param venueService
 *            The NMAVenue3dService object authenticated.
 * @param result
 *            The BOOL value which represents the authentication result.
 *            YES if authentication finished successfully, NO otherwise.
 * @param errorMessage
 *            The NSString message which returns an error information from
 *            the http response in case of failure.
 */
- (void)didAuthenticateVenueService:(nonnull NMAVenue3dService *)venueService
                         withResult:(BOOL)result
                    andErrorMessage:(nonnull NSString *)errorMessage
NS_SWIFT_NAME(venueService(_:didAuthenticateWithResult:errorMessage:));

@end

/**
 * Represents a interface that offers listeners and callback methods related to
 * stopping venue service.
 *
 * @note Methods of this protocol are called on the main queue.
 *
 */
@protocol NMAVenue3dServiceStopListener<NSObject>

@required

/**
 * NMAVenue3dService stopped completed callback.
 *
 * This callback is called when NMAVenue3dService has been stopped using
 * `NMAVenue3dService::stopWithCallback:`
 * method and no more venues are being loaded.
 */
- (void)didStopVenueService:(nonnull NMAVenue3dService *)venueService
NS_SWIFT_NAME(didStopVenueService(_:));

@end

/**
 * Represents a interface that offers listeners and callback methods related to
 * clearing cache of venue service.
 *
 * @note Methods of this protocol are called on the main queue.
 *
 */
@protocol NMAVenue3dServiceClearCacheListener<NSObject>

@required

/**
 * NMAVenue3dService clear cache completed callback.
 *
 * This callback is called when NMAVenue3dService has cleared its cache using
 * `NMAVenue3dService::stopAndClearCacheWithCallback:` method.
 */
- (void)didClearCache;

@end


/**
 *
 * NMAVenue3dService offers methods to search for venues and
 * to get NMAVenue3dVenue objects based on search.
 *
 * Use of this object does not necessitate NMAMapView involvement.
 * 
 * This class can not be instantiated directly.
 * Use the `NMAVenue3dService::sharedVenueService` method
 * to get the singeton instance of the class instead.
 */
@interface NMAVenue3dService : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Returns a new additional `NMAVenue3dService` instance.
 *
 * @note Use this method to obtain a new additional `NMAVenue3dService` instance.
 * @note The returned object isn't related to the shared singleton `NMAVenue3dService` instance.
 */
- (nullable instancetype)initAdditionalVenueService;

/**
 * Returns the singleton `NMAVenue3dService` instance.
 *
 * @note Use this method to obtain a shared singleton `NMAVenue3dService` instance.
 */
+ (nullable instancetype)sharedVenueService
NS_SWIFT_NAME(sharedInstance());

/**
 * The venue service initialization status.
 */
@property (nonatomic, readonly) NMAVenue3dServiceInitializationStatus initializationStatus;

/**
 * Sets a HERE account token. In case of valid token and if private content
 * is used, NMAVenue3dService will be using private bucket of a HERE account
 * instead of private bucket of the app.
 *
 * @param token a HERE account token.
 */
- (void)setHereAccountToken:(nonnull NSString *)token;

/**
 * Starts NMAVenue3dService authentication asynchronously, without starting
 * NMAVenue3dService. Can be used to retrieve information about NMAVenue3dAccount
 * objects assosiated with the active HERE account token.
 * 
 * An authentication status is returned to the object registered as
 * NMAVenue3dAuthenticationListener.
 *
 * @param listener
 *              NMAVenue3dAuthenticationListener object which will be called
 *              after authentication is done.
 *
 * See also `setHereAccountToken:`
 *
 * See also `activeVenueAccount`
 *
 * See also `venueAccounts`
 *
 * See also `setActiveVenueAccount:`
 */
- (void)authenticateWithCallback:(nullable id<NMAVenue3dAuthenticationListener>)listener
NS_SWIFT_NAME(authenticate(callback:));

/**
 * Returns the active NMAVenue3dAccount, if any exists, or nil otherwise.
 * A NMAVenue3dAccount object only exists if the user is authenticated with a HERE account
 * token and if the account is connected to at least one private content sources.
 * If an account has been made active by calling the setter of this property, that
 * account is returned. Otherwise, the first account in the list of accounts is returned.
 * NMAVenue3dService will use this account only if private content is active.
 *
 * See also `setHereAccountToken:`
 *
 * See also `authenticateWithCallback:`
 *
 * See also `venueAccounts`
 *
 * See also `setActiveVenueAccount:`
 */
@property (nonatomic, readonly, nullable) NMAVenue3dAccount *activeVenueAccount;

/**
 * Returns a (possibly empty) array of available NMAVenue3dAccount objects.
 * Multiple NMAVenue3dAccount objects can be returned if the user is authenticated with
 * the HERE account token and if this HERE account token is connected to at least one
 * private content sources.
 *
 * See also `setHereAccountToken:`
 *
 * See also `authenticateWithCallback:`
 *
 * See also `activeVenueAccount`
 *
 * See also `setActiveVenueAccount:`
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAVenue3dAccount *> *venueAccounts;

/**
 * Sets an active NMAVenue3dAccount object. In case of success, the user can restart
 * the current NMAVenue3dService object with the `NMAVenue3dService::start`
 * method to switch to another private content source, related to the new active
 * NMAVenue3dAccount object.
 *
 * @param account
 *            NMAVenue3dAccount object which needs to be active.
 * @return YES if NMAVenue3dAccount was set successfully, NO otherwise.
 *
 * See also `setHereAccountToken:`
 *
 * See also `authenticateWithCallback:`
 *
 * See also `activeVenueAccount`
 *
 * See also `venueAccounts`
 */
- (BOOL)setActiveVenueAccount:(nullable NMAVenue3dAccount *)account;

/**
 * Add a listener to the venue service. The listener must implement the NMAVenue3dServiceListener protocol.
 * The listener monitors the venue service initialization status and a venue loaded completion event.
 *
 * @param listener the NMAVenue3dServiceListener object to be added
 *
 * See also `NMAVenue3dServiceListener`
 */
- (void)addListener:(nonnull id<NMAVenue3dServiceListener>)listener
NS_SWIFT_NAME(add(listener:));

/**
 * Remove a listener from the venue service. The listener must implement the NMAVenue3dServiceListener protocol.
 * The listener monitors the venue service initialization status and a venue loaded completion event.
 *
 * @param listener the NMAVenue3dServiceListener object to be removed.
 */
- (void)removeListener:(nonnull id<NMAVenue3dServiceListener>)listener
NS_SWIFT_NAME(remove(listener:));

/**
 * A value indicating whether the HERE SDK or the HERE private 3D venue content is
 * to be used. The HERE SDK content is used by default.
 *
 * This property needs to be set before `NMAVenue3dService::start`.
 * If NMAVenue3dService is already running, stop it first using
 * `NMAVenue3dService::stopAndClearCacheWithCallback:` or
 * `NMAVenue3dService::stopWithCallback:`,
 * and then after calling this function, start it again using
 * `NMAVenue3dService::start`.
 */
@property (nonatomic) BOOL privateContent;

/**
 * Defines whether a development or another backend is used.
 * By default, the backend specified with the testEnv property is used.
 *
 * This property needs to be set before `NMAVenue3dService::start`.
 * If NMAVenue3dService is already running, stop it first using
 * `NMAVenue3dService::stopAndClearCacheWithCallback:` or
 * `NMAVenue3dService::stopWithCallback:`,
 * and then after calling this function, start it again using
 * `NMAVenue3dService::start`.
 */
@property (nonatomic) BOOL devEnv;

/**
 * Defines whether a normal or a test backend is used. The normal backend is used by default.
 * This property is irrelevant when the property devEnv is true,
 * because then the development backend is used.
 *
 * This property needs to be set before `NMAVenue3dService::start`.
 * If NMAVenue3dService is already running, stop it first using
 * `NMAVenue3dService::stopAndClearCacheWithCallback:` or
 * `NMAVenue3dService::stopWithCallback:`,
 * and then after calling this function, start it again using
 * `NMAVenue3dService::start`.
 */
@property (nonatomic) BOOL testEnv;

/**
 * A value indicating whether the HERE SDK and the HERE private 3D venue content will
 * be used together. By default combined content is not used.
 *
 * If NMAVenue3dService is using private content, then data from the private content
 * will be used as primary source, and HERE SDK data as an alternative one. Otherwise the HERE SDK
 * content will be primary source of data and the private content will be an alternative one.
 * This property needs to be set before `NMAVenue3dService::start`.
 * If NMAVenue3dService is already running, stop it first using
 * `NMAVenue3dService::stopAndClearCacheWithCallback:` or
 * `NMAVenue3dService::stopWithCallback:`,
 * and then after calling this function, start it again using
 * `NMAVenue3dService::start`.
 */
@property (nonatomic) BOOL combinedContent;

/**
 * Starts NMAVenue3dService asynchronously. The method will do nothing if NMAVenue3dService is already
 * initialized with status NMAVenue3dServiceInitializationStatusOnlineSuccess.
 *
 * An initialization status is returned to objects registered as NMAVenue3dServiceListener to NMAVenue3dService.
 */
- (void)start;

/**
 * Asynchronously gets the NMAVenue3dVenue object that is specified by the given NMAVenue3dVenueInfo object.
 *
 * Venue service listeners will be notified when the venue is loaded via the NMAVenue3dServiceListener::didGetVenue method.
 *
 * @param venueInfo The `NMAVenue3dVenueInfo` object specifying the venue to get.
 *
 * See also `NMAVenue3dVenueInfo:`
 */
- (void)getVenueWithInfo:(nonnull NMAVenue3dVenueInfo *)venueInfo
NS_SWIFT_NAME(venue(info:));

/**
 * Asynchronously gets the NMAVenue3dVenue objects that are specified by the given list of NMAVenue3dVenueInfo objects.
 *
 * Venue service listeners will be notified when a venue is loaded via the NMAVenue3dServiceListener::didGetVenue method.
 *
 * @param venueInfoArray An array of NMAVenue3dVenueInfo objects specifying venues to get.
 *
 * See also `NMAVenue3dVenueInfo:`
 */
- (void)getVenuesWithInfoArray:(nonnull NSArray<NMAVenue3dVenueInfo *> *)venueInfoArray
NS_SWIFT_NAME(venues(infos:));

/**
 * Gets venue info object for the venue identifier.
 *
 * @param venueId venue id
 * @return Venue info object for the venue identifier
 *
 * See also `getVenueWithInfo:`
 */
- (nullable NMAVenue3dVenueInfo *)venueWithId:(nonnull NSString *)venueId
NS_SWIFT_NAME(venue(id:));

/**
 * Searches for venues inside the given NMAGeoBoundingBox.
 *
 * @param boundingBox The area in which to search for venues.
 * @return An array of NMAVenue3dVenueInfo objects representing the venues found inside the specified area.
 *
 * See also `NMAVenue3dVenueInfo`
 */
- (nullable NSArray<NMAVenue3dVenueInfo *> *)venuesInGeoBoundingBox:(nonnull NMAGeoBoundingBox *)boundingBox
NS_SWIFT_NAME(venues(in:));

/**
 * Searches for venues at the given NMAGeoCoordinates.
 *
 * @param coordinates The location around which to search for venues.
 * @return An array of NMAVenue3dVenueInfo objects representing the venues found near the specified location.
 *
 * See also `NMAVenue3dVenueInfo`
 */
- (nullable NSArray<NMAVenue3dVenueInfo *> *)venuesAtGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates
NS_SWIFT_NAME(venues(at:));

/**
 * Searches for a venue closest to the given NMAGeoCoordinates.
 *
 * @param coordinates The location around which to search for venues.
 *
 * @return The closet NMAVenue3dVenueInfo object to the specified point or nil if there is no any.
 *
 * See also `NMAVenue3dVenueInfo`
 */
- (nullable NMAVenue3dVenueInfo *)venueAtGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates
NS_SWIFT_NAME(venue(at:));

/**
 * Searches for venues near the given NMAGeoCoordinates.
 *
 * @param coordinates The location around which to search for venues.
 * @param radius     The radius in meters where to search venues.
 * @return The array of NMAVenue3dVenueInfo objects found near the specified point
 *
 * See also `NMAVenue3dVenueInfo`
 */
- (nullable NSArray<NMAVenue3dVenueInfo *> *)venuesAtGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates radius:(float)radius
NS_SWIFT_NAME(venues(at:radius:));

/**
 * Searches for a venue closest to the given NMAGeoCoordinates within a radius.
 *
 * @param coordinates The location around which to search for venues.
 * @param radius      The radius in meters where to search venues.
 *
 * @return The closet NMAVenue3dVenueInfo object to the specified point or nil if there is no any
 *
 * See also `NMAVenue3dVenueInfo`
 */
- (nullable NMAVenue3dVenueInfo *)venueAtGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates radius:(float)radius
NS_SWIFT_NAME(venue(at:radius:));

/**
 * Stops NMAVenue3dService asynchronously. `NMAVenue3dServiceStopListener::didStopVenueService:`
 * callback will be called and this callback also indicates that no more Venue loading
 * is happening anymore.
 * Use `NMAVenue3dService::start` to start the service again.
 *
 * @param stopListener Notification callback.
 */
- (void)stopWithCallback:(nullable id<NMAVenue3dServiceStopListener>)stopListener
NS_SWIFT_NAME(stop(callback:));

/**
 * Clears cached data including all downloaded venues. All running instances of
 * venue service will be stopped asynchronously and locked ( `initializationStatus`
 * will return NMAVenue3dServiceInitializationStatusLocked during the operation).
 * After the cache is cleared, NMAVenue3dService needs to be started again using the
 * `NMAVenue3dService::start` method.
 *
 * @param listener Notification callback.
 */
+ (void)stopAndClearCacheWithCallback:(nullable id<NMAVenue3dServiceClearCacheListener>)listener
NS_SWIFT_NAME(stopAndClearCache(callback:));

@end
