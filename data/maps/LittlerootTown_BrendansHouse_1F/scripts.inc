.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
    .string "MOR: Ser du, {PLAYER}?\n"
    .string "Er det ikke også dejligt herinde?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
    .string "Flyttemændenes POKéMON gør alt arbejdet\n"
    .string "med at flytte os ind og rydde op efter.\l"
    .string "Det er så praktisk!\p"
    .string "{PLAYER}, dit værelse er ovenpå.\n"
    .string "Gå derop og se det, skat!\p"
    .string "FAR har købt et nyt ur til dig\n"
    .string "i forbindelse med vores flytning herhen.\l"
    .string "Glem ikke at stille det!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
    .string "MOR: Nå, {PLAYER}?\p"
    .string "Er du ikke interesseret i at se dit\n"
    .string "helt eget værelse?$"

PlayersHouse_1F_Text_GoSetTheClock:
    .string "MOR: {PLAYER}.\p"
    .string "Gå hen og stil uret på dit værelse, skat.$"

PlayersHouse_1F_Text_OhComeQuickly:
    .string "MOR: Åh! {PLAYER}, {PLAYER}!\n"
    .string "Skynd dig! Kom hurtigt!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
    .string "MOR: Se! Det er PETALBURG GYM!\n"
    .string "Måske er FAR på!\p"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
    .string "MOR: Åh… Det er slut.\p"
    .string "Jeg tror, at FAR var der, men vi\n"
    .string "mistede ham. Det er ærgerligt.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
    .string "Åh ja.\n"
    .string "En af FARs venner bor her i byen.\p"
    .string "PROF. BIRCH er hans navn.\p"
    .string "Han bor lige ved siden af, så du burde\n"
    .string "gå hen og præsentere dig selv.$"

PlayersHouse_1F_Text_SeeYouHoney:
    .string "MOR: Vi ses, skat!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
    .string "MOR: Præsenterede du dig selv for\n"
    .string "PROF. BIRCH?$"

PlayersHouse_1F_Text_YouShouldRestABit:
    .string "MOR: Hvordan har du det, {PLAYER}?\n"
    .string "Du ser lidt træt ud.\p"
    .string "Jeg synes, du burde hvile lidt.$"

PlayersHouse_1F_Text_TakeCareHoney:
    .string "MOR: Pas på dig selv, skat!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
    .string "MOR: Åh? Gav FAR dig den BADGE?\p"
    .string "Så her er noget fra din MOR!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
    .string "Pres dig ikke for hårdt, skat.\n"
    .string "Du kan altid komme hjem.\p"
    .string "Gå efter det, skat!$"

PlayersHouse_1F_Text_IsThatAPokenav:
    .string "MOR: Hvad er det, skat? En POKéNAV?\n"
    .string "Nogen fra DEVON gav dig den?\p"
    .string "Nå, skat, hvad med at registrere\ndin mor?\p"
    .string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
    .string "Registreret MOR\n"
    .string "i POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
    .string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
    .string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
    .string "INTERVIEWER: …Vi bringer dig denne\n"
    .string "rapport fra foran PETALBURG GYM.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
    .string "Der er en film på TV.\p"
    .string "To mænd danser på et stort klaver\n"
    .string "keyboard.\p"
    .string "Bedre komme videre!$"

PlayersHouse_1F_Text_RunningShoesManual:
    .string "Det er instruktionshæftet til\n"
    .string "LØBESKOENE.\p"
    .string "“Tryk på B-knappen for at løbe, mens\n"
    .string "du har dine LØBESKO på.\p"
    .string "“Sæt dine LØBESKO på og kom ud\n"
    .string "på vejen at løbe!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
    .string "FAR: Hm?\p"
    .string "Hej, det er {PLAYER}!\p"
    .string "Det er længe siden, jeg så dig,\n"
    .string "men du ser…stærkere ud, på en eller anden måde.\p"
    .string "Det er det indtryk, jeg får.\n"
    .string "Men din gamle far har ikke opgivet endnu!\p"
    .string "Åh ja, jeg har noget til dig.\n"
    .string "Dette kom til dig fra en, der hedder\n"
    .string "MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
    .string "FAR: Hm, en billet til en færge?\p"
    .string "Hvis jeg husker rigtigt, er der færgehavne\n"
    .string "i SLATEPORT og LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
    .string "Jeg burde nok komme tilbage til\n"
    .string "PETALBURG GYM.\p"
    .string "MOR, tak fordi du passer huset\n"
    .string "mens jeg er væk.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
    .string "MOR: Den FAR, din…\p"
    .string "Han kommer hjem for første gang i lang tid,\n"
    .string "men alt hvad han taler om, er POKéMON.\p"
    .string "Han burde slappe af og blive lidt længere.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
    .string "MOR: Er det en nyhedsflash?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
    .string "Vi bringer dig denne nød-\n"
    .string "nyhedsflash!\p"
    .string "I forskellige HOENN-områder er der blevet\n"
    .string "rapporteret om en BZZT…farvet\n"
    .string "POKéMON, der flyver rundt.\p"
    .string "Identiteten af denne POKéMON er\n"
    .string "for øjeblikket ukendt.\p"
    .string "Vi vender nu tilbage til den normale\n"
    .string "filmudsendelse.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
    .string "MOR: {PLAYER}, fangede du det?\p"
    .string "Hvilken farve sagde nyhedsoplæseren,\n"
    .string "at POKéMON'en havde?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
    .string "MOR: Nå, er det ikke noget!\n"
    .string "Der er stadig ukendte POKéMON.$"
