/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;
@class NMAVenue3dArea;
@class NMAVenue3dOuterArea;
@class NMAVenue3dSpace;



/**
 *
 * Represents a storey in a venue.
 *
 * A NMAVenue3dVenue object consists of one or more NMAVenue3dLevel objects. The NMAVenue3dLevel object
 * in turn consist of one or more NMAVenue3dOuterArea objects.
 * 
 * NMAVenue3dLevel cannot be instantiated directly. Instead, it can be obtained by calling the
 * `NMAVenue3dVenue::levels`.
 *
 * See also `NMAVenue3dVenue`
 *
 * See also `NMAVenue3dOuterArea`
 *
 * See also `NMAVenue3dController`
 *
 */
@interface NMAVenue3dLevel : NSObject

/**
 * The array of NMAVenue3dOuterArea objects for this NMAVenue3dLevel.
 *
 * Depending on the physical appearance of the building, the NMAVenue3dLevel can consist of one or more separate
 * NMAVenue3dOuterArea objects. The NMAVenue3dOuterArea object can be used to get the NMAVenue3dSpace objects
 * related to the NMAVenue3dOuterArea objects.
 *
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAVenue3dOuterArea *> *outerAreas;

/**
 * The center of the NMAVenue3dLevel.
 */
@property (nonatomic, readonly, nonnull) NMAGeoCoordinates *geoCenter;

/**
 * The alphabetically ordered array of NMAVenue3dSpace objects for this NMAVenue3dLevel, excluding facilities.
 *
 * This method returns the requested NMAVenue3dSpace objects of all NMAVenue3dOuterArea objects of this
 * NMAVenue3dLevel object.
 *
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAVenue3dSpace *> *spaces;

/**
 * The alphabetically ordered array of NMAVenue3dSpace objects of all the NMAVenue3dOuterArea objects
 * of this NMAVenue3dLevel.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAVenue3dSpace *> *spacesAndFacilities;

/**
 * The alphabetically-ordered array of NMAVenue3dSpace objects belonging to given category
 * for this NMAVenue3dLevel. This method returns matching NMAVenue3dSpace objects for all NMAVenue3dOuterArea
 * objects for this NMAVenue3dLevel object.
 */
- (nonnull NSArray<NMAVenue3dSpace *> *)spacesWithCategory:(nonnull NSString *)categoryName
NS_SWIFT_NAME(spaces(category:));

/**
 * The floor synonym, for example: 1, B, P1, MEZZ etc.
 */
@property (nonatomic, readonly, nonnull) NSString *floorSynonym;

/**
 * The floor number. For ground floor it's 0. For underground floors: -1, -2, -3... For
 * above ground floors: 1, 2, 3...
 */
@property (nonatomic, readonly) NSInteger floorNumber;

/**
 * Returns the area inside the level at a given position.
 *
 * @param   position    The position at which to return the area.
 *
 * @return  The area or nil. The area may be a space or an outer area.
 */
- (nullable NMAVenue3dArea *)areaAtPosition:(nonnull NMAGeoCoordinates *)position
NS_SWIFT_NAME(area(at:));

/**
 * Returns spaces intersecting a circle with a given radius around a given position.
 *
 * @param position  The position around which to search.
 * @param radius    The radius around the position within which to search.
 *
 * @returns         A (possibly empty) array of nearby spaces.
 */
 - (nonnull NSArray<NMAVenue3dSpace *> *)nearbySpacesAroundPosition:(nonnull NMAGeoCoordinates *)position withinRadius:(float)radius
NS_SWIFT_NAME(nearbySpaces(around:radius:));

@end
