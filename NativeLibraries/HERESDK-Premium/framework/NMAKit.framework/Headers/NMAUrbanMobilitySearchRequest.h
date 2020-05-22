/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;


/**
 * This enum defines the possible values that can be set by the optional flags in an Urban Mobility requests.
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilitySearchOption) {
    /** Flag value is not set (unspecified) */
    NMAUrbanMobilitySearchOptionUnset = 0,
    /** Flag value is set to Yes */
    NMAUrbanMobilitySearchOptionYes   = 1,
    /** Flag value is set to No */
    NMAUrbanMobilitySearchOptionNo    = 2
} DEPRECATED_ATTRIBUTE;


/**
 *
 * Defines an Urban Mobility request to the HERE backend servers.
 *
 * NMAUrbanMobilitySearchRequest defines properties which are available for every request being made to the HERE backend servers.
 * Actual Urban Mobility requests are defined in `NMAUrbanMobilityCityCoverageRequest`, `NMAUrbanMobilityCitySearchRequest`
 * `NMAUrbanMobilityDepartureBoardRequest`, `NMAUrbanMobilityNearbyCoverageRequest` and `NMAUrbanMobilityStationSearchRequest`
 *
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * See also `NMAUrbanMobilityCityCoverageRequest`
 *
 * See also `NMAUrbanMobilityCitySearchRequest`
 *
 * See also `NMAUrbanMobilityDepartureBoardRequest`
 *
 * See also `NMAUrbanMobilityNearbyCoverageRequest`
 *
 * See also `NMAUrbanMobilityStationSearchRequest`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilitySearchRequest : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Limits number of results (inclusively) returned by the HERE backend server.
 *
 * @note The default value is 0 which means that it is up to the HERE backend server to decide.
 */
@property (nonatomic) NSInteger resultLimit;


@end
