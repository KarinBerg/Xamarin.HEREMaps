/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMANavigationManager.h"
#import "NMARequest.h"


/**
 * Represents information about the country: such as code, metrics system, etc.
 */
@interface NMACountryInfo : NSObject

/**
 * Constructs a `NMACountryInfo` from country code.
 *
 * @param code Country code, named as in ISO 3166 alpha-3. Can't be null.
 */
- (nonnull instancetype)initWithCountryCode:(nonnull NSString*)code;

/**
 * The country code.
 */
@property (nonatomic, readonly, nonnull) NSString *code;

/**
 * The units measurement system used in this country.
 */
@property (nonatomic, readonly) NMAMeasurementSystem measurementSystem;

/**
 * A completion block used to handle the result of a country info request.
 *
 * @param countryInfo A `NMACountryCode` for a given coordinate. Could be nil.
 * @param error The error if the request failed, or nil if the request was successful.
 */
typedef void (^NMACountryInfoCompletionBlock)(NMACountryInfo * _Nullable countryInfo,
                                              NSError * _Nullable error);

/**
* Gets a `NMACountryInfo` for a given coordinate.
*
* @note Under the hood, this function uses the `NMAReverseGeocodeRequest` API to get the country by
* geo coordinates. That is why the function performs asynchronous call that may take a time.
* It requires internet connection or previously downloaded maps to work.
*
* @param coordinates A `NMAGeoCoordinates` to get country information.
* @param completionBlock A `NMACountryInfoCompletionBlock` to get request result.
* @param connectivity Desired `NMARequestConnectivity` for request.
*/

+ (void)getCountryInfoOnCoordinates:(nonnull NMAGeoCoordinates *)coordinates
                     withCompletion:(nonnull NMACountryInfoCompletionBlock)completionBlock
                       connectivity:(NMARequestConnectivity)connectivity;

@end
