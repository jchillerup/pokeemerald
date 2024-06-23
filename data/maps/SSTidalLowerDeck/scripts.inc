@ TRANSLATED

SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Åh nej! Jeg er godt træt og sur af at\n"
	.string "skulle gøre rent her hele tiden!\p"
	.string "Skal vi ikke i stedet kæmpe en hurtig\n"
	.string "kamp?$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Lillebror, jeg tabte!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Vi er RENGØRINGSBRØDRENE!\p"
	.string "Den ældre hælder sæben ud, og den yngre\n"
	.string "gør rent!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Dette er bunden af skibets skrog. Der\n"
	.string "er masser af plads.\p"
	.string "Det skal nok gå til en POKéMON kamp.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Storebror, jeg tabte!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Vi er RENGØRINGSBRØDRENE!\p"
	.string "Den ældre hælder sæben ud, og den yngre\n"
	.string "gør rent!$"



