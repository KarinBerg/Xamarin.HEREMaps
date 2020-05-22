local rules = {}


-- =================== Rules for natural guidance element selection ============

-- decision about whether natural guidance should be used for given type and category
rules.natural_guidance_type_allowed = { Attribute = 'type',
                                        Values = { ['traffic_light'] = { Setting = true },
                                                   ['stop_sign'] = { Setting = true },
                                                   ['t-junction'] = { Setting = true },
                                                   ['pois'] = { Setting = true },
                                                   ['misc'] = { Setting = true },
                                                   ['*'] = { Setting = false } } }

-- minimum importance value for given type
rules.natural_guidance_importance_threshold = { Attribute = 'type',
                                                Values = { ['*'] = { Setting = 6 } } }

-- maximum count value for given type (applicable for traffic lights and stop signs)
rules.natural_guidance_count_threshold = { Attribute = 'type',
                                           Values = { ['*'] = { Setting = 3 } } }

-- decision about whether natural guidance should be used for given street_side and maneuver turn
-- (allow elements only if street side matches turning side )
rules.street_side_filter = { Attribute = 'street_side',
                             Values = { ['LEFT'] = { Attribute = 'turn',
                                                     Values = { ['HEAVY_LEFT'] = { Setting = true },
                                                                ['QUITE_LEFT'] = { Setting = true },
                                                                ['LIGHT_LEFT'] = { Setting = true },
                                                                ['KEEP_LEFT'] = { Setting = true },
                                                                ['*'] = { Setting = false } } },
                                        ['RIGHT'] = { Attribute = 'turn',
                                                     Values = { ['HEAVY_RIGHT'] = { Setting = true },
                                                                ['QUITE_RIGHT'] = { Setting = true },
                                                                ['LIGHT_RIGHT'] = { Setting = true },
                                                                ['KEEP_RIGHT'] = { Setting = true },
                                                                ['*'] = { Setting = false } } } } }

-- decision about whether natural guidance should be used for given intersection_side
rules.intersection_side_filter = { Attribute = 'intersection_side',
                                   Values = { ['*'] = { Setting = true } } }


-- elements sorted in descending priority order
rules.natural_guidance_elements_priority_order = { Setting = { 't-junction',
                                                               'traffic_light',
                                                               'stop_sign',
                                                               { 'pois', 'misc' } } }


-- ================= Rules for natural guidance attribute selection ============

-- attributes map for pois and misc elements
local extended_attributes_map = {
    ['name'] = 'preferred_name',
    ['name_lang'] = 'preferred_name_lang',
    ['name_phoneme_nt_sampa'] = 'preferred_name_phoneme_nt_sampa',
    ['name_phoneme_nt_sampa_lang'] = 'preferred_name_phoneme_nt_sampa_lang',
    ['name_preposition'] = 'preferred_name_preposition'
}

-- Rules for attribute selection: map returned element attributes to attributes from natural guidance map
rules.element_selection_attributes = { Attribute = 'type',
                                       Values = { ['traffic_light'] = { Setting = { ['count'] = 'count' } },
                                                  ['stop_sign'] = { Setting = { ['count'] = 'count' } },
                                                  ['pois'] = { Setting = extended_attributes_map },
                                                  ['misc'] = { Setting = extended_attributes_map },
                                                  ['*'] = { Setting = {} } } }

return rules
