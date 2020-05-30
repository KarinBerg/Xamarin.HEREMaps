/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class UIColor;
@class NMAImage;



/**
 * Defines style settings for venue and space objects.
 *
 * See also `NMAVenue3dController`
 */
@interface NMAVenue3dStyleSettings : NSObject

/**
* The fill color of the object.
*/
@property (nonatomic, readwrite, nullable) UIColor *fillColor;

/**
 * The outline color of the object.
 */
@property (nonatomic, readwrite, nullable) UIColor *outlineColor;

/**
 * The fill color of the object in the selected state.
 */
@property (nonatomic, readwrite, nullable) UIColor *selectedFillColor;

/**
 * The outline color of the object in the selected state.
 */
@property (nonatomic, readwrite, nullable) UIColor *selectedOutlineColor;

/**
 * The string which is shown in the label of the object.
 */
@property (nonatomic, readwrite, nullable) NSString *labelName;

/**
 * The image which is shown with the label of the object.
 */
@property (nonatomic, readwrite, nullable) NMAImage *labelImage;

/**
 * The fill color of the label text of the object.
 */
@property (nonatomic, readwrite, nullable) UIColor *labelFillColor;

/**
 * The outline color of the label text of the object.
 */
@property (nonatomic, readwrite, nullable) UIColor *labelOutlineColor;

@end
