@ TRANSLATED

MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Hvad har jeg gjort for at fortjene\n"
	.string "denne vagt tjeneste?\p"
	.string "Mit venstre øre brænder op!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Jeg får hedeslag...$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Synes du ikke, det er underligt, at vi\n"
	.string "går rundt med hætter i denne\l"
	.string "magmafyldte vulkan?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Vi er med for at hjælpe vores leder med\n"
	.string "at opnå hans fantastiske vision.\p"
	.string "Jeg er ligeglad med om du er fra HOLD\n"
	.string "AQUA eller bare et tilfældigt barn, der\l"
	.string "går forbi.\p"
	.string "Ingen kommer og blander sig i vores\n"
	.string "sager og slipper godt fra det!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Åh, nej!  Du er slet ikke til at stole på!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Lyt til mig. HOLD MAGMA har ret!\p"
	.string "Lyt ikke til HOLD AQUA. Tro ikke på\n"
	.string "deres løgne!$"



