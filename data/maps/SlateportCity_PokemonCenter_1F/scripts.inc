@ TRANSLATED

.set LOCALID_NURSE, 1

SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Vil du have et tip til kampene?\p"
	.string "Jeg vil sige, at det er at træne forskellige\n"
	.string "typer af POKéMON på en balanceret måde.\p"
	.string "Det er ikke godt kun at gøre én POKéMON\n"
	.string "stærk.\p"
	.string "Hvis den har en typemæssig ulempe, har den\n"
	.string "måske ikke en chance.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "Jeg bytter POKéMON med mine venner.\p"
	.string "Hvis en byttet POKéMON holder et item, gør\n"
	.string "det mig dobbelt så glad!$"



