/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoPolyline;


/**
 * An isoline describing an area with multiple components, where each component can have
 * connections to other components.
 */
@interface NMAIsolineComponentConnection : NSObject

/**
 * NMAIsoline is generated from isoline calculation.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * * NMAIsoline is generated from isoline calculation.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * First isoline component index.
 */
@property (nonatomic) NSUInteger from;

/**
 * Second isoline component index.
 */
@property (nonatomic) NSUInteger to;

/**
 * Polygon describing the shape of connection of two isoline components.
 */
@property (nonatomic, nonnull, readonly) NMAGeoPolyline *shape;


@end
