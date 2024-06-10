@ TRANSLATED

MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Jeg har ikke noget at udsætte på dig.\n"
	.string "Jeg følger bare ordrer!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
.string "Jeg har måske tabt, men…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "Vi har gravet noget op ud over tro!\n"
	.string "Og vi fik DEN BLÅ ORB!\p"
	.string "Alt hvad der nu mangler er for vores leder at…\n"
	.string "Fufufu… Fwahahaha!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Jeg kan ikke klare varmen. Måske\n"
	.string "skulle jeg have valgt TEAM AQUA i stedet...$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Ja, jeg er måske virkelig ikke den rette for\n"
	.string "TEAM MAGMA...$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Bliver du ikke ensom efter havet\n"
	.string "når du er et sted som dette?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "Nogle gange kan du høre rystelser her.\p"
	.string "Kunne det være vulkanen, der skælver?\n"
	.string "Eller er det GRUPPE…\p"
	.string "Ups!\n"
	.string "Nå, glem det!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Du er en ildfuld kæmper.\n"
	.string "Præcis som en vulkan!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Du vandt tilfældigvis denne gang,\n"
	.string "men det gør ikke noget.\p"
	.string "Hold MAGMA er ved at nå deres\n"
	.string "mål!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "En af vores fyre var helt ude af den,\n"
	.string "fordi han havde tabt sit MAGMA-EMBLEM…\p"
	.string "Vent lige et øjeblik!\n"
	.string "Var det dig, der fandt det?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "Jeg har svært ved at tro på dette...$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "Jeg får en fornemmelse af, at vores plan\n"
	.string "endte i fiasko…$"



