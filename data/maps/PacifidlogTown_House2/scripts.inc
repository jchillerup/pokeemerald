@ TRANSLATED

PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_FRUSTRATION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "Undskyld!\p"
	.string "Jeg er formandens lillebror fra POKéMON\n"
	.string "KLUBBEN. Jeg nyder min ferie med\l"
	.string "POKéMON, ja, det er sandt.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "Åh! Din POKéMON...$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "Den kan tydeligvis rigtig godt lide dig.\p"
	.string "En POKéMON, der er hengiven og\n"
	.string "bedårende, fortjener en TM som denne,\l"
	.string "ikke?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "Hmm… Det er ikke dårligt, men det er\n"
	.string "heller ikke godt.\p"
	.string "Du, som TRÆNER, skal lægge lidt mere\n"
	.string "indsats i det.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "Den ser farlig ud.\p"
	.string "En uhyggelig POKéMON som den fortjener\n"
	.string "en TM som denne.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "Hvis en POKéMON kan lide dig meget,\n"
	.string "RETURNs kraft bliver forstærket.\p"
	.string "Hvis den ikke kan lide dig,\n"
	.string "FRUSTRATIONs kraft stiger.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "Åh ja. Omkring {STR_VAR_1} eller så\n"
	.string "dage, skulle jeg få et par gode TM'er.\p"
	.string "Du burde komme og besøge mig. Jeg giver\n"
	.string "dig en TM, der passer til dine POKéMON.$"

PacifidlogTown_House2_Text_Rurii:
.string "AZURILL: Rurii.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "Det virker meget venligt overfor\n"
	.string "TRÆNER.$"

PacifidlogTown_House2_Text_Rururi:
.string "AZURILL: Rururi!$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "Det ser ikke ud til at kunne lide\n"
	.string "TRÆNEREN så meget.$"



