/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


@class NMAFleetConnectivityIssue;

/**
 * Defines types of errors codes that can be reported by the `NMAFleetConnectivityService`.
 */
typedef NS_ENUM(NSUInteger, NMAFleetConnectivityErrorType) {
    /** Server reported error, for example due to incorrect data. */
    NMAFleetConnectivityErrorTypeServerError = 1,
    /** Connection problem occurred. */
    NMAFleetConnectivityErrorTypeConnectionError = 2
};


/**
 * Represents error reported by the server or the `NMAFleetConnectivityService`.
 */
@interface NMAFleetConnectivityError : NSObject

/**
 * HTTP response code of the server.
 */
@property (readonly, nonatomic) NSUInteger responseCode;

/**
 * Error ID that can be used for tracking the problem in case of server error.
 */
@property (readonly, nonatomic, nullable) NSString *errorId;

/**
 * Type of this error.
 */
@property (readonly, nonatomic) NMAFleetConnectivityErrorType errorType;

/**
 * Array of issues reported by the server. See `NMAFleetConnectivityIssue`.
 */
@property (readonly, nonatomic, nullable) NSArray<NMAFleetConnectivityIssue *> *issues;

@end
