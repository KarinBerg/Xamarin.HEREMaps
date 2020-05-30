/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIColor.h>

#import "NMAMapObject.h"

@class NMAFTCRRoute;


/**
 * Represents a NMAMapObject in the shape of a route that can be displayed on a map.
 *
 * In order to display the route object on the map, the route object needs to be added to
 * an NMAMapView by calling addMapObject:.
 *
 * The NMAViewObject location property for a NMAMapFTCRRoute returns the coordinates of the
 * first waypoint.
 *
 * IMPORTANT: This is a Beta API, and is subject to change without notice.
 *
 * See also `NMAFTCRRoute`
 */
@interface NMAMapFTCRRoute : NMAMapObject

/**
 * Use initWithRoute to instantiate a NMAMapFTCRRoute.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * A constructor for NMAMapFTCRRoute.
 *
 * @param route The route object from which to construct the NMAMapFTCRRoute.
 */
- (nullable instancetype)initWithRoute:(nonnull NMAFTCRRoute *)route
NS_SWIFT_NAME(init(_:));

/**
 * The `UIColor` representing the color of the `NMAFTCRRoute`.
 *
 * @note Attempts to set this property to nil are ignored.
 */
@property (nonatomic, strong, nonnull) UIColor *color;

@end
