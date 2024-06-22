@ TRANSLATED

Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "Jeg har hørt om en hule kaldet\n"
	.string "OPRINDELSENS HULE.\p"
	.string "Folk rygter, at ånderne af POKéMON\n"
	.string "genopstår der. Kunne noget sådant\l"
	.string "virkelig ske?$"

Route119_House_Text_Wingull:
.string "WINGULL: Pihyoh!$"



