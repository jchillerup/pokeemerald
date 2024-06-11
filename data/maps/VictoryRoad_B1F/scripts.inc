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
	.string "Tanken om, at jeg kommer tættere\n"
	.string "på POKéMON-LIGAEN…\p"
	.string "Jeg får sceneskræk…$"

VictoryRoad_B1F_Text_SamuelDefeat:
.string "Jeg kunne ikke gøre en ting…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "POKéMON LIGAEN virker fjernt\n"
	.string "igen... Sikken skuffelse...$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "For at vinde din vej gennem POKéMON-\n"
	.string "LIGAEN, skal du have tilliden fra\l"
	.string "dine POKéMON.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Dit forhold er baseret på\n"
	.string "solid tillid.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Ved at være sammen hele tiden,\n"
	.string "vokser tilliden mellem POKéMON\n"
	.string "og TRÆNERE.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Det her er ikke målet. Det er\n"
	.string "bare et sted på vejen til POKéMON\nLEAGUE.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "Det er vejen!\p$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Du klarer det helt sikkert!\n"
	.string "Dine POKéMON er alle ivrige for at komme afsted!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Mine POKéMON er kosmisk\n"
	.string "inspirerende!\p$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Jeg har aldrig mødt nogen som dig før.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Selv uden for kamp, kan jeg mærke\n"
	.string "en utrolig kraft stråler fra dig\n"
	.string "og dine POKéMON.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Okay, ingen grund til at blive defensiv!\n"
	.string "Slap af, lad os tage det roligt!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Whoa!\n"
	.string "Fantastisk!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Selvfølgelig, dette er SEJRVEJEN.\p"
	.string "Men det er ikke så anderledes fra\n"
	.string "den vej, du hidtil har fulgt.\p"
	.string "Prøv at nyde resten af vejen!\p$"



