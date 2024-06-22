@ TRANSLATED

.set LOCALID_FAMILIAR_GRUNT, 13

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Velkommen til HAVMUSEET.\p"
	.string "Indgangsgebyret er ¥50. Ønsker du at gå\n"
	.string "ind?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Vær sød at nyde dig selv.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Åh? Undskyld, men du synes ikke at have nok\n"
	.string "penge.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Nå? Du er med den gruppe, der gik ind\n"
	.string "tidligere?\p"
	.string "Du er den eneste, der er sent. Du burde\n"
	.string "skynde dig at indhente dem!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Vi, TEAM AQUA, eksisterer for alles bedste!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Vi fik besked på at samle os her, så det\n"
	.string "gjorde vi, men…\p"
	.string "Vores CHEF, nøglepersonen, er ikke her.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Hvis jeg rev alt dette her af, ville det gøre\n"
	.string "mig rigtig?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Hvad jeg lærer her, kan jeg bruge til\n"
	.string "skurkagtige gerninger…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Hvis vores skurke ikke rodede tingene til i\n"
	.string "RUSTBORO, ville vi ikke være her!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Jeg havde ikke ¥50, så det tog lang tid at\n"
	.string "komme forbi receptionisten.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Jeg vil gerne lære om havet og bruge den\n"
	.string "viden til at kæmpe.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Jeg bliver helt fjollet og fnisende når jeg\n"
	.string "ser havet!\p"
	.string "For mig er KAPT. STERN den bedste\n"
	.string "rollemodel!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "Havet er uendeligt stort og dybt som en\n"
	.string "evighed…\p"
	.string "Der må være mange POKéMON, som vi ikke\n"
	.string "kender til.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Jeg vil gerne have en hav POKéMON.\p"
	.string "Jeg tror, det ville føles sejt og lækkert at\n"
	.string "kramme.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aiyeeeh! Hvad laver du her?\p"
	.string "Mig? Jeg er det TEAM AQUA-medlem du slog\n"
	.string "før, husker du det? Tilbage i RUSTURF\l"
	.string "TUNNEL?\p"
	.string "Her, tag dette! Du bliver nødt til at tilgive\n"
	.string "mig!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Den TM passer dig bedre end den gør mig.\p"
	.string "Håber aldrig at se dig igen! Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Åh, kom nu! Du er nødt til at tage det her og\n"
	.string "lade mig gå!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "En blå væske snor sig indeni et\n"
	.string "glasbeholder.\p"
	.string "“Dette er et eksperiment for at skabe en\n"
	.string "HVIRVELPOOL kunstigt ved hjælp af vind.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "En rød bold hopper op og ned i en\n"
	.string "glasbeholder.\p"
	.string "“Dette er et eksperiment, der simulerer en\n"
	.string "VANDFALD ved at bruge boldens opdrift.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "Det er et eksempel på jord fra havets bund.\p"
	.string "“I løbet af mange år sætter resterne af\n"
	.string "livsformer sig i bunden af havet og danner\l"
	.string "sedimentlag.\p"
	.string "“Ved at analysere disse lag bliver den gamle\n"
	.string "fortid afsløret.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "Det er et eksempel på strandsand.\p"
	.string "“Sten fra bjerge skylles ned af floder, hvor\n"
	.string "de splintres og slides ned.\p"
	.string "“De bliver reduceret til korn og ender som\n"
	.string "sand på strande.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“HAVS MINIFAKTUM 1 Hvorfor er havvand\n"
	.string "blåt?\p"
	.string "“Lys består af mange farver.\p"
	.string "“Når lys passerer gennem vand, mister de\n"
	.string "fleste farver deres farve.\p"
	.string "“Dog bevarer blå lys sin farve, hvilket får\n"
	.string "havet til at se blåt ud.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“HAVS MINIFAKT 2 Hvorfor er havet saltet?\p"
	.string "“Havvand indeholder opløst salt i form af\n"
	.string "natrium- og klorioner.\p"
	.string "“Disse ioner udvaskes fra klipperne og\n"
	.string "transporteres ud til havet via regn.\p"
	.string "“Koncentrationen af opløst salt gør havet\n"
	.string "salt.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“HAVSKE MINIFAKT 3 Hvad er større? Havet\n"
	.string "eller landet?\p"
	.string "“Havet dækker cirka 70% af planeten, og\n"
	.string "resten er land.\p"
	.string "“Havet er derfor mere end dobbelt så stort\n"
	.string "som land.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "Det er et fossilt med bølgede ridser på det.\p"
	.string "“Jorden på havbunden bliver skuret af\n"
	.string "tidevandet.\p"
	.string "“Det strømmende havvand markerer jorden\n"
	.string "med små ridser og dale.\p"
	.string "“Hvis denne jord bliver fossiliseret,\n"
	.string "kaldes det en bølgeaftryksfossil.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "En mærkelig maskine roterer under en\n"
	.string "glaskuppel.\p"
	.string "Måske er det til at måle dybden af noget…$"



