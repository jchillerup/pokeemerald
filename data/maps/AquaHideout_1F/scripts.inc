@ TRANSLATED

AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Hvad? Hvad? Hvad vil du med \n"
	.string "TEAM AQUA?\p"
	.string "Vores chef er ikke her! Han er taget\n"
	.string "afsted for at snuppe noget vigtigt!\p"
	.string "… …\n"
	.string "Hvor er han taget hen?\p"
	.string "Hahaha! Tror du virkelig, jeg ville\n"
	.string "fortælle dig noget så afgørende?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Hvad? Hvad?\n"
	.string "Er du en del af TEAM MAGMA holdet?\p"
	.string "Jeg hører, at TEAM MAGMA prøver at\n"
	.string "vække en fantastisk POKéMON i deres\l"
	.string "SKJULESTED.\p"
	.string "Men hvor mon deres SKJULESTED er?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Hvad? Hvad? Hvad vil du med \n"
	.string "TEAM AQUA?\p"
	.string "Vores BOSS er ikke her!\n"
	.string "Han er taget af sted for at kapre en \nubåd!\p"
	.string "… …\n"
	.string "Hvor er han taget hen?\p"
	.string "Haha! Tror du virkelig, jeg ville \nforkrænke dig med så vigtig en \noplysning?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Hvad? Hvad? Hvad vil du med \n"
	.string "TEAM AQUA?\p"
	.string "Vores BOSS er ikke her! Han er på vej til\n"
	.string "MT. PYRE på ROUTE 122!\p"
	.string "… …\n"
	.string "Hvorfor tog han af sted?\p"
	.string "Hahaha! Tror du virkelig, jeg ville\n"
	.string "fortælle dig noget så afgørende?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Hvad? Hvad?\n"
	.string "Er du en del af TEAM MAGMA?\p"
	.string "Jeg hører, at TEAM MAGMA jagter\n"
	.string "en fantastisk POKéMON på MT. CHIMNEY.\p"
	.string "Men hvordan er den POKéMON?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Hvad? Hvad? Hvad vil du med\n"
	.string "TEAM AQUA?\p"
	.string "Vores BOSS er ikke her!\n"
	.string "Han er på vej til SLATEPORT CITY!\p"
	.string "… …\n"
	.string "Hvorfor tog han afsted?\p"
	.string "Haha! Tror du virkelig, jeg ville\n"
	.string "fortælle dig noget så afgørende?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Aj-aj-aj!\n"
	.string "Mistænkelig karakter spottet!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Av av…\n"
	.string "Jeg tabte den!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "Jeg tog tabet for HOLDEN,\n"
	.string "men jeg gjorde mit job...\p$"



