/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>

@class NMAGeoCoordinates;
@class NMAVenue3dAnimationParameters;
@class NMAVenue3dLevel;
@class NMAVenue3dSpace;
@class NMAVenue3dVenue;
@class NMAVenue3dBaseLocation;
@class NMAVenue3dStyleSettings;



/**
 * NMAVenue3dController encapsulates interactions of a viewable NMAVenue3dVenue. Methods of this class allow clients to
 * select and deselect levels and spaces.
 * 
 * This class can not be instantiated directly. Instead an instance of this class is returned by `NMAVenue3dMapLayer::venueController` or
 * `NMAVenue3dMapLayer::controllerForVenue:`.
 *
 * See also `NMAVenue3dMapLayer`
 */
@interface NMAVenue3dController : NSObject

/**
 * The NMAVenue3dVenue object this NMAVenue3dController is representing.
 */
@property (nonatomic, readonly, nonnull) NMAVenue3dVenue *venue;

/**
 * The NMAVenue3dLevel object representing groud level.
 */
@property (nonatomic, readonly, nonnull) NMAVenue3dLevel *groundLevel;

/**
 * Select a specific or access the selected NMAVenue3dLevel. The selected level is viewed as the topmost in the venue.
 * Levels on top of the selected level are hidden. Levels below the selected level are obscured by the level being selected.
 */
@property (nonatomic, weak, nullable) NMAVenue3dLevel *level;

/**
 * Select a specific or access the selected NMAVenue3dSpace inside NMAVenue3dVenue.
 * nil if no space is selected.
 *
 */
@property (nonatomic, weak, nullable) NMAVenue3dSpace *space;

/**
 * Deselect current NMAVenue3dSpace inside NMAVenue3dVenue.
 */
- (void)deselectSpace;

/**
 * The NMAVenue3dStyleSettings object representing styles for NMAVenue3dController.
 * Style settings can change visual representation of the venue, including colors for the
 * shape and the label, the name and the icon.
 * Default is nil (style settings are not specified).
 *
 */
@property (nonatomic, nullable) NMAVenue3dStyleSettings *styleSettings;

/**
 * Returns NMAVenue3dStyleSettings object for the specific space. Style settings can change visual representation
 * of the space, including colors for the shape and the label, the name and the icon.
 *
 * @param space  Space object for which style settings are applied.
 *
 * @return NMAVenue3dStyleSettings object for the specific space or nil if style settings are not set.
 *
 */
- (nullable NMAVenue3dStyleSettings *)getStyleSettingsForSpace:(nonnull NMAVenue3dSpace *)space
NS_SWIFT_NAME(styleSettings(for:));

/**
 * Sets NMAVenue3dStyleSettings object for the specific space. Style settings can change visual representation
 * of the space, including colors for the shape and the label, the name and the icon.
 *
 * @param settings  Style settings object.
 * @param space  Space object for which style settings will be applied.
 *
 */
- (void)setStyleSettings:(nullable NMAVenue3dStyleSettings *)settings forSpace:(nonnull NMAVenue3dSpace *)space
NS_SWIFT_NAME(setStyleSettings(_:for:));

/**
 * Returns the NMAVenue3dBaseLocation object based on the screen pixel coordinates.
 *
 * @param x  The horizontal screen pixel coordinate.
 * @param y  The vertivcal screen pixel coordinate.
 * @param preferSpace If YES and user clicked on the NMAVenue3dSpace, returns the NMAVenue3dSpaceLocation
 *                      object, otherwise returns the NMAVenue3dSpaceLocation object.
 * @return The NMAVenue3dLevelLocation or NMAVenue3dSpaceLocation object, if taps point is
 *         inside the venue, the NMAVenue3dOutdoorLocation object otherwise.
 *
 */
- (nullable NMAVenue3dBaseLocation *)getLocationAtX:(float)x
                                                  Y:(float)y
                                  WithSpacePrefered:(bool)preferSpace
NS_SWIFT_NAME(location(x:y:preferSpace:));

@end
