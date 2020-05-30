/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


#import <Foundation/Foundation.h>


/**
 * Localized signpost information used for navigation (both audible and
 * graphical/textual) and map display.
 *
 * In Europe, the label text is most relevant for guidance, while in the North
 * America, both route name and direction information are most relevant.
 */
@interface NMASignpostLocalizedLabel : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 *  The three letter MARC code for the label language.
 */
@property (nonatomic, readonly, nullable) NSString *language;

/**
 * Auxiliary information for the label.
 *
 * Typically the auxiliary information contains a destination name such as a city or
 * a characteristic place (e.g. "airport").
 */
@property (nonatomic, readonly, nullable) NSString *text;

/**
 * The route name/number of the label.
 *
 * Since the origin data is not always consistent it is recommended to concatenate the
 * route name and route direction fields. For example, in some cases the direction is
 * already contained in the route name and in others it is not.
 */
@property (nonatomic, readonly, nullable) NSString *routeName;

/**
 *  The cardinal direction for the label.
 */
@property (nonatomic, readonly, nullable) NSString *routeDirection;

@end
