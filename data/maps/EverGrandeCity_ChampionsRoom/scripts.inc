@ TRANSLATED

.set LOCALID_WALLACE, 1
.set LOCALID_RIVAL, 2
.set LOCALID_BIRCH, 3

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "WALLACE: Velkommen, {PLAYER}{KUN}.\p"
	.string "Den hændelse i SOOTOPOLIS BY… Det var\n"
	.string "en fremragende præstation at stoppe\l"
	.string "den krise helt alene.\p"
	.string "Ups!\p"
	.string "Det ville ikke være fair at sige, at du\n"
	.string "alene afsluttede krisen.\p"
	.string "Du overvandt den svære situation ved\n"
	.string "at arbejde sammen med dine POKéMON.\p"
	.string "Vi TRÆNERE opdrager POKéMON ved at\n"
	.string "give dem ting og undervise dem i nye\l"
	.string "kampteknikker.\p"
	.string "Men vi lærer også mange ting af POKéMON.\p"
	.string "Og her bliver dine præstationer testet\n"
	.string "mod, hvad andre ligesom dig har opnået.\p"
	.string "Nu!\p"
	.string "Hvem kan danse mest elegant med deres\n"
	.string "POKéMON i HOENN?\p"
	.string "Vis mig det lige her og nu!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Jeg, MESTEREN, falder i nederlag…\p"
	.string "Det var vidunderligt arbejde. Du var\n"
	.string "elegant, irriterende sådan. Og alligevel\l"
	.string "var det fuldstændig glorværdigt!\p"
	.string "Kudos til dig, {PLAYER}{KUN}!\p"
	.string "Du er en sand ædel POKéMON TRÆNER!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "WALLACE: Den POKéMON, som du sendte i\n"
	.string "kamp…\p"
	.string "Nogle gange dansede de som en\n"
	.string "forårsbrise, og andre gange slog de til\l"
	.string "som lynet.\p"
	.string "Med let, dog sikker elegances føring,\n"
	.string "førte du dine POKéMON.\p"
	.string "Selv jeg blev fortryllet af din\n"
	.string "mesterlige præstation!\p"
	.string "Du står nu på det strålende\n"
	.string "bjergtoppen af POKéMON-LIGAEN.\p"
	.string "Jeg udråber dig nu til at være den nye\n"
	.string "mester af HOENN regionen…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "MAY: {PLAYER} KUN!\p"
	.string "Her er lidt råd, før du udfordrer\n"
	.string "CHAMPIONEN...$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "MAY: Hva'? Hvad, hvad, hvad?\p"
	.string "{PLAYER}{KUN}… Kunne det være, at… Det er\n"
	.string "allerede slut?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BRENDAN: {PLAYER}!\p"
	.string "Hvad siger du til lidt råd, inden du\n"
	.string "udfordrer CHAMPIONEN?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BRENDAN: {PLAYER}…\p"
	.string "Prøver du at fortælle mig… At du har\n"
	.string "besejret MESTEREN?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. BIRCH: Ser du? Hvad sagde jeg,\n"
	.string "{RIVAL}?\p"
	.string "Sagde jeg ikke, at du ikke behøver\n"
	.string "bekymre dig om {PLAYER}{KUN}?\p"
	.string "… … … … … … … … {PLAYER}{KUN}, du har endelig\n"
	.string "gjort det.\p"
	.string "Da jeg hørte, at du besejrede din egen\n"
	.string "far i PETALBURG GYM, tænkte jeg måske,\l"
	.string "at du havde en chance…\p"
	.string "Men at tænke sig, du er faktisk blevet\n"
	.string "mesteren!\p"
	.string "Åh, ja!\p"
	.string "Hvad blev der af din POKéDEX? Her, lad\n"
	.string "mig se.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. BIRCH: Nå, sådan! Tillykke!\p"
	.string "Nu, gå stolt ind i det sidste rum!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "WALLACE: {PLAYER}{KUN}…\p"
	.string "Nej, lad mig formulere det ordentligt.\p"
	.string "Den nye MESTER!\p"
	.string "Kom med mig.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "WALLACE: Undskyld, men…\p"
	.string "Fra nu af kan kun de TRÆNERE, der er\n"
	.string "blevet MESTRE, gå ind.\p"
	.string "Du bliver nødt til at vente udenfor med\n"
	.string "PROF. BIRCH.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "MAY: Støn…\p"
	.string "… … … … … … … … … … … … … … … …\p"
	.string "Jeg laver bare sjov! Det er okay! Sådan\n"
	.string "er reglen!\p"
	.string "{PLAYER}{KUN}! Ærligt talt, tillykke!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BRENDAN: Hvaaaad?! … … … … … … … …\p"
	.string "Det kan ikke ændres, hvis det er reglen.\p"
	.string "{PLAYER}, godt klaret! Tillykke!$"



