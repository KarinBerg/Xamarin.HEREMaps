/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARequest.h"


/**
 * Reverse Geocode Mode type enum
 */
typedef NS_ENUM(NSUInteger, NMAReverseGeocodeMode) {
    /** Search for the closest street address or addresses. */
    NMAReverseGeocodeModeRetrieveAddresses = 0,
    /** Retrieve the administrative area information for the position provided in the request. */
    NMAReverseGeocodeModeRetrieveAreas,
    /**  Search for landmarks like parks and lakes in the proximity provided in the request. */
    NMAReverseGeocodeModeRetrieveLandmarks,
    /**
     * Search for streets, administrative areas and landmarks.
     * This mode aggregates the results of the three different modes in one call.
     */
    NMAReverseGeocodeModeRetrieveAll,
    /** Retrieve street information based on a position and bearing. */
    NMAReverseGeocodeModeTrackPosition
};


/**
 *
 * Represents a request to retrieve NMAPlaceLocation data by way of
 * NMAGeocoder search services.
 *
 * @note A `NMAReverseGeocodeRequest` is a kind of NMARequest, and its response is an instance
 * of NMAReverseGeocodeResult.
 */
@interface NMAReverseGeocodeRequest : NMARequest

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
