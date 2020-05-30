/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */



/**
 * Represents a HERE account that can be used by the Venue Service.
 * Each account is associated with a specific private venue source. All available
 * accounts can be obtained with `NMAVenue3dService::venueAccounts`.
 * Switching accounts with `NMAVenue3dService::setActiveVenueAccount:`
 * will enable different private venues for a user.
 *
 * See also `NMAVenue3dService`
 */
@interface NMAVenue3dAccount : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The string which uniquely identifies this NMAVenue3dAccount.
 */
@property (nonatomic, readonly, nonnull) NSString *uniqueId;

/**
 * The string which contains a description for this NMAVenue3dAccount.
 */
@property (nonatomic, readonly, nonnull) NSString *description;

@end

