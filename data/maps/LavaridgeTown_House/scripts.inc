@ TRANSLATED

LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "Min kone varmer et ÆG i de varme\n"
	.string "kilder. Det er hvad hun fortalte mig.\p"
	.string "Hun efterlod to POKéMON hos DAGPLEJEN.\n"
	.string "Og de opdagede det ÆG!$"

LavaridgeTown_House_Text_Zigzagoon:
.string "ZIGZAGOON: Pshoo!$" 




