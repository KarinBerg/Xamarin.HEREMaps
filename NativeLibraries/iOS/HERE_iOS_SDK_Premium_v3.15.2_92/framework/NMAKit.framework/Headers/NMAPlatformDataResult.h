/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


@class NMAPlatformDataItemCollection;


/**
 * After a Platform Data Request run, the result is returned with this
 * class.
 */
@interface NMAPlatformDataResult : NSObject

/**
 * Do not directly instantiate an instance of this class.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 * Returns the collection associated with a given key, i.e. layer.
 *
 * @param key The layer contained in the result.
 *
 * @return The collection for the layer data or nil if the key
 *         isn't found in result.
 */
- (NMAPlatformDataItemCollection *)objectForKeyedSubscript:(NSString *)key;

/**
 * Returns all the layer names.
 *
 * @return The array of all the layer names.
 */
- (NSArray<NSString *> *)allKeys;

/**
 * Returns the all the data collections.
 *
 * @return The array of all the collections, i.e. one collection for each layer contained in the result.
 */
- (NSArray<NMAPlatformDataItemCollection *> *)allValues;

/**
 * Applies a given block object to the entries in the result.
 */
- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(NSString *key, NMAPlatformDataItemCollection *obj, BOOL *stop))block;

/**
 * Extracts the data contained into a dictionary. Note that for each NMAPlatformDataItemCollection
 * contained, an array is created which itself contains dictionaries.
 *
 * @return A dictionary of the string key/array value pairs.
 *
 * See also `NMAPlatformDataItemCollection::extract`
 */
- (NSDictionary<NSString *, NSArray<NSDictionary<NSString *, NSString *> *>*>*)extract;

/**
 * The number of entries in the result.
 */
@property (readonly) NSUInteger count;

@end
