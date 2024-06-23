@ TRANSLATED

.set LOCALID_NURSE, 1

LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether:
	.string "Jeg tror, at POKéMON kommer tættere på\n"
	.string "deres TRÆNERE, når de tilbringer tid\l"
	.string "sammen. Jo længere, jo bedre.\p"
	.string "Det er hvad jeg tænker.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate:
	.string "Det er lidt magisk, hvordan man bare kan\n"
	.string "få energi af at sidde i et varmt kildbad. \l"
	.string "Jeg ville ønske, at mine POKéMON også\l"
	.string "kunne blive forkælet.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo:
	.string "Høhøhø! Hej, knægt, du kan nå de varme\n"
	.string "kilder herfra.\p"
	.string "Hvis POKéMON får hvile, så skulle deres\n"
	.string "TRÆNERE også.$"



