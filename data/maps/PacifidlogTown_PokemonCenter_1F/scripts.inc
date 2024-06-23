@ TRANSLATED

.set LOCALID_NURSE, 1

PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "Hvilken farve er dit TRÆNERKORT? Mit er\n"
	.string "kobber!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "PACIFIDLOG BY f l o a t e r på t o p p e n\n"
	.string "a f en koloni af CORSOLA.\p"
	.string "Hvis jeg fortalte dig det, ville du t r o \n"
	.string "m i g?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "Forfædrene til folkene i PACIFIDLOG\n"
	.string "siges at være blevet født på både og\l"
	.string "levede og døde  ombord på dem.\p"
	.string "Jeg forstår, at de levede på den måde\n"
	.string "fordi de søgte efter noget.$"



