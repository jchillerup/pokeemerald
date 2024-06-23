@ TRANSLATED

FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. COZMO: Åh… Jeg burde aldrig have\n"
	.string "ladet mig snyde til at fortælle TEAM\l"
	.string "MAGMA, hvor du kan finde METEORITTER…\p"
	.string "Den METEORIT fra METEOR FALLS… Den vil\n"
	.string "aldrig blive min nu…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Åh! Hva?\p"
	.string "Det objekt…\p"
	.string "Kan det være?\p"
	.string "Er det METEORITEN som TEAM MAGMA tog\n"
	.string "fra METEOR FALLS?\p"
	.string "Må jeg få det, tak?\p"
	.string "Jeg beder ikke om det gratis. Hvad siger\n"
	.string "du til en byttehandel med denne TM?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. COZMO: Denne TM repræsenterer\n"
	.string "min følelse af taknemmelighed. Brug den\l"
	.string "venligst!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. COZMO: Åh, jeg kan ikke tro det.\n"
	.string "Det her er virkelig, virkelig fantastisk!\p"
	.string "Det her vil virkelig hjælpe med min\n"
	.string "forskning!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. COZMO: Åh, men... Jeg er knust af\n"
	.string "skuffelse...$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. COZMO: Må jeg bede om den\n"
	.string "METEORIT?\p"
	.string "Jeg beder ikke om den gratis. Hvad med i\n"
	.string "bytte for denne TM?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "PROF. COZMO tog afsted til METEOR\n"
	.string "FALLS på RUTE 114 med nogle mennesker\l"
	.string "fra TEAM MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Stakkels Prof. COZMO... Han er så\n"
	.string "deprimeret... Jeg synes ondt af ham.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Kig på PROF. COZMO… Han er så glad! Jeg\n"
	.string "synes, det er sødt.$"



