/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAPlaceTransitOperatorSupplier;
@class NMAPlaceTransitOperatorLink;


/**
 * Represents a public transport operator.
 */
@interface NMAPlaceTransitOperator : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The `NSString` representing the unique operator identifier.
 */
@property (nullable, nonatomic, readonly) NSString *uniqueId;

/**
 * The `NSString` representing the operator name.
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *title;

/**
 * The `NMAPlaceTransitOperatorSupplier` of the operator's schedule information.
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NMAPlaceTransitOperatorSupplier *supplier;

/**
 * Dictionary of NMAPlaceTransitOperatorLink additional links to be
 * displayed next to the departure informaiton of the operator. Possible keys
 * are operator, agency and tariff.
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSDictionary<NSString *, NMAPlaceTransitOperatorLink *> *links;

@end
