/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAExtendedAttribute.h"

@class NMAPlaceTransitSchedulePage;


/**
 * Represents a Transit Departures Extended Attribute that is associated with public transport
 * stop/station and contains information about scheduled departures from the place.
 */
@interface NMAPlaceTransitDeparturesAttribute : NMAExtendedAttribute

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Gets a paged collection of scheduled departure information.
 *
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NMAPlaceTransitSchedulePage *schedule;

@end
