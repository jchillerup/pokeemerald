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
	.string "Hvad har jeg gjort for at fortjene denne vagt\n"
	.string "tjeneste?\p"
	.string "Mit venstre øre brænder op!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Jeg får hedeslag...\p$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Synes du ikke, det er underligt, at vi går\n"
	.string "rundt med hætter i denne magmafyldte vulkan?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Vi er med for at hjælpe vores leder\n"
	.string "med at opnå hans fantastiske vision.\p"
	.string "Jeg er ligeglad med om du er fra HOLD AQUA\n"
	.string "eller bare et tilfældigt barn, der går forbi.\p"
	.string "Ingen kommer og blander sig i vores\n"
	.string "sager og slipper godt fra det!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Åh, nej! \n" 
	.string "Du er slet ikke til at stole på!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Lyt til mig.\n"
	.string "HOLD MAGMA har ret!\p"
	.string "Lyt ikke til HOLD AQUA.\n"
	.string "Tro ikke på deres løgne!$"



