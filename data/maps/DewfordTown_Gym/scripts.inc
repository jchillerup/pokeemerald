@ TRANSLATED

DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Hej, hvordan går det, CHAMPION-\n"
	.string "bundet {PLAYER}?\p"
	.string "DEWFORDs GYM-LEDer BRAWLY er kommandant\n"
	.string "af KAMP-type POKéMON.\p"
	.string "At stille op mod ham med NORMAL-\n"
	.string "type POKéMON er at bede om problemer.\p"
	.string "KAMP POKéMON vil give NORMAL POKéMON\n"
	.string "en alvorlig omgang,\l"
	.string "så vær forsigtig!\p"
	.string "Hvad der er værre, er at GYMMET er\n"
	.string "så mørkt som havets bund.\p"
	.string "Men det vil blive lysere efter at have\n"
	.string "besejret TRÆNERNE på din vej.\p"
	.string "Okay, gå efter det!$" 

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Whoah! Det er blevet alt for lyst herinde!\p"
	.string "Din fremtid er også lys!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "Styrke er ret!\n"
	.string "Kom nu!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Ikke nok energi...$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Dit dygtighed overvandt min styrke!\n"
	.string "Din teknik er beundringsværdig!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Der er ingen grund til, at BRAWLY\n"
	.string "skal blande sig!\p"
	.string "Jeg vil knuse dig!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Men... Hvordan?\n"
	.string "Hvordan kunne jeg tabe så let?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Jeg vil ikke spilde dette nederlag.\n"
	.string "Jeg vil bruge det til at motivere mig til at træne!\p"
	.string "En dag vil jeg blive en GYM LEDER...\p"
	.string "Nej, jeg vil blive POKéMON LIGA\n"
	.string "MESTER!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Du tør ikke at afvise mig!\n"
	.string "Det er ikke min skyld, hvis du græder!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Buuhuu!\n"
	.string "Jeg tabte!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Jeg kæmper i mørket for at gøre mit\n"
	.string "hjerte stærkere.\p"
	.string "Men fordi det er så mørkt, kan jeg\n"
	.string "aldrig se BRAWLY's ansigt…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Er du ved at snuble rundt i mørket?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Åh, dig…\n"
	.string "Jeg vil ikke kende dig!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Du fortjener at forblive tabt og ende\n"
	.string "tilbage ved indgangen igen!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Jeg vil vise dig manden ombord\n"
	.string "på et skib!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Hvordan skete det her?\n"
	.string "Det er ikke ligesom mig at tabe på denne måde!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Åh, ja! Du er værdig til at se\n"
	.string "vores GYM LEDER.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Hvis du vil passere, må det være\n"
	.string "gennem mig!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr!\n"
	.string "Voldsomt overlegen!$"  

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Du vinder!\n"
	.string "Jagten på DETT BADGE!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Jeg er BRAWLY!\n"
	.string "DEWFORDs GYM LEDER!\p"
	.string "Jeg er blevet skyllet rundt i de\n"
	.string "vilde bølger her omkring, og jeg er\n"
	.string "blevet stærk i den knaldsorte hule!\p"
	.string "Så du ville udfordre mig?\n"
	.string "Lad mig se hvad du er lavet af!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Whoah, wow! Du lavede en meget\n"
	.string "Større plask end jeg forventede!\p"
	.string "Du oversvømmede mig!\p"
	.string "Okay, du fik mig.\n"
	.string "Tag dette GYM BADGE!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} modtog KNUKLE-BADGEN\n"
	.string "fra BRAWLY.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "The KNUCKLE BADGE makes all POKéMON\n"
	.string "up to Level 30, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "And, you'll be able to use the HM move\n"
	.string "FLASH outside of battle.\p"
	.string "If you'd like, use this TECHNICAL\n"
	.string "MACHINE, too.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "Den TM08 indeholder BULK UP.\p"
	.string "Det er et træk, der øger både\n"
	.string "ANGREB og FORSVAR statistikker.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "Registreret GYM LEDER BRAWLY\n"
	.string "i POKéNAV'en.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Jeg kan se dit talent blive til en kæmpe\n"
	.string "bølge, der vil forårsage en storm af\n"
	.string "forundring blandt TRÆNERE en dag!\p$"

DewfordTown_Gym_Text_GymStatue:
	.string "DEWFORD BY POKéMON GYM$" 

DewfordTown_Gym_Text_GymStatueCertified:
	.string "DEWFORD BY POKéMON GYM\p"
	.string "BRAWLY'S GODKENDTE TRÆNERE:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BRAWLY: En bølge kan trække sig tilbage,\n"
	.string "men den vender altid tilbage til kysten.\p"
	.string "En kæmpemæssig bølge af et talent som dig…\n"
	.string "Jeg vidste, at du ville vende tilbage!\p"
	.string "Vis mig, hvor meget højere\n"
	.string "du er nået!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Øv!\n"
	.string "Overvældet igen!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BRAWLY: Kamp er vidt og bredt.\n"
	.string "Du kan ikke se bunden.\p"
	.string "Det er ligesom havet i HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
    .string "BRAWLY: En bølge kan trække sig tilbage,\n"
    .string "men den vender altid tilbage til stranden.\p"
    .string "En kæmpebølge af et talent som dig…\n"
    .string "Jeg vidste, du ville vende tilbage!\p"
    .string "Åh? Du har kun én POKéMON,\n"
    .string "der kan kæmpe.\p"
    .string "Jeg beklager, men jeg vil gerne bede dig\n"
    .string "om at komme tilbage med mindst to POKéMON.$"

