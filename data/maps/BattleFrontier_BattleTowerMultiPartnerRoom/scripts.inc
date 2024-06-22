@ TRANSLATED

.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_ATTENDANT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Find en partner blandt TRÆNERNE samlet\n"
	.string "her.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, du har ikke fundet en makker til\n"
	.string "dit tag team.\p"
	.string "Vil du stoppe med at lede og vende tilbage til\n"
	.string "receptionen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Så find venligst en partner fra TRÆNERNE\n"
	.string "der er samlet her.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Tak for at vælge en partner.\p"
	.string "Jeg vil nu vise dig til din MULTI BATTLE ROOM.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Jeg er {STR_VAR_1}'s nr.\n"
	.string "{STR_VAR_2} lærling. Du kan kalde mig\l"
	.string "{STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "På {STR_VAR_1}s råd, tog jeg en\n"
	.string "{STR_VAR_3} med {STR_VAR_2} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Vil du lade mig slutte mig til dig som et tag\n"
	.string "team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Tak! Jeg vil gå registrere lige nu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Jeg ville virkelig danne et tag team med dig,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Jeg er {STR_VAR_1}s nr.\n"
	.string "{STR_VAR_2} lærling. Mit navn er\l"
	.string "{STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "Jeg fik råd fra {STR_VAR_1} og valgte en\n"
	.string "{STR_VAR_3} med {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Kom så, lad os danne et makkerpar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Mange tak! Jeg bliver færdig med\n"
	.string "registreringen hurtigt!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, jeg håbede, at jeg kunne finde\n"
	.string "en partner i dig…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Øh, mit navn er {STR_VAR_3}, og jeg er\n"
	.string "{STR_VAR_1}'s lærling nr.\l"
	.string "{STR_VAR_2}.\p"
	.string "Snøft…\p"
	.string "Undskyld! Denne spænding får mig til at\n"
	.string "græde…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} rådede mig, så jeg har en\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "en {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Snøft… Vil du ikke være med i mit hold, vær\n"
	.string "sød!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Åh, virkelig? Vil du det? Fantastisk! Fedt!\n"
	.string "Awoooh!\p"
	.string "Åh... Undskyld... Jeg er så glad, jeg græder...\p"
	.string "Jeg går straks og registrerer mig. Vær sød at\n"
	.string "blive!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Åh, m-m...  Hik... Waaaaah!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Hej, med dig! Jeg er {STR_VAR_3}! Jeg er\n"
	.string "{STR_VAR_1}'s nr. {STR_VAR_2}\l"
	.string "lærling!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} anbefalede mit hold. En\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "én {STR_VAR_2} med {STR_VAR_1},\n"
	.string "det er hvad jeg har! Sejt, ikke?\p"
	.string "Så kom så! Lad os danne et tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Jubiii! Super! Okay, jeg vil gå registrere,\n"
	.string "okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Åh, hvorfor? Jeg ville gerne slå mig sammen,\n"
	.string "{PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Jeg er {STR_VAR_3}, nummer\n"
	.string "{STR_VAR_2} lærling af den berømte\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "Jeg spurgte {STR_VAR_3} om råd. En\n"
	.string "{STR_VAR_1}-brugende\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "og en {STR_VAR_2} med {STR_VAR_1},\n"
	.string "det er mit par.\p"
	.string "Vil du være med i et makkerpar med mig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Tak! Jeg vil registrere mig med det samme!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, jeg havde håbet at danne et\n"
	.string "hold med dig…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Øhm... Jeg er virkelig glad for, at du ville\n"
	.string "tage dig tid til at snakke med mig.\p"
	.string "Jeg er {STR_VAR_3}. Jeg er\n"
	.string "{STR_VAR_1}s nummer {STR_VAR_2}\l"
	.string "lærling...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} gav mig gode råd. Jeg er\n"
	.string "meget taknemmelig for det.\p"
	.string "Jeg har et hold med en {STR_VAR_2} med\n"
	.string "{STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "en {STR_VAR_2} med {STR_VAR_1}.\n"
	.string "Jeg ved, jeg beder om meget... \p"
	.string "Jeg tror ikke, du vil være villig til det, men må\n"
	.string "jeg være med som din partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Ærligt? Jeg kan ikke tro det! Jeg kan ikke\n"
	.string "tro, at du vil lade mig være med! Jeg… Jeg vil\l"
	.string "ikke skuffe dig!\p"
	.string "Øh… Hvis det virkelig er okay, vil jeg straks\n"
	.string "gå og tilmelde mig!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Åh… Jeg troede ikke, jeg var god nok…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Hej, jeg er {STR_VAR_3}. Jeg er\n"
	.string "{STR_VAR_1}s nr. {STR_VAR_2}\l"
	.string "lærling!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} fortalte mig, at det ville\n"
	.string "være godt at danne dette hold: en\l"
	.string "{STR_VAR_1}-brugende\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "og en {STR_VAR_2}, som ved, hvordan man\n"
	.string "bruger {STR_VAR_1}.\p"
	.string "Ikke dårligt, hva'? Vil du have mig som din\n"
	.string "makker?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "Okay, dejligt at være med dig! Jeg håber, du\n"
	.string "ikke roder tingene til for mig! Jeg vil lave\l"
	.string "min registrering nu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Hvad? Hvorfor afslog du mig? Du har ingen\n"
	.string "forstand på karakter!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Jeg er {STR_VAR_3} og jeg er en\n"
	.string "TRIATLET. Jeg har travlt hver dag med at\l"
	.string "jogge, træne og rappe.\p"
	.string "Jeg er også {STR_VAR_1}s nr.\n"
	.string "{STR_VAR_2} lærling.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Dette er hvad {STR_VAR_3} anbefalede.\n"
	.string "En {STR_VAR_1}-brugende\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "og en {STR_VAR_1}-bruger\n"
	.string "{STR_VAR_2}.\p"
	.string "Jeg har lagt meget arbejde i at opdrage dem,\n"
	.string "selvom jeg er travl.\p"
	.string "Lad os danne et hold sammen og prøve det!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Tak, det er ånden! Hold fast, mens jeg går og\n"
	.string "registrerer, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "Jeg fandt tid i min travle kalender for at\n"
	.string "være her! Giv mig en pause!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Hej! Hvordan går det?\p"
	.string "Jeg er {STR_VAR_3}, {STR_VAR_1}s\n"
	.string "nummer {STR_VAR_2} lærling. Rart at\l"
	.string "møde dig!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Lyt, lyt! Du skal høre om den POKéMON, som\n"
	.string "{STR_VAR_3} anbefalede. En\l"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "en {STR_VAR_2} med {STR_VAR_1}.\n"
	.string "Selvfølgelig har jeg opdraget dem\l"
	.string "suverænt!\p"
	.string "Så, vil du være med i et hold? Jeg er sikker på,\n"
	.string "det vil være en fantastisk kombination!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Jeg tror dette bliver sjovt! Jeg går hen og\n"
	.string "registrerer mig!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Åh, du er slem! Jeg kommer anbefalet, du ved.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Vil du så lade mig præsentere mig selv? Jeg er\n"
	.string "{STR_VAR_3}.\p"
	.string "Jeg er {STR_VAR_1}s lærling nr.\n"
	.string "{STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "Jeg søgte den vise vejledning fra\n"
	.string "{STR_VAR_3} og hev mit hold op af én\l"
	.string "{STR_VAR_2} med {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "og en {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Vil du være med i et tag team med mig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Åh… Jeg er henrykt! Jeg lover at give dig mit\n"
	.string "bedste!\p"
	.string "Selvfølgelig vil jeg registrere os! Vent\n"
	.string "venligst!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "Jeg havde håbet at kunne deltage sammen\n"
	.string "med dig, {PLAYER}...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Åh! Du talte til mig! Jeg... Jeg er henrykt!\p"
	.string "Jeg er {STR_VAR_3}! Jeg er\n"
	.string "{STR_VAR_1}s nr. {STR_VAR_2}\l"
	.string "lærling!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "På {STR_VAR_3}'s opfordring trænede\n"
	.string "jeg én {STR_VAR_1}-brugende\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "og en {STR_VAR_1}-bruger\n"
	.string "{STR_VAR_2}.\p"
	.string "Vil du være så venlig at opfylde min ønske?\n"
	.string "Jeg vil gerne være din tag-team partner!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Åh nej! Jeg... Jeg føler mig svimmel! Mange\n"
	.string "tak! Jeg vil straks registrere os!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Waaah! Føler du ingen medlidenhed? Men det\n"
	.string "gør dig sejere…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Jiihaa! Jeg er {STR_VAR_1}s nr.\n"
	.string "{STR_VAR_2} lærling!\p"
	.string "{STR_VAR_3} er mit navn, hej, hej!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Min mentor {STR_VAR_3} anbefalede én\n"
	.string "{STR_VAR_1}-mester {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "og en {STR_VAR_1}-mester\n"
	.string "{STR_VAR_2}.\p"
	.string "Godt stof, ikke? Du vil være min partner,\n"
	.string "ikke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Okay, fremragende! Jeg får registreringen\n"
	.string "hurtigt ordnet!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Gwaaah! Du er en beregnende en,\n"
	.string "{PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Hey! Der er stor problemer! Dette er BATTLE\n"
	.string "TOWER's sidste dag!\p"
	.string "… … … … … … Jeg laver bare sjov!\p"
	.string "Folk kalder mig {STR_VAR_3} og det gør\n"
	.string "jeg også! Jeg er {STR_VAR_1}'s 1.000.\l"
	.string "lærling! Faktisk er jeg nr. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} gav mig nogle råd.\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} med {STR_VAR_1}. Jeg\n"
	.string "har ti af hver slags! Faktisk kun en af hver!\p"
	.string "Hvad siger du til det? Har lyst til at prøve\n"
	.string "tag-kampe med mig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Jubii! Jeg vil give dig en POKéMON som tak!\p"
	.string "Bare sjov! Men jeg vil virkelig gå registrere\n"
	.string "det, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Åh, det er så koldt! Jeg bliver nødt til at\n"
	.string "ødelægge KAMPENS TÅRN for det!\p"
	.string "Selvfølgelig vil jeg ikke!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Hej med dig, jeg gynger og ruller! POKéMON,\n"
	.string "jeg kontrollerer!\p"
	.string "Jeg er {STR_VAR_3} den rappe SØMAND.\n"
	.string "Tag ikke fejl og vær ingen piver!\p"
	.string "Jeg er {STR_VAR_1}'s nr.\n"
	.string "{STR_VAR_2} lærling. Dig bør man ikke\l"
	.string "hurtigt afskrive!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Med råd fra {STR_VAR_3} fulgte jeg og\n"
	.string "samlede mit stolte hold!\p"
	.string "En {STR_VAR_2}, der bruger\n"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "og en {STR_VAR_1}-brugende\n"
	.string "{STR_VAR_2}!\p"
	.string "Vi bør fejre vores møde, med en tag-team\n"
	.string "sejr at feste!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hej, hej, jeg kan lide din stil! Jeg vil gå\n"
	.string "videre med vores registrering!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Åh, hey, {PLAYER}, nu er der koldt! Hvis jeg\n"
	.string "må være så fræk!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Jubiii! Åh, løb ikke! Jeg legede bare! \p"
	.string "Hej! Jeg er {STR_VAR_3}! Jeg er\n"
	.string "{STR_VAR_1}s nr. {STR_VAR_2}\l"
	.string "lærling!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} fortalte mig, hvad jeg skal\n"
	.string "gøre. Så en {STR_VAR_1}-brugende\l"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "og en {STR_VAR_1}-bruger\n"
	.string "{STR_VAR_2}, valgte jeg.\p"
	.string "Så, hvad siger du? Kom nu, gør min dag!\p"
	.string "Vær sød, jeg beder dig! Lad mig være med, lad\n"
	.string "mig ikke være blå!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Jaj! Heldet er med mig! Det gør mig virkelig\n"
	.string "glad!\p"
	.string "Inden vi deltager i kampen, vil jeg straks\n"
	.string "registrere mig!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Du afviser mig? {PLAYER}, du får mig til at\n"
	.string "trække på smilebåndet!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Host!\p"
	.string "Åh, undskyld, jeg har en forkølelse. Mine\n"
	.string "POKéMON har det godt, dog.\p"
	.string "Jeg hedder {STR_VAR_3},\n"
	.string "{STR_VAR_1}'s nr. {STR_VAR_2}\l"
	.string "lærling. Host!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "Jeg tog {STR_VAR_3}s råd til mig og\n"
	.string "satte mit hold sammen af ént\l"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Jeg trænede dem hver dag, selv i blæst og\n"
	.string "regn.\p"
	.string "Det er derfor, jeg har denne forkølelse,\n"
	.string "tror jeg.\p"
	.string "Det er det, jeg handler om. Vil du være min\n"
	.string "makker?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Tak, jeg sætter pris på dette! Host, host!\p"
	.string "Vent et øjeblik, mens jeg går for at\n"
	.string "registrere.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Åh, vil du ikke? {PLAYER}, jeg tror vi ville\n"
	.string "være et godt match.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Hej! Det her er nervepirrende.\p"
	.string "Jeg er {STR_VAR_3}. Jeg er nummer\n"
	.string "{STR_VAR_2}s lærling hos\l"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} sagde, at dette hold vil\n"
	.string "være godt-- en {STR_VAR_2} med\l"
	.string "{STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Jeg føler mig lidt genert over dette, men vil\n"
	.string "du lade mig være med?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Åh, tusind tak! Jeg føler mig genert, men jeg\n"
	.string "vil gøre mit bedste!\p"
	.string "Jeg går lige hen og får registreringen\n"
	.string "klaret.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Åh, sig venligst ikke nej! Jeg føler mig\n"
	.string "allerede selvbevidst nok...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Jeg er {STR_VAR_3}, og det er ingen løgn.\n"
	.string "Jeg er {STR_VAR_1}'s nr.\l"
	.string "{STR_VAR_2} lærling.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} anbefalede mit hold.\p"
	.string "Da rådet lød ærligt, besluttede jeg at tage\n"
	.string "med mig {STR_VAR_1}-brugende\l"
	.string "{STR_VAR_2} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "min {STR_VAR_1}-brugende\n"
	.string "{STR_VAR_2}.\p"
	.string "Hvis det er muligt, vil jeg gerne have dig som\n"
	.string "min tag-team partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "Vil du virkelig acceptere mig? Det ville være\n"
	.string "alt for forfærdeligt ellers.\p"
	.string "Men da du har sagt ja, er det fint. Jeg vil gå\n"
	.string "registrere os begge.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm? Nu, hvorfor ville du nægte? Er det din idé\n"
	.string "om en joke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Jeg er {STR_VAR_1}, og jeg er en PIGE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "Det jeg har er en {STR_VAR_2} som bruger\n"
	.string "{STR_VAR_1} og én$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} som bruger\n"
	.string "{STR_VAR_1}. Det er hvad jeg har med mig.\p"
	.string "Vil du være min partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Tak! Jeg går hen og registrerer mig!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "Vil du ikke være min partner? Du vil fortryde\n"
	.string "det senere!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Hej!\p"
	.string "Jeg er UNGE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Vil du vide, hvad jeg har? En {STR_VAR_2}\n"
	.string "med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "Én {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Du bliver min tag-team partner, ikke sandt?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Jubi! Jeg går lige hen og melder mig til, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Åh! Hvis du dannede et hold med mine\n"
	.string "POKéMON, ville vi være ustoppelige!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Hej! Jeg er VANDRER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Ved du, hvad jeg har med mig? Min\n"
	.string "{STR_VAR_1}-brugende\l"
	.string "{STR_VAR_2} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "min {STR_VAR_1}-brugende\n"
	.string "{STR_VAR_2}!\p"
	.string "Lyder godt, hva'? Har lyst til at danne et tag\n"
	.string "team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Jubii! Jeg vil gå og registrere det, så.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Jeg ville have elsket at kæmpe ved din side.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Hej! Jeg er {STR_VAR_1}, og jeg er en\n"
	.string "SKØNHED!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Ved du, hvad jeg har opdrættet? En\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Hvad tror du? Vil du danne et tag team\n"
	.string "sammen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Fantastisk! Jeg vil få registreringen\n"
	.string "klaret nu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Hvor skuffende!\p"
	.string "Vi to sammen--vi ville have været de\n"
	.string "bedste!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Hej!\p"
	.string "Ved du, hvem jeg er? Jeg er {STR_VAR_1}\n"
	.string "FISKEDEJEREN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Jeg har med mig et hold på en\n"
	.string "person-brugende {STR_VAR_2} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "en {STR_VAR_1}-brugende\n"
	.string "{STR_VAR_2}.\p"
	.string "Så, hvad siger du? Vil du kæmpe ved min side?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Godt, godt! Lad mig klare det!\p"
	.string "Jeg går og registrerer os nu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
.string "Vi matcher også perfekt…$ "

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Dejligt at møde dig. Jeg er {STR_VAR_1},\n"
	.string "en frøken.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Jeg er ledsaget af et hold bestående af en\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Jeg håber, jeg lever op til dine\n"
	.string "forventninger. For jeg ønsker dig som min\l"
	.string "partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Jeg takker dig oprigtigt. Jeg vil tage mig af\n"
	.string "registreringen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Jeg er sikker på, at du vil fortryde ikke at\n"
	.string "have mig som din partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
.string "Jeg er TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Hvad jeg har… En {STR_VAR_2} med\n"
	.string "{STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\n"
	.string "Det er min makker!\p"
	.string "Vil du ikke? Vil du danne et tag team med mig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Hold da op, tusind tak! Jeg vil gå registrere\n"
	.string "mig ved skranken.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Vi to sammen, vi ville have været sikker på\n"
	.string "seje!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Hej! Jeg er INSEKTOPFANGER\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Se lige hvad jeg har! En {STR_VAR_2} med\n"
	.string "{STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "Én {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Så, lyt! Vil du danne et makkerpar?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Gotcha!\p"
	.string "Jeg går hen og ordner registrerings- sagen\n"
	.string "ved disken.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Åh, mine POKéMON er fantastiske. Jeg håber,\n"
	.string "at du ikke vil fortryde dette!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "God dag! Jeg er SKOLEBARN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "Det, jeg har opdrættet, er en\n"
	.string "{STR_VAR_2}, der bruger\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "og en {STR_VAR_2}, der bruger\n"
	.string "{STR_VAR_1}.\p"
	.string "Ikke så dårligt, synes du ikke? Har du lyst\n"
	.string "til at danne et hold?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Mange tak! Jeg bliver færdig med\n"
	.string "registreringen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "Det er ærgerligt…\p"
	.string "Jeg håbede, at jeg kunne lære af dig som din\n"
	.string "partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Hej! Lad mig fortælle dig, hvem jeg er! Jeg er\n"
	.string "RIG dreng {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Gæt hvad jeg har fået! En {STR_VAR_2}\n"
	.string "med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "En kamp med {STR_VAR_1} og\n"
	.string "{STR_VAR_2}!\p"
	.string "Jeg er klar til at tilbyde dig chancen til at\n"
	.string "være i et tag team med mig.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Godt tænkt!\p"
	.string "Jeg afslutter registreringen processen\n"
	.string "hurtigt!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Vil du virkelig afvise mig? Du vil helt\n"
	.string "sikkert fortryde den beslutning!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hej! Jeg er SORT BÆLTE {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Som mine ledsagere har jeg en\n"
	.string "{STR_VAR_2} der bruger\l"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "og en {STR_VAR_2} bruger\n"
	.string "{STR_VAR_1}.\p"
	.string "Vær sød at opfylde mit ønske! Tillad mig at\n"
	.string "være din tag-partner!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hejyah! Jeg vil gå registrere\n"
	.string "øjeblikkeligt!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Jeg ser... Jeg håber på en mulighed næste\n"
	.string "gang vi mødes...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Hej, du! Jeg er {STR_VAR_1}, og jeg er en\n"
	.string "TUBER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Jeg vil fortælle dig, hvad jeg har. En\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}! Må\n"
	.string "jeg være med i dit hold?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Tak! Jeg vil gå registrere os nu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Hvis vi var blevet partnere, kunne vi have\n"
	.string "været så stærke!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Hej… Jeg er HEX MANIAC {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "Jeg bærer med mig én\n"
	.string "{STR_VAR_1}-bruger {STR_VAR_2}\l"
	.string "sammen med én$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_1}-bruger {STR_VAR_2}…\p"
	.string "Jeg trygler dig… Vil du være med i et tag\n"
	.string "team...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Jeg takker dig… Jeg vil registrere os…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
.string "Jeg længtes sådan efter at være en del af dit hold…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Hvordan går det? Jeg er {STR_VAR_1}, og\n"
	.string "jeg er en POKéMON OPDRÆTTER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "Jeg opdrætter et par gode! En\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "En kamp med {STR_VAR_1} mod\n"
	.string "{STR_VAR_2}!\p"
	.string "Hvad siger du? Har du lyst til at danne et\n"
	.string "hold med mig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Tak skal du have!\p"
	.string "Jeg går hen og tager mig af registreringen\n"
	.string "så venter du bare lige her!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "Jeg glædede mig til at være din partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Hej! Jeg er TRIATLET {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Vil du vide, hvad jeg løber med? En\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Nå? Vil du være med i et tag team med mig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Godt gået!\p"
	.string "Jeg vil være hurtig og få registreringen\n"
	.string "helt færdig!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Du og jeg, vi ville have været de bedste. Det\n"
	.string "er ærgerligt…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Hej med dig! Jeg hedder {STR_VAR_1}!\n"
	.string "Jeg er en TRIATLET!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Jeg tager på løbeture med mit hold af seje\n"
	.string "venner-- en {STR_VAR_2} med\l"
	.string "{STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Ikke dårligt, hva'?  Vi burde være et hold\n"
	.string "sammen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "Godt! Jeg går straks hen for at registrere\n"
	.string "mig!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Jeg ville virkelig kæmpe som din makker i\n"
	.string "holdkamp…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
.string "Jeg er KAMPEPIGEN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "Jeg har styrket mig ved at bruge\n"
	.string "{STR_VAR_1} med {STR_VAR_2} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "En bruger af {STR_VAR_1}-med\n"
	.string "{STR_VAR_2}!\p"
	.string "Kan du lide den kombination? Hvad siger du\n"
	.string "til, at vi slår os sammen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Hvor er du sød!\p"
	.string "Jeg vil få registreringen ordnet med det\n"
	.string "samme!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Med dig troede jeg, at vi kunne danne  det\n"
	.string "ultimative makkerpar…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Jeg er TRIATHLETEN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "Jeg har løbet med en {STR_VAR_2} der\n"
	.string "ved, hvordan man bruger {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "og én {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Vi kunne være et tag team. Ville det ikke være\n"
	.string "fedt?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Tak!\p"
	.string "Jeg går hen og registrerer os, og det er lige\n"
	.string "nu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Åh nej, det er ærgerligt. Vi ville have været\n"
	.string "det sejeste makkerpar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Jeg? Jeg er TUBER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Hvad har jeg med mig? En {STR_VAR_2} med\n"
	.string "{STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Hey? Vil du alliere dig med mig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "Okay!\p"
	.string "Jeg vil registrere mig! Lad os være\n"
	.string "fremragende sammen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "Mine POKéMON er helt sikkert seje… Det er\n"
	.string "ærgerligt, at du ikke vil danne hold.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Jubii-hurra! Kald mig GUITARIST\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Tjek min følge ud! En {STR_VAR_2} med\n"
	.string "{STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "Én {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Jubii-hurra! ret vildt, ik? Vi må synge en\n"
	.string "duet i et hold!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Jubiii! Rigtig godt! Jeg vil gøre den\n"
	.string "registrering nu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "Mine POKéMON er skide seje! Du vil fortryde\n"
	.string "det, det siger jeg dig!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Dejligt at møde dig. Jeg er {STR_VAR_1},\n"
	.string "en GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Jeg bliver fulgt af min betroede\n"
	.string "{STR_VAR_1}-brugende\l"
	.string "{STR_VAR_2} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "en {STR_VAR_1}-brugende\n"
	.string "{STR_VAR_2}.\p"
	.string "Vil du være med i et tag-team partnerskab\n"
	.string "med mig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Åh, jeg takker dig for din tillid. Jeg skal\n"
	.string "være færdig med registreringen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Det er meget uheldigt…\p"
	.string "Jeg glæder mig til næste mulighed…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "og jeg er en POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Jeg har nu med mig en {STR_VAR_2} som\n"
	.string "kender trækket {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Kan du lide hvad du ser? Hvorfor bliver du\n"
	.string "ikke min makker i ringen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Tak! Jeg vil tage mig af registreringen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "Mine POKéMON er af top kvalitet… Det er\n"
	.string "ærgerligt, at du ikke kan værdsætte det.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hm! Jeg er {STR_VAR_1}, og ekspert er\n"
	.string "jeg!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "De POKéMON, som jeg har trænet, er en\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Hvad siger du til et holdkamp med mig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hm! Jeg vil registrere os med det samme!\p"
	.string " Lad os begge gøre vores bedste!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Jeg håber, at dit valg er korrekt…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Hej, hej. Jeg er {STR_VAR_1}, og jeg er en\n"
	.string "EKSPERT.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "Jeg har opdraget mine POKéMON grundigt. En\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "en {STR_VAR_2} med {STR_VAR_1}--\n"
	.string "det er hvad jeg har.\p"
	.string "Vil du ikke gerne danne hold med mig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Godt, godt. Jeg skal straks tage mig af\n"
	.string "registreringen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Måske kan vi danne et hold næste gang vi\n"
	.string "mødes.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
.string "Jeg er DRAGE TEMMER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "Holdet, jeg har styrket, er et\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Hvad siger du? Vil du være min partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Okay, jeg vil gøre mit bedste! Jeg vil gå\n"
	.string "registrere mig nu, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "Du vil ikke finde mange, der er sejere end\n"
	.string "mig! $"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Jeg er FUGLEOPDRÆTTER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "Hvilke POKéMON har jeg? Én {STR_VAR_2}\n"
	.string "med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Synes du ikke, vi ville udgøre et ordentligt\n"
	.string "makkerpar?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Fantastisk, tak! Jeg vil tage mig af\n"
	.string "registreringen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Mine POKéMON og jeg er stærke. Hvad en\n"
	.string "skuffelse.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
.string "Jeg er NINJA DRENG {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Mit POKéMON-hold består af en\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Skal vi danne et tag team sammen?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Jubii! Lad mig gå registrere!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Du vil fortryde ikke at have min seje\n"
	.string "POKéMON ved din side!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Hej! Jeg er PARASOL DAMEN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Nu eskorterer mig mine {STR_VAR_2} der\n"
	.string "bruger {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "en {STR_VAR_2}, der bruger\n"
	.string "{STR_VAR_1}.\p"
	.string "Er de ikke søde? Har lyst til at være med i\n"
	.string "vores hold?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Tak en masse!\p"
	.string "Jeg vil gå og registrere mig ved skranken.\n"
	.string "Lad os ikke skuffe hinanden!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "Mine POKéMON er vanvittigt stærke. Hvor\n"
	.string "skuffende…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Hej. Jeg er {STR_VAR_1} og jeg er en\n"
	.string "INSEKTGLAD PERSON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "Jeg har fundet min POKéMON, ja. En\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "en {STR_VAR_2} med {STR_VAR_1}--\n"
	.string "det er det jeg fandt.\p"
	.string "Kunne jeg friste dig til at danne et\n"
	.string "makkerpar?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Okay! Forstået!\p"
	.string "Jeg bliver ikke længe med registreringen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Med de POKéMON, jeg fandt, ville vi ikke være\n"
	.string "blevet skuffet…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Hej med dig! Jeg er SØMAND {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Lad mig vise dig min stolthed og glæde! Én\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "en {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Selvfølgelig siger du ikke nej. Vi vil danne\n"
	.string "et hold, ikke sandt?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "Jeg havde heller ikke ventet mindre! Jeg vil\n"
	.string "gå registrere nu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Vi ville have stormet igennem\n"
	.string "modstanderen! Hvad ærgerligt!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Hej, jeg er {STR_VAR_1}. Jeg er en\n"
	.string "SAMLER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "Juvelerne i min samling er mine\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Fedt, ikke? Vi burde være i et hold sammen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Åh, ja!\p"
	.string "Nå, lad os ikke spilde tiden. Jeg vil gå\n"
	.string "registrere os to.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Nå, det er ærgerligt. Du sætter ikke pris på\n"
	.string "mine POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Hej, jeg er {STR_VAR_1}. Jeg er en\n"
	.string "POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "At holde mig med selskab er en\n"
	.string "{STR_VAR_1}-brugende\l"
	.string "{STR_VAR_2} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "Slå én på {STR_VAR_2} med\n"
	.string "{STR_VAR_1}!\p"
	.string "Synes du ikke, at vi ville være et\n"
	.string "imponerende makkerpar?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "Det er super! Jeg vil nu ordne\n"
	.string "registreringen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "Næste gang, vælg min POKéMON, vil du?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Jeg hedder {STR_VAR_1}. Jeg er en\n"
	.string "POKéMON RANGER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Lad mig fortælle dig om mit hold. Jeg har en\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "En kamp med {STR_VAR_1} mod\n"
	.string "{STR_VAR_2}!\p"
	.string "Hvordan vil du danne et tag team med min lille\n"
	.string "bande?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "Vi vil være på vores bedste! Jeg får\n"
	.string "registreringen hurtigt klaret!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "Jeg håber, du vil vælge min POKéMON næste\n"
	.string "gang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Behageligt at møde dig. Jeg er\n"
	.string "{STR_VAR_1}. Jeg betragter mig selv\l"
	.string "som en DUFTDAME.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Jeg rejser med en {STR_VAR_2}. som\n"
	.string "bruger {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "en {STR_VAR_2}, der bruger\n"
	.string "{STR_VAR_1}.\p"
	.string "Jeg håber, de vækker din interesse. Vil du\n"
	.string "være min partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Jeg er beæret over din accept. Jeg vil gå\n"
	.string "registrere mig lige nu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Det ville være fantastisk, hvis vi kunne\n"
	.string "danne et tag team næste gang, vi mødes.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Vil du vide, hvem jeg er? Jeg er\n"
	.string "{STR_VAR_1}, ØDELÆGGELSENS\l"
	.string "FANATIKER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "De POKéMON, jeg har med mig, er en\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Spændende, ikke sandt? Hvad siger du til at\n"
	.string "være partnere?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "Det er en fornuftig beslutning! Jeg går i\n"
	.string "gang med registreringspapirarbejdet.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm… Jeg tror mine POKéMON er seje…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
.string "Jeg er SEJTRÆNER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "De POKéMON, jeg har lige nu, er en\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "en {STR_VAR_2} med {STR_VAR_1}.\n"
	.string "Fedt, ikke?\p"
	.string "Synes du ikke, det ville være ret fedt, hvis vi\n"
	.string "dannede et hold?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Fedt! Jeg går straks i gang med\n"
	.string "registreringen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Jeg troede, at vi ville lave det bedste hold\n"
	.string "nogensinde.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Jeg er SEJTRÆNER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "Det hold jeg har trænet har en\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Lyder det okay? Hvad med at blive\n"
	.string "tag-partnere?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Lydene er helt i orden! Jeg må hellere\n"
	.string "registrere mig.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Jeg tænkte på, at vi ville være et sejt hold…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Hej! Jeg er {STR_VAR_1},\n"
	.string "POKéMANIAC'en!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Hvad har en fyr som mig? En {STR_VAR_2}\n"
	.string "med {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "én {STR_VAR_2} med {STR_VAR_1},\n"
	.string "det' sgu sjovt!\p"
	.string "Lad os gøre det! Vi vil trampe rundt som et\n"
	.string "tag-hold!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Godt tænkt! Jeg vil registrere os begge!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "Mine POKéMON er brutale! Det er ikke min\n"
	.string "skyld, hvis du fortryder dette!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Hej med dig! Jeg er KINDLER\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Ved du hvad min træning har fundet på? En\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Nå, hvad siger du? Vil du danne et\n"
	.string "makkerpar?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "Okay! Jeg går i gang med registreringen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Lover du at være min partner næste gang vi\n"
	.string "løber ind i hinanden?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Jeg er {STR_VAR_1}, og jeg er en\n"
	.string "SPEJDER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "Jeg har opdrættet en {STR_VAR_1}- ved\n"
	.string "brug af {STR_VAR_2} og én$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_1}-bruger {STR_VAR_2}.\p"
	.string "Tror du, det ville være sjovt at danne et\n"
	.string "hold? Jeg ved, det ville det!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Ja! Afsted for at registrere!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "Næste gang, okay? Jeg vil gerne være på dit\n"
	.string "hold.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Hej! Jeg er {STR_VAR_1}, og jeg er en\n"
	.string "PICNICKER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "De POKéMON, jeg har fanget, er  en\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Er du interesseret i at slutte dig til et tag\n"
	.string "team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Hvor er du sød! Jeg vil registrere dig nu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Det ville være dejligt, hvis jeg kunne blive\n"
	.string "med dig en anden gang.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Jeg er PSI-KYK {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "De to jeg har opdrættet er en\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Vil du danne et tag team med mig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Selvfølgelig! Jeg sørger for\n"
	.string "registreringen!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Hvis vi mødes igen, det er der, jeg gerne vil\n"
	.string "alliere mig med dig.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Jeg er {STR_VAR_1}. Jeg er en PSYKISK.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
.string "En {STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "en {STR_VAR_2} med {STR_VAR_1}--\n"
	.string "de er mine disciple.\p"
	.string "Synes du ikke tanken om at danne et\n"
	.string "tag-team partnerskab er spændende?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Tak. Jeg vil tage mig af registreringen.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "Jeg håber, at der vil være en anden mulighed\n"
	.string "for at danne et forbund.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Jeg er SKOLEBARN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
.string "En {STR_VAR_1}-brugende {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "og en {STR_VAR_1}-bruger\n"
	.string "{STR_VAR_2} er mit POKéMON-par.\p"
	.string "Må jeg være din partner i et tagteam?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Åh, tak! Jeg vil registrere mig i skranken\n"
	.string "med det samme!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Må jeg være med næste gang? Må jeg være med\n"
	.string "næste gang?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Hej! Jeg hedder {STR_VAR_1}! Jeg er en\n"
	.string "POKéMON-OPDRÆTTER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "De POKéMON, jeg har opdrættet, er en\n"
	.string "{STR_VAR_1}-brugende\l"
	.string "{STR_VAR_2} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "en {STR_VAR_1}-brugende\n"
	.string "{STR_VAR_2}.\p"
	.string "Lyder det spændende? Hvad siger du til at\n"
	.string "danne et tagteam, så?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Okaydukke! Du lader registreringen til mig!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Du skal slå dig sammen med mig næstetid,\n"
	.string "okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Jeg er {STR_VAR_1}, og jeg er stolt af at\n"
	.string "sige at jeg er en POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "De søde POKéMON, jeg har opdrættet, er en\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}.\p"
	.string "Er de ikke bare de sødeste? Vi burde danne\n"
	.string "et hold!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Tak, søde! Jeg vil nu gå videre for at\n"
	.string "registrere!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "Mine elskede POKéMON er de bedste, det vil\n"
	.string "jeg have dig til at vide. Hvor irriterende!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hej, jeg er SVØMMER {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "En {STR_VAR_1}-brugende\n"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "og en {STR_VAR_1}-brugende\n"
	.string "{STR_VAR_2} er hvad jeg har trænet.\p"
	.string "Du og jeg, lad os danne et hold.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "Det er fedt! Jeg vil registrere os begge.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Hvis vi mødes igen, skylder du mig en\n"
	.string "holdkamp!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Hvad sker der? Jeg er {STR_VAR_1}, og\n"
	.string "jeg er en TRIATLET.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "Jeg har et par okay POKéMON. En\n"
	.string "{STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Det ville være sjovt hvis vi dannede et hold\n"
	.string "sammen, så hvad siger du?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Helt rigtig! Du venter, mens jeg\n"
	.string "registrerer, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Jeg forventer, at du lader mig være med\n"
	.string "næste gang, er det en deal?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Jeg er TRIATLETTEN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
.string "Én {STR_VAR_2} med {STR_VAR_1} og$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "en anden {STR_VAR_2}, som ved hvordan\n"
	.string "man bruger {STR_VAR_1}. Det er min\l"
	.string "partner. Hvad synes du? Vi ville være et godt\l"
	.string "hold, vil jeg sige.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "Jeg kan godt lide det svar! Jeg bliver færdig\n"
	.string "med registrering hurtigt!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Vil du give mig enchance til at danne et\n"
	.string "partnerskabmed dig?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Hej med dig! Halløj! Jeg er {STR_VAR_1},\n"
	.string "og jeg er en SVØMMER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Se, hvad jeg har opdrættet! En\n"
	.string "{STR_VAR_2} med {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "En {STR_VAR_2} med {STR_VAR_1}!\p"
	.string "Sødt, ikke? Det ville være sødt at danne et\n"
	.string "hold også!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Tusind tak! Jeg sørger for at få denne\n"
	.string "registrering ting klaret!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Hvis vi mødes igen, bliver du så med i mit hold?\n"
	.string "Du vil gøre det, ikke? $"



