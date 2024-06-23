@ TRANSLATED

VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "WALLY: Jeg tabte til dig, {PLAYER},\n"
	.string "men jeg er ikke længere nedtrykt.\p"
	.string "Fordi jeg har en ny mening med mit liv.\n"
	.string "Sammen med min RALTS vil jeg tage\l"
	.string "udfordringen op fra POKéMON GYMS og\l"
	.string "blive en fantastisk TRÆNER.\p"
	.string "Vær sød at følge med, {PLAYER}. Jeg vil\n"
	.string "blive stærkere end dig.\p"
	.string "Når jeg er det, vil jeg udfordre dig til\n"
	.string "en anden kamp.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "WALLY: Vær sød at se på mig, {PLAYER}.\n"
	.string "Jeg vil blive stærkere end dig.\p"
	.string "Når jeg gør det, vil jeg udfordre dig til\n"
	.string "endnu et slag.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "ONKEL: Åh! {PLAYER}{KUN}! WALLY bor ved\n"
	.string "siden af.\p"
	.string "Men, dreng, der er noget, jeg skal\n"
	.string "fortælle dig.\p"
	.string "Denne naturlige omgivelse gør\n"
	.string "vidundere for WALLYs helbred.\p"
	.string "Måske er det ikke kun omgivelserne.Det\n"
	.string "kunne være POKéMON, der giver drengen\l"
	.string "håb.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "WALLY er taget væk… Han smuttede af på\n"
	.string "egen hånd…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "ONKEL: Er det rigtigt? WALLY er gået så\n"
	.string "langt væk helt på egen hånd…\p"
	.string "Nå, jeg må give ham kredit - han er min\n"
	.string "lillebrors søn.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "WANDA: Hvem er du? Åh, nu forstår jeg!\p"
	.string "Du er {PLAYER}, som WALLY fortalte\n"
	.string "mig om.\p"
	.string "Jeg er WALLYs fætter. Det er dejligt at\n"
	.string "møde dig!\p"
	.string "Jeg synes, at WALLY er blevet meget\n"
	.string "mere livlig og sund siden han kom hertil.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "WANDA: Bare rolig med WALLY. Han skal\n"
	.string "nok klare sig.\p"
	.string "Jeg kender min lille fætter, og han har\n"
	.string "også POKéMON med sig.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Takket være dig kan jeg se min kæreste\n"
	.string "hver dag. Er jeg glad? Du kan tro, jeg er!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Min datters kæreste er en meget\n"
	.string "dedikeret og lidenskabelig person.\p"
	.string "Han har gravet en tunnel uden stop,\n"
	.string "bare for at kunne se min datter.\p"
	.string "Min datter er lidt bekymret, så hun går\n"
	.string "ofte ud til tunnelen.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Det er fantastisk. Min datters kæreste\n"
	.string "var ved at grave tunnelen for hånd!\p"
	.string "Det er så utroligt!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Hvis der sker noget med WALLY, ville jeg\n"
	.string "aldrig kunne se hans forældre i\l"
	.string "PETALBURG i øjnene…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "WALLY var i EVER GRANDE?\p"
	.string "Hans forældre i PETALBURG ville blive\n"
	.string "overraskede over at høre det!$"



