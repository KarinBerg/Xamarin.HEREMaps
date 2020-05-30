/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;
@class NMAUrbanMobilityStationWithDepartureBoard;
@class NMAUrbanMobilityTransport;
#import "NMAUrbanMobility.h"


/**
 * Defines a callback which is triggered on the completion of a Multi Departure Board request.
 * The resulting callback contains an array of `NMAUrbanMobilityStationWithDepartureBoard`, an array of `NMAUrbanMobilityTransport` or `NSError`.
 *
 * NMAUrbanMobilityMultiBoardCompletionBlock is used with
 * `NMAUrbanMobilityMultiBoardRequest::startWithCompletionBlock:`
 * to provide a callback for capturing responses from the HERE backend server.
 *
 * @param stations Array of `NMAUrbanMobilityStationWithDepartureBoard` returned by the HERE backend server.
 * @param transports Array of `NMAUrbanMobilityTransport` returned by the HERE backend server.
 * @param error An error which occurred when searching for transit stations. Error codes are defined in `NSError`.
 *
 * See also `NMAUrbanMobilityMultiBoardRequest::startWithCompletionBlock:`
 *
 * See also `NMAUrbanMobilityStationWithDepartureBoard`
 *
 * See also `NMAUrbanMobilityTransport`
 *
 * See also `NSError`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
typedef void (^NMAUrbanMobilityMultiBoardCompletionBlock)(NSArray<NMAUrbanMobilityStationWithDepartureBoard *> * _Nullable stations, NSArray<NMAUrbanMobilityTransport *> * _Nullable transports, NSError * _Nullable error);


/**
 *
 * Represents a request to retrieve a multi departure board for the given location.
 *
 * NMAUrbanMobilityMultiBoardRequest assembles and issues requests to the HERE backend server
 * by providing a geo location.
 *
 * The HERE backend server responds with either a list of `NMAUrbanMobilityStationWithDepartureBoard` objects or NSError if something goes wrong.
 * Use `NMAUrbanMobilityMultiBoardCompletionBlock` to capture the response.
 *
 * See also `NMAUrbanMobilityMultiBoardCompletionBlock`
 *
 * See also `NMAUrbanMobilityStationWithDepartureBoard`
 *
 * IMPORTANT: Urban Mobility Multi Board is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityMultiBoardRequest : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Creates a new `NMAUrbanMobilityMultiBoardRequest` for a multi departure board at a transit station with a given geo coordinates.
 *
 * @param location Geo coordinates of the transit station.
 *
 * @note Geo coordinates are required to identify a transit station unambiguously.
 */
- (nonnull instancetype)initWithLocation:(nonnull NMAGeoCoordinates *)location
NS_SWIFT_NAME(init(location:));

/**
 * Creates a new `NMAUrbanMobilityMultiBoardRequest` to search only by Station IDs.
 *
 * @param stationIds array of stations IDs. Can't be nil or empty.
 */
- (nonnull instancetype)initWithStationIds:(nonnull NSArray<NSString *> *)stationIds
NS_SWIFT_NAME(init(stationIds:));

/**
 * Sends the request to retrieve a multi departure board from the HERE backend server.
 * Request processing is performed asynchronously: `NMAUrbanMobilityMultiBoardCompletionBlock` is used to pass the response.
 *
 * @param completion `NMAUrbanMobilityMultiBoardCompletionBlock` which is used to pass the response.
 * @return YES if the request was triggered successfully, NO otherwise.
 *
 * @note `NMAUrbanMobilityMultiBoardCompletionBlock` is called on the main queue.
 *
 * See also `NMAUrbanMobilityMultiBoardCompletionBlock`
 */
- (BOOL)startWithCompletionBlock:(nonnull NMAUrbanMobilityMultiBoardCompletionBlock)completion
NS_SWIFT_NAME(start(_:));

/**
 * Geo coordinates of the location which multi departure board is being requested.
 */
@property (nonatomic, readonly, nullable) NMAGeoCoordinates *location;

/**
 * Specifies a list of station IDs for which we request next departures.
 */
@property (nonatomic, readonly, nullable) NSArray<NSString *> *stationIds;

/**
 * Time which is used as a start point for the multi departure board being requested.
 * All entries in the departure board are the earliest possible departures after the specified time.
 *
 * @note If this property is not set then the current timestamp is used.
 */
@property (nonatomic, nullable) NSDate *departureTime;

/**
 * Optional. Specifies if the real time information will be included in the response. The possible values are:
 * NO – do not include real time information
 * YES – include real time information
 * The default is NO.
 */
@property (nonatomic, getter = isRealTimeInfoEnabled) BOOL realTimeInfoEnabled;

/**
 * Optional. Specifies a radius in meters that when combined with a centerpoint defines the area of the search.
 * Any value greater than 0 will be added to the request. Otherwise, default value will be used by the backend.
 */
@property (nonatomic) NSInteger radius;

/**
 * Optional. Specifies the transport type filter used to determine which types of transport to include
 * in the response (a set of `NMAUrbanMobilityTransportType`).
 * If not set, default values on backend server will be used.
 *
 * See also `NMAUrbanMobilityTransportType`
 */
@property (nonatomic, nullable) NSSet<NSNumber *> *transportTypes;

/**
 * Optional. Specifies the maximum number of next departures per station the response should include.
 * Must be greater than 0.
 */
@property (nonatomic) NSUInteger maxDeparturesPerStation;

/**
 * Optional. Specifies the maximum number of stations the response should include.
 * Must be greater than 0.
 */
@property (nonatomic) NSUInteger maximumResults;

@end
