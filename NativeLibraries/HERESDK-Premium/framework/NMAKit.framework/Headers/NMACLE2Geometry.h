/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;


/**
 * Represents a user defined geometry.
 *
 * See `NMACLE2GeometryPoint`, `NMACLE2GeometryMultiPoint`.
 * Geometries can be obtained from `NMACLE2Result` objects.
 */
@interface NMACLE2Geometry : NSObject

/**
 * Identifier of a geometry object. This identifier is guaranteed to be unique only within a
 * single layer, meaning that two geometry object belonging to different layers might have the
 * same geometry ID. Only geometries that were once stored locally or remotely have an ID.
 * Meaning that a newly created geometry object does not have an ID.
 *
 * @note For geometry objects that do not have an ID yet, this is nil.
 */
@property (nullable, nonatomic, readonly) NSString *geometryId;

/**
 * Returns the minimum distance in meters to the geometry from the point used in a search query.
 * If it is unknown, 0 will be returned.
 *
 * @note A `NMACLE2ProximityRequest` supports distance calculation in offline mode.
 */
@property (nonatomic, readonly) double distance;

/**
 * Indicates if this geometry is local to the device or if it came from remote CLE service.
 * Geometry that is stored locally but was initially retrieved from the server (for example, by
 * downloading a whole layer or caching of search results) is not considered local.
 */
@property (nonatomic, readonly) BOOL isLocal;

/**
 * Returns `NSDictionary` with the available attributes for this geometry.
 * The keys represent the customer fields, with their respective values.
 *
 * @note All keys and values are of `NSString` type.
 */
@property (nonnull, nonatomic) NSMutableDictionary<NSString *, NSString *> *attributes;


@end
