/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Represents issue reported by the server.
 * See `NMAFleetConnectivityError`.
 */
@interface NMAFleetConnectivityIssue : NSObject

/**
 * Details of the issue.
 */
@property (readonly, nonatomic, nullable) NSString *message;

/**
 * Code of the issue.
 */
@property (readonly, nonatomic, nullable) NSString *code;

@end
