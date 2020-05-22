/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * NMALaneInformationDirection
 * All possible directions the lane leads.
 *
 * A combination of the NMALaneInformationDirection forms a direction bitmask.
 *
 * See also `NMALaneInformation`
 */
typedef NS_OPTIONS(NSUInteger, NMALaneInformationDirection) {
    /** Indicates there are no markings on this lane and the direction is unknown. */
    NMALaneInformationDirectionMaskUndefined = 0,

    /** Indicates that the direction of travel is straight ahead. */
    NMALaneInformationDirectionMaskStraight NS_SWIFT_NAME(straight) = 1 << 0,

    /** Indicates a slight right turn. */
    NMALaneInformationDirectionMaskSlightlyRight NS_SWIFT_NAME(slightlyRight) = 1 << 1,

    /** Indicates a right turn. */
    NMALaneInformationDirectionMaskRight NS_SWIFT_NAME(right) = 1 << 2,

    /** Indicates a sharp right turn. */
    NMALaneInformationDirectionMaskSharpRight NS_SWIFT_NAME(sharpRight) = 1 << 3,

    /** Indicates a left u-turn. */
    NMALaneInformationDirectionMaskUTurnLeft NS_SWIFT_NAME(uTurnLeft) = 1 << 4,

    /** Indicates a sharp left turn. */
    NMALaneInformationDirectionMaskSharpLeft NS_SWIFT_NAME(sharpLeft) = 1 << 5,

    /** Indicates a left turn. */
    NMALaneInformationDirectionMaskLeft NS_SWIFT_NAME(left) = 1 << 6,

    /** Indicates a slight left turn. */
    NMALaneInformationDirectionMaskSlightlyLeft NS_SWIFT_NAME(slightlyLeft) = 1 << 7,

    /** Indicates a right merge. */
    NMALaneInformationDirectionMaskMergeRight NS_SWIFT_NAME(mergeRight) = 1 << 8,

    /** Indicates a left merge. */
    NMALaneInformationDirectionMaskMergeLeft NS_SWIFT_NAME(mergeLeft) = 1 << 9,

    /** Indicates a merge of lanes. */
    NMALaneInformationDirectionMaskMergeLanes NS_SWIFT_NAME(mergeLanes) = 1 << 10,

    /** Indicates a right u-turn. */
    NMALaneInformationDirectionMaskUTurnRight NS_SWIFT_NAME(uTurnRight) = 1 << 11,

    /** Indicates a second right. */
    NMALaneInformationDirectionMaskSecondRight NS_SWIFT_NAME(secondRight) = 1 << 12,

    /** Indicates a second left. */
    NMALaneInformationDirectionMaskSecondLeft NS_SWIFT_NAME(secondLeft) = 1 << 13
};

/**
 * Recommendation for taking the lane according to the lane connectivity.
 *
 * See also `NMALaneInformation`
 */
typedef NS_ENUM(NSUInteger, NMALaneInformationRecommendationState) {
    /** The lane is not on the current route. */
    NMALaneInformationRecommendationStateNotRecommended,

    /**
     * The lane is on the route at least up to the next decision point, but not for the whole
     * part of the route for which connectivity information is available.
     */
    NMALaneInformationRecommendationStateRecommended,

    /**
     * The lane is on the current route for the whole part of the route for which connectivity
     * information is available.
     */
    NMALaneInformationRecommendationStateHighlyRecommended,

    /** Recommendation information is not available. */
    NMALaneInformationRecommendationStateNotAvailable
} NS_SWIFT_NAME(NMALaneInformationRecommendation);

/**
 * Marking types for the divider and center marking.
 *
 * See also `NMALaneInformation`
 */
typedef NS_ENUM(NSUInteger, NMALaneInformationMarkingType) {
    /** Not Available */
    NMALaneInformationMarkingTypeNotAvailable,

    /** Long dashed */
    NMALaneInformationMarkingTypeLongDashed,

    /** Double solid line */
    NMALaneInformationMarkingTypeDoubleSolidLine,

    /** Single solid line */
    NMALaneInformationMarkingTypeSingleSolidLine,

    /** Double inner single outer dashed */
    NMALaneInformationMarkingTypeDoubleInnerSingleOuterDashed,

    /** Double inner dashed outer single */
    NMALaneInformationMarkingTypeDoubleInnerDashedOuterSingle,

    /** Short dashed */
    NMALaneInformationMarkingTypeShortDashed,

    /** Shared area */
    NMALaneInformationMarkingTypeSharedArea,

    /** Dashed blocks */
    NMALaneInformationMarkingTypeDashedBlocks,

    /** Physical divider */
    NMALaneInformationMarkingTypePhysicalDivider,

    /** Double dashed */
    NMALaneInformationMarkingTypeDoubleDashed,

    /** No divider */
    NMALaneInformationMarkingTypeNoDivider,

    /** Crossing alert */
    NMALaneInformationMarkingTypeCrossingAlert
} NS_SWIFT_NAME(NMALaneInformationMarking);

/**
 * Crossing restriction to enter or exit a HOV lane.
 *
 * See also `NMALaneInformation`
 */
typedef NS_ENUM(NSUInteger, NMALaneInformationCrossingRestriction) {
    /** No restriction */
    NMALaneInformationCrossingRestrictionNoRestriction,

    /** Left restriction */
    NMALaneInformationCrossingRestrictionLeft,

    /** Right restriction */
    NMALaneInformationCrossingRestrictionRight,

    /** Both directions restricted */
    NMALaneInformationCrossingRestrictionBoth
};


/**
 * Gives information about a lane, e.g. its type, direction and recommendation state.
 */
@interface NMALaneInformation : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * All the directions the lane leads to as an OR combination of one or more NMALaneInformationDirection values.
 *
 * @note directions can be used as a bitmask (e.g. for efficient indexing of image resources).
 */
@property (nonatomic, readonly) NMALaneInformationDirection directions;

/**
 * Gets the matched direction to the current maneuver on the route.
 *
 * @note If there is no matched direction or maneuver is nil then
 * NMALaneInformationDirectionMaskUndefined is returned.
 */
@property (nonatomic, readonly) NMALaneInformationDirection matchedDirection;

/**
 * Gets whether the direction of the lane is synthetic.
 *
 * @note Synthetic directions are derived from the connectivity of the lane. Non-synthetic directions
 * represent actual physical arrows printed on the lane.
 */
@property (nonatomic, readonly, getter = isSyntheticDirection) BOOL syntheticDirection;

/**
 * Gets the recommendation state of the lane according to the current route.
 *
 * @note If the map data does not provide connectivity information for this lane, then the
 * recommendation state is set to NMALaneInformationRecommendationStateNotAvailable.
 */
@property (nonatomic, readonly) NMALaneInformationRecommendationState recommendationState;

/**
 * Returns whether this is a regular lane.
 *
 * @note Regular lanes are lanes which have no specific use (i.e. they are not a special type such as hov, reversible, etc.)
 */
@property (nonatomic, readonly, getter = isRegular) BOOL regular;

/**
 * Returns whether this is a high occupancy vehicle (HOV) lane.
 *
 * @note A HOV lane (or carpool lane) is reserved for carpool usage. Carpool lane requires a minimum number of
 * passengers in order for the car to use the carpool lane. HOV lanes may also be reserved for hybrids, motorcycles,
 * alternate fuel, etc. HOV Lane may require a fee
 */
@property (nonatomic, readonly, getter = isHov) BOOL hov;

/**
 * Returns whether this is a reversible lane.
 *
 * @note A reversible lane is a lane in which traffic may travel in either direction, depending on
 * certain conditions (also known as a tidal flow lane).
 */
@property (nonatomic, readonly, getter = isReversible) BOOL reversible;

/**
 * Returns whether this is an express lane.
 */
@property (nonatomic, readonly, getter = isExpress) BOOL express;

/**
 * Returns whether this is an acceleration lane.
 *
 * @note An acceleration lane (or merge lane) allows traffic entering a highway to accelerate
 * to the speed of through traffic before merging with it.
 */
@property (nonatomic, readonly, getter = isAcceleration) BOOL acceleration;

/**
 * Returns whether this is a deceleration lane.
 *
 * @note A deceleration lane is a lane adjacent to the primary road or street allowing drivers
 * to pull out of the through lane and decelerate safely before turning off a surface street or exiting a freeway.
 */
@property (nonatomic, readonly, getter = isDeceleration) BOOL deceleration;

/**
 * Returns whether this is an auxiliary lane.
 *
 * @note An auxiliary lane is a lane other than a through lane, used to separate entering, exiting or turning traffic from the through traffic.
 */
@property (nonatomic, readonly, getter = isAuxLane) BOOL auxLane;

/**
 * Returns whether this is a slow lane.
 */
@property (nonatomic, readonly, getter = isSlow) BOOL slow;

/**
 * Returns whether this is a passing lane.
 */
@property (nonatomic, readonly, getter = isPassing) BOOL passing;

/**
 * Returns whether this is a regulated access lane.
 *
 * @note (Trucks only) A regulated access lane is a lane designated as a holding zone, used to regulate traffic using time intervals.
 */
@property (nonatomic, readonly, getter = isRegulatedAccess) BOOL regulatedAccess;

/**
 * Returns whether this is a driveable shoulder lane.
 *
 * @note A shoulder lane is reserved paved area on the side of the road (one or both sides) that are not
 * generally used for driving, although it is possible under certain circumstances. Only shoulder lanes
 * designated as a part-time driving lanes are included.
 */
@property (nonatomic, readonly, getter = isDriveableShoulder) BOOL driveableShoulder;

/**
 * Returns whether this is a turn lane.
 *
 * @note Turn lane is an extra lane that is used for making a turn in order not to disrupt ongoing traffic.
 */
@property (nonatomic, readonly, getter = isTurn) BOOL turn;

/**
 * Returns whether this is a center turn lane.
 *
 * @note Center turn lane is a bidirectional turn lane located in the middle of a road that allows traffic
 * in both directions to turn left (right for left side driving countries).
 */
@property (nonatomic, readonly, getter = isCenterTurn) BOOL centerTurn;

/**
 * Returns whether this is a truck parking lane.
 *
 * @note Truck parking lanes are wide shoulder lane that maybe used for truck parking as well as for emergency.
 */
@property (nonatomic, readonly, getter = isTruckParking) BOOL truckParking;

/**
 * Gets the divider marking type for side marks.
 *
 * @note Divider markings are markings between lanes of same direction
 */
@property (nonatomic, readonly) NMALaneInformationMarkingType dividerMarking;

/**
 * Gets the divider marking type for the center mark.
 *
 * @note Center markings are markings between lanes in opposite direction.
 */
@property (nonatomic, readonly) NMALaneInformationMarkingType centerMarking;

/**
 * Gets the speed limit on this lane in the positive lane direction in km/h. Zero if the
 * speed limit is not available. In the case of zero, the speed limit is the speed limit of the
 * whole road (see `NMARoadElement`).
 */
@property (nonatomic, readonly) NSUInteger speedLimit;

/**
 * Gets the height restriction in cm or zero if there is no restriction or it is unknown.
 */
@property (nonatomic, readonly) NSUInteger heightRestriction;

/**
 * Gets the lane width in cm or zero if the lane width is not available.
 */
@property (nonatomic, readonly) NSUInteger width;

/**
 * Gets the crossing restriction of the lane. This indicates if it is illegal to enter or exit a lane.
 */
@property (nonatomic, readonly) NMALaneInformationCrossingRestriction crossingRestriction;

@end
