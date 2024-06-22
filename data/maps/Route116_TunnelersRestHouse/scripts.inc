@ TRANSLATED

Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Den RUSTAKKER TUNNEL der…\p"
	.string "Først havde vi en stor arbejdsstyrke, der\n"
	.string "borede gennem stenen med den nyeste\l"
	.string "maskinteknologi. Men vi var nødt til at\l"
	.string "stoppe.\p"
	.string "Det viser sig, at vi ville have haft en\n"
	.string "negativ effekt på vilde POKéMON i området.\p"
	.string "Så vi har intet andet at gøre end at dumpe\n"
	.string "rundt her og lave ingenting.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Der er en mand, der graver sig vej til\n"
	.string "VERDANTURF helt alene. Han er desperat for\l"
	.string "at komme igennem.\p"
	.string "Han siger, at hvis han graver lidt ad gangen\n"
	.string "uden at bruge maskiner, vil han ikke\l"
	.string "forstyrre POKéMON og undgå at skade den\l"
	.string "naturlige miljø.\p"
	.string "Jeg undrer mig over, om han er kommet\n"
	.string "igennem endnu.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "For at komme til VERDANTURF uden at bruge\n"
	.string "denne TUNNEL, skulle du krydse havet til\l"
	.string "DEWFORD, sejle videre til SLATEPORT og\l"
	.string "derefter rejse gennem MAUVILLE.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Har du hørt? TUNNELEN til VERDANTURF er\n"
	.string "blevet færdig!\p"
	.string "Nogle gange, hvis du håber stærkt nok, går\n"
	.string "drømme i opfyldelse.$"



