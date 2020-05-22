/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilitySearchRequest.h"
#import <Foundation/Foundation.h>
@class NMAUrbanMobilityCitySearchResult;


/**
 * A completion block used to handle the search result of an Urban Mobility city search request.
 *
 * @param searchResult `NMAUrbanMobilityCitySearchResult`. The result of the Urban Mobility city search request (can be nil if `NSError`
 * error param is not nil).
 * @param error An NSError.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
typedef void (^NMAUrbanMobilityCitySearchCompletionBlock)(NMAUrbanMobilityCitySearchResult * _Nullable  searchResult, NSError * _Nullable error);


/**
 * Represents a request used for search for public transit coverage by city.
 *
 * NMAUrbanMobilityCitySearchRequest assembles and issues requests to the HERE backend server
 * by providing a query string and configuration flag for China.
 *
 * The HERE backend server responds with a `NMAUrbanMobilityCitySearchResult` or NSError if something goes wrong.
 * Use `NMAUrbanMobilityCitySearchCompletionBlock` to capture the response.
 *
 * See also `NMAUrbanMobilityCitySearchCompletionBlock`
 *
 * IMPORTANT: Urban Mobility City Search is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityCitySearchRequest : NMAUrbanMobilitySearchRequest

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Optional parameter. Limits the number of cities the response can contain. Default value is 0. Parameter is added to request if it's value is greater than 0.
 */
@property (nonatomic) NSInteger maximumResults;

/**
 * Creates a new `NMAUrbanMobilityCitySearchRequest` represents a request used for search public transit coverage by city
 *
 * @param cityName specifies the search text for the city name.
 *
 */
- (nonnull instancetype)initWithCity:(nonnull NSString *)cityName
NS_SWIFT_NAME(init(city:));

/**
 * Sends the request to retrieve a public transit coverage by city.
 * Request processing is performed asynchronously: `NMAUrbanMobilityCitySearchCompletionBlock` is used to pass the response.
 *
 * @param completion `NMAUrbanMobilityCitySearchCompletionBlock` which is used to pass the response.
 * @return YES if the request was triggered successfully, NO otherwise.
 *
 * @note `NMAUrbanMobilityCitySearchCompletionBlock` is called on the main queue.
 *
 * See also `NMAUrbanMobilityCitySearchCompletionBlock`
 */
- (BOOL)startWithCompletionBlock:(nonnull NMAUrbanMobilityCitySearchCompletionBlock)completion
NS_SWIFT_NAME(start(_:));

@end
