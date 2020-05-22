/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAEHPathTree;



/**
 * Represents an enumerator for iterating through the `NMAEHPathTree` objects.
 */
@interface NMAEHPathTreeRange : NSEnumerator

/**
 * The size property represents the number of `NMAEHPathTree` objects in the range.
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
 * Overridden method that gets the next `NMAEHPathTree` in the range.
 * This method is used to iterate through the elements of the range.
 *
 * @return The `NMAEHPathTree` instance, or nil if the iterator reaches the end.
 */
- (nullable NMAEHPathTree *)nextObject;

/**
 * Resets the iterator to point to the beginning of the range.
 */
- (void)reset;

@end
