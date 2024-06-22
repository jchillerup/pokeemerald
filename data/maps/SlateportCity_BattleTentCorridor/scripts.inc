@ TRANSLATED

.set LOCALID_ATTENDANT, 1

SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_ATTENDANT, 2, 2
	turnobject LOCALID_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Vil du have lidt lækker rådgivning\n"
	.string "til KONKURRENCER?\p"
	.string "At bruge et bestemt træk efter et\n"
	.string "anden bestemt træk kan nogle\l"
	.string "gange få dig ekstra opmærksomhed.\p"
	.string "Hvis du ved, hvad du laver, kan du\n"
	.string "score stort på tiltrækning.\p"
	.string "Selvfølgelig kan dine modstandere\n"
	.string "prøve at forstyrre din POKéMONs optræden.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Min far, han er DOMMER i konkurrencer.\p"
	.string "Jeg spørger mig selv, hvad jeg skal\n"
	.string "blive, en DOMMER eller en GYMLEDERS$\n"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
    .string "Hey, mand, jeg er virkelig sur,\n"
    .string "ved du. Jeg ville bare vide,\l"
    .string "hvorfor min POKéMON aldrig vandt,\l"
    .string "ved du. Så gav jeg DOMMEREN\n"
    .string "mine to cent, ved du, de er gratis.\p"
    .string "Og han ville ikke lytte til mig, ej, hey!\n"
    .string "Sådan helt bummer, mand!\p"
    .string "Hey, dig der! Tag en time-out, ved du?\n"
    .string "Bare, ved du, tag det her!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "Det der er, som, TM41, du ved?\n"
	.string "Hey, det er TORMENT, kan du høre mig?\p"
	.string "Det der, det tillader ikke den anden\n"
	.string "at bruge samme træk to gange i træk, forstår du?\p"
	.string "Nå, hør nu her, som,\n"
	.string "jeg lægger ikke en plage på dig!$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "MC: Åh, min, min!\n"
	.string "Er det ikke en skøn POKéMON, du har der?\p"
	.string "Vær så venlig! Kom endelig frem og\n"
	.string "deltag i vores fantastiske KONKURRENCER!\p"
	.string "Du vil klare dig godt! Jeg er sikker på det!\n"
	.string "Mine øjne har aldrig svigtet mig!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "DOMMER: Hej med dig!\n"
	.string "Jeg kan se, at du er en TRÆNER!\p"
	.string "Det ville bare ikke være godt for dig\n"
	.string "at gå glip af en POKéMON-KONKURRENCE!\p"
	.string "Få dig et KONKURRENCE-PAS i VERDANTURF\n"
	.string "CITY og deltag når som helst!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "Det er tid til at imponere!\n"
	.string "Hvad skal jeg starte med?$" 

@ Unused

SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "De lagde ikke meget mærke til min POKéMONs\n"
	.string "tiltrækningskraft…\p"
	.string "Hmm, den dommer kender ikke en god ting, når\n"
	.string "han ser det.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Hej! Du må være en alvorlig fan for at\n"
	.string "komme så tæt på handlingen.\p"
	.string "Jeg vil belønne din entusiasme med\n"
	.string "dette visdomsråd.\p"
	.string "Hvis en manøvre går rigtig godt,\n"
	.string "vil publikum blive begejstrede.\p"
	.string "POKéMON'en der appellerer lige når\n"
	.string "alle er begejstrede…\p"
	.string "Nå, man skulle tro, der sker noget\n"
	.string "godt!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "Jeg kan ikke klare det! Jeg er mere\n"
	.string "skræmt end min POKéMON.\p"
	.string "Jeg ryster og mit hjerte hamrer!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "En kamp og en KONKURRENCE er ikke\n"
	.string "det samme, men de ligner også hinanden.\p"
	.string "Du skal arbejde hårdt og tro på de\n"
	.string "POKéMON, du har opdrættet.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "Denne POKéMON ser ud til at være\n"
	.string "på toppen af sit spil, hva?\p"
	.string "En POKéMON, der gør det godt i den\n"
	.string "sekundære bedømmelse, virker mere\n"
	.string "afslappet, når den laver appel.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Skal du se den sørgelige syn?\p"
	.string "Hihi, min POKéMON er helt klart\n" 
	.string "bedre end den flok!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "Føler du ikke trangen til at\ngøre noget, når\n"
	.string "POKéMON giver et\nenergisk\nudtryk?\p$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
    .string "POKéMON KONKURRENCER\n"
    .string "HYPER RANG SCENE!$"



