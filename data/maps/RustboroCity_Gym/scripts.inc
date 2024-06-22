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
	.string "Lyt, min ven! Vil du gerne blive MESTEREN?\p"
	.string "Jeg er ikke EN TRÆNER, det er ikke mig, men jeg\n"
	.string "kan helt sikkert give dig vindende råd.\p"
	.string "Så er det afgjort! Vi går efter\n"
	.string "POKéMON-MESTERSKABET sammen!\p"
	.string "Det er din opgave som EN TRÆNER at samle\n"
	.string "GYMNASTIKMÆRKER, ikke sandt?\p"
	.string "Men GYMLEDERE er ikke nemme!\p"
	.string "Og der kommer jeg ind i billedet! Jeg er her\n"
	.string "for at give ekspert-råd!\p"
	.string "ROXANNE, GYMLEDEREN, bruger ROCK-type\n"
	.string "POKéMON.\p"
	.string "ROCK-typen er meget holdbar, men den kan\n"
	.string "ikke tåle VAND-type og GRÆS-type angreb.\p"
	.string "Kom og se mig efterfølgende, hvis du slår\n"
	.string "GYMLEDEREN.\p"
	.string "Nå, gå efter det!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa! Sikke en fantastisk sejr! Mit\n"
	.string "heppende har nok virket!\p"
	.string "Fantastisk! Tjek din TRÆNERKORT.\p"
	.string "STENMÆRKET, du fik, burde være korrekt\n"
	.string "optaget på det.\p"
	.string "Med andre ord…\p"
	.string "Du har besteget det første trin på vejen\n"
	.string "mod MESTERSKABET!\p"
	.string "Det må føles fantastisk!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Tag ikke os GYM TRAINERS let! Jeg vil vise\n"
	.string "dig, hvorfor vi er bedre!$"

RustboroCity_Gym_Text_JoshDefeat:
.string "Du var for god til mig...$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Du har ikke set noget af ROCK typens\n"
	.string "skræmmende kraft!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Hvis du ikke kan slå mig, har du ingen\n"
	.string "mulighed mod ROXANNE!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wow! Du har potentiale!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE er stærkere end mig med flere\n"
	.string "gange.\p"
	.string "Du bør være på vagt!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Vi er måske midt i byen, men så hvad?\p"
	.string "Mine KLIPPE POKéMON skal bruge plads til at\n"
	.string "hærge!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Åh ja, åh ja! Vores udfordrer er en sej kunde!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Jeg må nok give vores LEDER en stor kredit.\n"
	.string "Det krævede intelligens og sund fornuft at\l"
	.string "vælge STEN-typen i en så ung alder.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Hej, jeg er ROXANNE, lederen af\n"
	.string "RUSTRUTE-POKéMON GYM.\p"
	.string "Jeg blev GYM-leder for at kunne anvende\n"
	.string "det, jeg lærte på POKéMON- TRÆNERSKOLEN i\l"
	.string "kamp.\p"
	.string "Kan du venligst demonstrere, hvordan du\n"
	.string "kæmper, og med hvilke POKéMON?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Så... Jeg tabte...\p"
	.string "Det ser ud til, at jeg stadig har meget mere\n"
	.string "at lære... \p"
	.string "Jeg forstår.\p"
	.string "POKéMON LIGAENS regler siger, at\n"
	.string "TOGETHINGs skal gives dette hvis de\l"
	.string "besejrer en GYM LEADER.\p"
	.string "Vær venlig at acceptere det officielle\n"
	.string "POKéMON LIGA STENBAGE.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} modtog STENBADGEN fra\n"
	.string "ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "STENBADGEN forstærker ANGREBSKRAFTEN\n"
	.string "hos dine POKéMON.\p"
	.string "Den gør det også muligt for dem at bruge\n"
	.string "HM-teknikken KLIP uden for kamp.\p"
	.string "Tag også denne med dig.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Den TEKNISKE MASKINE, TM39, indeholder\n"
	.string "STENGRAV.\p"
	.string "Den forårsager skade ved at kaste sten, og\n"
	.string "den sænker også HASTIGHED.\p"
	.string "Hvis du bruger en TM, lærer en POKéMON\n"
	.string "øjeblikkeligt angrebet.\p"
	.string "Husk, en TM kan kun bruges én gang, så tænk\n"
	.string "dig om, før du bruger den.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Fordi du er så stærk, bør du udfordre andre\n"
	.string "GYM LEDERE.\p"
	.string "Ved at kæmpe mod mange TRÆNERE, bør du lære\n"
	.string "mange ting.$"

RustboroCity_Gym_Text_GymStatue:
.string "RUSTBORO CITY POKéMON GYM$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "RUSTBORO CITY POKéMON GYM\p"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … … … … … … … Bip!\p"
	.string "ROXANNE: Åh, hej, {PLAYER}? Det er\n"
	.string "ROXANNE fra RUSTBORO BY.\p"
	.string "Jeg hørte fra BRAWLY, at du bevæger dig op\n"
	.string "gennem rækkerne af TRÆNERE med en utrolig\l"
	.string "fart.\p"
	.string "Nå, jeg vil hellere ikke tænke på, at jeg ikke\n"
	.string "kan slå dig.\p"
	.string "Jeg lover, at jeg vil få mit GYM på højde, så du\n"
	.string "kan udfordre os igen.\p"
	.string "Jeg håber, at du ser frem til den lejlighed\n"
	.string "lige så meget som jeg!\p"
	.string "… … … … … … … … … … … Klik!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Registreret GYM LEDER ROXANNE i POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: Jeg er så glad for at se dig igen.\n"
	.string "Jeg er ROXANNE, GYM-LEDEREN her.\p"
	.string "Jeg er sikker på, at vi begge har haft mange\n"
	.string "kampe siden vi sidst mødtes.\p"
	.string "Jeg vil gerne se, hvor meget bedre vi er\n"
	.string "blevet. Lad os kæmpe!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr… Igen har jeg tabt…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: Jeg har stadig meget at lære når\n"
	.string "det kommer til at kæmpe med POKéMON.\p"
	.string "Den bevidsthed gør, at jeg elsker at kæmpe\n"
	.string "endnu mere!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: Jeg er så glad for at se dig igen.\n"
	.string "Jeg er ROXANNE, GYM LEDEREN her.\p"
	.string "Jeg er sikker på, at vi begge har oplevet\n"
	.string "mange kampe, siden vi sidst sås.\p"
	.string "Jeg vil gerne se, hvor meget bedre vi er\n"
	.string "blevet…\p"
	.string "Åh nej… Du har kun én POKéMON med dig?\p"
	.string "Vend venligst tilbage med mindst én mere\n"
	.string "POKéMON.$"



