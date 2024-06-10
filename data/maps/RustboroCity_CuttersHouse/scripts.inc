@ TRANSLATED

RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Det der bestemte udtryk…\n"
	.string "Den smidige måde, du bevæger dig på…\l"
	.string "Og dine veltrænede POKéMON…\p"
	.string "Du er tydeligvis en dygtig TRÆNER!\p"
	.string "Nej, vent, sig ikke et ord.\n"
	.string "Jeg kan se det bare ved at kigge på dig.\p"
	.string "Jeg er sikker på, at du kan bruge denne\n"
	.string "SKJULTE MASKINE godt.\p"
	.string "Ingen grund til at være beskeden eller genert.\n"
	.string "Kom nu, tag den!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Den SKJULTE MASKINE, eller HM for\n"
	.string "kort, er KLIP.\p"
	.string "Et HM-træk er et, der kan bruges\n"
	.string "af en POKéMON uden for kamp.\p"
	.string "Enhver POKéMON, som har lært KLIP,\n"
	.string "kan hugge tynde træer ned, hvis\n"
	.string "TRÆNEREN har optjent STENBADGEN.\p"
	.string "Og, i modsætning til en TM, kan en\n"
	.string "HM bruges flere gange.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Da de udvidede byen RUSTBORO,\n"
	.string "hjalp min far til.\p"
	.string "Han lod sit POKéMON bruge SAKS\n"
	.string "til at rydde landet for træer.$"



