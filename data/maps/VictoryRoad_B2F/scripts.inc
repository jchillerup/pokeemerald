@ TRANSLATED

VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "Jeg trænede sammen med hele min familie,\n"
	.string "alle sammen! Jeg taber ikke til nogen!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Bedre end min familie?! Er det muligt?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Jeg var bedre end alle i min familie. Jeg\n"
	.string "har aldrig tabt før…\p"
	.string "Jeg har mistet min tillid… Måske vil jeg\n"
	.string "tage hjem…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "Jeg havde hørt, at der var en sej  lille\n"
	.string "knægt heromkring. Mener de dig?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "Den lille reje er sej!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "De rygter, jeg hørte, om den seje lille\n"
	.string "knægt er fra PETALBURG CITY.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Du må være lidt træt.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Ingen tegn på træthed overhovedet!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "SEJR VEJ og POKéMON LIGAEN er lange og\n"
	.string "udmattende udfordringer.\p"
	.string "Pas på træthed!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Du skal ikke blive selvtilfreds bare\n"
	.string "fordi du har mange GYM BADGES.\p"
	.string "Der vil altid være nogen, der er bedre\n"
	.string "end dig!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Du er bedre end mig!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Se på dine indsamlede MÆRKER og husk\n"
	.string "TRÆNERNE, du har stået overfor.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Jeg er nået så langt, men spændingen\n"
	.string "giver mig forfærdelige mavesmerter…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Åh… Det gør ondt…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Jeg kan ikke lade være med at blive\n"
	.string "spændt, når jeg nærmer mig POKéMON-\l"
	.string "LIGAEN. Jeg prøver virkelig at være\l"
	.string "rolig.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "De bedste af de bedste samles i denne\n"
	.string "grotte.\p"
	.string "Hvordan synes du om den?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Slet ikke forskrækket!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Du har virkelig modet! Det kan jeg lide!\n"
	.string "Bliv ved med det!$"



