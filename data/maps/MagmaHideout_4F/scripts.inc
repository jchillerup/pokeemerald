@ TRANSLATED

.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Jeg vil også gerne se GROUDON, men de\n"
	.string "vil ikke engang lade mig se dens hale…\p"
	.string "Det får mig virkelig til at føle mig frustreret.\p"
	.string "Åh nej!\n"
	.string "Jeg sladrede om GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Jeg gætter på, at det er umuligt at vinde,\n"
	.string "hvis man ikke har et roligt sind…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
.string "Jeg undrer mig over, om GROUDON overhovedet har en hale?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Snart! Meget snart!\p"
	.string "Vores store mål vil blive opnået!$" 

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "Jeg er kommet så langt, men nu dette?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAXIE, sir!\n"
	.string "En indtrænger er på vej mod dig!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Du er ikke færdig endnu!\n"
	.string "Du kommer ikke forbi mig så let!$"

MagmaHideout_4F_Text_Grunt13Defeat:
.string "Var jeg virkelig så nem at vælte?\p$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "Kom så, ét mere spil…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hihihi!\n"
	.string "Du er nået så langt, så jeg vil fortælle dig!\p"
	.string "Det passer!\n"
	.string "Lige forude sover GROUDON!\p"
	.string "MAXIE gik til GROUDON for et par\n"
	.string "sekunder siden!\p"
	.string "Det vil snart vågne op!\n"
	.string "Hihi! Hihihi!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Taget ned igen…\n"
	.string "Haha…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…Og imens du spildte tid med mig,\n"
	.string "MAXIE burde have vækket GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE: GROUDON…\p"
	.string "Intet kunne vække dig fra din\n"
	.string "søvn badet i magma…\p"
	.string "Denne BLÅ ORB er hvad du søgte.\n"
	.string "Var det ikke?\p"
	.string "Jeg har bragt dig den BLÅ ORB.\n"
	.string "Lad dens skær vække dig!\p"
	.string "Og vis mig…\n"
	.string "Vis mig din fulde kraft!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE: GROUDON!\n"
	.string "Hvad er der galt?\p"
	.string "Var DEN BLÅ ORB ikke nøglen?\p"
	.string "GROUDON!\n"
	.string "Hvor er du taget hen...$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAXIE: Åh, så det var dig?\p"
	.string "Jeg har set dig rode rundt uden\n"
	.string "invitation her og der…\p"
	.string "Nu forstår jeg det!\n"
	.string "Du må have lavet et billigt trick!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Hvad gør dig så dygtig til at håndtere\n"
	.string "POKéMON?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAXIE: Der må være en grund til, at\n"
	.string "GROUDON flygtede…\p"
	.string "Det er det, du forsøger at sige,\n"
	.string "ikke sandt?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hmph…\n"
	.string "Tror du, jeg ikke vidste det?\p"
	.string "Nu da GROUDON er væk, er der ikke\n"
	.string "længere brug for denne forbandende\n"
	.string "vulkan.\p"
	.string "Jeg tager efter GROUDON, så her\n"
	.string "skilles vores veje!$"

