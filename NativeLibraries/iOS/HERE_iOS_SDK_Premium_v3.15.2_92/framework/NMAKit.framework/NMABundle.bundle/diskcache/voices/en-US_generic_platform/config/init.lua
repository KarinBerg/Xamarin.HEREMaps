local config = {}

function config.get_selection_rules(rules)
    local result = {}
    for key, value in pairs(rules) do
        result[key] = value
    end
    return result
end

return config
