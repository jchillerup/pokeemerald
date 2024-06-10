@ TRANSLATED

.set LOCALID_ATTENDANT, 1

FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
	.string "Vi klarer os fint i forrunden,\n"
	.string "men vi kan aldrig vinde appellerne... \p"
	.string "Måske betyder det, at jeg skal se på,\n"
	.string "hvad de andre deltagere laver...$"

@ Unused
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
	.string "Se!\n"
	.string "Min POKéMON har vundet alle disse BÅND!\p"
	.string "Har dine POKéMON tjent nogen BÅND?\n"
	.string "Du kan tjekke dem på din POKéNAV.$"

@ Unused
FallarborTown_ContestHall_Text_CantWinEverywhere:
	.string "Jeg kan ikke slå GYMLEDERE…\p"
	.string "Jeg kan ikke vinde nogen KONKURRENCER…\p"
	.string "Jeg har været her, der og alle vegne,\n"
	.string "og det er alt sammen forgæves…$"

@ Unused
FallarborTown_ContestHall_Text_SuperRankStage:
	.string "POKéMON-KONKURRENCER\n"
	.string "SUPER RANK STAGE!$"



