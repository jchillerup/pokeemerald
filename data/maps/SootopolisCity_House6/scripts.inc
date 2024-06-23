@ TRANSLATED

SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Hej! Du er vores første gæst i lang tid.\p"
	.string "Du har gjort min dag meget bedre, så jeg\n"
	.string "vil give dig en stor WAILMER- DUKKE.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Pas godt på det!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Åh, vil du have det, men ikke lige nu?\n"
	.string "Okay, så vil jeg holde det for dig.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Er du sikker? Vil du ikke have denne\n"
	.string "DUKKE?$"

SootopolisCity_House6_Text_LovePlushDolls:
.string "Jeg elsker bamse DUKKER!$"



