@ TRANSLATED

.set LOCALID_GREETER, 1
.set LOCALID_GUIDE, 2
.set LOCALID_SCOTT, 4

BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_GUIDE, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "Er det din første gang her? Træd\n"
	.string "venligst denne vej!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "Frontlinjerne af POKéMON-kampe!\n"
	.string "Velkommen til KAMPENS FRONTIER!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "For en førstegangsgæst, udsteder vi\n"
	.string "FRONTIER-PASSET.\p"
	.string "Det kan bruges på alle faciliteterne i\n"
	.string "BATTLE FRONTIER.\p"
	.string "Her er det!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} har fået FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} lagde TRÆNERKORTET i\n"
	.string "FRONTIER PASSPORT.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Vi håber, du nyder alt, som BATTLE\n"
	.string "FRONTIER har at byde på!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Nå, hvis det ikke er {PLAYER}{KUN}! Du\n"
	.string "kom ud her!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "GUIDE: Åh! HR. SCOTT, sir! God dag til\n"
	.string "dig, sir!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "SCOTT: Det er skønt at se dig her, det\n"
	.string "er virkelig!\p"
	.string "Jeg håber, at du vil tage dig god tid og\n"
	.string "udforske overalt.\p"
	.string "Selvfølgelig håber jeg også, at du vil\n"
	.string "opleve kernen i kampe.\p"
	.string "Jeg har også min bolig her, så føl dig\n"
	.string "velkommen til at besøge mig, hvis du har\l"
	.string "tid.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Jeg er din guide til de forskellige\n"
	.string "faciliteter her i KAMPFRONTEN.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Hvad vil du gerne lære om?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "Det er det gigantiske tårn, der\n"
	.string "betragtes som SYMBOL for KAMPFRONTEN.\p"
	.string "Der er fire slags KAMPRUM i tårnet til\n"
	.string "ENE, DOBBELT, FLERE, og FORBINDEDE\l"
	.string "FLERE KAMPE.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "KAMPDOMEN er den store bygning, formet\n"
	.string "som et kæmpe æg.\p"
	.string "Begivenheder kaldet Kampturneringer\n"
	.string "afholdes i denne facilitet.\p"
	.string "Kampturneringerne tilbydes i to\n"
	.string "kurser--for ENKELT og Dobbelt KAMPE.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "KAMPBYGNINGEN er den røde bygning til\n"
	.string "højre for KAMPMONUMENTET.\p"
	.string "Der er to slags KAMP HALLER til ENKELT-\n"
	.string "og DOBBELT KAMPE.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "KAMPARENAEN er bygningen i dojo-stil,\n"
	.string "der ligger i midten til højre på\l"
	.string "KAMPFRONTEN.\p"
	.string "Et arrangement kaldet Set KO\n"
	.string "Turneringen finder sted i KAMPARENAEN.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "KAMPFABRIKKEN er den store bygning,\n"
	.string "der er tættest på os.\p"
	.string "En begivenhed kaldet Battle Swap\n"
	.string "afholdes der.\p"
	.string "Battle Swap-begivenheden tilbydes i to\n"
	.string "baner for ENKELT og DOPPELT KAMPE.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "Slagtpikken ligner et byggeri formet\n"
	.string "som en POKéMON i midten-venstre på\l"
	.string "FELTET FOR KAMPE.\p"
	.string "Et arrangement kaldet Kampvalget\n"
	.string "afholdes der.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "DEN KÆMPESTORE KAMPPIRAMIDE er den\n"
	.string "enorme pyramide.\p"
	.string "Et arrangement kaldet Kampquesten\n"
	.string "afholdes der.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "RANGHALLEN befinder sig nær KAMPENS\n"
	.string "TÅRN.\p"
	.string "Her kan du se de mest fantastiske\n"
	.string "rekorder sat af TRÆNERE, der har taget\l"
	.string "udfordringerne i KAMPENS FRONTIER.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "DEN BYTTE SERVICE HJØRNE er tæt på\n"
	.string "KAMPTÅRNET.\p"
	.string "Kamp Point du har tjent i KAMPFRONTEN\n"
	.string "kan udveksles til fantastiske præmier\l"
	.string "der.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Jeg er din guide til de grundlæggende\n"
	.string "regler, som er fælles for alle\l"
	.string "udfordringer, der tilbydes af\l"
	.string "faciliteterne i BATTLE FRONTIER.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Hvad vil du gerne lære om?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Alle udfordringerne på BATTLE\n"
	.string "FRONTIERs faciliteter kommer i to\l"
	.string "kurser--Level 50 og Åben Level.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "Niveau 50-banen er åben for POKéMON op\n"
	.string "til og med niveau 50.\p"
	.string "Husk dog, at ingen TRÆNER, du møder, vil\n"
	.string "have nogen POKéMON under niveau 50.\p"
	.string "Denne bane er begynderniveauet for\n"
	.string "kampe ved KAMPFRONTEN.\p"
	.string "For at begynde håber vi, du vil udfordre\n"
	.string "denne bane.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "Den Åbne Niveau bane sætter ingen\n"
	.string "begrænsninger på niveauer af POKéMON,\l"
	.string "der deltager i udfordringer.\p"
	.string "Dine modstanderes niveauer vil blive\n"
	.string "justeret til at matche dine POKéMONs\l"
	.string "niveauer.\p"
	.string "Dog vil ingen TRÆNER, du står overfor,\n"
	.string "have nogen POKéMON under Niveau 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Praktisk talt enhver type POKéMON kan\n"
	.string "tage udfordringerne på alle faciliteter.\p"
	.string "ÆG og visse typer POKéMON er dog ikke\n"
	.string "tilladt.\p"
	.string "Antallet af POKéMON, der kræves for\n"
	.string "udfordringer, vil afhænge af\l"
	.string "faciliteten.\p"
	.string "På alle faciliteter er det dog ikke\n"
	.string "tilladt med to eller flere af samme type\l"
	.string "POKéMON.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "Når du deltager i en udfordring på en\n"
	.string "KAMPFRONT facilitet, må POKéMON ikke\l"
	.string "holde den samme type genstand. Sørg\l"
	.string "venligst for, at alle POKéMON, der\l"
	.string "deltager i en udfordring, holder\l"
	.string "forskellige genstande.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Jeg er din guide til DEN VILDE VEST.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Hvad vil du gerne lære om?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "Der er syv faciliteter på BATTLE\n"
	.string "FRONTIER.\p"
	.string "TRÆNERE, der opnår anerkendelse for\n"
	.string "deres evner, kan belønnes med symboler\l"
	.string "fra hver af faciliteterne.\p"
	.string "For at tjene et symbol kan TRÆNERE\n"
	.string "blive nødt til at besejre andre TRÆNERE\l"
	.string "i træk, og måske endda vinde\l"
	.string "begivenheder gentagne gange.\p"
	.string "Det er bestemt ikke let at vinde\n"
	.string "symboler. Jeg ønsker dig al held og\l"
	.string "lykke!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Det er muligt at optage én kamp på din\n"
	.string "FRONTIER-PASS.\p"
	.string "Du kan optage en kamp, du har haft med\n"
	.string "en ven eller venner.\p"
	.string "Eller du kan optage en kamp udført ved\n"
	.string "BATTLE FRONTIER undtagen kampe ved\l"
	.string "BATTLE PIKE eller BATTLE PYRAMID.\p"
	.string "Du kan vælge at optage din kamp ved\n"
	.string "afslutningen af en kamp.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Kamp Point er belønninger givet til\n"
	.string "TRENERS, der kæmpede enestående på\l"
	.string "KAMPFRONTEN.\p"
	.string "Du kan ombytte dine Kamp Point til\n"
	.string "præmier i OMBYTNINGS SERVICEHJØRNET.$"



