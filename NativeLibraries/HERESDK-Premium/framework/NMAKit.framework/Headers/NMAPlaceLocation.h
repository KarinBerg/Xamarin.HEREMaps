/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAAddress;
@class NMAGeoBoundingBox;
@class NMAGeoCoordinates;
@class NMANavigationPosition;



/**
 * Represents a location on a map in terms of a street address and a geographical position.
 */
@interface NMAPlaceLocation : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The NMAAddress for the NMAPlaceLocation.
 */
@property (nullable, nonatomic) NMAAddress *address;

/**
 * The descriptive label for the NMAPlaceLocation.
 */
@property (nullable, nonatomic) NSString *label;

/**
 * NMAGeoCoordinates for the NMAPlaceLocation if available.
 *
 * @note If you want to create a route to this location please use this property
 * for NMAWaypoint creation. This is referred to as originalPosition in NMAWaypoint.
 */
@property (nullable, nonatomic) NMAGeoCoordinates *position;

/**
 * The bounding box of the place location if available.
 */
@property (nullable, nonatomic) NMAGeoBoundingBox *boundingBox;

/**
 * An array of NMANavigationPosition objects representing access points to the location.
 * The NMANavigationPosition should be used as navigablePosition of a NMAWaypoint
 * when calculating route to the location.
 *
 * For example, An aiport might have road access point for car routing and public
 * transport access points for public transport routing.
 */
@property (nullable, nonatomic, readonly) NSArray<NMANavigationPosition *> *accessPoints;

/**
 * Time zone in effect in this location. Only available for online Geocode results.
 */
@property (nullable, nonatomic, readonly) NSTimeZone *timeZone;

/**
 * Get reference identifiers for a specific source. For example, a place
 * can have a reference to an extruded building object in the map. The
 * reference identifiers can be retrieved by calling this method with source
 * NMAPlacesSourceBuilding.
 *
 * Index 0 is the primary reference identifier for the place.
 *
 * @note A reference identifier will not be returned if it has not been queried
 * with the (see `NMARequest::addSource:`).
 *
 * @param source `NSString` specifying the source.
 *
 * @return An NSArray of reference identifiers. Return nil if reference
 * identifier does not exist.
 */
- (nullable NSArray<NSString *> *)referenceIdentifiersForSource:(nonnull NSString *)source
NS_SWIFT_NAME(referenceIdentifiers(forSource:));

#pragma mark - DEPRECATED

@end
