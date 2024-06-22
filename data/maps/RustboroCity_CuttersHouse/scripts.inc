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
	.string "Det der bestemte udtryk… Den smidige måde,\n"
	.string "du bevæger dig på… Og dine veltrænede\l"
	.string "POKéMON…\p"
	.string "Du er tydeligvis en dygtig TRÆNER!\p"
	.string "Nej, vent, sig ikke et ord. Jeg kan se det bare\n"
	.string "ved at kigge på dig.\p"
	.string "Jeg er sikker på, at du kan bruge denne\n"
	.string "SKJULTE MASKINE godt.\p"
	.string "Ingen grund til at være beskeden eller\n"
	.string "genert. Kom nu, tag den!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Den SKJULTE MASKINE, eller HM for kort, er\n"
	.string "KLIP.\p"
	.string "Et HM-træk er et, der kan bruges af en\n"
	.string "POKéMON uden for kamp.\p"
	.string "Enhver POKéMON, som har lært KLIP, kan\n"
	.string "hugge tynde træer ned, hvis TRÆNEREN har\l"
	.string "optjent STENBADGEN.\p"
	.string "Og, i modsætning til en TM, kan en HM bruges\n"
	.string "flere gange.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Da de udvidede byen RUSTBORO, hjalp min far\n"
	.string "til.\p"
	.string "Han lod sit POKéMON bruge SAKS til at rydde\n"
	.string "landet for træer.$"



