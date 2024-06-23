@ TRANSLATED

BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "Hvad er det, du vil?\p"
	.string "Kan du ikke se, at vi er lidt travlt lige\n"
	.string "nu? Kan din forretning ikke vente til\l"
	.string "senere?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…Huh? Du ser ud til at være en sej\n"
	.string "TRÆNER.\p"
	.string "Heheh… Lyt, jeg har et forslag.\p"
	.string "Vi har en lille gruppe her, og vi spiller\n"
	.string "et lille spil med, hvad der foregår i\l"
	.string "BATTLE FRONTIER.\p"
	.string "Reglerne er virkelig simple.\p"
	.string "Først vælger vi en af faciliteterne i\n"
	.string "BATTLE FRONTIER.\p"
	.string "Derefter vælger vi hver en anden\n"
	.string "TRÆNER, som tager udfordringen i den\l"
	.string "facilitet, og better med vores Battle\l"
	.string "Points.\p"
	.string "Personen, der better på TRÆNEREN med\n"
	.string "den bedste rekord, vinder alle Battle\l"
	.string "Points i puljen.\p"
	.string "Lytter det simpelt, ikk'?  Nå, uanset\n"
	.string "hvad…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Det jeg leder efter, er en TRÆNER, som\n"
	.string "skal udfordre KAMP TÅRNETS ENKELTKAMP\l"
	.string "RUM.\p"
	.string "Men indtil videre har jeg ikke set en\n"
	.string "TRÆNER, der besidder den sejrende\l"
	.string "kvalitet.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Det, jeg leder efter, er en TRÆNER, der\n"
	.string "skal udfordre KAMP-TÅRNs DOUBLE\l"
	.string "BATTLE ROOMS.\p"
	.string "Men indtil videre har jeg ikke set en\n"
	.string "TRÆNER med den vindende kvalitet.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Det jeg leder efter, er en TRÆNER, der\n"
	.string "skal udfordre KAMP TÅRN's MULTI-KAMP-\l"
	.string "LOKALER.\p"
	.string "Men indtil videre har jeg ikke set en\n"
	.string "TRÆNER med den sejrende kvalitet.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Det jeg leder efter, er en TRÆNER som\n"
	.string "skal deltage i KAMPDOMENS\l"
	.string "ENKELTBATLE-turnering.\p"
	.string "Men indtil videre har jeg ikke set en\n"
	.string "TRÆNER med den vindende kvalitet.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Det, jeg leder efter, er en TRÆNER, som\n"
	.string "skal deltage i KAMPDOMENS\l"
	.string "DOBBELTKAMPSTURNERING.\p"
	.string "Men indtil videre har jeg ikke set en\n"
	.string "TRÆNER, der besidder den vindende\l"
	.string "kvalitet.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Hvad jeg leder efter, er en TRÆNER, der\n"
	.string "vil deltage i KAMPARENAENS Battle Swap\l"
	.string "Single Tourney.\p"
	.string "Men indtil videre har jeg ikke set en\n"
	.string "TRÆNER med den sejrende kvalitet.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Det jeg leder efter, er en TRÆNER, som\n"
	.string "skal deltage i KAMPFABRIKENS Battle\l"
	.string "Swap Double Turnering.\p"
	.string "Men indtil videre har jeg ikke set en\n"
	.string "TRÆNER med den vindende kvalitet.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Det, jeg leder efter, er en TRÆNER, som\n"
	.string "kommer til at udfordre KAMPALASETs\l"
	.string "ENKELTBATLHALLE.\p"
	.string "Men indtil videre har jeg ikke set en\n"
	.string "TRÆNER med den vindende kvalitet.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Det jeg leder efter, er en TRÆNER, der\n"
	.string "vil udfordre KAMPALs DOBBELTBATLE-\l"
	.string "HALLER.\p"
	.string "Men indtil videre har jeg ikke set en\n"
	.string "TRÆNER, der besidder den vindende\l"
	.string "kvalitet.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Det jeg leder efter, er en TRÆNER, som\n"
	.string "skal deltage i KAMPARENAs Set KO\l"
	.string "Tourney.\p"
	.string "Men indtil videre har jeg ikke set en\n"
	.string "TRÆNER, der har den vindende kvalitet.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Det jeg leder efter, er en TRÆNER der\n"
	.string "skal deltage i KAMPPIKENs Kamputvalg.\p"
	.string "Indtil videre har jeg dog ikke set en\n"
	.string "TRÆNER med den vindende kvalitet.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Det jeg leder efter, er en TRÆNER, som\n"
	.string "skal deltage i KAMP PYRAMIDENS\l"
	.string "Kamp-Quest.\p"
	.string "Men indtil videre har jeg ikke set en\n"
	.string "TRÆNER med den vindende kvalitet.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Jeg vil sørge for, at du også får gavn\n"
	.string "af det. Så hvad siger du?\p"
	.string "Hvad med at deltage i den begivenhed\n"
	.string "for mig?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Okay, det er perfekt. Så, øh... Hvad med\n"
	.string "at spotte mig nogle af dine Kamp Point?\p"
	.string "Tro mig, jeg vil vise dig min\n"
	.string "taknemmelighed bagefter.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Fantastisk, fantastisk! Så, hvor meget\n"
	.string "kan du spotte mig?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Åh, nej, nej, nej! Du har ikke nok Kamp\n"
	.string "Point!\p"
	.string "Jeg ville ønske, du ikke pjattede rundt\n"
	.string "og spildte alles tid!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Hihi! Mange tak! Så afsted med dig!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Kom til KAMPENS TÅRNs\n"
	.string "ENKELTKAMPSSALEN hurtigst muligt!\p"
	.string "Det er en skal-vinde-situation! Blæs\n"
	.string "ikke din chance! Vores fremtid afhænger\l"
	.string "af dig!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Kom hen til KAMP-TÅRNETS\n"
	.string "DOBBELTKAMMER hurtigst muligt!\p"
	.string "Det er en nødvendig sejr! Så ødelæg ikke\n"
	.string "din chance! Vores fremtider afhænger\l"
	.string "begge af dig!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Kom til KAMP TÅRNETS MULTI-KAMP\n"
	.string "LOKALER hurtigst muligt!\p"
	.string "Det er en must-win situation! Misbrug\n"
	.string "ikke din chance! Vores fremtid afhænger\l"
	.string "af dig!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Kom ind i KAMPDOMENS ENKELT KAMP\n"
	.string "Turnering hurtigt!\p"
	.string "Det er en skal-vinde situation! Blæs\n"
	.string "ikke din chance! Vores fremtid afhænger\l"
	.string "af dig!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Kom hen til KAMPDOMENs DOBBELTKAMP\n"
	.string "Turnering øjeblikkeligt!\p"
	.string "Det er en must-win situation! Mist ikke\n"
	.string "din chance! Vores fremtid afhænger af\l"
	.string "dig!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Kom til KAMPFABRIKKENS Battle Swap\n"
	.string "Single Turnering hurtigst muligt!\p"
	.string "Det er en skal-vinde situation! Blæs\n"
	.string "ikke din chance! Vores fremtid afhænger\l"
	.string "af dig!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Kom til KAMPFABRIKKENS Battle Swap\n"
	.string "Double Turnering hurtigst muligt!\p"
	.string "Det er en must-win-situation! Blæs ikke\n"
	.string "din chance! Vores fremtid afhænger af\l"
	.string "dig!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Kom nu hen til KAMPALLET's\n"
	.string "ENKELTSLAGSHALLER hurtigst muligt!\p"
	.string "Det er en must-win situation! Snyd ikke\n"
	.string "dig selv for chancen! Vores fremtid\l"
	.string "afhænger af dig!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Kom dig til KAMPALASET's DUAL KAMP\n"
	.string "HALLER pronto!\p"
	.string "Det er en must-win situation! Blæs ikke\n"
	.string "din chance! Vores fremtid afhænger af\l"
	.string "dig!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Kom til KAMPARENAEN's Klar til\n"
	.string "KO-turneringen pronto!\p"
	.string "Det er et must-win situation! Sørg for\n"
	.string "ikke at ødelægge din chance! Vores\l"
	.string "fremtid afhænger af dig!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Kom til KAMP LANCEN Vælg kampen pronto!\p"
	.string "Det er en skal-vinde situation! Snyd\n"
	.string "ikke dig selv for chancen! Vores fremtid\l"
	.string "afhænger af dig!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Kom til KAMP-PYRAMIDENs Kampopgave\n"
	.string "hurtigt!\p"
	.string "Det er en must-win situation! Blæs ikke\n"
	.string "din chance! Vores fremtid afhænger af\l"
	.string "dig!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Åh, det er dig… Godt forsøg…\p"
	.string "Jeg hader at skulle sige det til dig, men\n"
	.string "jeg kan ikke give dig dine Kamp Point\l"
	.string "tilbage…\p"
	.string "Jeg gætter på, at det må motivere os til\n"
	.string "at forsøge hårdere næste gang!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Åh, ja! Hej, champ!\p"
	.string "Jeg vidste, du kunne! Jeg vidste, du\n"
	.string "ville! Vi er begge store vindere!\p"
	.string "Jeg vil returnere dine Kamp Point og,\n"
	.string "selvfølgelig, lidt ekstra fra mig!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} fik {STR_VAR_1} Kamp\n"
	.string "Point.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Hvis du er klar til endnu en udfordring,\n"
	.string "så tænk endelig på mig!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Ikke interesseret?! Du behøver ikke \n"
	.string "være så bange for at tage en chance!$"

BattleFrontier_Lounge3_Text_Oh::
.string "Åh...$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "Jeg støttede den forkerte TRÆNER igen!\p"
	.string "Måske burde jeg kæmpe normalt ligesom\n"
	.string "alle andre…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "Den TRÆNER…\p"
	.string "Han er god, men han bliver alt for let\n"
	.string "oprevet for at overleve KAMPDOME…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Hihi! Jeg kender en vinder, når jeg ser\n"
	.string "en!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Disse TRÆNERE… Hvad laver de? De burde\n"
	.string "tage udfordringer.$"



