@ TRANSLATED

MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "Her træner vi DRAGE-brugere. Selveste\n"
	.string "MESTEREN kommer endda på besøg. Kan du\l"
	.string "se, hvor specielt det er her?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Åh! Jeg havde ikke forventet, at du var\n"
	.string "så stærk!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "Vejen frem forbliver lang og barsk.\p"
	.string "Hvornår vil min POKéMON og jeg blive de\n"
	.string "bedste?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Jeg vil gerne vide mere om din kraft. Lad\n"
	.string "mig registrere dig i min POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Siden vi mødtes, har vi trænet hårdt med\n"
	.string "vores øjne rettet mod førstepladsen.\p"
	.string "Hjælp os med at se, hvor meget stærkere\n"
	.string "vi er blevet!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Åh! Jeg forventede ikke, at du var så\n"
	.string "stærk!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Du har tydeligvis holdt dig opdateret\n"
	.string "med din POKéMON-træning.\p"
	.string "Så længe du forbliver stærk, kan jeg\n"
	.string "også blive stærkere!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN: Vi har altid kæmpet med POKéMON\n"
	.string "sammen som et par.\p"
	.string "Vi har tillid til os selv.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN: Åh, nej. Vi har tabt, kære kone.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN: Vi har været gift i halvtreds år.\p"
	.string "Nu da jeg tænker over det, har jeg endnu\n"
	.string "ikke slået min kære kone i en kamp.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN: Nåh, nåh, en ung TRÆNER!\p"
	.string "Vil du kæmpe med os? Hvis du gør, så er\n"
	.string "du nødt til at komme tilbage med flere\l"
	.string "POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN: Ung TRÆNER, hvis muligheden\n"
	.string "opstår, vil du kæmpe med os igen?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY: Vi har været gift i halvtreds år.\p"
	.string "Båndet vi deler som et par kan aldrig\n"
	.string "brydes.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY: Åh, nej. Vi har tabt, min kære mand.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY: Halvtreds års ægteskab…\p"
	.string "Hvis vi nogensinde skændtes, løste vi\n"
	.string "det med en POKéMON-kamp…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY: Nåh, nåh, er du ikke en ung TRÆNER?\p"
	.string "Hvis du har lyst til at kæmpe med os,\n"
	.string "skal du komme tilbage med flere POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN: Vi har altid kæmpet med POKéMON\n"
	.string "sammen som et dynamisk duo. Vi har tillid\l"
	.string "til os selv.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "John: Åh, nej. Vi har tabt, kære kone.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN: Gift i halvtreds år…\p"
	.string "Når jeg tænker tilbage, kære kone og\n"
	.string "jeg, kæmpede vi dag ind og dag ud…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN: Nå, nå, en ung TRÆNER!\p"
	.string "Vil du kæmpe med os? Hvis du vil, skal du\n"
	.string "vende tilbage med flere POKéMON.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY: Vi har været gift i halvtreds år.\p"
	.string "Vi har støttet hinanden hele den tid. Vi\n"
	.string "har gjort os stærke.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY: Åh, nej. Vi har tabt, min kære mand.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY: Halvtreds års ægteskab... Der er\n"
	.string "sket mange ting.\p"
	.string "Jeg håber, at vi vil fortsætte med at\n"
	.string "skabe glade minder sammen.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY: Nå, nå, er du ikke en ung TRÆNER?\p"
	.string "Hvis du har lyst til at kæmpe med os,\n"
	.string "bliver du nødt til at komme tilbage med\l"
	.string "flere POKéMON.$"



