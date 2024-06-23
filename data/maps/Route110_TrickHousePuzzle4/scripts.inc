@ TRANSLATED

Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} skrev den hemmelige kode på\n"
	.string "døren.\p"
	.string "“TRICK MASTER er sej.” … … … … … … … …\p"
	.string "Låsen klikkede op!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Det er alt for besværligt at tænke på\n"
	.string "dette. Jeg ville bare kæmpe!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Selvom jeg tabte, kan jeg stadig lide at\n"
	.string "kæmpe bedst!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Ville du ikke være enig? Du ville gå hvor\n"
	.string "som helst, hvis TRAINERS var der.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Hi hi! Sten som denne kan jeg skubbe til\n"
	.string "side med en finger!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Jeg kan skubbe sten, men jeg kan ikke\n"
	.string "løse puslespillet…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Det er ikke godt nok at være stærk... Du\n"
	.string "skal bruge dit hoved. Vær smart!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "Det LISTIGE HUS bliver endnu mere\n"
	.string "snedigt, er det ikke?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
.string "Aaak!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Har nogen nået til enden?$"



