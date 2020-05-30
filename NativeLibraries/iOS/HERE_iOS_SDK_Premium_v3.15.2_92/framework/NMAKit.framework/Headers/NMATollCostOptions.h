/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMATollCostVehicleProfile;



/**
 * All the TCE options
 */
@interface NMATollCostOptions : NSObject

/**
 * Creates a toll cost request with the default vehicle profile.
 *
 * @return An NMATollCostOptions object configured with the default `NMATollCostVehicleProfile`.
 */
- (nonnull instancetype)init;

/**
 * Creates a toll cost request with the specified vehicle profile.
 *
 * @param vehicleProfile All the parameters for the toll cost request. When it is nil, the object
 *                       isn't created, i.e. nil is returned.
 *
 * @return If the parameters are valid, an NMATollCostOptions object configured with
 *         the vehicle profile and nil otherwise.
 */
- (nullable instancetype)initWithVehicleProfile:(nonnull NMATollCostVehicleProfile *)vehicleProfile;

/**
 * The vehicle profile in use.
 */
@property (nonatomic, strong, readonly, nonnull) NMATollCostVehicleProfile * vehicleProfile;

/**
 * Currency parameter in the ISO-4217 code format like "EUR" or "USD". When the currency is
 * found to be invalid, the related request raises an error, either "Currency is not valid" or "Error
 * validating currency: Unknown currency". When it is not set, the default currency "EUR" is used.
 *
 * See https://en.wikipedia.org/wiki/ISO_4217
 */
@property (nonatomic, strong, nonnull) NSString * currency;

/**
 * The departure date for the trip.
 *
 * This is an optional parameter. When it is nil, it is ignored.
 *
 * See also `NMATollCostRequest::initWithRoute:`
 */
@property (nonatomic, strong, nullable) NSDate * departure;

@end
