@ TRANSLATED

.set LOCALID_OLD_WOMAN, 2

BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "Vi kom her for at være forsigtige med\n"
	.string "vores barnebarn.\p"
	.string "Men siden vi er her, tænkte vi, at vi\n"
	.string "burde få nogle souvenirs.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Kære, hvad synes du om dette? Ville\n"
	.string "dette ikke være en fin gave?\p"
	.string "Det er…PRO…TE…IN? Det lyder lækkert,\n"
	.string "gør det ikke?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "En stor del af SLAGETS FRONTIER's\n"
	.string "faciliteter tillader ikke brugen af\l"
	.string "genstande under kampe.\p"
	.string "Den regel gør tingene sværere end de\n"
	.string "allerede er!$"



