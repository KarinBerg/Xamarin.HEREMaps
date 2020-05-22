/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * Represents values describing public transport routing options that can be used to enforce
 * special conditions on a calculated route.
 */
typedef NS_OPTIONS(NSUInteger, NMATransitRoutingOption) {
    /**
     * The routing engine will avoid public bus transport.
     */
    NMATransitRoutingOptionAvoidPublicBus          = 1 << 0,

    /**
     * The routing engine will avoid tourist bus.
     */
    NMATransitRoutingOptionAvoidTouristicBus       = 1 << 1,

    /**
     * The routing engine will avoid intercity bus.
     */
    NMATransitRoutingOptionAvoidIntercityBus       = 1 << 2,

    /**
     * The routing engine will avoid express bus.
     */
    NMATransitRoutingOptionAvoidExpressBus         = 1 << 3,

    /**
     * The routing engine will avoid metro rail.
     */
    NMATransitRoutingOptionAvoidMetroRail          = 1 << 4,

    /**
     * The routing engine will avoid light rail.
     */
    NMATransitRoutingOptionAvoidLightRail          = 1 << 5,

    /**
     * The routing engine will avoid regional rail.
     */
    NMATransitRoutingOptionAvoidRegionalRail       = 1 << 6,

    /**
     * The routing engine will avoid regional train.
     */
    NMATransitRoutingOptionAvoidRegionalTrain      = 1 << 7,

    /**
     * The routing engine will avoid intercity train.
     */
    NMATransitRoutingOptionAvoidIntercityTrain     = 1 << 8,

    /**
     * The routing engine will avoid high speed train.
     */
    NMATransitRoutingOptionAvoidHighSpeedTrain     = 1 << 9,

    /**
     * The routing engine will avoid mono rail.
     */
    NMATransitRoutingOptionAvoidMonoRail           = 1 << 10,

    /**
     * The routing engine will avoid aerial.
     */
    NMATransitRoutingOptionAvoidAerial             = 1 << 11,

    /**
     * The routing engine will avoid inclined.
     */
    NMATransitRoutingOptionAvoidInclined           = 1 << 12,

    /**
     * The routing engine will avoid boat.
     */
    NMATransitRoutingOptionAvoidWater              = 1 << 13
};
