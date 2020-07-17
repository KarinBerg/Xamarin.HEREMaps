// WARNING
//
// This file has been generated automatically by Visual Studio from the outlets and
// actions declared in your storyboard file.
// Manual changes to this file will not be maintained.
//
using Foundation;
using System;
using System.CodeDom.Compiler;

namespace HereMapsTestApp
{
    [Register ("MapViewController")]
    partial class MapViewController
    {
        [Outlet]
        [GeneratedCode ("iOS Designer", "1.0")]
        UIKit.UIButton RouteButton { get; set; }

        [Action ("routeButton_TouchUpInside:")]
        [GeneratedCode ("iOS Designer", "1.0")]
        partial void routeButton_TouchUpInside (UIKit.UIButton sender);

        void ReleaseDesignerOutlets ()
        {
            if (RouteButton != null) {
                RouteButton.Dispose ();
                RouteButton = null;
            }
        }
    }
}