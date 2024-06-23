@ TRANSLATED

FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Hej, hvordan går det, CHAMPION- bundne\n"
	.string "{PLAYER}?\p"
	.string "FORTREE GYM LEADER WINONA er en mester\n"
	.string "i FLYVETYPE POKéMON.\p"
	.string "Hun venter bagved GYMMET, bag de\n"
	.string "roterende døre.\p"
	.string "Hun venter på nye udfordrere, som\n"
	.string "prøver at tage til vejrs!\p"
	.string "Okay, så go for it!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Du gjorde det! Du har opnået lift-off!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "FUGLE POKéMON!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Du… Du er stærk…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "En TRÆNER skal være klog for at holde\n"
	.string "trit med uventede begivenheder.\p"
	.string "Har du hvad der skal til for at nå til\n"
	.string "vores LEDER?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "De elskere af FUGLE POKéMON stræber\n"
	.string "efter at deltage i dette GYM.\p"
	.string "Som medlem af FORTREE GYM, er det ikke\n"
	.string "tilladt at tabe!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Det var for meget af en byrde for mig at\n"
	.string "bære…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Verden er kæmpestor, og der er utallige\n"
	.string "seje TRÆNERE.\p"
	.string "Jeg vil blive ved med at træne og gøre\n"
	.string "mig selv endnu stærkere.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Der er ingen grund til, at WINONA, vores\n"
	.string "GYM LEDER, skal beskæftige sig med dig!\p"
	.string "Jeg er mere end god nok til dig!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "Winona, jeg… jeg tabte!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "WINONA er sød og stærk. Hun er den\n"
	.string "ultimative LEDER!\p"
	.string "Rødmer...$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "WINONA lærte mig personligt! Du kan ikke\n"
	.string "slå mig let!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Jeg blev slået...$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Takket være WINONA kan folkene i\n"
	.string "FORTREE leve uden frygt.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Når WINONA går i kamp, lyser hendes\n"
	.string "ansigt af smuk beslutsomhed...\p"
	.string "Jeg tillader dig ikke at være vidne til\n"
	.string "den smukke syn!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Åh nej! Jeg kunne ikke stoppe dig.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Du skal passe på! Bliv ikke distraheret\n"
	.string "af at stirre på WINONA ellers ender du\l"
	.string "med et stort brag!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Du skal vide, at der er alle slags\n"
	.string "FLYVENDE-type POKéMON.\p"
	.string "Det ved du vel, ikke?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Du virker godt nok skarp!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Selvfølgelig, du slog mig helt sikkert.\n"
	.string "Men du skal passe på! Vores LEADER\l"
	.string "WINONA's POKéMON mener alvor.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Jeg er WINONA. Jeg er lederen af\n"
	.string "FORTREE POKéMON GYM.\p"
	.string "Jeg er blevet én med FUGLE POKéMON og\n"
	.string "har svævet på himlen…\p"
	.string "Uanset hvor hård kampen har været, har\n"
	.string "vi sejret med værdighed…\p"
	.string "Se den elegante koreografi mellem\n"
	.string "FUGLE POKéMON og mig!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Aldrig før har jeg set en TRÆNER\n"
	.string "kommandere POKéMON med mere elegance\l"
	.string "end jeg…\p"
	.string "Som anerkendelse af din dygtighed,\n"
	.string "præsenterer jeg dig for dette\l"
	.string "GYM-BADGE.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} modtog FJERBROCHEN fra\n"
	.string "WINONA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Med FJER-BADGE'et, vil alle POKéMON op\n"
	.string "til LV 70, selv dem du har fået gennem\l"
	.string "bytte, adlyde dine kommandoer.\p"
	.string "Du vil også kunne bruge HM-tricket FLY\n"
	.string "uden for kamp.\p"
	.string "Og dette… Dette er en gave fra mig.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM40 indeholder FLYVENDT SVÆRD.\p"
	.string "Dens hastighed… Ingen POKéMON burde\n"
	.string "kunne undgå det.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Registreret GYM LEDER WINONA i\n"
	.string "POKé-NAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Selvom jeg tabte til dig, vil jeg\n"
	.string "forblive dedikeret til FUGL POKéMON.$"

FortreeCity_Gym_Text_GymStatue:
.string "FORTREE CITY POKéMON GYM$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "FORTREE CITY POKéMON GYM\p"
	.string "WINONA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "WINONA: Vi mennesker kan aldrig\n"
	.string "undslippe tyngdekraftens tiltrækning\l"
	.string "på jorden.\p"
	.string "Men ved at stræbe efter fremragende,\n"
	.string "har vi magten til at svæve!\p"
	.string "Du har nået toppen som den regerende\n"
	.string "MESTER.\p"
	.string "Please, lad mig se din styrke i fuldt\n"
	.string "firspring!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Jeg mislykkedes igen med at nå din\n"
	.string "højde…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "WINONA: Selvom jeg har tabt, er\n"
	.string "vingerne på mit hjerte uskadt.\p"
	.string "Jeg kan stige op og svæve igen og igen.\p"
	.string "Jeg er overbevist om det!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "WINONA: Vi mennesker kan aldrig\n"
	.string "undslippe tyngdekraftens træk mod\l"
	.string "jorden.\p"
	.string "Men ved at stræbe efter ekspertise har\n"
	.string "vi kraften til at svæve!\p"
	.string "Du har nået toppen som den regjerende\n"
	.string "CHAMPION.\p"
	.string "Vil du tillade mig at se din kraft i fuld\n"
	.string "flyvning!\p"
	.string "Åh, nej... Har du kun én POKéMON med dig?\p"
	.string "Vend tilbage med mindst to POKéMON!$"



