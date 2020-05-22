/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "HelloMapViewController.h"

@import NMAKit;

@interface HelloMapViewController ()
@property (weak, nonatomic) IBOutlet NMAMapView *mapView;
@end

@implementation HelloMapViewController

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];

    // Make sure copyright logo is visible according to your App's UI design
    self.mapView.copyrightLogoPosition = NMALayoutPositionBottomLeft;

    // Enable current position indicator
    self.mapView.positionIndicator.visible = YES;
    self.mapView.positionIndicator.accuracyIndicatorVisible = YES;
}

- (IBAction)startTrackingChanged:(UIButton *)button
{
    if (NMANavigationManager.sharedNavigationManager.navigationState == NMANavigationStateIdle) {
        NMANavigationManager.sharedNavigationManager.map = self.mapView;
        NSError *error = [NMANavigationManager.sharedNavigationManager startTrackingWithTransportMode:NMATransportModeCar];
        if (error == nil) {
            [button setTitle:@"Stop Tracking" forState:UIControlStateNormal];
        }
    } else {
        [NMANavigationManager.sharedNavigationManager stop];
        self.mapView.tilt = 0;
        [button setTitle:@"Track Current Location" forState:UIControlStateNormal];
    }
}

@end
