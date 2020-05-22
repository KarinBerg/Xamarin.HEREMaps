/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAAddress;



/**
 * Contains POI (Point Of Interest) information of the spatial area in a venue.
 *
 * Examples of included POI information are the street address, the access information, the search tags, the space type, the category.
 *
 */
@interface NMAVenue3dContent : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The human-readable name related to holder of the spatial area. This can be, for example, the name of the shop.
 * Can be nil if there is no name for the spatial area.
 *
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The phone number related to holder of the spatial area.
 * Can be nil if there is no phone number for the spatial area.
 *
 */
@property (nonatomic, readonly, nullable) NSString *phoneNumber;

/**
 * The URL address of the web site related to holder of the spatial area.
 * Can be nil if there is no URL for the spatial area.
 *
 */
@property (nonatomic, readonly, nullable) NSString *website;

/**
 * The email address related to holder of the spatial area.
 * Can be nil if there is no email address for the spatial area.
 *
 */
@property (nonatomic, readonly, nullable) NSString *email;

/**
 * The postal address of the spatial area.
 *
 * See also `NMAAddress`
 */
@property (nonatomic, readonly, nonnull) NMAAddress *address;

/**
 * The parent category identifier of the spatial area. This information can be used
 * for example to check type of the space: shopping, transportation-facility etc.
 *
 */
@property (nonatomic, readonly, nonnull) NSString *parentCategoryId;

/**
 * The category identifier of the spatial area. For example, this information can be used
 * to check the type of a store, such as food and clothing.
 *
 * See also `NMAVenue3dLevel::spacesWithCategory:`
 */
@property (nonatomic, readonly, nonnull) NSString *placeCategoryId;

/**
 * The tags which describes the content holder. For example, the tags for an electronics retailer
 * may contain: television, phone, mobile, computer, and so on.
 * The tags can help to search inside NMAVenue3dVenue for specific key words.
 *
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *searchTags;

/**
 * The unique venue identifier of the spatial area. This identifier is unique and
 * constant for each spatial area and can't be changed in later data updates.
 * Can be nil if there is no unique venue id for the spatial area.
 *
 */
@property (nonatomic, readonly, nonnull) NSString *uniqueVenueId;

/**
 * The unique content identifier of the spatial area.
 */
@property (nonatomic, readonly, nonnull) NSString *uniqueId;

/**
 * The string containing the venue-specific category identifier.
 *
 */
@property (nonatomic, readonly, nonnull) NSString *categoryId;

/**
 * The custom attributes of the spatial area.
 * Can be nil if there is are no custom attributes for the spatial area.
 * Attribute values may be of type NSNumber, NSString, NSArray, and NSDictionary.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *,NSObject *> *customAttributes;

@end
