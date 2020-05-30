/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#ifndef NMASDK_NMARoutingError_h
#define NMASDK_NMARoutingError_h


/**
 * Defines types of error codes that can be returned from route calculation
 * operations.
 */
typedef NS_ENUM(NSUInteger, NMARoutingError) {
    /** There was no error, route calcualtion succeeded. */
    NMARoutingErrorNone = 0,
    /** There was an unknown error. */
    NMARoutingErrorUnknown,
    /** There was an out-of-memory error. */
    NMARoutingErrorOutOfMemory,
    /** There was an error due to invalid parameters. */
    NMARoutingErrorInvalidParameters,
    /** There was an error due to another request already being processed. */
    NMARoutingErrorInvalidOperation,
    /** There was an error because no route could be found. */
    NMARoutingErrorGraphDisconnected,
    /**
     * There was an error because no route could be found, possibly due to some option
     * (e.g. disabled highways) preventing it.
     */
    NMARoutingErrorGraphDisconnectedCheckOptions,
    /** There was an error because no starting waypoint could be found. */
    NMARoutingErrorNoStartPoint,
    /** There was an error because no destination waypoint could be found. */
    NMARoutingErrorNoEndPoint,
    /**
     * There was an error because the destination point is unreachable, possibly due to
     * some option (e.g. disabled highways) preventing it.
     */
    NMARoutingErrorNoEndPointCheckOptions,
    /**
     * There was an error because pedestrian mode was specified yet is not practical
     * (e.g. the route is too long).
     */
    NMARoutingErrorCannotDoPedestrian,
    /** There was an error because the application user cancelled the route calculation. */
    NMARoutingErrorRoutingCancelled,
    /**
     * There was an error because the route calculation request included options that
     * prohibit successful completion.
     */
    NMARoutingErrorViolatesOptions,
    /**
     * There was an error because the service could not digest the requested route
     * parameters.
     */
    NMARoutingErrorRouteCorrupted,
    /** There was an error due to invalid or missing HERE Developer credentials. */
    NMARoutingErrorInvalidCredentials,
    /**
     * There was an error because there is not enough local map data to perform route
     * calculation. Client can redownload map data and calculate route again.
     * The error may be returned if a route is requested right after `NMAMapEngine` is
     * initialized but map data request is not completed yet due to network latency.
     */
    NMARoutingErrorInsufficientMapData,
    /**
     * The online route calculation request failed because of a networking error. The route
     * calculation request should be retried.
     */
    NMARoutingErrorNetworkCommunication,
    /**
     * The routing server does not support map version specified in request. Client must
     * update the downloaded map version installed on the device.
     */
    NMARoutingErrorUnsupportedMapVersion
};

#endif /// NMASDK_NMARoutingError_h
