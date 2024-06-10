@ TRANSLATED

MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Hvad, hvad, hvad?\p"
	.string "Kun TEAM MAGMA medlemmer skulle være\n"
	.string "herinde!\p"
	.string "Men du er ikke iført TEAM MAGMA's\n"
	.string "uniform…\p"
	.string "Du vækker min mistanke!\n"
	.string "Kæmp med mig!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aiyiyi…\n"
	.string "Min stolthed som et TEAM MAGMA medlem…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Hvis du lider af kuldegysninger, bør du\n"
	.string "melde dig til TEAM MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Stop lige der!\p"
	.string "Du forventer vel ikke,\n"
	.string "at jeg bare lukker og lader dig gå forbi?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Åh wow!\n"
	.string "Jeg giver op!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Måske det ville have været bedre, hvis jeg\n"
	.string "bare lod dig gå udfordringsløs…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Ahah!\n"
	.string "En indtrænger!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
.string "Graaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Jeg har allerede tabt.\p"
	.string "Skal jeg virkelig blive ved med at\n"
	.string "løbe rundt i en cirkel?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Åh, åh!\n"
	.string "En indtrænger!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
.string "Mor...$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
.string "Faktisk er jeg ikke nogen ekspert i at kæmpe...$"



