/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */
#import <UIKit/UIKit.h>
#import "NMAUrbanMobility.h"
@class NMAUrbanMobilityOperator;
@class NMAUrbanMobilityLink;



/**
 * Represents a kind of transport (e.g. transit line or bike) with its properties like name,
 * color that can be used to display on the map, or operator that serves given transport.
 *
 * See also `NMAUrbanMobilityOperator`
 *
 * See also `NMAUrbanMobilityLink`
 *
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityTransport : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The name of the transport.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * Means of transport which servers the transport (Bus, Tram, Train, etc).
 */
@property (nonatomic, readonly) NMAUrbanMobilityTransportType transportType;

/**
 * Specific name of the transport type which serves the transport.
 * Name is localized according to current device's language.
 * If given language is not supported English version is returned.
 */
@property (nonatomic, readonly, nullable) NSString *transportTypeName;

/**
 * Direction which the transport is heading.
 */
@property (nonatomic, readonly, nullable) NSString *direction;

/**
 * Operator serving the transport (might be not available).
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityOperator *transportOperator;

/**
 * Describes whether or not bikes are allowed on the transport.
 */
@property (nonatomic, readonly) NMAUrbanMobilityFeatureAvailability bikeAllowed;

/**
 * Describes whether or not the transport is barrier free.
 */
@property (nonatomic, readonly) NMAUrbanMobilityFeatureAvailability barrierFree;

/**
 * Transport color or nil if not available.
 */
@property (nonatomic, readonly, nullable) UIColor *color;

/**
 * Transport name color or nil if not available.
 */
@property (nonatomic, readonly, nullable) UIColor *textColor;

/**
 * Color of the border around the transport name or nil if not available.
 */
@property (nonatomic, readonly, nullable) UIColor *outlineColor;

@end
