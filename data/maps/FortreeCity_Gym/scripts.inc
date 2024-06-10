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
	.string "Hej, hvordan går det, CHAMPION-\n"
	.string "bundne {PLAYER}?\p"
	.string "FORTREE GYM LEADER WINONA er\n"
	.string "en mester i FLYVETYPE POKéMON.\p"
	.string "Hun venter bagved GYMMET,\n"
	.string "bag de roterende døre.\p"
	.string "Hun venter på nye udfordrere,\n"
	.string "som prøver at tage til vejrs!\p"
	.string "Okay, så go for it!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Du gjorde det!\n"
	.string "Du har opnået lift-off!$"

FortreeCity_Gym_Text_JaredIntro:
.string "Se den elegante kampstil af\n"
.string "FUGLE POKéMON!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Du…\n"
	.string "Du er stærk…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "En TRÆNER skal være klog for at\n"
	.string "holde trit med uventede begivenheder.\p"
	.string "Har du hvad der skal til for at nå\n"
	.string "til vores LEDER?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "De elskere af FUGLE POKéMON stræber\n"
	.string "efter at deltage i dette GYM.\p"
	.string "Som medlem af FORTREE GYM,\n"
	.string "er det ikke tilladt at tabe!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Det var for meget af en byrde for mig\n"
	.string "at bære…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Verden er kæmpestor, og der er\n"
	.string "utallige seje TRÆNERE.\p"
	.string "Jeg vil blive ved med at træne og gøre\n"
	.string "mig selv endnu stærkere.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Der er ingen grund til, at WINONA, vores GYM\n"
	.string "LEDER, skal beskæftige sig med dig!\p"
	.string "Jeg er mere end god nok til dig!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "Winona, jeg…\n"
	.string "jeg tabte!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "WINONA er sød og stærk.\n"
	.string "Hun er den ultimative LEDER!\p"
	.string "Rødmer...$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "WINONA lærte mig personligt!\n"
	.string "Du kan ikke slå mig let!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Jeg blev slået...$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Takket være WINONA kan folkene i\n"
	.string "FORTREE leve uden frygt.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Når WINONA går i kamp, lyser hendes ansigt\n"
	.string "af smuk beslutsomhed...\p"
	.string "Jeg tillader dig ikke at være vidne til den\n"
	.string "smukke syn!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Åh nej!\n"
	.string "Jeg kunne ikke stoppe dig.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Du skal passe på!\n"
	.string "Bliv ikke distraheret af at stirre på WINONA\l"
	.string "ellers ender du med et stort brag!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Du skal vide, at der er alle\n"
	.string "slags FLYVENDE-type POKéMON.\p"
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
	.string "Jeg er blevet én med FUGLE POKéMON\n"
	.string "og har svævet på himlen…\p"
	.string "Uanset hvor hård kampen har været,\n"
	.string "har vi sejret med værdighed…\p"
	.string "Se den elegante koreografi\n"
	.string "mellem FUGLE POKéMON og mig!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Aldrig før har jeg set en TRÆNER\n"
	.string "kommandere POKéMON med mere\l"
	.string "elegance end jeg…\p"
	.string "Som anerkendelse af din dygtighed,\n"
	.string "præsenterer jeg dig for dette GYM-BADGE.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} modtog FJERBROCHEN\n"
	.string "fra WINONA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Med FJER-BADGE'et,\n"
	.string "vil alle POKéMON op til LV 70,\n"
	.string "selv dem du har fået gennem\l"
	.string "bytte, adlyde dine kommandoer.\p"
	.string "Du vil også kunne bruge\n"
	.string "HM-tricket FLY uden for kamp.\p"
	.string "Og dette…\n"
	.string "Dette er en gave fra mig.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM40 indeholder FLYVENDT SVÆRD.\p"
	.string "Dens hastighed…\n"
	.string "Ingen POKéMON burde kunne undgå det.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Registreret GYM LEDER WINONA\n"
	.string "i POKé-NAV.\p$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Selvom jeg tabte til dig, vil jeg forblive\n"
	.string "dedikeret til FUGL POKéMON.$"

FortreeCity_Gym_Text_GymStatue:
.string "FORTREE CITY POKéMON GYM$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "FORTREE CITY POKéMON GYM\p"
	.string "WINONA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "WINONA: Vi mennesker kan aldrig undslippe\n"
	.string "tyngdekraftens tiltrækning på jorden.\p"
	.string "Men ved at stræbe efter fremragende,\n"
	.string "har vi magten til at svæve!\p"
	.string "Du har nået toppen som\n"
	.string "den regerende MESTER.\p"
	.string "Please, lad mig se din styrke\n"
	.string "i fuldt firspring!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Jeg mislykkedes igen med at nå din højde…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "WINONA: Selvom jeg har tabt,\n"
	.string "er vingerne på mit hjerte uskadt.\p"
	.string "Jeg kan stige op og svæve\n"
	.string "igen og igen.\p"
	.string "Jeg er overbevist om det!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "WINONA: Vi mennesker kan aldrig\n"
	.string "undslippe tyngdekraftens træk\n"
	.string "mod jorden.\p"
	.string "Men ved at stræbe efter\n"
	.string "ekspertise har vi kraften til\n"
	.string "at svæve!\p"
	.string "Du har nået toppen som den\n"
	.string "regjerende CHAMPION.\p"
	.string "Vil du tillade mig at se din\n"
	.string "kraft i fuld flyvning!\p"
	.string "Åh, nej... Har du kun én\n"
	.string "POKéMON med dig?\p"
	.string "Vend tilbage med mindst to\n"
	.string "POKéMON!$"


