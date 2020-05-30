/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMATypes.h"

/**
 * NMAMapTileRequest status
 */
typedef NS_ENUM(NSUInteger, NMAMapTileRequestStatus) {
    NMAMapTileRequestStatusUnitialized,
    NMAMapTileRequestStatusPending,
    NMAMapTileRequestStatusFailed,
    NMAMapTileRequestStatusComplete
};


/**
 * Represents a request for tile bitmap data.
 *
 * NMAMapTileRequest encapsulates a memory buffer for the bitmap data and a request status.
 * It is important that you write exactly bytesLength bytes into the bytesPtr and only set
 * status after the write is complete.
 */
@interface NMAMapTileRequest : NSObject

/**
 * Returns a memory buffer for you to copy bitmap data into.
 *
 * If you are going to copy data to bytesPtr directly via memcpy or other
 * low level functions make sure you copy exactly bytesLength number of
 * bytes.
 *
 * nil will be returned if memory cannot be allocated to hold the bitmap
 * data.
 */
@property (nonatomic, readonly, nullable) void *bytesPtr;

/**
 * The length of the tile bitmap data buffer in bytes.
 */
@property (nonatomic, readonly) int bytesLength;

/**
 * NMAMapTileRequest status.
 *
 * This must be set to NMAMapTileRequestStatusFailed or
 * NMAMapTileRequestStatusComplete when you deem the request complete.
 *
 * status may only be set NMAMapTileRequestStatusFailed or NMAMapTileRequestStatusComplete
 * precisely once and attempts to set the status to other values will be ignored.
 *
 * If the request is set to NMAMapTileRequestStatusComplete the framework will begin reading
 * the bitmap data stored in bytesPtr immedidately so only set to NMAMapTileRequestStatusComplete
 * after you have finished writing the bitmap data.
 *
 * If the request is set to NMAMapTileRequestStatusFailed the framework will repeatedly ask for
 * tile data again via NMAMapTileLayerDataSource#mapTileLayer:requestDataForTileAtX: until the
 * request is completed with NMAMapTileRequestStatusComplete. If the tile data cannot be made
 * available then return NO from NMAMapTileLayerDataSource#mapTileLayer:hasTileAtX: to avoid
 * endless callbacks.
 */
@property (nonatomic) NMAMapTileRequestStatus status;

/**
 * Copies tile bitmap data from an NSData instance to the bytesPtr property.
 *
 * This is equivalent to writing to bytesPtr directly.
 *
 * @param tileData NSData instance containing tile bitmap data. Ensure the length of tileData
 *                 matches bytesLength.
 *
 * @return YES if the data was copied. NO if tileData is the wrong length
 *         or if memory allocation fails.
 */
- (BOOL)getBytesFromData:(NSData * _Nonnull)tileData
NS_SWIFT_NAME(getBytes(from:));

@end
