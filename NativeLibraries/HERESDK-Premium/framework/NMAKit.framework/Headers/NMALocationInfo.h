/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


/**
 * The available information fields in the NMALocationInfo class.
 *
 * See also `NMALocationInfo`
 */
typedef NS_ENUM(NSUInteger, NMALocationInfoField) {
    /**
     * Place Name
     */
    NMALocationInfoFieldPlaceName,
    /**
     * Name of the category of the place
     */
    NMALocationInfoFieldPlaceCategory,
    /**
     * Phone number of the place.
     */
    NMALocationInfoFieldPlacePhoneNumber,
    /**
     * A unique identifier for the place in the context of a particular reference source.
     */
    NMALocationInfoFieldReferenceIdentifier,

    /**
     * The source of the reference identifier of the place.
     */
    NMALocationInfoFieldReferenceSource
};


/**
 * Contains information about a real-world location.
 *
 * The types of information available are given by the NMALocationInfoField enum.
 */
@interface NMALocationInfo : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Determines whether or not the NMALocationInfo object has a particular field.
 *
 * @param field NMALocationInfoField to determine if the NMALocationInfo has it or not.
 *
 * @return YES if the NMALocationInfo object has the field.
 */
- (BOOL)hasField:(NMALocationInfoField)field;

/**
 * Retrieves the value of the specified NMANMALocationInfoField for the NMALocationInfo object.
 *
 * @param field NMALocationInfoField to get the field value for.
 *
 * @return The string value of the specified NMALocationInfoField if available, otherwise nil.
 */
- (nullable NSString *)valueForField:(NMALocationInfoField)field
NS_SWIFT_NAME(valueForField(_:));

@end
