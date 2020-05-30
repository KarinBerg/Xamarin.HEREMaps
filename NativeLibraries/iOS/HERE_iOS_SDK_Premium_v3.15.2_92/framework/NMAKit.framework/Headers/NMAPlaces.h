/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMACategoryFilter;
@class NMAAutoSuggestionRequest;
@class NMADiscoveryRequest;
@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;
@class NMAPlaceRequest;
@class NMACategory;
@class NMAAddressFilter;

/**
 * The Search group provides classes, protocols, and enumerations
 * for performing place and geocoder searches.
 * Some important classes in this group are
 * `NMAPlaces` and `NMAGeocoder`.
 */

/**
 * Represents values describing AutoSuggestion response's result types that can be
 * used to restrict the AutoSuggestion response.
 */
typedef NS_OPTIONS(NSUInteger, NMAPlacesAutoSuggestionResultType) {
    /**
     * AutoSuggestion response will contain Location and address suggestion result type
     */
    NMAPlacesAutoSuggestionResultAddress        = 1,

    /**
     * AutoSuggestion response will contain POI suggestion result type
     */
    NMAPlacesAutoSuggestionResultPlace          = 1 << 1,

    /**
     * AutoSuggestion response will contain Category search suggestion result type
     */
    NMAPlacesAutoSuggestionResultCategory       = 1 << 2,

    /**
     * AutoSuggestion response will contain Chain/Brand search suggestion result type
     */
    NMAPlacesAutoSuggestionResultChain          = 1 << 3,

    /**
     * AutoSuggestion response will contain Query completion suggestion result type
     */
    NMAPlacesAutoSuggestionResultQuery          = 1 << 4
};

/**
 * Places Reference Source for core POI IDs.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPlacesSourcePVID;
/**
 * Places Reference Source for sharing IDs.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPlacesSourceSharing;
/**
 * Places Wikipedia Content.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPlacesContentWikipedia;


#pragma mark - DEPRECATED
/**
 * Places Reference Source for all types of venue IDs.
 *
 * DEPRECATED As of SDK 3.12.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPlacesSourceVenuesAll DEPRECATED_ATTRIBUTE;
/**
 * Places Reference Source for venue IDs.
 *
 * DEPRECATED As of SDK 3.12.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPlacesSourceVenuesVenue DEPRECATED_ATTRIBUTE;
/**
 * Places Reference Source for venue content IDs.
 *
 * DEPRECATED As of SDK 3.12.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPlacesSourceVenuesContent DEPRECATED_ATTRIBUTE;
/**
 * Places Reference Source for venue destination IDs.
 *
 * DEPRECATED As of SDK 3.12.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPlacesSourceVenuesDestination DEPRECATED_ATTRIBUTE;
/**
 * Places Reference Source for building IDs.
 *
 * DEPRECATED As of SDK 3.12.
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPlacesSourceBuilding DEPRECATED_ATTRIBUTE;

#pragma mark -

/**
 * A typedef of a block parameter signature used with
 * `NMAPlaces::refreshTopLevelCategoriesWithCompletion:`.
 *
 * @param categories An NSArray of localized NMACategory if available, nil otherwise.
 * @param error The error if the refresh failed, or nil if the refresh was successful.
 *
 * See also `NMAPlaces::refreshTopLevelCategoriesWithCompletion:`
 *
 * @note The block will be called on the main queue.
 */
typedef void (^NMAPlacesCategoriesCompletionBlock)(NSArray<NMACategory *> *_Nullable categories, NSError *_Nullable error);


/**
 *
 * Represents a factory for creating places requests.
 *
 * The `NMAPlaces` service supports a variety of use cases that center
 * around two major features:
 *
 * 1. Place discovery - helps users find places that are relevant to them.
 *
 * 2. Place information retrieval - provides detailed information about places
 * in which users are interested.
 *
 * For place discovery, the `NMAPlaces` API supports two use cases from which
 * to choose according to the requirements for the application:
 *
 * 1. Search - finds places that match user-provided search terms.
 *
 * 2. Explore - guides users to relevant places nearby.
 *
 * The `NMAPlaces` API defines resources that represent entry points for
 * supported use cases, employing links to describe the application flow within
 * a particular use case.
 *
 * For example, the discovery request is an entry point to the `NMAPlaces`
 * API resource. When an application user submits a discovery request to the
 * search resource, the response contains, among other items, a list of links
 * to places or to place resources. Each referenced place might have rich
 * content associated with it, including ratings, images, reviews, editorials,
 * and owner content. Each place also contains references to related places, which
 * allow users to discover places relevant to or otherwise related to their
 * original search.
 *
 * @note NMAPlaces requires valid authentication credentials to be set via
 * NMAApplicationContext. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.
 */
@interface NMAPlaces : NSObject

/**
 * Returns the `NMAPlaces` singleton instance.
 *
 * @note Use this method to obtain a `NMAPlaces` instance. Do not call
 * init directly.
 *
 * @return shared `NMAPlaces` instance
 */
+ (nullable NMAPlaces *)sharedPlaces NS_SWIFT_NAME(sharedInstance());

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Creates a `NMAPlaces` search request using a specified location
 * and query.
 *
 * The results of the search request are sets of places that match a
 * user's search term in a specific location. Additional user's current position
 * will also be sent to ensure you get the best results possible. The user's
 * current position is only available if [NMAPositioningManager active] is true.
 *
 * The viewport is a bounding box used to perform the search. To ensure you get
 * the best results possible, you should match the viewport to your map if there
 * is a map visible to the user. (see also `NMARequest::viewport`).
 *
 * A search location context must be provided by setting a search location or
 * a bounding map viewport or both. Failing to set a location context will
 * result in an error NMARequestErrorInvalidParameter when executing the request.
 *
 * @param location A `NMAGeoCoordinates` representing the query's location
 *                 context used to search for results that are appropriate to
 *                 the query parameter.
 * @param query NSString specifying the kind of places to locate
 * @return The `NMADiscoveryRequest` if both parameters are valid,
 *         nil otherwise.
 */
- (nullable NMADiscoveryRequest *)createSearchRequestWithLocation:(nullable NMAGeoCoordinates *)location
                                                            query:(nullable NSString *)query
NS_SWIFT_NAME(createSearchRequest(location:query:));

/**
 * Creates a `NMAPlaces` search request using a specified location
 * and query.
 *
 * The results of the search request are sets of places that match a
 * user's search term in a specific location. Additional user's current position
 * will also be sent to ensure you get the best results possible. The user's
 * current position is only available if [NMAPositioningManager active] is true.
 *
 * The viewport is a bounding box used to perform the search. To ensure you get
 * the best results possible, you should match the viewport to your map if there
 * is a map visible to the user. (see also `NMARequest::viewport`).
 *
 * A search location context must be provided by setting a search location or
 * a bounding map viewport or both. Failing to set a location context will
 * result in an error NMARequestErrorInvalidParameter when executing the request.
 *
 * @param location A `NMAGeoCoordinates` representing the query's location
 *                 context used to search for results that are appropriate to
 *                 the query parameter.
 * @param query NSString specifying the kind of places to locate
 * @param filter A `NMAAddressFilter` defining constraints used to filter results based on their
                 address.
 * @return The `NMADiscoveryRequest` if both parameters are valid,
 *         nil otherwise.
 */
- (nullable NMADiscoveryRequest *)createSearchRequestWithLocation:(nullable NMAGeoCoordinates *)location
                                                            query:(nullable NSString *)query
                                                           filter:(nullable NMAAddressFilter *)filter
NS_SWIFT_NAME(createSearchRequest(location:query:filter:));

/**
 * Creates a `NMAPlaces` explore request using a specified location
 * context and category filter. If a category filter is provided, the created
 * request will limit results to include only items with categories specified
 * in the filter.
 *
 * The results of the explore request is a list of nearby relevant places
 * for a given positon. It answers the question "What interesting places are near
 * a location?" The results returned are confined to those located in the current
 * search area and are ordered by popularity.
 *
 * Note that in addition to the requested location this search also considers the
 * current device position as returned by NMAPositioningManager.
 *
 * A search location context must be provided by setting a search location or
 * a search area or a bounding map viewport. Failing to set a location context will
 * result in an error NMARequestErrorInvalidParameter when executing the request.
 *
 * @param location A `NMAGeoCoordinates` representing the location
 *                 context used to search for nearby places
 * @param searchArea A `NMAGeoBoundingBox` representing the query's search area
 *                (this is an optional parameter and should not be set unless
 *                 such functionality is explicitly intended in the application)
 * @param filters A `NMACategoryFilter` representing the category filter
 * @return The `NMADiscoveryRequest` if parameters are valid
 */
- (nonnull NMADiscoveryRequest *)createExploreRequestWithLocation:(nullable NMAGeoCoordinates *)location
                                                       searchArea:(nullable NMAGeoBoundingBox *)searchArea
                                                          filters:(nullable NMACategoryFilter *)filters
NS_SWIFT_NAME(createExploreRequest(location:searchArea:filters:));


/**
 * Creates a `NMAPlaces` "What's here?" request using a specified
 * location context and category filter. If a category filter is provided, the
 * created request will limit results to include only items with categories
 * specified in the filter.
 *
 * The results of the here request is a list of places with addresses that
 * lie within the vicinity of the search location. The feature is typically used
 * by applications that include "check-in" or "click on map to get more
 * information" options. 
 *
 * Note that in addition to the requested location this search also considers the
 * current device position as returned by NMAPositioningManager.
 *
 * A search location context must be provided by setting a search location or
 * a bounding map viewport. Failing to set a location context will
 * result in an error NMARequestErrorInvalidParameter when executing the request.
 *
 * @param location A `NMAGeoCoordinates` representing the location
 *                 context used to search for nearby places
 * @param filters A `NMACategoryFilter` representing the category filter
 * @return The `NMADiscoveryRequest` if both parameters are valid
 */
- (nonnull NMADiscoveryRequest *)createHereRequestWithLocation:(nullable NMAGeoCoordinates *)location
                                                       filters:(nullable NMACategoryFilter *)filters
NS_SWIFT_NAME(createHereRequest(location:filters:));

/**
 * Creates a `NMAPlaces` around request using a specified location
 * context, usually the location of the user. If a category filter is provided,
 * the created request will limit results to include only items with categories
 * specified in the filter.
 *
 * This request is intended for applications that employ features such as
 * augmented reality, where places around the user's current location are of most
 * interest. It is intended to provide places that are likely to be visible to the
 * user as well as important places that are further away. The places around the
 * location context are returned in order of proximity. 
 *
 * Note that in addition to the requested location this search also considers the
 * current device position as returned by NMAPositioningManager.
 *
 * A search location context must be provided by setting a search location or
 * a search area or a bounding map viewport. Failing to set a location context will
 * result in an error NMARequestErrorInvalidParameter when executing the request.
 *
 * @param location A `NMAGeoCoordinates` representing the location
 *                 context used to search for nearby places
 * @param searchArea A `NMAGeoBoundingBox` representing the query's search area
 *                (this is an optional parameter and should not be set unless
 *                 such functionality is explicitly intended in the application)
 * @param filters A `NMACategoryFilter` representing the category filter
 * @return The `NMADiscoveryRequest` if parameters are valid
 */
- (nonnull NMADiscoveryRequest *)createAroundRequestWithLocation:(nullable NMAGeoCoordinates *)location
                                                      searchArea:(nullable NMAGeoBoundingBox *)searchArea
                                                         filters:(nullable NMACategoryFilter *)filters
NS_SWIFT_NAME(createAroundRequest(location:searchArea:filters:));

/**
 * Creates a `NMAAutoSuggestionRequest` request to return lists of suggested search terms, instant results and
 * refined search links related to a specified location context and partial search term.
 *
 * Note that this AutoSuggestion request supports online only. Please use
 * createSuggestionRequestWithLocation:partialTerm for offline.
 * Offline AutoSuggestion request fails with NMARequestErrorNotSupported error.
 *
 * In addition to the requested location this search also considers the
 * current device position as returned by NMAPositioningManager.
 *
 * A search location context must be provided by setting a search location or
 * a search area or a bounding map viewport. Failing to set a location context will
 * result in an error NMARequestErrorInvalidParameter when executing the request.
 *
 * Response items with `NMAAutoSuggestTypeQuery` type are not bounded to the provided search
 * location. If it is not needed to have such items in response, use `createAutoSuggestionRequestWithLocation`
 * method with `resultType` parameter to include/exclude certain item types, e.g. do not include
 * `NMAPlacesAutoSuggestionResultQuery` in this case.
 *
 * @param location A `NMAGeoCoordinates` representing the query location context
 * @param partialTerm An NSString specifying the partial search term
 *
 * @return The `NMAAutoSuggestionRequest` if the location is valid, nil otherwise
 */
- (nullable NMAAutoSuggestionRequest *)createAutoSuggestionRequestWithLocation:(nullable NMAGeoCoordinates *)location
                                                                   partialTerm:(nullable NSString *)partialTerm
NS_SWIFT_NAME(createAutoSuggestionRequest(location:partialTerm:));

/**
 * Creates a `NMAAutoSuggestionRequest` request to return lists of suggested search terms, instant results and
 * refined search links related to a specified location context, partial search term and
 * auto suggestion result types.
 *
 * Note that this AutoSuggestion request supports online only. Please use
 * createSuggestionRequestWithLocation:partialTerm for offline.
 * Offline AutoSuggestion request fails with NMARequestErrorNotSupported error.
 *
 * In addition to the requested location this search also considers the
 * current device position as returned by NMAPositioningManager.
 *
 * A search location context must be provided by setting a search location or
 * a search area or a bounding map viewport. Failing to set a location context will
 * result in an error NMARequestErrorInvalidParameter when executing the request.
 *
 * Response items with `NMAAutoSuggestTypeQuery` type are not bounded to the provided search
 * location. If it is not needed to have such items in response, use `resultType` parameter to
 * include/exclude certain item types, e.g. do not include `NMAPlacesAutoSuggestionResultQuery`
 * in this case.
 *
 * @param location A `NMAGeoCoordinates` representing the query location context
 * @param partialTerm An NSString specifying the partial search term
 * @param resultType An `NMAPlacesAutoSuggestionResultType` used to restrict the AutoSuggestion response
 *
 * @return The `NMAAutoSuggestionRequest` if the location is valid, nil otherwise
 */
- (nullable NMAAutoSuggestionRequest *)createAutoSuggestionRequestWithLocation:(nullable NMAGeoCoordinates *)location
                                                                   partialTerm:(nullable NSString *)partialTerm
                                                                    resultType:(NMAPlacesAutoSuggestionResultType)resultType
NS_SWIFT_NAME(createAutoSuggestionRequest(location:partialTerm:resultType:));

/**
 * Creates a `NMAAutoSuggestionRequest` request to return lists of suggested search terms, instant results and
 * refined search links related to a specified location context, partial search term and
 * auto suggestion result types.
 *
 * Note that this AutoSuggestion request supports online only. Please use
 * createSuggestionRequestWithLocation:partialTerm for offline.
 * Offline AutoSuggestion request fails with NMARequestErrorNotSupported error.
 *
 * In addition to the requested location this search also considers the
 * current device position as returned by NMAPositioningManager.
 *
 * A search location context must be provided by setting a search location or
 * a search area or a bounding map viewport. Failing to set a location context will
 * result in an error NMARequestErrorInvalidParameter when executing the request.
 *
 * Response items with `NMAAutoSuggestTypeQuery` type are not bounded to the provided search
 * location. If it is not needed to have such items in response, use `resultType` parameter to
 * include/exclude certain item types, e.g. do not include `NMAPlacesAutoSuggestionResultQuery`
 * in this case.
 *
 * @param location A `NMAGeoCoordinates` representing the query location context
 * @param partialTerm An NSString specifying the partial search term
 * @param resultType An `NMAPlacesAutoSuggestionResultType` used to restrict the AutoSuggestion response
 * @param filter A `NMAAddressFilter` defining constraints used to filter results based on their
                 address.
 *
 * @return The `NMAAutoSuggestionRequest` if the location is valid, nil otherwise
 */
- (nullable NMAAutoSuggestionRequest *)createAutoSuggestionRequestWithLocation:(nullable NMAGeoCoordinates *)location
                                                                   partialTerm:(nullable NSString *)partialTerm
                                                                    resultType:(NMAPlacesAutoSuggestionResultType)resultType
                                                                        filter:(nullable NMAAddressFilter *)filter
NS_SWIFT_NAME(createAutoSuggestionRequest(location:partialTerm:resultType:filter:));

/**
 * Creates a `NMAPlaceRequest` based on a reference identifier and source.
 *
 * The supported sources are "pvid", "sharing", "venues", "venues.content", "venues.venue",
 * "venues.destination" and "building". See resource look-up at documentation at
 * https://developer.here.com/documentation/places/topics_api/resource-lookup.html
 *
 * For "sharing" use cases the referenceIdentifier argument to use is the last path
 * segment of the URL returned by NMAPlace#viewUrl. For example if the URL is
 * "http://here.com/p/I_AM_AN_IDENTIFIER" then the referenceIdentifier is "I_AM_AN_IDENTIFIER".
 * The source would be `NMAPlacesSourceSharing`. For example:
 * \code
 *     NMAPlaceRequest* request = [[NMAPlaces sharedPlaces]
 *         createLookupRequestWithReferenceIdentifier:@"I_AM_AN_IDENTIFIER"
 *                                           inSource:NMAPlacesSourceSharing];
 * \endcode
 *
 * For "venues" use cases the referenceIdentifier can be obtained from the Venues API
 * (e.g. "DM_7171" for the "Alexa Shopping Center") and the source would be
 * `NMAPlacesSourceVenuesVenue`. For example:
 * \code
 * NMAPlaceRequest* request = [[NMAPlaces sharedPlaces]
 *     createLookupRequestWithReferenceIdentifier:@"DM_7171"
 *                                       inSource:NMAPlacesSourceVenuesVenue];
 * \endcode
 *
 * @param referenceIdentifier The reference identifier of the requested NMAPlace in a
 *                            specified source (e.g. Core POI, `Venue`).
 * @param source The NSString of the source in lower case (for examle pvid).
 * @return The `NMAPlaceRequest` if the reference identifier is valid, nil otherwise
 */
- (nullable NMAPlaceRequest *)createLookupRequestWithReferenceIdentifier:(nullable NSString *)referenceIdentifier
                                                                inSource:(nullable NSString *)source
NS_SWIFT_NAME(createLookupRequest(referenceIdentifier:source:));

/**
 * Return the localized top level categories for Places Search.
 *
 * User can manually refresh the categories with refreshTopLevelCategoriesWithCompletion:
 *
 * Note that the list of categories is cached. The update request to Places backend
 * is made periodically and when device locale is changed. If there is no cache
 * or cache is being updated nil is returned. User should try again later.
 *
 * @return An NSArray of localized NMACategory if available, nil otherwise
 */
- (nullable NSArray<NMACategory *> *)topLevelCategories;

/**
 * Refresh the localized top level categories for Places Search.
 */
- (void)refreshTopLevelCategoriesWithCompletion:(nullable NMAPlacesCategoriesCompletionBlock)completionBlock
NS_SWIFT_NAME(refreshTopLevelCategories(_:));

@end
