@ TRANSLATED

.set LOCALID_HIDEOUT_GUARD, 5

JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "BJERGET CHIMNEY's FULDE AF KANTER…\p"
	.string "Det her er virkelig det, jeg altid\n"
	.string "har ønsket mig i et bjerg.\p"
	.string "Alle disse skarpe kanter…\n"
	.string "Det giver mig gåsehud!\p"

JaggedPass_Text_EricDefeat:
	.string "At tabe gjorde mig bitter!$"

JaggedPass_Text_EricPostBattle:
	.string "Ja, jeg tabte i POKéMON…\p"
	.string "Men når det kommer til kærligheden\n"
	.string "til bjergene, slår jeg dig!$"

JaggedPass_Text_DianaIntro:
	.string "Dette sted er ikke din almindelige gåtur.\n"
	.string "Det er ikke velegnet til en picnic.$"

JaggedPass_Text_DianaDefeat:
	.string "Åh nej!\n"
	.string "Jorden er alt for ujævn...$"

JaggedPass_Text_DianaPostBattle:
	.string "Vidste du det?\p"
	.string "Nogle folk klogt cykler opad\n"
	.string "denne forfærdelig bumpede vej.$"

JaggedPass_Text_DianaRegister:
	.string "Vil du nogensinde være tilbage i dette område?\n"
	.string "Hvis du vender tilbage, vil jeg gerne have en revanche.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Picnic er sjovt,\nnår som helst,\nhvor som helst.\n"
	.string "Ligesom POKéMON!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Jeg tabte kun fordi jorden er for\n"
	.string "bumpet!$"

JaggedPass_Text_DianaPostRematch:
	.string "Jeg vil glemme at tabe og bare\n"
	.string "nyde denne ujævne vandretur.$"

JaggedPass_Text_EthanIntro:
	.string "STEJL PASSAGE er svær at gå på.\n"
	.string "Det er et godt sted at træne.$"

JaggedPass_Text_EthanDefeat:
	.string "Det hele var forbi mens vi stadig\n"
	.string "prøvede at finde fodfæste…$"

JaggedPass_Text_EthanPostBattle:
	.string "Hvis jeg havde en ACROCYKEL, ville jeg\n"
	.string "kunne hoppe ned.\p$"

JaggedPass_Text_EthanRegister:
	.string "Når jeg bliver mere vant til denne bumpiness,\n"
	.string "er jeg sikker på, at jeg vil vinde!\p"
	.string "Kan du registrere mig i din POKéNAV?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Jeg har vænnet mig til denne ujævnhed.\n"
	.string "Nu synger jeg mens jeg klatrer.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Det er stadig ikke let at kæmpe på denne\n"
	.string "ujævne grund...$"  

JaggedPass_Text_EthanPostRematch:
	.string "Jeg burde få en ACROCYKEL fra RYDEL\n"
	.string "i MAUVILLE CITY...$"

JaggedPass_Text_GruntIntro:
	.string "Åh nej!\n"
	.string "Hvad laver du her?\p"
	.string "Hvad laver jeg et sted som dette?\p"
	.string "Hvad angår det dig?$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh…\p"
	.string "Jeg skulle have gemt mig i vores SKJULESTED\n"
	.string "med det samme…$"

JaggedPass_Text_GoWhereverYouWant:
    .string "Okay, oh-kay!\n"
    .string "Jeg indrømmer det - du er stærk!\p"
    .string "Bare rolig om mig.\n"
    .string "Gå hvorhen du vil!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Åh! Denne klippe ryster som svar\n"
	.string "på MAGMA EMBLEM!\n$"

JaggedPass_Text_JulioIntro:
	.string "Uha! Det er vældig skræmmende at skyde\n"
	.string "ned ad bjerget på én gang!$" 

JaggedPass_Text_JulioDefeat:
	.string "Jeg føler, at jeg falder fra hinanden...$"

JaggedPass_Text_JulioPostBattle:
	.string "Min cykel hoppede så meget rundt,\n"
	.string "at min bagende er øm…$"

JaggedPass_Text_AutumnIntro:
	.string "Jeg klatrer op ad denne bakke hver dag.\n"
	.string "Jeg har tillid til min styrke!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm…\n"
	.string "Hvad gik galt?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Hvad er det for en mærkelig stenfremspring\n"
	.string "lidt op ad bakken her?$"



