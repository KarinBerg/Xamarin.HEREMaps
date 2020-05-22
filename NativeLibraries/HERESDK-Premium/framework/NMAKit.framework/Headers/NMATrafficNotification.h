/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMATrafficNotificationInfo;


/**
 * Traffic notification for the current navigation session.
 *
 * @note This class should not be instantiated directly.
 */
@interface NMATrafficNotification : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Array of NMATrafficNotificationInfo objects associated with the traffic notification
 */
@property (nonatomic, readonly, nonnull) NSArray<NMATrafficNotificationInfo *> *trafficNotificationInfo;

@end
