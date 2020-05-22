local utils = {}


function utils.inside(value, array)
    for _, item in ipairs(array) do
        if value == item then
            return true
        end
    end
    return false
end


function utils.keys(dict)
    local keys = {}
    for key, _ in pairs(dict) do
        table.insert(keys, key)
    end
    return keys
end


function utils.contains(table, element, casesensitive)
    for _, value in pairs(table) do
        if casesensitive == true then
            if value == element then
                return true
            end
        else
            if value:lower() == element:lower() then
                return true
            end
        end
    end
    return false
end


function utils.copy_table(table)
    local copy = {}
    for key, value in pairs(table) do
        if type(value) == 'table' then
            copy[key] = utils.copy_table(value)
        else
            copy[key] = value
        end
    end
    return copy
end


function utils.copy_attributes(table, attributes_array)
    local copy = {}
    for _, key in ipairs(attributes_array) do
        local value = table[key]
        if type(value) == 'table' then
            copy[key] = utils.copy_table(value)
        else
            copy[key] = value
        end
    end
    return copy
end


function utils.create_filtered_array(elements_array, filter)
    local result_array = {}
    for _, element in ipairs(elements_array) do
        if filter(element) then
            table.insert(result_array, element)
        end
    end
    if #result_array > 0 then return result_array end
    return nil
end


return utils
