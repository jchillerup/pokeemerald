@ TRANSLATED

SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Hej, hej! Jeg er NAVNEVURDEREN!\n"
	.string "Jeg er navne-spåmanden!\p"
	.string "Jeg vil med glæde vurdere dit\n"
	.string "POKéMONs kaldenavn.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Hvilket POKéMON's kælenavn skal\n"
	.string "jeg kritisere?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, er det? Det er\n"
	.string "et ganske fint navn du har valgt.\p"
	.string "Men! Hvad siger du til, hvis jeg\n"
	.string "foreslår et lidt bedre navn?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Åh, godt. Hvad skal det nye\n"
	.string "kaldenavn være?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Færdig! Fra nu af vil denne POKéMON\n"
	.string "blive kendt som {STR_VAR_1}!\p"
	.string "Det er et bedre navn end før!\n"
	.string "Hvor heldig du er!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Jeg forstår.\n"
	.string "Kom gerne og besøg igen.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Færdig! Fra nu af skal denne POKéMON\n"
	.string "være kendt som {STR_VAR_1}!\p"
	.string "Den ser ikke anderledes ud end før,\n"
	.string "og dog er den markant bedre!\p"
	.string "Hvor heldig for dig!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmm ... {STR_VAR_1} det er!\p"
	.string "Dette er et pragtfuldt kælenavn!\n"
	.string "Det er utroligt ud over enhver kritik!\p"
	.string "Du vil gøre klogt i at værdsætte dit\n"
	.string "{STR_VAR_1} nu og i fremtiden.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Nu, nu.\n"
	.string "Det er bare et ÆG!$"



