/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * Determines the side of driving.
 */
typedef NS_ENUM(NSUInteger, NMAEHMetaDataSideOfDriving) {
    NMAEHMetaDataSideOfDrivingRight,
    NMAEHMetaDataSideOfDrivingLeft,
    NMAEHMetaDataSideOfDrivingUnknown
};

/**
 * Determines the unit system.
 */
typedef NS_ENUM(NSUInteger, NMAEHMetaDataUnitSystem) {
    NMAEHMetaDataUnitSystemMetric,
    NMAEHMetaDataUnitSystemImperial,
    NMAEHMetaDataUnitSystemUnknown
};


/**
 * Represents common meta data of a `NMAEHLink`, which depends on the region of the link.
 */
@interface NMAEHMetaData : NSObject

/**
 * Represents the side of driving.
 */
@property (nonatomic) NMAEHMetaDataSideOfDriving sideOfDriving;

/**
 * Represents the unit system.
 */
@property (nonatomic) NMAEHMetaDataUnitSystem unitSystem;

/**
 * Represents the ISO 3166-1 numeric country code.
 */
@property (nonatomic) NSUInteger countryCode;

/**
 * Represents the ISO 3166-1 numeric region code.
 */
@property (nonatomic) NSUInteger regionCode;

@end
