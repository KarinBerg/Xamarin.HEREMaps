/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAEHPathTreeRange;
@class NMAEHLinkRange;



/**
 * Represents a tree like structure where each PathTree may contain multiple links, parent and
 * children paths. For a vehicle, children paths are less likely to be followed than their parents.
 */
@interface NMAEHPathTree : NSObject

/**
 * Returns the distance from the beginning of the parent `NMAEHPathTree` to the start of this
 * path.
 */
@property (nonatomic, readonly) NSUInteger offsetCentimeters;

/**
 * Represents the probability of taking this path ranging from 0 to 1.
 */
@property (nonatomic, readonly) float probability;

/**
 * The parent property represents the parent path tree in the hierarchy.
 *
 * @note the parent property of the root path tree is nil.
 */
@property (nonatomic, readonly, nullable) NMAEHPathTree *parent;

/**
 * The children property is an enumerator of type `NMAEHPathTreeRange`, which allows to iterate
 * over all children.
 */
@property (nonatomic, readonly, nonnull) NMAEHPathTreeRange *children;

/**
 * The links property is an enumerator of type `NMAEHLinkRange`, which allows to iterate
 * over all links.
 */
@property (nonatomic, readonly, nonnull) NMAEHLinkRange *links;

/**
 * Determines whether this NMAEHPathTree is equal to another.
 *
 * @return YES if the paths are equal, NO otherwise
 */
- (BOOL)isEqualToPathTree:(nonnull NMAEHPathTree *)pathTree
NS_SWIFT_NAME(isEqual(_:));

/**
 * Instances of this class should not be initialized. Call class methods only.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
