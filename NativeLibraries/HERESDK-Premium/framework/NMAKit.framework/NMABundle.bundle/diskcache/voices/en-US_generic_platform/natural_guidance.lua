local utils = require 'content.utils'

local natural_guidance = {}
local internal = {}

-- Ported from src_proto
local common = {}

function common.get_config_value(config_table, attribute_table)
    if not config_table or not attribute_table then return nil end
    local config = config_table
    while not utils.inside('Setting', utils.keys(config)) do
        local attribute = config['Attribute']
        local value = attribute_table[attribute]
        if not value then return nil end
        if utils.inside(value, utils.keys(config['Values'])) then
            config = config['Values'][value]
        elseif utils.inside('*', utils.keys(config['Values'])) then
            config = config['Values']['*']
        else return nil end
    end
    return config['Setting']
end


function internal.filter_elements(maneuver, voice_settings)
    local filtered_elements_table = {}
    for key, value in pairs(maneuver.natural_guidance) do
        if type(value) == 'table' then
            local info = {type = key}
            if #value > 0 then
                local filter = function (item)
                    local extended_info = {
                        type = key,
                        category = item.type,
                        turn = maneuver.turn
                    }
                    return internal.use_array_element(item, extended_info, voice_settings)
                end
                filtered_elements_table[key] = utils.create_filtered_array(value, filter)
            elseif internal.use_element(value, info, voice_settings) then
                filtered_elements_table[key] = value
            end
        end
    end
    return filtered_elements_table
end


function internal.select_top_priority_and_importance_element(elements_table)
    local prioritized_array = common.get_config_value(internal.rules.natural_guidance_elements_priority_order, {})
    if type(prioritized_array) ~= 'table' then return nil end

    local filtered_element = nil
    for _, value in ipairs(prioritized_array) do
        if type(value) == 'table' then
            local filter = function(item)
                return elements_table[item] ~= nil
            end
            local same_priority_filtered_keys = utils.create_filtered_array(value, filter)
            if same_priority_filtered_keys ~= nil then
                return internal.select_top_importance_element(
                    utils.copy_attributes(elements_table, same_priority_filtered_keys))
            end
        elseif elements_table[value] ~= nil then
            filtered_element = elements_table[value]
            if #filtered_element > 0 then
                filtered_element = internal.select_top_importance_element({[value] = filtered_element})
            end
            filtered_element.element_type = value
            break
        end
    end

    return filtered_element
end


function internal.select_top_importance_element(elements_table)
    local selected_element = nil
    for key, elements_array in pairs(elements_table) do
        for _, element in ipairs(elements_array) do
            element.importance = tonumber(element.importance)
            if selected_element == nil or element.importance > selected_element.importance then
               selected_element = element
               selected_element.element_type = key
            end
        end
    end
    return selected_element
end


function internal.is_allowed_in_ng_voice_settings(element_type, voice_settings)
    if (voice_settings == nil) then return true end
    local info_to_settings = {['traffic_light'] = 'nguidance_trafficlights',
                              ['stop_sign'] = 'nguidance_stop_sign',
                              ['pois'] = 'nguidance_junction',
                              ['misc'] = 'nguidance_junction'}
    if (voice_settings[info_to_settings[element_type]] == false) then return false end
    return true
end

function internal.use_element(element, info, voice_settings)
    local is_allowed_in_config = common.get_config_value(internal.rules.natural_guidance_type_allowed, info)
    local is_allowed_in_ng_voice_settings = internal.is_allowed_in_ng_voice_settings(info.type, voice_settings)
    if not (is_allowed_in_config and is_allowed_in_ng_voice_settings) then
        return false
    end

    if element.importance ~= nil then
        element.importance = tonumber(element.importance)
        local min_importance = common.get_config_value(internal.rules.natural_guidance_importance_threshold, info)
        if min_importance ~= nil and tonumber(min_importance) > element.importance then
            return false
        end
    end

    if element.count ~= nil then
        element.count = tonumber(element.count)
        local max_count = common.get_config_value(internal.rules.natural_guidance_count_threshold, info)
        if max_count ~= nil and tonumber(max_count) < element.count then
            return false
        end
    end

    return true
end


function internal.use_array_element(element, info, voice_settings)
    if not internal.use_element(element, info, voice_settings) then return false end

    if element.street_side ~= nil then
        local attributes = {street_side = element.street_side, turn = info.turn}
        local flag = common.get_config_value(internal.rules.street_side_filter, attributes)
        if not flag then return false end
    end

    if element.intersection_side ~= nil then
        local attributes = {intersection_side = element.intersection_side}
        local flag = common.get_config_value(internal.rules.intersection_side_filter, attributes)
        if not flag then return false end
    end

    return true
end


function natural_guidance.select(maneuver, rules, voice_settings)
    if type(maneuver) ~= 'table' or type(maneuver.natural_guidance) ~= 'table' then return nil end
    if (voice_settings ~= nil and voice_settings["nguidance"] == false) then return nil end

    internal.rules = rules
    local filtered_elements = internal.filter_elements(maneuver, voice_settings)

    if next(filtered_elements) == nil then return nil end

    local selected_element = internal.select_top_priority_and_importance_element(filtered_elements)

    if selected_element == nil then return nil end

    local result = {}
    local attributes = common.get_config_value(rules.element_selection_attributes,
                                               {type = selected_element.element_type})
    if type(attributes) == 'table' then
        for key, original_key in pairs(attributes) do
            result[key] = selected_element[original_key]
        end
    end
    result.element_type = selected_element.element_type
    result.importance = selected_element.importance
    return result
end


return natural_guidance
