/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAPlaceTransitSchedulePageRequest;
@class NMAPlaceTransitDeparture;
@class NMAPlaceTransitLine;
@class NMAPlaceTransitOperator;


/**
 * Represents departure information for a public transport stop/station.
 * Departure items are paginated based on NMARequest#collectionSize.
 *
 * NMAPlaceTransitScheduleRequest objects are typically created using the NMAPlaces
 * interface to initialize search, explore or here requests.
 *
 * Results may be split into multiple page. Each results page contains a collection of
 * NMAPlaceTransitDeparture objects representing departure information.
 *
 */
@interface NMAPlaceTransitSchedulePage : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The total number of available NMATransitDeparture objects for
 * this transit schedule page.
 */
@property (nonatomic, readonly) NSInteger available;

/**
 * Result offset of the current results page into the total number of results avilable.
 *
 * @note The number of results on the current page is the number of elements in `departures`.
 */
@property (nonatomic, readonly) NSInteger offsetCount;

/**
 * The NMAPlaceTransitScheduleRequest for requesting the next page of results.
 *
 * @note This will be nil if there is no next page.
 */
@property (nullable, nonatomic, readonly) NMAPlaceTransitSchedulePageRequest *nextPageRequest;

/**
 * Array of NMAPlaceTransitDeparture objects for the current page of results.
 */
@property (nonnull, nonatomic, readonly) NSArray<NMAPlaceTransitDeparture *> *departures;

/**
 * Dictionary of transit line names to NMAPlaceTransitLine objects for the
 * current page of results.
 *
 * @note The dictionary of transit lines serving departures shown in current
 * departure item list using line name as key.
 * Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSDictionary<NSString *, NMAPlaceTransitLine *> *lines;

/**
 * Dictionary of transit line operatiors to NMAPlaceTransitOperator objects
 * for the current page of results.
 *
 * @note The dictionary of operators operating on this stop/station using
 * [NMAPlaceTransitOperator uniqueId] as key.
 * Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSDictionary<NSString *, NMAPlaceTransitOperator *> *operators;

@end

