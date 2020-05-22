/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAMapTileLayer.h"


/**
 * A raster tile layer that displays historical traffic patterns for
 * a specific time of day and day of the week.
 */
@interface NMAHistoricalTrafficTileLayer : NMAMapTileLayer<NMAMapTileLayerDataSource>

/**
 * Initializes a historical traffic tile layer for a specific day,
 * hour and minute.
 *
 * The day/week/hour requested is interpreted as local to the current map
 * viewport. For example, if you specify Tuesday 17:30 and the map is showing
 * Berlin you are seeing historical traffic for Tuesdays at 17:30 local time
 * in Berlin. This is regardless of the device’s current locale, current location,
 * or current time.
 *
 * This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * @param weekDay the day of the week, where Sunday is 1 and Saturday is 7.
 * @param hour the hour during the day in the range [0, 23].
 * @param minute the minute the range [0, 59].
 *
 * @note If any of the input parameters are invalid, this method will return nil.
 *
 * @note Calling the default [NMAHistoricalTrafficTileLayer init] method will call
 * this method with the current local day/hour/minute values.
 */
- (nullable instancetype)initForWeekDay:(NSInteger)weekDay hour:(NSInteger)hour minute:(NSInteger)minute
NS_DESIGNATED_INITIALIZER NS_SWIFT_NAME(init(weekDay:hour:minute:));

/**
 * Initializes a historical traffic tile layer for the current day, hour, minute
 *
 * Returns nil if access to this operation is denied.
 * Contact your HERE representative for more information.
 */
- (null_unspecified instancetype)init;

@end
