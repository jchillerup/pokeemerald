@ TRANSLATED

.set LOCALID_NURSE, 1

SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn:
	.string "WALLACE siges at være den sejeste\n"
	.string "TRÆNER i hele HOENN-regionen.\p"
	.string "Denne bys GYM ledes af TRÆNEREN, der\n"
	.string "underviste WALLACE.\p"
	.string "Men ELITE FOUR... Siges at være endnu\n"
	.string "stærkere end WALLACEs mentor.\p"
	.string "Hvor stærke mon de er?$"

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge:
	.string "Alle i byen har søgt tilflugt og vil ikke\n"
	.string "komme ud af deres hjem.\p"
	.string "Selv jeg vil hellere ikke tage udenfor.$"

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon:
	.string "Når som helst, hvor som helst, og hvad\n"
	.string "som helst der sker, vil jeg altid være\l"
	.string "venner med POKéMON.\p"
	.string "Fordi det er sjovt at være med POKéMON!$"

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends:
	.string "Er POKéMON ikke vores venner?\p"
	.string "Hvorfor opfører de sig så vildt?$"



