@ TRANSLATED

LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Åh, åh! Rejser du alene? Men du er så\n"
	.string "ung! Godt klaret!\p"
	.string "Jeg er sikker på, at mine børn kunne\n"
	.string "lære en ting eller to af dig!\p"
	.string "Jeg? Jeg er en mester i {POKEBLOCK}S.\p"
	.string "Hvis jeg bliver lidt mere alvorlig, kan\n"
	.string "jeg fremtrylle fantastiske {POKEBLOCK}S.\p"
	.string "Vil du lære af mig, en mester i {POKEBLOCK}S?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Åh? Er du sikker?\p"
	.string "Du skal ikke altid prøve at gøre alting\n"
	.string "selv, kære!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Åh, godt! Du er en klog sjæl! Dette er\n"
	.string "lidt langt, så lyt godt efter!\p"
	.string "Er du klar?\p"
	.string "Hvis du kigger på {POKEBLOCK}S, bør du se at\n"
	.string "de er vurderet ud fra, hvordan de føles.\p"
	.string "Jo lavere følelsesvurderingen er, jo\n"
	.string "bedre er den. Glem ikke dette!\p"
	.string "En god {POKEBLOCK} har en lav følelses-\n"
	.string "vurdering og et højt niveau.\p"
	.string "En POKéMON kan spise flere gode\n"
	.string "{POKEBLOCK}S end almindelige, også.\p"
	.string "Og dette er vigtigt.\p"
	.string "Hvis du vil lave glatte {POKEBLOCK}S, brug\n"
	.string "forskellige slags BÆR.\p"
	.string "Vær ikke nærig--slags BÆR påvirker\n"
	.string "glattheden af {POKEBLOCK}S.\p"
	.string "Og en ting til.\p"
	.string "Jo flere personer der blander BÆR,\n"
	.string "desto glattere bliver {POKEBLOCK}S.\p"
	.string "Derfor bør du tale med andre personer\n"
	.string "og lave {POKEBLOCK}S sammen.\p"
	.string "Det er alt, du behøver at vide for at\n"
	.string "lave gode {POKEBLOCK}S.\p"
	.string "Hvis alle havde POKéMON de elsker,\n"
	.string "glatte {POKEBLOCK}S, og en kærlig familie,\l"
	.string "ville verden være et gladere sted.\p"
	.string "Giv ikke op, kære!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Da min kone fødte firlinger, kan du tro,\n"
	.string "jeg var chokeret.\p"
	.string "Men nu, når jeg ser dem lege sammen, gør\n"
	.string "det mig glad.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Vi skal kæmpe flere KAMPE, men jeg ved,\n"
	.string "jeg vil vinde.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "Vi kan godt lide at blande ting på\n"
	.string "RECORD CORNER.\p"
	.string "Men hvad bliver blandet? $"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "Vi skal lave super {POKEBLOCK}S med en\n"
	.string "BÆRBLÆNDER!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Jeg vil gerne prale af, hvor sej min\n"
	.string "POKéMON er, så vi skal deltage i en\l"
	.string "KONKURRENCE sammen.$"



