/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

### HelloMap ###

===========================================================================
DESCRIPTION:

Simple ObjC sample app to display an NMAMapView.

===========================================================================
INSTRUCTIONS (CocoaPods)

1) Register your app (or this sample app) on developer.here.com to
   HERE SDK credentials:
    - Each app requires a unique set of credentials.
    - You need your own bundle identifier even if you are just trying out
      this sample app.
    - The registered bundle identifier must match the bundle identifier you
      will use in your app.

2) Run "pod install" or "pod update" in the root "HelloMap" folder to install
   the HERE SDK. Skip this step if using "pod try".

3) In the "General" settings of the App target:
    - Select an eligible provisioning profile or enable "Automatically
      manage signing".
    - Replace "com.yourcompany.HelloMap" with your own bundle identifier.

4) In HelloMapAppDelegate.m:
    - Enter the app id, app code and license key acquired in step #1 above.

===========================================================================
INSTRUCTIONS (Without CocoaPods)

1) Register your app (or this sample app) on developer.here.com to acquire
   HERE SDK credentials:
    - Each app requires a unique set of credentials.
    - You need your own bundle identifier even if you are just trying out
      this sample app.
    - The registered bundle identifier must match the bundle identifier you
      will use in your app.

2) In the "General" settings of the App target:
    - Select an eligible provisioning profile or enable "Automatically
      manage signing".
    - Add NMAKit.framework from HEREMaps/framework/ to the "Embedded Content"
      section otherwise you will get an error at runtime.
    - Replace "com.yourcompany.HelloMap" with your own bundle identifier.

3) In the "Builds Settings" of the App target:
    - Ensure "Frameworks Search Paths" includes the location of
      NMAKit.framework. In this example app it is already set to
      "$(PROJECT_DIR)/../../framework".

4) In HelloMapAppDelegate.m:
    - Enter the app id, app code and license key acquired in step #1 above.

===========================================================================
BUILD REQUIREMENTS:

* Xcode 11 & iOS 13 SDK or above
* HERE Premium SDK Version 3.15 or above

===========================================================================
TARGET PLATFORM:

* iOS 12.0 and above
