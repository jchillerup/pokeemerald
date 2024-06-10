@ TRANSLATED

Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Åh, kære, kære.\n"
	.string "Er dine POKéMON udmattede?\p"
	.string "Hvis du vil, kan du hvile dig her.\n"
	.string "Det er en god idé! Det burde du gøre.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "Det er korrekt.\n"
	.string "Tag dig god tid og hvil dig!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Åh, kære, kære.\n"
	.string "Er dine POKéMON stadig trætte?\p"
	.string "Du burde tage en anden pause her.\n"
	.string "Det er en god idé. Du burde gøre det.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Er det sandt?\n"
	.string "Du behøver ikke at være genert om det.$"



