/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>



/**
 * Represents a set of consumption parameters.
 *
 * This class stores information about consumption parameters of vehicle. Consumption parameters are
 * used for consumption calculation.
 *
 * @note Using the default initializer will return a consumption parameters object containing
 * default values which can be used for general purpose testing.
 *
 * IMPORTANT: Consumption calculation is a Beta feature. The related classes and
 * methods are subject to change without notice.
 */
@interface NMARouteConsumptionParameters : NSObject

/**
 * Initializes an NMARouteConsumptionParameters instance
 */
- (nonnull instancetype)init;

/**
 * Ascent multiplier models capacity expenditure during ascent in capacity units per meter
 * of ascent. A higher value corresponds to greater capacity expenditure while driving up-hill.
 */
@property (nonatomic, assign) double ascentMultiplier;

/**
 * Descent multiplier is models capactiy gained during descent in capacity units per meter
 * of descent. A higher value corresponds to greater capacity gain while driving down-hill.
 */
@property (nonatomic, assign) double descentMutiplier;

/**
 * Capacity expenditure while turning in capacity units per second of travel time. A higher
 * value corresponds to greater capacity expenditure while the vehicle is turning.
 */
@property (nonatomic, assign) double turnTimeMultiplier;

/**
 * During speed up this parameter is used to model capacity expenditure in capacity units
 * per km/h^2 of acceleration. A higher value corresponds to greater capacity expenditure
 * while the vehicle is accelerating.
 */
@property (nonatomic, assign) double accelerationMultiplier;

/**
 * During slowdown this parameter is used to model capacity gain in capacity units per km/h^2
 * of deceleration. A higher value corresponds to greater capacity gain while the vehicle is
 * decelerating.
 */
@property (nonatomic, assign) double decelartionMultiplier;

/**
 * Sets Auxiliary consumption per second.
 * Auxiliary consumption is used to account for the consumption by items such as lights,
 * air conditioner, or stereo. A higher value corresponds to greater capacity expenditure
 * over time.
 */
@property (nonatomic, assign) double auxiliaryConsumption;

/**
 * Specifies consumption per meter according to travel speeds.
 *
 * Setting only this property is sufficient to perform basic consumption calculation.
 *
 * This dictionary is made up of keys representing the speed (in km/h) and values
 * representing the consumption per meter in the capacity unit.
 *
 * Consider a simple consumption table for a sample electric vehicle where the consumption
 * unit is kilowatt hours (kWh):
 *
 * - 0 - 30 km/h - 38.82 kWh
 *
 * - 31 - 90 km/h - 18.20 kWh
 *
 * - More than 90 km/h    - 27.41 kWh
 *
 * The upper bounds on the speed ranges should be passed as the dictionary keys, while the
 * corresponding consumption per meter should be passed as the dictionary values:
 *
 * \code
 * \endcode
 *
 * @note Default values are assigned when the object is instantiated.
 */
@property (nonatomic, nonnull) NSDictionary<NSNumber *, NSNumber *> * consumptionSpeed;

/**
 * Enables/disables "high speed consumption" mode.
 *
 * An NMARoadElement within a route satisfies "high speed consumption" mode conditions when it:
 *
 * - is a highway;
 *
 * - has no speed limit;
 *
 * - has no time-aware speed limit;
 *
 * - has no dynamic speed limit;
 *
 * - has free flow speed above threshold highSpeedConsumptionThresholdKmh.
 *
 * When "high speed consumption" mode is enabled and NMARoadElement satisfies its conditions, then
 * consumption for this NMARoadElement is calculated not based on its free flow speed, but based on the
 * highest consumption provided by consumptionSpeed.
 *
 * The idea is to better predict consumption for drivers going on considerably higher speed than
 * free flow values, eg. in sport mode.
 * Default value is NO.
 */
@property (nonatomic, assign, getter= isHighSpeedConsumptionEnabled) BOOL highSpeedConsumptionEnabled;

/**
 * Sets free flow speed threshold [kmh] for a NMARoadElement to satisfy "high speed consumption"
 * conditions. Default value is 255. If the value is more than 255, it is capped at 255.
 */
@property (nonatomic, assign) NSUInteger highSpeedConsumptionThresholdKmh;

/**
 * Sets consumption per meter for different travel speeds for heavy traffic. The exact consumption
 * per meter that is used will be an interpolated value between the standard consumption for speed
 * and the traffic consumption for speed, depending on the amount of traffic along each part of the
 * route. The interpolation can be configured with the `trafficScales` property.
 *
 * @note This is an advanced consumption calculation feature. For more information, please contact
 * your HERE representative.
 *
 * This dictionary is made up of keys representing the speed (in km/h) and values representing the
 * consumption per meter in the capacity unit. See the
 * `NMARouteConsumptionParameters#consumptionSpeed` property for more details on
 * how the values should be filled in.
 */
@property (nonatomic, nonnull) NSDictionary<NSNumber *, NSNumber *> * trafficSpeed;

/**
 * Defines the scale of consumption table between free-flow and heavy traffic condition.
 *
 * Scale will be used when calculating consumption for a segment that contains traffic information.
 * Setting this scale allows the definition of how the ratio between the speed parameters (see the
 * `NMARouteConsumptionParameters.consumptionSpeed` property) and traffic speed
 * parameters (see the `NMARouteConsumptionParameters.trafficSpeed` property) influence
 * the consumption.
 *
 * @note This is an advanced consumption calculation feature. For more information, please contact
 * your HERE representative.
 *
 * This dictionary is made up of keys representing the traffic value (calculated as 1 - traffic
 * speed/free-flow speed) and values representing the interpolation point between free-flow
 * consumption and traffic consumption for the traffic speed.
 */
@property (nonatomic, nonnull) NSDictionary<NSNumber *, NSNumber *> * trafficScales;

@end
