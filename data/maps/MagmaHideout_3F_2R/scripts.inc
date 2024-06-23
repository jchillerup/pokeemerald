@ TRANSLATED

MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Jeg forstår alt, hvad vores leder siger.\n"
	.string "Men ved du hvad?\p"
	.string "At lave ting som at grave en super-\n"
	.string "ældgammel POKéMON op og stjæle en\l"
	.string "METEORIT fra nogen…\p"
	.string "Jeg synes, vi går lidt for langt. Hvad\n"
	.string "synes du?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Ja, jeg tror vi gør noget forkert på en\n"
	.string "eller anden måde.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Du ved, at tabe til dig ryddede mine\n"
	.string "tanker.\p"
	.string "Næste gang jeg ser vores leder, vil jeg\n"
	.string "spørge ham om, hvad vi gør.$"



