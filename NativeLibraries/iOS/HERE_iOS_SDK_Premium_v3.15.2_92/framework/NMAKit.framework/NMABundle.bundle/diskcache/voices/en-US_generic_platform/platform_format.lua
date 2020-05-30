-- ----------------------------------------------------------------------------
-- Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
-- All rights reserved.
-- The use of this software is conditional upon having a separate agreement
-- with a HERE company for the use or utilization of this software. In the
-- absence of such agreement, the use of the software is not allowed.
-- ----------------------------------------------------------------------------
--      Author: Dirk Huppermann, Bill King
-- ----------------------------------------------------------------------------
--      Output format for Nuance Engine
--      0.4.0.XXX


_package_settings["phonemeset"] = "NT-SAMPA"

marc_to_nuance = {
    ["010"] = "ENU",     -- English (US)
    ["051"] = "FRC",     -- French (Canada)
    ["076"] = "PTB",     -- Portuguese (Brazil)
    ["083"] = "SPM",     -- Spanish (Mexico)
    ["CZE"] = "CZC",     -- Czech
    ["DAN"] = "DAD",     -- Danish
    ["ENG"] = "ENG",     -- English (UK)
    ["FIN"] = "FIF",     -- Finnish
    ["FRE"] = "FRF",     -- French
    ["GER"] = "GED",     -- German
    ["IND"] = "IDI",     -- Bahasa Indonesian
    ["ITA"] = "ITI",     -- Italian
    ["KOR"] = "KOK",     -- Korean
    ["NOR"] = "NON",     -- Norwegian
    ["POL"] = "PLP",     -- Polish
    ["POR"] = "PTP",     -- Portuguese
    ["RUS"] = "RUR",     -- Russian
    ["SPA"] = "SPE",     -- Spanish
    ["SWE"] = "SWS",     -- Swedish
    ["TUR"] = "TRT",     -- Turkish
    ["CHT"] = "MNT",     -- Mandarin (Taiwan)
}

phoneme_lang_to_nuance = {
    ["APS"] = "SPE",     -- Altiplano Spanish
    ["ARS"] = "SPA",     -- Argentine Spanish
    ["AUE"] = "ENA",     -- Australian English
    ["BAQ"] = "BAE",     -- Basque
    ["BFR"] = "FRF",     -- Belgian French
    ["BGR"] = "GED",     -- Belgian German
    ["BRA"] = "PTB",     -- Brazilian Portuguese
    ["CAT"] = "CAE",     -- Catalan
    ["CFR"] = "FRC",     -- Canadian French
    ["CLS"] = "SPA",     -- Chilean Spanish
    ["CZE"] = "CZC",     -- Czech
    ["DAN"] = "DAD",     -- Danish
    ["DUT"] = "DUN",     -- Dutch
    ["ENG"] = "ENU",     -- US English
    ["FIN"] = "FIF",     -- Finnish
    ["FLM"] = "DUB",     -- Belgian Dutch
    ["FRE"] = "FRF",     -- French
    ["FSW"] = "SWS",     -- Finland Swedish
    ["GCS"] = "SPM",     -- (Gran) Colombia Spanish
    ["GER"] = "GED",     -- German
    ["GFA"] = "ARW",     -- (Gulf) Arabic
    ["GJE"] = "ENG",     -- Gujarati English
    ["GLG"] = "PTP",     -- Galician
    ["GRE"] = "GRG",     -- Greek
    ["HEB"] = "ENU",     -- Hebrew
    ["HUN"] = "HUH",     -- Hungarian
    ["IDE"] = "ENG",     -- Indian English
    ["IND"] = "ENG",     -- Bahasa Indonesian
    ["IRE"] = "ENE",     -- Irish English
    ["ITA"] = "ITI",     -- Italian
    ["LFR"] = "FRF",     -- Luxembourg French
    ["LGR"] = "GED",     -- Luxembourg German
    ["LIE"] = "GED",     -- Liechtenstein German
    ["LVA"] = "ARW",     -- Levantine Arabic
    ["MAY"] = "ENG",     -- Bahasa Malaysia
    ["NAS"] = "SPM",     -- North American Spanish
    ["NOR"] = "NON",     -- Norwegian
    ["NZE"] = "ENA",     -- New Zealand English
    ["POL"] = "PLP",     -- Polish
    ["POR"] = "PTP",     -- Portuguese
    ["RUS"] = "RUR",     -- Russian
    ["SAE"] = "ENZ",     -- South Africa English
    ["SEN"] = "ENG",     -- Singapore English
    ["SFR"] = "FRF",     -- Swiss French
    ["SGR"] = "GED",     -- Swiss German
    ["SIT"] = "ITI",     -- Swiss Italian
    ["SLO"] = "SKS",     -- Slovak
    ["SPA"] = "SPE",     -- Spanish
    ["SWE"] = "SWS",     -- Swedish
    ["THA"] = "THT",     -- Thai
    ["THE"] = "ENG",     -- Thai English
    ["TME"] = "ENG",     -- Tamil English
    ["TUR"] = "TRT",     -- Turkish
    ["TWN"] = "MNT",     -- Chinese Mandarin Taiwan
    ["UKE"] = "ENG",     -- UK English
    ["UKR"] = "RUR"      -- Ukrainian
}

function nuance_formatter( orthotext, phoneme, language, article, add_address_tags )
    
    local result = ""
    local do_shorten, value = can_shorten( article, orthotext )
    local ortho_article = value.ortho
    local phonetic_article = value.phoneme

    if language == "IND" and marc_code == "IND" then
        use_phoneticdata = false
    end
    if use_phoneticdata
        and phoneme ~= nil
        and phoneme ~= ""
    then
        -- for NT-SAMPA phonemes
        if do_shorten == true then
            result = "<ESC>\\toi=nts:\"" .. ortho_article .. orthotext .. "\"\\".. phonetic_article .. phoneme.."<ESC>\\toi=orth\\"
        else
            if ortho_article ~= nil and ortho_article ~= "" then
                result = ortho_article .. " <ESC>\\toi=nts:\"" .. orthotext .. "\"\\".. phoneme.."<ESC>\\toi=orth\\"
            else
                result = "<ESC>\\toi=nts:\"" .. orthotext .. "\"\\".. phoneme.."<ESC>\\toi=orth\\"
            end
        end
        if language ~= nil and string.len(language) == 3  and result ~= "" then
            local dest_lang = phoneme_lang_to_nuance[language] or 'ENU'
            local orig_lang = marc_to_nuance[marc_code] or ''
            if dest_lang ~= orig_lang then
                result = "<ESC>\\lang="..dest_lang.."\\" .. result .. "<ESC>\\lang="..orig_lang.."\\"
            end
        end
    else
        if do_shorten == true then
            result = ortho_article .. orthotext
        else
            if ortho_article ~= nil and ortho_article ~= "" then
                result = ortho_article .. " " .. orthotext
            else
                result = orthotext
            end
        end
    end
    if result ~= "" then
        if add_address_tags == true then
            return "!ADDRESS_MODE!" .. result .. "!NORMAL_MODE!"
        else
            return result
        end
    else
        return ""
    end
end

function raw_formatter( orthotext, phoneme, language, article, add_address_tags )
    return nuance_formatter( orthotext, nil, language, article, false )
end

local OUTPUT_FORMATTERS = {
    ["raw"] = raw_formatter,           -- Raw
    ["nuance"] = nuance_formatter,     -- Nuance
}

function set_result( id )
    local tts_output_format = voice_settings["tts_output_format"]
    if tts_output_format == nil then
        tts_output_format = "nuance"
    end
    local output_formatter = OUTPUT_FORMATTERS[tts_output_format]

    if nonTTS and double_command and id == command_id_1 and commands_double[ id ] ~= nil and commands_double[ id ] ~= "" then
        result_sentence = commands_double[ id ]
    elseif guidance_mode == "pedestrian" and commands_ped[ id ] ~= nil and commands_ped[ id ] ~= "" then
        result_sentence = commands_ped[ id ]
    else
        result_sentence = commands_common[ id ]
    end

    if result_sentence ~= nil and result_sentence ~= "" and not nonTTS then

        tts_street_1 = build_streetname(tts_street_1, result_sentence, output_formatter)
        tts_street_2 = build_streetname(tts_street_2, result_sentence, output_formatter)

        tts_signpost_1 = build_signpost(tts_signpost_1, result_sentence, output_formatter)
        tts_signpost_2 = build_signpost(tts_signpost_2, result_sentence, output_formatter)

        tts_exit_number = build_signpost(tts_exit_number, result_sentence, output_formatter)

        natural_guidance_terms = provide_natual_guidance( {maneuver, nextManeuver}, output_formatter)

        result_sentence, trash = string.gsub ( result_sentence, "!PED_TURN_NO!", ped_turn_no )
        result_sentence, trash = string.gsub ( result_sentence, "!DIST!", distance_1 )
        result_sentence, trash = string.gsub ( result_sentence, "!UNIT!", usedUnit_1 )
        result_sentence, trash = string.gsub ( result_sentence, "!STREET!", escape_string(tts_street_1) )
        result_sentence, trash = string.gsub ( result_sentence, "!STREET_2!", escape_string(tts_street_2) )
        result_sentence, trash = string.gsub ( result_sentence, "!SIGNPOST!", escape_string(tts_signpost_1) )
        result_sentence, trash = string.gsub ( result_sentence, "!SIGNPOST_2!", escape_string(tts_signpost_2) )
        result_sentence, trash = string.gsub ( result_sentence, "!EXIT_NO_ROUNDABOUT!", exit_no_roundabout )
        result_sentence, trash = string.gsub ( result_sentence, "!ORIENTATION!", head_orientation )
        result_sentence, trash = string.gsub ( result_sentence, "!NG_COMMAND_1!", escape_string(natural_guidance_terms[1]) )
        result_sentence, trash = string.gsub ( result_sentence, "!NG_COMMAND_2!", escape_string(natural_guidance_terms[2]) )
        result_sentence, trash = string.gsub ( result_sentence, "!EXIT_NUMBER!", escape_string(tts_exit_number) )
        result_sentence, trash = string.gsub ( result_sentence, "!ROUTE_ATTRIBUTES!", escape_string(route_attributes_string) )
        
        -- replace the delay only if the prompt requires it
        if string.find( result_sentence, "!DELAY_MINUTES_NUMBER!" ) then
            result_sentence, trash = string.gsub ( result_sentence, "!DELAY_MINUTES_NUMBER!", delay )
        end
        
        -- replace the time unit only if the prompt requires it
        if string.find( result_sentence, "!TIME_UNIT!" ) then
            result_sentence, trash = string.gsub ( result_sentence, "!TIME_UNIT!", used_time_unit )
        end

        -- replace <break> in between phonemes with 30 ms pause
        if ( string.find( result_sentence, "<break>" ) ) then

            -- first remove orthographic fallback if present
            result_sentence, trash = string.gsub ( result_sentence, "<ESC>\\toi=nts:\"([^<]-)\"\\([^<]-)<break>(.-)", "<ESC>\\toi=nts\\%2<break>%3" )

            -- then replace any breaks with pauses
            result_sentence, trash = string.gsub ( result_sentence, "<break>", "<ESC>\\toi=orth\\ !BREAK:30! <ESC>\\toi=nts\\" )            
        end

        -- insert comma between two consecutive phonemes( e.g. between the exit_number and exit_name )
        result_sentence, trash = string.gsub(result_sentence, "!NORMAL_MODE! !ADDRESS_MODE!", ", ")

        -- called from ruleset.lua
        result_sentence = languageSpecificMods( result_sentence )

        -- replacement of general tags with Nuance specific tags
        result_sentence, trash = string.gsub ( result_sentence, "!FREQUENCY!", frequency )

        if string.find( result_sentence, "!SET_AUDIO!" ) then
            audio_start = '<ESC>\\audio="'..audio_files_path_absolute..package.config:sub(1, 1)
            audio_end = "\"\\"
            result_sentence, trash = string.gsub ( result_sentence, "!SET_AUDIO!(.+)!SET_AUDIO!", audio_start.."%1"..audio_end )
        end

        if tts_output_format == "raw" then
            -- removing BREAK tags for raw TTS output format
            result_sentence, trash = string.gsub ( result_sentence, "!BREAK!", "" )
            result_sentence, trash = string.gsub ( result_sentence, "!BREAK:(%d-)!", "")
        else
            -- replace default BREAK with 100 ms pause
            result_sentence, trash = string.gsub ( result_sentence, "!BREAK!", "<ESC>\\pause=100\\" )

            -- replace custom BREAK with a pause of specified value
            while string.find( result_sentence, "!BREAK:" ) do
                pauseTime, trash = string.gsub(result_sentence, ".+!BREAK:(%d+).+", "%1")
                result_sentence, trash = string.gsub ( result_sentence, "!BREAK:"..pauseTime.."!", "<ESC>\\pause="..pauseTime.."\\", 1)
            end
        end

        result_sentence, trash = string.gsub ( result_sentence, "!NORMAL_MODE!", "<ESC>\\tn=normal\\" )
        result_sentence, trash = string.gsub ( result_sentence, "!ADDRESS_MODE!", "<ESC>\\tn=address\\" )
        result_sentence, trash = string.gsub( result_sentence, "<ESC>", "")
        
        -- general clean-up of the prompt
        while true do
            result_sentence, b_use = string.gsub ( result_sentence, "  ", " " )
            if b_use == 0 then
                break
            end
        end

        if ( string.byte(result_sentence,-1) == 32 ) then
            result_sentence = string.sub( result_sentence, 1, -2 )
        end

        result_sentence, trash = string.gsub( result_sentence, " ,", "," )

        -- trim front and back
        result_sentence, trash = string.gsub(result_sentence, "^(%s+)(.+)(%s*)$", "%2")

    end

    return result_sentence

end

function set_result_tts( )

    if double_command then
        if sentence_1 ~= "" and sentence_1 ~= " " and sentence_1 ~= nil then
            result_sentence = sentence_1.." "..sentence_2
        else
            result_sentence = ""
        end
    else
        if sentence_1 ~= "" and sentence_1 ~= " " and sentence_1 ~= nil then
            result_sentence = sentence_1
        else
            result_sentence = ""
        end
    end

    result_sentence, b_use = string.gsub ( result_sentence, "  ", "" )

    if ( string.byte( result_sentence, -1 ) == 32 ) then
        result_sentence = string.sub( result_sentence, 1, -2 )
    end

    result_sentence = string.upper( string.sub( result_sentence, 1, 1 ) )..string.sub( result_sentence, 2 )
    
    -- remove comma from the end of the sentence (useful when natural guidance elements are added to the prompt)
    result_sentence, count = string.gsub( result_sentence, ",$", "")

    result_sentence, count = string.gsub( result_sentence, '(audio=\\"[%a%d]+.wav"\\)'..'(%.)', "%1" )
    result_sentence, count = string.gsub( result_sentence, ',%p', "." ) -- Shouldn't have to handle this, have a pre-check.
    table.insert( result_list, result_sentence)

end

function set_result_wave( )

    for _,v in pairs(sentence_1) do
        table.insert( result_list, v )
    end

    if double_command then
        for _,v in pairs(sentence_2) do
            table.insert( result_list, v )
        end
    end

end
