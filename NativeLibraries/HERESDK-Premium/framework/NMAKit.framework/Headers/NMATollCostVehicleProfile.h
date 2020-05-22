/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


/**
 * Vehicle type for the `NMATollCostVehicleProfile`
 */
typedef NS_ENUM(NSUInteger, NMATollCostVehicleType) {
    /**
     * Indicates the vehicle type is motorcycle.
     */
    NMATollCostVehicleTypeMotorcycle        = 1,

    /**
     * Indicates the vehicle type is auto.
     */
    NMATollCostVehicleTypeAuto              = 2,

    /**
     * Indicates the vehicle type is truck.
     */
    NMATollCostVehicleTypeTruck             = 3,

    /**
     * Indicates the vehicle type is motor home.
     */
    NMATollCostVehicleTypeMotorHome         = 4,

    /**
     * Indicates the vehicle type is minibus.
     */
    NMATollCostVehicleTypeMinibus           = 5,

    /**
     * Indicates the vehicle type is bus.
     *         The scope is all the World.
     */
    NMATollCostVehicleTypeBus               = 6,

    /**
     * Indicates the vehicle type is motorcycle sidecar.
     */
    NMATollCostVehicleTypeMotorcycleSidecar = 7,

    /**
     * Indicates the vehicle type is tricyle.
     */
    NMATollCostVehicleTypeTricyle           = 8,

    /**
     * Indicates the vehicle type is delivery truck.
     */
    NMATollCostVehicleTypeDeliveryTruck     = 9,

    /**
     * Indicates the vehicle type is snowmobile.
     */
    NMATollCostVehicleTypeSnowmobile        = 10,

    /**
     * Indicates the vehicle type is pick-up.
     */
    NMATollCostVehicleTypePickUp            = 11,

    /**
     * Indicates the vehicle type is tractor.
     */
    NMATollCostVehicleTypeTractor           = 12,

    /**
     * Indicates the vehicle type is taxi.
     */
    NMATollCostVehicleTypeTaxi              = 13,

    /**
     * Indicates the vehicle type is HCM/EME.
     */
    NMATollCostVehicleTypeHcmEme            = 14
};

/**
 * Trailer type for the `NMATollCostVehicleProfile`
 */
typedef NS_ENUM(NSUInteger, NMATollCostTrailerType) {
    /** Indicates there is no trailer. */
    NMATollCostTrailerTypeNone    = 0,

    /** Indicates the trailer type is caravan. */
    NMATollCostTrailerTypeCaravan = 1,

    /** Indicates the trailer type is trailer. */
    NMATollCostTrailerTypeTrailer = 2
};

/**
 * Trailer count for the `NMATollCostVehicleProfile`
 */
typedef NS_ENUM(NSUInteger, NMATollCostTrailersCount) {
    /** Indicates a vehicle without trailer. */
    NMATollCostTrailersCountVehicleWithoutTrailer          = 0,

    /** Indicates a vehicle with one trailer. */
    NMATollCostTrailersCountVehicleWithOneTrailer          = 1,

    /** Indicates a vehicle with two trailers. */
    NMATollCostTrailersCountVehicleWithTwoTrailers         = 2,

    /** Indicates a vehicle with three or more trailers. */
    NMATollCostTrailersCountVehicleWithThreeOrMoreTrailers = 3
};

/**
 * Hybrid vehicle type for the `NMATollCostVehicleProfile`
 */
typedef NS_ENUM(NSUInteger, NMATollCostHybridType) {
    /** Indicates the vehicle is not hybrid. */
    NMATollCostHybridTypeNone = 0,

    /** Indicates the vehicle is partly running on electricity. */
    NMATollCostHybridTypePartlyRunningOnElectricity = 1
};

/**
 * Emission type for the `NMATollCostVehicleProfile`
 */
typedef NS_ENUM(NSUInteger, NMATollCostEmissionType) {
    /** Indicates the emission type is the not set. */
    NMATollCostEmissionTypeNone             = 0,

    /** Indicates the emission type is EURO I. */
    NMATollCostEmissionTypeEuroI            = 1,

    /** Indicates the emission type is EURO II. */
    NMATollCostEmissionTypeEuroII           = 2,

    /** Indicates the emission type is EURO III. */
    NMATollCostEmissionTypeEuroIII          = 3,

    /** Indicates the emission type is EURO IV. */
    NMATollCostEmissionTypeEuroIV           = 4,

    /** Indicates the emission type is EURO V. */
    NMATollCostEmissionTypeEuroV            = 5,

    /** Indicates the emission type is EURO VI. */
    NMATollCostEmissionTypeEuroVI           = 6,

    /** Indicates the emission type is EURO EEV. */
    NMATollCostEmissionTypeEuroEEV          = 7,

    /** Indicates the emission type is electric vehicles. */
    NMATollCostEmissionTypeElectricVehicles = 8
};

/**
 * Hazardous Goods type for the `NMATollCostVehicleProfile`
 */
typedef NS_ENUM(NSUInteger, NMATollCostShippedHazardousGoods) {
    /** Indicates there is no shipped hazardous goods. */
    NMATollCostShippedHazardousGoodsNone                 = 0,

    /** Indicates the shipped hazardous goods are explosives. */
    NMATollCostShippedHazardousGoodsExplosives           = 1,

    /** Indicates the shipped hazardous goods are any hazardous material. */
    NMATollCostShippedHazardousGoodsAnyHazardousMaterial = 2
};


/**
 * All the TCE parameters related with vehicle. Note that when the vehicle has
 * any trailer, all the trailer related properties need to be
 * set one-by-one.
 *
 * See also `NMATollCostVehicleProfile::trailerType`
 *
 * See also `NMATollCostVehicleProfile::trailersCount`
 *
 * See also `NMATollCostVehicleProfile::trailerNumberAxles`
 *
 * See also `NMATollCostVehicleProfile::trailerHeight`
 */
@interface NMATollCostVehicleProfile : NSObject

/** Vehicle type. The default value is NMATollCostVehicleTypeAuto */
@property (nonatomic) NMATollCostVehicleType vehicleType;

/** Trailer type. The default value is NMATollCostTrailerTypeNone */
@property (nonatomic) NMATollCostTrailerType trailerType;

/** Number of Trailer. The default value is NMATollCostTrailersCountVehicleWithoutTrailer */
@property (nonatomic) NMATollCostTrailersCount trailersCount;

/** Number of vehicle's axles. The default value is 2 */
@property (nonatomic) NSUInteger vehicleNumberAxles;

/** Number of Trailer's axles. The default value is 0 */
@property (nonatomic) NSUInteger trailerNumberAxles;

/** Vehicle running mode. The default value is NMATollCostHybridTypeNone */
@property (nonatomic) NMATollCostHybridType hybridType;

/** Vehicle emission type. The default value is NMATollCostEmissionTypeNone. */
@property (nonatomic) NMATollCostEmissionType emissionType;

/** Vehicle height in meter. The default value is 0. Negative values are ignored. */
@property (nonatomic) double height;

/** Trailer height in meter. The default value is 0. Negative values are ignored. */
@property (nonatomic) double trailerHeight;

/** Vehicle weight in tonne. The default value is 0. Negative values are ignored. */
@property (nonatomic) double vehicleWeight;

/** Total weight of the vehicle including trailer(s) or caravan in tonne.
 * The default value is 0. Negative values are ignored.
 */
@property (nonatomic) double limitedWeight;

/** If the vehicle is specially equipped for transporting disabled people. The default value is false. */
@property (nonatomic, getter = isDisabledEquipped) BOOL disabledEquipped;

/** Number of passengers can fit in vehicle. The default value is 1. */
@property (nonatomic) NSUInteger passengersCount;

/** Vehicle's tires count. The default value is 4. */
@property (nonatomic) NSUInteger tiresCount;

/** If the vehicle is designed for commercial use. The default value is false. */
@property (nonatomic, getter = isCommercial) BOOL commercial;

/** Hazardous goods transported in the vehicle. The default value is NMATollCostShippedHazardousGoodsNone. */
@property (nonatomic) NMATollCostShippedHazardousGoods shippedHazardousGoods;

/** Height above 1st axle in meters. The default value is 0. Negative values are ignored. */
@property (nonatomic) double heightAbove1stAxle;

@end
