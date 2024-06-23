@ TRANSLATED

SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MT. PYRE…\p"
	.string "På toppen er der to kugler, der er\n"
	.string "placeret side om side. Vidste du det?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Ja, to kugler ved siden af hinanden…\p"
	.string "Synet af dem sammen… Det er på en eller\n"
	.string "anden måde beroligende…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Er det sådan? Måske skulle du besøge og\n"
	.string "se...$"



