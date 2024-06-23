@ TRANSLATED

Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} skrev den hemmelige kode på\n"
	.string "døren.\p"
	.string "“TRICK MASTER, jeg elsker.” … … … … … … …\n"
	.string "…\p"
	.string "Låsen klikkede op!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Ikke mange TRÆNERE er nået så langt.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
.string "Det må betyde, at du også er sej…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Du har slået POKéMON-LIGAEN MESTEREN?\n"
	.string "Det er for vildt!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Betragt dig selv som heldig for at\n"
	.string "kæmpe mod mig!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Det her er ikke rigtigt! Jeg kan ikke\n"
	.string "tabe!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Det er et mirakel, at du slog mig. Du kan\n"
	.string "prale af det.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Du har kæmpet dig gennem TRICK HOUSE\n"
	.string "udfordringen også.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Jeg ser... Du besidder en ekstraordinær\n"
	.string "stil.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "At se nogen som dig bør glæde TRICK\n"
	.string "MASTEREN.$"



