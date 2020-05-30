/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@class NMAMapView;


/**
 * The types of gesture that can be performed on an NMAMapView.
 */
typedef NS_OPTIONS(NSInteger, NMAMapGestureType) {
    /** A double tap. */
    NMAMapGestureTypeDoubleTap      = 1 << 0,
    /** A long press. */
    NMAMapGestureTypeLongPress      = 1 << 1,
    /** A pan. */
    NMAMapGestureTypePan            = 1 << 2,
    /** A pinch. */
    NMAMapGestureTypePinch          = 1 << 3,
    /** A two-finger map rotate. */
    NMAMapGestureTypeRotate         = 1 << 4,
    /** A tap. */
    NMAMapGestureTypeTap            = 1 << 5,
    /** A two-finger pan. */
    NMAMapGestureTypeTwoFingerPan   = 1 << 6,
    /** A two-finger tap. */
    NMAMapGestureTypeTwoFingerTap   = 1 << 7,
    /** All geture types. */
    NMAMapGestureTypeAll            = 0xFF
};

/**
 * Delegate protocol for map gesture handling.
 *
 * This protocol should be implemented by any class which acts as the gesture delegate for a map view
 * or any map subview which needs to receive gestures from the map view.
 *
 * When a gesture is detected by the map view, the following steps are taken:
 *
 * 1. The map checks whether a suitable subview can be found to handle the gesture (see below)
 *
 * 2. If a suitable subview is found, the gesture is passed to it and the map takes no further action
 *
 * 3. If a subview is not found, the NMAMapView's gestureDelegate is checked if present to see if it
 * can handle the gesture type in question
 *
 * 4. The gesture is passed to the delegate if it can handle it, and the map takes no further action
 *
 * 5. Finally, if the gesture is still not handled, the NMAMapView takes the default action
 * (e.g. panning, zooming, etc. depending on the type of gesture received)
 *
 * In order for a map subview to accept a gesture which originates inside it, three conditions must
 * be met: the view must be visible, it must implement the `NMAMapGestureDelegate` protocol, and it
 * must implement the specific gesture handling method for the type of gesture in question.
 * If a gesture hits a subview which cannot handle it, the NMAMApView will perform the same
 * check on that view's superview. The view hierarchy is ascended in this manner until either the
 * gesture is accepted or the NMAMapView itself is reached. Note that a subview using the
 * NMAMapGestureDelegate protocol may implement any or all of the gesture handling methods.
 *
 * The NMAMapView may optionally be provided with a gesture delegate, set via the gestureDelegate
 * property. This delegate can be used to modify how the NMAMapView responds to some or all of
 * its recognized gestures. The delegate class must implement the NMAMapGestureDelegate protocol;
 * however, it need not implement all of the gesture handling methods. For any methods not
 * implemented, the default behaviour will be used when that type of gesture is received. If
 * specialized gesture behaviour is desired in addition to the default behaviour, then
 * the custom gesture handling method should invoke the implementation of that handling method
 * on the map view's default gesture handler, accessed via the defaultGestureHandler property.
 *
 * For example, to add behaviour when the map receives a tap, the delegate class implementation
 * of the NMAMapGestureDelegate protocol method mapView:(NMAMapView*)mapView didReceiveTapAtLocation:
 * could have the following form:
 *
 * \code
 * -(void)mapView:(NMAMapView*)mapView didReceiveTapAtLocation:(CGPoint)location
 * {
 *     // Some custom tap behaviour
 *     // ...
 *
 *     [mapView.defaultGestureHandler mapView:mapView didReceiveTapAtLocation:location];
 *
 *     // More custom tap behaviour
 *     // ...
 * }
 * \endcode
 *
 * @note Methods of this protocol will be called on the main queue.
 */
@protocol NMAMapGestureDelegate<NSObject>

@optional

/**
 * Delegate callback for an NMAMapView tap gesture.
 *
 * @param mapView The NMAMapView on which the gesture occurred.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceiveTapAtLocation:(CGPoint)location
NS_SWIFT_NAME(mapView(_:didReceiveTapAt:));

/**
 * Delegate callback for an NMAMapView double-tap gesture.
 *
 * @param mapView The NMAMapView on which the gesture occurred.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceiveDoubleTapAtLocation:(CGPoint)location
NS_SWIFT_NAME(mapView(_:didReceiveDoubleTapAt:));

/**
 * Delegate callback for an NMAMapView two finger-tap gesture.
 *
 * @param mapView The NMAMapView on which the gesture occurred.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceiveTwoFingerTapAtLocation:(CGPoint)location
NS_SWIFT_NAME(mapView(_:didReceiveTwoFingerTapAt:));

/**
 * Delegate callback for an NMAMapView pan gesture.
 *
 * The translation of a pan gesture is reported as the distance covered by the gesture
 * since the last callback or since the beginning of the gesture. Note that this differs
 * from the behaviour of UIPanGestureRecognizer, which reports the total translation
 * since the beginning of the gesture.
 *
 * @param mapView The NMAMapView on which the gesture occurred.
 * @param translation The current translation of the pan gesture, in points.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceivePan:(CGPoint)translation atLocation:(CGPoint)location
NS_SWIFT_NAME(mapView(_:didReceivePan:at:));

/**
 * Delegate callback for an NMAMapView two finger-pan gesture.
 *
 * @param mapView The NMAMapView on which the gesture occurred.
 * @param translation The current translation of the pan gesture, in points.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceiveTwoFingerPan:(CGPoint)translation atLocation:(CGPoint)location
NS_SWIFT_NAME(mapView(_:didReceiveTwoFingerPan:at:));

/**
 * Delegate callback for an NMAMapView rotation gesture.
 *
 * The current rotation is calculated as the net rotation that has occurred since the
 * last rotation callback or since the beginning of the gesture. Note that this differs
 * from the behaviour of UIRotationGestureRecognizer, which reports the total rotation
 * since the beginning of the gesture.
 *
 * @param mapView The NMAMapView on which the gesture occurred.
 * @param rotation The current rotation of the gesture, in degrees.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceiveRotation:(float)rotation atLocation:(CGPoint)location
NS_SWIFT_NAME(mapView(_:didReceiveRotation:at:));

/**
 * Delegate callback for an NMAMapView pinch gesture.
 *
 * The current pinch change is measured as the relative distance change of the two touch
 * points since the last pinch callback or the beginning of the gesture. For example, if
 * the pinch value is 1.2, the two touches are 20% farther apart than they were at the time
 * of the last update. Note that this differs from the behaviour of UIPinchGestureRecognizer,
 * which reports the total pinch since the beginning of the gesture.
 *
 * @param mapView The NMAMapView on which the gesture occurred.
 * @param pinch The current relative pinch change of the gesture.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceivePinch:(float)pinch atLocation:(CGPoint)location
NS_SWIFT_NAME(mapView(_:didReceivePinch:at:));

/**
 * Delegate callback for an NMAMapView long press gesture.
 *
 * @param mapView The NMAMapView on which the gesture occurred.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceiveLongPressAtLocation:(CGPoint)location
NS_SWIFT_NAME(mapView(_:didReceiveLongPressAt:));

@end
