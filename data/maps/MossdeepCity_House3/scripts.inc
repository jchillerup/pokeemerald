@ TRANSLATED

MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Hej TRÆNER! En SUPER STANG er virkelig\n"
	.string "super!\p"
	.string "Sig alt det du vil, men denne her kan fange\n"
	.string "POKéMON fra havbunden!\p"
	.string "Hvad synes du? Du vil gerne have den, ikke?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Selvfølgelig, selvfølgelig! En SUPER STANG\n"
	.string "er virkelig super!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Hvis der er vand, så prøv at slippe din STANG\n"
	.string "ned og se hvad der bider!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hvad? Kan du ikke lide at fiske?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Jag dem på havets bund med din SUPERSTANG.$"



