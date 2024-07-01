@ TRANSLATED

Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	waitstate
	end

Roulette_Text_PlayMinimumWagerIsX::
	.string "Det mindste bet på dette bord er\n"
	.string "{STR_VAR_1}. Vil du spille?$"

Roulette_Text_NotEnoughCoins::
.string "Du har ikke nok MØNTER.$"

Roulette_Text_SpecialRateTable::
.string "Særlig prisoversigt lige nu!$"

Roulette_Text_ControlsInstruction::
	.string "Placer dit væddemål med + Kontrol Pad,\n"
	.string "og tryk derefter på A-knappen.$"

Roulette_Text_ItsAHit::
.string "Det rammer plet!$"

Roulette_Text_Jackpot::
	.string "Jackpot!$"

Roulette_Text_NothingDoing::
	.string "Ingenting sker!$"

Roulette_Text_YouveWonXCoins::
	.string "Du har vundet {STR_VAR_1} MØNTER!$"

Roulette_Text_NoCoinsLeft::
	.string "Ingen MØNTER tilbage…$"

Roulette_Text_KeepPlaying::
	.string "Fortsæt med at spille?$"

Roulette_Text_BoardWillBeCleared::
.string "Roulettespillet vil blive ryddet op.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "Du har ikke en MØNTHOLDER.$"

Roulette_Text_CoinCaseIsFull::
	.string "Din MØNTSAMLING er fuld! Mønter kan\n"
	.string "byttes til præmier.$"



