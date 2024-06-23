@ TRANSLATED

PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
.string "Jeg kan ikke se MIRAGE ISLAND i dag…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Åh! Åh min! Jeg kan se MIRAGE ISLAND i\n"
	.string "dag!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "MIRAGE ISLAND…\p"
	.string "Det skal blive synligt og usynligt\n"
	.string "afhængigt af vejrforholdene, der\l"
	.string "fremkalder mirager Er det virkelig\l"
	.string "synligt eller usynligt?$"



