@ TRANSLATED

PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Tjek denne {STR_VAR_2} ud!\p"
	.string "Det er {STR_VAR_2}'en, jeg fangede\n"
	.string "i går for at fejre min fødselsdag!\p"
	.string "Åh, jeg kan se, at du gerne vil have den!\n"
	.string "Den er trods alt uvurderlig!\p"
	.string "Jeg skal fortælle dig noget. Jeg er muligvis\n"
	.string "villig til at bytte den for en {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Åh, så det her er en {STR_VAR_1}?\p"
	.string "Det er lidt ligesom en {STR_VAR_2},\n"
	.string "og alligevel er den subtilt forskellig.\p"
	.string "Tak!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Nej, nej, nej! Jeg accepterer ikke"
	.string "mindre end en rigtig {STR_VAR_1}!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Åh, så du vil ikke gå igennem\n"
	.string "med dette?\p"
	.string "Det er helt i orden. Jeg er ikke desperat\n"
	.string "efter at lave en handel eller noget.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Jeg ved, at jeg kunne lede efter en\n"
	.string "selv, men…\p"
	.string "Men jeg vil virkelig gerne have en BAGON\n"
	.string "som en anden TRÆNER har fanget…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Er det en POKéDEX?\p"
	.string "Har du mødt mange forskellige\n"
	.string "POKéMON?\p"
	.string "Jeg ville ønske, jeg var ligesom dig.$"



