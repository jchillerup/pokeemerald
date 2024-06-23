@ TRANSLATED

BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "Min POKéMON er en {STR_VAR_2}.\n"
	.string "Kender du den? Den er ret sød og ret rar.\p"
	.string "Denne lille fyr, jeg kunne bytte med\n"
	.string "stolthed!\p"
	.string "Vil du bytte mig en {STR_VAR_1} for\n"
	.string "min {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "Åh, hvor er den sød! Tak! Jeg lover, jeg\n"
	.string "vil passe godt på den!\p"
	.string "Åh! Jeg håber, du også vil være god ved\n"
	.string "min {STR_VAR_2}!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "Åh, undskyld! Jeg har ikke til hensigt\n"
	.string "at handle for andet end en\l"
	.string "{STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "Åh, vil du ikke? Nå, det er også fint.\n"
	.string "Besøg os igen, tak.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "Grin! En SKITTY er meget sødere end jeg\n"
	.string "havde forestillet mig. Jeg er henrykt!$"



