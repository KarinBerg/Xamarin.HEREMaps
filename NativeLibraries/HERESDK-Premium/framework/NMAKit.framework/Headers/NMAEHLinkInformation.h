/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


/**
 * Determines the allowed direction property for the NMAEHLink
 */
typedef NS_ENUM(NSUInteger, NMAEHLinkAllowedDirection) {
    NMAEHLinkAllowedDirectionForward,
    NMAEHLinkAllowedDirectionBackward,
    NMAEHLinkAllowedDirectionBoth,
    NMAEHLinkAllowedDirectionNone
};

/**
 * Determines the priority of the road for the NMAEHLink
 *
 * @note NMAEHLinkFunctionalRoadClass1 is the highest priority road
 * and the NMAEHLinkFunctionalRoadClass5 is lowest priority road.
 */
typedef NS_ENUM(NSUInteger, NMAEHLinkFunctionalRoadClass) {
    /**
     * Functional road class 1. These roads are meant for high volume,
     * maximum speed traffic between and through major metropolitan areas.
     * There are very few, if any, speed changes. Access to this road is
     * usually controlled.
     */
    NMAEHLinkFunctionalRoadClass1,
    /**
     * Functional road class 2. These roads are used to channel traffic to
     * Main Roads (`NMAEHLinkFunctionalRoadClass1`) for travel between and
     * through cities in the shortest amount of time. There are very few,
     * if any speed changes.
     */
    NMAEHLinkFunctionalRoadClass2,
    /**
     * Functional road class 3. These roads interconnect First Class Roads
     * (`NMAEHLinkFunctionalRoadClass2`) and provide a high volume of traffic
     * movement at a lower level of mobility than First Class Roads
     * (`NMAEHLinkFunctionalRoadClass2`).
     */
    NMAEHLinkFunctionalRoadClass3,
    /**
     * Functional road class 4. These roads provide for a high volume of
     * traffic movement at moderate speeds between neighborhoods. These
     * roads connect with higher Functional Class roads to collect and
     * distribute traffic between neighborhoods.
     */
    NMAEHLinkFunctionalRoadClass4,
    /**
     * Functional road class 5. These roads' volume and traffic movements
     * are below the level of any other road.
     */
    NMAEHLinkFunctionalRoadClass5
};

/**
 * Determines the form of the road for the NMAEHLink
 */
typedef NS_ENUM(NSUInteger, NMAEHLinkFormOfWay) {
    NMAEHLinkFormOfWayMultidigitized,
    NMAEHLinkFormOfWaySingleCarriage,
    NMAEHLinkFormOfWaySliproad,
    NMAEHLinkFormOfWayRoundaboutCircle,
    NMAEHLinkFormOfWaySpecialTrafficFigure,
    NMAEHLinkFormOfWayPedestrianZone,
    NMAEHLinkFormOfWayServiceRoad,
};


/**
 * Provides basic information about the `NMAEHLink` in electronic horizon.
 */
@interface NMAEHLinkInformation : NSObject

/**
 * The isBridge determines if this link is a bridge.
 */
@property (nonatomic) BOOL isBridge;

/**
 * The isDividedRoad determines if this link is a divided road.
 */
@property (nonatomic) BOOL isDividedRoad;

/**
 * The isTunnel determines if this link is a tunnel.
 */
@property (nonatomic) BOOL isTunnel;

/**
 * The isUrban determines if this link is urban.
 */
@property (nonatomic) BOOL isUrban;

/**
 * The isPedestrianOpen determines if this link is open to pedestrians.
 */
@property (nonatomic) BOOL isPedestrianOpen;

/**
 * The speedLimitMetersPerSecond is the speed limitation for the this link in meters per second.
 */
@property (nonatomic) double speedLimitMetersPerSecond;

/**
 * The lengthMeters is the length of the link in meters
 */
@property (nonatomic) double lengthMeters;

/**
 * Checks whether the link is open for cars with a certain direction.
 *
 * @param direction The direction for which the link will be checked.
 *
 * @return YES if link is open, otherwise NO.
 */
- (BOOL)isOpenForCars:(NMAEHLinkAllowedDirection)direction
NS_SWIFT_NAME(isOpenForCars(_:));

/**
 * Checks whether the link is open for cars to pass through with a certain direction.
 * A disallowed link should be avoided by cars, except when starting or stopping from
 * there.
 *
 * @param direction The direction for which the link will be checked.
 *
 * @return YES if link is allowed to pass, otherwise NO.
 */
- (BOOL)isCarThroughOpen:(NMAEHLinkAllowedDirection)direction
NS_SWIFT_NAME(isCarThroughOpen(_:));

/**
 * The functionalRoadClass determines the priority of the road.
 */
@property (nonatomic) NMAEHLinkFunctionalRoadClass functionalRoadClass;

/**
 * The formOfWay determines the form of way for the link.
 */
@property (nonatomic) NMAEHLinkFormOfWay formOfWay;

@end
