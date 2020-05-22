/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilitySearchRequest.h"

@class NMAUrbanMobilityStation;
@class NMAGeoCoordinates;
@class NMAUrbanMobilityDeparture;

/**
 * Defines a callback that is triggered upon the completion of a departure board request.
 *        The resulting completion block contains a list of `NMAUrbanMobilityDeparture` or `NSError`.
 *
 * NMAUrbanMobilityDepartureBoardCompletionBlock is used with
 * NMAUrbanMobilityDepartureBoardRequest::startWithCompletionBlock:
 * to provide a callback for capturing responses from the HERE backend server.
 *
 * @param departures List of `NMAUrbanMobilityDeparture` returned by the HERE backend server.
 * @param error An error which occurred when requesting a departure board. Error codes are defined in `NSError`.
 *
 * See also `NMAUrbanMobilityDeparture`
 *
 * See also `NSError`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
typedef void (^NMAUrbanMobilityDepartureBoardCompletionBlock)(NSArray<NMAUrbanMobilityDeparture *> * _Nullable departures, NSError * _Nullable error);


/**
 *
 * Represents a request to retrieve a departure board for the given transit station.
 *
 * NMAUrbanMobilityDepartureBoardRequest assembles and issues requests to the HERE backend server
 * by providing a station ID, a geo location and some optional properties (such as whether to do a fuzzy search).
 *
 * The HERE backend server responds with either a list of `NMAUrbanMobilityDeparture` objects or NSError if something goes wrong.
 * Use `NMAUrbanMobilityDepartureBoardCompletionBlock` to capture the response.
 *
 * See also `NMAUrbanMobilityDepartureBoardCompletionBlock`
 *
 * See also `NMAUrbanMobilityDeparture`
 *
 * IMPORTANT: Urban Mobility Departure Board is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityDepartureBoardRequest : NMAUrbanMobilitySearchRequest

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Creates a new `NMAUrbanMobilityDepartureBoardRequest` for a departure board at a transit station with a given ID and given geo coordinates.
 *
 * @param stationId The unique ID of the transit station.
 * @param location Geo coordinates of the transit station.
 *
 * @note Both station ID and geo coordinates are required to identify a transit station unambiguously.
 */
- (nonnull instancetype)initWithStationId:(nonnull NSString *)stationId location:(nonnull NMAGeoCoordinates *)location
NS_SWIFT_NAME(init(stationId:location:));

/**
 * Sends the request to retrieve a departure board to the HERE backend server.
 * Request processing is performed asynchronously: `NMAUrbanMobilityDepartureBoardCompletionBlock` is used to pass the response.
 *
 * @param completion `NMAUrbanMobilityDepartureBoardCompletionBlock` which is used to pass the response.
 * @return YES if the request was triggered successfully, NO otherwise.
 *
 * @note `NMAUrbanMobilityDepartureBoardCompletionBlock` is called on the main queue.
 *
 * See also `NMAUrbanMobilityDepartureBoardCompletionBlock`
 */
- (BOOL)startWithCompletionBlock:(nonnull NMAUrbanMobilityDepartureBoardCompletionBlock)completion
NS_SWIFT_NAME(start(_:));

/**
 * The unique ID of the transit station where the departure board is being requested.
 */
@property (nonatomic, readonly, nonnull) NSString *stationId;

/**
 * Geo coordinates of the station which departure board is being requested.
 */
@property (nonatomic, readonly, nonnull) NMAGeoCoordinates *location;

/**
 * Time which is used as a start point for the departure board being requested.
 * All entries in the departure board are the earliest possible departures after the specified time.
 *
 * @note If this property is not set then the current timestamp is used.
 */
@property (nonatomic, nullable) NSDate *departureTime;

/**
 * If set to `NMAUrbanMobilitySearchOptionalFlagNo` departures from the nearby stations will also be included in the response.
 *
 * @note The default value is `NMAUrbanMobilitySearchOptionUnset` which means that it is up to the HERE backend server to decide.
 */
@property (nonatomic) NMAUrbanMobilitySearchOption strictSearch;

/**
 * Optional. Specifies the transit type filter used to determine which types of transit to include
 * in the response (a set of `NMAUrbanMobilityTransitModes`).
 * If not set, default values on backend server will be used.
 *
 * See also `NMAUrbanMobilityTransitMode`
 */
@property (nonatomic, nullable) NSSet *transitModes;

/**
 * Optional. Specifies if the real time information will be included in the response. The possible values are:
 * NO – do not include real time information
 * YES – include real time information
 * The default is NO.
 */
@property (nonatomic, getter = isRealTimeInfoEnabled) BOOL realTimeInfoEnabled;

@end
