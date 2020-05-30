/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#ifndef NMASDK_NMAIsolineError_h
#define NMASDK_NMAIsolineError_h


/**
 * Defines types of error codes that can be returned from isoline calculation operations.
 */
typedef NS_ENUM(NSUInteger, NMAIsolineError) {
    /** There was no error. */
    NMAIsolineErrorNone = 0,
    /** There was an unknown error. */
    NMAIsolineErrorUnknown,
    /** There was an out-of-memory error. */
    NMAIsolineErrorOutOfMemory,
    /** There was an error due to invalid parameters. */
    NMAIsolineErrorInvalidParameters,
    /** There was an error due to another request already being processed. */
    NMAIsolineErrorInvalidOperation,
    /** There was an error because no route could be found. */
    NMAIsolineErrorGraphDisconnected,
    /** There was an error because the application user cancelled the isoline calculation. */
    NMAIsolineErrorRoutingCancelled,
    /** There was an error due to invalid or missing HERE Developer credentials. */
    NMAIsolineErrorInvalidCredentials,
    /**
     * There was an error because there is not enough local map data to perform route
     * calculation. Client can redownload map data and calculate route again.
     * The error may be returned if a route is requested right after `NMAMapEngine` is
     * initialized but map data request is not completed yet due to network latency.
     */
    NMAIsolineErrorInsufficientMapData,
    /**
     * The online route calculation request failed because of a networking error. The route
     * calculation request should be retried.
     */
    NMAIsolineErrorNetworkCommunication,
    /**
     * The routing server does not support map version specified in request. Client must
     * update the downloaded map version installed on the device.
     */
    NMAIsolineErrorUnsupportedMapVersion
};

#endif /// NMASDK_NMAIsolineError_h
