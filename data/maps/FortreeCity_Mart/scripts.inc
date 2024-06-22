@ TRANSLATED

FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE
	release
	end

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.string "SUPER REPEL varer længe, og det klarer\n"
	.string "opgaven.\p"
	.string "Det er meget bedre end en almindelig REPEL.$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "Jeg køber altid flere ting end jeg er sikker\n"
	.string "på, jeg får brug for.\p"
	.string "Man ved aldrig, hvad der kan ske. Det er bedre\n"
	.string "at være på den sikre side!$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "En SJÆLDEN CANDY får en POKéMONgrow\n"
	.string "øjeblikkeligt med et niveau.$"



