@ TRANSLATED

DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Der er meget at sige om at bo på en lille\n"
	.string "ø som denne i harmoni med POKéMON og\l"
	.string "familien.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Jeg forlod den store havn i SLATEPORT\n"
	.string "CITY da jeg giftede mig med min mand her.\p"
	.string "Livet går langsomt her på denne lille ø.\n"
	.string "Men at være omgivet af det smukke hav -\l"
	.string "det er også lykke.$"

DewfordTown_House1_Text_Zigzagoon:
.string "ZIGZAGOON: Guguuh!$"



