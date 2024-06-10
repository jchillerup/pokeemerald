@ TRANSLATED

.set LOCALID_ATTENDANT, 1

VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
    .string "Hvilken KONKURRENCE vil du deltage i?\n"
    .string "Vil du have et tip?\p"
    .string "I enhver KONKURRENCE, f.eks. en SØD\n"
    .string "KONKURRENCE, tror jeg ikke, de kun\l"
    .string "bedømmer dig ud fra sødme i første runde.\p"
    .string "Du skal finde måder at opdrage\n"
    .string "POKéMON på bedre.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "Jeg har opdrættet mine POKéMON til at være søde.\p"
	.string "Jeg fandt ud af, at man kan deltage\n"
	.string "i en KONKURRENCE om sødme med POKéMON!\p"
	.string "Jeg er så glad for, at jeg har opdrættet mine\n"
	.string "POKéMON med kærlig omsorg...$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "Mine POKéMON regler!\p"
	.string "Det er sejt, stærkt men smukt, sødt,\n"
	.string "og klogt. Det er komplet!\p"
	.string "Jeg vil gå efter sejre i hver eneste\n"
	.string "konkurrence.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "POKéMON KONKURRENCER\n"
	.string "NORMAL RANG TRIN!$" 



