@ TRANSLATED

FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Ingen tror på mig, men jeg så denne\n"
	.string "kæmpestore POKéMON på himlen.\p"
	.string "Den så ud til at vride sig, mens den fløj\n"
	.string "mod RUTE 131.\p"
	.string "Forresten… Snif… Øh… Du, øh… du lugter\n"
	.string "af brændt.\p"
	.string "Var du i en vulkan eller noget?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Jeg vil gerne gå til POKéMON GYM, men\n"
	.string "noget blokerer vejen.\p"
	.string "Efter alt besværet jeg gik igennem med\n"
	.string "træningen på ROUTE 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Jeg har min stolthed og glæde POKéMON\n"
	.string "med mig. Denne gang vil jeg slå WINONA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Jorden opsuger regnvand, og træer\n"
	.string "vokser ved at drikke det vand…\p"
	.string "Vores FORTREE CITY eksisterer, fordi\n"
	.string "der er både vand og jord.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "BYEN består af hjem bygget på træer.\p"
	.string "Måske på grund af den livsstil er alle\n"
	.string "sunde og livlige.\p"
	.string "Selv jeg--jeg føler, som om jeg er\n"
	.string "blevet tredive år yngre.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "At bo øverst i træerne er okay.\p"
	.string "Men nogle gange kommer FEJL POKéMON\n"
	.string "ind gennem vinduerne. Det kan være\l"
	.string "virkelig skræmmende.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Der er POKéMON, der udvikler sig, når du\n"
	.string "handler dem! Det har jeg hørt.$"

FortreeCity_Text_SomethingUnseeable:
.string "Noget usynligt er i vejen.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Noget usynligt er i vejen.\p"
	.string "Vil du bruge DEVON-SCOPE?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} brugte DEVON-TELESKOPET.\p"
	.string "En usynlig POKéMON blev fuldstændig\n"
	.string "synlig!\p"
	.string "Den forskrækkede POKéMON flygtede!$"

FortreeCity_Text_CitySign:
	.string "FORTREE BY “Trækronernes by, der leger\n"
	.string "med naturen.”$"

FortreeCity_Text_GymSign:
	.string "FORTREE CITY POKéMON GYM LEDER:\n"
	.string "WINONA\p"
	.string "“Fuglebrugeren der flyver ud i\n"
	.string "verdenen.”$"



