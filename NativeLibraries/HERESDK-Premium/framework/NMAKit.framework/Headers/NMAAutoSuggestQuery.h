/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAAutoSuggest.h"
#import "NMAAutoSuggestionRequest.h"


/**
 *
 * Represents a suggested query. Query can be used to trigger next
 * Suggest request.
 *
 * See also `NMAAutoSuggestPlace`
 *
 * See also `NMAAutoSuggestSearch`
 */
@interface NMAAutoSuggestQuery : NMAAutoSuggest

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The suggested query completion of the given string
 */
@property (nullable, nonatomic, readonly) NSString *completion;

/**
 * Gets the `NMAAutoSuggestionRequest` to perform the next AutoSuggestion request with
 * the user's chosen completed query term
 */
- (nonnull NMAAutoSuggestionRequest *)autoSuggestionRequest;

@end
