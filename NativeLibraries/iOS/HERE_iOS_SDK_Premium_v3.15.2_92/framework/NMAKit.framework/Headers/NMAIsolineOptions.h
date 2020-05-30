/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Isoline quality modes.
 *
 * @note Isoline Routing offers flexibility to choose the best quality, best performance or
 * a balance between the two. The best quality considers a finer level of data for optimization but
 * takes longer than choosing the best performance.
 */
typedef NS_ENUM(NSUInteger, NMAIsolineQuality) {
    /**
     * Best quality.
     */
    NMAIsolineQualityBest,
    /**
     * Best performance.
     */
    NMAIsolineQualityPerformance,
    /**
     * Balanced.
     */
    NMAIsolineQualityBalanced
};


/**
 * Represents a options for isoline calculation
 */
@interface NMAIsolineOptions : NSObject

/**
 * Initializes a `NMAIsolineOptions` instance with default values.
 */
- (nonnull instancetype)init;

/**
 * The desired `NMAIsolineQuality` to use. Default is `NMAIsolineQualityBest`.
 */
@property (nonatomic) NMAIsolineQuality quality;

/**
 * The desired isoline resolution to use.
 *
 * @note The view resolution allows the client to specify the level of detail needed for visualizing
 * the polygon. It is specified in meters per pixel and reflects the client's zoom level and screen
 * resolution. The isoline service will use this value in order to find the optimal level of detail.
 * Specify the level of detail needed for the isoline polygon. Higher resolution may cause increased
 * response time from the service.
 */
@property (nonatomic) NSUInteger viewResolution;

/**
 * If true is the isoline service will always return single polygon instead of creating a separate
 * polygon for each ferry separated island.
 */
@property (nonatomic) BOOL computeSingleComponent;

@end
