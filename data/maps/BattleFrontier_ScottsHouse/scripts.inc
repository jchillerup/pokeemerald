@ TRANSLATED

.set LOCALID_SCOTT, 1

BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
	.string "SCOTT: Nå, hej og velkommen!\n"
	.string "Heheh... Undskyld det trange rum.\p"
	.string "{PLAYER}{KUN}, Lad mig officielt\n"
	.string "byde dig velkommen til BATTLE FRONTIER.\p"
	.string "Det her er min drøm, der er gået i opfyldelse.\n"
	.string "Det tog mig år og år, men jeg har\l"
	.string "endelig givet liv til min drøm.$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
	.string "På refleksion var det en forfærdelig\n"
	.string "lang rejse…\p"
	.string "Jeg forlod hjemmet alene på en\n"
	.string "mission for at finde stærke\n"
	.string "TRÆNERE.\p"
	.string "Ingen kan forestille sig, hvor meget\n"
	.string "anstrengelse eller tid det tog for\n"
	.string "at gøre dette til virkelighed.$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
	.string "Men det er fortid.\n"
	.string "Der er ingen grund til at dvæle ved det!\p"
	.string "Alt hvad jeg ønsker for dig er at nyde at kæmpe\n"
	.string "til dit hjerte's indhold her.\p"
	.string "{PLAYER}{KUN}, jeg ønsker at give dig dette\n"
	.string "som et minde for al den tid vores\l"
	.string "stier krydsedes på vores rejser.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.string "{PLAYER} fik\n"
	.string "{STR_VAR_1} Kamp Point(er).$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
	.string "SCOTT: Du kan tjekke dine Kamp\n"
	.string "Points på din FRONTIER-PAS.\p"
	.string "Jo mere succes du har her på\n"
	.string "KAMPFRONTEN, jo flere Kamp\l"
	.string "Points vil du samle.\p"
	.string "Brug dine Kamp Points, som du\n"
	.string "finder passende, f.eks. bytte dem til genstande.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
.string "Jeg forventer store ting fra dig!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
	.string "SCOTT: Enhver TRÆNER er en individuel.\n"
	.string "De fører alle deres egne liv.\p"
	.string "Men når de er i kamp,\n"
	.string "så betyder det ikke, hvem de er.\p"
	.string "De er alle ens!\p"
	.string "Jeg elsker kampens renhed,\n"
	.string "hvor alle er ligeværdige.\p"
	.string "Derfor rejser jeg overalt for at finde\n"
	.string "TRÆNERE, der er seriøse omkring\l"
	.string "kampe, og inviterer dem her.$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
	.string "SCOTT: Har du mødt nogen af\n"
	.string "FRONTIER BRAINS?\p"
	.string "Endnu bedre, har du opnået nogen\n"
	.string "symboler fra dem?\p"
	.string "Jeg udvalgte FRONTIER BRAINS\n"
	.string "som de hårdeste TRÆNERE nogensteds.\p"
	.string "Men jeg er sikker på, at når de\n"
	.string "ser, hvor sej du er, vil det\n"
	.string "overraske selv dem!$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
	.string "SCOTT: Du træner ikke kun til kamp,\n"
	.string "vel?\p"
	.string "Jeg tror, jeg husker, at du også\n"
	.string "arbejdede på en POKéDEX.\p"
	.string "Nå, gæt hvad?\p"
	.string "Du kan støde på vilde POKéMON et\n"
	.string "eller andet sted i KAMPFRONTEN…\l"
	.string "Fufufu!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
	.string "SCOTT: Nyder du tingene i\n"
	.string "BATTLE FRONTIER?\p"
	.string "…Vent lige…\n"
	.string "Åh!\p"
	.string "Din FRONTIER-PAS!\n"
	.string "Du har samlet hele sættet\l"
	.string "af sølvsymboler!\p"
	.string "Det er mere end imponerende!\n"
	.string "Du er sej, præcis som jeg havde mistanke om!\p"
	.string "Normalt ville jeg ikke gøre noget\n"
	.string "som dette, men det her er en særlig lejlighed!\p"
	.string "Jeg vil gerne give dig dette.\n"
	.string "Jeg er sikker på, du kan bruge det på en god måde.$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
	.string "SCOTT: Jeg håber, at du nyder\n"
	.string "alt i BATTLE FRONTIER.\p"
	.string "…Vent lige…\n"
	.string "Åh, mine vantro øjne!\p"
	.string "Din FRONTIER-PAS!\n"
	.string "Du har samlet hele sættet\l"
	.string "af guld-symboler!\p"
	.string "Det er mere end fantastisk!\n"
	.string "Du er utrolig, præcis som jeg\n"
	.string "havde mistænkt!\p"
	.string "… … … … … …\p"
	.string "{PLAYER}, du bliver nødt til at\n"
	.string "acceptere dette!\p"
	.string "Jeg tror, at du vil kunne\n"
	.string "være værdsat af min gave!$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
	.string "Jeg må sige, at jeg har gaven at vide\n"
	.string "hvornår jeg ser en god TRÆNER.\p"
	.string "Jeg er så glad for, at jeg havde\n"
	.string "forudseenheden at bringe dig her!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
	.string "Din BÆRTASKE virker til at\n"
	.string "være proppet.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
	.string "SCOTT: Åh, jeg har hørt om dig!\n"
	.string "Hvordan du regerede KAMP TÅRNET!\l"
	.string "Har du slået over 50 TRÆNERE i træk?\p"
	.string "Det er fantastisk!\n"
	.string "Jeg vil have dig til at have dette!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
	.string "SCOTT: Åh, du! Jeg har hørt om dig!\n"
	.string "Hvordan du overvandt KAMPTÅRNET!\l"
	.string "Du slog over 100 TRÆNERE i træk?\p"
	.string "Det er vanvittigt spektakulært!\n"
	.string "Du skal bare have dette!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
	.string "Jeg ser frem til at høre endnu større\n"
	.string "ting om dig nu!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
	.string "Ups, nå, hvis du har for meget\n"
	.string "grej, så kom tilbage senere.$"



