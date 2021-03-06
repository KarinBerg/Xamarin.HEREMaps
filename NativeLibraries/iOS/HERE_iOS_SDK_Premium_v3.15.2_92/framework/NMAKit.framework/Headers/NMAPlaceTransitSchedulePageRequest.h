/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARequest.h"


/**
 * Represents an extended `NMARequest` used to retrieve a NMAPlaceTransitSchedulePage
 * information associated with a NMAPlace, by way of Places search services.
 *
 * @note The response to a `NMAPlaceTransitSchedulePageRequest` is a
 * NMAPlaceTransitSchedulePage object.
 */
@interface NMAPlaceTransitSchedulePageRequest : NMARequest

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
