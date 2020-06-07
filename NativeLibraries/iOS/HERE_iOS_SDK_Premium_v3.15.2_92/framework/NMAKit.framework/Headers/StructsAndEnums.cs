using System;
using System.Runtime.InteropServices;
using NMAKit;
using ObjCRuntime;

namespace Xamarin.HEREMaps.iOS
{
	[Native]
	public enum NMAARError : nuint
	{
		None = 0,
		InvalidOperation = 1,
		InvalidParameters = 2,
		OperationNotAllowed = 3,
		CameraUnavailable = 4,
		SensorsUnavailable = 5,
		Stopped = 6,
		CameraAccessNotAuthorized = 7
	}

	[Native]
	public enum NMAARProjectionType : nuint
	{
		NearFar,
		Direct3D,
		Horizontal,
		Map,
		Global
	}

	[StructLayout (LayoutKind.Sequential)]
	public struct NMAVector3d
	{
		public nfloat x;

		public nfloat y;

		public nfloat z;
	}

	static class CFunctions
	{
		// BOOL NMAVector3dEqualToVector (const NMAVector3d v1, const NMAVector3d v2);
		[DllImport ("__Internal")]
		[Verify (PlatformInvoke)]
		static extern bool NMAVector3dEqualToVector (NMAVector3d v1, NMAVector3d v2);

		// NMAVector3d NMAVector3dMake (CGFloat x, CGFloat y, CGFloat z);
		[DllImport ("__Internal")]
		[Verify (PlatformInvoke)]
		static extern NMAVector3d NMAVector3dMake (nfloat x, nfloat y, nfloat z);

		// BOOL NMAVector3dValid (const NMAVector3d v1);
		[DllImport ("__Internal")]
		[Verify (PlatformInvoke)]
		static extern bool NMAVector3dValid (NMAVector3d v1);
	}

	[Native]
	public enum NMAARModelObjectShadingMode : nuint
	{
		FlatTextured = 0,
		DiffuseTextured = 1
	}

	[Native]
	public enum NMAARBillboardObjectOrientation : nuint
	{
		Fixed = 0,
		Billboard = 1
	}

	[Native]
	public enum NMALayoutPosition : nuint
	{
		TopLeft,
		TopCenter,
		TopRight,
		CenterLeft,
		Center,
		CenterRight,
		BottomLeft,
		BottomCenter,
		BottomRight
	}

	[Native]
	public enum NMAMapLayerType : nuint
	{
		Foreground,
		PointOfInterest,
		TransitStop,
		Road,
		Area,
		Background,
		Replacement
	}

	[Native]
	public enum NMAPixelFormat : nuint
	{
		Unknown,
		Rgba,
		Bgra,
		Rgb,
		R5g6b5
	}

	[Native]
	public enum NMARequestError : nuint
	{
		None = 0,
		Unknown,
		AddressMissing,
		LocationContextInvalid,
		LocationContextMissing,
		CountryCodeMissing,
		SearchTextMissing,
		InvalidParameter,
		NetworkCommunication,
		NetworkServer,
		NetworkEmptyInput,
		InvalidCredentials,
		Http,
		NetworkUnknown,
		NotSupported,
		NotReady,
		NotFound,
		AlreadyExists,
		OutOfMemory,
		OperationFailed,
		Aborted,
		FinderIndexFailure,
		MovedPermanently,
		NotModified,
		BadRequest,
		ResourceGone,
		Parse,
		Timeout,
		OperationNotAllowed
	}

	[Native]
	public enum NMARouteDisplayType : nuint
	{
		Primary,
		Secondary,
		UserDefined
	}

	[Native]
	public enum NMAMapPedestrianFeatureType : nint
	{
		Crosswalk,
		Stairs,
		Escalator,
		Elevator,
		Tunnel,
		Bridge,
		All
	}

	[Native]
	public enum NMAMapFleetFeatureType : nint
	{
		EnvironmentalZones,
		CongestionZones,
		TruckRestrictions,
		All
	}

	[Native]
	public enum NMAPatternStyle : nuint
	{
		None,
		Dash,
		CustomBlend,
		CustomFill
	}

	[Native]
	public enum NMAMapObjectType : nuint
	{
		Point,
		Marker,
		LabeledMarker,
		Polygon,
		Polyline,
		Route,
		SafetySpot,
		Container,
		Circle,
		Reserved,
		Unknown
	}

	[Native]
	public enum NMALineCapStyle : nuint
	{
		Butt,
		Round
	}

	[Native]
	public enum NMAApplicationContextError : nuint
	{
		None = 0,
		LicenseKeyEmpty,
		LicenseKeyMismatch,
		LicenseInvalidPlatform,
		LicenseExpired,
		MapVariantPermissionDenied,
		MapVariantChangeAttempt,
		MapVariantStorageFailed,
		IncorrectLicenseKey
	}

	[Native]
	public enum NMAMapVariant : nuint
	{
		Global = 0,
		Korea,
		China
	}

	[Native]
	public enum NMAAudioOutputEvent : nint
	{
		Began,
		Skipped,
		Ended
	}

	[Native]
	public enum NMAAudioOutputSource : nint
	{
		Unknown,
		User,
		Guidance
	}

	[Native]
	public enum NMAAudioRoute : nuint
	{
		Default = 0,
		DeviceSpeaker,
		BluetoothHFP,
		BluetoothHFPPreferred
	}

	[Native]
	public enum NMARoutingType : nuint
	{
		Shortest = 0,
		Fastest = 1,
		Balanced = 3
	}

	[Native]
	public enum NMATransportMode : nuint
	{
		Car = 0,
		Pedestrian = 1,
		PublicTransport = 2,
		Truck = 5,
		UrbanMobility = 6,
		Bike = 7,
		Scooter = 8
	}

	[Native]
	public enum NMARoutingOption : nuint
	{
		BoatFerry = 1 << 0,
		DirtRoad = 1 << 1,
		Highway = 1 << 2,
		Park = 1 << 3,
		TollRoad = 1 << 4,
		Tunnel = 1 << 5,
		CarShuttleTrain = 1 << 6,
		Carpool = 1 << 7
	}

	[Native]
	public enum NMASpeedProfile : nuint
	{
		Default = 0,
		Fast
	}

	[Native]
	public enum NMARouteDurationDetail : nuint
	{
		Accurate = 0,
		BlockedRoad = 1 << 0,
		CarPool = 1 << 1,
		RestrictedTurn = 1 << 2
	}

	[Native]
	public enum NMATrafficPenaltyMode : nint
	{
		Disabled = 0,
		Optimal,
		AvoidLongTermClosures
	}

	[Native]
	public enum NMADrivingDirection : nuint
	{
		Both = 0,
		Forward,
		Backward
	}

	[Native]
	public enum NMARouteError : nuint
	{
		InvalidParameter = 1,
		NotSupported,
		Unknown
	}

	[Native]
	public enum NMARouteSerializationError : nuint
	{
		InvalidParameter,
		MapVersionMismatch,
		DataCorrupted,
		TransportModeNotSupported,
		Unknown
	}

	[Native]
	public enum NMARouteInstructionsUnitSystem : nuint
	{
		Metric,
		Imperial
	}

	[Native]
	public enum NMARoutingError : nuint
	{
		None = 0,
		Unknown,
		OutOfMemory,
		InvalidParameters,
		InvalidOperation,
		GraphDisconnected,
		GraphDisconnectedCheckOptions,
		NoStartPoint,
		NoEndPoint,
		NoEndPointCheckOptions,
		CannotDoPedestrian,
		RoutingCancelled,
		ViolatesOptions,
		RouteCorrupted,
		InvalidCredentials,
		InsufficientMapData,
		NetworkCommunication,
		UnsupportedMapVersion
	}

	[Native]
	public enum NMAManeuverAction : nint
	{
		Undefined = 0,
		None,
		End,
		Stopover,
		Junction,
		Roundabout,
		UTurn,
		EnterHighwayFromRight,
		EnterHighwayFromLeft,
		EnterHighway,
		LeaveHighway,
		ChangeHighway,
		ContinueHighway,
		Ferry,
		PassJunction,
		HeadTo,
		PassStation,
		ChangeLine,
		Invalid = -1
	}

	[Native]
	public enum NMAManeuverTurn : nuint
	{
		Undefined = 0,
		None,
		KeepMiddle,
		KeepRight,
		LightRight,
		QuiteRight,
		HeavyRight,
		KeepLeft,
		LightLeft,
		QuiteLeft,
		HeavyLeft,
		Return,
		Roundabout1,
		Roundabout2,
		Roundabout3,
		Roundabout4,
		Roundabout5,
		Roundabout6,
		Roundabout7,
		Roundabout8,
		Roundabout9,
		Roundabout10,
		Roundabout11,
		Roundabout12
	}

	[Native]
	public enum NMAManeuverIcon : nuint
	{
		Undefined = 0,
		GoStraight,
		UTurnRight,
		UTurnLeft,
		KeepRight,
		LightRight,
		QuiteRight,
		HeavyRight,
		KeepMiddle,
		KeepLeft,
		LightLeft,
		QuiteLeft,
		HeavyLeft,
		EnterHighwayRightLane,
		EnterHighwayLeftLane,
		LeaveHighwayRightLane,
		LeaveHighwayLeftLane,
		HighwayKeepRight,
		HighwayKeepLeft,
		Roundabout1,
		Roundabout2,
		Roundabout3,
		Roundabout4,
		Roundabout5,
		Roundabout6,
		Roundabout7,
		Roundabout8,
		Roundabout9,
		Roundabout10,
		Roundabout11,
		Roundabout12,
		Roundabout1LH,
		Roundabout2LH,
		Roundabout3LH,
		Roundabout4LH,
		Roundabout5LH,
		Roundabout6LH,
		Roundabout7LH,
		Roundabout8LH,
		Roundabout9LH,
		Roundabout10LH,
		Roundabout11LH,
		Roundabout12LH,
		Start,
		End,
		Ferry,
		PassStation,
		HeadTo,
		ChangeLine
	}

	[Native]
	public enum NMAManeuverTrafficDirection : nuint
	{
		Left = 0,
		Right
	}

	[Native]
	public enum NMANavigationState : nuint
	{
		Idle = 0,
		Running,
		Paused
	}

	[Native]
	public enum NMANavigationMode : nuint
	{
		None = 0,
		TurnByTurn,
		Tracking
	}

	[Native]
	public enum NMAMapTrackingOrientation : nuint
	{
		Dynamic,
		NorthUp
	}

	[Native]
	public enum NMAMapTrackingTilt : nuint
	{
		NMAMapTrackingTilt2D,
		NMAMapTrackingTilt3D,
		Custom
	}

	[Native]
	public enum NMAMeasurementSystem : nuint
	{
		Metric = 0,
		Imperial,
		ImperialUS
	}

	[Native]
	public enum NMARealisticViewAspectRatio : nuint
	{
		NMARealisticView16x9 = 1,
		NMARealisticView3x5 = 2,
		NMARealisticView5x3 = 4,
		NMARealisticView4x3 = 8
	}

	[Native]
	public enum NMARealisticViewMode : nuint
	{
		Off,
		Day,
		Night
	}

	[Native]
	public enum NMANavigationError : nuint
	{
		None,
		GuidanceNotReady,
		NotReady,
		PositioningFailed,
		OutOfMemory,
		InvalidParameters,
		InvalidOperation,
		NotFound,
		Aborted,
		OperationNotAllowed,
		InvalidCredentials,
		PedestrianNavigationNotAvailable,
		Unknown
	}

	[Native]
	public enum NMANaturalGuidanceOption : nuint
	{
		None = 0,
		TrafficLight = 1,
		Landmark = 4
	}

	[Native]
	public enum NMATrafficAvoidanceMode : nuint
	{
		Dynamic,
		Manual,
		Disabled
	}

	[Native]
	public enum NMATrafficEnabledRoutingState : nuint
	{
		Off,
		On,
		NotAvailable
	}

	[Native]
	public enum NMATTSOutputFormat : nuint
	{
		Raw = 0,
		Nuance = 1
	}

	[Native]
	public enum NMANavigationAudioEvent : nuint
	{
		NMANavigationAudioEventSafetySpot = 32
	}

	[Native]
	public enum NMATextFormat : nuint
	{
		Html = 0,
		Plain
	}

	[Native]
	public enum NMARequestConnectivity : nuint
	{
		Default = 0,
		Offline,
		Online
	}

	[Native]
	public enum NMAMapStyleConfigurationError : nuint
	{
		None = 0,
		HERESDKAlreadyInitialized,
		ConfigurationFile,
		ResourceFile,
		TrafficConfigurationFile,
		CustomPreferenceConfigurationFile,
		ConfigurationResourceFiles,
		KeyIsNotSupported
	}

	[Native]
	public enum NMADevicePositioningMethod : nuint
	{
		Gps,
		SignificantChanges
	}

	[Native]
	public enum NMAGeoPositionSource : nuint
	{
		Unknown = 0,
		SystemLocation = 1,
		Indoor = 2
	}

	[Native]
	public enum NMAIndoorPositioningMode : nuint
	{
		None = 0,
		Automatic,
		Community,
		Private
	}

	[Native]
	public enum NMALocationTrackingMethod : nuint
	{
		None = 0,
		Gps,
		SignificantChanges
	}

	[Native]
	public enum NMAMapMatchMode : nuint
	{
		Car,
		Pedestrian,
		Truck,
		Scooter
	}

	[Native]
	public enum NMAPositionLogType : nint
	{
		None = 0,
		DataSource = 1 << 0,
		Current = 1 << 1,
		Raw = 1 << 2,
		Matched = 1 << 3,
		All = 255
	}

	[Native]
	public enum NMARoadElementAttribute : nuint
	{
		Undefined = 0,
		DirectionNoCars = 0,
		DirectionForward = 1,
		DirectionBackward = 2,
		DirectionBoth = 3,
		DirtRoad = 256,
		UsageFeeRequired = 512,
		Carpool = 1024,
		Urban = 2048,
		Tollroad = 4096,
		NoThroughTraffic = 8192,
		Tunnel = 16384,
		Sliproad = 262144,
		Highway = 524288,
		UnderConstruction = 1048576,
		HasLaneDir = 2097152,
		HasLaneExit = 4194304,
		Ferry = 8388608,
		RailFerry = 16777216,
		DirectionNoTruck = 33554432,
		DirectionTruckForward = 67108864,
		DirectionTruckBackward = 134217728,
		DirectionTruckBoth = 201326592,
		SchoolZone = 268435456
	}

	[Native]
	public enum NMARoadElementType : nuint
	{
		Undefined = 0,
		Motorway,
		MultiCarriageway,
		SingleCarriageway,
		Roundabout,
		Sliproad,
		PedestrianZone,
		PedestrianWalkway,
		ServiceAccess,
		PedestrianOnly
	}

	[Native]
	public enum NMARoadElementPluralType : nuint
	{
		None = 0,
		Maneuver,
		Connector,
		Indeterminate
	}

	[Native]
	public enum NMASafetySpotType : nuint
	{
		Undefined,
		SpeedCamera,
		RedLightCamera,
		SpeedRedLightCamera
	}

	[Native]
	public enum NMATrafficEventSeverity : nuint
	{
		Undefined,
		Normal,
		High,
		VeryHigh,
		Blocking
	}

	[Native]
	public enum NMATrafficRequestError : nint
	{
		None,
		InvalidParameters,
		InvalidOperation,
		Unknown
	}

	[Native]
	public enum NMATrafficSeverity : nuint
	{
		Undefined = 0,
		Normal,
		High,
		VeryHigh,
		Blocking
	}

	[Native]
	public enum NMATrafficNotificationType : nuint
	{
		Undefined = 0,
		OnRoute,
		OnHighway,
		NearStart,
		NearStopover,
		NearDestination
	}

	[Native]
	public enum NMASignCategory : nuint
	{
		Unknown = 0,
		RegulatorySign = 1,
		InformativeSign = 2,
		WarningSign = 3
	}

	[Native]
	public enum NMASignSubcategory : nuint
	{
		Unknown = 0,
		PrioritySign = 1
	}

	[Native]
	public enum NMASignLocation : nuint
	{
		Unknown = 0,
		Right = 1,
		Left = 2,
		Overhead = 3
	}

	[Native]
	public enum NMASignDirection : nuint
	{
		Unknown = 0,
		Positive = 1,
		Negative = 2,
		Both = 3
	}

	[Native]
	public enum NMASignTransportType : nuint
	{
		Unknown = 0,
		Truck = 1,
		HeavyTruck = 2,
		Bus = 3,
		AutoTrailer = 4,
		Motorhome = 5,
		Motorcycle = 6
	}

	[Native]
	public enum NMASignWeatherAffects : nuint
	{
		Unknown = 0,
		Rain = 1,
		Snow = 2,
		Fog = 3
	}

	[Native]
	public enum NMATransitType : nuint
	{
		PublicBus,
		TouristicBus,
		IntercityBus,
		ExpressBus,
		MetroRail,
		LightRail,
		RegionalRail,
		RegionalTrain,
		IntercityTrain,
		HighSpeedTrain,
		Monorail,
		Aerial,
		Inclined,
		Water,
		Airline,
		Unknown
	}

	[Native]
	public enum NMATransitManagerError : nuint
	{
		None,
		Busy,
		InvalidParameters,
		NotFound,
		Unknown
	}

	[Native]
	public enum NMATransitObjectType : nuint
	{
		Access,
		Line,
		Stop
	}

	[Native]
	public enum NMAEHLinkDirection : nuint
	{
		Forward,
		Backward
	}

	[Native]
	public enum NMAEHLinkAllowedDirection : nuint
	{
		Forward,
		Backward,
		Both,
		None
	}

	[Native]
	public enum NMAEHLinkFunctionalRoadClass : nuint
	{
		NMAEHLinkFunctionalRoadClass1,
		NMAEHLinkFunctionalRoadClass2,
		NMAEHLinkFunctionalRoadClass3,
		NMAEHLinkFunctionalRoadClass4,
		NMAEHLinkFunctionalRoadClass5
	}

	[Native]
	public enum NMAEHLinkFormOfWay : nuint
	{
		Multidigitized,
		SingleCarriage,
		Sliproad,
		RoundaboutCircle,
		SpecialTrafficFigure,
		PedestrianZone,
		ServiceRoad
	}

	[Native]
	public enum NMAEHMetaDataSideOfDriving : nuint
	{
		Right,
		Left,
		Unknown
	}

	[Native]
	public enum NMAEHMetaDataUnitSystem : nuint
	{
		Metric,
		Imperial,
		Unknown
	}

	[Native]
	public enum NMAFleetConnectivityErrorType : nuint
	{
		ServerError = 1,
		ConnectionError = 2
	}

	[Native]
	public enum NMAIsolineError : nuint
	{
		None = 0,
		Unknown,
		OutOfMemory,
		InvalidParameters,
		InvalidOperation,
		GraphDisconnected,
		RoutingCancelled,
		InvalidCredentials,
		InsufficientMapData,
		NetworkCommunication,
		UnsupportedMapVersion
	}

	[Native]
	public enum NMAIsolineQuality : nuint
	{
		Best,
		Performance,
		Balanced
	}

	[Native]
	public enum NMAIsolineRouterConnectivity : nuint
	{
		Default,
		Offline,
		Online
	}

	[Native]
	public enum NMAIsolineRangeType : nuint
	{
		Undefined,
		Distance,
		Time
	}

	[Native]
	public enum NMACustomizablePropertyType : nuint
	{
		FloatType,
		IntegerType,
		BooleanType,
		ColorType
	}

	[Native]
	public enum NMASchemeColorProperty : nuint
	{
		AirportAreaColor,
		AirportAreaInfoFontStyleColor,
		AirportAreaInfoFontStyleOutlineColor,
		AllotmentColor,
		AllotmentInfoFontStyleColor,
		AllotmentInfoFontStyleOutlineColor,
		AmbientLightColor,
		AmusementParkColor,
		AmusementParkInfoFontStyleColor,
		AmusementParkInfoFontStyleOutlineColor,
		AnimalParkColor,
		AnimalParkInfoFontStyleColor,
		AnimalParkInfoFontStyleOutlineColor,
		AvoidBlockedRouteDashColor,
		AvoidBlockedRouteGapColor,
		AvoidBlockedRouteOutlineColor,
		BayHarbourColor,
		BayHarbourDisplayClass1Color,
		BayHarbourDisplayClass1FontStyleColor,
		BayHarbourDisplayClass1FontStyleOutlineColor,
		BayHarbourDisplayClass2Color,
		BayHarbourDisplayClass2FontStyleColor,
		BayHarbourDisplayClass2FontStyleOutlineColor,
		BayHarbourDisplayClass3Color,
		BayHarbourDisplayClass3FontStyleColor,
		BayHarbourDisplayClass3FontStyleOutlineColor,
		BayHarbourDisplayClass4Color,
		BayHarbourDisplayClass4FontStyleColor,
		BayHarbourDisplayClass4FontStyleOutlineColor,
		BayHarbourDisplayClass5Color,
		BayHarbourDisplayClass5FontStyleColor,
		BayHarbourDisplayClass5FontStyleOutlineColor,
		BayHarbourDisplayClass6Color,
		BayHarbourDisplayClass6FontStyleColor,
		BayHarbourDisplayClass6FontStyleOutlineColor,
		BayHarbourDisplayClass7Color,
		BayHarbourDisplayClass7FontStyleColor,
		BayHarbourDisplayClass7FontStyleOutlineColor,
		BayHarbourDisplayClass8Color,
		BayHarbourDisplayClass8FontStyleColor,
		BayHarbourDisplayClass8FontStyleOutlineColor,
		BayHarbourFontStyleColor,
		BayHarbourFontStyleOutlineColor,
		BeachColor,
		BeachInfoFontStyleColor,
		BeachInfoFontStyleOutlineColor,
		BillboardAdjacentColor,
		BillboardAdjacentFontStyleColor,
		BillboardAdjacentFontStyleOutlineColor,
		BillboardAdjacentOutlineColor,
		BillboardOffRouteColor,
		BillboardOffRouteFontStyleColor,
		BillboardOffRouteFontStyleOutlineColor,
		BillboardOffRouteOutlineColor,
		BuildingColor,
		Building1Color,
		Building1OutlineColor,
		BuildingAddressFontStyleColor,
		BuildingAddressFontStyleOutlineColor,
		BuildingInfoFontStyleColor,
		BuildingInfoFontStyleOutlineColor,
		BuildingOutlineColor,
		BuiltupAreaColor,
		BuiltupBorderBackgroundColor,
		BuiltupBorderColor,
		CanalWaterChannelColor,
		CanalWaterChannelDisplayClass1Color,
		CanalWaterChannelDisplayClass1FontStyleColor,
		CanalWaterChannelDisplayClass1FontStyleOutlineColor,
		CanalWaterChannelDisplayClass2Color,
		CanalWaterChannelDisplayClass2FontStyleColor,
		CanalWaterChannelDisplayClass2FontStyleOutlineColor,
		CanalWaterChannelDisplayClass3Color,
		CanalWaterChannelDisplayClass3FontStyleColor,
		CanalWaterChannelDisplayClass3FontStyleOutlineColor,
		CanalWaterChannelDisplayClass4Color,
		CanalWaterChannelDisplayClass4FontStyleColor,
		CanalWaterChannelDisplayClass4FontStyleOutlineColor,
		CanalWaterChannelDisplayClass5Color,
		CanalWaterChannelDisplayClass5FontStyleColor,
		CanalWaterChannelDisplayClass5FontStyleOutlineColor,
		CanalWaterChannelDisplayClass6Color,
		CanalWaterChannelDisplayClass6FontStyleColor,
		CanalWaterChannelDisplayClass6FontStyleOutlineColor,
		CanalWaterChannelDisplayClass7Color,
		CanalWaterChannelDisplayClass7FontStyleColor,
		CanalWaterChannelDisplayClass7FontStyleOutlineColor,
		CanalWaterChannelDisplayClass8Color,
		CanalWaterChannelDisplayClass8FontStyleColor,
		CanalWaterChannelDisplayClass8FontStyleOutlineColor,
		CanalWaterChannelFontStyleColor,
		CanalWaterChannelFontStyleOutlineColor,
		CemeteryColor,
		CemeteryInfoFontStyleColor,
		CemeteryInfoFontStyleOutlineColor,
		CityCenterClass1FontStyleColor,
		CityCenterClass1FontStyleOutlineColor,
		CityCenterClass2FontStyleColor,
		CityCenterClass2FontStyleOutlineColor,
		CityCenterClass3FontStyleColor,
		CityCenterClass3FontStyleOutlineColor,
		CityCenterClass4FontStyleColor,
		CityCenterClass4FontStyleOutlineColor,
		CityCenterClass5FontStyleColor,
		CityCenterClass5FontStyleOutlineColor,
		CityCenterDistrictFontStyleColor,
		CityCenterDistrictFontStyleOutlineColor,
		CityCenterHamletFontStyleColor,
		CityCenterHamletFontStyleOutlineColor,
		CongestionZoneColor,
		CongestionZoneBorderColor,
		CongestionZoneInfoFontStyleColor,
		CongestionZoneInfoFontStyleOutlineColor,
		ContinentLabelFontStyleColor,
		ContinentLabelFontStyleOutlineColor,
		CountryBoundaryBackgroundColor,
		CountryBoundaryColor,
		CountryBoundaryDisputedBackgroundColor,
		CountryBoundaryDisputedColor,
		CountrySideLabelFontStyleColor,
		CountrySideLabelFontStyleOutlineColor,
		DirectionalLight1Color,
		DirectionalLight2Color,
		DirectionalLight3Color,
		ElevationMapColor0,
		ElevationMapColor1,
		ElevationMapColor2,
		ElevationMapColor3,
		ElevationMapColor4,
		ElevationMapColor5,
		ElevationMapColor6,
		ElevationMapColor7,
		ElevationMapShaderShadowColor,
		ElevationMapShaderSpecularColor,
		EnvironmentalZoneColor,
		EnvironmentalZoneBorderColor,
		EnvironmentalZoneInfoFontStyleColor,
		EnvironmentalZoneInfoFontStyleOutlineColor,
		ExitInfoStreetCategory0Color,
		ExitInfoStreetCategory0FontStyleColor,
		ExitInfoStreetCategory0FontStyleOutlineColor,
		ExitInfoStreetCategory0OutlineColor,
		ExitInfoStreetCategory0TollColor,
		ExitInfoStreetCategory0TollFontStyleColor,
		ExitInfoStreetCategory0TollFontStyleOutlineColor,
		ExitInfoStreetCategory0TollOutlineColor,
		ExitInfoStreetCategory1Color,
		ExitInfoStreetCategory1FontStyleColor,
		ExitInfoStreetCategory1FontStyleOutlineColor,
		ExitInfoStreetCategory1OutlineColor,
		ExitInfoStreetCategory1TollColor,
		ExitInfoStreetCategory1TollFontStyleColor,
		ExitInfoStreetCategory1TollFontStyleOutlineColor,
		ExitInfoStreetCategory1TollOutlineColor,
		ExitInfoStreetCategory2Color,
		ExitInfoStreetCategory2FontStyleColor,
		ExitInfoStreetCategory2FontStyleOutlineColor,
		ExitInfoStreetCategory2OutlineColor,
		ExitInfoStreetCategory2TollColor,
		ExitInfoStreetCategory2TollFontStyleColor,
		ExitInfoStreetCategory2TollFontStyleOutlineColor,
		ExitInfoStreetCategory2TollOutlineColor,
		ExitInfoSimplifiedStreetCategory0Color,
		ExitInfoSimplifiedStreetCategory0OutlineColor,
		ExitInfoSimplifiedStreetCategory0TollColor,
		ExitInfoSimplifiedStreetCategory0TollOutlineColor,
		ExitInfoSimplifiedStreetCategory1Color,
		ExitInfoSimplifiedStreetCategory1OutlineColor,
		ExitInfoSimplifiedStreetCategory1TollColor,
		ExitInfoSimplifiedStreetCategory1TollOutlineColor,
		ExitInfoSimplifiedStreetCategory2Color,
		ExitInfoSimplifiedStreetCategory2OutlineColor,
		ExitInfoSimplifiedStreetCategory2TollColor,
		ExitInfoSimplifiedStreetCategory2TollOutlineColor,
		ExtrudedBuildingsColor,
		ExtrudedBuildingsColorHighlight0,
		ExtrudedBuildingsColorHighlight1,
		ExtrudedBuildingsColorHighlight2,
		ExtrudedBuildingsColorHighlight3,
		ExtrudedBuildingsColorHighlight4,
		ExtrudedBuildingsColorHighlight5,
		ExtrudedBuildingsColorNamed,
		ExtrudedBuildingsColorSelected,
		FerryFontStyleColor,
		FerryFontStyleOutlineColor,
		FerryTunnelColor,
		FogDarkColor,
		FogDistanceColor,
		FogLightColor,
		GolfCourseColor,
		GolfCourseInfoFontStyleColor,
		GolfCourseInfoFontStyleOutlineColor,
		HarborAreaColor,
		HarborAreaInfoFontStyleColor,
		HarborAreaInfoFontStyleOutlineColor,
		HospitalCampusColor,
		HospitalCampusInfoFontStyleColor,
		HospitalCampusInfoFontStyleOutlineColor,
		IndustrialComplexColor,
		IndustrialComplexInfoFontStyleColor,
		IndustrialComplexInfoFontStyleOutlineColor,
		IntermittentRiverColor,
		IntermittentRiverDisplayClass1Color,
		IntermittentRiverDisplayClass1FontStyleColor,
		IntermittentRiverDisplayClass1FontStyleOutlineColor,
		IntermittentRiverDisplayClass2Color,
		IntermittentRiverDisplayClass2FontStyleColor,
		IntermittentRiverDisplayClass2FontStyleOutlineColor,
		IntermittentRiverDisplayClass3Color,
		IntermittentRiverDisplayClass3FontStyleColor,
		IntermittentRiverDisplayClass3FontStyleOutlineColor,
		IntermittentRiverDisplayClass4Color,
		IntermittentRiverDisplayClass4FontStyleColor,
		IntermittentRiverDisplayClass4FontStyleOutlineColor,
		IntermittentRiverDisplayClass5Color,
		IntermittentRiverDisplayClass5FontStyleColor,
		IntermittentRiverDisplayClass5FontStyleOutlineColor,
		IntermittentRiverDisplayClass6Color,
		IntermittentRiverDisplayClass6FontStyleColor,
		IntermittentRiverDisplayClass6FontStyleOutlineColor,
		IntermittentRiverDisplayClass7Color,
		IntermittentRiverDisplayClass7FontStyleColor,
		IntermittentRiverDisplayClass7FontStyleOutlineColor,
		IntermittentRiverDisplayClass8Color,
		IntermittentRiverDisplayClass8FontStyleColor,
		IntermittentRiverDisplayClass8FontStyleOutlineColor,
		IntermittentRiverFontStyleColor,
		IntermittentRiverFontStyleOutlineColor,
		IslandInfoFontStyleColor,
		IslandInfoFontStyleOutlineColor,
		LakeColor,
		LakeDisplayClass1Color,
		LakeDisplayClass1FontStyleColor,
		LakeDisplayClass1FontStyleOutlineColor,
		LakeDisplayClass2Color,
		LakeDisplayClass2FontStyleColor,
		LakeDisplayClass2FontStyleOutlineColor,
		LakeDisplayClass3Color,
		LakeDisplayClass3FontStyleColor,
		LakeDisplayClass3FontStyleOutlineColor,
		LakeDisplayClass4Color,
		LakeDisplayClass4FontStyleColor,
		LakeDisplayClass4FontStyleOutlineColor,
		LakeDisplayClass5Color,
		LakeDisplayClass5FontStyleColor,
		LakeDisplayClass5FontStyleOutlineColor,
		LakeDisplayClass6Color,
		LakeDisplayClass6FontStyleColor,
		LakeDisplayClass6FontStyleOutlineColor,
		LakeDisplayClass7Color,
		LakeDisplayClass7FontStyleColor,
		LakeDisplayClass7FontStyleOutlineColor,
		LakeDisplayClass8Color,
		LakeDisplayClass8FontStyleColor,
		LakeDisplayClass8FontStyleOutlineColor,
		LakeFontStyleColor,
		LakeFontStyleOutlineColor,
		LandColor,
		LandCoverDesertColor,
		LandCoverDesertFontStyleColor,
		LandCoverDesertFontStyleOutlineColor,
		LandCoverGlacierColor,
		LandCoverGlacierFontStyleColor,
		LandCoverGlacierFontStyleOutlineColor,
		LineOfControlBackgroundColor,
		LineOfControlColor,
		MajorCountryLabelFontStyleColor,
		MajorCountryLabelFontStyleOutlineColor,
		MarkingDividerCenterColor,
		MarkingLaneDashedColor,
		MarkingLaneSolidColor,
		MilitaryBaseColor,
		MilitaryBaseInfoFontStyleColor,
		MilitaryBaseInfoFontStyleOutlineColor,
		MinorCountryLabelFontStyleColor,
		MinorCountryLabelFontStyleOutlineColor,
		MotorwayJunctionSimplifiedIconColor,
		MotorwayJunctionSimplifiedIconOutlineColor,
		MountainPeakHeightFontStyleColor,
		MountainPeakHeightFontStyleOutlineColor,
		MountainPeakInfoFontStyleColor,
		MountainPeakInfoFontStyleOutlineColor,
		MountainRangeInfoDisplayClass1FontStyleColor,
		MountainRangeInfoDisplayClass1FontStyleOutlineColor,
		MountainRangeInfoDisplayClass2FontStyleColor,
		MountainRangeInfoDisplayClass2FontStyleOutlineColor,
		MountainRangeInfoDisplayClass3FontStyleColor,
		MountainRangeInfoDisplayClass3FontStyleOutlineColor,
		MountainRangeInfoFontStyleColor,
		MountainRangeInfoFontStyleOutlineColor,
		NationalForestColor,
		NationalForestInfoFontStyleColor,
		NationalForestInfoFontStyleOutlineColor,
		NationalGrasslandColor,
		NationalGrasslandInfoFontStyleColor,
		NationalGrasslandInfoFontStyleOutlineColor,
		NationalHistoricParkColor,
		NationalHistoricParkInfoFontStyleColor,
		NationalHistoricParkInfoFontStyleOutlineColor,
		NationalMilitaryParkColor,
		NationalParkColor,
		NationalParkInfoFontStyleColor,
		NationalParkInfoFontStyleOutlineColor,
		NationalRecreationAreaColor,
		NationalRecreationAreaInfoFontStyleColor,
		NationalRecreationAreaInfoFontStyleOutlineColor,
		NationalReserveColor,
		NationalStateParkColor,
		NationalStateParkInfoFontStyleColor,
		NationalStateParkInfoFontStyleOutlineColor,
		NationalWildlifeRefugeColor,
		NativeReservationColor,
		NativeReservationInfoFontStyleColor,
		NativeReservationInfoFontStyleOutlineColor,
		NeighborhoodColor0,
		NeighborhoodColor1,
		NeighborhoodColor2,
		NeighborhoodColor3,
		NeighborhoodColor4,
		NeighborhoodColor5,
		NeighborhoodInfoFontStyle0Color,
		NeighborhoodInfoFontStyle0OutlineColor,
		NeighborhoodInfoFontStyle1Color,
		NeighborhoodInfoFontStyle1OutlineColor,
		NeighborhoodInfoFontStyle2Color,
		NeighborhoodInfoFontStyle2OutlineColor,
		NeighborhoodInfoFontStyle3Color,
		NeighborhoodInfoFontStyle3OutlineColor,
		NeighborhoodInfoFontStyle4Color,
		NeighborhoodInfoFontStyle4OutlineColor,
		NeighborhoodInfoFontStyle5Color,
		NeighborhoodInfoFontStyle5OutlineColor,
		OceanColor,
		OceanDisplayClass1Color,
		OceanDisplayClass1FontStyleColor,
		OceanDisplayClass1FontStyleOutlineColor,
		OceanDisplayClass2Color,
		OceanDisplayClass2FontStyleColor,
		OceanDisplayClass2FontStyleOutlineColor,
		OceanDisplayClass3Color,
		OceanDisplayClass3FontStyleColor,
		OceanDisplayClass3FontStyleOutlineColor,
		OceanDisplayClass4Color,
		OceanDisplayClass4FontStyleColor,
		OceanDisplayClass4FontStyleOutlineColor,
		OceanDisplayClass5Color,
		OceanDisplayClass5FontStyleColor,
		OceanDisplayClass5FontStyleOutlineColor,
		OceanDisplayClass6Color,
		OceanDisplayClass6FontStyleColor,
		OceanDisplayClass6FontStyleOutlineColor,
		OceanDisplayClass7Color,
		OceanDisplayClass7FontStyleColor,
		OceanDisplayClass7FontStyleOutlineColor,
		OceanDisplayClass8Color,
		OceanDisplayClass8FontStyleColor,
		OceanDisplayClass8FontStyleOutlineColor,
		OceanFontStyleColor,
		OceanFontStyleOutlineColor,
		PanoramaCoverageColor,
		PanoramaCoverageOutlineColor,
		PanoramaHighlightPrimaryColor,
		PanoramaHighlightSecondaryColor,
		PanoramaRasterCoverageColor,
		PanoramaRasterCoverageOutlineColor,
		PanoramaRouteColor,
		PanoramaRouteSecondaryColor,
		PanoramaRouteArrowColor,
		PanoramaRouteArrowHighlightColor,
		PanoramaStreetColor,
		PanoramaStreetFontStyleColor,
		PanoramaStreetFontStyleOutlineColor,
		ParkColor,
		ParkInfoFontStyleColor,
		ParkInfoFontStyleOutlineColor,
		PedestrianAreaColor,
		PedestrianAreaInfoFontStyleColor,
		PedestrianAreaInfoFontStyleOutlineColor,
		PointOfInterest24hourFontStyleColor,
		PointOfInterest24hourFontStyleOutlineColor,
		PointOfInterestFontStyleColor,
		PointOfInterestFontStyleOutlineColor,
		PointOfInterestFuelTypeFontStyleColor,
		PointOfInterestFuelTypeFontStyleOutlineColor,
		RailFontStyleColor,
		RailFontStyleOutlineColor,
		RailwayStreetPolylineAttributeArrowColor,
		RailwayStreetPolylineAttributeArrowTollColor,
		RailwayStreetPolylineAttributeArrowUnpavedColor,
		RailwayStreetPolylineAttributeBridgeColor,
		RailwayStreetPolylineAttributeTollCenterlineColor,
		RailwayStreetPolylineAttributeTollColor,
		RailwayStreetPolylineAttributeTollOutlineColor,
		RailwayStreetPolylineAttributeTollThinColor,
		RailwayStreetPolylineAttributeTollTunnelColor,
		RailwayStreetPolylineAttributeUnpavedColor,
		RailwayStreetPolylineAttributeUnpavedOutlineColor,
		RailwayStreetPolylineAttributeUnpavedThinColor,
		RailyardColor,
		RailyardInfoFontStyleColor,
		RailyardInfoFontStyleOutlineColor,
		RemainingRangeEVGradientColorInner,
		RemainingRangeEVGradientColorOuter,
		RemainingRangeEVLineColor,
		RemainingRangeEVOutlineColor,
		RiverColor,
		RiverDisplayClass1Color,
		RiverDisplayClass1FontStyleColor,
		RiverDisplayClass1FontStyleOutlineColor,
		RiverDisplayClass2Color,
		RiverDisplayClass2FontStyleColor,
		RiverDisplayClass2FontStyleOutlineColor,
		RiverDisplayClass3Color,
		RiverDisplayClass3FontStyleColor,
		RiverDisplayClass3FontStyleOutlineColor,
		RiverDisplayClass4Color,
		RiverDisplayClass4FontStyleColor,
		RiverDisplayClass4FontStyleOutlineColor,
		RiverDisplayClass5Color,
		RiverDisplayClass5FontStyleColor,
		RiverDisplayClass5FontStyleOutlineColor,
		RiverDisplayClass6Color,
		RiverDisplayClass6FontStyleColor,
		RiverDisplayClass6FontStyleOutlineColor,
		RiverDisplayClass7Color,
		RiverDisplayClass7FontStyleColor,
		RiverDisplayClass7FontStyleOutlineColor,
		RiverDisplayClass8Color,
		RiverDisplayClass8FontStyleColor,
		RiverDisplayClass8FontStyleOutlineColor,
		RiverFontStyleColor,
		RiverFontStyleOutlineColor,
		RoadSignFontStyleColor,
		RoadSignFontStyleOutlineColor,
		RouteStyle1BillboardFontStyleColor,
		RouteStyle1BillboardFontStyleOutlineColor,
		RunwayColor,
		SSAOColor,
		SeaFontStyleColor,
		SeaFontStyleOutlineColor,
		ShoppingComplexColor,
		ShoppingComplexInfoFontStyleColor,
		ShoppingComplexInfoFontStyleOutlineColor,
		SkyColorBottom,
		SkyColorIntermediate,
		SkyColorTop,
		SportsComplexColor,
		SportsComplexInfoFontStyleColor,
		SportsComplexInfoFontStyleOutlineColor,
		StateAbbreviationLabelFontStyleColor,
		StateAbbreviationLabelFontStyleOutlineColor,
		StateBoundaryBackgroundColor,
		StateBoundaryColor,
		StateBoundaryDisputedBackgroundColor,
		StateBoundaryDisputedColor,
		StateLabelFontStyleColor,
		StateLabelFontStyleOutlineColor,
		StreetCategory0CenterLineColor,
		StreetCategory0CenterLineTunnelColor,
		StreetCategory0Color,
		StreetCategory0FontStyleColor,
		StreetCategory0FontStyleOutlineColor,
		StreetCategory0OutlineColor,
		StreetCategory0StreetPolylineAttributeArrowColor,
		StreetCategory0StreetPolylineAttributeArrowTollColor,
		StreetCategory0StreetPolylineAttributeArrowUnpavedColor,
		StreetCategory0StreetPolylineAttributeBridgeColor,
		StreetCategory0StreetPolylineAttributeTollCenterlineColor,
		StreetCategory0StreetPolylineAttributeTollColor,
		StreetCategory0StreetPolylineAttributeTollOutlineColor,
		StreetCategory0StreetPolylineAttributeTollThinColor,
		StreetCategory0StreetPolylineAttributeTollTunnelColor,
		StreetCategory0StreetPolylineAttributeUnpavedColor,
		StreetCategory0StreetPolylineAttributeUnpavedOutlineColor,
		StreetCategory0StreetPolylineAttributeUnpavedThinColor,
		StreetCategory0ThinColor,
		StreetCategory0TunnelColor,
		StreetCategory1Color,
		StreetCategory1FontStyleColor,
		StreetCategory1FontStyleOutlineColor,
		StreetCategory1OutlineColor,
		StreetCategory1RoadSignFontStyleColor,
		StreetCategory1RoadSignFontStyleOutlineColor,
		StreetCategory1StreetPolylineAttributeArrowColor,
		StreetCategory1StreetPolylineAttributeArrowTollColor,
		StreetCategory1StreetPolylineAttributeArrowUnpavedColor,
		StreetCategory1StreetPolylineAttributeBridgeColor,
		StreetCategory1StreetPolylineAttributeTollCenterlineColor,
		StreetCategory1StreetPolylineAttributeTollColor,
		StreetCategory1StreetPolylineAttributeTollOutlineColor,
		StreetCategory1StreetPolylineAttributeTollThinColor,
		StreetCategory1StreetPolylineAttributeTollTunnelColor,
		StreetCategory1StreetPolylineAttributeUnpavedColor,
		StreetCategory1StreetPolylineAttributeUnpavedOutlineColor,
		StreetCategory1StreetPolylineAttributeUnpavedThinColor,
		StreetCategory1ThinColor,
		StreetCategory1TunnelColor,
		StreetCategory2Color,
		StreetCategory2FontStyleColor,
		StreetCategory2FontStyleOutlineColor,
		StreetCategory2OutlineColor,
		StreetCategory2RoadSignFontStyleColor,
		StreetCategory2RoadSignFontStyleOutlineColor,
		StreetCategory2StreetPolylineAttributeArrowColor,
		StreetCategory2StreetPolylineAttributeArrowTollColor,
		StreetCategory2StreetPolylineAttributeArrowUnpavedColor,
		StreetCategory2StreetPolylineAttributeBridgeColor,
		StreetCategory2StreetPolylineAttributeTollCenterlineColor,
		StreetCategory2StreetPolylineAttributeTollColor,
		StreetCategory2StreetPolylineAttributeTollOutlineColor,
		StreetCategory2StreetPolylineAttributeTollThinColor,
		StreetCategory2StreetPolylineAttributeTollTunnelColor,
		StreetCategory2StreetPolylineAttributeUnpavedColor,
		StreetCategory2StreetPolylineAttributeUnpavedOutlineColor,
		StreetCategory2StreetPolylineAttributeUnpavedThinColor,
		StreetCategory2ThinColor,
		StreetCategory2TunnelColor,
		StreetCategory3Color,
		StreetCategory3FontStyleColor,
		StreetCategory3FontStyleOutlineColor,
		StreetCategory3OutlineColor,
		StreetCategory3RoadSignFontStyleColor,
		StreetCategory3RoadSignFontStyleOutlineColor,
		StreetCategory3StreetPolylineAttributeArrowColor,
		StreetCategory3StreetPolylineAttributeArrowTollColor,
		StreetCategory3StreetPolylineAttributeArrowUnpavedColor,
		StreetCategory3StreetPolylineAttributeBridgeColor,
		StreetCategory3StreetPolylineAttributeTollCenterlineColor,
		StreetCategory3StreetPolylineAttributeTollColor,
		StreetCategory3StreetPolylineAttributeTollOutlineColor,
		StreetCategory3StreetPolylineAttributeTollThinColor,
		StreetCategory3StreetPolylineAttributeTollTunnelColor,
		StreetCategory3StreetPolylineAttributeUnpavedColor,
		StreetCategory3StreetPolylineAttributeUnpavedOutlineColor,
		StreetCategory3StreetPolylineAttributeUnpavedThinColor,
		StreetCategory3ThinColor,
		StreetCategory3TunnelColor,
		StreetCategory4Color,
		StreetCategory4FontStyleColor,
		StreetCategory4FontStyleOutlineColor,
		StreetCategory4OutlineColor,
		StreetCategory4RoadSignFontStyleColor,
		StreetCategory4RoadSignFontStyleOutlineColor,
		StreetCategory4StreetPolylineAttributeArrowColor,
		StreetCategory4StreetPolylineAttributeArrowTollColor,
		StreetCategory4StreetPolylineAttributeArrowUnpavedColor,
		StreetCategory4StreetPolylineAttributeBridgeColor,
		StreetCategory4StreetPolylineAttributeTollCenterlineColor,
		StreetCategory4StreetPolylineAttributeTollColor,
		StreetCategory4StreetPolylineAttributeTollOutlineColor,
		StreetCategory4StreetPolylineAttributeTollThinColor,
		StreetCategory4StreetPolylineAttributeTollTunnelColor,
		StreetCategory4StreetPolylineAttributeUnpavedColor,
		StreetCategory4StreetPolylineAttributeUnpavedOutlineColor,
		StreetCategory4StreetPolylineAttributeUnpavedThinColor,
		StreetCategory4ThinColor,
		StreetCategory4TunnelColor,
		StreetPedestrianColor,
		StreetPedestrianFontStyleColor,
		StreetPedestrianFontStyleOutlineColor,
		StreetPedestrianOutlineColor,
		StreetPedestrianStreetPolylineAttributeArrowColor,
		StreetPedestrianStreetPolylineAttributeArrowTollColor,
		StreetPedestrianStreetPolylineAttributeArrowUnpavedColor,
		StreetPedestrianStreetPolylineAttributeBridgeColor,
		StreetPedestrianStreetPolylineAttributeTollCenterlineColor,
		StreetPedestrianStreetPolylineAttributeTollColor,
		StreetPedestrianStreetPolylineAttributeTollOutlineColor,
		StreetPedestrianStreetPolylineAttributeTollThinColor,
		StreetPedestrianStreetPolylineAttributeTollTunnelColor,
		StreetPedestrianStreetPolylineAttributeUnpavedColor,
		StreetPedestrianStreetPolylineAttributeUnpavedOutlineColor,
		StreetPedestrianStreetPolylineAttributeUnpavedThinColor,
		StreetPedestrianThinColor,
		StreetPedestrianTunnelColor,
		StreetWalkwayColor,
		StreetWalkwayFontStyleColor,
		StreetWalkwayFontStyleOutlineColor,
		StreetWalkwayOutlineColor,
		StreetWalkwayStreetPolylineAttributeArrowColor,
		StreetWalkwayStreetPolylineAttributeArrowTollColor,
		StreetWalkwayStreetPolylineAttributeArrowUnpavedColor,
		StreetWalkwayStreetPolylineAttributeBridgeColor,
		StreetWalkwayStreetPolylineAttributeTollCenterlineColor,
		StreetWalkwayStreetPolylineAttributeTollColor,
		StreetWalkwayStreetPolylineAttributeTollOutlineColor,
		StreetWalkwayStreetPolylineAttributeTollThinColor,
		StreetWalkwayStreetPolylineAttributeTollTunnelColor,
		StreetWalkwayStreetPolylineAttributeUnpavedColor,
		StreetWalkwayStreetPolylineAttributeUnpavedOutlineColor,
		StreetWalkwayStreetPolylineAttributeUnpavedThinColor,
		StreetWalkwayThinColor,
		StreetWalkwayTunnelColor,
		TMC_INCIDENTBLOCKINGColor,
		TMC_INCIDENTBLOCKINGSelectedColor,
		TMC_INCIDENTHIGHColor,
		TMC_INCIDENTHIGHSelectedColor,
		TMC_INCIDENTNORMALColor,
		TMC_INCIDENTNORMALSelectedColor,
		TMC_INCIDENTVERY_HIGHColor,
		TMC_INCIDENTVERY_HIGHSelectedColor,
		TransitAerialDefaultColor,
		TransitBackgroundColor,
		TransitBlendColor,
		TransitBusExpressDefaultColor,
		TransitBusIntercityDefaultColor,
		TransitBusPublicDefaultColor,
		TransitBusTouristicDefaultColor,
		TransitHighlightedBackgroundColor,
		TransitHighlightedFontOutlineColor,
		TransitInclinedDefaultColor,
		TransitMonorailDefaultColor,
		TransitRailCityMetroDefaultColor,
		TransitRailLightDefaultColor,
		TransitRailRegionalDefaultColor,
		TransitStopFontStyleColor,
		TransitStopFontStyleOutlineColor,
		TransitTrainHighSpeedDefaultColor,
		TransitTrainIntercityDefaultColor,
		TransitTrainRegionalDefaultColor,
		TransitWaterBackgroundColor,
		TransitWaterDefaultColor,
		TransitWaterHighlightedBackgroundColor,
		TransitWaterHighlightedFontOutlineColor,
		TruckIconFontStyleColor,
		TruckIconFontStyleOutlineColor,
		TruckLineColor,
		UniversityCampusColor,
		UniversityCampusInfoFontStyleColor,
		UniversityCampusInfoFontStyleOutlineColor,
		WaterColor0m,
		WaterColor3000m,
		WoodlandColor,
		WoodlandInfoFontStyleColor,
		WoodlandInfoFontStyleOutlineColor,
		WorldMountainsColor1500m,
		WorldMountainsColor3000m,
		ColorPropertyCount
	}

	[Native]
	public enum NMASchemeFloatProperty : nint
	{
		AirportAreaInfoFontStyleOutlineWidth,
		AirportAreaInfoFontStyleSize,
		AllotmentInfoFontStyleOutlineWidth,
		AllotmentInfoFontStyleSize,
		AmusementParkInfoFontStyleOutlineWidth,
		AmusementParkInfoFontStyleSize,
		AnimalParkInfoFontStyleOutlineWidth,
		AnimalParkInfoFontStyleSize,
		AvoidBlockedRouteOutlineWidth,
		AvoidBlockedRouteWidth,
		BayHarbourDisplayClass1FontStyleOutlineWidth,
		BayHarbourDisplayClass1FontStyleSize,
		BayHarbourDisplayClass2FontStyleOutlineWidth,
		BayHarbourDisplayClass2FontStyleSize,
		BayHarbourDisplayClass3FontStyleOutlineWidth,
		BayHarbourDisplayClass3FontStyleSize,
		BayHarbourDisplayClass4FontStyleOutlineWidth,
		BayHarbourDisplayClass4FontStyleSize,
		BayHarbourDisplayClass5FontStyleOutlineWidth,
		BayHarbourDisplayClass5FontStyleSize,
		BayHarbourDisplayClass6FontStyleOutlineWidth,
		BayHarbourDisplayClass6FontStyleSize,
		BayHarbourDisplayClass7FontStyleOutlineWidth,
		BayHarbourDisplayClass7FontStyleSize,
		BayHarbourDisplayClass8FontStyleOutlineWidth,
		BayHarbourDisplayClass8FontStyleSize,
		BayHarbourFontStyleOutlineWidth,
		BayHarbourFontStyleSize,
		BeachInfoFontStyleOutlineWidth,
		BeachInfoFontStyleSize,
		BillboardAdjacentFontStyleOutlineWidth,
		BillboardAdjacentFontStyleSize,
		BillboardAdjacentOutlineWidth,
		BillboardAdjacentPointerHeight,
		BillboardOffRouteFontStyleOutlineWidth,
		BillboardOffRouteFontStyleSize,
		BillboardOffRouteOutlineWidth,
		BillboardOffRoutePointerHeight,
		BuildingAddressFontStyleOutlineWidth,
		BuildingAddressFontStyleSize,
		BuildingInfoFontStyleOutlineWidth,
		BuildingInfoFontStyleSize,
		BuiltupBorderBackgroundWidth,
		BuiltupBorderWidth,
		CanalWaterChannelDisplayClass1FontStyleOutlineWidth,
		CanalWaterChannelDisplayClass1FontStyleSize,
		CanalWaterChannelDisplayClass1Width,
		CanalWaterChannelDisplayClass2FontStyleOutlineWidth,
		CanalWaterChannelDisplayClass2FontStyleSize,
		CanalWaterChannelDisplayClass2Width,
		CanalWaterChannelDisplayClass3FontStyleOutlineWidth,
		CanalWaterChannelDisplayClass3FontStyleSize,
		CanalWaterChannelDisplayClass3Width,
		CanalWaterChannelDisplayClass4FontStyleOutlineWidth,
		CanalWaterChannelDisplayClass4FontStyleSize,
		CanalWaterChannelDisplayClass4Width,
		CanalWaterChannelDisplayClass5FontStyleOutlineWidth,
		CanalWaterChannelDisplayClass5FontStyleSize,
		CanalWaterChannelDisplayClass5Width,
		CanalWaterChannelDisplayClass6FontStyleOutlineWidth,
		CanalWaterChannelDisplayClass6FontStyleSize,
		CanalWaterChannelDisplayClass6Width,
		CanalWaterChannelDisplayClass7FontStyleOutlineWidth,
		CanalWaterChannelDisplayClass7FontStyleSize,
		CanalWaterChannelDisplayClass7Width,
		CanalWaterChannelDisplayClass8FontStyleOutlineWidth,
		CanalWaterChannelDisplayClass8FontStyleSize,
		CanalWaterChannelDisplayClass8Width,
		CanalWaterChannelFontStyleOutlineWidth,
		CanalWaterChannelFontStyleSize,
		CanalWaterChannelWidth,
		CemeteryInfoFontStyleOutlineWidth,
		CemeteryInfoFontStyleSize,
		CityCenterClass1FontStyleOutlineWidth,
		CityCenterClass1FontStyleSize,
		CityCenterClass2FontStyleOutlineWidth,
		CityCenterClass2FontStyleSize,
		CityCenterClass3FontStyleOutlineWidth,
		CityCenterClass3FontStyleSize,
		CityCenterClass4FontStyleOutlineWidth,
		CityCenterClass4FontStyleSize,
		CityCenterClass5FontStyleOutlineWidth,
		CityCenterClass5FontStyleSize,
		CityCenterDistrictFontStyleOutlineWidth,
		CityCenterDistrictFontStyleSize,
		CityCenterHamletFontStyleOutlineWidth,
		CityCenterHamletFontStyleSize,
		CongestionZoneInfoFontStyleOutlineWidth,
		CongestionZoneInfoFontStyleSize,
		ContinentLabelFontStyleOutlineWidth,
		ContinentLabelFontStyleSize,
		CountryBoundaryBackgroundWidth,
		CountryBoundaryWidth,
		CountryBoundaryDisputedBackgroundWidth,
		CountryBoundaryDisputedWidth,
		CountrySideLabelFontStyleOutlineWidth,
		CountrySideLabelFontStyleSize,
		EnvironmentalZoneInfoFontStyleOutlineWidth,
		EnvironmentalZoneInfoFontStyleSize,
		ExitInfoStreetCategory0FontStyleOutlineWidth,
		ExitInfoStreetCategory0FontStyleSize,
		ExitInfoStreetCategory0OutlineWidth,
		ExitInfoStreetCategory0TollFontStyleOutlineWidth,
		ExitInfoStreetCategory0TollFontStyleSize,
		ExitInfoStreetCategory0TollOutlineWidth,
		ExitInfoStreetCategory1FontStyleOutlineWidth,
		ExitInfoStreetCategory1FontStyleSize,
		ExitInfoStreetCategory1OutlineWidth,
		ExitInfoStreetCategory1TollFontStyleOutlineWidth,
		ExitInfoStreetCategory1TollFontStyleSize,
		ExitInfoStreetCategory1TollOutlineWidth,
		ExitInfoStreetCategory2FontStyleOutlineWidth,
		ExitInfoStreetCategory2FontStyleSize,
		ExitInfoStreetCategory2OutlineWidth,
		ExitInfoStreetCategory2TollFontStyleOutlineWidth,
		ExitInfoStreetCategory2TollFontStyleSize,
		ExitInfoStreetCategory2TollOutlineWidth,
		ExitInfoSimplifiedStreetCategory0OutlineWidth,
		ExitInfoSimplifiedStreetCategory0TollOutlineWidth,
		ExitInfoSimplifiedStreetCategory1OutlineWidth,
		ExitInfoSimplifiedStreetCategory1TollOutlineWidth,
		ExitInfoSimplifiedStreetCategory2OutlineWidth,
		ExitInfoSimplifiedStreetCategory2TollOutlineWidth,
		ExtrudedBuildingsDefaultHeight,
		ExtrudedBuildingsGradientStopHeight,
		FarPlaneHorizonHeightPercent,
		FarPlaneHorizonHeightTiltRange,
		FarPlaneHorizonHeightTiltStart,
		FerryFontStyleOutlineWidth,
		FerryFontStyleSize,
		GolfCourseInfoFontStyleOutlineWidth,
		GolfCourseInfoFontStyleSize,
		HarborAreaInfoFontStyleOutlineWidth,
		HarborAreaInfoFontStyleSize,
		HospitalCampusInfoFontStyleOutlineWidth,
		HospitalCampusInfoFontStyleSize,
		IndustrialComplexInfoFontStyleOutlineWidth,
		IndustrialComplexInfoFontStyleSize,
		IntermittentRiverDisplayClass1FontStyleOutlineWidth,
		IntermittentRiverDisplayClass1FontStyleSize,
		IntermittentRiverDisplayClass1Width,
		IntermittentRiverDisplayClass2FontStyleOutlineWidth,
		IntermittentRiverDisplayClass2FontStyleSize,
		IntermittentRiverDisplayClass2Width,
		IntermittentRiverDisplayClass3FontStyleOutlineWidth,
		IntermittentRiverDisplayClass3FontStyleSize,
		IntermittentRiverDisplayClass3Width,
		IntermittentRiverDisplayClass4FontStyleOutlineWidth,
		IntermittentRiverDisplayClass4FontStyleSize,
		IntermittentRiverDisplayClass4Width,
		IntermittentRiverDisplayClass5FontStyleOutlineWidth,
		IntermittentRiverDisplayClass5FontStyleSize,
		IntermittentRiverDisplayClass5Width,
		IntermittentRiverDisplayClass6FontStyleOutlineWidth,
		IntermittentRiverDisplayClass6FontStyleSize,
		IntermittentRiverDisplayClass6Width,
		IntermittentRiverDisplayClass7FontStyleOutlineWidth,
		IntermittentRiverDisplayClass7FontStyleSize,
		IntermittentRiverDisplayClass7Width,
		IntermittentRiverDisplayClass8FontStyleOutlineWidth,
		IntermittentRiverDisplayClass8FontStyleSize,
		IntermittentRiverDisplayClass8Width,
		IntermittentRiverFontStyleOutlineWidth,
		IntermittentRiverFontStyleSize,
		IntermittentRiverWidth,
		IslandInfoFontStyleOutlineWidth,
		IslandInfoFontStyleSize,
		LakeDisplayClass1FontStyleOutlineWidth,
		LakeDisplayClass1FontStyleSize,
		LakeDisplayClass2FontStyleOutlineWidth,
		LakeDisplayClass2FontStyleSize,
		LakeDisplayClass3FontStyleOutlineWidth,
		LakeDisplayClass3FontStyleSize,
		LakeDisplayClass4FontStyleOutlineWidth,
		LakeDisplayClass4FontStyleSize,
		LakeDisplayClass5FontStyleOutlineWidth,
		LakeDisplayClass5FontStyleSize,
		LakeDisplayClass6FontStyleOutlineWidth,
		LakeDisplayClass6FontStyleSize,
		LakeDisplayClass7FontStyleOutlineWidth,
		LakeDisplayClass7FontStyleSize,
		LakeDisplayClass8FontStyleOutlineWidth,
		LakeDisplayClass8FontStyleSize,
		LakeFontStyleOutlineWidth,
		LakeFontStyleSize,
		LandCoverDesertFontStyleOutlineWidth,
		LandCoverDesertFontStyleSize,
		LandCoverGlacierFontStyleOutlineWidth,
		LandCoverGlacierFontStyleSize,
		LaneWidthM,
		LineOfControlBackgroundWidth,
		LineOfControlWidth,
		MajorCountryLabelFontStyleOutlineWidth,
		MajorCountryLabelFontStyleSize,
		MarkingLaneWidth,
		MilitaryBaseInfoFontStyleOutlineWidth,
		MilitaryBaseInfoFontStyleSize,
		MinorCountryLabelFontStyleOutlineWidth,
		MinorCountryLabelFontStyleSize,
		MotorwayJunctionSimplifiedIconOutlineWidth,
		MountainPeakHeightFontStyleOutlineWidth,
		MountainPeakHeightFontStyleSize,
		MountainPeakInfoFontStyleOutlineWidth,
		MountainPeakInfoFontStyleSize,
		MountainRangeInfoDisplayClass1FontStyleOutlineWidth,
		MountainRangeInfoDisplayClass1FontStyleSize,
		MountainRangeInfoDisplayClass2FontStyleOutlineWidth,
		MountainRangeInfoDisplayClass2FontStyleSize,
		MountainRangeInfoDisplayClass3FontStyleOutlineWidth,
		MountainRangeInfoDisplayClass3FontStyleSize,
		MountainRangeInfoFontStyleOutlineWidth,
		MountainRangeInfoFontStyleSize,
		NationalForestInfoFontStyleOutlineWidth,
		NationalForestInfoFontStyleSize,
		NationalGrasslandInfoFontStyleOutlineWidth,
		NationalGrasslandInfoFontStyleSize,
		NationalHistoricParkInfoFontStyleOutlineWidth,
		NationalHistoricParkInfoFontStyleSize,
		NationalParkInfoFontStyleOutlineWidth,
		NationalParkInfoFontStyleSize,
		NationalRecreationAreaInfoFontStyleOutlineWidth,
		NationalRecreationAreaInfoFontStyleSize,
		NationalStateParkInfoFontStyleOutlineWidth,
		NationalStateParkInfoFontStyleSize,
		NativeReservationInfoFontStyleOutlineWidth,
		NativeReservationInfoFontStyleSize,
		NeighborhoodInfoFontStyle0OutlineWidth,
		NeighborhoodInfoFontStyle0Size,
		NeighborhoodInfoFontStyle1OutlineWidth,
		NeighborhoodInfoFontStyle1Size,
		NeighborhoodInfoFontStyle2OutlineWidth,
		NeighborhoodInfoFontStyle2Size,
		NeighborhoodInfoFontStyle3OutlineWidth,
		NeighborhoodInfoFontStyle3Size,
		NeighborhoodInfoFontStyle4OutlineWidth,
		NeighborhoodInfoFontStyle4Size,
		NeighborhoodInfoFontStyle5OutlineWidth,
		NeighborhoodInfoFontStyle5Size,
		OceanDisplayClass1FontStyleOutlineWidth,
		OceanDisplayClass1FontStyleSize,
		OceanDisplayClass2FontStyleOutlineWidth,
		OceanDisplayClass2FontStyleSize,
		OceanDisplayClass3FontStyleOutlineWidth,
		OceanDisplayClass3FontStyleSize,
		OceanDisplayClass4FontStyleOutlineWidth,
		OceanDisplayClass4FontStyleSize,
		OceanDisplayClass5FontStyleOutlineWidth,
		OceanDisplayClass5FontStyleSize,
		OceanDisplayClass6FontStyleOutlineWidth,
		OceanDisplayClass6FontStyleSize,
		OceanDisplayClass7FontStyleOutlineWidth,
		OceanDisplayClass7FontStyleSize,
		OceanDisplayClass8FontStyleOutlineWidth,
		OceanDisplayClass8FontStyleSize,
		OceanFontStyleOutlineWidth,
		OceanFontStyleSize,
		PanoramaRasterCoverageBlendWidthFactor,
		PanoramaRasterCoverageOutlineWidthFactor,
		PanoramaRouteArrowWidthM,
		PanoramaStreetFontStyleOutlineWidth,
		PanoramaStreetFontStyleSize,
		PanoramaStreetWidthM,
		ParkInfoFontStyleOutlineWidth,
		ParkInfoFontStyleSize,
		PedestrianAreaInfoFontStyleOutlineWidth,
		PedestrianAreaInfoFontStyleSize,
		PointOfInterest24hourFontStyleOutlineWidth,
		PointOfInterest24hourFontStyleSize,
		PointOfInterestFontStyleOutlineWidth,
		PointOfInterestFontStyleSize,
		PointOfInterestFuelTypeFontStyleOutlineWidth,
		PointOfInterestFuelTypeFontStyleSize,
		RailFontStyleOutlineWidth,
		RailFontStyleSize,
		RailyardInfoFontStyleOutlineWidth,
		RailyardInfoFontStyleSize,
		RemainingRangeEVLineWidth,
		RemainingRangeEVOutlineWidth,
		RiverDisplayClass1FontStyleOutlineWidth,
		RiverDisplayClass1FontStyleSize,
		RiverDisplayClass1Width,
		RiverDisplayClass2FontStyleOutlineWidth,
		RiverDisplayClass2FontStyleSize,
		RiverDisplayClass2Width,
		RiverDisplayClass3FontStyleOutlineWidth,
		RiverDisplayClass3FontStyleSize,
		RiverDisplayClass3Width,
		RiverDisplayClass4FontStyleOutlineWidth,
		RiverDisplayClass4FontStyleSize,
		RiverDisplayClass4Width,
		RiverDisplayClass5FontStyleOutlineWidth,
		RiverDisplayClass5FontStyleSize,
		RiverDisplayClass5Width,
		RiverDisplayClass6FontStyleOutlineWidth,
		RiverDisplayClass6FontStyleSize,
		RiverDisplayClass6Width,
		RiverDisplayClass7FontStyleOutlineWidth,
		RiverDisplayClass7FontStyleSize,
		RiverDisplayClass7Width,
		RiverDisplayClass8FontStyleOutlineWidth,
		RiverDisplayClass8FontStyleSize,
		RiverDisplayClass8Width,
		RiverFontStyleOutlineWidth,
		RiverFontStyleSize,
		RiverWidth,
		RoadSignFontStyleOutlineWidth,
		RoadSignFontStyleSize,
		RouteStyle1BillboardFontStyleOutlineWidth,
		RouteStyle1BillboardFontStyleSize,
		SeaFontStyleOutlineWidth,
		SeaFontStyleSize,
		ShoppingComplexInfoFontStyleOutlineWidth,
		ShoppingComplexInfoFontStyleSize,
		SportsComplexInfoFontStyleOutlineWidth,
		SportsComplexInfoFontStyleSize,
		StateAbbreviationLabelFontStyleOutlineWidth,
		StateAbbreviationLabelFontStyleSize,
		StateBoundaryBackgroundWidth,
		StateBoundaryWidth,
		StateBoundaryDisputedBackgroundWidth,
		StateBoundaryDisputedWidth,
		StateLabelFontStyleOutlineWidth,
		StateLabelFontStyleSize,
		StreetCategory0CenterLineWidth,
		StreetCategory0FontStyleOutlineWidth,
		StreetCategory0FontStyleSize,
		StreetCategory0OutlineWidth,
		StreetCategory0Width,
		StreetCategory1FontStyleOutlineWidth,
		StreetCategory1FontStyleSize,
		StreetCategory1OutlineWidth,
		StreetCategory1RoadSignFontStyleOutlineWidth,
		StreetCategory1RoadSignFontStyleSize,
		StreetCategory1Width,
		StreetCategory2FontStyleOutlineWidth,
		StreetCategory2FontStyleSize,
		StreetCategory2OutlineWidth,
		StreetCategory2RoadSignFontStyleOutlineWidth,
		StreetCategory2RoadSignFontStyleSize,
		StreetCategory2Width,
		StreetCategory3FontStyleOutlineWidth,
		StreetCategory3FontStyleSize,
		StreetCategory3OutlineWidth,
		StreetCategory3RoadSignFontStyleOutlineWidth,
		StreetCategory3RoadSignFontStyleSize,
		StreetCategory3Width,
		StreetCategory4FontStyleOutlineWidth,
		StreetCategory4FontStyleSize,
		StreetCategory4OutlineWidth,
		StreetCategory4RoadSignFontStyleOutlineWidth,
		StreetCategory4RoadSignFontStyleSize,
		StreetCategory4Width,
		StreetPedestrianFontStyleOutlineWidth,
		StreetPedestrianFontStyleSize,
		StreetPedestrianOutlineWidth,
		StreetPedestrianWidth,
		StreetWalkwayFontStyleOutlineWidth,
		StreetWalkwayFontStyleSize,
		StreetWalkwayOutlineWidth,
		StreetWalkwayWidth,
		TransitStopFontStyleOutlineWidth,
		TransitStopFontStyleSize,
		TruckIconFontStyleOutlineWidth,
		TruckIconFontStyleSize,
		UniversityCampusInfoFontStyleOutlineWidth,
		UniversityCampusInfoFontStyleSize,
		WoodlandInfoFontStyleOutlineWidth,
		WoodlandInfoFontStyleSize,
		ZoneBorderWidth,
		FloatPropertyCount
	}

	[Native]
	public enum NMASchemeBooleanProperty : nint
	{
		TruckIconIconScaleEnabled,
		BooleanPropertyCount
	}

	[Native]
	public enum NMASchemeIntegerProperty : nint
	{
		AreaIconSize,
		BuiltupAreaMinPixelHeight,
		BuiltupAreaMinPixelWidth,
		ElevationMapHeight0,
		ElevationMapHeight1,
		ElevationMapHeight2,
		ElevationMapHeight3,
		ElevationMapHeight4,
		ElevationMapHeight5,
		ElevationMapHeight6,
		ElevationMapHeight7,
		ElevationMapNumHeights,
		ElevationMapRangedScale0MaxHeight,
		ElevationMapRangedScale1MaxHeight,
		ElevationMapRangedScale2MaxHeight,
		ElevationMapRangedScale3MaxHeight,
		FogHeight,
		MountainPeakIconSize,
		PanoramaCoverageOutlineWidth,
		PanoramaCoverageWidth,
		PedestrianPointIconSize,
		PointOfInterest24hourIconSize,
		PointOfInterestFuelTypeIconSize,
		PointOfInterestGeneralIconSize,
		TransitAerialWidth,
		TransitBusExpressWidth,
		TransitBusIntercityWidth,
		TransitBusPublicWidth,
		TransitBusTouristicWidth,
		TransitInclinedWidth,
		TransitMonorailWidth,
		TransitOutlineWidth,
		TransitRailCityMetroWidth,
		TransitRailLightWidth,
		TransitRailRegionalWidth,
		TransitTrainHighSpeedWidth,
		TransitTrainIntercityWidth,
		TransitTrainRegionalWidth,
		TransitWaterWidth,
		TransitAccessAirlineIconSize,
		TransitAccessIconSize,
		TruckIconIconSize,
		TruckLineCategory0Width,
		TruckLineCategory1Width,
		TruckLineCategory2Width,
		TruckLineCategory3Width,
		TruckLineCategory4Width,
		IntegerPropertyCount
	}

	[Native]
	public enum NMALocationInfoField : nuint
	{
		PlaceName,
		PlaceCategory,
		PlacePhoneNumber,
		ReferenceIdentifier,
		ReferenceSource
	}

	[Native]
	public enum NMAMapGestureType : nint
	{
		DoubleTap = 1 << 0,
		LongPress = 1 << 1,
		Pan = 1 << 2,
		Pinch = 1 << 3,
		Rotate = 1 << 4,
		Tap = 1 << 5,
		TwoFingerPan = 1 << 6,
		TwoFingerTap = 1 << 7,
		All = 255
	}

	[Native]
	public enum NMAMapPackageInstallation : nuint
	{
		None = 0,
		Implicit,
		Explicit,
		PartiallyInstalled
	}

	[Native]
	public enum NMAMapDataGroup : nint
	{
		TruckAttributes = 12,
		ScooterAttributes = 13,
		LowRes3DLandmarks = 17,
		Terrain3D = 18,
		SimpleExtrudedBuildings = 20,
		WorldwideExtendedPOI = 21,
		WorldwidePointAddresses = 22,
		LinkGDBIdPVId = 26,
		PhoneticNames = 49,
		RealisticViews16x9 = 50,
		RealisticViews3x5 = 51,
		RealisticViews4x3 = 52,
		RealisticViews5x3 = 53,
		Adas = 54
	}

	[Native]
	public enum NMAMapLoaderResult : nuint
	{
		Success,
		InvalidParameters,
		OperationCancelled,
		InitializationFailed,
		ConnectionFailed,
		SearchFailed,
		InsufficientStorage
	}

	[Native]
	public enum NMAProjectionType : nint
	{
		Mercator,
		Globe
	}

	[Native]
	public enum NMAMapAnimation : nuint
	{
		Bow,
		Linear,
		None,
		Rocket
	}

	[Native]
	public enum NMAMapEvent : nint
	{
		GeoCenterChanged = 1 << 0,
		ZoomLevelChanged = 1 << 1,
		OrientationChanged = 1 << 2,
		TiltChanged = 1 << 3,
		TransformationBegan = 1 << 4,
		TransformationEnded = 1 << 5,
		GestureBegan = 1 << 6,
		GestureEnded = 1 << 7,
		AnimationBegan = 1 << 8,
		AnimationEnded = 1 << 9,
		MarkerDragBegan = 1 << 10,
		MarkerDragged = 1 << 11,
		MarkerDragEnded = 1 << 12,
		All = 65535
	}

	[Native]
	public enum NMAMapTransitDisplayMode : nint
	{
		Nothing,
		StopAndAccess,
		Everything
	}

	[Native]
	public enum NMATrafficLayer : nint
	{
		Flow = 1,
		Incidents = 2,
		OnRoute = 4,
		All = 255
	}

	[Native]
	public enum NMAMapLayerCategory : nint
	{
		Land,
		Water,
		LabelOcean,
		LabelSea,
		LabelWaterOther,
		Beach,
		Woodland,
		Desert,
		Glacier,
		LabelBeach,
		LabelWoodland,
		LabelDesert,
		LabelGlacier,
		AirportArea,
		AmusementPark,
		AnimalPark,
		Builtup,
		Cemetery,
		GolfCourse,
		HarborArea,
		HospitalCampus,
		IndustrialComplex,
		MilitaryBase,
		NationalPark,
		NativeReservation,
		OutlineMilitaryBase,
		OutlineNationalPark,
		OutlineNativeReservation,
		CityPark,
		PedestrianArea,
		Railyard,
		ShoppingComplex,
		SportsComplex,
		UniversityCampus,
		LabelAirportArea,
		LabelAmusementPark,
		LabelAnimalPark,
		LabelCemetery,
		LabelGolfCourse,
		LabelHarborArea,
		LabelHospitalCampus,
		LabelIndustrialComplex,
		LabelMilitaryBase,
		LabelNationalPark,
		LabelNativeReservation,
		LabelCityPark,
		LabelPedestrianArea,
		LabelRailyard,
		LabelShoppingComplex,
		LabelSportsComplex,
		LabelUniversityCampus,
		StreetCategory0,
		StreetCategory1,
		StreetCategory2,
		StreetCategory3,
		StreetCategory4,
		StreetCategoryPedestrian,
		StreetCategoryWalkway,
		LabelStreetCategory0,
		LabelStreetCategory1,
		LabelStreetCategory2,
		LabelStreetCategory3,
		LabelStreetCategory4,
		LabelStreetCategoryPedestrian,
		LabelStreetCategoryWalkway,
		RoadsignIcon,
		ExitSign,
		BorderCountry,
		BorderState,
		BorderRegional,
		BorderBuiltup,
		BorderLineOfControl,
		NeighborhoodArea,
		LabelContinent = 74,
		LabelMajorCountry,
		LabelMinorCountry,
		LabelState,
		LabelStateAbbreviation,
		LabelCityCapital,
		LabelCityStateCapital,
		LabelCityOther,
		LabelNeighborhoodArea,
		PublicTransitLine,
		LabelPublicTransitLine,
		IconPublicTransitStation,
		LabelPublicTransitStation,
		Relief,
		Background,
		LabelMountain,
		IconMountain,
		LabelIsland,
		Building,
		LabelBuilding,
		PointAddress,
		PedestrianFeature,
		Railroad,
		Ferry,
		LabelFerry,
		PoiIcon,
		PoiLabel,
		Count,
		None
	}

	[Native]
	public enum NMAMapPoiCategory : nint
	{
		AirLineAccess,
		AmusementPark,
		CarDealer,
		Casino,
		Cinema,
		Company,
		ConcertHall,
		Congress,
		Courthouse,
		CulturalCentre,
		ExhibitionCentre,
		GolfCourse,
		GovernmentOffice,
		HolidayPark,
		Museum,
		Opera,
		ParkingGarage,
		PetrolStation,
		PlaceOfWorship,
		PostOffice,
		RentACarFacility,
		RestArea,
		Restaurant,
		Shop,
		ShoppingCentre,
		Stadium,
		Theatre,
		TouristAttraction,
		TouristInformationCentre,
		University,
		Zoo,
		Library,
		Camping,
		BarDisco,
		Embassy,
		FerryTerminal,
		FrontierCrossing,
		Hospital,
		Hotel,
		ParkingArea,
		Police,
		RailwayStation,
		MetroStation,
		Airport,
		MountainPass,
		MountainPeak,
		Carrepair,
		CashDispenser,
		ParkRecreation,
		Pharmacy,
		Beach,
		BusStation = 57,
		Education = 106,
		ResidentialArea = 117,
		EVChargingStation = 196,
		NightClub = 203,
		PublicToilet = 204,
		Laundry = 207,
		TaxiStand = 216,
		RailwayAccess = 217,
		BarsCafes = 218,
		Parking = 219,
		SportOutdoor = 220,
		MetroAccess = 221,
		AutMetroAccess = 222,
		AutMetroStop = 223,
		BelMetroAccess = 224,
		BelMetroStop = 225,
		CzeMetroAccess = 226,
		CzeMetroStop = 227,
		DenMetroAccess = 228,
		DenMetroStop = 229,
		FinMetroAccess = 230,
		FinMetroStop = 231,
		FraMetroAccess = 232,
		FraMetroStop = 233,
		FraRerAccess = 234,
		FraRerStop = 235,
		DeuMetroAccess = 236,
		DeuMetroStop = 237,
		DeuSbahnAccess = 238,
		DeuSbahnStop = 239,
		ItaMetroAccess = 240,
		ItaMetroStop = 241,
		NorMetroAccess = 242,
		NorMetroStop = 243,
		PrtMetroAccess = 244,
		PrtMetroStop = 245,
		EspBarcelonaMetroAccess = 246,
		EspBarcelonaMetroStop = 247,
		EspCercaniasMetroAccess = 248,
		EspCercaniasMetroStop = 249,
		EspMadridMetroAccess = 250,
		EspMadridMetroStop = 251,
		SweMetroAccess = 252,
		SweMetroStop = 253,
		GbrGlasgowMetroAccess = 254,
		GbrGlasgowMetroStop = 255,
		GbrLondonMetroAccess = 256,
		GbrLondonMetroStop = 257,
		All = 258
	}

	[Native]
	public enum NMAMapRouteRenderType : nuint
	{
		Primary = 1,
		Secondary = 2,
		UserDefined = 3
	}

	[Native]
	public enum NMAMapTileRequestStatus : nuint
	{
		Unitialized,
		Pending,
		Failed,
		Complete
	}

	[Native]
	public enum NMAPositionIndicatorType : nuint
	{
		Raw,
		MapMatched,
		Current
	}

	[Native]
	public enum NMALaneInformationDirection : nuint
	{
		Undefined = 0,
		Straight = 1 << 0,
		SlightlyRight = 1 << 1,
		Right = 1 << 2,
		SharpRight = 1 << 3,
		UTurnLeft = 1 << 4,
		SharpLeft = 1 << 5,
		Left = 1 << 6,
		SlightlyLeft = 1 << 7,
		MergeRight = 1 << 8,
		MergeLeft = 1 << 9,
		MergeLanes = 1 << 10,
		UTurnRight = 1 << 11,
		SecondRight = 1 << 12,
		SecondLeft = 1 << 13
	}

	[Native]
	public enum NMALaneInformationRecommendationState : nuint
	{
		NotRecommended,
		Recommended,
		HighlyRecommended,
		NotAvailable
	}

	[Native]
	public enum NMALaneInformationMarkingType : nuint
	{
		NotAvailable,
		LongDashed,
		DoubleSolidLine,
		SingleSolidLine,
		DoubleInnerSingleOuterDashed,
		DoubleInnerDashedOuterSingle,
		ShortDashed,
		SharedArea,
		DashedBlocks,
		PhysicalDivider,
		DoubleDashed,
		NoDivider,
		CrossingAlert
	}

	[Native]
	public enum NMALaneInformationCrossingRestriction : nuint
	{
		NoRestriction,
		Left,
		Right,
		Both
	}

	[Native]
	public enum NMANavigationRoadType : nuint
	{
		NonHighway,
		Highway
	}

	[Native]
	public enum NMANavigationVoicePromptType : nuint
	{
		Announcement,
		Reminder1,
		Reminder2,
		Command
	}

	[Native]
	public enum NMAVoiceGender : nuint
	{
		Female,
		Male,
		Both,
		Unknown
	}

	[Native]
	public enum NMAVoiceCatalogError : nuint
	{
		None,
		Unknown,
		NotFound,
		InvalidOperation,
		InvalidParameters,
		FileOpen,
		DownloadNotReady,
		VoiceLoadingFailed,
		MissingMandatoryFields,
		OutOfMemory,
		Cancelled
	}

	[Native]
	public enum NMAAutoSuggestType : nuint
	{
		Unknown = 0,
		Place,
		Search,
		Query
	}

	[Native]
	public enum NMACategoryFilterType : nuint
	{
		None = 0,
		Accommodation,
		AdministrativeAreasBuildings,
		EatDrink,
		GoingOut,
		LeisureOutdoor,
		NaturalGeographical,
		Shopping,
		SightsMuseums,
		Transport,
		PetrolStation,
		AtmBankExchange,
		ToiletRestArea,
		HospitalHealthCareFacility
	}

	[Native]
	public enum NMAReverseGeocodeMode : nuint
	{
		RetrieveAddresses = 0,
		RetrieveAreas,
		RetrieveLandmarks,
		RetrieveAll,
		TrackPosition
	}

	[Native]
	public enum NMAMediaType : nuint
	{
		Unknown = 0,
		Editorial,
		Image,
		Review,
		Rating
	}

	[Native]
	public enum NMAPlacesAutoSuggestionResultType : nuint
	{
		Address = 1,
		Place = 1 << 1,
		Category = 1 << 2,
		Chain = 1 << 3,
		Query = 1 << 4
	}

	[Native]
	public enum NMAPrefetchStatus : nuint
	{
		InProgress,
		Success,
		Failure,
		Cancelled
	}

	[Native]
	public enum NMAPrefetchRequestError : nuint
	{
		None = 0,
		Unknown,
		Busy,
		InvalidParameters,
		OperationNotAllowed,
		RouteAreaTooBig
	}

	[Native]
	public enum NMACoreRouterConnectivity : nuint
	{
		Default,
		Offline,
		Online
	}

	[Native]
	public enum NMAUrbanMobilityTransportType : nuint
	{
		HighspeedTrain = 0,
		IntercityTrain = 1,
		InterregionalTrain = 2,
		RegionalTrain = 3,
		CityTrain = 4,
		Bus = 5,
		Ferry = 6,
		Subway = 7,
		Tram = 8,
		PrivateBus = 9,
		Inclined = 10,
		Aerial = 11,
		RapidBus = 12,
		Monorail = 13,
		Flight = 14,
		Unknown = 15,
		Bike = 17,
		BikeShare = 18,
		Walk = 20,
		Car = 21,
		CarShare = 22,
		Taxi = 23,
		Undefined = 24
	}

	[Native]
	public enum NMAUrbanMobilityError : nuint
	{
		None = 0,
		Offline = 1,
		BadResponseCode = 2,
		MalformedResponse = 3,
		Unknown = 4,
		Unauthorized = 5,
		NoCoverage = 6,
		NoResponse = 7,
		NotFound = 8,
		InvalidParameters = 9,
		Unexpected = 10,
		UnavailableAPI = 11,
		InvalidPeriod = 12,
		RoutingNotPossible = 13,
		StartDestinationTooClose = 14,
		NoStationNearby = 15,
		InvalidOperation = 16,
		OutOfMemory = 17,
		RoutingCancelled = 18,
		ViolatesOptions = 19,
		InsufficientMapData = 20,
		ServiceUnavailable = 21,
		NetworkCommunication = 22,
		OperationNotAllowed = 23
	}

	[Native]
	public enum NMAUrbanMobilityFeatureAvailability : nuint
	{
		AvailabilityUnknown = 0,
		Available = 1,
		NotAvailable = 2
	}

	[Native]
	public enum NMARouteElementType : nint
	{
		Transit = 0,
		Road,
		Invalid
	}

	[Native]
	public enum NMATravelDirection : nuint
	{
		Forward = 0,
		Backward = 1
	}

	[Native]
	public enum NMARoutingViolatedOption : nint
	{
		OptionNone = 0,
		OptionBlockedRoad = 1 << 12,
		OptionTurnRestriction = 1 << 13,
		OptionStartDirection = 1 << 14,
		PermanentTruckRestriction = 1 << 15,
		OptionZoneRestriction = 1 << 16
	}

	[Native]
	public enum NMATransitRoutingOption : nuint
	{
		PublicBus = 1 << 0,
		TouristicBus = 1 << 1,
		IntercityBus = 1 << 2,
		ExpressBus = 1 << 3,
		MetroRail = 1 << 4,
		LightRail = 1 << 5,
		RegionalRail = 1 << 6,
		RegionalTrain = 1 << 7,
		IntercityTrain = 1 << 8,
		HighSpeedTrain = 1 << 9,
		MonoRail = 1 << 10,
		Aerial = 1 << 11,
		Inclined = 1 << 12,
		Water = 1 << 13
	}

	[Native]
	public enum NMATunnelCategory : nuint
	{
		None,
		B,
		C,
		D,
		E
	}

	[Native]
	public enum NMAHazardousGoodsType : nuint
	{
		Explosive = 1 << 0,
		Gas = 1 << 1,
		Flammable = 1 << 2,
		Combustible = 1 << 3,
		Organic = 1 << 4,
		Poison = 1 << 5,
		RadioActive = 1 << 6,
		Corrosive = 1 << 7,
		PoisonousInhalation = 1 << 8,
		HarmfulToWater = 1 << 9,
		Other = 1 << 10
	}

	[Native]
	public enum NMATruckType : nuint
	{
		None,
		Truck,
		TractorTruck
	}

	[Native]
	public enum NMATruckRestrictionsMode : nuint
	{
		NoViolations,
		PenalizeViolations
	}

	[Native]
	public enum NMAUrbanMobilityRoutingTypeOption : nuint
	{
		All = 0,
		TimeTable = 1,
		SimpleRouting = 2,
		RealTimeRouting = 3
	}

	[Native]
	public enum NMAUrbanMobilityUnits : nuint
	{
		Metric,
		Imperial
	}

	[Native]
	public enum NMAUrbanMobilityOption : nuint
	{
		HighSpeedTrains = 1 << 0,
		IntercityEurocityTrains = 1 << 1,
		InterregionalFastTrains = 1 << 2,
		RegionalTrains = 1 << 3,
		CityTrains = 1 << 4,
		Busses = 1 << 5,
		BoatFerries = 1 << 6,
		MetroSubway = 1 << 7,
		Tram = 1 << 8,
		OrderedServiceTaxi = 1 << 9,
		InclinedFunicular = 1 << 10,
		AerialCableCar = 1 << 11,
		RapidBus = 1 << 12,
		Monorail = 1 << 13,
		Airplane = 1 << 14,
		Undefined = 1 << 15
	}

	[Native]
	public enum NMARoutingZoneType : nuint
	{
		Vignette = 0,
		CongestionPricing = 1,
		AdministrativeClass = 2,
		Environmental = 3
	}

	[Native]
	public enum NMATransitLineStyle : nuint
	{
		Solid,
		Dotted,
		Dashed,
		Undefined
	}

	[Native]
	public enum NMATruckRestrictionType : nuint
	{
		TruckRestriction = 0,
		WeightRestriction = 1,
		HeightRestriction = 2,
		LengthRestriction = 3,
		WidthRestriction = 4,
		WeightPerAxelRestriction = 5,
		KpraLengthRestriction = 6,
		PreferredRoute = 7,
		HazMatPermitRequired = 8,
		SpeedLimit = 9,
		Toll = 10,
		Unknown = 11
	}

	[Native]
	public enum NMATruckRestrictionHazMat : nuint
	{
		None = 0,
		Explosives = 1,
		Gas = 2,
		Flammable = 3,
		FlammableSolidCombustible = 4,
		Organic = 5,
		Poison = 6,
		Radioactive = 7,
		Corrosive = 8,
		Other = 9,
		Any = 10,
		Pih = 11,
		HarmfulForWater = 12,
		ExplosiveFlammable = 13,
		TunnelCategoryB = 14,
		TunnelCategoryC = 15,
		TunnelCategoryD = 16,
		TunnelCategoryE = 17,
		Unknown = 18
	}

	[Native]
	public enum NMATruckRestrictionWeatherType : nuint
	{
		None = 0,
		Rain = 1,
		Snow = 2,
		Fog = 3,
		Unknown = 4
	}

	[Native]
	public enum NMATruckRestrictionTrailerType : nuint
	{
		None = 0,
		Value1 = 1,
		Value2 = 2,
		Value3 = 3,
		Value4 = 4,
		Unknown = 5
	}

	[Native]
	public enum NMAWaypointType : nuint
	{
		StopWaypoint,
		ViaWaypoint
	}

	[Native]
	public enum NMAWaypointDirection : nuint
	{
		Any,
		Positive,
		Negative
	}

	[Native]
	public enum NMARoadSide : nuint
	{
		Undefined,
		UnknownLeft,
		UnknownRight,
		Left,
		Right
	}

	[Native]
	public enum NMATollCostRequestError : nuint
	{
		NoPermission = 1,
		AlreadyRunning = 2,
		Cancelled = 3,
		InvalidParameters = 4,
		ConnectionError = 5,
		ServerError = 6,
		UnknownError = 7
	}

	[Native]
	public enum NMATollCostVehicleType : nuint
	{
		Motorcycle = 1,
		Auto = 2,
		Truck = 3,
		MotorHome = 4,
		Minibus = 5,
		Bus = 6,
		MotorcycleSidecar = 7,
		Tricyle = 8,
		DeliveryTruck = 9,
		Snowmobile = 10,
		PickUp = 11,
		Tractor = 12,
		Taxi = 13,
		HcmEme = 14
	}

	[Native]
	public enum NMATollCostTrailerType : nuint
	{
		None = 0,
		Caravan = 1,
		Trailer = 2
	}

	[Native]
	public enum NMATollCostTrailersCount : nuint
	{
		outTrailer = 0,
		OneTrailer = 1,
		TwoTrailers = 2,
		ThreeOrMoreTrailers = 3
	}

	[Native]
	public enum NMATollCostHybridType : nuint
	{
		None = 0,
		PartlyRunningOnElectricity = 1
	}

	[Native]
	public enum NMATollCostEmissionType : nuint
	{
		None = 0,
		EuroI = 1,
		EuroII = 2,
		EuroIII = 3,
		EuroIV = 4,
		EuroV = 5,
		EuroVI = 6,
		EuroEEV = 7,
		ElectricVehicles = 8
	}

	[Native]
	public enum NMATollCostShippedHazardousGoods : nuint
	{
		None = 0,
		Explosives = 1,
		AnyHazardousMaterial = 2
	}

	[Native]
	public enum NMAUrbanMobilitySearchOption : nuint
	{
		Unset = 0,
		Yes = 1,
		No = 2
	}

	[Native]
	public enum NMACoverageUpdateType : nuint
	{
		New = 0,
		Updated,
		All
	}

	[Native]
	public enum NMAUrbanMobilityFareType : nuint
	{
		NotAvailable = 0,
		Hourly = 1,
		Daily = 2,
		Range = 3,
		Unrecognized = 4
	}

	[Native]
	public enum NMAUrbanMobilityLinkType : nuint
	{
		Agency = 0,
		AgencyLogo = 1,
		Tariff = 2,
		Website = 3,
		Booking = 4,
		Alert = 5,
		Unknown = 6
	}

	[Native]
	public enum NMAUrbanMobilityManeuverDirection : nuint
	{
		Undefined = 0,
		Forward,
		Right,
		Left,
		BearRight,
		LightRight,
		HardRight,
		UturnRight,
		UturnLeft,
		HardLeft,
		LightLeft,
		BearLeft
	}

	[Native]
	public enum NMAUrbanMobilityCoverageType : nuint
	{
		RealTime = 0,
		SimpleRouting = 1,
		TimeTable = 2,
		Unknown = 3
	}

	[Native]
	public enum NMAUrbanMobilityOperatorType : nuint
	{
		Unknown = 0,
		Estimated = 1,
		TimeTable = 2,
		RealTime = 3
	}

	[Native]
	public enum NMAUrbanMobilityRealTimeInfoStatus : nuint
	{
		Ok,
		Redirected,
		Replaced,
		Cancelled,
		Additional
	}

	[Native]
	public enum NMAUrbanMobilityViolatedOption : nuint
	{
		MaxWalkingDistance = 1 << 0,
		WalkSpeed = 1 << 1,
		MaxChangesCount = 1 << 2,
		RestrictTransportTypes = 1 << 3,
		EstimatedRouting = 1 << 4
	}

	[Native]
	public enum NMAUrbanMobilityRouterConnectivity : nuint
	{
		Default,
		Offline,
		Online
	}

	[Native]
	public enum NMASubsequentRouteType : nuint
	{
		Forward = 0,
		Backward
	}

	[Native]
	public enum NMAUrbanMobilitySearchNameMatchingMethod : nuint
	{
		Unspecified = 0,
		Strict = 1,
		Fuzzy = 2
	}

	[Native]
	public enum NMAVenue3dBaseLocationType : nuint
	{
		Space,
		Outdoor,
		Level,
		Other
	}

	[Native]
	public enum NMAVenue3dCombinedNavigationState : nuint
	{
		Idle = 0,
		Running,
		Simulating,
		Paused
	}

	[Native]
	public enum NMAVenue3dCombinedNavigationType : nuint
	{
		None = 0,
		Indoor,
		Link,
		Outdoor
	}

	[Native]
	public enum NMAVenue3dRoutingError : nuint
	{
		NoError,
		Arguments,
		Internal,
		CoreMap,
		Unknown
	}

	[Native]
	public enum NMAVenue3dRouteSectionType : nuint
	{
		Venue,
		Outdoor,
		Link
	}

	[Native]
	public enum NMAVenue3dDeselectEvent : nuint
	{
		MapMoved,
		MapZoomedOut,
		MapTappedOutside,
		LayerDisabled,
		SelectedOther,
		Manual
	}

	[Native]
	public enum NMAVenue3dNavigationState : nuint
	{
		Idle = 0,
		Running,
		Paused
	}

	[Native]
	public enum NMAVenue3dTrackingTilt : nuint
	{
		NMAVenue3dTrackingTilt2D,
		NMAVenue3dTrackingTilt3D,
		Custom
	}

	[Native]
	public enum NMAVenue3dTrackingMode : nuint
	{
		Follow,
		NorthUp,
		FreeRotation
	}

	[Native]
	public enum NMAVenue3dRouteActionType : nuint
	{
		None,
		Enter,
		Exit
	}

	[Native]
	public enum NMAVenue3dRouteLevelChangeType : nuint
	{
		None,
		Up,
		Down
	}

	[Native]
	public enum NMAVenue3dRouteConnectorType : nuint
	{
		Elevator,
		Escalator,
		Stairs,
		Skywalk,
		Shuttle,
		MovingSidewalk,
		Ramp,
		OtherCategory,
		NotConnector
	}

	[Native]
	public enum NMAVenue3dServiceVenueLoadStatus : nuint
	{
		OnlineSuccess,
		OfflineSuccess,
		Failed
	}

	[Native]
	public enum NMAVenue3dServiceInitializationStatus : nuint
	{
		OnlineSuccess,
		OfflineSuccess,
		AuthenticationFailed,
		StyleInitializationFailed,
		IconInitializationFailed,
		IndexInitializationFailed,
		OnlineFailed,
		NotStarted,
		InProgress,
		Locked
	}

	[Native]
	public enum NMAVenue3dSimulationState : nuint
	{
		Idle = 0,
		Running,
		Paused
	}

	[Native]
	public enum NMAVenue3dSpaceType : nuint
	{
		General,
		Facility
	}
}
