/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;
@class NMARoadElement;
@class NMATransitRouteElement;

/**
 * Defines types of route element.
 */
typedef NS_ENUM(NSInteger, NMARouteElementType) {
    /** Transit Route Element */
    NMARouteElementTransit = 0,
    /** Road Element */
    NMARouteElementRoad,
    /** invalid  */
    NMARouteElementInvalid
};

/**
 * Enumeration for travel direction.
 */
typedef NS_ENUM(NSUInteger, NMATravelDirection) {
    /** Driving in the 'canonical' direction of the road */
    NMATravelDirectionForward   = 0,
    /** Driving against the 'canonical' direction of the road */
    NMATravelDirectionBackward  = 1
};



/**
 * Represents a generic container for an element of a route.
 */
@interface NMARouteElement : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The route element type.
 */
@property (nonatomic, readonly) NMARouteElementType type;

/**
 * Road element of the route element.
 *
 * @note nil if type of the route element is not `NMARouteElementRoad`
 */
@property (nonatomic, readonly, nullable) NMARoadElement *roadElement;

/**
 * NMATransitRouteElement of the route element.
 *
 * @note nil if route element type is not NMARouteElementTransit.
 */
@property (nonatomic, readonly, nullable) NMATransitRouteElement *transitRouteElement;

/**
 * Gives all the points of the route element polyline presented as an array of NMAGeoCoordinates
 * objects.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAGeoCoordinates *> *geometry;

/**
 * Gets the travel direction (either FORWARD or BACKWARD) for the route on a given RoadElement.
 * The primary use case for this value is when wanting to calculate a new route which matches
 * the current route or a portion of the current route. Waypoints may be specified using
 * a RoadElement Identifier and this travelDirection value and then used as stops when calculating
 * the new route.
 */
@property (nonatomic, readonly) NMATravelDirection travelDirection;

@end
