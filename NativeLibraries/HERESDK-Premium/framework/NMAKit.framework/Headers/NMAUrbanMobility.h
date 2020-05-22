/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * The Urban Mobility group provides classes, callbacks, and enumerations
 * that can be used to enable Urban Mobility functionality such as
 * searching for nearby transit stations and requesting departure boards.
 *
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * Key classes in this group are:
 * `NMAUrbanMobilityRequestManager`,
 * `NMAUrbanMobilityStationSearchRequest`,
 * `NMAUrbanMobilityDepartureBoardRequest`,
 * `NMAUrbanMobilityMultiBoardRequest`,
 * `NMAUrbanMobilityCitySearchRequest`,
 * `NMAUrbanMobilityCityCoverageRequest`,
 * `NMAUrbanMobilityNearbyCoverageRequest`
 */

/**
 * This constant value is set for Urban Mobility property that is not available from backend server.
 *
 * DEPRECATED As of SDK 3.8.
 */
FOUNDATION_EXPORT NSUInteger const NMAUrbanMobilityValueNotAvailable DEPRECATED_ATTRIBUTE;


/**
 * This enum defines Urban Mobility transport type (means of transport).
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityTransportType) {
    /** Highspeed train */
    NMAUrbanMobilityTransportTypeHighspeedTrain      = 0,

    /** Intercity train */
    NMAUrbanMobilityTransportTypeIntercityTrain      = 1,

    /** Interregional train */
    NMAUrbanMobilityTransportTypeInterregionalTrain  = 2,

    /** Regional train */
    NMAUrbanMobilityTransportTypeRegionalTrain       = 3,

    /** City train */
    NMAUrbanMobilityTransportTypeCityTrain           = 4,

    /** Bus */
    NMAUrbanMobilityTransportTypeBus                 = 5,

    /** Ferry */
    NMAUrbanMobilityTransportTypeFerry               = 6,

    /** Subway */
    NMAUrbanMobilityTransportTypeSubway              = 7,

    /** Tram */
    NMAUrbanMobilityTransportTypeTram                = 8,

    /** Ordered services/Private buses */
    NMAUrbanMobilityTransportTypePrivateBus          = 9,

    /** Inclined */
    NMAUrbanMobilityTransportTypeInclined            = 10,

    /** Aerial */
    NMAUrbanMobilityTransportTypeAerial              = 11,

    /** Rapid bus */
    NMAUrbanMobilityTransportTypeRapidBus            = 12,

    /** Monorail */
    NMAUrbanMobilityTransportTypeMonorail            = 13,

    /** Flight */
    NMAUrbanMobilityTransportTypeFlight              = 14,

    /** Unknown */
    NMAUrbanMobilityTransportTypeUnknown             = 15,

    /** Use bike */
    NMAUrbanMobilityTransportTypeBike                = 17,

    /** Use bike share */
    NMAUrbanMobilityTransportTypeBikeShare           = 18,

    /** Use walk */
    NMAUrbanMobilityTransportTypeWalk                = 20,

    /** Use car */
    NMAUrbanMobilityTransportTypeCar                 = 21,

    /** Use car share */
    NMAUrbanMobilityTransportTypeCarShare            = 22,

    /** Use taxi */
    NMAUrbanMobilityTransportTypeTaxi                = 23,

    /** Undefined transport type */
    NMAUrbanMobilityTransportTypeUndefined           = 24

} DEPRECATED_ATTRIBUTE;

/**
 * This enum defines Urban Mobility operation errors.
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityError) {
    /** No error. */
    NMAUrbanMobilityErrorNone                        = 0,

    /** Application is currently offline. */
    NMAUrbanMobilityErrorOffline                     = 1,

    /** Backend returned bad HTTP response. */
    NMAUrbanMobilityErrorBadResponseCode             = 2,

    /** Backend returned malformed response. */
    NMAUrbanMobilityErrorMalformedResponse           = 3,

    /** Unknown error occurred. */
    NMAUrbanMobilityErrorUnknown                     = 4,

    /** Credentials which were sent to the backend server were not recognised as valid. */
    NMAUrbanMobilityErrorUnauthorized                = 5,

    /** No coverage in this region/area. */
    NMAUrbanMobilityErrorNoCoverage                  = 6,

    /** Backend did not return any response. */
    NMAUrbanMobilityErrorNoResponse                  = 7,

    /** No search matches were found. */
    NMAUrbanMobilityErrorNotFound                    = 8,

    /** Invalid request parameters were provided. */
    NMAUrbanMobilityErrorInvalidParameters           = 9,

    /** Unexpected error occurred. */
    NMAUrbanMobilityErrorUnexpected                  = 10,

    /** API is not available in this region/area. */
    NMAUrbanMobilityErrorUnavailableAPI              = 11,

    /** Given period is invalid. */
    NMAUrbanMobilityErrorInvalidPeriod               = 12,

    /** Routing was not possible. */
    NMAUrbanMobilityErrorRoutingNotPossible          = 13,

    /** The start and destination locations are too close to each other. */
    NMAUrbanMobilityErrorStartDestinationTooClose    = 14,

    /** No stations were found near the given address. */
    NMAUrbanMobilityErrorNoStationNearby             = 15,

    /** There was an error due to another request already being processed. */
    NMAUrbanMobilityErrorInvalidOperation            = 16,

    /** There was insufficient memory to complete the request. */
    NMAUrbanMobilityErrorOutOfMemory                 = 17,

    /** The request was cancelled. */
    NMAUrbanMobilityErrorRoutingCancelled            = 18,

    /** A route was found but is invalid because it makes use of roads that were disabled by #NMARoutingOption */
    NMAUrbanMobilityErrorViolatesOptions             = 19,

    /** The route cannot be calculated because there is not enough local map data to perform route calculation. Client can re-download map data and calculate route again. */
    NMAUrbanMobilityErrorInsufficientMapData         = 20,

    /** The backend service was unavailable. Try again later. */
    NMAUrbanMobilityErrorServiceUnavailable          = 21,

    /** There was a network communications error. */
    NMAUrbanMobilityErrorNetworkCommunication        = 22,

    /** Access to this operation is denied. Contact your HERE representative for more information. */
    NMAUrbanMobilityErrorOperationNotAllowed         = 23

} DEPRECATED_ATTRIBUTE;

/**
 * This enum defines availability options of a transit feature.
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityFeatureAvailability) {
    /** Feature availability is unknown. */
    NMAUrbanMobilityFeatureAvailabilityUnknown      = 0,

    /** Feature is available. */
    NMAUrbanMobilityFeatureAvailable                = 1,

    /** Feature is not available. */
    NMAUrbanMobilityFeatureNotAvailable             = 2
} DEPRECATED_ATTRIBUTE;

