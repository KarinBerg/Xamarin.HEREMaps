/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAFleetConnectivityEvent.h"


/**
 * Represents event used to inform the operator that the incoming job was rejected.
 */
@interface NMAFleetConnectivityJobRejectedEvent : NMAFleetConnectivityEvent

/**
 * Job ID to which this event relates.
 * Should be set before sending out.
 */
@property (nonatomic, readwrite, nullable) NSString *jobId;

@end
