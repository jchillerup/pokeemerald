@ TRANSLATED

RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Tavlen viser statusændringer,\n"
	.string "der kan påvirke POKéMON i kamp.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
.string "Hvilket emne vil du læse om?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Hvis en POKéMON er forgiftet, vil den\n"
	.string "gradvist miste HP.\p"
	.string "Forgiftningens effekter forbliver efter\n"
	.string "en kamp.\p"
	.string "En forgiftet POKéMONs HP vil falde\n"
	.string "mens den rejser sig.\p"
	.string "Helbred en forgiftning ved at bruge en\n"
	.string "MODGIFT.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Hvis en POKéMON bliver lammet,\n"
	.string "sænkes dens HASTIGHED.\p"
	.string "Den kan muligvis heller ikke bevæge sig\n"
	.string "mens den er i kamp.\p"
	.string "Lammelse forbliver efter kampen.\n"
	.string "Helbred det ved at bruge en PARLYZ HEAL.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Hvis en POKéMON falder i søvn, kan den\n"
	.string "ikke angribe.\p"
	.string "En POKéMON kan vågne af sig selv,\n"
	.string "men hvis en kamp slutter mens den\l"
	.string "sover, forbliver den i søvn.\p"
	.string "Væk den op med en OPVÅGNING.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "En forbrænding reducerer ANGREB styrke, og den\n"
	.string "reducerer gradvist offerets HP.\p"
	.string "En forbrænding bliver ved efter kampen.\n"
	.string "Helbred en forbrænding ved at bruge en FORBRÆNDINGSHEAL.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Hvis en POKéMON er frossen, bliver den\n"
	.string "fuldstændig hjælpeløs.\p"
	.string "Den forbliver frossen efter kampen.\n"
	.string "Tø dem op ved at bruge en IS-HELING.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Elever, der ikke studerer, får en lille\n"
	.string "smag af min HURTIGE KLO.\p"
	.string "Om du er en god elev eller ej, vil\n"
	.string "være tydeligt ud fra, hvordan du\n"
	.string "bruger dette item.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "En POKéMON, som holder QUICK CLAW,\n"
	.string "vil lejlighedsvis øge sin hastighed og\l"
	.string "få lov til at bevæge sig før sin modstander.\p"
	.string "Der er mange andre genstande, som er\n"
	.string "ment til at blive holdt af POKéMON.\p"
	.string "Bare dem alene vil give dig mange\n"
	.string "emner at studere!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Jeg bytter POKéMON med min ven\n"
	.string "lige nu.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Jeg har altid ønsket mig en SEEDOT, og\n"
	.string "jeg får endelig en!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "POKéMON kan holde på ting, men de\n"
	.string "ved ikke, hvad de skal gøre med\l"
	.string "menneskeskabte ting som POTION\n"
	.string "og ANTIDOTE.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Du ved, hvordan visse POKéMON-angreb kan\n"
	.string "forvirre en POKéMON?\p"
	.string "En forvirret POKéMON vil nogle gange\n"
	.string "angribe sig selv uden at mene det.\p"
	.string "Men når den forlader kampen, vil den\n"
	.string "vende tilbage til normal igen.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "En POKéMON, der holder en BÆR, vil hele\n"
	.string "sig selv…\p"
	.string "Der er mange slags genstande, som en\n"
	.string "POKéMON kan holde…\p"
	.string "Åh, hvor er det svært at tage noter\n"
	.string "…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Det her er en elevs notesbog…\p"
	.string "Man fanger POKéMON med\n"
	.string "POKé-BOLD.\p"
	.string "Op til seks POKéMON kan tage med\n"
	.string "en TRÆNER.\p"
	.string "En TRÆNER er en person, der fanger\n"
	.string "POKéMON, opdrætter dem og kæmper\l"
	.string "med dem.\p"
	.string "En TRÆNER's mission er at besejre\n"
	.string "de stærke TRÆNERE, der venter\l"
	.string "på udfordringer i POKéMON GYMER.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Hej? Har vi ikke mødt hinanden før?\n"
	.string "Jeg tror tilbage i PETALBLOMST- BYEN.\p"
	.string "Lad mig præsentere mig selv.\n"
	.string "Mit navn er SCOTT.\p"
	.string "Jeg har rejst overalt for at finde\n"
	.string "fremragende TRÆNERE.\p"
	.string "Mere specifikt leder jeg efter\n"
	.string "POKéMON kampeksperter.\p"
	.string "Så, hvad bringer dig til denne SKOLE?\n"
	.string "Er du også en TRÆNER?\p"
	.string "Det første, du bør gøre, er at\n"
	.string "lære en POKéMON bevægelsen CUT.\p"
	.string "Hvis jeg husker korrekt, har nogen i\n"
	.string "denne by CUT.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hmm…\p"
	.string "Talentniveauerne hos eleverne her\n"
	.string "er ukendte. Potentialet er der.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: Åh, hvad er det?\p"
	.string "Det er en STENBROCHE, er det ikke?\n"
	.string "Det er ret imponerende, vil jeg sige.\p"
	.string "Men ved du hvad, jeg ville gerne have set\n"
	.string "dig i kamp.\p"
	.string "Det er svært at sige, hvordan du er som\n"
	.string "en TRÆNER fra en LIGABROCHE.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Hej? Mødtes vi ikke før?\n"
	.string "Jeg tror det var i PETALBLADBYEN.\p"
	.string "Lad mig præsentere mig.\n"
	.string "Jeg hedder SCOTT.\p"
	.string "Jeg har rejst overalt for at finde\n"
	.string "fremragende TRÆNERE.\p"
	.string "Mere specifikt leder jeg efter\n"
	.string "POKéMON kamp eksperter.\p"
	.string "Åh, hvad er det?\n"
	.string "Det er en STENMÆRKET, ikke sandt?\p"
	.string "Det er ret imponerende, må jeg sige,\n"
	.string "for en begyndende TRÆNER som dig.\p"
	.string "Men, ved du hvad, jeg ville have elsket\n"
	.string "at se dig i kamp.\p"
	.string "Det er svært at vurdere, hvordan du er\n"
	.string "som TRÆNER med et LIGAMÆRKE.$"



