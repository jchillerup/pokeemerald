@ TRANSLATED

.set LOCALID_DOCK, 1

SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Øhm... Hvis dette skal her, og\n"
	.string "det skal derhen...\p"
	.string "Hvor skal denne ting så\n"
	.string "hen?\n"
	.string "Og hvad med den dims der? \p"
	.string "Åh nej! Jeg kan ikke finde\n"
	.string "rundt i det her!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hm?\n"
	.string "Hej, jeg er DOCK.\p"
	.string "CAPT. STERN bad mig om at\n"
	.string "designe en færge.\p"
	.string "Åh! Er det DER DE FISK?\p"
	.string "Men, hmm…\n"
	.string "Dette går ikke…\p"
	.string "CAPT. STERN er taget et sted hen.\n"
	.string "Han sagde, han havde noget arbejde.\p"
	.string "Kunne jeg bede dig finde CAPT.\n"
	.string "STERN og give det til ham?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "DOCK: Hvor mon KAPT. STERN\n"
	.string "er taget hen?\p"
	.string "Kunne du finde KAPT. STERN og\n"
	.string "levere den pakke til ham?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "DOCK: Skibsbygning er en kunst.\p"
	.string "En masse ting kan ikke findes ud af\n"
	.string "bare ved at regne.\p"
	.string "Jeg kunne virkelig bruge råd fra en veteran\n"
	.string "som kender havene...$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "DOCK: Hej! MR. BRINEY er kommet for at\n"
	.string "hjælpe os.\p"
	.string "Takket være den erfarne sømand,\n"
	.string "færgen tager form.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK: Færgen er endelig klar!\p"
	.string "Den nye S.S. TIDAL er virkelig et\n"
	.string "teknologisk vidunder!\p"
	.string "Men jeg har en fornemmelse af, at vi\n"
	.string "kan lave noget endnu bedre.\p"
	.string "Du ved, der er aldrig en ende på\n"
	.string "teknologiens udvikling.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "MR. BRINEY: Åh, {PLAYER}{KUN}!\n"
	.string "Det er alt for længe siden!\p"
	.string "Ja, siden jeg sidst så dig, har denne\n"
	.string "gamle søulk fået lyst til eventyr!\p"
	.string "Så jeg har besluttet at hjælpe DOCK\n"
	.string "med at bygge en færge.\p"
	.string "Ja, for en færge vil kunne fragte\n"
	.string "mange mennesker.\p"
	.string "Men, ved du hvad, den DOCK er virkelig\n"
	.string "noget særligt.\p"
	.string "Med hans evner for teknologi og min\n"
	.string "erfaring, er jeg sikker på, at vi kan\l"
	.string "bygge et fantastisk skib, ja!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Årstiderne, vejret, hvor\n"
	.string "månen sidder på himlen…\p"
	.string "Disse og andre forhold får\n"
	.string "havet til at skifte udtryk.\p"
	.string "Præcis!\n"
	.string "Havet er som en levende ting!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Jeg bliver søsyg meget let.\n"
	.string "Så jeg får lov til at hjælpe her i stedet.$"



