/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;

/**
 * Defines types of error codes that can be returned when setting the HERE Authentication
 * Credentials, License Key and Map Variant.
 */
typedef NS_ENUM(NSUInteger, NMAApplicationContextError) {
    /** There was no error. */
    NMAApplicationContextErrorNone = 0,
    /** There was no license key e.g. license key is empty string. */
    NMAApplicationContextErrorLicenseKeyEmpty,
    /** There was an error due to the namespace, App_Id, or App_Code being mismatched. */
    NMAApplicationContextErrorLicenseKeyMismatch,
    /** There was an error due to invalid platform, e.g. Android license key used on iOS. */
    NMAApplicationContextErrorLicenseInvalidPlatform,
    /** There was an error due to expired license key.*/
    NMAApplicationContextErrorLicenseExpired,
    /** Permission to use map variant denied. Please consult with your HERE representative to get access. */
    NMAApplicationContextErrorMapVariantPermissionDenied,
    /**
     * There was attempt to change map variant. Map variant cannot be changed after HERE SDK has been initialized for
     * first time. If you want use other map variant, please, reinstall application and choose appropriate one.
     */
    NMAApplicationContextErrorMapVariantChangeAttempt,
    /** Storage of the selected map variant failed. */
    NMAApplicationContextErrorMapVariantStorageFailed,
    /** Incorrect license key. */
    NMAApplicationContextErrorIncorrectLicenseKey
};

/**
 * Defines supported map variants. Value will be stored and used on sub-sequent `NMAMapEngine`
 * initializations. User must use the same value for sub-sequent `NMAMapEngine` initializations.
 * Using different values in sub-sequent initializations will report error and initialization
 * will fail. In order to use either `NMAMapVariantKorea` or `NMAMapVariantChina` developer
 * must consult with HERE representative.
 */
typedef NS_ENUM(NSUInteger, NMAMapVariant) {
    /** Global map variant. */
    NMAMapVariantGlobal = 0,
    /** Korean map variant. */
    NMAMapVariantKorea,
    /** Chinese map variant. */
    NMAMapVariantChina
};

/**
 * Indicates that the NMAApplicationContext isOnline status has changed.
 *
 * In order to receive this notification, register with NSNotificationCenter
 * using this notification name and a nil notification sender.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAApplicationContextOnlineStatusDidChangeNotification;


/**
 * Indicates that the `NMAApplicationContext` license key has expired.
 *
 * In order to receive this notification, register with NSNotificationCenter
 * using this notification name and a nil notification sender.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAApplicationContextLicenseKeyExpiredNotification;


/**
 *
 * Use this interface to set mandatory authentication crendentials
 *
 * @note YOU MUST SET AUTHENTICATION CREDENTIALS in order to use the APIs
 * contained within this SDK. Some APIs may appear to work without valid
 * credentials but they may stop functioning in the near future when server side
 * configurations change, so please obtain and use valid credentials.
 */
@interface NMAApplicationContext : NSObject

/**
 * Instances of this class should not be initialized. Call class methods only.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Sets the mandatory HERE Authentication Credentials and License Key.
 *
 * These credentials MUST be set before attempting to use any other APIs in the HERE SDK.
 * You may only call one of setAppId:appCode:licenseKey: or setAppId:appCode:licenseKey:mapVariant: methods once.
 * This method will use `NMAMapVariantGlobal` map variant
 * It is recommended to call this method in
 * [UIApplicationDelegate didFinishLaunchingWithOptions]
 *
 * @param appId Application ID
 * @param appCode Application Code
 * @param licenseKey License Key
 * @return The status i.e. check NMAApplicationContextError for failure reason
 */
+ (NMAApplicationContextError)setAppId:(nonnull NSString *)appId
                               appCode:(nonnull NSString *)appCode
                            licenseKey:(nonnull NSString *)licenseKey;

/**
 * Sets the mandatory HERE Authentication Credentials, License Key and Map Variant.
 *
 * These credentials MUST be set before attempting to use any other APIs in the HERE SDK.
 * You may only call one of setAppId:appCode:licenseKey: or setAppId:appCode:licenseKey:mapVariant: methods once.
 * It is recommended to call this method in
 * [UIApplicationDelegate didFinishLaunchingWithOptions]
 *
 * @param appId Application ID
 * @param appCode Application Code
 * @param licenseKey License Key
 * @param mapVariant map variant to use. See `NMAMapVariant`.
 * @return The status i.e. check NMAApplicationContextError for failure reason
 */
+ (NMAApplicationContextError)setAppId:(nonnull NSString *)appId
                               appCode:(nonnull NSString *)appCode
                            licenseKey:(nonnull NSString *)licenseKey
                            mapVariant:(NMAMapVariant)mapVariant;

/**
 * Returns the LicenseKey.
 */
+ (nullable NSString *)licenseKey;

/**
 * Sets initial map center with specified `NMAGeoCoordinates`.
 */
+ (void)setMapCenter:(nonnull NMAGeoCoordinates *)initialCenter;

/**
 * Return the SDK version
 * @return The SDK verion
 */
+ (nonnull NSString *)sdkVersion;

/**
 * Controls whether the HERE SDK is ALLOWED to access network services.
 *
 * @note If set to NO then the HERE SDK will not access the network to download
 * map data, perform searches, calculate routes or when providing any other service
 * unless the service allows overriding this setting, e.g. see `NMACoreRouterConnectivity`,
 * `NMARequestConnectivity`, and `NMACLE2ConnectivityMode`.
 */
+ (void)setNetworkAccessAllowed:(BOOL)networkAccessAllowed;

/**
 * Indicates whether the HERE SDK is ALLOWED to access network services.
 *
 * Defaults to YES.
 *
 * @note If NO is returned then the HERE SDK will not access the network to
 * download map data, perform searches, calculate routes or when providing any
 * other service unless the service allows overriding this setting, e.g. see
 * `NMACoreRouterConnectivity`, `NMARequestConnectivity`, and `NMACLE2ConnectivityMode`.
 */
+ (BOOL)isNetworkAccessAllowed;

/**
 * Allows to use online traffic when the HERE SDK is set to Offline.
 *
 * @note setNetworkAccessAllowed method resets traffic connectivity mode. Therefore this
 * method must be called only after setNetworkAccessAllowed.
 *
 * @note This method must be called only when the HERE SDK is NOT ALLOWED to access
 * network services. If isNetworkAccessAllowed returns YES then this method returns NO.
 */
+ (BOOL)enableTrafficInOfflineMode:(BOOL)enable;

/**
 * Indicates whether the HERE SDK is currently online and accessing
 * network services.
 *
 * @note This reflects the actual online status of the HERE SDK. If
 * isNetworkAccessAllowed returns YES but no data connection is available then
 * this method will return NO. If isNetworkAccessAllowed returns NO then this
 * method returns NO.
 */
+ (BOOL)isOnline;

/**
 * Indicates whether the HERE SDK is initialized.
 *
 * @note If NO is returned then the HERE SDK is not ready to handle any service.
 */
+ (BOOL)isInitialized;

/**
 * Disable showing the HERE SDK Version in crash stack traces.
 *
 * @note By default, the HERE SDK starts a lightweight thread which which sleeps
 * in a function whose name is the current HERE SDK Version. Calling this method
 * causes that thread to terminate.
 */
+ (void)disableSdkVersionInCrashStack;

/**
 * Sets a disk cache size. Default value is 256 Mb.
 *
 * @note It is not recommended to change this cache size, but allow SDK defines size of the cache.
 * Consider when deciding to change the default value that a small cache size will
 * help limit persistent memory usage on the device however will result in more frequent
 * cache purging in order to make space available for new map data. This can increase
 * the likelihood of needing to re-download map data for an area as the previously
 * downloaded map data was purged from the cache.
 * A large cache size will increase the likelihood that previously downloaded map data
 * will be available in the cache when needed (i.e. cache purging is less frequent)
 * however at the expense of consuming a large amount of the devices persistent memory.
 *
 * @param size Desired disk cache size. Must be within the [256..2048] Mb range.
 * @return YES if the size was set, NO otherwise (if the size is out of range).
 */
+ (BOOL)setDiskCacheSize:(NSUInteger)size;

/**
 * Gets map approval code for specific country.
 *
 * @param locale `NSLocale` with country code. Provided locale must have country code.
 * @return map approval code or nil if approval code is not required for provided country
 * or provided locale does not have country code.
 */
+ (NSString *_Nullable)getMapApprovalCodeWithCountry:(NSLocale *_Nonnull)locale;

/**
 * Gets provider copyright statement for specific country.
 *
 * @param locale `NSLocale` with country code. Provided locale must have country code.
 * @return provider copyright statement or nil if there is no such statement or provided
 * locale does not have country code.
 */
+ (NSString *_Nullable)getMapDataProviderCopyrightStatementWithCountry:(NSLocale *_Nonnull)locale;

/**
 * Enables improvements for map matcher functionality. It provides improvements in algorithms
 * that allow determining current location over the map with better precision.
 * The SDK 3.12 includes it as a beta feature and the improvements are enabled by default.
 *
 * IMPORTANT: This is a Beta API, and is subject to change without notice
 * DEPRECATED As of SDK 3.12.
 */
+ (void)enableEnhancedMapMatcher:(BOOL)enabled DEPRECATED_ATTRIBUTE;

@end
