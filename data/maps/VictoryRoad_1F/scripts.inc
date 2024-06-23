@ TRANSLATED

.set LOCALID_WALLY_ENTRANCE, 4

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "WALLY: Hej, {PLAYER}!\p"
	.string "Jeg satser på, at du er overrasket over\n"
	.string "at se mig her!\p"
	.string "Jeg klarede hele vejen herop, og det er\n"
	.string "takket være dig!\p"
	.string "{PLAYER}, at tabe til dig den gang\n"
	.string "gjorde mig stærkere!\p"
	.string "Men jeg vil ikke tabe mere!\p"
	.string "Jeg vil vinde! For POKéMON'erne der gav\n"
	.string "mig mod og styrke!\p"
	.string "Okay… Her kommer jeg!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Wow! {PLAYER}, du er stærk, trods alt!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "WALLY: Jeg kunne ikke slå dig i dag,\n"
	.string "{PLAYER}, men en dag vil jeg indhente\l"
	.string "dig!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "WALLY: Hej! {PLAYER}!\p"
	.string "Jeg er blevet stærkere siden sidste\n"
	.string "gang! Jeg vil vise dig det, {PLAYER}!\p"
	.string "Okay… Her kommer jeg!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Wow! {PLAYER}, du er stærk, alligevel!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "WALLY: Jeg kunne ikke slå dig denne\n"
	.string "gang, {PLAYER}... Men en dag vil jeg\l"
	.string "indhente dig... Og udfordre POKéMON\l"
	.string "LIGAEN!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "Jeg er kommet så langt et par gange,\n"
	.string "men det sidste stræk er så langt...$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Min drøm ender her igen…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Du er nået så langt. Hold momentum\n"
	.string "going og bliv CHAMPION! Hvis nogen kan,\l"
	.string "er det dig!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Jeg er ikke kommet hele vejen hertil for\n"
	.string "at tabe nu. Den mulighed eksisterer\l"
	.string "ikke!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Umuligt... Jeg tabte?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "Jeg tabte her…\p"
	.string "Det betyder, at jeg mangler de\n"
	.string "kvalifikationer for at blive MESTEREN…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Denne tilsyneladende uendelige og\n"
	.string "barske vej lever op til sit navn VICTORY.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Din kampstil er fantastisk…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Det virker som om, at du har potentiale\n"
	.string "til at blive MESTEREN.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "Hvad er SEJRVEJEN? Det vil jeg fortælle\n"
	.string "dig, hvis du vinder!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "Okay! Godt klaret!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "At komme igennem her sikkert - det er\n"
	.string "den ultimative test for enhver TRÆNER\l"
	.string "med ambitioner om at blive POKéMON\l"
	.string "MESTEREN.\p"
	.string "Derfor hedder det VICTORY ROAD.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Jeg har ingenting at sige til nogen der\n"
	.string "er kommet så langt. Kom så!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "Dette er en skam...$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Humph, fortsæt bare lige fremad. Se om\n"
	.string "jeg bekymrer mig.$"



