@ TRANSLATED

FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "Træhusene i SKOVHAVEN er fantastiske!\p"
	.string "Jeg tror, det er den bedste by til at bo\n"
	.string "sammen med POKéMON.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "POKéMON og mennesker har tilpasset sig\n"
	.string "naturen for at overleve.\p"
	.string "Der er ingen grund til at få naturen til at\n"
	.string "tilpasse sig den måde, vi ønsker at leve på.$"

FortreeCity_House5_Text_Zigzagoon:
.string "ZIGZAGOON: Bufuu!$"



