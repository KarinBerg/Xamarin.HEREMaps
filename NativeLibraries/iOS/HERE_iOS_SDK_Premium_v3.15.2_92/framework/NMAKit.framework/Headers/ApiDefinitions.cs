using System;
using CoreGraphics;
using Foundation;
using NMAKit;
using ObjCRuntime;
using UIKit;

namespace Xamarin.HEREMaps.iOS
{
	[Static]
	[Verify (ConstantsInterfaceAssociation)]
	partial interface Constants
	{
		// extern const NSUInteger NMAMapObjectMinimumZIndex;
		[Field ("NMAMapObjectMinimumZIndex", "__Internal")]
		nuint NMAMapObjectMinimumZIndex { get; }

		// extern const NSUInteger NMAMapObjectMaximumZIndex;
		[Field ("NMAMapObjectMaximumZIndex", "__Internal")]
		nuint NMAMapObjectMaximumZIndex { get; }

		// extern const float NMAMapViewMinimumZoomLevel;
		[Field ("NMAMapViewMinimumZoomLevel", "__Internal")]
		float NMAMapViewMinimumZoomLevel { get; }

		// extern const float NMAMapViewMaximumZoomLevel;
		[Field ("NMAMapViewMaximumZoomLevel", "__Internal")]
		float NMAMapViewMaximumZoomLevel { get; }
	}

	// @interface NMATrafficNotificationInfo : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATrafficNotificationInfo
	{
		// @property (readonly, nonatomic) NMATrafficNotificationType type;
		[Export ("type")]
		NMATrafficNotificationType Type { get; }

		// @property (readonly, nonatomic) NMATrafficSeverity severity;
		[Export ("severity")]
		NMATrafficSeverity Severity { get; }

		// @property (readonly, nonatomic) double distance;
		[Export ("distance")]
		double Distance { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull affectedArea;
		[Export ("affectedArea")]
		NMAGeoBoundingBox AffectedArea { get; }

		// @property (readonly, nonatomic) double affectedLength;
		[Export ("affectedLength")]
		double AffectedLength { get; }

		// @property (readonly, nonatomic) NSTimeInterval travelTime;
		[Export ("travelTime")]
		double TravelTime { get; }

		// @property (readonly, nonatomic) NSTimeInterval travelTimeWithTraffic;
		[Export ("travelTimeWithTraffic")]
		double TravelTimeWithTraffic { get; }
	}

	// @protocol NMAMapGestureDelegate <NSObject>
	[Protocol, Model]
	[BaseType (typeof(NSObject))]
	interface NMAMapGestureDelegate
	{
		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveTapAtLocation:(CGPoint)location;
		[Export ("mapView:didReceiveTapAtLocation:")]
		void DidReceiveTapAtLocation (NMAMapView mapView, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveDoubleTapAtLocation:(CGPoint)location;
		[Export ("mapView:didReceiveDoubleTapAtLocation:")]
		void DidReceiveDoubleTapAtLocation (NMAMapView mapView, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveTwoFingerTapAtLocation:(CGPoint)location;
		[Export ("mapView:didReceiveTwoFingerTapAtLocation:")]
		void DidReceiveTwoFingerTapAtLocation (NMAMapView mapView, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceivePan:(CGPoint)translation atLocation:(CGPoint)location;
		[Export ("mapView:didReceivePan:atLocation:")]
		void DidReceivePan (NMAMapView mapView, CGPoint translation, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveTwoFingerPan:(CGPoint)translation atLocation:(CGPoint)location;
		[Export ("mapView:didReceiveTwoFingerPan:atLocation:")]
		void DidReceiveTwoFingerPan (NMAMapView mapView, CGPoint translation, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveRotation:(float)rotation atLocation:(CGPoint)location;
		[Export ("mapView:didReceiveRotation:atLocation:")]
		void DidReceiveRotation (NMAMapView mapView, float rotation, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceivePinch:(float)pinch atLocation:(CGPoint)location;
		[Export ("mapView:didReceivePinch:atLocation:")]
		void DidReceivePinch (NMAMapView mapView, float pinch, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveLongPressAtLocation:(CGPoint)location;
		[Export ("mapView:didReceiveLongPressAtLocation:")]
		void DidReceiveLongPressAtLocation (NMAMapView mapView, CGPoint location);
	}

	// @protocol NMAMapTileLayerDataSource <NSObject>
	[Protocol, Model]
	[BaseType (typeof(NSObject))]
	interface NMAMapTileLayerDataSource
	{
		// @optional -(BOOL)mapTileLayer:(NMAMapTileLayer * _Nonnull)mapTileLayer hasTileAtX:(NSUInteger)x y:(NSUInteger)y zoomLevel:(NSUInteger)zoomLevel;
		[Export ("mapTileLayer:hasTileAtX:y:zoomLevel:")]
		bool MapTileLayer (NMAMapTileLayer mapTileLayer, nuint x, nuint y, nuint zoomLevel);

		// @optional -(NSString * _Nonnull)mapTileLayer:(NMAMapTileLayer * _Nonnull)mapTileLayer urlForTileAtX:(NSUInteger)x y:(NSUInteger)y zoomLevel:(NSUInteger)zoomLevel;
		[Export ("mapTileLayer:urlForTileAtX:y:zoomLevel:")]
		string MapTileLayer (NMAMapTileLayer mapTileLayer, nuint x, nuint y, nuint zoomLevel);

		// @optional -(void)mapTileLayer:(NMAMapTileLayer * _Nonnull)mapTileLayer requestDataForTileAtX:(NSUInteger)x y:(NSUInteger)y zoomLevel:(NSUInteger)zoomLevel tileRequest:(NMAMapTileRequest * _Nonnull)tileRequest;
		[Export ("mapTileLayer:requestDataForTileAtX:y:zoomLevel:tileRequest:")]
		void MapTileLayer (NMAMapTileLayer mapTileLayer, nuint x, nuint y, nuint zoomLevel, NMAMapTileRequest tileRequest);

		// @optional -(NSData * _Nonnull)mapTileLayer:(NMAMapTileLayer * _Nonnull)mapTileLayer requestDataForTileAtX:(NSUInteger)x y:(NSUInteger)y zoomLevel:(NSUInteger)zoomLevel;
		[Export ("mapTileLayer:requestDataForTileAtX:y:zoomLevel:")]
		NSData MapTileLayer (NMAMapTileLayer mapTileLayer, nuint x, nuint y, nuint zoomLevel);
	}

	// @interface NMAMapTileLayer : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAMapTileLayer
	{
		// @property (nonatomic, weak) id<NMAMapTileLayerDataSource> _Nullable dataSource;
		[NullAllowed, Export ("dataSource", ArgumentSemantic.Weak)]
		NMAMapTileLayerDataSource DataSource { get; set; }

		// @property (readonly, getter = isLocked, nonatomic) BOOL locked;
		[Export ("locked")]
		bool Locked { [Bind ("isLocked")] get; }

		// @property (nonatomic) NMAMapLayerType mapLayerType;
		[Export ("mapLayerType", ArgumentSemantic.Assign)]
		NMAMapLayerType MapLayerType { get; set; }

		// @property (nonatomic) NSUInteger zIndex;
		[Export ("zIndex")]
		nuint ZIndex { get; set; }

		// @property (nonatomic) NMAPixelFormat pixelFormat;
		[Export ("pixelFormat", ArgumentSemantic.Assign)]
		NMAPixelFormat PixelFormat { get; set; }

		// @property (nonatomic) NSUInteger tileSize;
		[Export ("tileSize")]
		nuint TileSize { get; set; }

		// @property (getter = isTransparent, nonatomic) BOOL transparent;
		[Export ("transparent")]
		bool Transparent { [Bind ("isTransparent")] get; set; }

		// @property (getter = isFallbackEnabled, nonatomic) BOOL fallbackEnabled;
		[Export ("fallbackEnabled")]
		bool FallbackEnabled { [Bind ("isFallbackEnabled")] get; set; }

		// @property (getter = isFadingEnabled, nonatomic) BOOL fadingEnabled;
		[Export ("fadingEnabled")]
		bool FadingEnabled { [Bind ("isFadingEnabled")] get; set; }

		// @property (nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export ("boundingBox", ArgumentSemantic.Assign)]
		NMAGeoBoundingBox BoundingBox { get; set; }

		// @property (readonly, getter = isCacheEnabled, nonatomic) BOOL cacheEnabled;
		[Export ("cacheEnabled")]
		bool CacheEnabled { [Bind ("isCacheEnabled")] get; }

		// @property (readonly, nonatomic) NSString * _Nonnull cacheIdentifier;
		[Export ("cacheIdentifier")]
		string CacheIdentifier { get; }

		// @property (nonatomic) NSTimeInterval cacheTimeToLive;
		[Export ("cacheTimeToLive")]
		double CacheTimeToLive { get; set; }

		// @property (nonatomic) NSUInteger cacheSizeLimit;
		[Export ("cacheSizeLimit")]
		nuint CacheSizeLimit { get; set; }

		// -(void)setCacheEnabled:(BOOL)cacheEnabled withIdentifier:(NSString * _Nonnull)cacheIdentifier;
		[Export ("setCacheEnabled:withIdentifier:")]
		void SetCacheEnabled (bool cacheEnabled, string cacheIdentifier);

		// -(void)clearCache;
		[Export ("clearCache")]
		void ClearCache ();

		// -(void)showAtZoomLevel:(int)zoomLevel;
		[Export ("showAtZoomLevel:")]
		void ShowAtZoomLevel (int zoomLevel);

		// -(void)hideAtZoomLevel:(int)zoomLevel;
		[Export ("hideAtZoomLevel:")]
		void HideAtZoomLevel (int zoomLevel);

		// -(void)showFromZoomLevel:(int)fromLevel toZoomLevel:(int)toLevel;
		[Export ("showFromZoomLevel:toZoomLevel:")]
		void ShowFromZoomLevel (int fromLevel, int toLevel);

		// -(void)hideFromZoomLevel:(int)fromLevel toZoomLevel:(int)toLevel;
		[Export ("hideFromZoomLevel:toZoomLevel:")]
		void HideFromZoomLevel (int fromLevel, int toLevel);

		// -(BOOL)isShownAtZoomLevel:(int)zoomLevel;
		[Export ("isShownAtZoomLevel:")]
		bool IsShownAtZoomLevel (int zoomLevel);
	}

	[Static]
	[Verify (ConstantsInterfaceAssociation)]
	partial interface Constants
	{
		// extern const float NMAMapViewPreserveValue;
		[Field ("NMAMapViewPreserveValue", "__Internal")]
		float NMAMapViewPreserveValue { get; }

		// extern const float NMAMapViewMaximumTilt;
		[Field ("NMAMapViewMaximumTilt", "__Internal")]
		float NMAMapViewMaximumTilt { get; }
	}

	// typedef float (^NMATiltZoomProfile)(float);
	delegate float NMATiltZoomProfile (float arg0);

	// typedef BOOL (^NMAMapEventBlock)(NMAMapEvent, NMAMapView * _Nonnull, id _Nullable);
	delegate bool NMAMapEventBlock (NMAMapEvent arg0, NMAMapView arg1, [NullAllowed] NSObject arg2);

	// @protocol NMAMapViewDelegate <NSObject>
	[Protocol, Model]
	[BaseType (typeof(NSObject))]
	interface NMAMapViewDelegate
	{
		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didSelectObjects:(NSArray<NMAViewObject *> * _Nonnull)objects;
		[Export ("mapView:didSelectObjects:")]
		void MapView (NMAMapView mapView, NMAViewObject[] objects);

		// @optional -(void)mapViewDidBeginMovement:(NMAMapView * _Nonnull)mapView;
		[Export ("mapViewDidBeginMovement:")]
		void MapViewDidBeginMovement (NMAMapView mapView);

		// @optional -(void)mapViewDidEndMovement:(NMAMapView * _Nonnull)mapView;
		[Export ("mapViewDidEndMovement:")]
		void MapViewDidEndMovement (NMAMapView mapView);

		// @optional -(void)mapViewDidBeginAnimation:(NMAMapView * _Nonnull)mapView;
		[Export ("mapViewDidBeginAnimation:")]
		void MapViewDidBeginAnimation (NMAMapView mapView);

		// @optional -(void)mapViewDidEndAnimation:(NMAMapView * _Nonnull)mapView;
		[Export ("mapViewDidEndAnimation:")]
		void MapViewDidEndAnimation (NMAMapView mapView);

		// @optional -(void)mapViewDidDraw:(NMAMapView * _Nonnull)mapView;
		[Export ("mapViewDidDraw:")]
		void MapViewDidDraw (NMAMapView mapView);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didRenderBitmap:(void * _Nonnull)bitmap withWidth:(NSUInteger)width height:(NSUInteger)height bytesPerPixel:(NSUInteger)bytesPerPixel;
		[Export ("mapView:didRenderBitmap:withWidth:height:bytesPerPixel:")]
		unsafe void MapView (NMAMapView mapView, void* bitmap, nuint width, nuint height, nuint bytesPerPixel);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didTapOnSafetySpot:(NMASafetySpot * _Nonnull)info;
		[Export ("mapView:didTapOnSafetySpot:")]
		void MapView (NMAMapView mapView, NMASafetySpot info);
	}

	// @interface NMAMapView : UIView
	[BaseType (typeof(UIView))]
	interface NMAMapView
	{
		// +(void)shouldBeginRenderingAutomatically:(BOOL)enabled;
		[Static]
		[Export ("shouldBeginRenderingAutomatically:")]
		void ShouldBeginRenderingAutomatically (bool enabled);

		// -(instancetype _Nonnull)initWithFrame:(CGRect)frame;
		[Export ("initWithFrame:")]
		IntPtr Constructor (CGRect frame);

		// @property (getter = isRenderAllowed, nonatomic) BOOL renderAllowed;
		[Export ("renderAllowed")]
		bool RenderAllowed { [Bind ("isRenderAllowed")] get; set; }

		// @property (nonatomic) BOOL pauseOnWillResignActive;
		[Export ("pauseOnWillResignActive")]
		bool PauseOnWillResignActive { get; set; }

		// @property (nonatomic) BOOL maximumRefreshRateLimitEnabled;
		[Export ("maximumRefreshRateLimitEnabled")]
		bool MaximumRefreshRateLimitEnabled { get; set; }

		// @property (nonatomic) float maximumRefreshRate;
		[Export ("maximumRefreshRate")]
		float MaximumRefreshRate { get; set; }

		[Wrap ("WeakDelegate")]
		[NullAllowed]
		NMAMapViewDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMAMapViewDelegate> _Nullable delegate;
		[NullAllowed, Export ("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// -(NSInteger)respondToEvents:(NMAMapEvent)events withBlock:(NMAMapEventBlock _Nonnull)block;
		[Export ("respondToEvents:withBlock:")]
		nint RespondToEvents (NMAMapEvent events, NMAMapEventBlock block);

		// -(BOOL)removeEventBlockWithIdentifier:(NSInteger)identifier;
		[Export ("removeEventBlockWithIdentifier:")]
		bool RemoveEventBlockWithIdentifier (nint identifier);

		// @property (nonatomic) CGRect clipRect;
		[Export ("clipRect", ArgumentSemantic.Assign)]
		CGRect ClipRect { get; set; }

		// @property (readonly, nonatomic, weak) NMAGeoBoundingBox * _Nullable boundingBox;
		[NullAllowed, Export ("boundingBox", ArgumentSemantic.Weak)]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (nonatomic, strong) NSString * _Nonnull mapScheme;
		[Export ("mapScheme", ArgumentSemantic.Strong)]
		string MapScheme { get; set; }

		// @property (readonly, nonatomic) NSArray<NSString *> * _Nonnull availableMapSchemes;
		[Export ("availableMapSchemes")]
		string[] AvailableMapSchemes { get; }

		// @property (nonatomic) NMAProjectionType projectionType;
		[Export ("projectionType", ArgumentSemantic.Assign)]
		NMAProjectionType ProjectionType { get; set; }

		// @property (readonly, nonatomic) NMAPositionIndicator * _Nonnull positionIndicator;
		[Export ("positionIndicator")]
		NMAPositionIndicator PositionIndicator { get; }

		// @property (nonatomic) BOOL landmarksVisible;
		[Export ("landmarksVisible")]
		bool LandmarksVisible { get; set; }

		// -(void)showFleetFeature:(NMAMapFleetFeatureType)fleetFeature;
		[Export ("showFleetFeature:")]
		void ShowFleetFeature (NMAMapFleetFeatureType fleetFeature);

		// -(void)hideFleetFeature:(NMAMapFleetFeatureType)fleetFeature;
		[Export ("hideFleetFeature:")]
		void HideFleetFeature (NMAMapFleetFeatureType fleetFeature);

		// -(BOOL)isFleetFeatureShown:(NMAMapFleetFeatureType)fleetFeature;
		[Export ("isFleetFeatureShown:")]
		bool IsFleetFeatureShown (NMAMapFleetFeatureType fleetFeature);

		// @property (readonly, nonatomic) NMAVenue3dMapLayer * _Nullable venue3dMapLayer;
		[NullAllowed, Export ("venue3dMapLayer")]
		NMAVenue3dMapLayer Venue3dMapLayer { get; }

		// -(NMACustomizableScheme * _Nullable)createCustomizableSchemeWithName:(NSString * _Nonnull)schemeName basedOnScheme:(NSString * _Nonnull)baseSchemeName;
		[Export ("createCustomizableSchemeWithName:basedOnScheme:")]
		[return: NullAllowed]
		NMACustomizableScheme CreateCustomizableSchemeWithName (string schemeName, string baseSchemeName);

		// -(NMACustomizableScheme * _Nullable)getCustomizableSchemeWithName:(NSString * _Nonnull)schemeName;
		[Export ("getCustomizableSchemeWithName:")]
		[return: NullAllowed]
		NMACustomizableScheme GetCustomizableSchemeWithName (string schemeName);

		// -(BOOL)removeCustomizableSchemeWithName:(NSString * _Nonnull)schemeName;
		[Export ("removeCustomizableSchemeWithName:")]
		bool RemoveCustomizableSchemeWithName (string schemeName);

		// -(void)showPedestrianFeature:(NMAMapPedestrianFeatureType)pedestrianFeature;
		[Export ("showPedestrianFeature:")]
		void ShowPedestrianFeature (NMAMapPedestrianFeatureType pedestrianFeature);

		// -(void)hidePedestrianFeature:(NMAMapPedestrianFeatureType)pedestrianFeature;
		[Export ("hidePedestrianFeature:")]
		void HidePedestrianFeature (NMAMapPedestrianFeatureType pedestrianFeature);

		// -(BOOL)isPedestrianFeatureShown:(NMAMapPedestrianFeatureType)pedestrianFeature;
		[Export ("isPedestrianFeatureShown:")]
		bool IsPedestrianFeatureShown (NMAMapPedestrianFeatureType pedestrianFeature);

		// -(void)setVisibility:(BOOL)visible forMapLayerCategories:(NSArray<NSNumber *> * _Nonnull)layerCategories;
		[Export ("setVisibility:forMapLayerCategories:")]
		void SetVisibility (bool visible, NSNumber[] layerCategories);

		// -(NSArray<NSNumber *> * _Nonnull)visibleMapLayerCategories;
		[Export ("visibleMapLayerCategories")]
		[Verify (MethodToProperty)]
		NSNumber[] VisibleMapLayerCategories { get; }

		// @property (nonatomic) BOOL safetySpotsVisible;
		[Export ("safetySpotsVisible")]
		bool SafetySpotsVisible { get; set; }

		// -(BOOL)isMapLayerCategoryVisible:(NMAMapLayerCategory)layerCategory;
		[Export ("isMapLayerCategoryVisible:")]
		bool IsMapLayerCategoryVisible (NMAMapLayerCategory layerCategory);

		// -(BOOL)setVisibility:(BOOL)visible forPoiCategory:(NMAMapPoiCategory)poiCategory;
		[Export ("setVisibility:forPoiCategory:")]
		bool SetVisibility (bool visible, NMAMapPoiCategory poiCategory);

		// -(BOOL)isPoiCategoryVisible:(NMAMapPoiCategory)poiCategory;
		[Export ("isPoiCategoryVisible:")]
		bool IsPoiCategoryVisible (NMAMapPoiCategory poiCategory);

		// -(NSArray<NSString *> * _Nonnull)poiCategories;
		[Export ("poiCategories")]
		[Verify (MethodToProperty)]
		string[] PoiCategories { get; }

		// @property (readwrite, nonatomic) BOOL extrudedBuildingsVisible;
		[Export ("extrudedBuildingsVisible")]
		bool ExtrudedBuildingsVisible { get; set; }

		// -(BOOL)useDefaultDisplayLanguage;
		[Export ("useDefaultDisplayLanguage")]
		[Verify (MethodToProperty)]
		bool UseDefaultDisplayLanguage { get; }

		// -(BOOL)useDisplayLanguageFromLocale:(NSLocale * _Nonnull)locale;
		[Export ("useDisplayLanguageFromLocale:")]
		bool UseDisplayLanguageFromLocale (NSLocale locale);

		// @property (readonly, nonatomic, weak) NSString * _Nullable displayLanguage;
		[NullAllowed, Export ("displayLanguage", ArgumentSemantic.Weak)]
		string DisplayLanguage { get; }

		// -(BOOL)useSecondaryDisplayLanguageFromLocale:(NSLocale * _Nullable)locale;
		[Export ("useSecondaryDisplayLanguageFromLocale:")]
		bool UseSecondaryDisplayLanguageFromLocale ([NullAllowed] NSLocale locale);

		// @property (readonly, nonatomic, weak) NSString * _Nullable secondaryDisplayLanguage;
		[NullAllowed, Export ("secondaryDisplayLanguage", ArgumentSemantic.Weak)]
		string SecondaryDisplayLanguage { get; }

		// -(NSArray<NSString *> * _Nonnull)supportedDisplayLanguages;
		[Export ("supportedDisplayLanguages")]
		[Verify (MethodToProperty)]
		string[] SupportedDisplayLanguages { get; }

		[Wrap ("WeakGestureDelegate")]
		[NullAllowed]
		NMAMapGestureDelegate GestureDelegate { get; set; }

		// @property (nonatomic, weak) id<NMAMapGestureDelegate> _Nullable gestureDelegate;
		[NullAllowed, Export ("gestureDelegate", ArgumentSemantic.Weak)]
		NSObject WeakGestureDelegate { get; set; }

		// @property (readonly, nonatomic) id<NMAMapGestureDelegate> _Nullable defaultGestureHandler;
		[NullAllowed, Export ("defaultGestureHandler")]
		NMAMapGestureDelegate DefaultGestureHandler { get; }

		// @property (getter = isMapInteractionEnabled, nonatomic) BOOL mapInteractionEnabled;
		[Export ("mapInteractionEnabled")]
		bool MapInteractionEnabled { [Bind ("isMapInteractionEnabled")] get; set; }

		// @property (nonatomic) NSTimeInterval longPressDuration;
		[Export ("longPressDuration")]
		double LongPressDuration { get; set; }

		// @property (nonatomic) BOOL mapCenterFixedOnRotateZoom;
		[Export ("mapCenterFixedOnRotateZoom")]
		bool MapCenterFixedOnRotateZoom { get; set; }

		// @property (nonatomic) BOOL upwardPanIncreasesTilt;
		[Export ("upwardPanIncreasesTilt")]
		bool UpwardPanIncreasesTilt { get; set; }

		// @property (nonatomic) BOOL twoFingerPanTiltingEnabled;
		[Export ("twoFingerPanTiltingEnabled")]
		bool TwoFingerPanTiltingEnabled { get; set; }

		// -(void)enableMapGestures:(NMAMapGestureType)gestures;
		[Export ("enableMapGestures:")]
		void EnableMapGestures (NMAMapGestureType gestures);

		// -(void)disableMapGestures:(NMAMapGestureType)gestures;
		[Export ("disableMapGestures:")]
		void DisableMapGestures (NMAMapGestureType gestures);

		// -(BOOL)isMapGestureEnabled:(NMAMapGestureType)gesture;
		[Export ("isMapGestureEnabled:")]
		bool IsMapGestureEnabled (NMAMapGestureType gesture);

		// -(void)enableKineticForGestures:(NMAMapGestureType)gestures;
		[Export ("enableKineticForGestures:")]
		void EnableKineticForGestures (NMAMapGestureType gestures);

		// -(void)disableKineticForGestures:(NMAMapGestureType)gestures;
		[Export ("disableKineticForGestures:")]
		void DisableKineticForGestures (NMAMapGestureType gestures);

		// -(BOOL)isKineticForGestureEnabled:(NMAMapGestureType)gesture;
		[Export ("isKineticForGestureEnabled:")]
		bool IsKineticForGestureEnabled (NMAMapGestureType gesture);

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull geoCenter;
		[Export ("geoCenter", ArgumentSemantic.Assign)]
		NMAGeoCoordinates GeoCenter { get; set; }

		// @property (nonatomic) float zoomLevel;
		[Export ("zoomLevel")]
		float ZoomLevel { get; set; }

		// @property (getter = isExtendedZoomLevelsEnabled, nonatomic) BOOL extendedZoomLevelsEnabled;
		[Export ("extendedZoomLevelsEnabled")]
		bool ExtendedZoomLevelsEnabled { [Bind ("isExtendedZoomLevelsEnabled")] get; set; }

		// @property (readonly, nonatomic) float minimumZoomLevel;
		[Export ("minimumZoomLevel")]
		float MinimumZoomLevel { get; }

		// @property (readonly, nonatomic) float maximumZoomLevel;
		[Export ("maximumZoomLevel")]
		float MaximumZoomLevel { get; }

		// @property (nonatomic) float orientation;
		[Export ("orientation")]
		float Orientation { get; set; }

		// @property (nonatomic) float tilt;
		[Export ("tilt")]
		float Tilt { get; set; }

		// @property (readonly, nonatomic) float clippedTilt;
		[Export ("clippedTilt")]
		float ClippedTilt { get; }

		// @property (nonatomic, strong) NMATiltZoomProfile _Nonnull maximumTiltProfile;
		[Export ("maximumTiltProfile", ArgumentSemantic.Strong)]
		NMATiltZoomProfile MaximumTiltProfile { get; set; }

		// -(float)minimumTiltAtZoomLevel:(float)zoomLevel;
		[Export ("minimumTiltAtZoomLevel:")]
		float MinimumTiltAtZoomLevel (float zoomLevel);

		// -(float)maximumTiltAtZoomLevel:(float)zoomLevel;
		[Export ("maximumTiltAtZoomLevel:")]
		float MaximumTiltAtZoomLevel (float zoomLevel);

		// @property (nonatomic) CGPoint transformCenter;
		[Export ("transformCenter", ArgumentSemantic.Assign)]
		CGPoint TransformCenter { get; set; }

		// @property (nonatomic) UIEdgeInsets padding;
		[Export ("padding", ArgumentSemantic.Assign)]
		UIEdgeInsets Padding { get; set; }

		// -(void)setGeoCenter:(NMAGeoCoordinates * _Nonnull)geoCenter withAnimation:(NMAMapAnimation)animationType;
		[Export ("setGeoCenter:withAnimation:")]
		void SetGeoCenter (NMAGeoCoordinates geoCenter, NMAMapAnimation animationType);

		// -(void)setOrientation:(float)orientation withAnimation:(NMAMapAnimation)animationType;
		[Export ("setOrientation:withAnimation:")]
		void SetOrientation (float orientation, NMAMapAnimation animationType);

		// -(void)setZoomLevel:(float)zoomLevel withAnimation:(NMAMapAnimation)animationType;
		[Export ("setZoomLevel:withAnimation:")]
		void SetZoomLevel (float zoomLevel, NMAMapAnimation animationType);

		// -(void)setTilt:(float)tilt withAnimation:(NMAMapAnimation)animationType;
		[Export ("setTilt:withAnimation:")]
		void SetTilt (float tilt, NMAMapAnimation animationType);

		// -(void)setGeoCenter:(NMAGeoCoordinates * _Nonnull)geoCenter zoomLevel:(float)zoomLevel withAnimation:(NMAMapAnimation)animationType;
		[Export ("setGeoCenter:zoomLevel:withAnimation:")]
		void SetGeoCenter (NMAGeoCoordinates geoCenter, float zoomLevel, NMAMapAnimation animationType);

		// -(void)setGeoCenter:(NMAGeoCoordinates * _Nullable)geoCenter zoomLevel:(float)zoomLevel orientation:(float)orientation tilt:(float)tilt withAnimation:(NMAMapAnimation)animationType;
		[Export ("setGeoCenter:zoomLevel:orientation:tilt:withAnimation:")]
		void SetGeoCenter ([NullAllowed] NMAGeoCoordinates geoCenter, float zoomLevel, float orientation, float tilt, NMAMapAnimation animationType);

		// -(void)setGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates toPoint:(CGPoint)point withAnimation:(NMAMapAnimation)animation;
		[Export ("setGeoCoordinates:toPoint:withAnimation:")]
		void SetGeoCoordinates (NMAGeoCoordinates coordinates, CGPoint point, NMAMapAnimation animation);

		// -(void)setGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates toPoint:(CGPoint)point withAnimation:(NMAMapAnimation)animation zoomLevel:(float)zoomLevel orientation:(float)orientation tilt:(float)tilt;
		[Export ("setGeoCoordinates:toPoint:withAnimation:zoomLevel:orientation:tilt:")]
		void SetGeoCoordinates (NMAGeoCoordinates coordinates, CGPoint point, NMAMapAnimation animation, float zoomLevel, float orientation, float tilt);

		// -(void)setBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox withAnimation:(NMAMapAnimation)animationType;
		[Export ("setBoundingBox:withAnimation:")]
		void SetBoundingBox (NMAGeoBoundingBox boundingBox, NMAMapAnimation animationType);

		// -(void)setBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox insideRect:(CGRect)screenRect withAnimation:(NMAMapAnimation)animationType;
		[Export ("setBoundingBox:insideRect:withAnimation:")]
		void SetBoundingBox (NMAGeoBoundingBox boundingBox, CGRect screenRect, NMAMapAnimation animationType);

		// -(NMAGeoCoordinates * _Nullable)geoCoordinatesFromPoint:(CGPoint)point;
		[Export ("geoCoordinatesFromPoint:")]
		[return: NullAllowed]
		NMAGeoCoordinates GeoCoordinatesFromPoint (CGPoint point);

		// -(NMAGeoCoordinates * _Nullable)geoCoordinatesFromPoint:(CGPoint)point withAltitude:(float)altitude;
		[Export ("geoCoordinatesFromPoint:withAltitude:")]
		[return: NullAllowed]
		NMAGeoCoordinates GeoCoordinatesFromPoint (CGPoint point, float altitude);

		// -(CGPoint)pointFromGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export ("pointFromGeoCoordinates:")]
		CGPoint PointFromGeoCoordinates (NMAGeoCoordinates coordinates);

		// -(double)pointDistanceFromGeoCoordinates:(NMAGeoCoordinates * _Nonnull)startCoordinates toGeoCoordinates:(NMAGeoCoordinates * _Nonnull)endCoordinates;
		[Export ("pointDistanceFromGeoCoordinates:toGeoCoordinates:")]
		double PointDistanceFromGeoCoordinates (NMAGeoCoordinates startCoordinates, NMAGeoCoordinates endCoordinates);

		// -(float)metersPerPointAtZoomLevel:(float)zoomLevel;
		[Export ("metersPerPointAtZoomLevel:")]
		float MetersPerPointAtZoomLevel (float zoomLevel);

		// +(void)snapshotWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates zoomLevel:(float)zoom orientation:(float)orientation size:(CGSize)size block:(void (^ _Nonnull)(UIImage * _Nonnull))resultBlock;
		[Static]
		[Export ("snapshotWithGeoCoordinates:zoomLevel:orientation:size:block:")]
		void SnapshotWithGeoCoordinates (NMAGeoCoordinates coordinates, float zoom, float orientation, CGSize size, Action<UIImage> resultBlock);

		// -(void)snapshotWithBlock:(void (^ _Nonnull)(UIImage * _Nullable))resultBlock;
		[Export ("snapshotWithBlock:")]
		void SnapshotWithBlock (Action<UIImage> resultBlock);

		// -(BOOL)addMapObject:(NMAMapObject * _Nonnull)object;
		[Export ("addMapObject:")]
		bool AddMapObject (NMAMapObject @object);

		// -(BOOL)addMapObject:(NMAMapObject * _Nonnull)object toLayer:(NMAMapLayerType)layer;
		[Export ("addMapObject:toLayer:")]
		bool AddMapObject (NMAMapObject @object, NMAMapLayerType layer);

		// -(BOOL)addMapObjects:(NSArray<NMAMapObject *> * _Nonnull)objects;
		[Export ("addMapObjects:")]
		bool AddMapObjects (NMAMapObject[] objects);

		// -(BOOL)addMapObjects:(NSArray<NMAMapObject *> * _Nonnull)objects toLayer:(NMAMapLayerType)layer;
		[Export ("addMapObjects:toLayer:")]
		bool AddMapObjects (NMAMapObject[] objects, NMAMapLayerType layer);

		// -(NSArray<NMAMapObject *> * _Nonnull)allMapObjects;
		[Export ("allMapObjects")]
		[Verify (MethodToProperty)]
		NMAMapObject[] AllMapObjects { get; }

		// -(BOOL)removeMapObject:(NMAMapObject * _Nonnull)object;
		[Export ("removeMapObject:")]
		bool RemoveMapObject (NMAMapObject @object);

		// -(BOOL)removeMapObjects:(NSArray<NMAMapObject *> * _Nonnull)objects;
		[Export ("removeMapObjects:")]
		bool RemoveMapObjects (NMAMapObject[] objects);

		// -(BOOL)removeAllMapObjects;
		[Export ("removeAllMapObjects")]
		[Verify (MethodToProperty)]
		bool RemoveAllMapObjects { get; }

		// -(NSArray<NMAViewObject *> * _Nonnull)objectsAtPoint:(CGPoint)point;
		[Export ("objectsAtPoint:")]
		NMAViewObject[] ObjectsAtPoint (CGPoint point);

		// -(NSArray<NMAViewObject *> * _Nonnull)visibleObjectsAtPoint:(CGPoint)point;
		[Export ("visibleObjectsAtPoint:")]
		NMAViewObject[] VisibleObjectsAtPoint (CGPoint point);

		// -(BOOL)addClusterLayer:(NMAClusterLayer * _Nonnull)clusterLayer;
		[Export ("addClusterLayer:")]
		bool AddClusterLayer (NMAClusterLayer clusterLayer);

		// -(BOOL)removeClusterLayer:(NMAClusterLayer * _Nonnull)clusterLayer;
		[Export ("removeClusterLayer:")]
		bool RemoveClusterLayer (NMAClusterLayer clusterLayer);

		// -(BOOL)addMapOverlay:(NMAMapOverlay * _Nonnull)overlay;
		[Export ("addMapOverlay:")]
		bool AddMapOverlay (NMAMapOverlay overlay);

		// -(BOOL)removeMapOverlay:(NMAMapOverlay * _Nonnull)overlay;
		[Export ("removeMapOverlay:")]
		bool RemoveMapOverlay (NMAMapOverlay overlay);

		// @property (readonly, nonatomic) NSString * _Nonnull copyright;
		[Export ("copyright")]
		string Copyright { get; }

		// @property (nonatomic) NMALayoutPosition copyrightLogoPosition;
		[Export ("copyrightLogoPosition", ArgumentSemantic.Assign)]
		NMALayoutPosition CopyrightLogoPosition { get; set; }

		// @property (nonatomic) float copyrightLogoVerticalMargin;
		[Export ("copyrightLogoVerticalMargin")]
		float CopyrightLogoVerticalMargin { get; set; }

		// @property (nonatomic) float copyrightLogoHorizontalMargin;
		[Export ("copyrightLogoHorizontalMargin")]
		float CopyrightLogoHorizontalMargin { get; set; }

		// @property (nonatomic) NMAMapTransitDisplayMode transitDisplayMode;
		[Export ("transitDisplayMode", ArgumentSemantic.Assign)]
		NMAMapTransitDisplayMode TransitDisplayMode { get; set; }

		// @property (readonly, nonatomic) NMAMapTransitLayer * _Nonnull mapTransitLayer;
		[Export ("mapTransitLayer")]
		NMAMapTransitLayer MapTransitLayer { get; }

		// @property (getter = isTrafficVisible, nonatomic) BOOL trafficVisible;
		[Export ("trafficVisible")]
		bool TrafficVisible { [Bind ("isTrafficVisible")] get; set; }

		// -(void)showTrafficLayers:(NMATrafficLayer)layers;
		[Export ("showTrafficLayers:")]
		void ShowTrafficLayers (NMATrafficLayer layers);

		// -(void)hideTrafficLayers:(NMATrafficLayer)layers;
		[Export ("hideTrafficLayers:")]
		void HideTrafficLayers (NMATrafficLayer layers);

		// -(BOOL)isTrafficLayerVisible:(NMATrafficLayer)layer;
		[Export ("isTrafficLayerVisible:")]
		bool IsTrafficLayerVisible (NMATrafficLayer layer);

		// @property (nonatomic) NMATrafficSeverity trafficDisplayFilter;
		[Export ("trafficDisplayFilter", ArgumentSemantic.Assign)]
		NMATrafficSeverity TrafficDisplayFilter { get; set; }

		// -(NSArray<NMARoadElement *> * _Nonnull)roadElementsInArea:(NMAGeoBoundingBox * _Nonnull)geoArea;
		[Export ("roadElementsInArea:")]
		NMARoadElement[] RoadElementsInArea (NMAGeoBoundingBox geoArea);

		// -(NSArray<NMARoadElement *> * _Nonnull)roadElementsInArea:(NMAGeoBoundingBox * _Nonnull)geoArea lang:(NSString * _Nullable)marcLangCode;
		[Export ("roadElementsInArea:lang:")]
		NMARoadElement[] RoadElementsInArea (NMAGeoBoundingBox geoArea, [NullAllowed] string marcLangCode);

		// -(NMARoadElement * _Nullable)roadElementAtCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export ("roadElementAtCoordinates:")]
		[return: NullAllowed]
		NMARoadElement RoadElementAtCoordinates (NMAGeoCoordinates coordinates);

		// -(NMARoadElement * _Nullable)roadElementAtCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates lang:(NSString * _Nullable)marcLangCode;
		[Export ("roadElementAtCoordinates:lang:")]
		[return: NullAllowed]
		NMARoadElement RoadElementAtCoordinates (NMAGeoCoordinates coordinates, [NullAllowed] string marcLangCode);

		// -(void)addMapTileLayer:(NMAMapTileLayer * _Nonnull)tileLayer;
		[Export ("addMapTileLayer:")]
		void AddMapTileLayer (NMAMapTileLayer tileLayer);

		// -(void)removeMapTileLayer:(NMAMapTileLayer * _Nonnull)tileLayer;
		[Export ("removeMapTileLayer:")]
		void RemoveMapTileLayer (NMAMapTileLayer tileLayer);

		// -(NSArray<NMAMapTileLayer *> * _Nonnull)mapTileLayers;
		[Export ("mapTileLayers")]
		[Verify (MethodToProperty)]
		NMAMapTileLayer[] MapTileLayers { get; }

		// @property (nonatomic) BOOL softwareRenderToBitmap;
		[Export ("softwareRenderToBitmap")]
		bool SoftwareRenderToBitmap { get; set; }
	}

	// @interface NMAViewObject : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAViewObject
	{
		// -(BOOL)isEqual:(id _Nullable)aViewObject;
		[Export ("isEqual:")]
		bool IsEqual ([NullAllowed] NSObject aViewObject);

		// -(BOOL)isInArray:(NSArray<NMAViewObject *> * _Nonnull)objects;
		[Export ("isInArray:")]
		bool IsInArray (NMAViewObject[] objects);

		// -(NMAGeoCoordinates * _Nullable)location;
		[NullAllowed, Export ("location")]
		[Verify (MethodToProperty)]
		NMAGeoCoordinates Location { get; }
	}

	// @interface NMAUserObject : NMAViewObject
	[BaseType (typeof(NMAViewObject))]
	interface NMAUserObject
	{
	}

	// @interface NMAMapObject : NMAUserObject
	[BaseType (typeof(NMAUserObject))]
	interface NMAMapObject
	{
		// @property (readwrite, nonatomic) NMAMapLayerType mapLayerType;
		[Export ("mapLayerType", ArgumentSemantic.Assign)]
		NMAMapLayerType MapLayerType { get; set; }

		// @property (nonatomic) NSUInteger zIndex;
		[Export ("zIndex")]
		nuint ZIndex { get; set; }

		// @property (getter = isVisible, nonatomic) BOOL visible;
		[Export ("visible")]
		bool Visible { [Bind ("isVisible")] get; set; }

		// @property (readonly, nonatomic) NMAMapObjectType type;
		[Export ("type")]
		NMAMapObjectType Type { get; }

		// @property (readonly, nonatomic, weak) NMAMapContainer * _Nullable parent;
		[NullAllowed, Export ("parent", ArgumentSemantic.Weak)]
		NMAMapContainer Parent { get; }

		// -(NSUInteger)uniqueId;
		[Export ("uniqueId")]
		[Verify (MethodToProperty)]
		nuint UniqueId { get; }

		// -(BOOL)isVisibleAtZoomLevel:(float)zoomLevel;
		[Export ("isVisibleAtZoomLevel:")]
		bool IsVisibleAtZoomLevel (float zoomLevel);

		// -(void)setVisibility:(BOOL)visible atZoomLevel:(float)zoomLevel;
		[Export ("setVisibility:atZoomLevel:")]
		void SetVisibility (bool visible, float zoomLevel);

		// -(void)setVisibility:(BOOL)visible fromZoomLevel:(float)fromZoomLevel toZoomLevel:(float)toZoomLevel;
		[Export ("setVisibility:fromZoomLevel:toZoomLevel:")]
		void SetVisibility (bool visible, float fromZoomLevel, float toZoomLevel);
	}

	// @interface NMAMapMarker : NMAMapObject
	[BaseType (typeof(NMAMapObject))]
	interface NMAMapMarker
	{
		// +(instancetype _Nonnull)mapMarkerWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Static]
		[Export ("mapMarkerWithGeoCoordinates:")]
		NMAMapMarker MapMarkerWithGeoCoordinates (NMAGeoCoordinates coordinates);

		// +(instancetype _Nonnull)mapMarkerWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates icon:(NMAImage * _Nonnull)icon;
		[Static]
		[Export ("mapMarkerWithGeoCoordinates:icon:")]
		NMAMapMarker MapMarkerWithGeoCoordinates (NMAGeoCoordinates coordinates, NMAImage icon);

		// +(instancetype _Nonnull)mapMarkerWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates image:(UIImage * _Nonnull)image;
		[Static]
		[Export ("mapMarkerWithGeoCoordinates:image:")]
		NMAMapMarker MapMarkerWithGeoCoordinates (NMAGeoCoordinates coordinates, UIImage image);

		// @property (nonatomic, strong) NMAGeoCoordinates * _Nonnull coordinates;
		[Export ("coordinates", ArgumentSemantic.Strong)]
		NMAGeoCoordinates Coordinates { get; set; }

		// @property (nonatomic, strong) NMAImage * _Nullable icon;
		[NullAllowed, Export ("icon", ArgumentSemantic.Strong)]
		NMAImage Icon { get; set; }

		// @property (getter = isDraggable, nonatomic) BOOL draggable;
		[Export ("draggable")]
		bool Draggable { [Bind ("isDraggable")] get; set; }

		// @property (getter = isDraggingOffsetEnabled, nonatomic) BOOL draggingOffsetEnabled;
		[Export ("draggingOffsetEnabled")]
		bool DraggingOffsetEnabled { [Bind ("isDraggingOffsetEnabled")] get; set; }

		// @property (nonatomic) CGPoint anchorOffset;
		[Export ("anchorOffset", ArgumentSemantic.Assign)]
		CGPoint AnchorOffset { get; set; }

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export ("initWithGeoCoordinates:")]
		IntPtr Constructor (NMAGeoCoordinates coordinates);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates icon:(NMAImage * _Nonnull)icon __attribute__((objc_designated_initializer));
		[Export ("initWithGeoCoordinates:icon:")]
		[DesignatedInitializer]
		IntPtr Constructor (NMAGeoCoordinates coordinates, NMAImage icon);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates image:(UIImage * _Nonnull)image;
		[Export ("initWithGeoCoordinates:image:")]
		IntPtr Constructor (NMAGeoCoordinates coordinates, UIImage image);

		// -(CGPoint)setAnchorOffsetUsingLayoutPosition:(NMALayoutPosition)position;
		[Export ("setAnchorOffsetUsingLayoutPosition:")]
		CGPoint SetAnchorOffsetUsingLayoutPosition (NMALayoutPosition position);

		// -(void)setSize:(CGSize)size forZoomLevel:(NSUInteger)zoomLevel;
		[Export ("setSize:forZoomLevel:")]
		void SetSize (CGSize size, nuint zoomLevel);

		// -(void)setSize:(CGSize)size forZoomRange:(NSRange)zoomRange;
		[Export ("setSize:forZoomRange:")]
		void SetSize (CGSize size, NSRange zoomRange);

		// -(void)resetIconSize;
		[Export ("resetIconSize")]
		void ResetIconSize ();
	}

	// @interface NMAMapContainer : NMAMapObject
	[BaseType (typeof(NMAMapObject))]
	interface NMAMapContainer
	{
		// @property (readonly, nonatomic, weak) NSArray<NMAMapObject *> * _Nullable mapObjects;
		[NullAllowed, Export ("mapObjects", ArgumentSemantic.Weak)]
		NMAMapObject[] MapObjects { get; }

		// -(BOOL)addMapObject:(NMAMapObject * _Nonnull)aMapObject;
		[Export ("addMapObject:")]
		bool AddMapObject (NMAMapObject aMapObject);

		// -(BOOL)removeMapObject:(NMAMapObject * _Nonnull)aMapObject;
		[Export ("removeMapObject:")]
		bool RemoveMapObject (NMAMapObject aMapObject);

		// -(BOOL)removeAllMapObjects;
		[Export ("removeAllMapObjects")]
		[Verify (MethodToProperty)]
		bool RemoveAllMapObjects { get; }
	}

	// @interface NMAImage : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAImage
	{
		// +(instancetype _Nullable)imageWithUIImage:(UIImage * _Nonnull)image;
		[Static]
		[Export ("imageWithUIImage:")]
		[return: NullAllowed]
		NMAImage ImageWithUIImage (UIImage image);

		// +(instancetype _Nullable)imageWithData:(NSData * _Nonnull)data;
		[Static]
		[Export ("imageWithData:")]
		[return: NullAllowed]
		NMAImage ImageWithData (NSData data);

		// +(instancetype _Nullable)imageWithURL:(NSString * _Nonnull)url;
		[Static]
		[Export ("imageWithURL:")]
		[return: NullAllowed]
		NMAImage ImageWithURL (string url);

		// -(instancetype _Nullable)initWithUIImage:(UIImage * _Nonnull)image;
		[Export ("initWithUIImage:")]
		IntPtr Constructor (UIImage image);

		// -(instancetype _Nullable)initWithData:(NSData * _Nonnull)data;
		[Export ("initWithData:")]
		IntPtr Constructor (NSData data);

		// -(instancetype _Nullable)initWithURL:(NSString * _Nonnull)url;
		[Export ("initWithURL:")]
		IntPtr Constructor (string url);

		// @property (readonly, getter = isValid, nonatomic) BOOL valid;
		[Export ("valid")]
		bool Valid { [Bind ("isValid")] get; }

		// @property (readonly, nonatomic) CGSize size;
		[Export ("size")]
		CGSize Size { get; }

		// -(UIImage * _Nullable)UIImageRepresentation;
		[NullAllowed, Export ("UIImageRepresentation")]
		[Verify (MethodToProperty)]
		UIImage UIImageRepresentation { get; }
	}

	[Static]
	[Verify (ConstantsInterfaceAssociation)]
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMAMapSchemeNormalDay;
		[Field ("NMAMapSchemeNormalDay", "__Internal")]
		NSString NMAMapSchemeNormalDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeNormalNight;
		[Field ("NMAMapSchemeNormalNight", "__Internal")]
		NSString NMAMapSchemeNormalNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeReducedDay;
		[Field ("NMAMapSchemeReducedDay", "__Internal")]
		NSString NMAMapSchemeReducedDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeReducedNight;
		[Field ("NMAMapSchemeReducedNight", "__Internal")]
		NSString NMAMapSchemeReducedNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeNormalDayTransit;
		[Field ("NMAMapSchemeNormalDayTransit", "__Internal")]
		NSString NMAMapSchemeNormalDayTransit { get; }

		// extern NSString *const _Nonnull NMAMapSchemeNormalNightTransit;
		[Field ("NMAMapSchemeNormalNightTransit", "__Internal")]
		NSString NMAMapSchemeNormalNightTransit { get; }

		// extern NSString *const _Nonnull NMAMapSchemeTerrainDay;
		[Field ("NMAMapSchemeTerrainDay", "__Internal")]
		NSString NMAMapSchemeTerrainDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeSatelliteDay;
		[Field ("NMAMapSchemeSatelliteDay", "__Internal")]
		NSString NMAMapSchemeSatelliteDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeSatelliteNight;
		[Field ("NMAMapSchemeSatelliteNight", "__Internal")]
		NSString NMAMapSchemeSatelliteNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridDay;
		[Field ("NMAMapSchemeHybridDay", "__Internal")]
		NSString NMAMapSchemeHybridDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridGreyDay;
		[Field ("NMAMapSchemeHybridGreyDay", "__Internal")]
		NSString NMAMapSchemeHybridGreyDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridNight;
		[Field ("NMAMapSchemeHybridNight", "__Internal")]
		NSString NMAMapSchemeHybridNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridGreyNight;
		[Field ("NMAMapSchemeHybridGreyNight", "__Internal")]
		NSString NMAMapSchemeHybridGreyNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridReducedDay;
		[Field ("NMAMapSchemeHybridReducedDay", "__Internal")]
		NSString NMAMapSchemeHybridReducedDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridReducedNight;
		[Field ("NMAMapSchemeHybridReducedNight", "__Internal")]
		NSString NMAMapSchemeHybridReducedNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeManeuverDay;
		[Field ("NMAMapSchemeManeuverDay", "__Internal")]
		NSString NMAMapSchemeManeuverDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridDayTransit;
		[Field ("NMAMapSchemeHybridDayTransit", "__Internal")]
		NSString NMAMapSchemeHybridDayTransit { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridNightTransit;
		[Field ("NMAMapSchemeHybridNightTransit", "__Internal")]
		NSString NMAMapSchemeHybridNightTransit { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationDay;
		[Field ("NMAMapSchemeCarNavigationDay", "__Internal")]
		NSString NMAMapSchemeCarNavigationDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationDayGrey;
		[Field ("NMAMapSchemeCarNavigationDayGrey", "__Internal")]
		NSString NMAMapSchemeCarNavigationDayGrey { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationNight;
		[Field ("NMAMapSchemeCarNavigationNight", "__Internal")]
		NSString NMAMapSchemeCarNavigationNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationNightGrey;
		[Field ("NMAMapSchemeCarNavigationNightGrey", "__Internal")]
		NSString NMAMapSchemeCarNavigationNightGrey { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridCarNavigationDay;
		[Field ("NMAMapSchemeHybridCarNavigationDay", "__Internal")]
		NSString NMAMapSchemeHybridCarNavigationDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridPedestrianDay;
		[Field ("NMAMapSchemeHybridPedestrianDay", "__Internal")]
		NSString NMAMapSchemeHybridPedestrianDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridPedestrianNight;
		[Field ("NMAMapSchemeHybridPedestrianNight", "__Internal")]
		NSString NMAMapSchemeHybridPedestrianNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridCarNavigationNight;
		[Field ("NMAMapSchemeHybridCarNavigationNight", "__Internal")]
		NSString NMAMapSchemeHybridCarNavigationNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemePedestrianDay;
		[Field ("NMAMapSchemePedestrianDay", "__Internal")]
		NSString NMAMapSchemePedestrianDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemePedestrianNight;
		[Field ("NMAMapSchemePedestrianNight", "__Internal")]
		NSString NMAMapSchemePedestrianNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeTruckDay;
		[Field ("NMAMapSchemeTruckDay", "__Internal")]
		NSString NMAMapSchemeTruckDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeTruckNight;
		[Field ("NMAMapSchemeTruckNight", "__Internal")]
		NSString NMAMapSchemeTruckNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridTruckDay;
		[Field ("NMAMapSchemeHybridTruckDay", "__Internal")]
		NSString NMAMapSchemeHybridTruckDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridTruckNight;
		[Field ("NMAMapSchemeHybridTruckNight", "__Internal")]
		NSString NMAMapSchemeHybridTruckNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeTruckNavigationDay;
		[Field ("NMAMapSchemeTruckNavigationDay", "__Internal")]
		NSString NMAMapSchemeTruckNavigationDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeTruckNavigationNight;
		[Field ("NMAMapSchemeTruckNavigationNight", "__Internal")]
		NSString NMAMapSchemeTruckNavigationNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridTruckNavigationDay;
		[Field ("NMAMapSchemeHybridTruckNavigationDay", "__Internal")]
		NSString NMAMapSchemeHybridTruckNavigationDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridTruckNavigationNight;
		[Field ("NMAMapSchemeHybridTruckNavigationNight", "__Internal")]
		NSString NMAMapSchemeHybridTruckNavigationNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeNormalDayWithTraffic;
		[Field ("NMAMapSchemeNormalDayWithTraffic", "__Internal")]
		NSString NMAMapSchemeNormalDayWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeNormalNightWithTraffic;
		[Field ("NMAMapSchemeNormalNightWithTraffic", "__Internal")]
		NSString NMAMapSchemeNormalNightWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridDayWithTraffic;
		[Field ("NMAMapSchemeHybridDayWithTraffic", "__Internal")]
		NSString NMAMapSchemeHybridDayWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridNightWithTraffic;
		[Field ("NMAMapSchemeHybridNightWithTraffic", "__Internal")]
		NSString NMAMapSchemeHybridNightWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationDayWithTraffic;
		[Field ("NMAMapSchemeCarNavigationDayWithTraffic", "__Internal")]
		NSString NMAMapSchemeCarNavigationDayWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationNightWithTraffic;
		[Field ("NMAMapSchemeCarNavigationNightWithTraffic", "__Internal")]
		NSString NMAMapSchemeCarNavigationNightWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridCarNavigationDayWithTraffic;
		[Field ("NMAMapSchemeHybridCarNavigationDayWithTraffic", "__Internal")]
		NSString NMAMapSchemeHybridCarNavigationDayWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridCarNavigationNightWithTraffic;
		[Field ("NMAMapSchemeHybridCarNavigationNightWithTraffic", "__Internal")]
		NSString NMAMapSchemeHybridCarNavigationNightWithTraffic { get; }
	}

	// @interface NMAMapPolyline : NMAMapObject
	[BaseType (typeof(NMAMapObject))]
	interface NMAMapPolyline
	{
		// +(instancetype _Nonnull)mapPolylineWithVertices:(NSArray<NMAGeoCoordinates *> * _Nonnull)vertices;
		[Static]
		[Export ("mapPolylineWithVertices:")]
		NMAMapPolyline MapPolylineWithVertices (NMAGeoCoordinates[] vertices);

		// @property (readonly, nonatomic) NSArray<NMAGeoCoordinates *> * _Nonnull vertices;
		[Export ("vertices")]
		NMAGeoCoordinates[] Vertices { get; }

		// @property (nonatomic, strong) UIColor * _Nonnull lineColor;
		[Export ("lineColor", ArgumentSemantic.Strong)]
		UIColor LineColor { get; set; }

		// @property (nonatomic) NSUInteger lineWidth;
		[Export ("lineWidth")]
		nuint LineWidth { get; set; }

		// @property (getter = isDashed, nonatomic) BOOL dashed;
		[Export ("dashed")]
		bool Dashed { [Bind ("isDashed")] get; set; }

		// @property (nonatomic) NSUInteger dashPrimaryLength;
		[Export ("dashPrimaryLength")]
		nuint DashPrimaryLength { get; set; }

		// @property (nonatomic) NSUInteger dashSecondaryLength;
		[Export ("dashSecondaryLength")]
		nuint DashSecondaryLength { get; set; }

		// @property (nonatomic, strong) UIColor * _Nonnull outlineColor;
		[Export ("outlineColor", ArgumentSemantic.Strong)]
		UIColor OutlineColor { get; set; }

		// @property (nonatomic) NSUInteger outlineWidth;
		[Export ("outlineWidth")]
		nuint OutlineWidth { get; set; }

		// @property (nonatomic) BOOL depthTestEnabled;
		[Export ("depthTestEnabled")]
		bool DepthTestEnabled { get; set; }

		// -(void)enableShadow:(NSUInteger)width shearFactor:(float)shearFactor;
		[Export ("enableShadow:shearFactor:")]
		void EnableShadow (nuint width, float shearFactor);

		// @property (getter = isShadowEnabled, nonatomic) BOOL shadowEnabled;
		[Export ("shadowEnabled")]
		bool ShadowEnabled { [Bind ("isShadowEnabled")] get; set; }

		// @property (nonatomic) NSUInteger shadowWidth;
		[Export ("shadowWidth")]
		nuint ShadowWidth { get; set; }

		// @property (nonatomic, strong) UIColor * _Nonnull shadowColor;
		[Export ("shadowColor", ArgumentSemantic.Strong)]
		UIColor ShadowColor { get; set; }

		// @property (nonatomic) float shadowShearFactor;
		[Export ("shadowShearFactor")]
		float ShadowShearFactor { get; set; }

		// @property (nonatomic) float shadowOffsetX;
		[Export ("shadowOffsetX")]
		float ShadowOffsetX { get; set; }

		// @property (nonatomic) float shadowOffsetY;
		[Export ("shadowOffsetY")]
		float ShadowOffsetY { get; set; }

		// @property (nonatomic) float shadowSizeIncrement;
		[Export ("shadowSizeIncrement")]
		float ShadowSizeIncrement { get; set; }

		// -(instancetype _Nonnull)initWithPolyline:(NMAGeoPolyline * _Nonnull)geoPolyline;
		[Export ("initWithPolyline:")]
		IntPtr Constructor (NMAGeoPolyline geoPolyline);

		// @property (readonly, nonatomic) NMAGeoPolyline * _Nonnull geoPolyline;
		[Export ("geoPolyline")]
		NMAGeoPolyline GeoPolyline { get; }

		// -(instancetype _Nonnull)initWithVertices:(NSArray<NMAGeoCoordinates *> * _Nonnull)vertices __attribute__((objc_designated_initializer));
		[Export ("initWithVertices:")]
		[DesignatedInitializer]
		IntPtr Constructor (NMAGeoCoordinates[] vertices);

		// -(NMAGeoCoordinates * _Nonnull)nearestVertexToGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export ("nearestVertexToGeoCoordinates:")]
		NMAGeoCoordinates NearestVertexToGeoCoordinates (NMAGeoCoordinates coordinates);

		// -(NSInteger)indexOfNearestVertexToGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export ("indexOfNearestVertexToGeoCoordinates:")]
		nint IndexOfNearestVertexToGeoCoordinates (NMAGeoCoordinates coordinates);

		// -(void)clearVertices;
		[Export ("clearVertices")]
		void ClearVertices ();

		// -(void)appendVertex:(NMAGeoCoordinates * _Nonnull)vertex;
		[Export ("appendVertex:")]
		void AppendVertex (NMAGeoCoordinates vertex);

		// -(void)addVertex:(NMAGeoCoordinates * _Nonnull)vertex atIndex:(NSUInteger)index;
		[Export ("addVertex:atIndex:")]
		void AddVertex (NMAGeoCoordinates vertex, nuint index);

		// -(void)removeLastVertex;
		[Export ("removeLastVertex")]
		void RemoveLastVertex ();

		// -(void)removeVertexAtIndex:(NSUInteger)index;
		[Export ("removeVertexAtIndex:")]
		void RemoveVertexAtIndex (nuint index);

		// @property (getter = isPerspective, nonatomic) BOOL perspective;
		[Export ("perspective")]
		bool Perspective { [Bind ("isPerspective")] get; set; }

		// @property (assign, nonatomic) NMAPatternStyle patternStyle;
		[Export ("patternStyle", ArgumentSemantic.Assign)]
		NMAPatternStyle PatternStyle { get; set; }

		// @property (readwrite, nonatomic) NMAImage * _Nullable customPattern;
		[NullAllowed, Export ("customPattern", ArgumentSemantic.Assign)]
		NMAImage CustomPattern { get; set; }
	}

	[Static]
	[Verify (ConstantsInterfaceAssociation)]
	partial interface Constants
	{
		// extern const float NMAGeoCoordinatesUnknownAltitudeValue;
		[Field ("NMAGeoCoordinatesUnknownAltitudeValue", "__Internal")]
		float NMAGeoCoordinatesUnknownAltitudeValue { get; }

		// extern const double NMAGeoCoordinatesInvalidValue;
		[Field ("NMAGeoCoordinatesInvalidValue", "__Internal")]
		double NMAGeoCoordinatesInvalidValue { get; }
	}

	// @interface NMAGeoCoordinates : NSObject <NSCoding>
	[BaseType (typeof(NSObject))]
	interface NMAGeoCoordinates : INSCoding
	{
		// +(instancetype _Nonnull)geoCoordinatesWithLatitude:(double)latitude longitude:(double)longitude;
		[Static]
		[Export ("geoCoordinatesWithLatitude:longitude:")]
		NMAGeoCoordinates GeoCoordinatesWithLatitude (double latitude, double longitude);

		// +(instancetype _Nonnull)geoCoordinatesWithLatitude:(double)latitude longitude:(double)longitude altitude:(double)altitude;
		[Static]
		[Export ("geoCoordinatesWithLatitude:longitude:altitude:")]
		NMAGeoCoordinates GeoCoordinatesWithLatitude (double latitude, double longitude, double altitude);

		// -(instancetype _Nonnull)initWithLatitude:(double)latitude longitude:(double)longitude;
		[Export ("initWithLatitude:longitude:")]
		IntPtr Constructor (double latitude, double longitude);

		// -(instancetype _Nonnull)initWithLatitude:(double)latitude longitude:(double)longitude altitude:(float)altitude;
		[Export ("initWithLatitude:longitude:altitude:")]
		IntPtr Constructor (double latitude, double longitude, float altitude);

		// @property (nonatomic) double latitude;
		[Export ("latitude")]
		double Latitude { get; set; }

		// @property (nonatomic) double longitude;
		[Export ("longitude")]
		double Longitude { get; set; }

		// @property (nonatomic) float altitude;
		[Export ("altitude")]
		float Altitude { get; set; }

		// -(double)distanceTo:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export ("distanceTo:")]
		double DistanceTo (NMAGeoCoordinates coordinates);

		// -(double)headingTo:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export ("headingTo:")]
		double HeadingTo (NMAGeoCoordinates coordinates);

		// -(BOOL)isEqualToGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export ("isEqualToGeoCoordinates:")]
		bool IsEqualToGeoCoordinates (NMAGeoCoordinates coordinates);
	}

	// @interface NMAGeoBoundingBox : NSObject <NSCoding>
	[BaseType (typeof(NSObject))]
	interface NMAGeoBoundingBox : INSCoding
	{
		// +(instancetype _Nullable)geoBoundingBoxWithTopLeft:(NMAGeoCoordinates * _Nonnull)topLeft bottomRight:(NMAGeoCoordinates * _Nonnull)bottomRight;
		[Static]
		[Export ("geoBoundingBoxWithTopLeft:bottomRight:")]
		[return: NullAllowed]
		NMAGeoBoundingBox GeoBoundingBoxWithTopLeft (NMAGeoCoordinates topLeft, NMAGeoCoordinates bottomRight);

		// +(instancetype _Nullable)geoBoundingBoxWithTopRight:(NMAGeoCoordinates * _Nonnull)topRight bottomLeft:(NMAGeoCoordinates * _Nonnull)bottomLeft;
		[Static]
		[Export ("geoBoundingBoxWithTopRight:bottomLeft:")]
		[return: NullAllowed]
		NMAGeoBoundingBox GeoBoundingBoxWithTopRight (NMAGeoCoordinates topRight, NMAGeoCoordinates bottomLeft);

		// +(instancetype _Nullable)geoBoundingBoxWithCenter:(NMAGeoCoordinates * _Nonnull)center width:(float)width height:(float)height;
		[Static]
		[Export ("geoBoundingBoxWithCenter:width:height:")]
		[return: NullAllowed]
		NMAGeoBoundingBox GeoBoundingBoxWithCenter (NMAGeoCoordinates center, float width, float height);

		// +(instancetype _Nullable)geoBoundingBoxContainingGeoCoordinates:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Static]
		[Export ("geoBoundingBoxContainingGeoCoordinates:")]
		[return: NullAllowed]
		NMAGeoBoundingBox GeoBoundingBoxContainingGeoCoordinates (NMAGeoCoordinates[] coordinates);

		// +(instancetype _Nullable)geoBoundingBoxContainingGeoBoundingBoxes:(NSArray<NMAGeoBoundingBox *> * _Nonnull)boxes;
		[Static]
		[Export ("geoBoundingBoxContainingGeoBoundingBoxes:")]
		[return: NullAllowed]
		NMAGeoBoundingBox GeoBoundingBoxContainingGeoBoundingBoxes (NMAGeoBoundingBox[] boxes);

		// -(instancetype _Nullable)initWithTopLeft:(NMAGeoCoordinates * _Nonnull)topLeft bottomRight:(NMAGeoCoordinates * _Nonnull)bottomRight;
		[Export ("initWithTopLeft:bottomRight:")]
		IntPtr Constructor (NMAGeoCoordinates topLeft, NMAGeoCoordinates bottomRight);

		// -(instancetype _Nullable)initWithTopRight:(NMAGeoCoordinates * _Nonnull)topRight bottomLeft:(NMAGeoCoordinates * _Nonnull)bottomLeft;
		[Export ("initWithTopRight:bottomLeft:")]
		IntPtr Constructor (NMAGeoCoordinates topRight, NMAGeoCoordinates bottomLeft);

		// -(instancetype _Nullable)initWithCenter:(NMAGeoCoordinates * _Nonnull)center width:(float)width height:(float)height;
		[Export ("initWithCenter:width:height:")]
		IntPtr Constructor (NMAGeoCoordinates center, float width, float height);

		// -(instancetype _Nullable)initContainingGeoCoordinates:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Export ("initContainingGeoCoordinates:")]
		IntPtr Constructor (NMAGeoCoordinates[] coordinates);

		// -(instancetype _Nullable)initContainingGeoBoundingBoxes:(NSArray<NMAGeoBoundingBox *> * _Nonnull)boxes;
		[Export ("initContainingGeoBoundingBoxes:")]
		IntPtr Constructor (NMAGeoBoundingBox[] boxes);

		// @property (readonly, nonatomic) double width;
		[Export ("width")]
		double Width { get; }

		// @property (readonly, nonatomic) double height;
		[Export ("height")]
		double Height { get; }

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull topLeft;
		[Export ("topLeft", ArgumentSemantic.Assign)]
		NMAGeoCoordinates TopLeft { get; set; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull topLeftFront;
		[Export ("topLeftFront")]
		NMAGeoCoordinates TopLeftFront { get; }

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull topRight;
		[Export ("topRight", ArgumentSemantic.Assign)]
		NMAGeoCoordinates TopRight { get; set; }

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull bottomLeft;
		[Export ("bottomLeft", ArgumentSemantic.Assign)]
		NMAGeoCoordinates BottomLeft { get; set; }

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull bottomRight;
		[Export ("bottomRight", ArgumentSemantic.Assign)]
		NMAGeoCoordinates BottomRight { get; set; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull bottomRightBack;
		[Export ("bottomRightBack")]
		NMAGeoCoordinates BottomRightBack { get; }

		// @property (readonly, nonatomic, weak) NMAGeoCoordinates * _Nullable center;
		[NullAllowed, Export ("center", ArgumentSemantic.Weak)]
		NMAGeoCoordinates Center { get; }

		// @property (readonly, assign, nonatomic) double areaSize;
		[Export ("areaSize")]
		double AreaSize { get; }

		// @property (readonly, nonatomic) BOOL crossesInternationalDateLine;
		[Export ("crossesInternationalDateLine")]
		bool CrossesInternationalDateLine { get; }

		// -(BOOL)containsGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export ("containsGeoCoordinates:")]
		bool ContainsGeoCoordinates (NMAGeoCoordinates coordinates);

		// -(BOOL)containsGeoBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox;
		[Export ("containsGeoBoundingBox:")]
		bool ContainsGeoBoundingBox (NMAGeoBoundingBox boundingBox);

		// -(BOOL)intersectsGeoBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox;
		[Export ("intersectsGeoBoundingBox:")]
		bool IntersectsGeoBoundingBox (NMAGeoBoundingBox boundingBox);

		// -(NMAGeoBoundingBox * _Nullable)intersectionWithGeoBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox;
		[Export ("intersectionWithGeoBoundingBox:")]
		[return: NullAllowed]
		NMAGeoBoundingBox IntersectionWithGeoBoundingBox (NMAGeoBoundingBox boundingBox);

		// -(BOOL)isEmpty;
		[Export ("isEmpty")]
		[Verify (MethodToProperty)]
		bool IsEmpty { get; }

		// -(BOOL)isEqualToGeoBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox;
		[Export ("isEqualToGeoBoundingBox:")]
		bool IsEqualToGeoBoundingBox (NMAGeoBoundingBox boundingBox);
	}

	// @interface NMASafetySpot : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASafetySpot
	{
		// @property (readonly, nonatomic) NSInteger heading1;
		[Export ("heading1")]
		nint Heading1 { get; }

		// @property (readonly, nonatomic) NSInteger heading2;
		[Export ("heading2")]
		nint Heading2 { get; }

		// @property (readonly, nonatomic) float speedLimit1;
		[Export ("speedLimit1")]
		float SpeedLimit1 { get; }

		// @property (readonly, nonatomic) float speedLimit2;
		[Export ("speedLimit2")]
		float SpeedLimit2 { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable location;
		[NullAllowed, Export ("location")]
		NMAGeoCoordinates Location { get; }

		// @property (readonly, nonatomic) NMASafetySpotType type;
		[Export ("type")]
		NMASafetySpotType Type { get; }
	}

	// @interface NMAGeoPolyline : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAGeoPolyline
	{
		// -(instancetype _Nonnull)initWithCoordinates:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Export ("initWithCoordinates:")]
		IntPtr Constructor (NMAGeoCoordinates[] coordinates);

		// -(void)addPoint:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export ("addPoint:")]
		void AddPoint (NMAGeoCoordinates coordinate);

		// -(void)addPoints:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Export ("addPoints:")]
		void AddPoints (NMAGeoCoordinates[] coordinates);

		// -(void)insertPoint:(NMAGeoCoordinates * _Nonnull)coordinate atIndex:(int)index;
		[Export ("insertPoint:atIndex:")]
		void InsertPoint (NMAGeoCoordinates coordinate, int index);

		// -(void)removePointAtIndex:(int)index;
		[Export ("removePointAtIndex:")]
		void RemovePointAtIndex (int index);

		// -(void)clear;
		[Export ("clear")]
		void Clear ();

		// -(int)getNumberOfPoints;
		[Export ("getNumberOfPoints")]
		[Verify (MethodToProperty)]
		int NumberOfPoints { get; }

		// -(NMAGeoCoordinates * _Nullable)getPointAtIndex:(int)index;
		[Export ("getPointAtIndex:")]
		[return: NullAllowed]
		NMAGeoCoordinates GetPointAtIndex (int index);

		// -(NSArray<NMAGeoCoordinates *> * _Nonnull)getAllPoints;
		[Export ("getAllPoints")]
		[Verify (MethodToProperty)]
		NMAGeoCoordinates[] AllPoints { get; }

		// -(double)getLength;
		[Export ("getLength")]
		[Verify (MethodToProperty)]
		double Length { get; }

		// -(NMAGeoCoordinates * _Nullable)getNearestCoordinateFrom:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export ("getNearestCoordinateFrom:")]
		[return: NullAllowed]
		NMAGeoCoordinates GetNearestCoordinateFrom (NMAGeoCoordinates coordinate);

		// -(NSUInteger)getNearestIndexFromCoordinate:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export ("getNearestIndexFromCoordinate:")]
		nuint GetNearestIndexFromCoordinate (NMAGeoCoordinates coordinate);

		// -(NMAGeoBoundingBox * _Nullable)geoBoundingBox;
		[NullAllowed, Export ("geoBoundingBox")]
		[Verify (MethodToProperty)]
		NMAGeoBoundingBox GeoBoundingBox { get; }
	}

	// @interface NMAMapTileRequest : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAMapTileRequest
	{
		// @property (readonly, nonatomic) void * _Nullable bytesPtr;
		[NullAllowed, Export ("bytesPtr")]
		unsafe void* BytesPtr { get; }

		// @property (readonly, nonatomic) int bytesLength;
		[Export ("bytesLength")]
		int BytesLength { get; }

		// @property (nonatomic) NMAMapTileRequestStatus status;
		[Export ("status", ArgumentSemantic.Assign)]
		NMAMapTileRequestStatus Status { get; set; }

		// -(BOOL)getBytesFromData:(NSData * _Nonnull)tileData;
		[Export ("getBytesFromData:")]
		bool GetBytesFromData (NSData tileData);
	}

	// @interface NMAPositionIndicator : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAPositionIndicator
	{
		// @property (nonatomic) NMAMapObject * _Nullable displayObject;
		[NullAllowed, Export ("displayObject", ArgumentSemantic.Assign)]
		NMAMapObject DisplayObject { get; set; }

		// @property (getter = isVisible, nonatomic) BOOL visible;
		[Export ("visible")]
		bool Visible { [Bind ("isVisible")] get; set; }

		// @property (nonatomic) float hue;
		[Export ("hue")]
		float Hue { get; set; }

		// @property (getter = isAccuracyIndicatorVisible, nonatomic) BOOL accuracyIndicatorVisible;
		[Export ("accuracyIndicatorVisible")]
		bool AccuracyIndicatorVisible { [Bind ("isAccuracyIndicatorVisible")] get; set; }

		// @property (nonatomic) UIColor * _Nonnull accuracyIndicatorColor;
		[Export ("accuracyIndicatorColor", ArgumentSemantic.Assign)]
		UIColor AccuracyIndicatorColor { get; set; }

		// @property (nonatomic) NMAPositionIndicatorType type;
		[Export ("type", ArgumentSemantic.Assign)]
		NMAPositionIndicatorType Type { get; set; }

		// @property (nonatomic) BOOL tracksCourse;
		[Export ("tracksCourse")]
		bool TracksCourse { get; set; }

		// @property (nonatomic) float orientationOffset;
		[Export ("orientationOffset")]
		float OrientationOffset { get; set; }

		// -(void)setDisplayObject:(NMAMapObject * _Nullable)displayObject toLayer:(NMAMapLayerType)layer;
		[Export ("setDisplayObject:toLayer:")]
		void SetDisplayObject ([NullAllowed] NMAMapObject displayObject, NMAMapLayerType layer);
	}

	// @protocol NMAVenue3dMapLayerDelegate <NSObject>
	[Protocol, Model]
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dMapLayerDelegate
	{
		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didTapVenue:(NMAVenue3dVenue * _Nonnull)venue atPoint:(CGPoint)point;
		[Export ("venueMapLayer:didTapVenue:atPoint:")]
		void VenueMapLayer (NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue, CGPoint point);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didSelectVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export ("venueMapLayer:didSelectVenue:")]
		void VenueMapLayer (NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didDeselectVenue:(NMAVenue3dVenue * _Nonnull)venue withEvent:(NMAVenue3dDeselectEvent)event;
		[Export ("venueMapLayer:didDeselectVenue:withEvent:")]
		void VenueMapLayer (NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue, NMAVenue3dDeselectEvent @event);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didSelectSpace:(NMAVenue3dSpace * _Nonnull)space inVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export ("venueMapLayer:didSelectSpace:inVenue:")]
		void VenueMapLayer (NMAVenue3dMapLayer venueMapLayer, NMAVenue3dSpace space, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didDeselectSpace:(NMAVenue3dSpace * _Nonnull)space inVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export ("venueMapLayer:didDeselectSpace:inVenue:")]
		void VenueMapLayer (NMAVenue3dMapLayer venueMapLayer, NMAVenue3dSpace space, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didChangeFromLevel:(NMAVenue3dLevel * _Nonnull)oldLevel toLevel:(NMAVenue3dLevel * _Nonnull)newLevel inVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export ("venueMapLayer:didChangeFromLevel:toLevel:inVenue:")]
		void VenueMapLayer (NMAVenue3dMapLayer venueMapLayer, NMAVenue3dLevel oldLevel, NMAVenue3dLevel newLevel, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didShowVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export ("venueMapLayer:didShowVenue:")]
		void VenueMapLayer (NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didHideVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export ("venueMapLayer:didHideVenue:")]
		void VenueMapLayer (NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didCreateVenueController:(NMAVenue3dController * _Nonnull)venueController;
		[Export ("venueMapLayer:didCreateVenueController:")]
		void VenueMapLayer (NMAVenue3dMapLayer venueMapLayer, NMAVenue3dController venueController);

		// @optional -(void)venueMapLayerDidStart:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer;
		[Export ("venueMapLayerDidStart:")]
		void VenueMapLayerDidStart (NMAVenue3dMapLayer venueMapLayer);
	}

	// @protocol NMAVenue3dVenueZoomDelegate <NSObject>
	[Protocol, Model]
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dVenueZoomDelegate
	{
		// @required -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didUpdateVenueZoomInVenue:(NMAVenue3dVenue * _Nonnull)venue withValue:(_Bool)active;
		[Abstract]
		[Export ("venueMapLayer:didUpdateVenueZoomInVenue:withValue:")]
		void DidUpdateVenueZoomInVenue (NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue, bool active);
	}

	// @interface NMAVenue3dMapLayer : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dMapLayer
	{
		[Wrap ("WeakDelegate")]
		[NullAllowed]
		NMAVenue3dMapLayerDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMAVenue3dMapLayerDelegate> _Nullable delegate;
		[NullAllowed, Export ("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// -(void)addListener:(id<NMAVenue3dMapLayerDelegate> _Nonnull)listener;
		[Export ("addListener:")]
		void AddListener (NMAVenue3dMapLayerDelegate listener);

		// -(void)removeListener:(id<NMAVenue3dMapLayerDelegate> _Nonnull)listener;
		[Export ("removeListener:")]
		void RemoveListener (NMAVenue3dMapLayerDelegate listener);

		// @property (readonly, nonatomic) NMAVenue3dController * _Nullable venueController;
		[NullAllowed, Export ("venueController")]
		NMAVenue3dController VenueController { get; }

		// @property (readonly, nonatomic) NMAVenue3dRoutingController * _Nullable venueRoutingController;
		[NullAllowed, Export ("venueRoutingController")]
		NMAVenue3dRoutingController VenueRoutingController { get; }

		// @property (nonatomic) BOOL visible;
		[Export ("visible")]
		bool Visible { get; set; }

		// @property (nonatomic) BOOL openMode;
		[Export ("openMode")]
		bool OpenMode { get; set; }

		// @property (nonatomic) BOOL shouldCheckVenuesInViewport;
		[Export ("shouldCheckVenuesInViewport")]
		bool ShouldCheckVenuesInViewport { get; set; }

		// @property (nonatomic) BOOL animatesFloorChange;
		[Export ("animatesFloorChange")]
		bool AnimatesFloorChange { get; set; }

		// @property (nonatomic) BOOL animatesVenueSelection;
		[Export ("animatesVenueSelection")]
		bool AnimatesVenueSelection { get; set; }

		// @property (nonatomic) BOOL hideIconOnSelectedSpace;
		[Export ("hideIconOnSelectedSpace")]
		bool HideIconOnSelectedSpace { get; set; }

		// @property (nonatomic) BOOL venueUpdatesEnabled;
		[Export ("venueUpdatesEnabled")]
		bool VenueUpdatesEnabled { get; set; }

		// @property (nonatomic) UIEdgeInsets margins;
		[Export ("margins", ArgumentSemantic.Assign)]
		UIEdgeInsets Margins { get; set; }

		// @property (readonly, nonatomic) NMAPositionIndicator * _Nullable positionIndicator;
		[NullAllowed, Export ("positionIndicator")]
		NMAPositionIndicator PositionIndicator { get; }

		// @property (readonly, nonatomic) NMAVenue3dNavigationManager * _Nonnull venueNavigationManager;
		[Export ("venueNavigationManager")]
		NMAVenue3dNavigationManager VenueNavigationManager { get; }

		// @property (readonly, nonatomic) NMAVenue3dCombinedNavigation * _Nonnull combinedNavigation;
		[Export ("combinedNavigation")]
		NMAVenue3dCombinedNavigation CombinedNavigation { get; }

		// -(void)start;
		[Export ("start")]
		void Start ();

		// -(NMAVenue3dController * _Nullable)controllerForVenue:(NMAVenue3dVenue * _Nullable)venue;
		[Export ("controllerForVenue:")]
		[return: NullAllowed]
		NMAVenue3dController ControllerForVenue ([NullAllowed] NMAVenue3dVenue venue);

		// -(void)selectVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export ("selectVenue:")]
		void SelectVenue (NMAVenue3dVenue venue);

		// -(NMAVenue3dVenueInfo * _Nullable)selectVenueWithVenueId:(NSString * _Nonnull)venueId;
		[Export ("selectVenueWithVenueId:")]
		[return: NullAllowed]
		NMAVenue3dVenueInfo SelectVenueWithVenueId (string venueId);

		// -(NMAVenue3dVenueInfo * _Nullable)selectVenueWithVenueId:(NSString * _Nonnull)venueId spaceId:(NSString * _Nonnull)spaceId;
		[Export ("selectVenueWithVenueId:spaceId:")]
		[return: NullAllowed]
		NMAVenue3dVenueInfo SelectVenueWithVenueId (string venueId, string spaceId);

		// -(BOOL)cancelVenueSelection;
		[Export ("cancelVenueSelection")]
		[Verify (MethodToProperty)]
		bool CancelVenueSelection { get; }

		// -(void)deselectVenue;
		[Export ("deselectVenue")]
		void DeselectVenue ();

		// -(BOOL)isVenueVisible:(NSString * _Nonnull)venueId;
		[Export ("isVenueVisible:")]
		bool IsVenueVisible (string venueId);
	}

	// @interface NMAClusterLayer : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAClusterLayer
	{
		// @property (nonatomic) NMAClusterTheme * _Nonnull theme;
		[Export ("theme", ArgumentSemantic.Assign)]
		NMAClusterTheme Theme { get; set; }

		// @property (readonly, nonatomic) NSArray * _Nonnull markers;
		[Export ("markers")]
		[Verify (StronglyTypedNSArray)]
		NSObject[] Markers { get; }

		// +(instancetype _Nonnull)clusterLayer;
		[Static]
		[Export ("clusterLayer")]
		NMAClusterLayer ClusterLayer ();

		// -(BOOL)addMarker:(NMAMapMarker * _Nonnull)marker;
		[Export ("addMarker:")]
		bool AddMarker (NMAMapMarker marker);

		// -(BOOL)addMarkers:(NSArray<NMAMapMarker *> * _Nonnull)markers;
		[Export ("addMarkers:")]
		bool AddMarkers (NMAMapMarker[] markers);

		// -(BOOL)removeMarker:(NMAMapMarker * _Nonnull)marker;
		[Export ("removeMarker:")]
		bool RemoveMarker (NMAMapMarker marker);

		// -(BOOL)removeMarkers:(NSArray<NMAMapMarker *> * _Nonnull)markers;
		[Export ("removeMarkers:")]
		bool RemoveMarkers (NMAMapMarker[] markers);
	}

	// @interface NMAMapOverlay : UIView <NMAMapViewDelegate>
	[BaseType (typeof(UIView))]
	interface NMAMapOverlay : INMAMapViewDelegate
	{
		// +(instancetype _Nonnull)mapOverlayWithSubview:(UIView * _Nonnull)subview;
		[Static]
		[Export ("mapOverlayWithSubview:")]
		NMAMapOverlay MapOverlayWithSubview (UIView subview);

		// +(instancetype _Nonnull)mapOverlayWithSubview:(UIView * _Nonnull)subview geoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Static]
		[Export ("mapOverlayWithSubview:geoCoordinates:")]
		NMAMapOverlay MapOverlayWithSubview (UIView subview, NMAGeoCoordinates coordinates);

		// @property (nonatomic, strong) NMAGeoCoordinates * _Nonnull coordinates;
		[Export ("coordinates", ArgumentSemantic.Strong)]
		NMAGeoCoordinates Coordinates { get; set; }

		// @property (nonatomic) CGPoint anchorOffset;
		[Export ("anchorOffset", ArgumentSemantic.Assign)]
		CGPoint AnchorOffset { get; set; }

		// @property (nonatomic) BOOL displayedAsMarker;
		[Export ("displayedAsMarker")]
		bool DisplayedAsMarker { get; set; }

		// @property (nonatomic) NSUInteger zMarkerIndex;
		[Export ("zMarkerIndex")]
		nuint ZMarkerIndex { get; set; }

		// -(instancetype _Nonnull)initWithSubview:(UIView * _Nonnull)subview;
		[Export ("initWithSubview:")]
		IntPtr Constructor (UIView subview);

		// -(instancetype _Nonnull)initWithSubview:(UIView * _Nonnull)subview geoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates __attribute__((objc_designated_initializer));
		[Export ("initWithSubview:geoCoordinates:")]
		[DesignatedInitializer]
		IntPtr Constructor (UIView subview, NMAGeoCoordinates coordinates);

		// -(CGPoint)setAnchorOffsetUsingLayoutPosition:(NMALayoutPosition)position;
		[Export ("setAnchorOffsetUsingLayoutPosition:")]
		CGPoint SetAnchorOffsetUsingLayoutPosition (NMALayoutPosition position);

		// -(void)refresh;
		[Export ("refresh")]
		void Refresh ();
	}

	[Static]
	[Verify (ConstantsInterfaceAssociation)]
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMAApplicationContextOnlineStatusDidChangeNotification;
		[Field ("NMAApplicationContextOnlineStatusDidChangeNotification", "__Internal")]
		NSString NMAApplicationContextOnlineStatusDidChangeNotification { get; }

		// extern NSString *const _Nonnull NMAApplicationContextLicenseKeyExpiredNotification;
		[Field ("NMAApplicationContextLicenseKeyExpiredNotification", "__Internal")]
		NSString NMAApplicationContextLicenseKeyExpiredNotification { get; }
	}

	// @interface NMAApplicationContext : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAApplicationContext
	{
		// +(NMAApplicationContextError)setAppId:(NSString * _Nonnull)appId appCode:(NSString * _Nonnull)appCode licenseKey:(NSString * _Nonnull)licenseKey;
		[Static]
		[Export ("setAppId:appCode:licenseKey:")]
		NMAApplicationContextError SetAppId (string appId, string appCode, string licenseKey);

		// +(NMAApplicationContextError)setAppId:(NSString * _Nonnull)appId appCode:(NSString * _Nonnull)appCode licenseKey:(NSString * _Nonnull)licenseKey mapVariant:(NMAMapVariant)mapVariant;
		[Static]
		[Export ("setAppId:appCode:licenseKey:mapVariant:")]
		NMAApplicationContextError SetAppId (string appId, string appCode, string licenseKey, NMAMapVariant mapVariant);

		// +(NSString * _Nullable)licenseKey;
		[Static]
		[NullAllowed, Export ("licenseKey")]
		[Verify (MethodToProperty)]
		string LicenseKey { get; }

		// +(void)setMapCenter:(NMAGeoCoordinates * _Nonnull)initialCenter;
		[Static]
		[Export ("setMapCenter:")]
		void SetMapCenter (NMAGeoCoordinates initialCenter);

		// +(NSString * _Nonnull)sdkVersion;
		[Static]
		[Export ("sdkVersion")]
		[Verify (MethodToProperty)]
		string SdkVersion { get; }

		// +(void)setNetworkAccessAllowed:(BOOL)networkAccessAllowed;
		[Static]
		[Export ("setNetworkAccessAllowed:")]
		void SetNetworkAccessAllowed (bool networkAccessAllowed);

		// +(BOOL)isNetworkAccessAllowed;
		[Static]
		[Export ("isNetworkAccessAllowed")]
		[Verify (MethodToProperty)]
		bool IsNetworkAccessAllowed { get; }

		// +(BOOL)enableTrafficInOfflineMode:(BOOL)enable;
		[Static]
		[Export ("enableTrafficInOfflineMode:")]
		bool EnableTrafficInOfflineMode (bool enable);

		// +(BOOL)isOnline;
		[Static]
		[Export ("isOnline")]
		[Verify (MethodToProperty)]
		bool IsOnline { get; }

		// +(BOOL)isInitialized;
		[Static]
		[Export ("isInitialized")]
		[Verify (MethodToProperty)]
		bool IsInitialized { get; }

		// +(void)disableSdkVersionInCrashStack;
		[Static]
		[Export ("disableSdkVersionInCrashStack")]
		void DisableSdkVersionInCrashStack ();

		// +(BOOL)setDiskCacheSize:(NSUInteger)size;
		[Static]
		[Export ("setDiskCacheSize:")]
		bool SetDiskCacheSize (nuint size);

		// +(NSString * _Nullable)getMapApprovalCodeWithCountry:(NSLocale * _Nonnull)locale;
		[Static]
		[Export ("getMapApprovalCodeWithCountry:")]
		[return: NullAllowed]
		string GetMapApprovalCodeWithCountry (NSLocale locale);

		// +(NSString * _Nullable)getMapDataProviderCopyrightStatementWithCountry:(NSLocale * _Nonnull)locale;
		[Static]
		[Export ("getMapDataProviderCopyrightStatementWithCountry:")]
		[return: NullAllowed]
		string GetMapDataProviderCopyrightStatementWithCountry (NSLocale locale);

		// +(void)enableEnhancedMapMatcher:(BOOL)enabled __attribute__((deprecated("")));
		[Static]
		[Export ("enableEnhancedMapMatcher:")]
		void EnableEnhancedMapMatcher (bool enabled);
	}

	// @interface NMAMapTransitLayer : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAMapTransitLayer
	{
		// -(void)highlightTransitLinesFromUniqueIds:(NSArray<NSString *> * _Nonnull)uniqueIds;
		[Export ("highlightTransitLinesFromUniqueIds:")]
		void HighlightTransitLinesFromUniqueIds (string[] uniqueIds);

		// -(void)highlightTransitStopsFromUniqueIds:(NSArray<NSString *> * _Nonnull)uniqueIds;
		[Export ("highlightTransitStopsFromUniqueIds:")]
		void HighlightTransitStopsFromUniqueIds (string[] uniqueIds);

		// -(void)highlightTransitAccessesFromUniqueIds:(NSArray<NSString *> * _Nonnull)uniqueIds;
		[Export ("highlightTransitAccessesFromUniqueIds:")]
		void HighlightTransitAccessesFromUniqueIds (string[] uniqueIds);

		// -(void)highlightTransitLineSegmentsFromUniqueIds:(NSArray<NSString *> * _Nonnull)uniqueIds;
		[Export ("highlightTransitLineSegmentsFromUniqueIds:")]
		void HighlightTransitLineSegmentsFromUniqueIds (string[] uniqueIds);

		// -(void)clearTransitHighlights;
		[Export ("clearTransitHighlights")]
		void ClearTransitHighlights ();
	}

	// @interface NMARoadElement : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARoadElement
	{
		// @property (readonly, nonatomic, weak) NSString * _Nullable uniqueId;
		[NullAllowed, Export ("uniqueId", ArgumentSemantic.Weak)]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSUInteger permanentLinkId;
		[Export ("permanentLinkId")]
		nuint PermanentLinkId { get; }

		// @property (readonly, nonatomic) NSInteger permanentDirectedLinkId;
		[Export ("permanentDirectedLinkId")]
		nint PermanentDirectedLinkId { get; }

		// @property (readonly, nonatomic) NSUInteger attributes;
		[Export ("attributes")]
		nuint Attributes { get; }

		// @property (readonly, nonatomic) NMARoadElementType type;
		[Export ("type")]
		NMARoadElementType Type { get; }

		// @property (readonly, nonatomic) NMARoadElementPluralType pluralType;
		[Export ("pluralType")]
		NMARoadElementPluralType PluralType { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable roadName;
		[NullAllowed, Export ("roadName", ArgumentSemantic.Weak)]
		string RoadName { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable abbreviatedName;
		[NullAllowed, Export ("abbreviatedName", ArgumentSemantic.Weak)]
		string AbbreviatedName { get; }

		// @property (readonly, nonatomic) float speedLimit;
		[Export ("speedLimit")]
		float SpeedLimit { get; }

		// @property (readonly, nonatomic) NSUInteger averageSpeed;
		[Export ("averageSpeed")]
		nuint AverageSpeed { get; }

		// @property (readonly, nonatomic) NSUInteger numberOfLanes;
		[Export ("numberOfLanes")]
		nuint NumberOfLanes { get; }

		// -(NSArray<NMATrafficSign *> * _Nullable)trafficSignsOrError:(NSError * _Nullable * _Nullable)error;
		[Export ("trafficSignsOrError:")]
		[return: NullAllowed]
		NMATrafficSign[] TrafficSignsOrError ([NullAllowed] out NSError error);
	}

	// @interface NMATransitRouteElement : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitRouteElement
	{
		// @property (readonly, nonatomic) NSTimeInterval duration;
		[Export ("duration")]
		double Duration { get; }

		// @property (readonly, nonatomic) NMATransitRouteStop * _Nullable departureStop;
		[NullAllowed, Export ("departureStop")]
		NMATransitRouteStop DepartureStop { get; }

		// @property (readonly, nonatomic) NMATransitRouteStop * _Nullable arrivalStop;
		[NullAllowed, Export ("arrivalStop")]
		NMATransitRouteStop ArrivalStop { get; }
	}

	// @interface NMATransitRouteStop : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitRouteStop
	{
		// @property (readonly, nonatomic) NSString * _Nullable identifier;
		[NullAllowed, Export ("identifier")]
		string Identifier { get; }

		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export ("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable coordinates;
		[NullAllowed, Export ("coordinates")]
		NMAGeoCoordinates Coordinates { get; }
	}

	// @interface NMAAddress : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAAddress
	{
		// @property (nonatomic) NSString * _Nullable floorNumber;
		[NullAllowed, Export ("floorNumber")]
		string FloorNumber { get; set; }

		// @property (nonatomic) NSString * _Nullable houseNumber;
		[NullAllowed, Export ("houseNumber")]
		string HouseNumber { get; set; }

		// @property (nonatomic) NSString * _Nullable suiteNumberOrName;
		[NullAllowed, Export ("suiteNumberOrName")]
		string SuiteNumberOrName { get; set; }

		// @property (nonatomic) NSString * _Nullable street;
		[NullAllowed, Export ("street")]
		string Street { get; set; }

		// @property (nonatomic) NSString * _Nullable district;
		[NullAllowed, Export ("district")]
		string District { get; set; }

		// @property (nonatomic) NSString * _Nullable county;
		[NullAllowed, Export ("county")]
		string County { get; set; }

		// @property (nonatomic) NSString * _Nullable city;
		[NullAllowed, Export ("city")]
		string City { get; set; }

		// @property (nonatomic) NSString * _Nullable state;
		[NullAllowed, Export ("state")]
		string State { get; set; }

		// @property (nonatomic) NSString * _Nullable postalCode;
		[NullAllowed, Export ("postalCode")]
		string PostalCode { get; set; }

		// @property (nonatomic) NSString * _Nullable countryCode;
		[NullAllowed, Export ("countryCode")]
		string CountryCode { get; set; }

		// @property (nonatomic) NSString * _Nullable countryName;
		[NullAllowed, Export ("countryName")]
		string CountryName { get; set; }

		// @property (nonatomic) NSString * _Nullable label;
		[NullAllowed, Export ("label")]
		string Label { get; set; }

		// @property (nonatomic) NSString * _Nullable formattedAddress;
		[NullAllowed, Export ("formattedAddress")]
		string FormattedAddress { get; set; }

		// -(NSDictionary<NSString *,NSString *> * _Nonnull)additionalData;
		[Export ("additionalData")]
		[Verify (MethodToProperty)]
		NSDictionary<NSString, NSString> AdditionalData { get; }
	}

	// @interface NMAVenue3dSpatialObject : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dSpatialObject
	{
		// @property (readonly, nonatomic) NSString * _Nonnull uniqueId;
		[Export ("uniqueId")]
		string UniqueId { get; }
	}

	// @interface NMAVenue3dVenue : NMAVenue3dSpatialObject
	[BaseType (typeof(NMAVenue3dSpatialObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dVenue
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull geoCenter;
		[Export ("geoCenter")]
		NMAGeoCoordinates GeoCenter { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export ("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readonly, nonatomic) NSInteger floorNumber;
		[Export ("floorNumber")]
		nint FloorNumber { get; }

		// @property (readonly, nonatomic) NSInteger groundFloorNumber;
		[Export ("groundFloorNumber")]
		nint GroundFloorNumber { get; }

		// @property (readonly, nonatomic) NSArray<NMAVenue3dLevel *> * _Nonnull levels;
		[Export ("levels")]
		NMAVenue3dLevel[] Levels { get; }

		// @property (readonly, nonatomic) NSArray<NMAVenue3dSpace *> * _Nonnull spaces;
		[Export ("spaces")]
		NMAVenue3dSpace[] Spaces { get; }

		// @property (readonly, nonatomic) NMAVenue3dContent * _Nullable content;
		[NullAllowed, Export ("content")]
		NMAVenue3dContent Content { get; }

		// -(NMAVenue3dSpace * _Nullable)spaceWithId:(NSString * _Nonnull)spaceId;
		[Export ("spaceWithId:")]
		[return: NullAllowed]
		NMAVenue3dSpace SpaceWithId (string spaceId);

		// -(NSArray<NMAVenue3dSpace *> * _Nonnull)nearbySpacesAroundSpace:(NMAVenue3dSpace * _Nonnull)space withinRadius:(float)radius;
		[Export ("nearbySpacesAroundSpace:withinRadius:")]
		NMAVenue3dSpace[] NearbySpacesAroundSpace (NMAVenue3dSpace space, float radius);
	}

	// @interface NMAVenue3dVenueInfo : NMAVenue3dSpatialObject
	[BaseType (typeof(NMAVenue3dSpatialObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dVenueInfo
	{
		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export ("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull name;
		[Export ("name")]
		string Name { get; }

		// @property (readonly, nonatomic) BOOL isAlternativeSource;
		[Export ("isAlternativeSource")]
		bool IsAlternativeSource { get; }
	}

	// @interface NMAVenue3dController : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dController
	{
		// @property (readonly, nonatomic) NMAVenue3dVenue * _Nonnull venue;
		[Export ("venue")]
		NMAVenue3dVenue Venue { get; }

		// @property (readonly, nonatomic) NMAVenue3dLevel * _Nonnull groundLevel;
		[Export ("groundLevel")]
		NMAVenue3dLevel GroundLevel { get; }

		// @property (nonatomic, weak) NMAVenue3dLevel * _Nullable level;
		[NullAllowed, Export ("level", ArgumentSemantic.Weak)]
		NMAVenue3dLevel Level { get; set; }

		// @property (nonatomic, weak) NMAVenue3dSpace * _Nullable space;
		[NullAllowed, Export ("space", ArgumentSemantic.Weak)]
		NMAVenue3dSpace Space { get; set; }

		// -(void)deselectSpace;
		[Export ("deselectSpace")]
		void DeselectSpace ();

		// @property (nonatomic) NMAVenue3dStyleSettings * _Nullable styleSettings;
		[NullAllowed, Export ("styleSettings", ArgumentSemantic.Assign)]
		NMAVenue3dStyleSettings StyleSettings { get; set; }

		// -(NMAVenue3dStyleSettings * _Nullable)getStyleSettingsForSpace:(NMAVenue3dSpace * _Nonnull)space;
		[Export ("getStyleSettingsForSpace:")]
		[return: NullAllowed]
		NMAVenue3dStyleSettings GetStyleSettingsForSpace (NMAVenue3dSpace space);

		// -(void)setStyleSettings:(NMAVenue3dStyleSettings * _Nullable)settings forSpace:(NMAVenue3dSpace * _Nonnull)space;
		[Export ("setStyleSettings:forSpace:")]
		void SetStyleSettings ([NullAllowed] NMAVenue3dStyleSettings settings, NMAVenue3dSpace space);

		// -(NMAVenue3dBaseLocation * _Nullable)getLocationAtX:(float)x Y:(float)y WithSpacePrefered:(_Bool)preferSpace;
		[Export ("getLocationAtX:Y:WithSpacePrefered:")]
		[return: NullAllowed]
		NMAVenue3dBaseLocation GetLocationAtX (float x, float y, bool preferSpace);
	}

	// @interface NMAVenue3dLevel : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dLevel
	{
		// @property (readonly, nonatomic) NSArray<NMAVenue3dOuterArea *> * _Nonnull outerAreas;
		[Export ("outerAreas")]
		NMAVenue3dOuterArea[] OuterAreas { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull geoCenter;
		[Export ("geoCenter")]
		NMAGeoCoordinates GeoCenter { get; }

		// @property (readonly, nonatomic) NSArray<NMAVenue3dSpace *> * _Nonnull spaces;
		[Export ("spaces")]
		NMAVenue3dSpace[] Spaces { get; }

		// @property (readonly, nonatomic) NSArray<NMAVenue3dSpace *> * _Nonnull spacesAndFacilities;
		[Export ("spacesAndFacilities")]
		NMAVenue3dSpace[] SpacesAndFacilities { get; }

		// -(NSArray<NMAVenue3dSpace *> * _Nonnull)spacesWithCategory:(NSString * _Nonnull)categoryName;
		[Export ("spacesWithCategory:")]
		NMAVenue3dSpace[] SpacesWithCategory (string categoryName);

		// @property (readonly, nonatomic) NSString * _Nonnull floorSynonym;
		[Export ("floorSynonym")]
		string FloorSynonym { get; }

		// @property (readonly, nonatomic) NSInteger floorNumber;
		[Export ("floorNumber")]
		nint FloorNumber { get; }

		// -(NMAVenue3dArea * _Nullable)areaAtPosition:(NMAGeoCoordinates * _Nonnull)position;
		[Export ("areaAtPosition:")]
		[return: NullAllowed]
		NMAVenue3dArea AreaAtPosition (NMAGeoCoordinates position);

		// -(NSArray<NMAVenue3dSpace *> * _Nonnull)nearbySpacesAroundPosition:(NMAGeoCoordinates * _Nonnull)position withinRadius:(float)radius;
		[Export ("nearbySpacesAroundPosition:withinRadius:")]
		NMAVenue3dSpace[] NearbySpacesAroundPosition (NMAGeoCoordinates position, float radius);
	}

	// @interface NMAVenue3dArea : NMAVenue3dSpatialObject
	[BaseType (typeof(NMAVenue3dSpatialObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dArea
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull geoCenter;
		[Export ("geoCenter")]
		NMAGeoCoordinates GeoCenter { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export ("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readonly, nonatomic) NMAGeoPolygon * _Nullable polygon;
		[NullAllowed, Export ("polygon")]
		NMAGeoPolygon Polygon { get; }

		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export ("name")]
		string Name { get; }
	}

	// @interface NMAVenue3dSpace : NMAVenue3dArea
	[BaseType (typeof(NMAVenue3dArea))]
	[DisableDefaultCtor]
	interface NMAVenue3dSpace
	{
		// @property (readonly, nonatomic) NMAVenue3dContent * _Nullable content;
		[NullAllowed, Export ("content")]
		NMAVenue3dContent Content { get; }

		// @property (readonly, nonatomic) NSInteger floorNumber;
		[Export ("floorNumber")]
		nint FloorNumber { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull floorSynonym;
		[Export ("floorSynonym")]
		string FloorSynonym { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull venueName;
		[Export ("venueName")]
		string VenueName { get; }

		// @property (readonly, nonatomic) UIImage * _Nullable icon;
		[NullAllowed, Export ("icon")]
		UIImage Icon { get; }

		// @property (readonly, nonatomic) NSString * _Nullable iconUri;
		[NullAllowed, Export ("iconUri")]
		string IconUri { get; }

		// @property (readonly, nonatomic) NMAVenue3dSpaceType type;
		[Export ("type")]
		NMAVenue3dSpaceType Type { get; }
	}

	// @interface NMAVenue3dBaseLocation : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dBaseLocation
	{
		// -(void)setParkingLocation:(NMAVenue3dBaseLocation * _Nonnull)location;
		[Export ("setParkingLocation:")]
		void SetParkingLocation (NMAVenue3dBaseLocation location);

		// -(BOOL)isValid;
		[Export ("isValid")]
		[Verify (MethodToProperty)]
		bool IsValid { get; }

		// -(NMAVenue3dArea * _Nullable)getArea;
		[NullAllowed, Export ("getArea")]
		[Verify (MethodToProperty)]
		NMAVenue3dArea Area { get; }

		// -(NMAGeoCoordinates * _Nullable)getGeoCoordinate;
		[NullAllowed, Export ("getGeoCoordinate")]
		[Verify (MethodToProperty)]
		NMAGeoCoordinates GeoCoordinate { get; }

		// -(NMAVenue3dBaseLocationType)getType;
		[Export ("getType")]
		[Verify (MethodToProperty)]
		NMAVenue3dBaseLocationType Type { get; }
	}

	// @interface NMAVenue3dStyleSettings : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dStyleSettings
	{
		// @property (readwrite, nonatomic) UIColor * _Nullable fillColor;
		[NullAllowed, Export ("fillColor", ArgumentSemantic.Assign)]
		UIColor FillColor { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nullable outlineColor;
		[NullAllowed, Export ("outlineColor", ArgumentSemantic.Assign)]
		UIColor OutlineColor { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nullable selectedFillColor;
		[NullAllowed, Export ("selectedFillColor", ArgumentSemantic.Assign)]
		UIColor SelectedFillColor { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nullable selectedOutlineColor;
		[NullAllowed, Export ("selectedOutlineColor", ArgumentSemantic.Assign)]
		UIColor SelectedOutlineColor { get; set; }

		// @property (readwrite, nonatomic) NSString * _Nullable labelName;
		[NullAllowed, Export ("labelName")]
		string LabelName { get; set; }

		// @property (readwrite, nonatomic) NMAImage * _Nullable labelImage;
		[NullAllowed, Export ("labelImage", ArgumentSemantic.Assign)]
		NMAImage LabelImage { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nullable labelFillColor;
		[NullAllowed, Export ("labelFillColor", ArgumentSemantic.Assign)]
		UIColor LabelFillColor { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nullable labelOutlineColor;
		[NullAllowed, Export ("labelOutlineColor", ArgumentSemantic.Assign)]
		UIColor LabelOutlineColor { get; set; }
	}

	// @protocol NMAVenue3dRoutingControllerObserver <NSObject>
	[Protocol, Model]
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dRoutingControllerObserver
	{
		// @required -(void)didCalculateRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Abstract]
		[Export ("didCalculateRoute:")]
		void DidCalculateRoute (NMAVenue3dCombinedRoute combinedRoute);
	}

	// @interface NMAVenue3dRoutingController : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dRoutingController
	{
		// -(void)calculateRouteFrom:(NMAVenue3dBaseLocation * _Nonnull)startLocation to:(NMAVenue3dBaseLocation * _Nonnull)endLocation withParams:(NMAVenue3dRouteOptions * _Nonnull)options;
		[Export ("calculateRouteFrom:to:withParams:")]
		void CalculateRouteFrom (NMAVenue3dBaseLocation startLocation, NMAVenue3dBaseLocation endLocation, NMAVenue3dRouteOptions options);

		// -(void)calculateRouteWithPoints:(NSArray<NMAVenue3dBaseLocation *> * _Nonnull)points withParams:(NMAVenue3dRouteOptions * _Nonnull)options;
		[Export ("calculateRouteWithPoints:withParams:")]
		void CalculateRouteWithPoints (NMAVenue3dBaseLocation[] points, NMAVenue3dRouteOptions options);

		// -(void)addObserver:(id<NMAVenue3dRoutingControllerObserver> _Nonnull)observer;
		[Export ("addObserver:")]
		void AddObserver (NMAVenue3dRoutingControllerObserver observer);

		// -(void)removeObserver:(id<NMAVenue3dRoutingControllerObserver> _Nonnull)observer;
		[Export ("removeObserver:")]
		void RemoveObserver (NMAVenue3dRoutingControllerObserver observer);

		// -(void)showRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export ("showRoute:")]
		void ShowRoute (NMAVenue3dCombinedRoute combinedRoute);

		// -(void)showRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute withStyleOptions:(NMAVenue3dRouteStyleOptions * _Nonnull)styleOptions;
		[Export ("showRoute:withStyleOptions:")]
		void ShowRoute (NMAVenue3dCombinedRoute combinedRoute, NMAVenue3dRouteStyleOptions styleOptions);

		// -(void)hideRoute;
		[Export ("hideRoute")]
		void HideRoute ();
	}

	[Static]
	[Verify (ConstantsInterfaceAssociation)]
	partial interface Constants
	{
		// extern const float NMAVenue3dNavigationManagerInvalidValue;
		[Field ("NMAVenue3dNavigationManagerInvalidValue", "__Internal")]
		float NMAVenue3dNavigationManagerInvalidValue { get; }

		// extern const NSTimeInterval NMAVenue3dNavigationManagerInvalidTimeInterval;
		[Field ("NMAVenue3dNavigationManagerInvalidTimeInterval", "__Internal")]
		double NMAVenue3dNavigationManagerInvalidTimeInterval { get; }
	}

	// @protocol NMAVenue3dNavigationListener <NSObject>
	[Protocol, Model]
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dNavigationListener
	{
		// @optional -(void)navigationManagerDidReachDestination:(NMAVenue3dNavigationManager * _Nonnull)navigationManager;
		[Export ("navigationManagerDidReachDestination:")]
		void NavigationManagerDidReachDestination (NMAVenue3dNavigationManager navigationManager);

		// @optional -(void)navigationManager:(NMAVenue3dNavigationManager * _Nonnull)navigationManager hasCurrentManeuver:(NMAVenue3dRouteManeuver * _Nullable)maneuver nextManeuver:(NMAVenue3dRouteManeuver * _Nullable)nextManeuver;
		[Export ("navigationManager:hasCurrentManeuver:nextManeuver:")]
		void NavigationManager (NMAVenue3dNavigationManager navigationManager, [NullAllowed] NMAVenue3dRouteManeuver maneuver, [NullAllowed] NMAVenue3dRouteManeuver nextManeuver);

		// @optional -(void)navigationManagerDidLosePosition:(NMAVenue3dNavigationManager * _Nonnull)navigationManager;
		[Export ("navigationManagerDidLosePosition:")]
		void NavigationManagerDidLosePosition (NMAVenue3dNavigationManager navigationManager);

		// @optional -(void)navigationManagerDidFindPosition:(NMAVenue3dNavigationManager * _Nonnull)navigationManager;
		[Export ("navigationManagerDidFindPosition:")]
		void NavigationManagerDidFindPosition (NMAVenue3dNavigationManager navigationManager);

		// @optional -(void)navigationManager:(NMAVenue3dNavigationManager * _Nonnull)navigationManager didUpdateRouteSection:(NMAVenue3dVenueRouteSection * _Nonnull)routeSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export ("navigationManager:didUpdateRouteSection:inCombinedRoute:")]
		void NavigationManager (NMAVenue3dNavigationManager navigationManager, NMAVenue3dVenueRouteSection routeSection, NMAVenue3dCombinedRoute combinedRoute);

		// @optional -(void)navigationManagerWillReroute:(NMAVenue3dNavigationManager * _Nonnull)navigationManager;
		[Export ("navigationManagerWillReroute:")]
		void NavigationManagerWillReroute (NMAVenue3dNavigationManager navigationManager);

		// @optional -(void)navigationManagerDidReroute:(NMAVenue3dNavigationManager * _Nonnull)navigationManager;
		[Export ("navigationManagerDidReroute:")]
		void NavigationManagerDidReroute (NMAVenue3dNavigationManager navigationManager);
	}

	// @interface NMAVenue3dNavigationManager : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dNavigationManager
	{
		// @property (readonly, nonatomic) NMAVenue3dNavigationState navigationState;
		[Export ("navigationState")]
		NMAVenue3dNavigationState NavigationState { get; }

		// @property (getter = isPaused, nonatomic) BOOL paused;
		[Export ("paused")]
		bool Paused { [Bind ("isPaused")] get; set; }

		// @property (getter = isMapTrackingEnabled, nonatomic) BOOL mapTrackingEnabled;
		[Export ("mapTrackingEnabled")]
		bool MapTrackingEnabled { [Bind ("isMapTrackingEnabled")] get; set; }

		// @property (nonatomic) NMAVenue3dTrackingTilt mapTrackingTilt;
		[Export ("mapTrackingTilt", ArgumentSemantic.Assign)]
		NMAVenue3dTrackingTilt MapTrackingTilt { get; set; }

		// @property (nonatomic) NMAVenue3dTrackingMode mapTrackingMode;
		[Export ("mapTrackingMode", ArgumentSemantic.Assign)]
		NMAVenue3dTrackingMode MapTrackingMode { get; set; }

		// @property (readonly, nonatomic, weak) NMAVenue3dMapLayer * _Nullable venueMapLayer;
		[NullAllowed, Export ("venueMapLayer", ArgumentSemantic.Weak)]
		NMAVenue3dMapLayer VenueMapLayer { get; }

		// @property (readonly, nonatomic, weak) NMAVenue3dVenue * _Nullable venue;
		[NullAllowed, Export ("venue", ArgumentSemantic.Weak)]
		NMAVenue3dVenue Venue { get; }

		// @property (readonly, nonatomic) NMAVenue3dRouteManeuver * _Nullable currentManeuver;
		[NullAllowed, Export ("currentManeuver")]
		NMAVenue3dRouteManeuver CurrentManeuver { get; }

		// @property (readonly, nonatomic) NMAVenue3dRouteManeuver * _Nullable nextManeuver;
		[NullAllowed, Export ("nextManeuver")]
		NMAVenue3dRouteManeuver NextManeuver { get; }

		// @property (readonly, nonatomic) float distanceToCurrentManeuver;
		[Export ("distanceToCurrentManeuver")]
		float DistanceToCurrentManeuver { get; }

		// @property (readonly, nonatomic) float distanceToNextManeuver;
		[Export ("distanceToNextManeuver")]
		float DistanceToNextManeuver { get; }

		// @property (readonly, nonatomic) float distanceToDestination;
		[Export ("distanceToDestination")]
		float DistanceToDestination { get; }

		// @property (readonly, nonatomic) float distanceFromStart;
		[Export ("distanceFromStart")]
		float DistanceFromStart { get; }

		// @property (readonly, nonatomic) float averageSpeed;
		[Export ("averageSpeed")]
		float AverageSpeed { get; }

		// @property (readonly, nonatomic) NSTimeInterval timeToArrival;
		[Export ("timeToArrival")]
		double TimeToArrival { get; }

		// @property (nonatomic) NSTimeInterval reroutingTimeout;
		[Export ("reroutingTimeout")]
		double ReroutingTimeout { get; set; }

		// @property (nonatomic) _Bool vibrationEnabled;
		[Export ("vibrationEnabled")]
		bool VibrationEnabled { get; set; }

		// @property (nonatomic) _Bool beepsEnabled;
		[Export ("beepsEnabled")]
		bool BeepsEnabled { get; set; }

		// @property (nonatomic) BOOL backgroundNavigationEnabled;
		[Export ("backgroundNavigationEnabled")]
		bool BackgroundNavigationEnabled { get; set; }

		// @property (nonatomic) BOOL backgroundNavigationStartEnabled;
		[Export ("backgroundNavigationStartEnabled")]
		bool BackgroundNavigationStartEnabled { get; set; }

		// -(void)addListener:(id<NMAVenue3dNavigationListener> _Nonnull)listener;
		[Export ("addListener:")]
		void AddListener (NMAVenue3dNavigationListener listener);

		// -(void)removeListener:(id<NMAVenue3dNavigationListener> _Nonnull)listener;
		[Export ("removeListener:")]
		void RemoveListener (NMAVenue3dNavigationListener listener);

		// -(BOOL)startForRouteSection:(NMAVenue3dVenueRouteSection * _Nonnull)routeSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export ("startForRouteSection:inCombinedRoute:")]
		bool StartForRouteSection (NMAVenue3dVenueRouteSection routeSection, NMAVenue3dCombinedRoute combinedRoute);

		// -(BOOL)startForLinkSection:(NMAVenue3dLinkRouteSection * _Nonnull)linkSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export ("startForLinkSection:inCombinedRoute:")]
		bool StartForLinkSection (NMAVenue3dLinkRouteSection linkSection, NMAVenue3dCombinedRoute combinedRoute);

		// -(void)stop;
		[Export ("stop")]
		void Stop ();

		// @property (readwrite, nonatomic) BOOL maneuverZoomEnabled;
		[Export ("maneuverZoomEnabled")]
		bool ManeuverZoomEnabled { get; set; }

		// @property (readwrite, nonatomic) float maneuverZoomDistance;
		[Export ("maneuverZoomDistance")]
		float ManeuverZoomDistance { get; set; }

		// @property (readwrite, nonatomic) float maneuverZoomLevel;
		[Export ("maneuverZoomLevel")]
		float ManeuverZoomLevel { get; set; }
	}

	[Static]
	[Verify (ConstantsInterfaceAssociation)]
	partial interface Constants
	{
		// extern const double NMAVenue3dCombinedNavigationManagerInvalidValue;
		[Field ("NMAVenue3dCombinedNavigationManagerInvalidValue", "__Internal")]
		double NMAVenue3dCombinedNavigationManagerInvalidValue { get; }
	}

	// @protocol NMAVenue3dCombinedNavigationListener <NSObject>
	[Protocol, Model]
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dCombinedNavigationListener
	{
		// @optional -(void)navigationManagerDidReachDestination:(NMAVenue3dCombinedNavigation * _Nonnull)navigationManager;
		[Export ("navigationManagerDidReachDestination:")]
		void NavigationManagerDidReachDestination (NMAVenue3dCombinedNavigation navigationManager);

		// @optional -(void)navigationManager:(NMAVenue3dCombinedNavigation * _Nonnull)navigationManager didUpdateCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export ("navigationManager:didUpdateCombinedRoute:")]
		void NavigationManager (NMAVenue3dCombinedNavigation navigationManager, NMAVenue3dCombinedRoute combinedRoute);

		// @optional -(void)navigationManager:(NMAVenue3dCombinedNavigation * _Nonnull)navigationManager willStartIndoorSection:(NMAVenue3dVenueRouteSection * _Nonnull)indoorSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export ("navigationManager:willStartIndoorSection:inCombinedRoute:")]
		void NavigationManager (NMAVenue3dCombinedNavigation navigationManager, NMAVenue3dVenueRouteSection indoorSection, NMAVenue3dCombinedRoute combinedRoute);

		// @optional -(void)navigationManager:(NMAVenue3dCombinedNavigation * _Nonnull)navigationManager willStartLinkingSection:(NMAVenue3dLinkRouteSection * _Nonnull)linkingSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export ("navigationManager:willStartLinkingSection:inCombinedRoute:")]
		void NavigationManager (NMAVenue3dCombinedNavigation navigationManager, NMAVenue3dLinkRouteSection linkingSection, NMAVenue3dCombinedRoute combinedRoute);

		// @optional -(void)navigationManager:(NMAVenue3dCombinedNavigation * _Nonnull)navigationManager willStartOutdoorSection:(NMAVenue3dOutdoorRouteSection * _Nonnull)outdoorSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export ("navigationManager:willStartOutdoorSection:inCombinedRoute:")]
		void NavigationManager (NMAVenue3dCombinedNavigation navigationManager, NMAVenue3dOutdoorRouteSection outdoorSection, NMAVenue3dCombinedRoute combinedRoute);
	}

	// @interface NMAVenue3dCombinedNavigation : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dCombinedNavigation
	{
		// @property (readonly, nonatomic) NMAVenue3dCombinedNavigationState navigationState;
		[Export ("navigationState")]
		NMAVenue3dCombinedNavigationState NavigationState { get; }

		// @property (getter = isPaused, nonatomic) BOOL paused;
		[Export ("paused")]
		bool Paused { [Bind ("isPaused")] get; set; }

		// @property (readonly, nonatomic, weak) NMAVenue3dMapLayer * _Nullable venueMapLayer;
		[NullAllowed, Export ("venueMapLayer", ArgumentSemantic.Weak)]
		NMAVenue3dMapLayer VenueMapLayer { get; }

		// @property (readonly, nonatomic) NMAVenue3dCombinedNavigationType currentNavigationType;
		[Export ("currentNavigationType")]
		NMAVenue3dCombinedNavigationType CurrentNavigationType { get; }

		// @property (readonly, nonatomic) double distanceToDestination;
		[Export ("distanceToDestination")]
		double DistanceToDestination { get; }

		// @property (readonly, nonatomic) double distanceFromStart;
		[Export ("distanceFromStart")]
		double DistanceFromStart { get; }

		// -(void)addListener:(id<NMAVenue3dCombinedNavigationListener> _Nonnull)listener;
		[Export ("addListener:")]
		void AddListener (NMAVenue3dCombinedNavigationListener listener);

		// -(void)removeListener:(id<NMAVenue3dCombinedNavigationListener> _Nonnull)listener;
		[Export ("removeListener:")]
		void RemoveListener (NMAVenue3dCombinedNavigationListener listener);

		// -(BOOL)startForCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export ("startForCombinedRoute:")]
		bool StartForCombinedRoute (NMAVenue3dCombinedRoute combinedRoute);

		// -(BOOL)simulateForCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute speed:(double)speed distortionEnabled:(BOOL)distortionEnabled updateInterval:(NSTimeInterval)updateInterval;
		[Export ("simulateForCombinedRoute:speed:distortionEnabled:updateInterval:")]
		bool SimulateForCombinedRoute (NMAVenue3dCombinedRoute combinedRoute, double speed, bool distortionEnabled, double updateInterval);

		// -(void)stop;
		[Export ("stop")]
		void Stop ();
	}

	// @interface NMAVenue3dOuterArea : NMAVenue3dArea
	[BaseType (typeof(NMAVenue3dArea))]
	[DisableDefaultCtor]
	interface NMAVenue3dOuterArea
	{
		// @property (readonly, nonatomic) NSArray<NMAVenue3dSpace *> * _Nonnull spaces;
		[Export ("spaces")]
		NMAVenue3dSpace[] Spaces { get; }

		// -(NMAVenue3dSpace * _Nullable)spaceAtPosition:(NMAGeoCoordinates * _Nonnull)position;
		[Export ("spaceAtPosition:")]
		[return: NullAllowed]
		NMAVenue3dSpace SpaceAtPosition (NMAGeoCoordinates position);

		// -(NSArray<NMAVenue3dSpace *> * _Nonnull)nearbySpacesAroundPosition:(NMAGeoCoordinates * _Nonnull)position withinRadius:(float)radius;
		[Export ("nearbySpacesAroundPosition:withinRadius:")]
		NMAVenue3dSpace[] NearbySpacesAroundPosition (NMAGeoCoordinates position, float radius);
	}

	// @interface NMAVenue3dContent : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dContent
	{
		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export ("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NSString * _Nullable phoneNumber;
		[NullAllowed, Export ("phoneNumber")]
		string PhoneNumber { get; }

		// @property (readonly, nonatomic) NSString * _Nullable website;
		[NullAllowed, Export ("website")]
		string Website { get; }

		// @property (readonly, nonatomic) NSString * _Nullable email;
		[NullAllowed, Export ("email")]
		string Email { get; }

		// @property (readonly, nonatomic) NMAAddress * _Nonnull address;
		[Export ("address")]
		NMAAddress Address { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull parentCategoryId;
		[Export ("parentCategoryId")]
		string ParentCategoryId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull placeCategoryId;
		[Export ("placeCategoryId")]
		string PlaceCategoryId { get; }

		// @property (readonly, nonatomic) NSArray<NSString *> * _Nonnull searchTags;
		[Export ("searchTags")]
		string[] SearchTags { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull uniqueVenueId;
		[Export ("uniqueVenueId")]
		string UniqueVenueId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull uniqueId;
		[Export ("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull categoryId;
		[Export ("categoryId")]
		string CategoryId { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NSObject *> * _Nullable customAttributes;
		[NullAllowed, Export ("customAttributes")]
		NSDictionary<NSString, NSObject> CustomAttributes { get; }
	}

	// @interface NMAVenue3dCombinedRoute : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dCombinedRoute
	{
		// @property (readonly, nonatomic) NSArray<NMAVenue3dRouteSection *> * _Nonnull routeSections;
		[Export ("routeSections")]
		NMAVenue3dRouteSection[] RouteSections { get; }

		// -(BOOL)conformsConnectorOptions;
		[Export ("conformsConnectorOptions")]
		[Verify (MethodToProperty)]
		bool ConformsConnectorOptions { get; }

		// -(BOOL)conformsModeOptions;
		[Export ("conformsModeOptions")]
		[Verify (MethodToProperty)]
		bool ConformsModeOptions { get; }

		// -(NMAVenue3dRoutingError)getError;
		[Export ("getError")]
		[Verify (MethodToProperty)]
		NMAVenue3dRoutingError Error { get; }

		// -(NMARoutingError)getCoreMapError;
		[Export ("getCoreMapError")]
		[Verify (MethodToProperty)]
		NMARoutingError CoreMapError { get; }

		// -(NMAVenue3dBaseLocation * _Nonnull)getStart;
		[Export ("getStart")]
		[Verify (MethodToProperty)]
		NMAVenue3dBaseLocation Start { get; }

		// -(NMAVenue3dBaseLocation * _Nonnull)getEnd;
		[Export ("getEnd")]
		[Verify (MethodToProperty)]
		NMAVenue3dBaseLocation End { get; }

		// -(NSArray<NMAVenue3dBaseLocation *> * _Nonnull)getWaypoints;
		[Export ("getWaypoints")]
		[Verify (MethodToProperty)]
		NMAVenue3dBaseLocation[] Waypoints { get; }

		// -(NSInteger)getLength;
		[Export ("getLength")]
		[Verify (MethodToProperty)]
		nint Length { get; }
	}

	// @interface NMAVenue3dRouteSection : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dRouteSection
	{
	}

	[Static]
	[Verify (ConstantsInterfaceAssociation)]
	partial interface Constants
	{
		// extern const float NMARoutingModeStartDirectionAny;
		[Field ("NMARoutingModeStartDirectionAny", "__Internal")]
		float NMARoutingModeStartDirectionAny { get; }
	}

	// @interface NMARoutingMode : NSObject
	[BaseType (typeof(NSObject))]
	interface NMARoutingMode
	{
		// -(instancetype _Nonnull)initWithRoutingType:(NMARoutingType)routingType transportMode:(NMATransportMode)transportMode routingOptions:(NMARoutingOption)routingOptions;
		[Export ("initWithRoutingType:transportMode:routingOptions:")]
		IntPtr Constructor (NMARoutingType routingType, NMATransportMode transportMode, NMARoutingOption routingOptions);

		// @property (nonatomic) NMARoutingType routingType;
		[Export ("routingType", ArgumentSemantic.Assign)]
		NMARoutingType RoutingType { get; set; }

		// @property (nonatomic) NMATransportMode transportMode;
		[Export ("transportMode", ArgumentSemantic.Assign)]
		NMATransportMode TransportMode { get; set; }

		// @property (nonatomic) NMASpeedProfile speedProfile;
		[Export ("speedProfile", ArgumentSemantic.Assign)]
		NMASpeedProfile SpeedProfile { get; set; }

		// @property (nonatomic) NMARoutingOption routingOptions;
		[Export ("routingOptions", ArgumentSemantic.Assign)]
		NMARoutingOption RoutingOptions { get; set; }

		// @property (nonatomic, strong) NSDate * _Nullable departureTime;
		[NullAllowed, Export ("departureTime", ArgumentSemantic.Strong)]
		NSDate DepartureTime { get; set; }

		// @property (nonatomic) NSUInteger resultLimit;
		[Export ("resultLimit")]
		nuint ResultLimit { get; set; }

		// @property (nonatomic) float startDirection;
		[Export ("startDirection")]
		float StartDirection { get; set; }

		// @property (nonatomic) NSUInteger deviationDistanceToPedestrianReroute;
		[Export ("deviationDistanceToPedestrianReroute")]
		nuint DeviationDistanceToPedestrianReroute { get; set; }

		// @property (nonatomic) NSArray<NSString *> * _Nonnull excludeRoutingZones;
		[Export ("excludeRoutingZones", ArgumentSemantic.Assign)]
		string[] ExcludeRoutingZones { get; set; }

		// @property (copy, nonatomic) NSArray<NSString *> * _Nonnull excludedCountries;
		[Export ("excludedCountries", ArgumentSemantic.Copy)]
		string[] ExcludedCountries { get; set; }

		// @property (nonatomic) NSString * _Nullable licensePlateLastCharacter;
		[NullAllowed, Export ("licensePlateLastCharacter")]
		string LicensePlateLastCharacter { get; set; }

		// @property (nonatomic) NSString * _Nullable languagePreference;
		[NullAllowed, Export ("languagePreference")]
		string LanguagePreference { get; set; }
	}

	// @interface NMAVenue3dRouteOptions : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dRouteOptions
	{
		// +(instancetype _Nonnull)optionsWithRoutingMode:(NMARoutingMode * _Nonnull)routingMode;
		[Static]
		[Export ("optionsWithRoutingMode:")]
		NMAVenue3dRouteOptions OptionsWithRoutingMode (NMARoutingMode routingMode);

		// -(instancetype _Nonnull)initWithRoutingMode:(NMARoutingMode * _Nonnull)routingMode;
		[Export ("initWithRoutingMode:")]
		IntPtr Constructor (NMARoutingMode routingMode);

		// -(BOOL)isRouteVisibleFor:(NMAVenue3dRouteSectionType)sectionType;
		[Export ("isRouteVisibleFor:")]
		bool IsRouteVisibleFor (NMAVenue3dRouteSectionType sectionType);

		// -(void)setRouteVisibilityFor:(NMAVenue3dRouteSectionType)sectionType as:(BOOL)visibility;
		[Export ("setRouteVisibilityFor:as:")]
		void SetRouteVisibilityFor (NMAVenue3dRouteSectionType sectionType, bool visibility);

		// -(UIColor * _Nonnull)routeColorFor:(NMAVenue3dRouteSectionType)sectionType;
		[Export ("routeColorFor:")]
		UIColor RouteColorFor (NMAVenue3dRouteSectionType sectionType);

		// -(void)setRouteColorForType:(NMAVenue3dRouteSectionType)sectionType as:(UIColor * _Nonnull)color;
		[Export ("setRouteColorForType:as:")]
		void SetRouteColorForType (NMAVenue3dRouteSectionType sectionType, UIColor color);

		// @property (readwrite, nonatomic) BOOL flagsVisible;
		[Export ("flagsVisible")]
		bool FlagsVisible { get; set; }

		// @property (readwrite, nonatomic) BOOL iconsVisible;
		[Export ("iconsVisible")]
		bool IconsVisible { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nonnull connectorColor;
		[Export ("connectorColor", ArgumentSemantic.Assign)]
		UIColor ConnectorColor { get; set; }

		// @property (readwrite, nonatomic) double indoorRouteLineWidth;
		[Export ("indoorRouteLineWidth")]
		double IndoorRouteLineWidth { get; set; }

		// @property (readwrite, nonatomic) int outdoorRouteLineWidth;
		[Export ("outdoorRouteLineWidth")]
		int OutdoorRouteLineWidth { get; set; }

		// @property (readwrite, nonatomic) BOOL autoParking;
		[Export ("autoParking")]
		bool AutoParking { get; set; }

		// @property (readwrite, nonatomic) BOOL avoidElevators;
		[Export ("avoidElevators")]
		bool AvoidElevators { get; set; }

		// @property (readwrite, nonatomic) BOOL avoidEscalators;
		[Export ("avoidEscalators")]
		bool AvoidEscalators { get; set; }

		// @property (readwrite, nonatomic) BOOL avoidStairs;
		[Export ("avoidStairs")]
		bool AvoidStairs { get; set; }

		// @property (readwrite, nonatomic) BOOL avoidRamps;
		[Export ("avoidRamps")]
		bool AvoidRamps { get; set; }

		// @property (readwrite, nonatomic) BOOL preferCorridors;
		[Export ("preferCorridors")]
		bool PreferCorridors { get; set; }

		// @property (readwrite, nonatomic) BOOL preferGroundEntrances;
		[Export ("preferGroundEntrances")]
		bool PreferGroundEntrances { get; set; }
	}

	// @interface NMAVenue3dRouteStyleOptions : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAVenue3dRouteStyleOptions
	{
		// @property (readwrite, nonatomic) NMAMapObject * _Nullable startRouteMapObject;
		[NullAllowed, Export ("startRouteMapObject", ArgumentSemantic.Assign)]
		NMAMapObject StartRouteMapObject { get; set; }

		// @property (readwrite, nonatomic) NMAMapObject * _Nullable endRouteMapObject;
		[NullAllowed, Export ("endRouteMapObject", ArgumentSemantic.Assign)]
		NMAMapObject EndRouteMapObject { get; set; }

		// @property (readwrite, nonatomic) NMAMapObject * _Nullable enterCarMapObject;
		[NullAllowed, Export ("enterCarMapObject", ArgumentSemantic.Assign)]
		NMAMapObject EnterCarMapObject { get; set; }

		// @property (readwrite, nonatomic) NMAMapObject * _Nullable leaveCarMapObject;
		[NullAllowed, Export ("leaveCarMapObject", ArgumentSemantic.Assign)]
		NMAMapObject LeaveCarMapObject { get; set; }

		// -(BOOL)setMapObject:(NMAMapObject * _Nullable)mapObject forWaypoint:(NSUInteger)waypointIndex;
		[Export ("setMapObject:forWaypoint:")]
		bool SetMapObject ([NullAllowed] NMAMapObject mapObject, nuint waypointIndex);

		// -(NMAMapObject * _Nullable)mapObjectForWaypoint:(NSUInteger)waypointIndex;
		[Export ("mapObjectForWaypoint:")]
		[return: NullAllowed]
		NMAMapObject MapObjectForWaypoint (nuint waypointIndex);

		// @property (readwrite, nonatomic) CGSize startRouteDefaultIconSize;
		[Export ("startRouteDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize StartRouteDefaultIconSize { get; set; }

		// @property (readwrite, nonatomic) CGSize endRouteDefaultIconSize;
		[Export ("endRouteDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize EndRouteDefaultIconSize { get; set; }

		// @property (readwrite, nonatomic) CGSize enterCarDefaultIconSize;
		[Export ("enterCarDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize EnterCarDefaultIconSize { get; set; }

		// @property (readwrite, nonatomic) CGSize leaveCarDefaultIconSize;
		[Export ("leaveCarDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize LeaveCarDefaultIconSize { get; set; }

		// @property (readwrite, nonatomic) CGSize connectorsDefaultIconSize;
		[Export ("connectorsDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize ConnectorsDefaultIconSize { get; set; }

		// @property (readwrite, nonatomic) CGSize waypointsDefaultIconSize;
		[Export ("waypointsDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize WaypointsDefaultIconSize { get; set; }
	}

	// @interface NMAVenue3dVenueRouteSection : NMAVenue3dRouteSection
	[BaseType (typeof(NMAVenue3dRouteSection))]
	[DisableDefaultCtor]
	interface NMAVenue3dVenueRouteSection
	{
		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export ("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// -(NMAGeoBoundingBox * _Nullable)boundingBox:(NMAVenue3dLevel * _Nonnull)level;
		[Export ("boundingBox:")]
		[return: NullAllowed]
		NMAGeoBoundingBox BoundingBox (NMAVenue3dLevel level);

		// @property (readonly, nonatomic) NMAVenue3dVenue * _Nonnull venue;
		[Export ("venue")]
		NMAVenue3dVenue Venue { get; }

		// @property (readonly, nonatomic) NSArray<NMAVenue3dRouteManeuver *> * _Nonnull routeManeuvers;
		[Export ("routeManeuvers")]
		NMAVenue3dRouteManeuver[] RouteManeuvers { get; }
	}

	// @interface NMAManeuver : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAManeuver
	{
		// @property (readonly, nonatomic) NSUInteger angle;
		[Export ("angle")]
		nuint Angle { get; }

		// @property (readonly, nonatomic, weak) NMAGeoCoordinates * _Nullable coordinates;
		[NullAllowed, Export ("coordinates", ArgumentSemantic.Weak)]
		NMAGeoCoordinates Coordinates { get; }

		// @property (readonly, nonatomic) NMAManeuverAction action;
		[Export ("action")]
		NMAManeuverAction Action { get; }

		// @property (readonly, nonatomic) NMAManeuverTurn turn;
		[Export ("turn")]
		NMAManeuverTurn Turn { get; }

		// @property (readonly, nonatomic) NSUInteger distanceFromStart;
		[Export ("distanceFromStart")]
		nuint DistanceFromStart { get; }

		// @property (readonly, nonatomic) NSUInteger distanceFromPreviousManeuver;
		[Export ("distanceFromPreviousManeuver")]
		nuint DistanceFromPreviousManeuver { get; }

		// @property (readonly, nonatomic) NSUInteger distanceToNextManeuver;
		[Export ("distanceToNextManeuver")]
		nuint DistanceToNextManeuver { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable roadName;
		[NullAllowed, Export ("roadName", ArgumentSemantic.Weak)]
		string RoadName { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable nextRoadName;
		[NullAllowed, Export ("nextRoadName", ArgumentSemantic.Weak)]
		string NextRoadName { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable roadNumber;
		[NullAllowed, Export ("roadNumber", ArgumentSemantic.Weak)]
		string RoadNumber { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable nextRoadNumber;
		[NullAllowed, Export ("nextRoadNumber", ArgumentSemantic.Weak)]
		string NextRoadNumber { get; }

		// @property (readonly, nonatomic) NMAManeuverIcon icon;
		[Export ("icon")]
		NMAManeuverIcon Icon { get; }

		// @property (readonly, nonatomic, weak) NSDate * _Nullable startTime;
		[NullAllowed, Export ("startTime", ArgumentSemantic.Weak)]
		NSDate StartTime { get; }

		// @property (readonly, nonatomic) NSUInteger mapOrientation;
		[Export ("mapOrientation")]
		nuint MapOrientation { get; }

		// @property (readonly, nonatomic) NSArray<NMAGeoCoordinates *> * _Nonnull maneuverGeometry;
		[Export ("maneuverGeometry")]
		NMAGeoCoordinates[] ManeuverGeometry { get; }

		// @property (readonly, nonatomic) NMATransportMode transportMode;
		[Export ("transportMode")]
		NMATransportMode TransportMode { get; }

		// @property (readonly, nonatomic) NMAImage * _Nullable nextRoadIcon;
		[NullAllowed, Export ("nextRoadIcon")]
		NMAImage NextRoadIcon { get; }

		// @property (readonly, nonatomic) NMASignpost * _Nullable signpost;
		[NullAllowed, Export ("signpost")]
		NMASignpost Signpost { get; }

		// @property (readonly, nonatomic) NMAManeuverTrafficDirection trafficDirection;
		[Export ("trafficDirection")]
		NMAManeuverTrafficDirection TrafficDirection { get; }

		// @property (readonly, nonatomic) NSArray<NMARouteElement *> * _Nonnull routeElements;
		[Export ("routeElements")]
		NMARouteElement[] RouteElements { get; }
	}

	// @interface NMAVenue3dRouteManeuver : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dRouteManeuver
	{
		// @property (readonly, nonatomic) NMAVenue3dRouteManeuver * _Nullable targetManeuver;
		[NullAllowed, Export ("targetManeuver")]
		NMAVenue3dRouteManeuver TargetManeuver { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export ("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readwrite, nonatomic) NMAVenue3dRouteActionType routeActionType;
		[Export ("routeActionType", ArgumentSemantic.Assign)]
		NMAVenue3dRouteActionType RouteActionType { get; set; }

		// @property (readonly, nonatomic) NMAVenue3dRouteLevelChangeType levelChangeType;
		[Export ("levelChangeType")]
		NMAVenue3dRouteLevelChangeType LevelChangeType { get; }

		// @property (readonly, nonatomic) NMAManeuverTurn turn;
		[Export ("turn")]
		NMAManeuverTurn Turn { get; }

		// @property (readwrite, nonatomic) NMAVenue3dRouteConnectorType routeConnectorType;
		[Export ("routeConnectorType", ArgumentSemantic.Assign)]
		NMAVenue3dRouteConnectorType RouteConnectorType { get; set; }

		// @property (readwrite, nonatomic) NMAVenue3dSpace * _Nullable space;
		[NullAllowed, Export ("space", ArgumentSemantic.Assign)]
		NMAVenue3dSpace Space { get; set; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull geoCoordinates;
		[Export ("geoCoordinates")]
		NMAGeoCoordinates GeoCoordinates { get; }

		// @property (readonly, nonatomic) NSArray<NMAGeoCoordinates *> * _Nonnull geometry;
		[Export ("geometry")]
		NMAGeoCoordinates[] Geometry { get; }

		// @property (readonly, nonatomic) float distanceFromStart;
		[Export ("distanceFromStart")]
		float DistanceFromStart { get; }

		// @property (readonly, nonatomic) float distanceFromPreviousManeuver;
		[Export ("distanceFromPreviousManeuver")]
		float DistanceFromPreviousManeuver { get; }

		// @property (readonly, nonatomic) float distanceToNextManeuver;
		[Export ("distanceToNextManeuver")]
		float DistanceToNextManeuver { get; }

		// @property (readonly, nonatomic) NSInteger floorIndex;
		[Export ("floorIndex")]
		nint FloorIndex { get; }

		// @property (readonly, nonatomic) NSInteger angle;
		[Export ("angle")]
		nint Angle { get; }

		// @property (readonly, nonatomic) NSInteger mapOrientation;
		[Export ("mapOrientation")]
		nint MapOrientation { get; }

		// +(float)naturalGuidanceRadius;
		// +(void)setNaturalGuidanceRadius:(float)radius;
		[Static]
		[Export ("naturalGuidanceRadius")]
		[Verify (MethodToProperty)]
		float NaturalGuidanceRadius { get; set; }

		// +(NSSet<NSString *> * _Nonnull)naturalGuidanceBlacklist;
		[Static]
		[Export ("naturalGuidanceBlacklist")]
		NSSet<NSString> NaturalGuidanceBlacklist ();

		// +(void)addCategoryToNaturalGuidanceBlacklist:(NSString * _Nonnull)categoryId;
		[Static]
		[Export ("addCategoryToNaturalGuidanceBlacklist:")]
		void AddCategoryToNaturalGuidanceBlacklist (string categoryId);

		// +(void)removeCategoryFromNaturalGuidanceBlacklist:(NSString * _Nonnull)categoryId;
		[Static]
		[Export ("removeCategoryFromNaturalGuidanceBlacklist:")]
		void RemoveCategoryFromNaturalGuidanceBlacklist (string categoryId);

		// @property (readonly, nonatomic) NSString * _Nonnull naturalGuidancePOI;
		[Export ("naturalGuidancePOI")]
		string NaturalGuidancePOI { get; }

		// -(NMAMapObject * _Nullable)mapObject;
		[Export ("mapObject")]
		[return: NullAllowed]
		NMAMapObject MapObject ();

		// -(BOOL)setMapObject:(NMAMapObject * _Nullable)mapObject;
		[Export ("setMapObject:")]
		bool SetMapObject ([NullAllowed] NMAMapObject mapObject);
	}

	// @interface NMAVenue3dLinkRouteSection : NMAVenue3dRouteSection
	[BaseType (typeof(NMAVenue3dRouteSection))]
	[DisableDefaultCtor]
	interface NMAVenue3dLinkRouteSection
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull from;
		[Export ("from")]
		NMAGeoCoordinates From { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull to;
		[Export ("to")]
		NMAGeoCoordinates To { get; }
	}

	// @interface NMAVenue3dOutdoorRouteSection : NMAVenue3dRouteSection
	[BaseType (typeof(NMAVenue3dRouteSection))]
	[DisableDefaultCtor]
	interface NMAVenue3dOutdoorRouteSection
	{
		// @property (readonly, nonatomic) NMARoute * _Nonnull route;
		[Export ("route")]
		NMARoute Route { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export ("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }
	}

	// @interface NMAGeoPolygon : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAGeoPolygon
	{
		// -(instancetype _Nonnull)initWithCoordinates:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Export ("initWithCoordinates:")]
		IntPtr Constructor (NMAGeoCoordinates[] coordinates);

		// -(void)addPoint:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export ("addPoint:")]
		void AddPoint (NMAGeoCoordinates coordinate);

		// -(void)addPoints:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Export ("addPoints:")]
		void AddPoints (NMAGeoCoordinates[] coordinates);

		// -(void)insertPoint:(NMAGeoCoordinates * _Nonnull)coordinate atIndex:(int)index;
		[Export ("insertPoint:atIndex:")]
		void InsertPoint (NMAGeoCoordinates coordinate, int index);

		// -(void)removePointAtIndex:(int)index;
		[Export ("removePointAtIndex:")]
		void RemovePointAtIndex (int index);

		// -(void)clear;
		[Export ("clear")]
		void Clear ();

		// -(int)numberOfPoints;
		[Export ("numberOfPoints")]
		[Verify (MethodToProperty)]
		int NumberOfPoints { get; }

		// -(NMAGeoCoordinates * _Nullable)pointAtIndex:(int)index;
		[Export ("pointAtIndex:")]
		[return: NullAllowed]
		NMAGeoCoordinates PointAtIndex (int index);

		// -(NSArray<NMAGeoCoordinates *> * _Nonnull)allPoints;
		[Export ("allPoints")]
		[Verify (MethodToProperty)]
		NMAGeoCoordinates[] AllPoints { get; }

		// -(double)length;
		[Export ("length")]
		[Verify (MethodToProperty)]
		double Length { get; }

		// -(NMAGeoCoordinates * _Nullable)nearestCoordinateFrom:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export ("nearestCoordinateFrom:")]
		[return: NullAllowed]
		NMAGeoCoordinates NearestCoordinateFrom (NMAGeoCoordinates coordinate);

		// -(NSUInteger)nearestIndexFromCoordinate:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export ("nearestIndexFromCoordinate:")]
		nuint NearestIndexFromCoordinate (NMAGeoCoordinates coordinate);

		// -(NMAGeoPolygon * _Nonnull)sortedPolygon;
		[Export ("sortedPolygon")]
		[Verify (MethodToProperty)]
		NMAGeoPolygon SortedPolygon { get; }

		// -(NMAGeoBoundingBox * _Nullable)geoBoundingBox;
		[NullAllowed, Export ("geoBoundingBox")]
		[Verify (MethodToProperty)]
		NMAGeoBoundingBox GeoBoundingBox { get; }
	}

	// @interface NMAClusterTheme : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAClusterTheme
	{
		// +(instancetype _Nonnull)clusterTheme;
		[Static]
		[Export ("clusterTheme")]
		NMAClusterTheme ClusterTheme ();

		// -(BOOL)setStyle:(NMAClusterStyle * _Nonnull)style forDensityRange:(NSRange)range;
		[Export ("setStyle:forDensityRange:")]
		bool SetStyle (NMAClusterStyle style, NSRange range);
	}

	// @interface NMATrafficSign : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATrafficSign
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull coordinate;
		[Export ("coordinate")]
		NMAGeoCoordinates Coordinate { get; }

		// @property (readonly, assign, nonatomic) NSUInteger type;
		[Export ("type")]
		nuint Type { get; }

		// @property (readonly, assign, nonatomic) NMASignCategory category;
		[Export ("category", ArgumentSemantic.Assign)]
		NMASignCategory Category { get; }

		// @property (readonly, assign, nonatomic) NMASignSubcategory subcategory;
		[Export ("subcategory", ArgumentSemantic.Assign)]
		NMASignSubcategory Subcategory { get; }

		// @property (readonly, assign, nonatomic) NMASignLocation location;
		[Export ("location", ArgumentSemantic.Assign)]
		NMASignLocation Location { get; }

		// @property (readonly, assign, nonatomic) NMASignDirection direction;
		[Export ("direction", ArgumentSemantic.Assign)]
		NMASignDirection Direction { get; }

		// @property (readonly, assign, nonatomic) NSUInteger subtype;
		[Export ("subtype")]
		nuint Subtype { get; }

		// @property (readonly, nonatomic) NSSet<NSNumber *> * _Nonnull applicableForTransportTypes;
		[Export ("applicableForTransportTypes")]
		NSSet<NSNumber> ApplicableForTransportTypes { get; }

		// @property (readonly, assign, nonatomic) NMASignWeatherAffects weatherAffects;
		[Export ("weatherAffects", ArgumentSemantic.Assign)]
		NMASignWeatherAffects WeatherAffects { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull signValue;
		[Export ("signValue")]
		string SignValue { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull duration;
		[Export ("duration")]
		string Duration { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull prewarning;
		[Export ("prewarning")]
		string Prewarning { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull validityTime;
		[Export ("validityTime")]
		string ValidityTime { get; }
	}

	// @interface NMAClusterStyle : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAClusterStyle
	{
	}

	// @interface NMARouteElement : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARouteElement
	{
		// @property (readonly, nonatomic) NMARouteElementType type;
		[Export ("type")]
		NMARouteElementType Type { get; }

		// @property (readonly, nonatomic) NMARoadElement * _Nullable roadElement;
		[NullAllowed, Export ("roadElement")]
		NMARoadElement RoadElement { get; }

		// @property (readonly, nonatomic) NMATransitRouteElement * _Nullable transitRouteElement;
		[NullAllowed, Export ("transitRouteElement")]
		NMATransitRouteElement TransitRouteElement { get; }

		// @property (readonly, nonatomic) NSArray<NMAGeoCoordinates *> * _Nonnull geometry;
		[Export ("geometry")]
		NMAGeoCoordinates[] Geometry { get; }

		// @property (readonly, nonatomic) NMATravelDirection travelDirection;
		[Export ("travelDirection")]
		NMATravelDirection TravelDirection { get; }
	}

	// @interface NMARouteTta : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARouteTta
	{
		// @property (readonly, nonatomic) NSTimeInterval duration;
		[Export ("duration")]
		double Duration { get; }

		// @property (readonly, nonatomic) NMARouteDurationDetail details;
		[Export ("details")]
		NMARouteDurationDetail Details { get; }

		// @property (readonly, getter = isBlocked, nonatomic) BOOL blocked;
		[Export ("blocked")]
		bool Blocked { [Bind ("isBlocked")] get; }
	}

	// @interface NMADynamicPenalty : NSObject
	[BaseType (typeof(NSObject))]
	interface NMADynamicPenalty
	{
		// -(BOOL)addBannedArea:(NMAMapPolygon * _Nonnull)area;
		[Export ("addBannedArea:")]
		bool AddBannedArea (NMAMapPolygon area);

		// -(BOOL)removeBannedArea:(NMAMapPolygon * _Nonnull)area;
		[Export ("removeBannedArea:")]
		bool RemoveBannedArea (NMAMapPolygon area);

		// -(void)removeAllAreaPenalties;
		[Export ("removeAllAreaPenalties")]
		void RemoveAllAreaPenalties ();

		// -(BOOL)addPenaltyForRoadElement:(NMARoadElement * _Nonnull)element withDrivingDirection:(NMADrivingDirection)direction speed:(NSUInteger)newSpeed;
		[Export ("addPenaltyForRoadElement:withDrivingDirection:speed:")]
		bool AddPenaltyForRoadElement (NMARoadElement element, NMADrivingDirection direction, nuint newSpeed);

		// -(BOOL)removePenaltyForRoadElement:(NMARoadElement * _Nonnull)element;
		[Export ("removePenaltyForRoadElement:")]
		bool RemovePenaltyForRoadElement (NMARoadElement element);

		// -(void)removeAllRoadElementPenalties;
		[Export ("removeAllRoadElementPenalties")]
		void RemoveAllRoadElementPenalties ();

		// @property (nonatomic) NMATrafficPenaltyMode trafficPenaltyMode;
		[Export ("trafficPenaltyMode", ArgumentSemantic.Assign)]
		NMATrafficPenaltyMode TrafficPenaltyMode { get; set; }
	}

	[Static]
	[Verify (ConstantsInterfaceAssociation)]
	partial interface Constants
	{
		// extern const NSInteger NMARouteSublegWhole;
		[Field ("NMARouteSublegWhole", "__Internal")]
		nint NMARouteSublegWhole { get; }
	}

	// typedef void (^NMARouteSerializationCompletionBlock)(NSData * _Nullable, NSError * _Nullable);
	delegate void NMARouteSerializationCompletionBlock ([NullAllowed] NSData arg0, [NullAllowed] NSError arg1);

	// typedef void (^NMARouteDeserializationCompletionBlock)(NMARoute * _Nullable, NSError * _Nullable);
	delegate void NMARouteDeserializationCompletionBlock ([NullAllowed] NMARoute arg0, [NullAllowed] NSError arg1);

	// @interface NMARoute : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARoute
	{
		// +(void)routeFromSerializedRoute:(NSData * _Nonnull)data withCompletion:(NMARouteDeserializationCompletionBlock _Nonnull)completionBlock;
		[Static]
		[Export ("routeFromSerializedRoute:withCompletion:")]
		void RouteFromSerializedRoute (NSData data, NMARouteDeserializationCompletionBlock completionBlock);

		// @property (readonly, nonatomic, weak) NMAWaypoint * _Nullable start;
		[NullAllowed, Export ("start", ArgumentSemantic.Weak)]
		NMAWaypoint Start { get; }

		// @property (readonly, nonatomic, weak) NMAWaypoint * _Nullable destination;
		[NullAllowed, Export ("destination", ArgumentSemantic.Weak)]
		NMAWaypoint Destination { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAWaypoint *> * _Nullable waypoints;
		[NullAllowed, Export ("waypoints", ArgumentSemantic.Strong)]
		NMAWaypoint[] Waypoints { get; }

		// @property (readonly, nonatomic) NSArray<NSNumber *> * _Nonnull permanentLinkIds;
		[Export ("permanentLinkIds")]
		NSNumber[] PermanentLinkIds { get; }

		// @property (readonly, nonatomic) NSArray<NSNumber *> * _Nonnull permanentDirectedLinkIds;
		[Export ("permanentDirectedLinkIds")]
		NSNumber[] PermanentDirectedLinkIds { get; }

		// @property (readonly, nonatomic) NSUInteger length;
		[Export ("length")]
		nuint Length { get; }

		// -(NSUInteger)lengthForSubleg:(NSUInteger)subleg;
		[Export ("lengthForSubleg:")]
		nuint LengthForSubleg (nuint subleg);

		// @property (readonly, nonatomic) NSUInteger sublegCount;
		[Export ("sublegCount")]
		nuint SublegCount { get; }

		// -(NMARouteConsumption * _Nullable)consumptionWithParameters:(NMARouteConsumptionParameters * _Nonnull)consumptionParameters dynamicPenalty:(NMADynamicPenalty * _Nullable)dynamicPenalty;
		[Export ("consumptionWithParameters:dynamicPenalty:")]
		[return: NullAllowed]
		NMARouteConsumption ConsumptionWithParameters (NMARouteConsumptionParameters consumptionParameters, [NullAllowed] NMADynamicPenalty dynamicPenalty);

		// -(NMAGeoCoordinates * _Nullable)lastReachablePositionWithConsumption:(NMARouteConsumption * _Nonnull)routeConsumption currentCapacity:(NSInteger)capacity;
		[Export ("lastReachablePositionWithConsumption:currentCapacity:")]
		[return: NullAllowed]
		NMAGeoCoordinates LastReachablePositionWithConsumption (NMARouteConsumption routeConsumption, nint capacity);

		// @property (readonly, nonatomic, strong) NMAGeoBoundingBox * _Nullable boundingBox;
		[NullAllowed, Export ("boundingBox", ArgumentSemantic.Strong)]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAManeuver *> * _Nullable maneuvers;
		[NullAllowed, Export ("maneuvers", ArgumentSemantic.Strong)]
		NMAManeuver[] Maneuvers { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAGeoCoordinates *> * _Nullable geometry;
		[NullAllowed, Export ("geometry", ArgumentSemantic.Strong)]
		NMAGeoCoordinates[] Geometry { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAGeoCoordinates *> * _Nullable geometryWithElevationData;
		[NullAllowed, Export ("geometryWithElevationData", ArgumentSemantic.Strong)]
		NMAGeoCoordinates[] GeometryWithElevationData { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMARouteElement *> * _Nullable routeElements;
		[NullAllowed, Export ("routeElements", ArgumentSemantic.Strong)]
		NMARouteElement[] RouteElements { get; }

		// @property (readonly, nonatomic, strong) NMARoutingMode * _Nonnull routingMode;
		[Export ("routingMode", ArgumentSemantic.Strong)]
		NMARoutingMode RoutingMode { get; }

		// @property (nonatomic, strong) NSString * _Nullable userTag;
		[NullAllowed, Export ("userTag", ArgumentSemantic.Strong)]
		string UserTag { get; set; }

		// -(NMARouteTta * _Nullable)ttaIncludingTrafficForSubleg:(NSUInteger)subleg;
		[Export ("ttaIncludingTrafficForSubleg:")]
		[return: NullAllowed]
		NMARouteTta TtaIncludingTrafficForSubleg (nuint subleg);

		// -(NMARouteTta * _Nullable)ttaUsingDownloadedTrafficForSubleg:(NSUInteger)subleg;
		[Export ("ttaUsingDownloadedTrafficForSubleg:")]
		[return: NullAllowed]
		NMARouteTta TtaUsingDownloadedTrafficForSubleg (nuint subleg);

		// -(NMARouteTta * _Nullable)ttaExcludingTrafficForSubleg:(NSUInteger)subleg;
		[Export ("ttaExcludingTrafficForSubleg:")]
		[return: NullAllowed]
		NMARouteTta TtaExcludingTrafficForSubleg (nuint subleg);

		// -(void)serializedRouteWithCompletionBlock:(NMARouteSerializationCompletionBlock _Nonnull)completionBlock;
		[Export ("serializedRouteWithCompletionBlock:")]
		void SerializedRouteWithCompletionBlock (NMARouteSerializationCompletionBlock completionBlock);

		// -(NSArray<NMARouteElement *> * _Nullable)routeElementsFromManeuver:(NMAManeuver * _Nonnull)maneuver error:(NSError * _Nullable * _Nullable)error;
		[Export ("routeElementsFromManeuver:error:")]
		[return: NullAllowed]
		NMARouteElement[] RouteElementsFromManeuver (NMAManeuver maneuver, [NullAllowed] out NSError error);

		// -(NSArray<NMARouteElement *> * _Nullable)routeElementsFromDuration:(NSTimeInterval)duration error:(NSError * _Nullable * _Nullable)error;
		[Export ("routeElementsFromDuration:error:")]
		[return: NullAllowed]
		NMARouteElement[] RouteElementsFromDuration (double duration, [NullAllowed] out NSError error);

		// -(NSArray<NMARouteElement *> * _Nullable)routeElementsFromStartTime:(NSTimeInterval)startTime duration:(NSTimeInterval)duration error:(NSError * _Nullable * _Nullable)error;
		[Export ("routeElementsFromStartTime:duration:error:")]
		[return: NullAllowed]
		NMARouteElement[] RouteElementsFromStartTime (double startTime, double duration, [NullAllowed] out NSError error);

		// -(NSArray<NMARouteElement *> * _Nullable)routeElementsFromLength:(NSUInteger)length error:(NSError * _Nullable * _Nullable)error;
		[Export ("routeElementsFromLength:error:")]
		[return: NullAllowed]
		NMARouteElement[] RouteElementsFromLength (nuint length, [NullAllowed] out NSError error);

		// -(NSArray<NMARouteElement *> * _Nullable)routeElementsFromStartDistance:(NSUInteger)startDistance length:(NSUInteger)length error:(NSError * _Nullable * _Nullable)error;
		[Export ("routeElementsFromStartDistance:length:error:")]
		[return: NullAllowed]
		NMARouteElement[] RouteElementsFromStartDistance (nuint startDistance, nuint length, [NullAllowed] out NSError error);

		// -(NSUInteger)distanceFromRouteElement:(NSUInteger)fromRouteElement fromPosition:(NMAGeoCoordinates * _Nonnull)fromPosition toRouteElement:(NSUInteger)toRouteElement toPosition:(NMAGeoCoordinates * _Nonnull)toPosition;
		[Export ("distanceFromRouteElement:fromPosition:toRouteElement:toPosition:")]
		nuint DistanceFromRouteElement (nuint fromRouteElement, NMAGeoCoordinates fromPosition, nuint toRouteElement, NMAGeoCoordinates toPosition);

		// @property (readonly, nonatomic) NSArray<NMARoutingZone *> * _Nonnull routingZones;
		[Export ("routingZones")]
		NMARoutingZone[] RoutingZones { get; }

		// -(NSArray<NSString *> * _Nonnull)instructionsForLanguage:(NSString * _Nonnull)language unitSystem:(NMARouteInstructionsUnitSystem)unitSystem;
		[Export ("instructionsForLanguage:unitSystem:")]
		string[] InstructionsForLanguage (string language, NMARouteInstructionsUnitSystem unitSystem);
	}

	// @interface NMARouteConsumption : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARouteConsumption
	{
		// -(NSInteger)getConsumptionWithIndex:(NSUInteger)index;
		[Export ("getConsumptionWithIndex:")]
		nint GetConsumptionWithIndex (nuint index);

		// -(NSUInteger)firstAvailableConsumptionIndex;
		[Export ("firstAvailableConsumptionIndex")]
		[Verify (MethodToProperty)]
		nuint FirstAvailableConsumptionIndex { get; }
	}

	// @interface NMARouteConsumptionParameters : NSObject
	[BaseType (typeof(NSObject))]
	interface NMARouteConsumptionParameters
	{
		// @property (assign, nonatomic) double ascentMultiplier;
		[Export ("ascentMultiplier")]
		double AscentMultiplier { get; set; }

		// @property (assign, nonatomic) double descentMutiplier;
		[Export ("descentMutiplier")]
		double DescentMutiplier { get; set; }

		// @property (assign, nonatomic) double turnTimeMultiplier;
		[Export ("turnTimeMultiplier")]
		double TurnTimeMultiplier { get; set; }

		// @property (assign, nonatomic) double accelerationMultiplier;
		[Export ("accelerationMultiplier")]
		double AccelerationMultiplier { get; set; }

		// @property (assign, nonatomic) double decelartionMultiplier;
		[Export ("decelartionMultiplier")]
		double DecelartionMultiplier { get; set; }

		// @property (assign, nonatomic) double auxiliaryConsumption;
		[Export ("auxiliaryConsumption")]
		double AuxiliaryConsumption { get; set; }

		// @property (nonatomic) NSDictionary<NSNumber *,NSNumber *> * _Nonnull consumptionSpeed;
		[Export ("consumptionSpeed", ArgumentSemantic.Assign)]
		NSDictionary<NSNumber, NSNumber> ConsumptionSpeed { get; set; }

		// @property (getter = isHighSpeedConsumptionEnabled, assign, nonatomic) BOOL highSpeedConsumptionEnabled;
		[Export ("highSpeedConsumptionEnabled")]
		bool HighSpeedConsumptionEnabled { [Bind ("isHighSpeedConsumptionEnabled")] get; set; }

		// @property (assign, nonatomic) NSUInteger highSpeedConsumptionThresholdKmh;
		[Export ("highSpeedConsumptionThresholdKmh")]
		nuint HighSpeedConsumptionThresholdKmh { get; set; }

		// @property (nonatomic) NSDictionary<NSNumber *,NSNumber *> * _Nonnull trafficSpeed;
		[Export ("trafficSpeed", ArgumentSemantic.Assign)]
		NSDictionary<NSNumber, NSNumber> TrafficSpeed { get; set; }

		// @property (nonatomic) NSDictionary<NSNumber *,NSNumber *> * _Nonnull trafficScales;
		[Export ("trafficScales", ArgumentSemantic.Assign)]
		NSDictionary<NSNumber, NSNumber> TrafficScales { get; set; }
	}

	[Static]
	[Verify (ConstantsInterfaceAssociation)]
	partial interface Constants
	{
		// extern const CGFloat NMAUnknownWaypointCourse;
		[Field ("NMAUnknownWaypointCourse", "__Internal")]
		nfloat NMAUnknownWaypointCourse { get; }
	}

	// @interface NMAWaypoint : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAWaypoint
	{
		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)position;
		[Export ("initWithGeoCoordinates:")]
		IntPtr Constructor (NMAGeoCoordinates position);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)position waypointType:(NMAWaypointType)type;
		[Export ("initWithGeoCoordinates:waypointType:")]
		IntPtr Constructor (NMAGeoCoordinates position, NMAWaypointType type);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)position identifier:(NSString * _Nonnull)uniqueId waypointDirection:(NMAWaypointDirection)direction waypointType:(NMAWaypointType)type;
		[Export ("initWithGeoCoordinates:identifier:waypointDirection:waypointType:")]
		IntPtr Constructor (NMAGeoCoordinates position, string uniqueId, NMAWaypointDirection direction, NMAWaypointType type);

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull originalPosition;
		[Export ("originalPosition", ArgumentSemantic.Assign)]
		NMAGeoCoordinates OriginalPosition { get; set; }

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull navigablePosition;
		[Export ("navigablePosition", ArgumentSemantic.Assign)]
		NMAGeoCoordinates NavigablePosition { get; set; }

		// @property (readonly, nonatomic) NSString * _Nonnull identifier;
		[Export ("identifier")]
		string Identifier { get; }

		// @property (readonly, nonatomic) NMAWaypointDirection waypointDirection;
		[Export ("waypointDirection")]
		NMAWaypointDirection WaypointDirection { get; }

		// -(void)setIdentifier:(NSString * _Nonnull)identifier waypointDirection:(NMAWaypointDirection)direction;
		[Export ("setIdentifier:waypointDirection:")]
		void SetIdentifier (string identifier, NMAWaypointDirection direction);

		// @property (nonatomic) CGFloat course;
		[Export ("course")]
		nfloat Course { get; set; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable mappedPosition;
		[NullAllowed, Export ("mappedPosition")]
		NMAGeoCoordinates MappedPosition { get; }

		// @property (readonly, nonatomic) NMAWaypointRoadInfo * _Nullable roadInfo;
		[NullAllowed, Export ("roadInfo")]
		NMAWaypointRoadInfo RoadInfo { get; }

		// @property (nonatomic) NMAWaypointType waypointType;
		[Export ("waypointType", ArgumentSemantic.Assign)]
		NMAWaypointType WaypointType { get; set; }

		// @property (nonatomic) NSInteger waitingTime;
		[Export ("waitingTime")]
		nint WaitingTime { get; set; }

		// @property (nonatomic) NSInteger fuzzyMatchingRadius;
		[Export ("fuzzyMatchingRadius")]
		nint FuzzyMatchingRadius { get; set; }

		// @property (nonatomic) NSInteger junctionSnappingRadius;
		[Export ("junctionSnappingRadius")]
		nint JunctionSnappingRadius { get; set; }

		// @property (nonatomic) NSInteger selectiveMatchingRadius;
		[Export ("selectiveMatchingRadius")]
		nint SelectiveMatchingRadius { get; set; }

		// -(void)setStreetNameHint:(NSString * _Nonnull)hint;
		[Export ("setStreetNameHint:")]
		void SetStreetNameHint (string hint);
	}

	// @interface NMAMapPolygon : NMAMapObject
	[BaseType (typeof(NMAMapObject))]
	interface NMAMapPolygon
	{
		// +(instancetype _Nonnull)mapPolygonWithVertices:(NSArray<NMAGeoCoordinates *> * _Nonnull)vertices;
		[Static]
		[Export ("mapPolygonWithVertices:")]
		NMAMapPolygon MapPolygonWithVertices (NMAGeoCoordinates[] vertices);

		// @property (nonatomic, strong) UIColor * _Nonnull fillColor;
		[Export ("fillColor", ArgumentSemantic.Strong)]
		UIColor FillColor { get; set; }

		// @property (readonly, nonatomic, weak) NSArray<NMAGeoCoordinates *> * _Nullable vertices;
		[NullAllowed, Export ("vertices", ArgumentSemantic.Weak)]
		NMAGeoCoordinates[] Vertices { get; }

		// @property (nonatomic, strong) UIColor * _Nonnull lineColor;
		[Export ("lineColor", ArgumentSemantic.Strong)]
		UIColor LineColor { get; set; }

		// @property (nonatomic) NSUInteger lineWidth;
		[Export ("lineWidth")]
		nuint LineWidth { get; set; }

		// @property (getter = isDashed, nonatomic) BOOL dashed;
		[Export ("dashed")]
		bool Dashed { [Bind ("isDashed")] get; set; }

		// @property (nonatomic) NSUInteger dashPrimaryLength;
		[Export ("dashPrimaryLength")]
		nuint DashPrimaryLength { get; set; }

		// @property (nonatomic) NSUInteger dashSecondaryLength;
		[Export ("dashSecondaryLength")]
		nuint DashSecondaryLength { get; set; }

		// @property (nonatomic) BOOL depthTestEnabled;
		[Export ("depthTestEnabled")]
		bool DepthTestEnabled { get; set; }

		// -(instancetype _Nonnull)initWithPolygon:(NMAGeoPolygon * _Nonnull)geoPolygon;
		[Export ("initWithPolygon:")]
		IntPtr Constructor (NMAGeoPolygon geoPolygon);

		// @property (readonly, nonatomic) NMAGeoPolygon * _Nonnull geoPolygon;
		[Export ("geoPolygon")]
		NMAGeoPolygon GeoPolygon { get; }

		// -(instancetype _Nonnull)initWithVertices:(NSArray<NMAGeoCoordinates *> * _Nonnull)vertices __attribute__((objc_designated_initializer));
		[Export ("initWithVertices:")]
		[DesignatedInitializer]
		IntPtr Constructor (NMAGeoCoordinates[] vertices);

		// -(void)clearVertices;
		[Export ("clearVertices")]
		void ClearVertices ();

		// -(void)addVertex:(NMAGeoCoordinates * _Nonnull)vertex atIndex:(NSUInteger)index;
		[Export ("addVertex:atIndex:")]
		void AddVertex (NMAGeoCoordinates vertex, nuint index);

		// -(void)appendVertex:(NMAGeoCoordinates * _Nonnull)vertex;
		[Export ("appendVertex:")]
		void AppendVertex (NMAGeoCoordinates vertex);

		// -(void)removeLastVertex;
		[Export ("removeLastVertex")]
		void RemoveLastVertex ();

		// -(void)removeVertexAtIndex:(NSUInteger)index;
		[Export ("removeVertexAtIndex:")]
		void RemoveVertexAtIndex (nuint index);

		// -(BOOL)isValid;
		[Export ("isValid")]
		[Verify (MethodToProperty)]
		bool IsValid { get; }

		// -(BOOL)containsGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export ("containsGeoCoordinates:")]
		bool ContainsGeoCoordinates (NMAGeoCoordinates coordinates);

		// @property (assign, nonatomic) NMAPatternStyle patternStyle;
		[Export ("patternStyle", ArgumentSemantic.Assign)]
		NMAPatternStyle PatternStyle { get; set; }

		// @property (readwrite, nonatomic) NMAImage * _Nullable customPattern;
		[NullAllowed, Export ("customPattern", ArgumentSemantic.Assign)]
		NMAImage CustomPattern { get; set; }
	}

	// @interface NMARoutingZoneRestriction : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARoutingZoneRestriction
	{
		// @property (readonly, nonatomic) NSDate * _Nullable timeBegin;
		[NullAllowed, Export ("timeBegin")]
		NSDate TimeBegin { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable timeEnd;
		[NullAllowed, Export ("timeEnd")]
		NSDate TimeEnd { get; }

		// @property (readonly, nonatomic) NSString * _Nullable licensePlateLastDigits;
		[NullAllowed, Export ("licensePlateLastDigits")]
		string LicensePlateLastDigits { get; }

		// @property (readonly, nonatomic) NSSet<NSNumber *> * _Nonnull transportTypes;
		[Export ("transportTypes")]
		NSSet<NSNumber> TransportTypes { get; }
	}

	// @interface NMARoutingZone : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARoutingZone
	{
		// @property (readonly, nonatomic) NSString * _Nonnull identifier;
		[Export ("identifier")]
		string Identifier { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull name;
		[Export ("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NSArray<NMARoutingZoneRestriction *> * _Nonnull restrictions;
		[Export ("restrictions")]
		NMARoutingZoneRestriction[] Restrictions { get; }

		// @property (readonly, nonatomic) NMARoutingZoneType type;
		[Export ("type")]
		NMARoutingZoneType Type { get; }
	}

	// @interface NMAWaypointRoadInfo : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAWaypointRoadInfo
	{
		// @property (readonly, nonatomic) NMARoadSide roadSide;
		[Export ("roadSide")]
		NMARoadSide RoadSide { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable matchedCoordinates;
		[NullAllowed, Export ("matchedCoordinates")]
		NMAGeoCoordinates MatchedCoordinates { get; }
	}

	// @interface NMAZoomRange : NSObject
	[BaseType (typeof(NSObject))]
	interface NMAZoomRange
	{
		// @property (nonatomic) float min;
		[Export ("min")]
		float Min { get; set; }

		// @property (nonatomic) float max;
		[Export ("max")]
		float Max { get; set; }

		// -(instancetype _Nonnull)initWithMinZoomLevel:(float)minimum maxZoomLevel:(float)maximum;
		[Export ("initWithMinZoomLevel:maxZoomLevel:")]
		IntPtr Constructor (float minimum, float maximum);
	}

	// @interface NMACustomizableVariable : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMACustomizableVariable
	{
		// @property (nonatomic, strong) NSString * _Nonnull variableName;
		[Export ("variableName", ArgumentSemantic.Strong)]
		string VariableName { get; set; }

		// @property (readonly, nonatomic) NMACustomizablePropertyType propertyType;
		[Export ("propertyType")]
		NMACustomizablePropertyType PropertyType { get; }

		// @property (readonly, nonatomic) NSInteger propertyIdentifier;
		[Export ("propertyIdentifier")]
		nint PropertyIdentifier { get; }

		// +(NSDictionary<NSString *,NMACustomizableVariable *> * _Nonnull)allAvailableProperties;
		[Static]
		[Export ("allAvailableProperties")]
		[Verify (MethodToProperty)]
		NSDictionary<NSString, NMACustomizableVariable> AllAvailableProperties { get; }
	}

	// @interface NMACustomizableColor : NMACustomizableVariable
	[BaseType (typeof(NMACustomizableVariable))]
	[DisableDefaultCtor]
	interface NMACustomizableColor
	{
		// -(instancetype _Nonnull)initWithColorProperty:(NMASchemeColorProperty)property andZoomLevel:(float)zoomLevel andZoomRange:(NMAZoomRange * _Nullable)zoomRange;
		[Export ("initWithColorProperty:andZoomLevel:andZoomRange:")]
		IntPtr Constructor (NMASchemeColorProperty property, float zoomLevel, [NullAllowed] NMAZoomRange zoomRange);

		// @property (nonatomic) NSInteger red;
		[Export ("red")]
		nint Red { get; set; }

		// @property (nonatomic) NSInteger green;
		[Export ("green")]
		nint Green { get; set; }

		// @property (nonatomic) NSInteger blue;
		[Export ("blue")]
		nint Blue { get; set; }

		// @property (nonatomic) NSInteger alpha;
		[Export ("alpha")]
		nint Alpha { get; set; }

		// -(UIColor * _Nonnull)color;
		// -(void)setColor:(UIColor * _Nonnull)color;
		[Export ("color")]
		[Verify (MethodToProperty)]
		UIColor Color { get; set; }
	}

	// @interface NMACustomizableScheme : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMACustomizableScheme
	{
		// -(NMACustomizableColor * _Nullable)colorForProperty:(NMASchemeColorProperty)colorProperty forZoomLevel:(float)zoomLevel;
		[Export ("colorForProperty:forZoomLevel:")]
		[return: NullAllowed]
		NMACustomizableColor ColorForProperty (NMASchemeColorProperty colorProperty, float zoomLevel);

		// -(void)setColorProperty:(NMACustomizableColor * _Nonnull)variableColor forZoomRange:(NMAZoomRange * _Nonnull)zoomRange;
		[Export ("setColorProperty:forZoomRange:")]
		void SetColorProperty (NMACustomizableColor variableColor, NMAZoomRange zoomRange);

		// -(int)integerForProperty:(NMASchemeIntegerProperty)integerProperty forZoomLevel:(float)zoomLevel;
		[Export ("integerForProperty:forZoomLevel:")]
		int IntegerForProperty (NMASchemeIntegerProperty integerProperty, float zoomLevel);

		// -(void)setIntegerProperty:(NMASchemeIntegerProperty)integerProperty withValue:(int)value forZoomRange:(NMAZoomRange * _Nonnull)zoomRange;
		[Export ("setIntegerProperty:withValue:forZoomRange:")]
		void SetIntegerProperty (NMASchemeIntegerProperty integerProperty, int value, NMAZoomRange zoomRange);

		// -(BOOL)booleanForProperty:(NMASchemeBooleanProperty)booleanProperty forZoomLevel:(float)zoomLevel;
		[Export ("booleanForProperty:forZoomLevel:")]
		bool BooleanForProperty (NMASchemeBooleanProperty booleanProperty, float zoomLevel);

		// -(void)setBooleanProperty:(NMASchemeBooleanProperty)booleanProperty withValue:(BOOL)value forZoomRange:(NMAZoomRange * _Nonnull)zoomRange;
		[Export ("setBooleanProperty:withValue:forZoomRange:")]
		void SetBooleanProperty (NMASchemeBooleanProperty booleanProperty, bool value, NMAZoomRange zoomRange);

		// -(float)floatForProperty:(NMASchemeFloatProperty)floatProperty forZoomLevel:(float)zoomLevel;
		[Export ("floatForProperty:forZoomLevel:")]
		float FloatForProperty (NMASchemeFloatProperty floatProperty, float zoomLevel);

		// -(void)setFloatProperty:(NMASchemeFloatProperty)floatProperty withValue:(float)value forZoomRange:(NMAZoomRange * _Nonnull)zoomRange;
		[Export ("setFloatProperty:withValue:forZoomRange:")]
		void SetFloatProperty (NMASchemeFloatProperty floatProperty, float value, NMAZoomRange zoomRange);

		// -(NSString * _Nonnull)name;
		[Export ("name")]
		[Verify (MethodToProperty)]
		string Name { get; }
	}

	// @interface NMASignpost : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASignpost
	{
		// @property (readonly, nonatomic) UIColor * _Nonnull foregroundColor;
		[Export ("foregroundColor")]
		UIColor ForegroundColor { get; }

		// @property (readonly, nonatomic) UIColor * _Nonnull backgroundColor;
		[Export ("backgroundColor")]
		UIColor BackgroundColor { get; }

		// @property (readonly, nonatomic) NSArray<NMASignpostLocalizedLabel *> * _Nonnull exitDirections;
		[Export ("exitDirections")]
		NMASignpostLocalizedLabel[] ExitDirections { get; }

		// @property (readonly, nonatomic) NMAImage * _Nullable exitIcon;
		[NullAllowed, Export ("exitIcon")]
		NMAImage ExitIcon { get; }

		// @property (readonly, nonatomic) NSString * _Nullable exitNumber;
		[NullAllowed, Export ("exitNumber")]
		string ExitNumber { get; }

		// @property (readonly, nonatomic) NSString * _Nullable exitText;
		[NullAllowed, Export ("exitText")]
		string ExitText { get; }
	}

	// @interface NMASignpostLocalizedLabel : NSObject
	[BaseType (typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASignpostLocalizedLabel
	{
		// @property (readonly, nonatomic) NSString * _Nullable language;
		[NullAllowed, Export ("language")]
		string Language { get; }

		// @property (readonly, nonatomic) NSString * _Nullable text;
		[NullAllowed, Export ("text")]
		string Text { get; }

		// @property (readonly, nonatomic) NSString * _Nullable routeName;
		[NullAllowed, Export ("routeName")]
		string RouteName { get; }

		// @property (readonly, nonatomic) NSString * _Nullable routeDirection;
		[NullAllowed, Export ("routeDirection")]
		string RouteDirection { get; }
	}
}
