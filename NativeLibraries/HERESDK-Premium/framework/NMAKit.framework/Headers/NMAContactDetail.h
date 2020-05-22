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
 * Represents detailed information about a contact for a NMAPlace.
 *
 * For example, if a NMAPlace has among its known contacts array the
 * phone number 555-1234, use this interface to access details about that particular
 * contact's label ("Phone") and value ("555-1234").
 *
 */
@interface NMAContactDetail : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The localized label describing the mechanism by which application end users
 * can contact the place.
 */
@property (nullable, nonatomic, readonly) NSString *label;

/**
 * The string value appropriate to the localized label.
 */
@property (nullable, nonatomic, readonly) NSString *value;

/**
 * The type (email, fax, phone, website, etc.) of the NMAContactDetail.
 */
@property (nonnull, nonatomic, readonly) NSString *type;

@end
