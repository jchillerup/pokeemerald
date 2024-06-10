@ TRANSLATED

Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} skrev den hemmelige kode\n"
	.string "på døren.\p"
	.string "“TRICK MASTER er mit liv.”\n"
	.string "… … … … … … … …\p"
	.string "Låsen klikkede op!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Da jeg hørte, at der var et mærkeligt\n"
	.string "hus, var jeg nødt til at undersøge det.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
.string "Jeg har opdaget en sej TRÆNER!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Jeg er sikker på, at jeg har det sjovt\n"
	.string "med at udforske dette sted.\p"
	.string "Det er en udfordring, som jeg har fundet\n"
	.string "værd at gentage!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Måske kan jeg få min FUGL\n"
	.string "POKéMON til at flyve over muren…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
.string "Gwaaah! Jeg floppede!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Hihihi... Jeg gætter på, at jeg tabte,\n"
	.string "fordi jeg prøvede at snyde.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Jeg bliver svimmel af disse roterende\n"
	.string "døre…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Alting snurrer rundt og\n"
	.string "rundt. Jeg kan ikke klare det her mere...$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Du virker overhovedet ikke påvirket.\n"
	.string "Eller har du bare din poker face på?$"



