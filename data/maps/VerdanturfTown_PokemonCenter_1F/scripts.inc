@ TRANSLATED

.set LOCALID_NURSE, 1

VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "Du kan ikke betragte dig selv som en\n"
	.string "TRÆNER, hvis du ikke har tro på dine\l"
	.string "POKéMON.\p"
	.string "Kun de, der kan tro på deres kæmpende\n"
	.string "POKéMON, kan vinde helt til slutningen.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "Grunden til at nogen ville besøge\n"
	.string "VERDANTURF…\p"
	.string "Det er KAMPTALTET. Det siger sig selv.\p"
	.string "Eller er der nogen her, som du kom for at\n"
	.string "besøge?$"



