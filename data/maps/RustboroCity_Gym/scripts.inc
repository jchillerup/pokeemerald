@ TRANSLATED

RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Hej, hvordan går det?\p"
	.string "Lyt, min ven!\n"
	.string "Vil du gerne blive MESTEREN?\p"
	.string "Jeg er ikke EN TRÆNER, det er ikke mig,\n"
	.string "men jeg kan helt sikkert give dig\n"
	.string "vindende råd.\p"
	.string "Så er det afgjort! Vi går efter\n"
	.string "POKéMON-MESTERSKABET sammen!\p"
	.string "Det er din opgave som EN TRÆNER at\n"
	.string "samle GYMNASTIKMÆRKER, ikke sandt?\p"
	.string "Men GYMLEDERE er ikke nemme!\p"
	.string "Og der kommer jeg ind i billedet!\n"
	.string "Jeg er her for at give ekspert-råd!\p"
	.string "ROXANNE, GYMLEDEREN, bruger\n"
	.string "ROCK-type POKéMON.\p"
	.string "ROCK-typen er meget holdbar, men\n"
	.string "den kan ikke tåle VAND-type og\n"
	.string "GRÆS-type angreb.\p"
	.string "Kom og se mig efterfølgende,\n"
	.string "hvis du slår GYMLEDEREN.\p"
	.string "Nå, gå efter det!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa! Sikke en fantastisk sejr!\n"
	.string "Mit heppende har nok virket!\p"
	.string "Fantastisk!\n"
	.string "Tjek din TRÆNERKORT.\p"
	.string "STENMÆRKET, du fik, burde være\n"
	.string "korrekt optaget på det.\p"
	.string "Med andre ord…\p"
	.string "Du har besteget det første trin på\n"
	.string "vejen mod MESTERSKABET!\p"
	.string "Det må føles fantastisk!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Tag ikke os GYM TRAINERS let!\n"
	.string "Jeg vil vise dig, hvorfor vi er bedre!$"

RustboroCity_Gym_Text_JoshDefeat:
.string "Du var for god til mig...$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Du har ikke set noget af ROCK\n"
	.string "typens skræmmende kraft!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Hvis du ikke kan slå mig, har du ingen\n"
	.string "mulighed mod ROXANNE!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wow! Du har potentiale!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE er stærkere end mig med\n"
	.string "flere gange.\p"
	.string "Du bør være på vagt!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Vi er måske midt i byen,\n"
	.string "men så hvad?\p"
	.string "Mine KLIPPE POKéMON skal bruge plads\n"
	.string "til at hærge!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Åh ja, åh ja!\n"
	.string "Vores udfordrer er en sej kunde!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Jeg må nok give vores LEDER en stor\n"
	.string "kredit. Det krævede intelligens og\n"
	.string "sund fornuft at vælge STEN-typen i en\n"
	.string "så ung alder.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Hej, jeg er ROXANNE, lederen af\n"
	.string "RUSTRUTE-POKéMON GYM.\p"
	.string "Jeg blev GYM-leder for at kunne\n"
	.string "anvende det, jeg lærte på POKéMON-\n"
	.string "TRÆNERSKOLEN i kamp.\p"
	.string "Kan du venligst demonstrere, hvordan du\n"
	.string "kæmper, og med hvilke POKéMON?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Så...\n"
	.string "Jeg tabte...\p"
	.string "Det ser ud til, at jeg stadig har\n"
	.string "meget mere at lære... \p"
	.string "Jeg forstår.\p"
	.string "POKéMON LIGAENS regler siger, at\n"
	.string "TOGETHINGs skal gives dette\l"
	.string "hvis de besejrer en GYM LEADER.\p"
	.string "Vær venlig at acceptere det officielle\n"
	.string "POKéMON LIGA STENBAGE.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} modtog STENBADGEN\n"
	.string "fra ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "STENBADGEN forstærker ANGREBSKRAFTEN\n"
	.string "hos dine POKéMON.\p"
	.string "Den gør det også muligt for dem at bruge\n"
	.string "HM-teknikken KLIP uden for kamp.\p"
	.string "Tag også denne med dig.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Den TEKNISKE MASKINE, TM39,\n"
	.string "indeholder STENGRAV.\p"
	.string "Den forårsager skade ved at kaste\n"
	.string "sten, og den sænker også HASTIGHED.\p"
	.string "Hvis du bruger en TM, lærer en\n"
	.string "POKéMON øjeblikkeligt angrebet.\p"
	.string "Husk, en TM kan kun bruges én gang,\n"
	.string "så tænk dig om, før du bruger den.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Fordi du er så stærk, bør du\n"
	.string "udfordre andre GYM LEDERE.\p"
	.string "Ved at kæmpe mod mange TRÆNERE, bør du\n"
	.string "lære mange ting.$"

RustboroCity_Gym_Text_GymStatue:
.string "RUSTBORO CITY POKéMON GYM$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "RUSTBORO CITY POKéMON GYM\p"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Bip!\p"
	.string "ROXANNE: Åh, hej, {PLAYER}?\n"
	.string "Det er ROXANNE fra RUSTBORO BY.\p"
	.string "Jeg hørte fra BRAWLY, at du bevæger\l"
	.string "dig op gennem rækkerne af TRÆNERE\n"
	.string "med en utrolig fart.\p"
	.string "Nå, jeg vil hellere ikke tænke på,\n"
	.string "at jeg ikke kan slå dig.\p"
	.string "Jeg lover, at jeg vil få mit GYM på\n"
	.string "højde, så du kan udfordre os igen.\p"
	.string "Jeg håber, at du ser frem til den\n"
	.string "lejlighed lige så meget som jeg!\p"
	.string "… … … … … …\n"
	.string "… … … … … Klik!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Registreret GYM LEDER ROXANNE\n"
	.string "i POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: Jeg er så glad for at se dig igen.\n"
	.string "Jeg er ROXANNE, GYM-LEDEREN her.\p"
	.string "Jeg er sikker på, at vi begge har haft\n"
	.string "mange kampe siden vi sidst mødtes.\p"
	.string "Jeg vil gerne se, hvor meget bedre vi\n"
	.string "er blevet. Lad os kæmpe!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Igen har jeg tabt…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: Jeg har stadig meget at lære\n"
	.string "når det kommer til at kæmpe med POKéMON.\p"
	.string "Den bevidsthed gør, at jeg elsker at\n"
	.string "kæmpe endnu mere!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: Jeg er så glad for at se dig igen.\n"
	.string "Jeg er ROXANNE, GYM LEDEREN her.\p"
	.string "Jeg er sikker på, at vi begge har\n"
	.string "oplevet mange kampe, siden vi sidst sås.\p"
	.string "Jeg vil gerne se, hvor meget bedre vi\n"
	.string "er blevet…\p"
	.string "Åh nej…\n"
	.string "Du har kun én POKéMON med dig?\p"
	.string "Vend venligst tilbage med mindst én\n"
	.string "mere POKéMON.$"

