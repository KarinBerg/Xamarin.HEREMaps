/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMATransitRouteSupplier;


/**
 * Contains copyright notices that must be displayed to the end user when using
 * transit routing.
 *
 * Source attribution must be displayed together with a route. This requirement forms
 * part of the terms and conditions of the SDK.
 */
@interface NMATransitRouteSourceAttribution : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The source attribution information as an HTML-formatted string.
 */
@property (nonatomic, readonly, nullable) NSString *attribution;

/**
 * The suppliers of the transit information, represented as NMATransitRouteSupplier.
 *
 * See also `NMATransitRouteSupplier`
 */
@property (nonatomic, readonly, nullable) NSArray<NMATransitRouteSupplier *> *suppliers;

@end
