@ TRANSLATED

.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_GRUNT_3, 6
.set LOCALID_GRUNT_4, 7
.set LOCALID_MAXIE, 8

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MAXIE, 23, 6
	setobjectxyperm LOCALID_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Nej! De dér TEAM MAGMA fjolser nåede\n"
	.string "her før os!\p"
	.string "Vi kan ikke hænge i bremsen!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Jeg troede, du var en af MAGMAS-\n"
	.string "medlemmerne, der kom tilbage…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Ja, så du er stærk... Men der er mange af\n"
	.string "os!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hov! Det er ærgerligt for dig!\p"
	.string "Hvis du var kommet tidligere, skulle du\n"
	.string "kun have kæmpet mod de slappe TEAM\l"
	.string "MAGMA.\p"
	.string "Men nu, da du er kommet, skal du kæmpe\n"
	.string "mod os seje fyre!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Åh nej... Jeg skulle have ladet dig tage\n"
	.string "kampen mod TEAM MAGMA først...$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Du ved ikke noget! Så hvorfor roder du\n"
	.string "dig så i det?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Du… Vi så dig ved MT. CHIMNEY.\p"
	.string "Du hører ikke til nogen af holdene, så\n"
	.string "hvorfor er du her?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Hvis du vil drille nogen, så lad det være\n"
	.string "HOLD MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Haha, det betyder ikke noget! Vi har\n"
	.string "købt os lidt ekstra tid!\p"
	.string "BOSS'en burde have snuppet det, han var\n"
	.string "ude efter!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Åh, jeg ved det! Du prøvede at blive\n"
	.string "medlem af HOLD MAGMA, men de ville ikke\l"
	.string "have dig!\p"
	.string "Ja, så tro ikke, at vi vil lade dig blive\n"
	.string "medlem af vores HOLD AQUA!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Hvis du virkelig gerne vil være en del af\n"
	.string "HOLD AQUA, kan vi overveje det…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Vi har en fantastisk kombination med os\n"
	.string "medlemmer og vores leder.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARCHIE: Hold da op, hold da op! Holdt\n"
	.string "TEAM MAGMA's MAXIE førte an, men vi fik\l"
	.string "også, hvad vi ønskede.\p"
	.string "Den RØDE ORB bevaret på MT. PYRE… Jeg,\n"
	.string "ARCHIE, har den nu i min besiddelse!\p"
	.string "Fufufu… Nu kan vi realisere vores\n"
	.string "ultimative mål!\p"
	.string "Okay, TEAM! Vi trækker os tilbage!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Åh, nej… Dette kan ikke ske…\p"
	.string "Ikke kun den BLÅ ORB, men selv den RØDE\n"
	.string "ORB er blevet taget…\p"
	.string "DEN BLÅ ORB og DEN RØDE ORB må aldrig\n"
	.string "adskilles. De hører sammen.\p"
	.string "Hvad prøver de mænd at gøre med de to\n"
	.string "ORBER?\p"
	.string "… … … … … … … … … … … …\p"
	.string "Åh, ja. Var det TEAM MAGMA, der kom og\n"
	.string "tog DEN BLÅ ORB først?\p"
	.string "Nå, i deres hast lod de dette blive\n"
	.string "tilbage.\p"
	.string "Jeg kunne ikke forestille mig, hvad det\n"
	.string "præcist kunne være.\p"
	.string "Jeg vil gerne at du får det. Måske vil\n"
	.string "det være nyttigt på en eller anden måde.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "Den BLÅ ORB og RØDE ORB taget af disse\n"
	.string "ondsindede mænd…\p"
	.string "De må aldrig være adskilt… Jeg frygter,\n"
	.string "at noget forfærdeligt vil ske…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Åh, min gode…\p"
	.string "Du siger, at både GROUDON og KYOGRE er\n"
	.string "blevet vækket?\p"
	.string "Det siges, at DEN BLÅ ORB og DEN RØDE\n"
	.string "ORB dæmpede raseriet hos de to\l"
	.string "POKéMON…\p"
	.string "Det siges også, at den sande ejer af\n"
	.string "ORBERNE stadig eksisterer.\p"
	.string "Dog ved ingen, hvem eller hvad præcis,\n"
	.string "ORBERNE tilhører.\p"
	.string "Det kunne være et menneske, eller måske\n"
	.string "en POKéMON, men ingen ved.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "De to mænd, der tog ORBERNE, kom tilbage\n"
	.string "for at returnere dem på egen hånd.\p"
	.string "De mænd... Måske er de ikke så onde\n"
	.string "trods alt...$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Landenes, havets og himlens\n"
	.string "forvandlinger…\p"
	.string "Det siges at være identiteterne af de\n"
	.string "superældgamle POKéMON…\p"
	.string "På samme måde som vi mennesker og\n"
	.string "POKéMON har liv, så har vores verden det\l"
	.string "også…\p"
	.string "De superældgamle POKéMON har lært os\n"
	.string "det…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "MOUNT PYRE er, hvor vi beroliger ånderne\n"
	.string "af POKéMON, der er gået bort…\p"
	.string "Dette er et højt sted, hvor man kan se\n"
	.string "hele HOENN…\p"
	.string "De afdøde ånder af POKéMON finder\n"
	.string "trøst her…\p"
	.string "Er det tilfældigt, at du er her…\p"
	.string "Vil du lytte til min historie? En\n"
	.string "historie længe fortalt i\l"
	.string "HOENN-regionen?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Det skete for længe, længe siden…\p"
	.string "Verden blev rystet af en voldsom kamp\n"
	.string "mellem POKéMON fra landet og POKéMON\l"
	.string "fra havet…\p"
	.string "POKéMON fra landet løftede bjerge og\n"
	.string "skabte kontinenter…\p"
	.string "POKéMON fra havet rejste kæmpe bølger\n"
	.string "og udskar oceaner…\p"
	.string "Deres heftige duel rasede uden ende.\p"
	.string "Verden blev opslugt af massive\n"
	.string "infernoer og voldsomme storme.\p"
	.string "DEN BLÅ ORB og DEN RØDE ORB satte en\n"
	.string "stopper for katastrofen.\p"
	.string "Lys strømmede fra de to ORBS og fik de\n"
	.string "rasende modstandere til at falde til ro.\p"
	.string "Parret, gjort dulgel, dykkede dybt ned i\n"
	.string "havet, hvor de til sidst forsvandt…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Jeg ser... Nå, det er også fint...$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … … … … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Det er min rolle at videregive\n"
	.string "legenderne om HOENN til kommende\l"
	.string "generationer.\p"
	.string "Og krisen, der netop sluttede i\n"
	.string "SOOTOPOLIS, omskrev en legende…\p"
	.string "Har du tid til at høre den nye legende\n"
	.string "om HOENN?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Det skete for længe, længe siden…\p"
	.string "Verden blev hærget af et voldsomt\n"
	.string "sammenstød mellem POKéMON'erne fra\l"
	.string "landet og POKéMON'erne fra havet…\p"
	.string "POKéMON'erne fra landet skabte bjerge\n"
	.string "og kontinenter…\p"
	.string "POKéMON'erne fra havet skabte\n"
	.string "kæmpebølger og formede havene…\p"
	.string "Deres intense duel rasede uden ende.\p"
	.string "Verden blev opslugt af massive brande\n"
	.string "og voldsomme storme.\p"
	.string "Det var da POKéMON'en fra himlen\n"
	.string "nedsteg fra en storm.\p"
	.string "POKéMON'en, der strålede i en levende\n"
	.string "grøn farve, formildede de to rasende\l"
	.string "POKéMON'er.\p"
	.string "Derefter, da dens opgave var fuldført,\n"
	.string "fløj den grønne POKéMON ud i det\l"
	.string "ukendte…$"



