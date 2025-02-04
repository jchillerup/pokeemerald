@ TRANSLATED

Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Åh! {PLAYER}{KUN}!\p"
	.string "Undskyld, at alt er så rodet... Når jeg\n"
	.string "fordyber mig i forskning, ender tingene\l"
	.string "sådan her... \p"
	.string "Det er pinligt... Lov mig at holde det\n"
	.string "hemmeligt mod denne.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Må jeg tilbyde råd om mit POKéMONs\n"
	.string "Opbevaringssystem?\p"
	.string "Du bør organisere dine KASSER, så du\n"
	.string "kan se, hvilke POKéMON der er i dem.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Det er LANETTE's forskningsnotater.\n"
	.string "Der er information om KASSER.\p"
	.string "Design KASSER til at holde 30 POKéMON\n"
	.string "hver.\p"
	.string "Hver TRÆNER bør kunne opbevare 420\n"
	.string "POKéMON i PC-systemet.\p"
	.string "Vil du fortsætte med at læse?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Et mærkningssystem bør tilføjes for at\n"
	.string "gøre POKéMON lettere at organisere.\p"
	.string "Navnet og tapetdesignet af hver BOKS\n"
	.string "vil blive ændret for at glæde de\l"
	.string "opbevarede POKéMON.\p"
	.string "Vil du fortsætte med at læse?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Når du gemmer en POKéMON, skal den\n"
	.string "sendes til den sidst inspicerede BOKS.\p"
	.string "Hvis den BOKS er fuld, bliver den\n"
	.string "modtagne POKéMON gemt i den næste BOKS.\p"
	.string "Med andre ord, når en BOKS undersøges,\n"
	.string "bliver den automatisk valgt som den\l"
	.string "BOKS, hvortil POKéMON sendes.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
.string "{PLAYER} lukkede notesbogen.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Der er en e-mail fra nogen på\n"
	.string "computeren.\p"
	.string "“... ... ... ... ... ...\p"
	.string "“Dit Opbevaringssystem tilbyder mere\n"
	.string "bekvemmelighed end mit.\p"
	.string "“Det har en masse brugervenlige\n"
	.string "funktioner, som gør det sjovt og\l"
	.string "nyttigt, også.\p"
	.string "“Det gør mig stolt, at jeg spillede en\n"
	.string "rolle i dets udvikling.\p"
	.string "“Håber, at du vil fortsætte forskningen\n"
	.string "i Opbevaringssystemer.\p"
	.string "“Fra BILL ... ... ... ... ... ... ... ...$"



