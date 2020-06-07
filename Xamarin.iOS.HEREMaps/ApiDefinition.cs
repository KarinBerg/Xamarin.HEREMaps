using System;
using AVFoundation;
using CoreGraphics;
using CoreLocation;
using Foundation;
//using NMAKit;
using ObjCRuntime;
using UIKit;

namespace Xamarin.HEREMaps.iOS
{
	// @interface NMAARCameraParameters : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAARCameraParameters
	{
		// @property (readwrite, nonatomic) CGSize size;
		[Export("size", ArgumentSemantic.Assign)]
		CGSize Size { get; set; }

		// @property (readonly, nonatomic) NSArray<NSValue *> * _Nonnull supportedSizes;
		[Export("supportedSizes")]
		NSValue[] SupportedSizes { get; }
	}

	[Static]
	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMAARErrorDomain;
		[Field("NMAARErrorDomain", "__Internal")]
		NSString NMAARErrorDomain { get; }
	}

	// @protocol NMAARControllerDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAARControllerDelegate
	{
		// @optional -(void)arControllerDidEnterCameraView:(NMAARController * _Nonnull)arController;
		[Export("arControllerDidEnterCameraView:")]
		void ArControllerDidEnterCameraView(NMAARController arController);

		// @optional -(void)arControllerDidExitCameraView:(NMAARController * _Nonnull)arController;
		[Export("arControllerDidExitCameraView:")]
		void ArControllerDidExitCameraView(NMAARController arController);

		// @optional -(void)arController:(NMAARController * _Nonnull)arController errorOccurred:(NSError * _Nullable)error;
		[Export("arController:errorOccurred:")]
		void ArController(NMAARController arController, [NullAllowed] NSError error);

		// @optional -(void)arController:(NMAARController * _Nonnull)arController didUpdatePose:(NMAARPoseReading * _Nonnull)poseReading;
		[Export("arController:didUpdatePose:")]
		void ArController(NMAARController arController, NMAARPoseReading poseReading);
	}

	// @protocol NMAARControllerGestureDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAARControllerGestureDelegate
	{
		// @optional -(BOOL)arController:(NMAARController * _Nonnull)arController shouldProcessTouchDownAtPoint:(CGPoint)point;
		[Export("arController:shouldProcessTouchDownAtPoint:")]
		bool ShouldProcessTouchDownAtPoint(NMAARController arController, CGPoint point);

		// @optional -(BOOL)arController:(NMAARController * _Nonnull)arController shouldProcessPanFromPoint:(CGPoint)fromPoint toPoint:(CGPoint)toPoint;
		[Export("arController:shouldProcessPanFromPoint:toPoint:")]
		bool ShouldProcessPanFromPoint(NMAARController arController, CGPoint fromPoint, CGPoint toPoint);

		// @optional -(BOOL)arController:(NMAARController * _Nonnull)arController shouldProcessTouchUpAtPoint:(CGPoint)point;
		[Export("arController:shouldProcessTouchUpAtPoint:")]
		bool ShouldProcessTouchUpAtPoint(NMAARController arController, CGPoint point);

		// @optional -(BOOL)arController:(NMAARController * _Nonnull)arController shouldProcessTouchUpOnObjects:(NSArray<NMAARObject *> * _Nonnull)objects atPoint:(CGPoint)point;
		[Export("arController:shouldProcessTouchUpOnObjects:atPoint:")]
		bool ShouldProcessTouchUpOnObjects(NMAARController arController, NMAARObject[] objects, CGPoint point);

		// @optional -(BOOL)arController:(NMAARController * _Nonnull)arController shouldProcessTapAtPoint:(CGPoint)point;
		[Export("arController:shouldProcessTapAtPoint:")]
		bool ShouldProcessTapAtPoint(NMAARController arController, CGPoint point);
	}

	// @interface NMAARController : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAARController
	{
		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMAARControllerDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMAARControllerDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		[Wrap("WeakGestureDelegate")]
		[NullAllowed]
		NMAARControllerGestureDelegate GestureDelegate { get; set; }

		// @property (nonatomic, weak) id<NMAARControllerGestureDelegate> _Nullable gestureDelegate;
		[NullAllowed, Export("gestureDelegate", ArgumentSemantic.Weak)]
		NSObject WeakGestureDelegate { get; set; }

		// -(NSError * _Nullable)start;
		[NullAllowed, Export("start")]
		//[Verify(MethodToProperty)]
		NSError Start { get; }

		// -(NSError * _Nullable)stopWithAnimation:(BOOL)animation;
		[Export("stopWithAnimation:")]
		[return: NullAllowed]
		NSError StopWithAnimation(bool animation);

		// @property (readonly, nonatomic) BOOL isStarted;
		[Export("isStarted")]
		bool IsStarted { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable location;
		[NullAllowed, Export("location")]
		NMAGeoCoordinates Location { get; }

		// @property (nonatomic) NMAGeoCoordinates * _Nullable alternativeLocation;
		[NullAllowed, Export("alternativeLocation", ArgumentSemantic.Assign)]
		NMAGeoCoordinates AlternativeLocation { get; set; }

		// @property (readonly, nonatomic) NMAARPoseReading * _Nullable poseReading;
		[NullAllowed, Export("poseReading")]
		NMAARPoseReading PoseReading { get; }

		// -(void)setFrontPlaneIconSize:(CGSize)size;
		[Export("setFrontPlaneIconSize:")]
		void SetFrontPlaneIconSize(CGSize size);

		// -(void)addObject:(NMAARObject * _Nonnull)object;
		[Export("addObject:")]
		void AddObject(NMAARObject @object);

		// -(void)removeObject:(NMAARObject * _Nonnull)object;
		[Export("removeObject:")]
		void RemoveObject(NMAARObject @object);

		// -(void)addPolylineObject:(NMAARPolylineObject * _Nonnull)object;
		[Export("addPolylineObject:")]
		void AddPolylineObject(NMAARPolylineObject @object);

		// -(void)removePolylineObject:(NMAARPolylineObject * _Nonnull)object;
		[Export("removePolylineObject:")]
		void RemovePolylineObject(NMAARPolylineObject @object);

		// -(void)addModelObject:(NMAARModelObject * _Nonnull)object;
		[Export("addModelObject:")]
		void AddModelObject(NMAARModelObject @object);

		// -(void)removeModelObject:(NMAARModelObject * _Nonnull)object;
		[Export("removeModelObject:")]
		void RemoveModelObject(NMAARModelObject @object);

		// -(NMAARObject * _Nullable)objectAtPoint:(CGPoint)point withPress:(BOOL)press;
		[Export("objectAtPoint:withPress:")]
		[return: NullAllowed]
		NMAARObject ObjectAtPoint(CGPoint point, bool press);

		// -(void)pressObject:(NMAARObject * _Nonnull)object;
		[Export("pressObject:")]
		void PressObject(NMAARObject @object);

		// -(void)unpressObject:(NMAARObject * _Nonnull)object;
		[Export("unpressObject:")]
		void UnpressObject(NMAARObject @object);

		// -(void)selectObject:(NMAARObject * _Nonnull)object;
		[Export("selectObject:")]
		void SelectObject(NMAARObject @object);

		// -(void)selectObject:(NMAARObject * _Nonnull)object allowInfo:(BOOL)allowInfo scale:(CGFloat)scale;
		[Export("selectObject:allowInfo:scale:")]
		void SelectObject(NMAARObject @object, bool allowInfo, nfloat scale);

		// -(void)deselectObject;
		[Export("deselectObject")]
		void DeselectObject();

		// -(void)focusObject:(NMAARObject * _Nonnull)object;
		[Export("focusObject:")]
		void FocusObject(NMAARObject @object);

		// -(void)defocusObject;
		[Export("defocusObject")]
		void DefocusObject();

		// -(NSArray<NMAARObject *> * _Nullable)objectsAtPoint:(CGPoint)point;
		[Export("objectsAtPoint:")]
		[return: NullAllowed]
		NMAARObject[] ObjectsAtPoint(CGPoint point);

		// -(NSArray<NMAARObject *> * _Nullable)objectsInRect:(CGRect)rect;
		[Export("objectsInRect:")]
		[return: NullAllowed]
		NMAARObject[] ObjectsInRect(CGRect rect);

		// @property (nonatomic) NMAARProjectionType projectionType;
		[Export("projectionType", ArgumentSemantic.Assign)]
		NMAARProjectionType ProjectionType { get; set; }

		// @property (getter = isShowingFrontPlaneObjectsOnly, nonatomic) BOOL showFrontPlaneObjectsOnly;
		[Export("showFrontPlaneObjectsOnly")]
		bool ShowFrontPlaneObjectsOnly { [Bind("isShowingFrontPlaneObjectsOnly")] get; set; }

		// @property (nonatomic) float objectUpdateGpsDistanceThreshold;
		[Export("objectUpdateGpsDistanceThreshold")]
		float ObjectUpdateGpsDistanceThreshold { get; set; }

		// @property (readonly, nonatomic) NMAARCameraParameters * _Nonnull cameraParameters;
		[Export("cameraParameters")]
		NMAARCameraParameters CameraParameters { get; }
	}

	// @interface NMAARPoseReading : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAARPoseReading
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull location;
		[Export("location")]
		NMAGeoCoordinates Location { get; }

		// @property (readonly, nonatomic) float pitch;
		[Export("pitch")]
		float Pitch { get; }

		// @property (readonly, nonatomic) float heading;
		[Export("heading")]
		float Heading { get; }

		// @property (readonly, nonatomic) float roll;
		[Export("roll")]
		float Roll { get; }

		// @property (readonly, nonatomic) NSTimeInterval timestamp;
		[Export("timestamp")]
		double Timestamp { get; }
	}

	// @interface NMAARModelObject : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAARModelObject
	{
		// @property (readwrite, nonatomic) CGFloat opacity;
		[Export("opacity")]
		nfloat Opacity { get; set; }

		// @property (readwrite, nonatomic) CGPoint visibilityRange;
		[Export("visibilityRange", ArgumentSemantic.Assign)]
		CGPoint VisibilityRange { get; set; }

		// @property (readwrite, nonatomic) NMAARModelObjectShadingMode shadingMode;
		[Export("shadingMode", ArgumentSemantic.Assign)]
		NMAARModelObjectShadingMode ShadingMode { get; set; }

		// @property (readwrite, nonatomic) NMAImage * _Nullable texture;
		[NullAllowed, Export("texture", ArgumentSemantic.Assign)]
		NMAImage Texture { get; set; }

		// @property (readwrite, nonatomic) CGPoint dynamicScaleRange;
		[Export("dynamicScaleRange", ArgumentSemantic.Assign)]
		CGPoint DynamicScaleRange { get; set; }

		// @property (readwrite, nonatomic) CGPoint dynamicScaleFactors;
		[Export("dynamicScaleFactors", ArgumentSemantic.Assign)]
		CGPoint DynamicScaleFactors { get; set; }

		// -(void)setTransformation:(const float * _Nonnull)transformation;
		[Export("setTransformation:")]
		void SetTransformation(NSNumber[] transformation);

		// -(void)getTransformation:(float * _Nonnull)transformation;
		[Export("getTransformation:")]
		void GetTransformation(NSNumber[] transformation);

		// -(void)clearTransformation;
		[Export("clearTransformation")]
		void ClearTransformation();

		// -(void)scale:(NMAVector3d)scaleFactors;
		[Export("scale:")]
		void Scale(NMAVector3d scaleFactors);

		// -(void)rotateWithAxis:(NMAVector3d)rotationAxis angle:(CGFloat)rotationAngleDeg;
		[Export("rotateWithAxis:angle:")]
		void RotateWithAxis(NMAVector3d rotationAxis, nfloat rotationAngleDeg);

		// -(void)rotate:(NMAVector3d)rotationAngles;
		[Export("rotate:")]
		void Rotate(NMAVector3d rotationAngles);

		// -(void)translate:(NMAVector3d)translation;
		[Export("translate:")]
		void Translate(NMAVector3d translation);
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const float NMAGeoCoordinatesUnknownAltitudeValue;
		[Field("NMAGeoCoordinatesUnknownAltitudeValue", "__Internal")]
		float NMAGeoCoordinatesUnknownAltitudeValue { get; }

		// extern const double NMAGeoCoordinatesInvalidValue;
		[Field("NMAGeoCoordinatesInvalidValue", "__Internal")]
		double NMAGeoCoordinatesInvalidValue { get; }
	}

	// @interface NMAGeoCoordinates : NSObject <NSCoding>
	[BaseType(typeof(NSObject))]
	interface NMAGeoCoordinates : INSCoding
	{
		// +(instancetype _Nonnull)geoCoordinatesWithLatitude:(double)latitude longitude:(double)longitude;
		[Static]
		[Export("geoCoordinatesWithLatitude:longitude:")]
		NMAGeoCoordinates GeoCoordinatesWithLatitude(double latitude, double longitude);

		// +(instancetype _Nonnull)geoCoordinatesWithLatitude:(double)latitude longitude:(double)longitude altitude:(double)altitude;
		[Static]
		[Export("geoCoordinatesWithLatitude:longitude:altitude:")]
		NMAGeoCoordinates GeoCoordinatesWithLatitude(double latitude, double longitude, double altitude);

		// -(instancetype _Nonnull)initWithLatitude:(double)latitude longitude:(double)longitude;
		[Export("initWithLatitude:longitude:")]
		IntPtr Constructor(double latitude, double longitude);

		// -(instancetype _Nonnull)initWithLatitude:(double)latitude longitude:(double)longitude altitude:(float)altitude;
		[Export("initWithLatitude:longitude:altitude:")]
		IntPtr Constructor(double latitude, double longitude, float altitude);

		// @property (nonatomic) double latitude;
		[Export("latitude")]
		double Latitude { get; set; }

		// @property (nonatomic) double longitude;
		[Export("longitude")]
		double Longitude { get; set; }

		// @property (nonatomic) float altitude;
		[Export("altitude")]
		float Altitude { get; set; }

		// -(double)distanceTo:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("distanceTo:")]
		double DistanceTo(NMAGeoCoordinates coordinates);

		// -(double)headingTo:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("headingTo:")]
		double HeadingTo(NMAGeoCoordinates coordinates);

		// -(BOOL)isEqualToGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("isEqualToGeoCoordinates:")]
		bool IsEqualToGeoCoordinates(NMAGeoCoordinates coordinates);
	}

	// @interface NMAARBillboardObject : NMAARModelObject
	[BaseType(typeof(NMAARModelObject))]
	[DisableDefaultCtor]
	interface NMAARBillboardObject
	{
		// -(instancetype _Nonnull)initWithLocalPosition:(NMAVector3d)localPosition texture:(NMAImage * _Nullable)texture;
		[Export("initWithLocalPosition:texture:")]
		IntPtr Constructor(NMAVector3d localPosition, [NullAllowed] NMAImage texture);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)geoCoordinates texture:(NMAImage * _Nullable)texture;
		[Export("initWithGeoCoordinates:texture:")]
		IntPtr Constructor(NMAGeoCoordinates geoCoordinates, [NullAllowed] NMAImage texture);

		// @property (readwrite, nonatomic) NMAVector3d localPosition;
		[Export("localPosition", ArgumentSemantic.Assign)]
		NMAVector3d LocalPosition { get; set; }

		// @property (readwrite, nonatomic) NMAGeoCoordinates * _Nullable geoPosition;
		[NullAllowed, Export("geoPosition", ArgumentSemantic.Assign)]
		NMAGeoCoordinates GeoPosition { get; set; }

		// @property (readwrite, nonatomic) NMAARBillboardObjectOrientation orientation;
		[Export("orientation", ArgumentSemantic.Assign)]
		NMAARBillboardObjectOrientation Orientation { get; set; }

		// @property (readwrite, nonatomic) NMAVector3d surfaceNormal;
		[Export("surfaceNormal", ArgumentSemantic.Assign)]
		NMAVector3d SurfaceNormal { get; set; }

		// @property (readwrite, nonatomic) NMAVector3d upDirection;
		[Export("upDirection", ArgumentSemantic.Assign)]
		NMAVector3d UpDirection { get; set; }

		// @property (readwrite, nonatomic) CGSize size;
		[Export("size", ArgumentSemantic.Assign)]
		CGSize Size { get; set; }
	}

	// @interface NMAARObject : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAARObject
	{
		// @property (readonly, nonatomic) NSUInteger uniqueId;
		[Export("uniqueId")]
		nuint UniqueId { get; }

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull coordinates;
		[Export("coordinates", ArgumentSemantic.Assign)]
		NMAGeoCoordinates Coordinates { get; set; }

		// @property (readonly, nonatomic) CGRect frame;
		[Export("frame")]
		CGRect Frame { get; }

		// @property (nonatomic) NMAARProjectionType projectionType;
		[Export("projectionType", ArgumentSemantic.Assign)]
		NMAARProjectionType ProjectionType { get; set; }

		// @property (nonatomic) CGFloat opacity;
		[Export("opacity")]
		nfloat Opacity { get; set; }

		// @property (readwrite, nonatomic) NMAImage * _Nonnull frontPlaneIcon;
		[Export("frontPlaneIcon", ArgumentSemantic.Assign)]
		NMAImage FrontPlaneIcon { get; set; }

		// @property (readwrite, nonatomic) NMAImage * _Nonnull backPlaneIcon;
		[Export("backPlaneIcon", ArgumentSemantic.Assign)]
		NMAImage BackPlaneIcon { get; set; }

		// @property (nonatomic, strong) NMAImage * _Nonnull infoImage;
		[Export("infoImage", ArgumentSemantic.Strong)]
		NMAImage InfoImage { get; set; }

		// @property (nonatomic) CGFloat infoImageMaximumWidth;
		[Export("infoImageMaximumWidth")]
		nfloat InfoImageMaximumWidth { get; set; }

		// @property (nonatomic) CGFloat infoImageMaximumHeight;
		[Export("infoImageMaximumHeight")]
		nfloat InfoImageMaximumHeight { get; set; }

		// @property (readonly, getter = isInfoImageVisible, nonatomic) BOOL infoImageVisible;
		[Export("infoImageVisible")]
		bool InfoImageVisible { [Bind("isInfoImageVisible")] get; }
	}

	// @interface NMAARIconObject : NMAARObject
	[BaseType(typeof(NMAARObject))]
	[DisableDefaultCtor]
	interface NMAARIconObject
	{
		// +(instancetype _Nonnull)iconObjectWithIcon:(NMAImage * _Nonnull)icon coordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Static]
		[Export("iconObjectWithIcon:coordinates:")]
		NMAARIconObject IconObjectWithIcon(NMAImage icon, NMAGeoCoordinates coordinates);

		// +(instancetype _Nonnull)iconObjectWithIcon:(NMAImage * _Nonnull)icon infoImage:(NMAImage * _Nonnull)infoImage coordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Static]
		[Export("iconObjectWithIcon:infoImage:coordinates:")]
		NMAARIconObject IconObjectWithIcon(NMAImage icon, NMAImage infoImage, NMAGeoCoordinates coordinates);

		// +(instancetype _Nonnull)iconObjectWithFrontPlaneIcon:(NMAImage * _Nonnull)frontPlaneIcon backPlaneIcon:(NMAImage * _Nonnull)backPlaneIcon mapIcon:(NMAImage * _Nonnull)mapIcon infoImage:(NMAImage * _Nonnull)infoImage coordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Static]
		[Export("iconObjectWithFrontPlaneIcon:backPlaneIcon:mapIcon:infoImage:coordinates:")]
		NMAARIconObject IconObjectWithFrontPlaneIcon(NMAImage frontPlaneIcon, NMAImage backPlaneIcon, NMAImage mapIcon, NMAImage infoImage, NMAGeoCoordinates coordinates);
	}

	/*
	// @interface NMAFloatMesh : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAFloatMesh
	{
		// -(instancetype _Nonnull)initWithVertices:(const float * _Nonnull)vertices vertexCount:(NSUInteger)vertexCount textureCoordinates:(const float * _Nonnull)textureCoordinates coorCount:(NSUInteger)coorCount triangles:(const short * _Nonnull)triangles triangleCount:(NSUInteger)triangleCount;
		[Export("initWithVertices:vertexCount:textureCoordinates:coorCount:triangles:triangleCount:")]
		unsafe IntPtr Constructor(float* vertices, nuint vertexCount, float* textureCoordinates, nuint coorCount, short* triangles, nuint triangleCount);

		// -(void)setVertices:(const float * _Nonnull)vertices withCount:(NSUInteger)count;
		[Export("setVertices:withCount:")]
		unsafe void SetVertices(float* vertices, nuint count);

		// -(void)setTextureCoordinates:(const float * _Nonnull)textureCoordinates withCount:(NSUInteger)count;
		[Export("setTextureCoordinates:withCount:")]
		unsafe void SetTextureCoordinates(float* textureCoordinates, nuint count);

		// -(void)setTriangles:(const short * _Nonnull)triangles withCount:(NSUInteger)count;
		[Export("setTriangles:withCount:")]
		unsafe void SetTriangles(short* triangles, nuint count);

		// -(BOOL)isValid;
		[Export("isValid")]
		//[Verify(MethodToProperty)]
		bool IsValid { get; }
	}

	// @interface NMAARMeshObject : NMAARModelObject
	[BaseType(typeof(NMAARModelObject))]
	[DisableDefaultCtor]
	interface NMAARMeshObject
	{
		// -(instancetype _Nonnull)initWithLocalPosition:(NMAVector3d)localPosition mesh:(NMAFloatMesh * _Nonnull)mesh texture:(NMAImage * _Nonnull)texture;
		[Export("initWithLocalPosition:mesh:texture:")]
		IntPtr Constructor(NMAVector3d localPosition, NMAFloatMesh mesh, NMAImage texture);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)geoCoordinates mesh:(NMAFloatMesh * _Nonnull)mesh texture:(NMAImage * _Nonnull)texture;
		[Export("initWithGeoCoordinates:mesh:texture:")]
		IntPtr Constructor(NMAGeoCoordinates geoCoordinates, NMAFloatMesh mesh, NMAImage texture);

		// -(instancetype _Nonnull)initWithLocalPosition:(NMAVector3d)localPosition geoDirection:(NMAGeoCoordinates * _Nonnull)geoDirection mesh:(NMAFloatMesh * _Nonnull)mesh texture:(NMAImage * _Nonnull)texture;
		[Export("initWithLocalPosition:geoDirection:mesh:texture:")]
		IntPtr Constructor(NMAVector3d localPosition, NMAGeoCoordinates geoDirection, NMAFloatMesh mesh, NMAImage texture);

		// @property (readwrite, nonatomic) NMAVector3d localPosition;
		[Export("localPosition", ArgumentSemantic.Assign)]
		NMAVector3d LocalPosition { get; set; }

		// @property (readwrite, nonatomic) NMAGeoCoordinates * _Nonnull geoPosition;
		[Export("geoPosition", ArgumentSemantic.Assign)]
		NMAGeoCoordinates GeoPosition { get; set; }

		// @property (readwrite, nonatomic) NMAGeoCoordinates * _Nonnull geoDirection;
		[Export("geoDirection", ArgumentSemantic.Assign)]
		NMAGeoCoordinates GeoDirection { get; set; }

		// @property (readwrite, nonatomic) NMAFloatMesh * _Nonnull mesh;
		[Export("mesh", ArgumentSemantic.Assign)]
		NMAFloatMesh Mesh { get; set; }
	}
	*/

	// @interface NMAARPolylineObject : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAARPolylineObject
	{
		// -(instancetype _Nonnull)initWithPolyline:(NMAMapPolyline * _Nonnull)polyline;
		[Export("initWithPolyline:")]
		IntPtr Constructor(NMAMapPolyline polyline);

		// -(instancetype _Nonnull)initWithPolyline:(NMAMapPolyline * _Nonnull)polyline lineAttributes:(NMALineAttributes * _Nonnull)lineAttributes;
		[Export("initWithPolyline:lineAttributes:")]
		IntPtr Constructor(NMAMapPolyline polyline, NMALineAttributes lineAttributes);

		// @property (readonly, nonatomic) NSUInteger uniqueId;
		[Export("uniqueId")]
		nuint UniqueId { get; }

		// @property (readwrite, nonatomic) NMAMapPolyline * _Nonnull polyline;
		[Export("polyline", ArgumentSemantic.Assign)]
		NMAMapPolyline Polyline { get; set; }

		// @property (readwrite, nonatomic) NMALineAttributes * _Nonnull lineAttributes;
		[Export("lineAttributes", ArgumentSemantic.Assign)]
		NMALineAttributes LineAttributes { get; set; }
	}

	// @interface NMAViewObject : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAViewObject
	{
		// -(BOOL)isEqual:(id _Nullable)aViewObject;
		[Export("isEqual:")]
		bool IsEqual([NullAllowed] NSObject aViewObject);

		// -(BOOL)isInArray:(NSArray<NMAViewObject *> * _Nonnull)objects;
		[Export("isInArray:")]
		bool IsInArray(NMAViewObject[] objects);

		// -(NMAGeoCoordinates * _Nullable)location;
		[NullAllowed, Export("location")]
		//[Verify(MethodToProperty)]
		NMAGeoCoordinates Location { get; }
	}

	// @interface NMAUserObject : NMAViewObject
	[BaseType(typeof(NMAViewObject))]
	interface NMAUserObject
	{
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const NSUInteger NMAMapObjectMinimumZIndex;
		[Field("NMAMapObjectMinimumZIndex", "__Internal")]
		nuint NMAMapObjectMinimumZIndex { get; }

		// extern const NSUInteger NMAMapObjectMaximumZIndex;
		[Field("NMAMapObjectMaximumZIndex", "__Internal")]
		nuint NMAMapObjectMaximumZIndex { get; }

		// extern const float NMAMapViewMinimumZoomLevel;
		[Field("NMAMapViewMinimumZoomLevel", "__Internal")]
		float NMAMapViewMinimumZoomLevel { get; }

		// extern const float NMAMapViewMaximumZoomLevel;
		[Field("NMAMapViewMaximumZoomLevel", "__Internal")]
		float NMAMapViewMaximumZoomLevel { get; }
	}

	// @interface NMAMapObject : NMAUserObject
	[BaseType(typeof(NMAUserObject))]
	interface NMAMapObject
	{
		// @property (readwrite, nonatomic) NMAMapLayerType mapLayerType;
		[Export("mapLayerType", ArgumentSemantic.Assign)]
		NMAMapLayerType MapLayerType { get; set; }

		// @property (nonatomic) NSUInteger zIndex;
		[Export("zIndex")]
		nuint ZIndex { get; set; }

		// @property (getter = isVisible, nonatomic) BOOL visible;
		[Export("visible")]
		bool Visible { [Bind("isVisible")] get; set; }

		// @property (readonly, nonatomic) NMAMapObjectType type;
		[Export("type")]
		NMAMapObjectType Type { get; }

		// @property (readonly, nonatomic, weak) NMAMapContainer * _Nullable parent;
		[NullAllowed, Export("parent", ArgumentSemantic.Weak)]
		NMAMapContainer Parent { get; }

		// -(NSUInteger)uniqueId;
		[Export("uniqueId")]
		//[Verify(MethodToProperty)]
		nuint UniqueId { get; }

		// -(BOOL)isVisibleAtZoomLevel:(float)zoomLevel;
		[Export("isVisibleAtZoomLevel:")]
		bool IsVisibleAtZoomLevel(float zoomLevel);

		// -(void)setVisibility:(BOOL)visible atZoomLevel:(float)zoomLevel;
		[Export("setVisibility:atZoomLevel:")]
		void SetVisibility(bool visible, float zoomLevel);

		// -(void)setVisibility:(BOOL)visible fromZoomLevel:(float)fromZoomLevel toZoomLevel:(float)toZoomLevel;
		[Export("setVisibility:fromZoomLevel:toZoomLevel:")]
		void SetVisibility(bool visible, float fromZoomLevel, float toZoomLevel);
	}

	// @interface NMAMapPolyline : NMAMapObject
	[BaseType(typeof(NMAMapObject))]
	interface NMAMapPolyline
	{
		// +(instancetype _Nonnull)mapPolylineWithVertices:(NSArray<NMAGeoCoordinates *> * _Nonnull)vertices;
		[Static]
		[Export("mapPolylineWithVertices:")]
		NMAMapPolyline MapPolylineWithVertices(NMAGeoCoordinates[] vertices);

		// @property (readonly, nonatomic) NSArray<NMAGeoCoordinates *> * _Nonnull vertices;
		[Export("vertices")]
		NMAGeoCoordinates[] Vertices { get; }

		// @property (nonatomic, strong) UIColor * _Nonnull lineColor;
		[Export("lineColor", ArgumentSemantic.Strong)]
		UIColor LineColor { get; set; }

		// @property (nonatomic) NSUInteger lineWidth;
		[Export("lineWidth")]
		nuint LineWidth { get; set; }

		// @property (getter = isDashed, nonatomic) BOOL dashed;
		[Export("dashed")]
		bool Dashed { [Bind("isDashed")] get; set; }

		// @property (nonatomic) NSUInteger dashPrimaryLength;
		[Export("dashPrimaryLength")]
		nuint DashPrimaryLength { get; set; }

		// @property (nonatomic) NSUInteger dashSecondaryLength;
		[Export("dashSecondaryLength")]
		nuint DashSecondaryLength { get; set; }

		// @property (nonatomic, strong) UIColor * _Nonnull outlineColor;
		[Export("outlineColor", ArgumentSemantic.Strong)]
		UIColor OutlineColor { get; set; }

		// @property (nonatomic) NSUInteger outlineWidth;
		[Export("outlineWidth")]
		nuint OutlineWidth { get; set; }

		// @property (nonatomic) BOOL depthTestEnabled;
		[Export("depthTestEnabled")]
		bool DepthTestEnabled { get; set; }

		// -(void)enableShadow:(NSUInteger)width shearFactor:(float)shearFactor;
		[Export("enableShadow:shearFactor:")]
		void EnableShadow(nuint width, float shearFactor);

		// @property (getter = isShadowEnabled, nonatomic) BOOL shadowEnabled;
		[Export("shadowEnabled")]
		bool ShadowEnabled { [Bind("isShadowEnabled")] get; set; }

		// @property (nonatomic) NSUInteger shadowWidth;
		[Export("shadowWidth")]
		nuint ShadowWidth { get; set; }

		// @property (nonatomic, strong) UIColor * _Nonnull shadowColor;
		[Export("shadowColor", ArgumentSemantic.Strong)]
		UIColor ShadowColor { get; set; }

		// @property (nonatomic) float shadowShearFactor;
		[Export("shadowShearFactor")]
		float ShadowShearFactor { get; set; }

		// @property (nonatomic) float shadowOffsetX;
		[Export("shadowOffsetX")]
		float ShadowOffsetX { get; set; }

		// @property (nonatomic) float shadowOffsetY;
		[Export("shadowOffsetY")]
		float ShadowOffsetY { get; set; }

		// @property (nonatomic) float shadowSizeIncrement;
		[Export("shadowSizeIncrement")]
		float ShadowSizeIncrement { get; set; }

		// -(instancetype _Nonnull)initWithPolyline:(NMAGeoPolyline * _Nonnull)geoPolyline;
		[Export("initWithPolyline:")]
		IntPtr Constructor(NMAGeoPolyline geoPolyline);

		// @property (readonly, nonatomic) NMAGeoPolyline * _Nonnull geoPolyline;
		[Export("geoPolyline")]
		NMAGeoPolyline GeoPolyline { get; }

		// -(instancetype _Nonnull)initWithVertices:(NSArray<NMAGeoCoordinates *> * _Nonnull)vertices __attribute__((objc_designated_initializer));
		[Export("initWithVertices:")]
		[DesignatedInitializer]
		IntPtr Constructor(NMAGeoCoordinates[] vertices);

		// -(NMAGeoCoordinates * _Nonnull)nearestVertexToGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("nearestVertexToGeoCoordinates:")]
		NMAGeoCoordinates NearestVertexToGeoCoordinates(NMAGeoCoordinates coordinates);

		// -(NSInteger)indexOfNearestVertexToGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("indexOfNearestVertexToGeoCoordinates:")]
		nint IndexOfNearestVertexToGeoCoordinates(NMAGeoCoordinates coordinates);

		// -(void)clearVertices;
		[Export("clearVertices")]
		void ClearVertices();

		// -(void)appendVertex:(NMAGeoCoordinates * _Nonnull)vertex;
		[Export("appendVertex:")]
		void AppendVertex(NMAGeoCoordinates vertex);

		// -(void)addVertex:(NMAGeoCoordinates * _Nonnull)vertex atIndex:(NSUInteger)index;
		[Export("addVertex:atIndex:")]
		void AddVertex(NMAGeoCoordinates vertex, nuint index);

		// -(void)removeLastVertex;
		[Export("removeLastVertex")]
		void RemoveLastVertex();

		// -(void)removeVertexAtIndex:(NSUInteger)index;
		[Export("removeVertexAtIndex:")]
		void RemoveVertexAtIndex(nuint index);

		// @property (getter = isPerspective, nonatomic) BOOL perspective;
		[Export("perspective")]
		bool Perspective { [Bind("isPerspective")] get; set; }

		// @property (assign, nonatomic) NMAPatternStyle patternStyle;
		[Export("patternStyle", ArgumentSemantic.Assign)]
		NMAPatternStyle PatternStyle { get; set; }

		// @property (readwrite, nonatomic) NMAImage * _Nullable customPattern;
		[NullAllowed, Export("customPattern", ArgumentSemantic.Assign)]
		NMAImage CustomPattern { get; set; }
	}

	// @interface NMALineAttributes : NSObject
	[BaseType(typeof(NSObject))]
	interface NMALineAttributes
	{
		// -(instancetype _Nonnull)initWithWidth:(NSUInteger)widthInPixel color:(UIColor * _Nonnull)color capStyle:(NMALineCapStyle)capStyle perspective:(BOOL)perspective;
		[Export("initWithWidth:color:capStyle:perspective:")]
		IntPtr Constructor(nuint widthInPixel, UIColor color, NMALineCapStyle capStyle, bool perspective);

		// @property (readwrite, nonatomic) NSUInteger lineWidth;
		[Export("lineWidth")]
		nuint LineWidth { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nonnull lineColor;
		[Export("lineColor", ArgumentSemantic.Assign)]
		UIColor LineColor { get; set; }

		// @property (getter = isDashed, readwrite, nonatomic) BOOL dashed;
		[Export("dashed")]
		bool Dashed { [Bind("isDashed")] get; set; }

		// @property (readwrite, nonatomic) NSUInteger dashPrimaryLength;
		[Export("dashPrimaryLength")]
		nuint DashPrimaryLength { get; set; }

		// @property (readwrite, nonatomic) NSUInteger dashSecondaryLength;
		[Export("dashSecondaryLength")]
		nuint DashSecondaryLength { get; set; }

		// @property (readwrite, nonatomic) NMALineCapStyle capStyle;
		[Export("capStyle", ArgumentSemantic.Assign)]
		NMALineCapStyle CapStyle { get; set; }

		// @property (readwrite, nonatomic) BOOL renderedWithPerspective;
		[Export("renderedWithPerspective")]
		bool RenderedWithPerspective { get; set; }
	}

	// @interface NMACompositeView : UIView
	[BaseType(typeof(UIView))]
	interface NMACompositeView
	{
		// @property (readonly, nonatomic) NMAARController * _Nonnull arController;
		[Export("arController")]
		NMAARController ArController { get; }

		// @property (getter = isRenderAllowed, nonatomic) BOOL renderAllowed;
		[Export("renderAllowed")]
		bool RenderAllowed { [Bind("isRenderAllowed")] get; set; }
	}

	/*
	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull kNMACLE2ErrorDomain;
		[Field("kNMACLE2ErrorDomain", "__Internal")]
		NSString kNMACLE2ErrorDomain { get; }
	}
	
	// @protocol NMACLE2ResultListener <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMACLE2ResultListener
	{
		// @optional -(void)request:(NMACLE2Request * _Nonnull)request didCompleteWithResult:(NMACLE2Result * _Nonnull)result error:(NSError * _Nullable)error;
		[Export("request:didCompleteWithResult:error:")]
		void DidCompleteWithResult(NMACLE2Request request, NMACLE2Result result, [NullAllowed] NSError error);
	}

	// typedef void (^NMACLE2RequestCompletionBlock)(NMACLE2Request * _Nonnull, NMACLE2Result * _Nonnull, NSError * _Nullable);
	delegate void NMACLE2RequestCompletionBlock(NMACLE2Request arg0, NMACLE2Result arg1, [NullAllowed] NSError arg2);

	// @interface NMACLE2Request : NSObject
	[BaseType(typeof(NSObject))]
	interface NMACLE2Request
	{
		// @property (readwrite, nonatomic) NMACLE2GeometryType geometryType;
		[Export("geometryType", ArgumentSemantic.Assign)]
		NMACLE2GeometryType GeometryType { get; set; }

		// @property (readwrite, nonatomic) NMACLE2ConnectivityMode connectivityMode;
		[Export("connectivityMode", ArgumentSemantic.Assign)]
		NMACLE2ConnectivityMode ConnectivityMode { get; set; }

		// @property (readwrite, nonatomic) BOOL cachingEnabled;
		[Export("cachingEnabled")]
		bool CachingEnabled { get; set; }

		// @property (readwrite, nonatomic) NSString * _Nullable query;
		[NullAllowed, Export("query")]
		string Query { get; set; }

		// -(NSError * _Nullable)startWithListener:(id<NMACLE2ResultListener> _Nonnull)listener;
		[Export("startWithListener:")]
		[return: NullAllowed]
		NSError StartWithListener(NMACLE2ResultListener listener);

		// -(NSError * _Nullable)startWithBlock:(NMACLE2RequestCompletionBlock _Nonnull)block;
		[Export("startWithBlock:")]
		[return: NullAllowed]
		NSError StartWithBlock(NMACLE2RequestCompletionBlock block);

		// -(void)cancel;
		[Export("cancel")]
		void Cancel();
	}

	// @interface NMACLE2AttributeRequest : NMACLE2Request
	[BaseType(typeof(NMACLE2Request))]
	interface NMACLE2AttributeRequest
	{
		// -(instancetype _Nullable)initWithLayer:(NSString * _Nonnull)layerId query:(NSString * _Nonnull)query;
		[Export("initWithLayer:query:")]
		IntPtr Constructor(string layerId, string query);

		// -(instancetype _Nullable)initWithLayers:(NSArray<NSString *> * _Nonnull)layerIds query:(NSString * _Nonnull)query;
		[Export("initWithLayers:query:")]
		IntPtr Constructor(string[] layerIds, string query);
	}

	// @interface NMACLE2BoundingBoxRequest : NMACLE2Request
	[BaseType(typeof(NMACLE2Request))]
	interface NMACLE2BoundingBoxRequest
	{
		// -(instancetype _Nullable)initWithLayer:(NSString * _Nonnull)layerId boundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox;
		[Export("initWithLayer:boundingBox:")]
		IntPtr Constructor(string layerId, NMAGeoBoundingBox boundingBox);

		// -(instancetype _Nullable)initWithLayers:(NSArray<NSString *> * _Nonnull)layerIds boundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox;
		[Export("initWithLayers:boundingBox:")]
		IntPtr Constructor(string[] layerIds, NMAGeoBoundingBox boundingBox);
	}

	// @interface NMACLE2CorridorRequest : NMACLE2Request
	[BaseType(typeof(NMACLE2Request))]
	interface NMACLE2CorridorRequest
	{
		// -(instancetype _Nullable)initWithLayer:(NSString * _Nonnull)layerId corridor:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinatesArray radius:(NSInteger)radius;
		[Export("initWithLayer:corridor:radius:")]
		IntPtr Constructor(string layerId, NMAGeoCoordinates[] coordinatesArray, nint radius);

		// -(instancetype _Nullable)initWithLayers:(NSArray<NSString *> * _Nonnull)layerIds corridor:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinatesArray radius:(NSInteger)radius;
		[Export("initWithLayers:corridor:radius:")]
		IntPtr Constructor(string[] layerIds, NMAGeoCoordinates[] coordinatesArray, nint radius);

		// -(instancetype _Nullable)initWithLayer:(NSString * _Nonnull)layerId route:(NMARoute * _Nonnull)route radius:(NSInteger)radius;
		[Export("initWithLayer:route:radius:")]
		IntPtr Constructor(string layerId, NMARoute route, nint radius);

		// -(instancetype _Nullable)initWithLayers:(NSArray<NSString *> * _Nonnull)layerIds route:(NMARoute * _Nonnull)route radius:(NSInteger)radius;
		[Export("initWithLayers:route:radius:")]
		IntPtr Constructor(string[] layerIds, NMARoute route, nint radius);
	}

	// @interface NMACLE2DataManager : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMACLE2DataManager
	{
		// +(instancetype _Nullable)sharedManager;
		[Static]
		[Export("sharedManager")]
		[return: NullAllowed]
		NMACLE2DataManager SharedManager();

		// -(NMACLE2Task<NMACLE2OperationResult *> * _Nonnull)downloadLayerTask:(NSString * _Nonnull)layerId;
		[Export("downloadLayerTask:")]
		NMACLE2Task<NMACLE2OperationResult> DownloadLayerTask(string layerId);

		// -(NMACLE2Task<NMACLE2OperationResult *> * _Nonnull)uploadLayerTask:(NSString * _Nonnull)layerId withGeometries:(NSArray<NMACLE2Geometry *> * _Nonnull)geometriesArray;
		[Export("uploadLayerTask:withGeometries:")]
		NMACLE2Task<NMACLE2OperationResult> UploadLayerTask(string layerId, NMACLE2Geometry[] geometriesArray);

		// -(NMACLE2Task<NMACLE2OperationResult *> * _Nonnull)geometryTask:(NMACLE2OperationType)operationType onLayer:(NSString * _Nonnull)layerId withGeometries:(NSArray<NMACLE2Geometry *> * _Nonnull)geometriesArray inStorage:(NMACLE2StorageType)storage;
		[Export("geometryTask:onLayer:withGeometries:inStorage:")]
		NMACLE2Task<NMACLE2OperationResult> GeometryTask(NMACLE2OperationType operationType, string layerId, NMACLE2Geometry[] geometriesArray, NMACLE2StorageType storage);

		// -(NMACLE2Task<NSDictionary<NSString *,NMACLE2LayerMetadata *> *> * _Nonnull)listLayersTaskInStorage:(NMACLE2StorageType)storageArea;
		[Export("listLayersTaskInStorage:")]
		NMACLE2Task<NSDictionary<NSString, NMACLE2LayerMetadata>> ListLayersTaskInStorage(NMACLE2StorageType storageArea);

		// -(NMACLE2Task<NMACLE2OperationResult *> * _Nonnull)deleteLayersTask:(NSArray<NSString *> * _Nonnull)layerIds fromStorage:(NMACLE2StorageType)storageType;
		[Export("deleteLayersTask:fromStorage:")]
		NMACLE2Task<NMACLE2OperationResult> DeleteLayersTask(string[] layerIds, NMACLE2StorageType storageType);

		// -(NMACLE2Task<NMACLE2OperationResult *> * _Nonnull)purgeLocalStorageTask;
		[Export("purgeLocalStorageTask")]
		//[Verify(MethodToProperty)]
		NMACLE2Task<NMACLE2OperationResult> PurgeLocalStorageTask { get; }

		// -(NMACLE2Task<NSMutableArray<NMACLE2Geometry *> *> * _Nonnull)fetchLocalLayersTask:(NSArray<NSString *> * _Nonnull)layerIds;
		[Export("fetchLocalLayersTask:")]
		NMACLE2Task<NSMutableArray<NMACLE2Geometry>> FetchLocalLayersTask(string[] layerIds);

		// -(NSNumber * _Nullable)numberOfStoredGeometriesOnError:(NSError * _Nullable * _Nullable)error;
		[Export("numberOfStoredGeometriesOnError:")]
		[return: NullAllowed]
		NSNumber NumberOfStoredGeometriesOnError([NullAllowed] out NSError error);

		// -(NSNumber * _Nullable)numberOfStoredGeometriesinLayer:(NSString * _Nonnull)layerId onError:(NSError * _Nullable * _Nonnull)error;
		[Export("numberOfStoredGeometriesinLayer:onError:")]
		[return: NullAllowed]
		NSNumber NumberOfStoredGeometriesinLayer(string layerId, [NullAllowed] out NSError error);
	}

	// @interface NMACLE2Geometry : NSObject
	[BaseType(typeof(NSObject))]
	interface NMACLE2Geometry : ObjCRuntime.INativeObject
	{
		// @property (readonly, nonatomic) NSString * _Nullable geometryId;
		[NullAllowed, Export("geometryId")]
		string GeometryId { get; }

		// @property (readonly, nonatomic) double distance;
		[Export("distance")]
		double Distance { get; }

		// @property (readonly, nonatomic) BOOL isLocal;
		[Export("isLocal")]
		bool IsLocal { get; }

		// @property (nonatomic) NSMutableDictionary<NSString *,NSString *> * _Nonnull attributes;
		[Export("attributes", ArgumentSemantic.Assign)]
		NSMutableDictionary<NSString, NSString> Attributes { get; set; }
	}

	// @interface NMACLE2GeometryMultiPoint : NMACLE2Geometry
	[BaseType(typeof(NMACLE2Geometry))]
	interface NMACLE2GeometryMultiPoint
	{
		// @property (readwrite, nonatomic) NSMutableArray<NMAGeoCoordinates *> * _Nonnull coordinatesArray;
		[Export("coordinatesArray", ArgumentSemantic.Assign)]
		NSMutableArray<NMAGeoCoordinates> CoordinatesArray { get; set; }
	}

	// @interface NMACLE2GeometryMultiPolygon : NMACLE2Geometry
	[BaseType(typeof(NMACLE2Geometry))]
	interface NMACLE2GeometryMultiPolygon
	{
		// @property (nonatomic) NSMutableArray<NMACLE2GeometryPolygon *> * _Nonnull multiPolygonArray;
		[Export("multiPolygonArray", ArgumentSemantic.Assign)]
		NSMutableArray<NMACLE2GeometryPolygon> MultiPolygonArray { get; set; }
	}

	// @interface NMACLE2GeometryMultiPolyline : NMACLE2Geometry
	[BaseType(typeof(NMACLE2Geometry))]
	interface NMACLE2GeometryMultiPolyline
	{
		// @property (nonatomic) NSMutableArray<NMAGeoPolyline *> * _Nonnull multiPolylineArray;
		[Export("multiPolylineArray", ArgumentSemantic.Assign)]
		NSMutableArray<NMAGeoPolyline> MultiPolylineArray { get; set; }
	}

	// @interface NMACLE2GeometryPoint : NMACLE2Geometry
	[BaseType(typeof(NMACLE2Geometry))]
	interface NMACLE2GeometryPoint
	{
		// @property (nonatomic) NMAGeoCoordinates * _Nullable coordinates;
		[NullAllowed, Export("coordinates", ArgumentSemantic.Assign)]
		NMAGeoCoordinates Coordinates { get; set; }
	}

	// @interface NMACLE2GeometryPolygon : NMACLE2Geometry
	[BaseType(typeof(NMACLE2Geometry))]
	interface NMACLE2GeometryPolygon : ObjCRuntime.INativeObject
	{
		// @property (nonatomic) NMAGeoPolygon * _Nullable outerRing;
		[NullAllowed, Export("outerRing", ArgumentSemantic.Assign)]
		NMAGeoPolygon OuterRing { get; set; }

		// @property (nonatomic) NSMutableArray<NMAGeoPolygon *> * _Nullable innerRings;
		[NullAllowed, Export("innerRings", ArgumentSemantic.Assign)]
		NSMutableArray<NMAGeoPolygon> InnerRings { get; set; }
	}

	// @interface NMACLE2GeometryPolyline : NMACLE2Geometry
	[BaseType(typeof(NMACLE2Geometry))]
	interface NMACLE2GeometryPolyline
	{
		// @property (nonatomic) NMAGeoPolyline * _Nonnull geoPolyline;
		[Export("geoPolyline", ArgumentSemantic.Assign)]
		NMAGeoPolyline GeoPolyline { get; set; }
	}

	// @interface NMACLE2LayerMetadata : NSObject
	[BaseType(typeof(NSObject))]
	interface NMACLE2LayerMetadata : ObjCRuntime.INativeObject
	{
		// @property (readonly, nonatomic) NSString * _Nullable layerId;
		[NullAllowed, Export("layerId")]
		string LayerId { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable timestamp;
		[NullAllowed, Export("timestamp")]
		NSDate Timestamp { get; }
	}

	// @interface NMACLE2OperationResult : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMACLE2OperationResult : ObjCRuntime.INativeObject
	{
		// @property (readonly) NMACLE2OperationType operationType;
		[Export("operationType")]
		NMACLE2OperationType OperationType { get; }

		// @property (readonly) NSNumber * _Nonnull affectedItemCount;
		[Export("affectedItemCount")]
		NSNumber AffectedItemCount { get; }

		// @property (readonly) NSArray<NSString *> * _Nullable affectedLayerIds;
		[NullAllowed, Export("affectedLayerIds")]
		string[] AffectedLayerIds { get; }
	}

	// @interface NMACLE2ProximityRequest : NMACLE2Request
	[BaseType(typeof(NMACLE2Request))]
	interface NMACLE2ProximityRequest
	{
		// -(instancetype _Nullable)initWithLayer:(NSString * _Nonnull)layerId center:(NMAGeoCoordinates * _Nonnull)coordinates radius:(NSInteger)radius;
		[Export("initWithLayer:center:radius:")]
		IntPtr Constructor(string layerId, NMAGeoCoordinates coordinates, nint radius);

		// -(instancetype _Nullable)initWithLayers:(NSArray<NSString *> * _Nonnull)layerIds center:(NMAGeoCoordinates * _Nonnull)coordinates radius:(NSInteger)radius;
		[Export("initWithLayers:center:radius:")]
		IntPtr Constructor(string[] layerIds, NMAGeoCoordinates coordinates, nint radius);
	}

	// @interface NMACLE2QuadkeyRequest : NMACLE2Request
	[BaseType(typeof(NMACLE2Request))]
	interface NMACLE2QuadkeyRequest
	{
		// -(instancetype _Nullable)initWithLayer:(NSString * _Nonnull)layerId quadKey:(NSString * _Nonnull)quadKey;
		[Export("initWithLayer:quadKey:")]
		IntPtr Constructor(string layerId, string quadKey);

		// -(instancetype _Nullable)initWithLayers:(NSArray<NSString *> * _Nonnull)layerIds quadKey:(NSString * _Nonnull)quadKey;
		[Export("initWithLayers:quadKey:")]
		IntPtr Constructor(string[] layerIds, string quadKey);
	}

	// @interface NMACLE2Result : NSObject
	[BaseType(typeof(NSObject))]
	interface NMACLE2Result
	{
		// @property (readonly, nonatomic) NSArray<NMACLE2Geometry *> * _Nullable geometriesArray;
		[NullAllowed, Export("geometriesArray")]
		NMACLE2Geometry[] GeometriesArray { get; }

		// @property (readonly, nonatomic) NMACLE2ConnectivityMode connectivityModeUsed;
		[Export("connectivityModeUsed")]
		NMACLE2ConnectivityMode ConnectivityModeUsed { get; }
	}

	// audit-objc-generics: @interface NMACLE2Task<__covariant ResultType> : NSObject
	[BaseType(typeof(NSObject))]
	interface NMACLE2Task<T>
	{
		// -(void)start;
		[Export("start")]
		void Start();

		// -(void)startWithBlock:(void (^ _Nonnull)(ResultType _Nullable, NSError * _Nullable))listenerBlock;
		[Export("startWithBlock:")]
		void StartWithBlock(Action<NSObject, NSError> listenerBlock);

		// -(void)cancel;
		[Export("cancel")]
		void Cancel();

		// -(BOOL)waitForResult:(NSTimeInterval)timeout;
		[Export("waitForResult:")]
		bool WaitForResult(double timeout);

		// -(void)waitForResult;
		[Export("waitForResult")]
		void WaitForResult();

		// -(void)subscribeWithBlock:(void (^ _Nonnull)(ResultType _Nullable, NSError * _Nullable))subscriberBlock;
		[Export("subscribeWithBlock:")]
		void SubscribeWithBlock(Action<NSObject, NSError> subscriberBlock);

		// -(void)unsubscribeBlock:(void (^ _Nonnull)(ResultType _Nullable, NSError * _Nullable))subscriberBlock;
		[Export("unsubscribeBlock:")]
		void UnsubscribeBlock(Action<NSObject, NSError> subscriberBlock);

		// @property (readonly) ResultType _Nullable result;
		[NullAllowed, Export("result")]
		NSObject Result { get; }

		// @property (readonly) NSError * _Nullable error;
		[NullAllowed, Export("error")]
		NSError Error { get; }

		// @property (readonly) BOOL isFinished;
		[Export("isFinished")]
		bool IsFinished { get; }

		// @property (readonly) BOOL isStarted;
		[Export("isStarted")]
		bool IsStarted { get; }
	}
	*/

	// @interface NMAClusterStyle : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAClusterStyle
	{
	}

	// @interface NMABasicClusterStyle : NMAClusterStyle
	[BaseType(typeof(NMAClusterStyle))]
	interface NMABasicClusterStyle
	{
		// @property (nonatomic) UIColor * _Nonnull fontColor;
		[Export("fontColor", ArgumentSemantic.Assign)]
		UIColor FontColor { get; set; }

		// @property (nonatomic) UIColor * _Nonnull fillColor;
		[Export("fillColor", ArgumentSemantic.Assign)]
		UIColor FillColor { get; set; }

		// @property (nonatomic) UIColor * _Nonnull strokeColor;
		[Export("strokeColor", ArgumentSemantic.Assign)]
		UIColor StrokeColor { get; set; }

		// +(instancetype _Nonnull)style;
		[Static]
		[Export("style")]
		NMABasicClusterStyle Style();

		// +(instancetype _Nonnull)styleWithStrokeColor:(UIColor * _Nonnull)stroke fillColor:(UIColor * _Nonnull)fill fontColor:(UIColor * _Nonnull)font;
		[Static]
		[Export("styleWithStrokeColor:fillColor:fontColor:")]
		NMABasicClusterStyle StyleWithStrokeColor(UIColor stroke, UIColor fill, UIColor font);

		// -(instancetype _Nonnull)initWithStrokeColor:(UIColor * _Nonnull)stroke fillColor:(UIColor * _Nonnull)fill fontColor:(UIColor * _Nonnull)font;
		[Export("initWithStrokeColor:fillColor:fontColor:")]
		IntPtr Constructor(UIColor stroke, UIColor fill, UIColor font);
	}

	// @interface NMAClusterLayer : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAClusterLayer
	{
		// @property (nonatomic) NMAClusterTheme * _Nonnull theme;
		[Export("theme", ArgumentSemantic.Assign)]
		NMAClusterTheme Theme { get; set; }

		// @property (readonly, nonatomic) NSArray * _Nonnull markers;
		[Export("markers")]
		//[Verify(StronglyTypedNSArray)]
		NSObject[] Markers { get; }

		// +(instancetype _Nonnull)clusterLayer;
		[Static]
		[Export("clusterLayer")]
		NMAClusterLayer ClusterLayer();

		// -(BOOL)addMarker:(NMAMapMarker * _Nonnull)marker;
		[Export("addMarker:")]
		bool AddMarker(NMAMapMarker marker);

		// -(BOOL)addMarkers:(NSArray<NMAMapMarker *> * _Nonnull)markers;
		[Export("addMarkers:")]
		bool AddMarkers(NMAMapMarker[] markers);

		// -(BOOL)removeMarker:(NMAMapMarker * _Nonnull)marker;
		[Export("removeMarker:")]
		bool RemoveMarker(NMAMapMarker marker);

		// -(BOOL)removeMarkers:(NSArray<NMAMapMarker *> * _Nonnull)markers;
		[Export("removeMarkers:")]
		bool RemoveMarkers(NMAMapMarker[] markers);
	}

	// @interface NMAClusterTheme : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAClusterTheme
	{
		// +(instancetype _Nonnull)clusterTheme;
		[Static]
		[Export("clusterTheme")]
		NMAClusterTheme ClusterTheme();

		// -(BOOL)setStyle:(NMAClusterStyle * _Nonnull)style forDensityRange:(NSRange)range;
		[Export("setStyle:forDensityRange:")]
		bool SetStyle(NMAClusterStyle style, NSRange range);
	}

	// @interface NMAProxyObject : NMAViewObject
	[BaseType(typeof(NMAViewObject))]
	interface NMAProxyObject
	{
	}

	// @interface NMAClusterViewObject : NMAProxyObject
	[BaseType(typeof(NMAProxyObject))]
	[DisableDefaultCtor]
	interface NMAClusterViewObject
	{
		// @property (readonly, nonatomic) NSArray<NMAMapMarker *> * _Nonnull markers;
		[Export("markers")]
		NMAMapMarker[] Markers { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }
	}

	// @interface NMAImageClusterStyle : NMAClusterStyle
	[BaseType(typeof(NMAClusterStyle))]
	[DisableDefaultCtor]
	interface NMAImageClusterStyle
	{
		// +(instancetype _Nullable)styleWithImage:(NMAImage * _Nullable)image;
		[Static]
		[Export("styleWithImage:")]
		[return: NullAllowed]
		NMAImageClusterStyle StyleWithImage([NullAllowed] NMAImage image);

		// +(instancetype _Nullable)styleWithUIImage:(UIImage * _Nullable)image;
		[Static]
		[Export("styleWithUIImage:")]
		[return: NullAllowed]
		NMAImageClusterStyle StyleWithUIImage([NullAllowed] UIImage image);

		// -(instancetype _Nullable)initWithImage:(NMAImage * _Nullable)image;
		[Export("initWithImage:")]
		IntPtr Constructor([NullAllowed] NMAImage image);

		// -(instancetype _Nullable)initWithUIImage:(UIImage * _Nullable)image;
		[Export("initWithUIImage:")]
		IntPtr Constructor([NullAllowed] UIImage image);
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMAApplicationContextOnlineStatusDidChangeNotification;
		[Field("NMAApplicationContextOnlineStatusDidChangeNotification", "__Internal")]
		NSString NMAApplicationContextOnlineStatusDidChangeNotification { get; }

		// extern NSString *const _Nonnull NMAApplicationContextLicenseKeyExpiredNotification;
		[Field("NMAApplicationContextLicenseKeyExpiredNotification", "__Internal")]
		NSString NMAApplicationContextLicenseKeyExpiredNotification { get; }
	}

	// @interface NMAApplicationContext : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAApplicationContext
	{
		// +(NMAApplicationContextError)setAppId:(NSString * _Nonnull)appId appCode:(NSString * _Nonnull)appCode licenseKey:(NSString * _Nonnull)licenseKey;
		[Static]
		[Export("setAppId:appCode:licenseKey:")]
		NMAApplicationContextError SetAppId(string appId, string appCode, string licenseKey);

		// +(NMAApplicationContextError)setAppId:(NSString * _Nonnull)appId appCode:(NSString * _Nonnull)appCode licenseKey:(NSString * _Nonnull)licenseKey mapVariant:(NMAMapVariant)mapVariant;
		[Static]
		[Export("setAppId:appCode:licenseKey:mapVariant:")]
		NMAApplicationContextError SetAppId(string appId, string appCode, string licenseKey, NMAMapVariant mapVariant);

		// +(NSString * _Nullable)licenseKey;
		[Static]
		[NullAllowed, Export("licenseKey")]
		//[Verify(MethodToProperty)]
		string LicenseKey { get; }

		// +(void)setMapCenter:(NMAGeoCoordinates * _Nonnull)initialCenter;
		[Static]
		[Export("setMapCenter:")]
		void SetMapCenter(NMAGeoCoordinates initialCenter);

		// +(NSString * _Nonnull)sdkVersion;
		[Static]
		[Export("sdkVersion")]
		//[Verify(MethodToProperty)]
		string SdkVersion { get; }

		// +(void)setNetworkAccessAllowed:(BOOL)networkAccessAllowed;
		[Static]
		[Export("setNetworkAccessAllowed:")]
		void SetNetworkAccessAllowed(bool networkAccessAllowed);

		// +(BOOL)isNetworkAccessAllowed;
		[Static]
		[Export("isNetworkAccessAllowed")]
		//[Verify(MethodToProperty)]
		bool IsNetworkAccessAllowed { get; }

		// +(BOOL)enableTrafficInOfflineMode:(BOOL)enable;
		[Static]
		[Export("enableTrafficInOfflineMode:")]
		bool EnableTrafficInOfflineMode(bool enable);

		// +(BOOL)isOnline;
		[Static]
		[Export("isOnline")]
		//[Verify(MethodToProperty)]
		bool IsOnline { get; }

		// +(BOOL)isInitialized;
		[Static]
		[Export("isInitialized")]
		//[Verify(MethodToProperty)]
		bool IsInitialized { get; }

		// +(void)disableSdkVersionInCrashStack;
		[Static]
		[Export("disableSdkVersionInCrashStack")]
		void DisableSdkVersionInCrashStack();

		// +(BOOL)setDiskCacheSize:(NSUInteger)size;
		[Static]
		[Export("setDiskCacheSize:")]
		bool SetDiskCacheSize(nuint size);

		// +(NSString * _Nullable)getMapApprovalCodeWithCountry:(NSLocale * _Nonnull)locale;
		[Static]
		[Export("getMapApprovalCodeWithCountry:")]
		[return: NullAllowed]
		string GetMapApprovalCodeWithCountry(NSLocale locale);

		// +(NSString * _Nullable)getMapDataProviderCopyrightStatementWithCountry:(NSLocale * _Nonnull)locale;
		[Static]
		[Export("getMapDataProviderCopyrightStatementWithCountry:")]
		[return: NullAllowed]
		string GetMapDataProviderCopyrightStatementWithCountry(NSLocale locale);

		// +(void)enableEnhancedMapMatcher:(BOOL)enabled __attribute__((deprecated("")));
		[Static]
		[Export("enableEnhancedMapMatcher:")]
		void EnableEnhancedMapMatcher(bool enabled);
	}

	// typedef void (^NMAAudioOutputEventBlock)(NMAAudioOutputEvent);
	delegate void NMAAudioOutputEventBlock(NMAAudioOutputEvent arg0);

	// @interface NMAAudioOutput : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAAudioOutput
	{
		// @property (nonatomic, strong) NMAAudioOutputEventBlock _Nullable eventBlock;
		[NullAllowed, Export("eventBlock", ArgumentSemantic.Strong)]
		NMAAudioOutputEventBlock EventBlock { get; set; }

		// @property (nonatomic) NMAAudioOutputSource source;
		[Export("source", ArgumentSemantic.Assign)]
		NMAAudioOutputSource Source { get; set; }

		// @property (nonatomic) float volume;
		[Export("volume")]
		float Volume { get; set; }

		// -(void)play;
		[Export("play")]
		void Play();

		// -(void)stop;
		[Export("stop")]
		void Stop();
	}

	// @interface NMAAudioFileOutput : NMAAudioOutput
	[BaseType(typeof(NMAAudioOutput))]
	[DisableDefaultCtor]
	interface NMAAudioFileOutput
	{
		// -(instancetype _Nullable)initWithFiles:(NSArray<NSString *> * _Nonnull)files __attribute__((objc_designated_initializer));
		[Export("initWithFiles:")]
		[DesignatedInitializer]
		IntPtr Constructor(string[] files);

		// +(instancetype _Nullable)audioOutputWithFiles:(NSArray<NSString *> * _Nonnull)files;
		[Static]
		[Export("audioOutputWithFiles:")]
		[return: NullAllowed]
		NMAAudioFileOutput AudioOutputWithFiles(string[] files);

		// @property (nonatomic) BOOL deleteWhenFinished;
		[Export("deleteWhenFinished")]
		bool DeleteWhenFinished { get; set; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMAAudioRouteDidChangeNotification;
		[Field("NMAAudioRouteDidChangeNotification", "__Internal")]
		NSString NMAAudioRouteDidChangeNotification { get; }
	}

	// @protocol NMAAudioManagerDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAAudioManagerDelegate
	{
		// @optional -(BOOL)audioManager:(NMAAudioManager * _Nonnull)audioManager shouldPlayOutput:(NMAAudioOutput * _Nonnull)output;
		[Export("audioManager:shouldPlayOutput:")]
		bool AudioManager(NMAAudioManager audioManager, NMAAudioOutput output);

		// @optional -(void)audioManagerWillPlayOutput:(NMAAudioManager * _Nonnull)audioManager;
		[Export("audioManagerWillPlayOutput:")]
		void AudioManagerWillPlayOutput(NMAAudioManager audioManager);

		// @optional -(void)audioManagerDidPlayOutput:(NMAAudioManager * _Nonnull)audioManager;
		[Export("audioManagerDidPlayOutput:")]
		void AudioManagerDidPlayOutput(NMAAudioManager audioManager);
	}

	// @interface NMAAudioManager : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAAudioManager
	{
		// +(NMAAudioManager * _Nonnull)sharedAudioManager;
		[Static]
		[Export("sharedAudioManager")]
		//[Verify(MethodToProperty)]
		NMAAudioManager SharedAudioManager { get; }

		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMAAudioManagerDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMAAudioManagerDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// @property (nonatomic) BOOL managesAudioSession;
		[Export("managesAudioSession")]
		bool ManagesAudioSession { get; set; }

		// -(void)playOutput:(NMAAudioOutput * _Nonnull)output;
		[Export("playOutput:")]
		void PlayOutput(NMAAudioOutput output);

		// -(void)skipCurrentOutput;
		[Export("skipCurrentOutput")]
		void SkipCurrentOutput();

		// -(void)stopOutputAndClearQueue;
		[Export("stopOutputAndClearQueue")]
		void StopOutputAndClearQueue();

		// -(void)clearQueue;
		[Export("clearQueue")]
		void ClearQueue();

		// -(BOOL)setAudioRoute:(NMAAudioRoute)audioRoute;
		[Export("setAudioRoute:")]
		bool SetAudioRoute(NMAAudioRoute audioRoute);

		// @property (readonly, nonatomic) NMAAudioRoute audioRoute;
		[Export("audioRoute")]
		NMAAudioRoute AudioRoute { get; }

		// @property (nonatomic) NSTimeInterval audioRouteLatencyCompensation;
		[Export("audioRouteLatencyCompensation")]
		double AudioRouteLatencyCompensation { get; set; }

		// @property (nonatomic) float volume;
		[Export("volume")]
		float Volume { get; set; }

		// @property (nonatomic) BOOL captureHardwareVolumeKeys;
		[Export("captureHardwareVolumeKeys")]
		bool CaptureHardwareVolumeKeys { get; set; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const float NMARoutingModeStartDirectionAny;
		[Field("NMARoutingModeStartDirectionAny", "__Internal")]
		float NMARoutingModeStartDirectionAny { get; }
	}

	// @interface NMARoutingMode : NSObject
	[BaseType(typeof(NSObject))]
	interface NMARoutingMode
	{
		// -(instancetype _Nonnull)initWithRoutingType:(NMARoutingType)routingType transportMode:(NMATransportMode)transportMode routingOptions:(NMARoutingOption)routingOptions;
		[Export("initWithRoutingType:transportMode:routingOptions:")]
		IntPtr Constructor(NMARoutingType routingType, NMATransportMode transportMode, NMARoutingOption routingOptions);

		// @property (nonatomic) NMARoutingType routingType;
		[Export("routingType", ArgumentSemantic.Assign)]
		NMARoutingType RoutingType { get; set; }

		// @property (nonatomic) NMATransportMode transportMode;
		[Export("transportMode", ArgumentSemantic.Assign)]
		NMATransportMode TransportMode { get; set; }

		// @property (nonatomic) NMASpeedProfile speedProfile;
		[Export("speedProfile", ArgumentSemantic.Assign)]
		NMASpeedProfile SpeedProfile { get; set; }

		// @property (nonatomic) NMARoutingOption routingOptions;
		[Export("routingOptions", ArgumentSemantic.Assign)]
		NMARoutingOption RoutingOptions { get; set; }

		// @property (nonatomic, strong) NSDate * _Nullable departureTime;
		[NullAllowed, Export("departureTime", ArgumentSemantic.Strong)]
		NSDate DepartureTime { get; set; }

		// @property (nonatomic) NSUInteger resultLimit;
		[Export("resultLimit")]
		nuint ResultLimit { get; set; }

		// @property (nonatomic) float startDirection;
		[Export("startDirection")]
		float StartDirection { get; set; }

		// @property (nonatomic) NSUInteger deviationDistanceToPedestrianReroute;
		[Export("deviationDistanceToPedestrianReroute")]
		nuint DeviationDistanceToPedestrianReroute { get; set; }

		// @property (nonatomic) NSArray<NSString *> * _Nonnull excludeRoutingZones;
		[Export("excludeRoutingZones", ArgumentSemantic.Assign)]
		string[] ExcludeRoutingZones { get; set; }

		// @property (copy, nonatomic) NSArray<NSString *> * _Nonnull excludedCountries;
		[Export("excludedCountries", ArgumentSemantic.Copy)]
		string[] ExcludedCountries { get; set; }

		// @property (nonatomic) NSString * _Nullable licensePlateLastCharacter;
		[NullAllowed, Export("licensePlateLastCharacter")]
		string LicensePlateLastCharacter { get; set; }

		// @property (nonatomic) NSString * _Nullable languagePreference;
		[NullAllowed, Export("languagePreference")]
		string LanguagePreference { get; set; }
	}

	// @interface NMARouteTta : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARouteTta
	{
		// @property (readonly, nonatomic) NSTimeInterval duration;
		[Export("duration")]
		double Duration { get; }

		// @property (readonly, nonatomic) NMARouteDurationDetail details;
		[Export("details")]
		NMARouteDurationDetail Details { get; }

		// @property (readonly, getter = isBlocked, nonatomic) BOOL blocked;
		[Export("blocked")]
		bool Blocked { [Bind("isBlocked")] get; }
	}

	// @interface NMADynamicPenalty : NSObject
	[BaseType(typeof(NSObject))]
	interface NMADynamicPenalty
	{
		// -(BOOL)addBannedArea:(NMAMapPolygon * _Nonnull)area;
		[Export("addBannedArea:")]
		bool AddBannedArea(NMAMapPolygon area);

		// -(BOOL)removeBannedArea:(NMAMapPolygon * _Nonnull)area;
		[Export("removeBannedArea:")]
		bool RemoveBannedArea(NMAMapPolygon area);

		// -(void)removeAllAreaPenalties;
		[Export("removeAllAreaPenalties")]
		void RemoveAllAreaPenalties();

		// -(BOOL)addPenaltyForRoadElement:(NMARoadElement * _Nonnull)element withDrivingDirection:(NMADrivingDirection)direction speed:(NSUInteger)newSpeed;
		[Export("addPenaltyForRoadElement:withDrivingDirection:speed:")]
		bool AddPenaltyForRoadElement(NMARoadElement element, NMADrivingDirection direction, nuint newSpeed);

		// -(BOOL)removePenaltyForRoadElement:(NMARoadElement * _Nonnull)element;
		[Export("removePenaltyForRoadElement:")]
		bool RemovePenaltyForRoadElement(NMARoadElement element);

		// -(void)removeAllRoadElementPenalties;
		[Export("removeAllRoadElementPenalties")]
		void RemoveAllRoadElementPenalties();

		// @property (nonatomic) NMATrafficPenaltyMode trafficPenaltyMode;
		[Export("trafficPenaltyMode", ArgumentSemantic.Assign)]
		NMATrafficPenaltyMode TrafficPenaltyMode { get; set; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const NSInteger NMARouteSublegWhole;
		[Field("NMARouteSublegWhole", "__Internal")]
		nint NMARouteSublegWhole { get; }
	}

	// typedef void (^NMARouteSerializationCompletionBlock)(NSData * _Nullable, NSError * _Nullable);
	delegate void NMARouteSerializationCompletionBlock([NullAllowed] NSData arg0, [NullAllowed] NSError arg1);

	// typedef void (^NMARouteDeserializationCompletionBlock)(NMARoute * _Nullable, NSError * _Nullable);
	delegate void NMARouteDeserializationCompletionBlock([NullAllowed] NMARoute arg0, [NullAllowed] NSError arg1);

	// @interface NMARoute : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARoute
	{
		// +(void)routeFromSerializedRoute:(NSData * _Nonnull)data withCompletion:(NMARouteDeserializationCompletionBlock _Nonnull)completionBlock;
		[Static]
		[Export("routeFromSerializedRoute:withCompletion:")]
		void RouteFromSerializedRoute(NSData data, NMARouteDeserializationCompletionBlock completionBlock);

		// @property (readonly, nonatomic, weak) NMAWaypoint * _Nullable start;
		[NullAllowed, Export("start", ArgumentSemantic.Weak)]
		NMAWaypoint Start { get; }

		// @property (readonly, nonatomic, weak) NMAWaypoint * _Nullable destination;
		[NullAllowed, Export("destination", ArgumentSemantic.Weak)]
		NMAWaypoint Destination { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAWaypoint *> * _Nullable waypoints;
		[NullAllowed, Export("waypoints", ArgumentSemantic.Strong)]
		NMAWaypoint[] Waypoints { get; }

		// @property (readonly, nonatomic) NSArray<NSNumber *> * _Nonnull permanentLinkIds;
		[Export("permanentLinkIds")]
		NSNumber[] PermanentLinkIds { get; }

		// @property (readonly, nonatomic) NSArray<NSNumber *> * _Nonnull permanentDirectedLinkIds;
		[Export("permanentDirectedLinkIds")]
		NSNumber[] PermanentDirectedLinkIds { get; }

		// @property (readonly, nonatomic) NSUInteger length;
		[Export("length")]
		nuint Length { get; }

		// -(NSUInteger)lengthForSubleg:(NSUInteger)subleg;
		[Export("lengthForSubleg:")]
		nuint LengthForSubleg(nuint subleg);

		// @property (readonly, nonatomic) NSUInteger sublegCount;
		[Export("sublegCount")]
		nuint SublegCount { get; }

		// -(NMARouteConsumption * _Nullable)consumptionWithParameters:(NMARouteConsumptionParameters * _Nonnull)consumptionParameters dynamicPenalty:(NMADynamicPenalty * _Nullable)dynamicPenalty;
		[Export("consumptionWithParameters:dynamicPenalty:")]
		[return: NullAllowed]
		NMARouteConsumption ConsumptionWithParameters(NMARouteConsumptionParameters consumptionParameters, [NullAllowed] NMADynamicPenalty dynamicPenalty);

		// -(NMAGeoCoordinates * _Nullable)lastReachablePositionWithConsumption:(NMARouteConsumption * _Nonnull)routeConsumption currentCapacity:(NSInteger)capacity;
		[Export("lastReachablePositionWithConsumption:currentCapacity:")]
		[return: NullAllowed]
		NMAGeoCoordinates LastReachablePositionWithConsumption(NMARouteConsumption routeConsumption, nint capacity);

		// @property (readonly, nonatomic, strong) NMAGeoBoundingBox * _Nullable boundingBox;
		[NullAllowed, Export("boundingBox", ArgumentSemantic.Strong)]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAManeuver *> * _Nullable maneuvers;
		[NullAllowed, Export("maneuvers", ArgumentSemantic.Strong)]
		NMAManeuver[] Maneuvers { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAGeoCoordinates *> * _Nullable geometry;
		[NullAllowed, Export("geometry", ArgumentSemantic.Strong)]
		NMAGeoCoordinates[] Geometry { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAGeoCoordinates *> * _Nullable geometryWithElevationData;
		[NullAllowed, Export("geometryWithElevationData", ArgumentSemantic.Strong)]
		NMAGeoCoordinates[] GeometryWithElevationData { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMARouteElement *> * _Nullable routeElements;
		[NullAllowed, Export("routeElements", ArgumentSemantic.Strong)]
		NMARouteElement[] RouteElements { get; }

		// @property (readonly, nonatomic, strong) NMARoutingMode * _Nonnull routingMode;
		[Export("routingMode", ArgumentSemantic.Strong)]
		NMARoutingMode RoutingMode { get; }

		// @property (nonatomic, strong) NSString * _Nullable userTag;
		[NullAllowed, Export("userTag", ArgumentSemantic.Strong)]
		string UserTag { get; set; }

		// -(NMARouteTta * _Nullable)ttaIncludingTrafficForSubleg:(NSUInteger)subleg;
		[Export("ttaIncludingTrafficForSubleg:")]
		[return: NullAllowed]
		NMARouteTta TtaIncludingTrafficForSubleg(nuint subleg);

		// -(NMARouteTta * _Nullable)ttaUsingDownloadedTrafficForSubleg:(NSUInteger)subleg;
		[Export("ttaUsingDownloadedTrafficForSubleg:")]
		[return: NullAllowed]
		NMARouteTta TtaUsingDownloadedTrafficForSubleg(nuint subleg);

		// -(NMARouteTta * _Nullable)ttaExcludingTrafficForSubleg:(NSUInteger)subleg;
		[Export("ttaExcludingTrafficForSubleg:")]
		[return: NullAllowed]
		NMARouteTta TtaExcludingTrafficForSubleg(nuint subleg);

		// -(void)serializedRouteWithCompletionBlock:(NMARouteSerializationCompletionBlock _Nonnull)completionBlock;
		[Export("serializedRouteWithCompletionBlock:")]
		void SerializedRouteWithCompletionBlock(NMARouteSerializationCompletionBlock completionBlock);

		// -(NSArray<NMARouteElement *> * _Nullable)routeElementsFromManeuver:(NMAManeuver * _Nonnull)maneuver error:(NSError * _Nullable * _Nullable)error;
		[Export("routeElementsFromManeuver:error:")]
		[return: NullAllowed]
		NMARouteElement[] RouteElementsFromManeuver(NMAManeuver maneuver, [NullAllowed] out NSError error);

		// -(NSArray<NMARouteElement *> * _Nullable)routeElementsFromDuration:(NSTimeInterval)duration error:(NSError * _Nullable * _Nullable)error;
		[Export("routeElementsFromDuration:error:")]
		[return: NullAllowed]
		NMARouteElement[] RouteElementsFromDuration(double duration, [NullAllowed] out NSError error);

		// -(NSArray<NMARouteElement *> * _Nullable)routeElementsFromStartTime:(NSTimeInterval)startTime duration:(NSTimeInterval)duration error:(NSError * _Nullable * _Nullable)error;
		[Export("routeElementsFromStartTime:duration:error:")]
		[return: NullAllowed]
		NMARouteElement[] RouteElementsFromStartTime(double startTime, double duration, [NullAllowed] out NSError error);

		// -(NSArray<NMARouteElement *> * _Nullable)routeElementsFromLength:(NSUInteger)length error:(NSError * _Nullable * _Nullable)error;
		[Export("routeElementsFromLength:error:")]
		[return: NullAllowed]
		NMARouteElement[] RouteElementsFromLength(nuint length, [NullAllowed] out NSError error);

		// -(NSArray<NMARouteElement *> * _Nullable)routeElementsFromStartDistance:(NSUInteger)startDistance length:(NSUInteger)length error:(NSError * _Nullable * _Nullable)error;
		[Export("routeElementsFromStartDistance:length:error:")]
		[return: NullAllowed]
		NMARouteElement[] RouteElementsFromStartDistance(nuint startDistance, nuint length, [NullAllowed] out NSError error);

		// -(NSUInteger)distanceFromRouteElement:(NSUInteger)fromRouteElement fromPosition:(NMAGeoCoordinates * _Nonnull)fromPosition toRouteElement:(NSUInteger)toRouteElement toPosition:(NMAGeoCoordinates * _Nonnull)toPosition;
		[Export("distanceFromRouteElement:fromPosition:toRouteElement:toPosition:")]
		nuint DistanceFromRouteElement(nuint fromRouteElement, NMAGeoCoordinates fromPosition, nuint toRouteElement, NMAGeoCoordinates toPosition);

		// @property (readonly, nonatomic) NSArray<NMARoutingZone *> * _Nonnull routingZones;
		[Export("routingZones")]
		NMARoutingZone[] RoutingZones { get; }

		// -(NSArray<NSString *> * _Nonnull)instructionsForLanguage:(NSString * _Nonnull)language unitSystem:(NMARouteInstructionsUnitSystem)unitSystem;
		[Export("instructionsForLanguage:unitSystem:")]
		string[] InstructionsForLanguage(string language, NMARouteInstructionsUnitSystem unitSystem);
	}

	// @interface NMAManeuver : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAManeuver
	{
		// @property (readonly, nonatomic) NSUInteger angle;
		[Export("angle")]
		nuint Angle { get; }

		// @property (readonly, nonatomic, weak) NMAGeoCoordinates * _Nullable coordinates;
		[NullAllowed, Export("coordinates", ArgumentSemantic.Weak)]
		NMAGeoCoordinates Coordinates { get; }

		// @property (readonly, nonatomic) NMAManeuverAction action;
		[Export("action")]
		NMAManeuverAction Action { get; }

		// @property (readonly, nonatomic) NMAManeuverTurn turn;
		[Export("turn")]
		NMAManeuverTurn Turn { get; }

		// @property (readonly, nonatomic) NSUInteger distanceFromStart;
		[Export("distanceFromStart")]
		nuint DistanceFromStart { get; }

		// @property (readonly, nonatomic) NSUInteger distanceFromPreviousManeuver;
		[Export("distanceFromPreviousManeuver")]
		nuint DistanceFromPreviousManeuver { get; }

		// @property (readonly, nonatomic) NSUInteger distanceToNextManeuver;
		[Export("distanceToNextManeuver")]
		nuint DistanceToNextManeuver { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable roadName;
		[NullAllowed, Export("roadName", ArgumentSemantic.Weak)]
		string RoadName { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable nextRoadName;
		[NullAllowed, Export("nextRoadName", ArgumentSemantic.Weak)]
		string NextRoadName { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable roadNumber;
		[NullAllowed, Export("roadNumber", ArgumentSemantic.Weak)]
		string RoadNumber { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable nextRoadNumber;
		[NullAllowed, Export("nextRoadNumber", ArgumentSemantic.Weak)]
		string NextRoadNumber { get; }

		// @property (readonly, nonatomic) NMAManeuverIcon icon;
		[Export("icon")]
		NMAManeuverIcon Icon { get; }

		// @property (readonly, nonatomic, weak) NSDate * _Nullable startTime;
		[NullAllowed, Export("startTime", ArgumentSemantic.Weak)]
		NSDate StartTime { get; }

		// @property (readonly, nonatomic) NSUInteger mapOrientation;
		[Export("mapOrientation")]
		nuint MapOrientation { get; }

		// @property (readonly, nonatomic) NSArray<NMAGeoCoordinates *> * _Nonnull maneuverGeometry;
		[Export("maneuverGeometry")]
		NMAGeoCoordinates[] ManeuverGeometry { get; }

		// @property (readonly, nonatomic) NMATransportMode transportMode;
		[Export("transportMode")]
		NMATransportMode TransportMode { get; }

		// @property (readonly, nonatomic) NMAImage * _Nullable nextRoadIcon;
		[NullAllowed, Export("nextRoadIcon")]
		NMAImage NextRoadIcon { get; }

		// @property (readonly, nonatomic) NMASignpost * _Nullable signpost;
		[NullAllowed, Export("signpost")]
		NMASignpost Signpost { get; }

		// @property (readonly, nonatomic) NMAManeuverTrafficDirection trafficDirection;
		[Export("trafficDirection")]
		NMAManeuverTrafficDirection TrafficDirection { get; }

		// @property (readonly, nonatomic) NSArray<NMARouteElement *> * _Nonnull routeElements;
		[Export("routeElements")]
		NMARouteElement[] RouteElements { get; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMANavigationManagerErrorDomain;
		[Field("NMANavigationManagerErrorDomain", "__Internal")]
		NSString NMANavigationManagerErrorDomain { get; }

		// extern const NMAUint64 NMANavigationManagerInvalidValue;
		[Field("NMANavigationManagerInvalidValue", "__Internal")]
		ulong NMANavigationManagerInvalidValue { get; }

		// extern NSString *const _Nonnull NMANavigationManagerStateChangedNotification;
		[Field("NMANavigationManagerStateChangedNotification", "__Internal")]
		NSString NMANavigationManagerStateChangedNotification { get; }

		// extern NSString *const _Nonnull NMANavigationManagerSignpostKey;
		[Field("NMANavigationManagerSignpostKey", "__Internal")]
		NSString NMANavigationManagerSignpostKey { get; }

		// extern NSString *const _Nonnull NMANavigationManagerJunctionViewKey;
		[Field("NMANavigationManagerJunctionViewKey", "__Internal")]
		NSString NMANavigationManagerJunctionViewKey { get; }

		// extern id  _Nonnull const NMARealisticView16x9Key;
		[Field("NMARealisticView16x9Key", "__Internal")]
		IntPtr NMARealisticView16x9Key { get; }

		// extern id  _Nonnull const NMARealisticView3x5Key;
		[Field("NMARealisticView3x5Key", "__Internal")]
		IntPtr NMARealisticView3x5Key { get; }

		// extern id  _Nonnull const NMARealisticView5x3Key;
		[Field("NMARealisticView5x3Key", "__Internal")]
		IntPtr NMARealisticView5x3Key { get; }

		// extern id  _Nonnull const NMARealisticView4x3Key;
		[Field("NMARealisticView4x3Key", "__Internal")]
		IntPtr NMARealisticView4x3Key { get; }
	}

	// @protocol NMANavigationManagerDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMANavigationManagerDelegate
	{
		// @optional -(void)navigationManagerDidReachDestination:(NMANavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerDidReachDestination:")]
		void NavigationManagerDidReachDestination(NMANavigationManager navigationManager);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager hasCurrentManeuver:(NMAManeuver * _Nullable)currentManeuver nextManeuver:(NMAManeuver * _Nullable)nextManeuver;
		[Export("navigationManager:hasCurrentManeuver:nextManeuver:")]
		void NavigationManagerHasCurrentManeuver(NMANavigationManager navigationManager, [NullAllowed] NMAManeuver currentManeuver, [NullAllowed] NMAManeuver nextManeuver);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didReachStopover:(NMAWaypoint * _Nonnull)stopover;
		[Export("navigationManager:didReachStopover:")]
		void NavigationManagerDidReachStopover(NMANavigationManager navigationManager, NMAWaypoint stopover);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didUpdateRouteWithResult:(NMARouteResult * _Nonnull)routeResult;
		[Export("navigationManager:didUpdateRouteWithResult:")]
		void NavigationManagerDidUpdateRouteWithResult(NMANavigationManager navigationManager, NMARouteResult routeResult);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didUpdateLaneInformation:(NSArray<NMALaneInformation *> * _Nonnull)laneInformations roadElement:(NMARoadElement * _Nullable)roadElement;
		[Export("navigationManager:didUpdateLaneInformation:roadElement:")]
		void NavigationManagerDidUpdateLaneInformation(NMANavigationManager navigationManager, NMALaneInformation[] laneInformations, [NullAllowed] NMARoadElement roadElement);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didUpdateRealisticViewsForCurrentManeuver:(NSDictionary<NSNumber *,NSDictionary<NSString *,NMAImage *> *> * _Nonnull)realisticViews;
		[Export("navigationManager:didUpdateRealisticViewsForCurrentManeuver:")]
		void NavigationManagerDidUpdateRealisticViewsForCurrentManeuver(NMANavigationManager navigationManager, NSDictionary<NSNumber, NSDictionary<NSString, NMAImage>> realisticViews);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didUpdateRealisticViewsForNextManeuver:(NSDictionary<NSNumber *,NSDictionary<NSString *,NMAImage *> *> * _Nonnull)realisticViews;
		[Export("navigationManager:didUpdateRealisticViewsForNextManeuver:")]
		void NavigationManagerDidUpdateRealisticViewsForNextManeuver(NMANavigationManager navigationManager, NSDictionary<NSNumber, NSDictionary<NSString, NMAImage>> realisticViews);

		// @optional -(void)navigationManagerDidInvalidateRealisticViews:(NMANavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerDidInvalidateRealisticViews:")]
		void NavigationManagerDidInvalidateRealisticViews(NMANavigationManager navigationManager);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didUpdateSpeedingStatus:(BOOL)isSpeeding forCurrentSpeed:(float)speed speedLimit:(float)speedLimit;
		[Export("navigationManager:didUpdateSpeedingStatus:forCurrentSpeed:speedLimit:")]
		void NavigationManagerDidUpdateSpeedingStatus(NMANavigationManager navigationManager, bool isSpeeding, float speed, float speedLimit);

		// @optional -(void)navigationManagerDidLosePosition:(NMANavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerDidLosePosition:")]
		void NavigationManagerDidLosePosition(NMANavigationManager navigationManager);

		// @optional -(void)navigationManagerDidFindPosition:(NMANavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerDidFindPosition:")]
		void NavigationManagerDidFindPosition(NMANavigationManager navigationManager);

		// @optional -(void)navigationManagerWillReroute:(NMANavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerWillReroute:")]
		void NavigationManagerWillReroute(NMANavigationManager navigationManager);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didRerouteWithError:(NMARoutingError)error;
		[Export("navigationManager:didRerouteWithError:")]
		void NavigationManagerDidRerouteWithError(NMANavigationManager navigationManager, NMARoutingError error);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didFindAlternateRouteWithResult:(NMARouteResult * _Nonnull)routeResult;
		[Export("navigationManager:didFindAlternateRouteWithResult:")]
		void NavigationManagerDidFindAlternateRouteWithResult(NMANavigationManager navigationManager, NMARouteResult routeResult);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didChangeRoutingState:(NMATrafficEnabledRoutingState)state;
		[Export("navigationManager:didChangeRoutingState:")]
		void NavigationManagerDidChangeRoutingState(NMANavigationManager navigationManager, NMATrafficEnabledRoutingState state);

		// @optional -(BOOL)navigationManager:(NMANavigationManager * _Nonnull)navigationManager shouldPlayVoiceFeedbackWithText:(NSString * _Nullable)text;
		[Export("navigationManager:shouldPlayVoiceFeedbackWithText:")]
		bool NavigationManagerShouldPlayVoiceFeedbackWithText(NMANavigationManager navigationManager, [NullAllowed] string text);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager willPlayVoiceFeedbackWithText:(NSString * _Nullable)text;
		[Export("navigationManager:willPlayVoiceFeedbackWithText:")]
		void NavigationManagerWillPlayVoiceFeedbackWithText(NMANavigationManager navigationManager, [NullAllowed] string text);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didPlayVoiceFeedbackWithText:(NSString * _Nullable)text;
		[Export("navigationManager:didPlayVoiceFeedbackWithText:")]
		void NavigationManagerDidPlayVoiceFeedbackWithText(NMANavigationManager navigationManager, [NullAllowed] string text);

		// @optional -(void)navigationManagerDidSuspendDueToInsufficientMapData:(NMANavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerDidSuspendDueToInsufficientMapData:")]
		void NavigationManagerDidSuspendDueToInsufficientMapData(NMANavigationManager navigationManager);

		// @optional -(void)navigationManagerDidResumeDueToMapDataAvailability:(NMANavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerDidResumeDueToMapDataAvailability:")]
		void NavigationManagerDidResumeDueToMapDataAvailability(NMANavigationManager navigationManager);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didFindAlternateRoutes:(NMARouteResult * _Nonnull)routeResult;
		[Export("navigationManager:didFindAlternateRoutes:")]
		void NavigationManagerDidFindAlternateRoutes(NMANavigationManager navigationManager, NMARouteResult routeResult);

		// @optional -(void)navigationManager:(NMANavigationManager * _Nonnull)navigationManager didUpdateCountry:(NSString * _Nonnull)previousCountry nextCountry:(NSString * _Nonnull)nextCountry;
		[Export("navigationManager:didUpdateCountry:nextCountry:")]
		void NavigationManagerDidUpdateCountry(NMANavigationManager navigationManager, string previousCountry, string nextCountry);
	}

	// @interface NMANavigationManager : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMANavigationManager
	{
		// +(NMANavigationManager * _Nonnull)sharedNavigationManager;
		[Static]
		[Export("sharedNavigationManager")]
		//[Verify(MethodToProperty)]
		NMANavigationManager SharedNavigationManager { get; }

		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMANavigationManagerDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMANavigationManagerDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// @property (readonly, nonatomic) NMANavigationState navigationState;
		[Export("navigationState")]
		NMANavigationState NavigationState { get; }

		// @property (readonly, nonatomic) NMANavigationMode navigationMode;
		[Export("navigationMode")]
		NMANavigationMode NavigationMode { get; }

		// @property (nonatomic, weak) NMAMapView * _Nullable map;
		[NullAllowed, Export("map", ArgumentSemantic.Weak)]
		NMAMapView Map { get; set; }

		// @property (nonatomic) BOOL mapTrackingEnabled;
		[Export("mapTrackingEnabled")]
		bool MapTrackingEnabled { get; set; }

		// @property (nonatomic) NMAMapTrackingOrientation mapTrackingOrientation;
		[Export("mapTrackingOrientation", ArgumentSemantic.Assign)]
		NMAMapTrackingOrientation MapTrackingOrientation { get; set; }

		// @property (nonatomic) BOOL mapTrackingAutoZoomEnabled;
		[Export("mapTrackingAutoZoomEnabled")]
		bool MapTrackingAutoZoomEnabled { get; set; }

		// @property (nonatomic) NMAMapTrackingTilt mapTrackingTilt;
		[Export("mapTrackingTilt", ArgumentSemantic.Assign)]
		NMAMapTrackingTilt MapTrackingTilt { get; set; }

		// @property (nonatomic) float backgroundMapTrackingMaximumRefreshRate;
		[Export("backgroundMapTrackingMaximumRefreshRate")]
		float BackgroundMapTrackingMaximumRefreshRate { get; set; }

		// @property (readonly, nonatomic) NMAManeuver * _Nullable currentManeuver;
		[NullAllowed, Export("currentManeuver")]
		NMAManeuver CurrentManeuver { get; }

		// @property (readonly, nonatomic) NMAManeuver * _Nullable nextManeuver;
		[NullAllowed, Export("nextManeuver")]
		NMAManeuver NextManeuver { get; }

		// @property (readonly, nonatomic) NMAUint64 distanceToCurrentManeuver;
		[Export("distanceToCurrentManeuver")]
		ulong DistanceToCurrentManeuver { get; }

		// @property (readonly, nonatomic) NMAUint64 distanceToNextManeuver;
		[Export("distanceToNextManeuver")]
		ulong DistanceToNextManeuver { get; }

		// @property (readonly, nonatomic) NMAUint64 distanceToDestination;
		[Export("distanceToDestination")]
		ulong DistanceToDestination { get; }

		// @property (readonly, nonatomic) NMAUint64 distanceFromStart;
		[Export("distanceFromStart")]
		ulong DistanceFromStart { get; }

		// @property (readonly, nonatomic) double averageSpeed;
		[Export("averageSpeed")]
		double AverageSpeed { get; }

		// @property (readonly, nonatomic) NSTimeInterval timeToArrival;
		[Export("timeToArrival")]
		double TimeToArrival { get; }

		// -(NSTimeInterval)timeToArrivalWithTraffic:(NMATrafficPenaltyMode)mode wholeRoute:(BOOL)wholeRoute;
		[Export("timeToArrivalWithTraffic:wholeRoute:")]
		double TimeToArrivalWithTraffic(NMATrafficPenaltyMode mode, bool wholeRoute);

		// -(NSTimeInterval)timeToArrivalForSubleg:(NSUInteger)subleg mode:(NMATrafficPenaltyMode)mode;
		[Export("timeToArrivalForSubleg:mode:")]
		double TimeToArrivalForSubleg(nuint subleg, NMATrafficPenaltyMode mode);

		// @property (getter = isPaused, nonatomic) BOOL paused;
		[Export("paused")]
		bool Paused { [Bind("isPaused")] get; set; }

		// @property (getter = isSpeedWarningEnabled, nonatomic) BOOL speedWarningEnabled;
		[Export("speedWarningEnabled")]
		bool SpeedWarningEnabled { [Bind("isSpeedWarningEnabled")] get; set; }

		// @property (readonly, nonatomic) float lowSpeedOffset;
		[Export("lowSpeedOffset")]
		float LowSpeedOffset { get; }

		// @property (readonly, nonatomic) float highSpeedOffset;
		[Export("highSpeedOffset")]
		float HighSpeedOffset { get; }

		// @property (readonly, nonatomic) float speedBoundary;
		[Export("speedBoundary")]
		float SpeedBoundary { get; }

		// @property (nonatomic) BOOL backgroundNavigationEnabled;
		[Export("backgroundNavigationEnabled")]
		bool BackgroundNavigationEnabled { get; set; }

		// @property (nonatomic) BOOL backgroundNavigationStartEnabled;
		[Export("backgroundNavigationStartEnabled")]
		bool BackgroundNavigationStartEnabled { get; set; }

		// @property (nonatomic) NMARealisticViewMode realisticViewMode;
		[Export("realisticViewMode", ArgumentSemantic.Assign)]
		NMARealisticViewMode RealisticViewMode { get; set; }

		// @property (nonatomic) NMARealisticViewAspectRatio realisticViewAspectRatios;
		[Export("realisticViewAspectRatios", ArgumentSemantic.Assign)]
		NMARealisticViewAspectRatio RealisticViewAspectRatios { get; set; }

		// -(NSError * _Nullable)startTurnByTurnNavigationWithRoute:(NMARoute * _Nonnull)route;
		[Export("startTurnByTurnNavigationWithRoute:")]
		[return: NullAllowed]
		NSError StartTurnByTurnNavigationWithRoute(NMARoute route);

		// -(NSError * _Nullable)startTrackingWithTransportMode:(NMATransportMode)transportMode;
		[Export("startTrackingWithTransportMode:")]
		[return: NullAllowed]
		NSError StartTrackingWithTransportMode(NMATransportMode transportMode);

		// -(void)stop;
		[Export("stop")]
		void Stop();

		// -(NSError * _Nullable)setLowSpeedOffset:(float)lowSpeedOffset highSpeedOffset:(float)highSpeedOffset speedBoundary:(float)speedBoundary;
		[Export("setLowSpeedOffset:highSpeedOffset:speedBoundary:")]
		[return: NullAllowed]
		NSError SetLowSpeedOffset(float lowSpeedOffset, float highSpeedOffset, float speedBoundary);

		// @property (nonatomic) NMAVoicePackage * _Null_unspecified voicePackage;
		[Export("voicePackage", ArgumentSemantic.Assign)]
		NMAVoicePackage VoicePackage { get; set; }

		// @property (nonatomic) NMATTSOutputFormat ttsOutputFormat;
		[Export("ttsOutputFormat", ArgumentSemantic.Assign)]
		NMATTSOutputFormat TtsOutputFormat { get; set; }

		// @property (getter = isVoiceEnabled, nonatomic) BOOL voiceEnabled;
		[Export("voiceEnabled")]
		bool VoiceEnabled { [Bind("isVoiceEnabled")] get; set; }

		// @property (getter = isVibrationEnabled, nonatomic) BOOL vibrationEnabled;
		[Export("vibrationEnabled")]
		bool VibrationEnabled { [Bind("isVibrationEnabled")] get; set; }

		// @property (getter = isBeepsEnabled, nonatomic) BOOL beepsEnabled;
		[Export("beepsEnabled")]
		bool BeepsEnabled { [Bind("isBeepsEnabled")] get; set; }

		// @property (getter = isSpeedWarningAudioFeedbackEnabled, nonatomic) BOOL speedWarningAudioFeedbackEnabled;
		[Export("speedWarningAudioFeedbackEnabled")]
		bool SpeedWarningAudioFeedbackEnabled { [Bind("isSpeedWarningAudioFeedbackEnabled")] get; set; }

		// @property (nonatomic) NMAMeasurementSystem voicePackageMeasurementSystem;
		[Export("voicePackageMeasurementSystem", ArgumentSemantic.Assign)]
		NMAMeasurementSystem VoicePackageMeasurementSystem { get; set; }

		// -(BOOL)isVoiceEnabledForManeuverAction:(NMAManeuverAction)action;
		[Export("isVoiceEnabledForManeuverAction:")]
		bool IsVoiceEnabledForManeuverAction(NMAManeuverAction action);

		// -(BOOL)setVoiceEnabled:(BOOL)enabled forManeuverAction:(NMAManeuverAction)action;
		[Export("setVoiceEnabled:forManeuverAction:")]
		bool SetVoiceEnabled(bool enabled, NMAManeuverAction action);

		// -(BOOL)setVoiceEnabledForAllManeuverActions:(BOOL)enabled;
		[Export("setVoiceEnabledForAllManeuverActions:")]
		bool SetVoiceEnabledForAllManeuverActions(bool enabled);

		// -(void)playVoiceCommand;
		[Export("playVoiceCommand")]
		void PlayVoiceCommand();

		// -(void)cancelVoiceFeedback;
		[Export("cancelVoiceFeedback")]
		void CancelVoiceFeedback();

		// -(NMANavigationError)setNaturalGuidanceMode:(NMANaturalGuidanceOption)mode;
		[Export("setNaturalGuidanceMode:")]
		NMANavigationError SetNaturalGuidanceMode(NMANaturalGuidanceOption mode);

		// @property (readonly, nonatomic) NMANaturalGuidanceOption naturalGuidanceMode;
		[Export("naturalGuidanceMode")]
		NMANaturalGuidanceOption NaturalGuidanceMode { get; }

		// -(NMANavigationError)setTrafficAvoidanceMode:(NMATrafficAvoidanceMode)mode;
		[Export("setTrafficAvoidanceMode:")]
		NMANavigationError SetTrafficAvoidanceMode(NMATrafficAvoidanceMode mode);

		// @property (readonly, nonatomic) NMATrafficAvoidanceMode trafficAvoidanceMode;
		[Export("trafficAvoidanceMode")]
		NMATrafficAvoidanceMode TrafficAvoidanceMode { get; }

		// -(NMANavigationError)setRouteRequestInterval:(NSUInteger)interval;
		[Export("setRouteRequestInterval:")]
		NMANavigationError SetRouteRequestInterval(nuint interval);

		// @property (readonly, nonatomic) NSUInteger routeRequestInterval;
		[Export("routeRequestInterval")]
		nuint RouteRequestInterval { get; }

		// -(NMANavigationError)setRoute:(NMARoute * _Nonnull)route;
		[Export("setRoute:")]
		NMANavigationError SetRoute(NMARoute route);

		// @property (readonly, nonatomic) NMATrafficWarner * _Nullable trafficWarner;
		[NullAllowed, Export("trafficWarner")]
		NMATrafficWarner TrafficWarner { get; }

		// @property (readonly, nonatomic) NMASafetySpotWarner * _Nullable safetySpotWarner;
		[NullAllowed, Export("safetySpotWarner")]
		NMASafetySpotWarner SafetySpotWarner { get; }

		// @property (readonly, nonatomic) NMATruckRestrictionWarner * _Nullable truckRestrictionWarner;
		[NullAllowed, Export("truckRestrictionWarner")]
		NMATruckRestrictionWarner TruckRestrictionWarner { get; }

		// @property (readonly, nonatomic) NMASchoolZoneWarner * _Nullable schoolZoneWarner;
		[NullAllowed, Export("schoolZoneWarner")]
		NMASchoolZoneWarner SchoolZoneWarner { get; }

		// @property (readonly, nonatomic) NMARoutingZoneWarner * _Nullable routingZoneWarner;
		[NullAllowed, Export("routingZoneWarner")]
		NMARoutingZoneWarner RoutingZoneWarner { get; }

		// @property (nonatomic) NMANavigationAudioEvent enabledAudioEvents;
		[Export("enabledAudioEvents", ArgumentSemantic.Assign)]
		NMANavigationAudioEvent EnabledAudioEvents { get; set; }

		// @property (readonly, nonatomic) NSString * _Nullable countryCode;
		[NullAllowed, Export("countryCode")]
		string CountryCode { get; }

		// -(NMAUint64)remainingDistanceToRouteElement:(NSUInteger)routeElementIndex positionOnElement:(NMAGeoCoordinates * _Nonnull)positionOnElement;
		[Export("remainingDistanceToRouteElement:positionOnElement:")]
		ulong RemainingDistanceToRouteElement(nuint routeElementIndex, NMAGeoCoordinates positionOnElement);

		// -(NMAUint64)remainingDistanceToSubleg:(NSUInteger)subleg;
		[Export("remainingDistanceToSubleg:")]
		ulong RemainingDistanceToSubleg(nuint subleg);

		// @property (readonly, nonatomic) NSUInteger currentRouteLeg;
		[Export("currentRouteLeg")]
		nuint CurrentRouteLeg { get; }

		// -(NMANavigationError)setDistanceToTriggerStopoverReached:(NSUInteger)distance;
		[Export("setDistanceToTriggerStopoverReached:")]
		NMANavigationError SetDistanceToTriggerStopoverReached(nuint distance);

		// -(NMANavigationError)setDistanceWithUTurnToTriggerStopoverReached:(NSUInteger)distance;
		[Export("setDistanceWithUTurnToTriggerStopoverReached:")]
		NMANavigationError SetDistanceWithUTurnToTriggerStopoverReached(nuint distance);

		// -(NMANavigationError)setDistanceAndStopTimeToTriggerStopoverReached:(NSUInteger)distance stopTime:(NSUInteger)time;
		[Export("setDistanceAndStopTimeToTriggerStopoverReached:stopTime:")]
		NMANavigationError SetDistanceAndStopTimeToTriggerStopoverReached(nuint distance, nuint time);
	}

	// typedef void (^NMARequestCompletionBlock)(NMARequest * _Nonnull, id _Nullable, NSError * _Nullable);
	delegate void NMARequestCompletionBlock(NMARequest arg0, [NullAllowed] NSObject arg1, [NullAllowed] NSError arg2);

	// @interface NMARequest : NSObject <NSCoding>
	[BaseType(typeof(NSObject))]
	interface NMARequest : INSCoding
	{
		// @property (nonatomic) NSString * _Nullable userTag;
		[NullAllowed, Export("userTag")]
		string UserTag { get; set; }

		// @property (nonatomic) NSString * _Nullable languagePreference;
		[NullAllowed, Export("languagePreference")]
		string LanguagePreference { get; set; }

		// @property (nonatomic) NSUInteger collectionSize;
		[Export("collectionSize")]
		nuint CollectionSize { get; set; }

		// @property (nonatomic) NMARequestConnectivity connectivity;
		[Export("connectivity", ArgumentSemantic.Assign)]
		NMARequestConnectivity Connectivity { get; set; }

		// @property (nonatomic) NMAGeoBoundingBox * _Nullable viewport;
		[NullAllowed, Export("viewport", ArgumentSemantic.Assign)]
		NMAGeoBoundingBox Viewport { get; set; }

		// @property (readonly, nonatomic) NSArray<NSString *> * _Nonnull sources;
		[Export("sources")]
		string[] Sources { get; }

		// -(void)addCustomHeader:(NSString * _Nonnull)name value:(NSString * _Nonnull)value;
		[Export("addCustomHeader:value:")]
		void AddCustomHeader(string name, string value);

		// -(NSError * _Nullable)startWithListener:(id<NMAResultListener> _Nullable)aSearchEventListener;
		[Export("startWithListener:")]
		[return: NullAllowed]
		NSError StartWithListener([NullAllowed] NMAResultListener aSearchEventListener);

		// -(NSError * _Nullable)startWithBlock:(NMARequestCompletionBlock _Nullable)completionBlock;
		[Export("startWithBlock:")]
		[return: NullAllowed]
		NSError StartWithBlock([NullAllowed] NMARequestCompletionBlock completionBlock);

		// -(BOOL)cancel;
		[Export("cancel")]
		//[Verify(MethodToProperty)]
		bool Cancel { get; }

		// -(void)addSource:(NSString * _Nonnull)source;
		[Export("addSource:")]
		void AddSource(string source);
	}

	// @interface NMACountryInfo : NSObject
	[BaseType(typeof(NSObject))]
	interface NMACountryInfo
	{
		// -(instancetype _Nonnull)initWithCountryCode:(NSString * _Nonnull)code;
		[Export("initWithCountryCode:")]
		IntPtr Constructor(string code);

		// @property (readonly, nonatomic) NSString * _Nonnull code;
		[Export("code")]
		string Code { get; }

		// @property (readonly, nonatomic) NMAMeasurementSystem measurementSystem;
		[Export("measurementSystem")]
		NMAMeasurementSystem MeasurementSystem { get; }

		// +(void)getCountryInfoOnCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates withCompletion:(NMACountryInfoCompletionBlock _Nonnull)completionBlock connectivity:(NMARequestConnectivity)connectivity;
		[Static]
		[Export("getCountryInfoOnCoordinates:withCompletion:connectivity:")]
		void GetCountryInfoOnCoordinates(NMAGeoCoordinates coordinates, NMACountryInfoCompletionBlock completionBlock, NMARequestConnectivity connectivity);
	}

	// typedef void (^NMACountryInfoCompletionBlock)(NMACountryInfo * _Nullable, NSError * _Nullable);
	delegate void NMACountryInfoCompletionBlock([NullAllowed] NMACountryInfo arg0, [NullAllowed] NSError arg1);

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const NMAMapViewCustomConfigurationFileKey NMAMapViewConfigurationFileKey;
		[Field("NMAMapViewConfigurationFileKey", "__Internal")]
		NSString NMAMapViewConfigurationFileKey { get; }

		// extern const NMAMapViewCustomConfigurationFileKey NMAMapViewResourceFileKey;
		[Field("NMAMapViewResourceFileKey", "__Internal")]
		NSString NMAMapViewResourceFileKey { get; }

		// extern const NMAMapViewCustomConfigurationFileKey NMAMapViewTrafficConfigurationFileKey;
		[Field("NMAMapViewTrafficConfigurationFileKey", "__Internal")]
		NSString NMAMapViewTrafficConfigurationFileKey { get; }

		// extern const NMAMapViewCustomConfigurationFileKey NMAMapViewCustomPreferenceConfigurationFileKey;
		[Field("NMAMapViewCustomPreferenceConfigurationFileKey", "__Internal")]
		NSString NMAMapViewCustomPreferenceConfigurationFileKey { get; }
	}

	// @interface NMACustomConfigurations : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMACustomConfigurations
	{
		// +(NMAMapStyleConfigurationError)setCustomConfiguration:(NSDictionary<NSString *,NSURL *> * _Nonnull)configFiles;
		[Static]
		[Export("setCustomConfiguration:")]
		NMAMapStyleConfigurationError SetCustomConfiguration(NSDictionary<NSString, NSUrl> configFiles);
	}

	// @protocol NMAPositionDataSource <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAPositionDataSource
	{
		// @required -(NMAGeoPosition * _Nullable)currentPosition;
		[Abstract]
		[NullAllowed, Export("currentPosition")]
		//[Verify(MethodToProperty)]
		NMAGeoPosition CurrentPosition { get; }

		// @optional -(void)start;
		[Export("start")]
		void Start();

		// @optional -(void)stop;
		[Export("stop")]
		void Stop();

		// @optional -(BOOL)backgroundUpdatesEnabled;
		// @optional -(void)setBackgroundUpdatesEnabled:(BOOL)enabled;
		[Export("backgroundUpdatesEnabled")]
		//[Verify(MethodToProperty)]
		bool BackgroundUpdatesEnabled { get; set; }

		// @optional -(void)navigationStartedWithTransportMode:(NMATransportMode)transportMode;
		[Export("navigationStartedWithTransportMode:")]
		void NavigationStartedWithTransportMode(NMATransportMode transportMode);

		// @optional -(void)navigationStopped;
		[Export("navigationStopped")]
		void NavigationStopped();
	}

	// @interface NMADevicePositionSource : NSObject <NMAPositionDataSource, CLLocationManagerDelegate>
	[BaseType(typeof(NSObject))]
	interface NMADevicePositionSource : NMAPositionDataSource, ICLLocationManagerDelegate
	{
		// @property (readonly, nonatomic) CLLocationManager * _Nonnull locationManager;
		[Export("locationManager")]
		CLLocationManager LocationManager { get; }

		// -(void)setPositioningMethod:(NMADevicePositioningMethod)method;
		[Export("setPositioningMethod:")]
		void SetPositioningMethod(NMADevicePositioningMethod method);
	}

	// @interface NMAGeoBoundingBox : NSObject <NSCoding>
	[BaseType(typeof(NSObject))]
	interface NMAGeoBoundingBox : INSCoding
	{
		// +(instancetype _Nullable)geoBoundingBoxWithTopLeft:(NMAGeoCoordinates * _Nonnull)topLeft bottomRight:(NMAGeoCoordinates * _Nonnull)bottomRight;
		[Static]
		[Export("geoBoundingBoxWithTopLeft:bottomRight:")]
		[return: NullAllowed]
		NMAGeoBoundingBox GeoBoundingBoxWithTopLeft(NMAGeoCoordinates topLeft, NMAGeoCoordinates bottomRight);

		// +(instancetype _Nullable)geoBoundingBoxWithTopRight:(NMAGeoCoordinates * _Nonnull)topRight bottomLeft:(NMAGeoCoordinates * _Nonnull)bottomLeft;
		[Static]
		[Export("geoBoundingBoxWithTopRight:bottomLeft:")]
		[return: NullAllowed]
		NMAGeoBoundingBox GeoBoundingBoxWithTopRight(NMAGeoCoordinates topRight, NMAGeoCoordinates bottomLeft);

		// +(instancetype _Nullable)geoBoundingBoxWithCenter:(NMAGeoCoordinates * _Nonnull)center width:(float)width height:(float)height;
		[Static]
		[Export("geoBoundingBoxWithCenter:width:height:")]
		[return: NullAllowed]
		NMAGeoBoundingBox GeoBoundingBoxWithCenter(NMAGeoCoordinates center, float width, float height);

		// +(instancetype _Nullable)geoBoundingBoxContainingGeoCoordinates:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Static]
		[Export("geoBoundingBoxContainingGeoCoordinates:")]
		[return: NullAllowed]
		NMAGeoBoundingBox GeoBoundingBoxContainingGeoCoordinates(NMAGeoCoordinates[] coordinates);

		// +(instancetype _Nullable)geoBoundingBoxContainingGeoBoundingBoxes:(NSArray<NMAGeoBoundingBox *> * _Nonnull)boxes;
		[Static]
		[Export("geoBoundingBoxContainingGeoBoundingBoxes:")]
		[return: NullAllowed]
		NMAGeoBoundingBox GeoBoundingBoxContainingGeoBoundingBoxes(NMAGeoBoundingBox[] boxes);

		// -(instancetype _Nullable)initWithTopLeft:(NMAGeoCoordinates * _Nonnull)topLeft bottomRight:(NMAGeoCoordinates * _Nonnull)bottomRight;
		[Export("initWithTopLeft:bottomRight:")]
		IntPtr Constructor(NMAGeoCoordinates topLeft, NMAGeoCoordinates bottomRight);

		// -(instancetype _Nullable)initWithCenter:(NMAGeoCoordinates * _Nonnull)center width:(float)width height:(float)height;
		[Export("initWithCenter:width:height:")]
		IntPtr Constructor(NMAGeoCoordinates center, float width, float height);

		// -(instancetype _Nullable)initContainingGeoCoordinates:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Export("initContainingGeoCoordinates:")]
		IntPtr Constructor(NMAGeoCoordinates[] coordinates);

		// -(instancetype _Nullable)initContainingGeoBoundingBoxes:(NSArray<NMAGeoBoundingBox *> * _Nonnull)boxes;
		[Export("initContainingGeoBoundingBoxes:")]
		IntPtr Constructor(NMAGeoBoundingBox[] boxes);

		// @property (readonly, nonatomic) double width;
		[Export("width")]
		double Width { get; }

		// @property (readonly, nonatomic) double height;
		[Export("height")]
		double Height { get; }

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull topLeft;
		[Export("topLeft", ArgumentSemantic.Assign)]
		NMAGeoCoordinates TopLeft { get; set; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull topLeftFront;
		[Export("topLeftFront")]
		NMAGeoCoordinates TopLeftFront { get; }

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull topRight;
		[Export("topRight", ArgumentSemantic.Assign)]
		NMAGeoCoordinates TopRight { get; set; }

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull bottomLeft;
		[Export("bottomLeft", ArgumentSemantic.Assign)]
		NMAGeoCoordinates BottomLeft { get; set; }

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull bottomRight;
		[Export("bottomRight", ArgumentSemantic.Assign)]
		NMAGeoCoordinates BottomRight { get; set; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull bottomRightBack;
		[Export("bottomRightBack")]
		NMAGeoCoordinates BottomRightBack { get; }

		// @property (readonly, nonatomic, weak) NMAGeoCoordinates * _Nullable center;
		[NullAllowed, Export("center", ArgumentSemantic.Weak)]
		NMAGeoCoordinates Center { get; }

		// @property (readonly, assign, nonatomic) double areaSize;
		[Export("areaSize")]
		double AreaSize { get; }

		// @property (readonly, nonatomic) BOOL crossesInternationalDateLine;
		[Export("crossesInternationalDateLine")]
		bool CrossesInternationalDateLine { get; }

		// -(BOOL)containsGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("containsGeoCoordinates:")]
		bool ContainsGeoCoordinates(NMAGeoCoordinates coordinates);

		// -(BOOL)containsGeoBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox;
		[Export("containsGeoBoundingBox:")]
		bool ContainsGeoBoundingBox(NMAGeoBoundingBox boundingBox);

		// -(BOOL)intersectsGeoBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox;
		[Export("intersectsGeoBoundingBox:")]
		bool IntersectsGeoBoundingBox(NMAGeoBoundingBox boundingBox);

		// -(NMAGeoBoundingBox * _Nullable)intersectionWithGeoBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox;
		[Export("intersectionWithGeoBoundingBox:")]
		[return: NullAllowed]
		NMAGeoBoundingBox IntersectionWithGeoBoundingBox(NMAGeoBoundingBox boundingBox);

		// -(BOOL)isEmpty;
		[Export("isEmpty")]
		//[Verify(MethodToProperty)]
		bool IsEmpty { get; }

		// -(BOOL)isEqualToGeoBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox;
		[Export("isEqualToGeoBoundingBox:")]
		bool IsEqualToGeoBoundingBox(NMAGeoBoundingBox boundingBox);
	}

	/*
	// @interface NMAGeoMesh : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAGeoMesh
	{
		// -(void)setVertices:(NSArray<NMAGeoCoordinates *> * _Nonnull)vertices;
		[Export("setVertices:")]
		void SetVertices(NMAGeoCoordinates[] vertices);

		// -(void)setVertices:(const double * _Nonnull)vertices withCount:(NSUInteger)count;
		[Export("setVertices:withCount:")]
		unsafe void SetVertices(double* vertices, nuint count);

		// -(void)setTextureCoordinates:(const float * _Nonnull)textureCoordinates withCount:(NSUInteger)count;
		[Export("setTextureCoordinates:withCount:")]
		unsafe void SetTextureCoordinates(float* textureCoordinates, nuint count);

		// -(void)setTriangles:(const short * _Nonnull)triangles withCount:(NSUInteger)count;
		[Export("setTriangles:withCount:")]
		unsafe void SetTriangles(short* triangles, nuint count);

		// -(BOOL)isValid;
		[Export("isValid")]
		//[Verify(MethodToProperty)]
		bool IsValid { get; }
	}
	*/

	// @interface NMAGeoPolygon : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAGeoPolygon : ObjCRuntime.INativeObject
	{
		// -(instancetype _Nonnull)initWithCoordinates:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Export("initWithCoordinates:")]
		IntPtr Constructor(NMAGeoCoordinates[] coordinates);

		// -(void)addPoint:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export("addPoint:")]
		void AddPoint(NMAGeoCoordinates coordinate);

		// -(void)addPoints:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Export("addPoints:")]
		void AddPoints(NMAGeoCoordinates[] coordinates);

		// -(void)insertPoint:(NMAGeoCoordinates * _Nonnull)coordinate atIndex:(int)index;
		[Export("insertPoint:atIndex:")]
		void InsertPoint(NMAGeoCoordinates coordinate, int index);

		// -(void)removePointAtIndex:(int)index;
		[Export("removePointAtIndex:")]
		void RemovePointAtIndex(int index);

		// -(void)clear;
		[Export("clear")]
		void Clear();

		// -(int)numberOfPoints;
		[Export("numberOfPoints")]
		//[Verify(MethodToProperty)]
		int NumberOfPoints { get; }

		// -(NMAGeoCoordinates * _Nullable)pointAtIndex:(int)index;
		[Export("pointAtIndex:")]
		[return: NullAllowed]
		NMAGeoCoordinates PointAtIndex(int index);

		// -(NSArray<NMAGeoCoordinates *> * _Nonnull)allPoints;
		[Export("allPoints")]
		//[Verify(MethodToProperty)]
		NMAGeoCoordinates[] AllPoints { get; }

		// -(double)length;
		[Export("length")]
		//[Verify(MethodToProperty)]
		double Length { get; }

		// -(NMAGeoCoordinates * _Nullable)nearestCoordinateFrom:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export("nearestCoordinateFrom:")]
		[return: NullAllowed]
		NMAGeoCoordinates NearestCoordinateFrom(NMAGeoCoordinates coordinate);

		// -(NSUInteger)nearestIndexFromCoordinate:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export("nearestIndexFromCoordinate:")]
		nuint NearestIndexFromCoordinate(NMAGeoCoordinates coordinate);

		// -(NMAGeoPolygon * _Nonnull)sortedPolygon;
		[Export("sortedPolygon")]
		//[Verify(MethodToProperty)]
		NMAGeoPolygon SortedPolygon { get; }

		// -(NMAGeoBoundingBox * _Nullable)geoBoundingBox;
		[NullAllowed, Export("geoBoundingBox")]
		//[Verify(MethodToProperty)]
		NMAGeoBoundingBox GeoBoundingBox { get; }
	}

	// @interface NMAGeoPolyline : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAGeoPolyline : ObjCRuntime.INativeObject
	{
		// -(instancetype _Nonnull)initWithCoordinates:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Export("initWithCoordinates:")]
		IntPtr Constructor(NMAGeoCoordinates[] coordinates);

		// -(void)addPoint:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export("addPoint:")]
		void AddPoint(NMAGeoCoordinates coordinate);

		// -(void)addPoints:(NSArray<NMAGeoCoordinates *> * _Nonnull)coordinates;
		[Export("addPoints:")]
		void AddPoints(NMAGeoCoordinates[] coordinates);

		// -(void)insertPoint:(NMAGeoCoordinates * _Nonnull)coordinate atIndex:(int)index;
		[Export("insertPoint:atIndex:")]
		void InsertPoint(NMAGeoCoordinates coordinate, int index);

		// -(void)removePointAtIndex:(int)index;
		[Export("removePointAtIndex:")]
		void RemovePointAtIndex(int index);

		// -(void)clear;
		[Export("clear")]
		void Clear();

		// -(int)getNumberOfPoints;
		[Export("getNumberOfPoints")]
		//[Verify(MethodToProperty)]
		int NumberOfPoints { get; }

		// -(NMAGeoCoordinates * _Nullable)getPointAtIndex:(int)index;
		[Export("getPointAtIndex:")]
		[return: NullAllowed]
		NMAGeoCoordinates GetPointAtIndex(int index);

		// -(NSArray<NMAGeoCoordinates *> * _Nonnull)getAllPoints;
		[Export("getAllPoints")]
		//[Verify(MethodToProperty)]
		NMAGeoCoordinates[] AllPoints { get; }

		// -(double)getLength;
		[Export("getLength")]
		//[Verify(MethodToProperty)]
		double Length { get; }

		// -(NMAGeoCoordinates * _Nullable)getNearestCoordinateFrom:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export("getNearestCoordinateFrom:")]
		[return: NullAllowed]
		NMAGeoCoordinates GetNearestCoordinateFrom(NMAGeoCoordinates coordinate);

		// -(NSUInteger)getNearestIndexFromCoordinate:(NMAGeoCoordinates * _Nonnull)coordinate;
		[Export("getNearestIndexFromCoordinate:")]
		nuint GetNearestIndexFromCoordinate(NMAGeoCoordinates coordinate);

		// -(NMAGeoBoundingBox * _Nullable)geoBoundingBox;
		[NullAllowed, Export("geoBoundingBox")]
		//[Verify(MethodToProperty)]
		NMAGeoBoundingBox GeoBoundingBox { get; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const double NMAGeoPositionUnknownValue;
		[Field("NMAGeoPositionUnknownValue", "__Internal")]
		double NMAGeoPositionUnknownValue { get; }
	}

	// @interface NMAGeoPosition : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAGeoPosition
	{
		// +(instancetype _Nullable)geoPositionWithCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates speed:(double)speed course:(double)course accuracy:(double)accuracy;
		[Static]
		[Export("geoPositionWithCoordinates:speed:course:accuracy:")]
		[return: NullAllowed]
		NMAGeoPosition GeoPositionWithCoordinates(NMAGeoCoordinates coordinates, double speed, double course, double accuracy);

		// +(instancetype _Nullable)geoPositionWithCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates speed:(double)speed course:(double)course accuracy:(double)accuracy timestamp:(NSDate * _Nonnull)timestamp;
		[Static]
		[Export("geoPositionWithCoordinates:speed:course:accuracy:timestamp:")]
		[return: NullAllowed]
		NMAGeoPosition GeoPositionWithCoordinates(NMAGeoCoordinates coordinates, double speed, double course, double accuracy, NSDate timestamp);

		// +(instancetype _Nullable)geoPositionWithCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates speed:(double)speed course:(double)course latitudeAccuracy:(double)latitudeAccuracy longitudeAccuracy:(double)longitudeAccuracy altitudeAccuracy:(double)altitudeAccuracy timestamp:(NSDate * _Nonnull)timestamp;
		[Static]
		[Export("geoPositionWithCoordinates:speed:course:latitudeAccuracy:longitudeAccuracy:altitudeAccuracy:timestamp:")]
		[return: NullAllowed]
		NMAGeoPosition GeoPositionWithCoordinates(NMAGeoCoordinates coordinates, double speed, double course, double latitudeAccuracy, double longitudeAccuracy, double altitudeAccuracy, NSDate timestamp);

		// +(instancetype _Nullable)geoPositionWithCLLocation:(CLLocation * _Nonnull)location;
		[Static]
		[Export("geoPositionWithCLLocation:")]
		[return: NullAllowed]
		NMAGeoPosition GeoPositionWithCLLocation(CLLocation location);

		// -(instancetype _Nullable)initWithCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates speed:(double)speed course:(double)course accuracy:(double)accuracy;
		[Export("initWithCoordinates:speed:course:accuracy:")]
		IntPtr Constructor(NMAGeoCoordinates coordinates, double speed, double course, double accuracy);

		// -(instancetype _Nullable)initWithCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates speed:(double)speed course:(double)course accuracy:(double)accuracy timestamp:(NSDate * _Nonnull)timestamp;
		[Export("initWithCoordinates:speed:course:accuracy:timestamp:")]
		IntPtr Constructor(NMAGeoCoordinates coordinates, double speed, double course, double accuracy, NSDate timestamp);

		// -(instancetype _Nullable)initWithCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates speed:(double)speed course:(double)course latitudeAccuracy:(double)latitudeAccuracy longitudeAccuracy:(double)longitudeAccuracy altitudeAccuracy:(double)altitudeAccuracy timestamp:(NSDate * _Nonnull)timestamp;
		[Export("initWithCoordinates:speed:course:latitudeAccuracy:longitudeAccuracy:altitudeAccuracy:timestamp:")]
		IntPtr Constructor(NMAGeoCoordinates coordinates, double speed, double course, double latitudeAccuracy, double longitudeAccuracy, double altitudeAccuracy, NSDate timestamp);

		// -(instancetype _Nullable)initWithCLLocation:(CLLocation * _Nonnull)location;
		[Export("initWithCLLocation:")]
		IntPtr Constructor(CLLocation location);

		// @property (readonly, nonatomic, weak) NMAGeoCoordinates * _Nullable coordinates;
		[NullAllowed, Export("coordinates", ArgumentSemantic.Weak)]
		NMAGeoCoordinates Coordinates { get; }

		// @property (readonly, nonatomic) double latitudeAccuracy;
		[Export("latitudeAccuracy")]
		double LatitudeAccuracy { get; }

		// @property (readonly, nonatomic) double longitudeAccuracy;
		[Export("longitudeAccuracy")]
		double LongitudeAccuracy { get; }

		// @property (readonly, nonatomic) double altitudeAccuracy;
		[Export("altitudeAccuracy")]
		double AltitudeAccuracy { get; }

		// @property (readonly, nonatomic) double speed;
		[Export("speed")]
		double Speed { get; }

		// @property (readonly, nonatomic) double course;
		[Export("course")]
		double Course { get; }

		// @property (readonly, nonatomic) NSDate * _Nonnull timestamp;
		[Export("timestamp")]
		NSDate Timestamp { get; }

		// @property (readonly, nonatomic) NSString * _Nullable buildingId;
		[NullAllowed, Export("buildingId")]
		string BuildingId { get; }

		// @property (readonly, nonatomic) NSString * _Nullable buildingName;
		[NullAllowed, Export("buildingName")]
		string BuildingName { get; }

		// @property (readonly, nonatomic) NSNumber * _Nullable floorId;
		[NullAllowed, Export("floorId")]
		NSNumber FloorId { get; }

		// @property (readonly, nonatomic) NMAGeoPositionSource source;
		[Export("source")]
		NMAGeoPositionSource Source { get; }

		// @property (readonly, nonatomic) BOOL isValid;
		[Export("isValid")]
		bool IsValid { get; }
	}

	// @interface NMAHEREPositionSource : NSObject <NMAPositionDataSource>
	[BaseType(typeof(NSObject))]
	interface NMAHEREPositionSource : NMAPositionDataSource
	{
		// @property (nonatomic) NMAIndoorPositioningMode indoorPositioningMode;
		[Export("indoorPositioningMode", ArgumentSemantic.Assign)]
		NMAIndoorPositioningMode IndoorPositioningMode { get; set; }
	}

	// @interface NMAImage : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAImage : ObjCRuntime.INativeObject
	{
		// +(instancetype _Nullable)imageWithUIImage:(UIImage * _Nonnull)image;
		[Static]
		[Export("imageWithUIImage:")]
		[return: NullAllowed]
		NMAImage ImageWithUIImage(UIImage image);

		// +(instancetype _Nullable)imageWithData:(NSData * _Nonnull)data;
		[Static]
		[Export("imageWithData:")]
		[return: NullAllowed]
		NMAImage ImageWithData(NSData data);

		// +(instancetype _Nullable)imageWithURL:(NSString * _Nonnull)url;
		[Static]
		[Export("imageWithURL:")]
		[return: NullAllowed]
		NMAImage ImageWithURL(string url);

		// -(instancetype _Nullable)initWithUIImage:(UIImage * _Nonnull)image;
		[Export("initWithUIImage:")]
		IntPtr Constructor(UIImage image);

		// -(instancetype _Nullable)initWithData:(NSData * _Nonnull)data;
		[Export("initWithData:")]
		IntPtr Constructor(NSData data);

		// -(instancetype _Nullable)initWithURL:(NSString * _Nonnull)url;
		[Export("initWithURL:")]
		IntPtr Constructor(string url);

		// @property (readonly, getter = isValid, nonatomic) BOOL valid;
		[Export("valid")]
		bool Valid { [Bind("isValid")] get; }

		// @property (readonly, nonatomic) CGSize size;
		[Export("size")]
		CGSize Size { get; }

		// -(UIImage * _Nullable)UIImageRepresentation;
		[NullAllowed, Export("UIImageRepresentation")]
		//[Verify(MethodToProperty)]
		UIImage UIImageRepresentation { get; }
	}

	// @interface NMALoggedPositionSource : NSObject <NMAPositionDataSource>
	[BaseType(typeof(NSObject))]
	interface NMALoggedPositionSource : NMAPositionDataSource
	{
		// -(instancetype _Nonnull)initWithLogFile:(NSURL * _Nonnull)logFile;
		[Export("initWithLogFile:")]
		IntPtr Constructor(NSUrl logFile);

		// @property (nonatomic) NSURL * _Nullable logFile;
		[NullAllowed, Export("logFile", ArgumentSemantic.Assign)]
		NSUrl LogFile { get; set; }

		// @property (readonly, nonatomic) NSArray<NMAGeoPosition *> * _Nullable positions;
		[NullAllowed, Export("positions")]
		NMAGeoPosition[] Positions { get; }

		// @property (readonly, nonatomic) NSUInteger currentPositionIndex;
		[Export("currentPositionIndex")]
		nuint CurrentPositionIndex { get; }

		// @property (nonatomic) BOOL stationary;
		[Export("stationary")]
		bool Stationary { get; set; }

		// @property (nonatomic) BOOL positionLost;
		[Export("positionLost")]
		bool PositionLost { get; set; }

		// @property (readonly, nonatomic) BOOL finished;
		[Export("finished")]
		bool Finished { get; }

		// -(void)reset;
		[Export("reset")]
		void Reset();
	}

	// @protocol NMAPositionDataSourceAutomotive <NMAPositionDataSource>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAPositionDataSourceAutomotive : NMAPositionDataSource
	{
		// @optional -(float)horizontalLargeStandardDeviation;
		[Export("horizontalLargeStandardDeviation")]
		//[Verify(MethodToProperty)]
		float HorizontalLargeStandardDeviation { get; }

		// @optional -(float)horizontalSmallStandardDeviation;
		[Export("horizontalSmallStandardDeviation")]
		//[Verify(MethodToProperty)]
		float HorizontalSmallStandardDeviation { get; }

		// @optional -(float)courseStandardDeviation;
		[Export("courseStandardDeviation")]
		//[Verify(MethodToProperty)]
		float CourseStandardDeviation { get; }

		// @optional -(float)speedStandardDeviation;
		[Export("speedStandardDeviation")]
		//[Verify(MethodToProperty)]
		float SpeedStandardDeviation { get; }

		// @optional -(float)elevationStandardDeviation;
		[Export("elevationStandardDeviation")]
		//[Verify(MethodToProperty)]
		float ElevationStandardDeviation { get; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMAPositioningManagerDidUpdatePositionNotification;
		[Field("NMAPositioningManagerDidUpdatePositionNotification", "__Internal")]
		NSString NMAPositioningManagerDidUpdatePositionNotification { get; }

		// extern NSString *const _Nonnull NMAPositioningManagerDidLosePositionNotification;
		[Field("NMAPositioningManagerDidLosePositionNotification", "__Internal")]
		NSString NMAPositioningManagerDidLosePositionNotification { get; }
	}

	// @protocol NMAGeoShiftableDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAGeoShiftableDelegate
	{
		// @required -(NMAGeoPosition * _Nonnull)shift:(NMAGeoPosition * _Nonnull)position;
		[Abstract]
		[Export("shift:")]
		NMAGeoPosition Shift(NMAGeoPosition position);
	}

	// @interface NMAPositioningManager : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPositioningManager
	{
		// +(NMAPositioningManager * _Nonnull)sharedPositioningManager;
		[Static]
		[Export("sharedPositioningManager")]
		//[Verify(MethodToProperty)]
		NMAPositioningManager SharedPositioningManager { get; }

		// @property (nonatomic) id<NMAPositionDataSource> _Nullable dataSource;
		[NullAllowed, Export("dataSource", ArgumentSemantic.Assign)]
		NMAPositionDataSource DataSource { get; set; }

		// @property (readonly, getter = isActive, nonatomic) BOOL active;
		[Export("active")]
		bool Active { [Bind("isActive")] get; }

		// @property (readonly, nonatomic) NMAGeoPosition * _Nullable rawPosition;
		[NullAllowed, Export("rawPosition")]
		NMAGeoPosition RawPosition { get; }

		// @property (readonly, nonatomic) NMAGeoPosition * _Nullable mapMatchedPosition;
		[NullAllowed, Export("mapMatchedPosition")]
		NMAGeoPosition MapMatchedPosition { get; }

		// @property (readonly, nonatomic) NMAGeoPosition * _Nullable currentPosition;
		[NullAllowed, Export("currentPosition")]
		NMAGeoPosition CurrentPosition { get; }

		// @property (nonatomic) BOOL mapMatchingEnabled;
		[Export("mapMatchingEnabled")]
		bool MapMatchingEnabled { get; set; }

		// @property (nonatomic) NMAMapMatchMode mapMatchMode;
		[Export("mapMatchMode", ArgumentSemantic.Assign)]
		NMAMapMatchMode MapMatchMode { get; set; }

		// -(BOOL)startPositioning;
		[Export("startPositioning")]
		//[Verify(MethodToProperty)]
		bool StartPositioning { get; }

		// -(void)stopPositioning;
		[Export("stopPositioning")]
		void StopPositioning();

		// -(NMARoadElement * _Nullable)currentRoadElement;
		[NullAllowed, Export("currentRoadElement")]
		//[Verify(MethodToProperty)]
		NMARoadElement CurrentRoadElement { get; }

		// -(void)dataSourceDidUpdatePosition:(id<NMAPositionDataSource> _Nonnull)dataSource;
		[Export("dataSourceDidUpdatePosition:")]
		void DataSourceDidUpdatePosition(NMAPositionDataSource dataSource);

		// @property (nonatomic) NMAPositionLogType logType;
		[Export("logType", ArgumentSemantic.Assign)]
		NMAPositionLogType LogType { get; set; }

		// @property (getter = isProbeCollectionEnabled, nonatomic) BOOL probeCollectionEnabled;
		[Export("probeCollectionEnabled")]
		bool ProbeCollectionEnabled { [Bind("isProbeCollectionEnabled")] get; set; }

		[Wrap("WeakGeoShiftableDelegate")]
		[NullAllowed]
		NMAGeoShiftableDelegate GeoShiftableDelegate { get; set; }

		// @property (nonatomic, weak) id<NMAGeoShiftableDelegate> _Nullable geoShiftableDelegate;
		[NullAllowed, Export("geoShiftableDelegate", ArgumentSemantic.Weak)]
		NSObject WeakGeoShiftableDelegate { get; set; }
	}

	// @interface NMARoadElement : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARoadElement
	{
		// @property (readonly, nonatomic, weak) NSString * _Nullable uniqueId;
		[NullAllowed, Export("uniqueId", ArgumentSemantic.Weak)]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSUInteger permanentLinkId;
		[Export("permanentLinkId")]
		nuint PermanentLinkId { get; }

		// @property (readonly, nonatomic) NSInteger permanentDirectedLinkId;
		[Export("permanentDirectedLinkId")]
		nint PermanentDirectedLinkId { get; }

		// @property (readonly, nonatomic) NSUInteger attributes;
		[Export("attributes")]
		nuint Attributes { get; }

		// @property (readonly, nonatomic) NMARoadElementType type;
		[Export("type")]
		NMARoadElementType Type { get; }

		// @property (readonly, nonatomic) NMARoadElementPluralType pluralType;
		[Export("pluralType")]
		NMARoadElementPluralType PluralType { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable roadName;
		[NullAllowed, Export("roadName", ArgumentSemantic.Weak)]
		string RoadName { get; }

		// @property (readonly, nonatomic, weak) NSString * _Nullable abbreviatedName;
		[NullAllowed, Export("abbreviatedName", ArgumentSemantic.Weak)]
		string AbbreviatedName { get; }

		// @property (readonly, nonatomic) float speedLimit;
		[Export("speedLimit")]
		float SpeedLimit { get; }

		// @property (readonly, nonatomic) NSUInteger averageSpeed;
		[Export("averageSpeed")]
		nuint AverageSpeed { get; }

		// @property (readonly, nonatomic) NSUInteger numberOfLanes;
		[Export("numberOfLanes")]
		nuint NumberOfLanes { get; }

		// -(NSArray<NMATrafficSign *> * _Nullable)trafficSignsOrError:(NSError * _Nullable * _Nullable)error;
		[Export("trafficSignsOrError:")]
		[return: NullAllowed]
		NMATrafficSign[] TrafficSignsOrError([NullAllowed] out NSError error);
	}

	// @interface NMARoutePositionSource : NSObject <NMAPositionDataSource>
	[BaseType(typeof(NSObject))]
	interface NMARoutePositionSource : NMAPositionDataSource
	{
		// -(instancetype _Nonnull)initWithRoute:(NMARoute * _Nonnull)route;
		[Export("initWithRoute:")]
		IntPtr Constructor(NMARoute route);

		// @property (nonatomic) NMARoute * _Nullable route;
		[NullAllowed, Export("route", ArgumentSemantic.Assign)]
		NMARoute Route { get; set; }

		// @property (nonatomic) NSTimeInterval updateInterval;
		[Export("updateInterval")]
		double UpdateInterval { get; set; }

		// @property (nonatomic) float movementSpeed;
		[Export("movementSpeed")]
		float MovementSpeed { get; set; }

		// @property (nonatomic) float accuracy;
		[Export("accuracy")]
		float Accuracy { get; set; }

		// @property (nonatomic) BOOL stationary;
		[Export("stationary")]
		bool Stationary { get; set; }

		// @property (nonatomic) BOOL positionLost;
		[Export("positionLost")]
		bool PositionLost { get; set; }

		// -(void)reset;
		[Export("reset")]
		void Reset();
	}

	// @interface NMARoutingZoneNotification : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARoutingZoneNotification
	{
		// @property (readonly, nonatomic) NSArray<NMARoutingZonesInfo *> * _Nonnull routingZonesInfos;
		[Export("routingZonesInfos")]
		NMARoutingZonesInfo[] RoutingZonesInfos { get; }

		// @property (readonly, nonatomic) BOOL isOnRoute;
		[Export("isOnRoute")]
		bool IsOnRoute { get; }
	}

	// @interface NMARoutingZonesInfo : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARoutingZonesInfo
	{
		// @property (readonly, nonatomic) NMARoadElement * _Nonnull roadElement;
		[Export("roadElement")]
		NMARoadElement RoadElement { get; }

		// @property (readonly, nonatomic) NSUInteger distance;
		[Export("distance")]
		nuint Distance { get; }

		// @property (readonly, nonatomic) NSArray<NMARoutingZone *> * _Nonnull routingZones;
		[Export("routingZones")]
		NMARoutingZone[] RoutingZones { get; }
	}

	// @interface NMASafetySpot : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASafetySpot
	{
		// @property (readonly, nonatomic) NSInteger heading1;
		[Export("heading1")]
		nint Heading1 { get; }

		// @property (readonly, nonatomic) NSInteger heading2;
		[Export("heading2")]
		nint Heading2 { get; }

		// @property (readonly, nonatomic) float speedLimit1;
		[Export("speedLimit1")]
		float SpeedLimit1 { get; }

		// @property (readonly, nonatomic) float speedLimit2;
		[Export("speedLimit2")]
		float SpeedLimit2 { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable location;
		[NullAllowed, Export("location")]
		NMAGeoCoordinates Location { get; }

		// @property (readonly, nonatomic) NMASafetySpotType type;
		[Export("type")]
		NMASafetySpotType Type { get; }
	}

	// @interface NMASafetySpotNotification : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASafetySpotNotification
	{
		// @property (readonly, nonatomic) NSArray<NMASafetySpotNotificationInfo *> * _Nonnull safetySpotNotificationInfo;
		[Export("safetySpotNotificationInfo")]
		NMASafetySpotNotificationInfo[] SafetySpotNotificationInfo { get; }
	}

	// @interface NMASafetySpotNotificationInfo : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASafetySpotNotificationInfo
	{
		// @property (readonly, nonatomic) double distance;
		[Export("distance")]
		double Distance { get; }

		// @property (readonly, nonatomic) NMASafetySpot * _Nullable safetySpot;
		[NullAllowed, Export("safetySpot")]
		NMASafetySpot SafetySpot { get; }
	}

	// @interface NMASchoolZoneInfo : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASchoolZoneInfo
	{
		// @property (readonly, nonatomic) NSDate * _Nullable timeBegin;
		[NullAllowed, Export("timeBegin")]
		NSDate TimeBegin { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable timeEnd;
		[NullAllowed, Export("timeEnd")]
		NSDate TimeEnd { get; }

		// @property (readonly, nonatomic) float speedLimit;
		[Export("speedLimit")]
		float SpeedLimit { get; }
	}

	// @interface NMASchoolZoneNotification : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASchoolZoneNotification
	{
		// @property (readonly, nonatomic) NMARoadElement * _Nonnull roadElement;
		[Export("roadElement")]
		NMARoadElement RoadElement { get; }

		// @property (readonly, nonatomic) NSUInteger distance;
		[Export("distance")]
		nuint Distance { get; }

		// @property (readonly, nonatomic) NMASchoolZoneInfo * _Nonnull schoolZoneInfo;
		[Export("schoolZoneInfo")]
		NMASchoolZoneInfo SchoolZoneInfo { get; }

		// @property (readonly, nonatomic) BOOL isOnRoute;
		[Export("isOnRoute")]
		bool IsOnRoute { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable timeBegin __attribute__((deprecated("")));
		[NullAllowed, Export("timeBegin")]
		NSDate TimeBegin { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable timeEnd __attribute__((deprecated("")));
		[NullAllowed, Export("timeEnd")]
		NSDate TimeEnd { get; }

		// @property (readonly, nonatomic) float speedLimit __attribute__((deprecated("")));
		[Export("speedLimit")]
		float SpeedLimit { get; }
	}

	// @interface NMATTSAudioOutput : NMAAudioOutput
	[BaseType(typeof(NMAAudioOutput))]
	[DisableDefaultCtor]
	interface NMATTSAudioOutput
	{
		// +(instancetype _Nullable)audioOutputWithText:(NSString * _Nonnull)text;
		[Static]
		[Export("audioOutputWithText:")]
		[return: NullAllowed]
		NMATTSAudioOutput AudioOutputWithText(string text);

		// -(instancetype _Nullable)initWithText:(NSString * _Nonnull)text;
		[Export("initWithText:")]
		IntPtr Constructor(string text);

		// @property (nonatomic) NSString * _Nonnull text;
		[Export("text")]
		string Text { get; set; }

		// @property (nonatomic) AVSpeechSynthesisVoice * _Nonnull voice;
		[Export("voice", ArgumentSemantic.Assign)]
		AVSpeechSynthesisVoice Voice { get; set; }

		// @property (nonatomic) float pitchMultiplier;
		[Export("pitchMultiplier")]
		float PitchMultiplier { get; set; }

		// @property (nonatomic) float speechRate;
		[Export("speechRate")]
		float SpeechRate { get; set; }
	}

	// typedef void (^NMATrafficEventCompletionBlock)();
	delegate void NMATrafficEventCompletionBlock();

	// @interface NMATrafficEvent : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATrafficEvent
	{
		// @property (readonly, getter = isValid, nonatomic) BOOL valid;
		[Export("valid")]
		bool Valid { [Bind("isValid")] get; }

		// @property (readonly, nonatomic) BOOL isVisible;
		[Export("isVisible")]
		bool IsVisible { get; }

		// @property (readonly, nonatomic) BOOL isReroutable;
		[Export("isReroutable")]
		bool IsReroutable { get; }

		// @property (readonly, nonatomic) BOOL isFlow;
		[Export("isFlow")]
		bool IsFlow { get; }

		// @property (readonly, nonatomic) BOOL isIncident;
		[Export("isIncident")]
		bool IsIncident { get; }

		// @property (readonly, nonatomic) NMATrafficEventSeverity severity;
		[Export("severity")]
		NMATrafficEventSeverity Severity { get; }

		// @property (readonly, nonatomic) NSInteger penalty;
		[Export("penalty")]
		nint Penalty { get; }

		// @property (readonly, nonatomic) NSString * _Nullable shortText;
		[NullAllowed, Export("shortText")]
		string ShortText { get; }

		// @property (readonly, nonatomic) NSString * _Nullable description;
		[NullAllowed, Export("description")]
		string Description { get; }

		// @property (readonly, nonatomic) NSString * _Nullable affectedStreets;
		[NullAllowed, Export("affectedStreets")]
		string AffectedStreets { get; }

		// -(void)getAffectedStreetsWithCompletion:(NMATrafficEventCompletionBlock _Nonnull)completion;
		[Export("getAffectedStreetsWithCompletion:")]
		void GetAffectedStreetsWithCompletion(NMATrafficEventCompletionBlock completion);

		// @property (readonly, nonatomic) NSString * _Nullable firstAffectedStreet;
		[NullAllowed, Export("firstAffectedStreet")]
		string FirstAffectedStreet { get; }

		// -(void)getFirstAffectedStreetWithCompletion:(NMATrafficEventCompletionBlock _Nonnull)completion;
		[Export("getFirstAffectedStreetWithCompletion:")]
		void GetFirstAffectedStreetWithCompletion(NMATrafficEventCompletionBlock completion);

		// @property (readonly, nonatomic) NSString * _Nullable startingStreets;
		[NullAllowed, Export("startingStreets")]
		string StartingStreets { get; }

		// -(void)getStartingStreetsWithCompletion:(NMATrafficEventCompletionBlock _Nonnull)completion;
		[Export("getStartingStreetsWithCompletion:")]
		void GetStartingStreetsWithCompletion(NMATrafficEventCompletionBlock completion);

		// @property (readonly, nonatomic) NSString * _Nullable endingStreets;
		[NullAllowed, Export("endingStreets")]
		string EndingStreets { get; }

		// -(void)getEndingStreetsWithCompletion:(NMATrafficEventCompletionBlock _Nonnull)completion;
		[Export("getEndingStreetsWithCompletion:")]
		void GetEndingStreetsWithCompletion(NMATrafficEventCompletionBlock completion);

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nullable affectedArea;
		[NullAllowed, Export("affectedArea")]
		NMAGeoBoundingBox AffectedArea { get; }

		// @property (readonly, nonatomic) NSInteger length;
		[Export("length")]
		nint Length { get; }

		// @property (readonly, nonatomic) NSInteger speedLimit;
		[Export("speedLimit")]
		nint SpeedLimit { get; }

		// @property (readonly, nonatomic) NSInteger trafficSpeed;
		[Export("trafficSpeed")]
		nint TrafficSpeed { get; }

		// @property (readonly, nonatomic) NMAImage * _Nullable iconOnRoute;
		[NullAllowed, Export("iconOnRoute")]
		NMAImage IconOnRoute { get; }

		// @property (readonly, nonatomic) NMAImage * _Nullable iconOffRoute;
		[NullAllowed, Export("iconOffRoute")]
		NMAImage IconOffRoute { get; }

		// @property (readonly, nonatomic) NSDate * _Nonnull activationDate;
		[Export("activationDate")]
		NSDate ActivationDate { get; }

		// @property (readonly, nonatomic) NSDate * _Nonnull updateDate;
		[Export("updateDate")]
		NSDate UpdateDate { get; }

		// @property (readonly, nonatomic) NSArray<NMARoadElement *> * _Nonnull affectedRoadElements;
		[Export("affectedRoadElements")]
		NMARoadElement[] AffectedRoadElements { get; }

		// -(NSUInteger)distanceToGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("distanceToGeoCoordinates:")]
		nuint DistanceToGeoCoordinates(NMAGeoCoordinates coordinates);

		// -(BOOL)isOnRoute:(NMARoute * _Nonnull)route;
		[Export("isOnRoute:")]
		bool IsOnRoute(NMARoute route);
	}

	// typedef void (^NMATrafficCompletionBlock)(NSArray<NMATrafficEvent *> * _Nullable, NMATrafficRequestError);
	delegate void NMATrafficCompletionBlock([NullAllowed] NMATrafficEvent[] arg0, NMATrafficRequestError arg1);

	// @protocol NMATrafficManagerObserver <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMATrafficManagerObserver
	{
		// @required -(void)trafficDataDidFinish;
		[Abstract]
		[Export("trafficDataDidFinish")]
		void TrafficDataDidFinish();
	}

	// @interface NMATrafficManager : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATrafficManager
	{
		// +(NMATrafficManager * _Nonnull)sharedTrafficManager;
		[Static]
		[Export("sharedTrafficManager")]
		//[Verify(MethodToProperty)]
		NMATrafficManager SharedTrafficManager { get; }

		// +(BOOL)setRefreshInterval:(NSTimeInterval)refreshInterval;
		[Static]
		[Export("setRefreshInterval:")]
		bool SetRefreshInterval(double refreshInterval);

		// -(BOOL)disableTrafficAutoUpdate;
		[Export("disableTrafficAutoUpdate")]
		//[Verify(MethodToProperty)]
		bool DisableTrafficAutoUpdate { get; }

		// -(BOOL)isTrafficAutoUpdateEnabled;
		[Export("isTrafficAutoUpdateEnabled")]
		//[Verify(MethodToProperty)]
		bool IsTrafficAutoUpdateEnabled { get; }

		// -(void)addObserver:(id<NMATrafficManagerObserver> _Nonnull)observer;
		[Export("addObserver:")]
		void AddObserver(NMATrafficManagerObserver observer);

		// -(void)removeObserver:(id<NMATrafficManagerObserver> _Nonnull)observer;
		[Export("removeObserver:")]
		void RemoveObserver(NMATrafficManagerObserver observer);

		// -(NSNumber * _Nullable)requestTrafficOnRoute:(NMARoute * _Nonnull)route;
		[Export("requestTrafficOnRoute:")]
		[return: NullAllowed]
		NSNumber RequestTrafficOnRoute(NMARoute route);

		// -(NSNumber * _Nullable)requestTrafficOnRoute:(NMARoute * _Nonnull)route radius:(NSUInteger)radius;
		[Export("requestTrafficOnRoute:radius:")]
		[return: NullAllowed]
		NSNumber RequestTrafficOnRoute(NMARoute route, nuint radius);

		// -(NSNumber * _Nullable)requestTrafficAtGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("requestTrafficAtGeoCoordinates:")]
		[return: NullAllowed]
		NSNumber RequestTrafficAtGeoCoordinates(NMAGeoCoordinates coordinates);

		// -(NSNumber * _Nullable)requestTrafficAtGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates radius:(NSUInteger)radius;
		[Export("requestTrafficAtGeoCoordinates:radius:")]
		[return: NullAllowed]
		NSNumber RequestTrafficAtGeoCoordinates(NMAGeoCoordinates coordinates, nuint radius);

		// -(void)cancelRequest:(NSNumber * _Nonnull)requestId;
		[Export("cancelRequest:")]
		void CancelRequest(NSNumber requestId);

		// -(void)getTrafficEventsOnRoute:(NMARoute * _Nonnull)route withCompletion:(NMATrafficCompletionBlock _Nonnull)completionBlock;
		[Export("getTrafficEventsOnRoute:withCompletion:")]
		void GetTrafficEventsOnRoute(NMARoute route, NMATrafficCompletionBlock completionBlock);

		// -(void)getTrafficEventsOnRouteElements:(NSArray<NMARouteElement *> * _Nonnull)routeElements withCompletion:(NMATrafficCompletionBlock _Nonnull)completionBlock;
		[Export("getTrafficEventsOnRouteElements:withCompletion:")]
		void GetTrafficEventsOnRouteElements(NMARouteElement[] routeElements, NMATrafficCompletionBlock completionBlock);
	}

	// @interface NMATrafficNotification : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATrafficNotification
	{
		// @property (readonly, nonatomic) NSArray<NMATrafficNotificationInfo *> * _Nonnull trafficNotificationInfo;
		[Export("trafficNotificationInfo")]
		NMATrafficNotificationInfo[] TrafficNotificationInfo { get; }
	}

	// @interface NMATrafficNotificationInfo : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATrafficNotificationInfo
	{
		// @property (readonly, nonatomic) NMATrafficNotificationType type;
		[Export("type")]
		NMATrafficNotificationType Type { get; }

		// @property (readonly, nonatomic) NMATrafficSeverity severity;
		[Export("severity")]
		NMATrafficSeverity Severity { get; }

		// @property (readonly, nonatomic) double distance;
		[Export("distance")]
		double Distance { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull affectedArea;
		[Export("affectedArea")]
		NMAGeoBoundingBox AffectedArea { get; }

		// @property (readonly, nonatomic) double affectedLength;
		[Export("affectedLength")]
		double AffectedLength { get; }

		// @property (readonly, nonatomic) NSTimeInterval travelTime;
		[Export("travelTime")]
		double TravelTime { get; }

		// @property (readonly, nonatomic) NSTimeInterval travelTimeWithTraffic;
		[Export("travelTimeWithTraffic")]
		double TravelTimeWithTraffic { get; }
	}

	// @interface NMATrafficObject : NMAProxyObject
	[BaseType(typeof(NMAProxyObject))]
	[DisableDefaultCtor]
	interface NMATrafficObject
	{
		// @property (readonly, nonatomic) NMATrafficEvent * _Nonnull trafficEvent;
		[Export("trafficEvent")]
		NMATrafficEvent TrafficEvent { get; }
	}

	// @interface NMATrafficSign : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATrafficSign
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull coordinate;
		[Export("coordinate")]
		NMAGeoCoordinates Coordinate { get; }

		// @property (readonly, assign, nonatomic) NSUInteger type;
		[Export("type")]
		nuint Type { get; }

		// @property (readonly, assign, nonatomic) NMASignCategory category;
		[Export("category", ArgumentSemantic.Assign)]
		NMASignCategory Category { get; }

		// @property (readonly, assign, nonatomic) NMASignSubcategory subcategory;
		[Export("subcategory", ArgumentSemantic.Assign)]
		NMASignSubcategory Subcategory { get; }

		// @property (readonly, assign, nonatomic) NMASignLocation location;
		[Export("location", ArgumentSemantic.Assign)]
		NMASignLocation Location { get; }

		// @property (readonly, assign, nonatomic) NMASignDirection direction;
		[Export("direction", ArgumentSemantic.Assign)]
		NMASignDirection Direction { get; }

		// @property (readonly, assign, nonatomic) NSUInteger subtype;
		[Export("subtype")]
		nuint Subtype { get; }

		// @property (readonly, nonatomic) NSSet<NSNumber *> * _Nonnull applicableForTransportTypes;
		[Export("applicableForTransportTypes")]
		NSSet<NSNumber> ApplicableForTransportTypes { get; }

		// @property (readonly, assign, nonatomic) NMASignWeatherAffects weatherAffects;
		[Export("weatherAffects", ArgumentSemantic.Assign)]
		NMASignWeatherAffects WeatherAffects { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull signValue;
		[Export("signValue")]
		string SignValue { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull duration;
		[Export("duration")]
		string Duration { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull prewarning;
		[Export("prewarning")]
		string Prewarning { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull validityTime;
		[Export("validityTime")]
		string ValidityTime { get; }
	}

	// @protocol NMATransitManagerDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMATransitManagerDelegate
	{
		// @optional -(void)transitManager:(NMATransitManager * _Nonnull)transitManager didGetAccessInfo:(NMATransitAccess * _Nonnull)access forId:(NSString * _Nonnull)uniqueId;
		[Export("transitManager:didGetAccessInfo:forId:")]
		void DidGetAccessInfo(NMATransitManager transitManager, NMATransitAccess access, string uniqueId);

		// @optional -(void)transitManager:(NMATransitManager * _Nonnull)transitManager didGetLineInfo:(NMATransitLine * _Nonnull)line forId:(NSString * _Nonnull)uniqueId;
		[Export("transitManager:didGetLineInfo:forId:")]
		void DidGetLineInfo(NMATransitManager transitManager, NMATransitLine line, string uniqueId);

		// @optional -(void)transitManager:(NMATransitManager * _Nonnull)transitManager didGetStopInfo:(NMATransitStop * _Nonnull)stop forId:(NSString * _Nonnull)uniqueId;
		[Export("transitManager:didGetStopInfo:forId:")]
		void DidGetStopInfo(NMATransitManager transitManager, NMATransitStop stop, string uniqueId);

		// @optional -(void)transitManager:(NMATransitManager * _Nonnull)transitManager didGetSystemInfo:(NMATransitSystem * _Nonnull)system forId:(NSString * _Nonnull)uniqueId;
		[Export("transitManager:didGetSystemInfo:forId:")]
		void DidGetSystemInfo(NMATransitManager transitManager, NMATransitSystem system, string uniqueId);

		// @optional -(void)transitManager:(NMATransitManager * _Nonnull)transitManager didCompleteWithError:(NSError * _Nullable)error;
		[Export("transitManager:didCompleteWithError:")]
		void DidCompleteWithError(NMATransitManager transitManager, [NullAllowed] NSError error);
	}

	// @interface NMATransitManager : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitManager
	{
		// +(NMATransitManager * _Nonnull)sharedTransitManager;
		[Static]
		[Export("sharedTransitManager")]
		//[Verify(MethodToProperty)]
		NMATransitManager SharedTransitManager { get; }

		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMATransitManagerDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMATransitManagerDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// -(void)requestAccessInfoForId:(NSString * _Nonnull)uniqueId;
		[Export("requestAccessInfoForId:")]
		void RequestAccessInfoForId(string uniqueId);

		// -(void)requestLineInfoForId:(NSString * _Nonnull)uniqueId;
		[Export("requestLineInfoForId:")]
		void RequestLineInfoForId(string uniqueId);

		// -(void)requestStopInfoForId:(NSString * _Nonnull)uniqueId;
		[Export("requestStopInfoForId:")]
		void RequestStopInfoForId(string uniqueId);

		// -(void)requestSystemInfoForId:(NSString * _Nonnull)uniqueId;
		[Export("requestSystemInfoForId:")]
		void RequestSystemInfoForId(string uniqueId);

		// -(void)requestInfoForObject:(NMATransitObject * _Nonnull)object;
		[Export("requestInfoForObject:")]
		void RequestInfoForObject(NMATransitObject @object);
	}

	// @interface NMATransitAccess : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitAccess
	{
		// @property (readonly, nonatomic) NSString * _Nonnull uniqueId;
		[Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull name;
		[Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable location;
		[NullAllowed, Export("location")]
		NMAGeoCoordinates Location { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull stopId;
		[Export("stopId")]
		string StopId { get; }

		// -(BOOL)hasTransitType:(NMATransitType)type;
		[Export("hasTransitType:")]
		bool HasTransitType(NMATransitType type);
	}

	// @interface NMATransitLine : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitLine
	{
		// @property (readonly, nonatomic) NSString * _Nonnull uniqueId;
		[Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull officialName;
		[Export("officialName")]
		string OfficialName { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull informalName;
		[Export("informalName")]
		string InformalName { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull shortName;
		[Export("shortName")]
		string ShortName { get; }

		// @property (readonly, nonatomic) NMATransitType transitType;
		[Export("transitType")]
		NMATransitType TransitType { get; }

		// @property (readonly, nonatomic) UIColor * _Nullable color;
		[NullAllowed, Export("color")]
		UIColor Color { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull systemId;
		[Export("systemId")]
		string SystemId { get; }
	}

	// @interface NMATransitObject : NMAProxyObject
	[BaseType(typeof(NMAProxyObject))]
	[DisableDefaultCtor]
	interface NMATransitObject
	{
		// @property (readonly, nonatomic) NMATransitObjectType type;
		[Export("type")]
		NMATransitObjectType Type { get; }

		// @property (readonly, nonatomic) NSString * _Nullable uniqueId;
		[NullAllowed, Export("uniqueId")]
		string UniqueId { get; }
	}

	// @interface NMATransitStop : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitStop
	{
		// @property (readonly, nonatomic) NSString * _Nonnull uniqueId;
		[Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull officialName;
		[Export("officialName")]
		string OfficialName { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull informalName;
		[Export("informalName")]
		string InformalName { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable location;
		[NullAllowed, Export("location")]
		NMAGeoCoordinates Location { get; }

		// @property (readonly, nonatomic) NSArray<NSString *> * _Nonnull lineIds;
		[Export("lineIds")]
		string[] LineIds { get; }

		// @property (readonly, nonatomic) NSArray<NSString *> * _Nonnull systemIds;
		[Export("systemIds")]
		string[] SystemIds { get; }

		// -(BOOL)hasTransitType:(NMATransitType)type;
		[Export("hasTransitType:")]
		bool HasTransitType(NMATransitType type);
	}

	// @interface NMATransitSystem : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitSystem
	{
		// @property (readonly, nonatomic) NSString * _Nonnull uniqueId;
		[Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull officialName;
		[Export("officialName")]
		string OfficialName { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull informalName;
		[Export("informalName")]
		string InformalName { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull shortName;
		[Export("shortName")]
		string ShortName { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull website;
		[Export("website")]
		string Website { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull companyOfficialName;
		[Export("companyOfficialName")]
		string CompanyOfficialName { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull companyInformalName;
		[Export("companyInformalName")]
		string CompanyInformalName { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull companyShortName;
		[Export("companyShortName")]
		string CompanyShortName { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull companyWebsite;
		[Export("companyWebsite")]
		string CompanyWebsite { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull companyRoutePlannerWebsite;
		[Export("companyRoutePlannerWebsite")]
		string CompanyRoutePlannerWebsite { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull companyScheduleWebsite;
		[Export("companyScheduleWebsite")]
		string CompanyScheduleWebsite { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull companyTelephoneNumber;
		[Export("companyTelephoneNumber")]
		string CompanyTelephoneNumber { get; }
	}

	// @protocol NMATruckRestrictionWarnerDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMATruckRestrictionWarnerDelegate
	{
		// @optional -(void)truckRestrictionWarner:(NMATruckRestrictionWarner * _Nonnull)truckWarner didDetectTruckRestriction:(NMATruckRestrictionNotification * _Nonnull)truckNotification;
		[Export("truckRestrictionWarner:didDetectTruckRestriction:")]
		void DidDetectTruckRestriction(NMATruckRestrictionWarner truckWarner, NMATruckRestrictionNotification truckNotification);

		// @optional -(void)truckRestrictionWarner:(NMATruckRestrictionWarner * _Nonnull)truckWarner didUpdateTruckRestriction:(NSArray<NMATruckRestriction *> * _Nullable)truckRestrictions;
		[Export("truckRestrictionWarner:didUpdateTruckRestriction:")]
		void DidUpdateTruckRestriction(NMATruckRestrictionWarner truckWarner, [NullAllowed] NMATruckRestriction[] truckRestrictions);
	}

	// @interface NMATruckRestrictionWarner : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATruckRestrictionWarner
	{
		// +(NSArray<NMATruckRestriction *> * _Nullable)truckRestrictionsForRoadElement:(NMARoadElement * _Nonnull)roadElement;
		[Static]
		[Export("truckRestrictionsForRoadElement:")]
		[return: NullAllowed]
		NMATruckRestriction[] TruckRestrictionsForRoadElement(NMARoadElement roadElement);

		// +(NSArray<NMATruckRestriction *> * _Nullable)truckRestrictionsForRoadElement:(NMARoadElement * _Nonnull)roadElement routingMode:(NMARoutingMode * _Nonnull)mode;
		[Static]
		[Export("truckRestrictionsForRoadElement:routingMode:")]
		[return: NullAllowed]
		NMATruckRestriction[] TruckRestrictionsForRoadElement(NMARoadElement roadElement, NMARoutingMode mode);

		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMATruckRestrictionWarnerDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMATruckRestrictionWarnerDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// -(void)start;
		[Export("start")]
		void Start();

		// -(void)stop;
		[Export("stop")]
		void Stop();
	}

	// @interface NMATruckRestrictionNotification : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATruckRestrictionNotification
	{
		// @property (readonly, nonatomic) NSArray<NMATruckRestriction *> * _Nonnull truckRestrictions __attribute__((deprecated("")));
		[Export("truckRestrictions")]
		NMATruckRestriction[] TruckRestrictions { get; }

		// @property (readonly, nonatomic) NSArray<NMATruckRestrictionsInfo *> * _Nonnull truckRestrictionsInfos;
		[Export("truckRestrictionsInfos")]
		NMATruckRestrictionsInfo[] TruckRestrictionsInfos { get; }

		// @property (readonly, nonatomic) BOOL isOnRoute;
		[Export("isOnRoute")]
		bool IsOnRoute { get; }
	}

	// @interface NMATruckRestrictionsInfo : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATruckRestrictionsInfo
	{
		// @property (readonly, nonatomic) NMARoadElement * _Nonnull roadElement;
		[Export("roadElement")]
		NMARoadElement RoadElement { get; }

		// @property (readonly, nonatomic) NSUInteger distance;
		[Export("distance")]
		nuint Distance { get; }

		// @property (readonly, nonatomic) NSArray<NMATruckRestriction *> * _Nonnull truckRestrictions;
		[Export("truckRestrictions")]
		NMATruckRestriction[] TruckRestrictions { get; }
	}

	// @protocol NMAAdasisV2EngineDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAAdasisV2EngineDelegate
	{
		// @optional -(void)adasisV2Engine:(NMAAdasisV2Engine * _Nonnull)adasisV2Engine didReceiveAdasisMessage:(NSData * _Nonnull)message;
		[Export("adasisV2Engine:didReceiveAdasisMessage:")]
		void DidReceiveAdasisMessage(NMAAdasisV2Engine adasisV2Engine, NSData message);
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const NSUInteger NMAAdasisV2MessageLength;
		[Field("NMAAdasisV2MessageLength", "__Internal")]
		nuint NMAAdasisV2MessageLength { get; }

		// extern NSString *const _Nonnull kNMAAdasisV2EngineErrorDomain;
		[Field("kNMAAdasisV2EngineErrorDomain", "__Internal")]
		NSString kNMAAdasisV2EngineErrorDomain { get; }
	}

	// @interface NMAAdasisV2Engine : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAAdasisV2Engine
	{
		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMAAdasisV2EngineDelegate Delegate { get; set; }

		// @property (readwrite, nonatomic, weak) id<NMAAdasisV2EngineDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// -(instancetype _Nonnull)initWithConfiguration:(NMAAdasisV2MessageConfiguration * _Nonnull)configuration;
		[Export("initWithConfiguration:")]
		IntPtr Constructor(NMAAdasisV2MessageConfiguration configuration);

		// -(NSError * _Nullable)update;
		[NullAllowed, Export("update")]
		//[Verify(MethodToProperty)]
		NSError Update { get; }
	}

	// @interface NMAAdasisV2MessageConfiguration : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAAdasisV2MessageConfiguration
	{
		// @property (nonatomic) BOOL metaDataEnabled;
		[Export("metaDataEnabled")]
		bool MetaDataEnabled { get; set; }

		// @property (nonatomic) BOOL positionEnabled;
		[Export("positionEnabled")]
		bool PositionEnabled { get; set; }

		// @property (nonatomic) BOOL segmentEnabled;
		[Export("segmentEnabled")]
		bool SegmentEnabled { get; set; }

		// @property (nonatomic) BOOL stubEnabled;
		[Export("stubEnabled")]
		bool StubEnabled { get; set; }

		// @property (nonatomic) BOOL latitudeLongitudeEnabled;
		[Export("latitudeLongitudeEnabled")]
		bool LatitudeLongitudeEnabled { get; set; }

		// @property (nonatomic) BOOL pvidEnabled;
		[Export("pvidEnabled")]
		bool PvidEnabled { get; set; }

		// @property (nonatomic) BOOL roadAccessibilityEnabled;
		[Export("roadAccessibilityEnabled")]
		bool RoadAccessibilityEnabled { get; set; }

		// @property (nonatomic) BOOL slopeEnabled;
		[Export("slopeEnabled")]
		bool SlopeEnabled { get; set; }

		// +(instancetype _Nonnull)createWithAllMessagesEnabled;
		[Static]
		[Export("createWithAllMessagesEnabled")]
		NMAAdasisV2MessageConfiguration CreateWithAllMessagesEnabled();

		// +(instancetype _Nonnull)createWithDefaultMessagesEnabled;
		[Static]
		[Export("createWithDefaultMessagesEnabled")]
		NMAAdasisV2MessageConfiguration CreateWithDefaultMessagesEnabled();
	}

	// @interface NMAEHLink : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAEHLink
	{
		// @property (nonatomic) UInt64 id;
		[Export("id")]
		ulong Id { get; set; }

		// @property (nonatomic) NMAEHLinkDirection direction;
		[Export("direction", ArgumentSemantic.Assign)]
		NMAEHLinkDirection Direction { get; set; }

		// @property (nonatomic) NSUInteger startOffsetCentimeters;
		[Export("startOffsetCentimeters")]
		nuint StartOffsetCentimeters { get; set; }

		// @property (nonatomic) NSUInteger endOffsetCentimeters;
		[Export("endOffsetCentimeters")]
		nuint EndOffsetCentimeters { get; set; }

		// -(BOOL)isEqualToLink:(NMAEHLink * _Nonnull)link;
		[Export("isEqualToLink:")]
		bool IsEqualToLink(NMAEHLink link);
	}

	// @interface NMAEHLinkInformation : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAEHLinkInformation
	{
		// @property (nonatomic) BOOL isBridge;
		[Export("isBridge")]
		bool IsBridge { get; set; }

		// @property (nonatomic) BOOL isDividedRoad;
		[Export("isDividedRoad")]
		bool IsDividedRoad { get; set; }

		// @property (nonatomic) BOOL isTunnel;
		[Export("isTunnel")]
		bool IsTunnel { get; set; }

		// @property (nonatomic) BOOL isUrban;
		[Export("isUrban")]
		bool IsUrban { get; set; }

		// @property (nonatomic) BOOL isPedestrianOpen;
		[Export("isPedestrianOpen")]
		bool IsPedestrianOpen { get; set; }

		// @property (nonatomic) double speedLimitMetersPerSecond;
		[Export("speedLimitMetersPerSecond")]
		double SpeedLimitMetersPerSecond { get; set; }

		// @property (nonatomic) double lengthMeters;
		[Export("lengthMeters")]
		double LengthMeters { get; set; }

		// -(BOOL)isOpenForCars:(NMAEHLinkAllowedDirection)direction;
		[Export("isOpenForCars:")]
		bool IsOpenForCars(NMAEHLinkAllowedDirection direction);

		// -(BOOL)isCarThroughOpen:(NMAEHLinkAllowedDirection)direction;
		[Export("isCarThroughOpen:")]
		bool IsCarThroughOpen(NMAEHLinkAllowedDirection direction);

		// @property (nonatomic) NMAEHLinkFunctionalRoadClass functionalRoadClass;
		[Export("functionalRoadClass", ArgumentSemantic.Assign)]
		NMAEHLinkFunctionalRoadClass FunctionalRoadClass { get; set; }

		// @property (nonatomic) NMAEHLinkFormOfWay formOfWay;
		[Export("formOfWay", ArgumentSemantic.Assign)]
		NMAEHLinkFormOfWay FormOfWay { get; set; }
	}

	// @interface NMAEHLinkRange : NSEnumerator
	[BaseType(typeof(NSEnumerator))]
	[DisableDefaultCtor]
	interface NMAEHLinkRange
	{
		// @property (readonly, nonatomic) NSUInteger size;
		[Export("size")]
		nuint Size { get; }

		// -(NMAEHLink * _Nullable)nextObject;
		[NullAllowed, Export("nextObject")]
		//[Verify(MethodToProperty)]
		NMAEHLink NextObject { get; }

		// -(void)reset;
		[Export("reset")]
		void Reset();
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull kNMAEHMapAccessorErrorDomain;
		[Field("kNMAEHMapAccessorErrorDomain", "__Internal")]
		NSString kNMAEHMapAccessorErrorDomain { get; }
	}

	// @interface NMAEHMapAccessor : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAEHMapAccessor
	{
		// -(NMAEHLinkInformation * _Nullable)getLinkInformation:(NMAEHLink * _Nonnull)link;
		[Export("getLinkInformation:")]
		[return: NullAllowed]
		NMAEHLinkInformation GetLinkInformation(NMAEHLink link);

		// -(NMAEHLinkInformation * _Nullable)getLinkInformation:(NMAEHLink * _Nonnull)link error:(NSError * _Nullable * _Nonnull)error;
		[Export("getLinkInformation:error:")]
		[return: NullAllowed]
		NMAEHLinkInformation GetLinkInformation(NMAEHLink link, [NullAllowed] out NSError error);

		// -(NMAGeoPolyline * _Nullable)getLinkPolyline:(NMAEHLink * _Nonnull)link;
		[Export("getLinkPolyline:")]
		[return: NullAllowed]
		NMAGeoPolyline GetLinkPolyline(NMAEHLink link);

		// -(NMAGeoPolyline * _Nullable)getLinkPolyline:(NMAEHLink * _Nonnull)link error:(NSError * _Nullable * _Nonnull)error;
		[Export("getLinkPolyline:error:")]
		[return: NullAllowed]
		NMAGeoPolyline GetLinkPolyline(NMAEHLink link, [NullAllowed] out NSError error);

		// -(NSArray<NMAEHLink *> * _Nullable)getConnectedLinks:(NMAEHLink * _Nonnull)link;
		[Export("getConnectedLinks:")]
		[return: NullAllowed]
		NMAEHLink[] GetConnectedLinks(NMAEHLink link);

		// -(NSArray<NMAEHLink *> * _Nullable)getConnectedLinks:(NMAEHLink * _Nonnull)link error:(NSError * _Nullable * _Nonnull)error;
		[Export("getConnectedLinks:error:")]
		[return: NullAllowed]
		NMAEHLink[] GetConnectedLinks(NMAEHLink link, [NullAllowed] out NSError error);

		// -(NMAEHMetaData * _Nullable)getMetaData:(NMAEHLink * _Nonnull)link;
		[Export("getMetaData:")]
		[return: NullAllowed]
		NMAEHMetaData GetMetaData(NMAEHLink link);

		// -(NMAEHMetaData * _Nullable)getMetaData:(NMAEHLink * _Nonnull)link error:(NSError * _Nullable * _Nonnull)error;
		[Export("getMetaData:error:")]
		[return: NullAllowed]
		NMAEHMetaData GetMetaData(NMAEHLink link, [NullAllowed] out NSError error);

		// -(NSString * _Nullable)getPVID:(NMAEHLink * _Nonnull)link;
		[Export("getPVID:")]
		[return: NullAllowed]
		string GetPVID(NMAEHLink link);

		// -(NSString * _Nullable)getPVID:(NMAEHLink * _Nonnull)link error:(NSError * _Nullable * _Nonnull)error;
		[Export("getPVID:error:")]
		[return: NullAllowed]
		string GetPVID(NMAEHLink link, [NullAllowed] out NSError error);

		// -(NSArray<NMAEHSlopeDataPoint *> * _Nullable)getSlopeDataPoints:(NMAEHLink * _Nonnull)link;
		[Export("getSlopeDataPoints:")]
		[return: NullAllowed]
		NMAEHSlopeDataPoint[] GetSlopeDataPoints(NMAEHLink link);

		// -(NSArray<NMAEHSlopeDataPoint *> * _Nullable)getSlopeDataPoints:(NMAEHLink * _Nonnull)link error:(NSError * _Nullable * _Nonnull)error;
		[Export("getSlopeDataPoints:error:")]
		[return: NullAllowed]
		NMAEHSlopeDataPoint[] GetSlopeDataPoints(NMAEHLink link, [NullAllowed] out NSError error);
	}

	// @interface NMAEHMetaData : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAEHMetaData
	{
		// @property (nonatomic) NMAEHMetaDataSideOfDriving sideOfDriving;
		[Export("sideOfDriving", ArgumentSemantic.Assign)]
		NMAEHMetaDataSideOfDriving SideOfDriving { get; set; }

		// @property (nonatomic) NMAEHMetaDataUnitSystem unitSystem;
		[Export("unitSystem", ArgumentSemantic.Assign)]
		NMAEHMetaDataUnitSystem UnitSystem { get; set; }

		// @property (nonatomic) NSUInteger countryCode;
		[Export("countryCode")]
		nuint CountryCode { get; set; }

		// @property (nonatomic) NSUInteger regionCode;
		[Export("regionCode")]
		nuint RegionCode { get; set; }
	}

	// @interface NMAEHPathTree : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAEHPathTree
	{
		// @property (readonly, nonatomic) NSUInteger offsetCentimeters;
		[Export("offsetCentimeters")]
		nuint OffsetCentimeters { get; }

		// @property (readonly, nonatomic) float probability;
		[Export("probability")]
		float Probability { get; }

		// @property (readonly, nonatomic) NMAEHPathTree * _Nullable parent;
		[NullAllowed, Export("parent")]
		NMAEHPathTree Parent { get; }

		// @property (readonly, nonatomic) NMAEHPathTreeRange * _Nonnull children;
		[Export("children")]
		NMAEHPathTreeRange Children { get; }

		// @property (readonly, nonatomic) NMAEHLinkRange * _Nonnull links;
		[Export("links")]
		NMAEHLinkRange Links { get; }

		// -(BOOL)isEqualToPathTree:(NMAEHPathTree * _Nonnull)pathTree;
		[Export("isEqualToPathTree:")]
		bool IsEqualToPathTree(NMAEHPathTree pathTree);
	}

	// @interface NMAEHPathTreeRange : NSEnumerator
	[BaseType(typeof(NSEnumerator))]
	[DisableDefaultCtor]
	interface NMAEHPathTreeRange
	{
		// @property (readonly, nonatomic) NSUInteger size;
		[Export("size")]
		nuint Size { get; }

		// -(NMAEHPathTree * _Nullable)nextObject;
		[NullAllowed, Export("nextObject")]
		//[Verify(MethodToProperty)]
		NMAEHPathTree NextObject { get; }

		// -(void)reset;
		[Export("reset")]
		void Reset();
	}

	// @interface NMAEHPosition : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAEHPosition
	{
		// @property (readonly, nonatomic) NSUInteger offsetCentimeters;
		[Export("offsetCentimeters")]
		nuint OffsetCentimeters { get; }

		// @property (readonly, nonatomic) double speedMetersPerSecond;
		[Export("speedMetersPerSecond")]
		double SpeedMetersPerSecond { get; }

		// @property (readonly, nonatomic) NSDate * _Nonnull timestamp;
		[Export("timestamp")]
		NSDate Timestamp { get; }

		// @property (readonly, nonatomic) NMAEHPathTree * _Nullable pathTree;
		[NullAllowed, Export("pathTree")]
		NMAEHPathTree PathTree { get; }
	}

	// @interface NMAEHSlopeDataPoint : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAEHSlopeDataPoint
	{
		// @property (nonatomic) double relativePositionOnLink;
		[Export("relativePositionOnLink")]
		double RelativePositionOnLink { get; set; }

		// @property (nonatomic) double slopePercent;
		[Export("slopePercent")]
		double SlopePercent { get; set; }
	}

	// @protocol NMAElectronicHorizonDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAElectronicHorizonDelegate
	{
		// @optional -(void)electronicHorizon:(NMAElectronicHorizon * _Nonnull)electronicHorizon didReceiveNewPosition:(NMAEHPosition * _Nonnull)position;
		[Export("electronicHorizon:didReceiveNewPosition:")]
		void ElectronicHorizonDidReceiveNewPosition(NMAElectronicHorizon electronicHorizon, NMAEHPosition position);

		// @optional -(void)electronicHorizonDidReceiveTreeReset:(NMAElectronicHorizon * _Nonnull)electronicHorizon;
		[Export("electronicHorizonDidReceiveTreeReset:")]
		void ElectronicHorizonDidReceiveTreeReset(NMAElectronicHorizon electronicHorizon);

		// @optional -(void)electronicHorizon:(NMAElectronicHorizon * _Nonnull)electronicHorizon didReceiveLinkAdded:(NMAEHPathTree * _Nonnull)pathTree link:(NMAEHLink * _Nonnull)link;
		[Export("electronicHorizon:didReceiveLinkAdded:link:")]
		void ElectronicHorizonDidReceiveLinkAdded(NMAElectronicHorizon electronicHorizon, NMAEHPathTree pathTree, NMAEHLink link);

		// @optional -(void)electronicHorizon:(NMAElectronicHorizon * _Nonnull)electronicHorizon didReceiveLinkRemoved:(NMAEHPathTree * _Nonnull)pathTree link:(NMAEHLink * _Nonnull)link;
		[Export("electronicHorizon:didReceiveLinkRemoved:link:")]
		void ElectronicHorizonDidReceiveLinkRemoved(NMAElectronicHorizon electronicHorizon, NMAEHPathTree pathTree, NMAEHLink link);

		// @optional -(void)electronicHorizon:(NMAElectronicHorizon * _Nonnull)electronicHorizon didReceivePathAdded:(NMAEHPathTree * _Nonnull)pathTree;
		[Export("electronicHorizon:didReceivePathAdded:")]
		void ElectronicHorizonDidReceivePathAdded(NMAElectronicHorizon electronicHorizon, NMAEHPathTree pathTree);

		// @optional -(void)electronicHorizon:(NMAElectronicHorizon * _Nonnull)electronicHorizon didReceivePathRemoved:(NMAEHPathTree * _Nonnull)pathTree;
		[Export("electronicHorizon:didReceivePathRemoved:")]
		void ElectronicHorizonDidReceivePathRemoved(NMAElectronicHorizon electronicHorizon, NMAEHPathTree pathTree);

		// @optional -(void)electronicHorizon:(NMAElectronicHorizon * _Nonnull)electronicHorizon didReceiveChildDetached:(NMAEHPathTree * _Nonnull)parent child:(NMAEHPathTree * _Nonnull)child;
		[Export("electronicHorizon:didReceiveChildDetached:child:")]
		void ElectronicHorizonDidReceiveChildDetached(NMAElectronicHorizon electronicHorizon, NMAEHPathTree parent, NMAEHPathTree child);
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull kNMAElectronicHorizonErrorDomain;
		[Field("kNMAElectronicHorizonErrorDomain", "__Internal")]
		NSString kNMAElectronicHorizonErrorDomain { get; }
	}

	// @interface NMAElectronicHorizon : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAElectronicHorizon
	{
		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMAElectronicHorizonDelegate Delegate { get; set; }

		// @property (readwrite, nonatomic, weak) id<NMAElectronicHorizonDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// @property (readonly, nonatomic, strong) NMAEHMapAccessor * _Nonnull mapAccessor;
		[Export("mapAccessor", ArgumentSemantic.Strong)]
		NMAEHMapAccessor MapAccessor { get; }

		// -(NSError * _Nullable)update;
		[NullAllowed, Export("update")]
		//[Verify(MethodToProperty)]
		NSError Update { get; }

		// -(NSError * _Nullable)setTrailingDistanceInCentimeters:(NSInteger)distance;
		[Export("setTrailingDistanceInCentimeters:")]
		[return: NullAllowed]
		NSError SetTrailingDistanceInCentimeters(nint distance);

		// -(NSError * _Nullable)setLookAheadDistancesInCentimeters:(NSArray<NSNumber *> * _Nonnull)distances;
		[Export("setLookAheadDistancesInCentimeters:")]
		[return: NullAllowed]
		NSError SetLookAheadDistancesInCentimeters(NSNumber[] distances);

		// -(NSError * _Nullable)setRoute:(NMARoute * _Nonnull)route;
		[Export("setRoute:")]
		[return: NullAllowed]
		NSError SetRoute(NMARoute route);
	}

	// @interface NMAFleetConnectivityEvent : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAFleetConnectivityEvent
	{
		// @property (readwrite, nonatomic) NSMutableDictionary<NSString *,NSString *> * _Nullable content;
		[NullAllowed, Export("content", ArgumentSemantic.Assign)]
		NSMutableDictionary<NSString, NSString> Content { get; set; }

		// @property (readonly, nonatomic) NSString * _Nonnull jobId;
		[Export("jobId")]
		string JobId { get; }
	}

	// @interface NMAFleetConnectivityCustomEvent : NMAFleetConnectivityEvent
	[BaseType(typeof(NMAFleetConnectivityEvent))]
	interface NMAFleetConnectivityCustomEvent
	{
		// @property (readwrite, nonatomic) NSString * _Nullable jobId;
		[NullAllowed, Export("jobId")]
		string JobId { get; set; }
	}

	// @interface NMAFleetConnectivityMessage : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAFleetConnectivityMessage
	{
		// @property (readonly, nonatomic) NSString * _Nullable jobId;
		[NullAllowed, Export("jobId")]
		string JobId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull dispatcherId;
		[Export("dispatcherId")]
		string DispatcherId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull assetId;
		[Export("assetId")]
		string AssetId { get; }

		// @property (readonly, nonatomic) NSString * _Nullable message;
		[NullAllowed, Export("message")]
		string Message { get; }

		// @property (readonly, nonatomic) NSTimeInterval creationTime;
		[Export("creationTime")]
		double CreationTime { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NSString *> * _Nullable content;
		[NullAllowed, Export("content")]
		NSDictionary<NSString, NSString> Content { get; }
	}

	// @interface NMAFleetConnectivityCustomMessage : NMAFleetConnectivityMessage
	[BaseType(typeof(NMAFleetConnectivityMessage))]
	interface NMAFleetConnectivityCustomMessage
	{
	}

	// @interface NMAFleetConnectivityError : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAFleetConnectivityError
	{
		// @property (readonly, nonatomic) NSUInteger responseCode;
		[Export("responseCode")]
		nuint ResponseCode { get; }

		// @property (readonly, nonatomic) NSString * _Nullable errorId;
		[NullAllowed, Export("errorId")]
		string ErrorId { get; }

		// @property (readonly, nonatomic) NMAFleetConnectivityErrorType errorType;
		[Export("errorType")]
		NMAFleetConnectivityErrorType ErrorType { get; }

		// @property (readonly, nonatomic) NSArray<NMAFleetConnectivityIssue *> * _Nullable issues;
		[NullAllowed, Export("issues")]
		NMAFleetConnectivityIssue[] Issues { get; }
	}

	// @interface NMAFleetConnectivityIssue : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAFleetConnectivityIssue
	{
		// @property (readonly, nonatomic) NSString * _Nullable message;
		[NullAllowed, Export("message")]
		string Message { get; }

		// @property (readonly, nonatomic) NSString * _Nullable code;
		[NullAllowed, Export("code")]
		string Code { get; }
	}

	// @interface NMAFleetConnectivityJobCancelledEvent : NMAFleetConnectivityEvent
	[BaseType(typeof(NMAFleetConnectivityEvent))]
	interface NMAFleetConnectivityJobCancelledEvent
	{
	}

	// @interface NMAFleetConnectivityJobFinishedEvent : NMAFleetConnectivityEvent
	[BaseType(typeof(NMAFleetConnectivityEvent))]
	interface NMAFleetConnectivityJobFinishedEvent
	{
	}

	// @interface NMAFleetConnectivityJobMessage : NMAFleetConnectivityMessage
	[BaseType(typeof(NMAFleetConnectivityMessage))]
	interface NMAFleetConnectivityJobMessage
	{
		// @property (readonly, nonatomic) NSUInteger etaThreshold;
		[Export("etaThreshold")]
		nuint EtaThreshold { get; }
	}

	// @interface NMAFleetConnectivityJobRejectedEvent : NMAFleetConnectivityEvent
	[BaseType(typeof(NMAFleetConnectivityEvent))]
	interface NMAFleetConnectivityJobRejectedEvent
	{
		// @property (readwrite, nonatomic) NSString * _Nullable jobId;
		[NullAllowed, Export("jobId")]
		string JobId { get; set; }
	}

	// @interface NMAFleetConnectivityJobStartedEvent : NMAFleetConnectivityEvent
	[BaseType(typeof(NMAFleetConnectivityEvent))]
	interface NMAFleetConnectivityJobStartedEvent
	{
		// @property (readwrite, nonatomic) NSString * _Nullable jobId;
		[NullAllowed, Export("jobId")]
		string JobId { get; set; }

		// @property (readwrite, nonatomic) NSUInteger etaThreshold;
		[Export("etaThreshold")]
		nuint EtaThreshold { get; set; }
	}

	// @protocol NMAFleetConnectivityServiceDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAFleetConnectivityServiceDelegate
	{
		// @required -(void)fleetConnectivityMessageReceived:(NMAFleetConnectivityMessage * _Nonnull)message;
		[Abstract]
		[Export("fleetConnectivityMessageReceived:")]
		void FleetConnectivityMessageReceived(NMAFleetConnectivityMessage message);

		// @required -(void)fleetConnectivityEventAcknowledged:(NMAFleetConnectivityEvent * _Nonnull)event error:(NMAFleetConnectivityError * _Nullable)error;
		[Abstract]
		[Export("fleetConnectivityEventAcknowledged:error:")]
		void FleetConnectivityEventAcknowledged(NMAFleetConnectivityEvent @event, [NullAllowed] NMAFleetConnectivityError error);
	}

	// @interface NMAFleetConnectivityService : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAFleetConnectivityService
	{
		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMAFleetConnectivityServiceDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMAFleetConnectivityServiceDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// @property (nonatomic) NSString * _Nonnull assetId;
		[Export("assetId")]
		string AssetId { get; set; }

		// @property (nonatomic) NSString * _Nonnull dispatcherId;
		[Export("dispatcherId")]
		string DispatcherId { get; set; }

		// @property (nonatomic) NSUInteger pollingInterval;
		[Export("pollingInterval")]
		nuint PollingInterval { get; set; }

		// +(NMAFleetConnectivityService * _Nullable)sharedFleetConnectivityService;
		[Static]
		[NullAllowed, Export("sharedFleetConnectivityService")]
		//[Verify(MethodToProperty)]
		NMAFleetConnectivityService SharedFleetConnectivityService { get; }

		// -(BOOL)start;
		[Export("start")]
		//[Verify(MethodToProperty)]
		bool Start { get; }

		// -(BOOL)stop;
		[Export("stop")]
		//[Verify(MethodToProperty)]
		bool Stop { get; }

		// -(BOOL)forcePoll;
		[Export("forcePoll")]
		//[Verify(MethodToProperty)]
		bool ForcePoll { get; }

		// -(BOOL)sendEvent:(NMAFleetConnectivityEvent * _Nonnull)event;
		[Export("sendEvent:")]
		bool SendEvent(NMAFleetConnectivityEvent @event);

		// -(NSString * _Nullable)runningJobId;
		[NullAllowed, Export("runningJobId")]
		//[Verify(MethodToProperty)]
		string RunningJobId { get; }
	}

	/*
	// @interface NMAFTCRManeuver : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAFTCRManeuver
	{
		// @property (readonly, nonatomic, strong) NMAGeoCoordinates * _Nullable position;
		[NullAllowed, Export("position", ArgumentSemantic.Strong)]
		NMAGeoCoordinates Position { get; }

		// @property (readonly, nonatomic, strong) NSString * _Nullable instruction;
		[NullAllowed, Export("instruction", ArgumentSemantic.Strong)]
		string Instruction { get; }

		// @property (readonly, assign, nonatomic) NSUInteger travelTime;
		[Export("travelTime")]
		nuint TravelTime { get; }

		// @property (readonly, assign, nonatomic) NSUInteger length;
		[Export("length")]
		nuint Length { get; }
	}

	// @protocol NMAFTCRNavigationManagerDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAFTCRNavigationManagerDelegate
	{
		// @optional -(void)navigationManager:(NMAFTCRNavigationManager * _Nonnull)navigationManager hasCurrentManeuver:(NMAFTCRManeuver * _Nullable)maneuver nextManeuver:(NMAFTCRManeuver * _Nullable)nextManeuver;
		[Export("navigationManager:hasCurrentManeuver:nextManeuver:")]
		void NavigationManager(NMAFTCRNavigationManager navigationManager, [NullAllowed] NMAFTCRManeuver maneuver, [NullAllowed] NMAFTCRManeuver nextManeuver);

		// @optional -(void)navigationManagerDidReachDestination:(NMAFTCRNavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerDidReachDestination:")]
		void NavigationManagerDidReachDestination(NMAFTCRNavigationManager navigationManager);

		// @optional -(void)navigationManager:(NMAFTCRNavigationManager * _Nonnull)navigationManager didReachStopover:(NSInteger)stopoverIndex;
		[Export("navigationManager:didReachStopover:")]
		void NavigationManager(NMAFTCRNavigationManager navigationManager, nint stopoverIndex);

		// @optional -(void)navigationManagerWillReroute:(NMAFTCRNavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerWillReroute:")]
		void NavigationManagerWillReroute(NMAFTCRNavigationManager navigationManager);

		// @optional -(void)navigationManager:(NMAFTCRNavigationManager * _Nonnull)navigationManager didRerouteWithRoute:(NMAFTCRRoute * _Nullable)reroute error:(NSError * _Nullable)error;
		[Export("navigationManager:didRerouteWithRoute:error:")]
		void NavigationManager(NMAFTCRNavigationManager navigationManager, [NullAllowed] NMAFTCRRoute reroute, [NullAllowed] NSError error);
	}

	// @interface NMAFTCRNavigationManager : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAFTCRNavigationManager
	{
		// +(instancetype _Nonnull)sharedNavigationManager;
		[Static]
		[Export("sharedNavigationManager")]
		NMAFTCRNavigationManager SharedNavigationManager();

		// @property (nonatomic, weak) NMAMapView * _Nullable map;
		[NullAllowed, Export("map", ArgumentSemantic.Weak)]
		NMAMapView Map { get; set; }

		// @property (nonatomic) NMAFTCRTrackingTilt mapTrackingTilt;
		[Export("mapTrackingTilt", ArgumentSemantic.Assign)]
		NMAFTCRTrackingTilt MapTrackingTilt { get; set; }

		// @property (nonatomic) NMAFTCRTrackingMode mapTrackingMode;
		[Export("mapTrackingMode", ArgumentSemantic.Assign)]
		NMAFTCRTrackingMode MapTrackingMode { get; set; }

		// @property (readonly, nonatomic) NMAFTCRManeuver * _Nullable currentManeuver;
		[NullAllowed, Export("currentManeuver")]
		NMAFTCRManeuver CurrentManeuver { get; }

		// @property (readonly, nonatomic) NMAFTCRManeuver * _Nullable nextManeuver;
		[NullAllowed, Export("nextManeuver")]
		NMAFTCRManeuver NextManeuver { get; }

		// @property (readonly, nonatomic) NSUInteger distanceToCurrentManeuver;
		[Export("distanceToCurrentManeuver")]
		nuint DistanceToCurrentManeuver { get; }

		// @property (readonly, nonatomic) NSUInteger distanceToNextManeuver;
		[Export("distanceToNextManeuver")]
		nuint DistanceToNextManeuver { get; }

		// @property (readonly, nonatomic) NSUInteger distanceToDestination;
		[Export("distanceToDestination")]
		nuint DistanceToDestination { get; }

		// @property (readonly, nonatomic) NSUInteger distanceFromStart;
		[Export("distanceFromStart")]
		nuint DistanceFromStart { get; }

		// @property (readonly, nonatomic) NSInteger averageSpeed;
		[Export("averageSpeed")]
		nint AverageSpeed { get; }

		// @property (readonly, nonatomic) NSTimeInterval timeToArrival;
		[Export("timeToArrival")]
		double TimeToArrival { get; }

		// @property (readonly, nonatomic) NMAGeoPosition * _Nullable routePosition;
		[NullAllowed, Export("routePosition")]
		NMAGeoPosition RoutePosition { get; }

		// -(void)addListener:(id<NMAFTCRNavigationManagerDelegate> _Nonnull)listener;
		[Export("addListener:")]
		void AddListener(NMAFTCRNavigationManagerDelegate listener);

		// -(void)removeListener:(id<NMAFTCRNavigationManagerDelegate> _Nonnull)listener;
		[Export("removeListener:")]
		void RemoveListener(NMAFTCRNavigationManagerDelegate listener);

		// -(void)startWithRoute:(NMAFTCRRoute * _Nonnull)route;
		[Export("startWithRoute:")]
		void StartWithRoute(NMAFTCRRoute route);

		// -(void)stop;
		[Export("stop")]
		void Stop();

		// -(NSUInteger)remainingDistanceToSubleg:(NSUInteger)subleg;
		[Export("remainingDistanceToSubleg:")]
		nuint RemainingDistanceToSubleg(nuint subleg);

		// -(NSTimeInterval)timeToArrivalForSubleg:(NSUInteger)subleg;
		[Export("timeToArrivalForSubleg:")]
		double TimeToArrivalForSubleg(nuint subleg);
	}
	*/

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const CGFloat NMAUnknownWaypointCourse;
		[Field("NMAUnknownWaypointCourse", "__Internal")]
		nfloat NMAUnknownWaypointCourse { get; }
	}

	// @interface NMAWaypoint : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAWaypoint
	{
		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)position;
		[Export("initWithGeoCoordinates:")]
		IntPtr Constructor(NMAGeoCoordinates position);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)position waypointType:(NMAWaypointType)type;
		[Export("initWithGeoCoordinates:waypointType:")]
		IntPtr Constructor(NMAGeoCoordinates position, NMAWaypointType type);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)position identifier:(NSString * _Nonnull)uniqueId waypointDirection:(NMAWaypointDirection)direction waypointType:(NMAWaypointType)type;
		[Export("initWithGeoCoordinates:identifier:waypointDirection:waypointType:")]
		IntPtr Constructor(NMAGeoCoordinates position, string uniqueId, NMAWaypointDirection direction, NMAWaypointType type);

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull originalPosition;
		[Export("originalPosition", ArgumentSemantic.Assign)]
		NMAGeoCoordinates OriginalPosition { get; set; }

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull navigablePosition;
		[Export("navigablePosition", ArgumentSemantic.Assign)]
		NMAGeoCoordinates NavigablePosition { get; set; }

		// @property (readonly, nonatomic) NSString * _Nonnull identifier;
		[Export("identifier")]
		string Identifier { get; }

		// @property (readonly, nonatomic) NMAWaypointDirection waypointDirection;
		[Export("waypointDirection")]
		NMAWaypointDirection WaypointDirection { get; }

		// -(void)setIdentifier:(NSString * _Nonnull)identifier waypointDirection:(NMAWaypointDirection)direction;
		[Export("setIdentifier:waypointDirection:")]
		void SetIdentifier(string identifier, NMAWaypointDirection direction);

		// @property (nonatomic) CGFloat course;
		[Export("course")]
		nfloat Course { get; set; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable mappedPosition;
		[NullAllowed, Export("mappedPosition")]
		NMAGeoCoordinates MappedPosition { get; }

		// @property (readonly, nonatomic) NMAWaypointRoadInfo * _Nullable roadInfo;
		[NullAllowed, Export("roadInfo")]
		NMAWaypointRoadInfo RoadInfo { get; }

		// @property (nonatomic) NMAWaypointType waypointType;
		[Export("waypointType", ArgumentSemantic.Assign)]
		NMAWaypointType WaypointType { get; set; }

		// @property (nonatomic) NSInteger waitingTime;
		[Export("waitingTime")]
		nint WaitingTime { get; set; }

		// @property (nonatomic) NSInteger fuzzyMatchingRadius;
		[Export("fuzzyMatchingRadius")]
		nint FuzzyMatchingRadius { get; set; }

		// @property (nonatomic) NSInteger junctionSnappingRadius;
		[Export("junctionSnappingRadius")]
		nint JunctionSnappingRadius { get; set; }

		// @property (nonatomic) NSInteger selectiveMatchingRadius;
		[Export("selectiveMatchingRadius")]
		nint SelectiveMatchingRadius { get; set; }

		// -(void)setStreetNameHint:(NSString * _Nonnull)hint;
		[Export("setStreetNameHint:")]
		void SetStreetNameHint(string hint);
	}

	/*
	// @interface NMAFTCRRequestParameters : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAFTCRRequestParameters
	{
		// -(instancetype _Nonnull)initWithWaypoints:(NSArray<NMAWaypoint *> * _Nonnull)waypoints mode:(NMARoutingMode * _Nonnull)mode overlay:(NSString * _Nonnull)overlay;
		[Export("initWithWaypoints:mode:overlay:")]
		IntPtr Constructor(NMAWaypoint[] waypoints, NMARoutingMode mode, string overlay);

		// @property (copy, nonatomic) NSString * _Nonnull overlay;
		[Export("overlay")]
		string Overlay { get; set; }

		// @property (nonatomic, strong) NSArray<NMAWaypoint *> * _Nonnull waypoints;
		[Export("waypoints", ArgumentSemantic.Strong)]
		NMAWaypoint[] Waypoints { get; set; }

		// @property (nonatomic, strong) NMARoutingMode * _Nonnull mode;
		[Export("mode", ArgumentSemantic.Strong)]
		NMARoutingMode Mode { get; set; }

		// @property (nonatomic) BOOL trafficEnabled;
		[Export("trafficEnabled")]
		bool TrafficEnabled { get; set; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const NSInteger NMAFTCRRouteSublegWhole;
		[Field("NMAFTCRRouteSublegWhole", "__Internal")]
		nint NMAFTCRRouteSublegWhole { get; }
	}

	// @interface NMAFTCRRoute : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAFTCRRoute
	{
		// @property (readonly, nonatomic, strong) NMAGeoBoundingBox * _Nullable boundingBox;
		[NullAllowed, Export("boundingBox", ArgumentSemantic.Strong)]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAGeoCoordinates *> * _Nullable geometry;
		[NullAllowed, Export("geometry", ArgumentSemantic.Strong)]
		NMAGeoCoordinates[] Geometry { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAFTCRManeuver *> * _Nullable maneuvers;
		[NullAllowed, Export("maneuvers", ArgumentSemantic.Strong)]
		NMAFTCRManeuver[] Maneuvers { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAFTCRRouteLink *> * _Nullable routeLinks;
		[NullAllowed, Export("routeLinks", ArgumentSemantic.Strong)]
		NMAFTCRRouteLink[] RouteLinks { get; }

		// @property (readonly, nonatomic) NSUInteger length;
		[Export("length")]
		nuint Length { get; }

		// @property (readonly, nonatomic) NSUInteger baseTime;
		[Export("baseTime")]
		nuint BaseTime { get; }

		// @property (readonly, nonatomic) NSUInteger travelTime;
		[Export("travelTime")]
		nuint TravelTime { get; }

		// @property (readonly, nonatomic) NSUInteger trafficTime;
		[Export("trafficTime")]
		nuint TrafficTime { get; }
	}

	// @interface NMAFTCRRouteLink : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAFTCRRouteLink
	{
		// @property (readonly, nonatomic, strong) NSArray<NMAGeoCoordinates *> * _Nullable geometry;
		[NullAllowed, Export("geometry", ArgumentSemantic.Strong)]
		NMAGeoCoordinates[] Geometry { get; }

		// @property (readonly, assign, nonatomic) NSUInteger length;
		[Export("length")]
		nuint Length { get; }

		// @property (readonly, assign, nonatomic) NSInteger remainDistance;
		[Export("remainDistance")]
		nint RemainDistance { get; }

		// @property (readonly, assign, nonatomic) NSUInteger remainTime;
		[Export("remainTime")]
		nuint RemainTime { get; }
	}

	// @interface NMAFTCRRoutePositionSource : NSObject <NMAPositionDataSource>
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAFTCRRoutePositionSource : NMAPositionDataSource
	{
		// -(instancetype _Nonnull)initWithRoute:(NMAFTCRRoute * _Nonnull)route movementSpeed:(double)speed;
		[Export("initWithRoute:movementSpeed:")]
		IntPtr Constructor(NMAFTCRRoute route, double speed);

		// @property (nonatomic) NSTimeInterval updatesInterval;
		[Export("updatesInterval")]
		double UpdatesInterval { get; set; }
	}

	// typedef void (^NMAFTCRRouterResultBlock)(NSArray<NMAFTCRRoute *> * _Nullable, NSError * _Nullable);
	delegate void NMAFTCRRouterResultBlock([NullAllowed] NMAFTCRRoute[] arg0, [NullAllowed] NSError arg1);

	// @interface NMAFTCRRouter : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAFTCRRouter
	{
		// +(instancetype _Nonnull)new;
		[Static]
		[Export("new")]
		NMAFTCRRouter New();

		// -(NSInteger)calculateRouteWithParameters:(NMAFTCRRequestParameters * _Nonnull)parameters completionBlock:(NMAFTCRRouterResultBlock _Nonnull)completion;
		[Export("calculateRouteWithParameters:completionBlock:")]
		nint CalculateRouteWithParameters(NMAFTCRRequestParameters parameters, NMAFTCRRouterResultBlock completion);

		// -(void)cancel:(NSInteger)taskId;
		[Export("cancel:")]
		void Cancel(nint taskId);
	}
	*/

	// @interface NMAIsoline : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAIsoline
	{
		// @property (readonly, nonatomic) NSArray<NMAGeoPolygon *> * _Nonnull components;
		[Export("components")]
		NMAGeoPolygon[] Components { get; }

		// @property (readonly, nonatomic) NSArray<NMAIsolineComponentConnection *> * _Nonnull componentConnections;
		[Export("componentConnections")]
		NMAIsolineComponentConnection[] ComponentConnections { get; }
	}

	// @interface NMAIsolineComponentConnection : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAIsolineComponentConnection
	{
		// @property (nonatomic) NSUInteger from;
		[Export("from")]
		nuint From { get; set; }

		// @property (nonatomic) NSUInteger to;
		[Export("to")]
		nuint To { get; set; }

		// @property (readonly, nonatomic) NMAGeoPolyline * _Nonnull shape;
		[Export("shape")]
		NMAGeoPolyline Shape { get; }
	}

	// @interface NMAIsolineOptions : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAIsolineOptions
	{
		// @property (nonatomic) NMAIsolineQuality quality;
		[Export("quality", ArgumentSemantic.Assign)]
		NMAIsolineQuality Quality { get; set; }

		// @property (nonatomic) NSUInteger viewResolution;
		[Export("viewResolution")]
		nuint ViewResolution { get; set; }

		// @property (nonatomic) BOOL computeSingleComponent;
		[Export("computeSingleComponent")]
		bool ComputeSingleComponent { get; set; }
	}

	// typedef void (^NMAIsolineCalculateResultBlock)(NSArray<NMAIsoline *> * _Nullable, NMAIsolineError);
	delegate void NMAIsolineCalculateResultBlock([NullAllowed] NMAIsoline[] arg0, NMAIsolineError arg1);

	// @interface NMAIsolineRouter : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAIsolineRouter
	{
		// @property (nonatomic) NMAIsolineRouterConnectivity connectivity;
		[Export("connectivity", ArgumentSemantic.Assign)]
		NMAIsolineRouterConnectivity Connectivity { get; set; }

		// -(BOOL)calculateFrom:(NMAGeoCoordinates * _Nonnull)point routingMode:(NMARoutingMode * _Nonnull)mode isolineOptions:(NMAIsolineOptions * _Nonnull)options rangeType:(NMAIsolineRangeType)type ranges:(NSArray * _Nonnull)ranges completionBlock:(NMAIsolineCalculateResultBlock _Nullable)completion;
		[Export("calculateFrom:routingMode:isolineOptions:rangeType:ranges:completionBlock:")]
		//[Verify(StronglyTypedNSArray)]
		bool CalculateFrom(NMAGeoCoordinates point, NMARoutingMode mode, NMAIsolineOptions options, NMAIsolineRangeType type, NSObject[] ranges, [NullAllowed] NMAIsolineCalculateResultBlock completion);

		// -(BOOL)calculateTo:(NMAGeoCoordinates * _Nonnull)destination routingMode:(NMARoutingMode * _Nonnull)mode isolineOptions:(NMAIsolineOptions * _Nonnull)options rangeType:(NMAIsolineRangeType)type ranges:(NSArray * _Nonnull)ranges completionBlock:(NMAIsolineCalculateResultBlock _Nullable)completion;
		[Export("calculateTo:routingMode:isolineOptions:rangeType:ranges:completionBlock:")]
		//[Verify(StronglyTypedNSArray)]
		bool CalculateTo(NMAGeoCoordinates destination, NMARoutingMode mode, NMAIsolineOptions options, NMAIsolineRangeType type, NSObject[] ranges, [NullAllowed] NMAIsolineCalculateResultBlock completion);

		// @property (getter = isBusy, nonatomic) BOOL busy;
		[Export("busy")]
		bool Busy { [Bind("isBusy")] get; set; }

		// -(BOOL)cancel;
		[Export("cancel")]
		//[Verify(MethodToProperty)]
		bool Cancel { get; }
	}

	// @interface NMAZoomRange : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAZoomRange
	{
		// @property (nonatomic) float min;
		[Export("min")]
		float Min { get; set; }

		// @property (nonatomic) float max;
		[Export("max")]
		float Max { get; set; }

		// -(instancetype _Nonnull)initWithMinZoomLevel:(float)minimum maxZoomLevel:(float)maximum;
		[Export("initWithMinZoomLevel:maxZoomLevel:")]
		IntPtr Constructor(float minimum, float maximum);
	}

	// @interface NMACustomizableVariable : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMACustomizableVariable : ObjCRuntime.INativeObject
	{
		// @property (nonatomic, strong) NSString * _Nonnull variableName;
		[Export("variableName", ArgumentSemantic.Strong)]
		string VariableName { get; set; }

		// @property (readonly, nonatomic) NMACustomizablePropertyType propertyType;
		[Export("propertyType")]
		NMACustomizablePropertyType PropertyType { get; }

		// @property (readonly, nonatomic) NSInteger propertyIdentifier;
		[Export("propertyIdentifier")]
		nint PropertyIdentifier { get; }

		// +(NSDictionary<NSString *,NMACustomizableVariable *> * _Nonnull)allAvailableProperties;
		[Static]
		[Export("allAvailableProperties")]
		//[Verify(MethodToProperty)]
		NSDictionary<NSString, NMACustomizableVariable> AllAvailableProperties { get; }
	}

	// @interface NMACustomizableColor : NMACustomizableVariable
	[BaseType(typeof(NMACustomizableVariable))]
	[DisableDefaultCtor]
	interface NMACustomizableColor
	{
		// -(instancetype _Nonnull)initWithColorProperty:(NMASchemeColorProperty)property andZoomLevel:(float)zoomLevel andZoomRange:(NMAZoomRange * _Nullable)zoomRange;
		[Export("initWithColorProperty:andZoomLevel:andZoomRange:")]
		IntPtr Constructor(NMASchemeColorProperty property, float zoomLevel, [NullAllowed] NMAZoomRange zoomRange);

		// @property (nonatomic) NSInteger red;
		[Export("red")]
		nint Red { get; set; }

		// @property (nonatomic) NSInteger green;
		[Export("green")]
		nint Green { get; set; }

		// @property (nonatomic) NSInteger blue;
		[Export("blue")]
		nint Blue { get; set; }

		// @property (nonatomic) NSInteger alpha;
		[Export("alpha")]
		nint Alpha { get; set; }

		// -(UIColor * _Nonnull)color;
		// -(void)setColor:(UIColor * _Nonnull)color;
		[Export("color")]
		//[Verify(MethodToProperty)]
		UIColor Color { get; set; }
	}

	// @interface NMACustomizableScheme : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMACustomizableScheme
	{
		// -(NMACustomizableColor * _Nullable)colorForProperty:(NMASchemeColorProperty)colorProperty forZoomLevel:(float)zoomLevel;
		[Export("colorForProperty:forZoomLevel:")]
		[return: NullAllowed]
		NMACustomizableColor ColorForProperty(NMASchemeColorProperty colorProperty, float zoomLevel);

		// -(void)setColorProperty:(NMACustomizableColor * _Nonnull)variableColor forZoomRange:(NMAZoomRange * _Nonnull)zoomRange;
		[Export("setColorProperty:forZoomRange:")]
		void SetColorProperty(NMACustomizableColor variableColor, NMAZoomRange zoomRange);

		// -(int)integerForProperty:(NMASchemeIntegerProperty)integerProperty forZoomLevel:(float)zoomLevel;
		[Export("integerForProperty:forZoomLevel:")]
		int IntegerForProperty(NMASchemeIntegerProperty integerProperty, float zoomLevel);

		// -(void)setIntegerProperty:(NMASchemeIntegerProperty)integerProperty withValue:(int)value forZoomRange:(NMAZoomRange * _Nonnull)zoomRange;
		[Export("setIntegerProperty:withValue:forZoomRange:")]
		void SetIntegerProperty(NMASchemeIntegerProperty integerProperty, int value, NMAZoomRange zoomRange);

		// -(BOOL)booleanForProperty:(NMASchemeBooleanProperty)booleanProperty forZoomLevel:(float)zoomLevel;
		[Export("booleanForProperty:forZoomLevel:")]
		bool BooleanForProperty(NMASchemeBooleanProperty booleanProperty, float zoomLevel);

		// -(void)setBooleanProperty:(NMASchemeBooleanProperty)booleanProperty withValue:(BOOL)value forZoomRange:(NMAZoomRange * _Nonnull)zoomRange;
		[Export("setBooleanProperty:withValue:forZoomRange:")]
		void SetBooleanProperty(NMASchemeBooleanProperty booleanProperty, bool value, NMAZoomRange zoomRange);

		// -(float)floatForProperty:(NMASchemeFloatProperty)floatProperty forZoomLevel:(float)zoomLevel;
		[Export("floatForProperty:forZoomLevel:")]
		float FloatForProperty(NMASchemeFloatProperty floatProperty, float zoomLevel);

		// -(void)setFloatProperty:(NMASchemeFloatProperty)floatProperty withValue:(float)value forZoomRange:(NMAZoomRange * _Nonnull)zoomRange;
		[Export("setFloatProperty:withValue:forZoomRange:")]
		void SetFloatProperty(NMASchemeFloatProperty floatProperty, float value, NMAZoomRange zoomRange);

		// -(NSString * _Nonnull)name;
		[Export("name")]
		//[Verify(MethodToProperty)]
		string Name { get; }
	}

	// @interface NMALight : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMALight
	{
	}

	// @interface NMADirectionalLight : NMALight
	[BaseType(typeof(NMALight))]
	interface NMADirectionalLight
	{
		// +(instancetype _Nonnull)lightWithDirection:(NMAVector3d)direction;
		[Static]
		[Export("lightWithDirection:")]
		NMADirectionalLight LightWithDirection(NMAVector3d direction);

		// -(instancetype _Nonnull)initWithDirection:(NMAVector3d)direction __attribute__((objc_designated_initializer));
		[Export("initWithDirection:")]
		[DesignatedInitializer]
		IntPtr Constructor(NMAVector3d direction);

		// @property (nonatomic) NMAVector3d direction;
		[Export("direction", ArgumentSemantic.Assign)]
		NMAVector3d Direction { get; set; }
	}

	// @protocol NMAMapTileLayerDataSource <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAMapTileLayerDataSource
	{
		// @optional -(BOOL)mapTileLayer:(NMAMapTileLayer * _Nonnull)mapTileLayer hasTileAtX:(NSUInteger)x y:(NSUInteger)y zoomLevel:(NSUInteger)zoomLevel;
		[Export("mapTileLayer:hasTileAtX:y:zoomLevel:")]
		bool MapTileLayerHasTileAt(NMAMapTileLayer mapTileLayer, nuint x, nuint y, nuint zoomLevel);

		// @optional -(NSString * _Nonnull)mapTileLayer:(NMAMapTileLayer * _Nonnull)mapTileLayer urlForTileAtX:(NSUInteger)x y:(NSUInteger)y zoomLevel:(NSUInteger)zoomLevel;
		[Export("mapTileLayer:urlForTileAtX:y:zoomLevel:")]
		string MapTileLayerUrlForTileAt(NMAMapTileLayer mapTileLayer, nuint x, nuint y, nuint zoomLevel);

		// @optional -(void)mapTileLayer:(NMAMapTileLayer * _Nonnull)mapTileLayer requestDataForTileAtX:(NSUInteger)x y:(NSUInteger)y zoomLevel:(NSUInteger)zoomLevel tileRequest:(NMAMapTileRequest * _Nonnull)tileRequest;
		[Export("mapTileLayer:requestDataForTileAtX:y:zoomLevel:tileRequest:")]
		void MapTileLayerRequestDataForTileAt(NMAMapTileLayer mapTileLayer, nuint x, nuint y, nuint zoomLevel, NMAMapTileRequest tileRequest);

		// @optional -(NSData * _Nonnull)mapTileLayer:(NMAMapTileLayer * _Nonnull)mapTileLayer requestDataForTileAtX:(NSUInteger)x y:(NSUInteger)y zoomLevel:(NSUInteger)zoomLevel;
		[Export("mapTileLayer:requestDataForTileAtX:y:zoomLevel:")]
		NSData MapTileLayerRequestDataForTileAt(NMAMapTileLayer mapTileLayer, nuint x, nuint y, nuint zoomLevel);
	}

	// @interface NMAMapTileLayer : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAMapTileLayer
	{
		// @property (nonatomic, weak) id<NMAMapTileLayerDataSource> _Nullable dataSource;
		[NullAllowed, Export("dataSource", ArgumentSemantic.Weak)]
		NMAMapTileLayerDataSource DataSource { get; set; }

		// @property (readonly, getter = isLocked, nonatomic) BOOL locked;
		[Export("locked")]
		bool Locked { [Bind("isLocked")] get; }

		// @property (nonatomic) NMAMapLayerType mapLayerType;
		[Export("mapLayerType", ArgumentSemantic.Assign)]
		NMAMapLayerType MapLayerType { get; set; }

		// @property (nonatomic) NSUInteger zIndex;
		[Export("zIndex")]
		nuint ZIndex { get; set; }

		// @property (nonatomic) NMAPixelFormat pixelFormat;
		[Export("pixelFormat", ArgumentSemantic.Assign)]
		NMAPixelFormat PixelFormat { get; set; }

		// @property (nonatomic) NSUInteger tileSize;
		[Export("tileSize")]
		nuint TileSize { get; set; }

		// @property (getter = isTransparent, nonatomic) BOOL transparent;
		[Export("transparent")]
		bool Transparent { [Bind("isTransparent")] get; set; }

		// @property (getter = isFallbackEnabled, nonatomic) BOOL fallbackEnabled;
		[Export("fallbackEnabled")]
		bool FallbackEnabled { [Bind("isFallbackEnabled")] get; set; }

		// @property (getter = isFadingEnabled, nonatomic) BOOL fadingEnabled;
		[Export("fadingEnabled")]
		bool FadingEnabled { [Bind("isFadingEnabled")] get; set; }

		// @property (nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export("boundingBox", ArgumentSemantic.Assign)]
		NMAGeoBoundingBox BoundingBox { get; set; }

		// @property (readonly, getter = isCacheEnabled, nonatomic) BOOL cacheEnabled;
		[Export("cacheEnabled")]
		bool CacheEnabled { [Bind("isCacheEnabled")] get; }

		// @property (readonly, nonatomic) NSString * _Nonnull cacheIdentifier;
		[Export("cacheIdentifier")]
		string CacheIdentifier { get; }

		// @property (nonatomic) NSTimeInterval cacheTimeToLive;
		[Export("cacheTimeToLive")]
		double CacheTimeToLive { get; set; }

		// @property (nonatomic) NSUInteger cacheSizeLimit;
		[Export("cacheSizeLimit")]
		nuint CacheSizeLimit { get; set; }

		// -(void)setCacheEnabled:(BOOL)cacheEnabled withIdentifier:(NSString * _Nonnull)cacheIdentifier;
		[Export("setCacheEnabled:withIdentifier:")]
		void SetCacheEnabled(bool cacheEnabled, string cacheIdentifier);

		// -(void)clearCache;
		[Export("clearCache")]
		void ClearCache();

		// -(void)showAtZoomLevel:(int)zoomLevel;
		[Export("showAtZoomLevel:")]
		void ShowAtZoomLevel(int zoomLevel);

		// -(void)hideAtZoomLevel:(int)zoomLevel;
		[Export("hideAtZoomLevel:")]
		void HideAtZoomLevel(int zoomLevel);

		// -(void)showFromZoomLevel:(int)fromLevel toZoomLevel:(int)toLevel;
		[Export("showFromZoomLevel:toZoomLevel:")]
		void ShowFromZoomLevel(int fromLevel, int toLevel);

		// -(void)hideFromZoomLevel:(int)fromLevel toZoomLevel:(int)toLevel;
		[Export("hideFromZoomLevel:toZoomLevel:")]
		void HideFromZoomLevel(int fromLevel, int toLevel);

		// -(BOOL)isShownAtZoomLevel:(int)zoomLevel;
		[Export("isShownAtZoomLevel:")]
		bool IsShownAtZoomLevel(int zoomLevel);
	}

	// @interface NMAHistoricalTrafficTileLayer : NMAMapTileLayer <NMAMapTileLayerDataSource>
	[BaseType(typeof(NMAMapTileLayer))]
	interface NMAHistoricalTrafficTileLayer : NMAMapTileLayerDataSource
	{
		// -(instancetype _Nullable)initForWeekDay:(NSInteger)weekDay hour:(NSInteger)hour minute:(NSInteger)minute __attribute__((objc_designated_initializer));
		[Export("initForWeekDay:hour:minute:")]
		[DesignatedInitializer]
		IntPtr Constructor(nint weekDay, nint hour, nint minute);
	}

	// @interface NMALocationInfo : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMALocationInfo
	{
		// -(BOOL)hasField:(NMALocationInfoField)field;
		[Export("hasField:")]
		bool HasField(NMALocationInfoField field);

		// -(NSString * _Nullable)valueForField:(NMALocationInfoField)field;
		[Export("valueForField:")]
		[return: NullAllowed]
		string ValueForField(NMALocationInfoField field);
	}

	// @interface NMAMapCircle : NMAMapObject
	[BaseType(typeof(NMAMapObject))]
	interface NMAMapCircle
	{
		// +(instancetype _Nonnull)mapCircleWithGeoCoordinates:(NMAGeoCoordinates * _Nullable)coordinates;
		[Static]
		[Export("mapCircleWithGeoCoordinates:")]
		NMAMapCircle MapCircleWithGeoCoordinates([NullAllowed] NMAGeoCoordinates coordinates);

		// +(instancetype _Nonnull)mapCircleWithGeoCoordinates:(NMAGeoCoordinates * _Nullable)coordinates radius:(double)radius;
		[Static]
		[Export("mapCircleWithGeoCoordinates:radius:")]
		NMAMapCircle MapCircleWithGeoCoordinates([NullAllowed] NMAGeoCoordinates coordinates, double radius);

		// @property (nonatomic, strong) NMAGeoCoordinates * _Nullable center;
		[NullAllowed, Export("center", ArgumentSemantic.Strong)]
		NMAGeoCoordinates Center { get; set; }

		// @property (nonatomic) double radius;
		[Export("radius")]
		double Radius { get; set; }

		// @property (nonatomic, strong) UIColor * _Nonnull lineColor;
		[Export("lineColor", ArgumentSemantic.Strong)]
		UIColor LineColor { get; set; }

		// @property (nonatomic, strong) UIColor * _Nonnull fillColor;
		[Export("fillColor", ArgumentSemantic.Strong)]
		UIColor FillColor { get; set; }

		// @property (nonatomic) NSUInteger lineWidth;
		[Export("lineWidth")]
		nuint LineWidth { get; set; }

		// @property (getter = isDashed, nonatomic) BOOL dashed;
		[Export("dashed")]
		bool Dashed { [Bind("isDashed")] get; set; }

		// @property (nonatomic) NSUInteger dashPrimaryLength;
		[Export("dashPrimaryLength")]
		nuint DashPrimaryLength { get; set; }

		// @property (nonatomic) NSUInteger dashSecondaryLength;
		[Export("dashSecondaryLength")]
		nuint DashSecondaryLength { get; set; }

		// @property (nonatomic) BOOL depthTestEnabled;
		[Export("depthTestEnabled")]
		bool DepthTestEnabled { get; set; }

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nullable)coordinates;
		[Export("initWithGeoCoordinates:")]
		IntPtr Constructor([NullAllowed] NMAGeoCoordinates coordinates);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nullable)coordinates radius:(double)radius __attribute__((objc_designated_initializer));
		[Export("initWithGeoCoordinates:radius:")]
		[DesignatedInitializer]
		IntPtr Constructor([NullAllowed] NMAGeoCoordinates coordinates, double radius);

		// @property (assign, nonatomic) NMAPatternStyle patternStyle;
		[Export("patternStyle", ArgumentSemantic.Assign)]
		NMAPatternStyle PatternStyle { get; set; }

		// @property (readwrite, nonatomic) NMAImage * _Nullable customPattern;
		[NullAllowed, Export("customPattern", ArgumentSemantic.Assign)]
		NMAImage CustomPattern { get; set; }
	}

	// @interface NMAMapContainer : NMAMapObject
	[BaseType(typeof(NMAMapObject))]
	interface NMAMapContainer
	{
		// @property (readonly, nonatomic, weak) NSArray<NMAMapObject *> * _Nullable mapObjects;
		[NullAllowed, Export("mapObjects", ArgumentSemantic.Weak)]
		NMAMapObject[] MapObjects { get; }

		// -(BOOL)addMapObject:(NMAMapObject * _Nonnull)aMapObject;
		[Export("addMapObject:")]
		bool AddMapObject(NMAMapObject aMapObject);

		// -(BOOL)removeMapObject:(NMAMapObject * _Nonnull)aMapObject;
		[Export("removeMapObject:")]
		bool RemoveMapObject(NMAMapObject aMapObject);

		// -(BOOL)removeAllMapObjects;
		[Export("removeAllMapObjects")]
		//[Verify(MethodToProperty)]
		bool RemoveAllMapObjects { get; }
	}

	/*
	// @interface NMAMapFTCRRoute : NMAMapObject
	[BaseType(typeof(NMAMapObject))]
	[DisableDefaultCtor]
	interface NMAMapFTCRRoute
	{
		// -(instancetype _Nullable)initWithRoute:(NMAFTCRRoute * _Nonnull)route;
		[Export("initWithRoute:")]
		IntPtr Constructor(NMAFTCRRoute route);

		// @property (nonatomic, strong) UIColor * _Nonnull color;
		[Export("color", ArgumentSemantic.Strong)]
		UIColor Color { get; set; }
	}
	*/

	// @interface NMAMapModelObject : NMAMapObject
	[BaseType(typeof(NMAMapObject))]
	interface NMAMapModelObject
	{
		// @property (nonatomic, strong) NMAMaterial * _Nullable material;
		[NullAllowed, Export("material", ArgumentSemantic.Strong)]
		NMAMaterial Material { get; set; }

		// @property (readonly, nonatomic) NSArray<NMALight *> * _Nonnull lights;
		[Export("lights")]
		NMALight[] Lights { get; }

		// @property (readonly, nonatomic) NSUInteger maximumNumberOfLights;
		[Export("maximumNumberOfLights")]
		nuint MaximumNumberOfLights { get; }

		// -(void)setTexture:(NMAImage * _Nullable)texture;
		[Export("setTexture:")]
		void SetTexture([NullAllowed] NMAImage texture);

		// -(BOOL)addLight:(NMALight * _Nullable)light;
		[Export("addLight:")]
		bool AddLight([NullAllowed] NMALight light);

		// -(void)removeAllLights;
		[Export("removeAllLights")]
		void RemoveAllLights();
	}

	/*
	// @interface NMAMapGeoModel : NMAMapModelObject
	[BaseType(typeof(NMAMapModelObject))]
	interface NMAMapGeoModel
	{
		// -(instancetype _Nonnull)initWithMesh:(NMAGeoMesh * _Nonnull)mesh;
		[Export("initWithMesh:")]
		IntPtr Constructor(NMAGeoMesh mesh);
	}
	*/

	// @protocol NMAMapGestureDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAMapGestureDelegate
	{
		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveTapAtLocation:(CGPoint)location;
		[Export("mapView:didReceiveTapAtLocation:")]
		void DidReceiveTapAtLocation(NMAMapView mapView, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveDoubleTapAtLocation:(CGPoint)location;
		[Export("mapView:didReceiveDoubleTapAtLocation:")]
		void DidReceiveDoubleTapAtLocation(NMAMapView mapView, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveTwoFingerTapAtLocation:(CGPoint)location;
		[Export("mapView:didReceiveTwoFingerTapAtLocation:")]
		void DidReceiveTwoFingerTapAtLocation(NMAMapView mapView, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceivePan:(CGPoint)translation atLocation:(CGPoint)location;
		[Export("mapView:didReceivePan:atLocation:")]
		void DidReceivePan(NMAMapView mapView, CGPoint translation, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveTwoFingerPan:(CGPoint)translation atLocation:(CGPoint)location;
		[Export("mapView:didReceiveTwoFingerPan:atLocation:")]
		void DidReceiveTwoFingerPan(NMAMapView mapView, CGPoint translation, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveRotation:(float)rotation atLocation:(CGPoint)location;
		[Export("mapView:didReceiveRotation:atLocation:")]
		void DidReceiveRotation(NMAMapView mapView, float rotation, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceivePinch:(float)pinch atLocation:(CGPoint)location;
		[Export("mapView:didReceivePinch:atLocation:")]
		void DidReceivePinch(NMAMapView mapView, float pinch, CGPoint location);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didReceiveLongPressAtLocation:(CGPoint)location;
		[Export("mapView:didReceiveLongPressAtLocation:")]
		void DidReceiveLongPressAtLocation(NMAMapView mapView, CGPoint location);
	}

	// @interface NMAMapMarker : NMAMapObject
	[BaseType(typeof(NMAMapObject))]
	interface NMAMapMarker
	{
		// +(instancetype _Nonnull)mapMarkerWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Static]
		[Export("mapMarkerWithGeoCoordinates:")]
		NMAMapMarker MapMarkerWithGeoCoordinates(NMAGeoCoordinates coordinates);

		// +(instancetype _Nonnull)mapMarkerWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates icon:(NMAImage * _Nonnull)icon;
		[Static]
		[Export("mapMarkerWithGeoCoordinates:icon:")]
		NMAMapMarker MapMarkerWithGeoCoordinates(NMAGeoCoordinates coordinates, NMAImage icon);

		// +(instancetype _Nonnull)mapMarkerWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates image:(UIImage * _Nonnull)image;
		[Static]
		[Export("mapMarkerWithGeoCoordinates:image:")]
		NMAMapMarker MapMarkerWithGeoCoordinates(NMAGeoCoordinates coordinates, UIImage image);

		// @property (nonatomic, strong) NMAGeoCoordinates * _Nonnull coordinates;
		[Export("coordinates", ArgumentSemantic.Strong)]
		NMAGeoCoordinates Coordinates { get; set; }

		// @property (nonatomic, strong) NMAImage * _Nullable icon;
		[NullAllowed, Export("icon", ArgumentSemantic.Strong)]
		NMAImage Icon { get; set; }

		// @property (getter = isDraggable, nonatomic) BOOL draggable;
		[Export("draggable")]
		bool Draggable { [Bind("isDraggable")] get; set; }

		// @property (getter = isDraggingOffsetEnabled, nonatomic) BOOL draggingOffsetEnabled;
		[Export("draggingOffsetEnabled")]
		bool DraggingOffsetEnabled { [Bind("isDraggingOffsetEnabled")] get; set; }

		// @property (nonatomic) CGPoint anchorOffset;
		[Export("anchorOffset", ArgumentSemantic.Assign)]
		CGPoint AnchorOffset { get; set; }

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("initWithGeoCoordinates:")]
		IntPtr Constructor(NMAGeoCoordinates coordinates);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates icon:(NMAImage * _Nonnull)icon __attribute__((objc_designated_initializer));
		[Export("initWithGeoCoordinates:icon:")]
		[DesignatedInitializer]
		IntPtr Constructor(NMAGeoCoordinates coordinates, NMAImage icon);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates image:(UIImage * _Nonnull)image;
		[Export("initWithGeoCoordinates:image:")]
		IntPtr Constructor(NMAGeoCoordinates coordinates, UIImage image);

		// -(CGPoint)setAnchorOffsetUsingLayoutPosition:(NMALayoutPosition)position;
		[Export("setAnchorOffsetUsingLayoutPosition:")]
		CGPoint SetAnchorOffsetUsingLayoutPosition(NMALayoutPosition position);

		// -(void)setSize:(CGSize)size forZoomLevel:(NSUInteger)zoomLevel;
		[Export("setSize:forZoomLevel:")]
		void SetSize(CGSize size, nuint zoomLevel);

		// -(void)setSize:(CGSize)size forZoomRange:(NSRange)zoomRange;
		[Export("setSize:forZoomRange:")]
		void SetSize(CGSize size, NSRange zoomRange);

		// -(void)resetIconSize;
		[Export("resetIconSize")]
		void ResetIconSize();
	}

	// @interface NMAMapLabeledMarker : NMAMapMarker
	[BaseType(typeof(NMAMapMarker))]
	interface NMAMapLabeledMarker
	{
		// +(instancetype _Nonnull)mapLabeledMarkerWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Static]
		[Export("mapLabeledMarkerWithGeoCoordinates:")]
		NMAMapLabeledMarker MapLabeledMarkerWithGeoCoordinates(NMAGeoCoordinates coordinates);

		// +(instancetype _Nonnull)mapLabeledMarkerWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates icon:(NMAImage * _Nonnull)icon;
		[Static]
		[Export("mapLabeledMarkerWithGeoCoordinates:icon:")]
		NMAMapLabeledMarker MapLabeledMarkerWithGeoCoordinates(NMAGeoCoordinates coordinates, NMAImage icon);

		// +(instancetype _Nonnull)mapLabeledMarkerWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates image:(UIImage * _Nonnull)image;
		[Static]
		[Export("mapLabeledMarkerWithGeoCoordinates:image:")]
		NMAMapLabeledMarker MapLabeledMarkerWithGeoCoordinates(NMAGeoCoordinates coordinates, UIImage image);

		// -(BOOL)setText:(NSString * _Nullable)text forLanguage:(NSString * _Nullable)language;
		[Export("setText:forLanguage:")]
		bool SetText([NullAllowed] string text, [NullAllowed] string language);

		// -(NSString * _Nullable)textForLanguage:(NSString * _Nullable)language;
		[Export("textForLanguage:")]
		[return: NullAllowed]
		string TextForLanguage([NullAllowed] string language);
	}

	// @interface NMAMapPackage : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAMapPackage
	{
		// @property (readonly, nonatomic, weak) NMAMapPackage * _Nullable parent;
		[NullAllowed, Export("parent", ArgumentSemantic.Weak)]
		NMAMapPackage Parent { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAMapPackage *> * _Nonnull children;
		[Export("children", ArgumentSemantic.Strong)]
		NMAMapPackage[] Children { get; }

		// @property (readonly, nonatomic) NSInteger packageId;
		[Export("packageId")]
		nint PackageId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull title;
		[Export("title")]
		string Title { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull englishTitle;
		[Export("englishTitle")]
		string EnglishTitle { get; }

		// @property (readonly, nonatomic) long sizeOnDisk;
		[Export("sizeOnDisk")]
		nint SizeOnDisk { get; }

		// @property (readonly, nonatomic) NMAMapPackageInstallation installationStatus;
		[Export("installationStatus")]
		NMAMapPackageInstallation InstallationStatus { get; }
	}

	// @protocol NMAMapLoaderDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAMapLoaderDelegate
	{
		// @optional -(void)mapLoader:(NMAMapLoader * _Nonnull)mapLoader didUpdateProgress:(float)progress;
		[Export("mapLoader:didUpdateProgress:")]
		void MapLoaderDidUpdateProgress(NMAMapLoader mapLoader, float progress);

		// @optional -(void)mapLoader:(NMAMapLoader * _Nonnull)mapLoader didGetPackagesWithResult:(NMAMapLoaderResult)mapLoaderResult;
		[Export("mapLoader:didGetPackagesWithResult:")]
		void MapLoaderDidGetPackagesWithResult(NMAMapLoader mapLoader, NMAMapLoaderResult mapLoaderResult);

		// @optional -(void)mapLoader:(NMAMapLoader * _Nonnull)mapLoader didInstallPackagesWithResult:(NMAMapLoaderResult)mapLoaderResult;
		[Export("mapLoader:didInstallPackagesWithResult:")]
		void MapLoaderDidInstallPackagesWithResult(NMAMapLoader mapLoader, NMAMapLoaderResult mapLoaderResult);

		// @optional -(void)mapLoader:(NMAMapLoader * _Nonnull)mapLoader didUninstallPackagesWithResult:(NMAMapLoaderResult)mapLoaderResult;
		[Export("mapLoader:didUninstallPackagesWithResult:")]
		void MapLoaderDidUninstallPackagesWithResult(NMAMapLoader mapLoader, NMAMapLoaderResult mapLoaderResult);

		// @optional -(void)mapLoader:(NMAMapLoader * _Nonnull)mapLoader didFindUpdate:(BOOL)updateIsAvailable fromVersion:(NSString * _Nonnull)currentMapVersion toVersion:(NSString * _Nonnull)newestMapVersion withResult:(NMAMapLoaderResult)mapLoaderResult;
		[Export("mapLoader:didFindUpdate:fromVersion:toVersion:withResult:")]
		void MapLoaderDidFindUpdate(NMAMapLoader mapLoader, bool updateIsAvailable, string currentMapVersion, string newestMapVersion, NMAMapLoaderResult mapLoaderResult);

		// @optional -(void)mapLoader:(NMAMapLoader * _Nonnull)mapLoader didGetUpdateSize:(NSUInteger)size withResult:(NMAMapLoaderResult)mapLoaderResult;
		[Export("mapLoader:didGetUpdateSize:withResult:")]
		void MapLoaderDidGetUpdateSize(NMAMapLoader mapLoader, nuint size, NMAMapLoaderResult mapLoaderResult);

		// @optional -(void)mapLoader:(NMAMapLoader * _Nonnull)mapLoader didUpdateWithResult:(NMAMapLoaderResult)mapLoaderResult;
		[Export("mapLoader:didUpdateWithResult:")]
		void MapLoaderDidUpdateWithResult(NMAMapLoader mapLoader, NMAMapLoaderResult mapLoaderResult);

		// @optional -(void)mapLoader:(NMAMapLoader * _Nonnull)mapLoader didGetMapPackage:(NMAMapPackage * _Nullable)package atGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates withResult:(NMAMapLoaderResult)mapLoaderResult;
		[Export("mapLoader:didGetMapPackage:atGeoCoordinates:withResult:")]
		void MapLoaderDidGetMapPackage(NMAMapLoader mapLoader, [NullAllowed] NMAMapPackage package, NMAGeoCoordinates coordinates, NMAMapLoaderResult mapLoaderResult);

		// @optional -(void)mapLoaderDidLoseConnection:(NMAMapLoader * _Nonnull)mapLoader;
		[Export("mapLoaderDidLoseConnection:")]
		void MapLoaderDidLoseConnection(NMAMapLoader mapLoader);

		// @optional -(void)mapLoaderDidFindConnection:(NMAMapLoader * _Nonnull)mapLoader;
		[Export("mapLoaderDidFindConnection:")]
		void MapLoaderDidFindConnection(NMAMapLoader mapLoader);
	}

	// @interface NMAMapLoader : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAMapLoader
	{
		// +(NMAMapLoader * _Nonnull)sharedMapLoader;
		[Static]
		[Export("sharedMapLoader")]
		//[Verify(MethodToProperty)]
		NMAMapLoader SharedMapLoader { get; }

		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMAMapLoaderDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMAMapLoaderDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// @property (readonly, nonatomic) BOOL active;
		[Export("active")]
		bool Active { get; }

		// @property (readonly, atomic, strong) NMAMapPackage * _Nullable rootPackage;
		[NullAllowed, Export("rootPackage", ArgumentSemantic.Strong)]
		NMAMapPackage RootPackage { get; }

		// -(BOOL)getMapPackages;
		[Export("getMapPackages")]
		//[Verify(MethodToProperty)]
		bool MapPackages { get; }

		// -(BOOL)installMapPackages:(NSArray<NMAMapPackage *> * _Nonnull)mapPackages;
		[Export("installMapPackages:")]
		bool InstallMapPackages(NMAMapPackage[] mapPackages);

		// -(BOOL)uninstallMapPackages:(NSArray<NMAMapPackage *> * _Nonnull)theMapPackages;
		[Export("uninstallMapPackages:")]
		bool UninstallMapPackages(NMAMapPackage[] theMapPackages);

		// -(BOOL)checkForMapDataUpdate;
		[Export("checkForMapDataUpdate")]
		//[Verify(MethodToProperty)]
		bool CheckForMapDataUpdate { get; }

		// -(BOOL)getMapDataUpdateSize;
		[Export("getMapDataUpdateSize")]
		//[Verify(MethodToProperty)]
		bool MapDataUpdateSize { get; }

		// -(BOOL)performMapDataUpdate;
		[Export("performMapDataUpdate")]
		//[Verify(MethodToProperty)]
		bool PerformMapDataUpdate { get; }

		// -(BOOL)cancelCurrentOperation;
		[Export("cancelCurrentOperation")]
		//[Verify(MethodToProperty)]
		bool CancelCurrentOperation { get; }

		// -(BOOL)getMapPackageAtGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("getMapPackageAtGeoCoordinates:")]
		bool GetMapPackageAtGeoCoordinates(NMAGeoCoordinates coordinates);

		// -(void)selectDataGroup:(NMAMapDataGroup)dataGroup;
		[Export("selectDataGroup:")]
		void SelectDataGroup(NMAMapDataGroup dataGroup);

		// -(void)deselectDataGroup:(NMAMapDataGroup)dataGroup;
		[Export("deselectDataGroup:")]
		void DeselectDataGroup(NMAMapDataGroup dataGroup);

		// -(BOOL)isDataGroupSelected:(NMAMapDataGroup)dataGroup;
		[Export("isDataGroupSelected:")]
		bool IsDataGroupSelected(NMAMapDataGroup dataGroup);
	}

	/*
	// @interface NMAMapLocalModel : NMAMapModelObject
	[BaseType(typeof(NMAMapModelObject))]
	interface NMAMapLocalModel
	{
		// @property (nonatomic) NMAGeoCoordinates * _Nullable coordinates;
		[NullAllowed, Export("coordinates", ArgumentSemantic.Assign)]
		NMAGeoCoordinates Coordinates { get; set; }

		// @property (nonatomic) float pitch;
		[Export("pitch")]
		float Pitch { get; set; }

		// @property (nonatomic) float yaw;
		[Export("yaw")]
		float Yaw { get; set; }

		// @property (nonatomic) float roll;
		[Export("roll")]
		float Roll { get; set; }

		// @property (nonatomic) float scale;
		[Export("scale")]
		float Scale { get; set; }

		// @property (nonatomic) BOOL autoscaled;
		[Export("autoscaled")]
		bool Autoscaled { get; set; }

		// -(instancetype _Nonnull)initWithMesh:(NMAFloatMesh * _Nonnull)mesh;
		[Export("initWithMesh:")]
		IntPtr Constructor(NMAFloatMesh mesh);
	}
	*/

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const float NMAMapViewPreserveValue;
		[Field("NMAMapViewPreserveValue", "__Internal")]
		float NMAMapViewPreserveValue { get; }

		// extern const float NMAMapViewMaximumTilt;
		[Field("NMAMapViewMaximumTilt", "__Internal")]
		float NMAMapViewMaximumTilt { get; }
	}

	// typedef float (^NMATiltZoomProfile)(float);
	delegate float NMATiltZoomProfile(float arg0);

	// typedef BOOL (^NMAMapEventBlock)(NMAMapEvent, NMAMapView * _Nonnull, id _Nullable);
	delegate bool NMAMapEventBlock(NMAMapEvent arg0, NMAMapView arg1, [NullAllowed] NSObject arg2);

	// @protocol NMAMapViewDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAMapViewDelegate
	{
		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didSelectObjects:(NSArray<NMAViewObject *> * _Nonnull)objects;
		[Export("mapView:didSelectObjects:")]
		void MapViewDidSelectObjects(NMAMapView mapView, NMAViewObject[] objects);

		// @optional -(void)mapViewDidBeginMovement:(NMAMapView * _Nonnull)mapView;
		[Export("mapViewDidBeginMovement:")]
		void MapViewDidBeginMovement(NMAMapView mapView);

		// @optional -(void)mapViewDidEndMovement:(NMAMapView * _Nonnull)mapView;
		[Export("mapViewDidEndMovement:")]
		void MapViewDidEndMovement(NMAMapView mapView);

		// @optional -(void)mapViewDidBeginAnimation:(NMAMapView * _Nonnull)mapView;
		[Export("mapViewDidBeginAnimation:")]
		void MapViewDidBeginAnimation(NMAMapView mapView);

		// @optional -(void)mapViewDidEndAnimation:(NMAMapView * _Nonnull)mapView;
		[Export("mapViewDidEndAnimation:")]
		void MapViewDidEndAnimation(NMAMapView mapView);

		// @optional -(void)mapViewDidDraw:(NMAMapView * _Nonnull)mapView;
		[Export("mapViewDidDraw:")]
		void MapViewDidDraw(NMAMapView mapView);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didRenderBitmap:(void * _Nonnull)bitmap withWidth:(NSUInteger)width height:(NSUInteger)height bytesPerPixel:(NSUInteger)bytesPerPixel;
		//[Export("mapView:didRenderBitmap:withWidth:height:bytesPerPixel:")]
		//unsafe void MapViewDidRenderBitmap(NMAMapView mapView, void* bitmap, nuint width, nuint height, nuint bytesPerPixel);

		// @optional -(void)mapView:(NMAMapView * _Nonnull)mapView didTapOnSafetySpot:(NMASafetySpot * _Nonnull)info;
		[Export("mapView:didTapOnSafetySpot:")]
		void MapViewDidTapOnSafetySpot(NMAMapView mapView, NMASafetySpot info);
	}

	// @interface NMAMapView : UIView
	[BaseType(typeof(UIView))]
	interface NMAMapView
	{
		// +(void)shouldBeginRenderingAutomatically:(BOOL)enabled;
		[Static]
		[Export("shouldBeginRenderingAutomatically:")]
		void ShouldBeginRenderingAutomatically(bool enabled);

		// -(instancetype _Nonnull)initWithFrame:(CGRect)frame;
		[Export("initWithFrame:")]
		IntPtr Constructor(CGRect frame);

		// @property (getter = isRenderAllowed, nonatomic) BOOL renderAllowed;
		[Export("renderAllowed")]
		bool RenderAllowed { [Bind("isRenderAllowed")] get; set; }

		// @property (nonatomic) BOOL pauseOnWillResignActive;
		[Export("pauseOnWillResignActive")]
		bool PauseOnWillResignActive { get; set; }

		// @property (nonatomic) BOOL maximumRefreshRateLimitEnabled;
		[Export("maximumRefreshRateLimitEnabled")]
		bool MaximumRefreshRateLimitEnabled { get; set; }

		// @property (nonatomic) float maximumRefreshRate;
		[Export("maximumRefreshRate")]
		float MaximumRefreshRate { get; set; }

		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMAMapViewDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMAMapViewDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// -(NSInteger)respondToEvents:(NMAMapEvent)events withBlock:(NMAMapEventBlock _Nonnull)block;
		[Export("respondToEvents:withBlock:")]
		nint RespondToEvents(NMAMapEvent events, NMAMapEventBlock block);

		// -(BOOL)removeEventBlockWithIdentifier:(NSInteger)identifier;
		[Export("removeEventBlockWithIdentifier:")]
		bool RemoveEventBlockWithIdentifier(nint identifier);

		// @property (nonatomic) CGRect clipRect;
		[Export("clipRect", ArgumentSemantic.Assign)]
		CGRect ClipRect { get; set; }

		// @property (readonly, nonatomic, weak) NMAGeoBoundingBox * _Nullable boundingBox;
		[NullAllowed, Export("boundingBox", ArgumentSemantic.Weak)]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (nonatomic, strong) NSString * _Nonnull mapScheme;
		[Export("mapScheme", ArgumentSemantic.Strong)]
		string MapScheme { get; set; }

		// @property (readonly, nonatomic) NSArray<NSString *> * _Nonnull availableMapSchemes;
		[Export("availableMapSchemes")]
		string[] AvailableMapSchemes { get; }

		// @property (nonatomic) NMAProjectionType projectionType;
		[Export("projectionType", ArgumentSemantic.Assign)]
		NMAProjectionType ProjectionType { get; set; }

		// @property (readonly, nonatomic) NMAPositionIndicator * _Nonnull positionIndicator;
		[Export("positionIndicator")]
		NMAPositionIndicator PositionIndicator { get; }

		// @property (nonatomic) BOOL landmarksVisible;
		[Export("landmarksVisible")]
		bool LandmarksVisible { get; set; }

		// -(void)showFleetFeature:(NMAMapFleetFeatureType)fleetFeature;
		[Export("showFleetFeature:")]
		void ShowFleetFeature(NMAMapFleetFeatureType fleetFeature);

		// -(void)hideFleetFeature:(NMAMapFleetFeatureType)fleetFeature;
		[Export("hideFleetFeature:")]
		void HideFleetFeature(NMAMapFleetFeatureType fleetFeature);

		// -(BOOL)isFleetFeatureShown:(NMAMapFleetFeatureType)fleetFeature;
		[Export("isFleetFeatureShown:")]
		bool IsFleetFeatureShown(NMAMapFleetFeatureType fleetFeature);

		// @property (readonly, nonatomic) NMAVenue3dMapLayer * _Nullable venue3dMapLayer;
		[NullAllowed, Export("venue3dMapLayer")]
		NMAVenue3dMapLayer Venue3dMapLayer { get; }

		// -(NMACustomizableScheme * _Nullable)createCustomizableSchemeWithName:(NSString * _Nonnull)schemeName basedOnScheme:(NSString * _Nonnull)baseSchemeName;
		[Export("createCustomizableSchemeWithName:basedOnScheme:")]
		[return: NullAllowed]
		NMACustomizableScheme CreateCustomizableSchemeWithName(string schemeName, string baseSchemeName);

		// -(NMACustomizableScheme * _Nullable)getCustomizableSchemeWithName:(NSString * _Nonnull)schemeName;
		[Export("getCustomizableSchemeWithName:")]
		[return: NullAllowed]
		NMACustomizableScheme GetCustomizableSchemeWithName(string schemeName);

		// -(BOOL)removeCustomizableSchemeWithName:(NSString * _Nonnull)schemeName;
		[Export("removeCustomizableSchemeWithName:")]
		bool RemoveCustomizableSchemeWithName(string schemeName);

		// -(void)showPedestrianFeature:(NMAMapPedestrianFeatureType)pedestrianFeature;
		[Export("showPedestrianFeature:")]
		void ShowPedestrianFeature(NMAMapPedestrianFeatureType pedestrianFeature);

		// -(void)hidePedestrianFeature:(NMAMapPedestrianFeatureType)pedestrianFeature;
		[Export("hidePedestrianFeature:")]
		void HidePedestrianFeature(NMAMapPedestrianFeatureType pedestrianFeature);

		// -(BOOL)isPedestrianFeatureShown:(NMAMapPedestrianFeatureType)pedestrianFeature;
		[Export("isPedestrianFeatureShown:")]
		bool IsPedestrianFeatureShown(NMAMapPedestrianFeatureType pedestrianFeature);

		// -(void)setVisibility:(BOOL)visible forMapLayerCategories:(NSArray<NSNumber *> * _Nonnull)layerCategories;
		[Export("setVisibility:forMapLayerCategories:")]
		void SetVisibility(bool visible, NSNumber[] layerCategories);

		// -(NSArray<NSNumber *> * _Nonnull)visibleMapLayerCategories;
		[Export("visibleMapLayerCategories")]
		//[Verify(MethodToProperty)]
		NSNumber[] VisibleMapLayerCategories { get; }

		// @property (nonatomic) BOOL safetySpotsVisible;
		[Export("safetySpotsVisible")]
		bool SafetySpotsVisible { get; set; }

		// -(BOOL)isMapLayerCategoryVisible:(NMAMapLayerCategory)layerCategory;
		[Export("isMapLayerCategoryVisible:")]
		bool IsMapLayerCategoryVisible(NMAMapLayerCategory layerCategory);

		// -(BOOL)setVisibility:(BOOL)visible forPoiCategory:(NMAMapPoiCategory)poiCategory;
		[Export("setVisibility:forPoiCategory:")]
		bool SetVisibility(bool visible, NMAMapPoiCategory poiCategory);

		// -(BOOL)isPoiCategoryVisible:(NMAMapPoiCategory)poiCategory;
		[Export("isPoiCategoryVisible:")]
		bool IsPoiCategoryVisible(NMAMapPoiCategory poiCategory);

		// -(NSArray<NSString *> * _Nonnull)poiCategories;
		[Export("poiCategories")]
		//[Verify(MethodToProperty)]
		string[] PoiCategories { get; }

		// @property (readwrite, nonatomic) BOOL extrudedBuildingsVisible;
		[Export("extrudedBuildingsVisible")]
		bool ExtrudedBuildingsVisible { get; set; }

		// -(BOOL)useDefaultDisplayLanguage;
		[Export("useDefaultDisplayLanguage")]
		//[Verify(MethodToProperty)]
		bool UseDefaultDisplayLanguage { get; }

		// -(BOOL)useDisplayLanguageFromLocale:(NSLocale * _Nonnull)locale;
		[Export("useDisplayLanguageFromLocale:")]
		bool UseDisplayLanguageFromLocale(NSLocale locale);

		// @property (readonly, nonatomic, weak) NSString * _Nullable displayLanguage;
		[NullAllowed, Export("displayLanguage", ArgumentSemantic.Weak)]
		string DisplayLanguage { get; }

		// -(BOOL)useSecondaryDisplayLanguageFromLocale:(NSLocale * _Nullable)locale;
		[Export("useSecondaryDisplayLanguageFromLocale:")]
		bool UseSecondaryDisplayLanguageFromLocale([NullAllowed] NSLocale locale);

		// @property (readonly, nonatomic, weak) NSString * _Nullable secondaryDisplayLanguage;
		[NullAllowed, Export("secondaryDisplayLanguage", ArgumentSemantic.Weak)]
		string SecondaryDisplayLanguage { get; }

		// -(NSArray<NSString *> * _Nonnull)supportedDisplayLanguages;
		[Export("supportedDisplayLanguages")]
		//[Verify(MethodToProperty)]
		string[] SupportedDisplayLanguages { get; }

		[Wrap("WeakGestureDelegate")]
		[NullAllowed]
		NMAMapGestureDelegate GestureDelegate { get; set; }

		// @property (nonatomic, weak) id<NMAMapGestureDelegate> _Nullable gestureDelegate;
		[NullAllowed, Export("gestureDelegate", ArgumentSemantic.Weak)]
		NSObject WeakGestureDelegate { get; set; }

		// @property (readonly, nonatomic) id<NMAMapGestureDelegate> _Nullable defaultGestureHandler;
		[NullAllowed, Export("defaultGestureHandler")]
		NMAMapGestureDelegate DefaultGestureHandler { get; }

		// @property (getter = isMapInteractionEnabled, nonatomic) BOOL mapInteractionEnabled;
		[Export("mapInteractionEnabled")]
		bool MapInteractionEnabled { [Bind("isMapInteractionEnabled")] get; set; }

		// @property (nonatomic) NSTimeInterval longPressDuration;
		[Export("longPressDuration")]
		double LongPressDuration { get; set; }

		// @property (nonatomic) BOOL mapCenterFixedOnRotateZoom;
		[Export("mapCenterFixedOnRotateZoom")]
		bool MapCenterFixedOnRotateZoom { get; set; }

		// @property (nonatomic) BOOL upwardPanIncreasesTilt;
		[Export("upwardPanIncreasesTilt")]
		bool UpwardPanIncreasesTilt { get; set; }

		// @property (nonatomic) BOOL twoFingerPanTiltingEnabled;
		[Export("twoFingerPanTiltingEnabled")]
		bool TwoFingerPanTiltingEnabled { get; set; }

		// -(void)enableMapGestures:(NMAMapGestureType)gestures;
		[Export("enableMapGestures:")]
		void EnableMapGestures(NMAMapGestureType gestures);

		// -(void)disableMapGestures:(NMAMapGestureType)gestures;
		[Export("disableMapGestures:")]
		void DisableMapGestures(NMAMapGestureType gestures);

		// -(BOOL)isMapGestureEnabled:(NMAMapGestureType)gesture;
		[Export("isMapGestureEnabled:")]
		bool IsMapGestureEnabled(NMAMapGestureType gesture);

		// -(void)enableKineticForGestures:(NMAMapGestureType)gestures;
		[Export("enableKineticForGestures:")]
		void EnableKineticForGestures(NMAMapGestureType gestures);

		// -(void)disableKineticForGestures:(NMAMapGestureType)gestures;
		[Export("disableKineticForGestures:")]
		void DisableKineticForGestures(NMAMapGestureType gestures);

		// -(BOOL)isKineticForGestureEnabled:(NMAMapGestureType)gesture;
		[Export("isKineticForGestureEnabled:")]
		bool IsKineticForGestureEnabled(NMAMapGestureType gesture);

		// @property (nonatomic) NMAGeoCoordinates * _Nonnull geoCenter;
		[Export("geoCenter", ArgumentSemantic.Assign)]
		NMAGeoCoordinates GeoCenter { get; set; }

		// @property (nonatomic) float zoomLevel;
		[Export("zoomLevel")]
		float ZoomLevel { get; set; }

		// @property (getter = isExtendedZoomLevelsEnabled, nonatomic) BOOL extendedZoomLevelsEnabled;
		[Export("extendedZoomLevelsEnabled")]
		bool ExtendedZoomLevelsEnabled { [Bind("isExtendedZoomLevelsEnabled")] get; set; }

		// @property (readonly, nonatomic) float minimumZoomLevel;
		[Export("minimumZoomLevel")]
		float MinimumZoomLevel { get; }

		// @property (readonly, nonatomic) float maximumZoomLevel;
		[Export("maximumZoomLevel")]
		float MaximumZoomLevel { get; }

		// @property (nonatomic) float orientation;
		[Export("orientation")]
		float Orientation { get; set; }

		// @property (nonatomic) float tilt;
		[Export("tilt")]
		float Tilt { get; set; }

		// @property (readonly, nonatomic) float clippedTilt;
		[Export("clippedTilt")]
		float ClippedTilt { get; }

		// @property (nonatomic, strong) NMATiltZoomProfile _Nonnull maximumTiltProfile;
		[Export("maximumTiltProfile", ArgumentSemantic.Strong)]
		NMATiltZoomProfile MaximumTiltProfile { get; set; }

		// -(float)minimumTiltAtZoomLevel:(float)zoomLevel;
		[Export("minimumTiltAtZoomLevel:")]
		float MinimumTiltAtZoomLevel(float zoomLevel);

		// -(float)maximumTiltAtZoomLevel:(float)zoomLevel;
		[Export("maximumTiltAtZoomLevel:")]
		float MaximumTiltAtZoomLevel(float zoomLevel);

		// @property (nonatomic) CGPoint transformCenter;
		[Export("transformCenter", ArgumentSemantic.Assign)]
		CGPoint TransformCenter { get; set; }

		// @property (nonatomic) UIEdgeInsets padding;
		[Export("padding", ArgumentSemantic.Assign)]
		UIEdgeInsets Padding { get; set; }

		// -(void)setGeoCenter:(NMAGeoCoordinates * _Nonnull)geoCenter withAnimation:(NMAMapAnimation)animationType;
		[Export("setGeoCenter:withAnimation:")]
		void SetGeoCenter(NMAGeoCoordinates geoCenter, NMAMapAnimation animationType);

		// -(void)setOrientation:(float)orientation withAnimation:(NMAMapAnimation)animationType;
		[Export("setOrientation:withAnimation:")]
		void SetOrientation(float orientation, NMAMapAnimation animationType);

		// -(void)setZoomLevel:(float)zoomLevel withAnimation:(NMAMapAnimation)animationType;
		[Export("setZoomLevel:withAnimation:")]
		void SetZoomLevel(float zoomLevel, NMAMapAnimation animationType);

		// -(void)setTilt:(float)tilt withAnimation:(NMAMapAnimation)animationType;
		[Export("setTilt:withAnimation:")]
		void SetTilt(float tilt, NMAMapAnimation animationType);

		// -(void)setGeoCenter:(NMAGeoCoordinates * _Nonnull)geoCenter zoomLevel:(float)zoomLevel withAnimation:(NMAMapAnimation)animationType;
		[Export("setGeoCenter:zoomLevel:withAnimation:")]
		void SetGeoCenter(NMAGeoCoordinates geoCenter, float zoomLevel, NMAMapAnimation animationType);

		// -(void)setGeoCenter:(NMAGeoCoordinates * _Nullable)geoCenter zoomLevel:(float)zoomLevel orientation:(float)orientation tilt:(float)tilt withAnimation:(NMAMapAnimation)animationType;
		[Export("setGeoCenter:zoomLevel:orientation:tilt:withAnimation:")]
		void SetGeoCenter([NullAllowed] NMAGeoCoordinates geoCenter, float zoomLevel, float orientation, float tilt, NMAMapAnimation animationType);

		// -(void)setGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates toPoint:(CGPoint)point withAnimation:(NMAMapAnimation)animation;
		[Export("setGeoCoordinates:toPoint:withAnimation:")]
		void SetGeoCoordinates(NMAGeoCoordinates coordinates, CGPoint point, NMAMapAnimation animation);

		// -(void)setGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates toPoint:(CGPoint)point withAnimation:(NMAMapAnimation)animation zoomLevel:(float)zoomLevel orientation:(float)orientation tilt:(float)tilt;
		[Export("setGeoCoordinates:toPoint:withAnimation:zoomLevel:orientation:tilt:")]
		void SetGeoCoordinates(NMAGeoCoordinates coordinates, CGPoint point, NMAMapAnimation animation, float zoomLevel, float orientation, float tilt);

		// -(void)setBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox withAnimation:(NMAMapAnimation)animationType;
		[Export("setBoundingBox:withAnimation:")]
		void SetBoundingBox(NMAGeoBoundingBox boundingBox, NMAMapAnimation animationType);

		// -(void)setBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox insideRect:(CGRect)screenRect withAnimation:(NMAMapAnimation)animationType;
		[Export("setBoundingBox:insideRect:withAnimation:")]
		void SetBoundingBox(NMAGeoBoundingBox boundingBox, CGRect screenRect, NMAMapAnimation animationType);

		// -(NMAGeoCoordinates * _Nullable)geoCoordinatesFromPoint:(CGPoint)point;
		[Export("geoCoordinatesFromPoint:")]
		[return: NullAllowed]
		NMAGeoCoordinates GeoCoordinatesFromPoint(CGPoint point);

		// -(NMAGeoCoordinates * _Nullable)geoCoordinatesFromPoint:(CGPoint)point withAltitude:(float)altitude;
		[Export("geoCoordinatesFromPoint:withAltitude:")]
		[return: NullAllowed]
		NMAGeoCoordinates GeoCoordinatesFromPoint(CGPoint point, float altitude);

		// -(CGPoint)pointFromGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("pointFromGeoCoordinates:")]
		CGPoint PointFromGeoCoordinates(NMAGeoCoordinates coordinates);

		// -(double)pointDistanceFromGeoCoordinates:(NMAGeoCoordinates * _Nonnull)startCoordinates toGeoCoordinates:(NMAGeoCoordinates * _Nonnull)endCoordinates;
		[Export("pointDistanceFromGeoCoordinates:toGeoCoordinates:")]
		double PointDistanceFromGeoCoordinates(NMAGeoCoordinates startCoordinates, NMAGeoCoordinates endCoordinates);

		// -(float)metersPerPointAtZoomLevel:(float)zoomLevel;
		[Export("metersPerPointAtZoomLevel:")]
		float MetersPerPointAtZoomLevel(float zoomLevel);

		// +(void)snapshotWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates zoomLevel:(float)zoom orientation:(float)orientation size:(CGSize)size block:(void (^ _Nonnull)(UIImage * _Nonnull))resultBlock;
		[Static]
		[Export("snapshotWithGeoCoordinates:zoomLevel:orientation:size:block:")]
		void SnapshotWithGeoCoordinates(NMAGeoCoordinates coordinates, float zoom, float orientation, CGSize size, Action<UIImage> resultBlock);

		// -(void)snapshotWithBlock:(void (^ _Nonnull)(UIImage * _Nullable))resultBlock;
		[Export("snapshotWithBlock:")]
		void SnapshotWithBlock(Action<UIImage> resultBlock);

		// -(BOOL)addMapObject:(NMAMapObject * _Nonnull)object;
		[Export("addMapObject:")]
		bool AddMapObject(NMAMapObject @object);

		// -(BOOL)addMapObject:(NMAMapObject * _Nonnull)object toLayer:(NMAMapLayerType)layer;
		[Export("addMapObject:toLayer:")]
		bool AddMapObject(NMAMapObject @object, NMAMapLayerType layer);

		// -(BOOL)addMapObjects:(NSArray<NMAMapObject *> * _Nonnull)objects;
		[Export("addMapObjects:")]
		bool AddMapObjects(NMAMapObject[] objects);

		// -(BOOL)addMapObjects:(NSArray<NMAMapObject *> * _Nonnull)objects toLayer:(NMAMapLayerType)layer;
		[Export("addMapObjects:toLayer:")]
		bool AddMapObjects(NMAMapObject[] objects, NMAMapLayerType layer);

		// -(NSArray<NMAMapObject *> * _Nonnull)allMapObjects;
		[Export("allMapObjects")]
		//[Verify(MethodToProperty)]
		NMAMapObject[] AllMapObjects { get; }

		// -(BOOL)removeMapObject:(NMAMapObject * _Nonnull)object;
		[Export("removeMapObject:")]
		bool RemoveMapObject(NMAMapObject @object);

		// -(BOOL)removeMapObjects:(NSArray<NMAMapObject *> * _Nonnull)objects;
		[Export("removeMapObjects:")]
		bool RemoveMapObjects(NMAMapObject[] objects);

		// -(BOOL)removeAllMapObjects;
		[Export("removeAllMapObjects")]
		//[Verify(MethodToProperty)]
		bool RemoveAllMapObjects { get; }

		// -(NSArray<NMAViewObject *> * _Nonnull)objectsAtPoint:(CGPoint)point;
		[Export("objectsAtPoint:")]
		NMAViewObject[] ObjectsAtPoint(CGPoint point);

		// -(NSArray<NMAViewObject *> * _Nonnull)visibleObjectsAtPoint:(CGPoint)point;
		[Export("visibleObjectsAtPoint:")]
		NMAViewObject[] VisibleObjectsAtPoint(CGPoint point);

		// -(BOOL)addClusterLayer:(NMAClusterLayer * _Nonnull)clusterLayer;
		[Export("addClusterLayer:")]
		bool AddClusterLayer(NMAClusterLayer clusterLayer);

		// -(BOOL)removeClusterLayer:(NMAClusterLayer * _Nonnull)clusterLayer;
		[Export("removeClusterLayer:")]
		bool RemoveClusterLayer(NMAClusterLayer clusterLayer);

		// -(BOOL)addMapOverlay:(NMAMapOverlay * _Nonnull)overlay;
		[Export("addMapOverlay:")]
		bool AddMapOverlay(NMAMapOverlay overlay);

		// -(BOOL)removeMapOverlay:(NMAMapOverlay * _Nonnull)overlay;
		[Export("removeMapOverlay:")]
		bool RemoveMapOverlay(NMAMapOverlay overlay);

		// @property (readonly, nonatomic) NSString * _Nonnull copyright;
		[Export("copyright")]
		string Copyright { get; }

		// @property (nonatomic) NMALayoutPosition copyrightLogoPosition;
		[Export("copyrightLogoPosition", ArgumentSemantic.Assign)]
		NMALayoutPosition CopyrightLogoPosition { get; set; }

		// @property (nonatomic) float copyrightLogoVerticalMargin;
		[Export("copyrightLogoVerticalMargin")]
		float CopyrightLogoVerticalMargin { get; set; }

		// @property (nonatomic) float copyrightLogoHorizontalMargin;
		[Export("copyrightLogoHorizontalMargin")]
		float CopyrightLogoHorizontalMargin { get; set; }

		// @property (nonatomic) NMAMapTransitDisplayMode transitDisplayMode;
		[Export("transitDisplayMode", ArgumentSemantic.Assign)]
		NMAMapTransitDisplayMode TransitDisplayMode { get; set; }

		// @property (readonly, nonatomic) NMAMapTransitLayer * _Nonnull mapTransitLayer;
		[Export("mapTransitLayer")]
		NMAMapTransitLayer MapTransitLayer { get; }

		// @property (getter = isTrafficVisible, nonatomic) BOOL trafficVisible;
		[Export("trafficVisible")]
		bool TrafficVisible { [Bind("isTrafficVisible")] get; set; }

		// -(void)showTrafficLayers:(NMATrafficLayer)layers;
		[Export("showTrafficLayers:")]
		void ShowTrafficLayers(NMATrafficLayer layers);

		// -(void)hideTrafficLayers:(NMATrafficLayer)layers;
		[Export("hideTrafficLayers:")]
		void HideTrafficLayers(NMATrafficLayer layers);

		// -(BOOL)isTrafficLayerVisible:(NMATrafficLayer)layer;
		[Export("isTrafficLayerVisible:")]
		bool IsTrafficLayerVisible(NMATrafficLayer layer);

		// @property (nonatomic) NMATrafficSeverity trafficDisplayFilter;
		[Export("trafficDisplayFilter", ArgumentSemantic.Assign)]
		NMATrafficSeverity TrafficDisplayFilter { get; set; }

		// -(NSArray<NMARoadElement *> * _Nonnull)roadElementsInArea:(NMAGeoBoundingBox * _Nonnull)geoArea;
		[Export("roadElementsInArea:")]
		NMARoadElement[] RoadElementsInArea(NMAGeoBoundingBox geoArea);

		// -(NSArray<NMARoadElement *> * _Nonnull)roadElementsInArea:(NMAGeoBoundingBox * _Nonnull)geoArea lang:(NSString * _Nullable)marcLangCode;
		[Export("roadElementsInArea:lang:")]
		NMARoadElement[] RoadElementsInArea(NMAGeoBoundingBox geoArea, [NullAllowed] string marcLangCode);

		// -(NMARoadElement * _Nullable)roadElementAtCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("roadElementAtCoordinates:")]
		[return: NullAllowed]
		NMARoadElement RoadElementAtCoordinates(NMAGeoCoordinates coordinates);

		// -(NMARoadElement * _Nullable)roadElementAtCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates lang:(NSString * _Nullable)marcLangCode;
		[Export("roadElementAtCoordinates:lang:")]
		[return: NullAllowed]
		NMARoadElement RoadElementAtCoordinates(NMAGeoCoordinates coordinates, [NullAllowed] string marcLangCode);

		// -(void)addMapTileLayer:(NMAMapTileLayer * _Nonnull)tileLayer;
		[Export("addMapTileLayer:")]
		void AddMapTileLayer(NMAMapTileLayer tileLayer);

		// -(void)removeMapTileLayer:(NMAMapTileLayer * _Nonnull)tileLayer;
		[Export("removeMapTileLayer:")]
		void RemoveMapTileLayer(NMAMapTileLayer tileLayer);

		// -(NSArray<NMAMapTileLayer *> * _Nonnull)mapTileLayers;
		[Export("mapTileLayers")]
		//[Verify(MethodToProperty)]
		NMAMapTileLayer[] MapTileLayers { get; }

		// @property (nonatomic) BOOL softwareRenderToBitmap;
		//[Export("softwareRenderToBitmap")]
		//bool SoftwareRenderToBitmap { get; set; }
	}

	// @interface NMAMapOverlay : UIView <NMAMapViewDelegate>
	[BaseType(typeof(UIView))]
	interface NMAMapOverlay : NMAMapViewDelegate
	{
		// +(instancetype _Nonnull)mapOverlayWithSubview:(UIView * _Nonnull)subview;
		[Static]
		[Export("mapOverlayWithSubview:")]
		NMAMapOverlay MapOverlayWithSubview(UIView subview);

		// +(instancetype _Nonnull)mapOverlayWithSubview:(UIView * _Nonnull)subview geoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Static]
		[Export("mapOverlayWithSubview:geoCoordinates:")]
		NMAMapOverlay MapOverlayWithSubview(UIView subview, NMAGeoCoordinates coordinates);

		// @property (nonatomic, strong) NMAGeoCoordinates * _Nonnull coordinates;
		[Export("coordinates", ArgumentSemantic.Strong)]
		NMAGeoCoordinates Coordinates { get; set; }

		// @property (nonatomic) CGPoint anchorOffset;
		[Export("anchorOffset", ArgumentSemantic.Assign)]
		CGPoint AnchorOffset { get; set; }

		// @property (nonatomic) BOOL displayedAsMarker;
		[Export("displayedAsMarker")]
		bool DisplayedAsMarker { get; set; }

		// @property (nonatomic) NSUInteger zMarkerIndex;
		[Export("zMarkerIndex")]
		nuint ZMarkerIndex { get; set; }

		// -(instancetype _Nonnull)initWithSubview:(UIView * _Nonnull)subview;
		[Export("initWithSubview:")]
		IntPtr Constructor(UIView subview);

		// -(instancetype _Nonnull)initWithSubview:(UIView * _Nonnull)subview geoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates __attribute__((objc_designated_initializer));
		[Export("initWithSubview:geoCoordinates:")]
		[DesignatedInitializer]
		IntPtr Constructor(UIView subview, NMAGeoCoordinates coordinates);

		// -(CGPoint)setAnchorOffsetUsingLayoutPosition:(NMALayoutPosition)position;
		[Export("setAnchorOffsetUsingLayoutPosition:")]
		CGPoint SetAnchorOffsetUsingLayoutPosition(NMALayoutPosition position);

		// -(void)refresh;
		[Export("refresh")]
		void Refresh();
	}

	// @interface NMAMapPolygon : NMAMapObject
	[BaseType(typeof(NMAMapObject))]
	interface NMAMapPolygon
	{
		// +(instancetype _Nonnull)mapPolygonWithVertices:(NSArray<NMAGeoCoordinates *> * _Nonnull)vertices;
		[Static]
		[Export("mapPolygonWithVertices:")]
		NMAMapPolygon MapPolygonWithVertices(NMAGeoCoordinates[] vertices);

		// @property (nonatomic, strong) UIColor * _Nonnull fillColor;
		[Export("fillColor", ArgumentSemantic.Strong)]
		UIColor FillColor { get; set; }

		// @property (readonly, nonatomic, weak) NSArray<NMAGeoCoordinates *> * _Nullable vertices;
		[NullAllowed, Export("vertices", ArgumentSemantic.Weak)]
		NMAGeoCoordinates[] Vertices { get; }

		// @property (nonatomic, strong) UIColor * _Nonnull lineColor;
		[Export("lineColor", ArgumentSemantic.Strong)]
		UIColor LineColor { get; set; }

		// @property (nonatomic) NSUInteger lineWidth;
		[Export("lineWidth")]
		nuint LineWidth { get; set; }

		// @property (getter = isDashed, nonatomic) BOOL dashed;
		[Export("dashed")]
		bool Dashed { [Bind("isDashed")] get; set; }

		// @property (nonatomic) NSUInteger dashPrimaryLength;
		[Export("dashPrimaryLength")]
		nuint DashPrimaryLength { get; set; }

		// @property (nonatomic) NSUInteger dashSecondaryLength;
		[Export("dashSecondaryLength")]
		nuint DashSecondaryLength { get; set; }

		// @property (nonatomic) BOOL depthTestEnabled;
		[Export("depthTestEnabled")]
		bool DepthTestEnabled { get; set; }

		// -(instancetype _Nonnull)initWithPolygon:(NMAGeoPolygon * _Nonnull)geoPolygon;
		[Export("initWithPolygon:")]
		IntPtr Constructor(NMAGeoPolygon geoPolygon);

		// @property (readonly, nonatomic) NMAGeoPolygon * _Nonnull geoPolygon;
		[Export("geoPolygon")]
		NMAGeoPolygon GeoPolygon { get; }

		// -(instancetype _Nonnull)initWithVertices:(NSArray<NMAGeoCoordinates *> * _Nonnull)vertices __attribute__((objc_designated_initializer));
		[Export("initWithVertices:")]
		[DesignatedInitializer]
		IntPtr Constructor(NMAGeoCoordinates[] vertices);

		// -(void)clearVertices;
		[Export("clearVertices")]
		void ClearVertices();

		// -(void)addVertex:(NMAGeoCoordinates * _Nonnull)vertex atIndex:(NSUInteger)index;
		[Export("addVertex:atIndex:")]
		void AddVertex(NMAGeoCoordinates vertex, nuint index);

		// -(void)appendVertex:(NMAGeoCoordinates * _Nonnull)vertex;
		[Export("appendVertex:")]
		void AppendVertex(NMAGeoCoordinates vertex);

		// -(void)removeLastVertex;
		[Export("removeLastVertex")]
		void RemoveLastVertex();

		// -(void)removeVertexAtIndex:(NSUInteger)index;
		[Export("removeVertexAtIndex:")]
		void RemoveVertexAtIndex(nuint index);

		// -(BOOL)isValid;
		[Export("isValid")]
		//[Verify(MethodToProperty)]
		bool IsValid { get; }

		// -(BOOL)containsGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("containsGeoCoordinates:")]
		bool ContainsGeoCoordinates(NMAGeoCoordinates coordinates);

		// @property (assign, nonatomic) NMAPatternStyle patternStyle;
		[Export("patternStyle", ArgumentSemantic.Assign)]
		NMAPatternStyle PatternStyle { get; set; }

		// @property (readwrite, nonatomic) NMAImage * _Nullable customPattern;
		[NullAllowed, Export("customPattern", ArgumentSemantic.Assign)]
		NMAImage CustomPattern { get; set; }
	}

	// @interface NMAMapRoute : NMAMapObject
	[BaseType(typeof(NMAMapObject))]
	[DisableDefaultCtor]
	interface NMAMapRoute
	{
		// +(instancetype _Nullable)mapRouteWithRoute:(NMARoute * _Nonnull)route;
		[Static]
		[Export("mapRouteWithRoute:")]
		[return: NullAllowed]
		NMAMapRoute MapRouteWithRoute(NMARoute route);

		// -(instancetype _Nullable)initWithRoute:(NMARoute * _Nonnull)route;
		[Export("initWithRoute:")]
		IntPtr Constructor(NMARoute route);

		// @property (nonatomic) BOOL maneuverNumberDisplayed;
		[Export("maneuverNumberDisplayed")]
		bool ManeuverNumberDisplayed { get; set; }

		// @property (nonatomic, strong) UIColor * _Nullable color;
		[NullAllowed, Export("color", ArgumentSemantic.Strong)]
		UIColor Color { get; set; }

		// @property (nonatomic, strong) UIColor * _Nullable traveledColor;
		[NullAllowed, Export("traveledColor", ArgumentSemantic.Strong)]
		UIColor TraveledColor { get; set; }

		// @property (nonatomic, strong) UIColor * _Nullable upcomingColor;
		[NullAllowed, Export("upcomingColor", ArgumentSemantic.Strong)]
		UIColor UpcomingColor { get; set; }

		// @property (nonatomic, strong) UIColor * _Nullable outlineColor;
		[NullAllowed, Export("outlineColor", ArgumentSemantic.Strong)]
		UIColor OutlineColor { get; set; }

		// @property (nonatomic, strong) UIColor * _Nullable textColor;
		[NullAllowed, Export("textColor", ArgumentSemantic.Strong)]
		UIColor TextColor { get; set; }

		// @property (nonatomic, strong) UIColor * _Nullable textOutlineColor;
		[NullAllowed, Export("textOutlineColor", ArgumentSemantic.Strong)]
		UIColor TextOutlineColor { get; set; }

		// @property (nonatomic, strong) UIColor * _Nullable maneuverNumberColor;
		[NullAllowed, Export("maneuverNumberColor", ArgumentSemantic.Strong)]
		UIColor ManeuverNumberColor { get; set; }

		// @property (assign, nonatomic) NMAMapRouteRenderType renderType;
		[Export("renderType", ArgumentSemantic.Assign)]
		NMAMapRouteRenderType RenderType { get; set; }

		// @property (nonatomic, strong) NMARoute * _Nonnull route;
		[Export("route", ArgumentSemantic.Strong)]
		NMARoute Route { get; set; }

		// @property (getter = isTrafficEnabled, nonatomic) BOOL trafficEnabled;
		[Export("trafficEnabled")]
		bool TrafficEnabled { [Bind("isTrafficEnabled")] get; set; }

		// @property (nonatomic) NSUInteger zIndex;
		[Export("zIndex")]
		nuint ZIndex { get; set; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMAMapSchemeNormalDay;
		[Field("NMAMapSchemeNormalDay", "__Internal")]
		NSString NMAMapSchemeNormalDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeNormalNight;
		[Field("NMAMapSchemeNormalNight", "__Internal")]
		NSString NMAMapSchemeNormalNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeReducedDay;
		[Field("NMAMapSchemeReducedDay", "__Internal")]
		NSString NMAMapSchemeReducedDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeReducedNight;
		[Field("NMAMapSchemeReducedNight", "__Internal")]
		NSString NMAMapSchemeReducedNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeNormalDayTransit;
		[Field("NMAMapSchemeNormalDayTransit", "__Internal")]
		NSString NMAMapSchemeNormalDayTransit { get; }

		// extern NSString *const _Nonnull NMAMapSchemeNormalNightTransit;
		[Field("NMAMapSchemeNormalNightTransit", "__Internal")]
		NSString NMAMapSchemeNormalNightTransit { get; }

		// extern NSString *const _Nonnull NMAMapSchemeTerrainDay;
		[Field("NMAMapSchemeTerrainDay", "__Internal")]
		NSString NMAMapSchemeTerrainDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeSatelliteDay;
		[Field("NMAMapSchemeSatelliteDay", "__Internal")]
		NSString NMAMapSchemeSatelliteDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeSatelliteNight;
		[Field("NMAMapSchemeSatelliteNight", "__Internal")]
		NSString NMAMapSchemeSatelliteNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridDay;
		[Field("NMAMapSchemeHybridDay", "__Internal")]
		NSString NMAMapSchemeHybridDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridGreyDay;
		[Field("NMAMapSchemeHybridGreyDay", "__Internal")]
		NSString NMAMapSchemeHybridGreyDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridNight;
		[Field("NMAMapSchemeHybridNight", "__Internal")]
		NSString NMAMapSchemeHybridNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridGreyNight;
		[Field("NMAMapSchemeHybridGreyNight", "__Internal")]
		NSString NMAMapSchemeHybridGreyNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridReducedDay;
		[Field("NMAMapSchemeHybridReducedDay", "__Internal")]
		NSString NMAMapSchemeHybridReducedDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridReducedNight;
		[Field("NMAMapSchemeHybridReducedNight", "__Internal")]
		NSString NMAMapSchemeHybridReducedNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeManeuverDay;
		[Field("NMAMapSchemeManeuverDay", "__Internal")]
		NSString NMAMapSchemeManeuverDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridDayTransit;
		[Field("NMAMapSchemeHybridDayTransit", "__Internal")]
		NSString NMAMapSchemeHybridDayTransit { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridNightTransit;
		[Field("NMAMapSchemeHybridNightTransit", "__Internal")]
		NSString NMAMapSchemeHybridNightTransit { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationDay;
		[Field("NMAMapSchemeCarNavigationDay", "__Internal")]
		NSString NMAMapSchemeCarNavigationDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationDayGrey;
		[Field("NMAMapSchemeCarNavigationDayGrey", "__Internal")]
		NSString NMAMapSchemeCarNavigationDayGrey { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationNight;
		[Field("NMAMapSchemeCarNavigationNight", "__Internal")]
		NSString NMAMapSchemeCarNavigationNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationNightGrey;
		[Field("NMAMapSchemeCarNavigationNightGrey", "__Internal")]
		NSString NMAMapSchemeCarNavigationNightGrey { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridCarNavigationDay;
		[Field("NMAMapSchemeHybridCarNavigationDay", "__Internal")]
		NSString NMAMapSchemeHybridCarNavigationDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridPedestrianDay;
		[Field("NMAMapSchemeHybridPedestrianDay", "__Internal")]
		NSString NMAMapSchemeHybridPedestrianDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridPedestrianNight;
		[Field("NMAMapSchemeHybridPedestrianNight", "__Internal")]
		NSString NMAMapSchemeHybridPedestrianNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridCarNavigationNight;
		[Field("NMAMapSchemeHybridCarNavigationNight", "__Internal")]
		NSString NMAMapSchemeHybridCarNavigationNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemePedestrianDay;
		[Field("NMAMapSchemePedestrianDay", "__Internal")]
		NSString NMAMapSchemePedestrianDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemePedestrianNight;
		[Field("NMAMapSchemePedestrianNight", "__Internal")]
		NSString NMAMapSchemePedestrianNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeTruckDay;
		[Field("NMAMapSchemeTruckDay", "__Internal")]
		NSString NMAMapSchemeTruckDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeTruckNight;
		[Field("NMAMapSchemeTruckNight", "__Internal")]
		NSString NMAMapSchemeTruckNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridTruckDay;
		[Field("NMAMapSchemeHybridTruckDay", "__Internal")]
		NSString NMAMapSchemeHybridTruckDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridTruckNight;
		[Field("NMAMapSchemeHybridTruckNight", "__Internal")]
		NSString NMAMapSchemeHybridTruckNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeTruckNavigationDay;
		[Field("NMAMapSchemeTruckNavigationDay", "__Internal")]
		NSString NMAMapSchemeTruckNavigationDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeTruckNavigationNight;
		[Field("NMAMapSchemeTruckNavigationNight", "__Internal")]
		NSString NMAMapSchemeTruckNavigationNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridTruckNavigationDay;
		[Field("NMAMapSchemeHybridTruckNavigationDay", "__Internal")]
		NSString NMAMapSchemeHybridTruckNavigationDay { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridTruckNavigationNight;
		[Field("NMAMapSchemeHybridTruckNavigationNight", "__Internal")]
		NSString NMAMapSchemeHybridTruckNavigationNight { get; }

		// extern NSString *const _Nonnull NMAMapSchemeNormalDayWithTraffic;
		[Field("NMAMapSchemeNormalDayWithTraffic", "__Internal")]
		NSString NMAMapSchemeNormalDayWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeNormalNightWithTraffic;
		[Field("NMAMapSchemeNormalNightWithTraffic", "__Internal")]
		NSString NMAMapSchemeNormalNightWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridDayWithTraffic;
		[Field("NMAMapSchemeHybridDayWithTraffic", "__Internal")]
		NSString NMAMapSchemeHybridDayWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridNightWithTraffic;
		[Field("NMAMapSchemeHybridNightWithTraffic", "__Internal")]
		NSString NMAMapSchemeHybridNightWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationDayWithTraffic;
		[Field("NMAMapSchemeCarNavigationDayWithTraffic", "__Internal")]
		NSString NMAMapSchemeCarNavigationDayWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeCarNavigationNightWithTraffic;
		[Field("NMAMapSchemeCarNavigationNightWithTraffic", "__Internal")]
		NSString NMAMapSchemeCarNavigationNightWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridCarNavigationDayWithTraffic;
		[Field("NMAMapSchemeHybridCarNavigationDayWithTraffic", "__Internal")]
		NSString NMAMapSchemeHybridCarNavigationDayWithTraffic { get; }

		// extern NSString *const _Nonnull NMAMapSchemeHybridCarNavigationNightWithTraffic;
		[Field("NMAMapSchemeHybridCarNavigationNightWithTraffic", "__Internal")]
		NSString NMAMapSchemeHybridCarNavigationNightWithTraffic { get; }
	}

	// @interface NMAMapTileRequest : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAMapTileRequest
	{
		// @property (readonly, nonatomic) void * _Nullable bytesPtr;
		[NullAllowed, Export("bytesPtr")]
		unsafe IntPtr BytesPtr { get; }

		// @property (readonly, nonatomic) int bytesLength;
		[Export("bytesLength")]
		int BytesLength { get; }

		// @property (nonatomic) NMAMapTileRequestStatus status;
		[Export("status", ArgumentSemantic.Assign)]
		NMAMapTileRequestStatus Status { get; set; }

		// -(BOOL)getBytesFromData:(NSData * _Nonnull)tileData;
		[Export("getBytesFromData:")]
		bool GetBytesFromData(NSData tileData);
	}

	// @interface NMAMapTransitLayer : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAMapTransitLayer
	{
		// -(void)highlightTransitLinesFromUniqueIds:(NSArray<NSString *> * _Nonnull)uniqueIds;
		[Export("highlightTransitLinesFromUniqueIds:")]
		void HighlightTransitLinesFromUniqueIds(string[] uniqueIds);

		// -(void)highlightTransitStopsFromUniqueIds:(NSArray<NSString *> * _Nonnull)uniqueIds;
		[Export("highlightTransitStopsFromUniqueIds:")]
		void HighlightTransitStopsFromUniqueIds(string[] uniqueIds);

		// -(void)highlightTransitAccessesFromUniqueIds:(NSArray<NSString *> * _Nonnull)uniqueIds;
		[Export("highlightTransitAccessesFromUniqueIds:")]
		void HighlightTransitAccessesFromUniqueIds(string[] uniqueIds);

		// -(void)highlightTransitLineSegmentsFromUniqueIds:(NSArray<NSString *> * _Nonnull)uniqueIds;
		[Export("highlightTransitLineSegmentsFromUniqueIds:")]
		void HighlightTransitLineSegmentsFromUniqueIds(string[] uniqueIds);

		// -(void)clearTransitHighlights;
		[Export("clearTransitHighlights")]
		void ClearTransitHighlights();
	}

	// @interface NMAMaterial : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAMaterial
	{
	}

	// @interface NMAPhongMaterial : NMAMaterial
	[BaseType(typeof(NMAMaterial))]
	interface NMAPhongMaterial
	{
		// +(instancetype _Nonnull)materialWithDiffuseColor:(UIColor * _Nonnull)diffuseColor ambientColor:(UIColor * _Nonnull)ambientColor;
		[Static]
		[Export("materialWithDiffuseColor:ambientColor:")]
		NMAPhongMaterial MaterialWithDiffuseColor(UIColor diffuseColor, UIColor ambientColor);

		// +(instancetype _Nonnull)new;
		[Static]
		[Export("new")]
		NMAPhongMaterial New();

		// -(instancetype _Nonnull)initWithDiffuseColor:(UIColor * _Nonnull)diffuseColor ambientColor:(UIColor * _Nonnull)ambientColor;
		[Export("initWithDiffuseColor:ambientColor:")]
		IntPtr Constructor(UIColor diffuseColor, UIColor ambientColor);

		// @property (nonatomic, strong) UIColor * _Nonnull diffuseColor;
		[Export("diffuseColor", ArgumentSemantic.Strong)]
		UIColor DiffuseColor { get; set; }

		// @property (nonatomic, strong) UIColor * _Nonnull ambientColor;
		[Export("ambientColor", ArgumentSemantic.Strong)]
		UIColor AmbientColor { get; set; }
	}

	// @interface NMAPoiObject : NMAProxyObject
	[BaseType(typeof(NMAProxyObject))]
	[DisableDefaultCtor]
	interface NMAPoiObject
	{
		// @property (nonatomic) NMALocationInfo * _Nonnull locationInfo;
		[Export("locationInfo", ArgumentSemantic.Assign)]
		NMALocationInfo LocationInfo { get; set; }
	}

	// @interface NMAPositionIndicator : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAPositionIndicator
	{
		// @property (nonatomic) NMAMapObject * _Nullable displayObject;
		[NullAllowed, Export("displayObject", ArgumentSemantic.Assign)]
		NMAMapObject DisplayObject { get; set; }

		// @property (getter = isVisible, nonatomic) BOOL visible;
		[Export("visible")]
		bool Visible { [Bind("isVisible")] get; set; }

		// @property (nonatomic) float hue;
		[Export("hue")]
		float Hue { get; set; }

		// @property (getter = isAccuracyIndicatorVisible, nonatomic) BOOL accuracyIndicatorVisible;
		[Export("accuracyIndicatorVisible")]
		bool AccuracyIndicatorVisible { [Bind("isAccuracyIndicatorVisible")] get; set; }

		// @property (nonatomic) UIColor * _Nonnull accuracyIndicatorColor;
		[Export("accuracyIndicatorColor", ArgumentSemantic.Assign)]
		UIColor AccuracyIndicatorColor { get; set; }

		// @property (nonatomic) NMAPositionIndicatorType type;
		[Export("type", ArgumentSemantic.Assign)]
		NMAPositionIndicatorType Type { get; set; }

		// @property (nonatomic) BOOL tracksCourse;
		[Export("tracksCourse")]
		bool TracksCourse { get; set; }

		// @property (nonatomic) float orientationOffset;
		[Export("orientationOffset")]
		float OrientationOffset { get; set; }

		// -(void)setDisplayObject:(NMAMapObject * _Nullable)displayObject toLayer:(NMAMapLayerType)layer;
		[Export("setDisplayObject:toLayer:")]
		void SetDisplayObject([NullAllowed] NMAMapObject displayObject, NMAMapLayerType layer);
	}

	// @interface NMALaneInformation : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMALaneInformation
	{
		// @property (readonly, nonatomic) NMALaneInformationDirection directions;
		[Export("directions")]
		NMALaneInformationDirection Directions { get; }

		// @property (readonly, nonatomic) NMALaneInformationDirection matchedDirection;
		[Export("matchedDirection")]
		NMALaneInformationDirection MatchedDirection { get; }

		// @property (readonly, getter = isSyntheticDirection, nonatomic) BOOL syntheticDirection;
		[Export("syntheticDirection")]
		bool SyntheticDirection { [Bind("isSyntheticDirection")] get; }

		// @property (readonly, nonatomic) NMALaneInformationRecommendationState recommendationState;
		[Export("recommendationState")]
		NMALaneInformationRecommendationState RecommendationState { get; }

		// @property (readonly, getter = isRegular, nonatomic) BOOL regular;
		[Export("regular")]
		bool Regular { [Bind("isRegular")] get; }

		// @property (readonly, getter = isHov, nonatomic) BOOL hov;
		[Export("hov")]
		bool Hov { [Bind("isHov")] get; }

		// @property (readonly, getter = isReversible, nonatomic) BOOL reversible;
		[Export("reversible")]
		bool Reversible { [Bind("isReversible")] get; }

		// @property (readonly, getter = isExpress, nonatomic) BOOL express;
		[Export("express")]
		bool Express { [Bind("isExpress")] get; }

		// @property (readonly, getter = isAcceleration, nonatomic) BOOL acceleration;
		[Export("acceleration")]
		bool Acceleration { [Bind("isAcceleration")] get; }

		// @property (readonly, getter = isDeceleration, nonatomic) BOOL deceleration;
		[Export("deceleration")]
		bool Deceleration { [Bind("isDeceleration")] get; }

		// @property (readonly, getter = isAuxLane, nonatomic) BOOL auxLane;
		[Export("auxLane")]
		bool AuxLane { [Bind("isAuxLane")] get; }

		// @property (readonly, getter = isSlow, nonatomic) BOOL slow;
		[Export("slow")]
		bool Slow { [Bind("isSlow")] get; }

		// @property (readonly, getter = isPassing, nonatomic) BOOL passing;
		[Export("passing")]
		bool Passing { [Bind("isPassing")] get; }

		// @property (readonly, getter = isRegulatedAccess, nonatomic) BOOL regulatedAccess;
		[Export("regulatedAccess")]
		bool RegulatedAccess { [Bind("isRegulatedAccess")] get; }

		// @property (readonly, getter = isDriveableShoulder, nonatomic) BOOL driveableShoulder;
		[Export("driveableShoulder")]
		bool DriveableShoulder { [Bind("isDriveableShoulder")] get; }

		// @property (readonly, getter = isTurn, nonatomic) BOOL turn;
		[Export("turn")]
		bool Turn { [Bind("isTurn")] get; }

		// @property (readonly, getter = isCenterTurn, nonatomic) BOOL centerTurn;
		[Export("centerTurn")]
		bool CenterTurn { [Bind("isCenterTurn")] get; }

		// @property (readonly, getter = isTruckParking, nonatomic) BOOL truckParking;
		[Export("truckParking")]
		bool TruckParking { [Bind("isTruckParking")] get; }

		// @property (readonly, nonatomic) NMALaneInformationMarkingType dividerMarking;
		[Export("dividerMarking")]
		NMALaneInformationMarkingType DividerMarking { get; }

		// @property (readonly, nonatomic) NMALaneInformationMarkingType centerMarking;
		[Export("centerMarking")]
		NMALaneInformationMarkingType CenterMarking { get; }

		// @property (readonly, nonatomic) NSUInteger speedLimit;
		[Export("speedLimit")]
		nuint SpeedLimit { get; }

		// @property (readonly, nonatomic) NSUInteger heightRestriction;
		[Export("heightRestriction")]
		nuint HeightRestriction { get; }

		// @property (readonly, nonatomic) NSUInteger width;
		[Export("width")]
		nuint Width { get; }

		// @property (readonly, nonatomic) NMALaneInformationCrossingRestriction crossingRestriction;
		[Export("crossingRestriction")]
		NMALaneInformationCrossingRestriction CrossingRestriction { get; }
	}

	// @interface NMANavigationManagerVoicePromptOptions (NMANavigationManager)
	[Category]
	[BaseType(typeof(NMANavigationManager))]
	interface NMANavigationManager_NMANavigationManagerVoicePromptOptions
	{
		// -(void)setMinimumDistance:(NSInteger)minimumDistance fromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("setMinimumDistance:fromPreviousManeuverForVoicePromptType:roadType:")]
		void SetMinimumDistanceFromPreviousManeuverForVoicePromptType(nint minimumDistance, NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(NSInteger)minimumDistanceFromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("minimumDistanceFromPreviousManeuverForVoicePromptType:roadType:")]
		nint MinimumDistanceFromPreviousManeuverForVoicePromptType(NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(void)setMaximumDistance:(NSInteger)maximumDistance fromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("setMaximumDistance:fromPreviousManeuverForVoicePromptType:roadType:")]
		void SetMaximumDistanceFromPreviousManeuverForVoicePromptType(nint maximumDistance, NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(NSInteger)maximumDistanceFromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("maximumDistanceFromPreviousManeuverForVoicePromptType:roadType:")]
		nint MaximumDistanceFromPreviousManeuverForVoicePromptType(NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(void)setMinimumDistance:(NSInteger)minimumDistance toUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("setMinimumDistance:toUpcomingManeuverForVoicePromptType:roadType:")]
		void SetMinimumDistanceToUpcomingManeuverForVoicePromptType(nint minimumDistance, NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(NSInteger)minimumDistanceToUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("minimumDistanceToUpcomingManeuverForVoicePromptType:roadType:")]
		nint MinimumDistanceToUpcomingManeuverForVoicePromptType(NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(void)setMaximumDistance:(NSInteger)maximumDistance toUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("setMaximumDistance:toUpcomingManeuverForVoicePromptType:roadType:")]
		void SetMaximumDistanceToUpcomingManeuverForVoicePromptType(nint maximumDistance, NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(NSInteger)maximumDistanceToUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("maximumDistanceToUpcomingManeuverForVoicePromptType:roadType:")]
		nint MaximumDistanceToUpcomingManeuverForVoicePromptType(NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(void)setMinimumTimeInterval:(NSTimeInterval)minimumTime fromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("setMinimumTimeInterval:fromPreviousManeuverForVoicePromptType:roadType:")]
		void SetMinimumTimeIntervalFromPreviousManeuverForVoicePromptType(double minimumTime, NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(NSTimeInterval)minimumTimeFromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("minimumTimeFromPreviousManeuverForVoicePromptType:roadType:")]
		double MinimumTimeFromPreviousManeuverForVoicePromptType(NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(void)setMaximumTimeInterval:(NSTimeInterval)maximumTime fromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("setMaximumTimeInterval:fromPreviousManeuverForVoicePromptType:roadType:")]
		void SetMaximumTimeIntervalFromPreviousManeuverForVoicePromptType(double maximumTime, NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(NSTimeInterval)maximumTimeFromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("maximumTimeFromPreviousManeuverForVoicePromptType:roadType:")]
		double MaximumTimeFromPreviousManeuverForVoicePromptType(NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(void)setMinimumTimeInterval:(NSTimeInterval)minimumTime toUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("setMinimumTimeInterval:toUpcomingManeuverForVoicePromptType:roadType:")]
		void SetMinimumTimeIntervalToUpcomingManeuverForVoicePromptType(double minimumTime, NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(NSTimeInterval)minimumTimeToUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("minimumTimeToUpcomingManeuverForVoicePromptType:roadType:")]
		double MinimumTimeToUpcomingManeuverForVoicePromptType(NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(void)setMaximumTimeInterval:(NSTimeInterval)maximumTime toUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("setMaximumTimeInterval:toUpcomingManeuverForVoicePromptType:roadType:")]
		void SetMaximumTimeIntervalToUpcomingManeuverForVoicePromptType(double maximumTime, NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(NSTimeInterval)maximumTimeToUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("maximumTimeToUpcomingManeuverForVoicePromptType:roadType:")]
		double MaximumTimeToUpcomingManeuverForVoicePromptType(NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(void)setTimeBasedDistance:(NSInteger)distance toUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("setTimeBasedDistance:toUpcomingManeuverForVoicePromptType:roadType:")]
		void SetTimeBasedDistanceToUpcomingManeuverForVoicePromptType(nint distance, NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(NSInteger)timeBasedDistanceToUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType roadType:(NMANavigationRoadType)roadType;
		[Export("timeBasedDistanceToUpcomingManeuverForVoicePromptType:roadType:")]
		nint TimeBasedDistanceToUpcomingManeuverForVoicePromptType(NMANavigationVoicePromptType voicePromptType, NMANavigationRoadType roadType);

		// -(void)resetAnnouncementRules;
		[Export("resetAnnouncementRules")]
		void ResetAnnouncementRules();
	}

	// @protocol NMARoutingZoneWarnerDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMARoutingZoneWarnerDelegate
	{
		// @optional -(void)routingZoneWarner:(NMARoutingZoneWarner * _Nonnull)routingZoneWarner didDetectRoutingZone:(NMARoutingZoneNotification * _Nonnull)notification;
		[Export("routingZoneWarner:didDetectRoutingZone:")]
		void DidDetectRoutingZone(NMARoutingZoneWarner routingZoneWarner, NMARoutingZoneNotification notification);

		// @optional -(void)routingZoneWarner:(NMARoutingZoneWarner * _Nonnull)routingZoneWarner didUpdateRoutingZone:(NSArray<NMARoutingZone *> * _Nullable)routingZones;
		[Export("routingZoneWarner:didUpdateRoutingZone:")]
		void DidUpdateRoutingZone(NMARoutingZoneWarner routingZoneWarner, [NullAllowed] NMARoutingZone[] routingZones);
	}

	// @interface NMARoutingZoneWarner : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARoutingZoneWarner
	{
		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMARoutingZoneWarnerDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMARoutingZoneWarnerDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// +(NSArray<NMARoutingZone *> * _Nullable)routingZonesForRoadElement:(NMARoadElement * _Nonnull)roadElement;
		[Static]
		[Export("routingZonesForRoadElement:")]
		[return: NullAllowed]
		NMARoutingZone[] RoutingZonesForRoadElement(NMARoadElement roadElement);

		// +(NSArray<NMARoutingZone *> * _Nullable)routingZonesForRoadElement:(NMARoadElement * _Nonnull)roadElement routingMode:(NMARoutingMode * _Nonnull)routingMode;
		[Static]
		[Export("routingZonesForRoadElement:routingMode:")]
		[return: NullAllowed]
		NMARoutingZone[] RoutingZonesForRoadElement(NMARoadElement roadElement, NMARoutingMode routingMode);

		// -(void)start;
		[Export("start")]
		void Start();

		// -(void)stop;
		[Export("stop")]
		void Stop();
	}

	// @protocol NMASafetySpotWarnerDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMASafetySpotWarnerDelegate
	{
		// @optional -(void)safetySpotWarner:(NMASafetySpotWarner * _Nonnull)safetySpotWarner didDetectSafetySpot:(NMASafetySpotNotification * _Nonnull)safetySpotNotification;
		[Export("safetySpotWarner:didDetectSafetySpot:")]
		void DidDetectSafetySpot(NMASafetySpotWarner safetySpotWarner, NMASafetySpotNotification safetySpotNotification);
	}

	// @interface NMASafetySpotWarner : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASafetySpotWarner
	{
		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMASafetySpotWarnerDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMASafetySpotWarnerDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// -(void)start;
		[Export("start")]
		void Start();

		// -(void)stop;
		[Export("stop")]
		void Stop();

		// -(BOOL)isSafetySpotNotificationInfoAhead:(NMASafetySpotNotificationInfo * _Nonnull)safetySpotNotificationInfo;
		[Export("isSafetySpotNotificationInfoAhead:")]
		bool IsSafetySpotNotificationInfoAhead(NMASafetySpotNotificationInfo safetySpotNotificationInfo);
	}

	// @protocol NMASchoolZoneWarnerDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMASchoolZoneWarnerDelegate
	{
		// @optional -(void)schoolZoneWarner:(NMASchoolZoneWarner * _Nonnull)schoolZoneWarner didDetectSchoolZone:(NMASchoolZoneNotification * _Nonnull)schoolZoneNotification;
		[Export("schoolZoneWarner:didDetectSchoolZone:")]
		void DidDetectSchoolZone(NMASchoolZoneWarner schoolZoneWarner, NMASchoolZoneNotification schoolZoneNotification);

		// @optional -(void)schoolZoneWarner:(NMASchoolZoneWarner * _Nonnull)schoolZoneWarner didUpdateSchoolZone:(NMASchoolZoneInfo * _Nonnull)schoolZoneInfo;
		[Export("schoolZoneWarner:didUpdateSchoolZone:")]
		void DidUpdateSchoolZone(NMASchoolZoneWarner schoolZoneWarner, NMASchoolZoneInfo schoolZoneInfo);
	}

	// @interface NMASchoolZoneWarner : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASchoolZoneWarner
	{
		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMASchoolZoneWarnerDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMASchoolZoneWarnerDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// +(NMASchoolZoneInfo * _Nullable)schoolZoneInfoForRoadElement:(NMARoadElement * _Nonnull)roadElement;
		[Static]
		[Export("schoolZoneInfoForRoadElement:")]
		[return: NullAllowed]
		NMASchoolZoneInfo SchoolZoneInfoForRoadElement(NMARoadElement roadElement);

		// +(NMASchoolZoneInfo * _Nullable)schoolZoneInfoForRoadElement:(NMARoadElement * _Nonnull)roadElement time:(NSDate * _Nonnull)time;
		[Static]
		[Export("schoolZoneInfoForRoadElement:time:")]
		[return: NullAllowed]
		NMASchoolZoneInfo SchoolZoneInfoForRoadElement(NMARoadElement roadElement, NSDate time);

		// -(void)start;
		[Export("start")]
		void Start();

		// -(void)stop;
		[Export("stop")]
		void Stop();
	}

	// @protocol NMATrafficWarnerDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMATrafficWarnerDelegate
	{
		// @optional -(void)trafficWarner:(NMATrafficWarner * _Nonnull)trafficWarner didDetectTraffic:(NMATrafficNotification * _Nonnull)trafficNotification;
		[Export("trafficWarner:didDetectTraffic:")]
		void DidDetectTraffic(NMATrafficWarner trafficWarner, NMATrafficNotification trafficNotification);
	}

	// @interface NMATrafficWarner : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATrafficWarner
	{
		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMATrafficWarnerDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMATrafficWarnerDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// -(void)start;
		[Export("start")]
		void Start();

		// -(void)stop;
		[Export("stop")]
		void Stop();

		// -(void)clear;
		[Export("clear")]
		void Clear();

		// -(NMATrafficNotification * _Nullable)trafficNotificationOnCurrentRoute;
		[NullAllowed, Export("trafficNotificationOnCurrentRoute")]
		//[Verify(MethodToProperty)]
		NMATrafficNotification TrafficNotificationOnCurrentRoute { get; }

		// -(NMATrafficNotification * _Nullable)trafficNotificationOnRoute:(NMARoute * _Nonnull)route;
		[Export("trafficNotificationOnRoute:")]
		[return: NullAllowed]
		NMATrafficNotification TrafficNotificationOnRoute(NMARoute route);

		// -(BOOL)isTrafficNotificationAhead:(NMATrafficNotification * _Nonnull)trafficNotification;
		[Export("isTrafficNotificationAhead:")]
		bool IsTrafficNotificationAhead(NMATrafficNotification trafficNotification);

		// -(BOOL)isTrafficNotification:(NMATrafficNotification * _Nonnull)trafficNotification onRoute:(NMARoute * _Nonnull)route;
		[Export("isTrafficNotification:onRoute:")]
		bool IsTrafficNotification(NMATrafficNotification trafficNotification, NMARoute route);
	}

	// @interface NMAVoicePackage : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVoicePackage
	{
		// @property (readonly, nonatomic) NSUInteger packageId;
		[Export("packageId")]
		nuint PackageId { get; }

		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NMAVoiceGender gender;
		[Export("gender")]
		NMAVoiceGender Gender { get; }

		// @property (readonly, nonatomic) NSString * _Nullable language;
		[NullAllowed, Export("language")]
		string Language { get; }

		// @property (readonly, nonatomic) NSString * _Nullable localizedLanguage;
		[NullAllowed, Export("localizedLanguage")]
		string LocalizedLanguage { get; }

		// @property (readonly, nonatomic) NSString * _Nullable languageCode;
		[NullAllowed, Export("languageCode")]
		string LanguageCode { get; }

		// @property (readonly, getter = isUpdateAvailable, nonatomic) BOOL updateAvailable;
		[Export("updateAvailable")]
		bool UpdateAvailable { [Bind("isUpdateAvailable")] get; }

		// @property (readonly, getter = isInstalled, nonatomic) BOOL installed;
		[Export("installed")]
		bool Installed { [Bind("isInstalled")] get; }

		// @property (readonly, nonatomic) float downloadSize;
		[Export("downloadSize")]
		float DownloadSize { get; }

		// @property (readonly, nonatomic) float installationSize;
		[Export("installationSize")]
		float InstallationSize { get; }

		// @property (readonly, getter = isRemovable, nonatomic) BOOL removable;
		[Export("removable")]
		bool Removable { [Bind("isRemovable")] get; }

		// @property (readonly, nonatomic) NSString * _Nullable quality;
		[NullAllowed, Export("quality")]
		string Quality { get; }

		// @property (readonly, getter = isTts, nonatomic) BOOL tts;
		[Export("tts")]
		bool Tts { [Bind("isTts")] get; }

		// @property (readonly, getter = isTtsLanguageAvailable, nonatomic) BOOL ttsLanguageAvailable;
		[Export("ttsLanguageAvailable")]
		bool TtsLanguageAvailable { [Bind("isTtsLanguageAvailable")] get; }

		// @property (readonly, nonatomic) NSString * _Nullable localizedGender;
		[NullAllowed, Export("localizedGender")]
		string LocalizedGender { get; }

		// @property (readonly, nonatomic) NSString * _Nullable localizedQuality;
		[NullAllowed, Export("localizedQuality")]
		string LocalizedQuality { get; }

		// @property (readonly, nonatomic) NSString * _Nullable localizedType;
		[NullAllowed, Export("localizedType")]
		string LocalizedType { get; }

		// @property (readonly, nonatomic) NSString * _Nullable marcCode;
		[NullAllowed, Export("marcCode")]
		string MarcCode { get; }

		// @property (readonly, nonatomic) NSString * _Nullable version;
		[NullAllowed, Export("version")]
		string Version { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NSString *> * _Nullable customAttributes;
		[NullAllowed, Export("customAttributes")]
		NSDictionary<NSString, NSString> CustomAttributes { get; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMAVoiceCatalogErrorDomain;
		[Field("NMAVoiceCatalogErrorDomain", "__Internal")]
		NSString NMAVoiceCatalogErrorDomain { get; }
	}

	// @protocol NMAVoiceCatalogDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAVoiceCatalogDelegate
	{
		// @optional -(void)voiceCatalog:(NMAVoiceCatalog * _Nonnull)voiceCatalog didUpdateWithError:(NSError * _Nullable)error;
		[Export("voiceCatalog:didUpdateWithError:")]
		void DidUpdateWithError(NMAVoiceCatalog voiceCatalog, [NullAllowed] NSError error);

		// @optional -(void)voiceCatalog:(NMAVoiceCatalog * _Nonnull)voiceCatalog didInstallPackage:(NMAVoicePackage * _Nonnull)package withError:(NSError * _Nullable)error;
		[Export("voiceCatalog:didInstallPackage:withError:")]
		void DidInstallPackage(NMAVoiceCatalog voiceCatalog, NMAVoicePackage package, [NullAllowed] NSError error);

		// @optional -(void)voiceCatalog:(NMAVoiceCatalog * _Nonnull)voiceCatalog didUpdateProgress:(float)progress forPackage:(NMAVoicePackage * _Nonnull)package;
		[Export("voiceCatalog:didUpdateProgress:forPackage:")]
		void DidUpdateProgress(NMAVoiceCatalog voiceCatalog, float progress, NMAVoicePackage package);

		// @optional -(void)voiceCatalog:(NMAVoiceCatalog * _Nonnull)voiceCatalog didUncompressProgress:(float)progress forPackage:(NMAVoicePackage * _Nonnull)package;
		[Export("voiceCatalog:didUncompressProgress:forPackage:")]
		void DidUncompressProgress(NMAVoiceCatalog voiceCatalog, float progress, NMAVoicePackage package);
	}

	// @interface NMAVoiceCatalog : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVoiceCatalog
	{
		// +(NMAVoiceCatalog * _Nullable)sharedVoiceCatalog;
		[Static]
		[NullAllowed, Export("sharedVoiceCatalog")]
		//[Verify(MethodToProperty)]
		NMAVoiceCatalog SharedVoiceCatalog { get; }

		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMAVoiceCatalogDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMAVoiceCatalogDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// @property (readonly, getter = isBusy, nonatomic) BOOL busy;
		[Export("busy")]
		bool Busy { [Bind("isBusy")] get; }

		// @property (readonly, nonatomic) NSArray<NMAVoicePackage *> * _Nonnull installedVoicePackages;
		[Export("installedVoicePackages")]
		NMAVoicePackage[] InstalledVoicePackages { get; }

		// @property (readonly, nonatomic) NSArray<NMAVoicePackage *> * _Nonnull voicePackages;
		[Export("voicePackages")]
		NMAVoicePackage[] VoicePackages { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable lastUpdate;
		[NullAllowed, Export("lastUpdate")]
		NSDate LastUpdate { get; }

		// -(BOOL)updateVoiceCatalog;
		[Export("updateVoiceCatalog")]
		//[Verify(MethodToProperty)]
		bool UpdateVoiceCatalog { get; }

		// -(NMAVoicePackage * _Nullable)voicePackageWithId:(NSUInteger)packageId;
		[Export("voicePackageWithId:")]
		[return: NullAllowed]
		NMAVoicePackage VoicePackageWithId(nuint packageId);

		// -(BOOL)installVoicePackage:(NMAVoicePackage * _Nonnull)package;
		[Export("installVoicePackage:")]
		bool InstallVoicePackage(NMAVoicePackage package);

		// -(BOOL)uninstallVoicePackage:(NMAVoicePackage * _Nonnull)package;
		[Export("uninstallVoicePackage:")]
		bool UninstallVoicePackage(NMAVoicePackage package);

		// -(void)cancel;
		[Export("cancel")]
		void Cancel();
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull kNMAPlatformDataRequestErrorDomain;
		[Field("kNMAPlatformDataRequestErrorDomain", "__Internal")]
		NSString kNMAPlatformDataRequestErrorDomain { get; }
	}

	// Do not bind "Platform Data Extensions" because NMAPlatformDataItemCollection implements the NSFastEnumeration which is not easy bindable.
	// So for now I skip it until I really need it :)
	/*
	// @interface NMAPlatformDataItem : NSObject <NSCopying>
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlatformDataItem : INSCopying
	{
		// @property (readonly, nonatomic, weak) NSString * _Nullable linkId;
		[NullAllowed, Export("linkId", ArgumentSemantic.Weak)]
		string LinkId { get; }

		// @property (readonly, nonatomic, weak) NSArray<NMAGeoCoordinates *> * _Nullable coordinates;
		[NullAllowed, Export("coordinates", ArgumentSemantic.Weak)]
		NMAGeoCoordinates[] Coordinates { get; }

		// @property (readonly, nonatomic) float linkLengthMeter;
		[Export("linkLengthMeter")]
		float LinkLengthMeter { get; }

		// @property (readonly, nonatomic, weak) NSArray<NSString *> * _Nullable linkIds;
		[NullAllowed, Export("linkIds", ArgumentSemantic.Weak)]
		string[] LinkIds { get; }

		// @property (readonly, nonatomic) NMAPlatformDataConditionType conditionType;
		[Export("conditionType")]
		NMAPlatformDataConditionType ConditionType { get; }

		// @property (readonly, nonatomic) NMAPlatformDataVehicleType vehicleTypes;
		[Export("vehicleTypes")]
		NMAPlatformDataVehicleType VehicleTypes { get; }

		// @property (readonly, nonatomic) NSInteger averageHeightCm;
		[Export("averageHeightCm")]
		nint AverageHeightCm { get; }

		// -(NSString * _Nullable)objectForKeyedSubscript:(NSString * _Nonnull)key;
		[Export("objectForKeyedSubscript:")]
		[return: NullAllowed]
		string ObjectForKeyedSubscript(string key);

		// -(NSArray<NSString *> * _Nullable)allKeys;
		[NullAllowed, Export("allKeys")]
		//[Verify(MethodToProperty)]
		string[] AllKeys { get; }

		// -(NSArray<NSString *> * _Nullable)allValues;
		[NullAllowed, Export("allValues")]
		//[Verify(MethodToProperty)]
		string[] AllValues { get; }

		// -(void)enumerateKeysAndObjectsUsingBlock:(void (^ _Nonnull)(NSString * _Nonnull, NSString * _Nonnull, BOOL * _Nonnull))block;
		[Export("enumerateKeysAndObjectsUsingBlock:")]
		unsafe void EnumerateKeysAndObjectsUsingBlock(Action<NSString, NSString, bool> block);

		// -(NSDictionary<NSString *,NSString *> * _Nullable)extract;
		[NullAllowed, Export("extract")]
		//[Verify(MethodToProperty)]
		NSDictionary<NSString, NSString> Extract { get; }

		// @property (readonly) NSUInteger count;
		[Export("count")]
		nuint Count { get; }
	}

	// @interface NMAPlatformDataItemCollection : NSObject <NSFastEnumeration>
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlatformDataItemCollection : NSFastEnumeration
	{
		// -(NMAPlatformDataItem * _Nonnull)objectAtIndexedSubscript:(NSUInteger)index;
		[Export("objectAtIndexedSubscript:")]
		NMAPlatformDataItem ObjectAtIndexedSubscript(nuint index);

		// -(NSEnumerator * _Nonnull)objectEnumerator;
		[Export("objectEnumerator")]
		//[Verify(MethodToProperty)]
		NSEnumerator ObjectEnumerator { get; }

		// -(NSArray<NSDictionary<NSString *,NSString *> *> * _Nonnull)extract;
		[Export("extract")]
		//[Verify(MethodToProperty)]
		NSDictionary<NSString, NSString>[] Extract { get; }

		// @property (readonly) NSUInteger count;
		[Export("count")]
		nuint Count { get; }
	}

	// typedef void (^NMAPlatformDataRequestCompletionBlock)(NMAPlatformDataRequest * _Nonnull, NMAPlatformDataResult * _Nonnull, NSError * _Nullable);
	delegate void NMAPlatformDataRequestCompletionBlock(NMAPlatformDataRequest arg0, NMAPlatformDataResult arg1, [NullAllowed] NSError arg2);

	// @protocol NMAPlatformDataRequestListener <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAPlatformDataRequestListener
	{
		// @required -(void)request:(NMAPlatformDataRequest * _Nonnull)request didCompleteWithResult:(NMAPlatformDataResult * _Nonnull)result error:(NSError * _Nullable)error;
		[Abstract]
		[Export("request:didCompleteWithResult:error:")]
		void DidCompleteWithResult(NMAPlatformDataRequest request, NMAPlatformDataResult result, [NullAllowed] NSError error);
	}

	// @interface NMAPlatformDataRequest : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlatformDataRequest
	{
		// -(instancetype _Nullable)initWithLayers:(NSSet<NSString *> * _Nonnull)layers geoBoundingBox:(NMAGeoBoundingBox * _Nonnull)geoBoundingBox;
		[Export("initWithLayers:geoBoundingBox:")]
		IntPtr Constructor(NSSet<NSString> layers, NMAGeoBoundingBox geoBoundingBox);

		// -(instancetype _Nullable)initWithLayers:(NSSet<NSString *> * _Nonnull)layers linkIds:(NSSet<NSNumber *> * _Nonnull)linkIds;
		[Export("initWithLayers:linkIds:")]
		IntPtr Constructor(NSSet<NSString> layers, NSSet<NSNumber> linkIds);

		// -(instancetype _Nullable)initWithStaticLayer:(NSString * _Nonnull)layer;
		[Export("initWithStaticLayer:")]
		IntPtr Constructor(string layer);

		// -(void)startWithListener:(id<NMAPlatformDataRequestListener> _Nonnull)requestListener;
		[Export("startWithListener:")]
		void StartWithListener(NMAPlatformDataRequestListener requestListener);

		// -(void)startWithBlock:(NMAPlatformDataRequestCompletionBlock _Nonnull)block;
		[Export("startWithBlock:")]
		void StartWithBlock(NMAPlatformDataRequestCompletionBlock block);
	}

	// @interface NMAPlatformDataResult : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlatformDataResult
	{
		// -(NMAPlatformDataItemCollection *)objectForKeyedSubscript:(NSString *)key;
		[Export("objectForKeyedSubscript:")]
		NMAPlatformDataItemCollection ObjectForKeyedSubscript(string key);

		// -(NSArray<NSString *> *)allKeys;
		[Export("allKeys")]
		//[Verify(MethodToProperty)]
		string[] AllKeys { get; }

		// -(NSArray<NMAPlatformDataItemCollection *> *)allValues;
		[Export("allValues")]
		//[Verify(MethodToProperty)]
		NMAPlatformDataItemCollection[] AllValues { get; }

		// -(void)enumerateKeysAndObjectsUsingBlock:(void (^)(NSString *, NMAPlatformDataItemCollection *, BOOL *))block;
		[Export("enumerateKeysAndObjectsUsingBlock:")]
		unsafe void EnumerateKeysAndObjectsUsingBlock(Action<NSString, NMAPlatformDataItemCollection, bool> block);

		// -(NSDictionary<NSString *,NSArray<NSDictionary<NSString *,NSString *> *> *> *)extract;
		[Export("extract")]
		//[Verify(MethodToProperty)]
		NSDictionary<NSString, NSArray<NSDictionary<NSString, NSString>>> Extract { get; }

		// @property (readonly) NSUInteger count;
		[Export("count")]
		nuint Count { get; }
	}
	*/
	// @interface NMAAddress : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAAddress
	{
		// @property (nonatomic) NSString * _Nullable floorNumber;
		[NullAllowed, Export("floorNumber")]
		string FloorNumber { get; set; }

		// @property (nonatomic) NSString * _Nullable houseNumber;
		[NullAllowed, Export("houseNumber")]
		string HouseNumber { get; set; }

		// @property (nonatomic) NSString * _Nullable suiteNumberOrName;
		[NullAllowed, Export("suiteNumberOrName")]
		string SuiteNumberOrName { get; set; }

		// @property (nonatomic) NSString * _Nullable street;
		[NullAllowed, Export("street")]
		string Street { get; set; }

		// @property (nonatomic) NSString * _Nullable district;
		[NullAllowed, Export("district")]
		string District { get; set; }

		// @property (nonatomic) NSString * _Nullable county;
		[NullAllowed, Export("county")]
		string County { get; set; }

		// @property (nonatomic) NSString * _Nullable city;
		[NullAllowed, Export("city")]
		string City { get; set; }

		// @property (nonatomic) NSString * _Nullable state;
		[NullAllowed, Export("state")]
		string State { get; set; }

		// @property (nonatomic) NSString * _Nullable postalCode;
		[NullAllowed, Export("postalCode")]
		string PostalCode { get; set; }

		// @property (nonatomic) NSString * _Nullable countryCode;
		[NullAllowed, Export("countryCode")]
		string CountryCode { get; set; }

		// @property (nonatomic) NSString * _Nullable countryName;
		[NullAllowed, Export("countryName")]
		string CountryName { get; set; }

		// @property (nonatomic) NSString * _Nullable label;
		[NullAllowed, Export("label")]
		string Label { get; set; }

		// @property (nonatomic) NSString * _Nullable formattedAddress;
		[NullAllowed, Export("formattedAddress")]
		string FormattedAddress { get; set; }

		// -(NSDictionary<NSString *,NSString *> * _Nonnull)additionalData;
		[Export("additionalData")]
		//[Verify(MethodToProperty)]
		NSDictionary<NSString, NSString> AdditionalData { get; }
	}

	// @interface NMAAddressFilter : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAAddressFilter
	{
		// @property (nonatomic) NSString * _Nullable countryCode;
		[NullAllowed, Export("countryCode")]
		string CountryCode { get; set; }

		// @property (nonatomic) NSString * _Nullable stateCode;
		[NullAllowed, Export("stateCode")]
		string StateCode { get; set; }

		// @property (nonatomic) NSString * _Nullable county;
		[NullAllowed, Export("county")]
		string County { get; set; }

		// @property (nonatomic) NSString * _Nullable district;
		[NullAllowed, Export("district")]
		string District { get; set; }

		// @property (nonatomic) NSString * _Nullable city;
		[NullAllowed, Export("city")]
		string City { get; set; }

		// @property (nonatomic) NSString * _Nullable zipCode;
		[NullAllowed, Export("zipCode")]
		string ZipCode { get; set; }
	}

	// @interface NMAAutoSuggest : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAAutoSuggest
	{
		// @property (readonly, nonatomic) NSString * _Nullable url;
		[NullAllowed, Export("url")]
		string Url { get; }

		// @property (readonly, nonatomic) NSString * _Nullable title;
		[NullAllowed, Export("title")]
		string Title { get; }

		// @property (readonly, nonatomic) NSString * _Nullable highlightedTitle;
		[NullAllowed, Export("highlightedTitle")]
		string HighlightedTitle { get; }

		// @property (readonly, nonatomic) NMAAutoSuggestType type;
		[Export("type")]
		NMAAutoSuggestType Type { get; }
	}

	// @interface NMAAutoSuggestPlace : NMAAutoSuggest
	[BaseType(typeof(NMAAutoSuggest))]
	[DisableDefaultCtor]
	interface NMAAutoSuggestPlace
	{
		// @property (readonly, nonatomic) NSString * _Nullable vicinityDescription;
		[NullAllowed, Export("vicinityDescription")]
		string VicinityDescription { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable position;
		[NullAllowed, Export("position")]
		NMAGeoCoordinates Position { get; }

		// @property (readonly, nonatomic) NSString * _Nullable category;
		[NullAllowed, Export("category")]
		string Category { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nullable boundingBox;
		[NullAllowed, Export("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// -(NMAPlaceRequest * _Nonnull)placeDetailsRequest;
		[Export("placeDetailsRequest")]
		//[Verify(MethodToProperty)]
		NMAPlaceRequest PlaceDetailsRequest { get; }
	}

	// @interface NMAAutoSuggestionRequest : NMARequest
	[BaseType(typeof(NMARequest))]
	interface NMAAutoSuggestionRequest
	{
		// @property (nonatomic) NMATextFormat textFormat;
		[Export("textFormat", ArgumentSemantic.Assign)]
		NMATextFormat TextFormat { get; set; }
	}

	// @interface NMAAutoSuggestQuery : NMAAutoSuggest
	[BaseType(typeof(NMAAutoSuggest))]
	[DisableDefaultCtor]
	interface NMAAutoSuggestQuery
	{
		// @property (readonly, nonatomic) NSString * _Nullable completion;
		[NullAllowed, Export("completion")]
		string Completion { get; }

		// -(NMAAutoSuggestionRequest * _Nonnull)autoSuggestionRequest;
		[Export("autoSuggestionRequest")]
		//[Verify(MethodToProperty)]
		NMAAutoSuggestionRequest AutoSuggestionRequest { get; }
	}

	// @interface NMAAutoSuggestSearch : NMAAutoSuggest
	[BaseType(typeof(NMAAutoSuggest))]
	[DisableDefaultCtor]
	interface NMAAutoSuggestSearch
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable position;
		[NullAllowed, Export("position")]
		NMAGeoCoordinates Position { get; }

		// @property (readonly, nonatomic) NSString * _Nullable category;
		[NullAllowed, Export("category")]
		string Category { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nullable boundingBox;
		[NullAllowed, Export("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// -(NMADiscoveryRequest * _Nonnull)suggestedSearchRequest;
		[Export("suggestedSearchRequest")]
		//[Verify(MethodToProperty)]
		NMADiscoveryRequest SuggestedSearchRequest { get; }
	}

	// @interface NMACategory : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMACategory
	{
		// @property (readonly, nonatomic) NSString * _Nullable uniqueId;
		[NullAllowed, Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NSString * _Nullable iconUrl;
		[NullAllowed, Export("iconUrl")]
		string IconUrl { get; }

		// @property (readonly, nonatomic) NMACategory * _Nullable parentCategory;
		[NullAllowed, Export("parentCategory")]
		NMACategory ParentCategory { get; }

		// @property (readonly, nonatomic) NSArray<NMACategory *> * _Nonnull subCategories;
		[Export("subCategories")]
		NMACategory[] SubCategories { get; }
	}

	// @interface NMACategoryFilter : NSObject
	[BaseType(typeof(NSObject))]
	interface NMACategoryFilter
	{
		// -(void)addCategoryFilterFromType:(NMACategoryFilterType)categoryFilterType;
		[Export("addCategoryFilterFromType:")]
		void AddCategoryFilterFromType(NMACategoryFilterType categoryFilterType);

		// -(void)addCategoryFilterFromUniqueId:(NSString * _Nonnull)uniqueId;
		[Export("addCategoryFilterFromUniqueId:")]
		void AddCategoryFilterFromUniqueId(string uniqueId);

		// -(NSString * _Nonnull)toString;
		[Export("toString")]
		//[Verify(MethodToProperty)]
		string ToString { get; }
	}

	// @interface NMACategoryGraphRequest : NMARequest
	[BaseType(typeof(NMARequest))]
	interface NMACategoryGraphRequest
	{
	}

	// @interface NMAContactDetail : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAContactDetail
	{
		// @property (readonly, nonatomic) NSString * _Nullable label;
		[NullAllowed, Export("label")]
		string Label { get; }

		// @property (readonly, nonatomic) NSString * _Nullable value;
		[NullAllowed, Export("value")]
		string Value { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull type;
		[Export("type")]
		string Type { get; }
	}

	// @interface NMALink : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMALink : ObjCRuntime.INativeObject
	{
		// @property (readonly, nonatomic) NSString * _Nullable uniqueId;
		[NullAllowed, Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nullable url;
		[NullAllowed, Export("url")]
		string Url { get; }

		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NSString * _Nullable iconUrl;
		[NullAllowed, Export("iconUrl")]
		string IconUrl { get; }
	}

	// @interface NMADiscoveryLink : NMALink
	[BaseType(typeof(NMALink))]
	[DisableDefaultCtor]
	interface NMADiscoveryLink
	{
		// -(NMADiscoveryRequest * _Nonnull)request;
		[Export("request")]
		//[Verify(MethodToProperty)]
		NMADiscoveryRequest Request { get; }
	}

	// @interface NMADiscoveryPage : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMADiscoveryPage
	{
		// @property (readonly, nonatomic) NSInteger available;
		[Export("available")]
		nint Available { get; }

		// @property (readonly, nonatomic) NSInteger offsetCount;
		[Export("offsetCount")]
		nint OffsetCount { get; }

		// @property (readonly, nonatomic) NMADiscoveryRequest * _Nullable nextPageRequest;
		[NullAllowed, Export("nextPageRequest")]
		NMADiscoveryRequest NextPageRequest { get; }

		// @property (readonly, nonatomic) NSArray<NMALink *> * _Nonnull discoveryResults;
		[Export("discoveryResults")]
		NMALink[] DiscoveryResults { get; }
	}

	// @interface NMADiscoveryRequest : NMARequest
	[BaseType(typeof(NMARequest))]
	interface NMADiscoveryRequest
	{
		// @property (nonatomic) NMATextFormat textFormat;
		[Export("textFormat", ArgumentSemantic.Assign)]
		NMATextFormat TextFormat { get; set; }

		// -(void)setSearchAreaWithCenter:(NMAGeoCoordinates * _Nonnull)center radius:(NSUInteger)radius;
		[Export("setSearchAreaWithCenter:radius:")]
		void SetSearchAreaWithCenter(NMAGeoCoordinates center, nuint radius);

		// -(void)addContent:(NSString * _Nonnull)content;
		[Export("addContent:")]
		void AddContent(string content);
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMATransitLinesExtendedAttributeId;
		[Field("NMATransitLinesExtendedAttributeId", "__Internal")]
		NSString NMATransitLinesExtendedAttributeId { get; }

		// extern NSString *const _Nonnull NMATransitDeparturesExtendedAttributeId;
		[Field("NMATransitDeparturesExtendedAttributeId", "__Internal")]
		NSString NMATransitDeparturesExtendedAttributeId { get; }
	}

	// @interface NMAExtendedAttribute : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAExtendedAttribute
	{
		// @property (readonly, nonatomic) NSString * _Nullable uniqueId;
		[NullAllowed, Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nullable label;
		[NullAllowed, Export("label")]
		string Label { get; }

		// @property (readonly, nonatomic) NSString * _Nullable text;
		[NullAllowed, Export("text")]
		string Text { get; }
	}

	// @interface NMAGeocodeRequest : NMARequest
	[BaseType(typeof(NMARequest))]
	interface NMAGeocodeRequest
	{
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const float NMAGeocodeResultInvalidRelevance;
		[Field("NMAGeocodeResultInvalidRelevance", "__Internal")]
		float NMAGeocodeResultInvalidRelevance { get; }
	}

	// @interface NMAGeocodeResult : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAGeocodeResult
	{
		// @property (readonly, nonatomic) NMAPlaceLocation * _Nullable location;
		[NullAllowed, Export("location")]
		NMAPlaceLocation Location { get; }

		// @property (readonly, nonatomic) float relevance;
		[Export("relevance")]
		float Relevance { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NSNumber *> * _Nullable matchQuality;
		[NullAllowed, Export("matchQuality")]
		NSDictionary<NSString, NSNumber> MatchQuality { get; }

		// @property (readonly, nonatomic) NSString * _Nullable matchLevel;
		[NullAllowed, Export("matchLevel")]
		string MatchLevel { get; }
	}

	// @interface NMAReverseGeocodeRequest : NMARequest
	[BaseType(typeof(NMARequest))]
	[DisableDefaultCtor]
	interface NMAReverseGeocodeRequest
	{
	}

	// @interface NMAGeocoder : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAGeocoder
	{
		// +(NMAGeocoder * _Nonnull)sharedGeocoder;
		[Static]
		[Export("sharedGeocoder")]
		//[Verify(MethodToProperty)]
		NMAGeocoder SharedGeocoder { get; }

		// -(NMAReverseGeocodeRequest * _Nonnull)createReverseGeocodeRequestWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)geoCoordinates;
		[Export("createReverseGeocodeRequestWithGeoCoordinates:")]
		NMAReverseGeocodeRequest CreateReverseGeocodeRequestWithGeoCoordinates(NMAGeoCoordinates geoCoordinates);

		// -(NMAReverseGeocodeRequest * _Nonnull)createReverseGeocodeRequestWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)geoCoordinates mode:(NMAReverseGeocodeMode)geocodeMode bearing:(float)bearing;
		[Export("createReverseGeocodeRequestWithGeoCoordinates:mode:bearing:")]
		NMAReverseGeocodeRequest CreateReverseGeocodeRequestWithGeoCoordinates(NMAGeoCoordinates geoCoordinates, NMAReverseGeocodeMode geocodeMode, float bearing);

		// -(NMAGeocodeRequest * _Nonnull)createGeocodeRequestWithQuery:(NSString * _Nullable)query searchArea:(NMAGeoBoundingBox * _Nullable)searchArea;
		[Export("createGeocodeRequestWithQuery:searchArea:")]
		NMAGeocodeRequest CreateGeocodeRequestWithQuery([NullAllowed] string query, [NullAllowed] NMAGeoBoundingBox searchArea);

		// -(NMAGeocodeRequest * _Nonnull)createGeocodeRequestWithQuery:(NSString * _Nullable)query searchRadius:(NSInteger)searchRadius searchCenter:(NMAGeoCoordinates * _Nullable)searchCenter;
		[Export("createGeocodeRequestWithQuery:searchRadius:searchCenter:")]
		NMAGeocodeRequest CreateGeocodeRequestWithQuery([NullAllowed] string query, nint searchRadius, [NullAllowed] NMAGeoCoordinates searchCenter);
	}

	// @interface NMAMedia : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAMedia
	{
		// @property (readonly, nonatomic) NSString * _Nullable attributionText;
		[NullAllowed, Export("attributionText")]
		string AttributionText { get; }

		// @property (readonly, nonatomic) NMALink * _Nullable supplierLink;
		[NullAllowed, Export("supplierLink")]
		NMALink SupplierLink { get; }

		// @property (readonly, nonatomic) NMALink * _Nullable viaLink;
		[NullAllowed, Export("viaLink")]
		NMALink ViaLink { get; }

		// @property (readonly, nonatomic) NMAMediaType type;
		[Export("type")]
		NMAMediaType Type { get; }
	}

	// @interface NMAMediaCollectionPage : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAMediaCollectionPage
	{
		// @property (readonly, nonatomic) NMAMediaType type;
		[Export("type")]
		NMAMediaType Type { get; }

		// @property (readonly, nonatomic) NSInteger available;
		[Export("available")]
		nint Available { get; }

		// @property (readonly, nonatomic) NSInteger offsetCount;
		[Export("offsetCount")]
		nint OffsetCount { get; }

		// @property (readonly, nonatomic) NMAMediaCollectionPageRequest * _Nullable nextPageRequest;
		[NullAllowed, Export("nextPageRequest")]
		NMAMediaCollectionPageRequest NextPageRequest { get; }

		// @property (readonly, nonatomic) NSArray<NMAMedia *> * _Nonnull mediaContents;
		[Export("mediaContents")]
		NMAMedia[] MediaContents { get; }
	}

	// @interface NMAMediaCollectionPageRequest : NMARequest
	[BaseType(typeof(NMARequest))]
	interface NMAMediaCollectionPageRequest
	{
	}

	// @interface NMAMediaEditorial : NMAMedia
	[BaseType(typeof(NMAMedia))]
	[DisableDefaultCtor]
	interface NMAMediaEditorial
	{
		// @property (readonly, nonatomic) NSString * _Nullable description;
		[NullAllowed, Export("description")]
		string Description { get; }

		// @property (readonly, nonatomic) NSString * _Nullable languageCode;
		[NullAllowed, Export("languageCode")]
		string LanguageCode { get; }
	}

	// @interface NMAMediaImage : NMAMedia
	[BaseType(typeof(NMAMedia))]
	[DisableDefaultCtor]
	interface NMAMediaImage
	{
		// @property (readonly, nonatomic) NSString * _Nullable imageSource;
		[NullAllowed, Export("imageSource")]
		string ImageSource { get; }

		// @property (readonly, nonatomic) NSString * _Nullable uniqueId;
		[NullAllowed, Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NMALink * _Nullable user;
		[NullAllowed, Export("user")]
		NMALink User { get; }

		// -(NSString * _Nullable)URLForImageWithWidth:(NSInteger)width height:(NSInteger)height;
		[Export("URLForImageWithWidth:height:")]
		[return: NullAllowed]
		string URLForImageWithWidth(nint width, nint height);
	}

	// @interface NMAMediaRating : NMAMedia
	[BaseType(typeof(NMAMedia))]
	[DisableDefaultCtor]
	interface NMAMediaRating
	{
		// @property (readonly, nonatomic) double average;
		[Export("average")]
		double Average { get; }

		// @property (readonly, nonatomic) NSUInteger count;
		[Export("count")]
		nuint Count { get; }
	}

	// @interface NMAMediaReview : NMAMedia
	[BaseType(typeof(NMAMedia))]
	[DisableDefaultCtor]
	interface NMAMediaReview
	{
		// @property (readonly, nonatomic) NSDate * _Nullable contributionDate;
		[NullAllowed, Export("contributionDate")]
		NSDate ContributionDate { get; }

		// @property (readonly, nonatomic) NSString * _Nullable title;
		[NullAllowed, Export("title")]
		string Title { get; }

		// @property (readonly, nonatomic) double rating;
		[Export("rating")]
		double Rating { get; }

		// @property (readonly, nonatomic) NSString * _Nullable description;
		[NullAllowed, Export("description")]
		string Description { get; }

		// @property (readonly, nonatomic) NSString * _Nullable languageCode;
		[NullAllowed, Export("languageCode")]
		string LanguageCode { get; }

		// @property (readonly, nonatomic) NMALink * _Nullable contributor;
		[NullAllowed, Export("contributor")]
		NMALink Contributor { get; }
	}

	// @interface NMANavigationPosition : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMANavigationPosition
	{
		// @property (readonly, nonatomic) NSString * _Nullable accessType;
		[NullAllowed, Export("accessType")]
		string AccessType { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable position;
		[NullAllowed, Export("position")]
		NMAGeoCoordinates Position { get; }
	}

	// @interface NMAPlace : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlace
	{
		// @property (readonly, nonatomic) NSString * _Nullable uniqueId;
		[NullAllowed, Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nullable viewUrl;
		[NullAllowed, Export("viewUrl")]
		string ViewUrl { get; }

		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NSString *> * _Nullable alternativeNames;
		[NullAllowed, Export("alternativeNames")]
		NSDictionary<NSString, NSString> AlternativeNames { get; }

		// @property (readonly, nonatomic) NMAPlaceLocation * _Nullable location;
		[NullAllowed, Export("location")]
		NMAPlaceLocation Location { get; }

		// @property (readonly, strong) NSArray<NMACategory *> * _Nullable categories;
		[NullAllowed, Export("categories", ArgumentSemantic.Strong)]
		NMACategory[] Categories { get; }

		// @property (readonly, nonatomic) NSString * _Nullable iconUrl;
		[NullAllowed, Export("iconUrl")]
		string IconUrl { get; }

		// @property (readonly, nonatomic, strong) NSArray<NMAContactDetail *> * _Nullable contacts;
		[NullAllowed, Export("contacts", ArgumentSemantic.Strong)]
		NMAContactDetail[] Contacts { get; }

		// @property (readonly, nonatomic) NSString * _Nullable attributionText;
		[NullAllowed, Export("attributionText")]
		string AttributionText { get; }

		// @property (readonly, nonatomic) NMALink * _Nullable supplier;
		[NullAllowed, Export("supplier")]
		NMALink Supplier { get; }

		// @property (readonly, nonatomic) NMARatings * _Nullable userRatings;
		[NullAllowed, Export("userRatings")]
		NMARatings UserRatings { get; }

		// @property (readonly, nonatomic) NSArray<NMAExtendedAttribute *> * _Nullable extendedAttributes;
		[NullAllowed, Export("extendedAttributes")]
		NMAExtendedAttribute[] ExtendedAttributes { get; }

		// @property (readonly, nonatomic) NMAMediaCollectionPage * _Nullable images;
		[NullAllowed, Export("images")]
		NMAMediaCollectionPage Images { get; }

		// @property (readonly, nonatomic) NMAMediaCollectionPage * _Nullable reviews;
		[NullAllowed, Export("reviews")]
		NMAMediaCollectionPage Reviews { get; }

		// @property (readonly, nonatomic) NMAMediaCollectionPage * _Nullable editorials;
		[NullAllowed, Export("editorials")]
		NMAMediaCollectionPage Editorials { get; }

		// @property (readonly, nonatomic) NMAMediaCollectionPage * _Nullable ratings;
		[NullAllowed, Export("ratings")]
		NMAMediaCollectionPage Ratings { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NMALink *> * _Nullable related;
		[NullAllowed, Export("related")]
		NSDictionary<NSString, NMALink> Related { get; }

		// @property (readonly, nonatomic) NMALink * _Nullable reportingLink;
		[NullAllowed, Export("reportingLink")]
		NMALink ReportingLink { get; }

		// -(NSArray<NSString *> * _Nullable)referenceIdentifiersForSource:(NSString * _Nonnull)source;
		[Export("referenceIdentifiersForSource:")]
		[return: NullAllowed]
		string[] ReferenceIdentifiersForSource(string source);
	}

	// @interface NMAPlaceLink : NMALink
	[BaseType(typeof(NMALink))]
	[DisableDefaultCtor]
	interface NMAPlaceLink
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable position;
		[NullAllowed, Export("position")]
		NMAGeoCoordinates Position { get; }

		// @property (readonly, nonatomic) NSInteger distance;
		[Export("distance")]
		nint Distance { get; }

		// @property (readonly, nonatomic) double averageRating;
		[Export("averageRating")]
		double AverageRating { get; }

		// @property (readonly, nonatomic) NMACategory * _Nullable category;
		[NullAllowed, Export("category")]
		NMACategory Category { get; }

		// @property (readonly, nonatomic) NSString * _Nullable vicinityDescription;
		[NullAllowed, Export("vicinityDescription")]
		string VicinityDescription { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nullable boundingBox;
		[NullAllowed, Export("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readonly, nonatomic) BOOL isSponsored;
		[Export("isSponsored")]
		bool IsSponsored { get; }

		// -(NMAPlaceRequest * _Nonnull)detailsRequest;
		[Export("detailsRequest")]
		//[Verify(MethodToProperty)]
		NMAPlaceRequest DetailsRequest { get; }

		// -(NSArray<NSString *> * _Nullable)referenceIdentifiersForSource:(NSString * _Nonnull)source;
		[Export("referenceIdentifiersForSource:")]
		[return: NullAllowed]
		string[] ReferenceIdentifiersForSource(string source);
	}

	// @interface NMAPlaceLocation : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlaceLocation
	{
		// @property (nonatomic) NMAAddress * _Nullable address;
		[NullAllowed, Export("address", ArgumentSemantic.Assign)]
		NMAAddress Address { get; set; }

		// @property (nonatomic) NSString * _Nullable label;
		[NullAllowed, Export("label")]
		string Label { get; set; }

		// @property (nonatomic) NMAGeoCoordinates * _Nullable position;
		[NullAllowed, Export("position", ArgumentSemantic.Assign)]
		NMAGeoCoordinates Position { get; set; }

		// @property (nonatomic) NMAGeoBoundingBox * _Nullable boundingBox;
		[NullAllowed, Export("boundingBox", ArgumentSemantic.Assign)]
		NMAGeoBoundingBox BoundingBox { get; set; }

		// @property (readonly, nonatomic) NSArray<NMANavigationPosition *> * _Nullable accessPoints;
		[NullAllowed, Export("accessPoints")]
		NMANavigationPosition[] AccessPoints { get; }

		// @property (readonly, nonatomic) NSTimeZone * _Nullable timeZone;
		[NullAllowed, Export("timeZone")]
		NSTimeZone TimeZone { get; }

		// -(NSArray<NSString *> * _Nullable)referenceIdentifiersForSource:(NSString * _Nonnull)source;
		[Export("referenceIdentifiersForSource:")]
		[return: NullAllowed]
		string[] ReferenceIdentifiersForSource(string source);
	}

	// @interface NMAPlaceRequest : NMARequest
	[BaseType(typeof(NMARequest))]
	[DisableDefaultCtor]
	interface NMAPlaceRequest
	{
		// @property (nonatomic) NMATextFormat textFormat;
		[Export("textFormat", ArgumentSemantic.Assign)]
		NMATextFormat TextFormat { get; set; }

		// -(void)addImageSizeWithWidth:(NSInteger)width height:(NSInteger)height;
		[Export("addImageSizeWithWidth:height:")]
		void AddImageSizeWithWidth(nint width, nint height);

		// -(void)addContent:(NSString * _Nonnull)content;
		[Export("addContent:")]
		void AddContent(string content);
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMADepartureTimeKeyName;
		[Field("NMADepartureTimeKeyName", "__Internal")]
		NSString NMADepartureTimeKeyName { get; }

		// extern NSString *const _Nonnull NMADeparturePlatformKeyName;
		[Field("NMADeparturePlatformKeyName", "__Internal")]
		NSString NMADeparturePlatformKeyName { get; }

		// extern NSString *const _Nonnull NMAExceptionEventRedirected;
		[Field("NMAExceptionEventRedirected", "__Internal")]
		NSString NMAExceptionEventRedirected { get; }

		// extern NSString *const _Nonnull NMAExceptionEventReplaced;
		[Field("NMAExceptionEventReplaced", "__Internal")]
		NSString NMAExceptionEventReplaced { get; }

		// extern NSString *const _Nonnull NMAExceptionEventCancelled;
		[Field("NMAExceptionEventCancelled", "__Internal")]
		NSString NMAExceptionEventCancelled { get; }

		// extern NSString *const _Nonnull NMAExceptionEventAdditional;
		[Field("NMAExceptionEventAdditional", "__Internal")]
		NSString NMAExceptionEventAdditional { get; }
	}

	// @interface NMAPlaceTransitDeparture : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitDeparture
	{
		// @property (readonly, nonatomic) NSString * _Nullable line;
		[NullAllowed, Export("line")]
		string Line { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NSString *> * _Nullable scheduledTimeInfo;
		[NullAllowed, Export("scheduledTimeInfo")]
		NSDictionary<NSString, NSString> ScheduledTimeInfo { get; }

		// @property (readonly, nonatomic) NSString * _Nullable direction;
		[NullAllowed, Export("direction")]
		string Direction { get; }

		// @property (readonly, nonatomic) NSString * _Nullable exception;
		[NullAllowed, Export("exception")]
		string Exception { get; }

		// @property (readonly, nonatomic) NSString * _Nullable transitOperator;
		[NullAllowed, Export("transitOperator")]
		string TransitOperator { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NSString *> * _Nullable realTimeInfo;
		[NullAllowed, Export("realTimeInfo")]
		NSDictionary<NSString, NSString> RealTimeInfo { get; }

		// @property (readonly, nonatomic) NSArray<NMAExtendedAttribute *> * _Nullable extendedAttributes;
		[NullAllowed, Export("extendedAttributes")]
		NMAExtendedAttribute[] ExtendedAttributes { get; }
	}

	// @interface NMAPlaceTransitDeparturesAttribute : NMAExtendedAttribute
	[BaseType(typeof(NMAExtendedAttribute))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitDeparturesAttribute
	{
		// @property (readonly, nonatomic) NMAPlaceTransitSchedulePage * _Nullable schedule;
		[NullAllowed, Export("schedule")]
		NMAPlaceTransitSchedulePage Schedule { get; }
	}

	// @interface NMAPlaceTransitDestination : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitDestination
	{
		// @property (readonly, nonatomic) NSString * _Nullable destination;
		[NullAllowed, Export("destination")]
		string Destination { get; }

		// @property (readonly, nonatomic) NSString * _Nullable line;
		[NullAllowed, Export("line")]
		string Line { get; }
	}

	// @interface NMAPlaceTransitLine : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitLine : ObjCRuntime.INativeObject
	{
		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NMAPlaceTransitLineCategory * _Nullable category;
		[NullAllowed, Export("category")]
		NMAPlaceTransitLineCategory Category { get; }

		// @property (readonly, nonatomic) NMAPlaceTransitLineStyle * _Nullable style;
		[NullAllowed, Export("style")]
		NMAPlaceTransitLineStyle Style { get; }

		// @property (readonly, nonatomic) NSString * _Nullable operatorName;
		[NullAllowed, Export("operatorName")]
		string OperatorName { get; }
	}

	// @interface NMAPlaceTransitLineCategory : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitLineCategory
	{
		// @property (readonly, nonatomic) NSString * _Nullable uniqueId;
		[NullAllowed, Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nullable title;
		[NullAllowed, Export("title")]
		string Title { get; }

		// @property (readonly, nonatomic) NSString * _Nullable localName;
		[NullAllowed, Export("localName")]
		string LocalName { get; }

		// @property (readonly, nonatomic) NSString * _Nullable iconUrl;
		[NullAllowed, Export("iconUrl")]
		string IconUrl { get; }
	}

	// @interface NMAPlaceTransitLineStyle : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitLineStyle
	{
		// @property (readonly, nonatomic) NSString * _Nullable color;
		[NullAllowed, Export("color")]
		string Color { get; }

		// @property (readonly, nonatomic) NSString * _Nullable textColor;
		[NullAllowed, Export("textColor")]
		string TextColor { get; }

		// @property (readonly, nonatomic) NSString * _Nullable outlineColor;
		[NullAllowed, Export("outlineColor")]
		string OutlineColor { get; }

		// @property (readonly, nonatomic) NSString * _Nullable iconShape;
		[NullAllowed, Export("iconShape")]
		string IconShape { get; }
	}

	// @interface NMAPlaceTransitLinesAttribute : NMAExtendedAttribute
	[BaseType(typeof(NMAExtendedAttribute))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitLinesAttribute
	{
		// @property (readonly, nonatomic) NSDictionary<NSString *,NMAPlaceTransitLine *> * _Nullable lines;
		[NullAllowed, Export("lines")]
		NSDictionary<NSString, NMAPlaceTransitLine> Lines { get; }

		// @property (readonly, nonatomic) NSArray<NMAPlaceTransitDestination *> * _Nullable destinations;
		[NullAllowed, Export("destinations")]
		NMAPlaceTransitDestination[] Destinations { get; }
	}

	// @interface NMAPlaceTransitOperator : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitOperator : ObjCRuntime.INativeObject
	{
		// @property (readonly, nonatomic) NSString * _Nullable uniqueId;
		[NullAllowed, Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nullable title;
		[NullAllowed, Export("title")]
		string Title { get; }

		// @property (readonly, nonatomic) NMAPlaceTransitOperatorSupplier * _Nullable supplier;
		[NullAllowed, Export("supplier")]
		NMAPlaceTransitOperatorSupplier Supplier { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NMAPlaceTransitOperatorLink *> * _Nullable links;
		[NullAllowed, Export("links")]
		NSDictionary<NSString, NMAPlaceTransitOperatorLink> Links { get; }
	}

	// @interface NMAPlaceTransitOperatorLink : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitOperatorLink : ObjCRuntime.INativeObject
	{
		// @property (readonly, nonatomic) NSString * _Nullable text;
		[NullAllowed, Export("text")]
		string Text { get; }

		// @property (readonly, nonatomic) NMALink * _Nullable url;
		[NullAllowed, Export("url")]
		NMALink Url { get; }
	}

	// @interface NMAPlaceTransitOperatorSupplier : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitOperatorSupplier
	{
		// @property (readonly, nonatomic) NSString * _Nullable title;
		[NullAllowed, Export("title")]
		string Title { get; }
	}

	// @interface NMAPlaceTransitSchedulePage : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitSchedulePage
	{
		// @property (readonly, nonatomic) NSInteger available;
		[Export("available")]
		nint Available { get; }

		// @property (readonly, nonatomic) NSInteger offsetCount;
		[Export("offsetCount")]
		nint OffsetCount { get; }

		// @property (readonly, nonatomic) NMAPlaceTransitSchedulePageRequest * _Nullable nextPageRequest;
		[NullAllowed, Export("nextPageRequest")]
		NMAPlaceTransitSchedulePageRequest NextPageRequest { get; }

		// @property (readonly, nonatomic) NSArray<NMAPlaceTransitDeparture *> * _Nonnull departures;
		[Export("departures")]
		NMAPlaceTransitDeparture[] Departures { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NMAPlaceTransitLine *> * _Nullable lines;
		[NullAllowed, Export("lines")]
		NSDictionary<NSString, NMAPlaceTransitLine> Lines { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NMAPlaceTransitOperator *> * _Nullable operators;
		[NullAllowed, Export("operators")]
		NSDictionary<NSString, NMAPlaceTransitOperator> Operators { get; }
	}

	// @interface NMAPlaceTransitSchedulePageRequest : NMARequest
	[BaseType(typeof(NMARequest))]
	[DisableDefaultCtor]
	interface NMAPlaceTransitSchedulePageRequest
	{
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMAPlacesSourcePVID;
		[Field("NMAPlacesSourcePVID", "__Internal")]
		NSString NMAPlacesSourcePVID { get; }

		// extern NSString *const _Nonnull NMAPlacesSourceSharing;
		[Field("NMAPlacesSourceSharing", "__Internal")]
		NSString NMAPlacesSourceSharing { get; }

		// extern NSString *const _Nonnull NMAPlacesContentWikipedia;
		[Field("NMAPlacesContentWikipedia", "__Internal")]
		NSString NMAPlacesContentWikipedia { get; }

		// extern NSString *const _Nonnull NMAPlacesSourceVenuesAll __attribute__((deprecated("")));
		[Field("NMAPlacesSourceVenuesAll", "__Internal")]
		NSString NMAPlacesSourceVenuesAll { get; }

		// extern NSString *const _Nonnull NMAPlacesSourceVenuesVenue __attribute__((deprecated("")));
		[Field("NMAPlacesSourceVenuesVenue", "__Internal")]
		NSString NMAPlacesSourceVenuesVenue { get; }

		// extern NSString *const _Nonnull NMAPlacesSourceVenuesContent __attribute__((deprecated("")));
		[Field("NMAPlacesSourceVenuesContent", "__Internal")]
		NSString NMAPlacesSourceVenuesContent { get; }

		// extern NSString *const _Nonnull NMAPlacesSourceVenuesDestination __attribute__((deprecated("")));
		[Field("NMAPlacesSourceVenuesDestination", "__Internal")]
		NSString NMAPlacesSourceVenuesDestination { get; }

		// extern NSString *const _Nonnull NMAPlacesSourceBuilding __attribute__((deprecated("")));
		[Field("NMAPlacesSourceBuilding", "__Internal")]
		NSString NMAPlacesSourceBuilding { get; }
	}

	// typedef void (^NMAPlacesCategoriesCompletionBlock)(NSArray<NMACategory *> * _Nullable, NSError * _Nullable);
	delegate void NMAPlacesCategoriesCompletionBlock([NullAllowed] NMACategory[] arg0, [NullAllowed] NSError arg1);

	// @interface NMAPlaces : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAPlaces
	{
		// +(NMAPlaces * _Nullable)sharedPlaces;
		[Static]
		[NullAllowed, Export("sharedPlaces")]
		//[Verify(MethodToProperty)]
		NMAPlaces SharedPlaces { get; }

		// -(NMADiscoveryRequest * _Nullable)createSearchRequestWithLocation:(NMAGeoCoordinates * _Nullable)location query:(NSString * _Nullable)query;
		[Export("createSearchRequestWithLocation:query:")]
		[return: NullAllowed]
		NMADiscoveryRequest CreateSearchRequestWithLocation([NullAllowed] NMAGeoCoordinates location, [NullAllowed] string query);

		// -(NMADiscoveryRequest * _Nullable)createSearchRequestWithLocation:(NMAGeoCoordinates * _Nullable)location query:(NSString * _Nullable)query filter:(NMAAddressFilter * _Nullable)filter;
		[Export("createSearchRequestWithLocation:query:filter:")]
		[return: NullAllowed]
		NMADiscoveryRequest CreateSearchRequestWithLocation([NullAllowed] NMAGeoCoordinates location, [NullAllowed] string query, [NullAllowed] NMAAddressFilter filter);

		// -(NMADiscoveryRequest * _Nonnull)createExploreRequestWithLocation:(NMAGeoCoordinates * _Nullable)location searchArea:(NMAGeoBoundingBox * _Nullable)searchArea filters:(NMACategoryFilter * _Nullable)filters;
		[Export("createExploreRequestWithLocation:searchArea:filters:")]
		NMADiscoveryRequest CreateExploreRequestWithLocation([NullAllowed] NMAGeoCoordinates location, [NullAllowed] NMAGeoBoundingBox searchArea, [NullAllowed] NMACategoryFilter filters);

		// -(NMADiscoveryRequest * _Nonnull)createHereRequestWithLocation:(NMAGeoCoordinates * _Nullable)location filters:(NMACategoryFilter * _Nullable)filters;
		[Export("createHereRequestWithLocation:filters:")]
		NMADiscoveryRequest CreateHereRequestWithLocation([NullAllowed] NMAGeoCoordinates location, [NullAllowed] NMACategoryFilter filters);

		// -(NMADiscoveryRequest * _Nonnull)createAroundRequestWithLocation:(NMAGeoCoordinates * _Nullable)location searchArea:(NMAGeoBoundingBox * _Nullable)searchArea filters:(NMACategoryFilter * _Nullable)filters;
		[Export("createAroundRequestWithLocation:searchArea:filters:")]
		NMADiscoveryRequest CreateAroundRequestWithLocation([NullAllowed] NMAGeoCoordinates location, [NullAllowed] NMAGeoBoundingBox searchArea, [NullAllowed] NMACategoryFilter filters);

		// -(NMAAutoSuggestionRequest * _Nullable)createAutoSuggestionRequestWithLocation:(NMAGeoCoordinates * _Nullable)location partialTerm:(NSString * _Nullable)partialTerm;
		[Export("createAutoSuggestionRequestWithLocation:partialTerm:")]
		[return: NullAllowed]
		NMAAutoSuggestionRequest CreateAutoSuggestionRequestWithLocation([NullAllowed] NMAGeoCoordinates location, [NullAllowed] string partialTerm);

		// -(NMAAutoSuggestionRequest * _Nullable)createAutoSuggestionRequestWithLocation:(NMAGeoCoordinates * _Nullable)location partialTerm:(NSString * _Nullable)partialTerm resultType:(NMAPlacesAutoSuggestionResultType)resultType;
		[Export("createAutoSuggestionRequestWithLocation:partialTerm:resultType:")]
		[return: NullAllowed]
		NMAAutoSuggestionRequest CreateAutoSuggestionRequestWithLocation([NullAllowed] NMAGeoCoordinates location, [NullAllowed] string partialTerm, NMAPlacesAutoSuggestionResultType resultType);

		// -(NMAAutoSuggestionRequest * _Nullable)createAutoSuggestionRequestWithLocation:(NMAGeoCoordinates * _Nullable)location partialTerm:(NSString * _Nullable)partialTerm resultType:(NMAPlacesAutoSuggestionResultType)resultType filter:(NMAAddressFilter * _Nullable)filter;
		[Export("createAutoSuggestionRequestWithLocation:partialTerm:resultType:filter:")]
		[return: NullAllowed]
		NMAAutoSuggestionRequest CreateAutoSuggestionRequestWithLocation([NullAllowed] NMAGeoCoordinates location, [NullAllowed] string partialTerm, NMAPlacesAutoSuggestionResultType resultType, [NullAllowed] NMAAddressFilter filter);

		// -(NMAPlaceRequest * _Nullable)createLookupRequestWithReferenceIdentifier:(NSString * _Nullable)referenceIdentifier inSource:(NSString * _Nullable)source;
		[Export("createLookupRequestWithReferenceIdentifier:inSource:")]
		[return: NullAllowed]
		NMAPlaceRequest CreateLookupRequestWithReferenceIdentifier([NullAllowed] string referenceIdentifier, [NullAllowed] string source);

		// -(NSArray<NMACategory *> * _Nullable)topLevelCategories;
		[NullAllowed, Export("topLevelCategories")]
		//[Verify(MethodToProperty)]
		NMACategory[] TopLevelCategories { get; }

		// -(void)refreshTopLevelCategoriesWithCompletion:(NMAPlacesCategoriesCompletionBlock _Nullable)completionBlock;
		[Export("refreshTopLevelCategoriesWithCompletion:")]
		void RefreshTopLevelCategoriesWithCompletion([NullAllowed] NMAPlacesCategoriesCompletionBlock completionBlock);
	}

	// @interface NMARatings : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARatings
	{
		// @property (readonly, nonatomic) double average;
		[Export("average")]
		double Average { get; }

		// @property (readonly, nonatomic) NSUInteger count;
		[Export("count")]
		nuint Count { get; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull NMA_PLACES_ERROR_DOMAIN;
		[Field("NMA_PLACES_ERROR_DOMAIN", "__Internal")]
		NSString NMA_PLACES_ERROR_DOMAIN { get; }
	}

	// @protocol NMAResultListener <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAResultListener
	{
		// @required -(void)request:(NMARequest * _Nonnull)request didCompleteWithData:(id _Nullable)data error:(NSError * _Nullable)error;
		[Abstract]
		[Export("request:didCompleteWithData:error:")]
		void DidCompleteWithData(NMARequest request, [NullAllowed] NSObject data, [NullAllowed] NSError error);
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const float NMAReverseGeocodeResultInvalidDistance;
		[Field("NMAReverseGeocodeResultInvalidDistance", "__Internal")]
		float NMAReverseGeocodeResultInvalidDistance { get; }
	}

	// @interface NMAReverseGeocodeResult : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAReverseGeocodeResult
	{
		// @property (readonly, nonatomic) NMAPlaceLocation * _Nullable location;
		[NullAllowed, Export("location")]
		NMAPlaceLocation Location { get; }

		// @property (readonly, nonatomic) float distance;
		[Export("distance")]
		float Distance { get; }
	}

	// @protocol NMAMapDataPrefetcherListener <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAMapDataPrefetcherListener
	{
		// @optional -(void)prefetcher:(NMAMapDataPrefetcher * _Nonnull)prefetcher didUpdateProgress:(float)progress forRequestId:(NSInteger)requestId;
		[Export("prefetcher:didUpdateProgress:forRequestId:")]
		void DidUpdateProgress(NMAMapDataPrefetcher prefetcher, float progress, nint requestId);

		// @optional -(void)prefetcher:(NMAMapDataPrefetcher * _Nonnull)prefetcher didUpdateStatus:(NMAPrefetchStatus)status forRequestId:(NSInteger)requestId;
		[Export("prefetcher:didUpdateStatus:forRequestId:")]
		void DidUpdateStatus(NMAMapDataPrefetcher prefetcher, NMAPrefetchStatus status, nint requestId);

		// @optional -(void)prefetcher:(NMAMapDataPrefetcher * _Nonnull)prefetcher didPurgeCache:(BOOL)success;
		[Export("prefetcher:didPurgeCache:")]
		void DidPurgeCache(NMAMapDataPrefetcher prefetcher, bool success);

		// @optional -(void)prefetcher:(NMAMapDataPrefetcher * _Nonnull)prefetcher didEstimate:(NSInteger)dataSizeKB forRequestId:(NSInteger)requestId withSuccess:(BOOL)success;
		[Export("prefetcher:didEstimate:forRequestId:withSuccess:")]
		void DidEstimate(NMAMapDataPrefetcher prefetcher, nint dataSizeKB, nint requestId, bool success);
	}

	// @interface NMAMapDataPrefetcher : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAMapDataPrefetcher
	{
		// +(NMAMapDataPrefetcher * _Nonnull)sharedMapDataPrefetcher;
		[Static]
		[Export("sharedMapDataPrefetcher")]
		//[Verify(MethodToProperty)]
		NMAMapDataPrefetcher SharedMapDataPrefetcher { get; }

		// -(NSInteger)fetchMapDataForBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox error:(NMAPrefetchRequestError * _Nullable)error;
		[Export("fetchMapDataForBoundingBox:error:")]
		nint FetchMapDataForBoundingBox(NMAGeoBoundingBox boundingBox, [NullAllowed] NMAPrefetchRequestError error);

		// -(NSInteger)fetchMapDataForRoute:(NMARoute * _Nonnull)route radius:(NSUInteger)radius error:(NMAPrefetchRequestError * _Nullable)error;
		[Export("fetchMapDataForRoute:radius:error:")]
		nint FetchMapDataForRoute(NMARoute route, nuint radius, [NullAllowed] NMAPrefetchRequestError error);

		// -(NSInteger)estimateMapDataSizeForBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox error:(NMAPrefetchRequestError * _Nullable)error;
		[Export("estimateMapDataSizeForBoundingBox:error:")]
		nint EstimateMapDataSizeForBoundingBox(NMAGeoBoundingBox boundingBox, [NullAllowed] NMAPrefetchRequestError error);

		// -(NSInteger)estimateMapDataSizeForRoute:(NMARoute * _Nonnull)route radius:(NSUInteger)radius error:(NMAPrefetchRequestError * _Nullable)error;
		[Export("estimateMapDataSizeForRoute:radius:error:")]
		nint EstimateMapDataSizeForRoute(NMARoute route, nuint radius, [NullAllowed] NMAPrefetchRequestError error);

		// -(void)cancel:(NSInteger)requestId;
		[Export("cancel:")]
		void Cancel(nint requestId);

		// -(void)cancelAll;
		[Export("cancelAll")]
		void CancelAll();

		// -(void)clearMapDataCache;
		[Export("clearMapDataCache")]
		void ClearMapDataCache();

		// -(void)addListener:(id<NMAMapDataPrefetcherListener> _Nonnull)listener;
		[Export("addListener:")]
		void AddListener(NMAMapDataPrefetcherListener listener);

		// -(void)removeListener:(id<NMAMapDataPrefetcherListener> _Nonnull)listener;
		[Export("removeListener:")]
		void RemoveListener(NMAMapDataPrefetcherListener listener);
	}

	// @interface NMARouter : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARouter
	{
		// @property (readonly, nonatomic) BOOL isBusy;
		[Export("isBusy")]
		bool IsBusy { get; }

		// -(void)cancel;
		[Export("cancel")]
		void Cancel();
	}

	// typedef void (^NMACalculateResultBlock)(NMARouteResult * _Nullable, NMARoutingError);
	delegate void NMACalculateResultBlock([NullAllowed] NMARouteResult arg0, NMARoutingError arg1);

	// @interface NMACoreRouter : NMARouter
	[BaseType(typeof(NMARouter))]
	interface NMACoreRouter
	{
		// +(instancetype _Nonnull)new;
		[Static]
		[Export("new")]
		NMACoreRouter New();

		// -(NSProgress * _Nullable)calculateRouteWithStops:(NSArray * _Nonnull)stops routingMode:(NMARoutingMode * _Nonnull)mode completionBlock:(NMACalculateResultBlock _Nullable)completion;
		[Export("calculateRouteWithStops:routingMode:completionBlock:")]
		//[Verify(StronglyTypedNSArray)]
		[return: NullAllowed]
		NSProgress CalculateRouteWithStops(NSObject[] stops, NMARoutingMode mode, [NullAllowed] NMACalculateResultBlock completion);

		// -(NSProgress * _Nullable)calculateRouteWithPoints:(NSArray<NMAGeoCoordinates *> * _Nonnull)points routingMode:(NMARoutingMode * _Nonnull)mode completionBlock:(NMACalculateResultBlock _Nullable)completion;
		[Export("calculateRouteWithPoints:routingMode:completionBlock:")]
		[return: NullAllowed]
		NSProgress CalculateRouteWithPoints(NMAGeoCoordinates[] points, NMARoutingMode mode, [NullAllowed] NMACalculateResultBlock completion);

		// @property (nonatomic) NMADynamicPenalty * _Nullable dynamicPenalty;
		[NullAllowed, Export("dynamicPenalty", ArgumentSemantic.Assign)]
		NMADynamicPenalty DynamicPenalty { get; set; }

		// @property (nonatomic) NMACoreRouterConnectivity connectivity;
		[Export("connectivity", ArgumentSemantic.Assign)]
		NMACoreRouterConnectivity Connectivity { get; set; }
	}

	// @interface NMATransitRoute (NMARoute)
	[Category]
	[BaseType(typeof(NMARoute))]
	interface NMARoute_NMATransitRoute
	{
		// @property (readonly, nonatomic) NMATransitRouteSourceAttribution * _Nullable sourceAttribution;
		[NullAllowed, Export("sourceAttribution")]
		[Static]
		NMATransitRouteSourceAttribution SourceAttribution { get; }
	}

	// @interface NMAUrbanMobilityArrival : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityArrival
	{
		// @property (readonly, nonatomic) NSDate * _Nullable time;
		[NullAllowed, Export("time")]
		NSDate Time { get; }

		// @property (readonly, nonatomic) NSString * _Nullable platform;
		[NullAllowed, Export("platform")]
		string Platform { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityRealTimeInfo * _Nullable realTimeInfo;
		[NullAllowed, Export("realTimeInfo")]
		NMAUrbanMobilityRealTimeInfo RealTimeInfo { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityStation * _Nullable station;
		[NullAllowed, Export("station")]
		NMAUrbanMobilityStation Station { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityPlace * _Nullable place;
		[NullAllowed, Export("place")]
		NMAUrbanMobilityPlace Place { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityAccessPoint * _Nullable accessPoint;
		[NullAllowed, Export("accessPoint")]
		NMAUrbanMobilityAccessPoint AccessPoint { get; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const NSUInteger NMAUrbanMobilityValueNotAvailable __attribute__((deprecated("")));
		[Field("NMAUrbanMobilityValueNotAvailable", "__Internal")]
		nuint NMAUrbanMobilityValueNotAvailable { get; }
	}

	// @interface NMAUrbanMobilityDeparture : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityDeparture
	{
		// @property (readonly, nonatomic) NMAUrbanMobilityTransport * _Nullable transport;
		[NullAllowed, Export("transport")]
		NMAUrbanMobilityTransport Transport { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable time;
		[NullAllowed, Export("time")]
		NSDate Time { get; }

		// @property (readonly, nonatomic) NSString * _Nullable platform;
		[NullAllowed, Export("platform")]
		string Platform { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityRealTimeInfo * _Nullable realTimeInfo;
		[NullAllowed, Export("realTimeInfo")]
		NMAUrbanMobilityRealTimeInfo RealTimeInfo { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityDepartureFrequency * _Nullable frequency;
		[NullAllowed, Export("frequency")]
		NMAUrbanMobilityDepartureFrequency Frequency { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityStation * _Nullable station;
		[NullAllowed, Export("station")]
		NMAUrbanMobilityStation Station { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityPlace * _Nullable place;
		[NullAllowed, Export("place")]
		NMAUrbanMobilityPlace Place { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityAccessPoint * _Nullable accessPoint;
		[NullAllowed, Export("accessPoint")]
		NMAUrbanMobilityAccessPoint AccessPoint { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityAlternativeDeparture *> * _Nullable alternativeDepartures;
		[NullAllowed, Export("alternativeDepartures")]
		NMAUrbanMobilityAlternativeDeparture[] AlternativeDepartures { get; }
	}

	// @interface NMAUrbanMobilityRoute (NMARoute)
	[Category]
	[BaseType(typeof(NMARoute))]
	interface NMARoute_NMAUrbanMobilityRoute
	{
		// @property (readonly, nonatomic) NSString * _Nullable routeId;
		[NullAllowed, Export("routeId")]
		[Static]
		string RouteId { get; }

		// @property (readonly, nonatomic) NSUInteger changes;
		[Export("changes")]
		[Static]
		nuint Changes { get; }

		// @property (readonly, nonatomic) NSTimeInterval duration;
		[Export("duration")]
		[Static]
		double Duration { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityArrival * _Nullable arrival;
		[NullAllowed, Export("arrival")]
		[Static]
		NMAUrbanMobilityArrival Arrival { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityDeparture * _Nullable departure;
		[NullAllowed, Export("departure")]
		[Static]
		NMAUrbanMobilityDeparture Departure { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityRouteSection *> * _Nullable sections;
		[NullAllowed, Export("sections")]
		[Static]
		NMAUrbanMobilityRouteSection[] Sections { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityTariff *> * _Nullable tariffOptions;
		[NullAllowed, Export("tariffOptions")]
		[Static]
		NMAUrbanMobilityTariff[] TariffOptions { get; }
	}

	// @interface NMARouteConsumption : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARouteConsumption
	{
		// -(NSInteger)getConsumptionWithIndex:(NSUInteger)index;
		[Export("getConsumptionWithIndex:")]
		nint GetConsumptionWithIndex(nuint index);

		// -(NSUInteger)firstAvailableConsumptionIndex;
		[Export("firstAvailableConsumptionIndex")]
		//[Verify(MethodToProperty)]
		nuint FirstAvailableConsumptionIndex { get; }
	}

	// @interface NMARouteConsumptionParameters : NSObject
	[BaseType(typeof(NSObject))]
	interface NMARouteConsumptionParameters
	{
		// @property (assign, nonatomic) double ascentMultiplier;
		[Export("ascentMultiplier")]
		double AscentMultiplier { get; set; }

		// @property (assign, nonatomic) double descentMutiplier;
		[Export("descentMutiplier")]
		double DescentMutiplier { get; set; }

		// @property (assign, nonatomic) double turnTimeMultiplier;
		[Export("turnTimeMultiplier")]
		double TurnTimeMultiplier { get; set; }

		// @property (assign, nonatomic) double accelerationMultiplier;
		[Export("accelerationMultiplier")]
		double AccelerationMultiplier { get; set; }

		// @property (assign, nonatomic) double decelartionMultiplier;
		[Export("decelartionMultiplier")]
		double DecelartionMultiplier { get; set; }

		// @property (assign, nonatomic) double auxiliaryConsumption;
		[Export("auxiliaryConsumption")]
		double AuxiliaryConsumption { get; set; }

		// @property (nonatomic) NSDictionary<NSNumber *,NSNumber *> * _Nonnull consumptionSpeed;
		[Export("consumptionSpeed", ArgumentSemantic.Assign)]
		NSDictionary<NSNumber, NSNumber> ConsumptionSpeed { get; set; }

		// @property (getter = isHighSpeedConsumptionEnabled, assign, nonatomic) BOOL highSpeedConsumptionEnabled;
		[Export("highSpeedConsumptionEnabled")]
		bool HighSpeedConsumptionEnabled { [Bind("isHighSpeedConsumptionEnabled")] get; set; }

		// @property (assign, nonatomic) NSUInteger highSpeedConsumptionThresholdKmh;
		[Export("highSpeedConsumptionThresholdKmh")]
		nuint HighSpeedConsumptionThresholdKmh { get; set; }

		// @property (nonatomic) NSDictionary<NSNumber *,NSNumber *> * _Nonnull trafficSpeed;
		[Export("trafficSpeed", ArgumentSemantic.Assign)]
		NSDictionary<NSNumber, NSNumber> TrafficSpeed { get; set; }

		// @property (nonatomic) NSDictionary<NSNumber *,NSNumber *> * _Nonnull trafficScales;
		[Export("trafficScales", ArgumentSemantic.Assign)]
		NSDictionary<NSNumber, NSNumber> TrafficScales { get; set; }
	}

	// @interface NMARouteElement : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARouteElement
	{
		// @property (readonly, nonatomic) NMARouteElementType type;
		[Export("type")]
		NMARouteElementType Type { get; }

		// @property (readonly, nonatomic) NMARoadElement * _Nullable roadElement;
		[NullAllowed, Export("roadElement")]
		NMARoadElement RoadElement { get; }

		// @property (readonly, nonatomic) NMATransitRouteElement * _Nullable transitRouteElement;
		[NullAllowed, Export("transitRouteElement")]
		NMATransitRouteElement TransitRouteElement { get; }

		// @property (readonly, nonatomic) NSArray<NMAGeoCoordinates *> * _Nonnull geometry;
		[Export("geometry")]
		NMAGeoCoordinates[] Geometry { get; }

		// @property (readonly, nonatomic) NMATravelDirection travelDirection;
		[Export("travelDirection")]
		NMATravelDirection TravelDirection { get; }
	}

	// @interface NMARouteResult : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARouteResult
	{
		// @property (readonly, nonatomic) NSArray<NMARoute *> * _Nullable routes;
		[NullAllowed, Export("routes")]
		NMARoute[] Routes { get; }

		// @property (readonly, nonatomic) NSArray<NSNumber *> * _Nullable violatedOptions;
		[NullAllowed, Export("violatedOptions")]
		NSNumber[] ViolatedOptions { get; }
	}

	// @interface NMATransitRoutingMode (NMARoutingMode)
	[Category]
	[BaseType(typeof(NMARoutingMode))]
	interface NMARoutingMode_NMATransitRoutingMode
	{
		// @property (nonatomic) NMATransitRoutingOption transitRoutingOptions;
		[Export("transitRoutingOptions", ArgumentSemantic.Assign)]
		[Static]
		NMATransitRoutingOption TransitRoutingOptions { get; set; }

		// @property (nonatomic) NSUInteger maximumChanges;
		[Export("maximumChanges")]
		[Static]
		nuint MaximumChanges { get; set; }
	}

	// @interface NMATruckRoutingMode (NMARoutingMode)
	[Category]
	[BaseType(typeof(NMARoutingMode))]
	interface NMARoutingMode_NMATruckRoutingMode
	{
		// @property (nonatomic) NMATunnelCategory tunnelCategory;
		[Export("tunnelCategory", ArgumentSemantic.Assign)]
		[Static]
		NMATunnelCategory TunnelCategory { get; set; }

		// @property (nonatomic) NMAHazardousGoodsType hazardousGoods;
		[Export("hazardousGoods", ArgumentSemantic.Assign)]
		[Static]
		NMAHazardousGoodsType HazardousGoods { get; set; }

		// @property (nonatomic) float limitedVehicleWeight;
		[Export("limitedVehicleWeight")]
		[Static]
		float LimitedVehicleWeight { get; set; }

		// @property (nonatomic) float weightPerAxle;
		[Export("weightPerAxle")]
		[Static]
		float WeightPerAxle { get; set; }

		// @property (nonatomic) float vehicleHeight;
		[Export("vehicleHeight")]
		[Static]
		float VehicleHeight { get; set; }

		// @property (nonatomic) float vehicleWidth;
		[Export("vehicleWidth")]
		[Static]
		float VehicleWidth { get; set; }

		// @property (nonatomic) float vehicleLength;
		[Export("vehicleLength")]
		[Static]
		float VehicleLength { get; set; }

		// @property (nonatomic) NSUInteger trailersCount;
		[Export("trailersCount")]
		[Static]
		nuint TrailersCount { get; set; }

		// @property (nonatomic) BOOL avoidDifficultTurns;
		[Export("avoidDifficultTurns")]
		[Static]
		bool AvoidDifficultTurns { get; set; }

		// @property (nonatomic) NMATruckType truckType;
		[Export("truckType", ArgumentSemantic.Assign)]
		[Static]
		NMATruckType TruckType { get; set; }

		// @property (nonatomic) NMATruckRestrictionsMode truckRestrictionsMode;
		[Export("truckRestrictionsMode", ArgumentSemantic.Assign)]
		[Static]
		NMATruckRestrictionsMode TruckRestrictionsMode { get; set; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const NSUInteger NMARoutingModeDefaultMaximumChanges __attribute__((deprecated("")));
		[Field("NMARoutingModeDefaultMaximumChanges", "__Internal")]
		nuint NMARoutingModeDefaultMaximumChanges { get; }
	}

	// @interface NMAUrbanMobilityRoutingMode (NMARoutingMode)
	[Category]
	[BaseType(typeof(NMARoutingMode))]
	interface NMARoutingMode_NMAUrbanMobilityRoutingMode
	{
		// @property (nonatomic) NMAUrbanMobilityRoutingTypeOption urbanMobilityRoutingType;
		[Export("urbanMobilityRoutingType", ArgumentSemantic.Assign)]
		[Static]
		NMAUrbanMobilityRoutingTypeOption UrbanMobilityRoutingType { get; set; }

		// @property (nonatomic) NMAUrbanMobilityOption urbanMobilityRoutingOptions;
		[Export("urbanMobilityRoutingOptions", ArgumentSemantic.Assign)]
		[Static]
		NMAUrbanMobilityOption UrbanMobilityRoutingOptions { get; set; }

		// @property (nonatomic) NSUInteger walkSpeed;
		[Export("walkSpeed")]
		[Static]
		nuint WalkSpeed { get; set; }

		// @property (nonatomic) NSUInteger walkDistance;
		[Export("walkDistance")]
		[Static]
		nuint WalkDistance { get; set; }

		// @property (getter = isStrict, nonatomic) BOOL strict;
		[Export("strict")]
		[Static]
		bool Strict { [Bind("isStrict")] get; set; }

		// @property (nonatomic) NSDate * _Nullable arrivalTime;
		[NullAllowed, Export("arrivalTime", ArgumentSemantic.Assign)]
		[Static]
		NSDate ArrivalTime { get; set; }

		// @property (nonatomic) NSUInteger maximumChanges;
		[Export("maximumChanges")]
		[Static]
		nuint MaximumChanges { get; set; }

		// @property (nonatomic) NMAUrbanMobilityUnits units;
		[Export("units", ArgumentSemantic.Assign)]
		[Static]
		NMAUrbanMobilityUnits Units { get; set; }
	}

	// @interface NMARoutingZoneRestriction : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARoutingZoneRestriction
	{
		// @property (readonly, nonatomic) NSDate * _Nullable timeBegin;
		[NullAllowed, Export("timeBegin")]
		NSDate TimeBegin { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable timeEnd;
		[NullAllowed, Export("timeEnd")]
		NSDate TimeEnd { get; }

		// @property (readonly, nonatomic) NSString * _Nullable licensePlateLastDigits;
		[NullAllowed, Export("licensePlateLastDigits")]
		string LicensePlateLastDigits { get; }

		// @property (readonly, nonatomic) NSSet<NSNumber *> * _Nonnull transportTypes;
		[Export("transportTypes")]
		NSSet<NSNumber> TransportTypes { get; }
	}

	// @interface NMARoutingZone : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMARoutingZone
	{
		// @property (readonly, nonatomic) NSString * _Nonnull identifier;
		[Export("identifier")]
		string Identifier { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull name;
		[Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NSArray<NMARoutingZoneRestriction *> * _Nonnull restrictions;
		[Export("restrictions")]
		NMARoutingZoneRestriction[] Restrictions { get; }

		// @property (readonly, nonatomic) NMARoutingZoneType type;
		[Export("type")]
		NMARoutingZoneType Type { get; }
	}

	// @interface NMASignpost : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASignpost
	{
		// @property (readonly, nonatomic) UIColor * _Nonnull foregroundColor;
		[Export("foregroundColor")]
		UIColor ForegroundColor { get; }

		// @property (readonly, nonatomic) UIColor * _Nonnull backgroundColor;
		[Export("backgroundColor")]
		UIColor BackgroundColor { get; }

		// @property (readonly, nonatomic) NSArray<NMASignpostLocalizedLabel *> * _Nonnull exitDirections;
		[Export("exitDirections")]
		NMASignpostLocalizedLabel[] ExitDirections { get; }

		// @property (readonly, nonatomic) NMAImage * _Nullable exitIcon;
		[NullAllowed, Export("exitIcon")]
		NMAImage ExitIcon { get; }

		// @property (readonly, nonatomic) NSString * _Nullable exitNumber;
		[NullAllowed, Export("exitNumber")]
		string ExitNumber { get; }

		// @property (readonly, nonatomic) NSString * _Nullable exitText;
		[NullAllowed, Export("exitText")]
		string ExitText { get; }
	}

	// @interface NMASignpostLocalizedLabel : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMASignpostLocalizedLabel
	{
		// @property (readonly, nonatomic) NSString * _Nullable language;
		[NullAllowed, Export("language")]
		string Language { get; }

		// @property (readonly, nonatomic) NSString * _Nullable text;
		[NullAllowed, Export("text")]
		string Text { get; }

		// @property (readonly, nonatomic) NSString * _Nullable routeName;
		[NullAllowed, Export("routeName")]
		string RouteName { get; }

		// @property (readonly, nonatomic) NSString * _Nullable routeDirection;
		[NullAllowed, Export("routeDirection")]
		string RouteDirection { get; }
	}

	// @interface NMATransitManeuver : NMAManeuver
	[BaseType(typeof(NMAManeuver))]
	[DisableDefaultCtor]
	interface NMATransitManeuver
	{
		// @property (readonly, nonatomic) NSString * _Nullable departureStopName;
		[NullAllowed, Export("departureStopName")]
		string DepartureStopName { get; }

		// @property (readonly, nonatomic) NSString * _Nullable arrivalStopName;
		[NullAllowed, Export("arrivalStopName")]
		string ArrivalStopName { get; }

		// @property (readonly, nonatomic) NSString * _Nullable terminusStopName;
		[NullAllowed, Export("terminusStopName")]
		string TerminusStopName { get; }

		// @property (readonly, nonatomic) NSString * _Nullable lineName;
		[NullAllowed, Export("lineName")]
		string LineName { get; }

		// @property (readonly, nonatomic) NMATransitLineStyle lineStyle;
		[Export("lineStyle")]
		NMATransitLineStyle LineStyle { get; }

		// @property (readonly, nonatomic) UIColor * _Nullable primaryLineColor;
		[NullAllowed, Export("primaryLineColor")]
		UIColor PrimaryLineColor { get; }

		// @property (readonly, nonatomic) UIColor * _Nullable secondaryLineColor;
		[NullAllowed, Export("secondaryLineColor")]
		UIColor SecondaryLineColor { get; }

		// @property (readonly, nonatomic) NSString * _Nullable systemOfficialName;
		[NullAllowed, Export("systemOfficialName")]
		string SystemOfficialName { get; }

		// @property (readonly, nonatomic) NSString * _Nullable systemShortName;
		[NullAllowed, Export("systemShortName")]
		string SystemShortName { get; }

		// @property (readonly, nonatomic) NMATransitType transitType;
		[Export("transitType")]
		NMATransitType TransitType { get; }

		// @property (readonly, nonatomic) NSString * _Nullable transitTypeName;
		[NullAllowed, Export("transitTypeName")]
		string TransitTypeName { get; }

		// @property (readonly, nonatomic) NSTimeInterval transitTravelTime;
		[Export("transitTravelTime")]
		double TransitTravelTime { get; }
	}

	// @interface NMATransitRouteElement : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitRouteElement
	{
		// @property (readonly, nonatomic) NSTimeInterval duration;
		[Export("duration")]
		double Duration { get; }

		// @property (readonly, nonatomic) NMATransitRouteStop * _Nullable departureStop;
		[NullAllowed, Export("departureStop")]
		NMATransitRouteStop DepartureStop { get; }

		// @property (readonly, nonatomic) NMATransitRouteStop * _Nullable arrivalStop;
		[NullAllowed, Export("arrivalStop")]
		NMATransitRouteStop ArrivalStop { get; }
	}

	// @interface NMATransitRouteSourceAttribution : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitRouteSourceAttribution
	{
		// @property (readonly, nonatomic) NSString * _Nullable attribution;
		[NullAllowed, Export("attribution")]
		string Attribution { get; }

		// @property (readonly, nonatomic) NSArray<NMATransitRouteSupplier *> * _Nullable suppliers;
		[NullAllowed, Export("suppliers")]
		NMATransitRouteSupplier[] Suppliers { get; }
	}

	// @interface NMATransitRouteStop : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitRouteStop
	{
		// @property (readonly, nonatomic) NSString * _Nullable identifier;
		[NullAllowed, Export("identifier")]
		string Identifier { get; }

		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable coordinates;
		[NullAllowed, Export("coordinates")]
		NMAGeoCoordinates Coordinates { get; }
	}

	// @interface NMATransitRouteSupplier : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitRouteSupplier
	{
		// @property (readonly, nonatomic) NSString * _Nullable title;
		[NullAllowed, Export("title")]
		string Title { get; }

		// @property (readonly, nonatomic) NSString * _Nullable url;
		[NullAllowed, Export("url")]
		string Url { get; }

		// @property (readonly, nonatomic) NSArray<NMATransitRouteSupplierNote *> * _Nullable notes;
		[NullAllowed, Export("notes")]
		NMATransitRouteSupplierNote[] Notes { get; }
	}

	// @interface NMATransitRouteSupplierNote : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATransitRouteSupplierNote
	{
		// @property (readonly, nonatomic) NSString * _Nullable type;
		[NullAllowed, Export("type")]
		string Type { get; }

		// @property (readonly, nonatomic) NSString * _Nullable text;
		[NullAllowed, Export("text")]
		string Text { get; }

		// @property (readonly, nonatomic) NSString * _Nullable url;
		[NullAllowed, Export("url")]
		string Url { get; }

		// @property (readonly, nonatomic) NSString * _Nullable urlText;
		[NullAllowed, Export("urlText")]
		string UrlText { get; }
	}

	// @interface NMATruckRestriction : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATruckRestriction
	{
		// @property (readonly, nonatomic) NMATruckRestrictionType truckRestrictionType;
		[Export("truckRestrictionType")]
		NMATruckRestrictionType TruckRestrictionType { get; }

		// @property (readonly, nonatomic) NMATruckRestrictionHazMat truckHazMatType;
		[Export("truckHazMatType")]
		NMATruckRestrictionHazMat TruckHazMatType { get; }

		// @property (readonly, nonatomic) NMATruckRestrictionTrailerType truckTrailerType;
		[Export("truckTrailerType")]
		NMATruckRestrictionTrailerType TruckTrailerType { get; }

		// @property (readonly, nonatomic) NMATruckRestrictionWeatherType truckWeatherType;
		[Export("truckWeatherType")]
		NMATruckRestrictionWeatherType TruckWeatherType { get; }

		// @property (readonly, nonatomic) NSUInteger value;
		[Export("value")]
		nuint Value { get; }

		// -(BOOL)hasValue;
		[Export("hasValue")]
		//[Verify(MethodToProperty)]
		bool HasValue { get; }

		// -(BOOL)hasHazMatRestriction;
		[Export("hasHazMatRestriction")]
		//[Verify(MethodToProperty)]
		bool HasHazMatRestriction { get; }

		// -(BOOL)hasTrailerRestriction;
		[Export("hasTrailerRestriction")]
		//[Verify(MethodToProperty)]
		bool HasTrailerRestriction { get; }

		// -(BOOL)hasWeatherRestriction;
		[Export("hasWeatherRestriction")]
		//[Verify(MethodToProperty)]
		bool HasWeatherRestriction { get; }
	}

	// @interface NMAWaypointRoadInfo : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAWaypointRoadInfo
	{
		// @property (readonly, nonatomic) NMARoadSide roadSide;
		[Export("roadSide")]
		NMARoadSide RoadSide { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable matchedCoordinates;
		[NullAllowed, Export("matchedCoordinates")]
		NMAGeoCoordinates MatchedCoordinates { get; }
	}

	// @interface NMATollCostOptions : NSObject
	[BaseType(typeof(NSObject))]
	interface NMATollCostOptions
	{
		// -(instancetype _Nullable)initWithVehicleProfile:(NMATollCostVehicleProfile * _Nonnull)vehicleProfile;
		[Export("initWithVehicleProfile:")]
		IntPtr Constructor(NMATollCostVehicleProfile vehicleProfile);

		// @property (readonly, nonatomic, strong) NMATollCostVehicleProfile * _Nonnull vehicleProfile;
		[Export("vehicleProfile", ArgumentSemantic.Strong)]
		NMATollCostVehicleProfile VehicleProfile { get; }

		// @property (nonatomic, strong) NSString * _Nonnull currency;
		[Export("currency", ArgumentSemantic.Strong)]
		string Currency { get; set; }

		// @property (nonatomic, strong) NSDate * _Nullable departure;
		[NullAllowed, Export("departure", ArgumentSemantic.Strong)]
		NSDate Departure { get; set; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern NSString *const _Nonnull kNMATollCostRequestErrorDomain;
		[Field("kNMATollCostRequestErrorDomain", "__Internal")]
		NSString kNMATollCostRequestErrorDomain { get; }
	}

	// typedef void (^NMATollCostRequestCompletionBlock)(NMATollCostRequest * _Nonnull, NMATollCostResult * _Nonnull, NSError * _Nullable);
	delegate void NMATollCostRequestCompletionBlock(NMATollCostRequest arg0, NMATollCostResult arg1, [NullAllowed] NSError arg2);

	// @protocol NMATollCostRequestListener <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMATollCostRequestListener
	{
		// @required -(void)request:(NMATollCostRequest * _Nonnull)request didCompleteWithResult:(NMATollCostResult * _Nonnull)result error:(NSError * _Nullable)error;
		[Abstract]
		[Export("request:didCompleteWithResult:error:")]
		void DidCompleteWithResult(NMATollCostRequest request, NMATollCostResult result, [NullAllowed] NSError error);
	}

	// @interface NMATollCostRequest : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATollCostRequest
	{
		// -(instancetype _Nullable)initWithRoute:(NMARoute * _Nonnull)route;
		[Export("initWithRoute:")]
		IntPtr Constructor(NMARoute route);

		// -(instancetype _Nullable)initWithRoute:(NMARoute * _Nonnull)route andOptions:(NMATollCostOptions * _Nonnull)options;
		[Export("initWithRoute:andOptions:")]
		IntPtr Constructor(NMARoute route, NMATollCostOptions options);

		// -(void)startWithListener:(id<NMATollCostRequestListener> _Nonnull)requestListener;
		[Export("startWithListener:")]
		void StartWithListener(NMATollCostRequestListener requestListener);

		// -(void)startWithBlock:(NMATollCostRequestCompletionBlock _Nonnull)block;
		[Export("startWithBlock:")]
		void StartWithBlock(NMATollCostRequestCompletionBlock block);

		// -(void)cancel;
		[Export("cancel")]
		void Cancel();
	}

	// @interface NMATollCostResult : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMATollCostResult
	{
		// @property (readonly, nonatomic, strong) NSDecimalNumber * _Nonnull tollCost;
		[Export("tollCost", ArgumentSemantic.Strong)]
		NSDecimalNumber TollCost { get; }

		// @property (readonly, nonatomic, strong) NSDictionary<NSString *,NSDecimalNumber *> * _Nullable countryTollMap;
		[NullAllowed, Export("countryTollMap", ArgumentSemantic.Strong)]
		NSDictionary<NSString, NSDecimalNumber> CountryTollMap { get; }

		// @property (readonly, nonatomic, strong) NSDictionary<NSString *,NSDecimalNumber *> * _Nonnull tollSystemMap;
		[Export("tollSystemMap", ArgumentSemantic.Strong)]
		NSDictionary<NSString, NSDecimalNumber> TollSystemMap { get; }
	}

	// @interface NMATollCostVehicleProfile : NSObject
	[BaseType(typeof(NSObject))]
	interface NMATollCostVehicleProfile
	{
		// @property (nonatomic) NMATollCostVehicleType vehicleType;
		[Export("vehicleType", ArgumentSemantic.Assign)]
		NMATollCostVehicleType VehicleType { get; set; }

		// @property (nonatomic) NMATollCostTrailerType trailerType;
		[Export("trailerType", ArgumentSemantic.Assign)]
		NMATollCostTrailerType TrailerType { get; set; }

		// @property (nonatomic) NMATollCostTrailersCount trailersCount;
		[Export("trailersCount", ArgumentSemantic.Assign)]
		NMATollCostTrailersCount TrailersCount { get; set; }

		// @property (nonatomic) NSUInteger vehicleNumberAxles;
		[Export("vehicleNumberAxles")]
		nuint VehicleNumberAxles { get; set; }

		// @property (nonatomic) NSUInteger trailerNumberAxles;
		[Export("trailerNumberAxles")]
		nuint TrailerNumberAxles { get; set; }

		// @property (nonatomic) NMATollCostHybridType hybridType;
		[Export("hybridType", ArgumentSemantic.Assign)]
		NMATollCostHybridType HybridType { get; set; }

		// @property (nonatomic) NMATollCostEmissionType emissionType;
		[Export("emissionType", ArgumentSemantic.Assign)]
		NMATollCostEmissionType EmissionType { get; set; }

		// @property (nonatomic) double height;
		[Export("height")]
		double Height { get; set; }

		// @property (nonatomic) double trailerHeight;
		[Export("trailerHeight")]
		double TrailerHeight { get; set; }

		// @property (nonatomic) double vehicleWeight;
		[Export("vehicleWeight")]
		double VehicleWeight { get; set; }

		// @property (nonatomic) double limitedWeight;
		[Export("limitedWeight")]
		double LimitedWeight { get; set; }

		// @property (getter = isDisabledEquipped, nonatomic) BOOL disabledEquipped;
		[Export("disabledEquipped")]
		bool DisabledEquipped { [Bind("isDisabledEquipped")] get; set; }

		// @property (nonatomic) NSUInteger passengersCount;
		[Export("passengersCount")]
		nuint PassengersCount { get; set; }

		// @property (nonatomic) NSUInteger tiresCount;
		[Export("tiresCount")]
		nuint TiresCount { get; set; }

		// @property (getter = isCommercial, nonatomic) BOOL commercial;
		[Export("commercial")]
		bool Commercial { [Bind("isCommercial")] get; set; }

		// @property (nonatomic) NMATollCostShippedHazardousGoods shippedHazardousGoods;
		[Export("shippedHazardousGoods", ArgumentSemantic.Assign)]
		NMATollCostShippedHazardousGoods ShippedHazardousGoods { get; set; }

		// @property (nonatomic) double heightAbove1stAxle;
		[Export("heightAbove1stAxle")]
		double HeightAbove1stAxle { get; set; }
	}

	// @interface NMAUrbanMobilityAccessPoint : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityAccessPoint
	{
		// @property (readonly, nonatomic) NSString * _Nonnull accessPointId;
		[Export("accessPointId")]
		string AccessPointId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull name;
		[Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull location;
		[Export("location")]
		NMAGeoCoordinates Location { get; }
	}

	// @interface NMAUrbanMobilityAddress : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityAddress
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable location;
		[NullAllowed, Export("location")]
		NMAGeoCoordinates Location { get; }

		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NSString * _Nullable country;
		[NullAllowed, Export("country")]
		string Country { get; }

		// @property (readonly, nonatomic) NSString * _Nullable countryCode;
		[NullAllowed, Export("countryCode")]
		string CountryCode { get; }

		// @property (readonly, nonatomic) NSString * _Nullable state;
		[NullAllowed, Export("state")]
		string State { get; }

		// @property (readonly, nonatomic) NSString * _Nullable postalCode;
		[NullAllowed, Export("postalCode")]
		string PostalCode { get; }

		// @property (readonly, nonatomic) NSString * _Nullable district;
		[NullAllowed, Export("district")]
		string District { get; }

		// @property (readonly, nonatomic) NSString * _Nullable street;
		[NullAllowed, Export("street")]
		string Street { get; }

		// @property (readonly, nonatomic) NSString * _Nullable houseNumber;
		[NullAllowed, Export("houseNumber")]
		string HouseNumber { get; }

		// @property (readonly, nonatomic) NSString * _Nullable city;
		[NullAllowed, Export("city")]
		string City { get; }
	}

	// @interface NMAUrbanMobilityAlert : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityAlert
	{
		// @property (readonly, nonatomic) NSString * _Nullable uniqueId;
		[NullAllowed, Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityProvider * _Nullable provider;
		[NullAllowed, Export("provider")]
		NMAUrbanMobilityProvider Provider { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityTransport *> * _Nullable transports;
		[NullAllowed, Export("transports")]
		NMAUrbanMobilityTransport[] Transports { get; }

		// @property (readonly, nonatomic) NSString * _Nullable info;
		[NullAllowed, Export("info")]
		string Info { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable validFrom;
		[NullAllowed, Export("validFrom")]
		NSDate ValidFrom { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable validUntil;
		[NullAllowed, Export("validUntil")]
		NSDate ValidUntil { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityLink * _Nullable source;
		[NullAllowed, Export("source")]
		NMAUrbanMobilityLink Source { get; }

		// @property (readonly, nonatomic) NSString * _Nullable imageUrl;
		[NullAllowed, Export("imageUrl")]
		string ImageUrl { get; }

		// @property (readonly, nonatomic) NSString * _Nullable imageCaption;
		[NullAllowed, Export("imageCaption")]
		string ImageCaption { get; }
	}

	// @interface NMAUrbanMobilityAlternativeDeparture : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityAlternativeDeparture
	{
		// @property (readonly, nonatomic) NMAUrbanMobilityTransport * _Nullable transport;
		[NullAllowed, Export("transport")]
		NMAUrbanMobilityTransport Transport { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable time;
		[NullAllowed, Export("time")]
		NSDate Time { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityRealTimeInfo * _Nullable realTimeInfo;
		[NullAllowed, Export("realTimeInfo")]
		NMAUrbanMobilityRealTimeInfo RealTimeInfo { get; }
	}

	// @interface NMAUrbanMobilityCity : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityCity
	{
		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NSString * _Nullable displayName;
		[NullAllowed, Export("displayName")]
		string DisplayName { get; }

		// @property (readonly, nonatomic) NSString * _Nullable country;
		[NullAllowed, Export("country")]
		string Country { get; }

		// @property (readonly, nonatomic) NSString * _Nullable state;
		[NullAllowed, Export("state")]
		string State { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable location;
		[NullAllowed, Export("location")]
		NMAGeoCoordinates Location { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable created;
		[NullAllowed, Export("created")]
		NSDate Created { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable updated;
		[NullAllowed, Export("updated")]
		NSDate Updated { get; }

		// @property (readonly, nonatomic) double relevancy;
		[Export("relevancy")]
		double Relevancy { get; }

		// @property (readonly, nonatomic) NSInteger distance;
		[Export("distance")]
		nint Distance { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityOperator *> * _Nullable operators;
		[NullAllowed, Export("operators")]
		NMAUrbanMobilityOperator[] Operators { get; }

		// @property (readonly, nonatomic) NSInteger population;
		[Export("population")]
		nint Population { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityProvider *> * _Nullable providers;
		[NullAllowed, Export("providers")]
		NMAUrbanMobilityProvider[] Providers { get; }

		// @property (readonly, nonatomic) float quality;
		[Export("quality")]
		float Quality { get; }

		// @property (readonly, nonatomic) NSInteger transportsCount;
		[Export("transportsCount")]
		nint TransportsCount { get; }

		// @property (readonly, nonatomic) NSInteger stopsCount;
		[Export("stopsCount")]
		nint StopsCount { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityMissingCoverage * _Nullable missingCoverage;
		[NullAllowed, Export("missingCoverage")]
		NMAUrbanMobilityMissingCoverage MissingCoverage { get; }
	}

	// @interface NMAUrbanMobilitySearchRequest : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilitySearchRequest
	{
		// @property (nonatomic) NSInteger resultLimit;
		[Export("resultLimit")]
		nint ResultLimit { get; set; }
	}

	// typedef void (^NMAUrbanMobilityCityCoverageRequestCompletionBlock)(NMAUrbanMobilityCityCoverageResult * _Nullable, NSError * _Nullable);
	delegate void NMAUrbanMobilityCityCoverageRequestCompletionBlock([NullAllowed] NMAUrbanMobilityCityCoverageResult arg0, [NullAllowed] NSError arg1);

	// @interface NMAUrbanMobilityCityCoverageRequest : NMAUrbanMobilitySearchRequest
	[BaseType(typeof(NMAUrbanMobilitySearchRequest))]
	interface NMAUrbanMobilityCityCoverageRequest
	{
		// +(instancetype _Nonnull)new;
		[Static]
		[Export("new")]
		NMAUrbanMobilityCityCoverageRequest New();

		// @property (nonatomic) NSInteger nearbyMax;
		[Export("nearbyMax")]
		nint NearbyMax { get; set; }

		// @property (nonatomic) NSInteger radius;
		[Export("radius")]
		nint Radius { get; set; }

		// @property (nonatomic) NMAGeoCoordinates * _Nullable location;
		[NullAllowed, Export("location", ArgumentSemantic.Assign)]
		NMAGeoCoordinates Location { get; set; }

		// @property (nonatomic) NSDate * _Nullable time;
		[NullAllowed, Export("time", ArgumentSemantic.Assign)]
		NSDate Time { get; set; }

		// @property (nonatomic) NMACoverageUpdateType updateType;
		[Export("updateType", ArgumentSemantic.Assign)]
		NMACoverageUpdateType UpdateType { get; set; }

		// @property (nonatomic) NSInteger maximumResults;
		[Export("maximumResults")]
		nint MaximumResults { get; set; }

		// -(BOOL)startWithCompletionBlock:(NMAUrbanMobilityCityCoverageRequestCompletionBlock _Nonnull)completion;
		[Export("startWithCompletionBlock:")]
		bool StartWithCompletionBlock(NMAUrbanMobilityCityCoverageRequestCompletionBlock completion);
	}

	// @interface NMAUrbanMobilityCitySearchResult : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityCitySearchResult
	{
		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityCity *> * _Nullable cities;
		[NullAllowed, Export("cities")]
		NMAUrbanMobilityCity[] Cities { get; }

		// @property (readonly, nonatomic) NSInteger timeTableCount;
		[Export("timeTableCount")]
		nint TimeTableCount { get; }

		// @property (readonly, nonatomic) NSInteger simpleRoutingCount;
		[Export("simpleRoutingCount")]
		nint SimpleRoutingCount { get; }

		// @property (readonly, nonatomic) NSInteger realTimeCount;
		[Export("realTimeCount")]
		nint RealTimeCount { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable refTime;
		[NullAllowed, Export("refTime")]
		NSDate RefTime { get; }
	}

	// @interface NMAUrbanMobilityCityCoverageResult : NMAUrbanMobilityCitySearchResult
	[BaseType(typeof(NMAUrbanMobilityCitySearchResult))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityCityCoverageResult
	{
		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityCity *> * _Nullable nearbyCities;
		[NullAllowed, Export("nearbyCities")]
		NMAUrbanMobilityCity[] NearbyCities { get; }
	}

	// typedef void (^NMAUrbanMobilityCitySearchCompletionBlock)(NMAUrbanMobilityCitySearchResult * _Nullable, NSError * _Nullable);
	delegate void NMAUrbanMobilityCitySearchCompletionBlock([NullAllowed] NMAUrbanMobilityCitySearchResult arg0, [NullAllowed] NSError arg1);

	// @interface NMAUrbanMobilityCitySearchRequest : NMAUrbanMobilitySearchRequest
	[BaseType(typeof(NMAUrbanMobilitySearchRequest))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityCitySearchRequest
	{
		// @property (nonatomic) NSInteger maximumResults;
		[Export("maximumResults")]
		nint MaximumResults { get; set; }

		// -(instancetype _Nonnull)initWithCity:(NSString * _Nonnull)cityName;
		[Export("initWithCity:")]
		IntPtr Constructor(string cityName);

		// -(BOOL)startWithCompletionBlock:(NMAUrbanMobilityCitySearchCompletionBlock _Nonnull)completion;
		[Export("startWithCompletionBlock:")]
		bool StartWithCompletionBlock(NMAUrbanMobilityCitySearchCompletionBlock completion);
	}

	// @interface NMAUrbanMobilityDepartureBoard : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityDepartureBoard
	{
		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityDeparture *> * _Nonnull departures;
		[Export("departures")]
		NMAUrbanMobilityDeparture[] Departures { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityTransport *> * _Nonnull transports;
		[Export("transports")]
		NMAUrbanMobilityTransport[] Transports { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityOperator *> * _Nonnull operators;
		[Export("operators")]
		NMAUrbanMobilityOperator[] Operators { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityLink *> * _Nonnull operatorDisclaimers;
		[Export("operatorDisclaimers")]
		NMAUrbanMobilityLink[] OperatorDisclaimers { get; }
	}

	// typedef void (^NMAUrbanMobilityDepartureBoardCompletionBlock)(NSArray<NMAUrbanMobilityDeparture *> * _Nullable, NSError * _Nullable);
	delegate void NMAUrbanMobilityDepartureBoardCompletionBlock([NullAllowed] NMAUrbanMobilityDeparture[] arg0, [NullAllowed] NSError arg1);

	// @interface NMAUrbanMobilityDepartureBoardRequest : NMAUrbanMobilitySearchRequest
	[BaseType(typeof(NMAUrbanMobilitySearchRequest))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityDepartureBoardRequest
	{
		// -(instancetype _Nonnull)initWithStationId:(NSString * _Nonnull)stationId location:(NMAGeoCoordinates * _Nonnull)location;
		[Export("initWithStationId:location:")]
		IntPtr Constructor(string stationId, NMAGeoCoordinates location);

		// -(BOOL)startWithCompletionBlock:(NMAUrbanMobilityDepartureBoardCompletionBlock _Nonnull)completion;
		[Export("startWithCompletionBlock:")]
		bool StartWithCompletionBlock(NMAUrbanMobilityDepartureBoardCompletionBlock completion);

		// @property (readonly, nonatomic) NSString * _Nonnull stationId;
		[Export("stationId")]
		string StationId { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull location;
		[Export("location")]
		NMAGeoCoordinates Location { get; }

		// @property (nonatomic) NSDate * _Nullable departureTime;
		[NullAllowed, Export("departureTime", ArgumentSemantic.Assign)]
		NSDate DepartureTime { get; set; }

		// @property (nonatomic) NMAUrbanMobilitySearchOption strictSearch;
		[Export("strictSearch", ArgumentSemantic.Assign)]
		NMAUrbanMobilitySearchOption StrictSearch { get; set; }

		// @property (nonatomic) NSSet * _Nullable transitModes;
		[NullAllowed, Export("transitModes", ArgumentSemantic.Assign)]
		NSSet TransitModes { get; set; }

		// @property (getter = isRealTimeInfoEnabled, nonatomic) BOOL realTimeInfoEnabled;
		[Export("realTimeInfoEnabled")]
		bool RealTimeInfoEnabled { [Bind("isRealTimeInfoEnabled")] get; set; }
	}

	// @interface NMAUrbanMobilityDepartureFrequency : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityDepartureFrequency
	{
		// @property (readonly, nonatomic) NSUInteger maxScheduledInterval;
		[Export("maxScheduledInterval")]
		nuint MaxScheduledInterval { get; }

		// @property (readonly, nonatomic) NSUInteger minScheduledInterval;
		[Export("minScheduledInterval")]
		nuint MinScheduledInterval { get; }

		// @property (readonly, nonatomic) NSUInteger maxRealTimeInterval;
		[Export("maxRealTimeInterval")]
		nuint MaxRealTimeInterval { get; }

		// @property (readonly, nonatomic) NSUInteger minRealTimeInterval;
		[Export("minRealTimeInterval")]
		nuint MinRealTimeInterval { get; }
	}

	// @interface NMAUrbanMobilityExploredCoverage : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityExploredCoverage
	{
		// @property (readonly, nonatomic) NSInteger radius;
		[Export("radius")]
		nint Radius { get; }

		// @property (readonly, nonatomic) NSInteger stopsCount;
		[Export("stopsCount")]
		nint StopsCount { get; }

		// @property (readonly, nonatomic) NSInteger transportsCount;
		[Export("transportsCount")]
		nint TransportsCount { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityStation *> * _Nullable stations;
		[NullAllowed, Export("stations")]
		NMAUrbanMobilityStation[] Stations { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityTransport *> * _Nullable transports;
		[NullAllowed, Export("transports")]
		NMAUrbanMobilityTransport[] Transports { get; }
	}

	// @interface NMAUrbanMobilityFare : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityFare
	{
		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) double price;
		[Export("price")]
		double Price { get; }

		// @property (readonly, nonatomic) double maximumPrice;
		[Export("maximumPrice")]
		double MaximumPrice { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityFareType fareType;
		[Export("fareType")]
		NMAUrbanMobilityFareType FareType { get; }

		// @property (readonly, nonatomic) NSString * _Nullable reason;
		[NullAllowed, Export("reason")]
		string Reason { get; }

		// @property (readonly, getter = isEstimatedPrice, nonatomic) BOOL estimatedPrice;
		[Export("estimatedPrice")]
		bool EstimatedPrice { [Bind("isEstimatedPrice")] get; }

		// @property (readonly, nonatomic) NSString * _Nullable currency;
		[NullAllowed, Export("currency")]
		string Currency { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityLink *> * _Nullable links;
		[NullAllowed, Export("links")]
		NMAUrbanMobilityLink[] Links { get; }
	}

	// @interface NMAUrbanMobilityIntermediateStop : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityIntermediateStop
	{
		// @property (readonly, nonatomic) NMAUrbanMobilityStation * _Nullable station;
		[NullAllowed, Export("station")]
		NMAUrbanMobilityStation Station { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable scheduledDepartureTime;
		[NullAllowed, Export("scheduledDepartureTime")]
		NSDate ScheduledDepartureTime { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable scheduledArrivalTime;
		[NullAllowed, Export("scheduledArrivalTime")]
		NSDate ScheduledArrivalTime { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable actualDepartureTime;
		[NullAllowed, Export("actualDepartureTime")]
		NSDate ActualDepartureTime { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable actualArrivalTime;
		[NullAllowed, Export("actualArrivalTime")]
		NSDate ActualArrivalTime { get; }
	}

	// @interface NMAUrbanMobilityLink : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityLink
	{
		// @property (readonly, nonatomic) NSString * _Nullable text;
		[NullAllowed, Export("text")]
		string Text { get; }

		// @property (readonly, nonatomic) NSURL * _Nullable url;
		[NullAllowed, Export("url")]
		NSUrl Url { get; }

		// @property (readonly, nonatomic) NSString * _Nullable urlText;
		[NullAllowed, Export("urlText")]
		string UrlText { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityLinkType linkType;
		[Export("linkType")]
		NMAUrbanMobilityLinkType LinkType { get; }
	}

	// @interface NMAUrbanMobilityManeuver : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityManeuver
	{
		// @property (readonly, nonatomic) NMAUrbanMobilityManeuverDirection direction;
		[Export("direction")]
		NMAUrbanMobilityManeuverDirection Direction { get; }

		// @property (readonly, nonatomic) NSString * _Nullable nextRoadName;
		[NullAllowed, Export("nextRoadName")]
		string NextRoadName { get; }

		// @property (readonly, nonatomic) NSString * _Nullable nextRoadNumber;
		[NullAllowed, Export("nextRoadNumber")]
		string NextRoadNumber { get; }

		// @property (readonly, nonatomic) NSString * _Nullable instruction;
		[NullAllowed, Export("instruction")]
		string Instruction { get; }

		// @property (readonly, nonatomic) NMAManeuverAction action;
		[Export("action")]
		NMAManeuverAction Action { get; }

		// @property (readonly, nonatomic) NSTimeInterval duration;
		[Export("duration")]
		double Duration { get; }

		// @property (readonly, nonatomic) NSUInteger distance;
		[Export("distance")]
		nuint Distance { get; }

		// @property (readonly, nonatomic) NSArray<NMAGeoCoordinates *> * _Nullable geometry;
		[NullAllowed, Export("geometry")]
		NMAGeoCoordinates[] Geometry { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nullable boundingBox;
		[NullAllowed, Export("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }
	}

	// @interface NMAUrbanMobilityNearbyCoverageResult : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityNearbyCoverageResult
	{
		// @property (readonly, nonatomic) NSString * _Nullable geoRef;
		[NullAllowed, Export("geoRef")]
		string GeoRef { get; }

		// @property (readonly, nonatomic) NSInteger radius;
		[Export("radius")]
		nint Radius { get; }

		// @property (readonly, nonatomic) NSInteger stopsCount;
		[Export("stopsCount")]
		nint StopsCount { get; }

		// @property (readonly, nonatomic) NSInteger linesCount;
		[Export("linesCount")]
		nint LinesCount { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityCoverageType type;
		[Export("type")]
		NMAUrbanMobilityCoverageType Type { get; }

		// @property (readonly, getter = isCovered, nonatomic) BOOL covered;
		[Export("covered")]
		bool Covered { [Bind("isCovered")] get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityExploredCoverage * _Nullable exploredCoverage;
		[NullAllowed, Export("exploredCoverage")]
		NMAUrbanMobilityExploredCoverage ExploredCoverage { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityCity * _Nullable city;
		[NullAllowed, Export("city")]
		NMAUrbanMobilityCity City { get; }
	}

	// @interface NMAUrbanMobilityMissingCoverage : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityMissingCoverage
	{
		// @property (readonly, nonatomic) NMAUrbanMobilityCoverageType type;
		[Export("type")]
		NMAUrbanMobilityCoverageType Type { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityTransport *> * _Nullable transports;
		[NullAllowed, Export("transports")]
		NMAUrbanMobilityTransport[] Transports { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityOperator *> * _Nullable operators;
		[NullAllowed, Export("operators")]
		NMAUrbanMobilityOperator[] Operators { get; }
	}

	// typedef void (^NMAUrbanMobilityMultiBoardCompletionBlock)(NSArray<NMAUrbanMobilityStationWithDepartureBoard *> * _Nullable, NSArray<NMAUrbanMobilityTransport *> * _Nullable, NSError * _Nullable);
	delegate void NMAUrbanMobilityMultiBoardCompletionBlock([NullAllowed] NMAUrbanMobilityStationWithDepartureBoard[] arg0, [NullAllowed] NMAUrbanMobilityTransport[] arg1, [NullAllowed] NSError arg2);

	// @interface NMAUrbanMobilityMultiBoardRequest : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityMultiBoardRequest
	{
		// -(instancetype _Nonnull)initWithLocation:(NMAGeoCoordinates * _Nonnull)location;
		[Export("initWithLocation:")]
		IntPtr Constructor(NMAGeoCoordinates location);

		// -(instancetype _Nonnull)initWithStationIds:(NSArray<NSString *> * _Nonnull)stationIds;
		[Export("initWithStationIds:")]
		IntPtr Constructor(string[] stationIds);

		// -(BOOL)startWithCompletionBlock:(NMAUrbanMobilityMultiBoardCompletionBlock _Nonnull)completion;
		[Export("startWithCompletionBlock:")]
		bool StartWithCompletionBlock(NMAUrbanMobilityMultiBoardCompletionBlock completion);

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable location;
		[NullAllowed, Export("location")]
		NMAGeoCoordinates Location { get; }

		// @property (readonly, nonatomic) NSArray<NSString *> * _Nullable stationIds;
		[NullAllowed, Export("stationIds")]
		string[] StationIds { get; }

		// @property (nonatomic) NSDate * _Nullable departureTime;
		[NullAllowed, Export("departureTime", ArgumentSemantic.Assign)]
		NSDate DepartureTime { get; set; }

		// @property (getter = isRealTimeInfoEnabled, nonatomic) BOOL realTimeInfoEnabled;
		[Export("realTimeInfoEnabled")]
		bool RealTimeInfoEnabled { [Bind("isRealTimeInfoEnabled")] get; set; }

		// @property (nonatomic) NSInteger radius;
		[Export("radius")]
		nint Radius { get; set; }

		// @property (nonatomic) NSSet<NSNumber *> * _Nullable transportTypes;
		[NullAllowed, Export("transportTypes", ArgumentSemantic.Assign)]
		NSSet<NSNumber> TransportTypes { get; set; }

		// @property (nonatomic) NSUInteger maxDeparturesPerStation;
		[Export("maxDeparturesPerStation")]
		nuint MaxDeparturesPerStation { get; set; }

		// @property (nonatomic) NSUInteger maximumResults;
		[Export("maximumResults")]
		nuint MaximumResults { get; set; }
	}

	// typedef void (^NMAUrbanMobilityNearbyCoverageRequestCompletionBlock)(NMAUrbanMobilityNearbyCoverageResult * _Nullable, NSError * _Nullable);
	delegate void NMAUrbanMobilityNearbyCoverageRequestCompletionBlock([NullAllowed] NMAUrbanMobilityNearbyCoverageResult arg0, [NullAllowed] NSError arg1);

	// @interface NMAUrbanMobilityNearbyCoverageRequest : NMAUrbanMobilitySearchRequest
	[BaseType(typeof(NMAUrbanMobilitySearchRequest))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityNearbyCoverageRequest
	{
		// -(instancetype _Nonnull)initWithLocation:(NMAGeoCoordinates * _Nonnull)location;
		[Export("initWithLocation:")]
		IntPtr Constructor(NMAGeoCoordinates location);

		// -(BOOL)startWithCompletionBlock:(NMAUrbanMobilityNearbyCoverageRequestCompletionBlock _Nonnull)completion;
		[Export("startWithCompletionBlock:")]
		bool StartWithCompletionBlock(NMAUrbanMobilityNearbyCoverageRequestCompletionBlock completion);
	}

	// @interface NMAUrbanMobilityOperator : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityOperator
	{
		// @property (readonly, nonatomic) NSString * _Nullable code;
		[NullAllowed, Export("code")]
		string Code { get; }

		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityOperatorType type;
		[Export("type")]
		NMAUrbanMobilityOperatorType Type { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityLink *> * _Nullable disclaimers;
		[NullAllowed, Export("disclaimers")]
		NMAUrbanMobilityLink[] Disclaimers { get; }
	}

	// @interface NMAUrbanMobilityPlace : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityPlace
	{
		// @property (readonly, nonatomic) NMAUrbanMobilityAddress * _Nullable address;
		[NullAllowed, Export("address")]
		NMAUrbanMobilityAddress Address { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityFeatureAvailability blindGuideAvailability;
		[Export("blindGuideAvailability")]
		NMAUrbanMobilityFeatureAvailability BlindGuideAvailability { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityFeatureAvailability elevatorAvailability;
		[Export("elevatorAvailability")]
		NMAUrbanMobilityFeatureAvailability ElevatorAvailability { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityFeatureAvailability escalatorAvailability;
		[Export("escalatorAvailability")]
		NMAUrbanMobilityFeatureAvailability EscalatorAvailability { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityTransport *> * _Nullable transports;
		[NullAllowed, Export("transports")]
		NMAUrbanMobilityTransport[] Transports { get; }

		// @property (readonly, nonatomic) NSUInteger distanceFromCurrentLocation;
		[Export("distanceFromCurrentLocation")]
		nuint DistanceFromCurrentLocation { get; }

		// @property (readonly, nonatomic) NSTimeInterval durationFromCurrentLocation;
		[Export("durationFromCurrentLocation")]
		double DurationFromCurrentLocation { get; }

		// @property (readonly, nonatomic) NSString * _Nullable info;
		[NullAllowed, Export("info")]
		string Info { get; }
	}

	// @interface NMAUrbanMobilityProvider : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityProvider
	{
		// @property (readonly, nonatomic) NSString * _Nonnull name;
		[Export("name")]
		string Name { get; }
	}

	// @interface NMAUrbanMobilityRealTimeInfo : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityRealTimeInfo
	{
		// @property (readonly, nonatomic) NSDate * _Nullable departureTime;
		[NullAllowed, Export("departureTime")]
		NSDate DepartureTime { get; }

		// @property (readonly, nonatomic) NSDate * _Nullable arrivalTime;
		[NullAllowed, Export("arrivalTime")]
		NSDate ArrivalTime { get; }

		// @property (readonly, nonatomic) NSString * _Nullable platform;
		[NullAllowed, Export("platform")]
		string Platform { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityRealTimeInfoStatus status;
		[Export("status")]
		NMAUrbanMobilityRealTimeInfoStatus Status { get; }
	}

	// @interface NMAUrbanMobilityRequestManager : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityRequestManager
	{
		// +(NMAUrbanMobilityRequestManager * _Nonnull)sharedRequestManager;
		[Static]
		[Export("sharedRequestManager")]
		//[Verify(MethodToProperty)]
		NMAUrbanMobilityRequestManager SharedRequestManager { get; }

		// -(NMAUrbanMobilityStationSearchRequest * _Nonnull)createStationSearchRequestWithLocation:(NMAGeoCoordinates * _Nonnull)location;
		[Export("createStationSearchRequestWithLocation:")]
		NMAUrbanMobilityStationSearchRequest CreateStationSearchRequestWithLocation(NMAGeoCoordinates location);

		// -(NMAUrbanMobilityStationSearchRequest * _Nonnull)createStationSearchRequestWithIds:(NSArray<NSString *> * _Nonnull)stationIds;
		[Export("createStationSearchRequestWithIds:")]
		NMAUrbanMobilityStationSearchRequest CreateStationSearchRequestWithIds(string[] stationIds);

		// -(NMAUrbanMobilityMultiBoardRequest * _Nonnull)createMultiBoardRequestWithLocation:(NMAGeoCoordinates * _Nonnull)location;
		[Export("createMultiBoardRequestWithLocation:")]
		NMAUrbanMobilityMultiBoardRequest CreateMultiBoardRequestWithLocation(NMAGeoCoordinates location);

		// -(NMAUrbanMobilityMultiBoardRequest * _Nonnull)createMultiBoardRequestWithStationIds:(NSArray<NSString *> * _Nonnull)stationIds;
		[Export("createMultiBoardRequestWithStationIds:")]
		NMAUrbanMobilityMultiBoardRequest CreateMultiBoardRequestWithStationIds(string[] stationIds);

		// -(NMAUrbanMobilityDepartureBoardRequest * _Nonnull)createDepartureBoardRequestWithStationId:(NSString * _Nonnull)stationId location:(NMAGeoCoordinates * _Nonnull)location;
		[Export("createDepartureBoardRequestWithStationId:location:")]
		NMAUrbanMobilityDepartureBoardRequest CreateDepartureBoardRequestWithStationId(string stationId, NMAGeoCoordinates location);

		// -(NMAUrbanMobilityCitySearchRequest * _Nonnull)createCitySearchRequestWithCity:(NSString * _Nonnull)cityName;
		[Export("createCitySearchRequestWithCity:")]
		NMAUrbanMobilityCitySearchRequest CreateCitySearchRequestWithCity(string cityName);

		// -(NMAUrbanMobilityCityCoverageRequest * _Nonnull)createCityCoverageRequest;
		[Export("createCityCoverageRequest")]
		//[Verify(MethodToProperty)]
		NMAUrbanMobilityCityCoverageRequest CreateCityCoverageRequest { get; }

		// -(NMAUrbanMobilityNearbyCoverageRequest * _Nonnull)createNearbyCoverageRequestForLocation:(NMAGeoCoordinates * _Nonnull)location;
		[Export("createNearbyCoverageRequestForLocation:")]
		NMAUrbanMobilityNearbyCoverageRequest CreateNearbyCoverageRequestForLocation(NMAGeoCoordinates location);
	}

	// @interface NMAUrbanMobilityRouteResult : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityRouteResult
	{
		// @property (readonly, nonatomic) NSArray<NMARoute *> * _Nonnull routes;
		[Export("routes")]
		NMARoute[] Routes { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull errorMessage;
		[Export("errorMessage")]
		string ErrorMessage { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityOperator *> * _Nonnull operators;
		[Export("operators")]
		NMAUrbanMobilityOperator[] Operators { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityLink *> * _Nonnull operatorDisclaimers;
		[Export("operatorDisclaimers")]
		NMAUrbanMobilityLink[] OperatorDisclaimers { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityAlert *> * _Nonnull alerts;
		[Export("alerts")]
		NMAUrbanMobilityAlert[] Alerts { get; }

		// @property (readonly, getter = isSubsequentRouteSupported, nonatomic) BOOL subsequentRouteSupported;
		[Export("subsequentRouteSupported")]
		bool SubsequentRouteSupported { [Bind("isSubsequentRouteSupported")] get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityViolatedOption violatedOptions;
		[Export("violatedOptions")]
		NMAUrbanMobilityViolatedOption ViolatedOptions { get; }
	}

	// @interface NMAUrbanMobilityRouteSection : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityRouteSection
	{
		// @property (readonly, nonatomic) NSString * _Nonnull sectionId;
		[Export("sectionId")]
		string SectionId { get; }

		// @property (readonly, nonatomic) NSArray<NMAGeoCoordinates *> * _Nonnull geometry;
		[Export("geometry")]
		NMAGeoCoordinates[] Geometry { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityDeparture * _Nonnull departure;
		[Export("departure")]
		NMAUrbanMobilityDeparture Departure { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityArrival * _Nonnull arrival;
		[Export("arrival")]
		NMAUrbanMobilityArrival Arrival { get; }

		// @property (readonly, nonatomic) NSUInteger distance;
		[Export("distance")]
		nuint Distance { get; }

		// @property (readonly, nonatomic) NSTimeInterval duration;
		[Export("duration")]
		double Duration { get; }

		// @property (readonly, getter = isTimeUncertain, nonatomic) BOOL timeUncertain;
		[Export("timeUncertain")]
		bool TimeUncertain { [Bind("isTimeUncertain")] get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityManeuver *> * _Nonnull maneuvers;
		[Export("maneuvers")]
		NMAUrbanMobilityManeuver[] Maneuvers { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityLink *> * _Nonnull operatorDisclaimers;
		[Export("operatorDisclaimers")]
		NMAUrbanMobilityLink[] OperatorDisclaimers { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityAlert *> * _Nonnull alerts;
		[Export("alerts")]
		NMAUrbanMobilityAlert[] Alerts { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityFare *> * _Nonnull fares;
		[Export("fares")]
		NMAUrbanMobilityFare[] Fares { get; }

		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityIntermediateStop *> * _Nonnull intermediateStops;
		[Export("intermediateStops")]
		NMAUrbanMobilityIntermediateStop[] IntermediateStops { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityTransportType transportType;
		[Export("transportType")]
		NMAUrbanMobilityTransportType TransportType { get; }
	}

	// typedef void (^NMAUrbanMobilityCalculateResultBlock)(NMAUrbanMobilityRouteResult * _Nullable, NMAUrbanMobilityError);
	delegate void NMAUrbanMobilityCalculateResultBlock([NullAllowed] NMAUrbanMobilityRouteResult arg0, NMAUrbanMobilityError arg1);

	// @interface NMAUrbanMobilityRouter : NMARouter
	[BaseType(typeof(NMARouter))]
	interface NMAUrbanMobilityRouter
	{
		// +(instancetype _Nonnull)new;
		[Static]
		[Export("new")]
		NMAUrbanMobilityRouter New();

		// -(NSProgress * _Nullable)calculateRouteWithStops:(NSArray<NMAWaypoint *> * _Nonnull)stops routingMode:(NMARoutingMode * _Nonnull)mode completionBlock:(NMAUrbanMobilityCalculateResultBlock _Nonnull)completion;
		[Export("calculateRouteWithStops:routingMode:completionBlock:")]
		[return: NullAllowed]
		NSProgress CalculateRouteWithStops(NMAWaypoint[] stops, NMARoutingMode mode, NMAUrbanMobilityCalculateResultBlock completion);

		// -(NSProgress * _Nullable)calculateSubsequentRouteWithRouteResult:(NMAUrbanMobilityRouteResult * _Nonnull)routeResult withSubsequentRouteType:(NMASubsequentRouteType)subsequentRouteType withRouteCount:(NSUInteger)routeCount completionBlock:(NMAUrbanMobilityCalculateResultBlock _Nonnull)completion;
		[Export("calculateSubsequentRouteWithRouteResult:withSubsequentRouteType:withRouteCount:completionBlock:")]
		[return: NullAllowed]
		NSProgress CalculateSubsequentRouteWithRouteResult(NMAUrbanMobilityRouteResult routeResult, NMASubsequentRouteType subsequentRouteType, nuint routeCount, NMAUrbanMobilityCalculateResultBlock completion);

		// @property (nonatomic) NMAUrbanMobilityRouterConnectivity connectivity;
		[Export("connectivity", ArgumentSemantic.Assign)]
		NMAUrbanMobilityRouterConnectivity Connectivity { get; set; }
	}

	// @interface NMAUrbanMobilityStation : NMAUrbanMobilityPlace
	[BaseType(typeof(NMAUrbanMobilityPlace))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityStation
	{
		// @property (readonly, nonatomic) NSString * _Nonnull stationId;
		[Export("stationId")]
		string StationId { get; }

		// @property (readonly, getter = isDepartureBoardAvailable, nonatomic) BOOL departureBoardAvailable;
		[Export("departureBoardAvailable")]
		bool DepartureBoardAvailable { [Bind("isDepartureBoardAvailable")] get; }
	}

	// typedef void (^NMAUrbanMobilityStationSearchCompletionBlock)(NSArray<NMAUrbanMobilityStation *> * _Nullable, NSError * _Nullable);
	delegate void NMAUrbanMobilityStationSearchCompletionBlock([NullAllowed] NMAUrbanMobilityStation[] arg0, [NullAllowed] NSError arg1);

	// @interface NMAUrbanMobilityStationSearchRequest : NMAUrbanMobilitySearchRequest
	[BaseType(typeof(NMAUrbanMobilitySearchRequest))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityStationSearchRequest
	{
		// -(instancetype _Nonnull)initWithLocation:(NMAGeoCoordinates * _Nonnull)location;
		[Export("initWithLocation:")]
		IntPtr Constructor(NMAGeoCoordinates location);

		// -(instancetype _Nonnull)initWithStationIds:(NSArray<NSString *> * _Nonnull)stationIds;
		[Export("initWithStationIds:")]
		IntPtr Constructor(string[] stationIds);

		// -(BOOL)startWithCompletionBlock:(NMAUrbanMobilityStationSearchCompletionBlock _Nonnull)completion;
		[Export("startWithCompletionBlock:")]
		bool StartWithCompletionBlock(NMAUrbanMobilityStationSearchCompletionBlock completion);

		// @property (readonly, nonatomic) NSArray<NSString *> * _Nullable stationIds;
		[NullAllowed, Export("stationIds")]
		string[] StationIds { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nullable location;
		[NullAllowed, Export("location")]
		NMAGeoCoordinates Location { get; }

		// @property (nonatomic) NSUInteger searchRange;
		[Export("searchRange")]
		nuint SearchRange { get; set; }

		// @property (nonatomic) NSString * _Nullable stationName;
		[NullAllowed, Export("stationName")]
		string StationName { get; set; }

		// @property (nonatomic) NMAUrbanMobilitySearchNameMatchingMethod nameMatchingMethod;
		[Export("nameMatchingMethod", ArgumentSemantic.Assign)]
		NMAUrbanMobilitySearchNameMatchingMethod NameMatchingMethod { get; set; }
	}

	// @interface NMAUrbanMobilityStationWithDepartureBoard : NMAUrbanMobilityStation
	[BaseType(typeof(NMAUrbanMobilityStation))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityStationWithDepartureBoard
	{
		// @property (readonly, nonatomic) NMAUrbanMobilityDepartureBoard * _Nullable departureBoard;
		[NullAllowed, Export("departureBoard")]
		NMAUrbanMobilityDepartureBoard DepartureBoard { get; }
	}

	// @interface NMAUrbanMobilityTariff : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityTariff
	{
		// @property (readonly, nonatomic) NSArray<NMAUrbanMobilityFare *> * _Nullable fares;
		[NullAllowed, Export("fares")]
		NMAUrbanMobilityFare[] Fares { get; }
	}

	// @interface NMAUrbanMobilityTransport : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAUrbanMobilityTransport
	{
		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityTransportType transportType;
		[Export("transportType")]
		NMAUrbanMobilityTransportType TransportType { get; }

		// @property (readonly, nonatomic) NSString * _Nullable transportTypeName;
		[NullAllowed, Export("transportTypeName")]
		string TransportTypeName { get; }

		// @property (readonly, nonatomic) NSString * _Nullable direction;
		[NullAllowed, Export("direction")]
		string Direction { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityOperator * _Nullable transportOperator;
		[NullAllowed, Export("transportOperator")]
		NMAUrbanMobilityOperator TransportOperator { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityFeatureAvailability bikeAllowed;
		[Export("bikeAllowed")]
		NMAUrbanMobilityFeatureAvailability BikeAllowed { get; }

		// @property (readonly, nonatomic) NMAUrbanMobilityFeatureAvailability barrierFree;
		[Export("barrierFree")]
		NMAUrbanMobilityFeatureAvailability BarrierFree { get; }

		// @property (readonly, nonatomic) UIColor * _Nullable color;
		[NullAllowed, Export("color")]
		UIColor Color { get; }

		// @property (readonly, nonatomic) UIColor * _Nullable textColor;
		[NullAllowed, Export("textColor")]
		UIColor TextColor { get; }

		// @property (readonly, nonatomic) UIColor * _Nullable outlineColor;
		[NullAllowed, Export("outlineColor")]
		UIColor OutlineColor { get; }
	}

	// @interface NMAVenue3dAccount : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dAccount
	{
		// @property (readonly, nonatomic) NSString * _Nonnull uniqueId;
		[Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull description;
		[Export("description")]
		string Description { get; }
	}

	// @interface NMAVenue3dSpatialObject : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dSpatialObject
	{
		// @property (readonly, nonatomic) NSString * _Nonnull uniqueId;
		[Export("uniqueId")]
		string UniqueId { get; }
	}

	// @interface NMAVenue3dArea : NMAVenue3dSpatialObject
	[BaseType(typeof(NMAVenue3dSpatialObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dArea
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull geoCenter;
		[Export("geoCenter")]
		NMAGeoCoordinates GeoCenter { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readonly, nonatomic) NMAGeoPolygon * _Nullable polygon;
		[NullAllowed, Export("polygon")]
		NMAGeoPolygon Polygon { get; }

		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }
	}

	// @interface NMAVenue3dBaseLocation : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dBaseLocation
	{
		// -(void)setParkingLocation:(NMAVenue3dBaseLocation * _Nonnull)location;
		[Export("setParkingLocation:")]
		void SetParkingLocation(NMAVenue3dBaseLocation location);

		// -(BOOL)isValid;
		[Export("isValid")]
		//[Verify(MethodToProperty)]
		bool IsValid { get; }

		// -(NMAVenue3dArea * _Nullable)getArea;
		[NullAllowed, Export("getArea")]
		//[Verify(MethodToProperty)]
		NMAVenue3dArea Area { get; }

		// -(NMAGeoCoordinates * _Nullable)getGeoCoordinate;
		[NullAllowed, Export("getGeoCoordinate")]
		//[Verify(MethodToProperty)]
		NMAGeoCoordinates GeoCoordinate { get; }

		// -(NMAVenue3dBaseLocationType)getType;
		[Export("getType")]
		//[Verify(MethodToProperty)]
		NMAVenue3dBaseLocationType Type { get; }
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const double NMAVenue3dCombinedNavigationManagerInvalidValue;
		[Field("NMAVenue3dCombinedNavigationManagerInvalidValue", "__Internal")]
		double NMAVenue3dCombinedNavigationManagerInvalidValue { get; }
	}

	// @protocol NMAVenue3dCombinedNavigationListener <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dCombinedNavigationListener
	{
		// @optional -(void)navigationManagerDidReachDestination:(NMAVenue3dCombinedNavigation * _Nonnull)navigationManager;
		[Export("navigationManagerDidReachDestination:")]
		void NavigationManagerDidReachDestination(NMAVenue3dCombinedNavigation navigationManager);

		// @optional -(void)navigationManager:(NMAVenue3dCombinedNavigation * _Nonnull)navigationManager didUpdateCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export("navigationManager:didUpdateCombinedRoute:")]
		void NavigationManager(NMAVenue3dCombinedNavigation navigationManager, NMAVenue3dCombinedRoute combinedRoute);

		// @optional -(void)navigationManager:(NMAVenue3dCombinedNavigation * _Nonnull)navigationManager willStartIndoorSection:(NMAVenue3dVenueRouteSection * _Nonnull)indoorSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export("navigationManager:willStartIndoorSection:inCombinedRoute:")]
		void NavigationManager(NMAVenue3dCombinedNavigation navigationManager, NMAVenue3dVenueRouteSection indoorSection, NMAVenue3dCombinedRoute combinedRoute);

		// @optional -(void)navigationManager:(NMAVenue3dCombinedNavigation * _Nonnull)navigationManager willStartLinkingSection:(NMAVenue3dLinkRouteSection * _Nonnull)linkingSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export("navigationManager:willStartLinkingSection:inCombinedRoute:")]
		void NavigationManager(NMAVenue3dCombinedNavigation navigationManager, NMAVenue3dLinkRouteSection linkingSection, NMAVenue3dCombinedRoute combinedRoute);

		// @optional -(void)navigationManager:(NMAVenue3dCombinedNavigation * _Nonnull)navigationManager willStartOutdoorSection:(NMAVenue3dOutdoorRouteSection * _Nonnull)outdoorSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export("navigationManager:willStartOutdoorSection:inCombinedRoute:")]
		void NavigationManager(NMAVenue3dCombinedNavigation navigationManager, NMAVenue3dOutdoorRouteSection outdoorSection, NMAVenue3dCombinedRoute combinedRoute);
	}

	// @interface NMAVenue3dCombinedNavigation : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dCombinedNavigation
	{
		// @property (readonly, nonatomic) NMAVenue3dCombinedNavigationState navigationState;
		[Export("navigationState")]
		NMAVenue3dCombinedNavigationState NavigationState { get; }

		// @property (getter = isPaused, nonatomic) BOOL paused;
		[Export("paused")]
		bool Paused { [Bind("isPaused")] get; set; }

		// @property (readonly, nonatomic, weak) NMAVenue3dMapLayer * _Nullable venueMapLayer;
		[NullAllowed, Export("venueMapLayer", ArgumentSemantic.Weak)]
		NMAVenue3dMapLayer VenueMapLayer { get; }

		// @property (readonly, nonatomic) NMAVenue3dCombinedNavigationType currentNavigationType;
		[Export("currentNavigationType")]
		NMAVenue3dCombinedNavigationType CurrentNavigationType { get; }

		// @property (readonly, nonatomic) double distanceToDestination;
		[Export("distanceToDestination")]
		double DistanceToDestination { get; }

		// @property (readonly, nonatomic) double distanceFromStart;
		[Export("distanceFromStart")]
		double DistanceFromStart { get; }

		// -(void)addListener:(id<NMAVenue3dCombinedNavigationListener> _Nonnull)listener;
		[Export("addListener:")]
		void AddListener(NMAVenue3dCombinedNavigationListener listener);

		// -(void)removeListener:(id<NMAVenue3dCombinedNavigationListener> _Nonnull)listener;
		[Export("removeListener:")]
		void RemoveListener(NMAVenue3dCombinedNavigationListener listener);

		// -(BOOL)startForCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export("startForCombinedRoute:")]
		bool StartForCombinedRoute(NMAVenue3dCombinedRoute combinedRoute);

		// -(BOOL)simulateForCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute speed:(double)speed distortionEnabled:(BOOL)distortionEnabled updateInterval:(NSTimeInterval)updateInterval;
		[Export("simulateForCombinedRoute:speed:distortionEnabled:updateInterval:")]
		bool SimulateForCombinedRoute(NMAVenue3dCombinedRoute combinedRoute, double speed, bool distortionEnabled, double updateInterval);

		// -(void)stop;
		[Export("stop")]
		void Stop();
	}

	// @interface NMAVenue3dCombinedRoute : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dCombinedRoute
	{
		// @property (readonly, nonatomic) NSArray<NMAVenue3dRouteSection *> * _Nonnull routeSections;
		[Export("routeSections")]
		NMAVenue3dRouteSection[] RouteSections { get; }

		// -(BOOL)conformsConnectorOptions;
		[Export("conformsConnectorOptions")]
		//[Verify(MethodToProperty)]
		bool ConformsConnectorOptions { get; }

		// -(BOOL)conformsModeOptions;
		[Export("conformsModeOptions")]
		//[Verify(MethodToProperty)]
		bool ConformsModeOptions { get; }

		// -(NMAVenue3dRoutingError)getError;
		[Export("getError")]
		//[Verify(MethodToProperty)]
		NMAVenue3dRoutingError Error { get; }

		// -(NMARoutingError)getCoreMapError;
		[Export("getCoreMapError")]
		//[Verify(MethodToProperty)]
		NMARoutingError CoreMapError { get; }

		// -(NMAVenue3dBaseLocation * _Nonnull)getStart;
		[Export("getStart")]
		//[Verify(MethodToProperty)]
		NMAVenue3dBaseLocation Start { get; }

		// -(NMAVenue3dBaseLocation * _Nonnull)getEnd;
		[Export("getEnd")]
		//[Verify(MethodToProperty)]
		NMAVenue3dBaseLocation End { get; }

		// -(NSArray<NMAVenue3dBaseLocation *> * _Nonnull)getWaypoints;
		[Export("getWaypoints")]
		//[Verify(MethodToProperty)]
		NMAVenue3dBaseLocation[] Waypoints { get; }

		// -(NSInteger)getLength;
		[Export("getLength")]
		//[Verify(MethodToProperty)]
		nint Length { get; }
	}

	// @interface NMAVenue3dContent : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dContent
	{
		// @property (readonly, nonatomic) NSString * _Nullable name;
		[NullAllowed, Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) NSString * _Nullable phoneNumber;
		[NullAllowed, Export("phoneNumber")]
		string PhoneNumber { get; }

		// @property (readonly, nonatomic) NSString * _Nullable website;
		[NullAllowed, Export("website")]
		string Website { get; }

		// @property (readonly, nonatomic) NSString * _Nullable email;
		[NullAllowed, Export("email")]
		string Email { get; }

		// @property (readonly, nonatomic) NMAAddress * _Nonnull address;
		[Export("address")]
		NMAAddress Address { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull parentCategoryId;
		[Export("parentCategoryId")]
		string ParentCategoryId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull placeCategoryId;
		[Export("placeCategoryId")]
		string PlaceCategoryId { get; }

		// @property (readonly, nonatomic) NSArray<NSString *> * _Nonnull searchTags;
		[Export("searchTags")]
		string[] SearchTags { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull uniqueVenueId;
		[Export("uniqueVenueId")]
		string UniqueVenueId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull uniqueId;
		[Export("uniqueId")]
		string UniqueId { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull categoryId;
		[Export("categoryId")]
		string CategoryId { get; }

		// @property (readonly, nonatomic) NSDictionary<NSString *,NSObject *> * _Nullable customAttributes;
		[NullAllowed, Export("customAttributes")]
		NSDictionary<NSString, NSObject> CustomAttributes { get; }
	}

	// @interface NMAVenue3dController : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dController
	{
		// @property (readonly, nonatomic) NMAVenue3dVenue * _Nonnull venue;
		[Export("venue")]
		NMAVenue3dVenue Venue { get; }

		// @property (readonly, nonatomic) NMAVenue3dLevel * _Nonnull groundLevel;
		[Export("groundLevel")]
		NMAVenue3dLevel GroundLevel { get; }

		// @property (nonatomic, weak) NMAVenue3dLevel * _Nullable level;
		[NullAllowed, Export("level", ArgumentSemantic.Weak)]
		NMAVenue3dLevel Level { get; set; }

		// @property (nonatomic, weak) NMAVenue3dSpace * _Nullable space;
		[NullAllowed, Export("space", ArgumentSemantic.Weak)]
		NMAVenue3dSpace Space { get; set; }

		// -(void)deselectSpace;
		[Export("deselectSpace")]
		void DeselectSpace();

		// @property (nonatomic) NMAVenue3dStyleSettings * _Nullable styleSettings;
		[NullAllowed, Export("styleSettings", ArgumentSemantic.Assign)]
		NMAVenue3dStyleSettings StyleSettings { get; set; }

		// -(NMAVenue3dStyleSettings * _Nullable)getStyleSettingsForSpace:(NMAVenue3dSpace * _Nonnull)space;
		[Export("getStyleSettingsForSpace:")]
		[return: NullAllowed]
		NMAVenue3dStyleSettings GetStyleSettingsForSpace(NMAVenue3dSpace space);

		// -(void)setStyleSettings:(NMAVenue3dStyleSettings * _Nullable)settings forSpace:(NMAVenue3dSpace * _Nonnull)space;
		[Export("setStyleSettings:forSpace:")]
		void SetStyleSettings([NullAllowed] NMAVenue3dStyleSettings settings, NMAVenue3dSpace space);

		// -(NMAVenue3dBaseLocation * _Nullable)getLocationAtX:(float)x Y:(float)y WithSpacePrefered:(_Bool)preferSpace;
		[Export("getLocationAtX:Y:WithSpacePrefered:")]
		[return: NullAllowed]
		NMAVenue3dBaseLocation GetLocationAtX(float x, float y, bool preferSpace);
	}

	// @interface NMAVenue3dLevel : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dLevel
	{
		// @property (readonly, nonatomic) NSArray<NMAVenue3dOuterArea *> * _Nonnull outerAreas;
		[Export("outerAreas")]
		NMAVenue3dOuterArea[] OuterAreas { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull geoCenter;
		[Export("geoCenter")]
		NMAGeoCoordinates GeoCenter { get; }

		// @property (readonly, nonatomic) NSArray<NMAVenue3dSpace *> * _Nonnull spaces;
		[Export("spaces")]
		NMAVenue3dSpace[] Spaces { get; }

		// @property (readonly, nonatomic) NSArray<NMAVenue3dSpace *> * _Nonnull spacesAndFacilities;
		[Export("spacesAndFacilities")]
		NMAVenue3dSpace[] SpacesAndFacilities { get; }

		// -(NSArray<NMAVenue3dSpace *> * _Nonnull)spacesWithCategory:(NSString * _Nonnull)categoryName;
		[Export("spacesWithCategory:")]
		NMAVenue3dSpace[] SpacesWithCategory(string categoryName);

		// @property (readonly, nonatomic) NSString * _Nonnull floorSynonym;
		[Export("floorSynonym")]
		string FloorSynonym { get; }

		// @property (readonly, nonatomic) NSInteger floorNumber;
		[Export("floorNumber")]
		nint FloorNumber { get; }

		// -(NMAVenue3dArea * _Nullable)areaAtPosition:(NMAGeoCoordinates * _Nonnull)position;
		[Export("areaAtPosition:")]
		[return: NullAllowed]
		NMAVenue3dArea AreaAtPosition(NMAGeoCoordinates position);

		// -(NSArray<NMAVenue3dSpace *> * _Nonnull)nearbySpacesAroundPosition:(NMAGeoCoordinates * _Nonnull)position withinRadius:(float)radius;
		[Export("nearbySpacesAroundPosition:withinRadius:")]
		NMAVenue3dSpace[] NearbySpacesAroundPosition(NMAGeoCoordinates position, float radius);
	}

	// @interface NMAVenue3dLevelLocation : NMAVenue3dBaseLocation
	[BaseType(typeof(NMAVenue3dBaseLocation))]
	[DisableDefaultCtor]
	interface NMAVenue3dLevelLocation
	{
		// +(instancetype _Nullable)levelLocationOnLevel:(NMAVenue3dLevel * _Nonnull)level withGeoCoordinate:(NMAGeoCoordinates * _Nonnull)geoCoordinates inVenue:(NMAVenue3dController * _Nonnull)controler;
		[Static]
		[Export("levelLocationOnLevel:withGeoCoordinate:inVenue:")]
		[return: NullAllowed]
		NMAVenue3dLevelLocation LevelLocationOnLevel(NMAVenue3dLevel level, NMAGeoCoordinates geoCoordinates, NMAVenue3dController controler);

		// -(instancetype _Nullable)initOnLevel:(NMAVenue3dLevel * _Nonnull)level withGeoCoordinate:(NMAGeoCoordinates * _Nonnull)geoCoordinates inVenue:(NMAVenue3dController * _Nonnull)venue;
		[Export("initOnLevel:withGeoCoordinate:inVenue:")]
		IntPtr Constructor(NMAVenue3dLevel level, NMAGeoCoordinates geoCoordinates, NMAVenue3dController venue);
	}

	// @interface NMAVenue3dRouteSection : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dRouteSection
	{
	}

	// @interface NMAVenue3dLinkRouteSection : NMAVenue3dRouteSection
	[BaseType(typeof(NMAVenue3dRouteSection))]
	[DisableDefaultCtor]
	interface NMAVenue3dLinkRouteSection
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull from;
		[Export("from")]
		NMAGeoCoordinates From { get; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull to;
		[Export("to")]
		NMAGeoCoordinates To { get; }
	}

	// @protocol NMAVenue3dMapLayerDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dMapLayerDelegate
	{
		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didTapVenue:(NMAVenue3dVenue * _Nonnull)venue atPoint:(CGPoint)point;
		[Export("venueMapLayer:didTapVenue:atPoint:")]
		void VenueMapLayerDidTapVenueAtPoint(NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue, CGPoint point);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didSelectVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export("venueMapLayer:didSelectVenue:")]
		void VenueMapLayerDidSelectVenue(NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didDeselectVenue:(NMAVenue3dVenue * _Nonnull)venue withEvent:(NMAVenue3dDeselectEvent)event;
		[Export("venueMapLayer:didDeselectVenue:withEvent:")]
		void VenueMapLayerDidDeselectVenueWithEvent(NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue, NMAVenue3dDeselectEvent @event);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didSelectSpace:(NMAVenue3dSpace * _Nonnull)space inVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export("venueMapLayer:didSelectSpace:inVenue:")]
		void VenueMapLayerDidSelectSpaceInVenue(NMAVenue3dMapLayer venueMapLayer, NMAVenue3dSpace space, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didDeselectSpace:(NMAVenue3dSpace * _Nonnull)space inVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export("venueMapLayer:didDeselectSpace:inVenue:")]
		void VenueMapLayerDidDeselectSpaceInVenue(NMAVenue3dMapLayer venueMapLayer, NMAVenue3dSpace space, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didChangeFromLevel:(NMAVenue3dLevel * _Nonnull)oldLevel toLevel:(NMAVenue3dLevel * _Nonnull)newLevel inVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export("venueMapLayer:didChangeFromLevel:toLevel:inVenue:")]
		void VenueMapLayerDidChangeFromLevelToLevelInVenue(NMAVenue3dMapLayer venueMapLayer, NMAVenue3dLevel oldLevel, NMAVenue3dLevel newLevel, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didShowVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export("venueMapLayer:didShowVenue:")]
		void VenueMapLayerDidShowVenue(NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didHideVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export("venueMapLayer:didHideVenue:")]
		void VenueMapLayerDidHideVenue(NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue);

		// @optional -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didCreateVenueController:(NMAVenue3dController * _Nonnull)venueController;
		[Export("venueMapLayer:didCreateVenueController:")]
		void VenueMapLayerDidCreateVenueController(NMAVenue3dMapLayer venueMapLayer, NMAVenue3dController venueController);

		// @optional -(void)venueMapLayerDidStart:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer;
		[Export("venueMapLayerDidStart:")]
		void VenueMapLayerDidStart(NMAVenue3dMapLayer venueMapLayer);
	}

	// @protocol NMAVenue3dVenueZoomDelegate <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dVenueZoomDelegate
	{
		// @required -(void)venueMapLayer:(NMAVenue3dMapLayer * _Nonnull)venueMapLayer didUpdateVenueZoomInVenue:(NMAVenue3dVenue * _Nonnull)venue withValue:(_Bool)active;
		[Abstract]
		[Export("venueMapLayer:didUpdateVenueZoomInVenue:withValue:")]
		void DidUpdateVenueZoomInVenue(NMAVenue3dMapLayer venueMapLayer, NMAVenue3dVenue venue, bool active);
	}

	// @interface NMAVenue3dMapLayer : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dMapLayer
	{
		[Wrap("WeakDelegate")]
		[NullAllowed]
		NMAVenue3dMapLayerDelegate Delegate { get; set; }

		// @property (nonatomic, weak) id<NMAVenue3dMapLayerDelegate> _Nullable delegate;
		[NullAllowed, Export("delegate", ArgumentSemantic.Weak)]
		NSObject WeakDelegate { get; set; }

		// -(void)addListener:(id<NMAVenue3dMapLayerDelegate> _Nonnull)listener;
		[Export("addListener:")]
		void AddListener(NMAVenue3dMapLayerDelegate listener);

		// -(void)removeListener:(id<NMAVenue3dMapLayerDelegate> _Nonnull)listener;
		[Export("removeListener:")]
		void RemoveListener(NMAVenue3dMapLayerDelegate listener);

		// @property (readonly, nonatomic) NMAVenue3dController * _Nullable venueController;
		[NullAllowed, Export("venueController")]
		NMAVenue3dController VenueController { get; }

		// @property (readonly, nonatomic) NMAVenue3dRoutingController * _Nullable venueRoutingController;
		[NullAllowed, Export("venueRoutingController")]
		NMAVenue3dRoutingController VenueRoutingController { get; }

		// @property (nonatomic) BOOL visible;
		[Export("visible")]
		bool Visible { get; set; }

		// @property (nonatomic) BOOL openMode;
		[Export("openMode")]
		bool OpenMode { get; set; }

		// @property (nonatomic) BOOL shouldCheckVenuesInViewport;
		[Export("shouldCheckVenuesInViewport")]
		bool ShouldCheckVenuesInViewport { get; set; }

		// @property (nonatomic) BOOL animatesFloorChange;
		[Export("animatesFloorChange")]
		bool AnimatesFloorChange { get; set; }

		// @property (nonatomic) BOOL animatesVenueSelection;
		[Export("animatesVenueSelection")]
		bool AnimatesVenueSelection { get; set; }

		// @property (nonatomic) BOOL hideIconOnSelectedSpace;
		[Export("hideIconOnSelectedSpace")]
		bool HideIconOnSelectedSpace { get; set; }

		// @property (nonatomic) BOOL venueUpdatesEnabled;
		[Export("venueUpdatesEnabled")]
		bool VenueUpdatesEnabled { get; set; }

		// @property (nonatomic) UIEdgeInsets margins;
		[Export("margins", ArgumentSemantic.Assign)]
		UIEdgeInsets Margins { get; set; }

		// @property (readonly, nonatomic) NMAPositionIndicator * _Nullable positionIndicator;
		[NullAllowed, Export("positionIndicator")]
		NMAPositionIndicator PositionIndicator { get; }

		// @property (readonly, nonatomic) NMAVenue3dNavigationManager * _Nonnull venueNavigationManager;
		[Export("venueNavigationManager")]
		NMAVenue3dNavigationManager VenueNavigationManager { get; }

		// @property (readonly, nonatomic) NMAVenue3dCombinedNavigation * _Nonnull combinedNavigation;
		[Export("combinedNavigation")]
		NMAVenue3dCombinedNavigation CombinedNavigation { get; }

		// -(void)start;
		[Export("start")]
		void Start();

		// -(NMAVenue3dController * _Nullable)controllerForVenue:(NMAVenue3dVenue * _Nullable)venue;
		[Export("controllerForVenue:")]
		[return: NullAllowed]
		NMAVenue3dController ControllerForVenue([NullAllowed] NMAVenue3dVenue venue);

		// -(void)selectVenue:(NMAVenue3dVenue * _Nonnull)venue;
		[Export("selectVenue:")]
		void SelectVenue(NMAVenue3dVenue venue);

		// -(NMAVenue3dVenueInfo * _Nullable)selectVenueWithVenueId:(NSString * _Nonnull)venueId;
		[Export("selectVenueWithVenueId:")]
		[return: NullAllowed]
		NMAVenue3dVenueInfo SelectVenueWithVenueId(string venueId);

		// -(NMAVenue3dVenueInfo * _Nullable)selectVenueWithVenueId:(NSString * _Nonnull)venueId spaceId:(NSString * _Nonnull)spaceId;
		[Export("selectVenueWithVenueId:spaceId:")]
		[return: NullAllowed]
		NMAVenue3dVenueInfo SelectVenueWithVenueId(string venueId, string spaceId);

		// -(BOOL)cancelVenueSelection;
		[Export("cancelVenueSelection")]
		//[Verify(MethodToProperty)]
		bool CancelVenueSelection { get; }

		// -(void)deselectVenue;
		[Export("deselectVenue")]
		void DeselectVenue();

		// -(BOOL)isVenueVisible:(NSString * _Nonnull)venueId;
		[Export("isVenueVisible:")]
		bool IsVenueVisible(string venueId);
	}

	//[Verify(ConstantsInterfaceAssociation)] 
	partial interface Constants
	{
		// extern const float NMAVenue3dNavigationManagerInvalidValue;
		[Field("NMAVenue3dNavigationManagerInvalidValue", "__Internal")]
		float NMAVenue3dNavigationManagerInvalidValue { get; }

		// extern const NSTimeInterval NMAVenue3dNavigationManagerInvalidTimeInterval;
		[Field("NMAVenue3dNavigationManagerInvalidTimeInterval", "__Internal")]
		double NMAVenue3dNavigationManagerInvalidTimeInterval { get; }
	}

	// @protocol NMAVenue3dNavigationListener <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dNavigationListener
	{
		// @optional -(void)navigationManagerDidReachDestination:(NMAVenue3dNavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerDidReachDestination:")]
		void NavigationManagerDidReachDestination(NMAVenue3dNavigationManager navigationManager);

		// @optional -(void)navigationManager:(NMAVenue3dNavigationManager * _Nonnull)navigationManager hasCurrentManeuver:(NMAVenue3dRouteManeuver * _Nullable)maneuver nextManeuver:(NMAVenue3dRouteManeuver * _Nullable)nextManeuver;
		[Export("navigationManager:hasCurrentManeuver:nextManeuver:")]
		void NavigationManager(NMAVenue3dNavigationManager navigationManager, [NullAllowed] NMAVenue3dRouteManeuver maneuver, [NullAllowed] NMAVenue3dRouteManeuver nextManeuver);

		// @optional -(void)navigationManagerDidLosePosition:(NMAVenue3dNavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerDidLosePosition:")]
		void NavigationManagerDidLosePosition(NMAVenue3dNavigationManager navigationManager);

		// @optional -(void)navigationManagerDidFindPosition:(NMAVenue3dNavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerDidFindPosition:")]
		void NavigationManagerDidFindPosition(NMAVenue3dNavigationManager navigationManager);

		// @optional -(void)navigationManager:(NMAVenue3dNavigationManager * _Nonnull)navigationManager didUpdateRouteSection:(NMAVenue3dVenueRouteSection * _Nonnull)routeSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export("navigationManager:didUpdateRouteSection:inCombinedRoute:")]
		void NavigationManager(NMAVenue3dNavigationManager navigationManager, NMAVenue3dVenueRouteSection routeSection, NMAVenue3dCombinedRoute combinedRoute);

		// @optional -(void)navigationManagerWillReroute:(NMAVenue3dNavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerWillReroute:")]
		void NavigationManagerWillReroute(NMAVenue3dNavigationManager navigationManager);

		// @optional -(void)navigationManagerDidReroute:(NMAVenue3dNavigationManager * _Nonnull)navigationManager;
		[Export("navigationManagerDidReroute:")]
		void NavigationManagerDidReroute(NMAVenue3dNavigationManager navigationManager);
	}

	// @interface NMAVenue3dNavigationManager : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dNavigationManager
	{
		// @property (readonly, nonatomic) NMAVenue3dNavigationState navigationState;
		[Export("navigationState")]
		NMAVenue3dNavigationState NavigationState { get; }

		// @property (getter = isPaused, nonatomic) BOOL paused;
		[Export("paused")]
		bool Paused { [Bind("isPaused")] get; set; }

		// @property (getter = isMapTrackingEnabled, nonatomic) BOOL mapTrackingEnabled;
		[Export("mapTrackingEnabled")]
		bool MapTrackingEnabled { [Bind("isMapTrackingEnabled")] get; set; }

		// @property (nonatomic) NMAVenue3dTrackingTilt mapTrackingTilt;
		[Export("mapTrackingTilt", ArgumentSemantic.Assign)]
		NMAVenue3dTrackingTilt MapTrackingTilt { get; set; }

		// @property (nonatomic) NMAVenue3dTrackingMode mapTrackingMode;
		[Export("mapTrackingMode", ArgumentSemantic.Assign)]
		NMAVenue3dTrackingMode MapTrackingMode { get; set; }

		// @property (readonly, nonatomic, weak) NMAVenue3dMapLayer * _Nullable venueMapLayer;
		[NullAllowed, Export("venueMapLayer", ArgumentSemantic.Weak)]
		NMAVenue3dMapLayer VenueMapLayer { get; }

		// @property (readonly, nonatomic, weak) NMAVenue3dVenue * _Nullable venue;
		[NullAllowed, Export("venue", ArgumentSemantic.Weak)]
		NMAVenue3dVenue Venue { get; }

		// @property (readonly, nonatomic) NMAVenue3dRouteManeuver * _Nullable currentManeuver;
		[NullAllowed, Export("currentManeuver")]
		NMAVenue3dRouteManeuver CurrentManeuver { get; }

		// @property (readonly, nonatomic) NMAVenue3dRouteManeuver * _Nullable nextManeuver;
		[NullAllowed, Export("nextManeuver")]
		NMAVenue3dRouteManeuver NextManeuver { get; }

		// @property (readonly, nonatomic) float distanceToCurrentManeuver;
		[Export("distanceToCurrentManeuver")]
		float DistanceToCurrentManeuver { get; }

		// @property (readonly, nonatomic) float distanceToNextManeuver;
		[Export("distanceToNextManeuver")]
		float DistanceToNextManeuver { get; }

		// @property (readonly, nonatomic) float distanceToDestination;
		[Export("distanceToDestination")]
		float DistanceToDestination { get; }

		// @property (readonly, nonatomic) float distanceFromStart;
		[Export("distanceFromStart")]
		float DistanceFromStart { get; }

		// @property (readonly, nonatomic) float averageSpeed;
		[Export("averageSpeed")]
		float AverageSpeed { get; }

		// @property (readonly, nonatomic) NSTimeInterval timeToArrival;
		[Export("timeToArrival")]
		double TimeToArrival { get; }

		// @property (nonatomic) NSTimeInterval reroutingTimeout;
		[Export("reroutingTimeout")]
		double ReroutingTimeout { get; set; }

		// @property (nonatomic) _Bool vibrationEnabled;
		[Export("vibrationEnabled")]
		bool VibrationEnabled { get; set; }

		// @property (nonatomic) _Bool beepsEnabled;
		[Export("beepsEnabled")]
		bool BeepsEnabled { get; set; }

		// @property (nonatomic) BOOL backgroundNavigationEnabled;
		[Export("backgroundNavigationEnabled")]
		bool BackgroundNavigationEnabled { get; set; }

		// @property (nonatomic) BOOL backgroundNavigationStartEnabled;
		[Export("backgroundNavigationStartEnabled")]
		bool BackgroundNavigationStartEnabled { get; set; }

		// -(void)addListener:(id<NMAVenue3dNavigationListener> _Nonnull)listener;
		[Export("addListener:")]
		void AddListener(NMAVenue3dNavigationListener listener);

		// -(void)removeListener:(id<NMAVenue3dNavigationListener> _Nonnull)listener;
		[Export("removeListener:")]
		void RemoveListener(NMAVenue3dNavigationListener listener);

		// -(BOOL)startForRouteSection:(NMAVenue3dVenueRouteSection * _Nonnull)routeSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export("startForRouteSection:inCombinedRoute:")]
		bool StartForRouteSection(NMAVenue3dVenueRouteSection routeSection, NMAVenue3dCombinedRoute combinedRoute);

		// -(BOOL)startForLinkSection:(NMAVenue3dLinkRouteSection * _Nonnull)linkSection inCombinedRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export("startForLinkSection:inCombinedRoute:")]
		bool StartForLinkSection(NMAVenue3dLinkRouteSection linkSection, NMAVenue3dCombinedRoute combinedRoute);

		// -(void)stop;
		[Export("stop")]
		void Stop();

		// @property (readwrite, nonatomic) BOOL maneuverZoomEnabled;
		[Export("maneuverZoomEnabled")]
		bool ManeuverZoomEnabled { get; set; }

		// @property (readwrite, nonatomic) float maneuverZoomDistance;
		[Export("maneuverZoomDistance")]
		float ManeuverZoomDistance { get; set; }

		// @property (readwrite, nonatomic) float maneuverZoomLevel;
		[Export("maneuverZoomLevel")]
		float ManeuverZoomLevel { get; set; }
	}

	// @interface NMAVenue3dOutdoorLocation : NMAVenue3dBaseLocation
	[BaseType(typeof(NMAVenue3dBaseLocation))]
	[DisableDefaultCtor]
	interface NMAVenue3dOutdoorLocation
	{
		// +(instancetype _Nonnull)outdoorLocationWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)geoCoordinates;
		[Static]
		[Export("outdoorLocationWithGeoCoordinates:")]
		NMAVenue3dOutdoorLocation OutdoorLocationWithGeoCoordinates(NMAGeoCoordinates geoCoordinates);

		// -(instancetype _Nonnull)initWithGeoCoordinates:(NMAGeoCoordinates * _Nonnull)geoCoordinates;
		[Export("initWithGeoCoordinates:")]
		IntPtr Constructor(NMAGeoCoordinates geoCoordinates);
	}

	// @interface NMAVenue3dOutdoorRouteSection : NMAVenue3dRouteSection
	[BaseType(typeof(NMAVenue3dRouteSection))]
	[DisableDefaultCtor]
	interface NMAVenue3dOutdoorRouteSection
	{
		// @property (readonly, nonatomic) NMARoute * _Nonnull route;
		[Export("route")]
		NMARoute Route { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }
	}

	// @interface NMAVenue3dOuterArea : NMAVenue3dArea
	[BaseType(typeof(NMAVenue3dArea))]
	[DisableDefaultCtor]
	interface NMAVenue3dOuterArea
	{
		// @property (readonly, nonatomic) NSArray<NMAVenue3dSpace *> * _Nonnull spaces;
		[Export("spaces")]
		NMAVenue3dSpace[] Spaces { get; }

		// -(NMAVenue3dSpace * _Nullable)spaceAtPosition:(NMAGeoCoordinates * _Nonnull)position;
		[Export("spaceAtPosition:")]
		[return: NullAllowed]
		NMAVenue3dSpace SpaceAtPosition(NMAGeoCoordinates position);

		// -(NSArray<NMAVenue3dSpace *> * _Nonnull)nearbySpacesAroundPosition:(NMAGeoCoordinates * _Nonnull)position withinRadius:(float)radius;
		[Export("nearbySpacesAroundPosition:withinRadius:")]
		NMAVenue3dSpace[] NearbySpacesAroundPosition(NMAGeoCoordinates position, float radius);
	}

	// @interface NMAVenue3dRouteManeuver : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dRouteManeuver
	{
		// @property (readonly, nonatomic) NMAVenue3dRouteManeuver * _Nullable targetManeuver;
		[NullAllowed, Export("targetManeuver")]
		NMAVenue3dRouteManeuver TargetManeuver { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readwrite, nonatomic) NMAVenue3dRouteActionType routeActionType;
		[Export("routeActionType", ArgumentSemantic.Assign)]
		NMAVenue3dRouteActionType RouteActionType { get; set; }

		// @property (readonly, nonatomic) NMAVenue3dRouteLevelChangeType levelChangeType;
		[Export("levelChangeType")]
		NMAVenue3dRouteLevelChangeType LevelChangeType { get; }

		// @property (readonly, nonatomic) NMAManeuverTurn turn;
		[Export("turn")]
		NMAManeuverTurn Turn { get; }

		// @property (readwrite, nonatomic) NMAVenue3dRouteConnectorType routeConnectorType;
		[Export("routeConnectorType", ArgumentSemantic.Assign)]
		NMAVenue3dRouteConnectorType RouteConnectorType { get; set; }

		// @property (readwrite, nonatomic) NMAVenue3dSpace * _Nullable space;
		[NullAllowed, Export("space", ArgumentSemantic.Assign)]
		NMAVenue3dSpace Space { get; set; }

		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull geoCoordinates;
		[Export("geoCoordinates")]
		NMAGeoCoordinates GeoCoordinates { get; }

		// @property (readonly, nonatomic) NSArray<NMAGeoCoordinates *> * _Nonnull geometry;
		[Export("geometry")]
		NMAGeoCoordinates[] Geometry { get; }

		// @property (readonly, nonatomic) float distanceFromStart;
		[Export("distanceFromStart")]
		float DistanceFromStart { get; }

		// @property (readonly, nonatomic) float distanceFromPreviousManeuver;
		[Export("distanceFromPreviousManeuver")]
		float DistanceFromPreviousManeuver { get; }

		// @property (readonly, nonatomic) float distanceToNextManeuver;
		[Export("distanceToNextManeuver")]
		float DistanceToNextManeuver { get; }

		// @property (readonly, nonatomic) NSInteger floorIndex;
		[Export("floorIndex")]
		nint FloorIndex { get; }

		// @property (readonly, nonatomic) NSInteger angle;
		[Export("angle")]
		nint Angle { get; }

		// @property (readonly, nonatomic) NSInteger mapOrientation;
		[Export("mapOrientation")]
		nint MapOrientation { get; }

		// +(float)naturalGuidanceRadius;
		// +(void)setNaturalGuidanceRadius:(float)radius;
		[Static]
		[Export("naturalGuidanceRadius")]
		//[Verify(MethodToProperty)]
		float NaturalGuidanceRadius { get; set; }

		// +(NSSet<NSString *> * _Nonnull)naturalGuidanceBlacklist;
		[Static]
		[Export("naturalGuidanceBlacklist")]
		NSSet<NSString> NaturalGuidanceBlacklist();

		// +(void)addCategoryToNaturalGuidanceBlacklist:(NSString * _Nonnull)categoryId;
		[Static]
		[Export("addCategoryToNaturalGuidanceBlacklist:")]
		void AddCategoryToNaturalGuidanceBlacklist(string categoryId);

		// +(void)removeCategoryFromNaturalGuidanceBlacklist:(NSString * _Nonnull)categoryId;
		[Static]
		[Export("removeCategoryFromNaturalGuidanceBlacklist:")]
		void RemoveCategoryFromNaturalGuidanceBlacklist(string categoryId);

		// @property (readonly, nonatomic) NSString * _Nonnull naturalGuidancePOI;
		[Export("naturalGuidancePOI")]
		string NaturalGuidancePOI { get; }

		// -(NMAMapObject * _Nullable)mapObject;
		[Export("mapObject")]
		[return: NullAllowed]
		NMAMapObject MapObject();

		// -(BOOL)setMapObject:(NMAMapObject * _Nullable)mapObject;
		[Export("setMapObject:")]
		bool SetMapObject([NullAllowed] NMAMapObject mapObject);
	}

	// @interface NMAVenue3dRouteOptions : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dRouteOptions
	{
		// +(instancetype _Nonnull)optionsWithRoutingMode:(NMARoutingMode * _Nonnull)routingMode;
		[Static]
		[Export("optionsWithRoutingMode:")]
		NMAVenue3dRouteOptions OptionsWithRoutingMode(NMARoutingMode routingMode);

		// -(instancetype _Nonnull)initWithRoutingMode:(NMARoutingMode * _Nonnull)routingMode;
		[Export("initWithRoutingMode:")]
		IntPtr Constructor(NMARoutingMode routingMode);

		// -(BOOL)isRouteVisibleFor:(NMAVenue3dRouteSectionType)sectionType;
		[Export("isRouteVisibleFor:")]
		bool IsRouteVisibleFor(NMAVenue3dRouteSectionType sectionType);

		// -(void)setRouteVisibilityFor:(NMAVenue3dRouteSectionType)sectionType as:(BOOL)visibility;
		[Export("setRouteVisibilityFor:as:")]
		void SetRouteVisibilityFor(NMAVenue3dRouteSectionType sectionType, bool visibility);

		// -(UIColor * _Nonnull)routeColorFor:(NMAVenue3dRouteSectionType)sectionType;
		[Export("routeColorFor:")]
		UIColor RouteColorFor(NMAVenue3dRouteSectionType sectionType);

		// -(void)setRouteColorForType:(NMAVenue3dRouteSectionType)sectionType as:(UIColor * _Nonnull)color;
		[Export("setRouteColorForType:as:")]
		void SetRouteColorForType(NMAVenue3dRouteSectionType sectionType, UIColor color);

		// @property (readwrite, nonatomic) BOOL flagsVisible;
		[Export("flagsVisible")]
		bool FlagsVisible { get; set; }

		// @property (readwrite, nonatomic) BOOL iconsVisible;
		[Export("iconsVisible")]
		bool IconsVisible { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nonnull connectorColor;
		[Export("connectorColor", ArgumentSemantic.Assign)]
		UIColor ConnectorColor { get; set; }

		// @property (readwrite, nonatomic) double indoorRouteLineWidth;
		[Export("indoorRouteLineWidth")]
		double IndoorRouteLineWidth { get; set; }

		// @property (readwrite, nonatomic) int outdoorRouteLineWidth;
		[Export("outdoorRouteLineWidth")]
		int OutdoorRouteLineWidth { get; set; }

		// @property (readwrite, nonatomic) BOOL autoParking;
		[Export("autoParking")]
		bool AutoParking { get; set; }

		// @property (readwrite, nonatomic) BOOL avoidElevators;
		[Export("avoidElevators")]
		bool AvoidElevators { get; set; }

		// @property (readwrite, nonatomic) BOOL avoidEscalators;
		[Export("avoidEscalators")]
		bool AvoidEscalators { get; set; }

		// @property (readwrite, nonatomic) BOOL avoidStairs;
		[Export("avoidStairs")]
		bool AvoidStairs { get; set; }

		// @property (readwrite, nonatomic) BOOL avoidRamps;
		[Export("avoidRamps")]
		bool AvoidRamps { get; set; }

		// @property (readwrite, nonatomic) BOOL preferCorridors;
		[Export("preferCorridors")]
		bool PreferCorridors { get; set; }

		// @property (readwrite, nonatomic) BOOL preferGroundEntrances;
		[Export("preferGroundEntrances")]
		bool PreferGroundEntrances { get; set; }
	}

	// @interface NMAVenue3dRouteStyleOptions : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dRouteStyleOptions
	{
		// @property (readwrite, nonatomic) NMAMapObject * _Nullable startRouteMapObject;
		[NullAllowed, Export("startRouteMapObject", ArgumentSemantic.Assign)]
		NMAMapObject StartRouteMapObject { get; set; }

		// @property (readwrite, nonatomic) NMAMapObject * _Nullable endRouteMapObject;
		[NullAllowed, Export("endRouteMapObject", ArgumentSemantic.Assign)]
		NMAMapObject EndRouteMapObject { get; set; }

		// @property (readwrite, nonatomic) NMAMapObject * _Nullable enterCarMapObject;
		[NullAllowed, Export("enterCarMapObject", ArgumentSemantic.Assign)]
		NMAMapObject EnterCarMapObject { get; set; }

		// @property (readwrite, nonatomic) NMAMapObject * _Nullable leaveCarMapObject;
		[NullAllowed, Export("leaveCarMapObject", ArgumentSemantic.Assign)]
		NMAMapObject LeaveCarMapObject { get; set; }

		// -(BOOL)setMapObject:(NMAMapObject * _Nullable)mapObject forWaypoint:(NSUInteger)waypointIndex;
		[Export("setMapObject:forWaypoint:")]
		bool SetMapObject([NullAllowed] NMAMapObject mapObject, nuint waypointIndex);

		// -(NMAMapObject * _Nullable)mapObjectForWaypoint:(NSUInteger)waypointIndex;
		[Export("mapObjectForWaypoint:")]
		[return: NullAllowed]
		NMAMapObject MapObjectForWaypoint(nuint waypointIndex);

		// @property (readwrite, nonatomic) CGSize startRouteDefaultIconSize;
		[Export("startRouteDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize StartRouteDefaultIconSize { get; set; }

		// @property (readwrite, nonatomic) CGSize endRouteDefaultIconSize;
		[Export("endRouteDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize EndRouteDefaultIconSize { get; set; }

		// @property (readwrite, nonatomic) CGSize enterCarDefaultIconSize;
		[Export("enterCarDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize EnterCarDefaultIconSize { get; set; }

		// @property (readwrite, nonatomic) CGSize leaveCarDefaultIconSize;
		[Export("leaveCarDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize LeaveCarDefaultIconSize { get; set; }

		// @property (readwrite, nonatomic) CGSize connectorsDefaultIconSize;
		[Export("connectorsDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize ConnectorsDefaultIconSize { get; set; }

		// @property (readwrite, nonatomic) CGSize waypointsDefaultIconSize;
		[Export("waypointsDefaultIconSize", ArgumentSemantic.Assign)]
		CGSize WaypointsDefaultIconSize { get; set; }
	}

	// @protocol NMAVenue3dRoutingControllerObserver <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dRoutingControllerObserver
	{
		// @required -(void)didCalculateRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Abstract]
		[Export("didCalculateRoute:")]
		void DidCalculateRoute(NMAVenue3dCombinedRoute combinedRoute);
	}

	// @interface NMAVenue3dRoutingController : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dRoutingController
	{
		// -(void)calculateRouteFrom:(NMAVenue3dBaseLocation * _Nonnull)startLocation to:(NMAVenue3dBaseLocation * _Nonnull)endLocation withParams:(NMAVenue3dRouteOptions * _Nonnull)options;
		[Export("calculateRouteFrom:to:withParams:")]
		void CalculateRouteFrom(NMAVenue3dBaseLocation startLocation, NMAVenue3dBaseLocation endLocation, NMAVenue3dRouteOptions options);

		// -(void)calculateRouteWithPoints:(NSArray<NMAVenue3dBaseLocation *> * _Nonnull)points withParams:(NMAVenue3dRouteOptions * _Nonnull)options;
		[Export("calculateRouteWithPoints:withParams:")]
		void CalculateRouteWithPoints(NMAVenue3dBaseLocation[] points, NMAVenue3dRouteOptions options);

		// -(void)addObserver:(id<NMAVenue3dRoutingControllerObserver> _Nonnull)observer;
		[Export("addObserver:")]
		void AddObserver(NMAVenue3dRoutingControllerObserver observer);

		// -(void)removeObserver:(id<NMAVenue3dRoutingControllerObserver> _Nonnull)observer;
		[Export("removeObserver:")]
		void RemoveObserver(NMAVenue3dRoutingControllerObserver observer);

		// -(void)showRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute;
		[Export("showRoute:")]
		void ShowRoute(NMAVenue3dCombinedRoute combinedRoute);

		// -(void)showRoute:(NMAVenue3dCombinedRoute * _Nonnull)combinedRoute withStyleOptions:(NMAVenue3dRouteStyleOptions * _Nonnull)styleOptions;
		[Export("showRoute:withStyleOptions:")]
		void ShowRoute(NMAVenue3dCombinedRoute combinedRoute, NMAVenue3dRouteStyleOptions styleOptions);

		// -(void)hideRoute;
		[Export("hideRoute")]
		void HideRoute();
	}

	// @protocol NMAVenue3dServiceListener <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dServiceListener
	{
		// @optional -(void)venueServiceDidInitialize:(NMAVenue3dService * _Nonnull)venueService withResult:(NMAVenue3dServiceInitializationStatus)result;
		[Export("venueServiceDidInitialize:withResult:")]
		void VenueServiceDidInitialize(NMAVenue3dService venueService, NMAVenue3dServiceInitializationStatus result);

		// @optional -(void)venueService:(NMAVenue3dService * _Nonnull)venueService didGetVenue:(NMAVenue3dVenue * _Nonnull)venue withVenueInfo:(NMAVenue3dVenueInfo * _Nonnull)venueInfo withStatus:(NMAVenue3dServiceVenueLoadStatus)status;
		[Export("venueService:didGetVenue:withVenueInfo:withStatus:")]
		void VenueService(NMAVenue3dService venueService, NMAVenue3dVenue venue, NMAVenue3dVenueInfo venueInfo, NMAVenue3dServiceVenueLoadStatus status);

		// @optional -(void)venueServiceDidLoadVenues:(NMAVenue3dService * _Nonnull)venueService;
		[Export("venueServiceDidLoadVenues:")]
		void VenueServiceDidLoadVenues(NMAVenue3dService venueService);
	}

	// @protocol NMAVenue3dAuthenticationListener <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dAuthenticationListener
	{
		// @required -(void)didAuthenticateVenueService:(NMAVenue3dService * _Nonnull)venueService withResult:(BOOL)result andErrorMessage:(NSString * _Nonnull)errorMessage;
		[Abstract]
		[Export("didAuthenticateVenueService:withResult:andErrorMessage:")]
		void WithResult(NMAVenue3dService venueService, bool result, string errorMessage);
	}

	// @protocol NMAVenue3dServiceStopListener <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dServiceStopListener
	{
		// @required -(void)didStopVenueService:(NMAVenue3dService * _Nonnull)venueService;
		[Abstract]
		[Export("didStopVenueService:")]
		void DidStopVenueService(NMAVenue3dService venueService);
	}

	// @protocol NMAVenue3dServiceClearCacheListener <NSObject>
	[Protocol, Model]
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dServiceClearCacheListener
	{
		// @required -(void)didClearCache;
		[Abstract]
		[Export("didClearCache")]
		void DidClearCache();
	}

	// @interface NMAVenue3dService : NSObject
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dService
	{
		// +(instancetype _Nullable)sharedVenueService;
		[Static]
		[Export("sharedVenueService")]
		[return: NullAllowed]
		NMAVenue3dService SharedVenueService();

		// @property (readonly, nonatomic) NMAVenue3dServiceInitializationStatus initializationStatus;
		[Export("initializationStatus")]
		NMAVenue3dServiceInitializationStatus InitializationStatus { get; }

		// -(void)setHereAccountToken:(NSString * _Nonnull)token;
		[Export("setHereAccountToken:")]
		void SetHereAccountToken(string token);

		// -(void)authenticateWithCallback:(id<NMAVenue3dAuthenticationListener> _Nullable)listener;
		[Export("authenticateWithCallback:")]
		void AuthenticateWithCallback([NullAllowed] NMAVenue3dAuthenticationListener listener);

		// @property (readonly, nonatomic) NMAVenue3dAccount * _Nullable activeVenueAccount;
		[NullAllowed, Export("activeVenueAccount")]
		NMAVenue3dAccount ActiveVenueAccount { get; }

		// @property (readonly, nonatomic) NSArray<NMAVenue3dAccount *> * _Nonnull venueAccounts;
		[Export("venueAccounts")]
		NMAVenue3dAccount[] VenueAccounts { get; }

		// -(BOOL)setActiveVenueAccount:(NMAVenue3dAccount * _Nullable)account;
		[Export("setActiveVenueAccount:")]
		bool SetActiveVenueAccount([NullAllowed] NMAVenue3dAccount account);

		// -(void)addListener:(id<NMAVenue3dServiceListener> _Nonnull)listener;
		[Export("addListener:")]
		void AddListener(NMAVenue3dServiceListener listener);

		// -(void)removeListener:(id<NMAVenue3dServiceListener> _Nonnull)listener;
		[Export("removeListener:")]
		void RemoveListener(NMAVenue3dServiceListener listener);

		// @property (nonatomic) BOOL privateContent;
		[Export("privateContent")]
		bool PrivateContent { get; set; }

		// @property (nonatomic) BOOL devEnv;
		[Export("devEnv")]
		bool DevEnv { get; set; }

		// @property (nonatomic) BOOL testEnv;
		[Export("testEnv")]
		bool TestEnv { get; set; }

		// @property (nonatomic) BOOL combinedContent;
		[Export("combinedContent")]
		bool CombinedContent { get; set; }

		// -(void)start;
		[Export("start")]
		void Start();

		// -(void)getVenueWithInfo:(NMAVenue3dVenueInfo * _Nonnull)venueInfo;
		[Export("getVenueWithInfo:")]
		void GetVenueWithInfo(NMAVenue3dVenueInfo venueInfo);

		// -(void)getVenuesWithInfoArray:(NSArray<NMAVenue3dVenueInfo *> * _Nonnull)venueInfoArray;
		[Export("getVenuesWithInfoArray:")]
		void GetVenuesWithInfoArray(NMAVenue3dVenueInfo[] venueInfoArray);

		// -(NMAVenue3dVenueInfo * _Nullable)venueWithId:(NSString * _Nonnull)venueId;
		[Export("venueWithId:")]
		[return: NullAllowed]
		NMAVenue3dVenueInfo VenueWithId(string venueId);

		// -(NSArray<NMAVenue3dVenueInfo *> * _Nullable)venuesInGeoBoundingBox:(NMAGeoBoundingBox * _Nonnull)boundingBox;
		[Export("venuesInGeoBoundingBox:")]
		[return: NullAllowed]
		NMAVenue3dVenueInfo[] VenuesInGeoBoundingBox(NMAGeoBoundingBox boundingBox);

		// -(NSArray<NMAVenue3dVenueInfo *> * _Nullable)venuesAtGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("venuesAtGeoCoordinates:")]
		[return: NullAllowed]
		NMAVenue3dVenueInfo[] VenuesAtGeoCoordinates(NMAGeoCoordinates coordinates);

		// -(NMAVenue3dVenueInfo * _Nullable)venueAtGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates;
		[Export("venueAtGeoCoordinates:")]
		[return: NullAllowed]
		NMAVenue3dVenueInfo VenueAtGeoCoordinates(NMAGeoCoordinates coordinates);

		// -(NSArray<NMAVenue3dVenueInfo *> * _Nullable)venuesAtGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates radius:(float)radius;
		[Export("venuesAtGeoCoordinates:radius:")]
		[return: NullAllowed]
		NMAVenue3dVenueInfo[] VenuesAtGeoCoordinates(NMAGeoCoordinates coordinates, float radius);

		// -(NMAVenue3dVenueInfo * _Nullable)venueAtGeoCoordinates:(NMAGeoCoordinates * _Nonnull)coordinates radius:(float)radius;
		[Export("venueAtGeoCoordinates:radius:")]
		[return: NullAllowed]
		NMAVenue3dVenueInfo VenueAtGeoCoordinates(NMAGeoCoordinates coordinates, float radius);

		// -(void)stopWithCallback:(id<NMAVenue3dServiceStopListener> _Nullable)stopListener;
		[Export("stopWithCallback:")]
		void StopWithCallback([NullAllowed] NMAVenue3dServiceStopListener stopListener);

		// +(void)stopAndClearCacheWithCallback:(id<NMAVenue3dServiceClearCacheListener> _Nullable)listener;
		[Static]
		[Export("stopAndClearCacheWithCallback:")]
		void StopAndClearCacheWithCallback([NullAllowed] NMAVenue3dServiceClearCacheListener listener);
	}

	// @interface NMAVenue3dSimulatedPositionSource : NSObject <NMAPositionDataSource>
	[BaseType(typeof(NSObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dSimulatedPositionSource : NMAPositionDataSource
	{
		// @property (readwrite, nonatomic) NSTimeInterval updatesInterval;
		[Export("updatesInterval")]
		double UpdatesInterval { get; set; }

		// +(instancetype _Nonnull)positionSourceWithRouteSection:(NMAVenue3dVenueRouteSection * _Nonnull)routeSection speed:(double)speed distortionEnabled:(BOOL)distortionEnabled;
		[Static]
		[Export("positionSourceWithRouteSection:speed:distortionEnabled:")]
		NMAVenue3dSimulatedPositionSource PositionSourceWithRouteSection(NMAVenue3dVenueRouteSection routeSection, double speed, bool distortionEnabled);

		// +(instancetype _Nonnull)positionSourceWithLinkSection:(NMAVenue3dLinkRouteSection * _Nonnull)linkSection speed:(double)speed distortionEnabled:(BOOL)distortionEnabled;
		[Static]
		[Export("positionSourceWithLinkSection:speed:distortionEnabled:")]
		NMAVenue3dSimulatedPositionSource PositionSourceWithLinkSection(NMAVenue3dLinkRouteSection linkSection, double speed, bool distortionEnabled);

		// -(instancetype _Nonnull)initWithRouteSection:(NMAVenue3dVenueRouteSection * _Nonnull)routeSection speed:(double)speed distortionEnabled:(BOOL)distortionEnabled;
		[Export("initWithRouteSection:speed:distortionEnabled:")]
		IntPtr Constructor(NMAVenue3dVenueRouteSection routeSection, double speed, bool distortionEnabled);

		// -(instancetype _Nonnull)initWithLinkSection:(NMAVenue3dLinkRouteSection * _Nonnull)linkSection speed:(double)speed distortionEnabled:(BOOL)distortionEnabled;
		[Export("initWithLinkSection:speed:distortionEnabled:")]
		IntPtr Constructor(NMAVenue3dLinkRouteSection linkSection, double speed, bool distortionEnabled);

		// @property (readonly, nonatomic) NMAVenue3dSimulationState navigationState;
		[Export("navigationState")]
		NMAVenue3dSimulationState NavigationState { get; }

		// @property (getter = isPaused, nonatomic) BOOL paused;
		[Export("paused")]
		bool Paused { [Bind("isPaused")] get; set; }
	}

	// @interface NMAVenue3dSpace : NMAVenue3dArea
	[BaseType(typeof(NMAVenue3dArea))]
	[DisableDefaultCtor]
	interface NMAVenue3dSpace
	{
		// @property (readonly, nonatomic) NMAVenue3dContent * _Nullable content;
		[NullAllowed, Export("content")]
		NMAVenue3dContent Content { get; }

		// @property (readonly, nonatomic) NSInteger floorNumber;
		[Export("floorNumber")]
		nint FloorNumber { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull floorSynonym;
		[Export("floorSynonym")]
		string FloorSynonym { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull venueName;
		[Export("venueName")]
		string VenueName { get; }

		// @property (readonly, nonatomic) UIImage * _Nullable icon;
		[NullAllowed, Export("icon")]
		UIImage Icon { get; }

		// @property (readonly, nonatomic) NSString * _Nullable iconUri;
		[NullAllowed, Export("iconUri")]
		string IconUri { get; }

		// @property (readonly, nonatomic) NMAVenue3dSpaceType type;
		[Export("type")]
		NMAVenue3dSpaceType Type { get; }
	}

	// @interface NMAVenue3dSpaceLocation : NMAVenue3dBaseLocation
	[BaseType(typeof(NMAVenue3dBaseLocation))]
	[DisableDefaultCtor]
	interface NMAVenue3dSpaceLocation
	{
		// +(instancetype _Nullable)spaceLocationWithSpace:(NMAVenue3dSpace * _Nonnull)space inVenue:(NMAVenue3dController * _Nonnull)venue;
		[Static]
		[Export("spaceLocationWithSpace:inVenue:")]
		[return: NullAllowed]
		NMAVenue3dSpaceLocation SpaceLocationWithSpace(NMAVenue3dSpace space, NMAVenue3dController venue);

		// -(instancetype _Nullable)initWithSpace:(NMAVenue3dSpace * _Nonnull)space inVenue:(NMAVenue3dController * _Nonnull)venue;
		[Export("initWithSpace:inVenue:")]
		IntPtr Constructor(NMAVenue3dSpace space, NMAVenue3dController venue);
	}

	// @interface NMAVenue3dStyleSettings : NSObject
	[BaseType(typeof(NSObject))]
	interface NMAVenue3dStyleSettings
	{
		// @property (readwrite, nonatomic) UIColor * _Nullable fillColor;
		[NullAllowed, Export("fillColor", ArgumentSemantic.Assign)]
		UIColor FillColor { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nullable outlineColor;
		[NullAllowed, Export("outlineColor", ArgumentSemantic.Assign)]
		UIColor OutlineColor { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nullable selectedFillColor;
		[NullAllowed, Export("selectedFillColor", ArgumentSemantic.Assign)]
		UIColor SelectedFillColor { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nullable selectedOutlineColor;
		[NullAllowed, Export("selectedOutlineColor", ArgumentSemantic.Assign)]
		UIColor SelectedOutlineColor { get; set; }

		// @property (readwrite, nonatomic) NSString * _Nullable labelName;
		[NullAllowed, Export("labelName")]
		string LabelName { get; set; }

		// @property (readwrite, nonatomic) NMAImage * _Nullable labelImage;
		[NullAllowed, Export("labelImage", ArgumentSemantic.Assign)]
		NMAImage LabelImage { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nullable labelFillColor;
		[NullAllowed, Export("labelFillColor", ArgumentSemantic.Assign)]
		UIColor LabelFillColor { get; set; }

		// @property (readwrite, nonatomic) UIColor * _Nullable labelOutlineColor;
		[NullAllowed, Export("labelOutlineColor", ArgumentSemantic.Assign)]
		UIColor LabelOutlineColor { get; set; }
	}

	// @interface NMAVenue3dVenue : NMAVenue3dSpatialObject
	[BaseType(typeof(NMAVenue3dSpatialObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dVenue
	{
		// @property (readonly, nonatomic) NMAGeoCoordinates * _Nonnull geoCenter;
		[Export("geoCenter")]
		NMAGeoCoordinates GeoCenter { get; }

		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readonly, nonatomic) NSInteger floorNumber;
		[Export("floorNumber")]
		nint FloorNumber { get; }

		// @property (readonly, nonatomic) NSInteger groundFloorNumber;
		[Export("groundFloorNumber")]
		nint GroundFloorNumber { get; }

		// @property (readonly, nonatomic) NSArray<NMAVenue3dLevel *> * _Nonnull levels;
		[Export("levels")]
		NMAVenue3dLevel[] Levels { get; }

		// @property (readonly, nonatomic) NSArray<NMAVenue3dSpace *> * _Nonnull spaces;
		[Export("spaces")]
		NMAVenue3dSpace[] Spaces { get; }

		// @property (readonly, nonatomic) NMAVenue3dContent * _Nullable content;
		[NullAllowed, Export("content")]
		NMAVenue3dContent Content { get; }

		// -(NMAVenue3dSpace * _Nullable)spaceWithId:(NSString * _Nonnull)spaceId;
		[Export("spaceWithId:")]
		[return: NullAllowed]
		NMAVenue3dSpace SpaceWithId(string spaceId);

		// -(NSArray<NMAVenue3dSpace *> * _Nonnull)nearbySpacesAroundSpace:(NMAVenue3dSpace * _Nonnull)space withinRadius:(float)radius;
		[Export("nearbySpacesAroundSpace:withinRadius:")]
		NMAVenue3dSpace[] NearbySpacesAroundSpace(NMAVenue3dSpace space, float radius);
	}

	// @interface NMAVenue3dVenueInfo : NMAVenue3dSpatialObject
	[BaseType(typeof(NMAVenue3dSpatialObject))]
	[DisableDefaultCtor]
	interface NMAVenue3dVenueInfo
	{
		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// @property (readonly, nonatomic) NSString * _Nonnull name;
		[Export("name")]
		string Name { get; }

		// @property (readonly, nonatomic) BOOL isAlternativeSource;
		[Export("isAlternativeSource")]
		bool IsAlternativeSource { get; }
	}

	// @interface NMAVenue3dVenueRouteSection : NMAVenue3dRouteSection
	[BaseType(typeof(NMAVenue3dRouteSection))]
	[DisableDefaultCtor]
	interface NMAVenue3dVenueRouteSection
	{
		// @property (readonly, nonatomic) NMAGeoBoundingBox * _Nonnull boundingBox;
		[Export("boundingBox")]
		NMAGeoBoundingBox BoundingBox { get; }

		// -(NMAGeoBoundingBox * _Nullable)boundingBox:(NMAVenue3dLevel * _Nonnull)level;
		[Export("boundingBox:")]
		[return: NullAllowed]
		NMAGeoBoundingBox BoundingBoxWithVenue3dLevel(NMAVenue3dLevel level);

		// @property (readonly, nonatomic) NMAVenue3dVenue * _Nonnull venue;
		[Export("venue")]
		NMAVenue3dVenue Venue { get; }

		// @property (readonly, nonatomic) NSArray<NMAVenue3dRouteManeuver *> * _Nonnull routeManeuvers;
		[Export("routeManeuvers")]
		NMAVenue3dRouteManeuver[] RouteManeuvers { get; }
	}
}
