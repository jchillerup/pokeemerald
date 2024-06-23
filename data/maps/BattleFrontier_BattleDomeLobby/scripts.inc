@ TRANSLATED

.set LOCALID_ATTENDANT_SINGLES, 1
.set LOCALID_ATTENDANT_DOUBLES, 6

BattleFrontier_BattleDomeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

BattleFrontier_BattleDomeLobby_OnResume:
	dome_initresultstree
	end

BattleFrontier_BattleDomeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleDomeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleDomeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	dome_set DOME_DATA_WIN_STREAK, 0
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_WonChallenge::
	call BattleFrontier_EventScript_IncrementWinStreak
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce::
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	dome_set DOME_DATA_HAS_WON_CHALLENGE, TRUE
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	goto BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle

BattleFrontier_BattleDomeLobby_EventScript_LostChallenge::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle::
	dome_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
	message BattleFrontier_BattleDomeLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge

BattleFrontier_BattleDomeLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleDomeLobby_EventScript_EndChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2
	waitmessage
	dome_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
	end

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
	end

BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles
BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleDomeLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleDomeLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	dome_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed
	dome_inittrainers
BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	dome_settrainers
	msgbox BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR, 23, 6
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge

BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor
	waitdooranim
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor
	waitdooranim
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor::
	applymovement LOCALID_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor::
	applymovement LOCALID_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor::
	applymovement LOCALID_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor::
	applymovement LOCALID_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor::
	opendoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor::
	opendoor 17, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor::
	closedoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor::
	closedoor 17, 4
	return

BattleFrontier_BattleDomeLobby_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree::
	dome_get DOME_DATA_PREV_TOURNEY_TYPE
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen
	fadescreen FADE_TO_BLACK
	dome_showprevtourneytree
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_Maniac::
	dome_getwinnersname
	msgbox BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Lass::
	msgbox BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Man::
	msgbox BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully, MSGBOX_NPC
	end

@ A few OutsideWest event scripts are inserted here instead, two of which are unused
BattleFrontier_OutsideWest_EventScript_Man3::
	msgbox BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_BattleDomeSign2::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign2, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnderConstructionSign::
	msgbox BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup
	case 1, BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree
	case 2, BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO
	case 3, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleDomeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle:
	.string "Hvor trænernes strategier bliver sat på\n"
	.string "prøve!\p"
	.string "Velkommen til KAMPKUPLEN!\p"
	.string "Jeg er din guide til SINGLE BATTLE\n"
	.string "turneringen.$"

BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge:
	.string "Vil du udfordre enkeltturneringen?$"

BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain:
.string "Vi håber at se dig igen.$"

BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge:
	.string "TURNERINGEN I SINGLE-BATTLE er præcis\n"
	.string "som navnet antyder-- en turnering af\l"
	.string "SINGLE-BATTLES.\p"
	.string "Alle deltagende TRÆNERE skal indsætte\n"
	.string "tre POKéMON hver.\p"
	.string "I hver kamp skal en af de tre POKéMON\n"
	.string "være i reserven.\p"
	.string "De to andre POKéMON kan kæmpe én ad\n"
	.string "gangen.\p"
	.string "Vælg de to kæmpende POKéMON efter at\n"
	.string "have undersøgt modstanderens trio.\p"
	.string "Du vinder turneringen ved at besejre\n"
	.string "fire TRÆNERE.\p"
	.string "Kamp Point tildeles turneringsvinderen.\p"
	.string "Hvis du ønsker at afbryde din\n"
	.string "turnering, skal du venligst gemme\l"
	.string "spillet.\p"
	.string "Hvis du ikke gemmer før afbrydelse, vil\n"
	.string "du blive diskvalificeret.$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge:
	.string "Inden jeg viser dig til KAMPDOMEN,  skal\n"
	.string "jeg gemme dataene. Er det okay?$"

BattleFrontier_BattleDomeLobby_Text_WhichLevelMode:
	.string "Turneringen tilbyder to niveauer af\n"
	.string "udfordring, Level 50 og Open Level. Hvad\l"
	.string "er dit valg?$"

BattleFrontier_BattleDomeLobby_Text_SelectThreeMons:
	.string "Vælg nu de tre POKéMON, du ønsker at\n"
	.string "sende ind.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Undskyld!\p"
	.string "Du har ikke tre kvalificerede POKéMON.\p"
	.string "Desuden skal POKéMON'erne holde\n"
	.string "forskellige slags genstande.\p"
	.string "ÆGG{STR_VAR_1} ikke kvalificeret.\p"
	.string "Kom venligst tilbage, når du er klar.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50:
	.string "Undskyld!\p"
	.string "Du har ikke tre kvalificerede POKéMON.\p"
	.string "Du skal have tre forskellige POKéMON på\n"
	.string "niveau 50 eller derunder for at deltage.\p"
	.string "De skal også bære forskellige typer af\n"
	.string "genstande.\p"
	.string "ÆG{STR_VAR_1} er diskvalificeret.\p"
	.string "Kom tilbage, når du er klar.$"

BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome:
	.string "Jeg vil nu vise dig til KAMPDOME-PALEN.$"

BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting:
	.string "Undskyld!\p"
	.string "Du gemte ikke, inden du afsluttede dit\n"
	.string "udfordring sidste gang.\p"
	.string "På grund af det er din udfordring indtil\n"
	.string "videre diskvalificeret. Beklager!$"

BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney:
	.string "Tillykke med at vinde din\n"
	.string "Kampturnering!$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize:
	.string "Her er din præmie for din Battle\n"
	.string "Turnering sejr.$"

@ Used by Verdanturf Tent
BattleFrontier_BattleDomeLobby_Text_ReceivedPrize:
	.string "{PLAYER} modtog præmien\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom:
	.string "Åh, din RYGSÆK ser ud til at være fuld.\p"
	.string "Venligst gør plads i din RYGSÆK, og kom\n"
	.string "tilbage til mig.$"

BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying:
	.string "Tak fordi du spiller!$"

BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved:
	.string "Din rekord vil blive gemt. Vent venligst.$"

BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou:
.string "Vi har ventet på dig!$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2:
	.string "Før jeg viser dig til KAMPDOME skal jeg\n"
	.string "gemme data. Er det okay?$"

BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle:
	.string "Hvor TRÆNERES strategier bliver sat på\n"
	.string "prøve!\p"
	.string "Velkommen til KAMPDOMEN!\p"
	.string "Jeg er din guide til DOBBELTBATTLE\n"
	.string "Turneringen.$"

BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge:
	.string "Vil du udfordre DOUBLE BATTLE\n"
	.string "Turneringen?$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge:
	.string "The DOUBLE BATTLE Turnering er præcis\n"
	.string "som navnet antyder-- en turnering af\l"
	.string "DOBBELTBATTLES.\p"
	.string "Alle deltagende TRÆNERE skal indsætte\n"
	.string "tre POKéMON hver.\p"
	.string "I hver kamp skal én af de tre POKéMON\n"
	.string "holdes i reserve.\p"
	.string "De resterende to POKéMON skal deltage i\n"
	.string "en DOBBELTBATTLE.\p"
	.string "Vælg de to kæmpende POKéMON efter at\n"
	.string "have undersøgt modstanderens trio.\p"
	.string "Du vinder turneringen ved at besejre\n"
	.string "fire TRÆNERE.\p"
	.string "Battle Points tildeles til\n"
	.string "turneringsvinderen.\p"
	.string "Hvis du ønsker at afbryde din\n"
	.string "turnering, bedes du gemme spillet.\p"
	.string "Hvis du ikke gemmer før afbrydelse, vil\n"
	.string "du blive diskvalificeret.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50:
	.string "Det er resultaterne fra den sidste\n"
	.string "Level 50 SINGLE BATTLE Turnering.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50:
	.string "Det er resultaterne fra den sidste\n"
	.string "Level 50 DOBBELTKAMP-turnering.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen:
	.string "Det er resultaterne af den sidste Åben\n"
	.string "Niveau ENKELTBATTLE Turnering.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen:
	.string "Det er resultaterne af den sidste Åbne\n"
	.string "Level DOUBLE BATTLE Turnering.$"

BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough:
	.string "Har du set det? Den seneste\n"
	.string "Kampturnering?\p"
	.string "Vinderen, {STR_VAR_1}, var virkelig\n"
	.string "sej.\p"
	.string "Du bør tjekke resultaterne på skærmen\n"
	.string "ved siden af PC'en.$"

BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier:
	.string "KAMPFRONTEN… Jeg har længe drømt om et\n"
	.string "sted som dette.$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_BattleDomeSign2:
	.string "KAMPDOMEN\n"
	.string "Bliv den Uovervindelige Superstjerne!$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction:
	.string "Et spørgsmålstegn?\n"
	.string "Under konstruktion!$"

BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation:
	.string "Når en TRÆNER kæder turnering sejre ved\n"
	.string "KAMPDOMEN, bliver han eller hun berømt\l"
	.string "som en stjerne.\p"
	.string "Stærke TRÆNERE tiltrækkes af denne\n"
	.string "berømmelse til KAMPDOMEN.\p"
	.string "En sand superstjerne er en TRÆNER, der\n"
	.string "kan fortsætte med at vindeturneringer.$"

BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound:
	.string "Jeg løb ind i en af favoritterne i\n"
	.string "turneringen allerede i den allerførste\l"
	.string "runde.\p"
	.string "Selvfølgelig blev jeg ødelagt…$"

BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully:
	.string "Jeg ville have vundet, hvis jeg havde\n"
	.string "holdt denne POKéMON i reserve.\p"
	.string "Du skal undersøge din modstanders\n"
	.string "POKéMON nøje, før du vælger din\l"
	.string "kamp-Pokémon.$"

BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker:
	.string "Tillykke!\p"
	.string "Du besejrede DOME ACE og vandt Battle\n"
	.string "Tournamentet!$"

BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints:
	.string "Som anerkendelse af din strategi-- en\n"
	.string "smuk ting var det også--\p"
	.string "vi tildeler dig disse Kamp Point(er)!$"

BattleFrontier_BattleDomeLobby_Text_RecordLastMatch:
	.string "Vil du gerne optage din sidste\n"
	.string "KAMPDOM-kamp på din FRONTIER PASS?$"

BattleFrontier_BattleDomeLobby_Text_RulesAreListed:
	.string "Turneringsreglerne for kampen er\n"
	.string "opført.$"

BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading:
	.string "Hvilken overskrift vil du læse?$"

BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules:
	.string "Turneringskampe er planlagt baseret på\n"
	.string "styrken af POKéMON ejet af TRÆNERE.\p"
	.string "Kampene undgår at lade stærke TRÆNERE\n"
	.string "stå over for hinanden med det samme.$"

BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree:
	.string "Turneringsskemaet, eller som vi kalder\n"
	.string "det, Træet, kan ses i VENTEVÆRELSET fra\l"
	.string "en hvilken som helst guide.\p"
	.string "Turneringstræet vil give adgang til\n"
	.string "forskellige typer af data.\p"
	.string "Dataene der kan ses inkluderer de\n"
	.string "foregående turneringsresultater, de\l"
	.string "POKéMON, som TRÆNERE har, og TRÆNERES\l"
	.string "kampstil.$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules:
	.string "Hvis begge POKéMON besvimer på samme\n"
	.string "tid - en dobbelt KO - i en turnerings\l"
	.string "kamp, vil DOMMERNE gennemgå kampen og\l"
	.string "erklære vinderen.$"



