# Important information:
I do not bind all header files of the HereMaps iOS Framework with are listed in NMAKit.h. Instead I concentrated on the ones I need at the moment. 
So NMAKit_mod.h list all the header files with should be bind by Sharpie.

# Requirements:
- You need Sharpie https://docs.microsoft.com/en-us/xamarin/cross-platform/macios/binding/objective-sharpie/tools?context=xamarin/ios
- If it is already installed you may want to check for an updated version with 'sharpie update'

# Steps
1. Generate ApiDefinition.cs and StructsAndEnums.cs:
- cd `HERESDK-Premium/framework/NMAKit.framework/Headers/`
- check available iOS sdks with `sharpie xcode -sdks`. If needed SDK is missing download xCode version from https://developer.apple.com/download/more/ and use 'sudo xcode-select -s /Applications/Xcode3_11.app' to use this xCode version.
- `sharpie bind -o . -n Xamarin.HEREMaps.iOS —sdk=iphoneos13.1 -scope . NMAKit_mod.h`

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

# Official documentation of Binding Objective-C:
https://docs.microsoft.com/en-us/xamarin/cross-platform/macios/binding/?context=xamarin/ios

# Helpful links:
https://insanelab.com/blog/mobile-development/advanced-xamarin-bindings-case-study-deep-dive-into-ios-part-ii/