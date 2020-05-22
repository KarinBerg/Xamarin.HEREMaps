/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Events which occur during the lifecycle of an NMAAudioOutput.
 */
typedef NS_ENUM(NSInteger, NMAAudioOutputEvent) {
    /** The audio output started. */
    NMAAudioOutputBegan NS_SWIFT_NAME(began),
    /** The audio output skipped. */
    NMAAudioOutputSkipped NS_SWIFT_NAME(skipped),
    /** The audio output ended. */
    NMAAudioOutputEnded NS_SWIFT_NAME(ended)
};

/**
 * Sources of audio output in the Here SDK.
 */
typedef NS_ENUM(NSInteger, NMAAudioOutputSource) {
    /** The source of the output is not known. */
    NMAAudioOutputSourceUnknown,
    /** The SDK user is the source of the output. */
    NMAAudioOutputSourceUser,
    /** The output is from turn-by-turn guidance. */
    NMAAudioOutputSourceGuidance
};

/**
 * A block interface for responding to NMAAudioOutput lifecycle events.
 */
typedef void (^NMAAudioOutputEventBlock)(NMAAudioOutputEvent event);


/**
 * A single segment of audio output.
 *
 * NMAAudioOutput represents one cohesive segment of audio output; for example,
 * a single sentence of TTS output or a single audio file. It is used with the
 * NMAAudioManager to play audio in an application.
 *
 * NMAAudioOutput is an abstract base class and should not be directly instantiated.
 * Instead, subclasses which implement the required interface functions should be
 * used.
 *
 * For convenience, the NMAAudioFileOutput and NMATTSAudioOutput classes have been
 * created for basic audio output functionality.
 *
 * See also `NMAAudioFileOutput`
 *
 * See also `NMATTSAudioOutput`
 *
 * See also `NMAAudioManager`
 */
@interface NMAAudioOutput : NSObject

/**
 * This is an abstract base class. Instances of this class should not be initialized
 * directly.
 */
- (nonnull instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * A block which provides user-defined behaviour in response to lifecycle events.
 *
 * The event block is typically defined by the object which created the audio output.
 * It can be used for example to notify a listener when a given audio output starts
 * and finishes.
 *
 * The NMAAudioOutputEvent enum defines the types of events for which the block is
 * called.
 *
 * See also `NMAAudioOutputEvent`
 */
@property (nonatomic, strong, nullable) NMAAudioOutputEventBlock eventBlock;

/**
 * The source of the audio output.
 *
 * Audio output objects created by the application should use NMAAudioOutputSourceUser.
 */
@property (nonatomic) NMAAudioOutputSource source;

/**
 * The playback volume in the range 0 to 1.0
 *
 * This volume may be used to adjust volume level relative to other audio sources on the
 * device (e.g. the music player) or within the application.
 *
 * Defaults to 1.0 (full volume).
 *
 * Subclasses should implement this method to adjust their volume appropriately. The super
 * implementation may be called to clamp to the volume to the range 0 to 1.0.
 *
 * @note This volume is applied as a multiplier to the "App" volume maintained by the OS.
 * The latter can only be controlled by the physical volume keys or the iOS MPVolumeView
 * UIControl.
 */
@property (nonatomic) float volume;

/**
 * Plays the audio output.
 *
 * @note Subclasses must implement this method and call the super implementation at
 * the beginning of the method.
 */
- (void)play;

/**
 * Stops the audio output.
 *
 * @note Subclasses must implement this method and call the super implementation at
 * the end of the method.
 */
- (void)stop;

@end
