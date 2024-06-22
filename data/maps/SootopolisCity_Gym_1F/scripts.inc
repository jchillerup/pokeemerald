@ TRANSLATED

SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo! Hvordan går det, CHAMPION- klarede\n"
	.string "{PLAYER}?\p"
	.string "SOOTOPOLIS's GYM LEADER JUAN er en mester\n"
	.string "med VAND-type POKéMON.\p"
	.string "Og for at komme til JUAN, vil en isglat gulv\n"
	.string "forhindre din fremgang…\p"
	.string "Undskyld, men det er alt det råd, jeg har til\n"
	.string "dig.\p"
	.string "Resten af vejen må du klare resten selv!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Av! Du har slået selv JUAN, som angiveligt\n"
	.string "var den bedste i hele HOENN!\p"
	.string "Okay! Se din TRÆNERKORT.\p"
	.string "Hvis du har fået alle MÆRKERNE, er du klar til\n"
	.string "POKéMON LIGA udfordringen!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Lad mig spørge dig. Vidste du det? Åh, jeg\n"
	.string "burde ikke være så afvisende.\p"
	.string "Det var mig, der lærte WALLACE alt der er at\n"
	.string "vide om POKéMON.\p"
	.string "Én gang havde jeg opgivet min position som\n"
	.string "GYM LEDER.\p"
	.string "I mit sted havde jeg betroet WALLACE\n"
	.string "GYMet.\p"
	.string "Dog opstod der en overbevisende årsag for\n"
	.string "mig at gøre comeback.\p"
	.string "Ah, men nok snak. Lad os begynde vores kamp,\n"
	.string "skal vi?\p"
	.string "Vær så venlig at være vidne til vores kunst.\p"
	.string "En storslået illusion af vand skabt af\n"
	.string "POKéMON og mig selv!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, fremragende!\n"
	.string "Meget godt, du er vinderen.\p"
	.string "Fra dig fornemmer jeg det strålende\n"
	.string "skær af færdighed, der vil overvinde alt.\p"
	.string "Ikke desto mindre, sammenlignet med mig\n"
	.string "eller endda WALLACE, mangler du elegance.\p"
	.string "Måske skulle jeg låne dig\n"
	.string "mit outfit?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hahaha, jeg joker blot!\p"
	.string "I stedet for mine klæder vil jeg belønne\n"
	.string "dig med dette, REGN BADGEST!"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} modtog REGNBUEMÆRKET fra\n"
	.string "JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Med REGN-BADGEN kan du være sikker på, at\n"
	.string "alle dine POKéMON lystrer hver eneste\l"
	.string "kommando fra dig.\p"
	.string "REGN-BADGEN tillader også brugen af\n"
	.string "HM-trækket VANDFALD til at klatre op ad\l"
	.string "vægge af rislende vand.\p"
	.string "Og så du aldrig glemmer den kamp, vi delte, så\n"
	.string "tag det her…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "Den TEKNISKE MASKINE jeg gav dig\n"
	.string "indeholder VANDPULS.\p"
	.string "Når den bruges, vil den lejlighedsvis\n"
	.string "forvirre målet med ultralydsbølger.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Registreret GYM LEDER JUAN i POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "De TRÆNERE, der har samlet alle GYM BADGES\n"
	.string "på HOENN, bør gøre sig klar til den ultimative\l"
	.string "destination.\p"
	.string "POKéMON LIGAEN.\p"
	.string "Rejs til de østligste egne af HOENN, til øen\n"
	.string "EVER GRANDE.\p"
	.string "Der vil du finde POKéMON LIGAEN.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Der er kun ét MÆRKE tilbage at få fat i i\n"
	.string "HOENN.\p"
	.string "Hvis du ønsker at udfordre POKéMON-\n"
	.string "LIGAEN, skal du skaffe det sidste MÆRKE fra\l"
	.string "GYMMET i FORTREE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "SOOTOPOLIS CITY POKéMON Gym$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "SOOTOPOLIS BY POKéMON GYM\p"
	.string "JUANS CERTIFICEREDE TRÆNERE:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: Åh, dette GYM var vendt tilbage til sin\n"
	.string "sædvanlige tilstand af ro…\p"
	.string "Men vores unge tyfon er vendt tilbage for\n"
	.string "at sætte os på prøve igen!\p"
	.string "Nå, min ven, helt sikkert!\p"
	.string "Jeg vil med glæde danse med dig så tit du\n"
	.string "ønsker!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, du er vinderen! Du har besejret mig\n"
	.string "igen!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: Hvis jeg bad dig om at blive min lærling,\n"
	.string "ville du sikkert afvise det, er jeg sikker på.\p"
	.string "Jeg vil gerne give dig min frakke som en gave.\p"
	.string "Men igen vil du sikkert afvise det. Sådan\n"
	.string "forestiller jeg det mig i hvert fald.\p"
	.string "Og det, min ven, er et sikkert tegn på noble\n"
	.string "sind!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: Åh, denne GYM var vendt tilbage til sin\n"
	.string "sædvanlige tilstand af fred...\p"
	.string "Men vores unge tyfon er vendt tilbage for\n"
	.string "at teste os igen!\p"
	.string "Nå, min ven, helt sikkert! Jeg vil være\n"
	.string "henrykt over at danse med dig...\p"
	.string "Åh, nej, nej, nej. Du har kun med dig én\n"
	.string "POKéMON.\p"
	.string "Jeg ville ønske, at du vendte tilbage med\p"
	.string "to, måske flere, POKéMON, tak.$"



