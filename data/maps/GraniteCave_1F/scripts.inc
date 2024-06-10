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
	.string "Hey, du.\n"
	.string "Det bliver alvorligt mørkt fremad.\l"
	.string "Det bliver svært at udforske.\p"
	.string "Den fyr, der kom forbi tidligere…\n"
	.string "STEVEN, tror jeg det var.\p"
	.string "Han vidste, hvordan man bruger FLASH,\n"
	.string "så han burde nok være i orden, men…\p"
	.string "Nå, for os VANDRERE er det vores motto\n"
	.string "at hjælpe dem, vi møder.\p"
	.string "Her får du dette, jeg vil give det videre.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Lær den skjulte træk FLASH til\n"
	.string "en POKéMON og brug den.\p"
	.string "Den lyser endda op i den dybeste\n"
	.string "mørke i huler.\p"
	.string "Men for at bruge den, skal du have\n"
	.string "GYM BADGEN fra DEWFORD's POKéMON GYM.$"



