/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>



/**
 * Represents a handler of a route consumption model.
 *
 * A route consumption model is route-specific. It describes consumption
 * behaviour based on vehicle consumption parameters and the route's possible penalties.
 * This model is needed to provide accurate energy consumption results
 * when the route is calculated.
 *
 * An NMARouteConsumption can be reused for multiple calculations with the same route.
 *
 * IMPORTANT: Consumption calculation is a Beta feature. The related classes and
 * methods are subject to change without notice.
 *
 * @note You do not create instances of this class directly - use
 * -consumptionWithParameters:dynamicPenalty: on NMARoute instead.
 *
 * See also `NMARouteConsumptionParameters`
 *
 * See also `NMADynamicPenalty.`
 */
@interface NMARouteConsumption : NSObject

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**Ø
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Returns the consumption value according to the given route element index.
 * These indexes correspond to the indexes in the array of route elements returned by
 * `NMARoute.routeElements`.
 *
 * Returns zero when index is out of range or less then first available consumption
 * index (see `firstAvailableConsumptionIndex`).
 *
 * @param index Index of the route element.
 * @return Consumption value in capacity units if available, or 0 otherwise.
 */
- (NSInteger)getConsumptionWithIndex:(NSUInteger)index
NS_SWIFT_NAME(consumption(index:));

/**
 * Provides the index of the first element with consumption available. This index
 * corresponds to the indexes in the array of route elements returned by
 * `NMARoute.routeElements`.
 *
 * @return Index of the route element
 */
- (NSUInteger)firstAvailableConsumptionIndex;

@end
