/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARequest.h"


/**
 *
 * Represents a request to retrieve a list of suggested search terms, instant results and refined
 * search links related to a specified location context and partial search term.
 *
 * This NMAAutoSuggestionRequest supports online only. Please use
 * `NMAPlaces::createSuggestionRequestWithLocation:partialTerm:` for offline.
 */
@interface NMAAutoSuggestionRequest : NMARequest

/**
 * The text format of the request results.
 *
 * @note The default value is NMATextFormatHTML.
 */
@property (nonatomic) NMATextFormat textFormat;

@end
