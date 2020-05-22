/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <CoreGraphics/CoreGraphics.h>
#import "NMAVenue3dSpatialObject.h"

@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;
@class NMAVenue3dAnimationParameters;
@class NMAVenue3dContent;
@class NMAVenue3dLevel;
@class NMAVenue3dSpace;

/**
 * The Venue Maps 3D group provides classes, protocols, and enumerations
 * for representing a group of public buildings in a map.
 *
 */


/**
 *
 * NMAVenue3dVenue represents a public building or a group of public buildings in a map.
 *
 * Examples of public buildings are shopping malls and airports. Venues are displayed or hidden depending on map location.
 * 
 * A NMAVenue3dVenue object consists of one or more NMAVenue3dLevel objects. NMAVenue3dLevel, in turn,
 * consists of one or more NMAVenue3dOuterArea objects. NMAVenue3dOuterArea represents a physical form of
 * an outer area of certain level in the building. An NMAVenue3dOuterArea typically contains NMAVenue3dSpace
 * objects that represent, for example, single shops inside the venue.
 *
 * @note NMAVenue3dVenue cannot be instantiated directly. Instead, it can be obtained by calling
 * `NMAVenue3dController::venue` or
 * `NMAVenue3dServiceListener::venueService:didGetVenue:withVenueInfo:withStatus:`
 * callback.
 *
 * See also `NMAVenue3dLevel`
 *
 * See also `NMAVenue3dOuterArea`
 *
 * See also `NMAVenue3dSpace`
 *
 * See also `NMAVenue3dController`
 */
@interface NMAVenue3dVenue : NMAVenue3dSpatialObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The center of the NMAVenue3dVenue bounding box.
 */
@property (nonatomic, readonly, nonnull) NMAGeoCoordinates *geoCenter;

/**
 * The bounding box of this NMAVenue3dVenue.
 */
@property (nonatomic, readonly, nonnull) NMAGeoBoundingBox *boundingBox;

/**
 * The current floor number. For ground floor it's 0. For underground floors:
 * -1, -2, -3... For above ground floors: 1, 2, 3...
 */
@property (nonatomic, readonly) NSInteger floorNumber;

/**
 * The ground floor number.
 */
@property (nonatomic, readonly) NSInteger groundFloorNumber;

/**
 * The array of NMAVenue3dLevel objects of this NMAVenue3dVenue.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAVenue3dLevel *> *levels;

/**
 * The alphabetically level-wise ordered array of NMAVenue3dSpace objects for this NMAVenue3dVenue.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAVenue3dSpace *> *spaces;

/**
 * The NMAVenues3dContent object this NMAVenue3dVenue.
 */
@property (nonatomic, readonly, nullable) NMAVenue3dContent *content;

/**
 * Returns the space or the facility as the NMAVenue3dSpace object based on the given identifier
 * inside this NMAVenue3dVenue.
 *
 * @param  spaceId The NMAVenue3dSpace identifier
 *
 * @return The NMAVenue3dSpace object or nil if there is no NMAVenue3dSpace with this identifier.
 */
- (nullable NMAVenue3dSpace *)spaceWithId:(nonnull NSString *)spaceId
NS_SWIFT_NAME(space(id:));

/**
 * Returns spaces intersecting a circle with a given radius around the center of a space.
 *
 * @param space     The space around the center of which to search.
 * @param radius    The radius around the center of the space around which to search.
 *
 * @returns         A (possibly empty) array of nearby spaces.
 */
 - (nonnull NSArray<NMAVenue3dSpace *> *)nearbySpacesAroundSpace:(nonnull NMAVenue3dSpace *)space
                                                    withinRadius:(float)radius
NS_SWIFT_NAME(nearbySpaces(around:radius:));

@end
