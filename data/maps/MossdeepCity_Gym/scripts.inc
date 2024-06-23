@ TRANSLATED

MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Yo, hvordan går det, kommende MESTER?\p"
	.string "Her i gymmet bruger lederne\n"
	.string "PSYKISK-type POKéMON.\p"
	.string "Hvis du står over for dem med KAMP-\n"
	.string "eller GIFT-type POKéMON, vil de påføre\l"
	.string "dig frygtelige skader!\p"
	.string "Desuden vil de angribe dig med\n"
	.string "imponerende kombinationsangreb.\p"
	.string "Hvis du vil vinde, skal du vise dem, hvor\n"
	.string "tæt du er med dine POKéMON. Kom så!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Wow, du er fantastisk! Du er en super\n"
	.string "TRÆNER!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Kampe afhænger af styrken i dit indre!\n"
	.string "De svagtsindede vil aldrig vinde!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "Jeg tabte! Jeg skal styrke mit mod igen!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "De tøvende taber. Det er min advarsel\n"
	.string "til dig.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Vis mig dit talent!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Du besidder spektakulært talent!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Hvis der er vidundere i verden, så er\n"
	.string "vores GYM LEADERS dem!\p"
	.string "Du kan dog være endnu dygtigere end\n"
	.string "dem...$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Hihihihi… Se mig levitere en POKé BOLD\n"
	.string "telekinetisk!\p"
	.string "Wrooooooooaaaar! … … … … … … …\p"
	.string "Nogle gange er jeg ude af sync…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Mine POKéMON kampfærdigheder er ude af\n"
	.string "sync, også!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "En POKé BALL var for tung at løfte\n"
	.string "psykisk. Men denne støvbunny…\p"
	.string "Whoooooooooooooooh! … … … … … …\p"
	.string "Nej, jeg snyder ikke! Jeg blæste ikke på\n"
	.string "den! Ærligt!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Når du taber til mig, så vær ikke for\n"
	.string "hård ved dig selv.\p"
	.string "Det er ikke fordi, du er svag--jeg er\n"
	.string "bare for stærk!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Du er bare for stærk!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Jeg vil ikke blive nedtrykt over at\n"
	.string "tabe. Jeg skal bare træne hårdere.\p"
	.string "Positiv tænkning - det er mit stærkeste\n"
	.string "punkt!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Jeg ser det... Jeg ser din fremtid...\p"
	.string "Hvis du kan slå mig, vil jeg fortælle dig\n"
	.string "din fremtid!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Jeg giver op!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Du vil udkæmpe en fantastisk intens\n"
	.string "kamp med vores GYM LEDERE…\p"
	.string "Resultatet… Du vil ikke høre det fra\n"
	.string "mig!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "De veje, du har rejst... Hvad du har\n"
	.string "oplevet...\p"
	.string "Kom efter mig med alt, hvad du har lært!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Du har fulgt en sti af storhed!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "En lys fremtid venter dem, der har\n"
	.string "arbejdet flittigt.\p"
	.string "For dem, der slaskede, er der kun\n"
	.string "fortvivlelse tilbage.\p"
	.string "Man høster som man sår...$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Selv på risikoen for livet, vil jeg vinde\n"
	.string "dette slag!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Hvad du gør… Det skræmmer mig…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Hvordan tør du at slå mig…\p"
	.string "Det bliver ikke min skyld, hvis noget\n"
	.string "forfærdeligt overgår dig…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hohoho.\p"
	.string "Du har brug for at jeg viser dig, hvor\n"
	.string "udholdende PSYCHIC-typen kan være.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Åh! Du, du! Dit kampstil er fantastisk!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "Jeg... Jeg lader mig ikke slå ud af\n"
	.string "nederlaget, uanset hvor slemt det er.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Lad mig vise dig en helt forfærdelig,\n"
	.string "skræmmende tid!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "N-nej!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Din livsgnist er smittende! Kom hurtigt\n"
	.string "væk fra mig!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Jeg er måske passeret min storhedstid,\n"
	.string "men jeg foreslår, at du ikke nedvurderer\l"
	.string "mig.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Åh, du flyder over med kraften fra\n"
	.string "ungdommen!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Det ser ud til, at jeg ikke kunne\n"
	.string "overvinde din unge energi.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Du kommer ikke igennem til slutningen!\n"
	.string "Ikke hvis jeg kan forhindre det!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Hvordan kunne du være så latterligt\n"
	.string "stærk?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Hov! Du er måske stærk, men du er ikke\n"
	.string "egnet til det PSYKISKE type!\p"
	.string "Din kampstil er på en eller anden måde\n"
	.string "brutal!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Wroooar! Få en smag af min super\n"
	.string "POKéMON hårdkæmpende kraft!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Åh! Færdig!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Sådan! Jeg tror, jeg vil udvikle en\n"
	.string "speciel uovervindelig POKéMON-evne\l"
	.string "næste gang.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "TATE: Hihihi… Blev du overrasket?\p"
	.string "LIZA: Huhuhu… Blev du overrasket?\p"
	.string "TATE: At der er to GYM LEADERS? LIZA:\n"
	.string "At der er to GYM LEADERS?\p"
	.string "TATE: Vi er tvillinger! LIZA: Vi er\n"
	.string "tvillinger!\p"
	.string "TATE: Vi behøver ikke at tale, fordi…\n"
	.string "LIZA: Vi kan hver især fornemme…\p"
	.string "TATE: Hvad den anden tænker… LIZA: Alt\n"
	.string "i vores sind!\p"
	.string "TATE: Vores kombination… LIZA: Kan du\n"
	.string "slå den?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "TATE: Hvad?! Vores kombination... LIZA:\n"
	.string "Blev knust!\p"
	.string "TATE: Det kan ikke undgås. Du har\n"
	.string "vundet... LIZA: Så tag dette som\l"
	.string "anerkendelse.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} modtog SINDS-EMBLEMET fra\n"
	.string "TATE og LIZA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "TATE: MIND BADGE styrker SP. ATK og SP.\n"
	.string "DEF hos POKéMON.\p"
	.string "LIZA: Det giver dig også mulighed for at\n"
	.string "bruge HM-trækket DYK uden for kamp.\p"
	.string "TATE: Du bør også tage dette med, også.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "TATE: Den TM04 indeholder… LIZA: RO\n"
	.string "FRÆK!\p"
	.string "TATE: Den øger SP. ATK og… LIZA: Den\n"
	.string "øger SP. DEF!\p"
	.string "TATE: Det er et træk, der er perfekt…\n"
	.string "LIZA: Til PSYKISK POKÉMON!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "Registrerede GYM LEADERS TATE & LIZA i\n"
	.string "POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "TATE: Ser ud til, at båndet mellem dig og\n"
	.string "dine POKéMON er langt stærkere end det\l"
	.string "bånd, vi deler som tvillinger.\p"
	.string "LIZA: Du vil blive endnu stærkere! Vi\n"
	.string "har kæmpet mod dig, så vi ved.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "TATE: Hihihi... Blev du overrasket?\p"
	.string "LIZA: At der er to GYM LEADERS?\p"
	.string "TATE: Ups, du har kun en... LIZA:\n"
	.string "POKéMON der kan kæmpe.\p"
	.string "TATE: Vi kan ikke kæmpe på den måde!\p"
	.string "LIZA: Hvis du vil udfordre os, tag nogle\n"
	.string "flere POKéMON.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "MOSSDEEP BYS POKéMON-GYM$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "MOSSDEEP BYS POKÉMON GYM\p"
	.string "LIZA OG TATE'S CERTIFICEREDE TRÆNERE:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "TATE: POKéMON… LIZA: POKéMON…\p"
	.string "TATE: Ved at ændre holdets\n"
	.string "sammensætning… LIZA: Ændrer kampstilen\l"
	.string "sig.\p"
	.string "TATE: Men mig… LIZA: Men mig…\p"
	.string "TATE: Jeg vil altid være sammen med\n"
	.string "LIZA! LIZA: Jeg vil altid være sammen\l"
	.string "med TATE!\p"
	.string "TATE: Vores kombination… LIZA: Vi vil\n"
	.string "vise dig igen og igen!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "TATE: Du og dine POKéMON... LIZA: Det er\n"
	.string "ligesom I var søskende!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "TATE: Du kan slå os ned, men vi bliver\n"
	.string "aldrig nede!\p"
	.string "LIZA: Fordi vi to, altid støtter\n"
	.string "hinanden!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "TATE: Du er tilbage igen… LIZA: Du er\n"
	.string "tilbage igen…\p"
	.string "TATE: For at udfordre os igen. LIZA: For\n"
	.string "at udfordre os igen.\p"
	.string "TATE: Men… LIZA: Til vores kamp…\p"
	.string "TATE: Du har kun medbragt én POKéMON!\n"
	.string "LIZA: Du har kun medbragt én POKéMON!\p"
	.string "TATE: Vi har brug for, at du medbringer\n"
	.string "mindst… LIZA: To POKéMON, når du vender\l"
	.string "tilbage.$"



