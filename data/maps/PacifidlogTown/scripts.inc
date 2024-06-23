@ TRANSLATED

PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "Havet mellem PACIFIDLOG og SLATEPORT\n"
	.string "har en hurtigt løbende tidevand.\p"
	.string "Hvis du beslutter dig for at SURFE, kan\n"
	.string "du ende et helt andet sted.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Se, er det ikke skønt? Disse huse er på\n"
	.string "vandet!\p"
	.string "Jeg blev født her!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "Himlens PILLE?\p"
	.string "…Åh, du mener nok den høje, høje tårn\n"
	.string "lidt længere væk.\p"
	.string "Hvis du spørger mig, ville jeg ikke\n"
	.string "bestige det. Det er alt for uhyggeligt\l"
	.string "at komme så højt op.$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIDLOG BY\p"
	.string "“Hvor morgensolen smiler ned på\n"
	.string "vandene.”$"



