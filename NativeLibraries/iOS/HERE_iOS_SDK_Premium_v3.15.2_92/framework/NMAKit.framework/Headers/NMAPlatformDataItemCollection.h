/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAPlatformDataItem;



/**
 * Array of NMAPlatformDataItem objects.
 */
@interface NMAPlatformDataItemCollection : NSObject <NSFastEnumeration>

/**
 * Do not directly instantiate an instance of this class.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Returns the object at the specified index. If the index is beyond the end of
 * the collection (that is, if index is greater than or equal to the value returned
 * by count), an NSRangeException is raised.
 *
 * @return The object located at index.
 */
- (nonnull NMAPlatformDataItem *)objectAtIndexedSubscript:(NSUInteger)index;

/**
 * Returns an enumerator object that lets you access each object in the collection.
 *
 * @return The enumerator object.
 */
- (nonnull NSEnumerator *)objectEnumerator;

/**
 * Extracts the data contained into an array of dictionaries. Note that for each
 * NMAPlatformDataItem contained, a dictionary is created.
 *
 * @return An array of dictionaries.
 *
 * See also `NMAPlatformDataItem::extract`
 */
- (nonnull NSArray<NSDictionary<NSString *, NSString *>*> *)extract;

/**
 * The number of entries in the collection.
 */
@property (readonly) NSUInteger count;

@end
