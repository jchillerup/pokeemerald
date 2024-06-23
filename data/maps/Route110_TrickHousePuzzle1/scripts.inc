@ TRANSLATED

Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} skrev den hemmelige kode på\n"
	.string "døren.\p"
	.string "“TRICK MASTER er fantastisk.” … … … … …\n"
	.string "… … …\p"
	.string "Låsen klikkede op!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Jeg vil hakke og skære mig vej til sejr\n"
	.string "med KLIPPET vi lige har lært!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Hvorfor er du så seriøs?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Jeg bliver aldrig træt af at hacke og\n"
	.string "skære!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Jeg vandrede ind i dette mærkelige hus\n"
	.string "ved et uheld…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Og nu har jeg tabt...$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Jeg har mistet min vej, jeg har tabt et\n"
	.string "slag, og nu er jeg endnu mere forvirret…\l"
	.string "Jeg kan ikke komme ud…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
.string "Hvem er bare SJOVE MESTER?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
.string "Jeg tabte, mens jeg var fordybet i tankerne!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Du er stærk! Hvem er du?$"



