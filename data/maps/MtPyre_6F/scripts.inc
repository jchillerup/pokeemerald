@ TRANSLATED

MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Når jeg er her…\n"
	.string "En nysgerrig kraft strømmer ind i mig…$"

MtPyre_6F_Text_ValerieDefeat:
.string "Kraften ebber væk...$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Måske kommer kraften fra ånderne\n"
	.string "af POKéMON, der sover uroligt her…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Haha... Jeg tabte kampen, men...\n"
	.string "Jeg har denne lille evne... \p"
	.string "Uden nogensinde at røre ved\n"
	.string "din POKéNAV... Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Bag dig…\n"
	.string "Hvad er det…$"

MtPyre_6F_Text_ValerieRematchDefeat:
.string "Noget forsvandt…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "De POKéMON, der hviler her…\n"
	.string "Nogle gange leger de…$"

MtPyre_6F_Text_CedricIntro:
	.string "Har du mistet din retning?\n"
	.string "Frygt ej, for jeg er her!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Var du ikke lost?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Jeg havde en fornemmelse af, at en tabt TRÆNER\n"
	.string "ville være panikslagen og nem at slå.\p"
	.string "Det er uretfærdigt, og jeg vil ikke prøve det igen...$"



