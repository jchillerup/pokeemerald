@ TRANSLATED

.set LOCALID_ATTENDANT_SINGLES, 1
.set LOCALID_ATTENDANT_DOUBLES, 6

BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "Hvor intelligensen af TRÆNERE bliver\n"
	.string "sat på prøve!\p"
	.string "Velkommen til KAMPFABRIKKEN!\p"
	.string "Jeg er din guide til Battle Swap Single\n"
	.string "Tournament.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "Vil du tage kampen om at skifte\n"
	.string "enkeltudfordring?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "Den Single Battle Swap Turnering er en\n"
	.string "SINGLE BATTLE konkurrence, hvor der\l"
	.string "kun bruges lejede POKéMON.\p"
	.string "Først lånes der tre POKéMON specifikt\n"
	.string "til dette event.\p"
	.string "Brug de lejede POKéMON, du har fået, til\n"
	.string "en SINGLE BATTLE.\p"
	.string "Hvis du vinder, må du bytte en af dine\n"
	.string "lejede POKéMON.\p"
	.string "Gentag denne cyklus af kampe og\n"
	.string "bytning--hvis du vinder syv gange i\l"
	.string "træk, vil du tjene Kamp Point.\p"
	.string "Hvis du vil afbryde din udfordring, så\n"
	.string "husk at gemme spillet.\p"
	.string "Hvis du ikke gemmer, bliver du\n"
	.string "diskvalificeret fra din udfordring.$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "Vi glæder os til dit næste besøg.$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "Hvilket niveau vil du udfordre? Niveau\n"
	.string "50 eller Åbent Niveau?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "Før du begynder din udfordring, skal jeg\n"
	.string "gemme spillet. Er det okay?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "Okay, jeg vil passe på dine POKéMON\n"
	.string "mens du konkurrerer.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
.string "Vær sød at gå denne vej.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "Tak for din deltagelse!\p"
	.string "Jeg vil returnere din POKéMON i bytte\n"
	.string "for vores lejede POKéMON.\p"
	.string "Jeg skal også gemme\n"
	.string "begivenhedsresultaterne. Vent\l"
	.string "venligst.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "Jeg vil returnere dine POKéMON i\n"
	.string "bytte for vores lejede POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "Tillykke! Du har vundet syv på stribe\n"
	.string "Battle Swap kampe!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "Som anerkendelse af din 7-sejr \nstribe,\n"
	.string "belønner vi dig med disse Kamp Point(er).$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "Åh, åh, åh!\p"
	.string "Dine Kamp Point er maksimalt.\p"
	.string "Kom venligst tilbage efter at have\n"
	.string "brugt nogle Kamp Point.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "Vi har ventet på dig!\p"
	.string "Inden vi fortsætter din udfordring,\n"
	.string "skal jeg gemme spillet.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "Jeg beklager at sige det, men du gemte\n"
	.string "ikke, før du stoppede med at lege sidste\l"
	.string "gang.\p"
	.string "Som et resultat er du diskvalificeret\n"
	.string "fra din udfordring.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "Vi vil returnere dine personlige POKéMON.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} modtog præmien\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "Hvor trænernes intelligens bliver sat\n"
	.string "på prøve!\p"
	.string "Velkommen til KAMPFABRIKKEN!\p"
	.string "Jeg er din guide til Battle Swap\n"
	.string "Double-turneringen.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "Vil du tage kampen Swap Double\n"
	.string "udfordring?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "Den Store Kampbytte Dobbelt Turnering\n"
	.string "er en DOBBELTKAMP konkurrence hvor der\l"
	.string "kun bruges lejede POKéMON.\p"
	.string "Først vil du låne tre POKéMON specielt\n"
	.string "til denne begivenhed.\p"
	.string "Brug de lejede POKéMON, du har fået\n"
	.string "tildelt,\p"
	.string "og udfør en DOBBELTKAMP.\p"
	.string "Hvis du vinder, må du bytte en af dine\n"
	.string "lejede POKéMON.\p"
	.string "Gentag denne cyklus af kampe og\n"
	.string "bytter--hvis du vinder syv gange i træk,\l"
	.string "vil du optjene Kamp Point.\p"
	.string "Hvis du ønsker at afbryde din\n"
	.string "udfordring, så gem spillet.\p"
	.string "Hvis du ikke gemmer før du afbryder, vil\n"
	.string "du blive diskvalificeret.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "Tillykke med at have besejret\n"
	.string "FABRIKSDIREKTØREN og have vundet syv\l"
	.string "kampe i træk!$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "Som belønning for din viden og skarpe\n"
	.string "intelligens, tildeles du disse Kamp\l"
	.string "Point.$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "Lad mig bytte din POKéMON med vores\n"
	.string "leje-POKéMON.\p"
	.string "Jeg skal gemme kampdataene, så vent\n"
	.string "venligst.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "Vil du gerne optage din seneste\n"
	.string "KAMPFABRIK kamp på din FRONTIER PASS?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "Hej! Dig dér!\p"
	.string "Tænker du, at begivenhederne her er\n"
	.string "lette, fordi du ikke behøver en opbygget\l"
	.string "hold af POKéMON?\p"
	.string "Jeg ville ikke være alt for sikker på at\n"
	.string "vinde så let.\p"
	.string "Hvis du ikke har indgående kendskab til\n"
	.string "POKéMON og deres angreb, bliver det\l"
	.string "svært at fortsætte med at vinde.$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "Jeg byttede til en svag POKéMON… Jeg\n"
	.string "troede, det var en god type at have…\p"
	.string "De fejede gulvet med os…$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "Det har slet ikke gået min vej\n"
	.string "overhovedet.\p"
	.string "Du skal tjekke din modstanders POKéMON\n"
	.string "under kampen for at se, om de er gode.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "Du ved, hvordan personalet her giver\p"
	.string "dig nogle hint om din næste modstander?\p"
	.string "Jeg er en voksen mand, og jeg har svært\n"
	.string "ved at forstå deres hints.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "Som, jeg er virkelig sej, men jeg keder mig\n"
	.string "hurtigt, så jeg skiftede bare ud og\l"
	.string "kæmpede igen og igen.\p"
	.string "Nå, når jeg blev ved med at deltage i\n"
	.string "Battle Swap-begivenheder, bemærkede jeg,\l"
	.string "at de varierede de udlejede POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
.string "Kamp Udskift reglerne er angivet.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "Hvilken overskrift vil du læse?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "I en Kampskifte-begivenhed kan du kun\n"
	.string "bruge tre POKéMON.\p"
	.string "Uanset om du lejer eller bytter, må dit\n"
	.string "hold ikke have to eller flere af det\l"
	.string "samme POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "Du kan kun bytte POKéMON med TRÆNEREN,\n"
	.string "du lige har besejret.\p"
	.string "Du kan kun bytte til de POKéMON, der\n"
	.string "blev brugt af den besejrede TRÆNER.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "Efter hver kamp, du vinder, kan du bytte\n"
	.string "til en af dine besejrede modstanderes\l"
	.string "POKéMON.\p"
	.string "Du vil ikke kunne bytte POKéMON med den\n"
	.string "syvende TRÆNER til arrangementet.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "Der er to vigtige punkter at være\n"
	.string "opmærksom på, når du bytter POKéMON.\p"
	.string "For det første kan du ikke tjekke\n"
	.string "statistikkerne for den POKéMON, du er\l"
	.string "ved at modtage.\p"
	.string "For det andet står de POKéMON på dit\n"
	.string "hold i rækkefølge, afhængigt af den\l"
	.string "rækkefølge, du lejede dem i.\p"
	.string "Denne rækkefølge forbliver uforandret,\n"
	.string "selv når der byttes.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "I det åbne niveau er den lejede POKéMON\n"
	.string "og modstandernes TRÆNERE POKéMON alle\l"
	.string "Level 100.$"



