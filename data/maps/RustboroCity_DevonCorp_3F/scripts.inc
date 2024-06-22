@ TRANSLATED

.set LOCALID_DEVON_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Jeg er HR. STONE, direktøren for DEVON\n"
	.string "CORPORATION.\p"
	.string "Jeg har netop hørt om dig!\p"
	.string "Du har reddet vores personale ikke bare én\n"
	.string "gang, men to gange!\p"
	.string "Jeg har en tjeneste at bede om fra en\n"
	.string "fantastisk person som dig.\p"
	.string "Jeg forstår, at du er på vej til at levere en\n"
	.string "pakke til SLATEPORTs SKIBSVÆRFT.\p"
	.string "Kunne du på vejen gøre et stop i DEWFORD BY?\p"
	.string "Jeg håbede, at du ville overbringe et BREV\n"
	.string "til STEVEN i DEWFORD.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "MR. STONE: Nu skal du vide, at jeg er en\n"
	.string "fantastisk PRÆSIDENT.\p"
	.string "Så jeg ville aldrig være så nærig som at bede\n"
	.string "om en tjeneste uden at give noget til\l"
	.string "gengæld.\p"
	.string "Derfor vil jeg have, at du tager dette!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} modtog en POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "HR. STEN: Den enhed…\p"
	.string "Det er en POKéMON NAVIGATOR, eller POKéNAV\n"
	.string "for kort.\p"
	.string "Det er et uundværligt værktøj for enhver\n"
	.string "TRÆNER på et eventyr.\p"
	.string "Den har et kort over HOENN-regionen.\p"
	.string "Du kan nemt checke lokationerne af\n"
	.string "DEWFORD og SLATEPORT!\p"
	.string "Forresten, jeg har hørt at skumle\n"
	.string "kriminelle--MAGMA og AQUA, tror jeg-- har\l"
	.string "skabt problemer overalt.\p"
	.string "Jeg tror det ville være bedst, hvis du fik\n"
	.string "hvilet, inden du fortsætter på din vej.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "HR. STONE: Nå, så, {PLAYER}{KUN}, gå forsigtigt\n"
	.string "og omhyggeligt!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "Hr. Sten: Jeg regner med dig!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "HR. STEN: Du leverede min BREV? Tak skal du\n"
	.string "have!\p"
	.string "Dette er min måde at takke dig på. Det burde\n"
	.string "hjælpe dig, en TRÆNER.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "HR. STEN: En POKéMON, der holder den EXP.\n"
	.string "DELING, vil få nogle af de EXP Point fra\l"
	.string "kampen.\p"
	.string "Den vil få EXP Point, selvom den ikke har\n"
	.string "kæmpet.\p"
	.string "Jeg vil sige, at EXP. DELING er ret nyttig til\n"
	.string "at træne svage POKéMON.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "HR. STEN: Siden min ungdom har jeg dykket\n"
	.string "ned i arbejdet.\p"
	.string "Derfor er jeg ikke bekendt med trends og\n"
	.string "den slags ting.\p"
	.string "Men ønsker alle unge at være TRÆNERE i\n"
	.string "POKéMON LIGAEN?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Dette er DEVON CORPORATION's tredje sal.\p"
	.string "Vores DIREKTØRs KONTOR er på denne etage.\p"
	.string "Nå, jeg kan ikke fortælle dig, hvor\n"
	.string "taknemmelig jeg er for det, du har gjort.\p"
	.string "Øh… Forresten, den pakke, du fik tilbage for\n"
	.string "os…\p"
	.string "Kunne jeg få dig til at aflevere den på\n"
	.string "VÆRFTET i SLATEPORT?\p"
	.string "Det ville være forfærdeligt, hvis de røvere\n"
	.string "prøvede at tage den igen.\p"
	.string "Øh… Hehehe, så, øh, kan jeg regne med, at du\n"
	.string "gør det for mig?\p"
	.string "Åh, det er rigtigt. Kan du vente her et\n"
	.string "øjeblik?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Vores PRÆSIDENT vil gerne tale med dig.\p"
	.string "Følg venligst med mig.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
.string "Værsgo,\npå med dig.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Hvis du besøger VÆRFTET i SLATEPORT, skal\n"
	.string "du gå hen og besøge KAPT. STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "DEVON's nye produkter, REPEAT BALL og\n"
	.string "TIMER BALL, er blevet utroligt populære\l"
	.string "blandt TRÆNERE.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Det er en samling af sjældne sten og klipper\n"
	.string "samlet af PRÆSIDENTEN.$"



