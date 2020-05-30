/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAAutoSuggest.h"


@class NMACategory;
@class NMAGeoBoundingBox;
@class NMAGeoCoordinates;
@class NMAPlaceRequest;


/**
 *
 * Represents a suggested place.
 *
 * See also `NMAAutoSuggestSearch`
 *
 * See also `NMAAutoSuggestQuery`
 */
@interface NMAAutoSuggestPlace : NMAAutoSuggest

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The NSString description of the location of the NMAPlace.
 *
 * Typically, this property is derived from the address, but could also
 * contain any other description that helps an application user understand
 * where the place is located.
 *
 * @note vicinity description for a place is optional. Attempts to read
 * this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *vicinityDescription;

/**
 * The `NMAGeoCoordinates` representing the geographical position of the NMAPlace.
 */
@property (nullable, nonatomic, readonly) NMAGeoCoordinates *position;

/**
 * The NSString representation of the category for the NMAPlace.
 */
@property (nullable, nonatomic, readonly) NSString *category;

/**
 * The enclosing `NMAGeoBoundingBox` describing a range of coordinates
 * that correspond to the NMAPlace. Typically, bounding boxes are
 * associated with places such as cities and countries.
 *
 * @note Bounding box information for a place is optional. Attempts to read
 * this property could return nil.
 */
@property (nullable, nonatomic, readonly) NMAGeoBoundingBox *boundingBox;

/**
 * Gets the `NMAPlaceRequest` to retrieve the NMAPlace details.
 */
- (nonnull NMAPlaceRequest *)placeDetailsRequest;

@end
