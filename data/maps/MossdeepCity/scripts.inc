@ TRANSLATED

.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "Jeg fik dette fra STEVEN, men jeg ved\n"
	.string "ikke, hvad det er godt for.\p"
	.string "Jeg tror, det hedder KONGENS STEN.\n"
	.string "Vil du have den?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Hvorfor vil du have det?\n"
	.string "Du er mærkelig.\p"
	.string "Du kan beholde det, men hold det hemmeligt\n"
	.string "for STEVEN.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "STEVENS hus er lige derovre!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Ja, det tror du også! Hvad er du\n"
	.string "meningen at gøre med en underlig sten?$"

MossdeepCity_Text_WailmerWatching:
	.string "Omkring MOSSDEEP kan du se vilde\n"
	.string "WAILMER.\p"
	.string "Det kaldes, øh...\n"
	.string "Hvad var det nu...?\p"
	.string "WAI, WAI, WAI...\p"
	.string "WAILMER-observation!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "Øens RUMCENTER har sendt store raketter\n"
	.string "til afsted.\p"
	.string "Der har været en form for tumult\n"
	.string "over et brev de modtog for nylig.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "Øens RUMCENTER har været\n"
	.string "i gang med at sende store raketter.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "Jeg hørte fra en SØMANDskammerat, at\n"
	.string "HOLD AQUA har slået sig ned i LILYCOVE.\p"
	.string "Jeg hørte også, at nogen kom og\n"
	.string "fejede gulvet med dem!\p"
	.string "Men her i MOSSDEEP har HOLD MAGMA\n"
	.string "sat deres øjne på os.\p"
	.string "Hvis du vil vide, hvad de går og laver,\n"
	.string "så besøg RUMCENTRET.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Jeg er en SØMAND, så havet er selvfølgelig\n"
	.string "vigtigere for mig.\p"
	.string "Men ved du hvad? Når jeg kommer tilbage\n"
	.string "på land efter en lang rejse, føler jeg lettelse!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Ville det ikke være dejligt?\p"
	.string "Hvis hele verden var dækket af\n"
	.string "planter og blomster som denne ø?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Alt liv har brug for havet for at\n"
	.string "overleve, selvom det har sit hjem på\n"
	.string "landjorden.\p"
	.string "Livet, når det har nået sin ende,\n"
	.string "bliver til jord og vender tilbage til\n"
	.string "landjorden.\p"
	.string "Og havet er altid forbundet med\n"
	.string "landjorden.\p"
	.string "Ja, ligesom kystlinjen lige her.$"

MossdeepCity_Text_SurfExhilarating:
	.string "En rejse på et skib er fint.\p"
	.string "Men at krydse havet med POKéMON\n"
	.string "ved at bruge SURF…\p"
	.string "Det er virkelig en spændende tur!\n"
	.string "Er du ikke enig, knægt?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Denne sten har en særlig betydning for\n"
	.string "folkene på RUMCENTERET.\p"
	.string "De har sat den her som en ønskesten\n"
	.string "om, at deres raketter vil flyve sikkert.\p"
	.string "Når du ønsker dig noget, hvad bruger du?\n"
	.string "Ønsker du på en stjerne?\p"
	.string "Jeg bruger en ønske-seddel til at gøre\n"
	.string "det sket.\p"
	.string "Det er min måde at gøre det på.$"

MossdeepCity_Text_ItsAWhiteRock:
.string "Det er en hvid sten.$"

MossdeepCity_Text_GymSign:
	.string "MOSSDEEP CITY POKéMON GYM\n"
	.string "LEADERS: LIZA & TATE\p"
	.string "“Den mystiske kombination!”$"

MossdeepCity_Text_CitySign:
	.string "Mossdeep By\n"
	.string "“Vores slogan: Værn om POKéMON!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "Mossdeep Space Center\n"
	.string "Det nærmeste sted til rummet.$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, føler du dig godt tilpas?\n"
	.string "Jeg har det strålende!\p"
	.string "Jeg havde hørt, at GYMLEDEREN i MOSSDEEP\n"
	.string "er ret stærk, så jeg besluttede mig for at\n"
	.string "tage et kig selv.\p"
	.string "Men der er noget underligt ved denne by.\p"
	.string "Folk snakker om et advarselsbrev og\n"
	.string "RUMCENTRET…\p"
	.string "Jeg tror dog ikke, det vedrører mig på\n"
	.string "nogen måde.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Åh… Det føles fantastisk at lade bølgerne\n"
	.string "vaske over mine fødder…\p"
	.string "Når vi taler om bølgerne, ved du at\n"
	.string "øbyen SOOTOPOLIS?\p"
	.string "Jeg tror, at GYMMET der har fået en ny\n"
	.string "LEDER.\p"
	.string "Folk fortæller mig, at den nye\n"
	.string "LEDER engang var mentor for WALLACE.$"



