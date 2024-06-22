@ TRANSLATED

.set LOCALID_ATTENDANT, 1
.set LOCALID_NURSE, 2
.set LOCALID_GIRL, 4
.set LOCALID_MAN, 5

TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_NURSE
	addobject LOCALID_ATTENDANT
	addobject LOCALID_MAN
	addobject LOCALID_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Dette er TRÆNERBAKKEN hvor du kan nyde\n"
	.string "tag-kampe med mange TRÆNERE.\p"
	.string "Desværre er vi stadig i gang med at klargøre\n"
	.string "tingene. Kom venligst tilbage senere!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Velkommen!\p"
	.string "Dette er TRÆNERBAKKEN hvor du kan nyde\n"
	.string "tag-kampe med mange TRÆNERE!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "Er dette dit første besøg her?\p"
	.string "Inden du går ind, bedes du gemme dit spil.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Lad os se... TRÆNERNE her nu er...\p"
	.string "Op til etage nr. {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Lad os se… TRÆNERNE her nu er…\p"
	.string "Der ser ud til at være TRÆNERE samlet i hvert\n"
	.string "rum.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Vil du udfordre de ventende TRÆNERE?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Jeg vil tage tiden på din fremgang. held og\n"
	.string "lykke!\p"
	.string "På dinemærker…\p"
	.string "Klar…\p"
	.string "Go!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Besøg os gerne igen!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Det var for dårligt.\p"
	.string "Jeg synes, at du gjorde en kæmpe indsats i\n"
	.string "dine kampe.\p"
	.string "Kom tilbage og prøv igen!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Jeg håber, at du gør dit bedste.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Når TRÆNERNE skifter plads, kan\n"
	.string "bevægelsen blive hektisk.\p"
	.string "For at undgå trængslen flyttede vi\n"
	.string "receptionsskranken herhen.\p"
	.string "Undskyld besværet.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Tak for at spille!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Her på TRÆNERBJERGET afholder vi et\n"
	.string "arrangement kaldet Tidsangreb.\p"
	.string "Det er et løb, der måler, hvor lang tid det\n"
	.string "tager dig at nå vores ejer på taget fra\l"
	.string "denne tæller.\p"
	.string "De hurtigste tider bliver posted på\n"
	.string "Tidstavlen--prøv at konkurrere med dine\l"
	.string "venner.\p"
	.string "I TRÆNER-kampe på vejen vil hverken\n"
	.string "Erfaringspoint eller penge blive tildelt.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Åh, undskyld, men du ser ud til kun at have\n"
	.string "én POKéMON med dig.\p"
	.string "Du skal have mindst to POKéMON\n"
	.string "for at deltage i dette eventyr.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hm! Hm!\p"
	.string "Du kom endelig! Ja, du er ankommet!\p"
	.string "Vent! Sig det ikke! Jeg ved hvorfor du kom\n"
	.string "hele vejen herhen alene!\p"
	.string "Du ville se mig, ejeren af TRÆNERBJERGET,\n"
	.string "fordi…\p"
	.string "Du vil danne et tagteam med mig! Wa-hoo!\p"
	.string "…Øh? Det er det ikke?\p"
	.string "Uanset, jeg fulgte dig på vejen op.\n"
	.string "Fantastisk kamp! Bravo, virkelig!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "For en fantastisk person som dig, har jeg\n"
	.string "den mest fantastiske gave!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Åh nej, fyldt op med ting! Du kommer tilbage\n"
	.string "senere for dette!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Åh, vent lige her! Kom du muligvis her hen\n"
	.string "forrygende hurtigt?\p"
	.string "Hvor skønt! Du behøvede ikke at skynde dig\n"
	.string "sådan for at se mig!\p"
	.string "Det er så dejligt. Jeg vil få Tids- tavlen i\n"
	.string "receptionen opdateret!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Men, åh... Du var ikke særlig hurtig til at\n"
	.string "komme herhen.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Måske ville det glæde mig mere, hvis du kom\n"
	.string "lidt hurtigere næste gang.\p"
	.string "Derefter vil jeg med glæde danne et\n"
	.string "makkerpar med dig!\p"
	.string "Indtil vi mødes igen, kammerat!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "Jeg ließ TRAINERHILL bauen aus\n"
	.string "einem einzigen Grund!\p"
	.string "Um den passenden Partner zu finden,\n"
	.string "mit dem ich ein starkes Team bilden kann!$"

TrainerHill_Entrance_Text_ChallengeTime:
.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sek.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Hvem ved, hvilke slags TRÆNERE og\n"
	.string "POKéMON-komboer, der venter?\p"
	.string "Alt jeg ved er, at jeg vil skubbe enhver til\n"
	.string "side, der står i min vej!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "Jeg har hørt, at seje TRÆNERE kommer til\n"
	.string "denne TRÆNERRIDGE fra alle mulige steder.\p"
	.string "Jeg kan ikke vente med at prøve det af!\p"
	.string "Jeg vil skubbe alle til side, som står i min\n"
	.string "vej!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Ser du Tavlen med Tiden derovre?\p"
	.string "Mine venner og jeg prøver at se, hvem der kan\n"
	.string "nå toppe i mindst tid.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Ved du, hvornår de åbner dette sted? \p"
	.string "Jeg venter her for at være den  allerførste\n"
	.string "udfordrer nogensinde!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Vil du gerne vende tilbage til receptionen?$"



