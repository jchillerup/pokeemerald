@ TRANSLATED

GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hey, du. Det bliver alvorligt mørkt fremad.\n"
	.string "Det bliver svært at udforske.\p"
	.string "Den fyr, der kom forbi tidligere… STEVEN,\n"
	.string "tror jeg det var.\p"
	.string "Han vidste, hvordan man bruger FLASH, så\n"
	.string "han burde nok være i orden, men…\p"
	.string "Nå, for os VANDRERE er det vores motto at\n"
	.string "hjælpe dem, vi møder.\p"
	.string "Her får du dette, jeg vil give det videre.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Lær den skjulte træk FLASH til en POKéMON og\n"
	.string "brug den.\p"
	.string "Den lyser endda op i den dybeste mørke i\n"
	.string "huler.\p"
	.string "Men for at bruge den, skal du have GYM\n"
	.string "BADGEN fra DEWFORD's POKéMON GYM.$"



