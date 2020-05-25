using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Util;
using Android.Widget;
using AndroidX.AppCompat.App;
using Com.Here.Android.Mpa.Common;
using Com.Here.Android.Mpa.Mapping;
using Java.IO;

namespace Xamarin.Android.HereMapsTestApp
{
    [Activity(Label = "@string/app_name", Theme = "@style/AppTheme", MainLauncher = true)]
    public class MainActivity : AppCompatActivity
    {
        // map embedded in the map fragment
        public Map map = null;
        // map fragment embedded in this activity
        public AndroidXMapFragment mapFragment = null;

        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            Essentials.Platform.Init(this, savedInstanceState);

            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.activity_main);

            // Search for the map fragment to finish setup by calling Init().
            mapFragment = (AndroidXMapFragment)SupportFragmentManager.FindFragmentById(Resource.Id.mapfragment);

            // Set up disk cache path for the map service for this application
            bool success = MapSettings.SetIsolatedDiskCacheRootPath(
                    ApplicationContext.GetExternalFilesDir(null) + File.Separator + ".here-maps");

            if (!success)
            {
                Toast.MakeText(ApplicationContext, "Unable to set isolated disk cache path.", ToastLength.Long);
            }
            else
            {
                mapFragment.Init(new OnEngineInitListener(this));
            }
        }

        public override void OnRequestPermissionsResult(int requestCode, string[] permissions, [GeneratedEnum] global::Android.Content.PM.Permission[] grantResults)
        {
            Essentials.Platform.OnRequestPermissionsResult(requestCode, permissions, grantResults);

            base.OnRequestPermissionsResult(requestCode, permissions, grantResults);
        }

        private class OnEngineInitListener : Java.Lang.Object, IOnEngineInitListener
        {
            private MainActivity parent;

            public OnEngineInitListener(MainActivity parent)
            {
                this.parent = parent;
            }

            public void OnEngineInitializationCompleted(OnEngineInitListenerError error)
            {
                if (error == OnEngineInitListenerError.None)
                {
                    // retrieve a reference of the map from the map fragment
                    parent.map = parent.mapFragment.Map;
                    // Set the map center to the Vancouver region (no animation)
                    parent.map.SetCenter(new GeoCoordinate(49.196261, -123.004773, 0.0),
                            Map.Animation.None);
                    // Set the zoom level to the average between min and max
                    parent.map.SetZoomLevel((parent.map.MaxZoomLevel + parent.map.MinZoomLevel) / 2);
                }
                else
                {
                    // print error
                    Log.Error("MainActivity", "ERROR: Cannot initialize Map Fragment: " + error.Details);                    

                }
            }
        }
    }
}