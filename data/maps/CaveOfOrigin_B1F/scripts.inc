@ TRANSLATED

.set LOCALID_WALLACE, 1

CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Åh, så du er {PLAYER}{KUN}? Jeg har hørt\n"
	.string "fortællinger om dine bedrifter.\p"
	.string "Mit navn er WALLACE.\p"
	.string "Jeg var engang GYM-leder i SOOTOPOLIS, men\n"
	.string "der skete noget.\p"
	.string "Så nu har jeg betroet min mentor JUAN\n"
	.string "driften af GYMet.\p"
	.string "… … … … … … … … … … … …\p"
	.string "GROUDON og KYOGRE, de to POKéMON, der\n"
	.string "hærger her, anses for at være super- gamle\l"
	.string "POKéMON.\p"
	.string "Men der er ikke kun to super- gamle POKéMON.\p"
	.string "Et sted er der en mere.\p"
	.string "Et sted er der en super- gammel POKéMON ved\n"
	.string "navn RAYQUAZA.\p"
	.string "Det siges, at det var RAYQUAZA, der fik de to\n"
	.string "rivaler til at falde til ro i fortiden.\p"
	.string "Men selv jeg har ingen anelse om, hvor\n"
	.string "RAYQUAZA befinder sig…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE: {PLAYER}{KUN}, ved du måske hvor\n"
	.string "RAYQUAZA er nu?\p"
	.string "Hvis du gør, så sig det venligst.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE: Hulen ORIGINS?\p"
	.string "Men det er lige her! Jeg har brug for dig til at\n"
	.string "gøre det bedre end det!\p"
	.string "Oh, jeg skal bede dig om at tænke over, hvor\n"
	.string "RAYQUAZA kan være lige nu.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE: MT. PYRE?\p"
	.string "Men da jeg mødte den gamle dame der\n"
	.string "tidligere, nævnte hun det ikke.\p"
	.string "Jeg tvivler meget på, at den gamle dame ville\n"
	.string "forsøge at skjule noget for mig…\p"
	.string "{PLAYER}{KUN}, kunne du tænke over dette lidt\n"
	.string "mere omhyggeligt for mig?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE: Hov? Kan du ikke huske? Hmm... Det\n"
	.string "er et problem...\p"
	.string "Kan du ikke huske på nogen måde?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE: Himlens PILLAR?\p"
	.string "Det er den! Det må være HIMLENS PILLAR!\p"
	.string "{PLAYER}{KUN}, der er ikke et øjeblik at miste!\n"
	.string "Vi drager straks til HIMLENS PILLAR!$"



