/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMACustomizableColor.h"

@class NMACustomizableVariable;


/**
 * Represents a Customizable scheme. Customizable schemes are obtained from `NMAMapView%` class
 * with getCustomizableSchemeWithName: or createCustomizableSchemeWithName: methods
 */
@interface NMACustomizableScheme : NSObject

/**
 * Use NMAMapView to obtain an instance of this class.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Retrieves a color property
 *
 * @param colorProperty The `NMASchemeColorProperty%` to retrieve.
 *
 * @note The zoom parameter takes a specific zoom level, and not a range.
 *
 * @return The `NMACustomizableColor%` object.
 */
- (nullable NMACustomizableColor *)colorForProperty:(NMASchemeColorProperty)colorProperty forZoomLevel:(float)zoomLevel
NS_SWIFT_NAME(colorForProperty(_:zoomLevel:));

/**
 * Sets a color property.
 *
 * @param variableColor The NMACustomizableColor.
 * @param zoomRange The zooom range to which the propety should be set to.
 */
- (void)setColorProperty:(nonnull NMACustomizableColor *)variableColor forZoomRange:(nonnull NMAZoomRange *)zoomRange
NS_SWIFT_NAME(setColorProperty(_:zoomRange:));

/**
 * Retrieve value of an Integer property
 *
 * @param integerProperty The `NMASchemeIntegerProperty%` to retrieve.
 *
 * @note The zoom parameter takes a specific zoom level, and not a range.
 *
 * @return The property value as int.
 */
- (int)integerForProperty:(NMASchemeIntegerProperty)integerProperty forZoomLevel:(float)zoomLevel
NS_SWIFT_NAME(integerProperty(_:zoomLevel:));

/**
 * Sets a property of Integer type.
 *
 * @param integerProperty The property to be modified.
 * @param zoomRange The zooom range to which the propety should be set to.
 */
- (void)setIntegerProperty:(NMASchemeIntegerProperty)integerProperty withValue:(int)value forZoomRange:(nonnull NMAZoomRange *)zoomRange
NS_SWIFT_NAME(setIntegerProperty(_:value:zoomRange:));

/**
 * Retrieve value of an Boolean property
 *
 * @param booleanProperty The `NMASchemeBooleanProperty%` to retrieve.
 *
 * @note The zoom parameter takes a specific zoom level, and not a range.
 *
 * @return The property value as bool.
 */
- (BOOL)booleanForProperty:(NMASchemeBooleanProperty)booleanProperty forZoomLevel:(float)zoomLevel
NS_SWIFT_NAME(booleanProperty(_:zoomLevel:));

/**
 * Sets a property of Boolean type.
 *
 * @param booleanProperty The property to be modified.
 * @param zoomRange The zooom range to which the propety should be set to.
 */
- (void)setBooleanProperty:(NMASchemeBooleanProperty)booleanProperty withValue:(BOOL)value forZoomRange:(nonnull NMAZoomRange *)zoomRange
NS_SWIFT_NAME(setBooleanProperty(_:value:zoomRange:));

/**
 * Retrieve value of a Float property
 *
 * @param floatProperty The `NMASchemeFloatProperty%` to retrieve.
 *
 * @note The zoom parameter takes a specific zoom level, and not a range.
 *
 * @return The property value as float.
 */
- (float)floatForProperty:(NMASchemeFloatProperty)floatProperty forZoomLevel:(float)zoomLevel
NS_SWIFT_NAME(floatForProperty(_:zoomLevel:));

/**
 * Sets a property of Float type.
 *
 * @param floatProperty The property to be modified.
 * @param zoomRange The zooom range to which the propety should be set to.
 */
- (void)setFloatProperty:(NMASchemeFloatProperty)floatProperty withValue:(float)value forZoomRange:(nonnull NMAZoomRange *)zoomRange
NS_SWIFT_NAME(setFloatProperty(_:value:zoomRange:));

/**
 * Returns the name of a customizable scheme object.
 *
 * @return name of customizable scheme or empty string if scheme is not valid.
 */
- (nonnull NSString *)name;

@end
