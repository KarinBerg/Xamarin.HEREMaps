/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@protocol NMATollCostRequestListener;
@class NMARoute;
@class NMATollCostOptions;
@class NMATollCostRequest;
@class NMATollCostResult;


/**
 * The error domain for NMATollCostRequest errors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull kNMATollCostRequestErrorDomain;

/**
 * Defines the possible errors when performing a TCE request.
 */
typedef NS_ENUM(NSUInteger, NMATollCostRequestError) {
    /**
     * Access to the TCE API is denied. Contact your HERE
     *         representative for more information.
     */
    NMATollCostRequestErrorNoPermission      = 1,
    /** There is an ongoing TCE request. */
    NMATollCostRequestErrorAlreadyRunning    = 2,
    /** The TCE request is cancelled. */
    NMATollCostRequestErrorCancelled         = 3,
    /** Parameters passed to the TCE API are not valid. */
    NMATollCostRequestErrorInvalidParameters = 4,
    /** Connection problem occurred. */
    NMATollCostRequestErrorConnectionError   = 5,
    /** Server reported error. */
    NMATollCostRequestErrorServerError       = 6,
    /** Unknown error. */
    NMATollCostRequestErrorUnknownError      = 7
};

/**
 * A completion block used to handle the result of a toll cost request.
 *
 * @param request The request object which started the toll cost query.
 * @param result The result returned.
 * @param error If an error occurs, the NSError object contains data on it and otherwise
 *              it is nil.
 */
typedef void (^NMATollCostRequestCompletionBlock)(NMATollCostRequest * _Nonnull request,
                                                  NMATollCostResult  * _Nonnull result,
                                                  NSError * _Nullable error);

/**
 * Represents an event listener that reports information about request
 * query completion.
 *
 * Methods of this protocol are called on the main queue.
 */
@protocol NMATollCostRequestListener<NSObject>

@required

/**
 * A callback method used to pass the result of a toll cost request.
 *
 * @param request The request object which started the toll cost query.
 * @param result The result returned.
 * @param error If an error occurs, the NSError object contains data on it and otherwise
 *              it is nil.
 */
- (void)request:(nonnull NMATollCostRequest *)request didCompleteWithResult:(nonnull NMATollCostResult *)result error:(nullable NSError *)error;

@end


/**
 * Runs the toll cost data requests with the specified parameters.
 * Note that only the routes calculated with the following transport mode options are supported:
 * NMATransportModeCar,
 * NMATransportModeTruck
 * So, if the route passed is not calculated with one of these transport modes, nil is
 * returned from both of the init methods. Plus, the route should be calculated in the online mode
 * and the offline mode is not supported.
 */
@interface NMATollCostRequest : NSObject

/**
 * Do not directly instantiate an instance of this class.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Creates a toll cost request with the specified route. Note that the route vehicle type and route
 * departure time are used for the toll cost request.
 *
 * @param route The route for which the toll cost will be returned. When it is nil, the object
 *              isn't created, i.e. nil is returned.
 *
 * @return If the parameter is valid, an NMATollCostRequest object configured with
 *         the parameter and nil otherwise.
 */
- (nullable instancetype)initWithRoute:(nonnull NMARoute *)route;

/**
 * Creates a toll cost request with the specified route and options. The route parameter only provides the route
 * and no routing option is considered for the toll cost calculation. It is the caller's responsibility to have
 * the route and toll cost options compatible. When they are not compatible, e.g. for the toll cost the
 * vehicle type is set as car, whereas the route is created for a truck, the quality of the outcome may
 * deteriorate.
 *
 * @param route The route for which the toll cost will be returned. When it is nil, the object
 *              isn't created, i.e. nil is returned.
 *
 * @param options All the toll cost calculation options. When it is nil, the object
 *                isn't created, i.e. nil is returned.
 *
 * @return If the parameters are valid, an NMATollCostRequest object configured with
 *         the parameters and nil otherwise.
 */
- (nullable instancetype)initWithRoute:(nonnull NMARoute *)route andOptions:(nonnull NMATollCostOptions *)options;

/**
 * Invokes the data request with the specified listener.
 *
 * @param requestListener A listener to listen for the data results.
 *
 * See also `startWithBlock:`
 */
- (void)startWithListener:(nonnull id<NMATollCostRequestListener>)requestListener;

/**
 * Invokes the data request with the block.
 *
 * @param block A block to run when the data received.
 *
 * See also `NMAPlatformDataRequestCompletionBlock`
 *
 * See also `startWithListener:`
 */
- (void)startWithBlock:(nonnull NMATollCostRequestCompletionBlock)block;

/**
 * Attempts to cancel the ongoing toll cost request. Calling this
 * method does not guarantees cancellation of the request. Subsequent calls
 * of this method will be ignored, once the request is cancelled.
 */
- (void)cancel;

@end
