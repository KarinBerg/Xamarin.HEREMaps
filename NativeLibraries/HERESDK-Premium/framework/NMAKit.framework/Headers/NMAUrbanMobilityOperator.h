/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAUrbanMobilityLink;


/**
 * This enum defines the types of transit operators.
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityOperatorType) {
    /** Unknown type. */
    NMAUrbanMobilityOperatorTypeUnknown      NS_SWIFT_NAME(unknown) = 0,

    /** Operator uses estimated times for departures and routing. */
    NMAUrbanMobilityOperatorTypeEstimated  NS_SWIFT_NAME(estimated) = 1 ,

    /** Operator uses time tables for departures and routing. */
    NMAUrbanMobilityOperatorTypeTimeTable  NS_SWIFT_NAME(timeTable) = 2,

    /** Operator tracks real time changes to departures and routes. */
    NMAUrbanMobilityOperatorTypeRealTime    NS_SWIFT_NAME(realTime) = 3
} DEPRECATED_ATTRIBUTE;


/**
 * Transit operator which governs transit lines.
 *
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * @note Disclaimers associated with the operator must be displayed to end-users.
 *
 * See also `NMAUrbanMobilityLink`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityOperator : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Unique code of the operator.
 */
@property (nonatomic, readonly, nullable) NSString *code;

/**
 * Name of the operator.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * Type of the operator.
 */
@property (nonatomic, readonly) NMAUrbanMobilityOperatorType type;

/**
 * Disclaimers which needs to be shown to the end-users as a part of the agreement with the operator.
 * @return array of `NMAUrbanMobilityLink` or nil.
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityLink *> *disclaimers;

@end
