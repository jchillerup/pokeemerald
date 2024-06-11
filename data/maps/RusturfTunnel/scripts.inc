@ TRANSLATED

.equ LOCALID_WANDAS_BF, 1
.set LOCALID_BRINEY, 5
.set LOCALID_GRUNT, 6
.set LOCALID_PEEKO, 7
.equ LOCALID_WANDA, 10

RusturfTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
	.byte 0

RusturfTunnel_OnFrame:
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_ClearTunnelScene
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_ClearTunnelScene
	.2byte 0

RusturfTunnel_OnTransition:
	call_if_eq VAR_RUSTURF_TUNNEL_STATE, 2, RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
	end

RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos::
	setobjectxyperm LOCALID_PEEKO, 13, 4
	setobjectxyperm LOCALID_GRUNT, 13, 5
	return

RusturfTunnel_EventScript_Wanda::
	lock
	faceplayer
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_WandasBoyfriend::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
	setflag FLAG_TEMP_1
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_AlreadySpokenTo::
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_ClearTunnelScene::
	lockall
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_FaceWandasBoyfriend1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_FaceWandasBoyfriend2
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_FaceWandasBoyfriend3
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_BoyfriendApproachWanda1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_BoyfriendApproachWanda2
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_BoyfriendApproachWanda3
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_WandaAndBoyfriendExit1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandaAndBoyfriendExit
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandaAndBoyfriendExit
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
	releaseall
	end

RusturfTunnel_EventScript_BoyfriendApproachWanda1::
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda2::
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda3::
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend1::
	applymovement LOCALID_WANDAS_BF, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend2::
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend3::
	return

RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer::
	closemessage
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit1::
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit1
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit::
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
	waitmovement 0
	return

RusturfTunnel_EventScript_WandasBoyfriendNotice::
	playse SE_PIN
	applymovement LOCALID_WANDAS_BF, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WANDAS_BF, Common_Movement_Delay48
	waitmovement 0
	return

RusturfTunnel_Movement_WandaExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandaExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_PlayerWatchWandaExit:
	delay_8
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused1:
	walk_left
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused2:
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused3:
	walk_up
	walk_in_place_faster_down
	delay_8
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend1:
	walk_left
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend:
	walk_right
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_BoyfriendFaceRight:
	walk_up
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendApproachPlayer:
	walk_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda1:
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_fast_up
	walk_fast_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_fast_right
	walk_in_place_faster_up
	step_end

RusturfTunnel_EventScript_TunnelBlockagePos1::
	setvar VAR_TEMP_1, 1
	end

RusturfTunnel_EventScript_TunnelBlockagePos2::
	setvar VAR_TEMP_1, 2
	end

RusturfTunnel_EventScript_TunnelBlockagePos3::
	setvar VAR_TEMP_1, 3
	end

RusturfTunnel_EventScript_AquaGruntBackUp::
	lockall
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
	waitmovement 0
	copyobjectxytoperm LOCALID_GRUNT
	copyobjectxytoperm LOCALID_PEEKO
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
	releaseall
	end

RusturfTunnel_Movement_GruntAndPeekoBackUp:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

RusturfTunnel_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RusturfTunnel_EventScript_Grunt::
	lock
	faceplayer
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
	giveitem ITEM_DEVON_GOODS
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntEscape
	waitmovement 0
	removeobject LOCALID_GRUNT
	delay 50
	addobject LOCALID_BRINEY
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko2
	waitmovement 0
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
	applymovement LOCALID_BRINEY, Common_Movement_FacePlayer
	waitmovement 0
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
	waitmessage
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyExit
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_PeekoExit
	waitmovement 0
	removeobject LOCALID_BRINEY
	removeobject LOCALID_PEEKO
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_RUSTBORO_CITY_STATE, 4
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	release
	end

RusturfTunnel_Movement_PushPlayerAsideForGrunt:
	face_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_PlayerMoveAsideForBriney:
	walk_down
	walk_in_place_faster_up
	step_end

RusturfTunnel_Movement_GruntEscape:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RusturfTunnel_Movement_BrineyExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_Movement_PlayerWatchBrineyExit:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko2:
	delay_16
	walk_right
	step_end

RusturfTunnel_Movement_PeekoExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

RusturfTunnel_Text_ComeAndGetSome:
	.string "Hvad, kommer du?\n"
	.string "Kom og få noget så!$"

RusturfTunnel_Text_Peeko:
	.string "PEEKO: Pii pihyoh!$" 

RusturfTunnel_Text_GruntIntro:
	.string "Åh, kejle det hele!\p"
	.string "Den gidsel POKéMON viste sig at\n"
	.string "være ubrugelig!\p"
	.string "Og tænk, at jeg slap væk…\n"
	.string "I denne tunnel til ingenting!\p"
	.string "Hey! Dig der!\n"
	.string "Så vil du i kamp med mig?$"

RusturfTunnel_Text_GruntDefeat:
	.string "Åhh nej! Min kriminelle karriere nåede\n"
	.string "et dødt punkt!$"

RusturfTunnel_Text_GruntTakePackage:
	.string "Det her er bare helt forkert…\p"
	.string "BOSS'en fortalte mig, at det her ville\n"
	.string "være en let og lækker sag.\p"
	.string "Alt jeg skulle gøre, var at stjæle en\n"
	.string "pakke fra DEVON.\p"
	.string "Tsk!\n"
	.string "Hvis du vil have den så meget tilbage,\n"
	.string "så tag den!$"

RusturfTunnel_Text_PeekoGladToSeeYouSafe:
	.string "PEEKO!\n"
	.string "Er jeg glad for at se, at du er sikker!$"

RusturfTunnel_Text_ThankYouLetsGoHomePeeko:
	.string "PEEKO skylder dig sit liv!\p"
	.string "De kalder mig HR. BRINEY.\n"
	.string "Og, du er?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Åh, så du er {PLAYER}{KUN}!\n"
	.string "Jeg takker dig dybt!\p"
	.string "Hvis der er noget, der bekymrer dig,\n"
	.string "så tøv ikke med at fortælle mig!\p"
	.string "Du kan som regel finde mig i mit hus\n"
	.string "ved havet, tæt på PETALBURG WOODS.\p"
	.string "Kom, PEEKO, vi bør tage hjemad.\p"
	.string "PEEKO: Pihyoh!$"

RusturfTunnel_Text_WhyCantTheyKeepDigging:
	.string "Hvorfor kan de ikke blive ved \npå at grave?\p"
	.string "Er undergrunden for hård?\p"
	.string "Min elskede venter på mig i \nVERDANTURF TOWN lige herovre…\p"
	.string "Hvis RUSTBORO og VERDANTURF blev\n"
	.string "forbundet af denne tunnel, kunne \njeg besøge hende hver dag…\p"
	.string "Men dette…\n"
	.string "Hvad skal jeg gøre?$"

RusturfTunnel_Text_ToGetToVerdanturf:
	.string "For at komme fra RUSTBORO til VERDANTURF,\n"
	.string "skal du tage til DEWFORD, og derefter\n"
	.string "passere gennem SLATEPORT og MAUVILLE...$"

RusturfTunnel_Text_YouShatteredBoulderTakeHM:
	.string "Wow! Du knuste den store sten\n"
	.string "der blokerede vejen.\p"
	.string "For at vise dig, hvor meget jeg\n"
	.string "værdsætter det, får du denne HM.$"

RusturfTunnel_Text_ExplainStrength:
	.string "Denne HM indeholder STYRKE.\p"
	.string "Hvis en muskuløs POKéMON lærte det,\n"
	.string "ville den kunne flytte selv store\n"
	.string "sten.$"

RusturfTunnel_Text_WandaReunion:
	.string "WANDA!\n"
	.string "Nu kan jeg se dig når som helst!\p"
	.string "WANDA: Det er... vidunderligt.\p"
	.string "Vær venlig at hvile dig lidt hjemme hos mig.$"

RusturfTunnel_Text_BoyfriendOnOtherSideOfRock:
	.string "På den anden side af denne sten…\n"
	.string "Min kæreste er der.\p"
	.string "Han… Han graver ikke bare tunnelen\n"
	.string "for at komme og se mig.\p"
	.string "Han arbejder sine hænder rå og ru\n"
	.string "for alles skyld.$"

RusturfTunnel_Text_MikeIntro:
	.string "Hvad kalder man en vild mand oppe i\n"
	.string "bjergene? En bjergmand, ikke sandt?\p"
	.string "Så hvorfor kalder de ikke en POKéMON\n"
	.string "i bjergene for en bjerg POKéMON?$"

RusturfTunnel_Text_MikeDefeat:
	.string "Mine POKéMON…\n"
	.string "Er løbet tør for energi…$"

RusturfTunnel_Text_MikePostBattle:
	.string "De stoppede udviklingen her for at\n"
	.string "beskytte POKéMON, ikke sandt?\p"
	.string "Det er en feel-good historie!$"



