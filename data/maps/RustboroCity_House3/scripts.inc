@ TRANSLATED

RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "For mine POKéMON giver jeg dem perfekt\n"
	.string "passende kælenavne!\p"
	.string "Det er udtryk for min, øh… originalitet,\n"
	.string "ja, dét er det!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Men at give navnet POKEMON til en\n"
	.string "PIKACHU? Det virker pointløst.\p"
	.string "Jeg antager, det er godt at bruge et\n"
	.string "navn, der er let at forstå, men…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Pika!$"



