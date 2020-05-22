/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMAAudioOutput.h"

@class AVSpeechSynthesisVoice;



/**
 * A TTS audio output segment consisting of a single string.
 *
 * @note Audio output should never be played directly. Instead it should be passed
 * to the NMAAudioManager (via the playOutput method) to be played.
 */
@interface NMATTSAudioOutput : NMAAudioOutput

/**
 * Creates an NMATTSAudioOutput with the given text string.
 */
+ (nullable  instancetype)audioOutputWithText:(nonnull NSString *)text
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Initializes an NMATTSAudioOutput with the given text string.
 */
- (nullable  instancetype)initWithText:(nonnull NSString *)text
NS_SWIFT_NAME(init(_:));

/**
 * Must initalize with a text string.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Must initalize with a text string.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The text string to speak.
 */
@property (nonatomic, nonnull) NSString *text;

/**
 * The voice used to speak the text.
 *
 * @note By default, the voice will be selected based on the current locale of the device.
 */
@property (nonatomic, nonnull) AVSpeechSynthesisVoice *voice;

/**
 * The pitch multiplier with which the text is spoken.
 *
 * @note The default value is 1.0;
 */
@property (nonatomic) float pitchMultiplier;

/**
 * The speech rate at which the text is spoken.
 *
 * @note The default value is AVSpeechUtteranceDefaultSpeechRate.
 */
@property (nonatomic) float speechRate;

@end
