@ TRANSLATED

.set LOCALID_STEVEN, 1
.set LOCALID_BELDUM_BALL, 2

MossdeepCity_StevensHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_OnFrame
	.byte 0

MossdeepCity_StevensHouse_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_HideStevensNote
	end

MossdeepCity_StevensHouse_EventScript_HideStevensNote::
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, TRUE
	return

MossdeepCity_StevensHouse_OnTransition:
	call_if_eq VAR_STEVENS_HOUSE_STATE, 2, MossdeepCity_StevensHouse_EventScript_SetStevenPos
	end

MossdeepCity_StevensHouse_EventScript_SetStevenPos::
	setobjectxyperm LOCALID_STEVEN, 6, 5
	setobjectmovementtype LOCALID_STEVEN, MOVEMENT_TYPE_FACE_UP
	return

MossdeepCity_StevensHouse_OnFrame:
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_StevenGivesDive
	.2byte 0

MossdeepCity_StevensHouse_EventScript_StevenGivesDive::
	lockall
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, MossdeepCity_StevensHouse_Movement_StevenApproachPlayer
	waitmovement 0
	msgbox MossdeepCity_StevensHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
	giveitem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
	msgbox MossdeepCity_StevensHouse_Text_ExplainDive, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_STEVEN, MossdeepCity_StevensHouse_Movement_StevenReturn
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setvar VAR_STEVENS_HOUSE_STATE, 2
	releaseall
	end

MossdeepCity_StevensHouse_Movement_StevenApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MossdeepCity_StevensHouse_Movement_StevenReturn:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MossdeepCity_StevensHouse_EventScript_BeldumPokeball::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_LeaveBeldum
	goto MossdeepCity_StevensHouse_EventScript_GiveBeldum
	end

MossdeepCity_StevensHouse_EventScript_LeaveBeldum::
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_GiveBeldum::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MossdeepCity_StevensHouse_EventScript_SendBeldumParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MossdeepCity_StevensHouse_EventScript_SendBeldumPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumParty::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumPC::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	end

MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_BELDUM
	removeobject LOCALID_BELDUM_BALL
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_StevensHouse_Text_ObtainedBeldum
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	return

MossdeepCity_StevensHouse_EventScript_ReceivedBeldum::
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_RECEIVED_BELDUM
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_RockDisplay::
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
	end

MossdeepCity_StevensHouse_EventScript_Steven::
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
	end

MossdeepCity_StevensHouse_EventScript_Letter::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
	releaseall
	end

@ Unused, leftover from RS
MossdeepCity_StevensHouse_EventScript_DiveItemBall::
	finditem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	end

MossdeepCity_StevensHouse_Text_YouveEarnedHMDive:
	.string "STEVEN: {PLAYER}{KUN}... \p"
	.string "Som du kan se, der er ikke meget her, men\n"
	.string "dette er mit hjem.\p"
	.string "Tak for alt hvad du har gjort.\p"
	.string "Dette er min tak for værdsættelse. Det\n"
	.string "er den SKJULTE MASKINE DIVE.\p"
	.string "Du behøver ikke være genert--du har\n"
	.string "fortjent denne HM.$"

MossdeepCity_StevensHouse_Text_ExplainDive:
	.string "STEVEN: Mens du bruger SURF, skal du\n"
	.string "bemærke mørke vandpletter.\p"
	.string "Brug DYK, hvis du når dybt vand som\n"
	.string "dette. Du vil falde til havbunden.\p"
	.string "Når du vil komme tilbage op, brug DYK\n"
	.string "igen.\p"
	.string "På nogle steder vil det dog ikke være\n"
	.string "muligt for dig at komme op til\l"
	.string "overfladen.$"

MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis:
	.string "STEVEN: Åbenbart er der en\n"
	.string "undervandsgrotte mellem MOSSAGTIG og\l"
	.string "SODAVANDSPOLIS.\p"
	.string "Du ved, den som KAPT. STERN fandt i sin\n"
	.string "ubåd.$"

MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum:
	.string "{PLAYER} checked the POKé BALL.\p"
	.string "Den indeholdt POKéMONet BELDUM.\p"
	.string "Vil du tage POKé BALLen?$"

MossdeepCity_StevensHouse_Text_ObtainedBeldum:
	.string "{PLAYER} fik en BELDUM.$"

@ Unused
MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon:
	.string "Der er ikke plads til flere POKéMON.$"

MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas:
	.string "{PLAYER} lod POKé BALL-en ligge, hvor\n"
	.string "den var.$"

MossdeepCity_StevensHouse_Text_LetterFromSteven:
	.string "Det er et brev.\p"
	.string "… … … … … …\p"
	.string "Til {PLAYER}{KUN}…\p"
	.string "Jeg har besluttet at foretage lidt\n"
	.string "soul-searching og træne på vejen.\p"
	.string "Jeg planlægger ikke at vende hjem\n"
	.string "foreløbig.\p"
	.string "Jeg har en tjeneste at bede om.\p"
	.string "Jeg vil have dig til at tage POKé BOLDEN\n"
	.string "på skrivebordet.\p"
	.string "Indeni er der en BELDUM, min\n"
	.string "yndlings-POKéMON.\p"
	.string "Jeg regner med dig.\p"
	.string "Må vores veje krydse en dag.\p"
	.string "STEVEN STONE$"

MossdeepCity_StevensHouse_Text_CollectionOfRareRocks:
	.string "Det er en samling af sjældne sten og\n"
	.string "klipper samlet af STEVEN.$"



