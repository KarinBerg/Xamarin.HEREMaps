/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAUrbanMobilityStationSearchRequest;
@class NMAUrbanMobilityDepartureBoardRequest;
@class NMAUrbanMobilityMultiBoardRequest;
@class NMAUrbanMobilityStation;
@class NMAGeoCoordinates;
@class NMAUrbanMobilityCitySearchRequest;
@class NMAUrbanMobilityCityCoverageRequest;
@class NMAUrbanMobilityNearbyCoverageRequest;



/**
 * Defines a singleton which manages creation of requests to the HERE backend servers.
 *
 * `NMAUrbanMobilityRequestManager` is a singleton which provides convenient shortcuts for creation of `NMAUrbanMobilitySearchRequest` instances:
 * `NMAUrbanMobilityStationSearchRequest` to search for transit stations and `NMAUrbanMobilityDepartureBoardRequest` to request departure boards.
 *
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * See also `NMAUrbanMobilitySearchRequest`
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
@interface NMAUrbanMobilityRequestManager : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Returns the shared instance of `NMAUrbanMobilityRequestManager`.
 * No other instances should be created.
 */
+ (nonnull NMAUrbanMobilityRequestManager *)sharedRequestManager
NS_SWIFT_NAME(sharedInstance());

/**
 * Creates a new `NMAUrbanMobilityStationSearchRequest` to search for transit stations around a given location.
 *
 * Use optional properties to fine tune the search: searchRange, stationName, nameMatchingMethod
 *
 * @param location Geo coordinates to search for nearby transit stations around.
 * @return `NMAUrbanMobilityStationSearchRequest` which is ready to be executed.
 *
 * See also `NMAUrbanMobilityStationSearchRequest::startWithCompletionBlock:`
 */
- (nonnull NMAUrbanMobilityStationSearchRequest *)createStationSearchRequestWithLocation:(nonnull NMAGeoCoordinates *)location
NS_SWIFT_NAME(createStationSearchRequest(withLocation:));

/**
 * Creates a new `NMAUrbanMobilityStationSearchRequest` to search for transit stations with given IDs.
 *
 * @param stationIds Array of transit station IDs to search for.
 * @return `NMAUrbanMobilityStationSearchRequest` which is ready to be executed.
 *
 * See also `NMAUrbanMobilityStationSearchRequest::startWithCompletionBlock:`
 */
- (nonnull NMAUrbanMobilityStationSearchRequest *)createStationSearchRequestWithIds:(nonnull NSArray<NSString *> *)stationIds
NS_SWIFT_NAME(createStationSearchRequest(withIds:));

/**
 * Creates a new `NMAUrbanMobilityMultiBoardRequest` for a multi departure board from given location.
 *
 * @param location Geo coordinates to search all stations around.
 * @return `NMAUrbanMobilityMultiBoardRequest` which is ready to be executed.
 *
 * See also `NMAUrbanMobilityMultiBoardRequest::startWithCompletionBlock:`
 */
- (nonnull NMAUrbanMobilityMultiBoardRequest *)createMultiBoardRequestWithLocation:(nonnull NMAGeoCoordinates *)location
NS_SWIFT_NAME(createMultiBoardRequest(withLocation:));

/**
 * Creates a new `NMAUrbanMobilityMultiBoardRequest` to search only by Station IDs.
 *
 * @param stationIds Array of station IDs to search for.
 * @return `NMAUrbanMobilityMultiBoardRequest` which is ready to be executed.
 *
 * See also `NMAUrbanMobilityMultiBoardRequest::startWithCompletionBlock:`
 */
- (nonnull NMAUrbanMobilityMultiBoardRequest *)createMultiBoardRequestWithStationIds:(nonnull NSArray<NSString *> *)stationIds
NS_SWIFT_NAME(createMultiBoardRequest(withStationIds:));

/**
 * Creates a new `NMAUrbanMobilityDepartureBoardRequest` for a departure board at a transit station with a given ID and given geo coordinates.
 *
 * @note Both station ID and geo coordinates are required to identify a transit station unambiguously.
 *
 * @param stationId Transit station ID.
 * @param location Geo coordinates of the transit station.
 * @return `NMAUrbanMobilityDepartureBoardRequest` which is ready to be executed.
 *
 * See also `NMAUrbanMobilityDepartureBoardRequest::startWithCompletionBlock:`
 */
- (nonnull NMAUrbanMobilityDepartureBoardRequest *)createDepartureBoardRequestWithStationId:(nonnull NSString *)stationId
                                                                                   location:(nonnull NMAGeoCoordinates *)location
NS_SWIFT_NAME(createDepartureBoardRequest(withStationId:location:));

/**
 * Creates a new `NMAUrbanMobilityCitySearchRequest` for search for public transit coverage by city.
 *
 * @param cityName - string used to search.
 * @return `NMAUrbanMobilityCitySearchRequest` which is ready to be executed.
 *
 * See also `NMAUrbanMobilityCitySearchRequest::startWithCompletionBlock:`
 */
- (nonnull NMAUrbanMobilityCitySearchRequest *)createCitySearchRequestWithCity:(nonnull NSString *)cityName
NS_SWIFT_NAME(createCitySearchRequest(withCity:));

/**
 * Creates a new `NMAUrbanMobilityCityCoverageRequest` used to get a list of cities where were have transit coverage,
 * as well as list of transit operators, from a given location, within a certain radius.
 *
 * @return `NMAUrbanMobilityCityCoverageRequest` which is ready to be executed.
 *
 * See also `NMAUrbanMobilityCityCoverageRequest::startWithCompletionBlock:`
 */
- (nonnull NMAUrbanMobilityCityCoverageRequest *)createCityCoverageRequest;

/**
 * Creates a new `NMAUrbanMobilityNearbyCoverageRequest` used for retrieve coverage information about nearby cities.
 *
  * @param location Geo coordinates of the entry point used to search.
 * @return `NMAUrbanMobilityNearbyCoverageRequest` which is ready to be executed.
 *
 * See also `NMAUrbanMobilityNearbyCoverageRequest::startWithCompletionBlock:`
 */
- (nonnull NMAUrbanMobilityNearbyCoverageRequest *)createNearbyCoverageRequestForLocation:(nonnull NMAGeoCoordinates *)location
NS_SWIFT_NAME(createNearbyCoverageRequest(withLocation:));

@end
