/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * Represents available NMAAutoSuggest derived objects.
 */
typedef NS_ENUM(NSUInteger, NMAAutoSuggestType) {
    /** NMAAutoSuggest object unknown */
    NMAAutoSuggestTypeUnknown = 0,
    /** A link to a suggested place. */
    NMAAutoSuggestTypePlace,
    /** A link to a suggested search. */
    NMAAutoSuggestTypeSearch,
    /** A link to a suggested query. */
    NMAAutoSuggestTypeQuery
};


/**
 *
 * Represents the base interface for suggested places, searches and queries.
 *
 * The following specialized type might be available:
 *
 * - place
 *
 * - search
 *
 * - query
 *
 */
@interface NMAAutoSuggest : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The NSString representation of the url to retrieve suggestions from the Places API backend.
 */
@property (nullable, nonatomic, readonly) NSString *url;

/**
 * The NSString representation of the title for this place to be displayed to the user.
 */
@property (nullable, nonatomic, readonly) NSString *title;

/**
 * The NSString representation of the title for this place to be displayed to the user. It contains
 * markup highlighting the parts of the string that were matched.
 *
 * For example: User performs an AutoSuggest search of "Rest" will return the following.
 * title:Joey Restaurant
 * highlightedTitle:Joey Restaurant
 */
@property (nullable, nonatomic, readonly) NSString *highlightedTitle;

/**
 * The specialized AutoSuggest type.
 */
@property (nonatomic, readonly) NMAAutoSuggestType type;

@end

