/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */



/**
 * Represents a slope data point.
 */
@interface NMAEHSlopeDataPoint : NSObject

/**
 * Represents the normalized position on the link,
 * where 0.0 represents the start of the link and 1.0 represents the end of the link.
 */
@property (nonatomic) double relativePositionOnLink;

/**
 * Represents the slope value. It can be a positive or negative infinity value in case
 * of a slope inclined at an angle greater than 45 degrees.
 */
@property (nonatomic) double slopePercent;

@end
