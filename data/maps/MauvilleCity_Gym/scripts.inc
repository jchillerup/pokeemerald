@ TRANSLATED

MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Hey, hvordan går det, CHAMPION- klarede\n"
	.string "{PLAYER} sig godt?\p"
	.string "WATTSON, lederen af MAUVILLEs GYM,\n"
	.string "bruger ELEKTRISK-type POKéMON.\p"
	.string "Hvis du udfordrer ham med VAND-type\n"
	.string "POKéMON, så vil han zappe dem! Bzzt!\p"
	.string "Og han har installeret switch- styret\n"
	.string "døre overalt i sit GYM! Eksentrisk!\p"
	.string "Hey, gå efter det!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Wow, du er elektrisk! Du har åbnet døren\n"
	.string "med strøm!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Mit elektriske sind, det vil knuse din\n"
	.string "ønskedrøm helt, whoa-yeahah!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "Det var tilsluttet, pumpet op,\n"
	.string "overdreven elektrisk, mand!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "POKéMON og sten, det hele handler om\n"
	.string "hjerte, whoa-yeah!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "Jeg trænede under WATTSON! Der er ingen\n"
	.string "måde jeg let taber!$"

MauvilleCity_Gym_Text_ShawnDefeat:
.string "Slukket og slukket ned…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "WATTSON, vores GYM-LEDER, har været\n"
	.string "her i lang, lang tid.\p"
	.string "Han kæmpede endda før din far blev\n"
	.string "født, den seje skarpe.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "Denne GYM har gåder! Er det ikke sjovt?$"

MauvilleCity_Gym_Text_BenDefeat:
.string "Det er ikke sjovt at tabe...$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "WATTSON siger, at han kan lide at\n"
	.string "opstille små fælder med kontakter.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Med min charme og min POKéMON's moves,\n"
	.string "vil du blive chokeret!$"

MauvilleCity_Gym_Text_VivianDefeat:
.string "Jeg er chokeret over din kraft!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "Jeg har hørt, at MAUVILLE blev\n"
	.string "grundlagt af WATTSON.\p"
	.string "Han var en TRÆNER længe før vi blev\n"
	.string "TRÆNERE. Han må vide alle mulige ting!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "Jeg elsker skinnende ting!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Åh… Mine øjne er helt brændt ud…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "MAUVILLE GYM's WATTSON har en\n"
	.string "skinnende pande. Det gør mig glad!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "Jeg har opgivet mine planer om at om\n"
	.string "danne byen, det har jeg.\p"
	.string "Så jeg bruger nu min tid på at lave\n"
	.string "dør-fælder i min GYM.\p"
	.string "Åh? Hvad laver du her?\p"
	.string "Hvad siger du? Du siger, at du har\n"
	.string "klaret alle mine fældede døre?\p"
	.string "Wahahahah! Det er morsomt!\p"
	.string "Så vil jeg, WATTSON, LEADER af MAUVILLE\n"
	.string "GYM, give dig en elektrisk\p"
	.string "oplevelse!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Wahaha! Okay, jeg tabte!\p"
	.string "Du fik mig virkelig til at spænde op! Her,\n"
	.string "tag denne MÆRKE!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} modtog DYNAMO-BADGEN fra\n"
	.string "WATTSON.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Med DYNAMOBADGEN kan POKéMON bruge\n"
	.string "ROCK SMASH uden for kampen.\p"
	.string "Og det vil også gøre din POKéMON lidt\n"
	.string "hurtigere.\p"
	.string "Hmm… Du burde også tage dette med!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "Den TM34 der indeholder SHOCK WAVE.\p"
	.string "Det er et pålideligt træk, der aldrig\n"
	.string "fejler! Du kan regne med det!\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "Registreret GYM LEDER WATTSON i\n"
	.string "POKéNAV'en.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Jeg svulmer af optimisme ved synet af\n"
	.string "en lovende UDDANNER som dig!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Hahaaha! Fremad, lille ven!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "MAUVILLE CITY POKéMON GYM$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "MAUVILLE CITY POKéMON GYM\p"
	.string "WATTSON'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "WATTSON: Ah-ha! Her kommer du endelig!\n"
	.string "Jeg ved hvad du vil.\p"
	.string "Du vil kæmpe mod mine POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Jeg vil lade gnister flyve fra dig! Sig\n"
	.string "ikke, at jeg ikke advarede dig!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Åh nej… Vores batterier løb tør…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "WATTSON: Vi bliver nødt til at oplade\n"
	.string "vores batterier igen.\p"
	.string "Når vi er helt opladet, vil vi glædeligt\n"
	.string "tage imod din udfordring.\p"
	.string "Så kom tilbage en anden gang, vil du\n"
	.string "ikke?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "WATTSON: Ah-ha! Here at last! I know\n"
	.string "what you want. You want to battle my\l"
	.string "POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Oops! Wait! You've only one POKéMON\n"
	.string "with you!\p"
	.string "Come see me with two or more POKéMON,\n"
	.string "all right?$"



