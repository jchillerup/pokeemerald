@ TRANSLATED

.set LOCALID_NURSE, 1

MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
	.string "Den mand derovre, han siger mærkelige\n"
	.string "ting!\p"
	.string "Han er sjov på en underlig måde. Jeg\n"
	.string "tvivler på, at jeg glemmer ham!$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "Da jeg fik adgang til\n"
	.string "REGISTRERINGSKROGEN, opdateredes\l"
	.string "dataene for hvad der er hot i DEWFORD Nu\l"
	.string "er den information den samme som min\l"
	.string "vens!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "En PLADEKROG åbnede ovenpå i\n"
	.string "POKéMON-CENTRET.\p"
	.string "Jeg ved ikke, hvad det handler om, men\n"
	.string "det lyder sjovt. Jeg vil gå tjekke det\l"
	.string "ud!$"



