@ TRANSLATED

MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy::
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.string "Min lillebror siger, at han kan lide at\n"
	.string "finde FOLKES HEMMELIGE BASE.$"

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.string "Min lillebror siger, at han kan lide at\n"
	.string "besøge folks HEMMELIGE BASE og have\l"
	.string "POKéMON kampe.$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.string "Var det dig, der lavede en HEMMELIG\n"
	.string "BASE nær {STR_VAR_1}?$"

MossdeepCity_House4_Text_MakeSecretBase:
	.string "Du burde lave en HEMMELIG BASE et sted.\n"
	.string "Jeg går ud og finder den!$"

MossdeepCity_House4_Text_Skitty:
	.string "SKITTY: Miav?$"



