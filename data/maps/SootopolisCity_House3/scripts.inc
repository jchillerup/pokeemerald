@ TRANSLATED

SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Du er en POKéMON TRÆNER, ikke sandt?\p"
	.string "JUAN fra SOOTOPOLIS har mange fans. Endnu\n"
	.string "flere end hans elev WALLACE!\p"
	.string "Har du nogen?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Nå, så må du være ret stærk.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Åh, kære… Det er lidt ensomt.\p"
	.string "Prøv at arbejde lidt hårdere for at få en\n"
	.string "fanskare.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Dedikerede fans kommer endda fra uden for\n"
	.string "HOENN.\p"
	.string "Det var virkelig vildt, da jeg besøgte\n"
	.string "TRÆNER FANKLUBBEN i LILYCOVE.$"



