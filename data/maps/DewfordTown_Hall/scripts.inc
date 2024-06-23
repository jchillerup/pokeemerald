@ TRANSLATED

.set LOCALID_EXPERT_M, 4
.set LOCALID_TWIN, 5
.set LOCALID_SCHOOL_KID_M, 7
.set LOCALID_PSYCHIC_M, 8

DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Hvad er på mode? Pjat, det må være\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Jeg kan slet ikke forestille mig,\n"
	.string "hvordan livet ville være uden\l"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Hvad er det helt store? Ja, det må være\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Men jeg begynder at kede mig med det.\p"
	.string "Jeg bør lede efter det næste store.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Jeg underviser mine POKéMON i\n"
	.string "“{STR_VAR_1},” men det går ikke så\l"
	.string "godt.\p"
	.string "Det er lidt for meget, tror jeg.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Jeg undersøger det hippe og trendy\n"
	.string "“{STR_VAR_1}” lige nu.\p"
	.string "Er det sandt, at der er en dyb\n"
	.string "forbindelse mellem “{STR_VAR_1}” og\l"
	.string "“{STR_VAR_2}”?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Åh! Så min fornemmelse var rigtig!\p"
	.string "Jeg er et skridt tættere på at være cool\n"
	.string "og sej, wauw!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Hvad?! Er det sandt?!\p"
	.string "Det er ikke nemt for en ældre herre som\n"
	.string "mig at følge med i trends!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Hele denne sag om “{STR_VAR_1}”... \n"
	.string "Er der ikke et tv-program om det?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Over havet…\p"
	.string "Er “{STR_VAR_1}” endnu mere\n"
	.string "populær?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Jeg samler på officielt\n"
	.string "“{STR_VAR_1}” licenseret\l"
	.string "merchandise.\p"
	.string "Jeg har officielle “{STR_VAR_1}”\n"
	.string "DUKKER…\p"
	.string "Officielt “{STR_VAR_1}” brandtøj…\p"
	.string "Og officielt licenseret\n"
	.string "“{STR_VAR_1}” billedbøger.\p"
	.string "Heheh, jeg ejer! Jeg deler ikke noget\n"
	.string "med dig!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "IDENTIFICERE DET GODE\n"
	.string "“{STR_VAR_1}” & DÅRLIG\l"
	.string "“{STR_VAR_1}”…\p"
	.string "FORBINDELSEN MELLEM “{STR_VAR_1}”\n"
	.string "OG POKéMON…\p"
	.string "BRUGBART “{STR_VAR_1}”…\p"
	.string "Den er pænt proppet med bøger om\n"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_TrendsScream:
	.string "“{STR_VAR_1}'S SKRIG” er titlen.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "“{STR_VAR_1}'S SMIL” er titlen.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Den hedder “DEN SIDSTE {STR_VAR_1}.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Det hedder “FØDSEL AF {STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "Jeg så “{STR_VAR_1}”! Fedt, hva’?\p"
	.string "Det er li’som det fedeste nogensinde!\p"
	.string "Det var fantastisk! Det var ægte vare,\n"
	.string "oh yeah!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Åh nej, nej, nej.\p"
	.string "Den påståede “{STR_VAR_1}” du\n"
	.string "siger, at du har set -- det er det ikke.\p"
	.string "Det autentiske produkt er meget…\n"
	.string "Hvordan skal jeg sige det? Skarpere, men\l"
	.string "mere blidt!\p"
	.string "Åh, det betyder ikke noget. Det er\n"
	.string "fantastisk!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Hej, lyt lige, jeg har komponeret en\n"
	.string "temasang til “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}” er virkelig populær\n"
	.string "lige nu.\p"
	.string "Okay, lyt! … …\p"
	.string "Åh! {STR_VAR_1}!\p"
	.string "Fantastisk {STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "Jeg tør nok sige, makker, at det ville\n"
	.string "betale sig for dig at arbejde på din\l"
	.string "sang, inden du fornøjer dig med\l"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Nå, som jeg sagde tidligere, burde vi\n"
	.string "samles og arrangere en\l"
	.string "“{STR_VAR_1}” fest på øen.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Åh, en fantastisk god idé!\p"
	.string "Det vil afgøre en gang for alle hvem der\n"
	.string "er bedst til “{STR_VAR_1}.” Brilliant,\l"
	.string "uden tvivl!\p"
	.string "Fra i dag vil vores liv dreje sig om\n"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Jeg tænkte dog...\p"
	.string "Ville du ikke være enig i, at\n"
	.string "“{STR_VAR_1}” er blevet mere end\l"
	.string "bare en trend og er blevet en del af\l"
	.string "vores hverdag?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Undskyld? Så meget, hvad?\p"
	.string "Dog er det sandt, at “{STR_VAR_1}”\n"
	.string "vejer tungt på dit sind, uanset om du er\l"
	.string "vågen eller sover.\p"
	.string "Helt sikkert, du er den\n"
	.string "“{STR_VAR_1}” PROFESSOR, gamle ven!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Hvis du og jeg danner et team som en\n"
	.string "duo, vil vi være uovervindelige, når det\l"
	.string "kommer til alle ting “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Spot on, my friend!\p"
	.string "We shall be the “{STR_VAR_1}” DUO!\p"
	.string "Isn't that a ripe image? Hahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "For mig er SLUDGE BOMB på toppen af\n"
	.string "popularitet. Det er den.\p"
	.string "Hvad? Du fortæller mig, at du ikke\n"
	.string "kender til SLUDGE BOMB?\p"
	.string "Det er altså ynkeligt. Jeg giver dig én.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Jeg elsker SLAMMEREGBOMBE.\p"
	.string "Men POKéMON med angrebet\n"
	.string "“{STR_VAR_1}” er også med.$"



