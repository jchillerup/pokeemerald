@ TRANSLATED

.set LOCALID_NURSE, 1
.set LOCALID_LANETTE, 4

FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
	.string "Hej, hej.\n"
	.string "Hvad hedder du?\p"
	.string "Okay, dit navn er {PLAYER}{KUN}.\n"
	.string "Jeg kan se, at du er en TRÆNER.\p"
	.string "Det betyder, at du bruger det POKéMON\n"
	.string "Opbevaringssystem, jeg har udviklet.\p"
	.string "Hvordan jeg nåede frem til den konklusion,\n"
	.string "er en enkel deduktiv proces.\p"
	.string "Du talte med mig, fordi du ønskede\n"
	.string "adgang til noget på denne computer.\p"
	.string "Åh, undskyld. Jeg er LANETTE.\p"
	.string "Ærligt talt er jeg glad for at møde dig--det\n"
	.string "er fantastisk, at du bruger Opbevaringssystemet.\p"
	.string "Hvis du kunne, så besøg mig derhjemme.\n"
	.string "Mit hus er på RUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "Jeg er nysgerrig på, hvordan POKéMON så ud\n"
	.string "for længe, længe siden?\p"
	.string "Måske vil FOSSILFANATIKEREN ved kanten\n"
	.string "af byen vide.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "I FJEDENE AF FALLARBOR, planter vi\n"
	.string "spirer af robuste træer, der trives\n"
	.string "selv i vulkansk aske.$"



