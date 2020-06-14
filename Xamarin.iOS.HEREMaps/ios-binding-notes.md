# Important information:
I do not bind all of the header files of the HereMaps iOS Framework which are listed in NMAKit.h. Instead I concentrated on the ones I need at the moment. 
So NMAKit_mod.h lists all the header files with should be bind by Sharpie.

# Requirements:
- You need Sharpie https://docs.microsoft.com/en-us/xamarin/cross-platform/macios/binding/objective-sharpie/tools?context=xamarin/ios
- If it is already installed you may want to check for an updated version with 'sharpie update'

# Steps
1. Generate ApiDefinition.cs and StructsAndEnums.cs:
- Open a terminal
- cd `HERESDK-Premium/framework/NMAKit.framework/Headers/`
- check available iOS sdks with `sharpie xcode -sdks`. If needed SDK is missing download xCode version from https://developer.apple.com/download/more/ and use 'sudo xcode-select -s /Applications/Xcode11_1.app' to use this xCode version.
- Because HEREMaps iOS SDK v.3.15 was build for 13.1 (see Info.plist inside the NMAKit.framework (DTPlatformVersion)) we use the option "-sdk iphoneos13.1" to avoid problems.
- Use now `sharpie bind -output . -sdk iphoneos13.1 -namespace Xamarin.HEREMaps.iOS -scope . NMAKit_mod.h` to trigger the binding process.
2. Adjust ApiDefinition.cs and Structs.cs:
- Copy content from generated file "ApiDefinition.cs" into "ApiDefinition.cs" of the iOS binding project
- Copy content from generated file "StructsAndEnums.cs" into "Structs.cs" of the iOA binding project
- In Structs.cs replace all „nuint“ with „ulong“ (every native enum should inherit from “long” or “ulong.”)
- In Structs.cs replace all „nint“ with „long“
- In ApiDefinition.cs replace all „[Verify(ConstantsInterfaceAssociation)] „with „//[Verify(ConstantsInterfaceAssociation)]“
- Verify all „[Verify(MethodToProperty)]“ properties if correct mapped or (the lazy approach ;) ) just replace all „[Verify(MethodToProperty)] „with „//[Verify(MethodToProperty)]“. (I you get errors at runtime, you can still start checking this bindings)
- In interface NMAMapTileLayerDataSource, rename MapTileLayer methods to different names e.g. MapTileLayer to MapTileLayerHasTileAt
- Remove duplicated method „IntPtr Constructor(NMAGeoCoordinates topRight, NMAGeoCoordinates bottomLeft);“
- Rename methods in interface NMAVenue3dMapLayerDelegate
- Change „interface NMAMapOverlay : INMAMapViewDelegate“ into „interface NMAMapOverlay : NMAMapViewDelegate“
- if you get an error like "Error CS0708: 'NMARoutingMode_NMATruckRoutingMode.TruckRestrictionsMode': cannot declare instance members in a static class (CS0708)" you have to make the generated property 'static' via [Static] attribute because C# Extensions are static classes which can not have non-static properties or methods.

# Official documentation of Binding Objective-C:
https://docs.microsoft.com/en-us/xamarin/cross-platform/macios/binding/?context=xamarin/ios
https://docs.microsoft.com/en-us/xamarin/cross-platform/macios/binding/binding-types-reference?context=xamarin/ios
https://docs.microsoft.com/en-us/xamarin/ios/troubleshooting/mtouch-errors#MT5214
https://github.com/xamarin/xamarin-macios/tree/master/docs/website

# Helpful links:
https://insanelab.com/blog/mobile-development/advanced-xamarin-bindings-case-study-deep-dive-into-ios-part-ii/