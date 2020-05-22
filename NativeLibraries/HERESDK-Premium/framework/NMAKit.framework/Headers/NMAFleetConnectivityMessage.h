/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Abstract interface for incoming messages.
 */
@interface NMAFleetConnectivityMessage : NSObject

/**
 * Do not directly instantiate an instance of this class.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Optional job ID of this message.
 */
@property (readonly, nonatomic, nullable) NSString *jobId;

/**
 * ID of the dispatcher of this message.
 */
@property (readonly, nonatomic, nonnull) NSString *dispatcherId;

/**
 * ID of the asset for which this message was intended.
 * This will be equal to the asset ID that was set in the `NMAFleetConnectivityService`.
 */
@property (readonly, nonatomic, nonnull) NSString *assetId;

/**
 * Optional generic message specified by the dispatcher.
 */
@property (readonly, nonatomic, nullable) NSString *message;

/**
 * Creation time in seconds.
 */
@property (readonly, nonatomic) NSTimeInterval creationTime;

/**
 * Dictionary of strings with custom content sent by the dispatcher.
 */
@property (readonly, nonatomic, nullable) NSDictionary<NSString *, NSString *> *content;

@end
