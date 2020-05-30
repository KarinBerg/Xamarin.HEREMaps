/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMATransitRouteSupplierNote;


/**
 * Contains structured information about a source data supplier.
 *
 * Data supplier information must be displayed in the client application.
 */
@interface NMATransitRouteSupplier : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The source data supplier's title.
 */
@property (nonatomic, readonly, nullable) NSString *title;

/**
 * The source data supplier's website.
 */
@property (nonatomic, readonly, nullable) NSString *url;

/**
 * Additional information about the supplier, represented as NMATransitRouteSupplierNote.
 *
 * This information must be displayed to the end-user.
 */
@property (nonatomic, readonly, nullable) NSArray <NMATransitRouteSupplierNote *> *notes;

@end
