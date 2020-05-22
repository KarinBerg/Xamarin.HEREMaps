/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilitySearchRequest.h"

@class NMAGeoCoordinates;
@class NMAUrbanMobilityCityCoverageResult;


/**
 * ENUM values for see also `updatetype` parameter.
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMACoverageUpdateType) {
    /** The resulting response contains only cities that are new (to HERE transit service) since the given date and time. */
    NMACoverageUpdateTypeNew = 0,  //0
    /** The resulting response contains only cities with updated coverage information since the specified date and time. */
    NMACoverageUpdateTypeUpdated,  //1
    /** The resulting response contains cities that are either updated or new since a given date and time. */
    NMACoverageUpdateTypeAll       //2
} DEPRECATED_ATTRIBUTE;

/**
 * Defines a callback that is triggered upon the completion of a city coverage request.
 *        The resulting completion block contains a `NMAUrbanMobilityCityCoverageResult` or `NSError`.
 *
 * NMAUrbanMobilityCityCoverageRequestCompletionBlock is used with
 * NMAUrbanMobilityCityCoverageRequest::startWithCompletionBlock:
 * to provide a callback for capturing responses from the HERE backend server.
 *
 * @param coverageResult  `NMAUrbanMobilityCityCoverageResult` returned by the HERE backend server.
 * @param error An error which occurred when requesting a city coverage board. Error codes are defined in `NSError`.
 *
 * See also `NMAUrbanMobilityCityCoverageResult`
 *
 * See also `NSError`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
typedef void (^NMAUrbanMobilityCityCoverageRequestCompletionBlock)(NMAUrbanMobilityCityCoverageResult  * _Nullable coverageResult, NSError * _Nullable error);


/**
 *
 * Represents a request used to get a list of cities where we have transit coverage,
 * as well as list of transit operators, from a given location, within a certain radius.
 *
 * NMAUrbanMobilityCityCoverageRequest assembles and issues requests to the HERE backend server.
 *
 * The HERE backend server responds with either a list of `NMACity` or NSError if something goes wrong.
 * Use `NMAUrbanMobilityCitySearchCompletionBlock` to capture the response.
 *
 * See also `NMAUrbanMobilityCitySearchCompletionBlock`
 *
 * IMPORTANT: Urban Mobility City Coverage is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityCityCoverageRequest : NMAUrbanMobilitySearchRequest

/**
 * Initializes an NMAUrbanMobilityCityCoverageRequest instance.
 */
- (nonnull instancetype)init;

/**
 * Initializes an NMAUrbanMobilityCityCoverageRequest instance.
 */
+ (nonnull instancetype)new;

/**
 * Optional parameter.
 * Set maximum number of cities returned in a separate "nearby" list.
 * Enables a separate list for nearby cities. The resulting response contains a separate list of cities without any details.
 * Cities with zero relevancy are included in the nearby list. All cities with a relevancy greater than 0 are shown in the "main" cities list.
 */
@property (nonatomic) NSInteger nearbyMax;

/**
 * Optional parameter. Specifies a radius in meters that when combined with a user location (as specified by the parameter location ) defines
 * the area of search. The default value is 150000m.
 */
@property (nonatomic) NSInteger radius;

/**
 * Optional parameter. Specifies the location of the center point of your search
 */
@property (nonatomic, nullable) NMAGeoCoordinates *location;

/**
 * Optional parameter. Specifies the date and time to search.
 * If you specify this parameter in your request, the response contains information filtered by given date.
 * Use the `NMACoverageUpdateType` parameter to specify filtering behavior.
 */
@property (nonatomic, nullable) NSDate *time;

/**
 * Optional parameter, used for filtering data. Used in conjunction with parameter See also `time.`
 */
@property (nonatomic) NMACoverageUpdateType updateType;

/**
 * Optional parameter. Limits the number of cities the response can contain. Default value is 0. Parameter is added to request if it's value is greater than 0.
 */
@property (nonatomic) NSInteger maximumResults;

/**
 * Sends the request to retrieve public transit coverage by city.
 * Request processing is performed asynchronously: `NMAUrbanMobilityCityCoverageRequestCompletionBlock` is used to pass the response.
 *
 * @param completion `NMAUrbanMobilityCityCoverageRequestCompletionBlock` which is used to pass the response.
 * @return YES if the request was triggered successfully, NO otherwise.
 *
 * @note `NMAUrbanMobilityCityCoverageRequestCompletionBlock` is called on the main queue.
 *
 * See also `NMAUrbanMobilityCityCoverageRequestCompletionBlock`
 */
- (BOOL)startWithCompletionBlock:(nonnull NMAUrbanMobilityCityCoverageRequestCompletionBlock)completion
NS_SWIFT_NAME(start(_:));

@end
