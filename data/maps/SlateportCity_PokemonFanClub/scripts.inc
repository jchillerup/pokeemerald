@ TRANSLATED

SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "Er-hem! Jeg er formanden for POKéMON FAN\n"
	.string "CLUB!\p"
	.string "Som formand er jeg naturligvis den\n"
	.string "vigtigste!\p"
	.string "Ingen kan slå mig, når det kommer til at\n"
	.string "opdrage POKéMON. Ingen!\p"
	.string "Nå, lad mig fortælle dig om\n"
	.string "POKéMON-KONKURRENCER.\p"
	.string "Det er begivenheder, hvor man kan vise\n"
	.string "POKéMON frem for verden!\p"
	.string "Dog afholdes de i fjerne byer, så jeg kan\n"
	.string "ikke deltage ofte nok.\p"
	.string "Derfor samles vi her for at vise vores\n"
	.string "POKéMON frem og se andres vise os deres.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "deltaget i en POKéMON KONKURRENCE…\p"
	.string "Det vil jeg gerne se.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Er-hem! Jeg kan se, at du har deltaget i en\n"
	.string "POKéMON-KONKURRENCE!\p"
	.string "Må jeg bede om at undersøge, hvordan du har\n"
	.string "opdrættet din POKéMON?\p"
	.string "Det glæder mig enormt at se POKéMON, der er\n"
	.string "opdrættet af andre TRÆNERE.\p"
	.string "De glade udtryk hos POKéMON, der er\n"
	.string "opdrættet med ordentlig pleje…\p"
	.string "TRÆNERENS venlige øjne, der nærede og\n"
	.string "opdrættede POKéMON'en…\p"
	.string "Tanken alene fylder mit hjerte med\n"
	.string "overvældende glæde.\p"
	.string "Åh! Jeg beder mange gange om undskyldning!\n"
	.string "Tilgiv mig for at snakke så meget!\p"
	.string "Må jeg bede om at undersøge, hvor meget din\n"
	.string "POKéMON er vokset!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "Hvordan vokser din POKéMON? Lad mig\n"
	.string "undersøge den.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Hm, hm… Jeg forstår...$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hmm ... Det er ikke dårligt, men det er heller\n"
	.string "ikke godt ... \p"
	.string "Du, TRÆNEREN, skal lægge mere indsats i at\n"
	.string "opdrage denne POKéMON!\p"
	.string "For eksempel, må jeg foreslå, at du giver den\n"
	.string "flere {POKEBLOCK}S?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Åh, min…\p"
	.string "Din POKéMON vokser ganske godt, så du\n"
	.string "fortjener en belønning.\p"
	.string "Desværre har du ikke plads til dette i din\n"
	.string "RYGSÆK.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "Din {STR_VAR_1}, den vokser på en mest\n"
	.string "imponerende måde! Det er et fint\l"
	.string "eksemplar!\p"
	.string "Men! Hvis du giver den dette, ville den vokse\n"
	.string "endnu bedre! Ja!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Lad en POKéMON holde den RØDE TØRKLÆDE.\p"
	.string "Alle vil genkende sejheden hos den\n"
	.string "POKéMON!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Lad en POKéMON holde den BLÅ TØRKLÆDE.\p"
	.string "Dens skønhed vil blive fremhævet meget\n"
	.string "mere end nu!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Lad en POKéMON bære det ROSA\n"
	.string "HALSTØRKLÆDE.\p"
	.string "Det vil fremhæve sødigheden af POKéMON'en\n"
	.string "endnu mere!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Lad en POKéMON holde den GRØNNE TØRKLÆDE.\p"
	.string "Det vil forbedre POKéMONs intelligens!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Lad en POKéMON holde den GULE TØRKLÆDE.\p"
	.string "Det vil styrke din POKéMONs udholdenhed\n"
	.string "endnu mere!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Jeg er ked af det, men jeg har intet mere at\n"
	.string "give dig! Slet ingenting!\p"
	.string "Trods alt er du velsignet med evnen til at\n"
	.string "opdrage POKéMON uden at ty til nogen\l"
	.string "genstande!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "Jeg elsker at se POKéMON, der elsker deres\n"
	.string "TRÆNERE.\p"
	.string "POKéMON er meget følsomme over for deres\n"
	.string "TRÆNERES følelser.\p"
	.string "Hvis du behandler dine POKéMON med\n"
	.string "kærlighed og omsorg, vil de elske dig\l"
	.string "tilbage.\p"
	.string "Når dine POKéMON vokser sig til at elske dig,\n"
	.string "så kom og vis mig det.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "Dit POKéMON holder virkelig af dig.\p"
	.string "Til dig, en meget medfølende TRÆNER, en gave\n"
	.string "fra FANKLUBBEN!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "POKéMON er meget følsomme overfor deres\n"
	.string "TRÆNERES følelser.\p"
	.string "Hvis du behandler dine POKéMON med\n"
	.string "kærlighed og omsorg, vil de elske dig\l"
	.string "tilbage.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "Hvis du bliver ved med at lade en POKéMON \n"
	.string "besvime i kampen, vil den komme til at\l"
	.string "bebrejde det.\p"
	.string "Snart vil den blive mindre tillidsfuld over\n"
	.string "for TRÆNEREN.\p"
	.string "Med andre ord, den vil helt sikkert ikke\n"
	.string "synes særlig godt om dig.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "Nyder POKéMON at få brugt genstande på\n"
	.string "dem?\p"
	.string "Min blev virkelig glad, da jeg gav den lidt\n"
	.string "PROTEIN.$"

SlateportCity_PokemonFanClub_Text_Skitty:
.string "SKITTY: Fffnyaaaah…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
.string "ZIGZAGOON: Kyuuu...$"

SlateportCity_PokemonFanClub_Text_Azumarill:
.string "AZUMARILL: Marimari?$"



