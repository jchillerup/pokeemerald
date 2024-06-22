@ TRANSLATED

MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "Lærer… Vær venlig at følge med i min\n"
	.string "fremgang!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "Lærer… Vil du tilgive mig?$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Indtil jeg bliver bedre, vil min lærer, som\n"
	.string "hviler her, aldrig finde sand fred…$"



