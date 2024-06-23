@ TRANSLATED

.set LOCALID_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Det der PC-baserede POKéMON\n"
	.string "opbevarings system…\p"
	.string "Den, der lavede det, må være en slags\n"
	.string "videnskabelig troldmand!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Når min POKéMON spiste en ORAN BÆR, fik\n"
	.string "den HP tilbage!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Der findes mange typer af POKéMON.\p"
	.string "Alle typer har deres styrker og\n"
	.string "svagheder over for andre typer.\p"
	.string "Afhængigt af POKéMONs typer, kunne en\n"
	.string "kamp være nem eller svær.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "For eksempel, din TREECKO er af\n"
	.string "GRÆS-typen.\p"
	.string "Den er stærk mod VAND- og\n"
	.string "JORD-typerne.\p"
	.string "Men den er svag over for ILD-typen\n"
	.string "POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "For eksempel er din TORCHIC en ILD\n"
	.string "type.\p"
	.string "Den er stærk mod GRÆS og INSEKT typer.\p"
	.string "Men den er svag over for VAND- type\n"
	.string "POKéMON.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "For eksempel er din MUDKIP af typen\n"
	.string "VAND.\p"
	.string "Det er stærkt imod Ild-typen.\p"
	.string "Men det er svagt imod GRÆS-typen og\n"
	.string "ELEKTRISK-typen af POKéMON.$"



