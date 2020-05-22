/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

import UIKit
import NMAKit

class ViewController: UIViewController
{
    @IBOutlet weak var mapView: NMAMapView!

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        // Make sure copyright logo is visible according to your App's UI design
        mapView.copyrightLogoPosition = NMALayoutPosition.bottomLeft

        // Show current position indicator
        mapView.positionIndicator.isVisible = true
        mapView.positionIndicator.isAccuracyIndicatorVisible = true
    }

    @IBAction func trackingButtonChanged(_ button: UIButton) {
        if (NMANavigationManager.sharedInstance().navigationState == .idle) {
            NMANavigationManager.sharedInstance().map = self.mapView;
            let error = NMANavigationManager.sharedInstance().startTracking(.car)
            if (error == nil) {
                button.setTitle("Stop Tracking", for:[])
            }
        } else {
            NMANavigationManager.sharedInstance().stop()
            self.mapView.tilt = 0
            button.setTitle("Track Current Location", for:[])
        }
    }
}
