/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Defines types of error codes that can be returned when setting the HERE custom
 * map style configuration.
 */
typedef NS_ENUM(NSUInteger, NMAMapStyleConfigurationError) {
    /** There was no error. */
    NMAMapStyleConfigurationErrorNone = 0,
    /** There was an error due to HERE SDK is already initialized. */
    NMAMapStyleConfigurationErrorHERESDKAlreadyInitialized,
    /** There was an error due to file cannot be found. */
    NMAMapStyleConfigurationErrorConfigurationFile,
    /** There was an error due to file cannot be found. */
    NMAMapStyleConfigurationErrorResourceFile,
    /** There was an error due to file cannot be found. */
    NMAMapStyleConfigurationErrorTrafficConfigurationFile,
    /** There was an error due to file cannot be found. */
    NMAMapStyleConfigurationErrorCustomPreferenceConfigurationFile,
    /** There was an error when trying to set configuration without setting resource file or vice versa. They must always be set together */
    NMAMapStyleConfigurationErrorConfigurationResourceFiles,
    /** There was an error due to wrong key, e.g Passed key is not supported. */
    NMAMapStyleConfigurationErrorKeyIsNotSupported
};

/**
 * Map Style key type
 */
typedef NSString * _Nonnull NMAMapViewCustomConfigurationFileKey NS_STRING_ENUM NS_SWIFT_NAME(NMAMapViewCustomConfiguration);

/**
 * Map Style Configuration File
 *
 * @note Key for the full file path of the configuration file.
 */
FOUNDATION_EXPORT NMAMapViewCustomConfigurationFileKey const NMAMapViewConfigurationFileKey;

/**
 * Map Style Resource File
 *
 * @note Key for the full file path of the resource file.
 */
FOUNDATION_EXPORT NMAMapViewCustomConfigurationFileKey const NMAMapViewResourceFileKey;

/**
 * Map Style Traffic File
 *
 * @note Key for the full file path of the traffic configuration file.
 */
FOUNDATION_EXPORT NMAMapViewCustomConfigurationFileKey const NMAMapViewTrafficConfigurationFileKey;

/**
 * Map Style Custom File
 *
 * @note Key for the full file path of the custom configuration file.
 */
FOUNDATION_EXPORT NMAMapViewCustomConfigurationFileKey const NMAMapViewCustomPreferenceConfigurationFileKey;


/**
 * Use this interface to set custom configurations
 *
 * @note This API should only be used in consultation with HERE technical support.
 */
@interface NMACustomConfigurations : NSObject

/**
 * Instances of this class should not be initialized. Call class methods only.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Sets a custom map style configuration.
 *
 * @note Setting of any type of configuration should be made before the HERE SDK is initialized.
 * NMAMapViewConfigurationFileKey config must always be set together with NMAMapViewResourceFileKey
 *
 * @param configFiles NSDictionary's keys that you can apply are NMAMapViewConfigurationFileKey,
 * NMAMapViewResourceFileKey, NMAMapViewTrafficConfigurationFileKey,
 * NMAMapViewCustomPreferenceConfigurationFileKey
 *
 * @return error `NMAMapStyleConfigurationErrorNone` if no error occured,
 * otherwise an error object of `NMAMapStyleConfigurationError` type indicating
 * the failure reason.
 *
 * @note the result of `NMAMapStyleConfigurationErrorNone` doesn't mean that
 * everything is good to go. If Map Style configuration or resource files cannot be used for some reason
 * the result of `NMAMapView` instantiation is nil. If an invalid traffic configuration is set
 * the results are undefined. Do not attempt to set a configuration file without consultation
 * with HERE technical support.
 */
+ (NMAMapStyleConfigurationError)setCustomConfiguration:(nonnull NSDictionary<NSString*, NSURL*> *)configFiles;

@end
