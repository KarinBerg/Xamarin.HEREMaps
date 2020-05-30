-- ----------------------------------------------------------------------------
-- Copyright (c) 2009-2020 HERE Global B.V. and its affiliate(s).
-- All rights reserved.
-- The use of this software is conditional upon having a separate agreement
-- with a HERE company for the use or utilization of this software. In the
-- absence of such agreement, the use of the software is not allowed.
-- ----------------------------------------------------------------------------

function get_common_code( )

    -- Pedestrian command
    if trigger == "PEDESTRIAN_COMMAND" then
        table.insert(result_list, misc[ "beep_sound" ] )   
    end
    
    if trigger == "ROUTE_RECALCULATION" then
        -- "Route recalculation"
        table.insert( result_list, misc[ "beep_sound" ] )
    end

end

