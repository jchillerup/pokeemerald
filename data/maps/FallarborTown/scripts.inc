@ TRANSLATED

FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Der sker noget,\n"
	.string "og jeg kan ikke lide det!\p"
	.string "Jeg har set skyggefulde personer vandre\n"
	.string "ind og ud af PROF. COZMO's hjem...$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Denne region har været kendt for meteorer\n"
	.string "siden oldtiden.\p"
	.string "De siger, at METEOR FALLS blev udgravet\n"
	.string "af en faldende meteorit for længe\n"
	.string "siden.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Se! Tag et kig!\n"
	.string "Det her er min dyrebare AZURILL!\p"
	.string "Den er glat og blød og plysset, også!$"

FallarborTown_Text_Azurill:
.string "AZURILL: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Har du allerede udfordret FLANNERY,\n"
	.string "LEDEREN af LAVARIDGE GYM?\p"
	.string "Pigens bedstefar var berømt.\n"
	.string "Han var en af de FIRSKE I\l"
	.string "POKéMON LIGAEN på et tidspunkt.\p"
	.string "Det ville ikke overraske mig at se FLANNERY\n"
	.string "blive en stor TRÆNER i sin egen\l"
	.string "ret.$"

FallarborTown_Text_BattleTentSign:
	.string "KAMP TELT FALLARBOR PLADS\n"
	.string "“Må de største hold samles!”$"

FallarborTown_Text_TownSign:
	.string "FALLARBOR TOWN\n"
	.string "“Et bondegårdssamfund med små haver.”$"

FallarborTown_Text_MoveTutorSign:
	.string "MOVE TUTOR'S HOUSE\n"
	.string "“Nye angreb lært til POKéMON.”$"



