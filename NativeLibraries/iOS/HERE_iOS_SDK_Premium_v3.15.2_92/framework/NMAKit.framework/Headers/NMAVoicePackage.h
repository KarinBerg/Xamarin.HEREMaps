/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * Defines the gender types of the voice package.
 */
typedef NS_ENUM(NSUInteger, NMAVoiceGender)
{
    /**
     * Female voice
     */
    NMAVoiceGenderFemale,
    /**
     * Male voice
     */
    NMAVoiceGenderMale,
    /**
     * Female or Male voice
     */
    NMAVoiceGenderBoth,
    /**
     * Unknown gender for the voice
     */
    NMAVoiceGenderUnknown
};


/**
 * Return information about voice packages.
 * Used in NMAVoiceCatalog.
 */
@interface NMAVoicePackage : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Id of the voice package.
 */
@property (nonatomic, readonly) NSUInteger packageId;

/**
 * Name of the voice package localized to the package locale, nil if not available.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * Gender of the voice package.
 */
@property (nonatomic, readonly) NMAVoiceGender gender;

/**
 * Language of the installed voice package in English, nil if the voice package is not installed.
 */
@property (nonatomic, readonly, nullable) NSString *language;

/**
 * Language of the voice package localized to the package locale, nil if it is not available.
 */
@property (nonatomic, readonly, nullable) NSString *localizedLanguage;

/**
 * The BCP-47 language code representing the language of the package, nil if voice
 * package is not available or BCP-47 language tag could not be found.
 */
@property (nonatomic, readonly, nullable) NSString *languageCode;

/**
 * Check if the voice package needs to be updated. YES if the installed voice package and the
 * voice package from the server in the voice catalog have different versions; NO otherwise
 */
@property (nonatomic, readonly, getter = isUpdateAvailable) BOOL updateAvailable;

/**
 * Check if the voice package is installed. YES if installed; NO otherwise.
 */
@property (nonatomic, readonly, getter = isInstalled) BOOL installed;

/**
 * Size of the package after download to device, in number of megabytes
 *
 * Returns -1 if the package is not available for download
 */
@property (nonatomic, readonly) float downloadSize;

/**
 * Size of the package after unzipping to device, in number of megabytes
 */
@property (nonatomic, readonly) float installationSize;

/**
 * Indicates whether the voice package can be uninstalled. YES if can be uninstalled; NO otherwise
 */
@property (nonatomic, readonly, getter = isRemovable) BOOL removable;

/**
 * Indicate the quality of the voice if it is available; nil if voice quality is not available
 */
@property (nonatomic, readonly, nullable) NSString *quality;

/**
 * Check if the voice package is a Text-to-Speech voice package.
 *
 * @note If this property returns YES you are advised to check whether to TTS language is supported
 * on the current device. See ttsLanguageAvailable.
 */
@property (nonatomic, readonly, getter = isTts) BOOL tts;

/**
 * Indicates whether this voice package is supported by AVSpeechSynthesizer.
 *
 * AVSpeechSynthesizer support can differ between devices and iOS versions so, if this package is a
 * TTS package, it is advisable to check this property before downloading the package.
 */
@property (nonatomic, readonly, getter = isTtsLanguageAvailable) BOOL ttsLanguageAvailable;

/**
 * The localized description of the gender for this voice package, nil if it is not available.
 */
@property (nonatomic, readonly, nullable) NSString *localizedGender;

/**
 * The localized description of the quality for this voice package, nil if it is not available.
 */
@property (nonatomic, readonly, nullable) NSString *localizedQuality;

/**
 * The localized description of the type of this voice package, nil if it is not available.
 */
@property (nonatomic, readonly, nullable) NSString *localizedType;

/**
 * The international MARC code describing the language of the voice package (see
 * http://www.loc.gov/marc/languages).
 */
@property (nonatomic, readonly, nullable) NSString *marcCode;

/**
 * The voice package version.
 */
@property (nonatomic, readonly, nullable) NSString *version;

/**
 * The custom attributes of this voice package, nil if not available.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, NSString *> *customAttributes;

@end
