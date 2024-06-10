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
	.string "Først havde vi en stor arbejdsstyrke,\n"
	.string "der borede gennem stenen med den\n"
	.string "nyeste maskinteknologi.\l"
	.string "Men vi var nødt til at stoppe.\p"
	.string "Det viser sig, at vi ville have haft en\n"
	.string "negativ effekt på vilde POKéMON i\n"
	.string "området.\p"
	.string "Så vi har intet andet at gøre end at\n"
	.string "dumpe rundt her og lave ingenting.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Der er en mand, der graver sig vej til\n"
	.string "VERDANTURF helt alene.\l"
	.string "Han er desperat for at komme igennem.\p"
	.string "Han siger, at hvis han graver lidt\n"
	.string "ad gangen uden at bruge maskiner,\n"
	.string "vil han ikke forstyrre POKéMON og\n"
	.string "undgå at skade den naturlige\n"
	.string "miljø.\p"
	.string "Jeg undrer mig over, om han er kommet\n"
	.string "igennem endnu.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "For at komme til VERDANTURF uden at\n"
	.string "bruge denne TUNNEL, skulle du krydse\n"
	.string "havet til DEWFORD, sejle videre til\n"
	.string "SLATEPORT og derefter rejse gennem\n"
	.string "MAUVILLE.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Har du hørt? TUNNELEN til VERDANTURF\n"
	.string "er blevet færdig!\p"
	.string "Nogle gange, hvis du håber stærkt nok,\n"
	.string "går drømme i opfyldelse.$"



