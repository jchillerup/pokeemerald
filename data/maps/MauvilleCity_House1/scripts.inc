@ TRANSLATED

MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Jubiii!\p"
	.string "Jeg hører folk kalder mig STENKNUSER-\n"
	.string "FYREN, men jeg synes det er lidt nedværdi-\n"
	.string "gende.\p"
	.string "Jeg synes, jeg fortjener lidt mere respekt,\n"
	.string "måske STENKNUSEREN.\p"
	.string "Jubiii!\p"
	.string "Nå, dine POKéMON ser ret\n"
	.string "stærke ud.\p"
	.string "Det kan jeg lide!\n"
	.string "Her, tag denne SKJULTE MASKINE!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Den HM indeholder ROCK SMASH.\p"
	.string "Hvis du støder på store stenblokke\n"
	.string "som blokerer din vej…\p"
	.string "Ja, brug den HM-færdighed og knus\n"
	.string "dem lige væk fra din vej!\p"
	.string "Ja, sir! Knus stenene til siden, siger jeg!\n"
	.string "Jubiii!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Åh, ja, hvis du smadrer en sten, kan en POKéMON\n"
	.string "komme flyvende ud af sit skjul.\p"
	.string "Jubii!$"



