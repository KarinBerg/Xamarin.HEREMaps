/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


@class NMAUrbanMobilityLink;

/**
 * Type of `NMAUrbanMobilityFare`.
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityFareType) {
    /** Price type not available.*/
    NMAUrbanMobilityFareTypeNotAvailable   = 0,
    /** The indicated price is the cost per hour. Example: 11$/hour.*/
    NMAUrbanMobilityFareTypeHourly         = 1,
    /** The indicated price is the cost per day. Example: 62$/day.*/
    NMAUrbanMobilityFareTypeDaily          = 2,
    /** The price represents a range with minimum and maximum value.*/
    NMAUrbanMobilityFareTypeRange          = 3,
    /** Unrecognized price type.*/
    NMAUrbanMobilityFareTypeUnrecognized   = 4
} DEPRECATED_ATTRIBUTE;


/**
 * A single fare which covers a portion of a journey (e.g. ticket).
 *
 * IMPORTANT: Urban Mobility routing is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityFare : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Name of the fare.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * Price of the fare or minimum price of the fare if fare type is a range.
 */
@property (nonatomic, readonly) double price;

/**
 * Maximum price of the fare, if range of price is available.
 * The default value is `NMAUrbanMobilityValueNotAvailable`;
 */
@property (nonatomic, readonly) double maximumPrice;

/**
 * Specifies the type of a fare.
 * The default value is NMAUrbanMobilityFareTypeNotAvailable.
 */
@property (nonatomic, readonly) NMAUrbanMobilityFareType fareType;

/**
 * Reason for the cost described in this fare, e.g. parking.
 * The string value or nil.
 */
@property (nonatomic, readonly, nullable) NSString *reason;

/**
 * Attribute value is YES if the fare price is estimated, NO if it's an exact value.
 * The default value is NO.
 */
@property (nonatomic, readonly, getter = isEstimatedPrice) BOOL estimatedPrice;

/**
 * Gets ISO 4217 code of currency in which the price is given, e.g. "EUR".
 *
 * See https://en.wikipedia.org/wiki/ISO_4217
 */
@property (nonatomic, readonly, nullable) NSString *currency;

/**
 * Gets the array of `NMAUrbanMobilityLink` associated with this fare (e.g. to a booking
 * page), or nil.
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityLink *> *links;

@end
