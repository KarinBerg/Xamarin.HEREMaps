/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoPolygon;
@class NMAIsolineComponentConnection;


/**
 * An isoline describes potential routes a user can take and provides a polygon indicating
 * the maximum reach in all directions around the given start position by time or distance.
 * An isoline may consist of several isolated components. This supports use cases where
 * the reachable area is disconnected by ferry links. All islands are returned as separate polygons
 * (components). Ferry links between these polygons are also returned as separate polyline
 * geometries (connections). The range reachable using ferries can be displayed as multiple
 * components (with or without connections) or even as a single component.
 */
@interface NMAIsoline : NSObject


/**
 * NMAIsoline is generated from isoline calculation.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * NMAIsoline is generated from isoline calculation.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Array of `NMAGeoPolygon` for all isoline components of the `NMAIsoline`.
 */
@property (nonatomic, readonly, nonnull) NSArray <NMAGeoPolygon *> *components;

/**
 * Array of `NMAIsolineComponentConnection` for all isoline connections of the `NMAIsoline`.
 */
@property (nonatomic, readonly, nonnull) NSArray <NMAIsolineComponentConnection *> *componentConnections;


@end
