@ TRANSLATED

MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "Jeg elsker alt skræmmende… Det er\n"
	.string "ligesom en sygdom…\p"
	.string "Når jeg er her… Jeg ryster af skræk…$"

MtPyre_4F_Text_TashaDefeat:
	.string "At tabe, det bryder jeg mig ikke om...$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Jeg vil gerne se frygtelige ting… Jeg\n"
	.string "kan ikke gå…\p"
	.string "Bliv… Vil du ikke blive hos mig?$"



