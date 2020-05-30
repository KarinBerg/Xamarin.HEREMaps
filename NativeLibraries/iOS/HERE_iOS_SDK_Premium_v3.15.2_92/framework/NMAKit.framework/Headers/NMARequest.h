/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@protocol NMAResultListener;
@class NMARequest;
@class NMAGeoBoundingBox;


/**
 * Search result text output formats.
 */
typedef NS_ENUM(NSUInteger, NMATextFormat) {
    /** The request results will be rendered as HTML */
    NMATextFormatHTML NS_SWIFT_NAME(html) = 0 ,
    /** The request results will be rendered as plain text */
    NMATextFormatPlain
};

/**
 * The possible types of connectivity mode that the request is performed.
 */
typedef NS_ENUM(NSUInteger, NMARequestConnectivity) {
    /**
     * The request will be executed based on the current online status [NMAApplicationContext isOnline], which depends
     * on the current network access and could be forced to offline using [NMAApplicationContext setNetworkAccessAllowed:NO].
     * If the SDK is online then an online request will be made. If the SDK is offline then an offline
     * request will be made.
     */
    NMARequestConnectivityDefault = 0,
    /**
     * The request will be executed in offline mode regardless whether there is enough map
     * data on the device. If there is not enough map data the request might fail or return zero results.
     * If it fails, it will not try online.
     */
    NMARequestConnectivityOffline,
    /**
     * The request will be executed in online mode regardless whether the current online status
     * [NMAApplicationContext isOnline] is online or not. If offline the request will fail.
     * If it fails, it will not try offline.
     */
    NMARequestConnectivityOnline
};

/**
 * A typedef of a block parameter signature used with `NMARequest::startWithBlock:`.
 *
 * The following table shows corresponding request and result types.
 *
 * 1. `NMARequest`                         - Expected Search Results
 *
 * 2. `NMAGeocodeRequest`                  - `NSArray` of `NMAGeocodeResult`
 *
 * 3. `NMAReverseGeocodeRequest`           - `NSArray` of `NMAReverseGeocodeResult`
 *
 * 4. `NMADiscoveryRequest`                - `NMADiscoveryPage`
 *
 * 5. `NMAPlaceRequest`                    - `NMAPlace`
 *
 * 6. `NMAMediaCollectionPageRequest`      - `NMAMediaCollectionPage`
 *
 * 7. `NMACategoryGraphRequest`            - `NSString`
 *
 * 8. `NMAPlaceTransitSchedulePage`Request - `NMAPlaceTransitSchedulePage`
 *
 * @note The block will be called on the main queue.
 *
 * @param request The search request being completed.
 * @param data Search results. Search result type varies according to the
 * search request initiated. It can be nil if no results are found or an error
 * is encountered.
 * @param error The error if the request failed, or nil if the request was successful.
 *
 * See also `NMARequest::startWithBlock:`
 *
 * See also `NMASearchResultType`
 */
typedef void (^NMARequestCompletionBlock)(NMARequest *_Nonnull request,
                                          id          _Nullable data,
                                          NSError *   _Nullable error);


/**
 *
 * Represents a base interface for a search request.
 */
@interface NMARequest : NSObject<NSCoding>

/**
 * Initializes a NMARequest instance.
 */
- (nonnull instancetype)init;

/**
 * User-defined Tag as convenience method to identify `NMARequest`.
 *
 * @note The default value for userTag is empty string and user should
 * assign any tag value with their own convention.
 */
@property (nullable, nonatomic) NSString *userTag;

/**
 * NSString representing the preferred language for request responses.
 *
 * Default Value: [[NSLocale preferredLanguages] objectAtIndex:0].
 *
 * @note languagePreference should be a valid code according to the IETF BCP-47 standard
 * (see http://tools.ietf.org/html/bcp47 ).
 */
@property (nullable, nonatomic) NSString *languagePreference;

/**
 * The maximum number of items in the response.
 *
 * @note The default value is 20.
 */
@property (nonatomic) NSUInteger collectionSize;

/**
 * The NMARequestConnectivity for controlling Places API connectivity mode.
 *
 * Default Value: NMARequestConnectivityDefault, based on NMAApplicationContext network access
 * status.
 *
 * @note the connectivity of a request is preserved for the next refined search request and the
 * place details request.
 * For example: A user performs an offline discovery search and receives a list of search resutls.
 * The NMADiscoveryRequest::nextPageRequest and NMAPlaceLink::detailsRequest retrieved from the
 * search results will also be executed in offline mode.
 */
@property (nonatomic) NMARequestConnectivity connectivity;

/**
 * The bounding box in which to perform the search.
 *
 * The viewport can act as an implicit location context in the absence of an
 * explicit location context. To ensure you get the best results possible, you
 * should match the viewport to your map if there is a map visible to the user.
 */
@property (nullable, nonatomic) NMAGeoBoundingBox *viewport;

/**
 * The NSArray of sources have been added for a NMAPlace.
 *
 * See also `NMARequest::addSource:`
 */
@property (nonnull, nonatomic, readonly) NSArray<NSString *> *sources;

/**
 * Adds custom header to request.
 * Online documentation provides a comprehensive reference to the query parameters supported by the Geocoder API:
 * https://developer.here.com/documentation/geocoder/topics/resources.html
 *
 * @param name Name of the header.
 * @param value Name of the header.
 */
- (void)addCustomHeader:(nonnull NSString *)name value:(nonnull NSString *)value;

/**
 * Invokes an asynchronous query request with a specified listener.
 *
 * @param aSearchEventListener A listener to listen for search results
 * @return The appropriate NSError code. NMARequestErrorOperationNotAllowed
 * indicates access to this operation is denied. Contact your HERE representative
 * for more information.
 *
 * @note The `NMARequestErrorNotSupported` can be returned if current search service
 * is unavailable for your region. For more information see the Developer's Guide.
 *
 * See also `startWithBlock:`
 */
- (nullable NSError *)startWithListener:(nullable id<NMAResultListener>)aSearchEventListener
NS_SWIFT_NAME(start(withListener:));
/**
 * Invokes an asynchronous query request with a specified block.
 *
 * @param completionBlock A block to be executed upon completion of the request
 * @return The appropriate NSError code
 *
 * @note The `NMARequestErrorNotSupported` can be returned if current search service
 * is unavailable for your region. For more information see the Developer's Guide.
 *
 * See also `NMARequestCompletionBlock`
 *
 * See also `startWithListener:`
 */
- (nullable NSError *)startWithBlock:(nullable NMARequestCompletionBlock)completionBlock
NS_SWIFT_NAME(start(_:));

/**
 * Cancels any pending query request.
 */
- (BOOL)cancel;

/**
 * This function adds the a reference
 * identifier to be returned in the request results. See also
 * `NMAPlace::referenceIdentifiersForSource:`.
 *
 * Examples of reference identifiers are:
 * "NMAPlacesSourcePVID" for HERE's core content product which provides map and POI data,
 * "NMAPlacesSourceVenuesAll" for HERE's venue maps product whcih provides indoor
 * maps for thousands of venues, "NMAPlacesSourceBuilding" for extruded building.
 *
 * @param source A string containing the source identifier to add.
 */
- (void)addSource:(nonnull NSString *)source;

@end
