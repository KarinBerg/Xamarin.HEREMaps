/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAPlaceTransitLineCategory;
@class NMAPlaceTransitLineStyle;


/**
 * Represents a public transport line.
 */
@interface NMAPlaceTransitLine : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The `NSString` representing the line name.
 */
@property (nullable, nonatomic, readonly) NSString *name;

/**
 * The `NMAPlaceTransitLineCategory` information for the line.
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NMAPlaceTransitLineCategory *category;

/**
 * The `NMAPlaceTransitLineStyle` guideline information for the line.
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NMAPlaceTransitLineStyle *style;

/**
 * The `NSString` of the operator serving the line.
 * @note Attempts to read this property could return nil.
 */
@property (nullable, nonatomic, readonly) NSString *operatorName;

@end
