@ TRANSLATED

FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Wrooooaaar! Jeg har brug for det! Jeg skal\n"
	.string "have fat i en {STR_VAR_1}! Jeg vil gøre\l"
	.string "alt for det!\p"
	.string "…Uh… Hørte du det? Mit råb fra bunden af mit\n"
	.string "hjerte?\p"
	.string "Efter at have hørt det, vil du bytte din\n"
	.string "{STR_VAR_1} for min {STR_VAR_2},\l"
	.string "vil du ikke?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Åh ja, lige på!\p"
	.string "{STR_VAR_1}, velkommen!\n"
	.string "{STR_VAR_2}, pas på dig selv!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Uh, nej, det tror jeg ikke. Det er ikke en\n"
	.string "{STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "Nej? Vil du ikke handle med mig? Selv efter\n"
	.string "jeg åbnede mit hjerte for dig?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "Jeg vil gøre VOLBEAT super stærk fra dette\n"
	.string "øjeblik af!\p"
	.string "Jeg håber, du gør det samme med PLUSLE!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "At bytte POKéMON med andre…\p"
	.string "Det er som om, du bytter dine egne minder med\n"
	.string "andre mennesker.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gummigum?$"



