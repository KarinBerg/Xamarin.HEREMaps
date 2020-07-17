using Foundation;
using UIKit;
using Xamarin.HEREMaps.iOS;

namespace HereMapsTestApp
{
    // The UIApplicationDelegate for the application. This class is responsible for launching the
    // User Interface of the application, as well as listening (and optionally responding) to application events from iOS.
    [Register("AppDelegate")]
    public class AppDelegate : UIResponder, IUIApplicationDelegate
    {
        private static readonly string appId = "YOUR_APP_ID";
        private static readonly string appCode = "YOUR_APP_CODE";
        private static readonly string appLicenseKey = "YOUR_LICENSE_KEY";

        [Export("window")]
        public UIWindow Window { get; set; }

        public static UIStoryboard Storyboard = UIStoryboard.FromName("Main", null);
        public static UIViewController initialViewController;

        [Export("application:didFinishLaunchingWithOptions:")]
        public bool FinishedLaunching(UIApplication application, NSDictionary launchOptions)
        {
            // Override point for customization after application launch.
            // If not required for your application you can safely delete this method
            NMAApplicationContext.SetAppId(appId, appCode, appLicenseKey);

            Window = new UIWindow(UIScreen.MainScreen.Bounds);

            initialViewController = Storyboard.InstantiateInitialViewController() as UIViewController;

            Window.RootViewController = initialViewController;
            Window.AddSubview(initialViewController.View);
            Window.MakeKeyAndVisible();
            return true;
        }

        // UISceneSession Lifecycle

        [Export("application:configurationForConnectingSceneSession:options:")]
        public UISceneConfiguration GetConfiguration(UIApplication application, UISceneSession connectingSceneSession, UISceneConnectionOptions options)
        {
            // Called when a new scene session is being created.
            // Use this method to select a configuration to create the new scene with.
            return UISceneConfiguration.Create("Default Configuration", connectingSceneSession.Role);
        }

        [Export("application:didDiscardSceneSessions:")]
        public void DidDiscardSceneSessions(UIApplication application, NSSet<UISceneSession> sceneSessions)
        {
            // Called when the user discards a scene session.
            // If any sessions were discarded while the application was not running, this will be called shortly after `FinishedLaunching`.
            // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
        }
    }
}

