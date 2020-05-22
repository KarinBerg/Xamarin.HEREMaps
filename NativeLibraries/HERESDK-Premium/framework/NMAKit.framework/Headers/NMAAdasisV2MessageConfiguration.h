/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */



/**
 *
 * `NMAAdasisV2MessageConfiguration` is a class that is used to
 * enable or disable generation of specific ADASIS v2 messages.
 */
@interface NMAAdasisV2MessageConfiguration : NSObject

/**
 * Enables META-DATA messages.
 */
@property (nonatomic) BOOL metaDataEnabled;

/**
 * Enables POSITION messages.
 */
@property (nonatomic) BOOL positionEnabled;

/**
 * Enables SEGMENT messages.
 */
@property (nonatomic) BOOL segmentEnabled;

/**
 * Enables STUB messages.
 */
@property (nonatomic) BOOL stubEnabled;

/**
 * Enables long profile LATITUDE and LONGITUDE messages.
 */
@property (nonatomic) BOOL latitudeLongitudeEnabled;

/**
 * Enables long profile PVID messages.
 */
@property (nonatomic) BOOL pvidEnabled;

/**
 * Enables short profile ROAD_ACCESSIBILITY messages.
 */
@property (nonatomic) BOOL roadAccessibilityEnabled;

/**
 * Enables short profile SLOPE messages.
 */
@property (nonatomic) BOOL slopeEnabled;

/**
 * Creates `NMAAdasisV2MessageConfiguration` instance with all possible ADASIS messages enabled.
 */
+ (nonnull instancetype)createWithAllMessagesEnabled;

/**
 * Creates `NMAAdasisV2MessageConfiguration` instance with default ADASIS messages enabled.
 * Default ADASIS messages are POSITION, STUB, SEGMENT and META-DATA.
 */
+ (nonnull instancetype)createWithDefaultMessagesEnabled;

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
