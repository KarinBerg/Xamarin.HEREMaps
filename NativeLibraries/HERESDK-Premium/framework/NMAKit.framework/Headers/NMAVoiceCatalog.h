/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAVoicePackage.h"

@class NMAVoiceCatalog;

/**
 * The VoiceCatalog API error domain.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAVoiceCatalogErrorDomain;

/**
 * VoiceCatalog Errors.
 */
typedef NS_ENUM(NSUInteger, NMAVoiceCatalogError) {
    NMAVoiceCatalogErrorNone,
    /**
     * General error
     *
     * @note This is also returned for network related errors such as no connectivity.
     */
    NMAVoiceCatalogErrorUnknown,
    NMAVoiceCatalogErrorNotFound,
    NMAVoiceCatalogErrorInvalidOperation,
    NMAVoiceCatalogErrorInvalidParameters,
    NMAVoiceCatalogErrorFileOpen,
    NMAVoiceCatalogErrorDownloadNotReady,
    NMAVoiceCatalogErrorVoiceLoadingFailed,
    NMAVoiceCatalogErrorMissingMandatoryFields,
    NMAVoiceCatalogErrorOutOfMemory,
    NMAVoiceCatalogErrorCancelled
};

/**
 * Delegate to handle NMAVoiceCatalog Download notifications
 *
 * @note Methods of this protocol are called on the main thread.
 */
@protocol NMAVoiceCatalogDelegate<NSObject>

@optional

/**
 * Sent when a voice catalog update request completes
 *
 * This method will be called whether the update succeeds, fails or is cancelled
 *
 * See [NMAVoiceCatalog updateVoiceCatalog] and [NMAVoiceCatalog cancel]
 *
 * @param voiceCatalog The NMAVoiceCatalog singleton
 * @param error nil if the request completed successfully otherwise an NSError populated with an NMAVoiceCatalogError
 *              error code and a domain of NMAVoiceCatalogErrorDomain
 */
- (void)voiceCatalog:(nonnull NMAVoiceCatalog *)voiceCatalog didUpdateWithError:(nullable NSError *)error
NS_SWIFT_NAME(voiceCatalog(_:didUpdate:));

/**
 * Sent when a voice package installation request completes
 *
 * This method will be called whether the installation succeeds, fails or is cancelled
 *
 * See [NMAVoiceCatalog installVoicePackage:] and [NMAVoiceCatalog cancel]
 *
 * @param voiceCatalog The NMAVoiceCatalog singleton
 * @param package The NMAVoicePackage being installed
 * @param error nil if the request completed successfully otherwise an NSError populated with an NMAVoiceCatalogError
 *              error code and a domain of NMAVoiceCatalogErrorDomain
 */
- (void)voiceCatalog:(nonnull NMAVoiceCatalog *)voiceCatalog didInstallPackage:(nonnull NMAVoicePackage *)package withError:(nullable NSError *)error;

/**
 *  NMAVoicePackage download progress, called multiple times
 *
 * See [NMAVoiceCatalog installVoicePackage:]
 *
 * @param voiceCatalog The NMAVoiceCatalog singleton.
 * @param progress The progress of the current operation from [0:100].
 * @param package The NMAVoicePackage being downloaded.
 */
- (void)voiceCatalog:(nonnull NMAVoiceCatalog *)voiceCatalog didUpdateProgress:(float)progress forPackage:(nonnull NMAVoicePackage *)package
NS_SWIFT_NAME(voiceCatalog(_:didUpdateDownloadProgress:for:));


/**
 *  NMAVoicePackage uncompress progress, called multiple times
 *
 * See [NMAVoiceCatalog installVoicePackage:]
 *
 * @param voiceCatalog The NMAVoiceCatalog singleton.
 * @param progress The progress of the current operation from [0:100].
 * @param package The NMAVoicePackage being uncompressed.
 */
- (void)voiceCatalog:(nonnull NMAVoiceCatalog *)voiceCatalog didUncompressProgress:(float)progress forPackage:(nonnull NMAVoicePackage *)package
NS_SWIFT_NAME(voiceCatalog(_:didUpdateUncompressProgress:for:));

@end


/**
 *
 * Used to manage voice packages for guided navigation.
 *
 * The voice catalog can be used to manage or access the voice packages currently
 * installed on the device. It can also be used to install new voice packages.
 *
 * This class returns nil if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * See also `NMAVoiceCatalogDelegate`
 */
@interface NMAVoiceCatalog : NSObject

/**
 * Returns the NMAVoiceCatalog singleton instance.
 *
 * @note Use this method to obtain a NMAVoiceCatalog instance.
 *
 * @return shared NMAVoiceCatalog instance
 */
+ (nullable NMAVoiceCatalog *)sharedVoiceCatalog
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
 * The voice catalog delegate
 */
@property (nonatomic, weak, nullable) id<NMAVoiceCatalogDelegate> delegate;

/**
 * YES if the voice catalog is currently busy, NO otherwise.
 *
 * @note The voice catalog can only perform one operation at a time.
 */
@property (nonatomic, readonly, getter = isBusy) BOOL busy;

/**
 * Array of NMAVoicePackage objects currently installed on the device.
 *
 * This is a subset of the voicePackages property.
 *
 * @note There will be one voice packages installed by default, which is English US.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAVoicePackage*> *installedVoicePackages;

/**
 * Array of NMAVoicePackage objects that are either installed or available for installation via
 * download from the voice catalog server.
 *
 * Important: Only installed voice packages maybe used during navigation, see the installedVoicePackages
 * property.
 *
 * @note If the voice catalog has not been downloaded yet this property will only contain the default
 * pre-installed packages. The catalog may be updated by calling updateVoiceCatalog.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAVoicePackage*> *voicePackages;

/**
 *  The date when the NMAVoiceCatalog was last updated.
 *
 * nil if the voice catalog has not been downloaded yet
 */
@property (nonatomic, readonly, nullable) NSDate *lastUpdate;

/**
 * Update the voice catalog by downloading data from the server
 *
 * On a successful update the voicePackages, installedVoicePackages and lastUpdate properties will be
 * modified.
 *
 * @return YES if the request was successfully issued (see [NMAVoiceCatalogDelegate voiceCatalog:didUpdateWithError:]
 * for the result of the update). NO if the request failed to be issued (no NMAVoiceCatalogDelegate methods will be
 * called)
 */
- (BOOL)updateVoiceCatalog;

/**
 *  Get a voice package instance
 *
 * @param packageId the identifier of the package
 * @return NMAVoicePackage instance if found, nil otherwise
 */
- (nullable NMAVoicePackage *)voicePackageWithId:(NSUInteger)packageId;

/**
 * Downloads and installs a NMAVoicePackage to the device
 *
 * Uninstalls the voice package if already installed before downloading the updated version.
 *
 * @param package Package to be downloaded/updated
 * @return YES if the request was successfully issued (see [NMAVoiceCatalogDelegate voiceCatalog:didInstallPackage:withError:]
 * for the result of the update). NO if the request failed to be issued (no NMAVoiceCatalogDelegate methods will be
 * called)
 */
- (BOOL)installVoicePackage:(nonnull NMAVoicePackage *)package;

/**
 *  Delete a particular NMAVoicePackage from the device.
 *
 * @param package Package to be uninstalled.
 * @returns NO if not installed or if the package is non-removable
 */
- (BOOL)uninstallVoicePackage:(nonnull NMAVoicePackage *)package;

/**
 * Cancels the current voice catalog update or voice package installation
 *
 * If there are no outstanding requests this method does nothing.
 *
 * If there is an outstanding request then the request will be completed (delegate method called) with
 * an error code of NMAVoiceCatalogErrorCancelled
 */
- (void)cancel;

@end
