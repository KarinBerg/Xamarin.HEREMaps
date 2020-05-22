/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAUrbanMobilityNearbyCoverageResult.h"
@class NMAUrbanMobilityTransport;
@class NMAUrbanMobilityOperator;



/**
 *
 * Contains information about if operators, lines or time tables are missing.
 *
 * IMPORTANT: Urban Mobility Coverage Search is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityMissingCoverage : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Coverage type in returned area.
 */
@property (nonatomic, readonly) NMAUrbanMobilityCoverageType type;

/**
 * Transit lines which run through this city (an array of `NMAUrbanMobilityTransport`).
 *
 * See also `NMAUrbanMobilityTransport`
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityTransport *> *transports;

/**
 * Operators serving city(an array of `NMAUrbanMobilityOperator`).
 *
 * See also `NMAUrbanMobilityOperator`
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityOperator *> *operators;

@end
