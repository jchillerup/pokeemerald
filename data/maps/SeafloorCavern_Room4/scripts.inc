@ TRANSLATED

SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Hvem er du? Hvor kom du ind fra?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Mistet det...$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Jeg kan ikke finde vejen ud!\p"
	.string "Jeg er ikke bange. Misforstå mig ikke!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Hvem er du? Hvor tror du, du skal hen?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
.string "Jeg formåede ikke at vinde!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Min partner glemte kortet i den ubåd!\p"
	.string "Hvad siger du til det, sådan er\n"
	.string "tjenestevillighed?$"



