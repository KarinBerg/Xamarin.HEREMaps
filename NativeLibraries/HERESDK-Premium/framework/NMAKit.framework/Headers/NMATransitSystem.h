/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>



/**
 *
 * Represents a public transit system.
 *
 * @note Some systems may not have complete information available.
 */
@interface NMATransitSystem : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The unique identifying string of the access.
 */
@property (nonatomic, readonly, nonnull) NSString *uniqueId;

/**
 * The officially published name of the system, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *officialName;

/**
 * The local name of the system, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *informalName;

/**
 * A short name for the system, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *shortName;

/**
 * The system website, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *website;

/**
 * The official name of the company operating the system.
 */
@property (nonatomic, readonly, nonnull) NSString *companyOfficialName;

/**
 * The local name of the company operating the system, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *companyInformalName;

/**
 * A short name for the company operating the system, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *companyShortName;

/**
 * The website for the company operating the system, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *companyWebsite;

/**
 * The website used for planning routes on the system, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *companyRoutePlannerWebsite;

/**
 * The website used for looking up system schedules, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *companyScheduleWebsite;

/**
 * The phone number of the company operating the system, if available.
 */
@property (nonatomic, readonly, nonnull) NSString *companyTelephoneNumber;

@end
