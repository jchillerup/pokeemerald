@ TRANSLATED

VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "For enhver POKéMON kamp er X SPECIAL\n"
	.string "afgørende.\p"
	.string "Det øger styrken af visse angreb selvom\n"
	.string "det kun gælder for én kamp.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Det ser ud til, at de ikke sælger nogen\n"
	.string "vinderstrategiguider til KAMP- TALTET…\p"
	.string "Det ser ud til, at man må stole på sin egen\n"
	.string "kløgt alligevel…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "NESTE BOLD virker bedre på svækkede\n"
	.string "POKéMON.\p"
	.string "VERDANTURF er det eneste sted, du kan købe\n"
	.string "den.$"



