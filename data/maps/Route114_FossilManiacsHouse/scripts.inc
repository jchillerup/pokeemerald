@ TRANSLATED

Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Min storebror er Fossilentusiasten…\n"
	.string "Han er en rar fyr, som elsker FOSSILER…\p"
	.string "Han elsker også at grave huller… Han\n"
	.string "gravede dette hul selv…\p"
	.string "Du kan få dette, så du kan GRAVE huller\n"
	.string "ligesom min storebror…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Hvis du laver en POKéMON GRAVE inde i en\n"
	.string "hule, så bliver du sendt tilbage til\l"
	.string "indgangen…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Sten i sælsomme former fylder\n"
	.string "udstillingskabinettet…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "SAMMENSÆTNINGEN AF LAGENE… HVORDAN\n"
	.string "REGN FORMER LANDET… STEN, JORD OG\l"
	.string "KLIPPER…\p"
	.string "Den er proppet med bøger.$"



