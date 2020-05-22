/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class CLLocation;
@class NMAGeoCoordinates;


/**
 * Defines position sources.
 */
typedef NS_ENUM(NSUInteger, NMAGeoPositionSource) {
    /** Position source is unknown. */
    NMAGeoPositionSourceUnknown = 0x0,
    /** Position source is iOS location manager. */
    NMAGeoPositionSourceSystemLocation = 0x1,
    /** Position source is indoor radio map. */
    NMAGeoPositionSourceIndoor = 0x2
};

/**
 * A constant used to indicate an unknown measurement value.
 */
FOUNDATION_EXPORT const double NMAGeoPositionUnknownValue;


/**
 * Represents position, speed, and course information as provided by a
 * positioning source for a distinct moment in time.
 */
@interface NMAGeoPosition : NSObject

/**
 * A convenience constructor for creating NMAGeoPosition instances with
 * specified coordinates, speed, course, and accuracy.
 *
 * @note The accuracy parameter will be used for all of latitudeAccuracy,
 * longitudeAccuracy, and altitudeAccuracy.
 *
 * @note The timestamp will be set to the current time.
 */
+ (nullable instancetype)geoPositionWithCoordinates:(nonnull NMAGeoCoordinates *)coordinates
                                              speed:(double)speed
                                             course:(double)course
                                           accuracy:(double)accuracy
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * A convenience constructor for creating NMAGeoPosition instances with
 * specified coordinates, speed, course, accuracy and timestamp.
 *
 * @note The accuracy parameter will be used for all of latitudeAccuracy,
 * longitudeAccuracy, and altitudeAccuracy.
 */
+ (nullable instancetype)geoPositionWithCoordinates:(nonnull NMAGeoCoordinates *)coordinates
                                              speed:(double)speed
                                             course:(double)course
                                           accuracy:(double)accuracy
                                          timestamp:(nonnull NSDate *)timestamp
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * A convenience constructor for creating NMAGeoPosition instances with
 * specified coordinates, speed, course, latitudeAccuracy, longitudeAccuracy
 * and altitudeAccuracy.
 */
+ (nullable instancetype)geoPositionWithCoordinates:(nonnull NMAGeoCoordinates *)coordinates
                                              speed:(double)speed
                                             course:(double)course
                                   latitudeAccuracy:(double)latitudeAccuracy
                                  longitudeAccuracy:(double)longitudeAccuracy
                                   altitudeAccuracy:(double)altitudeAccuracy
                                          timestamp:(nonnull NSDate *)timestamp
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * A convenience constructor for creating NMAGeoPosition instances with
 * the specified CLLocation.
 */
+ (nullable instancetype)geoPositionWithCLLocation:(nonnull CLLocation *)location
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Initializes an NMAGeoPosition
 */
- (nonnull instancetype)init;

/**
 * Initializes an NMAGeoPosition instance with
 * specified coordinates, speed, course, and accuracy.
 *
 * @note The accuracy parameter will be used for all of latitudeAccuracy,
 * longitudeAccuracy, and altitudeAccuracy.
 *
 * @note The timestamp will be set to the current time.
 */
- (nullable instancetype)initWithCoordinates:(nonnull NMAGeoCoordinates *)coordinates
                                       speed:(double)speed
                                      course:(double)course
                                    accuracy:(double)accuracy;

/**
 * Initializes an NMAGeoPosition instance with
 * specified coordinates, speed, course, accuracy and timestamp.
 *
 * @note The accuracy parameter will be used for all of latitudeAccuracy,
 * longitudeAccuracy, and altitudeAccuracy.
 */
- (nullable instancetype)initWithCoordinates:(nonnull NMAGeoCoordinates *)coordinates
                                       speed:(double)speed
                                      course:(double)course
                                    accuracy:(double)accuracy
                                   timestamp:(nonnull NSDate *)timestamp;

/**
 * Initializes an NMAGeoPosition instance with
 * specified coordinates, speed, course, latitudeAccuracy, longitudeAccuracy
 * and altitudeAccuracy.
 */
- (nullable instancetype)initWithCoordinates:(nonnull NMAGeoCoordinates *)coordinates
                                       speed:(double)speed
                                      course:(double)course
                            latitudeAccuracy:(double)latitudeAccuracy
                           longitudeAccuracy:(double)longitudeAccuracy
                            altitudeAccuracy:(double)altitudeAccuracy
                                   timestamp:(nonnull NSDate *)timestamp;

/**
 * Initializes an NMAGeoPosition instance with
 * the specified CLLocation.
 */
- (nullable instancetype)initWithCLLocation:(nonnull CLLocation *)location;

/**
 * The geographical location of the position.
 */
@property (nonatomic, readonly, weak, nullable) NMAGeoCoordinates *coordinates;

/**
 * The accuracy of the latitude coordinate, in meters.
 *
 * @note Will be NMAGeoPositionUnknownValue if unknown.
 */
@property (nonatomic, readonly) double latitudeAccuracy;

/**
 * The accuracy of the longitude coordinate, in meters.
 *
 * @note Will be NMAGeoPositionUnknownValue if unknown.
 */
@property (nonatomic, readonly) double longitudeAccuracy;

/**
 * The accuracy of the altitude, in meters.
 *
 * @note Will be NMAGeoPositionUnknownValue if unknown.
 */
@property (nonatomic, readonly) double altitudeAccuracy;

/**
 * The movement speed of the position.
 *
 * @note Will be NMAGeoPositionUnknownValue if unknown.
 */
@property (nonatomic, readonly) double speed;

/**
 * The course (direction of travel) of the position, in degrees.
 *
 * Valid course values are in the range [0, 360), with 0 degrees representing
 * north and values increasing clockwise. Thus, east is 90 degrees, south is
 * 180 degrees, and so on.
 *
 * @note Will be NMAGeoPositionUnknownValue if unknown.
 */
@property (nonatomic, readonly) double course;

/**
 * The time at which the position measurements were taken.
 */
@property (nonatomic, readonly, nonnull) NSDate *timestamp;

/**
 * Building ID of this position.
 *
 * @return nil if building ID is not available.
 */
@property (nonatomic, readonly, nullable) NSString *buildingId;

/**
 * Building name in human readable format, e.g. "London Heathrow Airport".
 * There can be different buildings with the same name.
 *
 * @return nil if building name is not available
 */
@property (nonatomic, readonly, nullable) NSString *buildingName;

/**
 * FloorId is an integer identifying the floor level in the building.
 *
 * Floor id 0 specifies the floor that is considered the Main Level of the building.
 * In the case building has multiple levels that can be considered as Main Level,
 * the lowest level which can be considered as Main Level will be chosen.
 * Floors below the chosen Main Level will have negative integers
 * and floors above the chosen Main Level will have positive integers:
 * The floor above the Main Level has floor id 1 and the floor below the Main Level has floor id -1.
 *
 * @return nil if floor ID is not available.
 */
@property (nonatomic, readonly, nullable) NSNumber* floorId;

/**
 * Source of position.
 */
@property (nonatomic, readonly) NMAGeoPositionSource source;

/**
 * Indicates the validity of the `NMAGeoPosition`. The position is valid
 * if its coordinates are valid.
 */
@property (nonatomic, readonly) BOOL isValid;

@end
