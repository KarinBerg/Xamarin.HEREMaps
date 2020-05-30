/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMATrafficSign;
@class NMARoutingMode;

NS_ASSUME_NONNULL_BEGIN

/**
 * Attributes of a road element.
 */
typedef NS_ENUM(NSUInteger, NMARoadElementAttribute) {
    NMARoadElementAttributeUndefined                = 0x00000000,

    /** Road direction. */
    NMARoadElementAttributeDirectionNoCars          = 0x00000000,
    NMARoadElementAttributeDirectionForward         = 0x00000001,
    NMARoadElementAttributeDirectionBackward        = 0x00000002,
    NMARoadElementAttributeDirectionBoth            = 0x00000003,

    /** Road type.      */
    NMARoadElementAttributeDirtRoad                 = 0x00000100,
    NMARoadElementAttributeUsageFeeRequired         = 0x00000200,
    NMARoadElementAttributeCarpool                  = 0x00000400,
    NMARoadElementAttributeUrban                    = 0x00000800,
    NMARoadElementAttributeTollroad                 = 0x00001000,
    NMARoadElementAttributeNoThroughTraffic         = 0x00002000,
    NMARoadElementAttributeTunnel                   = 0x00004000,
    NMARoadElementAttributeSliproad                 = 0x00040000,
    NMARoadElementAttributeHighway                  = 0x00080000,
    NMARoadElementAttributeUnderConstruction        = 0x00100000,
    NMARoadElementAttributeHasLaneDir               = 0x00200000,
    NMARoadElementAttributeHasLaneExit              = 0x00400000,
    NMARoadElementAttributeFerry                    = 0x00800000,
    NMARoadElementAttributeRailFerry                = 0x01000000,

    NMARoadElementAttributeDirectionNoTruck         = 0x02000000,
    NMARoadElementAttributeDirectionTruckForward    = 0x04000000,
    NMARoadElementAttributeDirectionTruckBackward   = 0x08000000,
    NMARoadElementAttributeDirectionTruckBoth       = 0x0C000000,
    NMARoadElementAttributeSchoolZone               = 0x10000000
};

/**
 * Road element classifications.
 *
 * The NMARoadElementType describes the nature of the road that a NMARoadElement
 * is part of. A road element may only have one type, or none if the road is an
 * unclassified type or the information is not available.
 */
typedef NS_ENUM(NSUInteger, NMARoadElementType) {
    /**
     * Road form of way is undefined/unknown.
     */
    NMARoadElementTypeUndefined = 0,

    /**
     * Road to which regulations will normally apply with regards to entry and use. It has two
     * or more mostly physically separated carriageways and no single level-crossings. Also
     * known as a freeway or expressway.
     */
    NMARoadElementTypeMotorway,

    /**
     * Road with physically separated carriageways regardless of the number of lanes, which is
     * not a motorway or a freeway.
     */
    NMARoadElementTypeMultiCarriageway,

    /**
     * Road where the traffic is not separated by any physical object.
     */
    NMARoadElementTypeSingleCarriageway,

    /**
     * Road which forms a ring on which traffic travelling in only one direction is allowed.
     */
    NMARoadElementTypeRoundabout,

    /**
     * Road especially designed to enter or exit another road.
     */
    NMARoadElementTypeSliproad,

    /**
     * Road within an area specially designed for use by pedestrians.
     */
    NMARoadElementTypePedestrianZone,

    /**
     * Paved or unpaved road for exclusive pedestrian use. These walkways are closed to bicycles
     * and normal vehicles.
     */
    NMARoadElementTypePedestrianWalkway,

    /**
     * Road running parallel to, and designed to connect, a road with a relatively high
     * connectivity function with roads with a lower connectivity function.
     */
    NMARoadElementTypeServiceAccess,

    /**
     * Road within an area specially designed for use by pedestrian only
     * but not pedestrian zone (e.g. forest road).
     */
    NMARoadElementTypePedestrianOnly
};

/**
 * Plural type identifies when a Junction is made up of multiple Road Elements.
 * It also implies that a maneuver may require different explication than implied
 * by the geometry.
 */
typedef NS_ENUM(NSUInteger, NMARoadElementPluralType) {
    /** Junction is not plural */
    NMARoadElementPluralTypeNone = 0,

    /**
     * Indicates that only one command should be given despite the fact that two
     * Junctions occur – one at each end of the turn lane. It is only necessary to
     * state "turn left/right" near the beginning of the maneuver because at the
     * end the driver does not have a choice in direction.
     */
    NMARoadElementPluralTypeManeuver,

    /**
     * Indicates that a road segment should not be viewed as an individual piece of
     * road but as part of the intersection. A separate guidance manoeuvre should
     * not exist for this segment.
     */
    NMARoadElementPluralTypeConnector,

    /**
     * Indicates a maneuver that cannot be explained in one command or at all. A
     * graphic may be needed to illustrate the turn. For example, a driver may need
     * to go right to make a left turn.
     */
    NMARoadElementPluralTypeIndeterminate
};


/**
 * Represents a section of a road.
 *
 * To determine whether an object is the same as this NMARoadElement, use isEqual:.
 * isEqual returns YES if all properties of the objects contain the same values.
 * Please note that road elements from different sources may contain different
 * attributes for the same road element, e.g. road elements from NMATrafficEvent
 * v.s. road elements from NMAManeuver. Compare uniqueIds of two road elements if
 * you only want to know whether they are the same road elements with the same
 * geometries.
 */
@interface NMARoadElement : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The unique identifier of the NMARoadElement.
 */
@property (nonatomic, readonly, weak, nullable) NSString *uniqueId;

/**
 * The Permanent Link ID (stable across different map versions) of the NMARoadElement.
 * This property is unavailable when the public transport mode (NMATransportModePublicTransport) is
 * used. For all the other transport modes, it is available only in routes calculated with the online
 * connectivity mode (NMACoreRouterConnectivityOnline).
 * When not available, 0 is returned.
 */
@property (nonatomic, readonly) NSUInteger permanentLinkId;

/**
 * The Permanent Link ID (stable across different map versions) of the NMARoadElement with travel
 * direction: positive sign (+) means driving in the 'canonical' direction of the road and negative
 * sign (-) means driving against the 'canonical' direction of the road. Every road element has two endpoints.
 * Starting from which end point the link is being traversed? Each link has a geometry associated with it.
 * The geometry gives the link a 'canonical' direction: if you traverse the link in the direction the geometry
 * is stored, you are traveling in the positive direction. Otherwise, you are traveling in the negative
 * direction. The assigned 'canonical' direction is completely arbitrary and no assumption should be made about
 * it.
 * This property is unavailable when the public transport mode (NMATransportModePublicTransport) is
 * used. For all the other transport modes, it is available only in routes calculated with the online
 * connectivity mode (NMACoreRouterConnectivityOnline).
 * When not available, 0 is returned.
 */
@property (nonatomic, readonly) NSInteger permanentDirectedLinkId;

/**
 * The attributes of the NMARoadElement. Can be a combination of any values
 * from NMARoadElementAttribute.
 */
@property (nonatomic, readonly) NSUInteger attributes;

/**
 * The type of the road element.
 *
 * See also `NMARoadElementType`
 */
@property (nonatomic, readonly) NMARoadElementType type;

/**
 * The plural type of the road element.
 *
 * See also `NMARoadElementPluralType`
 */
@property (nonatomic, readonly) NMARoadElementPluralType pluralType;

/**
 * The name of the road that contains this current road element, such
 * as "Still Creek Drive",
 * or an empty string if the data is not available or unknown,
 * such as when the road element is on an unnamed service alley.
 */
@property (nonatomic, readonly, weak, nullable) NSString *roadName;

/**
 * The abbreviated name of the road element. For example,
 * I5 for the Interstate 5 in the US. This property will contain an
 * empty string if the abbreviated name is unavailable.
 */
@property (nonatomic, readonly, weak, nullable) NSString *abbreviatedName;

/**
 * The speed limit of the NMARoadElement in m/s, or 0 if
 * the information is not available.
 */
@property (nonatomic, readonly) float speedLimit;

/**
 * The average speed of traffic on the NMARoadElement in m/s,
 * or 0 if the information is not available.
 */
@property (nonatomic, readonly) NSUInteger averageSpeed;

/**
 * The number of lanes of the road element, or 0 if the
 * data is unavailable.
 */
@property (nonatomic, readonly) NSUInteger numberOfLanes;

/**
 * Gets the list of `NMATrafficSign` objects within the road element object.
 *
 * @param error A pointer to error object that indicates why the request failed,
 *              or nil if the request was successful.
 *
 * @return The array of `NMATrafficSign` objects belonging to this `NMARoadElement`.
 */
- (NSArray<NMATrafficSign *> *_Nullable)trafficSignsOrError:(NSError *_Nullable *_Nullable)error
NS_SWIFT_NAME(trafficSigns());

@end

NS_ASSUME_NONNULL_END
