@ TRANSLATED

.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "Dette er KAMPDOMEN!\n"
	.string "Din vej til den uovervindelige superstjerne!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "Dette er KAMPFABRIKKEN!\n"
	.string "Find de sejeste POKéMON!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "Dette er KAMPFISKEN!\n"
	.string "Vælg en af tre stier!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Dette er KAMP TÅRNET.\p"
	.string "TRÆNERE bringer deres bedst-opdrættede\n"
	.string "POKéMON til eliminationskampe.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Hej, er du her for færgen?\n"
	.string "Må jeg se din BILLET?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} har ikke BILLETEN…\p"
	.string "Jeg er virkelig ked af det.\p"
	.string "Du skal have en BILLET for at\n"
	.string "komme om bord på færgen.$" ​​​​​

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} blinke{\r}de billetten.\p"
	.string "Perfekt! Det er alt, du behøver!\p"
	.string "Og hvor vil du gerne rejse hen?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
.string "SLATEPORT CITY det bliver!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
.string "LILYCOVE BY it is, så!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Vil du ikke sejle med os en anden gang, ven?$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Vær sød at gå om bord på færgen og\n"
	.string "vente på afgang.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Hvor vil du gerne gå hen?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Jeg er den bedste af alle mine venner.\n"
	.string "Men her...\p"
	.string "Jeg har været ubrugelig!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Jeg vil gerne til KAMPTÅRNET,\n"
	.string "men jeg kan ikke finde det, selvom jeg\n"
	.string "har et kort over KAMPFRONTEN.\p"
	.string "Dette sted er bare for stort!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Jeg ville tage en udfordring lige\n"
	.string "så snart jeg ankom her.\p"
	.string "Men på vejen blev jeg søsyg…\n"
	.string "Buuurp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Det er ikke ligesom, at hvem som\n"
	.string "helst kan komme her, ved du nok?\p"
	.string "Kun de TRÆNERE, der er blevet\n"
	.string "anerkendt som seje, bliver bragt herhen.\p"
	.string "Derfor ved mange TRÆNERE ikke engang\n"
	.string "om KAMPFRONTIEREN.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Hey, bro…\p"
	.string "Er du sikker på, at vi kan lave\n"
	.string "udfordringer selvom vi ikke har nogen POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Uh…\n"
	.string "Jeg er sikker på, det skal nok gå.\p"
	.string "Jeg tror…\p"
	.string "Men husker du den store skræmmende fyr?\n"
	.string "Han sagde, “Jeg vil låne dig POKéMON!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "Det er KAMPFABRIKKEN.\n"
	.string "Her kan du leje stærke POKéMON.\p"
	.string "Men det får mig til at undre mig.\n"
	.string "Hvem træner de lejede POKéMON?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "Jeg er bange for at gå ind i KAMP\n"
	.string "PIKEN på grund af SEVIPER…\p"
	.string "M-m-men jeg er kommet helt herhen,\n"
	.string "så jeg vil prøve at erobre alt!\l"
	.string "…Gråd…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Skal vi spille sten, saks, papir?\n"
	.string "En, to, tre!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Jubii! Jeg vandt!\n"
	.string "Jeg vil tage BATTLE PIKE udfordringen!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Åh nej…\n"
	.string "Jeg tabte.\p"
	.string "Jeg gætter på, at jeg ikke er særlig heldig i dag.\n"
	.string "Jeg vil udskyde min KAMP LANSE udfordring\l"
	.string "til i morgen.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Jeg tror, jeg er den eneste person her,\n"
	.string "som af en eller anden ukendt årsag,\l"
	.string "ville vælge at fiske frem for at\l"
	.string "kæmpe.\p"
	.string "Hvad? Kan du ikke fange noget her?\n"
	.string "Det er skuffende...$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "I dag vil jeg blive ved med at kæmpe,\n"
	.string "uanset hvad, indtil jeg får et Symbol.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Åh? Skal du udfordre\n"
	.string "KAMPDOMEN?\p"
	.string "Jeg ønsker dig al held og lykke.\n"
	.string " Lad os begge vinde vores vej op\n"
	.string " og mødes i udfordringerne.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Bedstefar, kom herover!\n"
	.string "KAMPDOMEN er her!\l"
	.string "Kom så, Bedstefar!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Åh, så det her er KAMPDOMEN?\n"
	.string "Jeg vil ikke lade HERRERNE slå mig!\p"
	.string "Men hvor er indgangen?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string ""Der plejede ikke at være noget her for\n"
	.string "så længe siden.\p"
	.string "Men se nu dette sted! Fantastisk!\n"
	.string "Jeg vil bringe min mor ud for at se dette.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Jeg er endelig nået til KAMP\n"
	.string "FRONTEN!\p"
	.string "Jeg er sikker på at tiltrække\n"
	.string "opmærksomhed med mit udseende\n"
	.string "og evner!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Mums, mums…\p"
	.string "Det ser ud til, at dette område er fyldt\n"
	.string "med seje mennesker.\p"
	.string "Mums, mums…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Knas, smask…\p"
	.string "For lidt tid siden mødte jeg en\n"
	.string "ældre pige på KAMPPILEN.\p"
	.string "Hun havde de her øjne, som var\n"
	.string "skræmmende på en virkelig slem måde.\p"
	.string "Knas, smask…\p"
	.string "Hun blev rasende: “Vil du holde\n"
	.string "op med at spise!” Så gik hun løs på mig.\p"
	.string "Det var en gyselig slags\n"
	.string "skræmmende oplevelse, helt sikkert.\p"
	.string "Knas, smask…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Hvad? Vil du høre dig selv?\n"
	.string "Det er ingenting!\p"
	.string "Sidste gang jeg heppede på ham,\n"
	.string "mødtes vores øjne, og gnister fløj!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Hvaaaaaaat?!\n"
	.string "Pfft!\p"
	.string "Det skete kun fordi jeg\n"
	.string "sad ved siden af dig!\p"
	.string "DOME ACE kiggede kun vores vej,\n"
	.string "fordi jeg heppede så højt!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Åh, hold nu kæft!\n"
	.string "Hold larmen nede!\p"
	.string "I skulle holde jer til at heppe\n"
	.string "på nogle GYM LEADERS!\p"
	.string "DOME ACE er min!\n"
	.string "Den eneste idol for mig!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "De personer, der skændes derovre…\p"
	.string "Det er svært at tro, men de var\n"
	.string "TRÆNERE, og gode også.\p"
	.string "De plejede at være utroligt seje,\n"
	.string "og de var også berømte.\p"
	.string "Men de blev udslettet af denne\n"
	.string "bestemte TRÆNER under en turnering.\p"
	.string "De blev så grundigt slået,\n"
	.string "at de blev betaget af TRÆNEREN.\p"
	.string "Nu er de bare fans af TRÆNEREN.\n"
	.string "De hepper på deres idol i\l"
	.string "KAMPDOMEN hver dag nu.$"  

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Jeg har hørt et rygte om, at nogen så\n"
	.string "en POKéMON med en usædvanligt lang hale\l"
	.string "et sted i BATTLE FRONTIER.\p"
	.string "Den må være sød. Jeg er sikker på det…\p"
	.string "Åh, udfordringer kan vente. Jeg føler\n"
	.string "mig drevet til at finde det dejlige væsen!$"



