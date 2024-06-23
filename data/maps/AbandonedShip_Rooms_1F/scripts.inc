@ TRANSLATED

AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Den slags skibe er sjældne, så jeg tager\n"
	.string "et kig rundt.\p"
	.string "Hmhm… Der ser ud til at være andre\n"
	.string "hytter…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Hvad i alverden skulle få dig til at\n"
	.string "komme herhen? Du må være nysgerrig!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Ikke bare nysgerrig, men også stærk…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "Manden ved siden af…\p"
	.string "Han siger, han bare kigger sig om, men\n"
	.string "det ved jeg ikke helt om.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Du er en sej TRÆNER! Lad mig registrere\n"
	.string "dig som et minde!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Hvad i al verden fik dig til at komme\n"
	.string "tilbage? Du må virkelig være nysgerrig!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Er du ikke for stærk?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Jeg er sikker på, at den mand er oppe på\n"
	.string "noget! Han opfører sig bare så\l"
	.string "mistænkeligt!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Åh nej! Jeg er blevet fundet! ...Hva'?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Åh, du er ikke min mor.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Jeg er i problemer med min mor, så jeg\n"
	.string "løb. Hold det hemmeligt, hvor jeg er!$"



