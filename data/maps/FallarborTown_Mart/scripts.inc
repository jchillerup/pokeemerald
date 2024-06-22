@ TRANSLATED

FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_NONE
	release
	end

FallarborTown_Mart_EventScript_Woman::
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve:
	.string "Jeg har svært ved at beslutte, om jeg skal\n"
	.string "lade min SKITTY udvikle sig eller ej.\p"
	.string "Jeg skal kun bruge denne MÅNESTEN, men det\n"
	.string "er så svært at beslutte…\p"
	.string "Hvis jeg lader den udvikle sig, vil den blive\n"
	.string "meget stærkere.\p"
	.string "Men den vil også se så anderledes ud.$"

FallarborTown_Mart_Text_Skitty:
	.string "SKITTY: Miyao?$"

FallarborTown_Mart_Text_SellNuggetIFound:
	.string "Denne NUGGET jeg fandt her… Jeg formoder,\n"
	.string "at jeg bliver nødt til at l sælge den, da den\l"
	.string "ikke har andre formål.$"



