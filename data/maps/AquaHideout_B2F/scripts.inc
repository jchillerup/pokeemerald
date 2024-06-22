@ TRANSLATED

.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_MATT
	setvar VAR_0x8009, LOCALID_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hihihi…\p"
	.string "Er du allerede her? Vi undervurderede dig!\p"
	.string "Men det er slut!\p"
	.string "Jeg er bedre end de GRUNTERS, du har set\n"
	.string "hidtil.\p"
	.string "Jeg spilder ikke tiden. Jeg vil pulverisere\n"
	.string "dig!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hihihi… Så, jeg tabte også…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hihihi!\p"
	.string "Mens jeg legede med dig, fik vores BOSS\n"
	.string "gjort sig klar!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Hihihi!\p"
	.string "Vores BOSS er allerede taget afsted til en\n"
	.string "grotte under havet!\p"
	.string "Hvis du vil indhente ham, skal du bedre lede i\n"
	.string "det store, vide hav beyond LILYCOVE.\p"
	.string "Men vil du finde den så? Hihihi!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, jeg blev træt af at vente! Du\n"
	.string "skylder mig også en kamp!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Træt af at vente… Forvirret og fortabt…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "BOSS... Er dette godt nok?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Warp paneler, skjulestedets stolthed og\n"
	.string "glæde!\p"
	.string "Du har ingen anelse om, hvor du er, gør du\n"
	.string "ikke?\p"
	.string "Forvirr og træt fjenden ud, og så sænk\n"
	.string "bommen! Det er vores plan!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Hvad er der galt med dig? Du er overhovedet\n"
	.string "ikke træt!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Det minder mig om... Jeg kan ikke huske, hvor\n"
	.string "jeg lagde MESTERBOLDEN.\p"
	.string "Hvis jeg ikke formår at passe på den, vil\n"
	.string "vores BOSS irettesætte mig...$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Da jeg blev en del af TEAM AQUA, var det\n"
	.string "første, jeg skulle lære, hvordan disse\l"
	.string "teleportpaneler var forbundet.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Jeg var for optaget af at tænke på\n"
	.string "warp-panalerne...$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Jeg bliver nødt til at lære hvordan jeg kan\n"
	.string "kæmpe mere effektivt…$"



