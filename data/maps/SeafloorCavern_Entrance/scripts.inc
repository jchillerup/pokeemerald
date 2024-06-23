@ TRANSLATED

.set LOCALID_GRUNT, 1

SeafloorCavern_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_OnResume
	.byte 0

SeafloorCavern_Entrance_OnResume:
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	end

SeafloorCavern_Entrance_EventScript_Grunt::
	lockall
	goto_if_eq VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1, SeafloorCavern_Entrance_EventScript_GruntSpeechShort
	waitse
	playse SE_PIN
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_Delay48
	waitmovement 0
	delay 20
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	delay 30
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	copyobjectxytoperm LOCALID_GRUNT
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntSpeechShort::
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep:
	.string "Hey! Jeg husker dit ansigt!\p"
	.string "Hvis du er her, må det betyde, at du igen\n"
	.string "er ude på ballade!\p"
	.string "En bølle som dig, tror du virkelig, du kan\n"
	.string "klare TEAM AQUA?\p"
	.string "Jeg vil sige, du er omkring en billion år\n"
	.string "for tidlig!\p"
	.string "Du passer perfekt til TEAM MAGMA!\p"
	.string "Nu vi er ved TEAM MAGMA, hørte jeg, at de\n"
	.string "var set i nærheden af MOSSDEEP.\p"
	.string "Den flok skurke, de ser virkelig ikke\n"
	.string "gode ud ved havet!$"

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort:
	.string "En lille ballademager som dig, tror du\n"
	.string "virkelig, at du kan tage kampen op med\l"
	.string "HOLD AQUA?\p"
	.string "Jeg vil sige, du er et par billioner år\n"
	.string "for tidlig!\p"
	.string "Du passer perfekt til HOLD MAGMA!\p"
	.string "Når vi taler om HOLD MAGMA, så hørte jeg,\n"
	.string "at de blev set i nærheden af MOSSDEEP.\p"
	.string "Den flok tossehoveder, de ser godt nok\n"
	.string "underlige ud ved havet!$"



