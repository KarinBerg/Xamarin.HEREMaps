# HERE iOS SDK, Premium Edition

This document contains information about the `HEREMaps` pod for CocoaPods. The `HEREMaps` pod contains the Premium Edition of the HERE iOS SDK.

HERE iOS SDK supports both Objective-C and Swift. With the [Premium Edition](https://developer.here.com/develop/mobile-sdks), developers can build immersive, geographically-aware iOS applications by leveraging a powerful and flexible mapping platform. Through this SDK, developers can add rich location features such as routing, interactive maps, and global place search to their applications. The powerful client-side HERE iOS SDK also includes a sophisticated engine for rendering map data, calculating routes, and providing turn-by-turn voice guidance along a route. In addition to dynamically downloading map data, the SDK also supports offline maps using previously cached map data or downloaded map packages.

There are two iOS SDKs available from HERE for iOS developers. You can find the Starter Edition of the HERE iOS SDK under the pod `HEREMapsStarter`.


# Trying the Sample App

*   You can try our basic HellpMap sample app using the following command:

    ```
    $ pod try HEREMaps
    ```

    When Xcode launches, follow the instructions in the readme.txt file found within the Sample app project.

# Getting Started

*   *Getting Help*: If you encounter problems with the iOS SDK, post a question to [Stack Overflow](https://stackoverflow.com/questions/tagged/here-api)

*   *Documentation*: Information to help with getting started with the SDK can be found on [developer.here.com](https://developer.here.com/mobile-sdks/documentation/ios-premium/topics/overview.html).

*   *Example code*: Example code can be found on [GitHub](https://github.com/heremaps/here-ios-sdk-examples).

*   *Registering you app*: Before you can use the HERE iOS SDK, you must register the app at [developer.here.com](developer.here.com) and use the returned credentials in your project. See the [Developer Guide](https://developer.here.com/mobile-sdks/documentation/ios-premium/topics/credentials.html) for details.

*	*Add the HERE iOS SDK to your Podfile*: To begin using the SDK in your project, you must add the following to your Podfile:

    ```
    platform :ios, '12.0'
    target 'YourApp' do
      pod 'HEREMaps'
    end
    ```

    Then install the pod by running the command:

    ```
    $ pod install
    ```


# License and Terms of Service

The use of the HERE iOS SDK shall be subject to the HERE Terms and Conditions and other legal requirement, by using the HERE iOS SDK you accept the HERE Terms and Conditions and other legal requirements. Therefore all developers must review the [legal requirements](https://developer.here.com/mobile-sdks/documentation/ios-premium/topics/legal-requirements.html) and [terms and conditions](https://developer.here.com/terms-and-conditions) associated with usage of the HERE iOS SDK prior to the use of the HERE iOS SDK.
