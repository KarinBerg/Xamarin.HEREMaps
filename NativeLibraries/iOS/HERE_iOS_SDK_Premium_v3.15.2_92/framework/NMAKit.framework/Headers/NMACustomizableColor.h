#import "NMAZoomRange.h"
#import "NMACustomizableVariable.h"

@class UIColor;



/**
 * Represents a map customization color property with red, green, blue components ranging
 * from 0 to 255.
 */
@interface NMACustomizableColor : NMACustomizableVariable

/**
 * Instances of this class should not be initialized. Call class methods only.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Initializes a `NMACustomizableColor` defining its property, zoomLevel and
 * zoomRange.
 *
 * @param property The NMASchemeColorProperty representing the property type of customizable variable
 * @param zoomLevel The float representing the current zoom level
 * @param zoomRange The float representing the zoom range
 * @return The `NMACustomizableColor`
 */
- (nonnull instancetype)initWithColorProperty:(NMASchemeColorProperty)property
                                 andZoomLevel:(float)zoomLevel
                                 andZoomRange:(nullable NMAZoomRange *)zoomRange
NS_SWIFT_NAME(init(property:zoomLevel:zoomRange:));

/**
 * Red color component in range 0 to 255.
 */
@property (nonatomic) NSInteger red;

/**
 * Green color component in range 0 to 255.
 */
@property (nonatomic) NSInteger green;

/**
 * Blue color component in range 0 to 255.
 */
@property (nonatomic) NSInteger blue;

/**
 * Alpha color component in range 0 to 255.
 */
@property (nonatomic) NSInteger alpha;

/**
 * Utility method to configure the color from an UIColor object.
 *
 * @note This property is only relevant when SETTING a custom property
 * The alpha component of UIColor is not considered
 */
- (void)setColor:(nonnull UIColor *)color;

/**
 * Utility method to configure the color from an UIColor object.
 *
 * @note This property is only relevant when READING a custom property
 * The alpha component of the returned UIColor is always 1.
 */
- (nonnull UIColor *)color;

@end
