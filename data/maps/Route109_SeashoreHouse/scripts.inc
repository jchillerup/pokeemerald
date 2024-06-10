@ TRANSLATED

Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Jeg er ejeren af STRANDHUSET.\n"
	.string "Men du kan kalde mig HR. HAV!\p"
	.string "Hvad jeg elsker mest er at se varme\n"
	.string "POKéMON-kampe.\p"
	.string "Lad mig se, at dit hjerte brænder!\p"
	.string "Hvis du kan besejre alle TRÆNERENE\n"
	.string "her, vil jeg belønne dine anstrengelser.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Vis mig nogle spændende kampe!\p"
	.string "Jeg driver dette STRANDHUS kun for\n"
	.string "den ene grund alene!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Du er brændende varm!\n"
	.string "De kampe blussede!\l"
	.string "Jeg er mere end bare tilfreds!\p"
	.string "Som tak for at vise mig din varme\n"
	.string "stribe, vil jeg have dig til at tage disse.\p"
	.string "Det er et halvt dusin flasker SODAVAND!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Åh, men hey, din TASCHE er proppet fuld.\n"
	.string "Jeg vil hænge på disse for dig.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Vil du købe lidt SODAVAND?\n"
	.string "POKéMON elsker det!\p"
	.string "Kun ¥300 pr. flaske!\n"
	.string "Køb noget!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Her er det!$" 

Route109_SeashoreHouse_Text_NotEnoughMoney:
.string "Du har ikke pengene.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Nå?\n"
	.string "Det er ærgerligt.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Hvis du leder efter en kamp på\n"
	.string "ØSTERSØENS HUS, så finder du\n"
	.string "ingen sejere TRÆNER end mig, makker!\p$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Det var en varm kamp!\n"
	.string "Jeg kan godt acceptere det tab, makker!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Når jeg er i SLATEPORT, nyder jeg\n"
	.string "varme kampe og iskolde SODAVAND!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Kedelige kampe er ikke besværet værd.\p"
	.string "Brændende hede kampe er det, der gør stærkere\n"
	.string "TRÆNERE og POKÉMON!\p$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Det er varmt!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Puha, jeg er helt tørstig.\n"
	.string "Måske jeg vil have en SODAVAND.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Jeg vil vise dig, hvor fantastiske\n"
	.string "mine POKéMON er, men græd ikke!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "Jeg tabte, men jeg vil ikke græde…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Hvis en af mine POKéMON kendte angrebet\n"
	.string "for at bære mig over vandet på sin\l"
	.string "ryg, kunne jeg komme af med denne badering.$"



