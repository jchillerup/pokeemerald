@ TRANSLATED

.set LOCALID_ATTENDANT_SINGLES, 1
.set LOCALID_ATTENDANT_DOUBLES, 6

BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "Hvor TRÆNERES hjerter bliver sat på\n"
	.string "prøve.\p"
	.string "Jeg byder dig velkommen til KAMPALASET.\p"
	.string "Jeg accepterer udfordringer til DE\n"
	.string "ENKELTE KAMPHALLER.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "Vil du tage udfordringen i\n"
	.string "ENKELTKAMPSSALEN?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "I BATTLE PALADSET er der flere\n"
	.string "auditorier til ENKELTBATLER der kaldes\l"
	.string "ENKELTBATTLE-HALLER.\p"
	.string "ENKELTBATLER udføres på normal vis,\n"
	.string "bortset fra én vigtig regel, der skal\l"
	.string "overholdes.\p"
	.string "TRÆNERE må kun skifte deres POKéMON\n"
	.string "ind og ud.\p"
	.string "TRÆNERE er ellers forbudt at give\n"
	.string "kommandoer til deres POKéMON.\p"
	.string "POKéMON skal opføre sig i\n"
	.string "overensstemmelse med deres natur og\l"
	.string "kæmpe på egen pote.\p"
	.string "Du må stole på dine POKéMON og holde\n"
	.string "øje med dem.\p"
	.string "Hvis du opnår æren af at besejre syv\n"
	.string "TRÆNERE i træk, vil vi give dig Kamp\l"
	.string "Point.\p"
	.string "Hvis du vil afbryde din udfordring, skal\n"
	.string "du gemme spillet.\p"
	.string "Hvis du ikke gemmer før afbrydelse, vil\n"
	.string "du blive diskvalificeret.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "Når du har styrket dit hjerte og\n"
	.string "POKéMON, skal du vende tilbage.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "Der er to KAMPHALLER, Niveau 50 og Åben\n"
	.string "Niveau.\p"
	.string "Hvilken udfordring vælger du?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "Åh…\p"
	.string "Du har ikke de tre POKéMON der kræves\n"
	.string "til udfordringen.\p"
	.string "For at deltage, skal du give tre\n"
	.string "forskellige slags POKéMON.\p"
	.string "Disse POKéMON skal alle være på niveau\n"
	.string "50 eller lavere.\p"
	.string "De må heller ikke holde de samme slags\n"
	.string "genstande.\p"
	.string "ÆG{STR_VAR_1} er ikke berettigede.\p"
	.string "Kom tilbage når du har lavet dine\n"
	.string "forberedelser.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Åh... \p"
	.string "Du har ikke de tre POKéMON der kræves\n"
	.string "til udfordringen. \p"
	.string "For at deltage skal du have tre\n"
	.string "forskellige typer POKéMON. \p"
	.string "De må heller ikke holde den samme slags\n"
	.string "genstande. \p"
	.string "ÆGG{STR_VAR_1} er ugyldige. \p"
	.string "Kom tilbage, når du har forberedt dig.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "Godt. Nu skal du vælge dine tre POKéMON.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "Jeg skal gemme, før jeg viser dig til\n"
	.string "KAMPALEREN. Er det okay?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "Godt. Nu, følg med mig.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "Jeg føler mig privilegeret for at have\n"
	.string "set din POKéMON's bedrifter.\p"
	.string "Resultaterne vil blive optaget. Jeg\n"
	.string "bliver nødt til at bede dig vente et\l"
	.string "øjeblik.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "For at opnå en 7-sejrsstreak…\p"
	.string "Båndene der binder dit hjerte med dine\n"
	.string "POKéMON virker stærke og sande.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "Dit bedrift vil blive registreret. Jeg må\n"
	.string "bede dig om at vente et øjeblik.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "For din præstation med en 7-kamp"
	.string "svindestreak, får du Kamp Point(er).$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "Det ser ud til, at du ikke har plads til\n"
	.string "vores præmie.\p"
	.string "Du bør vende tilbage, når du har\n"
	.string "organiseret din RYGSÆK.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "Vi har ventet på dig…$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "Jeg skal gemme, før jeg viser dig til\n"
	.string "KAMPENSHALLEN. Er det okay?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "Puha…\p"
	.string "Du glemte at gemme, før du sluttede dit\n"
	.string "eventyr sidste gang.\p"
	.string "Som følge heraf er dit eventyr blevet\n"
	.string "diskvalificeret. Det er meget uheldigt.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
    .string "{PLAYER} modtog præmien\n"
    .string "{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "For a hardy fellow like me, hardy\n"
	.string "POKéMON are the best.\p"
	.string "Offense is the best defense! A\n"
	.string "relentless attack is the ultimate!\p"
	.string "But that's not what I wanted to chat\n"
	.string "about.\p"
	.string "Every so often a really cute lady\n"
	.string "swings by here.\p"
	.string "She says that she can tell what\n"
	.string "POKéMON are thinking.\p"
	.string "I don't know about that part, but she is\n"
	.string "really cute.\p"
	.string "Huh? Why are you looking at me like\n"
	.string "that?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "Hmm…\p"
	.string "Det ser ud til, at naturen af POKéMON og\n"
	.string "de angreb, de har lært, er nøglen til\l"
	.string "kampen her.\p"
	.string "Mere præcist handler det om, hvor godt\n"
	.string "angrebene matcher naturen hos POKéMON.\p"
	.string "Hvis din POKéMON er i problemer og ikke\n"
	.string "kan leve op til sit potentiale, skal du\l"
	.string "måske undersøge, hvor godt dens angreb\l"
	.string "matcher dens natur.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "Min POKéMON er normalt meget\p"
	.string "dovne.\p"
	.string "Men når den er i en KAMPVÆRSEL, ser det\n"
	.string "til tider ud til, at den forvandler sig til\l"
	.string "noget ondskabsfuldt!\p"
	.string "Den bliver helt skræmmende. Det er\n"
	.string "chokerende, endda.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "Jeg spekulerer på, hvilken slags natur\n"
	.string "en POKéMON ville have, hvis den foretrak\l"
	.string "at svække sine modstandere og langsomt\l"
	.string "nedslide dem.\p"
	.string "Jeg ville blive overrasket, hvis det var\n"
	.string "en SLAP nature.\p"
	.string "Men, næh, det kan ikke være rigtigt.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "Hvor TRÆNERES hjerter bliver sat på\n"
	.string "prøve.\p"
	.string "Jeg byder dig velkommen til\n"
	.string "KAMPSLETTEN.\p"
	.string "Jeg accepterer udfordringer til DE\n"
	.string "DOBBELTE KAMPSTATIONER.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "Ønsker du at tage udfordringen i\n"
	.string "DOBBELTKAMPs HALLEN op?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "I BATTLE PALACE findes der flere\n"
	.string "auditorier til DOBBELTKAMPE kaldet\l"
	.string "DOBBELTKAMP-SALE.\p"
	.string "DOBBELTKAMPENE afholdes på sædvanlig\n"
	.string "vis, dog med en vigtig regel, der skal\l"
	.string "overholdes.\p"
	.string "TRÆNERE har kun lov til at skifte deres\n"
	.string "POKéMON ind og ud.\p"
	.string "TRÆNERE må ellers ikke kommandere\n"
	.string "deres POKéMON.\p"
	.string "POKéMON skal handle i overensstemmelse\n"
	.string "med deres natur og kæmpe på egen hånd.\p"
	.string "Du må stole på dine POKéMON og passe på\n"
	.string "dem.\p"
	.string "Hvis du formår at slå syv TRÆNERE i\n"
	.string "træk, vil vi belønne dig med Kamp-point.\p"
	.string "Hvis du ønsker at afbryde din\n"
	.string "udfordring, skal du gemme spillet.\p"
	.string "Hvis du ikke gemmer før afbrydelsen, vil\n"
	.string "du blive diskvalificeret.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "For at besejre PALACE MAVEN og syv\n"
	.string "TRÆNERE i træk…$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "Til ære for båndet du deler med din\n"
	.string "POKéMON, giver vi dig disse Kamp\l"
	.string "Point(er).$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "Vil du gerne optage din seneste BATTLE\n"
	.string "PALACE kamp på din FRONTIER PASS?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
.string "KAMP HALLEN regler er opført.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
.string "Hvilken overskrift vil du gerne læse?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "Her skal POKéMON tænke og kæmpe selv.\p"
	.string "I modsætning til i naturen opfører\n"
	.string "POKéMON, der lever med mennesker sig\l"
	.string "forskelligt afhængigt af deres natur.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "Afhængigt af sin natur, kan en POKéMON\n"
	.string "foretrække at angribe under alle\p"
	.string "omstændigheder. En anden POKéMON kan\n"
	.string "foretrække at beskytte sig selv mod\l"
	.string "skade.\p"
	.string "Endnu en kan nyde at forvirre eller\n"
	.string "drille sine fjender.\p"
	.string "På grund af sin natur vil en POKéMON\n"
	.string "have foretrukne bevægelser, som den er\l"
	.string "god til at bruge.\p"
	.string "Den kan også misunde visse bevægelser,\n"
	.string "som den har svært ved at bruge.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "Der er angrebsbevægelser, der påfører\n"
	.string "direkte skade på fjenden.\p"
	.string "Der er defensive bevægelser, der bruges\n"
	.string "til at forberede sig på fjendens  angreb\l"
	.string "eller til at hele HP og så videre.\p"
	.string "Der er også andre lidt mærkelige\n"
	.string "bevægelser, der kan svække fjenderne\l"
	.string "med statsproblemer, herunder gift og\l"
	.string "lammelse.\p"
	.string "POKéMON vil overveje at bruge\n"
	.string "bevægelser i disse tre kategorier.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "Når den ikke er under kommando af sin\n"
	.string "TRÆNER, kan en POKéMON være ude af\l"
	.string "stand til effektivt at bruge visse\l"
	.string "angreb.\p"
	.string "En POKéMON er ikke god til at bruge\n"
	.string "noget angreb, den ikke kan lide.\p"
	.string "Hvis en POKéMON kun kender angreb, der\n"
	.string "ikke passer til dens natur, vil den ofte\l"
	.string "være ude af stand til at udnytte sit\l"
	.string "potentiale.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "Afhængigt af dens natur kan en POKéMON\n"
	.string "begynde at bruge angreb, der ikke\l"
	.string "matcher dens natur, når den er i\l"
	.string "problemer.\p"
	.string "Hvis en POKéMON begynder at opføre sig\n"
	.string "underligt i en klemme, så hold et vågent\l"
	.string "øje med den.$"



