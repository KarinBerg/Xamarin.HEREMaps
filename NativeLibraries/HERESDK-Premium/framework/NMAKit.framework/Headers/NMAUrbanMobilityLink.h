/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


/**
 * Type of the link as enum for convinient use.
 * The allowed values are:
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityLinkType) {
    /** Link type agency: Operator information URL. */
    NMAUrbanMobilityLinkTypeAgency      = 0,
    /** Link type logo: Operator logo URL. */
    NMAUrbanMobilityLinkTypeAgencyLogo  = 1,
    /** Link type tariff: Tariff information URL. */
    NMAUrbanMobilityLinkTypeTariff      = 2,
    /** Link type website: Website URL. */
    NMAUrbanMobilityLinkTypeWebsite     = 3,
    /** Link type booking: Booking URL. */
    NMAUrbanMobilityLinkTypeBooking     = 4,
    /** Link type alert: Alert URL. */
    NMAUrbanMobilityLinkTypeAlert       = 5,
    /** Link type unknown. */
    NMAUrbanMobilityLinkTypeUnknown     = 6
} DEPRECATED_ATTRIBUTE;


/**
 * Represents a link which can be associated with operator, transit alert or a ticket.
 * For example, a link to the transit operator's website.
 * This information must be exposed in the client application.
 *
 * IMPORTANT: Urban Mobility routing is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * See also `NMAUrbanMobilityOperator`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityLink : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Gets the NMAUrbanMobilityLink text.
 */
@property (nonatomic, readonly, nullable) NSString *text;

/**
 * Gets the NSString representation of the NMAUrbanMobilityLink url.
 */
@property (nonatomic, readonly, nullable) NSURL *url;

/**
 * Gets clickable part of text. If not available (empty string) the full text need to be
 * clickable.
 * For example if the `text` property returns "Lorem ipsum dolor sit amet,
 * consectetur adipiscing elit." and `urlText` returns "Lorem ipsum" then only
 * "Lorem ipsum" part should be clickable.
 *
 * @return clickable part of text, or nil if not available.
 */
@property (nonatomic, readonly, nullable) NSString *urlText;

/**
 * Gets the NMAUrbanMobilityLink type as  `NMAUrbanMobilityLinkType` ,
 * i.e. is it url to agency web-site or tariff information url.
 */
@property (nonatomic, readonly) NMAUrbanMobilityLinkType linkType;

@end
