@ TRANSLATED

MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "REVIVE er fantastisk!\p"
	.string "Giv det til en besvimet POKéMON, og\n"
	.string "POKéMON vil genopstå.\p"
	.string "Men vær forsigtig, REVIVE genopretter\n"
	.string "ikke de brugte PP af angrebene.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "MAX REPEL holder alle svage POKéMON\n"
	.string "væk.\p"
	.string "Af alle REPEL-sprays varer den længst.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "NET- og DYKKERKUGLERNE er sjældne\n"
	.string "POKéKUGLER, som kun laves i MOSSDEEP.\p"
	.string "En NETKUGLE er effektiv mod BUG-type\n"
	.string "og VAND-type POKéMON.\p"
	.string "En DYKKERKUGLE fungerer bedst på\n"
	.string "POKéMON på havets bund.$"



