/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAUrbanMobilityOperator;
@class NMAUrbanMobilityProvider;
@class NMAUrbanMobilityLink;
@class NMAUrbanMobilityTransport;


/**
 * All available information about one transit alert.
 *
 * IMPORTANT: Urban Mobility routing is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityAlert : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Gets unique Id for this alert. Might help to identify
 * if this alert was already processed on the client.
 *
 * @return alert id.
 */
@property (nonatomic, readonly, nullable) NSString *uniqueId;

/**
 * Gets the `NMAUrbanMobilityProvider` whose services are affected by this alert.
 *
 * @return affected provider.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityProvider *provider;

/**
 * Gets array of `NMAUrbanMobilityTransport` objects affected by this alert.
 *
 * @return array of transports.
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityTransport *> *transports;

/**
 * Gets alert information text to display to the user.
 * Information text is localized to the current device's language.
 * If given language is not supported, English version is returned.
 *
 * @return alert information text.
 */
@property (nonatomic, readonly, nullable) NSString *info;

/**
 * Gets the NSDate from which this alert is valid.
 *
 * @return valid from date.
 */
@property (nonatomic, readonly, nullable) NSDate *validFrom;

/**
 * Gets the NSDate until which this alert is valid.
 *
 * @return valid until date.
 */
@property (nonatomic, readonly, nullable) NSDate *validUntil;

/**
 * Gets the `NMAUrbanMobilityLink` link to a web resource.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityLink *source;

/**
 * Gets a link to the image which, if present, should be displayed along with this alert.
 *
 * @return url (as NSString) to the image, or nil if not available.
 */
@property (nonatomic, readonly, nullable) NSString *imageUrl;

/**
 * Gets display text which, if present, should be displayed
 * next to image obtained by #imageUrl.
 *
 * @return display text, or nil if not available.
 */
@property (nonatomic, readonly, nullable) NSString *imageCaption;

@end
