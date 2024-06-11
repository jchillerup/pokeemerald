@ TRANSLATED

Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Hvad er det?\n"
	.string "Hvad laver jeg?\p"
	.string "Jeg overvejer at lave mit eget rum\n"
	.string "her ved at bruge en POKéMON\n"
	.string "move.\p"
	.string "Jeg ved det! Jeg giver dig denne TM.\n"
	.string "Vil du bruge den til at lave dit\n"
	.string "eget rum?$"

Route111_Text_ExplainSecretPower:
	.string "Find en stor træ, som ser ud til at kunne\n"
	.string "tabe nogle slyngplanter.\p"
	.string "Brug HEMMELIG KRAFT foran træet.\n"
	.string "Nogle slyngplanter burde løsne sig og\n"
	.string "falde ned, så du kan klatre i træet.\p"
	.string "Du vil finde masser af plads til at\n"
	.string "sætte dine yndlingsting.\p"
	.string "Det vil være dit eget hemmelige rum…\n"
	.string "EN HEMMELIG BASE!\p"
	.string "Du burde også lave en.\p"
	.string "En anden ting, du behøver ikke altid\n"
	.string "lave din HEMMELIGE BASE i et træ.\p"
	.string "Prøv at bruge HEMMELIG KRAFT på\n"
	.string "klippevægge, der har små fordybninger.\p"
	.string "Jeg vil også lede efter andre steder.\n"
	.string "Okay, farvel!$" 

Route111_Text_DontWantThis:
	.string "Åh, vil du ikke have dette?\n"
	.string "Hvis du skifter mening, så sig det til mig, okay?$"

Route111_Text_DontHaveAnyRoom:
	.string "Åh, du har ikke plads til dette.\p"
	.string "Jeg vil passe på det, så kom tilbage\n"
	.string "for det en anden gang, okay?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end


