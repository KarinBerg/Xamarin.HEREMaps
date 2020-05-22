-- ----------------------------------------------------------------------------
-- Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
-- All rights reserved.
-- The use of this software is conditional upon having a separate agreement
-- with a HERE company for the use or utilization of this software. In the
-- absence of such agreement, the use of the software is not allowed.
-- ---------------------------------------------------------------------------- 
--      Author: Dirk Huppermann, Bill King
-- ----------------------------------------------------------------------------
--             Voice Prompts: en-US English US TTS

street_article = nil -- in english no street-name articles are used.

nG_prepositions = {	-- prepositions code for natural guidance, delivered by navteq, no additional translation needed
	["ENGBAFTR"] = "after",
	["ENGBAFTT"] = "after the",
	["ENGBATXX"] = "at",
	["ENGBATTX"] = "at the",
	["ENGBBEFR"] = "before",
	["ENGBBEFT"] = "before the",
	["ENGBONTO"] = "onto",
	["ENGBONTT"] = "onto the",
	["ENGBOVER"] = "over",
	["ENGBOVRT"] = "over the",
	["ENGBPAST"] = "past",
	["ENGBPSTT"] = "past the",
	["ENGBTHRU"] = "through",
	["ENGBTHRT"] = "through the",
	["ENGBUNDR"] = "under",
	["ENGBUNDT"] = "under the",
	["NONE"] = "", -- leave this entry, it's important
}
nG_elements = { -- natural guidance traffic light command elements
	[1] = "at the next light", -- at the next traffic light
	[2] = "at the second light", -- at the second traffic light
	[3] = "at the third light", -- at the third traffic light
	["UNDEFINED"] = "",
}

unit_after = { -- Units to be used in sentences like After xx kilometers turn ...
	["MILE"] = "mile", -- mile
	["YARDS"] = "yards", -- yards
	["FEET"] = "feet", -- feet
	["KILOMETER"] = "kilometer", -- kilometer
	["METERS"] = "meters", -- meters
	["METER"] = "meter", -- meter
	["KILOMETERS"] = "kilometers", -- kilometers
	["MILES"] = "miles", -- miles
	["UNDEFINED"] = "",
}

unit_follow = { -- Units to be used in sentences like Follow the road for xx kilometers.
	["MILE"] = "mile", -- mile
	["YARDS"] = "yards", -- yards
	["FEET"] = "feet", -- feet
	["KILOMETER"] = "kilometer", -- kilometer
	["METERS"] = "meters", -- meters
	["METER"] = "meter", -- meter
	["KILOMETERS"] = "kilometers", -- kilometers
	["MILES"] = "miles", -- miles
	["UNDEFINED"] = "",
}

dist = { --
	["a"] = "one kilometer", -- one kilometer
	["b"] = "one mile", -- one mile
	["c"] = "a quarter of a mile", -- a quarter of a mile
	["d"] = "half a mile", -- half a mile
	["e"] = "three quarters of a mile", -- three quarters of a mile
	["UNDEFINED"] = "",
}

exit_number_roundabout = { -- exit numbers for roundabouts in car navigation
	[1] = "take the first exit", -- take the first exit
	[2] = "take the second exit", -- take the second exit
	[3] = "take the third exit", -- take the third exit
	[4] = "take the fourth exit", -- take the fourth exit
	[5] = "take the fifth exit", -- take the fifth exit
	[6] = "take the sixth exit", -- take the sixth exit
	[7] = "take the seventh exit", -- take the seventh exit
	[8] = "take the eighth exit", -- take the eighth exit
	[9] = "take the ninth exit", -- take the ninth exit
	[10] = "take the tenth exit", -- take the tenth exit
	[11] = "take the eleventh exit", -- take the eleventh exit
	[12] = "take the twelfth exit", -- take the twelfth exit
	["UNDEFINED"] = "",
}

orientation = { -- Heading directions for walk commands, e.g. Head north on Oxford Street
	["NORTH"] = "north", -- north
	["NORTH_EAST"] = "northeast", -- northeast
	["EAST"] = "east", -- east
	["SOUTH_EAST"] = "southeast", -- southeast
	["SOUTH"] = "south", -- south
	["SOUTH_WEST"] = "southwest", -- southwest
	["WEST"] = "west", -- west
	["NORTH_WEST"] = "northwest", -- northwest
	["UNDEFINED"] = "",
}

turn_number_ped = { -- exit numbers for roundabouts in walk navigation
	[1] = "and turn at the first street, !STREET!", -- and turn at the first street !STREET!
	[2] = "and turn at the second street, !STREET!", -- and turn at the second street !STREET!
	[3] = "and turn at the third street, !STREET!", -- and turn at the third street !STREET!
	["UNDEFINED"] = "",
}

commands_common = { -- Common commands for car & ped navigation.
	-- empty command
	["00000000"] = " ",
	-- 1: !EXIT_NO_ROUNDABOUT! at the end of the road at the roundabout towards !SIGNPOST!
	["c00c0zc0"] = "!EXIT_NO_ROUNDABOUT! at the end of the road at the traffic circle towards !SIGNPOST!",
	-- 2: !EXIT_NO_ROUNDABOUT! at the end of the road at the roundabout onto !STREET!
	["c00c0zb0"] = "!EXIT_NO_ROUNDABOUT! at the end of the road at the traffic circle onto !STREET!",
	-- 3: !EXIT_NO_ROUNDABOUT! at the end of the road at the roundabout
	["c00c0z00"] = "!EXIT_NO_ROUNDABOUT! at the end of the road at the traffic circle ",
	-- 4: and then take the exit !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00d000x"] = "and then take the exit !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 5: and then enter the motorway !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00f000x"] = "and then enter the highway !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 6: and then take the exit !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00j000x"] = "and then take the exit !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 7: and then make a u turn !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00e000x"] = "and then make a u turn !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 8: and then enter the urban motorway !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00i000x"] = "and then enter the expressway !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 9: and then take the exit !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00g000x"] = "and then take the exit !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 10: and then take the middle lane !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00o000x"] = "and then take the middle lane !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 11: and then turn left !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00v000x"] = "and then turn left !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 12: and then turn slightly left !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00w000x"] = "and then bear left !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 13: and then turn sharply left !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00u000x"] = "and then make a sharp left !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 14: and then turn sharply right !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00s000x"] = "and then make a sharp right !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 15: and then turn right !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00r000x"] = "and then turn right !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 16: and then keep right !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00p000x"] = "and then keep right !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 17: and then make a u turn !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00t000x"] = "and then make a u turn !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 18: and then keep left !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00x000x"] = "and then keep left !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 19: and then turn slightly right !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!
	["h00q000x"] = "and then bear right !NG_COMMAND_2! towards !STREET_2! !SIGNPOST_2!",
	-- 20: and then !EXIT_NO_ROUNDABOUT! at the roundabout towards !STREET_2! !SIGNPOST_2!
	["h000cz0x"] = "and then !EXIT_NO_ROUNDABOUT! at the traffic circle towards !STREET_2! !SIGNPOST_2!",
	-- 21: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take the exit
	["bl0o000j"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take the exit",
	-- 22: After !DIST! !UNIT! keep left !NG_COMMAND_1! , take the exit
	["bl0x000j"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , take the exit ",
	-- 23: After !DIST! !UNIT! keep right !NG_COMMAND_1! , take the exit
	["bl0p000j"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , take the exit ",
	-- 24: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take the exit
	["bl0n000j"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take the exit",
	-- 25: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! and take the exit
	["bl0o00fj"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! and take the exit ",
	-- 26: After !DIST! !UNIT! take the exit !NG_COMMAND_1!
	["bl00000j"] = "After !DIST! !UNIT! take the exit !NG_COMMAND_1!",
	-- 27: After !DIST! !UNIT! keep left !NG_COMMAND_1! and take the exit
	["bl0x00fj"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! and take the exit ",
	-- 28: After !DIST! !UNIT! keep right !NG_COMMAND_1! and take the exit
	["bl0p00fj"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! and take the exit ",
	-- 29: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! and take the exit
	["bl0n00fj"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! and take the exit ",
	-- 30: Now take the exit !NG_COMMAND_1!
	["a000000g"] = "Now take the exit !NG_COMMAND_1!",
	-- 31: After !DIST! !UNIT! take exit !EXIT_NUMBER! towards !STREET_2! !SIGNPOST_2!
	["bl000e0x"] = "After !DIST! !UNIT! take exit !EXIT_NUMBER! towards !STREET_2! !SIGNPOST_2!",
	-- 32: Now go straight ahead !NG_COMMAND_1! , enter the urban motorway
	["a00ni000"] = "Now go straight ahead !NG_COMMAND_1! , enter the expressway ",
	-- 33: and then go straight ahead towards !STREET_2! !SIGNPOST_2!
	["h00n000x"] = "and then go straight ahead towards !STREET_2! !SIGNPOST_2!",
	-- 34: Now take the middle lane !NG_COMMAND_1! , take the exit
	["a00o000j"] = "Now take the middle lane !NG_COMMAND_1! , take the exit ",
	-- 35: Now keep left !NG_COMMAND_1! , take the exit
	["a00x000j"] = "Now keep left !NG_COMMAND_1! , take the exit ",
	-- 36: Now keep right !NG_COMMAND_1!  , take the exit
	["a00p000j"] = "Now keep right !NG_COMMAND_1!  , take the exit ",
	-- 37: Now go straight ahead !NG_COMMAND_1! and take the exit
	["a00n00fj"] = "Now go straight ahead !NG_COMMAND_1! and take the exit ",
	-- 38: Now go straight ahead !NG_COMMAND_1! , take the exit
	["a00n000j"] = "Now go straight ahead !NG_COMMAND_1! , take the exit",
	-- 39: Now take the middle lane !NG_COMMAND_1! and take the exit
	["a00o00fj"] = "Now take the middle lane !NG_COMMAND_1! and take the exit ",
	-- 40: Now take the exit !NG_COMMAND_1!
	["a000000j"] = "Now take the exit !NG_COMMAND_1!",
	-- 41: Now keep left !NG_COMMAND_1! and take the exit
	["a00x00fj"] = "Now keep left !NG_COMMAND_1! and take the exit ",
	-- 42: Now keep right !NG_COMMAND_1! and take the exit
	["a00p00fj"] = "Now keep right !NG_COMMAND_1! and take the exit",
	-- 43: Now go straight ahead !NG_COMMAND_1! and take the exit
	["a00n00fj"] = "Now go straight ahead !NG_COMMAND_1! and take the exit ",
	-- 44: and then you will reach your destination !NG_COMMAND_2! on !STREET!
	["h000ab00"] = "and then you will reach your destination !NG_COMMAND_2! on !STREET!",
	-- 45: After !DIST! !UNIT! turn left !NG_COMMAND_1! onto !STREET!
	["bl0v0d00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! onto !STREET!",
	-- 46: Now keep right !NG_COMMAND_1! , enter the urban motorway
	["a00pi000"] = "Now keep right !NG_COMMAND_1! , enter the expressway",
	-- 47: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the motorway
	["bl0nf000"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the highway",
	-- 48: After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1! on !STREET!
	["bl0a0b00"] = "After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1! on !STREET!",
	-- 49: and then immediately turn slightly right onto !STREET! towards !SIGNPOST!
	["j00q0ac0"] = "and then immediately bear right onto !STREET! towards !SIGNPOST!",
	-- 50: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl0o0edz"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 51: and then make a u turn !NG_COMMAND_2! onto !STREET!
	["h000ed00"] = "and then make a u turn !NG_COMMAND_2! onto !STREET!",
	-- 52: After !DIST! !UNIT! turn right !NG_COMMAND_1! towards !STREET!
	["bl0r0c00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! towards !STREET!",
	-- 53: and then immediately make a u turn !NG_COMMAND_2! onto !STREET!
	["j000ed00"] = "and then immediately make a u turn !NG_COMMAND_2! onto !STREET!",
	-- 54: After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl0x0edz"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 55: Now turn right !NG_COMMAND_1! , enter the motorway
	["a00rf000"] = "Now turn right !NG_COMMAND_1! , enter the highway",
	-- 56: After !DIST! !UNIT! turn left !NG_COMMAND_1! towards !STREET!
	["bl0v0c00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! towards !STREET!",
	-- 57: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! towards !STREET!
	["bl0q0c00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! towards !STREET!",
	-- 58: At the end of the road turn right !NG_COMMAND_1! , enter the motorway
	["c00rf000"] = "At the end of the road turn right !NG_COMMAND_1! , enter the highway",
	-- 59: After !DIST! !UNIT! you will reach your stopover !NG_COMMAND_1!
	["bl0b0000"] = "After !DIST! !UNIT! you will reach your stopover !NG_COMMAND_1!",
	-- 60: After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl0x0e0z"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 61: Now take the exit !NG_COMMAND_1!
	["a00d0000"] = "Now take the exit !NG_COMMAND_1!",
	-- 62: After !DIST! !UNIT! enter the motorway
	["bl00f000"] = "After !DIST! !UNIT! enter the highway",
	-- 63: and then take the exit !NG_COMMAND_2!
	["h00d0000"] = "and then take the exit !NG_COMMAND_2!",
	-- 64: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["bl0qf0c0"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 65: and then turn left !NG_COMMAND_2!
	["h00v0000"] = "and then turn left !NG_COMMAND_2!",
	-- 66: and then immediately turn left !NG_COMMAND_2!
	["j00v0000"] = "and then immediately turn left !NG_COMMAND_2!",
	-- 67: and then immediately make a u turn !NG_COMMAND_2!
	["j000e000"] = "and then immediately make a u turn !NG_COMMAND_2!",
	-- 68: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["bl0uf0c0"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 69: At the end of the road turn sharply left !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["c00ui0c0"] = "At the end of the road make a sharp left !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 70: and then make a u turn !NG_COMMAND_2!
	["h000e000"] = "and then make a u turn !NG_COMMAND_2!",
	-- 71: At the end of the road turn right !NG_COMMAND_1! onto !STREET!
	["c00r0d00"] = "At the end of the road turn right !NG_COMMAND_1! onto !STREET!",
	-- 72: and then turn right, !STREET!
	["h00r0a00"] = "and then turn right, !STREET!",
	-- 73: and then immediately take the exit !NG_COMMAND_2! towards !STREET!
	["j000dc00"] = "and then immediately take the exit !NG_COMMAND_2! towards !STREET!",
	-- 74: Now turn left !NG_COMMAND_1!
	["a00v0000"] = "Now turn left !NG_COMMAND_1!",
	-- 75: At the end of the road turn left !NG_COMMAND_1!
	["c00v0000"] = "At the end of the road turn left !NG_COMMAND_1!",
	-- 76: At the end of the road take the ferry !NG_COMMAND_1! towards !STREET!
	["c00m0c00"] = "At the end of the road take the ferry !NG_COMMAND_1! towards !STREET!",
	-- 77: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1!
	["bl0o0000"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1!",
	-- 78: After !DIST! !UNIT! keep left !NG_COMMAND_1! and take the exit
	["bl0x00fg"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! and take the exit",
	-- 79: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! towards !STREET_2! !SIGNPOST_2!
	["bl0o0e0x"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! towards !STREET_2! !SIGNPOST_2!",
	-- 80: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["bl0ofac0"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 81: Now go straight ahead !NG_COMMAND_1! and take the exit
	["a00n00fg"] = "Now go straight ahead !NG_COMMAND_1! and take the exit",
	-- 82: Now take the exit !NG_COMMAND_1! towards !STREET!
	["a00d0c00"] = "Now take the exit !NG_COMMAND_1! towards !STREET!",
	-- 83: Now keep left !NG_COMMAND_1! , take the exit
	["a00x000g"] = "Now keep left !NG_COMMAND_1! , take the exit",
	-- 84: and then you will reach your stopover !NG_COMMAND_2!
	["h000b000"] = "and then you will reach your stopover !NG_COMMAND_2!",
	-- 85: At the end of the road turn slightly right !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["c00qi0c0"] = "At the end of the road bear right !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 86: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["bl0sf0c0"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 87: After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["bl0piac0"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 88: After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST!
	["bl0x0ed0"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST!",
	-- 89: After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2!
	["bl0p0edy"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2!",
	-- 90: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["bl0ti0c0"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 91: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! onto !STREET!
	["bl0w0d00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! onto !STREET!",
	-- 92: At the end of the road turn slightly left !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["c00wi0c0"] = "At the end of the road bear left !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 93: After !DIST! !UNIT! !EXIT_NO_ROUNDABOUT! !NG_COMMAND_1! at the roundabout
	["bl0c0z00"] = "After !DIST! !UNIT! !EXIT_NO_ROUNDABOUT! !NG_COMMAND_1! at the traffic circle",
	-- 94: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! towards !STREET_2! !SIGNPOST_2!
	["bl0o0edx"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! towards !STREET_2! !SIGNPOST_2!",
	-- 95: At the end of the road make a u turn !NG_COMMAND_1!
	["c00t0000"] = "At the end of the road make a u turn !NG_COMMAND_1!",
	-- 96: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["bl0ni0c0"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 97: After the junction keep right !NG_COMMAND_1!
	["bz0p0000"] = "After the junction keep right !NG_COMMAND_1!",
	-- 98: After the junction go straight ahead !NG_COMMAND_1!
	["bz0n0000"] = "After the junction go straight ahead !NG_COMMAND_1!",
	-- 99: and then make a u turn !NG_COMMAND_2!
	["h00t0000"] = "and then make a u turn !NG_COMMAND_2!",
	-- 100: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! and take the exit
	["bl0n00fg"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! and take the exit",
	-- 101: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["bl0uiac0"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 102: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["bl0n000x"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 103: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2!
	["bl0n0edy"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2!",
	-- 104: and then immediately turn sharply right onto !STREET! towards !SIGNPOST!
	["j00s0ac0"] = "and then immediately make a sharp right onto !STREET! towards !SIGNPOST!",
	-- 105: After !DIST! !UNIT! take the ferry !NG_COMMAND_1!
	["bl0m0000"] = "After !DIST! !UNIT! take the ferry !NG_COMMAND_1!",
	-- 106: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["bl0oi0c0"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 107: At the end of the road turn left !NG_COMMAND_1! , enter the urban motorway !STREET!
	["c00via00"] = "At the end of the road turn left !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 108: and then turn sharply right !NG_COMMAND_2! towards !SIGNPOST!
	["h00s00c0"] = "and then make a sharp right !NG_COMMAND_2! towards !SIGNPOST!",
	-- 109: Now take the middle lane !NG_COMMAND_1!
	["a00o0000"] = "Now take the middle lane !NG_COMMAND_1!",
	-- 110: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2!
	["bl0o0edy"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2!",
	-- 111: At the end of the road turn slightly right !NG_COMMAND_1!
	["c00q0000"] = "At the end of the road bear right !NG_COMMAND_1!",
	-- 112: and then take the middle lane !NG_COMMAND_2!
	["h00o0000"] = "and then take the middle lane !NG_COMMAND_2!",
	-- 113: Now keep right !NG_COMMAND_1! and take the exit
	["a00p00fg"] = "Now keep right !NG_COMMAND_1! and take the exit",
	-- 114: and then immediately take the middle lane !NG_COMMAND_2!
	["j00o0000"] = "and then immediately take the middle lane !NG_COMMAND_2!",
	-- 115: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["bl0wfac0"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 116: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! towards !STREET!
	["bl0t0c00"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! towards !STREET!",
	-- 117: and then take the ferry !NG_COMMAND_2!
	["h00m0000"] = "and then take the ferry !NG_COMMAND_2!",
	-- 118: Now turn slightly right !NG_COMMAND_1!
	["a00q0000"] = "Now bear right !NG_COMMAND_1!",
	-- 119: After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the urban motorway
	["bl0ri000"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the expressway",
	-- 120: and then keep left !NG_COMMAND_2! towards !STREET!
	["h00x0c00"] = "and then keep left !NG_COMMAND_2! towards !STREET!",
	-- 121: and then immediately turn slightly right !NG_COMMAND_2! onto !STREET!
	["j00q0d00"] = "and then immediately bear right !NG_COMMAND_2! onto !STREET!",
	-- 122: After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the motorway
	["bl0rf000"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the highway",
	-- 123: After !DIST! !UNIT! make a u turn !NG_COMMAND_1!
	["bl0e0000"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1!",
	-- 124: and then enter the urban motorway !NG_COMMAND_2! towards !SIGNPOST!
	["h00i00c0"] = "and then enter the expressway !NG_COMMAND_2! towards !SIGNPOST!",
	-- 125: At the end of the road take the ferry !NG_COMMAND_1!
	["c00m0000"] = "At the end of the road take the ferry !NG_COMMAND_1!",
	-- 126: Now take the ferry !NG_COMMAND_1!
	["a00m0000"] = "Now take the ferry !NG_COMMAND_1!",
	-- 127: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! towards !STREET!
	["bl0s0c00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! towards !STREET!",
	-- 128: At the end of the road turn sharply left !NG_COMMAND_1! , enter the motorway !STREET!
	["c00ufa00"] = "At the end of the road make a sharp left !NG_COMMAND_1! , enter the highway !STREET!",
	-- 129: At the end of the road make a u turn !NG_COMMAND_1! , enter the motorway !STREET!
	["c00tfa00"] = "At the end of the road make a u turn !NG_COMMAND_1! , enter the highway !STREET!",
	-- 130: After !DIST! !UNIT! enter the motorway !STREET! towards !SIGNPOST!
	["bl00fac0"] = "After !DIST! !UNIT! enter the highway !STREET! towards !SIGNPOST!",
	-- 131: and then enter the urban motorway !STREET! towards !SIGNPOST!
	["h00i0ac0"] = "and then enter the expressway !STREET! towards !SIGNPOST!",
	-- 132: and then immediately take the middle lane !NG_COMMAND_2! towards !SIGNPOST!
	["j00o00c0"] = "and then immediately take the middle lane !NG_COMMAND_2! towards !SIGNPOST!",
	-- 133: and then take the middle lane !NG_COMMAND_2! onto !STREET!
	["h00o0d00"] = "and then take the middle lane !NG_COMMAND_2! onto !STREET!",
	-- 134: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER!
	["bl0o0e00"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER!",
	-- 135: After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the urban motorway !STREET!
	["bl0via00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 136: At the end of the road turn sharply left !NG_COMMAND_1! , enter the motorway
	["c00uf000"] = "At the end of the road make a sharp left !NG_COMMAND_1! , enter the highway",
	-- 137: Now turn sharply left !NG_COMMAND_1! , enter the motorway
	["a00uf000"] = "Now make a sharp left !NG_COMMAND_1! , enter the highway",
	-- 138: After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST!
	["bl0p0ed0"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST!",
	-- 139: and then immediately enter the urban motorway !NG_COMMAND_2!
	["j000i000"] = "and then immediately enter the expressway !NG_COMMAND_2!",
	-- 140: At the end of the road turn left !NG_COMMAND_1! , enter the motorway !STREET!
	["c00vfa00"] = "At the end of the road turn left !NG_COMMAND_1! , enter the highway !STREET!",
	-- 141: and then enter the urban motorway !NG_COMMAND_2!
	["h000i000"] = "and then enter the expressway !NG_COMMAND_2!",
	-- 142: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["bl0qfac0"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 143: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1!
	["bl0w0000"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1!",
	-- 144: Now enter the urban motorway
	["a000i000"] = "Now enter the expressway",
	-- 145: After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the urban motorway !STREET!
	["bl0xia00"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 146: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST!
	["bl0n0ed0"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST!",
	-- 147: and then immediately turn sharply left !NG_COMMAND_2! towards !SIGNPOST!
	["j00u00c0"] = "and then immediately make a sharp left !NG_COMMAND_2! towards !SIGNPOST!",
	-- 148: Now go straight ahead !NG_COMMAND_1! , take the exit
	["a00n000g"] = "Now go straight ahead !NG_COMMAND_1! , take the exit",
	-- 149: At the end of the road turn sharply left !NG_COMMAND_1! , enter the urban motorway !STREET!
	["c00uia00"] = "At the end of the road make a sharp left !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 150: and then turn sharply left !NG_COMMAND_2! towards !SIGNPOST!
	["h00u00c0"] = "and then make a sharp left !NG_COMMAND_2! towards !SIGNPOST!",
	-- 151: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! onto !STREET!
	["bl0s0d00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! onto !STREET!",
	-- 152: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the motorway
	["bl0tf000"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the highway",
	-- 153: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1!
	["bl0q0000"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1!",
	-- 154: and then take the exit !NG_COMMAND_2!
	["h00g0000"] = "and then take the exit !NG_COMMAND_2!",
	-- 155: At the end of the road turn sharply right !NG_COMMAND_1!
	["c00s0000"] = "At the end of the road make a sharp right !NG_COMMAND_1!",
	-- 156: and then make a u turn !NG_COMMAND_2!
	["h00e0000"] = "and then make a u turn !NG_COMMAND_2!",
	-- 157: Now turn sharply right !NG_COMMAND_1!
	["a00s0000"] = "Now make a sharp right !NG_COMMAND_1!",
	-- 158: and then immediately keep right !NG_COMMAND_2! onto !STREET!
	["j00p0d00"] = "and then immediately keep right !NG_COMMAND_2! onto !STREET!",
	-- 159: At the end of the road make a u turn !NG_COMMAND_1!
	["c00e0000"] = "At the end of the road make a u turn !NG_COMMAND_1!",
	-- 160: and then turn sharply right !NG_COMMAND_2!
	["h00s0000"] = "and then make a sharp right !NG_COMMAND_2!",
	-- 161: At the end of the road turn sharply left !NG_COMMAND_1! towards !STREET!
	["c00u0c00"] = "At the end of the road make a sharp left !NG_COMMAND_1! towards !STREET!",
	-- 162: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["bl0tf0c0"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 163: At the end of the road turn slightly left !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["c00wfac0"] = "At the end of the road bear left !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 164: At the end of the road turn slightly left !NG_COMMAND_1! , enter the urban motorway
	["c00wi000"] = "At the end of the road bear left !NG_COMMAND_1! , enter the expressway",
	-- 165: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the motorway !STREET!
	["bl0ofa00"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the highway !STREET!",
	-- 166: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the urban motorway
	["bl0ti000"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the expressway",
	-- 167: At the end of the road turn slightly right !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["c00qiac0"] = "At the end of the road bear right !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 168: Now turn right !NG_COMMAND_1! take the exit
	["a00r000g"] = "Now turn right !NG_COMMAND_1! take the exit",
	-- 169: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , enter the urban motorway
	["bl0qi000"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , enter the expressway",
	-- 170: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! onto !STREET!
	["bl0q0d00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! onto !STREET!",
	-- 171: After !DIST! !UNIT! keep right !NG_COMMAND_1! and take the exit
	["bl0p00fg"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! and take the exit",
	-- 173: At the end of the road turn sharply right !NG_COMMAND_1! towards !STREET!
	["c00s0c00"] = "At the end of the road make a sharp right !NG_COMMAND_1! towards !STREET!",
	-- 174: Now turn left !NG_COMMAND_1! , enter the urban motorway
	["a00vi000"] = "Now turn left !NG_COMMAND_1! , enter the expressway",
	-- 175: At the end of the road turn left !NG_COMMAND_1! , enter the urban motorway
	["c00vi000"] = "At the end of the road turn left !NG_COMMAND_1! , enter the expressway",
	-- 176: Now turn left !NG_COMMAND_1! and take the exit
	["a00v00fg"] = "Now turn left !NG_COMMAND_1! and take the exit",
	-- 177: After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the motorway !STREET!
	["bl0xfa00"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the highway !STREET!",
	-- 178: After !DIST! !UNIT! !EXIT_NO_ROUNDABOUT! at the roundabout  towards !SIGNPOST!
	["bl0c0zc0"] = "After !DIST! !UNIT! !EXIT_NO_ROUNDABOUT! at the traffic circle  towards !SIGNPOST!",
	-- 179: At the end of the road make a u turn !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["c00tf0c0"] = "At the end of the road make a u turn !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 180: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["bl0si0c0"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 181: At the end of the road you will reach your stopover !NG_COMMAND_1! on !STREET!
	["c00b0b00"] = "At the end of the road you will reach your stopover !NG_COMMAND_1! on !STREET!",
	-- 182: After the junction turn slightly left !NG_COMMAND_1!
	["bz0w0000"] = "After the junction bear left !NG_COMMAND_1!",
	-- 183: At the end of the road turn slightly right !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["c00qfac0"] = "At the end of the road bear right !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 184: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1!
	["bl0s0000"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1!",
	-- 185: and then turn left !STREET! towards !SIGNPOST!
	["h00v0ac0"] = "and then turn left !STREET! towards !SIGNPOST!",
	-- 186: and then keep right, !STREET!
	["h00p0a00"] = "and then keep right !STREET!",
	-- 187: At the end of the road turn sharply right !NG_COMMAND_1! , enter the urban motorway on !STREET! towards !SIGNPOST!
	["c00siac0"] = "At the end of the road make a sharp right !NG_COMMAND_1! , enter the expressway on !STREET! towards !SIGNPOST!",
	-- 188: At the end of the road turn left !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["c00vf0c0"] = "At the end of the road turn left !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 189: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the motorway !STREET!
	["bl0tfa00"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the highway !STREET!",
	-- 190: At the end of the road turn left !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["c00viac0"] = "At the end of the road turn left !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 191: and then make a u turn !NG_COMMAND_2! towards !STREET!
	["h000ec00"] = "and then make a u turn !NG_COMMAND_2! towards !STREET!",
	-- 192: and then immediately make a u turn !NG_COMMAND_2! towards !STREET!
	["j000ec00"] = "and then immediately make a u turn !NG_COMMAND_2! towards !STREET!",
	-- 193: Now take the exit !NG_COMMAND_1! onto !STREET!
	["a00d0d00"] = "Now take the exit !NG_COMMAND_1! onto !STREET!",
	-- 194: and then take the exit !NG_COMMAND_2!
	["h000g000"] = "and then take the exit !NG_COMMAND_2!",
	-- 195: and then immediately take the middle lane, !STREET! towards !SIGNPOST!
	["j00o0ac0"] = "and then immediately take the middle lane, !STREET! towards !SIGNPOST!",
	-- 196: and then immediately take the exit !NG_COMMAND_2!
	["j000g000"] = "and then immediately take the exit !NG_COMMAND_2!",
	-- 197: At the end of the road turn slightly right !NG_COMMAND_1! , enter the urban motorway !STREET!
	["c00qia00"] = "At the end of the road bear right !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 198: and then enter the motorway !STREET! towards !SIGNPOST!
	["h000fac0"] = "and then enter the highway !STREET! towards !SIGNPOST!",
	-- 199: After !DIST! !UNIT! !EXIT_NO_ROUNDABOUT! at the roundabout onto !STREET!
	["bl0c0zb0"] = "After !DIST! !UNIT! !EXIT_NO_ROUNDABOUT! at the traffic circle onto !STREET!",
	-- 200: After !DIST! !UNIT! take the exit !NG_COMMAND_1! onto !STREET!
	["bl0d0d00"] = "After !DIST! !UNIT! take the exit !NG_COMMAND_1! onto !STREET!",
	-- 201: Now turn right !NG_COMMAND_1! , enter the urban motorway
	["a00ri000"] = "Now turn right !NG_COMMAND_1! , enter the expressway",
	-- 202: At the end of the road turn right !NG_COMMAND_1! , enter the urban motorway
	["c00ri000"] = "At the end of the road turn right !NG_COMMAND_1! , enter the expressway",
	-- 203: You have reached your destination
	["y0000000"] = "You have reached your destination",
	-- 204: You have reached your destination. The destination is on your right
	["yp000000"] = "You have reached your destination. The destination is on your right",
	-- 205: You have reached your destination. The destination is on your left
	["yq000000"] = "You have reached your destination. The destination is on your left",
	-- 206: !SET_AUDIO!beep!FREQUENCY!K.wav!SET_AUDIO!
	["x0000000"] = "!SET_AUDIO!beep!FREQUENCY!K.wav!SET_AUDIO!",
	-- 207: Route recalculation
	["w0000000"] = "Route recalculation",
	-- 208: !SET_AUDIO!beep!FREQUENCY!K.wav!SET_AUDIO! Safety camera ahead
	["v0000000"] = "!SET_AUDIO!beep!FREQUENCY!K.wav!SET_AUDIO! Safety camera ahead",
	-- 209: !EXIT_NO_ROUNDABOUT! at the roundabout
	["000c0z00"] = "!EXIT_NO_ROUNDABOUT! at the traffic circle ",
	-- 210: Now go straight ahead !NG_COMMAND_1! enter the motorway
	["a00nf000"] = "Now go straight ahead !NG_COMMAND_1! enter the highway",
	-- 211: You have reached your stopover. The stopover is on your right
	["zr000000"] = "You have reached your stopover. The stopover is on your right",
	-- 212: You have reached your stopover. The stopover is on your left
	["zs000000"] = "You have reached your stopover. The stopover is on your left",
	-- 213: You have reached your stopover
	["z0000000"] = "You have reached your stopover",
	-- 214: GPS signal has been restored
	["q0000000"] = "GPS signal has been restored",
	-- 215: GPS signal lost
	["p0000000"] = "GPS signal lost",
	-- 216: At the end of the road turn sharply right !NG_COMMAND_1! , enter the motorway !STREET!
	["c00sfa00"] = "At the end of the road make a sharp right !NG_COMMAND_1! , enter the highway !STREET!",
	-- 217: No detour found around traffic
	["u0000000"] = "No detour found around traffic",
	-- 218: Traffic on route, do you want to detour?
	["t0000000"] = "Traffic on route, do you want to detour?",
	-- 219: !SET_AUDIO!speeding_beep!FREQUENCY!K.wav!SET_AUDIO!
	["r0000000"] = "!SET_AUDIO!speeding_beep!FREQUENCY!K.wav!SET_AUDIO!",
	-- 220: At the end of the road turn right !NG_COMMAND_1! , enter the motorway !STREET!
	["c00rfa00"] = "At the end of the road turn right !NG_COMMAND_1! , enter the highway !STREET!",
	-- 221: and then immediately go straight ahead, !STREET!
	["j00n0a00"] = "and then immediately go straight ahead !STREET!",
	-- 222: At the end of the road turn slightly right !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["c00qf0c0"] = "At the end of the road bear right !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 223: After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["bl0riac0"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 224: After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["bl0pfac0"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 225: At the end of the road make a u turn !NG_COMMAND_1! , enter the motorway
	["c00tf000"] = "At the end of the road make a u turn !NG_COMMAND_1! , enter the highway",
	-- 226: Now make a u turn !NG_COMMAND_1! , enter the urban motorway
	["a00ti000"] = "Now make a u turn !NG_COMMAND_1! , enter the expressway",
	-- 227: Now make a u turn !NG_COMMAND_1! , enter the motorway
	["a00tf000"] = "Now make a u turn !NG_COMMAND_1! , enter the highway",
	-- 228: After !DIST! !UNIT! you will reach your stopover !NG_COMMAND_1! on !STREET!
	["bl0b0b00"] = "After !DIST! !UNIT! you will reach your stopover !NG_COMMAND_1! on !STREET!",
	-- 229: and then immediately take the second right !NG_COMMAND_2!
	["j00y0000"] = "and then immediately take the second right !NG_COMMAND_2!",
	-- 230: and then take the second right !NG_COMMAND_2!
	["h00y0000"] = "and then take the second right !NG_COMMAND_2!",
	-- 231: After !DIST! !UNIT! enter the urban motorway
	["bl00i000"] = "After !DIST! !UNIT! enter the expressway",
	-- 232: After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the urban motorway !STREET!
	["bl0pia00"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 233: Now enter the motorway
	["a000f000"] = "Now enter the highway",
	-- 234: At the end of the road turn sharply right !NG_COMMAND_1! , enter the urban motorway
	["c00si000"] = "At the end of the road make a sharp right !NG_COMMAND_1! , enter the expressway",
	-- 235: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the urban motorway !STREET!
	["bl0oia00"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 236: At the end of the road turn slightly left !NG_COMMAND_1! onto !STREET!
	["c00w0d00"] = "At the end of the road bear left !NG_COMMAND_1! onto !STREET!",
	-- 237: and then turn slightly left !NG_COMMAND_2!
	["h00w0000"] = "and then bear left !NG_COMMAND_2!",
	-- 238: and then immediately turn slightly left !NG_COMMAND_2!
	["j00w0000"] = "and then immediately bear left !NG_COMMAND_2!",
	-- 239: and then immediately take the second right !NG_COMMAND_2! onto !STREET!
	["j00y0d00"] = "and then immediately take the second right !NG_COMMAND_2! onto !STREET!",
	-- 240: and then take the second right !NG_COMMAND_2! onto !STREET!
	["h00y0d00"] = "and then take the second right !NG_COMMAND_2! onto !STREET!",
	-- 241: and then immediately enter the motorway !NG_COMMAND_2!
	["j000f000"] = "and then immediately enter the highway !NG_COMMAND_2!",
	-- 242: Now turn sharply right !NG_COMMAND_1! , enter the urban motorway
	["a00si000"] = "Now make a sharp right !NG_COMMAND_1! , enter the expressway",
	-- 243: Now turn slightly left !NG_COMMAND_1!
	["a00w0000"] = "Now bear left !NG_COMMAND_1!",
	-- 244: After the junction turn sharply right !NG_COMMAND_1!
	["bz0s0000"] = "After the junction make a sharp right !NG_COMMAND_1!",
	-- 245: At the end of the road turn slightly left !NG_COMMAND_1!
	["c00w0000"] = "At the end of the road bear left !NG_COMMAND_1!",
	-- 246: and then enter the motorway !NG_COMMAND_2!
	["h000f000"] = "and then enter the highway !NG_COMMAND_2!",
	-- 247: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , enter the urban motorway
	["bl0wi000"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , enter the expressway",
	-- 248: Now keep right !NG_COMMAND_1!
	["a00p0000"] = "Now keep right !NG_COMMAND_1!",
	-- 249: and then immediately keep left !NG_COMMAND_2! onto !STREET!
	["j00x0d00"] = "and then immediately keep left !NG_COMMAND_2! onto !STREET!",
	-- 250: and then immediately turn right !STREET! towards !SIGNPOST!
	["j00r0ac0"] = "and then immediately turn right !STREET! towards !SIGNPOST!",
	-- 251: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , enter the motorway !STREET!
	["bl0wfa00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , enter the highway !STREET!",
	-- 252: and then keep right !NG_COMMAND_2!
	["h00p0000"] = "and then keep right !NG_COMMAND_2!",
	-- 253: After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the motorway
	["bl0xf000"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the highway",
	-- 254: and then take the exit !NG_COMMAND_2! towards !STREET!
	["h000gc00"] = "and then take the exit !NG_COMMAND_2! towards !STREET!",
	-- 255: At the end of the road make a u turn !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["c00ti0c0"] = "At the end of the road make a u turn !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 256: and then immediately take the second left !NG_COMMAND_2! onto !STREET!
	["j00z0d00"] = "and then immediately take the second left !NG_COMMAND_2! onto !STREET!",
	-- 257: After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl0p0edz"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 258: and then take the middle lane !NG_COMMAND_2! towards !STREET!
	["h00o0c00"] = "and then take the middle lane !NG_COMMAND_2! towards !STREET!",
	-- 259: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["bl0nf0c0"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 260: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["bl0of0c0"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 261: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! towards !STREET!
	["bl0w0c00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! towards !STREET!",
	-- 262: and then take the second left !NG_COMMAND_2! onto !STREET!
	["h00z0d00"] = "and then take the second left !NG_COMMAND_2! onto !STREET!",
	-- 263: After !DIST! !UNIT! turn right !NG_COMMAND_1!
	["bl0r0000"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1!",
	-- 264: After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! towards !STREET_2! !SIGNPOST_2!
	["bl0p0e0x"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! towards !STREET_2! !SIGNPOST_2!",
	-- 265: After the junction turn left !NG_COMMAND_1!
	["bz0v0000"] = "After the junction turn left !NG_COMMAND_1!",
	-- 266: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["bl0q000x"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 267: At the end of the road turn slightly left !NG_COMMAND_1! , enter the urban motorway !STREET!
	["c00wia00"] = "At the end of the road bear left !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 268: and then take the exit !NG_COMMAND_2!
	["h000d000"] = "and then take the exit !NG_COMMAND_2!",
	-- 269: At the end of the road make a u turn !NG_COMMAND_1! onto !STREET!
	["c00t0d00"] = "At the end of the road make a u turn !NG_COMMAND_1! onto !STREET!",
	-- 270: and then take the ferry towards !STREET_2! !SIGNPOST_2!
	["h00m000x"] = "and then take the ferry towards !STREET_2! !SIGNPOST_2!",
	-- 271: and then take the ferry !NG_COMMAND_2! towards !STREET!
	["h000mc00"] = "and then take the ferry !NG_COMMAND_2! towards !STREET!",
	-- 272: and then you will reach your destination !NG_COMMAND_2!
	["h000a000"] = "and then you will reach your destination !NG_COMMAND_2!",
	-- 273: and then take the exit !NG_COMMAND_2! towards !STREET!
	["h000dc00"] = "and then take the exit !NG_COMMAND_2! towards !STREET!",
	-- 274: and then keep right !NG_COMMAND_2! towards !SIGNPOST!
	["h00p00c0"] = "and then keep right !NG_COMMAND_2! towards !SIGNPOST!",
	-- 275: and then immediately turn slightly right !NG_COMMAND_2! towards !SIGNPOST!
	["j00q00c0"] = "and then immediately bear right !NG_COMMAND_2! towards !SIGNPOST!",
	-- 276: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , enter the motorway
	["bl0wf000"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , enter the highway",
	-- 277: and then immediately go straight ahead !NG_COMMAND_2!
	["j00n0000"] = "and then immediately go straight ahead !NG_COMMAND_2!",
	-- 278: and then immediately make a u turn !NG_COMMAND_2! towards !SIGNPOST!
	["j00t00c0"] = "and then immediately make a u turn !NG_COMMAND_2! towards !SIGNPOST!",
	-- 279: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["bl0siac0"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 280: Follow the course of the road for !DIST! !UNIT!
	["el000000"] = "Follow the course of the road for !DIST! !UNIT!",
	-- 281: Follow the motorway
	["d0000000"] = "Follow the highway",
	-- 282: and then immediately keep right !NG_COMMAND_2! towards !SIGNPOST!
	["j00p00c0"] = "and then immediately keep right !NG_COMMAND_2! towards !SIGNPOST!",
	-- 283: and then immediately keep left !NG_COMMAND_2! towards !SIGNPOST!
	["j00x00c0"] = "and then immediately keep left !NG_COMMAND_2! towards !SIGNPOST!",
	-- 284: and then enter the motorway !STREET! towards !SIGNPOST!
	["h00f0ac0"] = "and then enter the highway !STREET! towards !SIGNPOST!",
	-- 285: and then immediately turn sharply right !NG_COMMAND_2! towards !SIGNPOST!
	["j00s00c0"] = "and then immediately make a sharp right !NG_COMMAND_2! towards !SIGNPOST!",
	-- 286: and then immediately turn slightly left !NG_COMMAND_2! towards !SIGNPOST!
	["j00w00c0"] = "and then immediately bear left !NG_COMMAND_2! towards !SIGNPOST!",
	-- 287: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl0n0edz"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 288: and then immediately turn left !NG_COMMAND_2! towards !SIGNPOST!
	["j00v00c0"] = "and then immediately turn left !NG_COMMAND_2! towards !SIGNPOST!",
	-- 289: and then immediately enter the urban motorway !NG_COMMAND_2! towards !SIGNPOST!
	["j000i0c0"] = "and then immediately enter the expressway !NG_COMMAND_2! towards !SIGNPOST!",
	-- 290: and then immediately enter the motorway !NG_COMMAND_2! towards !SIGNPOST!
	["j000f0c0"] = "and then immediately enter the highway !NG_COMMAND_2! towards !SIGNPOST!",
	-- 291: and then take the second left !NG_COMMAND_2!
	["h00z0000"] = "and then take the second left !NG_COMMAND_2!",
	-- 292: At the end of the road turn slightly left !NG_COMMAND_1! towards !STREET!
	["c00w0c00"] = "At the end of the road bear left !NG_COMMAND_1! towards !STREET!",
	-- 293: and then immediately take the second left !NG_COMMAND_2!
	["j00z0000"] = "and then immediately take the second left !NG_COMMAND_2!",
	-- 294: Now keep left !NG_COMMAND_1! enter the urban motorway
	["a00xi000"] = "Now keep left !NG_COMMAND_1! enter the expressway",
	-- 295: and then immediately take the ferry !NG_COMMAND_2!
	["j000m000"] = "and then immediately take the ferry !NG_COMMAND_2!",
	-- 296: After !DIST! !UNIT! turn right !NG_COMMAND_1! onto !STREET!
	["bl0r0d00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! onto !STREET!",
	-- 297: and then turn slightly left !NG_COMMAND_2! towards !STREET!
	["h00w0c00"] = "and then bear left !NG_COMMAND_2! towards !STREET!",
	-- 298: and then immediately take the exit !NG_COMMAND_2!
	["j000d000"] = "and then immediately take the exit !NG_COMMAND_2!",
	-- 299: and then keep left !NG_COMMAND_2! towards !SIGNPOST!
	["h00x00c0"] = "and then keep left !NG_COMMAND_2! towards !SIGNPOST!",
	-- 300: and then immediately take the ferry !NG_COMMAND_2! towards !STREET!
	["j000mc00"] = "and then immediately take the ferry !NG_COMMAND_2! towards !STREET!",
	-- 301: and then take the exit !NG_COMMAND_2!
	["h000j000"] = "and then take the exit !NG_COMMAND_2!",
	-- 302: and then immediately take the exit !NG_COMMAND_2! onto !STREET!
	["j000dd00"] = "and then immediately take the exit !NG_COMMAND_2! onto !STREET!",
	-- 303: and then immediately take the exit !NG_COMMAND_2!
	["j000j000"] = "and then immediately take the exit !NG_COMMAND_2!",
	-- 304: After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the motorway !STREET!
	["bl0vfa00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the highway !STREET!",
	-- 305: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the urban motorway
	["bl0ni000"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the expressway",
	-- 306: and then go straight ahead !NG_COMMAND_2!
	["h00n0000"] = "and then go straight ahead !NG_COMMAND_2!",
	-- 307: After the junction keep left !NG_COMMAND_1!
	["bz0x0000"] = "After the junction keep left !NG_COMMAND_1!",
	-- 308: drive to nearest road
	["000l0000"] = "drive to nearest road",
	-- 309: and then immediately keep left !NG_COMMAND_2! towards !STREET!
	["j00x0c00"] = "and then immediately keep left !NG_COMMAND_2! towards !STREET!",
	-- 310: and then immediately enter the motorway !STREET! towards !SIGNPOST!
	["j000fac0"] = "and then immediately enter the highway !STREET! towards !SIGNPOST!",
	-- 311: and then immediately enter the motorway !STREET!
	["j000fa00"] = "and then immediately enter the highway !STREET!",
	-- 312: and then immediately take the second left !NG_COMMAND_2! towards !STREET!
	["j00z0c00"] = "and then immediately take the second left !NG_COMMAND_2! towards !STREET!",
	-- 313: Now go straight ahead !NG_COMMAND_1!
	["a00n0000"] = "Now go straight ahead !NG_COMMAND_1!",
	-- 314: and then immediately turn slightly left !NG_COMMAND_2! towards !STREET!
	["j00w0c00"] = "and then immediately bear left !NG_COMMAND_2! towards !STREET!",
	-- 315: and then immediately take the second left , !STREET!
	["j00z0a00"] = "and then immediately take the second left , !STREET!",
	-- 316: and then immediately make a u turn, !STREET! towards !SIGNPOST!
	["j00t0ac0"] = "and then immediately make a u turn, !STREET! towards !SIGNPOST!",
	-- 317: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! towards !STREET!
	["bl0u0c00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! towards !STREET!",
	-- 318: and then immediately keep right, !STREET! towards !SIGNPOST!
	["j00p0ac0"] = "and then immediately keep right, !STREET! towards !SIGNPOST!",
	-- 319: and then immediately turn left, !STREET! towards !SIGNPOST!
	["j00v0ac0"] = "and then immediately turn left, !STREET! towards !SIGNPOST!",
	-- 320: and then immediately turn sharply left !NG_COMMAND_2! onto !STREET!
	["j00u0d00"] = "and then immediately make a sharp left !NG_COMMAND_2! onto !STREET!",
	-- 321: and then immediately go straight ahead !NG_COMMAND_2! towards !STREET!
	["j00n0c00"] = "and then immediately go straight ahead !NG_COMMAND_2! towards !STREET!",
	-- 322: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["bl0tfac0"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 323: At the end of the road make a u turn !NG_COMMAND_1! , enter the urban motorway
	["c00ti000"] = "At the end of the road make a u turn !NG_COMMAND_1! , enter the expressway",
	-- 324: After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["bl0vfac0"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 325: At the end of the road turn sharply left !NG_COMMAND_1! onto !STREET!
	["c00u0d00"] = "At the end of the road make a sharp left !NG_COMMAND_1! onto !STREET!",
	-- 326: and then take the second left !NG_COMMAND_2! towards !STREET!
	["h00z0c00"] = "and then take the second left !NG_COMMAND_2! towards !STREET!",
	-- 327: and then immediately turn slightly right !NG_COMMAND_2!
	["j00q0000"] = "and then immediately bear right !NG_COMMAND_2!",
	-- 328: and then go straight ahead !NG_COMMAND_2! towards !SIGNPOST!
	["h00n00c0"] = "and then go straight ahead !NG_COMMAND_2! towards !SIGNPOST!",
	-- 329: After the junction turn right !NG_COMMAND_1!
	["bz0r0000"] = "After the junction turn right !NG_COMMAND_1!",
	-- 330: and then immediately go straight ahead !NG_COMMAND_2! towards !SIGNPOST!
	["j00n00c0"] = "and then immediately go straight ahead !NG_COMMAND_2! towards !SIGNPOST!",
	-- 331: and then immediately make a u turn !NG_COMMAND_2! onto !STREET!
	["j00t0d00"] = "and then immediately make a u turn !NG_COMMAND_2! onto !STREET!",
	-- 332: and then immediately make a u turn !NG_COMMAND_2!
	["j00t0000"] = "and then immediately make a u turn !NG_COMMAND_2!",
	-- 333: After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER!
	["bl0p0e00"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER!",
	-- 334: and then immediately enter the urban motorway !STREET!
	["j000ia00"] = "and then immediately enter the expressway !STREET!",
	-- 335: and then keep left !NG_COMMAND_2! , !STREET! towards !SIGNPOST!
	["h00x0ac0"] = "and then keep left !NG_COMMAND_2! , !STREET! towards !SIGNPOST!",
	-- 336: and then immediately turn right !NG_COMMAND_2! towards !STREET!
	["j00r0c00"] = "and then immediately turn right !NG_COMMAND_2! towards !STREET!",
	-- 337: and then immediately turn right !NG_COMMAND_2! onto !STREET!
	["j00r0d00"] = "and then immediately turn right !NG_COMMAND_2! onto !STREET!",
	-- 338: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , enter the urban motorway !STREET!
	["bl0wia00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 339: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , enter the urban motorway
	["bl0si000"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , enter the expressway",
	-- 340: and then immediately turn right !NG_COMMAND_2! towards !SIGNPOST!
	["j00r00c0"] = "and then immediately turn right !NG_COMMAND_2! towards !SIGNPOST!",
	-- 341: and then immediately turn sharply right !NG_COMMAND_2! towards !STREET!
	["j00s0c00"] = "and then immediately make a sharp right !NG_COMMAND_2! towards !STREET!",
	-- 342: and then turn right !NG_COMMAND_2! towards !SIGNPOST!
	["h00r00c0"] = "and then turn right !NG_COMMAND_2! towards !SIGNPOST!",
	-- 343: and then enter the urban motorway !STREET!
	["h000ia00"] = "and then enter the expressway , !STREET!",
	-- 344: Now keep left !NG_COMMAND_1! , enter the motorway
	["a00xf000"] = "Now keep left !NG_COMMAND_1! , enter the highway",
	-- 345: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , enter the urban motorway
	["bl0ui000"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , enter the expressway",
	-- 346: and then immediately turn sharply right !NG_COMMAND_2!
	["j00s0000"] = "and then immediately make a sharp right !NG_COMMAND_2!",
	-- 347: and then immediately turn sharply left !NG_COMMAND_2! towards !STREET!
	["j00u0c00"] = "and then immediately make a sharp left !NG_COMMAND_2! towards !STREET!",
	-- 348: and then immediately turn sharply left !NG_COMMAND_2!
	["j00u0000"] = "and then immediately make a sharp left !NG_COMMAND_2!",
	-- 349: After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! towards !STREET_2! !SIGNPOST_2!
	["bl0x0edx"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! towards !STREET_2! !SIGNPOST_2!",
	-- 350: and then immediately take the second right !NG_COMMAND_2! towards !STREET!
	["j00y0c00"] = "and then immediately take the second right !NG_COMMAND_2! towards !STREET!",
	-- 351: and then immediately turn slightly left !NG_COMMAND_2! onto !STREET!
	["j00w0d00"] = "and then immediately bear left !NG_COMMAND_2! onto !STREET!",
	-- 352: and then take the second right !NG_COMMAND_2! towards !STREET!
	["h00y0c00"] = "and then take the second right !NG_COMMAND_2! towards !STREET!",
	-- 353: and then immediately turn left !NG_COMMAND_2! towards !STREET!
	["j00v0c00"] = "and then immediately turn left !NG_COMMAND_2! towards !STREET!",
	-- 354: and then immediately keep left, !STREET!
	["j00x0a00"] = "and then immediately keep left, !STREET!",
	-- 355: and then immediately take the middle lane !NG_COMMAND_2! towards !STREET!
	["j00o0c00"] = "and then immediately take the middle lane !NG_COMMAND_2! towards !STREET!",
	-- 356: After the junction take the middle lane !NG_COMMAND_1!
	["bz0o0000"] = "After the junction take the middle lane !NG_COMMAND_1!",
	-- 357: and then immediately take the middle lane !NG_COMMAND_2! onto !STREET!
	["j00o0d00"] = "and then immediately take the middle lane !NG_COMMAND_2! onto !STREET!",
	-- 358: At the end of the road turn sharply left !NG_COMMAND_1!
	["c00u0000"] = "At the end of the road make a sharp left !NG_COMMAND_1!",
	-- 359: and then turn sharply left !NG_COMMAND_2!
	["h00u0000"] = "and then make a sharp left !NG_COMMAND_2!",
	-- 360: and then immediately turn left !NG_COMMAND_2! onto !STREET!
	["j00v0d00"] = "and then immediately turn left !NG_COMMAND_2! onto !STREET!",
	-- 361: and then immediately make a u turn, !STREET!
	["j00t0a00"] = "and then immediately make a u turn, !STREET!",
	-- 362: and then immediately keep right, !STREET!
	["j00p0a00"] = "and then immediately keep right, !STREET!",
	-- 363: and then immediately go straight ahead, !STREET! towards !SIGNPOST!
	["j00n0ac0"] = "and then immediately go straight ahead, !STREET! towards !SIGNPOST!",
	-- 364: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! and take the exit
	["bl0o00fg"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! and take the exit",
	-- 365: and then immediately turn right, !STREET!
	["j00r0a00"] = "and then immediately turn right, !STREET!",
	-- 366: After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["bl0rf0c0"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 367: After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["bl0xf0c0"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 368: Now turn sharply left !NG_COMMAND_1!
	["a00u0000"] = "Now make a sharp left !NG_COMMAND_1!",
	-- 369: At the end of the road turn left !NG_COMMAND_1! onto !STREET!
	["c00v0d00"] = "At the end of the road turn left !NG_COMMAND_1! onto !STREET!",
	-- 370: and then take the middle lane, !STREET! towards !SIGNPOST!
	["h00o0ac0"] = "and then take the middle lane, !STREET! towards !SIGNPOST!",
	-- 371: After !DIST! !UNIT! take the exit !NG_COMMAND_1! towards !STREET!
	["bl0d0c00"] = "After !DIST! !UNIT! take the exit !NG_COMMAND_1! towards !STREET!",
	-- 372: After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["bl0vi0c0"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 373: and then immediately turn slightly left, !STREET!
	["j00w0a00"] = "and then immediately bear left, !STREET!",
	-- 374: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1!
	["bl0n0000"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1!",
	-- 375: and then you will reach your stopover !NG_COMMAND_2! on !STREET!
	["h000bb00"] = "and then you will reach your stopover !NG_COMMAND_2! on !STREET!",
	-- 376: and then go straight ahead, !STREET! towards !SIGNPOST!
	["h00n0ac0"] = "and then go straight ahead, !STREET! towards !SIGNPOST!",
	-- 377: At the end of the road turn slightly left !NG_COMMAND_1! , enter the motorway !STREET!
	["c00wfa00"] = "At the end of the road bear left !NG_COMMAND_1! , enter the highway !STREET!",
	-- 378: and then keep left !NG_COMMAND_2!
	["h00x0000"] = "and then keep left !NG_COMMAND_2!",
	-- 379: and then turn slightly right !NG_COMMAND_2!
	["h00q0000"] = "and then bear right !NG_COMMAND_2!",
	-- 380: and then turn right !NG_COMMAND_2!
	["h00r0000"] = "and then turn right !NG_COMMAND_2!",
	-- 381: and then you will reach your destination !NG_COMMAND_2!
	["h00a0000"] = "and then you will reach your destination !NG_COMMAND_2!",
	-- 382: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["bl0o000x"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 383: and then take the exit !NG_COMMAND_2! towards !STREET!
	["h000jc00"] = "and then take the exit !NG_COMMAND_2! towards !STREET!",
	-- 384: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , enter the motorway
	["bl0qf000"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , enter the highway",
	-- 385: and then keep left !NG_COMMAND_2! onto !STREET!
	["h00x0d00"] = "and then keep left !NG_COMMAND_2! onto !STREET!",
	-- 386: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take the exit
	["bl0n000g"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take the exit",
	-- 387: and then take the exit !NG_COMMAND_2! onto !STREET!
	["h000gd00"] = "and then take the exit !NG_COMMAND_2! onto !STREET!",
	-- 388: and then turn slightly left !NG_COMMAND_2! onto !STREET!
	["h00w0d00"] = "and then bear left !NG_COMMAND_2! onto !STREET!",
	-- 389: and then turn sharply right !NG_COMMAND_2! onto !STREET!
	["h00s0d00"] = "and then make a sharp right !NG_COMMAND_2! onto !STREET!",
	-- 390: Now take the middle lane !NG_COMMAND_1! and take the exit
	["a00o00fg"] = "Now take the middle lane !NG_COMMAND_1! and take the exit",
	-- 391: and then take the exit !NG_COMMAND_2! onto !STREET!
	["h000jd00"] = "and then take the exit !NG_COMMAND_2! onto !STREET!",
	-- 392: At the end of the road turn right !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["c00rfac0"] = "At the end of the road turn right !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 393: and then go straight ahead !NG_COMMAND_2! onto !STREET!
	["h00n0d00"] = "and then go straight ahead !NG_COMMAND_2! onto !STREET!",
	-- 394: At the end of the road turn left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["c00v000x"] = "At the end of the road turn left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 395: and then go straight ahead !NG_COMMAND_2! towards !STREET!
	["h00n0c00"] = "and then go straight ahead !NG_COMMAND_2! towards !STREET!",
	-- 396: and then make a u turn !NG_COMMAND_2! onto !STREET!
	["h00t0d00"] = "and then make a u turn !NG_COMMAND_2! onto !STREET!",
	-- 397: After !DIST! !UNIT! turn left !NG_COMMAND_1! enter the motorway
	["bl0vf000"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! enter the highway",
	-- 398: After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["bl0pf0c0"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 399: and then turn sharply left !NG_COMMAND_2! onto !STREET!
	["h00u0d00"] = "and then make a sharp left !NG_COMMAND_2! onto !STREET!",
	-- 400: and then turn sharply left !NG_COMMAND_2! towards !STREET!
	["h00u0c00"] = "and then make a sharp left !NG_COMMAND_2! towards !STREET!",
	-- 401: and then turn left !NG_COMMAND_2! onto !STREET!
	["h00v0d00"] = "and then turn left !NG_COMMAND_2! onto !STREET!",
	-- 402: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the motorway !STREET!
	["bl0nfa00"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the highway !STREET!",
	-- 403: After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the urban motorway !STREET!
	["bl0ria00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 404: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the motorway
	["bl0of000"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the highway",
	-- 405: and then keep right !NG_COMMAND_2! onto !STREET!
	["h00p0d00"] = "and then keep right !NG_COMMAND_2! onto !STREET!",
	-- 406: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! onto !STREET!
	["bl0n0d00"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! onto !STREET!",
	-- 407: and then keep right !NG_COMMAND_2! towards !STREET!
	["h00p0c00"] = "and then keep right !NG_COMMAND_2! towards !STREET!",
	-- 408: and then turn slightly right !NG_COMMAND_2! onto !STREET!
	["h00q0d00"] = "and then bear right !NG_COMMAND_2! onto !STREET!",
	-- 409: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! towards !STREET_2! !SIGNPOST_2!
	["bl0n0e0x"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! towards !STREET_2! !SIGNPOST_2!",
	-- 410: At the end of the road turn right !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["c00rf0c0"] = "At the end of the road turn right !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 411: and then turn sharply right !NG_COMMAND_2! towards !STREET!
	["h00s0c00"] = "and then make a sharp right !NG_COMMAND_2! towards !STREET!",
	-- 412: and then turn right !NG_COMMAND_2! onto !STREET!
	["h00r0d00"] = "and then turn right !NG_COMMAND_2! onto !STREET!",
	-- 413: After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["bl0vf0c0"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 414: At the end of the road turn slightly left !NG_COMMAND_1! , enter the motorway
	["c00wf000"] = "At the end of the road bear left !NG_COMMAND_1! , enter the highway",
	-- 415: and then enter the urban motorway !STREET! towards !SIGNPOST!
	["h000iac0"] = "and then enter the expressway !STREET! towards !SIGNPOST!",
	-- 416: Now keep left !NG_COMMAND_1!
	["a00x0000"] = "Now keep left !NG_COMMAND_1!",
	-- 417: At the end of the road turn slightly left !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["c00wiac0"] = "At the end of the road bear left !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 418: and then enter the motorway !NG_COMMAND_2! towards !SIGNPOST!
	["h000f0c0"] = "and then enter the highway !NG_COMMAND_2! towards !SIGNPOST!",
	-- 419: After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["bl0xi0c0"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 420: At the end of the road turn right !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["c00ri0c0"] = "At the end of the road turn right !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 421: and then enter the motorway !STREET!
	["h000fa00"] = "and then enter the highway !STREET!",
	-- 422: and then go straight ahead, !STREET!
	["h00n0a00"] = "and then go straight ahead, !STREET!",
	-- 423: and then immediately keep left !NG_COMMAND_2!
	["j00x0000"] = "and then immediately keep left !NG_COMMAND_2!",
	-- 424: At the end of the road turn slightly left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["c00w000x"] = "At the end of the road bear left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 425: and then make a u turn, !STREET! towards !SIGNPOST!
	["h00t0ac0"] = "and then make a u turn, !STREET! towards !SIGNPOST!",
	-- 426: and then take the middle lane !NG_COMMAND_2! towards !SIGNPOST!
	["h00o00c0"] = "and then take the middle lane !NG_COMMAND_2! towards !SIGNPOST!",
	-- 427: and then immediately turn sharply right, !STREET!
	["j00s0a00"] = "and then immediately make a sharp right, !STREET!",
	-- 428: At the end of the road turn sharply right !NG_COMMAND_1! , enter the urban motorway !STREET!
	["c00sia00"] = "At the end of the road make a sharp right !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 429: and then keep left, !STREET!
	["h00x0a00"] = "and then keep left, !STREET!",
	-- 430: Now turn sharply right !NG_COMMAND_1! , enter the motorway
	["a00sf000"] = "Now make a sharp right !NG_COMMAND_1! , enter the highway",
	-- 431: and then make a u turn !NG_COMMAND_2! towards !SIGNPOST!
	["h00t00c0"] = "and then make a u turn !NG_COMMAND_2! towards !SIGNPOST!",
	-- 432: At the end of the road turn sharply right !NG_COMMAND_1! , enter the motorway
	["c00sf000"] = "At the end of the road make a sharp right !NG_COMMAND_1! , enter the highway",
	-- 433: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1!
	["bl0u0000"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1!",
	-- 434: At the end of the road make a u turn !NG_COMMAND_1! , enter the urban motorway !STREET!
	["c00tia00"] = "At the end of the road make a u turn !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 435: and then turn slightly left !NG_COMMAND_2! towards !SIGNPOST!
	["h00w00c0"] = "and then bear left !NG_COMMAND_2! towards !SIGNPOST!",
	-- 436: and then turn sharply left, !STREET!
	["h00u0a00"] = "and then make a sharp left, !STREET!",
	-- 437: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take the exit
	["bl0o000g"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take the exit",
	-- 438: At the end of the road turn sharply right !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["c00si0c0"] = "At the end of the road make a sharp right !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 439: At the end of the road turn right !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["c00riac0"] = "At the end of the road turn right !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 440: and then turn slightly right !NG_COMMAND_2! towards !SIGNPOST!
	["h00q00c0"] = "and then bear right !NG_COMMAND_2! towards !SIGNPOST!",
	-- 441: and then turn sharply right, !STREET!
	["h00s0a00"] = "and then make a sharp right, !STREET!",
	-- 442: After !DIST! !UNIT! turn left !NG_COMMAND_1!
	["bl0v0000"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1!",
	-- 443: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl0o0e0z"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 444: and then turn sharply right, !STREET! towards !SIGNPOST!
	["h00s0ac0"] = "and then make a sharp right, !STREET! towards !SIGNPOST!",
	-- 445: and then turn right onto !STREET! towards !SIGNPOST!
	["h00r0ac0"] = "and then turn right onto !STREET! towards !SIGNPOST!",
	-- 446: and then !EXIT_NO_ROUNDABOUT! at the roundabout onto !STREET!
	["h000czb0"] = "and then !EXIT_NO_ROUNDABOUT! at the traffic circle onto !STREET!",
	-- 447: and then take the exit !NG_COMMAND_2!
	["h00j0000"] = "and then take the exit !NG_COMMAND_2!",
	-- 448: and then !EXIT_NO_ROUNDABOUT! at the roundabout
	["h00c0z00"] = "and then !EXIT_NO_ROUNDABOUT! at the traffic circle",
	-- 449: After !DIST! !UNIT! keep left !NG_COMMAND_1! towards !STREET!
	["bl0x0c00"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! towards !STREET!",
	-- 450: After !DIST! !UNIT! keep left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["bl0x000x"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 451: After !DIST! !UNIT! turn left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["bl0v000x"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 452: After the junction make a u turn !NG_COMMAND_1!
	["bz0t0000"] = "After the junction make a u turn !NG_COMMAND_1!",
	-- 453: After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the motorway !STREET!
	["bl0pfa00"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the highway !STREET!",
	-- 454: and then enter the motorway !NG_COMMAND_2!
	["h00f0000"] = "and then enter the highway !NG_COMMAND_2!",
	-- 455: After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1!
	["bl0a0000"] = "After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1!",
	-- 456: and then take the exit !NG_COMMAND_2! onto !STREET!
	["h000dd00"] = "and then take the exit !NG_COMMAND_2! onto !STREET!",
	-- 457: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["bl0wf0c0"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 458: and then !EXIT_NO_ROUNDABOUT! at the roundabout
	["h000cz00"] = "and then !EXIT_NO_ROUNDABOUT! at the traffic circle",
	-- 459: and then take the ferry !NG_COMMAND_2!
	["h000m000"] = "and then take the ferry !NG_COMMAND_2!",
	-- 460: and then enter the urban motorway !STREET!
	["h00i0a00"] = "and then enter the expressway !STREET!",
	-- 461: After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the urban motorway
	["bl0xi000"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the expressway",
	-- 462: and then enter the motorway towards !SIGNPOST!
	["h00f00c0"] = "and then enter the highway towards !SIGNPOST!",
	-- 463: and then enter the motorway !STREET!
	["h00f0a00"] = "and then enter the highway !STREET!",
	-- 464: and then immediately turn right !NG_COMMAND_2!
	["j00r0000"] = "and then immediately turn right !NG_COMMAND_2!",
	-- 465: Now keep left !NG_COMMAND_1! and take the exit
	["a00x00fg"] = "Now keep left !NG_COMMAND_1! and take the exit",
	-- 466: After !DIST! !UNIT! turn right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["bl0r000x"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 467: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! towards !STREET!
	["bl0o0c00"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! towards !STREET!",
	-- 468: After !DIST! !UNIT! keep left !NG_COMMAND_1! , take the exit
	["bl0x000g"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , take the exit",
	-- 469: After !DIST! !UNIT! keep right !NG_COMMAND_1! , take the exit
	["bl0p000g"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , take the exit",
	-- 470: and then make a u turn, !STREET!
	["h00t0a00"] = "and then make a u turn, !STREET!",
	-- 471: Now turn right !NG_COMMAND_1!
	["a00r0000"] = "Now turn right !NG_COMMAND_1!",
	-- 472: and then turn left !NG_COMMAND_2! towards !SIGNPOST!
	["h00v00c0"] = "and then turn left !NG_COMMAND_2! towards !SIGNPOST!",
	-- 473: At the end of the road turn right !NG_COMMAND_1!
	["c00r0000"] = "At the end of the road turn right !NG_COMMAND_1!",
	-- 474: After !DIST! !UNIT! keep right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["bl0p000x"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 475: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["bl0s000x"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 476: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["bl0u000x"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 477: At the end of the road turn slightly right !NG_COMMAND_1! , enter the motorway !STREET!
	["c00qfa00"] = "At the end of the road bear right !NG_COMMAND_1! , enter the highway !STREET!",
	-- 478: After !DIST! !UNIT! keep left !NG_COMMAND_1! onto !STREET!
	["bl0x0d00"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! onto !STREET!",
	-- 479: and then enter the urban motorway !NG_COMMAND_2!
	["h00i0000"] = "and then enter the expressway !NG_COMMAND_2!",
	-- 480: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2!
	["bl0n0e0y"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2!",
	-- 481: After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the motorway !STREET!
	["bl0rfa00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the highway !STREET!",
	-- 482: After !DIST! !UNIT! enter the urban motorway !STREET! towards !SIGNPOST!
	["bl00iac0"] = "After !DIST! !UNIT! enter the expressway !STREET! towards !SIGNPOST!",
	-- 483: After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["bl0xiac0"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 484: Now turn slightly left !NG_COMMAND_1! , enter the urban motorway
	["a00wi000"] = "Now bear left !NG_COMMAND_1! , enter the expressway",
	-- 485: After !DIST! !UNIT! keep left !NG_COMMAND_1! take exit !EXIT_NUMBER! and continue on !STREET_2!
	["bl0x0e0y"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! take exit !EXIT_NUMBER! and continue on !STREET_2!",
	-- 486: At the end of the road turn left !NG_COMMAND_1! , enter the motorway
	["c00vf000"] = "At the end of the road turn left !NG_COMMAND_1! , enter the highway",
	-- 487: At the end of the road turn sharply right !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["c00sf0c0"] = "At the end of the road make a sharp right !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 488: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["bl0w000x"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 489: and then !EXIT_NO_ROUNDABOUT! at the roundabout towards !SIGNPOST!
	["h000czc0"] = "and then !EXIT_NO_ROUNDABOUT! at the traffic circle towards !SIGNPOST!",
	-- 490: At the end of the road turn sharply left !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["c00uiac0"] = "At the end of the road make a sharp left !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 491: After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER!
	["bl0x0e00"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER!",
	-- 492: and then immediately keep right !NG_COMMAND_2! towards !STREET!
	["j00p0c00"] = "and then immediately keep right !NG_COMMAND_2! towards !STREET!",
	-- 493: After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl0p0e0z"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 494: After !DIST! !UNIT! take exit !EXIT_NUMBER! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl000e0z"] = "After !DIST! !UNIT! take exit !EXIT_NUMBER! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 495: After !DIST! !UNIT! take exit !EXIT_NUMBER!
	["bl000e00"] = "After !DIST! !UNIT! take exit !EXIT_NUMBER!",
	-- 496: After !DIST! !UNIT! take the exit !NG_COMMAND_1!
	["bl00000g"] = "After !DIST! !UNIT! take the exit !NG_COMMAND_1!",
	-- 497: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , enter the motorway !STREET!
	["bl0sfa00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , enter the highway !STREET!",
	-- 498: Now keep right !NG_COMMAND_1! , take the exit
	["a00p000g"] = "Now keep right !NG_COMMAND_1! , take the exit",
	-- 499: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! onto !STREET!
	["bl0u0d00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! onto !STREET!",
	-- 500: Now take the middle lane !NG_COMMAND_1! , enter the urban motorway
	["a00oi000"] = "Now take the middle lane !NG_COMMAND_1! , enter the expressway",
	-- 501: After !DIST! !UNIT! keep right !NG_COMMAND_1! onto !STREET!
	["bl0p0d00"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! onto !STREET!",
	-- 502: After !DIST! !UNIT! make a u turn !NG_COMMAND_1!
	["bl0t0000"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1!",
	-- 503: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , enter the motorway !STREET!
	["bl0ufa00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , enter the highway !STREET!",
	-- 504: At the end of the road turn left !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["c00vfac0"] = "At the end of the road turn left !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 505: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , enter the urban motorway !STREET!
	["bl0qia00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 506: Now keep right !NG_COMMAND_1! enter the motorway
	["a00pf000"] = "Now keep right !NG_COMMAND_1! enter the highway",
	-- 507: After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! towards !STREET_2! !SIGNPOST_2!
	["bl0x0e0x"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! towards !STREET_2! !SIGNPOST_2!",
	-- 508: and then immediately enter the urban motorway !STREET! towards !SIGNPOST!
	["j000iac0"] = "and then immediately enter the expressway !STREET! towards !SIGNPOST!",
	-- 509: and then immediately turn sharply right !NG_COMMAND_2! onto !STREET!
	["j00s0d00"] = "and then immediately make a sharp right !NG_COMMAND_2! onto !STREET!",
	-- 510: After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2!
	["bl0p0e0y"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2!",
	-- 511: Now turn slightly left !NG_COMMAND_1! , enter the motorway
	["a00wf000"] = "Now bear left !NG_COMMAND_1! , enter the highway",
	-- 512: Now turn left !NG_COMMAND_1! , enter the motorway
	["a00vf000"] = "Now turn left !NG_COMMAND_1! , enter the highway",
	-- 513: Now take the middle lane !NG_COMMAND_1! , take the exit
	["a00o000g"] = "Now take the middle lane !NG_COMMAND_1! , take the exit",
	-- 514: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["bl0ui0c0"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 515: At the end of the road turn sharply right !NG_COMMAND_1! onto !STREET!
	["c00s0d00"] = "At the end of the road make a sharp right !NG_COMMAND_1! onto !STREET!",
	-- 516: Now take the middle lane !NG_COMMAND_1! enter the motorway
	["a00of000"] = "Now take the middle lane !NG_COMMAND_1! enter the highway",
	-- 517: At the end of the road make a u turn !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["c00tiac0"] = "At the end of the road make a u turn !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 518: At the end of the road make a u turn !NG_COMMAND_1! towards !STREET!
	["c00t0c00"] = "At the end of the road make a u turn !NG_COMMAND_1! towards !STREET!",
	-- 519: At the end of the road make a u turn !NG_COMMAND_1! enter the motorway !STREET! towards !SIGNPOST!
	["c00tfac0"] = "At the end of the road make a u turn !NG_COMMAND_1! enter the highway !STREET! towards !SIGNPOST!",
	-- 520: Now turn slightly right !NG_COMMAND_1! , enter the motorway
	["a00qf000"] = "Now bear right !NG_COMMAND_1! , enter the highway",
	-- 521: At the end of the road turn slightly right !NG_COMMAND_1! onto !STREET!
	["c00q0d00"] = "At the end of the road bear right !NG_COMMAND_1! onto !STREET!",
	-- 522: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["bl0niac0"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 523: At the end of the road turn left !NG_COMMAND_1! towards !STREET!
	["c00v0c00"] = "At the end of the road turn left !NG_COMMAND_1! towards !STREET!",
	-- 524: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the urban motorway !STREET!
	["bl0nia00"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 525: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["bl0tiac0"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 526: and then immediately make a u turn !NG_COMMAND_2! towards !STREET!
	["j00t0c00"] = "and then immediately make a u turn !NG_COMMAND_2! towards !STREET!",
	-- 527: After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["bl0pi0c0"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 528: and then make a u turn !NG_COMMAND_2! towards !STREET!
	["h00t0c00"] = "and then make a u turn !NG_COMMAND_2! towards !STREET!",
	-- 529: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST!
	["bl0o0ed0"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST!",
	-- 530: and then turn left !NG_COMMAND_2! towards !STREET!
	["h00v0c00"] = "and then turn left !NG_COMMAND_2! towards !STREET!",
	-- 531: After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["bl0ri0c0"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 532: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["bl0sfac0"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 533: At the end of the road turn sharply left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["c00u000x"] = "At the end of the road make a sharp left !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 534: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["bl0wiac0"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 535: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["bl0wi0c0"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 536: After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["bl0viac0"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 537: After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the urban motorway
	["bl0vi000"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , enter the expressway",
	-- 538: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["bl0oiac0"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 539: After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! towards !STREET_2! !SIGNPOST_2!
	["bl0p0edx"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! towards !STREET_2! !SIGNPOST_2!",
	-- 540: After !DIST! !UNIT! take the ferry !NG_COMMAND_1! towards !STREET!
	["bl0m0c00"] = "After !DIST! !UNIT! take the ferry !NG_COMMAND_1! towards !STREET!",
	-- 541: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the urban motorway
	["bl0oi000"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , enter the expressway",
	-- 542: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , enter the motorway !STREET!
	["bl0qfa00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , enter the highway !STREET!",
	-- 543: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["bl0nfac0"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 544: After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the motorway
	["bl0pf000"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the highway",
	-- 545: After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["bl0xfac0"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 546: After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["bl0rfac0"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 547: Now make a u turn !NG_COMMAND_1!
	["a00t0000"] = "Now make a u turn !NG_COMMAND_1!",
	-- 548: At the end of the road turn slightly right !NG_COMMAND_1! , enter the urban motorway
	["c00qi000"] = "At the end of the road bear right !NG_COMMAND_1! , enter the expressway",
	-- 549: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["bl0ufac0"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 550: Now turn slightly right !NG_COMMAND_1! , enter the urban motorway
	["a00qi000"] = "Now bear right !NG_COMMAND_1! , enter the expressway",
	-- 551: and then turn right !NG_COMMAND_2! towards !STREET!
	["h00r0c00"] = "and then turn right !NG_COMMAND_2! towards !STREET!",
	-- 552: After !DIST! !UNIT! keep right !NG_COMMAND_1! towards !STREET!
	["bl0p0c00"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! towards !STREET!",
	-- 553: After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the urban motorway
	["bl0pi000"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! , enter the expressway",
	-- 554: At the end of the road make a u turn !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["c00t000x"] = "At the end of the road make a u turn !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 555: At the end of the road turn right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["c00r000x"] = "At the end of the road turn right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 556: At the end of the road turn sharply right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["c00s000x"] = "At the end of the road make a sharp right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 557: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2!
	["bl0o0e0y"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2!",
	-- 558: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , enter the motorway
	["bl0uf000"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , enter the highway",
	-- 559: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , enter the urban motorway !STREET!
	["bl0uia00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 560: At the end of the road turn sharply left !NG_COMMAND_1! , enter the urban motorway
	["c00ui000"] = "At the end of the road make a sharp left !NG_COMMAND_1! , enter the expressway",
	-- 561: Now turn sharply left !NG_COMMAND_1! , enter the urban motorway
	["a00ui000"] = "Now make a sharp left !NG_COMMAND_1! , enter the expressway",
	-- 562: and then you will reach your stopover !NG_COMMAND_2!
	["h00b0000"] = "and then you will reach your stopover !NG_COMMAND_2!",
	-- 563: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , enter the urban motorway !STREET! towards !SIGNPOST!
	["bl0qiac0"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , enter the expressway !STREET! towards !SIGNPOST!",
	-- 564: At the end of the road turn right !NG_COMMAND_1! , enter the urban motorway !STREET!
	["c00ria00"] = "At the end of the road turn right !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 565: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! towards !STREET!
	["bl0n0c00"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! towards !STREET!",
	-- 566: At the end of the road turn right !NG_COMMAND_1! towards !STREET!
	["c00r0c00"] = "At the end of the road turn right !NG_COMMAND_1! towards !STREET!",
	-- 567: At the end of the road turn left !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["c00vi0c0"] = "At the end of the road turn left !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 568: and then keep right, !STREET! towards !SIGNPOST!
	["h00p0ac0"] = "and then keep right, !STREET! towards !SIGNPOST!",
	-- 569: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! onto !STREET!
	["bl0t0d00"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! onto !STREET!",
	-- 570: and then immediately turn slightly right !NG_COMMAND_2! towards !STREET!
	["j00q0c00"] = "and then immediately bear right !NG_COMMAND_2! towards !STREET!",
	-- 571: At the end of the road turn sharply left !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["c00ufac0"] = "At the end of the road make a sharp left !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 572: At the end of the road turn sharply right !NG_COMMAND_1! , enter the motorway !STREET! towards !SIGNPOST!
	["c00sfac0"] = "At the end of the road make a sharp right !NG_COMMAND_1! , enter the highway !STREET! towards !SIGNPOST!",
	-- 573: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER!
	["bl0n0e00"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER!",
	-- 574: At the end of the road you will reach your destination !NG_COMMAND_1! on !STREET!
	["c00a0b00"] = "At the end of the road you will reach your destination !NG_COMMAND_1! on !STREET!",
	-- 575: At the end of the road turn slightly right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!
	["c00q000x"] = "At the end of the road bear right !NG_COMMAND_1! towards !STREET_2! !SIGNPOST_2!",
	-- 576: At the end of the road turn slightly right !NG_COMMAND_1! towards !STREET!
	["c00q0c00"] = "At the end of the road bear right !NG_COMMAND_1! towards !STREET!",
	-- 577: After !DIST! !UNIT! keep left !NG_COMMAND_1!
	["bl0x0000"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1!",
	-- 578: At the end of the road turn sharply left !NG_COMMAND_1! enter the motorway towards !SIGNPOST!
	["c00uf0c0"] = "At the end of the road make a sharp left !NG_COMMAND_1! enter the highway towards !SIGNPOST!",
	-- 579: and then immediately go straight ahead !NG_COMMAND_2! onto !STREET!
	["j00n0d00"] = "and then immediately go straight ahead !NG_COMMAND_2! onto !STREET!",
	-- 580: and then enter the urban motorway !NG_COMMAND_2! towards !SIGNPOST!
	["h000i0c0"] = "and then enter the expressway !NG_COMMAND_2! towards !SIGNPOST!",
	-- 581: At the end of the road turn slightly right !NG_COMMAND_1! , enter the motorway
	["c00qf000"] = "At the end of the road bear right !NG_COMMAND_1! , enter the highway",
	-- 582: and then turn slightly right !NG_COMMAND_2! towards !STREET!
	["h00q0c00"] = "and then bear right !NG_COMMAND_2! towards !STREET!",
	-- 583: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl0n0e0z"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 584: After !DIST! !UNIT! take the exit !NG_COMMAND_1!
	["bl0d0000"] = "After !DIST! !UNIT! take the exit !NG_COMMAND_1!",
	-- 585: Traffic on route, detouring
	["s0000000"] = "Traffic on route, detouring",
	-- 586: After the junction turn sharply left !NG_COMMAND_1!
	["bz0u0000"] = "After the junction make a sharp left !NG_COMMAND_1!",
	-- 587: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , enter the motorway
	["bl0sf000"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , enter the highway",
	-- 588: At the end of the road turn slightly left !NG_COMMAND_1! , enter the motorway towards !SIGNPOST!
	["c00wf0c0"] = "At the end of the road bear left !NG_COMMAND_1! , enter the highway towards !SIGNPOST!",
	-- 589: After the junction turn slightly right !NG_COMMAND_1!
	["bz0q0000"] = "After the junction bear right !NG_COMMAND_1!",
	-- 590: Now make a u turn !NG_COMMAND_1!
	["a00e0000"] = "Now make a u turn !NG_COMMAND_1!",
	-- 591: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , enter the urban motorway !STREET!
	["bl0sia00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 592: After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2!
	["bl0x0edy"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2!",
	-- 593: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the urban motorway !STREET!
	["bl0tia00"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! , enter the expressway !STREET!",
	-- 594: After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! towards !STREET_2! !SIGNPOST_2!
	["bl0n0edx"] = "After !DIST! !UNIT! go straight ahead !NG_COMMAND_1! , take exit !EXIT_NUMBER! !SIGNPOST! towards !STREET_2! !SIGNPOST_2!",
	-- 595: After !DIST! !UNIT! keep right !NG_COMMAND_1!
	["bl0p0000"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1!",
	-- 596: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! onto !STREET!
	["bl0o0d00"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! onto !STREET!",
	-- 597: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , enter the urban motorway towards !SIGNPOST!
	["bl0qi0c0"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , enter the expressway towards !SIGNPOST!",
	-- 598: and then immediately turn sharply left onto !STREET!
	["j00u0a00"] = "and then immediately make a sharp left onto !STREET!",
	-- 603: After !DIST! !UNIT! make a u turn !NG_COMMAND_1!
	["blt00000"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1!",
	-- 614: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! onto !STREET!
	["blt00d00"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! onto !STREET!",
	-- 615: After !DIST! !UNIT! make a u turn !NG_COMMAND_1! and continue on !STREET!
	["blt00f00"] = "After !DIST! !UNIT! make a u turn !NG_COMMAND_1! and continue on !STREET!",
	-- 621: Now make a u turn !NG_COMMAND_1! onto !STREET!
	["a0t00d00"] = "Now make a u turn !NG_COMMAND_1! onto !STREET!",
	-- 630: Now make a u turn !NG_COMMAND_1! and continue on !STREET!
	["a0t00f00"] = "Now make a u turn !NG_COMMAND_1! and continue on !STREET!",
	-- 653: and then after !DIST! !UNIT! !NG_COMMAND_1! you will reach your destination
	["ll0a0000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! you will reach your destination",
	-- 654: and then after !DIST! !UNIT! !NG_COMMAND_1! make a u turn
	["ll0e0000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! make a u turn",
	-- 656: and then after !DIST! !UNIT! !NG_COMMAND_1! you will reach your stopover
	["ll0b0000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! you will reach your stopover",
	-- 668: and then after !DIST! !UNIT! !NG_COMMAND_1! make a u turn
	["llt00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! make a u turn",
	-- 937: After !DIST! !UNIT! enter the highway !STREET!
	["bl00fa00"] = "After !DIST! !UNIT! enter the highway !STREET!",
	-- 938: and then immediately keep left !NG_COMMAND_2! , !STREET! towards !SIGNPOST!
	["j00x0ac0"] = "and then immediately keep left !NG_COMMAND_2!, !STREET! towards !SIGNPOST!",
	-- 939: After !DIST! !UNIT! take exit !EXIT_NUMBER! and continue on !STREET_2!
	["bl000e0y"] = "After !DIST! !UNIT! take exit !EXIT_NUMBER! and continue on !STREET_2!",
	-- 940: After !DIST! !UNIT! take exit !EXIT_NUMBER! !SIGNPOST!
	["bl000ed0"] = "After !DIST! !UNIT! take exit !EXIT_NUMBER! !SIGNPOST!",
	-- 941: After !DIST! !UNIT! take exit !EXIT_NUMBER! !SIGNPOST! towards !STREET_2! !SIGNPOST_2!
	["bl000edx"] = "After !DIST! !UNIT! take exit !EXIT_NUMBER! !SIGNPOST! towards !STREET_2! !SIGNPOST_2!",
	-- 942: After !DIST! !UNIT! take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl000edz"] = "After !DIST! !UNIT! take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 943: After !DIST! !UNIT! take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2!
	["bl000edy"] = "After !DIST! !UNIT! take exit !EXIT_NUMBER! !SIGNPOST! and continue on !STREET_2!",
	-- 944: After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1! . The destination is on your left
	["bl0a000l"] = "After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1! . The destination is on your left",
	-- 945: After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1! . The destination is on your right
	["bl0a000r"] = "After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1! . The destination is on your right",
	-- 946: After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1! on !STREET! . The destination is on your left
	["bl0a0b0l"] = "After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1! on !STREET! . The destination is on your left",
	-- 947: After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1! on !STREET! . The destination is on your right
	["bl0a0b0r"] = "After !DIST! !UNIT! you will reach your destination !NG_COMMAND_1! on !STREET! . The destination is on your right",
	-- 948: After !DIST! !UNIT! enter the motorway towards !SIGNPOST!
	["bl00f0c0"] = "After !DIST! !UNIT! enter the highway towards !SIGNPOST!",
	-- 949: After !DIST! !UNIT! enter the urban motorway towards !SIGNPOST!
	["bl00i0c0"] = "After !DIST! !UNIT! enter the expressway towards !SIGNPOST!",
	-- 950: After !DIST! !UNIT! enter the urban motorway !STREET!
	["bl00ia00"] = "After !DIST! !UNIT! enter the expressway !STREET!",
	-- 964: Enter the roundabout
	["000c0y00"] = "Enter the traffic circle",
	-- 965: After !DIST! !UNIT! enter the roundabout
	["bl0c0y00"] = "After !DIST! !UNIT! enter the traffic circle",
	-- 966: At the end of the road enter the roundabout
	["c00c0y00"] = "At the end of the road enter the traffic circle",
	-- 967: and then enter the roundabout
	["h000cy00"] = "and then enter the traffic circle",
	-- 968: After !DIST! !UNIT! keep left !NG_COMMAND_1! and continue on !STREET_2!
	["bl0x000y"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! and continue on !STREET_2!",
	-- 969: After !DIST! !UNIT! keep left !NG_COMMAND_1! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl0x000z"] = "After !DIST! !UNIT! keep left !NG_COMMAND_1! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 970: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! and continue on !STREET_2!
	["bl0o000y"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! and continue on !STREET_2!",
	-- 971: After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl0o000z"] = "After !DIST! !UNIT! take the middle lane !NG_COMMAND_1! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 972: After !DIST! !UNIT! keep right !NG_COMMAND_1! and continue on !STREET_2!
	["bl0p000y"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! and continue on !STREET_2!",
	-- 973: After !DIST! !UNIT! keep right !NG_COMMAND_1! and continue on !STREET_2! towards !SIGNPOST_2!
	["bl0p000z"] = "After !DIST! !UNIT! keep right !NG_COMMAND_1! and continue on !STREET_2! towards !SIGNPOST_2!",
	-- 974: Follow the course of the road
	["g0000000"] = "Follow the course of the road",
}

commands_ped = { -- Commands for ped navigation.
	-- empty command
	["00000000"] = " ",
	-- 599: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1!
	["blo00000"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1!",
	-- 600: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1!
	["blw00000"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1!",
	-- 601: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1!
	["blu00000"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1!",
	-- 602: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1!
	["bls00000"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1!",
	-- 604: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1!
	["blq00000"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1!",
	-- 605: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , !STREET!
	["blo00a00"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , !STREET!",
	-- 606: After !DIST! !UNIT! turn left !NG_COMMAND_1! and continue on !STREET!
	["blv00f00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! and continue on !STREET!",
	-- 607: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! onto !STREET!
	["blw00d00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! onto !STREET!",
	-- 608: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! and continue on !STREET!
	["blw00f00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! and continue on !STREET!",
	-- 609: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! onto !STREET!
	["blu00d00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! onto !STREET!",
	-- 610: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! and continue on !STREET!
	["blu00f00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! and continue on !STREET!",
	-- 611: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! onto !STREET!
	["bls00d00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! onto !STREET!",
	-- 612: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! and continue on !STREET!
	["bls00f00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! and continue on !STREET!",
	-- 613: After !DIST! !UNIT! turn right !NG_COMMAND_1! and continue on !STREET!
	["blr00f00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! and continue on !STREET!",
	-- 616: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! onto !STREET!
	["blq00d00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! onto !STREET!",
	-- 617: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! and continue on !STREET!
	["blq00f00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! and continue on !STREET!",
	-- 618: Now turn slightly right !NG_COMMAND_1! onto !STREET!
	["a0q00d00"] = "Now bear right !NG_COMMAND_1! onto !STREET!",
	-- 619: Now turn sharply right !NG_COMMAND_1! onto !STREET!
	["a0s00d00"] = "Now make a sharp right !NG_COMMAND_1! onto !STREET!",
	-- 620: Now turn slightly left !NG_COMMAND_1! onto !STREET!
	["a0w00d00"] = "Now bear left !NG_COMMAND_1! onto !STREET!",
	-- 622: Now turn sharply left !NG_COMMAND_1! onto !STREET!
	["a0u00d00"] = "Now make a sharp left !NG_COMMAND_1! onto !STREET!",
	-- 623: Now take the street in the middle !NG_COMMAND_1! , !STREET!
	["a0o00a00"] = "Now take the street in the middle !NG_COMMAND_1! , !STREET!",
	-- 624: Now take the street in the middle !NG_COMMAND_1!
	["a0o00000"] = "Now take the street in the middle !NG_COMMAND_1!",
	-- 625: Now turn left !NG_COMMAND_1! and continue on !STREET!
	["a0v00f00"] = "Now turn left !NG_COMMAND_1! and continue on !STREET!",
	-- 626: Now turn slightly left !NG_COMMAND_1! and continue on !STREET!
	["a0w00f00"] = "Now bear left !NG_COMMAND_1! and continue on !STREET!",
	-- 627: Now turn sharply left !NG_COMMAND_1! and continue on !STREET!
	["a0u00f00"] = "Now make a sharp left !NG_COMMAND_1! and continue on !STREET!",
	-- 628: Now turn sharply right !NG_COMMAND_1! and continue on !STREET!
	["a0s00f00"] = "Now make a sharp right !NG_COMMAND_1! and continue on !STREET!",
	-- 629: Now turn right !NG_COMMAND_1! and continue on !STREET!
	["a0r00f00"] = "Now turn right !NG_COMMAND_1! and continue on !STREET!",
	-- 631: Now walk straight ahead and continue on !STREET!
	["a0n00f00"] = "Now walk straight ahead and continue on !STREET!",
	-- 632: Now turn slightly right !NG_COMMAND_1! and continue on !STREET!
	["a0q00f00"] = "Now bear right !NG_COMMAND_1! and continue on !STREET!",
	-- 633: Now walk around the roundabout and turn onto !STREET!
	["a0c00h00"] = "Now walk around the traffic circle and turn onto !STREET!",
	-- 634: After !DIST! !UNIT! turn right !NG_COMMAND_1! , go through the building
	["blr00o00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , go through the building",
	-- 635: After !DIST! !UNIT! walk left around the roundabout
	["blb00000"] = "After !DIST! !UNIT! walk left around the traffic circle",
	-- 636: Now turn right !NG_COMMAND_1!
	["a0r00000"] = "Now turn right !NG_COMMAND_1!",
	-- 637: Now turn left !NG_COMMAND_1!
	["a0v00000"] = "Now turn left !NG_COMMAND_1!",
	-- 638: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , !STREET!
	["blp00a00"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , !STREET!",
	-- 639: Now take the street on the right !NG_COMMAND_1! , !STREET!
	["a0p00a00"] = "Now take the street on the right !NG_COMMAND_1! , !STREET!",
	-- 640: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1!
	["blp00000"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1!",
	-- 641: Now take the street on the right !NG_COMMAND_1!
	["a0p00000"] = "Now take the street on the right !NG_COMMAND_1!",
	-- 642: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , !STREET!
	["blx00a00"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , !STREET!",
	-- 643: Now take the street on the left !NG_COMMAND_1! , !STREET!
	["a0x00a00"] = "Now take the street on the left !NG_COMMAND_1! onto !STREET!",
	-- 644: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1!
	["blx00000"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1!",
	-- 645: Now take the street on the left !NG_COMMAND_1!
	["a0x00000"] = "Now take the street on the left !NG_COMMAND_1!",
	-- 646: After !DIST! !UNIT! turn left !NG_COMMAND_1!
	["blv00000"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1!",
	-- 647: After !DIST! !UNIT! turn right !NG_COMMAND_1!
	["blr00000"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1!",
	-- 648: After !DIST! !UNIT! !NG_COMMAND_1! turn left onto !STREET!
	["blv00d00"] = "After !DIST! !UNIT! !NG_COMMAND_1! turn left onto !STREET!",
	-- 649: After !DIST! !UNIT! !NG_COMMAND_1! turn right onto !STREET!
	["blr00d00"] = "After !DIST! !UNIT! !NG_COMMAND_1! turn right onto !STREET!",
	-- 650: Now turn left onto !STREET!
	["a0v00d00"] = "Now turn left onto !STREET!",
	-- 651: Now turn right onto !STREET!
	["a0r00d00"] = "Now turn right onto !STREET!",
	-- 652: Now walk around the roundabout !PED_TURN_NO!
	["a0c00j00"] = "Now walk around the traffic circle !PED_TURN_NO!",
	-- 655: and then after !DIST! !UNIT! !NG_COMMAND_1! take the ferry
	["ll0m0000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! take the ferry",
	-- 657: and then after !DIST! !UNIT! !NG_COMMAND_1! walk left around the roundabout
	["llb00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! walk left around the traffic circle",
	-- 658: and then after !DIST! !UNIT! !NG_COMMAND_1! walk around the roundabout
	["llc00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! walk around the traffic circle",
	-- 659: and then after !DIST! !UNIT! !NG_COMMAND_1! walk right around the roundabout
	["lla00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! walk right around the traffic circle",
	-- 660: and then after !DIST! !UNIT! !NG_COMMAND_1! take the street in the middle
	["llo00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! take the street in the middle",
	-- 661: and then after !DIST! !UNIT! !NG_COMMAND_1! turn left
	["llv00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! turn left",
	-- 662: and then after !DIST! !UNIT! !NG_COMMAND_1! turn slightly left
	["llw00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! bear left",
	-- 663: and then after !DIST! !UNIT! !NG_COMMAND_1! turn sharply left
	["llu00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! make a sharp left",
	-- 664: and then after !DIST! !UNIT! !NG_COMMAND_1! turn sharply right
	["lls00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! make a sharp right",
	-- 665: and then after !DIST! !UNIT! !NG_COMMAND_1! turn right
	["llr00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! turn right",
	-- 666: and then after !DIST! !UNIT! !NG_COMMAND_1! take the street on the left
	["llx00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! take the street on the left",
	-- 667: and then after !DIST! !UNIT! !NG_COMMAND_1! take the street on the right
	["llp00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! take the street on the right",
	-- 669: and then after !DIST! !UNIT! !NG_COMMAND_1! walk straight ahead
	["lln00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! walk straight ahead",
	-- 670: and then after !DIST! !UNIT! !NG_COMMAND_1! turn slightly right
	["llq00000"] = "and then after !DIST! !UNIT! !NG_COMMAND_1! bear right",
	-- 671: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and take the lift
	["bln000s0"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and take the elevator",
	-- 672: Now turn slightly right onto the footpath
	["a0q00g00"] = "Now bear right onto the footpath",
	-- 673: Now turn right !NG_COMMAND_1! onto the footpath
	["a0r00g00"] = "Now turn right !NG_COMMAND_1! onto the footpath",
	-- 674: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and take the stairs
	["bln000r0"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and take the stairs",
	-- 675: Now walk right around the roundabout and turn onto !STREET!
	["a0a00h00"] = "Now walk right around the traffic circle and turn onto !STREET!",
	-- 676: After !DIST! !UNIT! turn right !NG_COMMAND_1! , cross the park
	["blr00q00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , cross the park",
	-- 677: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , take the stairs
	["bln00r00"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , take the stairs",
	-- 678: Now turn left !NG_COMMAND_1! and take the escalator
	["a0v000t0"] = "Now turn left !NG_COMMAND_1! and take the escalator",
	-- 679: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and take the lift
	["blo000s0"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and take the elevator",
	-- 680: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , go through the building
	["bls00o00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , go through the building",
	-- 681: Now take the street in the middle !NG_COMMAND_1! , cross the park
	["a0o00q00"] = "Now take the street in the middle !NG_COMMAND_1! , cross the park",
	-- 682: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , take the escalator
	["blw00t00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , take the escalator",
	-- 683: Now turn slightly left !NG_COMMAND_1! and take the escalator
	["a0w000t0"] = "Now bear left !NG_COMMAND_1! and take the escalator",
	-- 684: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! and take the lift
	["blw000s0"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! and take the elevator",
	-- 685: Now walk left around the roundabout !PED_TURN_NO!
	["a0b00j00"] = "Now walk left around the traffic circle !PED_TURN_NO!",
	-- 686: Now walk left around the roundabout !NG_COMMAND_1! and turn onto !STREET!
	["a0b00h00"] = "Now walk left around the traffic circle !NG_COMMAND_1! and turn onto !STREET!",
	-- 687: Now turn slightly right !NG_COMMAND_1! , cross the square
	["a0q00p00"] = "Now bear right !NG_COMMAND_1! , cross the square",
	-- 688: Head !ORIENTATION!
	["f0000000"] = "Head !ORIENTATION!",
	-- 689: Now turn slightly right !NG_COMMAND_1! , cross the park
	["a0q00q00"] = "Now bear right !NG_COMMAND_1! , cross the park",
	-- 690: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! and cross the park
	["blq000q0"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! and cross the park",
	-- 691: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! and go through the building
	["blw000o0"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! and go through the building",
	-- 692: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , take the lift
	["blw00s00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , take the elevator",
	-- 693: Now turn sharply left !NG_COMMAND_1! and take the escalator
	["a0u000t0"] = "Now make a sharp left !NG_COMMAND_1! and take the escalator",
	-- 694: Now walk straight ahead !NG_COMMAND_1! and cross the square
	["a0n000p0"] = "Now walk straight ahead !NG_COMMAND_1! and cross the square",
	-- 695: Now take the street on the right !NG_COMMAND_1! and go through the building
	["a0p000o0"] = "Now take the street on the right !NG_COMMAND_1! and go through the building",
	-- 696: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! and take the escalator
	["blw000t0"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! and take the escalator",
	-- 697: Now turn left !NG_COMMAND_1! take the stairs
	["a0v00r00"] = "Now turn left !NG_COMMAND_1! take the stairs",
	-- 698: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and cross the park
	["blo000q0"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and cross the park",
	-- 699: Now take the street in the middle !NG_COMMAND_1! and cross the square
	["a0o000p0"] = "Now take the street in the middle !NG_COMMAND_1! and cross the square",
	-- 700: Now turn slightly right !NG_COMMAND_1! and go through the building
	["a0q000o0"] = "Now bear right !NG_COMMAND_1! and go through the building",
	-- 701: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , cross the park
	["bln00q00"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , cross the park",
	-- 702: Now walk right around the roundabout !NG_COMMAND_1! !PED_TURN_NO!
	["a0a00j00"] = "Now walk right around the traffic circle !NG_COMMAND_1! !PED_TURN_NO!",
	-- 703: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! and take the escalator
	["blq000t0"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! and take the escalator",
	-- 704: Now turn sharply right !NG_COMMAND_1! and take the escalator
	["a0s000t0"] = "Now make a sharp right !NG_COMMAND_1! and take the escalator",
	-- 705: Now take the street in the middle !NG_COMMAND_1! and go through the building
	["a0o000o0"] = "Now take the street in the middle !NG_COMMAND_1! and go through the building",
	-- 706: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and go through the building
	["bln000o0"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and go through the building",
	-- 707: Now walk straight ahead !NG_COMMAND_1! , cross the square
	["a0n00p00"] = "Now walk straight ahead !NG_COMMAND_1! , cross the square",
	-- 708: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and cross the park
	["bln000q0"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and cross the park",
	-- 709: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and take the lift
	["blx000s0"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and take the elevator",
	-- 710: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , take the escalator
	["blx00t00"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , take the escalator",
	-- 711: Now turn slightly right !NG_COMMAND_1! , take the escalator
	["a0q00t00"] = "Now bear right !NG_COMMAND_1! , take the escalator",
	-- 712: After !DIST! !UNIT! turn right !NG_COMMAND_1! and take the lift
	["blr000s0"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! and take the elevator",
	-- 713: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! and cross the park
	["blw000q0"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! and cross the park",
	-- 714: Now turn slightly right !NG_COMMAND_1! , take the stairs
	["a0q00r00"] = "Now bear right !NG_COMMAND_1! , take the stairs",
	-- 715: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! and take the stairs
	["blq000r0"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! and take the stairs",
	-- 716: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , take the stairs
	["blq00r00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , take the stairs",
	-- 717: Now turn !NG_COMMAND_1! onto the footpath
	["a0y00g00"] = "Now turn !NG_COMMAND_1! onto the footpath",
	-- 718: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! and cross the park
	["blu000q0"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! and cross the park",
	-- 719: Now turn right !NG_COMMAND_1! and go through the building
	["a0r000o0"] = "Now turn right !NG_COMMAND_1! and go through the building",
	-- 720: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! and go through the building
	["blu000o0"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! and go through the building",
	-- 721: Now turn sharply right !NG_COMMAND_1! , go through the building
	["a0s00o00"] = "Now make a sharp right !NG_COMMAND_1! , go through the building",
	-- 722: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! and take the escalator
	["blu000t0"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! and take the escalator",
	-- 723: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and take the stairs
	["blo000r0"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and take the stairs",
	-- 724: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! and take the stairs
	["bls000r0"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! and take the stairs",
	-- 725: After !DIST! !UNIT! turn left !NG_COMMAND_1! and cross the square
	["blv000p0"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! and cross the square",
	-- 726: After !DIST! !UNIT! turn right !NG_COMMAND_1! and cross the park
	["blr000q0"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! and cross the park",
	-- 727: Now turn left !NG_COMMAND_1! and take the stairs
	["a0v000r0"] = "Now turn left !NG_COMMAND_1! and take the stairs",
	-- 728: Now take the street on the left !NG_COMMAND_1! , take the escalator
	["a0x00t00"] = "Now take the street on the left !NG_COMMAND_1! , take the escalator",
	-- 729: Now turn slightly left !NG_COMMAND_1! , cross the square
	["a0w00p00"] = "Now bear left !NG_COMMAND_1! , cross the square",
	-- 730: Now turn sharply right !NG_COMMAND_1! and cross the park
	["a0s000q0"] = "Now make a sharp right !NG_COMMAND_1! and cross the park",
	-- 731: After !DIST! !UNIT! turn right !NG_COMMAND_1! and take the escalator
	["blr000t0"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! and take the escalator",
	-- 732: After !DIST! !UNIT! turn right !NG_COMMAND_1! and go through the building
	["blr000o0"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! and go through the building",
	-- 733: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and cross the park
	["blp000q0"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and cross the park",
	-- 734: After !DIST! !UNIT! walk right around the roundabout !NG_COMMAND_1!
	["bla00000"] = "After !DIST! !UNIT! walk right around the traffic circle !NG_COMMAND_1!",
	-- 735: Now take the street on the right !NG_COMMAND_1! and cross the square
	["a0p000p0"] = "Now take the street on the right !NG_COMMAND_1! and cross the square",
	-- 736: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! and go through the building
	["bls000o0"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! and go through the building",
	-- 737: Now walk straight ahead !NG_COMMAND_1! and take the stairs
	["a0n000r0"] = "Now walk straight ahead !NG_COMMAND_1! and take the stairs",
	-- 738: Now turn sharply right !NG_COMMAND_1! and go through the building
	["a0s000o0"] = "Now make a sharp right !NG_COMMAND_1! and go through the building",
	-- 739: Now turn right !NG_COMMAND_1! and take the lift
	["a0r000s0"] = "Now turn right !NG_COMMAND_1! and take the elevator",
	-- 740: Now turn slightly right !NG_COMMAND_1! and take the lift
	["a0q000s0"] = "Now bear right !NG_COMMAND_1! and take the elevator",
	-- 741: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , take the lift
	["blo00s00"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , take the elevator",
	-- 742: Now walk straight ahead !NG_COMMAND_1! , take the stairs
	["a0n00r00"] = "Now walk straight ahead !NG_COMMAND_1! , take the stairs",
	-- 743: After !DIST! !UNIT! turn right !NG_COMMAND_1! and take the stairs
	["blr000r0"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! and take the stairs",
	-- 744: Now take the street on the left !NG_COMMAND_1! and take the escalator
	["a0x000t0"] = "Now take the street on the left !NG_COMMAND_1! and take the escalator",
	-- 745: After !DIST! !UNIT! turn left !NG_COMMAND_1! and cross the park
	["blv000q0"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! and cross the park",
	-- 746: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , take the escalator
	["bln00t00"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , take the escalator",
	-- 747: Now turn sharply left !NG_COMMAND_1! and take the stairs
	["a0u000r0"] = "Now make a sharp left !NG_COMMAND_1! and take the stairs",
	-- 748: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! cross the park
	["blp00q00"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! cross the park",
	-- 749: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , cross the square
	["blp00p00"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , cross the square",
	-- 750: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! onto !STREET!
	["bln00d00"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! onto !STREET!",
	-- 751: Now take the street on the right !NG_COMMAND_1! , take the stairs
	["a0p00r00"] = "Now take the street on the right !NG_COMMAND_1! , take the stairs",
	-- 752: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , cross the square
	["blq00p00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , cross the square",
	-- 753: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , cross the park
	["blq00q00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , cross the park",
	-- 754: Now turn sharply right !NG_COMMAND_1! , take the stairs
	["a0s00r00"] = "Now make a sharp right !NG_COMMAND_1! , take the stairs",
	-- 755: Now turn !NG_COMMAND_1!
	["a0y00000"] = "Now turn !NG_COMMAND_1!",
	-- 756: Now turn left !NG_COMMAND_1! , cross the square
	["a0v00p00"] = "Now turn left !NG_COMMAND_1! , cross the square",
	-- 757: After !DIST! !UNIT! turn left !NG_COMMAND_1! and go through the building
	["blv000o0"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! and go through the building",
	-- 758: Now turn sharply right !NG_COMMAND_1! and take the lift
	["a0s000s0"] = "Now make a sharp right !NG_COMMAND_1! and take the elevator",
	-- 759: Now take the street on the left !NG_COMMAND_1! , take the stairs
	["a0x00r00"] = "Now take the street on the left !NG_COMMAND_1! , take the stairs",
	-- 760: Now turn slightly right !NG_COMMAND_1! and cross the square
	["a0q000p0"] = "Now bear right !NG_COMMAND_1! and cross the square",
	-- 761: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1!
	["bln00000"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1!",
	-- 762: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and cross the square
	["blx000p0"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and cross the square",
	-- 763: Now turn left !NG_COMMAND_1! and cross the park
	["a0v000q0"] = "Now turn left !NG_COMMAND_1! and cross the park",
	-- 764: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , take the stairs
	["blu00r00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , take the stairs",
	-- 765: Now take the street in the middle !NG_COMMAND_1! and take the escalator
	["a0o000t0"] = "Now take the street in the middle !NG_COMMAND_1! and take the escalator",
	-- 766: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! onto the footpath
	["blu00g00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! onto the footpath",
	-- 767: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , cross the square
	["bln00p00"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , cross the square",
	-- 768: Now turn right !NG_COMMAND_1! and take the escalator
	["a0r000t0"] = "Now turn right !NG_COMMAND_1! and take the escalator",
	-- 769: Now take the street on the left !NG_COMMAND_1! , cross the square
	["a0x00p00"] = "Now take the street on the left !NG_COMMAND_1! , cross the square",
	-- 770: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and cross the park
	["blx000q0"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and cross the park",
	-- 771: After !DIST! !UNIT! turn right !NG_COMMAND_1! , take the stairs
	["blr00r00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , take the stairs",
	-- 772: Now turn sharply right !NG_COMMAND_1! , cross the park
	["a0s00q00"] = "Now make a sharp right !NG_COMMAND_1! , cross the park",
	-- 773: Now take the street in the middle !NG_COMMAND_1! and cross the park
	["a0o000q0"] = "Now take the street in the middle !NG_COMMAND_1! and cross the park",
	-- 774: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! and take the escalator
	["bls000t0"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! and take the escalator",
	-- 775: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , cross the square
	["bls00p00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , cross the square",
	-- 776: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! and take the lift
	["bls000s0"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! and take the elevator",
	-- 777: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and take the escalator
	["bln000t0"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and take the escalator",
	-- 778: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and go through the building
	["blx000o0"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and go through the building",
	-- 779: Now take the street on the right !NG_COMMAND_1! , cross the square
	["a0p00p00"] = "Now take the street on the right !NG_COMMAND_1! , cross the square",
	-- 780: Now take the street on the right !NG_COMMAND_1! , take the lift
	["a0p00s00"] = "Now take the street on the right !NG_COMMAND_1! , take the elevator",
	-- 781: After !DIST! !UNIT! turn left !NG_COMMAND_1! , cross the square
	["blv00p00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , cross the square",
	-- 782: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , take the stairs
	["blp00r00"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , take the stairs",
	-- 783: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and continue on !STREET!
	["bln00f00"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and continue on !STREET!",
	-- 784: Now turn slightly left !NG_COMMAND_1! , take the stairs
	["a0w00r00"] = "Now bear left !NG_COMMAND_1! , take the stairs",
	-- 785: Now turn left !NG_COMMAND_1! , go through the building
	["a0v00o00"] = "Now turn left !NG_COMMAND_1! , go through the building",
	-- 786: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , take the escalator
	["blo00t00"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , take the escalator",
	-- 787: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , cross the square
	["blo00p00"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , cross the square",
	-- 788: Now walk straight ahead !NG_COMMAND_1! and take the lift
	["a0n000s0"] = "Now walk straight ahead !NG_COMMAND_1! and take the elevator",
	-- 789: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , take the stairs
	["bls00r00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , take the stairs",
	-- 790: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! and cross the square
	["blu000p0"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! and cross the square",
	-- 791: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , cross the park
	["blx00q00"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , cross the park",
	-- 792: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , cross the park
	["bls00q00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , cross the park",
	-- 793: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , cross the park
	["blu00q00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , cross the park",
	-- 794: Now turn sharply left !NG_COMMAND_1! and cross the park
	["a0u000q0"] = "Now make a sharp left !NG_COMMAND_1! and cross the park",
	-- 795: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and take the escalator
	["blp000t0"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and take the escalator",
	-- 796: Now turn slightly left !NG_COMMAND_1! , cross the park
	["a0w00q00"] = "Now bear left !NG_COMMAND_1! , cross the park",
	-- 797: Now take the street in the middle !NG_COMMAND_1! , take the escalator
	["a0o00t00"] = "Now take the street in the middle !NG_COMMAND_1! , take the escalator",
	-- 798: Now turn slightly right !NG_COMMAND_1! and cross the park
	["a0q000q0"] = "Now bear right !NG_COMMAND_1! and cross the park",
	-- 799: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , cross the park
	["blo00q00"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , cross the park",
	-- 800: Now turn slightly left !NG_COMMAND_1! and cross the square
	["a0w000p0"] = "Now bear left !NG_COMMAND_1! and cross the square",
	-- 801: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , take the stairs
	["blx00r00"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , take the stairs",
	-- 802: Now take the street in the middle !NG_COMMAND_1! , cross the square
	["a0o00p00"] = "Now take the street in the middle !NG_COMMAND_1! , cross the square",
	-- 803: After !DIST! !UNIT! turn left !NG_COMMAND_1! , take the stairs
	["blv00r00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , take the stairs",
	-- 804: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , take the stairs
	["blo00r00"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , take the stairs",
	-- 805: Head !ORIENTATION! towards !SIGNPOST!
	["f00000c0"] = "Head !ORIENTATION! towards !SIGNPOST!",
	-- 806: Now turn slightly left !NG_COMMAND_1! , go through the building
	["a0w00o00"] = "Now bear left !NG_COMMAND_1! , go through the building",
	-- 807: After !DIST! !UNIT! turn left !NG_COMMAND_1! , take the escalator
	["blv00t00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , take the escalator",
	-- 808: Now turn left !NG_COMMAND_1! and cross the square
	["a0v000p0"] = "Now turn left !NG_COMMAND_1! and cross the square",
	-- 809: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! take the lift
	["blq00s00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! take the elevator",
	-- 810: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! and cross the square
	["bls000p0"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! and cross the square",
	-- 811: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! onto the footpath
	["blq00g00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! onto the footpath",
	-- 812: Now turn sharply left !NG_COMMAND_1! and go through the building
	["a0u000o0"] = "Now make a sharp left !NG_COMMAND_1! and go through the building",
	-- 813: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , take the lift
	["blx00s00"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , take the elevator",
	-- 814: After !DIST! !UNIT! turn right !NG_COMMAND_1! , take the lift
	["blr00s00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , take the elevator",
	-- 815: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! , take the lift
	["bls00s00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! , take the elevator",
	-- 816: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , take the lift
	["blu00s00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , take the elevator",
	-- 817: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , take the escalator
	["blp00t00"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , take the escalator",
	-- 818: Now turn left !NG_COMMAND_1! , take the lift
	["a0v00s00"] = "Now turn left !NG_COMMAND_1! , take the elevator",
	-- 819: Now take the street on the left !NG_COMMAND_1! and go through the building
	["a0x000o0"] = "Now take the street on the left !NG_COMMAND_1! and go through the building",
	-- 820: Now take the street on the right !NG_COMMAND_1! and cross the park
	["a0p000q0"] = "Now take the street on the right !NG_COMMAND_1! and cross the park",
	-- 821: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , take the escalator
	["blu00t00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , take the escalator",
	-- 822: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , go through the building
	["blq00o00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , go through the building",
	-- 823: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , go through the building
	["blp00o00"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , go through the building",
	-- 824: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and take the escalator
	["blo000t0"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and take the escalator",
	-- 825: Now turn sharply left !NG_COMMAND_1! , take the lift
	["a0u00s00"] = "Now make a sharp left !NG_COMMAND_1! , take the elevator",
	-- 826: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , go through the building
	["blx00o00"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , go through the building",
	-- 827: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , go through the building
	["blu00o00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , go through the building",
	-- 828: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , go through the building
	["blw00o00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , go through the building",
	-- 829: After !DIST! !UNIT! turn left !NG_COMMAND_1! , go through the building
	["blv00o00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , go through the building",
	-- 830: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , go through the building
	["blo00o00"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! , go through the building",
	-- 831: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! , cross the square
	["blu00p00"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! , cross the square",
	-- 832: Now turn sharply right !NG_COMMAND_1! and take the stairs
	["a0s000r0"] = "Now make a sharp right !NG_COMMAND_1! and take the stairs",
	-- 833: Now turn right !NG_COMMAND_1! , cross the square
	["a0r00p00"] = "Now turn right !NG_COMMAND_1! , cross the square",
	-- 834: Now take the street in the middle !NG_COMMAND_1! and take the stairs
	["a0o000r0"] = "Now take the street in the middle !NG_COMMAND_1! and take the stairs",
	-- 835: Now turn sharply right !NG_COMMAND_1! , cross the square
	["a0s00p00"] = "Now make a sharp right !NG_COMMAND_1! , cross the square",
	-- 836: After !DIST! !UNIT! turn left !NG_COMMAND_1! and take the stairs
	["blv000r0"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! and take the stairs",
	-- 837: Now turn right !NG_COMMAND_1! and cross the park
	["a0r000q0"] = "Now turn right !NG_COMMAND_1! and cross the park",
	-- 838: Now turn right !NG_COMMAND_1! and take the stairs
	["a0r000r0"] = "Now turn right !NG_COMMAND_1! and take the stairs",
	-- 839: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! and cross the park
	["bls000q0"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! and cross the park",
	-- 840: Now turn sharply left !NG_COMMAND_1! , cross the square
	["a0u00p00"] = "Now make a sharp left !NG_COMMAND_1! , cross the square",
	-- 841: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , take the stairs
	["blw00r00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , take the stairs",
	-- 842: Now walk straight ahead !NG_COMMAND_1! , cross the park
	["a0n00q00"] = "Now walk straight ahead !NG_COMMAND_1! , cross the park",
	-- 843: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! and take the stairs
	["blw000r0"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! and take the stairs",
	-- 844: Now take the street on the right !NG_COMMAND_1! , cross the park
	["a0p00q00"] = "Now take the street on the right !NG_COMMAND_1! , cross the park",
	-- 845: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and cross the square
	["blp000p0"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and cross the square",
	-- 846: Now turn slightly right !NG_COMMAND_1! and take the escalator
	["a0q000t0"] = "Now bear right !NG_COMMAND_1! and take the escalator",
	-- 847: Now turn left !NG_COMMAND_1! and take the lift
	["a0v000s0"] = "Now turn left !NG_COMMAND_1! and take the elevator",
	-- 848: Now take the street on the left !NG_COMMAND_1! , cross the park
	["a0x00q00"] = "Now take the street on the left !NG_COMMAND_1! , cross the park",
	-- 849: Now turn right !NG_COMMAND_1! , cross the park
	["a0r00q00"] = "Now turn right !NG_COMMAND_1! , cross the park",
	-- 850: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! and cross the square
	["blq000p0"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! and cross the square",
	-- 851: Now turn sharply left !NG_COMMAND_1! , cross the park
	["a0u00q00"] = "Now make a sharp left !NG_COMMAND_1! , cross the park",
	-- 852: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , cross the park
	["blw00q00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , cross the park",
	-- 853: Now turn left !NG_COMMAND_1! , cross the park
	["a0v00q00"] = "Now turn left !NG_COMMAND_1! , cross the park",
	-- 854: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and go through the building
	["blp000o0"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and go through the building",
	-- 855: Now turn right !NG_COMMAND_1! , take the stairs
	["a0r00r00"] = "Now turn right !NG_COMMAND_1! , take the stairs",
	-- 856: Now turn left !NG_COMMAND_1! onto the footpath
	["a0v00g00"] = "Now turn left !NG_COMMAND_1! onto the footpath",
	-- 857: Now turn sharply left !NG_COMMAND_1! , take the stairs
	["a0u00r00"] = "Now make a sharp left !NG_COMMAND_1! , take the stairs",
	-- 858: Now walk straight ahead !NG_COMMAND_1! and take the escalator
	["a0n000t0"] = "Now walk straight ahead !NG_COMMAND_1! and take the escalator",
	-- 859: Now take the street on the left !NG_COMMAND_1! and take the stairs
	["a0x000r0"] = "Now take the street on the left !NG_COMMAND_1! and take the stairs",
	-- 860: After !DIST! !UNIT! turn right !NG_COMMAND_1! and cross the square
	["blr000p0"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! and cross the square",
	-- 861: Now take the street in the middle !NG_COMMAND_1! , take the stairs
	["a0o00r00"] = "Now take the street in the middle !NG_COMMAND_1! , take the stairs",
	-- 862: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! and go through the building
	["blq000o0"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! and go through the building",
	-- 863: Now turn slightly right !NG_COMMAND_1! , take the lift
	["a0q00s00"] = "Now bear right !NG_COMMAND_1! , take the elevator",
	-- 864: Now turn right !NG_COMMAND_1! , take the lift
	["a0r00s00"] = "Now turn right !NG_COMMAND_1! , take the elevator",
	-- 865: Now turn slightly right !NG_COMMAND_1! and take the stairs
	["a0q000r0"] = "Now bear right !NG_COMMAND_1! and take the stairs",
	-- 866: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and cross the square
	["blo000p0"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and cross the square",
	-- 867: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! , cross the square
	["blw00p00"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! , cross the square",
	-- 868: Now take the street on the left !NG_COMMAND_1! , take the lift
	["a0x00s00"] = "Now take the street on the left !NG_COMMAND_1! , take the elevator",
	-- 869: Now walk straight ahead !NG_COMMAND_1! onto !STREET!
	["a0n00d00"] = "Now walk straight ahead !NG_COMMAND_1! onto !STREET!",
	-- 870: Now turn sharply right !NG_COMMAND_1! , take the lift
	["a0s00s00"] = "Now make a sharp right !NG_COMMAND_1! , take the elevator",
	-- 871: Now turn slightly left !NG_COMMAND_1! , take the lift
	["a0w00s00"] = "Now bear left !NG_COMMAND_1! , take the elevator",
	-- 872: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! , take the escalator
	["blq00t00"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! , take the escalator",
	-- 873: Now take the street in the middle !NG_COMMAND_1! , take the lift
	["a0o00s00"] = "Now take the street in the middle !NG_COMMAND_1! , take the elevator",
	-- 874: Now walk straight ahead !NG_COMMAND_1! , take the escalator
	["a0n00t00"] = "Now walk straight ahead !NG_COMMAND_1! , take the escalator",
	-- 875: After !DIST! !UNIT! turn sharply right !NG_COMMAND_1! onto the footpath
	["bls00g00"] = "After !DIST! !UNIT! make a sharp right !NG_COMMAND_1! onto the footpath",
	-- 876: After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and go through the building
	["blo000o0"] = "After !DIST! !UNIT! take the street in the middle !NG_COMMAND_1! and go through the building",
	-- 877: Now turn right !NG_COMMAND_1! , go through the building
	["a0r00o00"] = "Now turn right !NG_COMMAND_1! , go through the building",
	-- 878: After !DIST! !UNIT! turn left !NG_COMMAND_1! and take the escalator
	["blv000t0"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! and take the escalator",
	-- 879: Now turn slightly left !NG_COMMAND_1! and cross the park
	["a0w000q0"] = "Now bear left !NG_COMMAND_1! and cross the park",
	-- 880: Now turn right !NG_COMMAND_1! , take the escalator
	["a0r00t00"] = "Now turn right !NG_COMMAND_1! , take the escalator",
	-- 881: Now turn sharply right !NG_COMMAND_1! , take the escalator
	["a0s00t00"] = "Now make a sharp right !NG_COMMAND_1! , take the escalator",
	-- 882: Now turn sharply left !NG_COMMAND_1! , take the escalator
	["a0u00t00"] = "Now make a sharp left !NG_COMMAND_1! , take the escalator",
	-- 883: Now turn left !NG_COMMAND_1! , take the escalator
	["a0v00t00"] = "Now turn left !NG_COMMAND_1! , take the escalator",
	-- 884: Now turn slightly right !NG_COMMAND_1! , go through the building
	["a0q00o00"] = "Now bear right !NG_COMMAND_1! , go through the building",
	-- 885: Now walk straight ahead !NG_COMMAND_1! , go through the building
	["a0n00o00"] = "Now walk straight ahead !NG_COMMAND_1! , go through the building",
	-- 886: Now take the street on the right !NG_COMMAND_1! , go through the building
	["a0p00o00"] = "Now take the street on the right !NG_COMMAND_1! , go through the building",
	-- 887: After !DIST! !UNIT! turn slightly right !NG_COMMAND_1! and take the lift
	["blq000s0"] = "After !DIST! !UNIT! bear right !NG_COMMAND_1! and take the elevator",
	-- 888: Now take the street on the right !NG_COMMAND_1! and take the lift
	["a0p000s0"] = "Now take the street on the right !NG_COMMAND_1! and take the elevator",
	-- 889: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! and take the lift
	["blu000s0"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! and take the elevator",
	-- 890: Now take the street on the left !NG_COMMAND_1! , go through the building
	["a0x00o00"] = "Now take the street on the left !NG_COMMAND_1! , go through the building",
	-- 891: Now take the street on the right !NG_COMMAND_1! , take the escalator
	["a0p00t00"] = "Now take the street on the right !NG_COMMAND_1! , take the escalator",
	-- 892: Head !ORIENTATION! on !STREET! towards !SIGNPOST!
	["f0000bc0"] = "Head !ORIENTATION! on !STREET! towards !SIGNPOST!",
	-- 893: Now take the street in the middle !NG_COMMAND_1! , go through the building
	["a0o00o00"] = "Now take the street in the middle !NG_COMMAND_1! , go through the building",
	-- 894: Now take the street on the left !NG_COMMAND_1! and cross the square
	["a0x000p0"] = "Now take the street on the left !NG_COMMAND_1! and cross the square",
	-- 895: Now turn right !NG_COMMAND_1! and cross the square
	["a0r000p0"] = "Now turn right !NG_COMMAND_1! and cross the square",
	-- 896: Now turn sharply right !NG_COMMAND_1! and cross the square
	["a0s000p0"] = "Now make a sharp right !NG_COMMAND_1! and cross the square",
	-- 897: Now turn sharply left !NG_COMMAND_1! and cross the square
	["a0u000p0"] = "Now make a sharp left !NG_COMMAND_1! and cross the square",
	-- 898: After !DIST! !UNIT! turn left !NG_COMMAND_1! , cross the park
	["blv00q00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , cross the park",
	-- 899: Now walk straight ahead !NG_COMMAND_1! and cross the park
	["a0n000q0"] = "Now walk straight ahead !NG_COMMAND_1! and cross the park",
	-- 900: Now turn sharply left onto the footpath
	["a0u00g00"] = "Now make a sharp left onto the footpath",
	-- 901: Now turn slightly left !NG_COMMAND_1! and go through the building
	["a0w000o0"] = "Now bear left !NG_COMMAND_1! and go through the building",
	-- 902: After !DIST! !UNIT! turn right !NG_COMMAND_1! , take the escalator
	["blr00t00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , take the escalator",
	-- 903: Now turn sharply left !NG_COMMAND_1! and take the lift
	["a0u000s0"] = "Now make a sharp left !NG_COMMAND_1! and take the elevator",
	-- 904: Now take the street on the right !NG_COMMAND_1! and take the stairs
	["a0p000r0"] = "Now take the street on the right !NG_COMMAND_1! and take the stairs",
	-- 905: Now turn left !NG_COMMAND_1! and go through the building
	["a0v000o0"] = "Now turn left !NG_COMMAND_1! and go through the building",
	-- 906: After !DIST! !UNIT! turn right !NG_COMMAND_1! , cross the square
	["blr00p00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! , cross the square",
	-- 907: Now walk straight ahead !NG_COMMAND_1! , take the lift
	["a0n00s00"] = "Now walk straight ahead !NG_COMMAND_1! , take the elevator",
	-- 908: Now turn slightly left !NG_COMMAND_1! and take the stairs
	["a0w000r0"] = "Now bear left !NG_COMMAND_1! and take the stairs",
	-- 909: Now take the street on the left !NG_COMMAND_1! and take the lift
	["a0x000s0"] = "Now take the street on the left !NG_COMMAND_1! and take the elevator",
	-- 910: Now turn slightly left onto the footpath
	["a0w00g00"] = "Now bear left onto the footpath",
	-- 911: Now take the street in the middle !NG_COMMAND_1! and take the lift
	["a0o000s0"] = "Now take the street in the middle !NG_COMMAND_1! and take the elevator",
	-- 912: After !DIST! !UNIT! turn left !NG_COMMAND_1! and take the lift
	["blv000s0"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! and take the elevator",
	-- 913: After !DIST! !UNIT! turn right !NG_COMMAND_1! onto the footpath
	["blr00g00"] = "After !DIST! !UNIT! turn right !NG_COMMAND_1! onto the footpath",
	-- 914: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and take the stairs
	["blp000r0"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and take the stairs",
	-- 915: Head !ORIENTATION! on !STREET!
	["f0000b00"] = "Head !ORIENTATION! on !STREET!",
	-- 916: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and take the stairs
	["blx000r0"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and take the stairs",
	-- 917: After !DIST! !UNIT! !NG_COMMAND_1! turn slightly left onto the footpath
	["blw00g00"] = "After !DIST! !UNIT! !NG_COMMAND_1! bear left onto the footpath",
	-- 918: Now walk straight ahead !NG_COMMAND_1! and go through the building
	["a0n000o0"] = "Now walk straight ahead !NG_COMMAND_1! and go through the building",
	-- 919: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and cross the square
	["bln000p0"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! and cross the square",
	-- 920: After !DIST! !UNIT! walk around the roundabout !NG_COMMAND_1!
	["blc00000"] = "After !DIST! !UNIT! walk around the traffic circle !NG_COMMAND_1!",
	-- 921: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , take the lift
	["bln00s00"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , take the elevator",
	-- 922: After !DIST! !UNIT! turn slightly left !NG_COMMAND_1! and cross the square
	["blw000p0"] = "After !DIST! !UNIT! bear left !NG_COMMAND_1! and cross the square",
	-- 923: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , cross the square
	["blx00p00"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! , cross the square",
	-- 924: Now take the street on the right !NG_COMMAND_1! and take the escalator
	["a0p000t0"] = "Now take the street on the right !NG_COMMAND_1! and take the escalator",
	-- 925: After !DIST! !UNIT! turn left !NG_COMMAND_1! , take the lift
	["blv00s00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! , take the elevator",
	-- 926: After !DIST! !UNIT! turn sharply left !NG_COMMAND_1! and take the stairs
	["blu000r0"] = "After !DIST! !UNIT! make a sharp left !NG_COMMAND_1! and take the stairs",
	-- 927: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and take the lift
	["blp000s0"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! and take the elevator",
	-- 928: After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , go through the building
	["bln00o00"] = "After !DIST! !UNIT! walk straight ahead !NG_COMMAND_1! , go through the building",
	-- 929: Now take the street on the left !NG_COMMAND_1! and cross the park
	["a0x000q0"] = "Now take the street on the left !NG_COMMAND_1! and cross the park",
	-- 930: After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , take the lift
	["blp00s00"] = "After !DIST! !UNIT! take the street on the right !NG_COMMAND_1! , take the elevator",
	-- 931: After !DIST! !UNIT! turn left !NG_COMMAND_1! onto the footpath
	["blv00g00"] = "After !DIST! !UNIT! turn left !NG_COMMAND_1! onto the footpath",
	-- 932: Now turn slightly left !NG_COMMAND_1! and take the lift
	["a0w000s0"] = "Now bear left !NG_COMMAND_1! and take the elevator",
	-- 933: Now walk straight ahead !NG_COMMAND_1!
	["a0n00000"] = "Now walk straight ahead !NG_COMMAND_1!",
	-- 934: Now turn sharply right onto the footpath
	["a0s00g00"] = "Now make a sharp right onto the footpath",
	-- 935: Now turn !NG_COMMAND_1! onto !STREET!
	["a0y00d00"] = "Now turn !NG_COMMAND_1! onto !STREET!",
	-- 936: Now turn sharply left !NG_COMMAND_1! , go through the building
	["a0u00o00"] = "Now make a sharp left !NG_COMMAND_1! , go through the building",
	-- 951: After !DIST! !UNIT! !NG_COMMAND_1! go through the building
	["bl000o00"] = "After !DIST! !UNIT! !NG_COMMAND_1! go through the building",
	-- 952: After !DIST! !UNIT! !NG_COMMAND_1! cross the square
	["bl000p00"] = "After !DIST! !UNIT! !NG_COMMAND_1! cross the square",
	-- 953: After !DIST! !UNIT! !NG_COMMAND_1! cross the park
	["bl000q00"] = "After !DIST! !UNIT! !NG_COMMAND_1! cross the park",
	-- 954: After !DIST! !UNIT! !NG_COMMAND_1! take the stairs
	["bl000r00"] = "After !DIST! !UNIT! !NG_COMMAND_1! take the stairs",
	-- 955: After !DIST! !UNIT! !NG_COMMAND_1! take the lift
	["bl000s00"] = "After !DIST! !UNIT! !NG_COMMAND_1! take the lift",
	-- 956: After !DIST! !UNIT! !NG_COMMAND_1! take the escalator
	["bl000t00"] = "After !DIST! !UNIT! !NG_COMMAND_1! take the escalator",
	-- 957: After !DIST! !UNIT! walk right around the roundabout and turn onto !STREET!
	["bla00h00"] = "After !DIST! !UNIT! walk right around the traffic circle and turn onto !STREET!",
	-- 958: After !DIST! !UNIT! walk right around the roundabout !NG_COMMAND_1! !PED_TURN_NO!
	["bla00j00"] = "After !DIST! !UNIT! walk right around the traffic circle !NG_COMMAND_1! !PED_TURN_NO!",
	-- 959: After !DIST! !UNIT! walk left around the roundabout !NG_COMMAND_1! and turn onto !STREET!
	["blb00h00"] = "After !DIST! !UNIT! walk left around the traffic circle !NG_COMMAND_1! and turn onto !STREET!",
	-- 960: After !DIST! !UNIT! walk left around the roundabout !PED_TURN_NO!
	["blb00j00"] = "After !DIST! !UNIT! walk left around the traffic circle !PED_TURN_NO!",
	-- 961: After !DIST! !UNIT! walk around the roundabout and turn onto !STREET!
	["blc00h00"] = "After !DIST! !UNIT! walk around the traffic circle and turn onto !STREET!",
	-- 962: After !DIST! !UNIT! walk around the roundabout !PED_TURN_NO!
	["blc00j00"] = "After !DIST! !UNIT! walk around the traffic circle !PED_TURN_NO!",
	-- 963: After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and take the escalator
	["blx000t0"] = "After !DIST! !UNIT! take the street on the left !NG_COMMAND_1! and take the escalator",
}
