@ TRANSLATED

.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Åh, wauw, {PLAYER}{KUN}. Jeg er\n"
	.string "forbløffet over, at du fandt mig.\p"
	.string "Tror du, uh... måske på mig som bare en\n"
	.string "stenmaniac?\p"
	.string "Nej, det kan ikke være rigtigt.\p"
	.string "Vi kæmpede side om side på SOOTOPOLIS\n"
	.string "SPACE CENTER.\p"
	.string "Du burde have en rigtig god idé om, hvor god\n"
	.string "jeg er.\p"
	.string "Okay, {PLAYER}{KUN}, hvis du vil udfordre mig\n"
	.string "alvorligt, forvent det værste!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Du… Jeg havde ingen anelse om, at du ville\n"
	.string "blive så stærk…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Når jeg tænker over det, siden\n"
	.string "vores veje først mødtes i GRANIT HULEN i\l"
	.string "DEWFORD, har jeg halet denne følelse efter. \p"
	.string "Jeg tænkte, at du ville blive MESTEREN.\p"
	.string "Mine forudsigelser plejer at holde.\p"
	.string "Hvor vil du gå hen herfra?\p"
	.string "… … … … … … … … … … … …\p"
	.string "Fufufu, selv jeg kunne ikke fortælle dig\n"
	.string "det.$"



