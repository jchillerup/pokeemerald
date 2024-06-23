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
	.string "FYREN, men jeg synes det er lidt\l"
	.string "nedværdi- gende.\p"
	.string "Jeg synes, jeg fortjener lidt mere\n"
	.string "respekt, måske STENKNUSEREN.\p"
	.string "Jubiii!\p"
	.string "Nå, dine POKéMON ser ret stærke ud.\p"
	.string "Det kan jeg lide! Her, tag denne SKJULTE\n"
	.string "MASKINE!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Den HM indeholder ROCK SMASH.\p"
	.string "Hvis du støder på store stenblokke som\n"
	.string "blokerer din vej…\p"
	.string "Ja, brug den HM-færdighed og knus dem\n"
	.string "lige væk fra din vej!\p"
	.string "Ja, sir! Knus stenene til siden, siger\n"
	.string "jeg! Jubiii!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Åh, ja, hvis du smadrer en sten, kan en\n"
	.string "POKéMON komme flyvende ud af sit skjul.\p"
	.string "Jubii!$"



