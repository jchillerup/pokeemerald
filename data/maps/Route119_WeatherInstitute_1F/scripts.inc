@ TRANSLATED

.set LOCALID_LITTLE_BOY, 5

Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "BOSSen blev interesseret i\n"
	.string "forskningen, de har gang i her,\l"
	.string "så han sendte os ud.\p"
	.string "Hold dig udenfor!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Pokkers…\n"
	.string "Blevet slået af et barn…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Vores CHEF ved alt.\p"
	.string "Men jeg er bare en FODTROPS. Hvad skulle\n"
	.string "jeg vide om, hvad han tænker?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Hov?\n"
	.string "Hvad laver en unge her?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Hvad?\n"
	.string "Jeg tabte?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:

	.string "Åh nej…\n"
	.string "Jeg får en ordentlig skideballe for at tabe til et barn…\p"
	.string "Jeg burde bare tage en lur i sengen…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Mens jeg sov, gik alle ovenpå!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Wow, du er virkelig stærk!\p"
	.string "Jeg ønsker, at jeg kunne være en POKéMON TRÆNER\n"
	.string "ligesom dig!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "PROFESSOREN elsker regn.\n"
	.string "Det er en kendsgerning.\p"
	.string "Men hvis det bliver ved med at regne, vil\n"
	.string "mennesker have problemer. Det er en anden\n"
	.string "kendsgerning.\p"
	.string "Og derfor undersøger PROFESSOREN, om\n"
	.string "regnen kan bruges på en god måde.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "På 2. sal af INSTITUTET,\n"
	.string "studerer vi vejrmønstrene over\l"
	.string "HOENN-regionen.\p"
	.string "Vi har bemærket midlertidige og\n"
	.string "isolerede tilfælde af tørke og\l"
	.string "kraftig regn på det seneste…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Hej!\n"
	.string "Vi er blevet reddet af dine handlinger!\p"
	.string "Det jeg ikke forstår er, hvad i\n"
	.string "al verden AQUAS lavede.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Der er en seng…\n"
	.string "Lad os hvile.$"



