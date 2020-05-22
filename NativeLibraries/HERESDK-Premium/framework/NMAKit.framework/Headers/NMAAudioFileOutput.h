/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMAAudioOutput.h"



/**
 * A collection of audio output consisting of one or more WAVE files.
 *
 * @note Audio output should never be played directly. Instead it should be passed
 * to the NMAAudioManager (via the playOutput method) to be played.
 */
@interface NMAAudioFileOutput : NMAAudioOutput

/**
 * Must initalize with a file list.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Must initalize with a file list.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Initialize an NMAAudioFileOutput instance with the given files.
 */
- (nullable instancetype)initWithFiles:(nonnull NSArray<NSString *> *)files
NS_SWIFT_NAME(init(_:)) NS_DESIGNATED_INITIALIZER;

/**
 * Creates an NMAAudioFileOutput with the given files.
 */
+ (nullable instancetype)audioOutputWithFiles:(nonnull NSArray<NSString *> *)files
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 *  If YES, the audio file(s) will be deleted when this object is destroyed.
 */
@property (nonatomic) BOOL deleteWhenFinished;

@end
