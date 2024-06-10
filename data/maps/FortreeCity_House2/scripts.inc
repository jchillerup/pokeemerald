@ TRANSLATED

FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Folk… POKéMON…\p"
	.string "Der intetanende kræfter bliver\n"
	.string "vakt i dem, når de lever i\n"
	.string "naturlige omgivelser…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Lad denne gamle kvinde se, om din\n"
	.string "skjulte kraft er vågnet…\p"
	.string "Jeg holder en mønt i min hånd.\p"
	.string "Nu, sig mig, har jeg den i\n"
	.string "højre hånd? Eller i den venstre?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Åh! Ja, korrekt!\p"
	.string "Vi skal prøve igen.\p"
	.string "I hvilken hånd har jeg gemt mønten?\n"
	.string "Den højre eller venstre?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Åh! Ja, rigtigt!\p"
	.string "Vi prøver igen.\p"
	.string "I hvilken hånd har jeg skjult mønten?\n"
	.string "I højre eller venstre?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Åh! Fremragende!\n"
	.string "Din skjulte kraft er blevet vækket!\p"
	.string "Her, tag dette og væk op den skjulte\n"
	.string "kraft af din POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "SKJULT KRAFT er et angreb, der ændrer sig\n"
	.string "sammen med POKéMON’en.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Nej, desværre.\n"
	.string "Du gættede forkert.$"



