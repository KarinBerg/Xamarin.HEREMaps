/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMATypes.h"

@class NMACLE2Request;
@class NMACLE2Result;


/**
 * Represents an event listener that reports information about query
 * progress changes or query completion.
 *
 * Methods of this protocol are called on the main queue.
 */
@protocol NMACLE2ResultListener<NSObject>

@optional
/**
 * Callback when a request has completed.
 *
 * @param request An `NMACLE2Request` object of the type shown on the left in the list above.
 *
 * @param result An object of type `NMACLE2Result` containing the request's result objects.
 *
 * @param error NSError for this request. Nil if the request completed successfully,
 * otherwise, this value is populated with an NMACLE2Error error code and a domain of
 * NMACLE2RequestError.
 */
- (void)          request:(nonnull NMACLE2Request *)request
    didCompleteWithResult:(nonnull NMACLE2Result *)result
                    error:(nullable NSError *)error;
@end
