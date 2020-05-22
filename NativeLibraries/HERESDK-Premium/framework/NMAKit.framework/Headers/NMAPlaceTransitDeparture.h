/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAExtendedAttribute;


/**
 * Key name to retrieve departure time
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMADepartureTimeKeyName;
/**
 * Key name to retrieve the departure platform information.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMADeparturePlatformKeyName;

/**
 * Departure has been redirected.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAExceptionEventRedirected;
/**
 * Departure has been replaced.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAExceptionEventReplaced;
/**
 * Departure has been cancelled.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAExceptionEventCancelled;
/**
 * Additional departure information provided.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAExceptionEventAdditional;


/**
 *
 * Represents information about a single departure.
 *
 * All times use the RFC 3339 date-time format with timezone offset.
 * See http://tools.ietf.org/html/rfc3339#section-5.6
 */
@interface NMAPlaceTransitDeparture : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Reference to the line in transit lines directory.
 */
@property (nullable, nonatomic, readonly) NSString *line;

/**
 * The NSDictionary of the originally scheduled departure time information.
 *
 * Known key identifier values are:
 *
 * 1. `NMADepartureTimeKeyName` - `NSString` of scheduled departure time (RFC 3339 date-time with timezone offset)
 *
 * 2. `NMADeparturePlatformKeyName` - `NSString` of scheduled departure platform (optional)
 */
@property (nullable, nonatomic, readonly) NSDictionary<NSString *, NSString *> *scheduledTimeInfo;

/**
 * Direction of the departure on its line.
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *direction;

/**
 * An indicator for some exceptional event happened to this departure.
 * Possible values are:
 * `NMAExceptionEventRedirected`, `NMAExceptionEventReplaced`,
 * `NMAExceptionEventCancelled` and `NMAExceptionEventAdditional`.
 *
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *exception;

/**
 * The `NSString` of reference to the operator in the operators collection information.
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *transitOperator;

/**
 * The NSDictionary of the real (actual) departure time information. The
 * departure key represents the departure time.
 *
 * Known key identifier values are:
 *
 * 1. `NMADepartureTimeKeyName` - `NSString` of real-time departure time (RFC 3339 date-time with timezone offset)
 *
 * 2. `NMADeparturePlatformKeyName` - `NSString` of real-time departure platform (optional)
 *
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSDictionary<NSString *, NSString *> *realTimeInfo;

/**
 * An NSArray of NMAExtendedAttribute features of departure. Supported keys are
 * bikeAllowed and barrierFree.
 *
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSArray<NMAExtendedAttribute *> *extendedAttributes;

@end
