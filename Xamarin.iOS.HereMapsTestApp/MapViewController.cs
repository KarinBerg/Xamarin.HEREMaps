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
        private NMACoreRouter router;
        private NMAMapRoute mapRoute;
        private UIButton button;

        public MapViewController(IntPtr handle) : base(handle)
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();

            // [EAGLContext renderbufferStorage:fromDrawable:] was called from a non-main thread in an implicit transaction! Note that this may be unsafe without an explicit CATransaction or a call to [CATransaction flush].
            BeginInvokeOnMainThread(() =>
            {
                AddMapViewToView(View);
                AddButtonToView(View);
            });            
        }

        private void AddMapViewToView(UIView view)
        {
            mapView = new NMAMapView(view.Frame);
            view.Add(mapView);
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
        }

        private void AddButtonToView(UIView view)
        {
            button = new UIButton(UIButtonType.Custom);
            button.SetTitle("Calculate Route", UIControlState.Normal);
            button.Layer.CornerRadius = 10;
            CGSize buttonSize = new CGSize(150, 50);
            CGPoint location = new CGPoint(view.Frame.GetMidX() - (buttonSize.Width / 2.0), view.Frame.Height - buttonSize.Height - 10);
            button.Frame = new CGRect(location, buttonSize);
            button.BackgroundColor = UIColor.DarkGray;
            button.TouchUpInside += (sender, e) =>
            {
                if (mapRoute != null)
                {
                    mapView.RemoveMapObject(mapRoute);
                    mapRoute = null;
                }

                // START: Daimler Fleetboard
                NMAGeoCoordinates start = new NMAGeoCoordinates(48.7244153, 9.1161991);
                // END: Biergarten
                NMAGeoCoordinates end = new NMAGeoCoordinates(48.701356, 9.1393803);

                // Create an NSMutableArray to add two stops
                NSObject[] stops = new NSObject[] { start, end };

                NMARoutingMode routingMode = new NMARoutingMode(NMARoutingType.Fastest, NMATransportMode.Car, NMARoutingOption.Highway);

                // Initialize the NMACoreRouter
                if (router == null)
                {
                    router = new NMACoreRouter();
                }

                // Trigger the route calculation
                router.CalculateRouteWithStops(stops, routingMode, OnCalculateRouteCompletion);
            };

            view.Add(button);
        }

        private void OnCalculateRouteCompletion(NMARouteResult routeResult, NMARoutingError error)
        {
            if (routeResult != null && routeResult.Routes.Length >= 1)
            {
                // Let's add the 1st result onto the map
                NMARoute route = routeResult.Routes[0];
                mapRoute = new NMAMapRoute(route);
                mapView.AddMapObject(mapRoute);

                // In order to see the entire route, we orientate the map view
                // accordingly
                mapView.SetBoundingBox(route.BoundingBox, NMAMapAnimation.Linear);
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
    }
}