@ TRANSLATED

.set LOCALID_WINGULL, 3

FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "Ved at være sammen med POKéMON, får\n"
	.string "folk flere og flere venner.\p"
	.string "Og det bringer verden tættere sammen.\n"
	.string "Jeg synes, det er vidunderligt!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "Der! Go, FUGL POKéMON!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "Hihi, jeg bad min WINGULL om atløbe en\n"
	.string "ærinde for mig.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "Godt! Velkommen tilbage, WINGULL!\p"
	.string "Hov? Hvad er dette? Hvad holder den\n"
	.string "på?\p"
	.string "En MENTAL URTE? Den må have samlet den\n"
	.string "op et sted.\p"
	.string "Men jeg er ikke en TRÆNER, så du kan få\n"
	.string "den.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "Takket være min WINGULL har jeg venner\n"
	.string "som bor langt væk.$"

FortreeCity_House4_Text_Wingull:
.string "WINGULL: Pihyoh!$"



