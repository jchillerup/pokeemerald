@ TRANSLATED

.set LOCALID_WOMAN_1, 19
.set LOCALID_MAN_1, 20

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "MAY: Hej? {PLAYER}{KUN}, er du også på indkøb?\p"
	.string "Jeg har købt en hel masse DUKKER og\n"
	.string "PLAKATER.\p"
	.string "Selvfølgelig har jeg også fanget en masse\n"
	.string "POKéMON, og jeg opdrager dem på ordentlig\l"
	.string "vis.\p"
	.string "Faktisk er jeg mere bekymret for, om du\n"
	.string "opdrager dine POKéMON ordentligt,\l"
	.string "{PLAYER}{KUN}.\p"
	.string "Jeg vil kæmpe mod dig, så du kan vise mig dine\n"
	.string "POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "MAY: Åh, hvorfor? {PLAYER}{KUN}, har du ikke\n"
	.string "trænet dine POKéMON?\p"
	.string "Det er ikke særlig imponerende som en\n"
	.string "TRÆNER...$"

LilycoveCity_Text_MayBattleMe:
	.string "MAY: Kom så, kæmp med mig, så jeg kan få set\n"
	.string "dine POKéMON!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "MAY: Den POKéMON, jeg opdrættede, vil ikke\n"
	.string "blive slået af din POKéMON, {PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Jeg husker det slag, jeg havde med dig,\n"
	.string "{PLAYER}{KUN}, på RUTE 103.\p"
	.string "Det slag hjalp dig med at blive så stærk,\n"
	.string "{PLAYER}{KUN}, gjorde det?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "MAY: Jeg overvejer at tage tilbage til\n"
	.string "LITTLEROOT snart.\p"
	.string "Jeg har fanget en god gruppe POKéMON, og\n"
	.string "min POKéDEX er ved at nå frem, så jeg tager\l"
	.string "hjem for at vise min far.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, hvad har du tænkt dig at gøre?\p"
	.string "Samle alle GYMBADGES og tage POKéMON LIGA\n"
	.string "udfordringen?\p"
	.string "Nå, mens du samler BADGES, {PLAYER}{KUN}, vil\n"
	.string "jeg arbejde på min POKéDEX. Jeg vil\l"
	.string "færdiggøre den før dig!\p"
	.string "Vi ses!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, hvad har du tænkt dig at gøre?\p"
	.string "Skal du udfordre POKéMON LIGAEN?\p"
	.string "Eller vil du fuldføre din POKéDEX?\p"
	.string "Jeg har måske tabt til dig i kampen, men jeg\n"
	.string "vil færdiggøre min POKéDEX før dig!\p"
	.string "Vi ses!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, hvad har du tænkt dig at gøre?\p"
	.string "Vil du tage udfordringen på KAMPSKYSSET?\p"
	.string "Eller vil du fuldføre din POKéDEX?\p"
	.string "Du har måske slået mig i kamp, men jeg vil\n"
	.string "færdiggøre min POKéDEX først!\p"
	.string "Vi ses!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRENDAN: Åh, hei, det er {PLAYER}.\p"
	.string "Jeg løber en ærinde for min far. Nej, jeg\n"
	.string "køber ikke nogen DUKKER.\p"
	.string "Nå, det er lang tid siden.\p"
	.string "Har lyst til at kæmpe for at se, hvem der har\n"
	.string "opdraget POKéMON bedre?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRENDAN: Åh, hvad er der galt? Har du ikke\n"
	.string "selvtilliden?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRENDAN: Vil du kæmpe for at se, hvem  der har\n"
	.string "opdrættet POKéMON bedre?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRENDAN: Åh, men du ved, jeg ikke kommer til\n"
	.string "at tabe til {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Puhh… Du har gjort meget opdræt.\p"
	.string "Det stikker lidt - jeg havde en forspring\n"
	.string "som EN TRÆNER…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRENDAN: Jeg... Jeg har tænkt mig at tage\n"
	.string "hjem til LITTLEROOT.\p"
	.string "Du ved, jeg hjælper min far med hans POKéDEX.\n"
	.string "Det går ret godt, så jeg burde vise ham det.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, hvad har du tænkt dig at gøre?\p"
	.string "Samle alle GYM BADGES og tage udfordringen\n"
	.string "i POKéMON-LIGAEN?\p"
	.string "Måske vil jeg også gøre det…\p"
	.string "Nå, uanset hvad, hæng i!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, hvad har du tænkt dig at gøre?\p"
	.string "Når du er så stærk, vil du så tage POKéMON\n"
	.string "LIGA udfordringen?\p"
	.string "Haha, selv jeg--hvis jeg trænede mine\n"
	.string "POKéMON lidt mere, burde jeg være stærkere\l"
	.string "end dig, {PLAYER}.\p"
	.string "Nå, uanset hvad, hold ud!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, hvad har du tænkt dig at gøre?\p"
	.string "Vil du tage udfordringen i BATTLE\n"
	.string "FRONTIER?\p"
	.string "Eller vil du fuldføre din POKéDEX?\p"
	.string "Da du er så stærk, burde du overveje BATTLE\n"
	.string "FRONTIER.\p"
	.string "Haha, hvis jeg træner mine POKéMON lidt\n"
	.string "mere, vil jeg blive stærkere end dig,\l"
	.string "{PLAYER}.\p"
	.string "Måske jeg også skulle tage til BATTLE\n"
	.string "FRONTIER.\p"
	.string "Nå, uanset hvad, hold ud!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Hihihi…\p"
	.string "Vi flyttede mere bytte ind i vores hemmelige\n"
	.string "SKJULESTED i dag…\p"
	.string "H-Hvem er du?! Jeg talte bare til mig selv!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Jeg er bare en GRUNT, så jeg ved ikke, hvad\n"
	.string "BOSSen tænker på…\p"
	.string "Men som en del af HOLD AQUA ved jeg, at jeg vil\n"
	.string "få chancen for at gøre store ting!\p"
	.string "Hvem er du?! Jeg talte bare med mig selv!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Hej!\p"
	.string "Gå ikke nær hulen i bugten!\p"
	.string "Hvorfor? Du behøver ikke en grund! Jeg er\n"
	.string "voksen, så du lytter bare til mig!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Hvis hele denne store verden bliver vores,\n"
	.string "holdet fra TEAM AQUA, så vil det være et mere\l"
	.string "lykkeligt sted for POKéMON også.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Der! WAILMER! Spring ud af vandet nu!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hva'? Hvad vil du?\p"
	.string "Du ødelægger vores træning, så kan du, som,\n"
	.string "skride væk?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Der er en POKéMON-KONKURRENCEHAL lige\n"
	.string "her i byen. \p"
	.string "Det betyder, at velopdragne POKéMON fra\n"
	.string "hele landet vil komme. \p"
	.string "Mit hjerte svulmer af spænding!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Har du set den underlige hule i bugten ved\n"
	.string "byens kant?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Jeg vil lære min POKéMON nogle nye angreb\n"
	.string "for at deltage i en KONKURRENCE.\p"
	.string "Så vil jeg besøge ANGREBSSLETTEREN og få\n"
	.string "den til at glemme HM-angreb.$"

LilycoveCity_Text_ImFromKanto:
	.string "Jeg kommer fra KANTO.\p"
	.string "HOENN-regionen er smuk med hele dens vand\n"
	.string "og frodige natur.\p"
	.string "Hvad? Vent lige et øjeblik…\p"
	.string "Kunne der være sjældne POKéMON, som kun\n"
	.string "lever i dette område?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "TEAM AQUAs træner deres WAILMER i bugten.\p"
	.string "Vi SEJLERE kan ikke få vores både ud på\n"
	.string "havet med dem i vejen!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Hej, vidste du det?\p"
	.string "Nogen sparkede TEAM AQUA væk for os!\p"
	.string "Det fik WAILMER ud af bugten, så vi kan få\n"
	.string "vores både ud igen.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Jeg lå og slappede af med en lur ved\n"
	.string "havsiden, lyttende til bølgerne…\p"
	.string "Da nogen stjal min POKéMON!\p"
	.string "Hvem er kidnapperen? TEAM AQUA? Er det\n"
	.string "TEAM AQUA?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Min savnede POKéMON… Den kom tilbage uden\n"
	.string "at jeg lagde mærke til det!$"

LilycoveCity_Text_ImArtDealer:
	.string "Jeg er en KUNSTHANDELER.\p"
	.string "Jeg køber og sælger fin kunst, især malerier.\p"
	.string "Jeg har hørt, at MUSEET her har magnifikke\n"
	.string "værker udstillet...$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Selv mens vi bliver ældre og rynkede,\n"
	.string "forbliver havet for evigt ungt med den\l"
	.string "levende glans af livet…\p"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Det var tres år siden, min mand forslog til\n"
	.string "mig her. Havet er stadig lige så smukt.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hm, kender du til den mærkelige grotte i\n"
	.string "denne vig?\p"
	.string "Den var en naturlig dannelse, men så kom det\n"
	.string "HOLD AQUA hold og lavede deres\l"
	.string "ombygninger.\p"
	.string "De kalder sig selv den “natur-elskende\n"
	.string "HOLD AQUA”!\p"
	.string "Men det de gør og det de siger har slet ikke\n"
	.string "noget med hinanden at gøre!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Den hule i bugten... \p"
	.string "Jeg lagde ikke mærke til det med det samme, \n"
	.string "men den er helt tom nu.\p"
	.string "Det hold fra TEAM AQUA, de må  være\n"
	.string "forsvundet for altid.$"

LilycoveCity_Text_CitySign:
	.string "LILYCOVE BY\p"
	.string "“Hvor landet ender og havet begynder.”$"

LilycoveCity_Text_ContestHallSign:
	.string "POKéMON KONKURRENCESAL\n"
	.string "“Samlingsstedet for TRÆNERE!”$"

LilycoveCity_Text_MotelSign:
	.string "COVE LILY MOTEL\p"
	.string "“Husk os som COVE LILY fra LILYCOVE.”$"

LilycoveCity_Text_MuseumSign:
	.string "LILYCOVE MUSEUM\p"
	.string "“POKéMON Mesterværk Samling på\n"
	.string "udstilling!$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "LILYCOVE MUSEUM\p"
	.string "“{PLAYER}'s POKéMON Samling er\n"
	.string "udstillet!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "LILYCOVE CITY HARBOR\p"
	.string "“Færgen S.S. TIDAL er under konstruktion i\n"
	.string "SLATEPORT CITY.\p"
	.string "“Servicen forventes at starte snart.”$"

LilycoveCity_Text_HarborSign:
	.string "LILYCOVE CITY HAVN\p"
	.string "“Tag på en dejlig sejltur på færgen S.S.\n"
	.string "TIDAL.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "POKéMON TRAINER FAN CLUB\p"
	.string "Navnene på TRÆNERE er kradset overalt på\n"
	.string "skiltet...$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "LILYCOVE DEPARTMENT STORE\p"
	.string "“Fyldt med fantastiske varer og spænding!\p"
	.string "“Et fantastisk sted at finde det du har\n"
	.string "brug for!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "FLYTT AFLEVERINGSBO\p"
	.string "“Uønskede POKéMON-moves slettet.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Kender du til maskinen BÆRBLÆNDEREN?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Folk skal arbejde sammen for at få det til at\n"
	.string "spinne hurtigere.\p"
	.string "Jo hurtigere du kan få det til at spinne, jo\n"
	.string "bedre {POKEBLOCK}S kan du få, har jeg hørt.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Det bruges til at lave en slags slik kaldet en\n"
	.string "{POKEBLOCK}.\p"
	.string "Hvis du giver en god {POKEBLOCK} til en POKéMON,\n"
	.string "vil dens tilstand forbedres markant.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "Jeg har hørt, at der er et tårn et sted ude på\n"
	.string "søruterne.\p"
	.string "Det hedder HIMMELPILEN, siges det.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Jeg så denne høje tårn et sted omkring RUTE\n"
	.string "131.\p"
	.string "Kunne det muligvis være...?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Vi er lige ankommet her på vores\n"
	.string "bryllupsrejse.\p"
	.string "Vi så tilfældigvis en DRAGE-type POKéMON\n"
	.string "flyve meget højt oppe på himlen.\p"
	.string "Bor seje POKéMON som den her i\n"
	.string "HOENN-regionen?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "På vores bryllupsrejse svor vi at se så\n"
	.string "mange sjældne POKéMON som muligt.\p"
	.string "Så vi var henrykte over at se en sjælden\n"
	.string "POKéMON lige så snart vi ankom.\p"
	.string "Jeg mener, vi er helt glade!$"



