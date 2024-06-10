@ TRANSLATED

.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Du er…\n"
	.string "Åh, du må være {PLAYER}{KUN}, ikke sandt?\p"
	.string "Tak for at lege med WALLY for et\n"
	.string "øjeblik siden.\p"
	.string "Han har været skrøbelig og syg\n"
	.string "lige siden han var en baby.\p"
	.string "Vi har sendt ham til at bo hos mine\n"
	.string "slægtninge i VERDANTURF BY et stykke tid.\p"
	.string "Luften er meget renere der\n"
	.string "end den er her.\p"
	.string "Hvad siger du? Hvor er WALLY?\n"
	.string "Han er allerede taget afsted, vores WALLY.\p"
	.string "Jeg undrer mig over, hvor han mon\n"
	.string "er taget hen nu?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Jeg spekulerer på, hvordan vores WALLY har det?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Undskyld os venligst for\n"
	.string "at trække dig hertil på denne måde.\p"
	.string "Men vores WALLY er blevet meget\n"
	.string "sund siden han tog til VERDANTURF BY.\p"
	.string "Vi skylder det hele til dig!\p"
	.string "Da WALLY forlod byen, hjalp du\n"
	.string "ham med at fange en POKéMON, ikke sandt?\p"
	.string "Jeg tror det gjorde WALLY virkelig\n"
	.string "lykkelig.\p"
	.string "Faktisk ikke kun WALLY.\n"
	.string "Det gjorde mig, hans far, også glad.\p"
	.string "Glad for at han har fået sådan en\n"
	.string "fantastisk ven som dig.\p"
	.string "Dette er ikke en bestikkelse eller noget,\n"
	.string "men jeg vil virkelig gerne give dig dette.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Hvis din POKéMON kan SURFE, kan du\n"
	.string "komme til alle mulige steder.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "WALLY kommer hjem snart.\n"
	.string "Jeg glæder mig til det.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Nå? Mødte du WALLY i\n"
	.string "EVER GRANDE CITY?\p"
	.string "Åh, {PLAYER}{KUN}, vær nu ikke fjollet.\p"
	.string "Han er måske blevet rask, men han\n"
	.string "kan ikke tage sådan en lang tur\l"
	.string "helt alene.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "WALLY var virkelig glad, da han\n"
	.string "fortalte os, at han havde fanget en\n"
	.string "POKéMON.\p"
	.string "Det er evigheder siden, jeg har set\n"
	.string "ham smile sådan.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Jeg vil have dig til at holde dette\n"
	.string "hemmeligt for min mand…\p"
	.string "Men vores WALLY forlod VERDANTURF\n   TOWN\n"
	.string "uden at fortælle nogen.\p"
	.string "Du ved, WALLY er skrøbelig, men\n"
	.string "han er overraskende viljestærk.\p"
	.string "Jeg er sikker på, at han en dag\n"
	.string "vil vende tilbage i god behold!$"



