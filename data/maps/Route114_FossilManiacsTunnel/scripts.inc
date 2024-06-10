@ TRANSLATED

.set LOCALID_FOSSIL_MANIAC, 1

Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Jeg er Fossilmennesket…\n"
	.string "Jeg er en rar fyr, der elsker FOSILER…\p"
	.string "Vil du have en FOSIL?\p"
	.string "Men FOSILERNE i disse egne tilhører\n"
	.string "mig… Ingen til dig…\p"
	.string "Hvis du ikke kan klare dig uden en\n"
	.string "FOSIL, så kig i en ørken, hvor der er\l"
	.string "store sten og sand, der kan skjule\l"
	.string "FOSILER…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Du fandt en FOSSIL, gjorde du ikke?\n"
	.string "Det er så dejligt... Det er så drømmende...\p"
	.string "Hvad vil du gøre med den\n"
	.string "FOSSIL?\p"
	.string "Fra hvad jeg har hørt, forsker DEVON i\n"
	.string "at genoplive POKéMON fra\l"
	.string "FOSSILER... \p"
	.string "Jeg elsker mine FOSSILER, så jeg ville\n"
	.string "aldrig gøre noget sådant...$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "Fossiler er så... Vidunderlige...\n"
	.string "Det er så drømmende...$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Åh…\n"
	.string "Det er ikke sikkert den vej…\p"
	.string "Jeg gravede, ser du…\n"
	.string "Da hele væggen kollapsede…\p"
	.string "Jeg tror, der er en kæmpe hule\n"
	.string "nedenunder nu…\p"
	.string "Men jeg har ladet den være, fordi jeg\n"
	.string "tror ikke, der er nogen FOSILER der…$"



