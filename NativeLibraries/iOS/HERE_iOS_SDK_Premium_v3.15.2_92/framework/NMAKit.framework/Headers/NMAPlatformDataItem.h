/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;

/**
 * Type of the condition entity as described by the CONDITION_TYPE field.
 */
typedef NS_ENUM(NSUInteger, NMAPlatformDataConditionType) {
    /** Indicates that the condition type is undefined. */
    NMAPlatformDataConditionTypeUndefined NS_SWIFT_NAME(undefined)                                  = 0,

    /** Indicates toll structure. */
    NMAPlatformDataConditionTypeTollStructure NS_SWIFT_NAME(tollStructure)                          = 1,

    /** Indicates construction status closed. */
    NMAPlatformDataConditionTypeConstructionStatusClosed NS_SWIFT_NAME(constructionStatusClosed)    = 3,

    /** Indicates gates. */
    NMAPlatformDataConditionTypeGates NS_SWIFT_NAME(gates)                                          = 4,

    /** Indicates direction of travel. */
    NMAPlatformDataConditionTypeDirectionOfTravel NS_SWIFT_NAME(directionOfTravel)                  = 5,

    /** Indicates restricted driving manoeuvre. */
    NMAPlatformDataConditionTypeRestrictedDrivingManoeuvre NS_SWIFT_NAME(restrictedDrivingManoeuvre)= 7,

    /** Indicates access restriction. */
    NMAPlatformDataConditionTypeAccessRestriction NS_SWIFT_NAME(accessRestriction)                  = 8,

    /** Indicates special explication. */
    NMAPlatformDataConditionTypeSpecialExplication NS_SWIFT_NAME(specialExplication)                = 9,

    /** Indicates special speed situation. */
    NMAPlatformDataConditionTypeSpecialSpeedSituation NS_SWIFT_NAME(specialSpeedSituation)          = 10,

    /** Indicates variable speed sign. */
    NMAPlatformDataConditionTypeVariableSpeedSign NS_SWIFT_NAME(variableSpeedSign)                  = 11,

    /** Indicates usage fee required. */
    NMAPlatformDataConditionTypeUsageFeeRequired NS_SWIFT_NAME(usageFeeRequired)                    = 12,

    /** Indicates lane traversal. */
    NMAPlatformDataConditionTypeLaneTraversal NS_SWIFT_NAME(laneTraversal)                          = 13,

    /** Indicates through route. */
    NMAPlatformDataConditionTypeThroughRoute NS_SWIFT_NAME(throughRoute)                            = 14,

    /** Indicates traffic signal. */
    NMAPlatformDataConditionTypeTrafficSignal NS_SWIFT_NAME(trafficSignal)                          = 16,

    /** Indicates traffic sign. */
    NMAPlatformDataConditionTypeTrafficSign NS_SWIFT_NAME(trafficSign)                              = 17,

    /** Indicates railway crossing. */
    NMAPlatformDataConditionTypeRailwayCrossing NS_SWIFT_NAME(railwayCrossing)                      = 18,

    /** Indicates no overtaking. */
    NMAPlatformDataConditionTypeNoOvertaking NS_SWIFT_NAME(noOvertaking)                            = 19,

    /** Indicates junction view. */
    NMAPlatformDataConditionTypeJunctionView NS_SWIFT_NAME(junctionView)                            = 20,

    /** Indicates protected overtaking. */
    NMAPlatformDataConditionTypeProtectedOvertaking NS_SWIFT_NAME(protectedOvertaking)              = 21,

    /** Indicates evacuation route. */
    NMAPlatformDataConditionTypeEvacuationRoute NS_SWIFT_NAME(evacuationRoute)                      = 22,

    /** Indicates transport access restriction. */
    NMAPlatformDataConditionTypeTransportAccessRestriction NS_SWIFT_NAME(transportAccessRestriction)= 23,

    /** Indicates transport special speed situation. */
    NMAPlatformDataConditionTypeTransportSpclSpdSituation NS_SWIFT_NAME(transportSpclSpdSituation)  = 25,

    /** Indicates transport restricted driving manoeuvre. */
    NMAPlatformDataConditionTypeTransportRdm NS_SWIFT_NAME(transportRdm)                            = 26,

    /** Indicates transport preferred route. */
    NMAPlatformDataConditionTypeTransportPreferredRoute NS_SWIFT_NAME(transportPreferredRoute)      = 27,

    /** Indicates calculated restricted driving manoeuvre. */
    NMAPlatformDataConditionTypeCalculatedRestrictedDrivingManoeuvre NS_SWIFT_NAME(calculatedRestrictedDrivingManoeuvre) = 30,

    /** Indicates parking information. */
    NMAPlatformDataConditionTypeParkingInformation NS_SWIFT_NAME(parkingInformation)                = 31,

    /** Indicates environmental zone. */
    NMAPlatformDataConditionTypeEnvironmentalZone NS_SWIFT_NAME(environmentalZone)                  = 34,

    /** Indicates blackspot. */
    NMAPlatformDataConditionTypeBlackspot NS_SWIFT_NAME(blackspot)                                  = 38,

    /** Indicates permitted driving manoeuvre. */
    NMAPlatformDataConditionTypePermittedDrivingManoeuvre NS_SWIFT_NAME(permittedDrivingManoeuvre)  = 39,

    /** Indicates variable speed limit. */
    NMAPlatformDataConditionTypeVariableSpeedLimit NS_SWIFT_NAME(variableSpeedLimit)                = 40,

    /** Indicates short construction warning. */
    NMAPlatformDataConditionTypeShortConstructionWarning NS_SWIFT_NAME(shortConstructionWarning)    = 41
};

/**
 * The possible vehicle types that are allowed on a link
 *        as described by the VEHICLE_TYPES field.
 */
typedef NS_OPTIONS(NSUInteger, NMAPlatformDataVehicleType) {
    /** Indicates that the vehicle type is undefined. */
    NMAPlatformDataVehicleTypeUndefined         NS_SWIFT_NAME(undefined)= 0,

    /** Indicates automobiles. */
    NMAPlatformDataVehicleTypeAutomobiles       NS_SWIFT_NAME(automobiles)= 1 << 0,

    /** Indicates buses. */
    NMAPlatformDataVehicleTypeBuses             NS_SWIFT_NAME(buses)= 1 << 1,

    /** Indicates taxis. */
    NMAPlatformDataVehicleTypeTaxis             NS_SWIFT_NAME(taxis)= 1 << 2,

    /** Indicates car pools. */
    NMAPlatformDataVehicleTypeCarPools          NS_SWIFT_NAME(carPools)= 1 << 3,

    /** Indicates pedestrians. */
    NMAPlatformDataVehicleTypePedestrians       NS_SWIFT_NAME(pedestrians)= 1 << 4,

    /** Indicates trucks. */
    NMAPlatformDataVehicleTypeTrucks            NS_SWIFT_NAME(trucks)= 1 << 5,

    /** Indicates deliveries. */
    NMAPlatformDataVehicleTypeDeliveries        NS_SWIFT_NAME(deliveries)= 1 << 6,

    /** Indicates emergency vehicles. */
    NMAPlatformDataVehicleTypeEmergencyVehicles NS_SWIFT_NAME(emergencyVehicles)= 1 << 7,

    /** Indicates through traffic.*/
    NMAPlatformDataVehicleTypeThroughTraffic    NS_SWIFT_NAME(throughTraffic)= 1 << 8,

    /** Indicates motorcycles. */
    NMAPlatformDataVehicleTypeMotorcycles       NS_SWIFT_NAME(motorcycles)= 1 << 9,

    /** Indicates road trains. */
    NMAPlatformDataVehicleTypeRoadTrains        NS_SWIFT_NAME(roadTrains)= 1 << 10,

    /** Indicates all the above types. */
    NMAPlatformDataVehicleTypeAll               NS_SWIFT_NAME(all)= 0x7FF
};



/**
 * After a Platform Data Request run, each layer data is returned with objects
 * of this class. The properties are just helper shortcuts for the most used fields.
 * That is for any data not accessed via the properties, the users can access them
 * directly. For example, assume item is an object of NMAPlatformDataItem type.
 * Then, item[@"COUNTRY_ID"] returns the COUNTRY_ID string and nil if the item has
 * no such data.
 */
@interface NMAPlatformDataItem : NSObject <NSCopying>

/**
 * Do not directly instantiate an instance of this class.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

#pragma mark - Shortcut properties

/**
 * LINK_ID data.
 *
 * Positive 64 bit Integer that globally identifies the road, carto or buildin footprint link,
 * also across map releases. Link IDs are never reused.
 *
 * However, it is returned as an NString object. It can be converted to numeric value via the
 * [NString longLongValue] method.
 *
 * @note It is nil if not set.
 */
@property (nullable, nonatomic, weak, readonly) NSString *linkId;

/**
 * LAT & LON data.
 *
 * Latitude & longitude coordinates [10^-5 degree WGS84] along the polyline or of the reference node
 * and the non reference node. Comma separated. Each value is relative to the previous.
 *
 * The LAT & LON strings are converted into an NSArray of NMAGeoCoordinates.
 *
 * @note It is nil if not set.
 */
@property (nullable, nonatomic, weak, readonly) NSArray<NMAGeoCoordinates*> *coordinates;

/**
 * LINK_LENGTH data.
 *
 * The link length in meter. This attribute publishes the whole link length, no matter whether the link
 * spans across several tiles. The link length is computed by straight lines between subsequent shape
 * points, no splines or other smoothing functions or geodesic computations are used.
 *
 * @note It is -1.0f if not set.
 */
@property (nonatomic, readonly) float linkLengthMeter;

/**
 * LINK_IDS data.
 *
 * Comma separated list of Permanent link IDs that describe a route path. A negative sign means that
 * this link was driven towards reference node. If the list contains only one link, then a 'B' prefix
 * tells that it applies for both driving directions. Each link ID is a positive 64 bit Integer that
 * globally identifies the road link, also across map releases. Link IDs are never reused.
 *
 * @note It is nil if not set.
 */
@property (nullable, nonatomic, weak, readonly) NSArray <NSString*> *linkIds;

/**
 * CONDITION_TYPE data.
 *
 * Type of the condition entity.
 *
 * @note It is NMAPlatformDataConditionTypeUndefined if not set.
 *
 * See also `NMAPlatformDataConditionType`
 */
@property (nonatomic, readonly) NMAPlatformDataConditionType conditionType;

/**
 * VEHICLE_TYPES data.
 *
 * Access Characteristics identify the vehicle types that are allowed on a link, allowed on a lane or to which
 * condition applies.
 *
 * 16 bit bitmask of affected vehicle types or functions. Sum of: Automobiles (1), buses (2), taxis (4), car
 * pools (8), pedestrians (16), trucks (32), deliveries (64), emergency vehicles (128), through traffic (256),
 * motorcycles (512) and road trains (1024).
 *
 * @note It is NMAPlatformDataVehicleTypeUndefined if not set.
 *
 * See also `NMAPlatformDataVehicleType`
 */
@property (nonatomic, readonly) NMAPlatformDataVehicleType vehicleTypes;

/**
 * DTM_AVG_HEIGHT data.
 *
 * The average height [cm above WGS84 ellipsoid] along the link.
 *
 * @note It is NSIntegerMax if not set.
 */
@property (nonatomic, readonly) NSInteger averageHeightCm;

#pragma mark - Methods

/**
 * Returns the data associated with a given key.
 *
 * @param key The key for the data requested.
 *
 * @return The associated data or nil if the key isn't
 *         found in result.
 */
- (nullable NSString *)objectForKeyedSubscript:(nonnull NSString *)key;

/**
 * Returns all the key strings.
 *
 * @return The array of all the keys.
 */
- (nullable NSArray<NSString *> *)allKeys;

/**
 * Returns the all the value strings.
 *
 * @return All the value strings contained in the item.
 */
- (nullable NSArray<NSString *> *)allValues;

/**
 * Applies a given block object to the entries in the item.
 */
- (void)enumerateKeysAndObjectsUsingBlock:(void (^_Nonnull)(NSString * _Nonnull key, NSString * _Nonnull obj, BOOL * _Nonnull stop))block;

/**
 * Extracts the data contained into a dictionary.
 *
 * @return A dictionary of the string key/value pairs.
 */
- (nullable NSDictionary<NSString *, NSString *> *)extract;

/**
 * The number of entries in the item.
 */
@property (readonly) NSUInteger count;

@end
