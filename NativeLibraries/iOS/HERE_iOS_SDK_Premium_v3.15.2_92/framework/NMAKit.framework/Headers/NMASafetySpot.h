/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 */

@class NMAGeoCoordinates;

/**
 *  Defines the safety spot type: undefined, speed camera, red light camera or both speed and red light camera.
 */
typedef NS_ENUM(NSUInteger, NMASafetySpotType) {
    NMASafetySpotTypeUndefined,
    NMASafetySpotTypeSpeedCamera,
    NMASafetySpotTypeRedLightCamera,
    NMASafetySpotTypeSpeedRedLightCamera
};


/**
 * NMASafetySpot represents a safety spot instance.
 */
@interface NMASafetySpot : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Heading in degrees representing the operational direction of the camera -
 * ie the direction of travel of vehicles detected by the camera (regardless
 * of whether the camera photographs front or rear of the vehicle).
 * With no heading ( value is zero ), a camera operates in all directions.
 * Safety spot may have two cameras; see get_heading_2_deg( ).
 * Contains the heading in degrees, 1 - 359, where 1 is north. The angle increases clockwise.
 */
@property (nonatomic, readonly) NSInteger heading1;

/**
 * Heading for the ( possible ) second camera.
 * If heading 1 is not zero, and heading 2 is zero, there is
 * only one camera, using the heading 1.
 * Contains the heading in degrees, 1 - 359, where 1 is north. The angle increases clockwise.
 */
@property (nonatomic, readonly) NSInteger heading2;

/**
 * The speed limit that triggers the camera on heading 1 in m/s.
 */
@property (nonatomic, readonly) float speedLimit1;

/**
 * The speed limit that triggers the camera on heading 2 in m/s.
 */
@property (nonatomic, readonly) float speedLimit2;

/**
 * The location of the camera.
 */
@property (nonatomic, readonly, nullable) NMAGeoCoordinates *location;

/**
 * The type of the safety spot.
 */
@property (nonatomic, readonly) NMASafetySpotType type;

@end
