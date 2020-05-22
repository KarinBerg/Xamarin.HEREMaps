/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * The installation status of a NMAMapPackage.
 */
typedef NS_ENUM(NSUInteger, NMAMapPackageInstallation) {
    /** The package is not installed */
    NMAMapPackageInstallationNone = 0,
    /** The package was installed through its parent */
    NMAMapPackageInstallationImplicit,
    /** The package was installed directly */
    NMAMapPackageInstallationExplicit,
    /**
     * The package is partially installed
     *
     * Some map data groups have not been downloaded or are damaged. In this state the map may not
     * be rendered correctly and data may not be available for other operations (e.g. routing).
     * Try to install the package again to download the missing data (only the delta will be
     * downloaded). Installing the missing data can be achieved by way of the
     * `NMAMapLoader::performMapDataUpdate` or `NMAMapLoader::installMapPackages:` APIs.
     */
    NMAMapPackageInstallationPartiallyInstalled
};

/**
 * The data groups which may be optionally selected for offline map downloads.
 *
 * The default data group selection state is:
 * \code
 *      Group                               Selected
 *      NMAMapDataGroupLinkGDBIdPVId        yes
 *      NMAMapDataGroupPhoneticNames        yes
 *      NMAMapDataGroupRealisticViews16x9   no
 *      NMAMapDataGroupRealisticViews3x5    no
 *      NMAMapDataGroupRealisticViews4x3    no
 *      NMAMapDataGroupRealisticViews5x3    no
 *      NMAMapDataGroupADAS                 no
 * \endcode
 *
 * See also `NMAMapLoader::selectDataGroup:(NMAMapDataGroup)dataGroup`
 *
 * Data groups not selected if access to this operation is denied.
 * Contact your HERE representative for more information.
 */
typedef NS_ENUM(NSInteger, NMAMapDataGroup) {
    /** Truck attributes. */
    NMAMapDataGroupTruckAttributes          = 12,
    /** Scooter route attributes. The data is needed for proper scooter navigation. */
    NMAMapDataGroupScooterAttributes        = 13,
    /** Low resolution 3D landmarks. */
    NMAMapDataGroupLowRes3DLandmarks        = 17,
    /** 3D terrain. */
    NMAMapDataGroupTerrain3D                = 18,
    /** Simplified Extruded Buildings. */
    NMAMapDataGroupSimpleExtrudedBuildings  = 20,
    /** Extended world wide POI (CartoPOI). */
    NMAMapDataGroupWorldwideExtendedPOI     = 21,
    /** Worldwide Point Addresses. */
    NMAMapDataGroupWorldwidePointAddresses  = 22,
    /** Mapping between GDBId and PVId. */
    NMAMapDataGroupLinkGDBIdPVId            = 26,
    /** Phonemes used for TTS guidance. */
    NMAMapDataGroupPhoneticNames            = 49,
    /** Images for used with the navigation realistic view feature, with 16x9 aspect ratio. */
    NMAMapDataGroupRealisticViews16x9       = 50,
    /** Images for used with the navigation realistic view feature, with 3x5 aspect ratio. */
    NMAMapDataGroupRealisticViews3x5        = 51,
    /** Images for used with the navigation realistic view feature, with 4x3 aspect ratio. */
    NMAMapDataGroupRealisticViews4x3        = 52,
    /** Images for used with the navigation realistic view feature, with 5x3 aspect ratio. */
    NMAMapDataGroupRealisticViews5x3        = 53,
    /** Height curvature and slope of shape points. */
    NMAMapDataGroupADAS                     = 54
};


/**
 * A collection of map data encompassing a particular region or country.
 *
 * Map data packages can be selectively installed or uninstalled using the
 * NMAMapLoader API. Installing a package makes its data available for offline
 * usage.
 *
 * @note NMAMapPackage objects are immutable; their properties will not change
 * after creation even if the state of the installed map data changes. In this
 * case, a new package list should be obtained.
 *
 * See also `NMAMapLoader`
 */
@interface NMAMapPackage : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The parent of the map package if one exists, nil otherwise.
 */
@property (nonatomic, readonly, weak, nullable) NMAMapPackage *parent;

/**
 * An immutable list of the children of the map package if any exist,
 * an empty list otherwise.
 */
@property (nonatomic, readonly, strong, nonnull) NSArray<NMAMapPackage *> *children;

/**
 * The unique ID of the map package. This is used to identify map packages
 * for install/uninstall operations.
 */
@property (nonatomic, readonly) NSInteger packageId;

/**
 * The human readable title of the map package. The language of the
 * title string is dependent upon the device locale.
 */
@property (nonatomic, readonly, nonnull) NSString *title;

/**
 * The title of the package in English.
 */
@property (nonatomic, readonly, nonnull) NSString *englishTitle;

/**
 * The maximum size (in KB) the map package will take up on disk.
 *
 * @note Actual install size may be smaller when multiple packages are installed.
 */
@property (nonatomic, readonly) long sizeOnDisk;

/**
 * Indicates whether or not this NMAMapPackage is currently installed on disk.
 */
@property (nonatomic, readonly) NMAMapPackageInstallation installationStatus;

@end
