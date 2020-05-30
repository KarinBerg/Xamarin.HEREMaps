using System;
using CoreGraphics;
using Foundation;
using UIKit;
using Xamarin.HEREMaps.iOS;

namespace HereMapsTestApp
{
    public partial class MapViewController : UIViewController
    {
        private NMAMapView mapView = null;

        public MapViewController(IntPtr handle) : base(handle)
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();

            // [EAGLContext renderbufferStorage:fromDrawable:] was called from a non-main thread in an implicit transaction! Note that this may be unsafe without an explicit CATransaction or a call to [CATransaction flush].
            this.BeginInvokeOnMainThread(() =>
            {
                mapView = new NMAMapView(View.Frame);
                View.Add(mapView);
                mapView.CopyrightLogoPosition = NMALayoutPosition.BottomLeft;

                NMAGeoCoordinates geoCoordCenter = new NMAGeoCoordinates(50.9605737, 7.7703383);
                mapView.SetGeoCenter(geoCoordCenter, NMAMapAnimation.None);

                mapView.ZoomLevel = 5;
                mapView.WeakGestureDelegate = this;

                NMAClusterLayer cl = new NMAClusterLayer();

                cl.AddMarker(new VehicleMapMarker(new NMAGeoCoordinates(50.9605738, 7.7703383), "Testvehicle 1"));
                cl.AddMarker(new VehicleMapMarker(new NMAGeoCoordinates(49.8022486, 8.6021228), "Testvehicle 2"));
                cl.AddMarker(new VehicleMapMarker(new NMAGeoCoordinates(48.712405, 9.3061532), "Testvehicle 3"));

                mapView.AddClusterLayer(cl);
            });
        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }

        //Weak Delegate: Bind to the Objective-C selector mapView:didReceiveTapAtLocation:
        // https://docs.microsoft.com/en-us/xamarin/ios/app-fundamentals/delegates-protocols-and-events#delegates
        [Export("mapView:didReceiveTapAtLocation:")]
        public void DidReceiveTapAtLocation(NMAMapView mapView, CGPoint location)
        {
            //Create Alert
            var okAlertController = UIAlertController.Create("Info", "You tapped on the map!", UIAlertControllerStyle.Alert);

            //Add Action
            okAlertController.AddAction(UIAlertAction.Create("OK", UIAlertActionStyle.Default, null));

            // Present Alert
            PresentViewController(okAlertController, true, null);
        }
    }
}