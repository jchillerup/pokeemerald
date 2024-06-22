@ TRANSLATED

SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Min POKéMON har en HURTIG natur.\p"
	.string "Den har højere HASTIGHED i forhold til mine\n"
	.string "andre POKéMON.\p"
	.string "Måske har deres natur noget at gøre med\n"
	.string "POKéMONs statistikstigninger.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Du er en TRÆNER, ikke sandt?\p"
	.string "Siden du er kommet til SLATEPORT CITY, må du\n"
	.string "være på vej til KAMPSTED.$"



