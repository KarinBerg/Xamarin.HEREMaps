/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NMAGeoCoordinates;

/**
 * Defined traffic sign categories
 */
typedef NS_ENUM(NSUInteger, NMASignCategory) {
    /** Category is undefined */
    NMASignCategoryUnknown              = 0,
    /** Regulatory Sign */
    NMASignCategoryRegulatorySign       = 1,
    /** Informative Sign */
    NMASignCategoryInformativeSign      = 2,
    /** Warning Sign */
    NMASignCategoryWarningSign          = 3
};

/**
 * Defined traffic sign subcategories
 */
typedef NS_ENUM(NSUInteger, NMASignSubcategory) {
    /** Subcategory is undefined */
    NMASignSubcategoryUnknown       = 0,
    /** Priority Sign */
    NMASignSubcategoryPrioritySign  = 1
};

/**
 * Defined the traffic sign location at an intersection
 */
typedef NS_ENUM(NSUInteger, NMASignLocation) {
    /** Traffic Sign location is undefined */
    NMASignLocationUnknown              = 0,
    /** Traffic Sign is located on the right side in the direction of travel */
    NMASignLocationRight                = 1,
    /** Traffic Sign is located on the left side in the direction of travel */
    NMASignLocationLeft                 = 2,
    /** Traffic Sign is located overhead in the direction of travel */
    NMASignLocationOverhead             = 3
};

/**
 * Defined traffic sign link directions
 */
typedef NS_ENUM(NSUInteger, NMASignDirection) {
    /** Direction is undefined */
    NMASignDirectionUnknown     = 0,
    /** Positive direction */
    NMASignDirectionPositive    = 1,
    /** Negative direction */
    NMASignDirectionNegative    = 2,
    /** Both directions */
    NMASignDirectionBoth        = 3
};

/**
 * Defined transport types that the sign is applicable for
 */
typedef NS_ENUM(NSUInteger, NMASignTransportType) {
    /** Transport type is undefined */
    NMASignTransportTypeUnknown         = 0,
    /** Indicates that the sign is applicable for truck */
    NMASignTransportTypeTruck           = 1,
    /** Indicates that the sign is applicable for heavy truck */
    NMASignTransportTypeHeavyTruck      = 2,
    /** Indicates that the sign is applicable for bus */
    NMASignTransportTypeBus             = 3,
    /** Indicates that the sign is applicable for auto trailer */
    NMASignTransportTypeAutoTrailer     = 4,
    /** Indicates that the sign is applicable for motorhome */
    NMASignTransportTypeMotorhome       = 5,
    /** Indicates that the sign is applicable for motorcycle */
    NMASignTransportTypeMotorcycle      = 6
};

/**
 * Defined weather situations that affects the sign
 */
typedef NS_ENUM(NSUInteger, NMASignWeatherAffects) {
    /** The weather situation that affects the sign is undefined */
    NMASignWeatherAffectsUnknown    = 0,
    /** Rain */
    NMASignWeatherAffectsRain       = 1,
    /** Snow */
    NMASignWeatherAffectsSnow       = 2,
    /** Fog */
    NMASignWeatherAffectsFog        = 3
};


/**
 * Represents information about the traffic sign(road sign): such as type, category, location, etc.
 */
@interface NMATrafficSign : NSObject

/**
 * The current map geocoordinate for this traffic sign.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *coordinate;

/**
 * Type of the traffic sign.
 *
 *     List of the available traffic sign types:
 *
 *      1 - Start of No Overtaking
 *
 *      2 - End of No Overtaking
 *
 *      3 - Protected Overtaking-Extra Lane
 *
 *      4 - Protected Overtaking-Extra Lane (Right Side)
 *
 *      5 - Protected Overtaking-Extra Lane (Left Side)
 *
 *      6 - Lane Merge Right
 *
 *      7 - Lane Merge Left
 *
 *      8 - Lane Merge Center
 *
 *      9 - Railway Crossing Protected
 *
 *      10 - Railway Crossing Unprotected
 *
 *      11 - Road Narrows
 *
 *      12 - Sharp Curve Left
 *
 *      13 - Sharp Curve Right
 *
 *      14 - Winding Road starting Left
 *
 *      15 - Winding Road starting Right
 *
 *      16 - Start of No Overtaking Trucks
 *
 *      17 - End of No Overtaking Trucks
 *
 *      18 - Steep Hill Upwards
 *
 *      19 - Steep Hill Downwards
 *
 *      20 - Stop Sign
 *
 *      21 - Lateral Wind
 *
 *      22 - General Warning Sign
 *
 *      23 - Risk of Grounding
 *
 *      24 - General Curve
 *
 *      25 - End of all restrictions
 *
 *      26 - General Hill
 *
 *      27 - Animal Crossing
 *
 *      28 - Icy Conditions
 *
 *      29 - Slippery Road
 *
 *      30 - Falling Rocks
 *
 *      31 - School Zone
 *
 *      32 - Tramway Crossing
 *
 *      33 - Congestion Hazard
 *
 *      34 - Accident Hazard
 *
 *      35 - Priority over oncoming traffic
 *
 *      36 - Yield to oncoming traffic
 *
 *      37 - Crossing with Priority from the Right
 *
 *      41 - Pedestrian Crossing
 *
 *      42 - Yield
 *
 *      53 - No Engine Brake
 *
 *      54 - End of No Engine Brake
 *
 *      55 - No Idling
 *
 *      56 - Truck Rollover
 *
 *      57 - Low Gear
 *
 *      58 - End of Low Gear
 *
 *      59 - Bicycle Crossing
 *
 *      60 - Yield to Bicycles
 */
@property (nonatomic, readonly, assign) NSUInteger type;

/**
 * Category of this traffic sign.
 */
@property (nonatomic, readonly, assign) NMASignCategory category;

/**
 * Subcategory of this traffic sign.
 */
@property (nonatomic, readonly, assign) NMASignSubcategory subcategory;

/**
 * Location of this traffic sign.
 */
@property (nonatomic, readonly, assign) NMASignLocation location;

/**
 * Direction of this traffic sign.
 */
@property (nonatomic, readonly, assign) NMASignDirection direction;

/**
 * Subtype of this traffic sign
 * @note A subtype is available only for "General Warning Sign" sign (sign with type 22).
 *
 *  1 – Object Overhang is published only if an overhang sign of any type exists on
 *      a supplemental sign in reality.
 *
 *  2 – Risk of Grounding is published only if the risk of grounding sign exists on
 *      a supplemental sign in reality.
 *
 *  3 – Animal Crossing is published only if the animal crossing sign exists as supplemental
 *      sign in reality.
 *
 *  4 – Accident Hazard is published only if the accident hazard sign exists as supplemental
 *      sign in reality.
 */
@property (nonatomic, readonly, assign) NSUInteger subtype;

/**
 * Indicates the set of vehicle types `NMASignTransportType` which are affected by sign.
 *
 * See also `NMASignTransportType`.
 */
@property (nonatomic, readonly) NSSet <NSNumber *>* applicableForTransportTypes;

/**
 * Weather affects of this traffic sign.
 */
@property (nonatomic, readonly, assign) NMASignWeatherAffects weatherAffects;

/**
 * Textual description of the value visible on the sign.
 *
 * Traffic Sign Value is published for the following Traffic Sign Type values:
 *  18 (Steep Hill Upwards) and 19 (Steep Hill Downwards)
 */
@property (nonatomic, readonly) NSString *signValue;

/**
 * Text visible on supplemental sign indicating duration.
 * Text is localized according to current device's language.
 * If given language is not supported English version is returned.
 */
@property (nonatomic, readonly) NSString *duration;

/**
 * Text visible on supplemental sign indicating prewarning.
 * Text is localized according to current device's language.
 * If given language is not supported English version is returned.
 */
@property (nonatomic, readonly) NSString *prewarning;

/**
 * Text visible on supplemental sign indicating indicating specific time(s) at which
 * Traffic Sign is applicable. Text is localized according to current device's language.
 * If given language is not supported English version is returned.
 */
@property (nonatomic, readonly) NSString *validityTime;

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
