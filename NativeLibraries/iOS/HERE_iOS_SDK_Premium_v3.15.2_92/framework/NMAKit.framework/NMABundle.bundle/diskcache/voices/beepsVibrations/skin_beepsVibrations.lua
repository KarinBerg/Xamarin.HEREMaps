-- ----------------------------------------------------------------------------
-- Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
-- All rights reserved.
-- The use of this software is conditional upon having a separate agreement
-- with a HERE company for the use or utilization of this software. In the
-- absence of such agreement, the use of the software is not allowed.
-- ----------------------------------------------------------------------------
--             Voice Skin: beepsVibrations

description = "" 
output_type = "audio"
speaker = ""
gender = "f"                         -- without gender
travel_mode = "2"                -- only walk
language = "Beeps and Vibrations"
marc_code = ""
language_id = "1"
id = "1003"                         
config_file = "beepsVibrations/config.lua"
audio_files_path = "beepsVibrations/beepsVibrations"
audio_files_version = "0.3.0.20110622"
feature_list = { "metric", "imperial_uk", "" }
client_range = "[client >= 1.4.6.0 ]"


distances = {  }

misc =  {  

[ "beep_sound" ] = "beep"

}

check_files = { misc }
