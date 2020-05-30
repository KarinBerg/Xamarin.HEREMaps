/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>

@class NMAImage;
@class NMASignpostLocalizedLabel;


/**
 * Represents a signpost information for navigation (both audible and
 * graphical/textual navigation) and map display.
 */
@interface NMASignpost : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 *  The foreground/text color of the exit icon for the signpost.
 */
@property (nonatomic, readonly, nonnull) UIColor *foregroundColor;

/**
 *  The background color of the exit icon for the signpost
 */
@property (nonatomic, readonly, nonnull) UIColor *backgroundColor;

/**
 *  An array of exit directions applicable to the signpost, defined
 * as NMASignpostLocalizedLabel objects.
 *
 * See also `NMASignpostLocalizedLabel`
 */
@property (nonatomic, readonly, nonnull) NSArray<NMASignpostLocalizedLabel *> *exitDirections;

/**
 *  The exit icon of the signpost.
 */
@property (nonatomic, readonly, nullable) NMAImage *exitIcon;

/**
 *  The exit number of the signpost.
 */
@property (nonatomic, readonly, nullable) NSString *exitNumber;

/**
 *  The exit text of the signpost.
 */
@property (nonatomic, readonly, nullable) NSString *exitText;

@end
