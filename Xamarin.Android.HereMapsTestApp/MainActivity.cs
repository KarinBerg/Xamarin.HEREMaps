using Android;
using Android.App;
using Android.Content;
using Android.Content.PM;
using Android.OS;
using Android.Runtime;
using Android.Widget;
using AndroidX.AppCompat.App;
using AndroidX.Core.App;
using AndroidX.Core.Content;
using Com.Here.Android.Mpa.Common;
using Google.Android.Material.Snackbar;
using Java.IO;

namespace Xamarin.Android.HereMapsTestApp
{
    [Activity(Label = "@string/app_name", Theme = "@style/AppTheme", MainLauncher = true)]
    public class MainActivity : AppCompatActivity
    {
        private static int REQUEST_CODE_ASK_PERMISSIONS = 1;
        private static string[] RUNTIME_PERMISSIONS = {
            Manifest.Permission.AccessFineLocation,
            Manifest.Permission.WriteExternalStorage,
            Manifest.Permission.Internet,
            Manifest.Permission.AccessWifiState,
            Manifest.Permission.AccessNetworkState
        };

        private MapFragmentView m_mapFragmentView;

        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            Essentials.Platform.Init(this, savedInstanceState);

            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.activity_main);

            if (HasPermissions(this, RUNTIME_PERMISSIONS))
            {
                SetupMapFragmentView();
            }
            else
            {
                ActivityCompat.RequestPermissions(this, RUNTIME_PERMISSIONS, REQUEST_CODE_ASK_PERMISSIONS);
            }
        }

        private static bool HasPermissions(Context context, string[] permissions)
        {
            if (Build.VERSION.SdkInt >= BuildVersionCodes.M && permissions != null)
            {
                foreach (string permission in permissions)
                {
                    if (ContextCompat.CheckSelfPermission(context, Manifest.Permission.Camera) != (int)Permission.Granted)
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        public override void OnRequestPermissionsResult(int requestCode, string[] permissions, [GeneratedEnum] global::Android.Content.PM.Permission[] grantResults)
        {
            if (requestCode == REQUEST_CODE_ASK_PERMISSIONS)
            {
                for (int index = 0; index < permissions.Length; index++)
                {
                    if (grantResults[index] != Permission.Granted)
                    {

                        /*
                         * If the user turned down the permission request in the past and chose the
                         * Don't ask again option in the permission request system dialog.
                         */
                        if (!ActivityCompat
                                .ShouldShowRequestPermissionRationale(this, permissions[index]))
                        {
                            Snackbar.Make(this.CurrentFocus, "Required permission " + permissions[index]
                                                   + " not granted. "
                                                   + "Please go to settings and turn on for sample app", Snackbar.LengthShort).Show();
                        }
                        else
                        {
                            Snackbar.Make(this.CurrentFocus, "Required permission " + permissions[index]
                                    + " not granted", Snackbar.LengthShort).Show();
                        }
                    }
                }
                SetupMapFragmentView();
            }
            else
            {
                Essentials.Platform.OnRequestPermissionsResult(requestCode, permissions, grantResults);
                base.OnRequestPermissionsResult(requestCode, permissions, grantResults);
            }
        }

        private void SetupMapFragmentView()
        {
            // Set up disk cache path for the map service for this application
            bool success = MapSettings.SetIsolatedDiskCacheRootPath(ApplicationContext.GetExternalFilesDir(null) + File.Separator + ".here-maps");

            if (!success)
            {
                Toast.MakeText(ApplicationContext, "Unable to set isolated disk cache path.", ToastLength.Long);
            }
            else
            {
                m_mapFragmentView = new MapFragmentView(this);
            }
        }
    }
}