/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMAPositionDataSource.h"

/**
 * Specifies the type of indoor positioning mode
 */
typedef NS_ENUM(NSUInteger, NMAIndoorPositioningMode) {
    /**
     * Indoor positioning is not supported.
     * This value cannot be set. Only supported as return value from the indoorPositioningMode
     * property.
     */
    NMAIndoorPositioningModeNone = 0,
    /**
     * Let the HERE positioning choose which radio maps to use, based on availability and accuracy.
     * This is the default mode when HERE indoor positioning is started.
     */
    NMAIndoorPositioningModeAutomatic,
    /**
     * Use community (public) indoor radio maps only
     * This mode is not available if access to this operation is denied. Contact your HERE representaive
     * for more information.
     */
    NMAIndoorPositioningModeCommunity,
    /**
     * Use private radio maps only
     * This mode is not available if access to this operation is denied. Contact your HERE representaive
     * for more information.
     */
    NMAIndoorPositioningModePrivate
};


/**
 * A position data source which provides hybrid position.
 *
 * In addition to device position the HERE position source can return an advanced
 * Bluetooth LE-based position provided by HERE Positioning Service.
 *
 * @note The HERE position source cannot be initialized if access to this operation is denied.
 * Contact your HERE representative for more information.
 */
@interface NMAHEREPositionSource : NSObject<NMAPositionDataSource>

/**
 * Initializes an NMAHEREPositionSource. May return nil.
 *
 * Returns nil if access to this operation is denied.
 * Contact your HERE representative for more information.
 */
- (null_unspecified instancetype)init;

/**
 * The mode defining which indoor radio maps HERE positioning is allowed to use.
 *
 * Explicit access rights are required to set some modes. See NMAIndoorPositioningMode. If access to
 * this operation is denied the property will not be changed. Contact your HERE representaive for more
 * information.
 *
 * See also `NMAIndoorPositioningMode`
 */
@property (nonatomic) NMAIndoorPositioningMode indoorPositioningMode;

@end
