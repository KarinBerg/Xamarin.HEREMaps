using System;
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
            });
        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }
    }
}