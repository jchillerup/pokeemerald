@ TRANSLATED

.set LOCALID_WALLY, 6
.set LOCALID_WALLYS_UNCLE, 7
.set LOCALID_SCOTT, 11

MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_SCOTT, 12, 13
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "ONKEL: Det er på grund af POKéMON, at\n"
	.string "denne dreng er så pjattet, antager jeg…\p"
	.string "Men han er blevet lidt for pjattet…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "WALLY: Ej, ONKEL, kan du ikke?\p"
	.string "Jeg vil udfordre dette GYM og se, hvor\n"
	.string "meget bedre jeg er blevet.\p"
	.string "Må jeg, vær sød?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "ONKEL: Nu hold nu igen, WALLY.\p"
	.string "Siden du begyndte at bo med POKéMON, er\n"
	.string "du blevet ret meget stærkere.\p"
	.string "Men synes du ikke, at du tager det for\n"
	.string "langt ved pludselig at udfordre en GYM?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "WALLY: Jeg trykker ikke på det.\p"
	.string "Hvis jeg kombinerer kræfter med RALTS,\n"
	.string "kan vi slå enhver!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "WALLY: Åh! Hej, {PLAYER}!\p"
	.string "Jeg er blevet meget stærkere siden\n"
	.string "sidst vi mødtes.\p"
	.string "{PLAYER}, jeg vil have dig og min\n"
	.string "ONKEL til at forstå det.\p"
	.string "{PLAYER}, vil du venligst tage en kamp\n"
	.string "med mig?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "WALLY: Åh… Hvis du ikke vil kæmpe imod\n"
	.string "mig, {PLAYER}, min ONKEL får ikke at\l"
	.string "vide, at jeg er blevet rigtig stærk.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "ONKEL: {PLAYER}{KUN}, ikke sandt? På\n"
	.string "WALLY's vegne, kan jeg bede dig om at\l"
	.string "kæmpe med ham bare denne ene gang?\p"
	.string "Jeg tror ikke, at han vil lytte til nogen\n"
	.string "grund i den tilstand, han er i.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "WALLY: {PLAYER}, kom nu! Kæmp med mig,\n"
	.string "vær sød.$"

MauvilleCity_Text_WallyHereICome:
	.string "WALLY: {PLAYER}, tak.\p"
	.string "Okay... Her kommer jeg!$"

MauvilleCity_Text_WallyDefeat:
	.string "WALLY: ... ... ... ... ... ...\p"
	.string "... ... ... ... ... ... ...\p"
	.string "Jeg tabte...$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "WALLY: ONKEL… Jeg vil tage til\n"
	.string "VERDANTURF…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, tak. Det er hårdt at være en\n"
	.string "TRÆNER, ikke sandt?\p"
	.string "Det er ikke nok bare at have POKéMON og\n"
	.string "lade dem kæmpe. Det er ikke det, det\l"
	.string "handler om at være en rigtig TRÆNER.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "ONKEL: WALLY, der er ingen grund til at\n"
	.string "være så nedtrykt over dig selv.\p"
	.string "Hvad er det, der holder dig tilbage fra\n"
	.string "at blive stærkere og stærkere?\p"
	.string "Kom nu, lad os gå hjem. Alle venter på\n"
	.string "dig.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "ONKEL: {PLAYER}{KUN}, det slog mig lige at\n"
	.string "du må være TRÆNEREN, som holdt øje med\l"
	.string "WALLY, da han fangete sin POKéMON.\p"
	.string "Hvorfor besøger du os ikke i\n"
	.string "VERDANTURF en gang imellem? Jeg er\l"
	.string "sikker på, at WALLY ville elske det.$"

MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … … … … … … … Beep!\p"
	.string "WALLY: Åh, hej, {PLAYER}!\p"
	.string "Jeg ville bare fortælle dig, at min onkel\n"
	.string "har købt mig en POKéNAV!\p"
	.string "Nu kan jeg kontakte dig når som helst,\n"
	.string "{PLAYER}!\p"
	.string "… … … … … … … … … … … Klik!$"

MauvilleCity_Text_RegisteredWally:
	.string "Registreret WALLY i POKéNAV'en.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT: Hihi… Jeg så den kamp!\p"
	.string "Du er venner med den dreng WALLY, ikke\n"
	.string "sandt?\p"
	.string "Men du holdt ikke noget tilbage og slog\n"
	.string "ham imponerende.\p"
	.string "Ja! Det er, hvad en rigtig POKéMON- kamp\n"
	.string "handler om!\p"
	.string "Jeg idoliserer TRÆNERE som dig!\p"
	.string "… … … … … … Jeg vil heppe på dig!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WATTSON: Åh, {PLAYER}{KUN}! Du ser ud til\n"
	.string "at have masser af energi! Det er en god\l"
	.string "ting, wahahahaha!\p"
	.string "Fint! Jeg har bestemt mig! Jeg har brug\n"
	.string "for en tjeneste, {PLAYER}{KUN}!\p"
	.string "MAUVILLE CITY har en underjordisk\n"
	.string "sektor kaldet NEW MAUVILLE.\p"
	.string "{PLAYER}{KUN}, jeg vil gerne have dig til at\n"
	.string "gå derhen og slukke for GENERATOREN.\p"
	.string "GENERATOREN har kørt lidt amok. Det er\n"
	.string "blevet usikkert.\p"
	.string "Her er nøglen til at komme ind i NEW\n"
	.string "MAUVILLE.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WATTSON: Bare rolig. Det bliver ikke en\n"
	.string "udfordring for dig.\p"
	.string "Indgangen til NY MAUVILLE er kun en\n"
	.string "kort SURF-tur væk fra RUTE 110.\p"
	.string "Det er det, så har du min tillid!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WATTSON: Wahahahaha!\p"
	.string "Jeg vidste det, {PLAYER}! Jeg vidste,\n"
	.string "jeg havde truffet det rigtige valg ved\l"
	.string "at bede dig om hjælp!\p"
	.string "Her er min tak - en TM med THUNDERBOLT!\p"
	.string "Fortsæt endelig, du har fortjent den!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WATTSON: Wahahahaha!\p"
	.string "Det glæder mig ufatteligt at se de unge\n"
	.string "træde frem og tage styringen!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Du ved, det er sjovt at have POKéMON\n"
	.string "kampe og sådan…\p"
	.string "Men hvis din POKéMON bliver såret, skal\n"
	.string "du pleje den tilbage til sundhed.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Vejen i denne by strækker sig mod nord\n"
	.string "og syd, øst og vest.\p"
	.string "På grund af det får vi alle mulige\n"
	.string "mennesker forbi.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Har du været i RYDEL'S CYCLES endnu?\p"
	.string "RYDEL, ejeren, er en meget gavmild mand.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Selvom du cykler, kan vilde POKéMON\n"
	.string "angribe dig.$"

MauvilleCity_Text_CitySign:
	.string "MAUVILLE CITY “Den lyse og skinnende\n"
	.string "by fyldt med sjov!”$"

MauvilleCity_Text_GymSign:
	.string "MAUVILLE CITY POKéMON GYM LEDER:\n"
	.string "WATTSON “Den livlige og\l"
	.string "elektrificerende mand!”$"

MauvilleCity_Text_BikeShopSign:
	.string "Kør i grus og ryst din sjæl! RYDELS\n"
	.string "CYKLER$"

MauvilleCity_Text_GameCornerSign:
	.string "“Legestedet for alle!” MAUVILLE\n"
	.string "SPILHJØRNE$"

MauvilleCity_Text_ExplainTV:
	.string "Hej, kigger du overhovedet på TV?\p"
	.string "De har tilføjet en masse seje nye shows\n"
	.string "for nylig.\p"
	.string "TV er så sejt. Jeg har set mine venner\n"
	.string "på TV helt ud af det blå.\p"
	.string "Og nogle gange kommer man endda på TV\n"
	.string "uden at blive fortalt det.\p"
	.string "Jeg ville ønske, at jeg kunne være på TV\n"
	.string "engang.\p"
	.string "Derfor synes jeg, at du burde kigge på\n"
	.string "TV, når du kan.$"

MauvilleCity_Text_BeenCheckingOutTV:
.string "Hej, har du kigget på fjernsyn?$"



