@ TRANSLATED

.set LOCALID_ATTENDANT, 1
.set LOCALID_HINT_GIVER, 2

BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "Hvor modet hos TRÆNERE bliver sat på prøve!\p"
	.string "Velkommen til KAMPPIRAMIDEN!\p"
	.string "Jeg er din guide til Kampmissionen.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "Har du modet til at påtage dig Battle Quest\n"
	.string "udfordringen?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "Vi venter spændt på din udfordring i\n"
	.string "fremtiden!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "Kamp Quest er en kampbegivenhed, hvor du\n"
	.string "skal udforske PYRAMIDEN og forsøge at nå\l"
	.string "toppen.\p"
	.string "I PYRAMIDEN er der syv etager med\n"
	.string "labyrinter, alle fyldt med dygtige TRÆNERE\l"
	.string "samt vilde POKéMON.\p"
	.string "Du skal gå ind med tre POKéMONs, ingen af dem\n"
	.string "holder en genstand.\p"
	.string "På din opstigning vil du få en KAMPRYGSÆK til\n"
	.string "genstande.\p"
	.string "Hvis du mislykkes i din udfordring,\n"
	.string "forsvinder alle genstande i\l"
	.string "KAMPRYGSÆKKEN.\p"
	.string "Hvis du ønsker at afbryde din udfordring,\n"
	.string "skal du vælge “HVILE” og gemme spillet.\p"
	.string "Hvis du ikke gemmer inden afbrydelse, vil du\n"
	.string "blive diskvalificeret.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "PYRAMIDEN tilbyder to kurser, Niveau 50 og\n"
	.string "Åben Niveau. Hvilket vil du vælge?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Rigtig godt. Vælg nu de tre POKéMON, som du\n"
	.string "gerne vil have med dig.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Et lille problem, eventyrer!\p"
	.string "Du ser ud til ikke at have de tre POKéMON, der\n"
	.string "er kvalificeret til udfordringen.\p"
	.string "Husk også at fjerne alle genstande fra dine\n"
	.string "POKéMON.\p"
	.string "ÆG{STR_VAR_1} er ikke kvalificeretil\n"
	.string "deltagelse.\p"
	.string "Når du er klar, så tal venligst med mig.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "Et lille problem, eventyrer!\p"
	.string "Du ser ud til ikke at have de tre POKéMON, der\n"
	.string "er kvalificeret til udfordringen.\p"
	.string "De tre POKéMON skal være forskellige og\n"
	.string "hver især højst niveau 50.\p"
	.string "Husk også at fjerne alle genstande fra dine\n"
	.string "POKéMON.\p"
	.string "ÆG{STR_VAR_1} er ugyldige.\p"
	.string "Når du er klar, så snak med mig.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Inden du går ind i KAMP-PYRAMIDEN, skal\n"
	.string "spillet gemmes. Er det okay?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Meget godt. Jeg vil nu vise dig ind i\n"
	.string "KAMP-PIRAMIDEN.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "Vi passer på din RYGSÆK mens du udforsker,\n"
	.string "{PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "Til gengæld, tag KAMPRYGSÆKKEN som du\n"
	.string "brugte tidligere.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "Som tak, tag venligst denne KAMPRYGSÆK.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} byttede RYGSÆKKEN ud med\n"
	.string "KAMPRYGSÆKKEN.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Når du træder på dette gulvpanel, vil du\n"
	.string "blive transporteret til et højere etage i\l"
	.string "PYRAMIDEN.\p"
	.string "Jeg håber for din skyld, at din mission går\n"
	.string "godt!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "Et stort problem, opdagelsesrejsende!\p"
	.string "Du gemte ikke, før du afsluttede din\n"
	.string "udfordring sidste gang.\p"
	.string "Som følge heraf er din udfordring blevet\n"
	.string "diskvalificeret, må jeg sige.\p"
	.string "Her er POSER vi har holdt for dig.\p"
	.string "{PLAYER} fik POSERNE tilbage.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "Dejligt at se dig tilbage!\p"
	.string "Du har erobret PYRAMIDEN! Hvor skønt!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "Åh, et lille problem.\p"
	.string "Mindst én POKéMON holder en genstand.\p"
	.string "Jeg beklager at sige, genstande obtained i\n"
	.string "PYRAMIDEN kan ikke fjernes.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Alle genstande holdt af din POKéMON vil\n"
	.string "blive flyttet til din KAMPRYGSÆK,\l"
	.string "{PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "KAMPRYGSÆKKEN har ikke plads alle dine\n"
	.string "genstande, det må jeg desværre sige.\p"
	.string "Vælg venligst de genstande, du vil gemme i\n"
	.string "KAMPRYGSÆKKEN, og med dine POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Mindst én POKéMON har stadig en genstand.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Vælg venligst de ting, du vil opbevare i\n"
	.string "KAMPRYGSÆKKEN sammen med dine POKéMON.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} returnerede alt, hvad\n"
	.string "POKéMONene holdt.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "KAMPRYGSÆKKEN, du brugte, vil blive gemt\n"
	.string "klar til din næste udfordring.\p"
	.string "{PLAYER} vendte KAMPRYGSÆKKEN for at\n"
	.string "få rygsækken tilbage.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "Jeg skal registrere dine resultater. Vent\n"
	.string "venligst.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "Som et minde for at erobre\n"
	.string "BATTLE PYRAMID, tag venligst dette.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} modtog præmien\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "…Åh…\n"
	.string "Din RYGSÆK ser ud til at være fuld.\p"
	.string "Kom venligst tilbage, når du har fået\n"
	.string "organiseret indholdet i din RYGSÆK.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Hvor skuffende for dig…\p"
	.string "Her er RYGSÆKKEN, vi har holdt på til dig.\p"
	.string "{PLAYER} fik RYGSÆKKEN tilbage.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "Vi glæder os til din næste udfordring!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "Vi har glædet os til, \nat du kom!\p"
	.string "Her er din præmie for at erobre \nPYRAMIDEN.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Velkommen…\p"
	.string "Jeg vil med glæde fortælle dig, hvad der af\n"
	.string "uheld venter i PYRAMIDEN…$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "… … … … … … … … … … … …\p"
	.string "… … … … … … Aah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Jeg ser en bruser af gnister…\p"
	.string "…Og i den ser jeg din POKéMON kæmpe med\n"
	.string "lammelse…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Jeg ser gift…\p"
	.string "…Og jeg ser dine POKéMON lide under\n"
	.string "virkningerne af gift…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Jeg ser lyse røde flammer…\p"
	.string "…Og jeg ser din POKéMON lide af\n"
	.string "forbrændinger…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Jeg fornemmer det enorme pres af ubevaret\n"
	.string "vrede... \p"
	.string "Det er en forbandelse... \p"
	.string "...Og jeg ser dine POKéMON tømt for Power\n"
	.string "Points og uden nogen mulighed for at gøre\l"
	.string "andet end at kæmpe...$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Jeg ser POKéMON svæve højt…\p"
	.string "…Og, jeg ser dit POKéMON frustreret af\n"
	.string "magtesløse JORD-typer bevægelser…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Jeg mærker en fantastisk energi stige op\n"
	.string "fra jorden under os…\p"
	.string "...Og jeg ser dine POKéMON ikke kan\n"
	.string "undslippe kraftens greb…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Jeg ser IS-type POKéMON…\p"
	.string "…Og jeg ser dine POKéMON kæmper mod isens\n"
	.string "frysende effekter…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Jeg ser en storm af bevægelser, der truer\n"
	.string "brugeren…\p"
	.string "…Og, jeg ser din POKéMON falde til dem…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Jeg ser PSYCHIC-type POKéMON…\p"
	.string "…Og jeg ser dine POKéMON i lidelse fra\n"
	.string "PSYCHIC-moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Jeg ser ROCK-type POKéMON…\p"
	.string "…Og jeg ser, at dine POKéMON lider af ROCK\n"
	.string "moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Jeg ser KAMP-type POKéMON…\p"
	.string "…Og jeg ser dit POKéMON blive banket af\n"
	.string "KAMP-moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "REGNDANS… SOLSKINSDAG… SANDESTORM…\n"
	.string "SNEFYG…\p"
	.string "Jeg ser POKéMON, der bliver stærkere med\n"
	.string "vejret…\p"
	.string "…Og jeg ser dine POKéMON forvirret af\n"
	.string "forskellige typer af angreb…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Jeg ser INSEKT-type POKéMON…\p"
	.string "…Og jeg ser din POKéMON lide under\n"
	.string "forskellige former for angreb…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Jeg ser MØRKE-type POKéMON…\p"
	.string "…Og jeg ser dit POKéMON lide fra MØRKE-type\n"
	.string "angreb…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Jeg ser VAND-type POKéMON…\p"
	.string "…Og jeg ser dit POKéMON lide af VAND-type\n"
	.string "angreb…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Jeg ser GHOST-type POKéMON…\p"
	.string "…Og jeg ser din POKéMON lide under\n"
	.string "GHOST-type angreb…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Jeg ser STÅL-typen POKéMON...\p"
	.string "...Og jeg ser din POKéMON lide under enormt\n"
	.string "kraftfulde angreb...$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Jeg ser flyvende POKéMON…\p"
	.string "…Og, jeg ser dit POKéMON lide under enormt\n"
	.string "kraftfulde angreb…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Jeg ser dem, der har udviklet sig fra kraften\n"
	.string "fra sten…\p"
	.string "Jeg fornemmer også ild, vand, og\n"
	.string "elektricitet…\p"
	.string "…Og jeg ser dine POKéMON lide under disse\n"
	.string "tre kræfter…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Jeg ser NORMAL-type POKéMON…\p"
	.string "…Og jeg ser dit POKéMON lide under enormt\n"
	.string "kraftfulde angreb…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Uanset om du tror på mine forudsigelser\n"
	.string "eller ej, valget er dit…\p"
	.string "Fremtiden kan ændres når som helst… Jeg\n"
	.string "ønsker dig en sikker rejse…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "Vidste du det?\p"
	.string "Hvis du løber hurtigt, kan TRÆNERE bemærke\n"
	.string "det og konfrontere dig til en kamp.\p"
	.string "Så hvis du vil undgå TRÆNERE, så fang ikke\n"
	.string "deres blik, men snig diskret og stille forbi\l"
	.string "dem.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "Åååååååååh!\p"
	.string "Jeg havde en hel masse ting, men jeg mistede\n"
	.string "dem alle, da jeg tabte!\p"
	.string "Åååååååååh!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "Velkommen tilbage! Du har gjort det\n"
	.string "utænkelige!\p"
	.string "Du har besejret PYRAMIDEKONGEN og\n"
	.string "erobret KAMP-PYRAMIDEN!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "Ung udforsker! Som belønning for din\n"
	.string "tapperhed, giver vi dig disse Kamp\l"
	.string "Point(er)!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
.string "Reglerne for Battle Quest er angivet.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "Hvilken overskrift vil du læse?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Når PYRAMIDEN er erobret, er de vilde\n"
	.string "POKéMON, der vises i den er erstattet af\l"
	.string "forskellige typer.\p"
	.string "Udforsk, iagttage, og lær hvilke typer af\n"
	.string "vilde POKéMON du kan møde.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "TRÆNERE ligger på lur efter dig i PYRAMIDEN.\p"
	.string "På hver etage er der op til otte TRÆNERE.\p"
	.string "Når du besejrer en TRÆNER, vil du få et\n"
	.string "nyttigt tip til dit eventyr.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Mazerne i PYRAMIDEN omarrangerer sig hver\n"
	.string "gang du går ind i den.\p"
	.string "Mazerne er dårligt oplyste. Du skal\n"
	.string "fortsætte forsigtigt.\p"
	.string "Lyset bliver stærkere hver gang du\n"
	.string "besejrer en vild POKéMON eller en TRÆNER.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "BATTLE BAG'en fungerer som din RYGSÆK\n"
	.string "mens du er i PYRAMIDEN.\p"
	.string "Der er to separate BATTLE BAGS-- en til\n"
	.string "hvert Level 50 og Åbent Level eventyr.\p"
	.string "De kan hver indeholde op til 99 stykker af ti\n"
	.string "forskellige typer genstande.\p"
	.string "Indholdet af BATTLE BAG'en går tabt, hvis\n"
	.string "du mislykkes i din quest.$"



