/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoBoundingBox;
@class NMAGeoCoordinates;
@class NMAImage;
@class NMARoute;
@class NMARoadElement;


/**
 * A block used to complete traffic event data requests.
 */
typedef void (^NMATrafficEventCompletionBlock)(void);

/**
 * The severity levels of a traffic event.
 *
 * See also `NMATrafficEvent::severity`
 */
typedef NS_ENUM(NSUInteger, NMATrafficEventSeverity) {
    NMATrafficEventSeverityUndefined,
    NMATrafficEventSeverityNormal,
    NMATrafficEventSeverityHigh,
    NMATrafficEventSeverityVeryHigh,
    NMATrafficEventSeverityBlocking
};


/**
 * NMATrafficEvent represents a real-world traffic event such as
 * an accident or road work.
 *
 * @note Not all traffic events will have complete information available,
 * and some information may not be available immediately. If a property
 * returns nil, it should be checked again after some time.
 *
 * @note Traffic data may become stale over time. The valid property should
 * be checked to determine if the traffic event is active and up-to-date.
 */
@interface NMATrafficEvent : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Indicates whether the traffic event is valid at the current time.
 *
 * A traffic event is considered valid if it applies now, i.e. it does not occur
 * in the past or future.
 */
@property (nonatomic, readonly, getter = isValid) BOOL valid;

/**
 * Indicates whether the traffic event is visible at the current time.
 *
 * A traffic event is visible if it applies now or will apply in the future.
 */
@property (nonatomic, readonly) BOOL isVisible;

/**
 * Indicates whether the traffic event is reroutable.
 */
@property (nonatomic, readonly) BOOL isReroutable;

/**
 * Indicates whether the traffic event is a flow event. Flow events are shown
 * as colored lines on road segments.
 */
@property (nonatomic, readonly) BOOL isFlow;

/**
 * Indicates whether the traffic event is an incident event. Incident events are
 * shown as icons on the map.
 */
@property (nonatomic, readonly) BOOL isIncident;

/**
 * Indicates the severity of the traffic event, from "Normal" to "Blocking".
 *
 * See also `NMATrafficEventSeverity`
 */
@property (nonatomic, readonly) NMATrafficEventSeverity severity;

/**
 * The penalty value associated with the traffic event.
 *
 * Penalty values are on the range [0, 100], with 0 being no penalty and 100
 * being the maximum penalty.
 */
@property (nonatomic, readonly) NSInteger penalty;

/**
 * Gets the short text (category) of this event.
 *
 * The default possible return values are "CLOSURE", "ROADWORKS", "ACCIDENT",
 * "CONGESTION", "OTHER", "FLOW". The text is NOT localized.
 *
 * @note The possible return values are configured in the traffic.xml file.
 * For most customers the default values should be used. Do not attempt to
 * modify traffic.xml without contacting your HERE representative.
 */
@property (nonatomic, readonly, nullable) NSString *shortText;

/**
 * A localized description of the traffic event.
 *
 * @note The description of an event may not be immediately available. If
 * nil is returned, this property should be checked again after some time.
 */
@property (nonatomic, readonly, nullable) NSString *description;

/**
 * A comma-separated list of streets affected by the traffic event.
 *
 * This property may be nil if the information is not yet available. Reading this
 * value will automatically request the necessary information, or you may use the
 * getAffectedStreetsWithCompletion: method to request the information and be
 * notified when it is available.
 *
 * @note The order of streets in the list is not significant.
 */
@property (nonatomic, readonly, nullable) NSString *affectedStreets;

/**
 * Asynchronously requests the affected streets information for this traffic event
 * and executes a block when the request completes.
 *
 * If the requested information is not received after a time limit, the completion
 * block will be executed and the affectedStreets property will still be nil.
 */
- (void)getAffectedStreetsWithCompletion:(nonnull NMATrafficEventCompletionBlock)completion;

/**
 * The street at the beginning of the traffic event.
 *
 * This property may be nil if the information is not yet available. Reading this
 * value will automatically request the necessary information, or you may use the
 * getFirstAffectedStreetWithCompletion: method to request the information and be
 * notified when it is available.
 */
@property (nonatomic, readonly, nullable) NSString *firstAffectedStreet;

/**
 * Asynchronously requests the first affected street information for this traffic
 * event and executes a block when the request completes.
 *
 * If the requested information is not received after a time limit, the completion
 * block will be executed and the firstAffectedStreet property will still be nil.
 */
- (void)getFirstAffectedStreetWithCompletion:(nonnull NMATrafficEventCompletionBlock)completion;

/**
 * A comma-separated list of streets forming the intersection where
 * the traffic event starts.
 *
 * This property may be nil if the information is not yet available. Reading this
 * value will automatically request the necessary information, or you may use the
 * getStartingStreetsWithCompletion: method to request the information and be
 * notified when it is available.
 */
@property (nonatomic, readonly, nullable) NSString *startingStreets;

/**
 * Asynchronously requests the starting streets information for this traffic event
 * and executes a block when the request completes.
 *
 * If the requested information is not received after a time limit, the completion
 * block will be executed and the startingStreets property will still be nil.
 */
- (void)getStartingStreetsWithCompletion:(nonnull NMATrafficEventCompletionBlock)completion;

/**
 * A comma-separated list of streets forming the intersection where
 * the traffic event ends.
 *
 * This property may be nil if the information is not yet available. Reading this
 * value will automatically request the necessary information, or you may use the
 * getEndingStreetsWithCompletion: method to request the information and be
 * notified when it is available.
 */
@property (nonatomic, readonly, nullable) NSString *endingStreets;

/**
 * Asynchronously requests the ending streets information for this traffic event
 * and executes a block when the request completes.
 *
 * If the requested information is not received after a time limit, the completion
 * block will be executed and the endingStreets property will still be nil.
 */
- (void)getEndingStreetsWithCompletion:(nonnull NMATrafficEventCompletionBlock)completion;

/**
 * The geographical area affected by the traffic event.
 */
@property (nonatomic, readonly, nullable) NMAGeoBoundingBox *affectedArea;

/**
 * The affected length of the traffic event, in meters.
 *
 * @note Will contain a negative value if the length is unavailable.
 */
@property (nonatomic, readonly) NSInteger length;

/**
 * The speed limit in km/h of roads affected by the traffic event.
 *
 * @note Will contain a negative value if the speed limit is unavailable.
 */
@property (nonatomic, readonly) NSInteger speedLimit;

/**
 * The estimated speed in km/h of traffic moving through the event.
 *
 * @note Will contain a negative value if the traffic speed is unavailable.
 */
@property (nonatomic, readonly) NSInteger trafficSpeed;

/**
 * An icon represeting the traffic event on a route.
 *
 * @note Will be nil if the icon is not available.
 */
@property (nonatomic, readonly, nullable) NMAImage *iconOnRoute;

/**
 * An icon representing the traffic event off a route.
 */
@property (nonatomic, readonly, nullable) NMAImage *iconOffRoute;

/**
 * The time at which the traffic event became active.
 *
 * @note Will be nil if unavailable.
 */
@property (nonatomic, readonly, nonnull) NSDate *activationDate;

/**
 * The time at which the traffic event was last updated.
 *
 * @note Will be nil if unavailable.
 */
@property (nonatomic, readonly, nonnull) NSDate *updateDate;

/**
 * The road elements affected by the traffic event.
 *
 * @note Returns empty array if there are no affected elements
 */
@property (nonatomic, readonly, nonnull) NSArray<NMARoadElement *> *affectedRoadElements;

/**
 * The distance in meters between the traffic event and the specified
 * NMAGeoCoordinates.
 *
 * @return The distance to the traffic event, or a negative value if the distance
 * could not be determined.
 */
- (NSUInteger)distanceToGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates;

/**
 * Indicates whether the traffic event is on the given route.
 */
- (BOOL)isOnRoute:(nonnull NMARoute *)route
NS_SWIFT_NAME(isOnRoute(_:));

@end
