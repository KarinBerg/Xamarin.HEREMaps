/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAMapMarker.h"

@class NMAGeoCoordinates;
@class NMAImage;


/**
 * A `NMAMapMarker` object with text label
 *
 * @note User can configure the localization of the text label via setText:forLanguage: API
 *
 */
@interface NMAMapLabeledMarker : NMAMapMarker

/**
 * A convenient method to construct a `NMAMapLabeledMarker` at the specified coordinates.
 *
 * @param coordinates The NMAGeoCoordinates to display the map marker
 *
 * @return The `NMAMapLabeledMarker` object
 */
+ (nonnull instancetype)mapLabeledMarkerWithGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * A convenient method to construct a `NMAMapLabeledMarker` at the specified coordinates with
 * a custom `NMAImage` icon
 *
 * @param coordinates The NMAGeoCoordinates to display the map marker
 * @param icon The NMAImage to use for the marker icon.
 * @return The `NMAMapLabeledMarker` object
 */
+ (nonnull instancetype)mapLabeledMarkerWithGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates
                                                      icon:(nonnull NMAImage *)icon
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * A convenient method to construct a `NMAMapLabeledMarker` at the specified coordinates with
 * a custom `UIImage`
 *
 * @param coordinates The NMAGeoCoordinates to display the map marker
 * @param image The UIImage to use for the marker icon.
 * @return The `NMAMapLabeledMarker` object
 */
+ (nonnull instancetype)mapLabeledMarkerWithGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates
                                                     image:(nonnull UIImage *)image
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Specify the localized text for the label associated with this map marker
 *
 * @note User can specify up to 255 localized text entries for the label (one per language).
 * The text being displayed is determined by the current language setting of `NMAMapView` this
 * marker is added to.
 *
 * @note User can obtain the system's current language code via
 * [[NSLocale preferredLanguages] objectAtIndex:0]]
 *
 * @param text The localized text for the label
 * @param language The language code in canonicalized IETF BCP 47 language identifier
 * @return True if the operation succeeded. False otherwise.
 */
- (BOOL)setText:(nullable NSString *)text forLanguage:(nullable NSString *)language;

/**
 * Retrieve the previously stored localized text entry for a specific langauge.
 *
 * @param language The language code in canonicalized IETF BCP 47 language identifier
 * @return The localized text for the language. Return nil if no such text is set.
 */
- (nullable NSString *)textForLanguage:(nullable NSString *)language;

@end
