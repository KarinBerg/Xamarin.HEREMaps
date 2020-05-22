/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilitySearchRequest.h"
@class NMAGeoCoordinates;
@class NMAUrbanMobilityStation;

/**
 * Name matching mode which is used when searching for transit stations.
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilitySearchNameMatchingMethod) {
    /** Search mode is not specified: up to the HERE backend server to decide. */
    NMAUrbanMobilitySearchNameMatchingMethodUnspecified = 0,

    /** Strict name match mode: names should be strictly equal. */
    NMAUrbanMobilitySearchNameMatchingMethodStrict      = 1,

    /** Fuzzy name match mode: names are allowed to be slightly different. */
    NMAUrbanMobilitySearchNameMatchingMethodFuzzy       = 2
} DEPRECATED_ATTRIBUTE;

/**
 * Defines a callback which is triggered on the completion of a station search request.
 * The resulting callback contains an array of `NMAUrbanMobilityStation` or `NSError`.
 *
 * NMAUrbanMobilityStationSearchCompletionBlock is used with
 * NMAUrbanMobilityStationSearchRequest::startWithCompletionBlock:
 * to provide a callback for capturing responses from the HERE backend server.
 *
 * @param stations Array of `NMAUrbanMobilityStation` returned by the HERE backend server.
 * @param error An error which occurred when searching for transit stations. Error codes are defined in `NSError`.
 *
 * See also `NMAUrbanMobilityStationSearchRequest::startWithCompletionBlock:`
 *
 * See also `NMAUrbanMobilityStation`
 *
 * See also `NSError`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
typedef void (^NMAUrbanMobilityStationSearchCompletionBlock)(NSArray<NMAUrbanMobilityStation *> * _Nullable stations, NSError * _Nullable error);


/**
 *
 * Represents a request to search for transit station nearby a given location.
 *
 * NMAUrbanMobilityStationSearchRequest assembles and issues requests to the HERE backend server
 * by providing either a location (with some extra optional properties) or an array of specific station IDs which needs to be found.
 *
 * The HERE backend server responds with either an array of `NMAUrbanMobilityStation` objects or `NSError` if something goes wrong.
 * Use `NMAUrbanMobilityStationSearchCompletionBlock` to capture the response.
 *
 * See also `NMAUrbanMobilityStationSearchCompletionBlock`
 *
 * See also `NMAUrbanMobilityStation`
 *
 * See also `NMAUrbanMobilityError`
 *
 * IMPORTANT: Urban Mobility Station Search is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityStationSearchRequest : NMAUrbanMobilitySearchRequest

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Creates a new `NMAUrbanMobilityStationSearchRequest` to search for transit stations around a given location.
 *
 * Use optional properties to fine tune the search: searchRange, stationName, nameMatchingMethod
 *
 * @param location Geo coordinates to search for nearby transit stations around.
 */
- (nonnull instancetype)initWithLocation:(nonnull NMAGeoCoordinates *)location
NS_SWIFT_NAME(init(location:));

/**
 * Creates a new `NMAUrbanMobilityStationSearchRequest` to search for transit stations with given IDs.
 *
 * @param stationIds Array of transit station IDs to search for.
 */
- (nonnull instancetype)initWithStationIds:(nonnull NSArray<NSString *> *)stationIds
NS_SWIFT_NAME(init(stationIds:));

/**
 * Sends the request to search for transit stations to the HERE backend server.
 * Request processing is performed asynchronously: `NMAUrbanMobilityStationSearchCompletionBlock` is used to pass the response.
 *
 * @param completion `NMAUrbanMobilityStationSearchCompletionBlock` which is used to pass the response.
 * @return YES if the request was triggered successfully, NO otherwise.
 *
 * @note `NMAUrbanMobilityStationSearchCompletionBlock` is called on the main queue.
 *
 * See also `NMAUrbanMobilityStationSearchCompletionBlock`
 */
- (BOOL)startWithCompletionBlock:(nonnull NMAUrbanMobilityStationSearchCompletionBlock)completion
NS_SWIFT_NAME(start(_:));

/**
 * Array of transit station IDs to search for.
 *
 * @note If station ID array is specified then all other request options (e.g. location) will have no effect.
 */
@property (nonatomic, readonly, nullable) NSArray<NSString *> *stationIds;

/**
 * Geo coordinates to search for nearby stations around.
 *
 * @note Search range is controlled with searchRange property.
 */
@property (nonatomic, readonly, nullable) NMAGeoCoordinates *location;

/**
 * Range in meters which is used to search for nearby transit stations around a given location.
 *
 * @note Default value is 0 which means the HERE backend server default.
 */
@property (nonatomic) NSUInteger searchRange;

/**
 * Name which is used to match nearby station names.
 * Matching strictness is controlled by nameMatchingMethod property.
 *
 * @note Default value is the empty string which means that station names are not accounted during the search.
 */
@property (nonatomic, nullable) NSString *stationName;

/**
 * Name matching method defines the fuzziness of the name matching.
 * `NMAUrbanMobilitySearchNameMatchingMethodStrict` means that names must be strictly equal to get matched.
 * `NMAUrbanMobilitySearchNameMatchingMethodFuzzy` allows some difference between names being matched.
 *
 * @note Default value is NMAUrbanMobilitySearchNameMatchingMethodUnspecified which means that it is up to the HERE backend server to decide.
 *
 */
@property (nonatomic) NMAUrbanMobilitySearchNameMatchingMethod nameMatchingMethod;

@end
