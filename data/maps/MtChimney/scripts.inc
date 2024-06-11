@ TRANSLATED

.set LOCALID_ARCHIE, 1
.set LOCALID_MAXIE, 2
.set LOCALID_TABITHA, 3
.set LOCALID_MAGMA_GRUNT_2, 22
.set LOCALID_MAGMA_GRUNT_1, 29


MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_ARCHIE, 10, 12
	addobject LOCALID_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "Kraften indeholdt i METEORITTEN…\p"
	.string "Ved at forstærke dens kraft med denne\n"
	.string "maskine, vil MT. CHIMNEYs vulkanske\l"
	.string "aktivitet øjeblikkeligt intensiveres…\p"
	.string "Dens energi vil vokse dybt inde i\n"
	.string "krateret og…\l"
	.string "Fufufu…$"

MtChimney_Text_MaxieIntro:
	.string "MAXIE: Hm?\n"
	.string "Hvem er du?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Jeg hørte ARCHIE beklage sig over et\n"
	.string "barn, der har rodet sig ind i TEAM\n"
	.string "AQUA's sager.\p"
	.string "Det må være dig, han mente.\p"
	.string "Hmf! Så du tænker på at blande dig\n"
	.string "i vores, TEAM MAGMA's, anliggender?\p"
	.string "Nu hør her.\n"
	.string "I gamle dage brugte levende væsener\n"
	.string "jorden til at leve og vokse.\p"
	.string "Det er derfor, jorden er så vigtig!\n"
	.string "Det er vuggen for alt!\p"
	.string "Derfor er TEAM MAGMA dedikeret til\n"
	.string "udvidelsen af landmassen.\p"
	.string "Det er til yderligere fremskridt for\n"
	.string "menneskeheden og POKéMON!\p"
	.string "Og til det har vi brug for kraften af\n"
	.string "det, der sover indeni dette bjerg…\p"
	.string "Åh! Du behøvede ikke at lære så\n"
	.string "meget.\p"
	.string "Men, det betyder intet!\n"
	.string "Jeg vil lære dig konsekvenserne af at\n"
	.string "blande dig i vores store plan!$"

MtChimney_Text_MaxieDefeat:
	.string "Hvad?!\p"
	.string "Jeg, MAXIE, blev overrasket?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAXIE: Men nok om det.\n"
	.string "Jeg vil trække mig denne gang.\p"
	.string "Men tro ikke, at det her er sidste\n"
	.string "gang, du har set til TEAM MAGMA.\p"
	.string "Fufufu…\p"
	.string "Selv uden METEORITEN, hvis vi\n"
	.string "skaffer den ORB… Fufufu…$"

MtChimney_Text_TabithaIntro:
	.string "Hihihi!\p"
	.string "Så du er kommet hele vejen herhen!\p"
	.string "Men du er for sent!\n"
	.string "Jeg har allerede leveret METEORITEN\l"
	.string "fra METEORFALDENE til BOSS!\p$"

MtChimney_Text_TabithaDefeat:
	.string "Hihihi…\p"
	.string "Selvom jeg har tabt, hvis vores leder\n"
	.string "vækker den ting…$"

MtChimney_Text_TabithaPostBattle:
	.string "BOSS, skynd dig!\n"
	.string "Giv den METEORITens energi!\p"
	.string "Hehehe…$"

MtChimney_Text_Grunt2Intro:
	.string "Vi i TEAM MAGMA arbejder hårdt for\n"
	.string "alles skyld.\p"
	.string "Hvis den der tinges kraft skabte mere\n"
	.string "land, ville der være flere steder at bo.\p"
	.string "Alle ville være glade!$"

MtChimney_Text_Grunt2Defeat:
	.string "Hvad mener du med, at jeg har tabt?\p$"

MtChimney_Text_Grunt2PostBattle:
	.string "Vores CHEF siger, “Det vil gøre alle\n"
	.string "glade.”\p"
	.string "Men hvorfor bliver alle ved med\n"
	.string "at komme i vores vej?$"

MtChimney_Text_Grunt1Intro:
	.string "Hvis der var mere jord, ville jeg kunne\n"
	.string "få et stort hus for mig selv!\p"
	.string "Jeg vil bygge det på størknet lava!$"

MtChimney_Text_Grunt1Defeat:
	.string "Min drøm om et stort hus…$"

MtChimney_Text_Grunt1PostBattle:
	.string "En lille skat som dig, burde\n"
	.string "plaske rundt i bølgerne!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "De irriterende TEAM AQUA…\n"
	.string "De roder altid med vores planer!$"

MtChimney_Text_MeteoritesPackAmazingPower:
.string "METEORITER har en fantastisk kraft!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Du skal nok lade være med at provokere os!\p"
	.string "Vi prøver at vække det der\n"
	.string "til gavn for alle!$"

MtChimney_Text_AquasNameSimilar:
	.string "Vi er TEAM MAGMA!\p"
	.string "De er TEAM AQUA!\p"
	.string "Det irriterer mig helt vildt, at de\n"
	.string "ville bruge et navn ligesom vores!$"

MtChimney_Text_DouseThemInFire:
	.string "Ja!\n"
	.string "Overøs dem i ild!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Vi vil blive ved med at skabe mere land!$"

MtChimney_Text_Bufoh:
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARCHIE: Grr, {PLAYER}!\n"
	.string "Jeg skulle have gættet på, at du ville dukke op!\p"
	.string "Se selv, hvad fanatikerne fra\n"
	.string "TEAM MAGMA er i gang med!\p"
	.string "De forsøger at injicere stjålet\n"
	.string "METEORITS kraft ind i vulkanen!\p"
	.string "At gøre noget sådan vil få vulkanen\n"
	.string "til at gå i udbrud!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARCHIE: Grrr…\p"
	.string "Jeg vil stoppe den MAXIE,\n"
	.string "men jeg kan ikke!\p"
	.string "Ikke når jeg har hænderne fulde med at kæmpe\n"
	.string "mod tre modstandere på én gang!$"

MtChimney_Text_ArchieThankYou:
	.string "ARCHIE: {PLAYER}!\n"
	.string "Tak!\p"
	.string "Med din hjælp har vi forhindret TEAM\n"
	.string "MAGMAs destruktive plan!\p"
	.string "Men… Du…\n"
	.string "Hvilken side er du på?\p"
	.string "Nå, det betyder ikke noget.\p"
	.string "Vi vil forblive årvågne og fortsætte\n"
	.string "vores jagt på TEAM MAGMA.\p"
	.string "{PLAYER}, vi skal mødes igen!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Øv... HOLD MAGMA er flere end os!\n"
	.string "Vi kan ikke følge med dem!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Hvis de udvider området, vil der være\n"
	.string "færre levesteder til VAND POKéMON!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Vi er HOLD AQUA!\p"
	.string "De er HOLD MAGMA!\p"
	.string "Det gør mig rasende, at de ville\n"
	.string "bruge et så forvirrende navn!$"

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "LAVA COOKIES er det lokale\n"
	.string "specialitet på MT. CHIMNEY.\p"
	.string "Prøv en. Det koster kun ¥200.$"

MtChimney_Text_ThankYouDear:
	.string "Tak, søde!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Åh, du. Du kan ikke købe noget, hvis\n"
	.string "du ikke har pengene.$"

MtChimney_Text_OhFineThen:
	.string "Åh, fint så.$"

MtChimney_Text_MetoriteFittedOnMachine:
	.string "En METEORIT er monteret på en mystisk\n"
	.string "maskine...\p"
	.string "Maskinen ser ud til at lagre\n"
	.string "energi i METEORITTEN.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "En METEORIT er monteret på en mystisk\n"
	.string "maskine…\p"
	.string "Vil du fjerne METEORITEN?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} fjernede METEORITEN fra\n"
	.string "den mystiske maskine.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} efterlod METEORITEN hvor den\n"
	.string "var.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Denne mystiske maskine...\n"
	.string "Den reagerer overhovedet ikke.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} STEJL STI\n"
	.string "LAVARIDGE BY FORAN$" 

MtChimney_Text_ShelbyIntro:
	.string "Jeg har været i de varme kilder og\n"
	.string "fået fornyet energi i mine trætte ben.\p"
	.string "Lige nu føler jeg mig stærk!$"

MtChimney_Text_ShelbyDefeat:
	.string "Åh, min gode.\n"
	.string "Nå, er du ikke noget særligt!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Nå, nå, jeg har tabt. Jeg kan ikke\n"
	.string "kalde mig selv en EKSPERT nu, kan jeg?$"

MtChimney_Text_ShelbyRegister:
	.string "Tak, barn. Det var sjovt, som om\n"
	.string "jeg kæmpede mod mit eget barnebarn.\p"
	.string "Kom venligst og besøg mig igen\n"
	.string "til en revanche.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Hvis du kan forene dit hjerte med\n"
	.string "dine POKéMONs, ja, så kan du\l"
	.string "opnå store ting.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Åh, min gode.\n"
	.string "Nå, er du ikke noget!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Måske er dit hjerte blevet ét\n"
	.string "med hjertene af dine POKéMON.$"

MtChimney_Text_MelissaIntro:
	.string "Jeg har ilden i mig, skat.\n"
	.string "Jeg kan ikke holde det ud! Jeg er nødt til at kæmpe!$"

MtChimney_Text_MelissaDefeat:
	.string "Åh, det var en brændende varm kamp!$"

MtChimney_Text_MelissaPostBattle:
	.string "Varmen fra MT. CHIMNEY\n"
	.string "varmer mig op, skat!$"

MtChimney_Text_SheilaIntro:
	.string "Jeg er endelig nået til MT. CHIMNEY.\n"
	.string "Jeg vil gerne have min POKéMON til kamp!$"

MtChimney_Text_SheilaDefeat:
	.string "Måden, du kæmper på…\n"
	.string "Det er som en MT. CHIMNEY-udbrud!$"

MtChimney_Text_SheilaPostBattle:
	.string "Som jeg sagde, er jeg endelig nået\n"
	.string "til MT. CHIMNEY. Det ville være en\n"
	.string "skam, hvis jeg kun nøjedes med at\n"
	.string "tage lidt sightseeing…\p"
	.string "Jeg vil gerne kæmpe og købe\n"
	.string "KAGEKAGER som souvenir.$"

MtChimney_Text_ShirleyIntro:
	.string "Siden jeg badede i de varme kilder,\n"
	.string "har jeg følt mig fantastisk!\l"
	.string "Jeg er sikker på, at jeg vil vinde!$"

MtChimney_Text_ShirleyDefeat:
	.string "Av!\n"
	.string "Jeg fryser af vandet.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Jeg bliver nødt til at tage endnu et\n"
	.string "dyp i de varme kilder. Vil du med?\p"
	.string "Bare pjat!\p$"

MtChimney_Text_SawyerIntro:
	.string "Det her er et fantastisk bjerg! Masser\n"
	.string "af seje mennesker at være sammen med!$"

MtChimney_Text_SawyerDefeat:
	.string "Åh, du er også en ægte ildsjæl!$"

MtChimney_Text_SawyerPostBattle:
	.string "Jeg tror, jeg har brug for en dukkert i LAVARIDGE\n"
	.string "VARME KILDE med de lokale!$"

MtChimney_Text_SawyerRegister:
	.string "Jeg kan godt lide små ildkugler som dig.\n"
	.string "Lad mig registrere dig i min POKéNAV.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Jeg er glad omgivet af seje folk\n"
	.string "her i nærheden. Jeg vil ikke tabe!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Åh, du er stadig den samme\n"
	.string "ildsjæl som før!$"

MtChimney_Text_SawyerPostRematch:
	.string "Faktisk er det virkelig varmt her.\n"
	.string "Jeg er klædt overdrevet på til disse egne.$"



