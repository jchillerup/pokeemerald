@ TRANSLATED

MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Mindet om min skønne SKITTY… Tårerne\n"
	.string "strømmer, når jeg tænker på det.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Av, av,... Der er huller igulvet her og der.\p"
	.string "Jeg lagde ikke mærke til dem og faldt ned fra\n"
	.string "etage over.$"

MtPyre_2F_Text_MarkIntro:
	.string "Hej! Leder du efter POKéMON? Du kom efter\n"
	.string "mig! Du er uforskammet!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Åååh! Undskyld, tilgiv mig, vær sød!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Folk kommer ikke her så tit, så jeg troede,\n"
	.string "der ville være sjældne POKéMON.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUKE: Vi er her på en udfordring.\p"
	.string "Heheh, hvis jeg viser hende, hvor sej jeg er,\n"
	.string "vil hun falde for mig. Jeg ved det!\p"
	.string "Jeg ved det! Jeg vil slå dig og vise hende,\n"
	.string "hvor sej jeg er!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUKE: Upsadaisy!$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUKE: Nå, vi tabte, men det er okay! Jeg er\n"
	.string "lige her ved din side.\p"
	.string "Vi klarer denne udfordring sammen!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUKE: Hvis du vil udfordre mig, så tag flere\n"
	.string "POKéMON med.\p"
	.string "Hvis ikke, kan jeg ikke vise min pige, hvor sej\n"
	.string "jeg er!$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ: Jeg kom her på en udfordring med min\n"
	.string "kæreste.\p"
	.string "Det er virkelig skræmmende, men jeg er\n"
	.string "sammen med min kæreste. Det er okay.\p"
	.string "Jeg ved det! Jeg vil få min kæreste til at se\n"
	.string "sej ud ved at slå dig!$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ: Åh nej! Jeg er bange!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ: Vi er kærlige og kælen, så vi bekymrer os\n"
	.string "ikke, hvis vi taber!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ: Hvis du vil udfordre os, skal du have\n"
	.string "mindst to POKéMON med.\p"
	.string "Min kæreste er stærk. Bare en POKéMON er\n"
	.string "slet ikke nok.$"

MtPyre_2F_Text_LeahIntro:
	.string "Du er et ukendt syn… Forsvind før der sker\n"
	.string "dig noget!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm… Du er sej.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Vores familie har været TRÆNERE her siden\n"
	.string "min oldemors tid…\p"
	.string "Det er min pligt at beskytte dette bjerg…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Åh nej! Jeg er skræmt!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Neeeej! Jeg har mistet fatningen!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Jeg bliver skræmt hver gang jeg ser noget\n"
	.string "bevæge sig…\p"
	.string "Jeg skulle ikke have taget herhen for at\n"
	.string "træne…$"



