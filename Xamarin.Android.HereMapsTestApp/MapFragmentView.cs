using Android.Util;
using Android.Views;
using Android.Widget;
using AndroidX.AppCompat.App;
using Com.Here.Android.Mpa.Common;
using Com.Here.Android.Mpa.Mapping;
using Com.Here.Android.Mpa.Routing;
using Java.Lang;

namespace Xamarin.Android.HereMapsTestApp
{
    public class MapFragmentView
    {
        private AndroidXMapFragment m_mapFragment;
        private Button m_createRouteButton;
        private AppCompatActivity m_activity;
        private Map m_map;
        private MapRoute m_mapRoute;

        public MapFragmentView(AppCompatActivity activity)
        {
            m_activity = activity;
            initMapFragment();
            /*
             * We use a button in this example to control the route calculation
             */
            initCreateRouteButton();
        }

        private AndroidXMapFragment getMapFragment()
        {
            return (AndroidXMapFragment)m_activity.SupportFragmentManager.FindFragmentById(Resource.Id.mapfragment);
        }

        private void initMapFragment()
        {
            /* Locate the mapFragment UI element */
            m_mapFragment = getMapFragment();

            if (m_mapFragment != null)
            {
                /* Initialize the AndroidXMapFragment, results will be given via the called back. */
                m_mapFragment.Init(new OnEngineInitListener(this));
            }
        }
        
        private class OnEngineInitListener : Java.Lang.Object, IOnEngineInitListener
        {
            private MapFragmentView parent;

            public OnEngineInitListener(MapFragmentView parent)
            {
                this.parent = parent;
            }

            public void OnEngineInitializationCompleted(OnEngineInitListenerError error)
            {
                if (error == OnEngineInitListenerError.None)
                {
                    // retrieve a reference of the map from the map fragment
                    parent.m_map = parent.m_mapFragment.Map;
                    // Set the map center to the Vancouver region (no animation)
                    parent.m_map.SetCenter(new GeoCoordinate(50.9605737, 7.7703383, 0.0), Map.Animation.None);
                    // Set the zoom level to the average between min and max
                    parent.m_map.SetZoomLevel((parent.m_map.MaxZoomLevel + parent.m_map.MinZoomLevel) / 2);
                }
                else
                {
                    // print error
                    Log.Error("MapFragmentView", "ERROR: Cannot initialize Map Fragment: " + error.Details);
                }
            }
        }

        private class OnClickListener : Java.Lang.Object, View.IOnClickListener
        {
            private MapFragmentView parent;

            public OnClickListener(MapFragmentView parent)
            {
                this.parent = parent;
            }

            public void OnClick(View v)
            {
                /*
                 * Clear map if previous results are still on map,otherwise proceed to creating
                 * route
                 */
                if (parent.m_map != null && parent.m_mapRoute != null)
                {
                    parent.m_map.RemoveMapObject(parent.m_mapRoute);
                    parent.m_mapRoute = null;
                }
                else
                {
                    /*
                     * The route calculation requires local map data.Unless there is pre-downloaded
                     * map data on device by utilizing MapLoader APIs, it's not recommended to
                     * trigger the route calculation immediately after the MapEngine is
                     * initialized.The INSUFFICIENT_MAP_DATA error code may be returned by
                     * CoreRouter in this case.
                     *
                     */
                    parent.CreateRoute();
                }
            }
        }

        private void initCreateRouteButton()
        {
            m_createRouteButton = (Button)m_activity.FindViewById(Resource.Id.button);

            m_createRouteButton.SetOnClickListener(new OnClickListener(this));
        }

        private class RouterListener : Java.Lang.Object, IRouterListener
        {
            private MapFragmentView parent;

            public RouterListener(MapFragmentView parent)
            {
                this.parent = parent;
            }

            public void OnCalculateRouteFinished(Object results, Object routingError)
            {
                /* Calculation is done. Let's handle the result */
                if (routingError == RoutingError.None)
                {
                    Java.Util.AbstractList routeResults = (Java.Util.AbstractList)results;
                    RouteResult route = routeResults.Get(0) as RouteResult;
                    if (route != null)
                    {
                        /* Create a MapRoute so that it can be placed on the map */
                        parent.m_mapRoute = new MapRoute(route.Route);

                        /* Show the maneuver number on top of the route */
                        parent.m_mapRoute.SetManeuverNumberVisible(true);

                        /* Add the MapRoute to the map */
                        parent.m_map.AddMapObject(parent.m_mapRoute);

                        /*
                         * We may also want to make sure the map view is orientated properly
                         * so the entire route can be easily seen.
                         */
                        GeoBoundingBox gbb = route.Route.BoundingBox;
                        parent.m_map.ZoomTo(gbb, Map.Animation.None, Map.MovePreserveOrientation);
                    }
                    else
                    {
                        Toast.MakeText(parent.m_activity,
                                "Error:route results returned is not valid",
                                ToastLength.Long).Show();
                    }
                }
                else
                {
                    Toast.MakeText(parent.m_activity,
                            "Error:route calculation returned error code: " + routingError,
                            ToastLength.Long).Show();
                }
            }

            public void OnProgress(int p0)
            {
                /* The calculation progress can be retrieved in this callback. */
            }
        }

        /* Creates a route from 4350 Still Creek Dr to Langley BC with highways disallowed */
        private void CreateRoute()
        {
            /* Initialize a CoreRouter */
            CoreRouter coreRouter = new CoreRouter();

            /* Initialize a RoutePlan */
            RoutePlan routePlan = new RoutePlan();

            /*
             * Initialize a RouteOption. HERE Mobile SDK allow users to define their own parameters for the
             * route calculation,including transport modes,route types and route restrictions etc.Please
             * refer to API doc for full list of APIs
             */
            RouteOptions routeOptions = new RouteOptions();
            /* Other transport modes are also available e.g Pedestrian */
            routeOptions.SetTransportMode(RouteOptions.TransportMode.Car);
            /* Disable highway in this route. */
            routeOptions.SetHighwaysAllowed(false);
            /* Calculate the shortest route available. */
            routeOptions.SetRouteType(RouteOptions.Type.Shortest);
            /* Calculate 1 route. */
            routeOptions.SetRouteCount(1);
            /* Finally set the route option */
            routePlan.SetRouteOptions(routeOptions);

            /* Define waypoints for the route */
            // START: Daimler Fleetboard
            RouteWaypoint startPoint = new RouteWaypoint(new GeoCoordinate(48.7244153, 9.1161991));
            // END: Biergarten
            RouteWaypoint destination = new RouteWaypoint(new GeoCoordinate(48.701356, 9.1393803));

            /* Add both waypoints to the route plan */
            routePlan.AddWaypoint(startPoint);
            routePlan.AddWaypoint(destination);

            /* Trigger the route calculation,results will be called back via the listener */
            coreRouter.CalculateRoute(routePlan, new RouterListener(this));
        }
    }
}
