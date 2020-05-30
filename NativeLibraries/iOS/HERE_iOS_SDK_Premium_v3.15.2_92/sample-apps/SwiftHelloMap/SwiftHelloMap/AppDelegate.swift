/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

import UIKit
import NMAKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool
    {
        #error ("Please enter an app id, app code and license key!")
        // An app id, app code and license key may be obtained from https://developer.here.com/develop/mobile-sdks
        // IMPORTANT: A license key is linked to a specific app bundle identifier. The bundle identifier
        // for this app is "com.yourcompany.SwiftHelloMap". Change the bundle identifier of this app to your
        // identifier if using your own license key.

        let kHelloMapAppID = ""
        let kHelloMapAppCode = ""
        let kHelloMapLicenseKey = ""

        let error =  NMAApplicationContext.setAppId(kHelloMapAppID,
                                                    appCode: kHelloMapAppCode,
                                                 licenseKey: kHelloMapLicenseKey)
        assert(error == NMAApplicationContextError.none)

        return true
    }
}
