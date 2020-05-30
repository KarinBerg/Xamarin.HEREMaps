/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMACLE2Task.h"
#import "NMACLE2Request.h"

/**
 * The Custom Location Extensions 2 group provides classes and protocols
 * that support advanced custom location searches.
 */

/**
 * Encapsulates asynchronous CLE2 task (that usually involves network communication
 * and/or database operations) and provides some common operations
 * like observing, waiting for the result, cancelling or getting the result.
 *
 * A typical use of a NMACLE2Task involves creating a task, subscribing to it for
 * result and starting its execution. For convenience, it is possible to start and
 * subscribe to the task with one call.
 *
 * In the simplest scenario where only one subscriber is enough and there is no
 * need to hold onto the task for later, it looks something like this:
 * [[taskFactory doSomethingTask:param] startWithBlock:^(ResultType *result, NSError * error) {
 *     // process result of the task
 * }];
 *
 * NMACLE2Task does however provide some more advanced features. For example, if
 * you are performing some background operation that at some point involves interacting
 * with CLE2 in some way, an NMACLE2Task can be used in a synchronous manner by means of
 * calling waitForResult method and then getting the result and error from the
 * properties of the task.
 *
 * Having multiple subscribers to the task is also possible.
 *
 * And finally, since NMACLE2Task object represents a unit of work, it can be held onto
 * for later use, passed around, run repeatedly multiple times (for example, retrying
 * a failed operation) and of course, canceled.
 */
@interface NMACLE2Task<__covariant ResultType>: NSObject

/**
 * Starts this task in background thread. All subscribers will be called on main thread.
 * Starting a task that is already running has no effect. Starting a task that has already
 * finished will start it once more.
 */
- (void)start;

/**
 * Starts this task in background thread with a supplied subscriber that will be called
 * on the main thread once this task finishes. Starting a task that is already running
 * has no effect. Starting a task that has already finished will start it once more.
 */
- (void)startWithBlock:(void (^_Nonnull)(ResultType _Nullable result, NSError *_Nullable error))listenerBlock;

/**
 * Cancels a previously triggered request execution. Cancelled requests will have their
 * subscribers called with the respective NMACLE2Error.
 *
 * @note Cancelling might not always be possible if the operation was already in an advanced stage,
 *       hence check the error code to determine actual fate of the task
 */
- (void)cancel;

/**
 * Blocks until this task finishes or a specied timeout passes.
 *
 * @note Only use this in a backgrounded thread.
 *
 * @param timeout Specifies how long to wait for the task to finish
 * @return YES if the task finishes within the specified time limit or if it was not running
 *         in the first place, NO if specified time limit went by without the task finishing
 */
- (BOOL)waitForResult:(NSTimeInterval)timeout
NS_SWIFT_NAME(waitForResult(_:));

/**
 * Blocks until this task finishes.
 *
 * @note Trying to call this method on main thread will result in NSException being thrown
 */
- (void)waitForResult;

/**
 * Adds a subscriber to this task. All subscribers are called on the main thread.
 * A subscriber block will be called with the result of the operation and an error
 * object that can be inspected to determine if the operation succeeded.
 * Subscribing to a task that has already finished will cause the block to be
 * called with the curently held (ie. last finished) result and error.
 *
 * @param subscriberBlock A block that will be called when this task finishes
 */
- (void)subscribeWithBlock:(void (^_Nonnull)(ResultType _Nullable result, NSError *_Nullable error))subscriberBlock;

/**
 * Removes a supplied block from the list of this task's subscribers.
 *
 * @param subscriberBlock A block to remove from the list of subscribers
 */
- (void)unsubscribeBlock:(void (^_Nonnull)(ResultType _Nullable, NSError *_Nullable error))subscriberBlock;

/** Holds result of last execution of this task. */
@property (readonly) ResultType _Nullable result;

/** Holds status of last execution of this task. */
@property (readonly) NSError * _Nullable error;

/** Indicates whether this task has finished or not. */
@property (readonly) BOOL isFinished;

/** Indicates whether this task has been started or not. Note that a task that is finished has also been started. */
@property (readonly) BOOL isStarted;

@end
