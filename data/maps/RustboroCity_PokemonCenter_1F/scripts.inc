@ TRANSLATED

.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Min POKéMON har en NAIV natur, og min\n"
	.string "ven har en MUNTER natur.\p"
	.string "Det er fascinerende, hvordan POKéMON har\n"
	.string "personligheder!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Præcis som mennesker, er der hanner og\n"
	.string "hunner POKéMON.\p"
	.string "Men ingen synes at have nogen idé om,\n"
	.string "hvordan de er forskellige.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "Manden ved siden af gav mig en HM!\p"
	.string "Jeg brugte den til at lære mine POKéMON\n"
	.string "at SKÆRE ned tynde træer.$"



