@ TRANSLATED

RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Hvad? Min POKéMON er sød? Selvfølgelig\n"
	.string "vidste jeg det.\p"
	.string "Men hvis du virkelig vil, er jeg villig til\n"
	.string "at bytte den med dig.\p"
	.string "Jeg bytter min {STR_VAR_2} for en\n"
	.string "{STR_VAR_1}, hvis du vil.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Hihihi... Vær sød ved min POKéMON.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hvad? Det ligner overhovedet ikke en\n"
	.string "{STR_VAR_1} for mig.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Åh, hvis du ikke har lyst, er det okay.\n"
	.string "Men min POKéMON er sød, ved du…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "du opdrager den med omhu og venlighed.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "På alle mulige steder er der alle mulige\n"
	.string "POKéMON og mennesker.\p"
	.string "Jeg synes, at det er fascinerende, så\n"
	.string "jeg besøger alle mulige steder.$"



