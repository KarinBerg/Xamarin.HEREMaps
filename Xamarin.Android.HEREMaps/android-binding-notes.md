# Steps
if you want to bind a newer version of the Android Here SDK, do the following:<br>
- Remove the old aar file.
- Add the new aar file to the "Jars" folder inside the Android Binding project.<br>
- Check if "Build action" is "LibraryProjectZip"
- Check if the gson.jar ist still needed by the HEREMaps aar and if yes which version. The update the jar or remove it.
- Check Target Framework: It is not possible to "downgrade" the Android API level; So ensure that the Xamarin.Android binding project is targeting the same API level (or higher) as the Android library.
- Build the binding project


# Official documentation of Binding an AAR:
https://docs.microsoft.com/en-gb/xamarin/android/platform/binding-java-library/binding-an-aar

https://docs.microsoft.com/en-gb/xamarin/android/platform/binding-java-library/troubleshooting-bindings

# Helpful links:
https://insanelab.com/blog/mobile-development/advanced-xamarin-bindings-android-case-study/

https://gist.github.com/JonDouglas/dda6d8ace7d071b0e8cb

https://xamarinhelp.com/creating-xamarin-android-binding-library/