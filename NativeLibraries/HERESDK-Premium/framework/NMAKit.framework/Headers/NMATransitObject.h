/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAProxyObject.h"


/**
 * The types of public transit object that can be represented
 * by an instance of NMATransitObject.
 */
typedef NS_ENUM(NSUInteger, NMATransitObjectType) {
    NMATransitObjectTypeAccess,
    NMATransitObjectTypeLine,
    NMATransitObjectTypeStop
};


/**
 * An object used to visually represent public transit information
 * on an NMAMapView instance.
 *
 * NMATransitObject instances are created as necessary by the system to
 * display public transit information on a map. The object may represent
 * any one of NMATransitAccess, NMATransitStop, or NMATransitLine.
 *
 * NMATransitObject instances are most commonly accessed by selecting them
 * on an NMAMapView, either via a tap gesture or programmatically.
 */
@interface NMATransitObject : NMAProxyObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The type of transit information represented by this object.
 */
@property (nonatomic, readonly) NMATransitObjectType type;

/**
 * The unique identifying string of the transit information
 * represented by this object.
 */
@property (nonatomic, readonly, nullable) NSString *uniqueId;

@end
