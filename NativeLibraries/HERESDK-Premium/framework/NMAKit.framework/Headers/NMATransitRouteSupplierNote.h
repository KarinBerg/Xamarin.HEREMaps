/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Contains giving additional information about a transit data supplier.
 *
 * This information must be exposed in the client application.
 */
@interface NMATransitRouteSupplierNote : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The type of source supplier note.
 */
@property (nonatomic, readonly, nullable) NSString *type;

/**
 * The text of the note.
 *
 * The text may contain HTML including hyperlinks. The text will be localized.
 */
@property (nonatomic, readonly, nullable) NSString *text;

/**
 * The URL to which note is referring, if any.
 */
@property (nonatomic, readonly, nullable) NSString *url;

/**
 * The text accompanying the URL to which note is referring, if any.
 */
@property (nonatomic, readonly, nullable) NSString *urlText;

@end
