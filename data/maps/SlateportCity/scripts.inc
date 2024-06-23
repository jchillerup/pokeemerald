@ TRANSLATED

.set LOCALID_FAT_MAN, 1
.set LOCALID_MAN_1, 2
.set LOCALID_RICH_BOY, 3
.set LOCALID_GRUNT_1, 5
.set LOCALID_COOK, 6
.set LOCALID_OLD_WOMAN, 7
.set LOCALID_GIRL, 8
.set LOCALID_TY, 9
.set LOCALID_GABBY, 10
.set LOCALID_CAPT_STERN, 11
.set LOCALID_GRUNT_2, 18
.set LOCALID_GRUNT_3, 19
.set LOCALID_GRUNT_4, 26
.set LOCALID_GRUNT_5, 27
.set LOCALID_GRUNT_6, 28
.set LOCALID_GRUNT_7, 29
.set LOCALID_GRUNT_8, 30
.set LOCALID_GRUNT_9, 31
.set LOCALID_GRUNT_11, 33
.set LOCALID_SCOTT, 35

@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_COOK, 27, 16
	setobjectxyperm LOCALID_GIRL, 28, 16
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_MAN_1, 31, 14
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	setobjectxyperm LOCALID_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_NONE
	release
	end

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_GABBY
	removeobject LOCALID_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Jeg er ENERGIGUIDEN! Jeg går all in  og\n"
	.string "sælger dig, hvad du har brug for!$"

SlateportCity_Text_OhYourPokemon:
	.string "Åh? Din {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Gik efter det fantastisk!\p"
	.string "Som belønning, giv den dette INDSATS\n"
	.string "BÅND.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} modtog INDSATS BÅND.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} sætter ANSTRENGELSES BÅND\n"
	.string "på {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Du skal gå lidt hårdere til den.\p"
	.string "Hvis du gør det, vil jeg give din POKéMON\n"
	.string "noget lækkert.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Åh! Din {STR_VAR_1}, det\n"
	.string "ANSTRÆNGELSEN SLØJFE ser godt ud på\l"
	.string "det!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "Lyset fra fyret når dusinvis af miles\n"
	.string "væk.\p"
	.string "Jeg undrer mig over, om det ikke\n"
	.string "skræmmer POKéMON i havet.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Åh, se lige her!\p"
	.string "Tang, som du kan finde heromkring, er\n"
	.string "frisk og fuld af liv.\p"
	.string "Det ser endda ud til, at det kan rejse\n"
	.string "sig og angribe!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Hvor vandet er rent, samles frugterne\n"
	.string "af en rig høst.\p"
	.string "Og hvor folk samles, starter et marked\n"
	.string "hurtigt.\p"
	.string "Sådan bliver en by født og vokser.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Shopping, hvor du kan indånde duften af\n"
	.string "havet…\p"
	.string "SLATEPORT er et fantastisk sted!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Hvis du lægger DUKKER eller PUDER på\n"
	.string "gulvet, bliver de beskidte.\p"
	.string "Jeg vil købe nogle MURSTEN, så mine\n"
	.string "DUKKER og PUDER ikke bliver beskidte\l"
	.string "når jeg lader dem ligge ude.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Wraaa! Jeg vil også deltage i\n"
	.string "KAMP-TALTET!\p"
	.string "Men først skal jeg fange nogle POKéMON!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Puha... Jeg er helt færdig...\p"
	.string "Jeg vandrede hele vejen fra MAUVILLE\n"
	.string "CITY. Men hold da op, denne by er\l"
	.string "kæmpestor.\p"
	.string "Hvis jeg havde vidst det, ville jeg have\n"
	.string "taget min CYKEL med.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN, fyren der byggede MUSEET, er\n"
	.string "også lederen af et undervands\l"
	.string "udforskningsteam.\p"
	.string "Så alle kalder ham KAPT. STERN.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Hvad er det derovre? Den lange linje...$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Da jeg var barn, besøgte jeg MUSEET\n"
	.string "ofte.\p"
	.string "Jeg plejede at drømme om mysterierne i\n"
	.string "havet efter at have set udstillingerne.$"

SlateportCity_Text_QuitPushing:
	.string "Hej med dig! Stop med at skubbe! Dette\n"
	.string "er køen, kan du ikke se?$"

SlateportCity_Text_AquaHasPolicy:
	.string "TEAM AQUA har en politik om at samle sig\n"
	.string "og sprede sig på operationsstedet.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Vores CHEF er genial.\p"
	.string "Hvad mon han vil med et MUSEUM nu?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Hvad mon det nye skema er, jegundrer\n"
	.string "mig?\p"
	.string "Vores CHEF er skræmmende, når han\n"
	.string "ervred, så jeg må hellere ikke lave rod…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Hvis der er noget vi har brug for i\n"
	.string "MUSEET, så lad os tage det hele!$"

SlateportCity_Text_DontButtIn:
	.string "Hej, du der! Bland dig ikke!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "En lang kø, hva’?\p"
	.string "Det minder mig om de gange, hvor jeg\n"
	.string "stod i kø for at købe top-spil…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Hvorfor står vi overhovedet i kø og\n"
	.string "betaler? Vi burde bare marchere ind!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Hvad? Hvad vil du have?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Vil du læse dette skilt? Jeg vil læse det\n"
	.string "for dig!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Lad os se…\p"
	.string "Øh... Jeg tror, det siger noget i retning\n"
	.string "af “livet i havet er uendeligt.”\p"
	.string "Ja, jeg er ret sikker på, det er det, der\n"
	.string "står.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Mumble…\p"
	.string "Jeg skulle have taget min Game Boy\n"
	.string "Advance med, så jeg ikke kede mig i\l"
	.string "køen…\p"
	.string "Mumble…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Når denne operation er ovre, vil jeg\n"
	.string "tage dig med til et varmt kildespa!\p"
	.string "Det er hvad vores leder sagde. Jeg kan\n"
	.string "ikke vente!$"

SlateportCity_Text_SeaIsSoWet:
	.string "Havet er bare så stort…\p"
	.string "Mon havet er blevet skabt af tårerne,\n"
	.string "som POKéMON har grædt?$"

SlateportCity_Text_SinkOldBoats:
	.string "Ved du, hvad de gør med gamle skibe, der\n"
	.string "bliver for skrøbelige til at sejle?\p"
	.string "De synker dem i havet, så de bliver\n"
	.string "levesteder for POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Hver gang jeg besøger dette sted,\n"
	.string "bliver jeg revet med og køber for meget.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Hvis du vil ændre dit POKéMON's\n"
	.string "kaldenavn, bliver du nødt til at få\l"
	.string "NAVNEBEDØMMEREN til at hjælpe dig.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Enhver POKéMON, du får i en handel, kan\n"
	.string "du ikke ændre kaldenavn på.\p"
	.string "Den oprindelige TRÆNER's kærlighed til\n"
	.string "den POKéMON er i kaldenavnet.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "For nylig blev en KAMP-TELT bygget i\n"
	.string "SLATEPORT.\p"
	.string "GYM'ER er sjove, men KAMP-TELTET er\n"
	.string "fantastisk på sin egen måde.\p"
	.string "Du burde finde stærke POKéMON til\n"
	.string "KAMP-TELTET!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Jeg håbede, at det var en berømt\n"
	.string "stjerne så jeg kunne få en autograf.\p"
	.string "Men hvem bliver der interviewet? Er det\n"
	.string "ikke KAPT. STERN?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Den dame-interviewer er så sej og smuk.\p"
	.string "Når jeg bliver stor, vil jeg være en\n"
	.string "international journalist!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "Kaptajn STERN siger, at de har opdaget\n"
	.string "noget på havets bund.\p"
	.string "Jeg undrer mig over, hvad det mon er?\n"
	.string "Hvad mon det kan være?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Hvad sker der her?\p"
	.string "Kom den gode KAPTAIN tilbage med en\n"
	.string "stor fisk fra havets bund?$"

SlateportCity_Text_AmIOnTV:
	.string "Hej! Ser du med? Er jeg på tv?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Et TV-interview! Her! KAPTAINEN er en\n"
	.string "superstjerne!$"

SlateportCity_Text_BigSmileForCamera:
	.string "Okay, KAPT. STERN, et stort smil til\n"
	.string "kameraet!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABBY: Jeg ser, jeg ser. Du har haft en\n"
	.string "uvurderlig oplevelse...$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "Kaptajn Stern: Ja, bestemt. Vi har\n"
	.string "tænkt os at fortsætte med vores\l"
	.string "udforskning.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABBY: Det er fantastisk, KAPT. STERN!\n"
	.string "Tak fordi du fandt tid i din travle\l"
	.string "hverdag til at tale med os.\p"
	.string "Vi håber, vi kan intervjue dig igen med\n"
	.string "nyheder om flere opdagelser!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "KAPT. STERN: Puha... \p"
	.string "Det var første gang, jeg blev filmet til\n"
	.string "TV. Det fik mine nerver til at stå på\l"
	.string "højkant.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Åh! {PLAYER}{KUN}! Du ser godt ud!\p"
	.string "Vi har gjort et kæmpe fund under vores\n"
	.string "seneste undersøgelse af havbunden.\p"
	.string "Vi fandt en undersøisk hule på ROUTE\n"
	.string "128.\p"
	.string "Vi tror, det er levestedet for en\n"
	.string "POKéMON, som menes at have været længe\l"
	.string "uddød.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Hihihi… KAPT. STERN, formoder jeg.\p"
	.string "Vi fra TEAM AQUA vil overtage\n"
	.string "kontrollen over din ubåd!\p"
	.string "Dine indvendinger er meningsløse! Vi\n"
	.string "forventer din totale samarbejde!\p"
	.string "Hihihi… Bare se og lær hvad TEAM AQUA\n"
	.string "har planlagt!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "KAPT. STERN: Hvad var det hele det der\n"
	.string "med?\p"
	.string "Det lød som om nogen brugte en\n"
	.string "megafon...\p"
	.string "Hvor kom det fra?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Det er fra HAVNEN!\p"
	.string "Den undervandsbåd! De prøver at tage\n"
	.string "den!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}! Kom med mig, vær så venlig!$"

SlateportCity_Text_BattleTentSign:
	.string "KAMPTALT - SLATEPORT-OMRÅDET “Find\n"
	.string "den! Den ultimative POKéMON!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "STERN'S SKIBSVÆRFT\p"
	.string "“Eftersøges: En sømand i stand til at\n"
	.string "sejle i alle strømme.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "STERN'S VÆRFT\p"
	.string "“Færgen S.S. TIDAL nærmer sig\n"
	.string "fuldførelse, så den kan betjene havnene\l"
	.string "i SLATEPORT og LILYCOVE.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "STERN'S SKIBSVÆRFT\p"
	.string "“Ombordstigning på færgen\n"
	.string "SLATEPORT-LILYCOVE, S.S. TIDAL, sker\l"
	.string "ved HAVNEN.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "POKéMON FAN CLUB “Kald alle fans af\n"
	.string "POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“Det uendelige hav sustains all life.”\p"
	.string "HAVMUSEET $"

SlateportCity_Text_CitySign:
	.string "SLATEPORT CITY\p"
	.string "“Havnen, hvor folk og POKéMON mødes.”$"

SlateportCity_Text_MarketSign:
	.string "SLATEPORT MARKED “Unikke varer, som\n"
	.string "ikke findes andre steder!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "SLATEPORT HAVN\p"
	.string "“Færgen S.S. TIDAL er under\n"
	.string "konstruktion på VÆRFTET.\p"
	.string "“Servicen forventes at begynde snart.”$"

SlateportCity_Text_HarborSign:
	.string "SLATEPORT HAVN\p"
	.string "“Tag med på en behagelig sejltur med\n"
	.string "færgen S.S. TIDAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "Navnegiverens Hus “POKéMON kælenavne\n"
	.string "vurderes.”$"

SlateportCity_Text_ExplainBerries:
	.string "Hvis en vild POKéMON bliver såret,\n"
	.string "helbreder den sig selv ved at tygge på\l"
	.string "BÆR.\p"
	.string "Vidste du det?\p"
	.string "Nogen så det og fik ideen til at lave\n"
	.string "medicin af BÆR.\p"
	.string "Vidste du det?\p"
	.string "For at omdanne BÆR til medicin, skal de\n"
	.string "knuses til pulver.\p"
	.string "Vidste du det?\p"
	.string "Du virker interesseret i BÆR!\p"
	.string "Jeg har noget godt til en person som\n"
	.string "dig.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Jeg har for nylig fået maskiner\n"
	.string "installeret på POKéMON CENTERS til at\l"
	.string "knuse BÆR.\p"
	.string "BÆRKNUSEmaskinen er ovenpå i DIREKTE\n"
	.string "HJØRNE.\p"
	.string "Vidste du det?\p"
	.string "Kunne du lave BÆRPULVER for mig ved\n"
	.string "hjælp af disse maskiner?\p"
	.string "Jeg kan lave alle slags medicin til dig,\n"
	.string "hvis du bringer mig masser af BÆRPULVER.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Har du bragt mig lidt BÆRPOULVER?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Hvad vil du gerne bytte det med?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Okay, vil du bytte din BERRY POWDER med\n"
	.string "én {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "BÆRPOD$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Det er fint med BÆRPULVER. Det vil gøre\n"
	.string "fremragende medicin.\p"
	.string "Vil du gerne bytte mere af din\n"
	.string "BÆRPULVER med noget andet?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Okay! Når du får lidt mere BÆRPULVER, så\n"
	.string "bring det til mig, tak!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Kom tilbage, hvis du vil bytte din\n"
	.string "BÆR-pulver til noget medicin.\p"
	.string "Jeg holder altid marked her.\p"
	.string "Vidste du det?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: Hov? Jeg er sikker på, at jeg har\n"
	.string "mødt dig et sted før.\p"
	.string "Har jeg præsenteret mig for dig? Hvis\n"
	.string "ikke, er mit navn SCOTT.\p"
	.string "Jeg så lige TEAM AQUA løbe væk herfra\n"
	.string "som om de var blevet stukket.\p"
	.string "Skal jeg gætte--du fik dem til at løbe\n"
	.string "væk?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "Hmm… Måske, bare måske, denne TRÆNER…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: Okay! Jeg tror, du bliver en god\n"
	.string "ven.\p"
	.string "Så lad os registrere hinanden i vores\n"
	.string "POKéNAVS.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Registrerede denne SCOTT-person i\n"
	.string "POKéNAV'en.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: Det jeg gerne vil, er at følge\n"
	.string "med dig, men jeg vil også gerne holde et\l"
	.string "øje med andres talenter.\p"
	.string "Så jeg smutter afsted for at udforske\n"
	.string "andre byer lidt mere.\p"
	.string "Vi ses, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: Hej! Hvis det ikke er {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, lad mig gætte-- du er her\n"
	.string "for at tage KAMP-TENTEN udfordringen?\p"
	.string "Ja! Det er en god idé! Det er en virkelig\n"
	.string "god idé!\p"
	.string "For en sej TRÆNER er den perfekte\n"
	.string "match til KAMP-TENTEN!\p"
	.string "Giv det dit bedste forsøg!$"



