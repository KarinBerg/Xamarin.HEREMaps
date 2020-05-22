-- ----------------------------------------------------------------------------
-- Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
-- All rights reserved.
-- The use of this software is conditional upon having a separate agreement
-- with a HERE company for the use or utilization of this software. In the
-- absence of such agreement, the use of the software is not allowed.
-- ----------------------------------------------------------------------------
--      Authors: Fabian TP Riek, Dirk Huppermann
-- ----------------------------------------------------------------------------
-------------------------------------------------------------------------------
-- Tokens:  (placeholder in the id based sentences, which will be replaced by
--           this script with variables declared above)
-- !DIST!       - Token for Distances
-- !UNIT!       - Token for Unit
-- !STREET!     - Token for Streetname
-- !SIGNPOST!   - Token for Signpost
-- !STREET_2!   - Token for Streetnames in long sentences
-- !SIGNPOST_2! - Token for Signposts in long sentences
-- !EXIT_NO_ROUNDABOUT! - Token for roundabout exit number
-- !ORIENTATION! - Token for heading orientation
-- !PED_TURN_NO! - Token for the pedestrian turn number
-- !SET_AUDIO!  - Token for setting engine to audio mode
-------------------------------------------------------------------------------

local utils = require 'content.utils'
local config = require 'config.init'
local rules = require 'config.rules'
local natural_guidance = require 'natural_guidance'

local actual_rules = config.get_selection_rules(rules)

function get_text_output( )     -- For TTS-Packages
    if output_type == "tts" then
        nonTTS = false
        preparations( )
        -- check if the prompt has valid conditions
        check_prompt_validity( )
        if (is_prompt_valid == true) then
                select_sentence_1( )
            if double_command then
                select_sentence_2( )
            end
        end
        set_result_tts( )
        cleanup( )
        maneuver_1 = nil
        maneuver_2 = nil
    end
end

function get_voicefiles( )      -- For Non-TTS-Packages
    if output_type == "audio" then
        nonTTS = true
        preparations( )
        select_sentence_1( )
        if double_command then
            select_sentence_2( )
        end
        set_result_wave( )
        cleanup( )
        maneuver_1 = nil
        maneuver_2 = nil
    end
end

function preparations( )

    -------------------------------------------------------------------------------
    -- Variables used in this script:
    -------------------------------------------------------------------------------

    cleanup()

    check_voice_guidance_settings()

    init_custom_voice_trigger_table()

    if trigger == "PEDESTRIAN_ANNOUNCEMENT" or trigger == "PEDESTRIAN_COMMAND" then
        guidance_mode = "pedestrian"
    end
    if maneuver_1 == nil then
        maneuver = base_maneuver_table
        maneuver_1 = base_maneuver_table
    elseif maneuver_1.id == "STOPOVER" and voice_settings["announce_stopover"] == false then
        maneuver = base_maneuver_table
        maneuver_1 = base_maneuver_table
    else
        maneuver = maneuver_1
    end
    if maneuver_2 == nil then
        nextManeuver = base_maneuver_table
        maneuver_2 = base_maneuver_table
    elseif maneuver_2.id == "STOPOVER" and voice_settings["announce_stopover"] == false then
        nextManeuver = base_maneuver_table
        maneuver_2 = base_maneuver_table
        maneuver_set_count = 1
    else
        nextManeuver = maneuver_2
    end

    if gps_location == nil then
        gps_location = { ["route"] = "", ["street"] = "", ["fow"] = "" }
    end

    if maneuver.dist_to_unit_string == nil then
        maneuver.dist_to_unit_string = maneuver.dist_to_unit
        nextManeuver.dist_to_unit_string = nextManeuver.dist_to_unit
    end

    check_maneuver_table( maneuver )    -- checking if every value is set in the maneuver tables (prevent nil value errors)
    check_maneuver_table( nextManeuver )

    if ( maneuver_set_count == 2 ) then     -- check for double cmd
        double_command = true
    else
        double_command = false
    end

    dgttsp_rules()

end

function check_maneuver_table( maneuver )
    for k,v in pairs(base_maneuver_table) do
        if maneuver[ k ] == nil or maneuver[ k ] == "" then
            maneuver[ k ] = v
        end
    end

    local selected_element = natural_guidance.select( maneuver, actual_rules, _G.voice_settings )
    if selected_element ~= nil then
        maneuver.ng_type = nil
        maneuver.ng_name = nil
        maneuver.ng_calculated_importance = nil
        maneuver.ng_language = nil
        maneuver.ng_preposition = nil
        maneuver.ng_name_phoneme_nt_sampa = nil
        maneuver.ng_name_phoneme_nt_sampa_lang = nil
        maneuver.extra_string = ""
        maneuver.traffic_light_int = nil

        if selected_element.element_type == "traffic_light" then
            maneuver.ng_type = "TRAFFIC LIGHT"
            maneuver.traffic_light_int = selected_element.count
            maneuver.ng_calculated_importance = selected_element.importance
        elseif selected_element.element_type == "stop_sign" then
            maneuver.ng_type = "STOP SIGN"
            maneuver.ng_calculated_importance = selected_element.importance
        elseif selected_element.element_type == "t-junction" then
            maneuver.extra_string = "EOS"
        else
            maneuver.ng_type = "JUNCTION"
            maneuver.ng_calculated_importance = selected_element.importance
            maneuver.ng_name = selected_element.name
            maneuver.ng_language = selected_element.name_lang or ""
            maneuver.ng_preposition = selected_element.name_preposition
            maneuver.ng_name_phoneme_nt_sampa = selected_element.name_phoneme_nt_sampa
            maneuver.ng_name_phoneme_nt_sampa_lang = selected_element.name_phoneme_nt_sampa_lang
        end
    end
end

-- check if the prompt is valid according to the conditions in which a prompt should be generated
function check_prompt_validity( )
    -- should be used when prompts should not be pronounced
    is_prompt_valid = true

    -- check if the double command prompt should be transformed to a single command
    if ( double_command == true and trigger == "REMINDER2" ) then
        double_command = false
    elseif ( double_command == true and trigger ~= "REMINDER2" and road_class == "STREET" and maneuver_2.dist_to > 210 ) then
        double_command = false
    elseif ( double_command == true and trigger ~= "REMINDER2" and road_class == "HIGHWAY" and maneuver_2.dist_to > 350 ) then
        double_command = false
    end
end

function cleanup( )
    distance_1 = ""              -- Distance in used unit for first command
    usedUnit_1 = ""              -- Unit for first command distance
    tts_street_1 = ""            -- Street name for first command
    tts_signpost_1 = ""          -- Signpost for the signpost place holder 1
    tts_street_2 = ""            -- Street name for the street place holder 2
    tts_signpost_2 = ""          -- Signpost for the signpost place holder 2
--    command_id_1 = ""            -- ID for the first command
--    command_id_2 = ""            -- ID for the second command
    exit_no_roundabout = ""      -- Roundabout exit number
    head_orientation = ""        -- Heading orientation
    ped_turn_no = ""             -- Pedestrian turn number
    tts_exit_number = ""         -- Exit number on highways

    second_cmd_trigger = ""      -- trigger for second cmd

    route_attributes_string = ""  -- route attributes string
end

function expand_dgttsp( input )

    local result = ""
    for token in input:gmatch("([^/]+)") do
        local words = {}

        token = lang_spec_abbr( token )

        words = split_token(token)

        for i = 1, table.getn(words) do
            local rawword = words[i][1]
            local substitutionword = rawword

            -- Check for case-sensitive abbreviations (e.g. AAA -> triple_A)
            if abbr_cs[rawword] ~= nil then
                substitutionword = abbr_cs[rawword]
            end

            local lowercaseword = rawword:lower()

            -- Check for abbreviations which have to be at the beginning (e.g. First "Dr" in "Dr Martin Luther Kng Jr Dr")
            if i == 1 and abbr_begin[lowercaseword] ~= nil then
                substitutionword = abbr_begin[lowercaseword]
            -- Check for abbreviations which have to be at the end (e.g. Second "Dr" in "Dr Martin Luther Kng Jr Dr")
            elseif i == table.getn(words) and abbr_end[lowercaseword] ~= nil then
                substitutionword = abbr_end[lowercaseword]
            -- Check all other abbreviations
            elseif abbr_misc[lowercaseword] ~= nil then
                substitutionword = abbr_misc[lowercaseword]
            end
            if rawword ~= substitutionword then
                words[i][1] = string.gsub(words[i][1], rawword .. "%.?", substitutionword )
            end
        end

        -- re-construct the token based on the components
        token = ""
        for i = 1, table.getn(words) do
            -- replace "." with " " if it does not come after a number
            if ( string.find( words[i][1], "%d+$" ) == nil ) then
                words[i][2] = string.gsub(words[i][2], "%s*%.%s*", " ")
            end
            token = token..words[i][1]..words[i][2]
        end

        if result ~= "" then
            result = result .. " !BREAK! "
        end
        result = result .. token
    end

    return result
end

function clear_result_id()
    result_id = {"0","0","0","0","0","0","0","0"}   -- resetting result_id
end

function select_sentence_1( )

    clear_result_id()

    if trigger == "ROUTE_RECALCULATION" and use_gpswarning then
        set_result_id( 1, "w" ) -- Route recalculation

    elseif ( trigger == "COMMAND" or trigger == "PEDESTRIAN_COMMAND" ) and maneuver.id == "END" then
        set_result_id( 1, "y" ) -- You have reached your destination.
        if maneuver.extra_string == "RIGHT" or maneuver.side_of_destination_side =="RIGHT" then
            set_result_id( 2, "p" ) -- The destination is on your right.
        elseif maneuver.extra_string == "LEFT" or maneuver.side_of_destination_side =="LEFT" then
            set_result_id( 2, "q" ) -- The destination is on your left.
        end

    elseif ( trigger == "COMMAND" or trigger == "PEDESTRIAN_COMMAND" ) and maneuver.id == "STOPOVER" then
        set_result_id( 1, "z" ) -- You have reached a stopover.
        if maneuver.extra_string == "RIGHT" or maneuver.side_of_destination_side =="RIGHT" then
            set_result_id( 2, "r" ) -- The stopover is on your right.
        elseif maneuver.extra_string == "LEFT" or maneuver.side_of_destination_side =="LEFT" then
            set_result_id( 2, "s" ) -- The stopover is on your left.
        end

    elseif ( trigger == "PEDESTRIAN_COMMAND" and nonTTS ) then
        set_result_id( 1, "x" ) -- only one beep sound
        double_command = false

    elseif guidance_mode ~= "pedestrian" then
        process_car_1st_cmd( )  -- CAR NAVI

    elseif not nonTTS then
        process_ped_1st_cmd( )  -- PED Navi

    else
        double_command = false

    end

    command_id_1 = table.concat( result_id, "" )
    filter_double_street_on_street_signpost_combination( )
    sentence_1 = set_result( command_id_1 )

end

function select_sentence_2( )

    clear_result_id()

    if guidance_mode ~= "pedestrian" then
        process_car_2nd_cmd( maneuver, nextManeuver, should_use_signpost, should_use_signpost_next )   -- CAR NAVI
    else
        process_ped_2nd_cmd( nextManeuver ) -- PED Navi
    end

    command_id_2 = table.concat( result_id, "" )
    filter_double_street_on_street_signpost_combination( )
    sentence_2 = set_result( command_id_2 )

end

function process_car_1st_cmd( )

    clear_result_id()

    local handler = cvt_handler_methods[trigger]

    if ( handler and type( handler ) == "function" ) then
        handler()

    elseif trigger == "GPS_SIGNAL_LOST" and use_gpswarning then
        set_result_id( 1, "p" ) -- GPS lost

    elseif trigger == "GPS_SIGNAL_RESTORED" and use_gpswarning then
        set_result_id( 1, "q" ) -- GPS restored

    elseif trigger == "SAFETYSPOT_WARNER" and use_safetyspotwarning then
        if above_speed_limit then
            set_result_id(1, "v" ) -- Safety camera ahead with beep
        else
            set_result_id(1, "x" ) -- only beep
        end

    elseif trigger == "SPEED_WARNER" and use_speedwarning then
        set_result_id( 1, "r" ) -- speeding beep (old: observe speed limit)

    elseif trigger == "TRAFFIC_WARNER" and use_trafficwarning then
        if avoidance_mode == "AUTOMATIC_AVOIDANCE" then
            set_result_id( 1, "s" ) -- Traffic on route, detouring!
        elseif avoidance_mode == "MANUAL_AVOIDANCE" then
            set_result_id( 1, "t" ) -- Traffic on route, wanna detour?
        end

    elseif trigger == "TRAFFIC_DETOUR_FAILED" and use_trafficwarning then
        set_result_id( 1, "u" ) -- Traffic detour failed

    -- Maneuver triggers
    elseif trigger == "COMMAND" then
        process_car_final_command( maneuver, should_use_signpost )

    elseif trigger == "REMINDER1" or trigger == "REMINDER2" then
        process_car_reminders( maneuver, should_use_signpost )

    elseif trigger == "ANNOUNCEMENT" then
        process_car_announcement( maneuver, should_use_signpost )

    end

end

function process_car_2nd_cmd( firstManeuver, secondManeuver, useSignpost, useSignpostNext )

    if second_cmd_trigger == "1" then

        junction_turn, maneuver_command = get_maneuver( "car", secondManeuver )

        if secondManeuver.dist_to <= 30
          and secondManeuver.id ~= "END"
          and secondManeuver.id ~= "ROUNDABOUT"
          and secondManeuver.id ~= "ENTER_ROUNDABOUT"
          and secondManeuver.id ~= "STOPOVER" then
            set_result_id( 1 , "j" )    -- and then immediately
        else
            set_result_id( 1 , "h" )    -- and then
        end

        if secondManeuver.id == "JUNCTION" then

            if right[ secondManeuver.turn ] ~= nil and secondManeuver.exits_right == 1 then
                set_result_id( 4 , "y" )    -- take the second right
            elseif left[ secondManeuver.turn ] ~= nil and secondManeuver.exits_left == 1 then
                set_result_id( 4 , "z" )    -- take the second left
            else
                set_result_id( 4 , junction_turn )
            end

        else
            -- if second maneuver is highway command other than ENTER_HIGHWAY, then rely only on the turn ID
            if highway[ secondManeuver.id ] ~= nil then
                -- if second maneuver is ENTER_HIGHWAY, then ignore the turn ID
                if ( secondManeuver.id == "ENTER_HIGHWAY" or secondManeuver.id == "ENTER_URBAN_HIGHWAY"
                 or secondManeuver.id == "ENTER_HIGHWAY_LEFT" or secondManeuver.id == "ENTER_HIGHWAY_RIGHT" ) then
                    if secondManeuver.turn ~= "UNDEFINED" then
                        junction_turn = nil
                    end
                elseif secondManeuver.turn ~= "UNDEFINED" then
                    maneuver_command = nil
                end
            elseif secondManeuver.id == "ROUNDABOUT"
              or secondManeuver.id == "ENTER_ROUNDABOUT"
              or secondManeuver.id == "EXIT_ROUNDABOUT" then
                junction_turn = nil
            end
            if junction_turn ~= nil then
                set_result_id( 4 , junction_turn )
            end
            if maneuver_command ~= nil then
                set_result_id( 5 , maneuver_command )
            end
            if secondManeuver.id == "ROUNDABOUT" or secondManeuver.id == "ENTER_ROUNDABOUT" then
                roundabout_car( secondManeuver )
            end
        end
        if ( secondManeuver.id == "ENTER_HIGHWAY" or secondManeuver.id == "ENTER_URBAN_HIGHWAY"
         or secondManeuver.id == "ENTER_HIGHWAY_LEFT" or secondManeuver.id == "ENTER_HIGHWAY_RIGHT" ) and not nonTTS then
            tts_street_1, tts_signpost_1 = insert_signpost_enter_hwy( secondManeuver, useSignpostNext )
        elseif secondManeuver.id == "ROUNDABOUT" or secondManeuver.id == "ENTER_ROUNDABOUT" then
            add_route_after_roundabout( secondManeuver, useSignpostNext )
        -- do not add signpost/street/route for END and for STOPOVER prompts
        elseif ( not nonTTS and secondManeuver.id ~= "END" and secondManeuver.id ~= "STOPOVER" ) then
            tts_street_1 = add_street_name_or_route( secondManeuver, useSignpostNext )
        end

    elseif second_cmd_trigger == "2" then
        -- insert route and signpost direction for single commands which are being treated as double command
        set_result_id( 1 , "h" )    -- and then
        junction_turn, maneuver_command = get_maneuver( "car", firstManeuver )
        set_result_id( 4 , maneuver_command )
        if not nonTTS then
            tts_street_1, tts_signpost_1 = insert_signpost_enter_hwy( firstManeuver, useSignpost )
        end

    elseif ( second_cmd_trigger == "3" ) then

        second_command_leave_or_continue_hwy( secondManeuver )

    end

end

function process_ped_1st_cmd( )
    -- Maneuver triggers
    if trigger == "PEDESTRIAN_ANNOUNCEMENT" then
        process_pedestrian_announcement( maneuver )

    elseif trigger == "PEDESTRIAN_COMMAND" then
        process_pedestrian_final_command( maneuver )
    end
end

function process_ped_2nd_cmd( secondManeuver )

    if second_cmd_trigger == "1" then
        junction_turn, maneuver_command = get_maneuver( "pedestrian", secondManeuver )
        distance_1, usedUnit_1 = include_distance ( secondManeuver, false )
        if secondManeuver.id == "ROUNDABOUT" or secondManeuver.id == "ENTER_ROUNDABOUT" then
            roundabout_pedestrian( secondManeuver )
        elseif junction_turn ~= nil and junction_turn ~= "0" then
            set_result_id( 3 , junction_turn )
        else
            set_result_id( 4 , maneuver_command )
        end
    end

end

function dgttsp_rules()
--------------------------------------------------------------------------
-- Rules when to use DGTTSP (dynamically generated TTS prompts)
--------------------------------------------------------------------------

    if road_class == "STREET" then  -- Non Highway

        if ( trigger == "ANNOUNCEMENT" and maneuver_1.dist_to <= 500 ) or
          ( trigger == "REMINDER1") or
          ( trigger == "COMMAND" and maneuver_1.id == "EXIT_ROUNDABOUT" ) then
            should_use_signpost = true
            should_use_signpost_next = false
        elseif ( trigger == "COMMAND" and maneuver_1.id ~= "EXIT_ROUNDABOUT" and double_command ) then
            should_use_signpost = false
            should_use_signpost_next = true
        else
            should_use_signpost = false
            should_use_signpost_next = false
        end

    else                            -- Highway

        if ( trigger == "ANNOUNCEMENT" and  maneuver_1.dist_to <= 650  ) or trigger == "REMINDER1" then
            should_use_signpost = true
            should_use_signpost_next = false

        elseif trigger == "COMMAND" and double_command then
            should_use_signpost = false
            should_use_signpost_next = true
        else
            should_use_signpost = false
            should_use_signpost_next = false
        end

    end

    -- override for u-turns
    if maneuver_1.id == "UTURN" then
         should_use_signpost = false
         should_use_signpost_next = false
    end
    if maneuver_2.id == "UTURN" then
         -- keep as it was should_use_signpost =
         should_use_signpost_next = false
    end
end

function process_car_final_command( maneuver, useSignpost )

    if maneuver.id ~= "ROUNDABOUT"
      and maneuver.id ~= "ENTER_ROUNDABOUT"
      and maneuver.id ~= "DRIVE_TO_NEAREST_ROAD" then
        set_result_id( 1 , "a" )    -- Now
        maneuver_car( maneuver, useSignpost )
    else
        maneuver_car( maneuver, useSignpost )
    end

end

function process_car_reminders( maneuver, useSignpost )

    if maneuver.extra_string == "EOS" and trigger == "REMINDER1" then
        set_result_id( 1 , "c" )    -- At the end of the road
    else
        distance_1, usedUnit_1 = include_distance( maneuver, false )
    end
    maneuver_car( maneuver, useSignpost )

end

function process_car_announcement( maneuver, useSignpost )

    if ( road_class == "HIGHWAY" or road_class == "URBAN_HIGHWAY" ) and maneuver.dist_to > 10000 then
        set_result_id( 1 , "d" )    -- Follow the motorway
        if ( gps_location.fow == "SLIPROAD" )then
            tts_street_1 = maneuver.route
        elseif ( gps_location.fow == "MOTORWAY"  )then
            tts_street_1 = gps_location.route
        else
            tts_street_1 = build_gps_street_name( gps_location )
        end
    elseif road_class == "STREET" and maneuver.dist_to > 3000 then
        if maneuver.dist_to > 10000 then
            set_result_id( 1 , "g" )    -- Follow the course of the road
        else
            set_result_id( 1 , "e" )    -- Follow the course of the road for...
            distance_1, usedUnit_1 = include_distance( maneuver, true )
        end
    else
        distance_1, usedUnit_1 = include_distance( maneuver, false )
        maneuver_car( maneuver, useSignpost )
    end

end

function process_pedestrian_announcement( firstManeuver )

    if firstManeuver.id == "HEAD_TO" then
        process_head_to_command( firstManeuver )
    else
        distance_1, usedUnit_1 = include_distance( firstManeuver, false )
        add_pedestrian_maneuvers_to_table( firstManeuver )
    end

end

function process_pedestrian_final_command( firstManeuver )

    if firstManeuver.id == "HEAD_TO" then
        process_head_to_command( firstManeuver )
    else
        if firstManeuver.id ~= "END" and firstManeuver.id ~= "STOPOVER" then
            set_result_id( 1 , "a" )    -- Now
        end
        add_pedestrian_maneuvers_to_table( firstManeuver )
    end

end

function include_distance( maneuver, isFollow )

    if maneuver == maneuver_2 and guidance_mode == "pedestrian" then
        set_result_id( 1 , "l" )    -- and then after...
    elseif not isFollow then
        set_result_id( 1 , "b" )    -- After...
    end
    set_result_id( 2 , "l" )    -- !DIST! !UNIT!

    if isFollow then
        distance = maneuver.dist_to_unit_string
        usedUnit = unit_follow[ maneuver.dist_unit ]
    else
        if maneuver.dist_unit == "KILOMETER" then
            if maneuver.dist_to_unit_string == "1" and not nonTTS then
                distance = dist["a"]    -- 1 km
                usedUnit = unit_after["UNDEFINED"]
            else
                -- if the unit is KILOMETER and distance is other than 1, then use KILOMETERS as unit instead
                distance = maneuver.dist_to_unit_string
                usedUnit = unit_after[ "KILOMETERS" ]
            end
        elseif maneuver.dist_unit == "MILE" then
            if maneuver.dist_to_unit_string == "0.25" then
                distance = dist["c"]    -- 1/4 mi
                usedUnit = unit_after["UNDEFINED"]
            elseif maneuver.dist_to_unit_string == "0.50" then
                distance = dist["d"]    -- 1/2 mi
                usedUnit = unit_after["UNDEFINED"]
            elseif maneuver.dist_to_unit_string == "0.75" then
                distance = dist["e"]    -- 3/4 mi
                usedUnit = unit_after["UNDEFINED"]
            elseif maneuver.dist_to_unit_string == "1" and not nonTTS then
                distance = dist["b"]    -- 1 mi
                usedUnit = unit_after["UNDEFINED"]
            else
                -- if the unit is MILE and distance is other than 1, then use MILES instead
                distance = maneuver.dist_to_unit_string
                usedUnit = unit_after[ "MILES" ]
            end
        else
            distance = maneuver.dist_to_unit_string
            usedUnit = unit_after[ maneuver.dist_unit ]
        end
    end

    -- check for language specific multiple plurals
    distance, usedUnit = checkMultiPlurals( distance, usedUnit, isFollow )

    return distance, usedUnit

end

function maneuver_car( maneuver, useSignpost )

    junction_turn, maneuver_command = get_maneuver( "car", maneuver )

    if maneuver.id == "ENTER_HIGHWAY" or maneuver.id == "ENTER_URBAN_HIGHWAY"
     or maneuver.id == "ENTER_HIGHWAY_LEFT" or maneuver.id == "ENTER_HIGHWAY_RIGHT" then
        set_result_id( 4 , junction_turn )

        if not double_command and junction_turn ~= nil and junction_turn ~= "0" then
            double_command = true
            second_cmd_trigger = "2"
        else
            set_result_id( 5 , maneuver_command )
            if not nonTTS then
                tts_street_1, tts_signpost_1 = insert_signpost_enter_hwy( maneuver, useSignpost )
            end
        end

    elseif maneuver.id == "END"
     or maneuver.id == "STOPOVER" then
        set_result_id( 4 , maneuver_command )

    elseif maneuver.id == "DRIVE_TO_NEAREST_ROAD"
     or maneuver.id == "FERRY"
     or maneuver.id == "EXIT_ROUNDABOUT" then
        set_result_id( 4 , maneuver_command )
        if not double_command and not nonTTS then
            tts_street_1 = add_street_name_or_route( maneuver, useSignpost )
        end

    elseif maneuver.id == "ROUNDABOUT" or maneuver.id == "ENTER_ROUNDABOUT" then
        set_result_id( 4 , maneuver_command )
        if maneuver.extra_integer > 0 then
            set_result_id( 6 , "z" )    -- !EXIT_NO_ROUNDABOUT!
            if double_command and nonTTS then
                exit_no_roundabout = exit_number_roundabout[ maneuver.extra_integer ][2]
            elseif nonTTS then
                exit_no_roundabout = exit_number_roundabout[ maneuver.extra_integer ][1]
            else
                exit_no_roundabout = exit_number_roundabout[ maneuver.extra_integer ]
            end
            if not nonTTS then
                add_route_after_roundabout( maneuver, useSignpost )
            end
        else
            set_result_id( 6 , "y" )    -- enter the roundabout
        end

    elseif maneuver.id == "UTURN" then
        set_result_id( 4 , maneuver_command )

    elseif ( road_class == "HIGHWAY" or road_class == "URBAN_HIGHWAY" ) then
        set_result_id( 4 , junction_turn )
        insert_signpost_exit_number_exit_name_hwy( maneuver, useSignpost )
        insert_signpost_leave_or_continue_hwy( maneuver, useSignpost )

    else
        set_result_id( 4 , junction_turn )
        if not nonTTS then
            tts_street_1 = add_street_name_or_route( maneuver, useSignpost )
        end
    end

    if ( double_command and road_class ~= "HIGHWAY" and road_class ~= "URBAN_HIGHWAY" and second_cmd_trigger == "" ) then
        second_cmd_trigger = "1"
    end

end

function get_maneuver( mode, maneuver )

    if mode == "car" then
        maneuver_turns = maneuver_turns_car
    else
        maneuver_turns = maneuver_turns_pedestrian
    end

    if maneuver ~= nil then
        junction_turn = maneuver_turns[ maneuver.turn ]
        maneuver_command = maneuver_check[ maneuver.id ]
    end

    return junction_turn, maneuver_command

end

function insert_signpost_enter_hwy( maneuver, useSignpost )

    if useSignpost then
        if maneuver.next_route ~= "" and use_streetnames then
            set_result_id( 6 , "a" )    -- !STREET!
            tts_street = maneuver.next_route
        elseif maneuver.next_street ~= "" and use_streetnames then
            set_result_id( 6 , "a" )    -- !STREET!
            tts_street = maneuver.next_street
        end
        if maneuver.signpost_direction ~= "" and use_signposts then
            set_result_id( 7 , "c" )    -- towards !SIGNPOST!
            tts_signpost = maneuver.signpost_direction
        end
    end

    if tts_street == nil then
        tts_street = ""
    end
    if tts_signpost == nil then
        tts_signpost = ""
    end

    return tts_street, tts_signpost

end

function add_street_name_or_route( maneuver, useSignpost )

    if useSignpost and use_streetnames then
        if ( road_class == "HIGHWAY" or road_class == "URBAN_HIGHWAY" ) and ( maneuver.signpost_direction ~= "" ) and use_signposts then
            set_result_id( 6 , "c" )    -- towards !STREET!
            tts_street = maneuver.signpost_direction
        elseif road_class == "STREET" and maneuver.id == "FERRY" then
            if ( maneuver.signpost_direction ~= "" ) and use_signposts then
                set_result_id( 6 , "c" )    -- towards !STREET!
                tts_street = maneuver.signpost_direction
            elseif ( maneuver.next_street ~= "" ) and use_signposts then
                set_result_id( 6 , "c" )    -- towards !STREET!
                tts_street = maneuver.next_street
            elseif ( maneuver.next_route ~= "" ) and use_signposts then
                set_result_id( 6 , "c" )    -- towards !STREET!
                tts_street = maneuver.next_route
            end
        -- add street names when there are no natural guidance elements, except traffic lights
        elseif road_class == "STREET" then
            if ( maneuver.signpost_direction ~= "" ) and use_signposts then
                set_result_id( 6 , "c" )    -- towards !STREET!
                tts_street = maneuver.signpost_direction
            elseif ( maneuver.next_street ~= "" ) and use_streetnames then
                set_result_id( 6 , "d" )    -- onto !STREET!
                tts_street = maneuver.next_street
            elseif ( maneuver.next_route ~= "" ) and use_streetnames then
                set_result_id( 6 , "d" )    -- onto !STREET!
                tts_street = maneuver.next_route
            end
        end
    end
    if tts_street == nil then
        tts_street = ""
    end

    return tts_street

end

function insert_signpost_exit_number_exit_name_hwy( firstManeuver, useSignpost )   -- Also valid for junctions on hwy

    exit_info_required = false
    if useSignpost and ( firstManeuver.signpost_exit_number ~= "" or firstManeuver.signpost_exit_name ~= "" ) and firstManeuver.turn ~= "KEEP_MIDDLE" then
        if ( double_command ) then
            exit_info_required = true
        elseif firstManeuver.id ~= "CONTINUE_HIGHWAY" and firstManeuver.id ~= "CONTINUE_URBAN_HIGHWAY" then
            exit_info_required = true
        elseif firstManeuver.next_route == "" or ( firstManeuver.next_route ~= "" and firstManeuver.route ~= firstManeuver.next_route ) then
            exit_info_required = true
        end
    end

    if exit_info_required then
        -- add exit_number and exit_name for single commands, if they are available and if the command is not continue_highway
        -- add exit number and exit name always for double commands if they are available
        set_result_id( 6 , "e" )    -- take exit !EXIT_NUMBER!
        if firstManeuver.signpost_exit_number ~= "" then
            tts_exit_number = firstManeuver.signpost_exit_number
        end
        if ( firstManeuver.signpost_exit_name ~= "" ) and use_signposts then
            set_result_id( 7 , "d" )    -- "pause" !SIGNPOST!
            tts_signpost_1 = firstManeuver.signpost_exit_name
        end
    end
end

function insert_continue_or_route_changed_for_single_command_hwy( firstManeuver )   -- Also valid for junctions on hwy

    signpost_direction_used = ( firstManeuver.signpost_direction ~= "" and firstManeuver.signpost_direction ~= firstManeuver.signpost_exit_name ) and use_signposts
    next_route_changed = ( firstManeuver.next_route ~= "" and firstManeuver.route ~= firstManeuver.next_route)
    next_route_same = ( firstManeuver.next_route ~= "" and firstManeuver.route == firstManeuver.next_route)

    if next_route_same then
        if signpost_direction_used then
           set_result_id( 8 , "z" )    -- and continue on !STREET_2! towards !SIGNPOST_2!
        else
           set_result_id( 8 , "y" )    -- and continue on !STREET_2!
        end
    elseif ( next_route_changed and use_signposts ) or signpost_direction_used then
        set_result_id( 8 , "x" )    -- towards !STREET_2! !SIGNPOST_2!
    end

end

function insert_signpost_leave_or_continue_hwy( firstManeuver, useSignpost )   -- Also valid for junctions on hwy

    tts_street_2 = firstManeuver.next_route
    tts_signpost_2 = firstManeuver.signpost_direction

    if useSignpost and ( ( exit_info_required )
     or ( firstManeuver.signpost_direction ~= "" or firstManeuver.next_route ~= "" ) ) then

        if not double_command then
            if use_streetnames then
                insert_continue_or_route_changed_for_single_command_hwy( firstManeuver )
            end
        else    -- double command == true
            if ( firstManeuver.signpost_direction ~= "" or firstManeuver.next_route ~= "" ) and use_streetnames and use_signposts then
                set_result_id( 8 , "x" )    -- towards !STREET_2! !SIGNPOST_2!
            end
            second_cmd_trigger = "3"
        end
    else
        if not double_command and ( firstManeuver.id == "LEAVE_HIGHWAY" or firstManeuver.id == "LEAVE_URBAN_HIGHWAY" ) then
            if junction_turn ~= nil and junction_turn ~= "0" then
                set_result_id( 7 , "f" )    -- and
            end
            set_result_id( 8 , maneuver_check[ firstManeuver.id ] )
        elseif double_command then
            if ( firstManeuver.id == "LEAVE_HIGHWAY" or firstManeuver.id == "LEAVE_URBAN_HIGHWAY" ) then
                set_result_id( 8 , maneuver_check[ firstManeuver.id ] )
            end
            second_cmd_trigger = "3"
        end
    end

end

function add_route_after_roundabout( maneuver, useSignpost )

    if useSignpost then
        if ( maneuver.signpost_direction ~= "" ) and use_signposts then
            set_result_id( 7 , "c" )    -- towards !SIGNPOST!
            tts_signpost_1 = maneuver.signpost_direction
        elseif ( maneuver.next_street ~= "" ) and use_streetnames then
            set_result_id( 7 , "b" )    -- onto !STREET!
            tts_street_1 = maneuver.next_street
        elseif ( maneuver.next_route ~= "" ) and use_streetnames then
            set_result_id( 7 , "b" )    -- onto !STREET!
            tts_street_1 = maneuver.next_route
        end
    end

end

function second_command_leave_or_continue_hwy( maneuver )

    junction_turn, maneuver_command = get_maneuver( "car", maneuver )
    set_result_id( 1 , "h" )    -- and then
    if maneuver.id == "ROUNDABOUT" or maneuver.id == "ENTER_ROUNDABOUT" then
        set_result_id( 5 , maneuver_command )
        roundabout_car( maneuver )
    else
        if junction_turn ~= nil and junction_turn ~= "0" then
            set_result_id( 4 , junction_turn )
        else
            set_result_id( 4 , maneuver_command )
        end
    end

end

function roundabout_car( maneuver )

    if maneuver.extra_integer > 0 then
        set_result_id( 6 , "z" )    -- !EXIT_NO_ROUNDABOUT!
        if nonTTS then
            exit_no_roundabout = exit_number_roundabout[ maneuver.extra_integer ][1]
        else
            exit_no_roundabout = exit_number_roundabout[ maneuver.extra_integer ]
        end
    else
        set_result_id( 6 , "y" )    -- enter the roundabout
    end

end

function process_head_to_command( firstManeuver )

    if firstManeuver.heading_orientation ~= "" then
        set_result_id( 1 , "f" )    -- Head !ORIENTATION!
        head_orientation = orientation[ firstManeuver.heading_orientation ]
        gps_street_name = build_gps_street_name( gps_location )
        if ( gps_street_name ~= "" ) and ( gps_street_name ~= nil ) and ( use_streetnames ) then
            set_result_id( 6 , "b" )    -- on !STREET!
            tts_street_1 = gps_street_name
        end
        if firstManeuver.extra_string ~= ""
            and firstManeuver.extra_string ~= gps_street_name and use_signposts then
            set_result_id( 7 , "c" )    -- towards !SIGNPOST!
            tts_signpost_1 = firstManeuver.extra_string
        elseif firstManeuver.next_street ~= ""
          and firstManeuver.next_street ~= gps_street_name
          and pedestrian_vc [ firstManeuver.next_street ] == nil
          and use_signposts then
            set_result_id( 7 , "c" )    -- towards !SIGNPOST!
            tts_signpost_1 = firstManeuver.next_street
        elseif firstManeuver.next_route ~= ""
         and firstManeuver.next_route ~= firstManeuver.route
         and pedestrian_vc [ firstManeuver.next_street ] == nil and use_signposts then
            set_result_id( 7 , "c" )    -- towards !SIGNPOST!
            tts_signpost_1 = firstManeuver.next_route
        end
    end

end

function add_pedestrian_maneuvers_to_table( firstManeuver )

    junction_turn, maneuver_command = get_maneuver( "pedestrian", firstManeuver )

    if firstManeuver.id == "END"
     or firstManeuver.id == "STOPOVER"
     or firstManeuver.id == "UTURN"
     or firstManeuver.id == "FERRY" then
        set_result_id( 4 , maneuver_command )
    elseif firstManeuver.id == "EXIT_ROUNDABOUT" then
        exiting_roundabout_pedestrian( firstManeuver )
    elseif firstManeuver.id == "ROUNDABOUT" or firstManeuver.id == "ENTER_ROUNDABOUT" then
        roundabout_pedestrian( firstManeuver )
    else
        set_result_id( 3 , junction_turn )
        add_pedestrian_vc_or_junction( firstManeuver )
    end

    if double_command == true
      and firstManeuver.id ~= "ROUNDABOUT"
      and firstManeuver.id ~= "ENTER_ROUNDABOUT" then
        second_cmd_trigger = "1"
    end

end

function exiting_roundabout_pedestrian( firstManeuver )

    if firstManeuver.turn == "QUITE_RIGHT" then
        set_result_id( 3 , maneuver_turns_pedestrian[ "QUITE_RIGHT" ] )
    elseif firstManeuver.turn == "QUITE_LEFT" then
        set_result_id( 3 , maneuver_turns_pedestrian[ "QUITE_LEFT" ] )
    else
        set_result_id( 3 , maneuver_turns_pedestrian[ "TURN" ] )
    end
    if firstManeuver.next_street_is_walkway
      and ( firstManeuver.next_street == "" ) then
        set_result_id( 6 , "g" )    -- onto the footpath
    elseif ((firstManeuver.next_street ~= "") and (pedestrian_vc[ firstManeuver.next_street ] == nil)) and use_streetnames then
        set_result_id( 6 , "d" )    -- onto !STREET!
        tts_street_1 = firstManeuver.next_street
    end

end

function roundabout_pedestrian( maneuver )

    if maneuver.turn == "QUITE_RIGHT" then
        set_result_id( 3 , "a" )    -- walk right around the roundabout
    elseif maneuver.turn == "QUITE_LEFT" then
        set_result_id( 3 , "b" )    -- walk left around the roundabout
    else
        set_result_id( 3 , "c" )    -- walk around the roundabout
    end

    -- ANNOUNCEMENTS AND REMINDERS don't include exit information
    if trigger == "PEDESTRIAN_COMMAND" or trigger == "WEB" then
        if maneuver == maneuver_1 then

            if maneuver.extra_integer < 4 then  -- no exit number for exits > 3
                ped_turn_no = turn_number_ped[ maneuver.extra_integer ]
                set_result_id( 6 , "j" )    -- and turn at the Xth. street
            elseif (( maneuver.next_street ~= "" ) and (pedestrian_vc[ maneuver.next_street ] == nil)) or ( maneuver.next_route ~= "" ) and use_streetnames then
                set_result_id( 6 , "h" )    -- and turn onto !STREET!
            end

            if maneuver.next_street ~= "" and pedestrian_vc[ maneuver.next_street ] == nil then
                tts_street_1 = maneuver.next_street
            elseif maneuver.next_route ~= "" then
                tts_street_1 = maneuver.next_route
            end
        end
    end
end

function add_pedestrian_vc_or_junction( firstManeuver )

    if pedestrian_vc[ firstManeuver.next_street ] == nil then
        -- JUNCTIONS
        if keep[ firstManeuver.turn ] == nil then   -- add "onto" only if maneuver doesn't belong to "keep"
            gps_street_name = build_gps_street_name( gps_location )
            if firstManeuver.next_street ~= "" and use_streetnames then
                if firstManeuver.next_street == gps_street_name then
                    set_result_id( 6 , "f" )    -- and continue on !STREET!
                    tts_street_1 = firstManeuver.next_street
                else
                    set_result_id( 6 , "d" )    -- onto !STREET!
                    tts_street_1 = firstManeuver.next_street
                end
            elseif firstManeuver.next_route ~= "" and use_streetnames then
                if firstManeuver.next_route == gps_street_name then
                    set_result_id( 6 , "f" )    -- and continue on !STREET!
                    tts_street_1 = firstManeuver.next_route
                else
                    set_result_id( 6 , "d" )    -- onto !STREET!
                    tts_street_1 = firstManeuver.next_route
                end
            elseif firstManeuver.next_street_is_walkway and not firstManeuver.street_is_walkway then
                set_result_id( 6 , "g" )    -- onto the footpath
            end
        elseif double_command == false and firstManeuver.next_street ~= "" and use_streetnames then
            set_result_id( 6 , "a" )    -- !STREET!
            tts_street_1 = firstManeuver.next_street
        end
    -- VIRTUAL CONNECTIONS
    elseif pedestrian_vc[ firstManeuver.next_street ] ~= pedestrian_vc[ firstManeuver.street ] then
        if junction_turn == nil or double_command then
            set_result_id( 6 , pedestrian_vc[ firstManeuver.next_street ] )
        else
            set_result_id( 7 , pedestrian_vc[ firstManeuver.next_street ] )
        end
    end

end

-- additional global input
-- trigger: ANNOUNCEMENT, COMMAND, PEDESTRIAN_ANNOUNCEMENT, WEB, REMINDER1, REMINDER2
base_maneuver_table = {
    id = "", -- JUNCTION, STOPOVER
    turn = "", -- QUITE_LEFT
    type = "", -- MANEUVER, NEXT_MANEUVER
    exits_left = 0,
    exits_right = 0,
    dist_to = 0,
    dist_to_unit_string = "",
    dist_unit = "",
    extra_integer = 0,
    extra_string = "",
    street = "",
    street_phoneme = "",
    street_is_walkway = false,
    next_street_is_walkway = false,
    next_street = "",
    next_street_phoneme = "",
    route = "",
    route_phoneme = "",
    next_route = "",
    next_route_phoneme = "",
    signpost_direction = "",
    signpost_direction_phoneme = "",
    signpost_exit_number = "" ,
    signpost_exit_number_phoneme = "" ,
    signpost_exit_name = "",
    signpost_exit_name_phoneme = "",
    heading_orientation = "",
-- NG
    ng_type = "", -- defines the type of NG: "TRAFFIC LIGHT", "STOP SIGN", "JUNCTION"
    -- fields for ng_type == JUNCTION
    ng_preposition = "NONE",
    ng_language = "",
    ng_name = "",
    ng_name_p = {},
    ng_name_p_lang = "",
    ng_name_p_nt_sampa = {},
    ng_name_p_nt_sampa_lang = "",
    -- fields for ng_type == TRAFFIC LIGHT
    traffic_light_int = 0,

--  phonetic_lang_code = "",
}

base_voice_guidance_settings = {
    gender = "female",
    streetnames = "true",
    signposts = "true",
    phoneticdata = "true",
    speedwarning = "true",
    safetyspotwarning = "true",
    gpswarning = "true",
    trafficwarning = "true",
    announce_stopover = "true",
    -- natural guidance - don't assume on by default.
    nguidance = "false", -- global natural guidance enabler/disabler
    nguidance_trafficlights = "false",
    nguidance_junction = "false", -- junctions logic as delivered by navteq/HERE
    nguidance_phoneme = "false", -- phonemes for buildings
    nguidance_stop_sign = "false",
}

maneuver_check = {
    ["END"] = "a",                         -- You will reach your destination
    ["STOPOVER"] = "b",                    -- You will reach a stopover
    ["JUNCTION"] = "0",                    -- No voice file needed -> check maneuver_turn
    ["ROUNDABOUT"] = "c",                  -- At the roundabout
    ["ENTER_ROUNDABOUT"] = "c",            -- At the roundabout
    ["EXIT_ROUNDABOUT"] = "d",             -- take the exit
    ["UTURN"] = "e",                       -- Make a uturn
    ["ENTER_HIGHWAY"] = "f",               -- enter the motorway
    ["ENTER_HIGHWAY_LEFT"] = "f",          -- enter the motorway
    ["ENTER_HIGHWAY_RIGHT"] = "f",         -- enter the motorway
    ["LEAVE_HIGHWAY"] = "g",               -- take the exit
    ["CONTINUE_HIGHWAY"] = "h",            -- due to specifications ("take the exit")
    ["ENTER_URBAN_HIGHWAY"] = "i",         -- enter the urban motorway
    ["LEAVE_URBAN_HIGHWAY"] = "j",         -- take the exit
    ["CONTINUE_URBAN_HIGHWAY"] = "k",      -- continue the urban motorway
    ["DRIVE_TO_NEAREST_ROAD"] = "l",       -- drive to nearest road
    ["FERRY"] = "m",                       -- take the ferry
    ["PASS_ROUNDABOUT"] = "0",
    ["ROAD_NAME_CHANGED"] = "0",
    ["nil"] = "0",
    ["UNDEFINED"] = "0"
}

maneuver_turns_car = {
    ["NO_TURN"] = "n",                      -- go straight ahead
    ["KEEP_MIDDLE"] = "o",                  -- take the middle lane
    ["KEEP_RIGHT"] = "p",                   -- keep right
    ["LIGHT_RIGHT"] = "q",                  -- turn slightly right
    ["QUITE_RIGHT"] = "r",                  -- turn right
    ["HEAVY_RIGHT"] = "s",                  -- turn sharply right
    ["RETURN"] = "t",                       -- make a u turn
    ["HEAVY_LEFT"] = "u",                   -- turn sharply left
    ["QUITE_LEFT"] = "v",                   -- turn left
    ["LIGHT_LEFT"] = "w",                   -- turn slightly left
    ["KEEP_LEFT"] = "x",                    -- keep left
    ["nil"] = "0",
    ["UNDEFINED"] = "0"
}

maneuver_turns_pedestrian = {
    ["NO_TURN"] = "n",                      -- walk straight ahead",
    ["KEEP_MIDDLE"] = "o",                  -- take the street in the middle",
    ["KEEP_RIGHT"] = "p",                   -- take the street on the right",
    ["LIGHT_RIGHT"] = "q",                  -- turn slightly right",
    ["QUITE_RIGHT"] = "r",                  -- turn right",
    ["HEAVY_RIGHT"] = "s",                  -- turn sharply right",
    ["RETURN"] = "t",                       -- make a u turn",
    ["HEAVY_LEFT"] = "u",                   -- turn sharply left",
    ["QUITE_LEFT"] = "v",                   -- turn left",
    ["LIGHT_LEFT"] = "w",                   -- turn slightly left",
    ["KEEP_LEFT"] = "x",                    -- take the street on the left",
    ["TURN"] = "y",                         -- turn
    ["nil"] = "0",
    ["UNDEFINED"] = "0"
}

pedestrian_vc = {
    ["BUILDING"] = "o",             -- go through the building
    ["SQUARE"] = "p",               -- cross the square
    ["PARK"] = "q",                 -- cross the park
    ["STAIRS"] = "r",               -- take the stairs
    ["ELEVATOR"] = "s",             -- take the lift
    ["ESCALATOR"] = "t",            -- take the escalator
    ["nil"] = "0",
    ["UNDEFINED"] = "0"
}

right = { ["QUITE_RIGHT"] = 0, ["HEAVY_RIGHT"] = 0, ["LIGHT_RIGHT"] = 0 }
left = { ["QUITE_LEFT"] = 0, ["HEAVY_LEFT"] = 0, ["LIGHT_LEFT"] = 0 }
keep = { ["KEEP_LEFT"] = 0, ["KEEP_RIGHT"] = 0, ["KEEP_MIDDLE"] = 0, ["NO_TURN"] = 0 }
highway = { ["ENTER_HIGHWAY"] = 0, ["ENTER_HIGHWAY_LEFT"] = 0, ["ENTER_HIGHWAY_RIGHT"] = 0, ["ENTER_URBAN_HIGHWAY"] = 0, ["LEAVE_HIGHWAY"] = 0, ["LEAVE_URBAN_HIGHWAY"] = 0 }

transit_type_list = {
    ["BUS_EXPRESS"] = {"BUS","STOP"},
    ["BUS_PUBLIC"] = {"BUS","STOP"},
    ["BUS_TOURISTIC"] = {"BUS","STOP"},
    ["BUS_INTERCITY"] = {"BUS","STATION"},
    ["RAIL_METRO"] = {"RAIL","STATION"},
    ["RAIL_LIGHT"] = {"RAIL","STATION"},
    ["RAIL_REGIONAL"] = {"RAIL","STATION"},
    ["TRAIN_REGIONAL"] = {"TRAIN","STATION"},
    ["TRAIN_INTERCITY"] = {"TRAIN","STATION"},
    ["TRAIN_HIGH_SPEED"] = {"TRAIN","STATION"},
    ["MONORAIL"] = {"MONORAIL","STATION"},
    ["AERIAL"] = {"AERIAL","STATION"},
    ["INCLINED"] = {"INCLINED","STATION"},
    ["WATER"] = {"WATER","STATION"},
}

function set_result_id( token , state )
    if token ~= nil then
        if state ~= nil then
            result_id[token] = state
        else
            result_id[token] = "0"
        end
    end
end

function add_phonetic_data( name )

    local phoneme = ""
    local lang = ""
    local phoneme_fields = {}
    phoneme_fields["street_phoneme_field"] = "street_phoneme"
    phoneme_fields["next_street_phoneme_field"] = "next_street_phoneme"
    phoneme_fields["route_phoneme_field"] = "route_phoneme"
    phoneme_fields["gps_route_phoneme_field"] = "route_phoneme"
    phoneme_fields["next_route_phoneme_field"] = "next_route_phoneme"
    phoneme_fields["gps_street_phoneme_field"] = "street_phoneme"
    phoneme_fields["signpost_direction_phoneme_field"] = "signpost_direction_phoneme"
    phoneme_fields["signpost_exit_name_phoneme_field"] = "signpost_exit_name_phoneme"
    phoneme_fields["signpost_exit_number_phoneme_field"] = "signpost_exit_number_phoneme"

    -- for TMC notification custom voice trigger
    phoneme_fields["affected_street_phoneme_field"] = "street_phoneme"
    phoneme_fields["affected_route_phoneme_field"] = "route_phoneme"

    if _package_settings["phonemeset"] == 'NT-SAMPA' then
        for phoneme_field, phoneme_field_value in pairs(phoneme_fields) do
            phoneme_fields[phoneme_field] = phoneme_field_value .. "_nt_sampa"
        end
    end

    if name ~= nil and name ~= "" then
        if name == maneuver.next_street then
            phoneme, lang = maneuver[phoneme_fields["next_street_phoneme_field"]], maneuver[phoneme_fields["next_street_phoneme_field"].."_lang"]
        elseif name == maneuver.next_route and (is_same_language( maneuver[phoneme_fields["next_route_phoneme_field"].."_lang"] ) == true or name:find('%d') == nil) then
            phoneme, lang = maneuver[phoneme_fields["next_route_phoneme_field"]], maneuver[phoneme_fields["next_route_phoneme_field"].."_lang"]
        elseif name == maneuver.street then
            phoneme, lang = maneuver[phoneme_fields["street_phoneme_field"]], maneuver[phoneme_fields["street_phoneme_field"].."_lang"]
        elseif name == maneuver.route and (is_same_language( maneuver[phoneme_fields["route_phoneme_field"].."_lang"] ) == true or name:find('%d') == nil) then
            phoneme, lang = maneuver[phoneme_fields["route_phoneme_field"]], maneuver[phoneme_fields["route_phoneme_field"].."_lang"]
        elseif name == maneuver.signpost_direction and (is_same_language( maneuver[phoneme_fields["signpost_direction_phoneme_field"].."_lang"] ) == true or name:find('%d') == nil) then
            phoneme, lang = maneuver[phoneme_fields["signpost_direction_phoneme_field"]], maneuver[phoneme_fields["signpost_direction_phoneme_field"].."_lang"]
        elseif name == maneuver.signpost_exit_name then
            phoneme, lang = maneuver[phoneme_fields["signpost_exit_name_phoneme_field"]], maneuver[phoneme_fields["signpost_exit_name_phoneme_field"].."_lang"]
        elseif name == maneuver.signpost_exit_number and (is_same_language( maneuver[phoneme_fields["signpost_exit_number_phoneme_field"].."_lang"] ) == true or name:find('%d') == nil) then
            phoneme, lang = maneuver[phoneme_fields["signpost_exit_number_phoneme_field"]], maneuver[phoneme_fields["signpost_exit_number_phoneme_field"].."_lang"]
        elseif name == gps_location.route and (is_same_language( maneuver[phoneme_fields["gps_route_phoneme_field"].."_lang"] ) == true or name:find('%d') == nil) then
            phoneme, lang = gps_location[phoneme_fields["gps_route_phoneme_field"]], gps_location[phoneme_fields["gps_route_phoneme_field"].."_lang"]
        elseif name == gps_location.street then
            phoneme, lang = gps_location[phoneme_fields["gps_street_phoneme_field"]], gps_location[phoneme_fields["gps_street_phoneme_field"].."_lang"]
        elseif name == nextManeuver.next_street then
            phoneme, lang = nextManeuver[phoneme_fields["next_street_phoneme_field"]], nextManeuver[phoneme_fields["next_street_phoneme_field"].."_lang"]
        elseif name == nextManeuver.next_route and (is_same_language( maneuver[phoneme_fields["next_route_phoneme_field"].."_lang"] ) == true or name:find('%d') == nil) then
            phoneme, lang = nextManeuver[phoneme_fields["next_route_phoneme_field"]], nextManeuver[phoneme_fields["next_route_phoneme_field"].."_lang"]
        elseif name == nextManeuver.street then
            phoneme, lang = nextManeuver[phoneme_fields["street_phoneme_field"]], nextManeuver[phoneme_fields["street_phoneme_field"].."_lang"]
        elseif name == nextManeuver.route and (is_same_language( maneuver[phoneme_fields["route_phoneme_field"].."_lang"] ) == true or name:find('%d') == nil) then
            phoneme, lang = nextManeuver[phoneme_fields["route_phoneme_field"]], nextManeuver[phoneme_fields["route_phoneme_field"].."_lang"]
        elseif name == nextManeuver.signpost_direction and (is_same_language( maneuver[phoneme_fields["signpost_direction_phoneme_field"].."_lang"] ) == true or name:find('%d') == nil) then
            phoneme, lang = nextManeuver[phoneme_fields["signpost_direction_phoneme_field"]], nextManeuver[phoneme_fields["signpost_direction_phoneme_field"].."_lang"]
        elseif name == nextManeuver.signpost_exit_name then
            phoneme, lang = nextManeuver[phoneme_fields["signpost_exit_name_phoneme_field"]], nextManeuver[phoneme_fields["signpost_exit_name_phoneme_field"].."_lang"]
        elseif name == nextManeuver.signpost_exit_number and (is_same_language( maneuver[phoneme_fields["signpost_exit_number_phoneme_field"].."_lang"] ) == true or name:find('%d') == nil) then
            phoneme, lang = nextManeuver[phoneme_fields["signpost_exit_number_phoneme_field"]], nextManeuver[phoneme_fields["signpost_exit_number_phoneme_field"].."_lang"]

        -- for TMC notification custom voice trigger
        elseif name == street and ( is_same_language( _G[phoneme_fields["affected_street_phoneme_field"].."_lang"] ) == true or name:find( '%d' ) == nil ) then
            phoneme, lang = _G[phoneme_fields["affected_street_phoneme_field"]], _G[phoneme_fields["affected_street_phoneme_field"] .. "_lang"]
        elseif name == route and ( is_same_language( _G[phoneme_fields["affected_route_phoneme_field"].."_lang"] ) == true or name:find( '%d' ) == nil ) then
            phoneme, lang = _G[phoneme_fields["affected_route_phoneme_field"]], _G[phoneme_fields["affected_route_phoneme_field"] .. "_lang"]

        end
    end

    return phoneme, lang
end

function add_street_article( name, sentence )
    if name ~= nil and street_article ~= nil then
        s_article = nil
        fc = 0
        for a_1,b_1 in pairs(street_article) do
            name = string.lower(name)
            sentence = string.lower(sentence)
            if string.find(sentence, a_1) then
                for a_2,b_2 in pairs(b_1) do
                    foo = false
                    for a_3,b_3 in pairs(b_2) do
                        if string.find(name, b_3) then
                            s_article = a_2
                            foo = true
                        end
                    end
                    if foo then
                        fc = fc+1
                    end
                end
            end
        end
        if fc == 1 then
            s_article = " "..s_article.." "
        elseif fc == 0 then
            for a_2,b_2 in pairs(street_article["baseArticle"]) do
                foo = false
                for a_3,b_3 in pairs(b_2) do
                    article_2 = string.lower(b_3)
                    if string.find(name, article_2) then
                        s_article = a_2
                        foo = true
                    end
                end
                if foo then
                    fc = fc+1
                end
            end
            if fc == 1 then
                s_article = " "..s_article.." "
            else
                s_article = ""
            end
        end
    end

    if s_article == nil then
        s_article = ""
    end

    return s_article

end

function check_voice_guidance_settings()

    if voice_settings == nil then
        voice_settings = {}
    end

    -- overwrite base_voice_guidance_settings (global) with package (skin file) settings
    if _package_settings and _package_settings.voice_settings then
        for k,v in pairs(_package_settings.voice_settings) do
            base_voice_guidance_settings[k] = v
        end
    end

    for k,v in pairs(base_voice_guidance_settings) do
        if voice_settings[k] ~= nil then
            voice_settings[k] = string.lower(tostring(voice_settings[k]))
            if not (voice_settings[k] == "true" or voice_settings[k] == "false") then
                if not ( k == "gender" and (voice_settings[k] == "female" or voice_settings[k] == "male") ) then
                    voice_settings[k] = v
                end
            end
        else
            voice_settings[k] = v
        end
    end

    if gender == "f" then
        voice_settings["gender"] = "female"
    elseif gender == "m" then
        voice_settings["gender"] = "male"
    end

  -- note our predefined values are real boolean, so the finale else is to keep the default
    for k,v in pairs(voice_settings) do
        if v == "true" then
            voice_settings[k] = true
        elseif v == "false" then
            voice_settings[k] = false
        end
    end

    -- Dirk: want to get rid of these. I'll use the voice_settings[] version: scoping and everything...
    use_streetnames = voice_settings["streetnames"]
    use_signposts = voice_settings["signposts"]
    use_nguidance = voice_settings["nguidance"]
    use_trafficlights = voice_settings["trafficlights"]
    use_phoneticdata = voice_settings["phoneticdata"]
    use_speedwarning = voice_settings["speedwarning"]
    use_safetyspotwarning = voice_settings["safetyspotwarning"]
    use_trafficwarning = voice_settings["trafficwarning"]
    use_gpswarning = voice_settings["gpswarning"]

end

function escape_string( text )
  -- dash is evil, so we escape them
  -- http://www.lua.org/pil/20.2.html
  -- http://stackoverflow.com/questions/9790688/escaping-strings-for-gsub
  -- The magic characters are:  ( ) . % + - * ? [ ^ $
  -- be complete -> lets escape them recursive
  return (text:gsub('%%', '%%%%')
               :gsub('%^', '%%%^')
               :gsub('%$', '%%%$')
               :gsub('%(', '%%%(')
               :gsub('%)', '%%%)')
               :gsub('%.', '%%%.')
               :gsub('%[', '%%%[')
               :gsub('%]', '%%%]')
               :gsub('%*', '%%%*')
               :gsub('%+', '%%%+')
               :gsub('%-', '%%%-')
               :gsub('%?', '%%%?'))
end

function is_street_in_signpost( street, signpost )

    if street == "" or signpost == "" then
        return false
    end

    -- dash is evil, so we escape them
    pattern = escape_string( street )
    return string.find(signpost, pattern)

end

function filter_double_street_on_street_signpost_combination( )
    if result_id[8] == "x" --towards <STREET_2> <SIGNPOST_2>
        and is_street_in_signpost( tts_street_2, tts_signpost_2 ) then
            tts_street_2 = ""
    end

    if result_id[6] == "a" -- onto <STREET>
        and result_id[7] == "c" --towards <SIGNPOST_2>
        and is_street_in_signpost( tts_street_1, tts_signpost_1 )
    then
        set_result_id( 6, "0" ) -- drop: onto <STREET>
        tts_street_1 = ""
    end

end

function should_expand_dgttsp( phoneme )
    local tts_output_format = voice_settings["tts_output_format"]
    if ( phoneme == nil or phoneme == "" or tts_output_format == "raw" ) then
        -- phonemes not found or "raw" tts_output_format is set, expanding abbreviations
        return true
    else
        -- phonemes will be included, no need to expand abbreviations
        return false
    end
end

-- phoneme_string_builder has to be defined in the platform_format and goes like (name, phoneme)
-- where it picks and transforms the phoneme in a platform depending format
-- like for WP in SSML
-- OR if it can not find a phoneme format a platform depending string containing the name
function build_streetname( street_name, r_sentence, phoneme_string_builder )
    if street_name == "" or street_name == nil then
        return ""
    end

    local article = add_street_article( street_name, r_sentence )
    local phoneme = ""
    local lang = ""
    phoneme, lang = add_phonetic_data( street_name )
    if should_expand_dgttsp( phoneme ) then
        name = expand_dgttsp( street_name, r_sentence )
    else
        -- if we have phonetic data, don't even bother with expansion
        name = street_name
    end

    if phoneme_string_builder ~= nil then
        return phoneme_string_builder( name, phoneme, lang, article, true )
    else
        return article .. name
    end
end

function build_signpost( signpost_name, r_sentence, phoneme_string_builder )
    if signpost_name == "" or signpost_name == nil then
        return ""
    end

    local phoneme = ""
    local lang = ""
    phoneme, lang = add_phonetic_data( signpost_name )
    if should_expand_dgttsp( phoneme ) then
        name = expand_dgttsp( signpost_name, r_sentence )
    else
        -- if we have phonetic data, don't even bother with expansion
        name = signpost_name
    end

    if phoneme_string_builder ~= nil then
        return phoneme_string_builder( name, phoneme, lang, "", true )
    else
        return name
    end
end

function build_gps_street_name( gps_location )
    gps_street_name = ""
    -- if the street in the GPS location is empty, the route name from the GPS location should be used instead
    if (gps_location.street ~= nil) and (gps_location.street ~= "") then
        gps_street_name = gps_location.street
    elseif (gps_location.route ~= nil) and (gps_location.route ~= "") then
        gps_street_name = gps_location.route
    end

    return gps_street_name
end

-- N A T U R A L   G U I D A N C E
function filter_natural_guidance( maneuver )
    show_nguidance = false
    if ( voice_settings["nguidance"] == true ) and ( maneuver.ng_type ~= nil ) and ( maneuver.ng_type ~= "" )
     and ( maneuver.id ~= "END" ) and ( maneuver.id ~= "STOPOVER" )
     and ( maneuver.id ~= "ROUNDABOUT" ) and ( maneuver.id ~= "ENTER_ROUNDABOUT" )
    then
        if ( maneuver.ng_type == "TRAFFIC LIGHT" and voice_settings["nguidance_trafficlights"] ) then
            show_nguidance = true
        elseif ( maneuver.ng_type == "STOP SIGN" and voice_settings["nguidance_stop_sign"] ) then
            show_nguidance = true
        elseif ( maneuver.ng_type == "JUNCTION" and voice_settings["nguidance_junction"] ) then
            if ( string.lower(maneuver.ng_language) == string.lower(main_attribute_array.ngLangCode) ) then
                show_nguidance = true
            end
--            if ( use_streetnames and _G.trigger ~= "COMMAND" and maneuver.ng_type ~= "TRAFFIC LIGHT" and maneuver.ng_type ~= "STOP SIGN" ) then
--                show_nguidance = false
--            end
        end

        if ( maneuver.dist_to > 1000.00 ) then
            show_nguidance = false
        elseif ( _G.trigger == "REMINDER2" ) then
            show_nguidance = false
        elseif ( _G.trigger == "COMMAND" ) and ( maneuver.type == "MANEUVER" or double_command == false ) then
            show_nguidance = false
        elseif ( _G.trigger ~= "COMMAND" and maneuver.type == "NEXT_MANEUVER" ) then
            show_nguidance = false
        end

    end

    -- if voice_settings["nguidance"] == false
        -- or ( maneuver.ng_calculated_importance ~= nil and maneuver.ng_calculated_importance < 5 )  -- eliminate NG elements with importance < 5
        -- or ( string.lower(maneuver.ng_language) ~= "def" and string.lower(maneuver.ng_language) ~= string.lower(main_attribute_array.ngLangCode)) -- has to be rethought on multi language NG
        -- or ( maneuver.dist_to > 1000.00 ) -- 6.2.2.1, I interpreat it as a general distance limitation
        -- or ( _G.trigger == "REMINDER2" ) -- REMINDER2 must never contain NG elements
        -- -- 6.2.2.4
        -- -- MOS/NMA BUG, and this is a workaround
        -- -- GI-1032 COMMAND trigger filter, if this works on NMA we may remove this.
        -- or ( _G.trigger == "COMMAND" and maneuver.type == "MANEUVER"
            -- and (maneuver.ng_type == "TRAFFIC LIGHT" or maneuver.ng_type == "STOP SIGN"))
        -- or ( maneuver.ng_type == "STOP SIGN" and not voice_settings["nguidance_stop_sign"] )
        -- or ( maneuver.ng_type == "TRAFFIC LIGHT" and not voice_settings["nguidance_trafficlights"] )
        -- or ( maneuver.id == "ROUNDABOUT" ) -- roundabouts are always excluded from NG
        -- or ( maneuver.id == "ENTER_ROUNDABOUT" ) -- roundabouts are always excluded from NG
    -- then
        -- maneuver.ng_type = ""
    -- end

    if not voice_settings["nguidance_phoneme"] then
        maneuver.ng_name_p = {}
        maneuver.ng_name_p_lang = nil
        maneuver.ng_name_p_nt_sampa = {}
        maneuver.ng_name_p_nt_sampa_lang = nil
    end


end

function build_natural_guidance( maneuver, phoneme_string_builder)

    if ( show_nguidance == false ) then
        return ""
    end

    if (maneuver.ng_type == "TRAFFIC LIGHT") then
        if (maneuver.traffic_light_int > 0) and voice_settings["nguidance_trafficlights"] then
            if nG_elements[maneuver.traffic_light_int] == nil then
              return ''
            else
              return ", "..nG_elements[maneuver.traffic_light_int]..", "
            end
        end
        return ""
    end

    if (maneuver.ng_type == "STOP SIGN") then
        return 'at the next stop sign'
    end

    if maneuver.ng_type == "JUNCTION"
        and voice_settings["nguidance_junction"] ~= false then
        -- Do not use NG element (ng type JUNCTION) together with street names
        if ( maneuver.signpost_direction == "" or not use_signposts ) and use_streetnames and maneuver.next_street ~= "" then
            if maneuver.type == "MANEUVER" then
                tts_street_1 = ""
            elseif maneuver.type == "NEXT_MANEUVER" then
                tts_street_2 = ""
            end
        end
        return build_natural_guidance_junction( maneuver, phoneme_string_builder)
    end

    return ""
end

function pick_natural_guidance_phoneme  ( maneuver )
    if not _package_settings["phonemeset"] then
        return pick_natural_guidance_phoneme_IPA( maneuver )
    end

    if _package_settings["phonemeset"] == 'IPA' then
        return pick_natural_guidance_phoneme_IPA( maneuver )
    end

    if _package_settings["phonemeset"] == 'NT-SAMPA' then
        return pick_natural_guidance_phoneme_NT_SAMPA( maneuver )
    end

    return ''

end

function pick_natural_guidance_phoneme_IPA ( maneuver )
    if maneuver.ng_name_p == nil then
        return ""
    end

    if _package_settings and _package_settings.NuanceLanguagePriorities then
        for _, code in ipairs(_package_settings.NuanceLanguagePriorities) do
            if maneuver.ng_name_p[code] then
                return maneuver.ng_name_p[code]
            end
        end
    end

    if not maneuver.ng_language then
        return ""
    end

    return maneuver.ng_name_p[maneuver.ng_language]

end

function pick_natural_guidance_phoneme_NT_SAMPA ( maneuver )
    if maneuver.ng_name_p_nt_sampa == nil then
        return ""
    end

    if _package_settings and _package_settings.NuanceLanguagePriorities then
        for _, code in ipairs(_package_settings.NuanceLanguagePriorities) do
            if maneuver.ng_name_p_nt_sampa[code] then
                return maneuver.ng_name_p_nt_sampa[code]
            end
        end
    end

    if not maneuver.ng_language then
        return ""
    end

    return maneuver.ng_name_p_nt_sampa[maneuver.ng_language]

end

function build_natural_guidance_junction( maneuver, phoneme_string_builder)
    if not maneuver.ng_preposition or maneuver.ng_preposition == "" then
        maneuver.ng_preposition = "NONE"
    end

    if nG_prepositions == nil or not nG_prepositions[maneuver.ng_preposition] or maneuver.ng_name_p == nil then
        return ""
    end

    local preposition = nG_prepositions[maneuver.ng_preposition]
    local phoneme = pick_natural_guidance_phoneme   ( maneuver )

    -- phoneme_builder has to be defined in platform_format
    local content = phoneme_string_builder( maneuver.ng_name, phoneme, maneuver.ng_language, '', false )

    -- 18.6.2.9 in Relational Database Format (RDF) Reference Guide Q1 2013 Product Version 3.0
    if maneuver.ng_preposition:sub(4, 4) == "B" then
        return phoneme_string_builder( maneuver.ng_name, phoneme, maneuver.ng_language, preposition, false )
    else
        return phoneme_string_builder( preposition, phoneme, maneuver.ng_language, maneuver.ng_name, false )
    end

end

function provide_natual_guidance(maneuvers, phoneme_string_builder)
    local ngs = {}
    for i,maneuver in ipairs(maneuvers) do
        -- determine if natural guidance will be used for this maneuver
        filter_natural_guidance( maneuver )
        ngs[i] = build_natural_guidance( maneuver, phoneme_string_builder)
    end

    return ngs
end

function trim_leading_and_folowing_whitespace(s)
  return s:gsub("^%s*", ""):gsub("%s*$", "")
end


-- split a token into a a table of components, each component has 2 values: the word and the punctuation after that word
function split_token(token)

    separators = { " ", ",", "." }
    local token_components = {}
    local i = 1
    local char = string.sub( token, i, i )
    while ( i <= string.len( token ) ) do
        local word_table = {}
        local content = ""
        local punctuation = ""
        while ( contains( separators, char, true) == false ) and ( i <= string.len( token ) ) do
            content = content..char
            i = i + 1
            char = string.sub( token, i, i )
        end
        while ( contains( separators, char, true) == true ) and ( i <= string.len( token ) ) do
            punctuation = punctuation..char
            i = i + 1
            char = string.sub( token, i, i )
        end
        table.insert( word_table, content )
        table.insert( word_table, punctuation )
        table.insert( token_components, word_table )
    end

    return token_components

end


phoneme_to_marc = {
    ["ARS"] = "ARG",     -- Spanish (Argentina)
    ["BRA"] = "076",     -- Portuguese (Brazil)
    ["CFR"] = "051",     -- French (Canada)
    ["CZE"] = "CZE",     -- Czech
    ["DAN"] = "DAN",     -- Danish
    ["ENG"] = "010",     -- US English
    ["FIN"] = "FIN",     -- Finnish
    ["FRE"] = "FRE",     -- French
    -- ["GCS"] = "083",     -- Spanish (Colombia)
    ["GER"] = "GER",     -- German
    ["HUN"] = "HUN",     -- Hungarian
    ["IND"] = "IND",     -- Indonesian
    ["ITA"] = "ITA",     -- Italian
    ["NAS"] = "083",     -- Spanish (Mexico)
    ["NOR"] = "NOR",     -- Norwegian
    ["POL"] = "POL",     -- Polish
    ["POR"] = "POR",     -- Portuguese
    ["RUS"] = "RUS",     -- Russian
    ["SLO"] = "SLO",     -- Slovak
    ["SPA"] = "SPA",     -- Spanish
    ["SWE"] = "SWE",     -- Swedish
    ["THA"] = "THA",     -- Thai
    ["TUR"] = "TUR",     -- Turkish
    ["TWN"] = "CHT",     -- Mandarin (Taiwan)
    ["UKE"] = "ENG",     -- UK English
    -- Korean Marc code 'KOR' not covered because the corresponding phonetic language is missing
}


function is_same_language(phoneme_language)
    if phoneme_language ~= nil and phoneme_to_marc[phoneme_language:upper()] == marc_code:upper() then
        return true
    else
        return false
    end
end

-- C U S T O M   V O I C E   T R I G G E R

-- initialise the handling methods table for the custom voice trigger
function init_custom_voice_trigger_table( )
    cvt_handler_methods = { }
    cvt_handler_methods["ROUTE_CALCULATION_BEGIN"] = function() process_route_calculation( true, false ) end
    cvt_handler_methods["ROUTE_CALCULATION_END"] = function() process_route_calculation( false, false ) end
    cvt_handler_methods["ROUTES_CALCULATION_BEGIN"] = function() process_route_calculation( true, true ) end
    cvt_handler_methods["ROUTES_CALCULATION_END"] = function() process_route_calculation( false, true ) end
    cvt_handler_methods["ROUTE_ATTRIBUTES_VIOLATION"] = function() process_route_attributes( "ROUTE_ATTRIBUTES_VIOLATION" ) end
    cvt_handler_methods["ROUTE_ATTRIBUTES_NOTIFICATION"] = function() process_route_attributes( "ROUTE_ATTRIBUTES_NOTIFICATION" ) end
    cvt_handler_methods["SEGMENT_ATTRIBUTES_NOTIFICATION"] = function() process_route_attributes( "SEGMENT_ATTRIBUTES_NOTIFICATION" ) end
    cvt_handler_methods["TRAFFIC_NOTIFICATION"] = process_traffic_notification
    cvt_handler_methods["TMC_NOTIFICATION"] = process_tmc_notification
    cvt_handler_methods["OFFROAD_ACTION_START"] = function() process_offroad_action( "OFFROAD_ACTION_START" ) end
    cvt_handler_methods["OFFROAD_ACTION_DESTINATION"] = function() process_offroad_action( "OFFROAD_ACTION_DESTINATION" ) end
    cvt_handler_methods["OFFROAD_ACTION_DESTINATION_AREA"] = function() process_offroad_action( "OFFROAD_ACTION_DESTINATION_AREA" ) end
    cvt_handler_methods["OFFROAD_ACTION_DESTINATION_ARROW"] = function() process_offroad_action( "OFFROAD_ACTION_DESTINATION_ARROW" ) end
    cvt_handler_methods["OFFROAD_ACTION_STOPOVER"] = function() process_offroad_action( "OFFROAD_ACTION_STOPOVER" ) end
    cvt_handler_methods["ROUTE_RECALCULATION_AUTOMATIC"] = function() process_route_recalculation( true ) end
    cvt_handler_methods["ROUTE_RECALCULATION_MANUAL"] = function() process_route_recalculation( false ) end
    cvt_handler_methods["GUIDANCE_INACTIVE"] = process_guidance_inactive
end


-- constructs the prompt for the route calculation prompt status
function process_route_calculation( is_calculation_begin, multiple_routes )
    set_result_id( 1, "x" )
    set_result_id( 2, "r" )
    if ( multiple_routes ) then
        if ( is_calculation_begin ) then
            set_result_id( 3, "o" )
        else
            set_result_id( 3, "p" )
        end
    else
        if ( is_calculation_begin ) then
            set_result_id( 3, "b" )
        else
            set_result_id( 3, "e" )
        end
    end
end


-- parse the route_attributes string and map the corresponding attributes into route_attributes_string
function process_route_attributes( trigger )
    count = #route_attributes

    for i = 1, count do
        if i == count and count > 1 then
            route_attributes_string = route_attributes_string .. route_attribute_type[ "and" ] .. " "
        end

        route_attributes_string = route_attributes_string .. route_attribute_type[ route_attributes[ i ] ]

        if count > 1 and i < count then
            route_attributes_string = route_attributes_string .. ", "
        end
    end

    if route_attributes_string ~= "" then
        set_result_id( 1, "x" )
        set_result_id( 2, "r" )
    end

    if ( trigger == "ROUTE_ATTRIBUTES_VIOLATION" ) then
        set_result_id( 3, "v" )
    elseif ( trigger == "ROUTE_ATTRIBUTES_NOTIFICATION" ) then
        set_result_id( 3, "n" )
    elseif ( trigger == "SEGMENT_ATTRIBUTES_NOTIFICATION" ) then
        set_result_id( 3, "s" )
    end
end


-- determine which traffic notification prompt to use based on the value of the "delay" field
function process_traffic_notification( )
    set_result_id( 1, "x" )
    set_result_id( 2, "t" )
    if ( delay == 0 ) then
        used_time_unit = time_unit["UNDEFINED"]
        if ( route_recalculated ) then
            if ( user_confirmation ) then
                set_result_id( 3, "c" )
            else
                set_result_id( 3, "b" )
            end
        else
            -- if the route recalculation failed, no user confirmation is required
            if ( not user_confirmation ) then
                set_result_id( 3, "e" )
            end
        end
    else
        if ( delay == 1 ) then
            used_time_unit = time_unit["MINUTE"]
        else
            used_time_unit = time_unit["MINUTES"]
        end
        if ( route_recalculated ) then
            if ( user_confirmation ) then
                set_result_id( 3, "d" )
            end
        else
            -- if the route recalculation failed, no user confirmation is required
            if ( not user_confirmation ) then
                set_result_id( 3, "a" )
            end
        end
    end
end


-- construct the TMC notification
function process_tmc_notification( )
    -- if no street name is available attempt to use the route name
    if ( street ~= nil and street ~= "" ) then
        tts_street_1 = street
    elseif ( route ~= nil and route ~= "" ) then
        tts_street_1 = route
    end
    set_result_id( 1, "x" )
    set_result_id( 2, "m" )
    -- if no street name or route name is available do not use it in the prompt
    if ( tts_street_1 == nil or tts_street_1 == "" ) then
        set_result_id( 3, "n" )
    else
        set_result_id( 3, "s" )
    end
    if ( distance == 1 ) then
        usedUnit_1 = unit_after["METER"]
    else
        usedUnit_1 = unit_after["METERS"]
    end
    distance_1 = tostring( distance )
end


-- constructs the prompt for reaching the off-road target
function process_offroad_action( trigger )
    set_result_id( 1, "x" )
    set_result_id( 2, "o" )
    if ( trigger == "OFFROAD_ACTION_START" ) then
        set_result_id( 3, "s" )
    elseif ( trigger == "OFFROAD_ACTION_DESTINATION" ) then
        set_result_id( 3, "d" )
    elseif ( trigger == "OFFROAD_ACTION_DESTINATION_AREA" ) then
        set_result_id( 3, "a" )
    elseif ( trigger == "OFFROAD_ACTION_DESTINATION_ARROW" ) then
        set_result_id( 3, "r" )
    elseif ( trigger == "OFFROAD_ACTION_STOPOVER" ) then
        set_result_id( 3, "v" )
    end
end


-- constructs the prompt for route recalculation
function process_route_recalculation( is_recalculation_automatic )
    set_result_id( 1, "x" )
    set_result_id( 2, "r" )
    if ( is_recalculation_automatic == true ) then
        set_result_id( 3, "a" )
    else
        set_result_id( 3, "m" )
    end
end


-- construct the prompt for inactive guidance
function process_guidance_inactive( )
    set_result_id( 1, "x" )
    set_result_id( 2, "g" )
    set_result_id( 3, "i" )
end
