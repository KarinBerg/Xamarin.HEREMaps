/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dArea.h"

@class UIImage;
@class NMAVenue3dContent;


/**
 * Represents the type of a venue space.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dSpaceType) {
    /**
     * Represents a standard NMAVenue3dSpace object.
     */
    NMAVenue3dSpaceTypeGeneral,

    /**
     * Represents NMAVenue3dSpace object which is a facility: elevators, stairs, toilets, ATM's etc.
     */
    NMAVenue3dSpaceTypeFacility
};

/**
 */


/**
 * A physical space in a NMAVenue3dVenue such as a shop in a mall.
 *
 * When the NMAVenue3dMapLayer is used, the NMAVenue3dSpace can be interacted with by tapping on it.
 *
 *  See also `NMAVenue3dContent`
 *
 *  See also `NMAVenue3dVenue`
 */
@interface NMAVenue3dSpace : NMAVenue3dArea

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The NMAVenue3dContent object belonging to this NMAVenue3dSpace.
 */
@property (nonatomic, readonly, nullable) NMAVenue3dContent *content;

/**
 * The floor number. For ground floor it's 0. For underground floors:
 * -1, -2, -3... For above ground floors: 1, 2, 3...
 */
@property (nonatomic, readonly) NSInteger floorNumber;

/**
 * The floor synonym, for example: 1, B, P1, MEZZ etc.
 */
@property (nonatomic, readonly, nonnull) NSString *floorSynonym;

/**
 * The name of the NMAVenue3dVenue where this NMAVenue3dSpace is located.
 *
 */
@property (nonatomic, readonly, nonnull) NSString *venueName;

/**
 * The icon of the NMAVenue3dSpace, which is displayed on the map.
 *
 */
@property (nonatomic, readonly, nullable) UIImage *icon;

/**
 * The URI of the NMAVenue3dSpace's icon. Return nil if type is not valid or there is no icon.
 */
@property (nonatomic, readonly, nullable) NSString *iconUri;

/**
 * The space type.
 */
@property (nonatomic, readonly) NMAVenue3dSpaceType type;

@end
