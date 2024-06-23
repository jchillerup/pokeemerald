@ TRANSLATED

MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "Hmm! Din {STR_VAR_1}…$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "Den kan lide {STR_VAR_1}ER, ikke\n"
	.string "sandt?\p"
	.string "Nej, jeg er helt sikker på det! Den kan\n"
	.string "absolut lide {STR_VAR_1}ER!$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "Det ser ikke ud til at kunne lide eller\n"
	.string "lide af nogen {POKEBLOCK}S.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "Min mand kan straks se, hvilken slags\n"
	.string "{POKEBLOCK}S en POKéMON kan lide.$"



