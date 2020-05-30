/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAFleetConnectivityMessage.h"



/**
 * Represents incoming message with a job request.
 * The job can be accepted or rejected, see `NMAFleetConnectivityJobStartedEvent`
 * and `NMAFleetConnectivityJobRejectedEvent`.
 * The details of the job (like destination) should be specified in the content dictionary in this message.
 */
@interface NMAFleetConnectivityJobMessage : NMAFleetConnectivityMessage

/**
 * Optional ETA threshold proposed by the operator.
 * See `NMAFleetConnectivityJobStartedEvent` for more details.
 */
@property (readonly, nonatomic) NSUInteger etaThreshold;

@end
