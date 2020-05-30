/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * The Navigation group includes category and enumerations
 * related to voice announcement.
 * The key class to this group is `NMANavigationManager`.
 */

#import "NMANavigationManager.h"

/**
 * Represents the type of road. Used to configure voice prompts strategy.
 */
typedef NS_ENUM(NSUInteger, NMANavigationRoadType) {
    /** Non highway, regular road. */
    NMANavigationRoadNonHighway,
    /** Highway road. */
    NMANavigationRoadHighway
};

/**
 * Represents the type of voice command. Enum used to configure voice guidance.
 */
typedef NS_ENUM(NSUInteger, NMANavigationVoicePromptType) {
    /** Maneuver announcement (i.e. first call) */
    NMANavigationVoicePromptAnnouncement,
    /** First reminder (i.e. second call) */
    NMANavigationVoicePromptReminder1,
    /** Second reminder (i.e. third call) */
    NMANavigationVoicePromptReminder2,
    /** Command right before maneuver (i.e. last call) */
    NMANavigationVoicePromptCommand
};

/**
 * Specifies at what times voice guidance prompts are triggered during
 * car navigation. For each upcoming maneuver, an instruction prompt
 * to perform the maneuver is always triggered. In addition, up to three
 * other prompts for performing the maneuver may be triggered, making
 * a total of four possible prompt triggers per maneuver:
 *
 * * ANNOUNCEMENT – announcement of an upcoming maneuver ahead of time
 *
 * * REMINDER 2 – distant reminder, given from quite a distance away from the maneuver
 *
 * * REMINDER 1 – nearby reminder, given when the maneuver is getting close
 *
 * * COMMAND – call for immediate action just before the maneuver
 *
 * A distinction is made according to whether the driver is currently
 * on a non-highway or a highway, as more time is typically needed to allow
 * the driver to react appropriately when driving on a highway.
 *
 * The conditions are evaluated as follows: First the conditions for
 * the trigger COMMAND are tested, then REMINDER 1, REMINDER 2, and
 * finally ANNOUNCEMENT. For each trigger, the distance-based conditions
 * are evaluated first. If these are not met, then the time-based conditions
 * are evaluated. As soon as a condition is met, the corresponding prompt
 * is triggered. Each type of prompt can be triggered automatically
 * at most once per maneuver.
 *
 * @note just first ANNOUNCEMENT is issued immediately
 * no matter what. Even if all parameters of ANNOUNCEMENT have been
 * installed to -1 or any other values.
 *
 * @note If ANNOUNCEMENT has been disabled then neither REMINDER 2 nor
 * REMINDER 1 would be issued, only COMMAND.
 *
 * @note If REMINDER 1 and REMINDER 2 met the same conditions then REMINDER 1
 * is issued, REMINDER 2 won't be issued.
 *
 * @note The distance-based conditions are evaluated first.
 * The time-based second. The time-based condition can be extended to take into
 * consideration either time or distance conditions.
 * See setTimeBasedDistance:toUpcomingManeuverForVoicePromptType:roadType:
 */
@interface NMANavigationManager (NMANavigationManagerVoicePromptOptions)

/**
 * Configures voice guidance rules. Sets minimal distance (in meters)
 * from previous maneuver to announce next maneuver.
 *
 * @param minimumDistance in meters. minimumDistance should be 0 or grater.
 * Negative values, anything < 0 will avoid this rule.
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 */
- (void)            setMinimumDistance:(NSInteger)minimumDistance
fromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                              roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(setMinimumDistance(_:fromPreviousManeuverForVoicePromptType:roadType:));

/**
 * Returns minimal distance from last maneuver to announce next maneuver.
 *
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 *
 * @return minimal distance in meters.
 */
- (NSInteger)minimumDistanceFromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                                                          roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(minimumDistance(fromPreviousManeuverForVoicePromptType:roadType:));

/**
 * Configures voice guidance rules. Sets maximum distance (in meters)
 * from previous maneuver to announce next maneuver.
 *
 * @param maximumDistance in meters. maximumDistance should be 0 or grater.
 * Negative values, anything < 0 will avoid this rule.
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 */
- (void)            setMaximumDistance:(NSInteger)maximumDistance
fromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                              roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(setMaximumDistance(_:fromPreviousManeuverForVoicePromptType:roadType:));

/**
 * Returns maximum distance after previous maneuver to announce next maneuver.
 *
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 *
 * @return maximum distance in meters.
 */
- (NSInteger)maximumDistanceFromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                                                          roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(maximumDistance(fromPreviousManeuverForVoicePromptType:roadType:));

/**
 * Configures voice guidance rules. Sets minimal distance (in meters)
 * to upcoming maneuver to announce it.
 *
 * @param minimumDistance in meters. minimumDistance should be 0 or grater.
 * Negative values, anything < 0 will avoid this rule.
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 */
- (void)          setMinimumDistance:(NSInteger)minimumDistance
toUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                            roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(setMinimumDistance(_:toUpcomingManeuverForVoicePromptType:roadType:));

/**
 * Returns minimal distance before upcoming maneuver to announce it.
 *
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 *
 * @return minimal distance in meters.
 */
- (NSInteger)minimumDistanceToUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                                                        roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(minimumDistance(toUpcomingManeuverForVoicePromptType:roadType:));

/**
 * Configures voice guidance rules. Sets maximum distance (in meters)
 * to upcoming maneuver to announce it.
 *
 * @param maximumDistance in meters. Value should be 0 or grater.
 * Negative values, anything < 0 will avoid this rule.
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 */
- (void)          setMaximumDistance:(NSInteger)maximumDistance
toUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                            roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(setMaximumDistance(_:toUpcomingManeuverForVoicePromptType:roadType:));

/**
 * Returns maximum distance before upcoming maneuver to announce it.
 *
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 *
 * @return maximum distance in meters.
 */
- (NSInteger)maximumDistanceToUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                                                        roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(maximumDistance(toUpcomingManeuverForVoicePromptType:roadType:));

/**
 * Configures voice guidance rules. Sets minimal time (in seconds)
 * from previous maneuver to announce next maneuver.
 *
 * @param minimumTime in seconds. minimumTime should be 0 or grater.
 * Negative values, anything < 0 will avoid this rule.
 * @param voicePromptType type of announcement
 * @param roadType type of road
 */
- (void)        setMinimumTimeInterval:(NSTimeInterval)minimumTime
fromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                              roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(setMinimumTime(_:fromPreviousManeuverForVoicePromptType:roadType:));

/**
 * Returns minimal time from previous maneuver to announce next maneuver.
 *
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 *
 * @return minimal time in seconds.
 */
- (NSTimeInterval)minimumTimeFromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                                                           roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(minimumTime(fromPreviousManeuverForVoicePromptType:roadType:));

/**
 * Configures voice guidance rules. Sets maximum time (in seconds)
 * from previous maneuver to announce next maneuver.
 *
 * @param maximumTime in seconds. maximumTime should be 0 or grater.
 * Negative values, anything < 0 will avoid this rule.
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
  * @param roadType type of road NMANavigationRoadType.
 */
- (void)        setMaximumTimeInterval:(NSTimeInterval)maximumTime
fromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                              roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(setMaximumTime(_:fromPreviousManeuverForVoicePromptType:roadType:));

/**
 * Returns maximum time from previous maneuver to announce next maneuver.
 *
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 *
 * @return maximum time in seconds.
 */
- (NSTimeInterval)maximumTimeFromPreviousManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                                                           roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(maximumTime(fromPreviousManeuverForVoicePromptType:roadType:));

/**
 * Configures voice guidance rules. Sets minimal time (in seconds)
 * to upcoming maneuver to announce it.
 *
 * @param minimumTime in seconds. Value should be 0 or grater.
 * Negative values, anything < 0 will avoid this rule.
 * @param voicePromptType type of announcement
 * @param roadType type of road
 */
- (void)      setMinimumTimeInterval:(NSTimeInterval)minimumTime
toUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                            roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(setMinimumTime(_:toUpcomingManeuverForVoicePromptType:roadType:));

/**
 * Returns minimal time to upcoming maneuver to announce it.
 *
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 *
 * @return minimal time in seconds.
 */
- (NSTimeInterval)minimumTimeToUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                                                         roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(minimumTime(toUpcomingManeuverForVoicePromptType:roadType:));

/**
 * Configures voice guidance rules. Sets maximum time (in seconds)
 * to upcoming maneuver to announce it.
 *
 * @param maximumTime in seconds. Value should be 0 or grater.
 * Negative values, anything < 0 will avoid this rule.
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 */
- (void)      setMaximumTimeInterval:(NSTimeInterval)maximumTime
toUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                            roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(setMaximumTime(_:toUpcomingManeuverForVoicePromptType:roadType:));

/**
 * Returns maximum time to upcoming maneuver to announce it.
 *
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 *
 * @return maximum time in seconds.
 */
- (NSTimeInterval)maximumTimeToUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                                                         roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(maximumTime(toUpcomingManeuverForVoicePromptType:roadType:));

/**
 * Configures voice guidance rules. Sets the time based distance (in meters)
 * before upcoming maneuver.
 *
 * @param distance to upcoming menauver. Values should be 0 or grater.
 * Negative values, anything < 0 will avoid this rule.
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 *
 * @note The distance-based conditions are evaluated first.
 * The time-based second. The time-based condition can be extended to take into
 * consideration either time or distance conditions. That is exactlly what
 * the time based distance option for.
 */
- (void)        setTimeBasedDistance:(NSInteger)distance
toUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                            roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(setTimeBasedDistance(_:toUpcomingManeuverForVoicePromptType:roadType:));

/**
 * Returns time based distance before next maneuver to announce.
 *
 * @param voicePromptType type of announcement NMANavigationVoicePromptType.
 * @param roadType type of road NMANavigationRoadType.
 *
 * @return time based distance in meters
 */
- (NSInteger)timeBasedDistanceToUpcomingManeuverForVoicePromptType:(NMANavigationVoicePromptType)voicePromptType
                                                          roadType:(NMANavigationRoadType)roadType
NS_SWIFT_NAME(timeBasedDistance(toUpcomingManeuverForVoicePromptType:roadType:));

/**
 * Resets all announcment rules back to default values
 */
- (void)resetAnnouncementRules;

@end
