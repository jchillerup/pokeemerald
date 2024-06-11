@ TRANSLATED

.set LOCALID_TRICK_MASTER, 1

Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
	return

Route110_TrickHouseEnd_EventScript_TrickMaster::
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM_TAUNT
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_ChooseTent
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent

Route110_TrickHouseEnd_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExit::
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_NoRoomForTent::
	call Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	waitmovement 0
	delay 4
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe:
	.string "Åh!\n"
	.string "Du har fundet vej til mig?\p"
	.string "Hmm... Du er skarp!$"

Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
	.string "Det tog mig hele natten at plante alle\n"
	.string "disse træer…\p"
	.string "Du er næsten min lige i storhed med\n"
	.string "et, to, tre, fire, fem, seks steder!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
	.string "Det tog mig hele natten at lave labyrinten...\p"
	.string "Du er næsten min ligeværdige i storhed på\n"
	.string "én, to, tre, fire, fem pladser!$"

Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
	.string "Det tog mig hele natten at forberede\n"
	.string "vægpanelerne...\p"
	.string "Du er næsten min ligemand i storhed på\n"
	.string "én, to, tre, fire pladser!$"

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
	.string "Det tog mig hele natten at skubbe de\n"
	.string "sten…\p"
	.string "Du er næsten min ligemand i storhed i\n"
	.string "én, to, tre områder!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.string "Det tog mig hele natten at lave MECHADOLLS\n"
	.string "og en anden til at tænke på quizzen…\p"
	.string "Du er næsten min ligemand, kun med en,\n"
	.string "to pladser!$"

Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
	.string "Det tog mig hele natten at installere\n"
	.string "dørene... \p"
	.string "Du er næsten min lige i storhed!$"

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
	.string "Det tog mig hele natten at sætte pile op…\p"
	.string "Du er min ligemand i storhed!$"

Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
	.string "Det tog mig hele natten at polere gulve…\p"
	.string "Du er højere i storhed end mig!\n"
	.string "Måske…$"

Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.string "Hvad skal jeg gøre?\n"
	.string "Mit springvand af ideer til tricks er\l"
	.string "tørlagt…\p"
	.string "Måske er det på tide, at jeg tager\n"
	.string "på tur i landet for at udtænke nye\n"
	.string "tricks…$"

Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
	.string "Jeg hader at indrømme nederlag, men\n"
	.string "du har overgået mig!\p"
	.string "Alligevel må du have været tiltrukket\n"
	.string "af min karisma, for at du besøger mig\n"
	.string "igen og igen. Ja, det må du!\p"
	.string "Men det har intet at gøre med mit\n"
	.string "tab!\p"
	.string "Som anerkendelse af venskabet\n"
	.string "mellem dig, den driftige, og geniet\l"
	.string "som jeg, kræver jeg, at du tager\l"
	.string "dette minde!\p"
	.string "Faktisk er der to--\n"
	.string "en RØD TELT og et BLÅT TELT.\l"
	.string "Hvilken foretrækker du?$"

Route110_TrickHouseEnd_Text_NoRoomInPC:
	.string "Hvad? Ingen plads på din PC?\n"
	.string "Hvad skal jeg dog gøre ved det?\p"
	.string "Jeg ville ønske, at jeg kunne sige det,\n"
	.string "men jeg er alt for venlig og omsorgsfuld,\nså kom tilbage senere!$"

Route110_TrickHouseEnd_Text_LeavingOnJourney:
	.string "… … … … … …\p"
	.string "Jeg drager ud på opdagelsesrejse.\n"
	.string "En mission for at finde nye tricks.\p"
	.string "Jeg håber, at du en dag vil besøge og\n"
	.string "underholde mig igen.\p"
	.string "Og nu, farvel!$"

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.string "Fint!\n"
	.string "Du har fortjent denne belønning!$"

Route110_TrickHouseEnd_Text_NoRoomForThis:
	.string "Hvad? Har du ikke plads til dette?\n"
	.string "Hvilken slags ting bærer du på?\p"
	.string "Men fint, når du har nået mig,\n"
	.string "vil din belønning være hos mig indtil senere.$"

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.string "Skru den der selvtilfredse mine af dit ansigt!\n"
	.string "Det er alt for tidligt at tro, at du har vundet!\p"
	.string "Jeg vil finde på nye tricks for at forvirre dig, det vil jeg.\n"
	.string "Du kan bare gøre nar af mig, når du er færdig.\p"
	.string "Kom tilbage til den næste spændende\n"
	.string "episode!$"

Route110_TrickHouseEnd_Text_YoureIgnoringMe:
	.string "Nu, nu! Ignorerer du mig nu?\n"
	.string "Det synes jeg er hjerteskærende!$"



