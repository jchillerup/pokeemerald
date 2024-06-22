@ TRANSLATED

DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Slå dig løs med dette!\p"
	.string "Det er et SILKESJAL. Det er lige på\n"
	.string "modefronten, ja!\p"
	.string "Åh, jeg kan se dine øjne funkler! Du\n"
	.string "værdsætter min blændende stil!\p"
	.string "Åh, du er en fornøjelse! Her har du. Jeg vil\n"
	.string "gerne give dig det!$"

DewfordTown_House2_Text_NoRoom:
	.string "Åh, du har ikke plads?\p"
	.string "Nu skal du høre, dette TØRKLÆDE er et\n"
	.string "must-have! Jeg ville endda sælge alle mine\l"
	.string "ting for at få det!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "SILK SCARF øger styrken af NORMAL-type\n"
	.string "angreb.\p"
	.string "Det er et fantastisk TØRKLÆDE, som vil\n"
	.string "klæde næsten alle POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wow, du besværede dig med at krydse havet\n"
	.string "for at besøge DEWFORD?\p"
	.string "Kom du måske hertil, fordi du hørte om\n"
	.string "BRAWLY?\p"
	.string "Han er så sej… Alle idoliserer ham.$"



