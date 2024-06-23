@ TRANSLATED

.set LOCALID_MOVE_DELETER, 1

LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
	.string "Øh... Åh, ja, jeg er FLYTTEFORGLEMMEREN.\p"
	.string "Jeg kan få POKéMON til at glemme deres\n"
	.string "træk.\p"
	.string "Skal jeg gøre det?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget:
	.string "Hvilken POKéMON skal glemme et træk?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
	.string "Hvilket træk skal glemmes?$"

LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} kender kun et træk så\n"
	.string "det kan ikke glemmes…$"

LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "Den bevægelse burde glemmes?$"

LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove:
	.string "Det fungerede perfekt!\p"
	.string "{STR_VAR_1} har glemt\n"
	.string "{STR_VAR_2} helt.$"

LilycoveCity_MoveDeletersHouse_Text_ComeAgain:
	.string "Kom tilbage, hvis der er træk, der skal\n"
	.string "glemmes.$"

LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves:
	.string "Hvad? Ingen ÆG skal kende nogen\n"
	.string "bevægelser.$"

LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf:
	.string "Hm!\p"
	.string "Din {STR_VAR_1} virker ikke villig \n"
	.string "til at glemme SURF.$"



