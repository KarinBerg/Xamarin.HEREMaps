/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>



/**
 * Abstract class common for all outgoing events.
 * It can be used to inform the operator about specific event, for example job start, or job cancellation etc.
 * The event can be sent out by using `NMAFleetConnectivityService` sendEvent: method.
 * The event is sent out asynchronously. To check the result of the dispatch,
 * a delegate with fleetConnectivityEventAcknowledged:error: method should be implemented
 * and set in `NMAFleetConnectivityService`.
 */
@interface NMAFleetConnectivityEvent : NSObject

/**
 * Generic dictionary of NSString. Can be used for any purpose.
 * Non-string values will be ignored.
 */
@property (nonatomic, readwrite, nullable) NSMutableDictionary <NSString *, NSString *> *content;

/**
 * Job ID to which this event relates.
 */
@property (nonatomic, readonly, nonnull) NSString *jobId;

@end
