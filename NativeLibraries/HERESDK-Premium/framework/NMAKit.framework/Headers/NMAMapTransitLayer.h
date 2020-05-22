/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */



/**
 * Represents a NMAMapView layer that can display any combination
 * of transit stops, accesses, and lines (including none)
 */
@interface NMAMapTransitLayer : NSObject

/**
 * Highlights a specified array of transit lines. Previously
 * highlighted lines remain highlighted until clearTransitHighlights
 * is called to clear all highlighted objects.
 *
 * @param uniqueIds The unique IDs of the translit lines to be highlighted.
 */
- (void)highlightTransitLinesFromUniqueIds:(nonnull NSArray<NSString *> *)uniqueIds
NS_SWIFT_NAME(highlightTransitLines(_:));

/**
 * Highlights a specified array of transit stops. Previously
 * highlighted stops remain highlighted until clearTransitHighlights
 * is called to clear all highlighted objects.
 *
 * @param uniqueIds The unique IDs of the translit stops to be highlighted.
 */
- (void)highlightTransitStopsFromUniqueIds:(nonnull NSArray<NSString *> *)uniqueIds
NS_SWIFT_NAME(highlightTransitStops(_:));

/**
 * Highlights a specified array of transit accesses. Previously
 * highlighted accesses remain highlighted until clearTransitHighlights
 * is called to clear all highlighted objects.
 *
 * @param uniqueIds The unique IDs of the translit accesses to be highlighted.
 */
- (void)highlightTransitAccessesFromUniqueIds:(nonnull
                                               NSArray<NSString *> *)uniqueIds
NS_SWIFT_NAME(highlightTransitAccesses(_:));

/**
 * Highlights a specified array of transit line segments. Previously
 * highlighted line segments remain highlighted until clearTransitHighlights
 * is called to clear all highlighted objects.
 *
 * @param uniqueIds The unique IDs of the translit line segments to be highlighted.
 */
- (void)highlightTransitLineSegmentsFromUniqueIds:(nonnull NSArray<NSString *> *)uniqueIds
NS_SWIFT_NAME(highlightTransitLineSegments(_:));

/**
 * Clears all transits layer objects from highlighted state to
 * non-highlighted state.
 */
- (void)clearTransitHighlights;

@end
