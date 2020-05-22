/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAFleetConnectivityEvent;
@class NMAFleetConnectivityError;
@class NMAFleetConnectivityMessage;


/**
 * Represents a delegate to handle NMAFleetConnectivityService incoming messages.
 *
 * Methods of this protocol are called on the main queue.
 */
@protocol NMAFleetConnectivityServiceDelegate<NSObject>
@required
/**
 * Called when incoming message arrives.
 *
 * @param message The NMAFleetConnectivityMessage instance.
 *                   See `NMAFleetConnectivityJobMessage` and `NMAFleetConnectivityCustomMessage`.
 */
- (void)fleetConnectivityMessageReceived:(nonnull NMAFleetConnectivityMessage *)message;

/**
 * Called when server acknowledges dispatched event.
 *
 * @param event The NMAFleetConnectivityEvent instance. Note that it won't be the same instance of event
 *                   that was passed to the sendEvent: call.
 *                   See `NMAFleetConnectivityJobStartedEvent`, `NMAFleetConnectivityJobFinishedEvent`,
 *                   `NMAFleetConnectivityJobRejectedEvent`, `NMAFleetConnectivityJobCancelledEvent`
 *                   and `NMAFleetConnectivityCustomEvent`.
 *
 * @param error The NMAFleetConnectivityError instance in case of network failure or server error.
 *                   See `NMAFleetConnectivityError`.
 */
- (void)fleetConnectivityEventAcknowledged:(nonnull NMAFleetConnectivityEvent *)event error:(nullable NMAFleetConnectivityError *)error;
@end


/**
 * Main component of Fleet Connectivity Extension responsible for communication.
 */
@interface NMAFleetConnectivityService : NSObject

/**
 * Do not directly instantiate an instance of this class.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The `NMAFleetConnectivityServiceDelegate` that listens for messages from the
 * `NMAFleetConnectivityService`.
 */
@property (nonatomic, weak, nullable) id<NMAFleetConnectivityServiceDelegate> delegate;

/**
 * Asset ID that identifies this device. Will be reported in every event dispatched to the server.
 * Server provides new messages based on this ID. Service won't start if it is not specified.
 */
@property (nonatomic, nonnull) NSString *assetId;

/**
 * Dispatcher ID that identifies the user of this device. Service won't start if it is not specified.
 */
@property (nonatomic, nonnull) NSString *dispatcherId;

/**
 * Polling interval specified in seconds. Default value is 10 seconds.
 * Any attempt to set this property to 0 will be ignored and pollingInterval remains unchanged.
 */
@property (nonatomic) NSUInteger pollingInterval;

/**
 * Returns the `NMAFleetConnectivityService` singleton instance.
 *
 * @note Use this method to obtain a `NMAFleetConnectivityService` instance. Do not call
 * init directly.
 * @note This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @return shared `NMAFleetConnectivityService` instance
 */
+ (nullable NMAFleetConnectivityService *)sharedFleetConnectivityService NS_SWIFT_NAME(sharedInstance());

/**
 * Starts the service if it is not already started.
 * Fails if assetId or dispatcherId is not set.
 *
 * @return NO if assetId or dispatcherId is not set or service is already started.
 */
- (BOOL)start;

/**
 * Stops the service if it is running.
 *
 * @return NO if service is not running.
 */
- (BOOL)stop;

/**
 * Forces poll of new events, if the service is running.
 *
 * @return NO if service is not running.
 */
- (BOOL)forcePoll;

/**
 * Dispatches the provided event.
 *
 * @param event The NMAFleetConnectivityEvent instance.
 *                   See `NMAFleetConnectivityJobStartedEvent`, `NMAFleetConnectivityJobFinishedEvent`,
 *                   `NMAFleetConnectivityJobRejectedEvent`, `NMAFleetConnectivityJobCancelledEvent`
 *                   and `NMAFleetConnectivityCustomEvent`.
 *
 * @return NO if service is not running or conditions for given event are not met.
 */
- (BOOL)sendEvent:(nonnull NMAFleetConnectivityEvent *)event;

/**
 * Retrieves the ID of currently running job. Job is started by sending `NMAFleetConnectivityJobStartedEvent`.
 * Job can be stopped by sending `NMAFleetConnectivityJobFinishedEvent` or `NMAFleetConnectivityJobCancelledEvent`.
 *
 * @return ID of the currently running job. Nil if no job is in progress.
 */
- (nullable NSString *)runningJobId;

@end
