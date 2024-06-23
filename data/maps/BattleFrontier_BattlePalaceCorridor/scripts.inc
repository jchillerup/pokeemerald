@ TRANSLATED

.set LOCALID_ATTENDANT, 1

BattleFrontier_BattlePalaceCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceCorridor_OnFrame
	.byte 0

BattleFrontier_BattlePalaceCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor
	.2byte 0

BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor::
	delay 16
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
	waitmovement 0
	lockall
	palace_getcomment
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	goto_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom
	waitmovement 0
	opendoor 6, 3
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
	waitmovement 0
	closedoor 6, 3
	waitdooranim
	goto BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom

BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom
	waitmovement 0
	opendoor 10, 3
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
	waitmovement 0
	closedoor 10, 3
	waitdooranim
BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom::
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM, 7, 4
	waitstate
	end

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom:
	walk_up
BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame:
	.string "Mennesker og POKéMON, de er ens, men\n"
	.string "alligevel forskellige…\p"
	.string "Deres individuelle natur gør dem gode\n"
	.string "til visse ting og ikke så gode til andre\l"
	.string "ting.$"

BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes:
	.string "I stedet for at prøve at få en POKéMON\n"
	.string "til at gøre noget, den ikke kan lide, så\l"
	.string "prøv at lade den gøre, hvad den godt kan\l"
	.string "lide og er god til. \p"
	.string "Sæt dig selv i POKéMONs sted og overvej,\n"
	.string "hvilke træk den ville kunne lide. $"

BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered:
	.string "En POKéMONs natur er en\n"
	.string "bemærkelsesværdig ting…\p"
	.string "Nogle POKéMON opfører sig på en helt\n"
	.string "anden måde, når de er pressede.$"

BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature:
	.string "Er du begyndt at forstå hvordan en\n"
	.string "POKéMONs natur påvirker dens adfærd?$"

BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons:
	.string "Åh... Jeg ser et stærkt, hjerteligt bånd\n"
	.string "mellem dig og din POKéMON...$"



