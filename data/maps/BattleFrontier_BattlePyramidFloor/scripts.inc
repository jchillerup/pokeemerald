@ TRANSLATED

BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Dette er en eksempelbesked.$"

gText_BattlePyramidConfirmRest::
	.string "Din KAMPPIRAMIDE-quest vil blive gemt,\n"
	.string "så du kan afslutte for nu.\p"
	.string "Er det okay?$"

gText_BattlePyramidConfirmRetire::
	.string "Er du sikker på, at du vil afslutte din\n"
	.string "PYRAMID-quest?$"

BattlePyramid_Text_ExitHintUp1::
	.string "den retning: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "Denne etages udgang er i den retning: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "Denne gangs udgang er i den retning: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "Denne etages udgang er i den retning: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "Udgangen på dette niveau er i\n"
	.string "opadgående retning.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "Udgangen på dette niveau er i venstre\n"
	.string "retning.$"

BattlePyramid_Text_ExitHintRight2::
	.string "Udgangen på dette niveau er i retning.\n"
	.string "{RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown2::
	.string "Udgangen på dette niveau er i\n"
	.string "{DOWN_ARROW}-retningen.$"

BattlePyramid_Text_ExitHintUp3::
	.string "Udgangen er derover den vej {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "Udgangen er den vej vej.{LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight3::
	.string "Udgangen er den vej {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown3::
	.string "Udgangen er den vej. denne {DOWN_ARROW} vej.$"

BattlePyramid_Text_ExitHintUp4::
	.string "På dette niveau er udgangen et sted i\n"
	.string "{UP_ARROW}-retningen.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "På dette niveau er udgangen et sted i {LEFT_ARROW}\n"
	.string "retning.$"

BattlePyramid_Text_ExitHintRight4::
	.string "På dette gulv er udgangen et eller\n"
	.string "andet sted i {RIGHT_ARROW} retning.$"

BattlePyramid_Text_ExitHintDown4::
	.string "På dette gulv er udgangen et elleranden\n"
	.string "sted inedadgående retning.$"

BattlePyramid_Text_ExitHintUp5::
	.string "Udgangen? Det er den {UP_ARROW} vej.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "Udgangen? Den er den {LEFT_ARROW} vej.$"

BattlePyramid_Text_ExitHintRight5::
	.string "Udgangen? Det er den {RIGHT_ARROW} vej.$"

BattlePyramid_Text_ExitHintDown5::
	.string "Udgangen? Det er den {DOWN_ARROW} vej.$"

BattlePyramid_Text_ExitHintUp6::
	.string "Udgangen er tilfældigvis i {UP_ARROW} retning.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "Udgangen er tilfældigvis i {LEFT_ARROW} retning.$"

BattlePyramid_Text_ExitHintRight6::
	.string "{RIGHT_ARROW} retning.$"

BattlePyramid_Text_ExitHintDown6::
	.string "Udgangen er tilfældigvis i {DOWN_ARROW} retning.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Er du på udkig efter genstande?\p"
	.string "Der er otte genstande tilbage som skal\n"
	.string "findes.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Leder du efter ting?\p"
	.string "Der er syv ting tilbage at finde.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Er du på jagt efter genstande?\p"
	.string "Der er seks genstande tilbage at finde.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Er du på jagt efter genstande?\p"
	.string "Der er fem genstande tilbage at finde.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Er du på jagt efter genstande?\p"
	.string "Der er fire genstande tilbage at finde.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Er du på udkig efter ting?\p"
	.string "Der er tre ting tilbage at finde.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Er du på udkig efter genstande?\p"
	.string "Der er to genstande tilbage at finde.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Er du på udkig efter genstande?\p"
	.string "Der er én genstand tilbage som skal\n"
	.string "findes.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Er du på udkig efter ting?\p"
	.string "Der er ikke mere tilbage at finde!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Fordi du vandt, vil jeg fortælle dig en\n"
	.string "lille hemmelighed!\p"
	.string "Der er otte genstande spredt omkring\n"
	.string "her.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Fordi du vandt, vil jeg fortælle dig en\n"
	.string "lille hemmelighed!\p"
	.string "Der er syv genstande tilbage\n"
	.string "heromkring.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Fordi du vandt, vil jeg fortælle dig en\n"
	.string "lille hemmelighed!\p"
	.string "Der er seks genstande tilbage\n"
	.string "heromkring.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Fordi du vandt, vil jeg fortælle dig en\n"
	.string "lille hemmelighed!\p"
	.string "Der er fem genstande tilbage\n"
	.string "heromkring.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Fordi du vandt, vil jeg fortælle dig en\n"
	.string "lille hemmelighed!\p"
	.string "Der er fire genstande tilbage der ligger\n"
	.string "og flyder her.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Fordi du vandt, vil jeg fortælle dig en\n"
	.string "lille hemmelighed!\p"
	.string "Der er tre genstande tilbage her\n"
	.string "omkring.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Fordi du vandt, vil jeg fortælle dig en\n"
	.string "lille hemmelighed!\p"
	.string "Der er to genstande tilbage her\n"
	.string "omkring.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Fordi du vandt, vil jeg fortælle dig en\n"
	.string "lille hemmelighed!\p"
	.string "Der er bare et stykke omkring her.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Fordi du vandt, vil jeg fortælledig en\n"
	.string "lille hemmelighed!\p"
	.string "Der er ikke noget tilbage her.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Hvordan klarer dit lager af genstande\n"
	.string "sig?\p"
	.string "Jeg gætter på, at der er otte genstande\n"
	.string "tilbage som venter på at blive fundet på\l"
	.string "dette gulv.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Hvordan holder dit lager af genstande\n"
	.string "sig?\p"
	.string "Jeg tror der er syv genstande tilbage\n"
	.string "der skal findes på dette gulv.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Hvordan går det med dit lager af\n"
	.string "genstande?\p"
	.string "Jeg regner med, at der er seks\n"
	.string "genstande tilbage som venter på at\l"
	.string "blive fundet på dette niveau.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Hvordan går det med dine ting?\p"
	.string "Jeg tror, der er fem ting tilbage venter\n"
	.string "på at blive fundet på dette gulv.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Hvordan står det til med dit lager af\n"
	.string "genstande?\p"
	.string "Jeg regner med, at der er fire\n"
	.string "genstande tilbage som venter på at\l"
	.string "blive fundet på dette niveau.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Hvordan holder dit lager af genstande?\p"
	.string "Jeg gætter på, at der er tre genstande\n"
	.string "tilbage som venter på at blive fundet på\l"
	.string "dette niveau.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Hvordan ser det ud med dine varer?\p"
	.string "Jeg tror der er to varer tilbage på\n"
	.string "dette niveau, der mangler at blive\l"
	.string "fundet.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Hvordan står det til med dine varer?\p"
	.string "Jeg tror, der er kun ét item  tilbage,\n"
	.string "som mangler at blive fundet på dette\l"
	.string "niveau.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Hvordan går det med dit lager af ting?\p"
	.string "Jeg tror ikke, der er flere ting at finde\n"
	.string "på dette niveau. Pas nu på!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Du er stærk, så du har fortjent et hint!\p"
	.string "Der ser ud til at være otte flere\n"
	.string "genstande på jorden.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Du er stærk, så du har fortjent et hint!\p"
	.string "Der ser ud til at være syv mere\n"
	.string "genstande på jorden.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Du er stærk, så du har fortjent et hint!\p"
	.string "Der ser ud til at være seks flere\n"
	.string "genstande på jorden.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Du er stærk, så du har fortjent et hint!\p"
	.string "Der ser ud til at være fem flere\n"
	.string "genstande på jorden.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Du er stærk, så du har fortjent et hint!\p"
	.string "Der ser ud til at være fire flere\n"
	.string "genstande på jorden.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Du er stærk, så du har fortjent et hint!\p"
	.string "Der ser ud til at være tre flere\n"
	.string "genstande på jorden.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Du er stærk, så du har fortjent et hint!\p"
	.string "Der ser ud til at være to mere genstande\n"
	.string "på jorden.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Du er stærk, så du har fortjent et hint!\p"
	.string "Der ser ud til kun at være ét genstand\n"
	.string "tilbage på jorden.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Du er stærk, så du har fortjent et hint!\p"
	.string "Der synes ikke at være flere genstande\n"
	.string "på jorden.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "På dette gulv af PYRAMIDEN, Jeg hører,\n"
	.string "der er otte genstande…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "På dette niveau af PYRAMIDEN, hører\n"
	.string "jeg, at der er syv genstande…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "På dette niveau af PYRAMIDEN, hører\n"
	.string "jeg, at der er seks genstande…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "På dette niveau af PYRAMIDEN, hører\n"
	.string "jeg, at der er fem genstande…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "På dette niveau af PYRAMIDEN, hører\n"
	.string "jeg, at der er fire genstande...$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "På dette niveau af PYRAMIDEN, hører\n"
	.string "jeg, at der er tre genstande…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "På dette niveau af PYRAMIDEN, hører\n"
	.string "jeg, at der er to genstande…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "På dette niveau af PYRAMIDEN, hører\n"
	.string "jeg, at der er ét emne…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "På dette niveau af PYRAMIDEN, hører\n"
	.string "jeg, at der ikke er nogen genstande…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Har du samlet nogen genstande?\p"
	.string "Jeg tror, der er otte ting mere på dette\n"
	.string "niveau.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Har du samlet nogen genstande?\p"
	.string "Jeg tror der er syv ting mere på dette\n"
	.string "niveau.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Har du samlet nogen genstande?\p"
	.string "Jeg tror, der er seks ting mere på dette\n"
	.string "niveau.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Har du samlet nogle genstande?\p"
	.string "Jeg tror, der er fem ting mere på dette\n"
	.string "niveau.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Har du samlet nogen ting op?\p"
	.string "Jeg tror, der er fire ting mere på dette\n"
	.string "niveau.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Har du samlet nogen ting op?\p"
	.string "Jeg tror, der er tre ting mere på dette\n"
	.string "niveau.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Har du samlet nogen ting?\p"
	.string "Jeg tror, der er to ting mere på dette\n"
	.string "niveau.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Har du samlet nogen ting?\p"
	.string "Jeg tror der er én ting mere på dette\n"
	.string "niveau.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Har du samlet nogen genstande?\p"
	.string "Jeg tror ikke, der er flere ting på dette\n"
	.string "niveau.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Du var virkelig fantastisk!\p"
	.string "Men der er stadig syv hårde TRÆNERE\n"
	.string "udover mig!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Du var virkelig fantastisk!\p"
	.string "Men der er stadig seks seje TRÆNERE\n"
	.string "udover mig!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Du var virkelig fantastisk!\p"
	.string "Men der er stadig fem hårde TRÆNERE\n"
	.string "udover mig!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Du var virkelig fantastisk!\p"
	.string "Men der er stadig fire seje TRÆNERE\n"
	.string "udover mig!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Du var virkelig fantastisk!\p"
	.string "Men der er stadig tre seje TRÆNERE\n"
	.string "udover mig!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Du var virkelig fantastisk!\p"
	.string "Men der er stadig to seje  TRÆNERE\n"
	.string "udover mig!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Du var virkelig fantastisk!\p"
	.string "Men der er stadig en sej TRÆNER udover\n"
	.string "mig!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Du var virkelig fantastisk!\p"
	.string "Der er ingen tilbage, som kan slå dig!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "Det er så frustrerende!\p"
	.string "Men der er syv TRÆNERE tilbage! Nogen\n"
	.string "vil ydmyge dig!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "Det er så ærgerligt!\p"
	.string "Men der er seks TRÆNERE tilbage! Nogen\n"
	.string "vil ydmyge dig!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "Det her er så ødelæggende!\p"
	.string "Men der er fem TRÆNERE tilbage! Nogen\n"
	.string "vil ydmyge dig!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "Det er så forfærdeligt!\p"
	.string "Men der er fire TRÆNERE tilbage! Nogen\n"
	.string "vil ydmyge dig!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "Det er så ærgerligt!\p"
	.string "Men der er tre TRÆNERE tilbage! Nogen\n"
	.string "vil ydmyge dig!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "Det er så ærgerligt!\p"
	.string "Men der er to TRÆNERE tilbage! Nogen vil\n"
	.string "ydmyge dig!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "Det her er så ærgerligt!\p"
	.string "Men der er en TRÆNER tilbage! Jeg er\n"
	.string "sikker på, du vil blive ydmyget!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "Det er så frustrerende!\p"
	.string "Men der er ingen flere TRÆNERE der kan\n"
	.string "udfordre dig!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "Det er ret imponerende!\p"
	.string "Men der er syv flere TRÆNERE på dette\n"
	.string "niveau. Kan du slå dem alle?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "Det er ret imponerende!\p"
	.string "Men der er seks flere TRÆNERE på dette\n"
	.string "gulv. Kan du slå dem alle?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "Det er ret imponerende!\p"
	.string "Men der er fem flere TRÆNERE på dette\n"
	.string "niveau. Kan du slå dem alle?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "Det er ret imponerende!\p"
	.string "Men der er fire mere TRÆNERE på dette\n"
	.string "niveau. Kan du slå dem alle?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "Det er ret imponerende!\p"
	.string "Men der er tre FLERE TRÆNERE på dette\n"
	.string "niveau. Kan du slå dem alle?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "Det er ret imponerende!\p"
	.string "Men der er to flere TRÆNERE på dette\n"
	.string "niveau. Kan du slå dem begge?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "Det er ret imponerende!\p"
	.string "Men der er stadig en TRÆNER tilbage på\n"
	.string "dette niveau. Kan du vinde?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "Det er ret imponerende!\p"
	.string "Du har klaret alle TRÆNERE på dette\n"
	.string "niveau.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Måske kan du feje gennem de SYV\n"
	.string "TRÆNERE tilbage på dette gulv.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Måske kunne du feje gennem de seks\n"
	.string "TRÆNERE tilbage på dette gulv.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Måske du kunne feje gennem de fem\n"
	.string "TRÆNERE tilbage på dette  gulv.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Måske kan du feje gennem de fire\n"
	.string "TRÆNERE tilbage på dette etageplan.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Måske kan du feje gennem de tre\n"
	.string "TRÆNERE tilbage på dette gulv.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Måske kan du feje gennem de to TRÆNERE\n"
	.string "tilbage på dette niveau.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Måske kan du fuldføre din runde med den\n"
	.string "ene TRÆNER tilbage på dette gulv.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Der er ikke en eneste person tilbage,\n"
	.string "der kan besejre dig nu…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Du har måske hvad der skal til for at slå\n"
	.string "de syv eksperter TRÆNERE, der er\l"
	.string "tilbage.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Du har måske, hvad der skal til for at\n"
	.string "slå de seks dygtige TRÆNERE, der er\l"
	.string "tilbage.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Du har måske hvad der skal til for at slå\n"
	.string "de fem ekspertTRÆNERE der er tilbage.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Du har måske, hvad der skal til, for at\n"
	.string "slå de fire ekspertTRÆNERE, der er\l"
	.string "tilbage.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Du har måske hvad der skal til for at slå\n"
	.string "de tre ekspertrænere, der er tilbage.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Du har måske, hvad der skal til for at\n"
	.string "besejre de to eksperttrænere, der er\l"
	.string "tilbage.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Du har måske, hvad der skal til for at\n"
	.string "slå den eneste eksperttræner, der er\l"
	.string "tilbage.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Dine færdigheder er uden forbehold.\p"
	.string "Der er ikke flere TRÆNERE her der har en\n"
	.string "chance for at slå dig.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Kan du blive ved med at vinde mod de syv\n"
	.string "tilbageværende TRÆNERE?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Kan du blive ved med at vinde imod de\n"
	.string "seks tilbageværende TRÆNERE?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Kan du blive ved med at vinde mod de fem\n"
	.string "tilbageværende TRÆNERE?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Kan du blive ved med at vinde mod de\n"
	.string "fire tilbageværende TRÆNERE?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Kan du blive ved med at vinde mod de tre\n"
	.string "tilbageværende TRÆNERE?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Kan du blive ved med at vinde mod de to\n"
	.string "tilbageværende TRÆNERE?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Kan du blive ved med at vinde mod den\n"
	.string "sidste tilbageværende TRÆNER?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Der er ikke flere TRÆNERE tilbage, der\n"
	.string "kan udfordre dig lige nu…$"



