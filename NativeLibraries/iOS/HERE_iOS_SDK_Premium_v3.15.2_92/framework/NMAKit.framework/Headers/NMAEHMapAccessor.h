/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAEHPathTree;
@class NMAEHLink;
@class NMAEHLinkInformation;
@class NMAGeoPolyline;
@class NMAEHMetaData;
@class NMAEHSlopeDataPoint;

/**
 * The error domain for NMAEHMapAccessor errors.
 */
FOUNDATION_EXPORT NSString *const _Nonnull kNMAEHMapAccessorErrorDomain;


/**
 * `NMAEHMapAccessor` is a class that provides information about any link.
 */
@interface NMAEHMapAccessor : NSObject

/**
 * Retrieves the information of the link.
 *
 * @param link The link from which the information will be retrieved.
 *
 * @return linkInformation if the operation was successful, otherwise nil.
 */

- (nullable NMAEHLinkInformation *)getLinkInformation:(nonnull NMAEHLink *)link;

/**
 * Retrieves the information of the link.
 *
 * @param link The link from which the information will be retreived.
 * @param error Reference error object to get the error if any.
 *
 * @return linkInformation if the operation was successful, otherwise nil.
 */

- (nullable NMAEHLinkInformation *)getLinkInformation:(nonnull NMAEHLink *)link
                                                error:(NSError *_Nullable *_Nonnull)error;

/**
 * Retrieves the geometry of the link.
 *
 * @param link The link from which the geometry will be retrieved.
 *
 * @return geometry if the operation was successful, otherwise nil.
 */
- (nullable NMAGeoPolyline *)getLinkPolyline:(nonnull NMAEHLink *)link;

/**
 * Retrieves the geometry of the link.
 *
 * @param link The link from which the geometry will be retrieved.
 * @param error Reference error object to get the error if any.
 *
 * @return geometry if the operation was successful, otherwise nil.
 */
- (nullable NMAGeoPolyline *)getLinkPolyline:(nonnull NMAEHLink *)link
                                       error:(NSError *_Nullable *_Nonnull)error;

/**
 * Retrieves an array of connected links of the link.
 *
 * @param link The link from which the connected links will be retrieved.
 *
 * @return array of links if the operation was successful, otherwise nil.
 */
- (nullable NSArray<NMAEHLink *> *)getConnectedLinks:(nonnull NMAEHLink *)link;

/**
 * Retrieves the connected links of the link.
 *
 * @param link The link from which the connected links will be retrieved.
 * @param error Reference error object to get the error if any.
 *
 * @return array of links if the operation was successful, otherwise nil.
 */
- (nullable NSArray<NMAEHLink *> *)getConnectedLinks:(nonnull NMAEHLink *)link
                                               error:(NSError *_Nullable *_Nonnull)error;

/**
 * Retrieves the meta data of the link.
 *
 * @param link The link from which the meta data will be retrieved.
 *
 * @return meta data if the operation was successful, otherwise nil.
 */
- (nullable NMAEHMetaData *)getMetaData:(nonnull NMAEHLink *)link;

/**
 * Retrieves the meta data of the link.
 *
 * @param link The link from which the meta data will be retrieved.
 * @param error Reference error object to get the error if any.
 *
 * @return meta data if the operation was successful, otherwise nil.
 */
- (nullable NMAEHMetaData *)getMetaData:(nonnull NMAEHLink *)link
                                  error:(NSError *_Nullable *_Nonnull)error;

/**
 * Retrieves the PVID of the link.
 *
 * @param link The link from which the PVID will be retrieved.
 *
 * @return PVID if the operation was successful, otherwise nil.
 */
- (nullable NSString *)getPVID:(nonnull NMAEHLink *)link;

/**
 * Retrieves the PVID of the link.
 *
 * @param link The link from which the PVID will be retrieved.
 * @param error Reference error object to get the error if any.
 *
 * @return PVID if the operation was successful, otherwise nil.
 */
- (nullable NSString *)getPVID:(nonnull NMAEHLink *)link
                         error:(NSError *_Nullable *_Nonnull)error;

/**
 * Retrieves an array of slope data points from the link.
 *
 * @param link The link from which the slope data points will be retrieved.
 *
 * @return array of slope data points if the operation was successful, otherwise nil.
 */
- (nullable NSArray<NMAEHSlopeDataPoint *> *)getSlopeDataPoints:(nonnull NMAEHLink *)link;

/**
 * Retrieves an array of slope data points from the link.
 *
 * @param link The link from which the slope data points will be retrieved.
 * @param error Reference error object to get the error if any.
 *
 * @return array of slope data points if the operation was successful, otherwise nil.
 */
- (nullable NSArray<NMAEHSlopeDataPoint *> *)getSlopeDataPoints:(nonnull NMAEHLink *)link
                                                          error:(NSError *_Nullable *_Nonnull)error;

@end
