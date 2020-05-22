/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * Determines which `NMAEHLinkDirection` of the link is part of the current path.
 */
typedef NS_ENUM(NSUInteger, NMAEHLinkDirection) {
    /**
     * Forward movement
     */
    NMAEHLinkDirectionForward,
    /**
     * Backward movement
     */
    NMAEHLinkDirectionBackward
};


/**
 *
 * Represents the smallest entity of a road segment. The path of a `NMAEHPathTree` is defined by
 * it's containing links.
 */
@interface NMAEHLink : NSObject

/**
 * The id property represents the unique identifier of the link.
 */
@property (nonatomic) UInt64 id;

/**
 * Represents the predicted `NMAEHLinkDirection` on this link.
 *
 * @note The direction can be NMAEHLinkDirectionForward or NMAEHLinkDirectionBackward.
 */
@property (nonatomic) NMAEHLinkDirection direction;

/**
 * Represents the distance from the beginning of the `NMAEHPathTree` that contains this link to
 * the beginning of the link.
 */
@property (nonatomic) NSUInteger startOffsetCentimeters;

/**
 * Represents the distance from the beginning of the `NMAEHPathTree` that contains this link to
 * the end of the link.
 */
@property (nonatomic) NSUInteger endOffsetCentimeters;

/**
 * Determines whether this `NMAEHLink` is equal to another link.
 *
 * @return YES if the links are equal, NO otherwise
 */
- (BOOL)isEqualToLink:(nonnull NMAEHLink *)link
NS_SWIFT_NAME(isEqual(_:));

@end
