/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "HelloMapAppDelegate.h"

@import NMAKit;

@implementation HelloMapAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    #error Please enter an app id, app code and license key!
    // An app id, app code and license key may be obtained from https://developer.here.com/develop/mobile-sdks
    // IMPORTANT: A license key is linked to a specific app bundle identifier. The bundle identifier
    // for this app is "com.yourcompany.HelloMap". Change the bundle identifier of this app to your
    // identifier if using your own license key.

    #define kHelloMapAppID @""
    #define kHelloMapAppCode @""
    #define kHelloMapLicenseKey @""

    NMAApplicationContextError error = [NMAApplicationContext setAppId:kHelloMapAppID
                                                               appCode:kHelloMapAppCode
                                                            licenseKey:kHelloMapLicenseKey];
    assert(error == NMAApplicationContextErrorNone);

    return YES;
}

@end
