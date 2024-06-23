@ TRANSLATED

.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Den PC i hjørnet der er til brug for\n"
	.string "enhver POKéMON TRAINER.\p"
	.string "Selvfølgelig betyder det, at du også er\n"
	.string "velkommen til at bruge den.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTRE er fantastisk!\p"
	.string "Du kan bruge deres services så meget du\n"
	.string "vil, og det er alt sammen gratis. Du\l"
	.string "behøver aldrig bekymre dig!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "POKéMON TRÅDLØSE KLUB på anden sal\n"
	.string "blev bygget for nylig.\p"
	.string "Men de siger, at de stadig laver\n"
	.string "justeringer.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "POKéMON WIRELESS CLUB på anden sal\n"
	.string "blev bygget for nylig.\p"
	.string "Jeg byttede POKéMON med det samme.$"



