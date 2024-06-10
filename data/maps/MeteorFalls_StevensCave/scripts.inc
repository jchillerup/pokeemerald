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
	.string "STEVEN: Åh, wauw, {PLAYER}{KUN}.\n"
	.string "Jeg er forbløffet over, at du fandt mig.\p"
	.string "Tror du, uh... måske på mig\n"
	.string "som bare en stenmaniac?\p"
	.string "Nej, det kan ikke være rigtigt.\p"
	.string "Vi kæmpede side om side på\n"
	.string "SOOTOPOLIS SPACE CENTER.\p"
	.string "Du burde have en rigtig god idé\n"
	.string "om, hvor god jeg er.\p"
	.string "Okay, {PLAYER}{KUN}, hvis du vil\n"
	.string "udfordre mig alvorligt, forvent det værste!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Du…\n"
	.string "Jeg havde ingen anelse om, at du ville blive så stærk…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Når jeg tænker over det, siden\n"
	.string "vores veje først mødtes i GRANIT\l"
	.string "HULEN i DEWFORD, har jeg halet\n"
	.string "denne følelse efter. \p"
	.string "Jeg tænkte, at du ville blive\n"
    .string "MESTEREN.\p"
    .string "Mine forudsigelser plejer at holde.\p"
    .string "Hvor vil du gå hen herfra?\p"
    .string "… … … … … …\n"
    .string "… … … … … …\p"
    .string "Fufufu, selv jeg kunne ikke fortælle dig det.$"



