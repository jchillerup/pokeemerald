@ TRANSLATED

AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Hvad er så sjovt ved at have min indre\n"
	.string "slange om bord på skibet?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Whoa, du overvældede mig!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Det er ikke nemt at kaste POKé BALLS\n"
	.string "mens man hænger på en badering!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Er det ikke sjovt her? Jeg bliver bare\n"
	.string "så spændt af at være her!$"



