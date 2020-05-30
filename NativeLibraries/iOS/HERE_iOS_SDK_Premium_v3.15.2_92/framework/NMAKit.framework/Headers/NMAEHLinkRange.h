/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAEHLink;


/**
 * Represents an enumerator for iterating through the `NMAEHLink` objects.
 */
@interface NMAEHLinkRange : NSEnumerator

/**
 * The size property represents the number of `NMAEHLink` objects in the range.
 */
@property (nonatomic, readonly) NSUInteger size;

/**
 * Instances of this class should not be initialized. Call class methods only.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Overridden method that gets the next `NMAEHLink` in the range.
 * This method is used to iterate through the elements of the range.
 *
 * @return The `NMAEHLink` instance, or nil if the iterator reaches the end.
 */
- (nullable NMAEHLink *)nextObject;

/**
 * Resets the iterator to point to the beginning of the range.
 */
- (void)reset;

@end
