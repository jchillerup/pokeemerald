@ TRANSLATED

AbandonedShip_Corridors_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Corridors_B1F_OnLoad
	.byte 0

AbandonedShip_Corridors_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 5, 4
	end

AbandonedShip_Corridors_B1F_OnLoad:
	call_if_unset FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom
	call_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	end

AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_TuberM::
	msgbox AbandonedShip_Corridors_B1F_Text_YayItsAShip, MSGBOX_NPC
	end

AbandonedShip_Corridors_B1F_EventScript_StorageRoomDoor::
	lockall
	goto_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked
	checkitem ITEM_STORAGE_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked
	msgbox AbandonedShip_Corridors_B1F_Text_InsertedStorageKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_STORAGE_KEY
	setflag FLAG_USED_STORAGE_KEY
	call AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked::
	msgbox AbandonedShip_Corridors_B1F_Text_DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked::
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_Duncan::
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_DuncanIntro, AbandonedShip_Corridors_B1F_Text_DuncanDefeat
	msgbox AbandonedShip_Corridors_B1F_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_B1F_Text_DuncanIntro:
	.string "Når vi sejler ud på havet, tager vi SØMÆND\n"
	.string "altid vores POKéMON med.\p"
	.string "Hvad med en hurtig kamp?$"

AbandonedShip_Corridors_B1F_Text_DuncanDefeat:
.string "Ups, jeg er sunket!$"

AbandonedShip_Corridors_B1F_Text_DuncanPostBattle:
	.string "Skibets bund er sunket ned i\n"
	.string "dybet.\p"
	.string "Hvis en POKéMON vidste, hvordan man\n"
	.string "gik under vand, kunne vi komme\n"
	.string "videre…$"

AbandonedShip_Corridors_B1F_Text_YayItsAShip:
	.string "Jubii!\n"
	.string "Det er et skib!$"

AbandonedShip_Corridors_B1F_Text_DoorIsLocked:
.string "Døren er låst.\p"
.string "“OPBEVARING” er malet på døren.$"

AbandonedShip_Corridors_B1F_Text_InsertedStorageKey:
	.string "{PLAYER} satte nøglen i og drejede om.\n"
	.string "OPBEVARINGSNØGLEN.\p"
	.string "Den indsatte nøgle sad fast,\n"
	.string "men døren åbnede.$"

AbandonedShip_Text_TheDoorIsOpen:
.string "Døren er åben.$"



