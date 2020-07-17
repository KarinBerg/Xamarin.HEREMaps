using System;
using CoreGraphics;
using Foundation;
using UIKit;
using Xamarin.HEREMaps.iOS;

namespace HereMapsTestApp
{
    public partial class MapViewController : UIViewController
    {
        private NMAMapView MapView { get; set; }
        private NMACoreRouter Router { get; set; }
        private NMAMapRoute MapRoute { get; set; }

        public MapViewController(IntPtr handle) : base(handle)
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();

            BeginInvokeOnMainThread(() =>
            {
                CreateMapView();
                ConfigureMapView();
                ConfigureButton();
            });
        }

        private void CreateMapView()
        {
            // Create NMAMapView manually on MainThread because otherwise there is a message "[EAGLContext renderbufferStorage:fromDrawable:] was called from a non-main thread in an implicit transaction! ..." and the map needs more time to be shown.
            MapView = new NMAMapView(View.Frame);
            View.Add(MapView);
            View.SendSubviewToBack(MapView);
        }

        private void ConfigureMapView()
        {
            MapView.CopyrightLogoPosition = NMALayoutPosition.BottomLeft;

            NMAGeoCoordinates geoCoordCenter = new NMAGeoCoordinates(50.9605737, 7.7703383);
            MapView.SetGeoCenter(geoCoordCenter, NMAMapAnimation.None);

            MapView.ZoomLevel = 5;
            MapView.WeakGestureDelegate = this;

            NMAClusterLayer cl = new NMAClusterLayer();

            cl.AddMarker(new VehicleMapMarker(new NMAGeoCoordinates(50.9605738, 7.7703383), "Testvehicle 1"));
            cl.AddMarker(new VehicleMapMarker(new NMAGeoCoordinates(49.8022486, 8.6021228), "Testvehicle 2"));
            cl.AddMarker(new VehicleMapMarker(new NMAGeoCoordinates(48.712405, 9.3061532), "Testvehicle 3"));

            MapView.AddClusterLayer(cl);
        }

        private void ConfigureButton()
        {
            RouteButton.SetTitle("Calculate Route", UIControlState.Normal);
            RouteButton.Layer.CornerRadius = 10;
            RouteButton.BackgroundColor = UIColor.DarkGray;
        }

        private void OnCalculateRouteCompletion(NMARouteResult routeResult, NMARoutingError error)
        {
            if (routeResult != null && routeResult.Routes.Length >= 1)
            {
                // Let's add the 1st result onto the map
                NMARoute route = routeResult.Routes[0];
                MapRoute = new NMAMapRoute(route);
                MapView.AddMapObject(MapRoute);

                // In order to see the entire route, we orientate the map view
                // accordingly
                MapView.SetBoundingBox(route.BoundingBox, NMAMapAnimation.Linear);
            }
            else
            {
                Console.WriteLine("Error:route result returned is not valid");
                Console.WriteLine("Error:route calculation returned error code %d", (int)error);
            }            
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

        partial void routeButton_TouchUpInside(UIButton sender)
        {
            if (MapRoute != null)
            {
                MapView.RemoveMapObject(MapRoute);
                MapRoute = null;
            }

            // START: Daimler Fleetboard
            NMAGeoCoordinates start = new NMAGeoCoordinates(48.7244153, 9.1161991);
            // END: Biergarten
            NMAGeoCoordinates end = new NMAGeoCoordinates(48.701356, 9.1393803);

            // Create an NSMutableArray to add two stops
            NSObject[] stops = new NSObject[] { start, end };

            NMARoutingMode routingMode = new NMARoutingMode(NMARoutingType.Fastest, NMATransportMode.Car, NMARoutingOption.Highway);

            // Initialize the NMACoreRouter
            if (Router == null)
            {
                Router = new NMACoreRouter();
            }
            // Trigger the route calculation
            Router.CalculateRouteWithStops(stops, routingMode, OnCalculateRouteCompletion);
        }
    }
}