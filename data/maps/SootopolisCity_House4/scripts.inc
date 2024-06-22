@ TRANSLATED

SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Lyt godt efter, og jeg vil fortælle dig noget\n"
	.string "godt.\p"
	.string "Der siges at være en gammel ruine i havet\n"
	.string "omkring her.\p"
	.string "Der kunne være skatte, der bare venter på at\n"
	.string "blive opdaget dernede.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Gamle skatte…\p"
	.string "Det ville være dejligt, hvis de fandtes, men\n"
	.string "selv hvis de ikke gjorde, ville det være så\l"
	.string "smukt at tage en undervands spadseretur\l"
	.string "med mine POKéMON.$"

SootopolisCity_House4_Text_Azumarill:
.string "AZUMARILL: Marurii.$"



