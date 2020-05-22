/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMACLE2DataManager.h"

/**
 * The Custom Location Extensions 2 group provides classes and protocols
 * that support advanced custom location searches.
 */

/**
 *
 * Encapsulates information about CLE2 data change that was a result of a local or remote data
 * operation.
 */
@interface NMACLE2OperationResult : NSObject

/** Indicates type of operation that resulted in data modification. */
@property (readonly) NMACLE2OperationType operationType;

/** Indicates how many geometries have been affected by the modification (nil if undefined). */
@property (nonnull, readonly) NSNumber *affectedItemCount;

/** Indicates which layers were affected by the data modification. */
@property (nullable, readonly) NSArray<NSString *> *affectedLayerIds;

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)new NS_UNAVAILABLE;

@end
