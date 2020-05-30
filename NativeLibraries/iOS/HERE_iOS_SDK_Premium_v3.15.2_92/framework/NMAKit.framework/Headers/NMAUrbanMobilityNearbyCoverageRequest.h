/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilitySearchRequest.h"
#import <Foundation/Foundation.h>

@class NMAUrbanMobilityCityCoverageResult;
@class NMAUrbanMobilityNearbyCoverageResult;


/**
 * Defines a callback that is triggered upon the completion of a departure board request.
 *        The resulting completion block contains a list of `NMAUrbanMobilityDeparture` or `NSError`.
 *
 * NMAUrbanMobilityNearbyCoverageRequestCompletionBlock is used with
 * NMAUrbanMobilityNearbyCoverageRequest::startWithCompletionBlock:
 * to provide a callback for capturing responses from the HERE backend server.
 *
 * @param nearbyCoverageResult `NMAUrbanMobilityNearbyCoverageResult` returned by the HERE backend server.
 * @param error An NSError which occurred when requesting a nearby coverage. Error codes are defined in `NSError`.
 *
 * See also `NMAUrbanMobilityNearbyCoverageResult`
 *
 * See also `NSError`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
typedef void (^NMAUrbanMobilityNearbyCoverageRequestCompletionBlock)(NMAUrbanMobilityNearbyCoverageResult * _Nullable nearbyCoverageResult, NSError * _Nullable error);


/**
 *
 * Represents a request used for retrieve coverage information about nearby cities.
 *
 * NMAUrbanMobilityNearbyCoverageRequest assembles and issues requests to the HERE backend server.
 *
 * The HERE backend server responds with  `NMAUrbanMobilityNearbyCoverageResult` or NSError if something goes wrong.
 * Use `NMAUrbanMobilityNearbyCoverageRequestCompletionBlock` to capture the response.
 *
 * See also `NMAUrbanMobilityNearbyCoverageRequestCompletionBlock`
 *
 * See also `NMAUrbanMobilityNearbyCoverageResult`
 *
 * IMPORTANT: Urban Mobility Nearby Coverage is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityNearbyCoverageRequest : NMAUrbanMobilitySearchRequest

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Creates a new `NMAUrbanMobilityNearbyCoverageRequest` for searching nearest coverage with a given geo coordinates.
 *
 * @param location Geo coordinates of the location.
 *
 */
- (nonnull instancetype)initWithLocation:(nonnull NMAGeoCoordinates *)location
NS_SWIFT_NAME(init(location:));

/**
 * Sends the request to the HERE backend server to retrieve a nearby coverage data.
 * Request processing is performed asynchronously: `NMAUrbanMobilityNearbyCoverageRequestCompletionBlock` is used to pass the response.
 *
 * @param completion `NMAUrbanMobilityNearbyCoverageRequestCompletionBlock` which is used to pass the response.
 * @return YES if the request was triggered successfully, NO otherwise.
 *
 * @note `NMAUrbanMobilityNearbyCoverageRequestCompletionBlock` is called on the main queue.
 *
 * See also `NMAUrbanMobilityNearbyCoverageRequestCompletionBlock`
 */
- (BOOL)startWithCompletionBlock:(nonnull NMAUrbanMobilityNearbyCoverageRequestCompletionBlock)completion
NS_SWIFT_NAME(start(_:));

@end
