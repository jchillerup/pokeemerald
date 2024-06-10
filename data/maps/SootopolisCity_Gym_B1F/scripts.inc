@ TRANSLATED

SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_ANNIKA, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_DAPHNE, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "Jeg vil vise dig de sublime teknikker\n"
	.string "jeg har lært af vores LEADER JUAN!$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
.string "Please forgive me, {PLAYER_NAME}…$" 

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "Se, hvad der sker, hvis du knækker\n"
	.string "alle gulvfliserne.$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "Du kom hele vejen hertil, men du får\n"
	.string "ikke lov til at se JUAN.\p"
	.string "Ikke hvis du taber til mig!$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "Du er stærk!\n"
	.string "Jeg blev narret af dit søde udseende!$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "Du er måske god nok til at undgå\n" \n
	.string "at blive udslettet med ét slag af JUAN.$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "Synet af JUAN i gang med\n"
	.string "en kamp…\p"
	.string "Skønheden i det tvang mig til at\n"
	.string "blive en TRÆNER.$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "Du kæmpede med mere skønhed end jeg\n"
	.string "kunne samle…$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "Den elegance, du bringer til kampen,\n"
	.string "er fantastisk.\p"
	.string "Åh... Jeg er så heldig at have fundet\n"
	.string "POKéMON.$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "Jeg bør lære dig, hvor barske kampe\n"
	.string "kan være.$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "Åh.\n"
	.string "Du er stærk.$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "Jeg vil fortælle dig noget godt.\p"
	.string "Hvis du vil nå JUAN, skal du\n"
	.string "gå på hvert gulvflise én gang.$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "Den POKéMON GYM på det højeste niveau\n"
	.string "i regionen HOENN…\p"
	.string "Det er SOOTOPOLIS GYM.$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
.string "Hvor er du på et højt niveau!$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "I stedet for at være tilfreds med at være\n"
	.string "i et stærkt GYM, forestiller jeg mig, at\l"
	.string "træning andre steder vil gøre dig stærkere.\l"
	.string "Men frem for alt ser det sjovere ud.$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "Jeg træner mine POKéMON sammen med\n"
	.string "JUAN.\p"
	.string "Tro ikke, jeg er en letvægter.$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "Jeg blev slået…$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "Jeg tror, du har potentiale.\n"
	.string "Hvorfor bliver du ikke og træner med os?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "En elegant glide hen over isen uden\n"
	.string "at krydse nogen linjer…\p"
	.string "En TRÆNER, der udfører den\n"
	.string "præstation, ville være smukt elegant!$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "Nå, undskyld mig?!"$ 

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "Det her er virkelig åbenlyst, men hvor\n"
	.string "stærk du er som EN TRÆNER har intet at\n"
	.string "gøre med hvor ung eller gammel du er.$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "Når jeg er sammen med mine POKéMON, så\n"
	.string "flyver tiden afsted før du kan sige \"Ups!\"$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "Ups!$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "Jeg ønsker, at jeg kunne glemme\n"
	.string "om tabte sager, før jeg kan\n"
	.string "klare et “Ups!”$"


SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "Jeg kan kæmpe med virkelig sjældne POKéMON\n"
	.string "hvis du har lyst.$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "Åh, der er du! Fik du et godt kig\n"
	.string "på mine POKéMON?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "Jeg kom til dette GYM, fordi JUAN\n"
	.string "roste mig for mine skønne POKéMON.\p"
	.string "Åh, hvis bare jeg havde mødt JUAN for år\n"
	.string "tilbage, da jeg var yngre…$"

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "Grin…\n"
	.string "Dit alvorlige udtryk er så charmerende.$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "Åh, duh.\n"
	.string "Jeg tog alt for let på dig.$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "Du kunne ikke engang røre ved JUAN,\n"
	.string "er jeg sikker på. Grin…$"



