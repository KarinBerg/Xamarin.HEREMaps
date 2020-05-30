/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARoutingMode.h"
#import "NMATransitRoutingOption.h"

/**
 * Contains options used when calculating a public transit route.
 */
@interface NMARoutingMode (NMATransitRoutingMode)

/**
 * The OR-ed `NMATransitRoutingOption` values.
 *
 * @note The default value is 0 (no options selected).
 */
@property (nonatomic) NMATransitRoutingOption transitRoutingOptions;

/**
 * The maximum number of vehicle changes allowed during the trip.
 */
@property (nonatomic) NSUInteger maximumChanges;

@end
