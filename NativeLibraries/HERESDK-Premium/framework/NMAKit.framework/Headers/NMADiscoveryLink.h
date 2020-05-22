/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMALink.h"

@class NMADiscoveryRequest;



/**
 * Represents a discovery search results link that can be used to perform another discovery search.
 */
@interface NMADiscoveryLink : NMALink

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Creates an NMADiscoveryRequest object to perform another NMADiscoveryPage request.
 *
 * @return The NMADiscoveryRequest
 */
- (nonnull NMADiscoveryRequest *)request;

@end
