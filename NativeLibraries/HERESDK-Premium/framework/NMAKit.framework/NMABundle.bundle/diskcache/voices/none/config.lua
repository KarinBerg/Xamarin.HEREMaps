-- ----------------------------------------------------------------------------
-- Copyright (c) 2012-2020 HERE Global B.V. and its affiliate(s).
-- All rights reserved.
-- The use of this software is conditional upon having a separate agreement
-- with a HERE company for the use or utilization of this software. In the
-- absence of such agreement, the use of the software is not allowed.
-- ----------------------------------------------------------------------------
--             Voice Skin:  NONE

function get_text_output()
end

function get_voicefiles()

	-- Safety SpotWarner
	if trigger == "SAFETYSPOT_WARNER" then
		table.insert(result_list, misc[ "beep_sound" ] )
	end

	-- Speed Warners triggers
	if trigger == "SPEED_WARNER" then
		table.insert(result_list, misc[ "over_speed_limit_wav" ] )
	end

end
