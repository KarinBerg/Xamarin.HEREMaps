/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAPlaceLocation;


/**
 * Represents an invalid geocoding result relevance
 */
FOUNDATION_EXPORT const float NMAGeocodeResultInvalidRelevance;



/**
 * Represents the result of a geocode request.
 *
 * The data of a geocode result is represented by an instance of NMAPlaceLocation,
 * accessed through the location property. The quality of the result can be
 * assessed in a broad sense with the relevance property, or in more detail using
 * the matchQuality dictionary.
 *
 * See also `NMAGeocodeRequest`
 */
@interface NMAGeocodeResult : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The location data of the geocode result.
 */
@property (nullable, nonatomic, readonly) NMAPlaceLocation *location;

/**
 * The relevance of the result location to the original search parameters.
 *
 * The relevance of a result provides a measure of how accurate or reliable it is.
 * The valid range is [0, 1], with a value of 1 representing a perfect match. If
 * relevancy data is unavailable (such as for an offline search), this property
 * will have the value `NMAGeocodeResultInvalidRelevance`.
 */
@property (nonatomic, readonly) float relevance;

/**
 * Details about the quality of the result.
 *
 * Additional information about the accuracy of the result is available in the
 * matchQuality dictionary. It contains one or more NSNumber values representing
 * how well each individual search parameter was matched. The values will be in
 * the range [0, 1] with a value of 1 indicating a perfect match.
 *
 * The possible keys are "State", "County", "City", "District", "Street",
 * "SecondaryStreet", "HouseNumber", and "PostalCode".
 *
 * @note The "SecondaryStreet" key will be present if an intersection was specified
 * in the geocode request. For example, if the request contained "1st St at 2nd Ave",
 * the "Street" key would access the match value for "1st St" and the "SecondaryStreet"
 * key would access the match value for "2nd Ave".
 */
@property (nullable, nonatomic, readonly) NSDictionary<NSString *, NSNumber *> *matchQuality;

/**
 * Shows the level of the most precise area information for the match,
 * district, city or a higher administrative level.
 *
 * The possible values are: "country", "state", "county", "city", "district", "street",
 * "intersection", "houseNumber", "postalCode" and "landmark".
 *
 * @note matchLevel always street for NMAReverseGeocodeModeTrackPosition mode results.
 */
@property (nullable, nonatomic, readonly) NSString *matchLevel;

@end
