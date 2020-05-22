/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>

@class NMAGeoCoordinates;
@class NMAMapView;
@class NMAPositionIndicator;
@class NMAVenue3dAnimationController;
@class NMAVenue3dController;
@class NMAVenue3dCombinedNavigation;
@class NMAVenue3dLevel;
@class NMAVenue3dSpace;
@class NMAVenue3dMapLayer;
@class NMAVenue3dNavigationManager;
@class NMAVenue3dRoutingController;
@class NMAVenue3dVenue;
@class NMAVenue3dVenueInfo;


/**
 * Represents values that describe the source which has called deselection
 * of the venue.
 *
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dDeselectEvent) {
    /**
     * Map was moved out from the venue viewport.
     */
    NMAVenueDeselectEventMapMoved           NS_SWIFT_NAME(mapMoved),

    /**
     * Map was zoom out to the specific zoom level where venue shouldn't be
     * shown and venue fully in view port.
     */
    NMAVenueDeselectEventMapZoomedOut       NS_SWIFT_NAME(zoomedOut),

    /**
     * Map was tapped outside the venue.
     */
    NMAVenueDeselectEventMapTappedOutside   NS_SWIFT_NAME(tappedOutside),

    /**
     * The NMAVenue3dMapLayer was switched off.
     */
    NMAVenueDeselectEventLayerDisabled      NS_SWIFT_NAME(layerDisabled),

    /**
     * Other venue was selected.
     */
    NMAVenueDeselectEventSelectedOther      NS_SWIFT_NAME(selectedOther),

    /**
     * Venue was deselected manually through API.
     */
    NMAVenueDeselectEventManual             NS_SWIFT_NAME(manual)
};

/**
 * Represents a delegate that offers listeners and callback methods related to
 * venue map layer.
 *
 * @note Methods of this protocol are called on the main queue.
 *
 */
@protocol NMAVenue3dMapLayerDelegate<NSObject>

@optional


/**
 * This callback method is triggered when a venue is tapped.
 *
 * @param venueMapLayer
 *            The NMAVenue3dMapLayer with tapped venue.
 * @param venue
 *            The NMAVenue3dVenue with tapped venue.
 * @param point screen position on the tapped point
 */
- (void)venueMapLayer:(nonnull NMAVenue3dMapLayer *)venueMapLayer
          didTapVenue:(nonnull NMAVenue3dVenue *)venue
              atPoint:(CGPoint)point
NS_SWIFT_NAME(venueMapLayer(_:didTapVenue:at:));

/**
 * This callback method is triggered when a venue is selected.
 *
 * @param venueMapLayer
 *            The NMAVenue3dMapLayer with selected venue.
 * @param venue
 *            The selected NMAVenue3dVenue.
 */
- (void)venueMapLayer:(nonnull NMAVenue3dMapLayer *)venueMapLayer
       didSelectVenue:(nonnull NMAVenue3dVenue *)venue
NS_SWIFT_NAME(venueMapLayer(_:didSelectVenue:));

/**
 * This callback method is triggered when a venue is deselected.
 *
 * @param venueMapLayer
 *            The NMAVenue3dMapLayer with deselected venue.
 * @param venue
 *            The deselected NMAVenue3dVenue.
 * @param event
 *            The event which has called deselection of the venue.
 */
- (void)venueMapLayer:(nonnull NMAVenue3dMapLayer *)venueMapLayer
     didDeselectVenue:(nonnull NMAVenue3dVenue *)venue
            withEvent:(NMAVenue3dDeselectEvent)event
NS_SWIFT_NAME(venueMapLayer(_:didDeselectVenue:event:));

/**
 * This callback method is triggered when a space is tapped.
 *
 * @param venueMapLayer
 *            The NMAVenue3dMapLayer with selected space.
 * @param space
 *            The selected NMAVenue3dSpace.
 * @param venue
 *            The NMAVenue3dVenue with selected space.
 */
- (void)venueMapLayer:(nonnull NMAVenue3dMapLayer *)venueMapLayer
       didSelectSpace:(nonnull NMAVenue3dSpace *)space
              inVenue:(nonnull NMAVenue3dVenue *)venue
NS_SWIFT_NAME(venueMapLayer(_:didSelectSpace:inVenue:));

/**
 * This callback method is triggered when a space is deselected.
 *
 * @param venueMapLayer
 *            The NMAVenue3dMapLayer with deselected space.
 * @param space
 *            The deselected NMAVenue3dSpace.
 * @param venue
 *            The NMAVenue3dVenue with deselected space.
 */
- (void)venueMapLayer:(nonnull NMAVenue3dMapLayer *)venueMapLayer
     didDeselectSpace:(nonnull NMAVenue3dSpace *)space
              inVenue:(nonnull NMAVenue3dVenue *)venue
NS_SWIFT_NAME(venueMapLayer(_:didDeselectSpace:inVenue:));

/**
 * This callback method is triggered when a floor is changed.
 *
 * @param venueMapLayer
 *            The NMAVenue3dMapLayer where floor is changed.
 * @param oldLevel
 *            The previously selected NMAVenue3dLevel.
 * @param newLevel
 *            The currently selected NMAVenue3dLevel.
 * @param venue
 *            The NMAVenue3dVenue where floor is changed.
 */
- (void) venueMapLayer:(nonnull NMAVenue3dMapLayer *)venueMapLayer
    didChangeFromLevel:(nonnull NMAVenue3dLevel *)oldLevel
               toLevel:(nonnull NMAVenue3dLevel *)newLevel
               inVenue:(nonnull NMAVenue3dVenue *)venue
NS_SWIFT_NAME(venueMapLayer(_:didChangeFromLevel:toLevel:inVenue:));

/**
 * This callback method is triggered when a venue becomes visible in the triggering area
 * The triggering area is centered to the viewport. The width of the triggering area is two-thirds of the map width
 * and the height is the same as the width.
 *
 * @param venueMapLayer
 *            The NMAVenue3dMapLayer with venue visible in viewport.
 * @param venue
 *            The visible venue NMAVenue3dVenue.
 */
- (void)venueMapLayer:(nonnull NMAVenue3dMapLayer *)venueMapLayer
         didShowVenue:(nonnull NMAVenue3dVenue *)venue
NS_SWIFT_NAME(venueMapLayer(_:didShowVenue:));

/**
 * This callback method is triggered when when a venue disappears from the triggering area.
 * The triggering area is centered to the viewport. The width of the  triggering area is two-thirds of the map width
 * and the height is the same as the width.
 *
 * @param venueMapLayer
 *            The NMAVenue3dMapLayer with venue visible in viewport.
 * @param venue
 *            The hidden venue NMAVenue3dVenue.
 */
- (void)venueMapLayer:(nonnull NMAVenue3dMapLayer *)venueMapLayer
         didHideVenue:(nonnull NMAVenue3dVenue *)venue
NS_SWIFT_NAME(venueMapLayer(_:didHideVenue:));

/**
 * This callback method is triggered when when a venue controller has been created.
 *
 * @param venueMapLayer
 *            The NMAVenue3dMapLayer.
 * @param venueController
 *            The NMAVenue3dController that was created.
 */
- (void)venueMapLayer:(nonnull NMAVenue3dMapLayer *)venueMapLayer
         didCreateVenueController:(nonnull NMAVenue3dController *)venueController
NS_SWIFT_NAME(venueMapLayer(_:didCreateVenueController:));

/**
 * This callback method is triggered when NMAVenue3dMapLayer::start completes.
 *
 * @param venueMapLayer
 *            The venue map layer NMAVenue3dMapLayer started.
 */
- (void)venueMapLayerDidStart:(nonnull NMAVenue3dMapLayer *)venueMapLayer
NS_SWIFT_NAME(venueMapLayerDidStart(_:));

@end

/**
 * Represents a delegate for Venue Zoom notifications.
 *
 * @note Methods of this protocol are called on the main queue.
 *
 */
@protocol NMAVenue3dVenueZoomDelegate<NSObject>

/**
 * This callback method is triggered when Venue Zoom is activated or deactivated.
 *
 * @param venueMapLayer
 *            The NMAVenue3dMapLayer with the venue where the event happens.
 *
 * @param venue
 *            The NMAVenue3dVenue where Venue Zoom is activated or deactivated.
 *
 * @param active
 *            Indicates if Venue Zoom is activated or deactivated.
 */
-     (void)venueMapLayer:(nonnull NMAVenue3dMapLayer *)venueMapLayer
didUpdateVenueZoomInVenue:(nonnull NMAVenue3dVenue *)venue
                withValue:(bool)active
NS_SWIFT_NAME(venueMapLayer(_:didUpdateVenueZoomInVenue:active:));

@optional

@end


/**
 * NMAVenue3dMapLayer provides a map with indoor venue maps.
 *
 * When the `NMAVenue3dMapLayer` is started, venues such as shopping malls and airports can be seen on
 * the map as interactive 3D models. Also spaces inside venues and access information like entrances can be seen.
 * 
 * After getting a NMAVenue3dMapLayer object, NMAVenue3dMapLayer::delegate need to be set in order to receive layer events,
 * and the layer must be activated by calling NMAVenue3dMapLayer::start.
 * 
 * NMAVenue3dMapLayer is an add-on to the base map functionality with its own content loading and cache.
 * For this reason in certain situations there may be a small delay before a venue can be seen on the map
 * because if it is not already in the cache it needs to be downloaded separately.
 *
 * @note This class can not be instantiated directly. NMAVenue3dMapLayer object can be fetched via
 * NMAMapView::venue3dMapLayer
 *
 */
@interface NMAVenue3dMapLayer : NSObject

/**
 * An event handler for the NMAVenue3dMapLayer.
 * 
 * An object may be installed as the NMAVenue3dMapLayer delegate in order to respond
 * to certain NMAVenue3dMapLayer events, such as venue selection or floor changing. See the
 * NMAVenue3dMapLayerDelegate protocol for the full list of events.
 */
@property (nonatomic, weak, nullable) id<NMAVenue3dMapLayerDelegate> delegate;

/**
 * Add a listener to the venue map layer. The listener must implement the NMAVenue3dMapLayerDelegate protocol.
 * The listener monitors certain NMAVenue3dMapLayer events, such as venue selection or floor changing.
 *
 * @param listener the NMAVenue3dMapLayerDelegate object to be added.
 *
 * See also `NMAVenue3dMapLayerDelegate`
 */
- (void)addListener:(nonnull id<NMAVenue3dMapLayerDelegate>)listener
NS_SWIFT_NAME(add(listener:));

/**
 * Remove a listener from the venue map layer. The listener must implement the NMAVenue3dMapLayerDelegate protocol.
 * The listener monitors certain NMAVenue3dMapLayer events, such as venue selection or floor changing.
 *
 * @param listener the NMAVenue3dMapLayerDelegate object to be removed.
 *
 * See also `NMAVenue3dMapLayerDelegate`
 */
- (void)removeListener:(nonnull id<NMAVenue3dMapLayerDelegate>)listener
NS_SWIFT_NAME(remove(listener:));

/**
 * NMAVenue3dController object of the selected venue or nil if there is no selected venue.
 */
@property (nonatomic, readonly, nullable) NMAVenue3dController *venueController;


/**
 * NMAVenue3dRoutingController object which can be used to calculate and show route in which at least one end is inside a venue.
 */
@property (nonatomic, readonly, nullable) NMAVenue3dRoutingController *venueRoutingController;

/**
 * Controls whether the venue map layer is visible.
 *
 * The default value is YES. Updating visible state is done in the background, so changes to this property
 * may not be immediately reflected in its value.
 *
 * @note Changes to this property will deselect a selected venue.
 */
@property (nonatomic) BOOL visible;

/**
 * Controls whether the venue map layer is using a classic or an open mode.
 *
 * The default value is NO (the classic mode). In the open mode a user can see outer areas and spaces all the time.
 * A selected floor and a floor stack is always shown. Venues are selected automatically.
 *
 * @note Updating the open mode is done in the background, so changes to this property
 * may not be immediately reflected in its value.
 *
 * @note Changes to this property will deselect a selected venue.
 */
@property (nonatomic) BOOL openMode;

/**
 * The flag to indicates whether or not to check if the venue is visisble in current map view port.
 *
 * venueMapLayer:didShowVenue: or venueMapLayer:didHideVenue: will be called back to the delegate NMAVenue3dMapLayerDelegate
 * if venue visiblity is changed in the current map view port.
 *
 * @note By default, the value is NO
 */
@property (nonatomic) BOOL shouldCheckVenuesInViewport;

/**
 * Controls whether venue floor changes are animated.
 *
 * The default value is NO.
 *
 */
@property (nonatomic) BOOL animatesFloorChange;

/**
 * Controls whether venue selection is animated.
 *
 * The default value is NO.
 *
 */
@property (nonatomic) BOOL animatesVenueSelection;

/**
 * Controls whether the icon on a selected space is hidden.
 *
 * The default value is YES.
 *
 */
@property (nonatomic) BOOL hideIconOnSelectedSpace;

/**
 * Controls whether updates are enabled for the venues on the map.
 *
 * If this property is set to NO and there are upcoming updates for the venues on the map
 * (i.e. you can get a valid NMAVenue3dController instance for that venue via
 * `NMAVenue3dMapLayer::controllerForVenue:`), then these updates will be discarded
 * until next app-n start.
 *
 * The default value is YES.
 */
@property( nonatomic ) BOOL venueUpdatesEnabled;

/**
 * The margin for current NMAVenue3dVenue view in screen points.
 * The default is (0, 0, 0, 0).
 */
@property (nonatomic) UIEdgeInsets margins;

/**
 * The position indicator for the NMAVenue3dMapLayer.
 *
 * @note IMPORTANT:
 * The NMAVenue3dMapLayer has own position indicator,
 * which should be enabled instead of enabling the NMAMapView indicator
 */
@property (nonatomic, readonly, nullable) NMAPositionIndicator *positionIndicator;

/**
 * NMAVenue3dNavigationManager object which can be used to navigate through indoor routes inside
 * a venue.
 */
@property (nonatomic, readonly, nonnull) NMAVenue3dNavigationManager *venueNavigationManager;

/**
 * NMAVenue3dCombinedNavigation object which can be used to navigate through combined routes.
 */
@property (nonatomic, readonly, nonnull) NMAVenue3dCombinedNavigation *combinedNavigation;

/**
 * Start NMAVenue3dService asynchronously.
 *
 * @note The venue service must be started before the venue map layer can be used.
 */
- (void)start;

/**
 * Returns the NMAVenue3dController of the given venue.
 *
 * @param venue NMAVenue3dVenue object.
 * @return The NMAVenue3dController of the venue or nil if there is no such venue on the map.
 */
- (nullable NMAVenue3dController *)controllerForVenue:(nullable NMAVenue3dVenue *)venue;

/**
 * Select a NMAVenue3dVenue in a 3D view mode.
 * 
 * In the 3D view mode layers and spaces of the venue are visible for the end user.
 * This method opens a previous donwloaded venue.
 * `NMAVenue3dMapLayerDelegate::venueMapLayer:didSelectVenue:`
 * is called when the venue has been opened.
 *
 * @param venue The NMAVenue3dVenue to be selected.
 */
- (void)selectVenue:(nonnull NMAVenue3dVenue *)venue;

/**
 * Select a NMAVenue3dVenue.
 * 
 * Asynchronously opens the NMAVenue3dVenue identified by given venue id in a 3D view mode.
 * In the 3D view mode layers and spaces of the venue are visible for the end user.
 * This method is asynchronous, because it involves venue downloading if the venue is not already
 * in the cache.
 * `NMAVenue3dServiceListener::venueService:didGetVenue:withVenueInfo:withStatus:`
 * callback method is called when the venue has been downloaded.
 * `NMAVenue3dMapLayerDelegate::venueMapLayer:didSelectVenue:`
 * callback method is called when the venue has been opened.
 *
 * @param venueId The identifier of the venue to be opened.
 * @return The NMAVenue3dVenueInfo for the venue if a venue for the given identifier exists, otherwise nil.
 *
 */
- (nullable NMAVenue3dVenueInfo *)selectVenueWithVenueId:(nonnull NSString *)venueId
NS_SWIFT_NAME(selectVenue(venueId:));

/**
 * Select a NMAVenue3dVenue.
 * 
 * Asynchronously opens the NMAVenue3dVenue identified by given venue id and
 * NMAVenue3dSpace identified by the given space id in a 3D view mode .
 * In the 3D view mode layers and spaces of the venue are visible for the end user.
 * This method is asynchronous, because it involves venue downloading if the venue is not already
 * in the cache.
 * `NMAVenue3dServiceListener::venueService:didGetVenue:withVenueInfo:withStatus:`
 * callback method is called when the venue has been downloaded.
 * `NMAVenue3dMapLayerDelegate::venueMapLayer:didSelectVenue:`
 * callback method is called when the venue has been opened.
 *
 * @param venueId The identifier of the venue to be opened.
 * @param spaceId The identifier of the space to be opened. If nil, only the venue will be opened.
 * @return The NMAVenue3dVenueInfo for the venue if a venue for the given identifier exists, otherwise nil.
 *
 */
- (nullable NMAVenue3dVenueInfo *)selectVenueWithVenueId:(nonnull NSString *)venueId
                                                 spaceId:(nonnull NSString *)spaceId
NS_SWIFT_NAME(selectVenue(venueId:spaceId:));

/**
 * Cancels ongoing venue selections.
 *
 * @return YES if a venue selection was cancelled, NO if there was no selection ongoing.
 */
- (BOOL)cancelVenueSelection;

/**
 * Deselect and close the current NMAVenue3dVenue.
 */
- (void)deselectVenue;

/**
 * Check if the venue layer has loaded and displayed a specific venue on the map.
 *
 * @param venueId  A venue identifier to be checked.
 *
 * @return YES if the venue is visible, NO if it is not.
 *
 * See also `NMAVenue3dVenue::uniqueId`
 */
- (BOOL)isVenueVisible:(nonnull NSString *)venueId
NS_SWIFT_NAME(isVenueVisible(venueId:));

@end
