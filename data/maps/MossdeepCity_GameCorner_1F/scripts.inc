@ TRANSLATED

MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end

@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Da jeg var ung, rejste jeg verden rundt\n"
	.string "som en POKéMON TRÆNER.\p"
	.string "Nu hvor jeg er blevet en gammel gøgler,\n"
	.string "er min eneste underholdning at se unge\l"
	.string "TRÆNERE kæmpe.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
.string "Døren ser ud til at være låst.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "EN TRÆNER ved navn {STR_VAR_1} er\n"
	.string "på besøg i mit hjem.\p"
	.string "Vil du udfordre {STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Vil du ikke kæmpe? Jeg er skuffet at jeg\n"
	.string "ikke kan se dig kæmpe...$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Åh, godt, godt!\p"
	.string "Men mit hus er ikke særlig solid.\p"
	.string "Kunne jeg bede dig om at holde det nede\n"
	.string "til en 3-mod-3 kamp?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Inden I to kæmper, bør I gemme jeres\n"
	.string "fremskridt.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "Jeg håber at se en god kamp!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Så stod vi pludselig der.\p"
	.string "Det var en fantastisk kamp, hvor ingen\n"
	.string "af parterne gav en tomme!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "Det var suverænt!\p"
	.string "Det var ligesom at se mig selv i min\n"
	.string "ungdom igen!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Åh, ØV for dig!\p"
	.string "Men det var en god kamp. Jeg håber, du\n"
	.string "vinder næste gang.$"



