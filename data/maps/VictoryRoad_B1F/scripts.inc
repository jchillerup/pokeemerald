@ TRANSLATED

VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Tanken om, at jeg kommer tættere på\n"
	.string "POKéMON-LIGAEN…\p"
	.string "Jeg får sceneskræk…$"

VictoryRoad_B1F_Text_SamuelDefeat:
.string "Jeg kunne ikke gøre en ting…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "POKéMON LIGAEN virker fjernt igen...\n"
	.string "Sikken skuffelse...$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "For at vinde din vej gennem POKéMON-\n"
	.string "LIGAEN, skal du have tilliden fra dine\l"
	.string "POKéMON.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Dit forhold er baseret på solid tillid.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Ved at være sammen hele tiden, vokser\n"
	.string "tilliden mellem POKéMON og TRÆNERE.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Det her er ikke målet. Det er bare et sted på\n"
	.string "vejen til POKéMONLEAGUE.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "Det er vejen!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Du klarer det helt sikkert! Dine POKéMON er\n"
	.string "alle ivrige for at komme afsted!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Mine POKéMON er kosmisk inspirerende!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Jeg har aldrig mødt nogen som dig før.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Selv uden for kamp, kan jeg mærke en utrolig\n"
	.string "kraft stråler fra dig og dine POKéMON.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Okay, ingen grund til at blive defensiv! Slap\n"
	.string "af, lad os tage det roligt!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Whoa! Fantastisk!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Selvfølgelig, dette er SEJRVEJEN.\p"
	.string "Men det er ikke så anderledes fra den vej, du\n"
	.string "hidtil har fulgt.\p"
	.string "Prøv at nyde resten af vejen!$"



