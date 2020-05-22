/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilityOperator.h"
@class NMARoute;
@class NMAUrbanMobilityOperator;
@class NMAUrbanMobilityLink;
@class NMAUrbanMobilityAlert;


/**
 * These are options which might not be taken into account when calculating the
 * `NMAUrbanMobilityRouteResult`. In other words, route calculations may give results that
 * violate the following options. Usually it depends on particular regions/countries.
 * By default all options are considered to be supported.
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_OPTIONS(NSUInteger, NMAUrbanMobilityViolatedOption) {
    /** Indicates if setting maximum walking distance was considered. */
    NMAUrbanMobilityViolatedOptionMaxWalkingDistance          NS_SWIFT_NAME(maxWalkingDistance) = 1 << 0,
    /** Indicates if setting walking speed was considered. */
    NMAUrbanMobilityViolatedOptionWalkSpeed                            NS_SWIFT_NAME(walkSpeed) = 1 << 1,
    /** Indicates if setting maximum number of changes was considered. */
    NMAUrbanMobilityViolatedOptionMaxChangesCount                NS_SWIFT_NAME(maxChangesCount) = 1 << 2,
    /** Indicates if restricting the TransportTpes  was considered. */
    NMAUrbanMobilityViolatedOptionRestrictTransportTypes  NS_SWIFT_NAME(restrictTransportTypes) = 1 << 3,
    /** Indicates if response contains only estimated routing data,
     *  due to license limitation.
     */
    NMAUrbanMobilityViolatedOptionEstimatedRouting              NS_SWIFT_NAME(estimatedRouting) = 1 << 4
} DEPRECATED_ATTRIBUTE;


/**
 * The Urban Mobility Route Result containing a result for a query.
 * Array of `NMAUrbanMobilityOperator`, `NMAUrbanMobilityLink` are related to
 * calculated array of `NMAUrbanMobilityRoute`.
 *
 * IMPORTANT: Urban Mobility routing is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityRouteResult : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Array of possible `NMAUrbanMobilityRoute`.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMARoute *> *routes;

/**
 * Gets error message string.
 *
 * @return error message string or nil.
 */
@property (nonatomic, readonly, nonnull) NSString *errorMessage;

/**
 * Array of `NMAUrbanMobilityOperator` which helped supply all calculated routes.
 * It's common array of unique `NMAUrbanMobilityOperator` that supply public transport for all calculated routes.
 * To find the operator for a particular `NMAUrbanMobilityRoute`, please see `NMAUrbanMobilityDeparture::NMAUrbanMobilityLine::transitOperator`.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityOperator *> *operators;

/**
 * Array of associated `NMAUrbanMobilityLink`.
 * It's a array of `NMAUrbanMobilityLink` that are available for all calculated routes.
 * To find the disclaimers for a particular `NMAUrbanMobilityRouteSection`, please see `NMAUrbanMobilityRoute::sections::operatorDisclaimers`.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityLink *> *operatorDisclaimers;

/**
 * Get alerts and disruptions associated with all calculated routes.
 * To find the alerts for a particular `NMAUrbanMobilityRouteSection`, please see `NMAUrbanMobilityRoute::sections::alerts`.
 * @return an array of `NMAUrbanMobilityAlert`.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAUrbanMobilityAlert *> *alerts;

/**
 * Indicates if it's possible to calculate subsequent route for given result.
 * Return YES if result can be used to calculate subsequent routes, NO otherwise.
 *
 * See also `NMAUrbanMobilityRouter`.
 */
@property (nonatomic, readonly, getter = isSubsequentRouteSupported) BOOL subsequentRouteSupported;

/**
 * Gets the violated options.
 *
 * @return NSUInteger bitmask representation of NMAUrbanMobilityViolatedOption or 0 if no options violated.
 */
@property (nonatomic, readonly) NMAUrbanMobilityViolatedOption violatedOptions;

@end
