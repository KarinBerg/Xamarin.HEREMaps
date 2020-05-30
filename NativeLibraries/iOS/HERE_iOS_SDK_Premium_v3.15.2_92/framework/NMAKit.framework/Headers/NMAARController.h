/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NMAARController;
@class NMAARObject;
@class NMAARModelObject;
@class NMAGeoCoordinates;
@class NMAARPoseReading;
@class NMAARRadarProperties;
@class NMAARUpViewParameters;
@class NMAARCameraParameters;
@class NMAARFilterParameters;
@class NMAARPolylineObject;

/**
 * The LiveSight group provides classes, protocols and enumerations
 * for displaying LiveSight and customizing the experience.
 * The key classes and interfaces in this group are
 * `NMACompositeView` and `NMAARController`.
 */

/**
 * The LiveSight API error domain.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAARErrorDomain;

/**
 * LiveSight error codes.
 */
typedef NS_ENUM(NSUInteger, NMAARError) {
    /**
     * No error.
     */
    NMAARErrorNone = 0,

    /**
     * The operation is not allowed at the time of the call. For example,
     * calling `NMAARController::start` a second time before calling stop.
     */
    NMAARErrorInvalidOperation = 1,

    /**
     * Parameters passed to the API are not valid.
     */
    NMAARErrorInvalidParameters = 2,

    /**
     * Access to this operation is denied. Contact your HERE
     * representative for more information.
     */
    NMAARErrorOperationNotAllowed = 3,

    /**
     * Camera unavailable.
     */
    NMAARErrorCameraUnavailable = 4,

    /**
     * Sensors unavailable.
     */
    NMAARErrorSensorsUnavailable = 5,

    /**
     * Livesight stopped.
     */
    NMAARErrorStopped = 6,

    /**
     * The user has not granted the app access to the camera to capture
     * video frames.
     *
     * The authorization status regarding video capture can be queried by calling
     * [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo].
     *
     * You should request the user grant access (iOS will prompt the user) by calling
     * [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted){}];
     */
    NMAARErrorCameraAccessNotAuthorized = 7
};

/**
 * Projection type used by the LiveSight engine for displaying
 * `NMAARObject`s in the camera view.
 */
typedef NS_ENUM(NSUInteger, NMAARProjectionType) {
    /**
     * Near-far projection. `NMAARObject`s appear in either a front
     * (near) or back (far) plane based on their proximity to the device. See
     * `NMAARObject` for further details of how objects are rendered in
     * this projection.
     */
    NMAARProjectionTypeNearFar,

    /**
     * Direct 3D projection. `NMAARObject`s appear in 3D space as a
     * result of direct projection of geo location.
     */
    NMAARProjectionTypeDirect3D,

    /**
     * Horizontal projection. `NMAARObject`s appear in one
     * horizontal line.
     */
    NMAARProjectionTypeHorizontal,

    /**
     * Map projection. `NMAARObject`s appear in the positions
     * projected to the screen via their geo coordinates.
     */
    NMAARProjectionTypeMap,

    /**
     * Use global default projection. The value of
     * NMAARController#projectionType defines the actual projection type used.
     */
    NMAARProjectionTypeGlobal
};


#pragma mark - Delegates

/**
 * A delegate protocol for handling NMAARController events.
 *
 * @note Methods of this protocol are called on the main queue.
 */
@protocol NMAARControllerDelegate<NSObject>

@optional

/**
 * Called when the camera view is presented.
 *
 * @param arController The NMAARController instance sending the callback.
 */
- (void)arControllerDidEnterCameraView:(nonnull NMAARController *)arController
NS_SWIFT_NAME(arController(didEnterCameraView:));


/**
 * Called when the camera view is hidden.
 *
 * @param arController The NMAARController instance sending the callback.
 */
- (void)arControllerDidExitCameraView:(nonnull NMAARController *)arController
NS_SWIFT_NAME(arController(didExitCameraView:));

/**
 * Called when a serious error occurs or when LiveSight is stopped.
 *
 * There may be the situations where hardware or other system components are not
 * behaving as expected. For example, sensors failing to respond, access being
 * denied to the camera or GPS hardware, or other hardware-related problems.
 *
 * This callback allows the app to handle such situations by asking the user to
 * attempt to recover by quitting the app or restarting the device. LiveSight
 * will continue to operate as best it can but certain features may not be
 * available. For example, if the camera cannot be started then the camera view
 * will not be presented.
 *
 * The same error may be reported more then once depending on the internal state
 * of the LiveSight system.
 *
 * @param arController The NMAARController instance sending the callback.
 * @param error The NMAARError that occured if available.
 */
- (void)arController:(nonnull NMAARController *)arController
       errorOccurred:(nullable NSError *)error;

/**
 * Called when the pose (device location and orientation) has been updated.
 *
 * The pose is udpated when the user moves the device (by tilting, rotating, or
 * changing location).
 *
 * @param arController The NMAARController instance sending the callback.
 * @param poseReading The current pose.
 */
- (void)arController:(nonnull NMAARController *)arController
       didUpdatePose:(nonnull NMAARPoseReading *)poseReading;

@end


/**
 * A delegate protocol for handling LiveSight camera view gesture events.
 *
 * To support default object press/unpress rendering and custom actions when a
 * touch up occurs on an object simply override
 * arController:shouldProcessTouchUpOnObjects:atPoint:. The remaining callbacks
 * of this protocol are for more advanced gesture control.
 *
 * @note Methods of this protocol are called on the main queue.
 */
@protocol NMAARControllerGestureDelegate<NSObject>

@optional

/**
 * Called when a touch down event occurs in the associated NMACompositeView.
 *
 * If YES is returned, or if this delegate method is not implemented, then the
 * object closest to the touch point will be rendered as pressed.
 *
 * @param arController The NMAARController instance sending the callback.
 * @param point The point at which the touch down occurred.
 *
 * @return NO if the touch event is NOT to be processed by NMAARController (this
 *         will disable the default behaviour described above).
 */
- (BOOL)             arController:(nonnull NMAARController *)arController
    shouldProcessTouchDownAtPoint:(CGPoint)point;

/**
 * Called when a pan gesture occurs in the associated NMACompositeView.
 *
 * If YES is returned, or if this delegate method is not implemented, then
 * pan gestures will be handled using the default behaviour.
 *
 * For NMAARProjectionTypeNearFar, performing a pan gesture has the visual effect
 * of moving objects between the back plane and the front plane. In reality, the
 * gesture is actually just changing the geo coordinates that define the boundary
 * between the two planes and hence changing the definition of which objects are
 * considered "near" and "far".
 *
 * @param arController The NMAARController instance sending the callback.
 * @param fromPoint The start point of the pan gesture.
 * @param toPoint The end point of the pan gesture.
 *
 * @return NO if the pan event is NOT to be processed by NMAARController (this
 *         will disable the default behaviour described above).
 */
- (BOOL)         arController:(nonnull NMAARController *)arController
    shouldProcessPanFromPoint:(CGPoint)fromPoint
                      toPoint:(CGPoint)toPoint;

/**
 * Called when a touch up event occurs in the associated NMACompositeView.
 *
 * Any object previously rendered as pressed by NMAARController will be rendered
 * unpressed on a touch up event.
 *
 * @param arController The NMAARController instance sending the callback.
 * @param point The point at which the touch up occurred.
 *
 * @return NO if the touch event is NOT to be processed by NMAARController (this
 *         will prevent object selection on touch up and prevent
 *         arController:shouldProcessTouchUpOnObjects:atPoint: from being called.
 */
- (BOOL)           arController:(nonnull NMAARController *)arController
    shouldProcessTouchUpAtPoint:(CGPoint)point;

/**
 * Called when a touch up event occurs in the associated NMACompositeView.
 *
 * If YES is returned, or if this delegate method is not implemented, then the
 * object closest to the touch point will be selected if the preceding touch
 * down occured on that object.
 *
 * @param arController The NMAARController instance sending the callback.
 * @param objects An array of NMAARObjects located at the touch point.
 * @param point The point at which the touch up occurred.
 *
 * @return NO if the touch event is NOT to be processed by NMAARController (this
 *         will disable the default behaviour described above).
 *
 * @note This delegate method will not be called if the delegate method
 *       arController:shouldProcessTouchDownAtPoint: returns NO.
 */
- (BOOL)             arController:(nonnull NMAARController *)arController
    shouldProcessTouchUpOnObjects:(nonnull NSArray<NMAARObject *> *)objects
                          atPoint:(CGPoint)point;

/**
 * Called when a tap gesture occurs in the associated NMACompositeView.
 *
 * Currently no default action is performed on a tap event. However, if you
 * implement this method it is recommended to return NO to override any default
 * tap handling that may be introduced in the future.
 *
 * @param arController The NMAARController instance sending the callback.
 * @param point The point at which the touch occurred.
 *
 * @return NO if the touch event is NOT to be processed by NMAARController.
 */
- (BOOL)       arController:(nonnull NMAARController *)arController
    shouldProcessTapAtPoint:(CGPoint)point;

@end


/**
 * NMAARController is used to start and configure LiveSight functionality
 *
 * When LiveSight is started it will begin to control the associated NMACompositeView
 * and display a LiveSight camera view.
 *
 * In the default projection mode (NMAARProjectionTypeNearFar), LiveSight objects
 * are displayed in either the front plane or the back plane based on their
 * geographical distance from the device. Objects in the front plane appear
 * closer to the bottom of the camera view and objects in the back plane appear
 * closer to the top of the view. Objects have different apperance and exhibit
 * different behaviours in each plane.
 *
 * Objects geographically closer to the device are placed in the front plane.
 * Performing a pan down gesture has the visual effect of moving objects from the
 * back plane to the front plane but the gesture is actually just changing the
 * geocoordinates that define the boundary between the two planes and hence
 * changing the definition of which objects are considered "near" and "far".
 *
 * NMAARControllerDelegate reports LiveSight events including view changes.
 */
@interface NMAARController : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

#pragma mark - Basic Control

/**
 * The delegate for receiving general LiveSight event and status changes.
 */
@property (nonatomic, weak, nullable) id<NMAARControllerDelegate> delegate;

/**
 * The delegate for receiving gesture callbacks from the LiveSight camera view.
 */
@property (nonatomic, weak, nullable) id<NMAARControllerGestureDelegate> gestureDelegate;

/**
 * Starts the LiveSight camera view.
 *
 * If LiveSight is successfully started then the LiveSight camera view will be
 * presented and NMAARDelegate#arController:arControllerDidEnterCameraView: will
 * be called.
 *
 * NMAARDelegate#arController:errorOccurred: will be called if LiveSight
 * experiences an unrecoverable error during startup or subsequent operations.
 *
 * @return nil if the start up sequence is initialized, otherwise an NSError
 * populated with an NMAARError code. The error NMAARErrorOperationNotAllowed
 * indicates that an updated HERE license key is required. Contact your HERE
 * representative for more information.
 */
- (nullable NSError *)start;

/**
 * Stops the LiveSight camera view.
 *
 * NMAARDelegate#arController:errorOccurred: will be called with NMAARErrorStopped
 * when exit animations have completed and LiveSight has stopped.
 *
 * When LiveSight is stopped the NMACompositeView will render a solid black view.
 *
 * @param animation If YES, an exit animation is performed before stopping LiveSight.
 *                  This parameter is currently ignored.
 *
 * @return nil if the stop request succeeded, otherwise an NSError populated with
 * an NMAARError error code.
 */
- (nullable NSError *)stopWithAnimation:(BOOL)animation;

/**
 * Indicates whether or not LiveSight has started.
 */
@property (nonatomic, readonly) BOOL isStarted;


#pragma mark - Device Pose (Position and Orientation)

/**
 * The last known device location or nil if the location is unknown.
 *
 * This is a convenience method that creates a geo coordinates from the current
 * pose reading.
 */
@property (nonatomic, readonly, nullable) NMAGeoCoordinates *location;

/**
 * An alternative device location to use for LiveSight.
 *
 * This method may be used to force LiveSight to use an alternative to the current
 * device location during testing. The alternative location will be reflected by
 * the location and poseReading properties.
 *
 * This default value is nil, in which case the actual device location is used.
 */
@property (nonatomic, nullable) NMAGeoCoordinates *alternativeLocation;

/**
 * The latest LiveSight pose (device location and orientation).
 *
 * @note Method `NMAARControllerDelegate::arController:didUpdatePose:`
 * is called when the pose changes.
 */
@property (nonatomic, readonly, nullable) NMAARPoseReading *poseReading;


#pragma mark - Objects

/**
 * Sets the front plane icon size, in points, for NMAARIconObjects.
 *
 * Before adding icon objects to the LiveSight view, the front plane icon size
 * should be specified here. For optimal results, only a single icon size should
 * be used.
 *
 * @note If the front plane icon size is not specified explicitly, it will be
 * inferred from the first icon object added to the LiveSight view.
 */
- (void)setFrontPlaneIconSize:(CGSize)size;

/**
 * Adds an `NMAARObject` that will be displayed in the camera view.
 *
 * @param object The NMAARObject to add to the `NMAARController`.
 *
 * @note Objects should not be added whilst Livesight is in a "starting" state as
 * this may cause the main thread to block. I.e. Don't add objects after calling
 * [NMAARController start] until the  [NMAARControllerDelegate arControllerDidEnterCameraView:]
 * callback has returned.
 */
- (void)addObject:(nonnull NMAARObject *)object;

/**
 * Removes an `NMAARObject` from the camera view.
 *
 * @param object The NMAARObject to remove from the `NMAARController`.
 */
- (void)removeObject:(nonnull NMAARObject *)object;

/**
 * Adds an NMAARPolylineObject that will be displayed in the camera view.
 *
 * @param object The NMAARPolyline to add to the `NMAARController`.
 *
 * @note Objects should not be added whilst Livesight is in a "starting" state as
 * this may cause the main thread to block. I.e. Don't add objects after calling
 * [NMAARController start] until the [NMAARControllerDelegate arControllerDidEnterCameraView:]
 * callback has returned.
 */
- (void)addPolylineObject:(nonnull NMAARPolylineObject *)object;

/**
 * Removes an `NMAARModelObject` from the camera view.
 *
 * @param object The NMAARModelObject to remove from the `NMAARController`.
 */
- (void)removePolylineObject:(nonnull NMAARPolylineObject *)object;

/**
 * Adds an `NMAARModelObject` that will be displayed in the camera view.
 *
 * @param object The NMAARModelObject to add to the `NMAARController`.
 *
 * @note Objects should not be added whilst Livesight is in a "starting" state as
 * this may cause the main thread to block. I.e. Don't add objects after calling
 * [NMAARController start] until the [NMAARControllerDelegate arControllerDidEnterCameraView:]
 * callback has returned.
 */
- (void)addModelObject:(nonnull NMAARModelObject *)object;

/**
 * Removes an `NMAARModelObject` from the camera view.
 *
 * @param object The NMAARModelObject to remove from the `NMAARController`.
 */
- (void)removeModelObject:(nonnull NMAARModelObject *)object;

/**
 * Returns the `NMAARObject` at a given point if available and optionally
 * renders the object as pressed.
 *
 * This method is designed to be used in conjunction with NMAARControllerGestureDelegate
 * to implement custom object gestures with visual feedback. Typically an object
 * becomes pressed when a touch down event occurs on that object. Multiple objects
 * may be in the pressed state.
 *
 * @param point The point in the associated NMAARCompositeView at which to check
 *        for an object.
 * @param press A BOOL indicating whether or not to press the returned object.
 *
 * @return The NMAARObject at the given point, or nil if no object is present.
 *
 * @note Object press is only applicable in the camera view. An object can be
 * rendered pressed regardless of its selected or focused state.
 */
- (nullable NMAARObject *)objectAtPoint:(CGPoint)point
                              withPress:(BOOL)press;

/**
 * Renders an NMAARObject as pressed.
 *
 * This method is designed to be used in conjunction with NMAARControllerGestureDelegate
 * to implement custom object gestures with visual feedback. Typically an object
 * becomes pressed when a touch down event occurs on that object. Multiple objects
 * may be in the pressed state.
 *
 * @param object The NMAARObject to render as pressed.
 *
 * @note Object press is only applicable in the camera view. An object can be
 * rendered pressed regardless of its selected or focused state.
 */
- (void)pressObject:(nonnull NMAARObject *)object;

/**
 * Renders an NMAARObject as not pressed (the default state).
 *
 * This method is designed to be used in conjunction with NMAARControllerGestureDelegate
 * to implement custom object gestures with visual feedback. Typically any pressed
 * objects are unpressed when a touch up event occurs anywhere on the view.
 *
 * @param object The NMAARObject to render unpressed; this method has no effect
 *               if the object is not currently pressed.
 *
 * @note Object press is only applicable in the camera view.
 */
- (void)unpressObject:(nonnull NMAARObject *)object;

/**
 * Selects an NMAARObject in the camera view.
 *
 * Any object in camera view can be in the selected state regardless of its plane.
 * Selected objects are rendered differently than "focused" objects. An object is
 * automatically unselected if another object is selected. Only one object can be
 * selected at a time.
 *
 * When selected, the object's info image collapses and the back plane image
 * replaces the front plane image (if the object is in the front plane). The
 * appearance of selected and deselected objects will be configurable in future
 * SDK releases.
 *
 * @param object The NMAARObject to select.
 *
 * @note Object selection only applies to the camera view.
 */
- (void)selectObject:(nonnull NMAARObject *)object;

/**
 * Select an NMAARObject in the camera view with optional configuration.
 *
 * Any object in camera view can be in the selected state regardless of its plane.
 * Selected objects are rendered differently than "focused" objects. An object is
 * automatically unselected if another object is selected. Only one object can be
 * selected at a given time.
 *
 * When selected, the object's info image collapses, the back plane image
 * replaces the front plane image (if the object is in the front plane) and the
 * image is scaled (if specified).
 *
 * @param object The NMAARObject to be marked as selected.
 * @param allowInfo A BOOL value indicating whether the object's info image should
 *                  be displayed while the object is selected.
 * @param scale The amount to scale the object's image by when selected.
 *
 * @note Object selection only applies to the camera view. An object may not be
 * selected and focused at the same time. Selecting a focused object will defocus
 * the object and vice versa.
 */
- (void)selectObject:(nonnull NMAARObject *)object
           allowInfo:(BOOL)allowInfo
               scale:(CGFloat)scale;

/**
 * Deselects a previously selected `NMAARObject` in the camera view.
 *
 * When an object is unselected, its info image (if set) expands, the front plane
 * image is used instead of the back plane image (if item is in front plane),
 * the item is scaled to normal size, and all opacities change to default values.
 *
 * @note Object selection only applies to the camera view.
 */
- (void)deselectObject;

/**
 * Focuses an `NMAARObject` in the camera view back plane.
 *
 * Focusing brings the object in front of other items and expands its info image.
 *
 * An object becomes defocused automatically if another object is focused; only
 * one object can be in focus at a time.
 *
 * @param object The NMAARObject to focus.
 *
 * @note Object focus only applies to the camera view back plane. An object may
 * not be selected and focused at the same time. Focusing a selected object will
 * deselect the object and vice versa.
 */
- (void)focusObject:(nonnull NMAARObject *)object;

/**
 * Defocuses a previously focused `NMAARObject` in the camera view Back plane.
 *
 * Returns the object to its original position among all other objects in the
 * camera view back plane.
 *
 * @note Object focus only applies to the camera view back plane.
 */
- (void)defocusObject;

/**
 * Retrieves `NMAARObject`s at a specified screen point.
 *
 * @param point The point within the associated NMAARCompositeView at which
 *              to check for `NMAARObject`s.
 *
 * @return An array of `NMAARObject`, or nil if no objects are
 * located at the specified point.
 */
- (nullable NSArray<NMAARObject *> *)objectsAtPoint:(CGPoint)point;

/**
 * Retrieves `NMAARObject`s which intersect a specified screen rect.
 *
 * @param rect The screen rect within the associated NMAARCompositeView inside
 *             which to check for `NMAARObject`s.
 *
 * @return An array of `NMAARObject`, or nil if no objects intersect
 * the specified rect.
 */
- (nullable NSArray<NMAARObject *> *)objectsInRect:(CGRect)rect;


#pragma mark - Camera View Configuration

/**
 * The projection type used to display `NMAARObject`s in the camera view.
 *
 * Attempts to set this property to NMAARProjectionTypeGlobal will be ignored.
 *
 * @note NMAARObject instances may override this default by setting an explicit
 * projectionType.
 */
@property (nonatomic) NMAARProjectionType projectionType;

/**
 * Controls whether only front plane objects are displayed in the camera view.
 *
 * Front plane object have their info images visible.
 *
 * @note Only applicable when the projection type is NMAARProjectionTypeNearFar.
 */
@property (nonatomic, getter = isShowingFrontPlaneObjectsOnly) BOOL showFrontPlaneObjectsOnly;

/**
 * The GPS location distance threshold, in meters, used to determine when object
 * projection is updated.
 *
 * When the distance between the current GPS location the location of the last
 * projection update is bigger than the threshold, the camera view projection of
 * objects is updated.
 *
 * The default value is 3 meters.
 */
@property (nonatomic) float objectUpdateGpsDistanceThreshold;

/**
 * Advanced camera view configuration parameters.
 *
 * See also `NMAARCameraParameters`
 */
@property (nonatomic, readonly, nonnull) NMAARCameraParameters *cameraParameters;

@end
