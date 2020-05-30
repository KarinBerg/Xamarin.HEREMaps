/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMALocationInfo.h"
#import "NMAProxyObject.h"


/**
 * Visually represents a selectable point of interest inside a view.
 *
 * NMAPoiObject is a proxy object (created by the SDK) and thus instances cannot
 * be modified. They can be selected from within their containing view (e.g.
 * NMAMapView) and can be used to obtain information about the real-world point
 * of interest that they represent.
 */
@interface NMAPoiObject : NMAProxyObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The information for the location represented by the POI object.
 */
@property (nonatomic, nonnull) NMALocationInfo *locationInfo;

@end
