@ TRANSLATED

.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_RIVAL, 11, 9
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "MAY: {PLAYER}{KUN}! Lang tid siden vi har set hinanden!\p"
	.string "Åh? Mens jeg besøgte varme kilder,\n"
	.string "fik du LAVARIDGE GYM BADGE.\p"
	.string "Du må have samlet\n"
	.string "gode POKéMON…\l"
	.string "Nej, jeg tror du har opdrættet nogle.\p"
	.string "Jeg gætter på, at det er okay for dig at\n"
	.string "få dette.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "MED de GO-BRILLER, kommer du ingen\n"
	.string "problemer igennem ørkenen nær\n"
	.string "VEJ 111.\p"
	.string "Men, wow, {PLAYER}{KUN}…\n"
	.string "At udfordre GYMMER…\p"
	.string "Du gør virkelig en indsats, fordi\n"
	.string "du ikke vil tabe til mig, hva'!\p"
	.string "{PLAYER}{KUN}, jeg tror, jeg burde\n"
	.string "udfordre din far i PETALBURG GYM.\p"
	.string "Vi ses igen!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRENDAN: {PLAYER}, hey, det var længe siden.\n"
	.string "Hvordan går det?\p"
	.string "Hmm…\n"
	.string "Det er en fin samling af MÆRKER.\p"
	.string "Godt, så.\n"
	.string "Du kan ligeså godt få dette.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRENDAN: Hold dem godt fast, hvis du har\n"
	.string "planer om at tage ind i ørkenen nær\l"
	.string "ROUTE 111.\p"
	.string "Der burde være nogle POKéMON, der\n"
	.string "kun bor i ørkenområder.\l"
	.string "Du skulle kigge efter dem.\p"
	.string "Hvad angår mig…\n"
	.string "Jeg overvejer at udfordre NORMAN,\l"
	.string "LEDEREN af PETALBURG's GYM.\p"
	.string "I modsætning til dig, {PLAYER}, ser\n"
	.string "din far virkelig sej ud.\p"
	.string "Vi ses!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Jeg har her ET ÆG.\p"
	.string "Jeg havde håbet at få det til at\l"
	.string "klække ved at dække det til med varm\n"
	.string "sand ved de varme kilder.\l"
	.string "Men det ser ikke ud til at være\n"
	.string "nok…\p"
	.string "Jeg har hørt, at det ville være bedst,\n"
	.string "hvis det blev holdt sammen med POKéMON\n"
	.string "og båret rundt.\p"
	.string "Du er en TRÆNER, ikke sandt?\n"
	.string "Og dine POKéMON udstråler vitalitet.\p"
	.string "Så, hvad siger du?\n"
	.string "Vil du tage dette ÆG for at klække?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Godt! Jeg håber, du vil gå rigeligt\n"
	.string "med dette her ÆG!$"

LavaridgeTown_Text_ReceivedTheEgg:
".string "{PLAYER} modtog ÆGGET.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Åh? Du har for mange POKéMON.\n"
	.string "Der er ikke plads til dette ÆG…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Som du ønsker, så...\p"
	.string "Hvis du ændrer mening om at\n"
	.string "udruge dette ÆG, så er jeg her.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Af og til vil der blive fundet et \n"
	.string "ÆG på POKéMON-BØRNEHUSET.\p"
	.string "I hvert fald sådan lyder rygtet.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "Vi tager så meget varmt vand, som vi har brug for,\n"
	.string "og alligevel løber varme kilder aldrig tør.\p"
	.string "Er det ikke magisk?\p"
	.string "Disse varme kilder opstår nær aktive\n"
	.string "vulkaner. Vandårer under jorden opvarmes af magma\l"
	.string "for at stige op som varme kilder.$" 

LavaridgeTown_Text_PokemonNippedBackside:
	.string "At være begravet i denne varme sand er…\n"
	.string "Suk…\p"
	.string "Så varmt og himmelsk…\p"
	.string "Hvad? Gyaah! Av!\p"
	.string "En POKéMON bed mig bag i!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Åh, kan du lide varme kilder, gør du?\p"
	.string "Det er overraskende for en så ung\n"
	.string "som dig.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Jeg bader i de varme kilder hver dag.\p"
	.string "Jeg vil gerne blive en smuk og stærk\n"
	.string "GYM LEDER som FLANNERY.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Hvis folk lægger POKéMON i varme kilder,\n"
	.string "kunne det være virkelig mærkeligt.\p"
	.string "Måske ender det som et elektrisk bad,\n"
	.string "et boblebad eller endda et lava-bad…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "De påstår, at disse varme kilder\n"
	.string "er gode til at berolige nervøs\n"
	.string "spænding, lindre ømme muskler,\l"
	.string "løse romantiske problemer og\l"
	.string "tiltrække penge…$"

LavaridgeTown_Text_TownSign:
	.string "LAVARIDGE TOWN\p"
	.string "“POKéMON CENTER VARME KILDER\n"
	.string "Et fremragende sted at slappe af!”$"

LavaridgeTown_Text_GymSign:
	.string "LAVARIDGE BY POKéMON GYM\n"
	.string "LEDER: FLANNERY\l"
	.string "“En med en ildfuld passion, der brænder!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "POKéMON URTEBUTIK\n"
	.string "“Bitter smag - bedre kur!”$"



