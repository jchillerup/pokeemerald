@ TRANSLATED

AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: Mens vi ledte efter skatte, fandt vi en\n"
	.string "TRÆNER!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "Vi kunne ikke vinde, selvom vi arbejdede\n"
	.string "sammen...$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "Vi kan ikke finde nogen skatte... Mon nogen\n"
	.string "har fået dem allerede?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Du har ikke engang to POKéMON. Du kan\n"
	.string "ikke forvente at slå os på den måde.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: Åh? Vi ledte efter skatte.\p"
	.string "Men vi fandt en TRÆNER i stedet!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
.string "KIRA: Åh, så stærk!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: Hvor mon skattene er?\p"
	.string "Jeg har allerede besluttet hvad jeg vil\n"
	.string "købe, når vi finder skattene!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: Åh, du har ikke to POKéMON? Vi må slås\n"
	.string "en anden gang!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: Åh, du gør mig så vred! Jeg vil melde dig\n"
	.string "til for det!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "Vi har ledt efter skatte i lang tid nu.\p"
	.string "Vores POKéMON er også blevet stærkere. Vi\n"
	.string "vil vise dig det, okay?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: Du er stærk, som altid!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "Vi kan ikke finde nogen skatte, vi taber i\n"
	.string "POKéMON…\p"
	.string "Jeg vil gerne hjem… Men hvis jeg siger det,\n"
	.string "bliver hun skidesur på mig…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "Du har ikke engang to POKéMON. Du kan ikke\n"
	.string "forvente at slå os på den måde.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: Åh? Vi mødes igen!\p"
	.string "Præcis som os har du stadig ikke givet op med\n"
	.string "at lede efter skatte, har du?\p"
	.string "Vil du gøre det så taberen må opgive at lede?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: Åh, vi tabte igen...$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: Vi går ikke, før vi har trænet vores\n"
	.string "POKéMON lidt mere og har fundet skattene\l"
	.string "her!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: Åh, har du ikke to POKéMON? Vi må slås\n"
	.string "en anden gang!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Jeg er ikke god til at svømme, men jeg er god\n"
	.string "til kampe!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Ups. Det gik ikke så godt.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "At gå rundt barfodet på dette skib er lidt\n"
	.string "ulækkert.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Styrke og medfølelse… Det er en TRÆNERS\n"
	.string "skatte!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Åh, der er noget ved dig, der funkler.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "I en hytte et sted om bord, så jeg noget\n"
	.string "glimte.$"



