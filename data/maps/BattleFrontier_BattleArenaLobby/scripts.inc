@ TRANSLATED

.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "Hvor TRÆNERNES kampånd sættes på\n"
	.string "prøve!\p"
	.string "Jeg byder dig velkommen til KAMPARENEN!\p"
	.string "Jeg er din guide til Set KO Turneringen!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "udfordringen i KAMPARENAEN?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "Vi venter på dit udfordring på en anden\n"
	.string "lejlighed!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "I KAMPARENAEN deltager vi i Set KO\n"
	.string "Turneringen.\p"
	.string "Alle deltagere kommer med et hold af tre\n"
	.string "POKéMON.\p"
	.string "De tre POKéMON skal stå i rækkefølgen,\n"
	.string "de skal dukke op.\p"
	.string "Under kampen vil POKéMON'erne dukke op\n"
	.string "én ad gangen i den forudbestemte\l"
	.string "rækkefølge.\p"
	.string "Når en POKéMON går ind i kampen, skal\n"
	.string "den forblive ude, indtil kampen er\l"
	.string "afgjort.\p"
	.string "Hvis en kamp forbliver uafgjort efter\n"
	.string "tre ture, går den til bedømmelse.\p"
	.string "Hvis du ønsker at afbryde din\n"
	.string "udfordring, venligst gem spillet.\p"
	.string "Hvis du ikke gemmer, vil du ikke kunne\n"
	.string "fortsætte din udfordring.\p"
	.string "Hvis du formår at slå syv TRÆNERE i\n"
	.string "træk, vil vi give dig Kamp Point.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "Inden vi viser dig til KAMP ARENEN, skal\n"
	.string "du gemme. Er det okay?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "KAMPARENAEN tilbyder to niveauer af\n"
	.string "udfordring, Niveau 50 og Åbent Niveau.\p"
	.string "Hvad er dit valg?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Rigtig godt, vælg nu dine tre POKéMON,\n"
	.string "tak.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Kære udfordrer!\p"
	.string "Du har ikke de tre POKéMON nødvendige\n"
	.string "for adgang.\p"
	.string "For at kvalificere dig, skal du\n"
	.string "medbringe tre forskellige slags\l"
	.string "POKéMON.\p"
	.string "De må heller ikke holde de samme slags\n"
	.string "ting.\p"
	.string "ÆG{STR_VAR_1} er diskvalificerede.\p"
	.string "Når du har gjort dine forberedelser,\n"
	.string "vend venligst tilbage.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "Kære udfordrer!\p"
	.string "Du har ikke de tre POKéMON der kræves\n"
	.string "for adgang.\p"
	.string "For at kvalificere dig, skal du\n"
	.string "medbringe tre forskellige typer af\l"
	.string "POKéMON.\p"
	.string "De tre forskellige POKéMON skal alle\n"
	.string "være på niveau 50 eller lavere.\p"
	.string "De må heller ikke have de samme typer af\n"
	.string "genstande.\p"
	.string "ÆG{STR_VAR_1} er ikke berettiget.\p"
	.string "Når du har gjort dine forberedelser,\n"
	.string "vend venligst tilbage.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Jeg vil nu guide dig til KAMPARENEN.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "Kære udfordrer!\p"
	.string "Du gemte ikke spillet før du slukkede,\n"
	.string "gjorde du det ikke?\p"
	.string "Det er uheldigt, men det har resulteret\n"
	.string "i diskvalifikation fra din udfordring.\p"
	.string "Du kan selvfølgelig starte med en ny\n"
	.string "udfordring.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "Vi lykønsker dig med dine strålende\n"
	.string "sejre over syv TRÆNERE!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "Dit bedrift vil blive registreret. Vent\n"
	.string "venligst mens jeg gemmer spillet.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
    .string "I anledning af din 7-sejrsstreak,\n"
    .string "præsenterer vi dig for denne præmie.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} modtog præmien\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "Nå?\n"
	.string "Din RYGSÆK ser ud til at være fuld.\p"
	.string "Jeg opfordrer dig til at frigøre plads og\n"
	.string "komme tilbage efter din præmie.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "Mange tak for din deltagelse!\p"
	.string "Vent venligst, mens jeg gemmer spillet.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "Vi venter på dit udfordring en anden\n"
	.string "gang!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Vi har set frem til din ankomst.\p"
	.string "Inden jeg viser dig til KAMP ARENAEN,\n"
	.string "skal jeg gemme spillet. Vent venligst.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "Skal jeg gemme din seneste KAMP ARENA\n"
	.string "kamp på dit FRONTIER PAS?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "Jeg tabte på DOMMERENS afgørelse…\p"
	.string "Jeg tror ikke, det var en god idé kun at\n"
	.string "bruge defensive moves og ikke angribe…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "Jeg vandt i bedømmelse!\p"
	.string "At lande slag konsekvent på\n"
	.string "modstanderens POKéMON virkede!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "Vores kamp blev erklæret uafgjort.\p"
	.string "Da tiden løb ud, havde både min POKéMON\n"
	.string "og modstanderens cirka det samme antal\l"
	.string "HP tilbage.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "I KAMPARENAEN er rækkefølgen af\n"
	.string "POKéMON helt vigtig.\p"
	.string "For eksempel, hvis din første POKéMON\n"
	.string "har visse type ulemper, så prøv at gøre\l"
	.string "din anden POKéMON til en med angreb, der\l"
	.string "er super effektive mod den første.\p"
	.string "Jeg tror, at det vil være en god måde at\n"
	.string "sammensætte et effektivt hold.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
.string "Reglerne for The Set KO Tourney er opført.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "Hvilken overskrift vil du læse?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "Set KO-turneringen har specielle\n"
	.string "regler, i modsætning til almindelige\l"
	.string "kampe.\p"
	.string "Først varer en kamp kun tre ture.\p"
	.string "Hvis udfaldet ikke er afgjort efter tre\n"
	.string "ture, går det til bedømmelse.\p"
	.string "DOMMEREN vil vælge vinderen baseret på\n"
	.string "hvordan POKéMON kæmpede.\p"
	.string "Desuden kan en POKéMON ikke skiftes ud\n"
	.string "før kampens resultat er afgjort.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "Den første vurderingsfaktor er “Sind.”\n"
	.string "Denne faktor vurderer, hvor aggressive\l"
	.string "kæmperne var.\p"
	.string "Vurderingen er baseret på, hvor ofte\n"
	.string "TRÆNERNE befalede brugen af offensivt\l"
	.string "træk.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "Den anden vurderingsfaktor er\n"
	.string "'Færdighed'. Denne faktor vurderer, hvor\l"
	.string "effektivt POKéMON-bevægelser blev\l"
	.string "brugt.\p"
	.string "Hvis en bevægelse lykkedes, øges\n"
	.string "Færdighedsbedømmelsen.\p"
	.string "Hvis en bevægelse mislykkedes, sænkes\n"
	.string "Færdighedsbedømmelsen.\p"
	.string "Hvis det var en angrebsbevægelse, øges\n"
	.string "Færdighedsbedømmelsen, hvis bevægelsen\l"
	.string "var 'super effektiv', og sænkes den, hvis\l"
	.string "den var 'ikke særlig effektiv'.\p"
	.string "Færdighedsbedømmelsen vil ikke stige\n"
	.string "for bevægelser som PROTECT og DETECT.\p"
	.string "Hvis modstanderen brugte PROTECT eller\n"
	.string "DETECT, og din POKéMON ikke ramte med en\l"
	.string "bevægelse, vil dens\l"
	.string "Færdighedsbedømmelse ikke falde.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "Den tredje bedømmelsesfaktor er\n"
	.string "“Krop”. Denne faktor er baseret på hvor\l"
	.string "meget HP der var tilbage ved slutningen\l"
	.string "af en kamp.\p"
	.string "Vurderingen tager højde for hvor meget\n"
	.string "HP en POKéMON havde i starten af\l"
	.string "kampen, og hvad der var tilbage i\l"
	.string "slutningen.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "En sejr snuppet fra ARENAEN TYCOON, og\n"
	.string "en syv-TRÆNER fejring!\p"
	.string "Vi lykønsker dig med din mest strålende\n"
	.string "udfordring!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Kære udfordrer, i anerkendelse af din\n"
	.string "uudslukkelige ånd, så tag disse Kamp\l"
	.string "Point(er) med dig.$"



