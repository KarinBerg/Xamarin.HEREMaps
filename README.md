# Xamarin.HEREMaps
Xamarin Binding library to make HEREMaps Premium Edition SDKs (v.3.15) available for Xamarin.iOS and Xamarin.Android Apps.

**Requirements:**<br>
You need to register at https://developer.here.com and get a license for the HEREMaps Premium Edition SDKs.

**Compatibility:**<br>
iOS:
- HERE iOS SDK supports iOS 12 or above. iOS 12 is recommended for optimal operation. <br>
- The Nuget package only contains the ARM64 cpu architecture because otherwise the package exceeds the size limitation of nuget.org
- At the moment not the whole functionality of the SDK is binded. So only the following header files are binded and can be used inside a Xamarin.iOS app: [ios-binded-headers]
- Not supported yet:
    - NMAMapView software renderer
    - NMAARMeshObject
    - NMAFloatMesh
    - NMAGeoMesh
    - NMAMapGeoModel
    - NMAMapLocalModel
    - no class from the "Custom Location Extension 2"
    - no class from the "Fleet Telematics Custom Route"
    - NMAMapFTCRRoute

Android:
- Minimum supported API Level of the used HEREMaps SDK is 17 which corresponds Android 4.2.x "Jelly Bean". (android:minSdkVersion)
Target SDK version is 29 which corresponds Android 10.0 "Q" (android:targetSdkVersion)

<p align="center">
<img src="docs/icons/HERE_logo.png" width="300">
</p>

| Binding project                                     | Sample project                                            | NuGet                                     |
|---------------------------------------------|---------------------------------------------------|-------------------------------------------|
| [Xamarin.Android.HereMaps][binding-android] | [Xamarin.Android.HereMapsTestApp][android-sample] | [![NuGet](https://img.shields.io/nuget/v/Xamarin.Android.HereMaps.svg?label=NuGet)](https://www.nuget.org/packages/Xamarin.Android.HereMaps/) |
| [Xamarin.iOS.HereMaps][binding-ios]         | [Xamarin.iOS.HereMapsTestApp][ios-sample]         | [![NuGet](https://img.shields.io/nuget/v/Xamarin.iOS.HereMaps.svg?label=NuGet)](https://www.nuget.org/packages/Xamarin.iOS.HereMaps/)         |


[official-docs-sdk-android]: https://developer.here.com/documentation/android-premium/3.15/dev_guide/topics/user-guide.html
[official-docs-sdk-ios]: https://developer.here.com/documentation/ios-premium/3.15/dev_guide/topics/user-guide.html

[binding-android]: Xamarin.Android.HEREMaps/
[binding-ios]: Xamarin.iOS.HEREMaps/

[android-sample]: Xamarin.Android.HereMapsTestApp/
[ios-sample]: Xamarin.iOS.HereMapsTestApp/

[ios-binded-headers]: NativeLibraries/iOS/HERE_iOS_SDK_Premium_v3.15.2_92/framework/NMAKit.framework/Headers/NMAKit_mod.h

### License
[MIT Licence](LICENSE) 

### Binding documentation
iOS Binding: [notes](Xamarin.iOS.HEREMaps/ios-binding-notes.md)<br>
Android: [notes](Xamarin.Android.HEREMaps/android-binding-notes.md)<br>

### Git hints
Because the iOS and Android native HereMaps libraries (NMAKit and HERE-sdk.zip) are larger than 100MB, I have to use Git Large File Storage (Git LFS) to add them to the github repository.
Type `git lfs ls-files`to see which files are managed by Git LFS.
Type `git lfs track`to see the tracked patterns
Type `git untrack "*.gif"` to configure Git LFS to stop tracking GIF files
Type `git track "*gif"` to configure Git LFS to start tracking GIF files
See https://git-lfs.github.com for more info about Git Large File Storage