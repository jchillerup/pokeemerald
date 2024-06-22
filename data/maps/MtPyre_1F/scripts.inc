@ TRANSLATED

MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Alle slags væsner vandrer op ad MT. PYRE…\p"
	.string "Det er umuligt at vide, hvad der kan ske. Tag\n"
	.string "dette. Det er til dit eget bedste.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Få en POKéMON til at holde en RENSE TAG.\p"
	.string "Det vil hjælpe med at skræmme vilde POKéMON.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Kom du for at vise respekt til ånderne af\n"
	.string "afdøde POKéMON?\p"
	.string "Du må virkelig passe godt på dine POKéMON.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Dette er det endelige hvilested for min\n"
	.string "ZIGZAGOON. Jeg satte pris på det...$"



