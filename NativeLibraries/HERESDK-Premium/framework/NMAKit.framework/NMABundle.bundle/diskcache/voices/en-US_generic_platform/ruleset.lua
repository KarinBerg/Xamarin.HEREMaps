-- ----------------------------------------------------------------------------
-- Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
-- All rights reserved.
-- The use of this software is conditional upon having a separate agreement
-- with a HERE company for the use or utilization of this software. In the
-- absence of such agreement, the use of the software is not allowed.
-- ---------------------------------------------------------------------------- 
--      Authors: Fabian TP Riek
-- ----------------------------------------------------------------------------

function replace(input, search_str, replace_str)
    return string.gsub(input, "^"..search_str.."[%.]?$", replace_str)
end


function contains(table, element, casesensitive)
  casesensitive = casesensitive or true
  for _, value in pairs(table) do
    if casesenesitive == true then
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


function lang_spec_abbr(token)	-- Language specific abbreviation rules

    -- Special cases, fix for MSDKB-757
    token, _ = string.gsub( token, "N J-N Y", "New Jersey New York" )
    token, _ = string.gsub( token, "S F ", "San Francisco " )
    token, _ = string.gsub( token, "N Y ", "New York " )
    token, _ = string.gsub( token, "N J ", "New Jersey " )

    local words = split_token(token)

    local has_cardinal = false
    local cardinals = { 'N', 'S', 'E', 'W', 'NE', 'NW', 'SE', 'SW', 'North', 'South', 'East', 'West', 'Northeast', 'Northwest', 'Southeast', 'Southwest' }

    -- check if the last word is a cardinal direction...
    if( contains( cardinals, words[table.getn( words )][1], false ) ) then
        has_cardinal = true
    end

    for i = 1, table.getn(words) do
        local word = words[i][1]
        -- all but last word rules...
        if ( ( has_cardinal == false and i < table.getn( words ) ) or ( has_cardinal == true and i < table.getn( words ) - 1 ) ) then
            word, _ = replace( word, "[Dd][Rr]", "Doctor" )
            word, _ = replace( word, "[Ss][Tt]", "Saint" )
            word, _ = replace( word, "SF", "San Francisco " )
            word, _ = replace( word, "NY", "New York " )
            word, _ = replace( word, "NJ", "New Jersey " )
            word, _ = replace( word, "Int'L", "International" )
            word, _ = replace( word, "Int'l", "International" )
            word, _ = replace( word, "Intl", "International" )
        end

        -- last word rules
        if ( ( has_cardinal == false and i == table.getn( words ) ) or ( has_cardinal == true and i == table.getn( words ) - 1 ) ) then
            -- Expansion of abbreviations that are at the end of street names (USA)
            word, _ = replace( word, "Aly", "Alley" )
            word, _ = replace( word, "Anx", "Annex" )
            word, _ = replace( word, "Arc", "Arcade" )
            word, _ = replace( word, "Ave", "Avenue" )
            word, _ = replace( word, "Byu", "Bayou" )
            word, _ = replace( word, "Bch", "Beach" )
            word, _ = replace( word, "Bnd", "Bend" )
            word, _ = replace( word, "Blf", "Bluff" )
            word, _ = replace( word, "Blfs", "Bluffs" )
            word, _ = replace( word, "Btm", "Bottom" )
            word, _ = replace( word, "Blvd", "Boulevard" )
            word, _ = replace( word, "Bldg", "Building" )
            word, _ = replace( word, "Br", "Branch" )
            word, _ = replace( word, "Brg", "Bridge" )
            word, _ = replace( word, "Brk", "Brook" )
            word, _ = replace( word, "Brks", "Brooks" )
            word, _ = replace( word, "Bg", "Burg" )
            word, _ = replace( word, "Bgs", "Burgs" )
            word, _ = replace( word, "Byp", "Bypass" )
            word, _ = replace( word, "Cp", "Camp" )
            word, _ = replace( word, "Cyn", "Canyon" )
            word, _ = replace( word, "Cpe", "Cape" )
            word, _ = replace( word, "Crt", "Court" )
            word, _ = replace( word, "Cswy", "Causeway" )
            word, _ = replace( word, "Ctr", "Center" )
            word, _ = replace( word, "Ctrs", "Centers" )
            word, _ = replace( word, "Cir", "Circle" )
            word, _ = replace( word, "Cirs", "Circles" )
            word, _ = replace( word, "Clf", "Cliff" )
            word, _ = replace( word, "Clfs", "Cliffs" )
            word, _ = replace( word, "Clb", "Club" )
            word, _ = replace( word, "Cmn", "Common" )
            word, _ = replace( word, "Cmns", "Commons" )
            word, _ = replace( word, "Cntr", "Center" )
            word, _ = replace( word, "Cor", "Corner" )
            word, _ = replace( word, "Cors", "Corners" )
            word, _ = replace( word, "Crse", "Course" )
            word, _ = replace( word, "Ct", "Court" )
            word, _ = replace( word, "Cts", "Courts" )
            word, _ = replace( word, "Cv", "Cove" )
            word, _ = replace( word, "Cvs", "Coves" )
            word, _ = replace( word, "Crk", "Creek" )
            word, _ = replace( word, "Cres", "Crescent" )
            word, _ = replace( word, "Crst", "Crest" )
            word, _ = replace( word, "Xing", "Crossing" )
            word, _ = replace( word, "Xrd", "Crossroad" )
            word, _ = replace( word, "Xrds", "Crossroads" )
            word, _ = replace( word, "Curv", "Curve" )
            word, _ = replace( word, "Dl", "Dale" )
            word, _ = replace( word, "Dm", "Dam" )
            word, _ = replace( word, "Dvsn", "Diversion" )
            word, _ = replace( word, "Dv", "Divide" )
            word, _ = replace( word, "Dr", "Drive" )
            word, _ = replace( word, "Drs", "Drives" )
            word, _ = replace( word, "Est", "Estate" )
            word, _ = replace( word, "Ests", "Estates" )
            word, _ = replace( word, "Expy", "Expressway" )
            word, _ = replace( word, "Ext", "Extension" )
            word, _ = replace( word, "Exts", "Extensions" )
            word, _ = replace( word, "Fall", "Fall" )
            word, _ = replace( word, "Fls", "Falls" )
            word, _ = replace( word, "Fry", "Ferry" )
            word, _ = replace( word, "Fld", "Field" )
            word, _ = replace( word, "Flds", "Fields" )
            word, _ = replace( word, "Flt", "Flat" )
            word, _ = replace( word, "Flts", "Flats" )
            word, _ = replace( word, "Frd", "Ford" )
            word, _ = replace( word, "Frds", "Fords" )
            word, _ = replace( word, "Frst", "Forest" )
            word, _ = replace( word, "Frg", "Forge" )
            word, _ = replace( word, "Frgs", "Forges" )
            word, _ = replace( word, "Frk", "Fork" )
            word, _ = replace( word, "Frks", "Forks" )
            word, _ = replace( word, "Ft", "Fort" )
            word, _ = replace( word, "Fwy", "Freeway" )
            word, _ = replace( word, "Gdn", "Garden" )
            word, _ = replace( word, "Gdns", "Gardens" )
            word, _ = replace( word, "Gtwy", "Gateway" )
            word, _ = replace( word, "Gln", "Glen" )
            word, _ = replace( word, "Glns", "Glens" )
            word, _ = replace( word, "Grn", "Green" )
            word, _ = replace( word, "Grns", "Greens" )
            word, _ = replace( word, "Grv", "Grove" )
            word, _ = replace( word, "Grvs", "Groves" )
            word, _ = replace( word, "Hbr", "Harbor" )
            word, _ = replace( word, "Hbrs", "Harbors" )
            word, _ = replace( word, "Hvn", "Haven" )
            word, _ = replace( word, "Hts", "Heights" )
            word, _ = replace( word, "Hwy", "Highway" )
            word, _ = replace( word, "Hl", "Hill" )
            word, _ = replace( word, "Hls", "Hills" )
            word, _ = replace( word, "Holw", "Hollow" )
            word, _ = replace( word, "Inlt", "Inlet" )
            word, _ = replace( word, "Int'L", "International" )
            word, _ = replace( word, "Int'l", "International" )
            word, _ = replace( word, "Intl", "International" )
            word, _ = replace( word, "Is", "Island" )
            word, _ = replace( word, "Iss", "Islands" )
            word, _ = replace( word, "Jct", "Junction" )
            word, _ = replace( word, "Jcts", "Junctions" )
            word, _ = replace( word, "Ky", "Key" )
            word, _ = replace( word, "Kys", "Keys" )
            word, _ = replace( word, "Knl", "Knoll" )
            word, _ = replace( word, "Knls", "Knolls" )
            word, _ = replace( word, "Lk", "Lake" )
            word, _ = replace( word, "Lks", "Lakes" )
            word, _ = replace( word, "Lndg", "Landing" )
            word, _ = replace( word, "Ln", "Lane" )
            word, _ = replace( word, "Lgt", "Light" )
            word, _ = replace( word, "Lgts", "Lights" )
            word, _ = replace( word, "Lf", "Loaf" )
            word, _ = replace( word, "Lck", "Lock" )
            word, _ = replace( word, "Lcks", "Locks" )
            word, _ = replace( word, "Ldg", "Lodge" )
            word, _ = replace( word, "Ltn", "Longturn" )
            word, _ = replace( word, "Mkt", "Market" )
            word, _ = replace( word, "Mnr", "Manor" )
            word, _ = replace( word, "Mnrs", "Manors" )
            word, _ = replace( word, "Mdw", "Meadow" )
            word, _ = replace( word, "Mdws", "Meadows" )
            word, _ = replace( word, "Ml", "Mill" )
            word, _ = replace( word, "Mls", "Mills" )
            word, _ = replace( word, "Msn", "Mission" )
            word, _ = replace( word, "Mtwy", "Motorway" )
            word, _ = replace( word, "Mt", "Mount" )
            word, _ = replace( word, "Mtn", "Mountain" )
            word, _ = replace( word, "Mtns", "Mountains" )
            word, _ = replace( word, "Nck", "Neck" )
            word, _ = replace( word, "Orch", "Orchard" )
            word, _ = replace( word, "Ovl", "Oval" )
            word, _ = replace( word, "Opas", "Overpass" )
            word, _ = replace( word, "Orgn", "Organization" )
            word, _ = replace( word, "Pky", "Parkway" )
            word, _ = replace( word, "Pkw", "Parkway" )
            word, _ = replace( word, "Pkwy", "Parkway" )
            word, _ = replace( word, "Pass", "Pass" )
            word, _ = replace( word, "Psge", "Passage" )
            word, _ = replace( word, "Pne", "Pine" )
            word, _ = replace( word, "Pnes", "Pines" )
            word, _ = replace( word, "Pl", "Place" )
            word, _ = replace( word, "Pln", "Plain" )
            word, _ = replace( word, "Plns", "Plains" )
            word, _ = replace( word, "Plz", "Plaza" )
            word, _ = replace( word, "Pt", "Point" )
            word, _ = replace( word, "Pts", "Points" )
            word, _ = replace( word, "Prt", "Port" )
            word, _ = replace( word, "Prts", "Ports" )
            word, _ = replace( word, "Pr", "Prairie" )
            word, _ = replace( word, "Radl", "Radial" )
            word, _ = replace( word, "Rnch", "Ranch" )
            word, _ = replace( word, "Rpd", "Rapid" )
            word, _ = replace( word, "Rpds", "Rapids" )
            word, _ = replace( word, "Rst", "Rest" )
            word, _ = replace( word, "Rdg", "Ridge" )
            word, _ = replace( word, "Rdgs", "Ridges" )
            word, _ = replace( word, "Riv", "River" )
            word, _ = replace( word, "Rd", "Road" )
            word, _ = replace( word, "Rds", "Roads" )
            word, _ = replace( word, "Rng", "Range" )
            word, _ = replace( word, "Rte", "Route" )
            word, _ = replace( word, "Shl", "Shoal" )
            word, _ = replace( word, "Shls", "Shoals" )
            word, _ = replace( word, "Shr", "Shore" )
            word, _ = replace( word, "Shrs", "Shores" )
            word, _ = replace( word, "Skwy", "Skyway" )
            word, _ = replace( word, "Spg", "Spring" )
            word, _ = replace( word, "Spgs", "Springs" )
            word, _ = replace( word, "Sq", "Square" )
            word, _ = replace( word, "Sqs", "Squares" )
            word, _ = replace( word, "Sta", "Station" )
            word, _ = replace( word, "Stra", "Stravenue" )
            word, _ = replace( word, "Strm", "Stream" )
            word, _ = replace( word, "St", "Street" )
            word, _ = replace( word, "Sts", "Streets" )
            word, _ = replace( word, "Smt", "Summit" )
            word, _ = replace( word, "Ter", "Terrace" )
            word, _ = replace( word, "Terr", "Terrace" )
            word, _ = replace( word, "Trwy", "Throughway" )
            word, _ = replace( word, "Trce", "Trace" )
            word, _ = replace( word, "Trak", "Track" )
            word, _ = replace( word, "Trfy", "Trafficway" )
            word, _ = replace( word, "Trl", "Trail" )
            word, _ = replace( word, "Tunl", "Tunnel" )
            word, _ = replace( word, "Trlr", "Trailer" )
            word, _ = replace( word, "Tpk", "Turnpike" )
            word, _ = replace( word, "Tpke", "Turnpike" )
            word, _ = replace( word, "Upas", "Underpass" )
            word, _ = replace( word, "Un", "Union" )
            word, _ = replace( word, "Uns", "Unions" )
            word, _ = replace( word, "Vly", "Valley" )
            word, _ = replace( word, "Vlys", "Valleys" )
            word, _ = replace( word, "Via", "Viaduct" )
            word, _ = replace( word, "Vw", "View" )
            word, _ = replace( word, "Vws", "Views" )
            word, _ = replace( word, "Vlg", "Village" )
            word, _ = replace( word, "Vlgs", "Villages" )
            word, _ = replace( word, "Vl", "Ville" )
            word, _ = replace( word, "Vis", "Vista" )
            word, _ = replace( word, "Whse", "Warehouse" )
            word, _ = replace( word, "Wl", "Well" )
            word, _ = replace( word, "Wls", "Wells" )
        end

        -- all words rules
        word, _ = replace( word, "I[-](%d+)", "Interstate %1" )	-- replaces I-[0-9] with "Interstate [0-9]"
        -- I-90/I-94, has to be before the slash handling
        word, _ = replace( word, "I-(%d+)/I-(%d+)", "Interstate %1, %2" )
        -- replace globally Jr with Junior
        word, _ = replace( word, "[Jj][Rr]", "Junior" )

        -- TODO: Break all of these down to:
        -- word, _ = replace( word, "([A-HJ-Z])(%d)(%d?)(%d?)(%d?)", "%1 %2 %3 %4" )

        -- use 'double oh' if the middle 2 digits are zero of a 4 digit number following a capital letter
        word, _ = replace( word, "([A-Z]%d)00(%d)", "%1 double oh %2" )
        -- pronounce 0 in 2nd position of a 4 digit number following a capital letter as 'Oh'
        word, _ = replace( word, "([A-Z]%d)0(%d)(%d)", "%1 oh %2 %3" )
        -- pronounce 0 in 3rd position of a 4 digit number following a capital letter as 'Oh',
        -- knowing that a 3 digit number with 0 in the middle is pronounced correctly in address mode
        word, _ = replace( word, "([A-Z]%d)(%d)0(%d)", "%1 %2 oh %3" )
        -- spell capital letter followed by 3 digits (not zero)
        word, _ = replace( word, "([A-Z]%d)([1-9])([1-9])", "%1 %2 %3" )
        -- spell capital letter followed by 4 digits if the last digit is non zero
        word, _ = replace( word, "([A-Z]%d)(%d)(%d)([1-9])", "%1 %2 %3 %4" )
        
        -- Replace umlauts with the corresponding letters, for words with length smaller or equal to 3, to improve pronunciation
        -- Since Lua deals with UTF-8 characters, the length of a string containing a diaeresis is actually 4, since the diaeresis character is represented on 2 bytes
        if ( string.len( word ) <= 4 ) then
            word, _ = string.gsub( word, "ä", "ae" )
            word, _ = string.gsub( word, "ö", "oe" )
            word, _ = string.gsub( word, "ü", "ue" )
        end
        
        -- TODO: should this go into the last word rules?
        -- compass directions on highway exit numbers (USA)
        word, _ = replace( word, "N%-?E", "North East" )
        word, _ = replace( word, "N%-?W", "North West" )
        word, _ = replace( word, "S%-?E", "South East" )
        word, _ = replace( word, "S%-?W", "South West" )
        word, _ = replace( word, "N", "North" )
        word, _ = replace( word, "S", "South" )
        word, _ = replace( word, "E", "East" )
        word, _ = replace( word, "W", "West" )

        words[i][1] = word
    end

    -- re-construct the token based on the components
    token = ""
    for i = 1, table.getn(words) do
        token = token..words[i][1]..words[i][2]
    end

    return token

end


function checkMultiPlurals( distance, usedUnit, isFollow )
    return distance, usedUnit
end


function languageSpecificMods( result_sentence )

    -- avoid end of sentence detection for a German ordinal number (1 or 2 digits) followed by a capital letter (e.g. 15. Juni)
    result_sentence = string.gsub( result_sentence, "(%d+)%.%s+([A-Z])", "%1 %2" )
    
    return result_sentence

end


function can_shorten( article, noun )
    return false, { ["ortho"] = article }
end


abbr_begin = {
}

abbr_end = {
}

abbr_cs = {
}

abbr_misc = {
}