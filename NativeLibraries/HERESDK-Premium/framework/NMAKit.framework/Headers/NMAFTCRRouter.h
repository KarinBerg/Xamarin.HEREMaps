/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMAFTCRRequestParameters.h"
#import "NMAFTCRRouter.h"
#import "NMAFTCRRoute.h"

@class NMAFTCRRequestParameters;

/**
 * A completion block used to handle the result of a `FTCRRoute` request.
 *
 * IMPORTANT: This is a Beta API, and is subject to change without notice.
 *
 * @param routes The array of possible routes. Can be nil if error occurred.
 * @param error  A routing calculation error. `nil` if there was no error during calculation.
 *               `NSError` object contains error code and description message.
 */
typedef void(^NMAFTCRRouterResultBlock)(NSArray<NMAFTCRRoute *> * _Nullable routes, NSError* _Nullable error);


/**
 * Route calculation executor for Fleet Telematics Custom Route (aka FTCR).
 *
 * IMPORTANT: `NMAFTCRNavigationManager` is a Beta feature. The related classes are subject to
 * change without notice.
 */
@interface NMAFTCRRouter : NSObject

/**
 * Default initializer that initializes a `NMAFTCRRouter` for route calculation.
 *
 * @return The `NMAFTCRRouter`
 */
- (nonnull instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Default initializer that initializes a `NMAFTCRRouter` instance for route calculation.
 *
 * @return The `NMAFTCRRouter`
 */
+ (nonnull instancetype)new;

/**
 * Starts a route calculation with the given parameters. Multiple routes can be calculated in
 * parallel by calling this method on the single instance of the `NMAFTCRRouter` class. Result
 * block will be executed on the main thread.
 *
 * @param parameters The parameters for route calculation.
 * @param completion The completion block that is used to pass the result.
 *
 * @return The id for the calculation task.
 */
- (NSInteger)calculateRouteWithParameters:(nonnull NMAFTCRRequestParameters *) parameters
                          completionBlock:(nonnull NMAFTCRRouterResultBlock) completion
NS_SWIFT_NAME(calculateRoute(withParameters:_:));

/**
 * Cancels ongoing route calculation task.
 *
 * @param taskId The route calculation identifier.
 */
- (void)cancel:(NSInteger)taskId;

@end
