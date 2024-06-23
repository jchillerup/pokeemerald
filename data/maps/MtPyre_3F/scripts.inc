@ TRANSLATED

MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "Den rige atmosfære på bjerget har\n"
	.string "styrket min psykiske kraft!\p"
	.string "Bare et barn som dig… Du drømmer om at\n"
	.string "vinde?$"

MtPyre_3F_Text_WilliamDefeat:
.string "Jeg drukner i selvmedlidenhed…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Mine psykiske evner er helt sikkert\n"
	.string "vokset flere gange, men…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Dette er ikke et sted for børn, især\n"
	.string "ikke dig!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Jeg tabte helt rent…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Det betyder, at min træning stadig ikke\n"
	.string "er nok…\p"
	.string "Jeg bliver nødt til at blive ved med at\n"
	.string "arbejde mod toppen…\p"
	.string "Kom så, mig!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Hvorfor er du kommet her?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Det var fantastisk! Du er en meget\n"
	.string "speciel TRÆNER.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "POKéMON ikke længere i denne verden.\n"
	.string "POKéMON, som er hos dig nu.\p"
	.string "Og de POKéMON, som du vil møde i\n"
	.string "fremtiden...\p"
	.string "De skal alle værdsættes lige meget. Husk\n"
	.string "venligst det.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Jeg vil gerne se dine POKéMON når de\n"
	.string "bliver lidt ældre... \p"
	.string "Vær sød at vise mig din POKéNAV.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Åh, det er dig…\p"
	.string "Er du kommet for at vise mig din  voksne\n"
	.string "POKéMON?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Hvor fantastisk! Du er en speciel\n"
	.string "person.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "POKéMON ikke længere af denne verden.\n"
	.string "POKéMON som er med dig nu.\p"
	.string "Og de POKéMON, som du vil møde i\n"
	.string "fremtiden…\p"
	.string "De skal alle være lige værdsatte. Jeg\n"
	.string "kan se, at du har husket det.$"



