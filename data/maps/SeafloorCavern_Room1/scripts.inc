@ TRANSLATED

SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Vi har ikke brug for et barn her! Gå hjem\n"
	.string "allerede!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Jeg vil hjem…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Jeg vil gerne have en forfremmelse, så\n"
	.string "jeg kan befale rundt med GRUNTE…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Den ubåd... Den er lille indeni. Jeg er øm\n"
	.string "over det hele!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "At tabe gør ondt!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Den undervandsbåd, vi kaprede, mand,\n"
	.string "det er vildt som en tur.\p"
	.string "Det er alt for stramt derinde!$"



