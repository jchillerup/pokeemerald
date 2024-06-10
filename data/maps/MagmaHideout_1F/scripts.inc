@ TRANSLATED

MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Når TEAM MAGMA har opstilling, får vi\n"
	.string "vigtige vagtopgaver i\l"
	.string "rækkefølgen, vi står i.\p"
	.string "Derfor er jeg fanget her i hjørnet.\n"
	.string "Jeg kommer altid for sent til opstilling!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Jeg er altid sent til træningssamlinger,\n"
	.string "også!\p"
	.string "Jeg hader at sige det, men jeg er en tøsedreng…$" 

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Okay, jeg vil prøve at gøre lidt mere\n"
	.string "indsats fra nu af…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Vores leder bad os om at grave ind i\n"
	.string "MT. CHIMNEY, så vi gravede og gravede.\p"
	.string "Og i løbet af at grave, fandt vi\n"
	.string "noget, der sprængte vores sind!\p"
	.string "Hvad fandt vi?\p"
	.string "Fuhahaha!\n"
	.string "Det vil jeg fortælle, hvis du slår mig!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Av for fanden!\n"
	.string "Taget ned!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Jeg vil ikke fortælle dig alligevel.\n"
	.string "Du vil finde ud af det, når du kommer derhen!\p"
	.string "Det ville være bedre, hvis du gemte overraskelser\n"
	.string "til slutningen, synes du ikke?$"



