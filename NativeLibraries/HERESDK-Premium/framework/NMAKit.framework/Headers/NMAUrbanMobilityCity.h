/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
@class NMAGeoCoordinates;
@class NMAUrbanMobilityMissingCoverage;
@class NMAUrbanMobilityOperator;
@class NMAUrbanMobilityProvider;



/**
 * Contains all available information about a city.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityCity : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Name of the city. It's the localized name.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * Giving hint how name, state and contry could be displayed in screen. There is no guarantee that this hint would actually be correct. Nil if not available.
 */
@property (nonatomic, readonly, nullable) NSString *displayName;

/**
 * Name of the country that city belongs to. It's the localized name.
 */
@property (nonatomic, readonly, nullable) NSString *country;

/**
 * Name of the state that city belongs to. It's the localized name.
 */
@property (nonatomic, readonly, nullable) NSString *state;

/**
 * Geo coordinates of the city.
 */
@property (nonatomic, readonly, nullable) NMAGeoCoordinates *location;

/**
 * Date when information about the city was created.
 */
@property (nonatomic, readonly, nullable) NSDate *created;

/**
 * Date when information about the city was updated.
 */
@property (nonatomic, readonly, nullable) NSDate *updated;

/**
 * Is value 0..1 putting weight how relevant some city should be for user when user is in some specifig location.
 * This will mostly give correct results but it cannot be guaranteed. -1 if not available.
 */
@property (nonatomic, readonly) double relevancy;

/**
 * Distance from the user to the city. -1 if not available.
 */
@property (nonatomic, readonly) NSInteger distance;

/**
 * Array of `NMAUrbanMobilityOperator` serving city. Nil if not available.
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityOperator *> *operators;

/**
 * City population. -1 if not available.
 */
@property (nonatomic, readonly) NSInteger population;

/**
 * Array of coverage data `NMAUrbanMobilityProvider`. Nil if not available.
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityProvider *> *providers;

/**
 * Detailed coverage information: the percentage of the city coverage in between 0.0 (nothing covered)
 * and 1.0 (completely covered). -1 if not available.
 */
@property (nonatomic, readonly) float quality;

/**
 * Detailed coverage information: number of transports found inside city. -1 if not available.
 */
@property (nonatomic, readonly) NSInteger transportsCount;

/**
 * Detailed coverage information: number of stops found inside city. -1 if not available.
 */
@property (nonatomic, readonly) NSInteger stopsCount;

/**
 * `NMAUrbanMobilityMissingCoverage` contains information about if operators, lines or time tables are missing. Nil if not available.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityMissingCoverage *missingCoverage;

@end
