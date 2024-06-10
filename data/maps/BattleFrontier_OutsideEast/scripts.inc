@ TRANSLATED

.set LOCALID_SUDOWOODO, 14

BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "Dette er KAMP-TÅRNET!\n"
	.string "Hold sejrsstimen som den sejeste \l"
	.string "TRÆNER!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "Dette er KAMP PALADSET!\n"
	.string "Hold øje med POKéMON kampe!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "Dette er KAMPARENEN!\n" 
	.string "Lad de sejeste hold samles!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "Dette er KAMPPIRAMIDEN!\n"
	.string "Fortsæt gennem Kampopgaven!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "KAMPFRONTIER-RANGERINGSHALLEN\n"
	.string "Sæt kurs mod nye rekorder!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "KAMPPOINT UDVEKSLINGSTJENESTE HJØRNE\n"
	.string "Udveksl dine KampPoint!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Wow!\n"
	.string "Det er kæmpestort!\p"
	.string "KAMP-TÅRNET føles specielt.\n"
	.string "Det er anderledes end de andre.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Min store ambition er at erobre både\n"
	.string "BATTLE FRONTIER og POKéMON\l"
	.string "LEAGUE.\p"
	.string "Og hvis min drøm går i opfyldelse…\p"
	.string "Så vil jeg… jeg spørger MIMI\n"
	.string "næste dør, om hun vil være venner\n"
	.string "med mig!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "BATTLE PYRAMIDEN er for barsk!\n"
	.string "Jeg kan bare ikke nå toppen!\p"
	.string "Nu hvor jeg er løbet tør for muligheder,\n"
	.string "kan jeg måske prøve at klatre udenpå…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Jeg trives i mørket…\n"
	.string "Ja… Hvad er værdigt for mig?\l"
	.string "Intet andet end KAMP PYRAMIDEN…\p"
	.string "Hvad siger du til at vandre i mørket\n"
	.string "og i fuldstændig og total desperation?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Jeg har ikke sovet i en uge, men så\n"
	.string "samlede jeg det ultimative hold!\p"
	.string "Jeg kan ikke forestille mig at tabe, ingen joke.\n"
	.string "Vi stormer KAMPARENEN!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "Har SCOTT også bragt dig herhen?\n"
	.string "Hvad er det med den fyr?\p"
	.string "Det lyder som om, at han virkelig\n"
	.string "ved, hvordan man spotter talentfulde\n"
	.string "TRÆNERE, men...\p"
	.string "Jeg har aldrig set ham kæmpe i\n"
	.string "person nogensinde.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "Svip!\n"
	.string "Jeg tror på dig, lille ven!\p"
	.string "Jeg laver alle dine yndlings\n"
	.string "lækre godbider, hvis du vinder!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
.string "Zigzagoon ser tom ud…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Folk kalder mig en nysgerrigper,\n"
	.string "men jeg kan ikke lade være.\p"
	.string "Din hat er skæv!\n"
	.string "Åh nej, affald på jorden!\l"
	.string "Ups, det er næsten spisetid!\p"
	.string "Jeg ved ikke, om jeg kan holde\n"
	.string "mig bare til at se på KAMPALLET…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Jeg ser måske ikke så imponerende ud nu,\n"
	.string "men jeg har engang slået en GYM LEDER.\p"
	.string "Hvem ved, måske skulle jeg prøve\n"
	.string "igen for at få lidt ære.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Jeg er hurtig på min CYKEL, og det gælder\n"
	.string "også for den måde, jeg kæmper på.\p"
	.string "Jeg vinder kampe på et øjebliks\n"
	.string "næsten!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Jeg er bedre end min far\n"
	.string "til POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Kom så, min skattemus!\n"
	.string "Luk nogle sejre ned for Far!\p"
	.string "Du er ligesom din mor,\n"
	.string "så du vil dominere!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Det var ikke nemt at komme herhen,\n"
	.string "men jeg havde hørt om den smukke\l"
	.string "pige på KAMPARENAEN.\p"
	.string "I stedet for hende, ved du hvad\n"
	.string "jeg fandt?\p"
	.string "En hel myriade af svedige,\n"
	.string "stinkende og primitive kampsportsudøvere!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "Jeg ser nogle gange denne virkelig vigtige-\n"
	.string "udseende gamle mand gå derind.\p"
	.string "Han har disse virkelig fantastiske POKéMON.\n"
	.string "Han virker dog virkelig rar.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Kender du den?\n"
	.string "Legenden om KAMPPIRAMIDEN?\p"
	.string "Når en selvsikker TRÆNER\n"
	.string "stræber efter den gyldne tinde,\l"
	.string "vil der vise sig en mand blandt mænd.\p"
	.string "Kender du ikke den legende?\n"
	.string "Nå, det er klart!\l"
	.string "Jeg fandt bare på den!\p"
	.string "Hvad betyder den?\n"
	.string "Det kan jeg desværre ikke sige!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Mand! Åh mand!\n"
	.string "Jeg har aldrig tabt før!\p"
	.string "Men jeg blev helt udryddet uden\n"
	.string "nogen nåde overhovedet!\p"
	.string "Og så får jeg at vide, at jeg\n"
	.string "ikke har nogen talent?! Mand!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Denne fyr løb ind i en forfærdeligt\n"
	.string "sej TRÆNER, mens han var på BATTLE\l"
	.string "TOWER-udfordringen.\p"
	.string "Nu ser du ham... \p"
	.string "Du skal være forsigtig, hvis du nogensinde\n"
	.string "beslutter dig for at tage til BATTLE TOWER.$"  

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Ja!\n"
	.string "Jeg har endelig nok Kamp Point!\p"
	.string "Jeg gætter på, at jeg vil bytte til en\n"
	.string "anden kæmpe BAMSE!\p$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Åh, ja, okay!\n"
	.string "Så dette er RANGERINGSSALEN!\p"
	.string "Jeg vil gerne gå ned i historien\n"
	.string "som en supermester og have mit\n"
	.string "navn optaget her for eftertiden.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
.string "Med dig ved min side, kan jeg gøre hvad som helst.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Åh, skat, du er så fantastisk!\p"
	.string "Åh, jeg kan simpelthen ikke vente mere!\p"
	.string "Lad os gå til en MULTI BATTLE ROOM\n"
	.string "lige her og nu!\p"
	.string "Hvis vi samles i BATTLE SALONEN,\n"
	.string "vil kraften af vores kærlighed overvinde\l"
	.string "alle vi møder.\p"
	.string "Ja, skat, foran os vil alt\n"
	.string "vælte som dominobrikker!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "Kampfronten er ikke kun for seje TRÆNERE.\n"
	.string "Det ser ud til, at mange personer med\n"
	.string "særlige evner er blevet inviteret.\p"
	.string "Den mand SCOTT…\p"
	.string "Han har måske opført dette sted for at\n"
	.string "tjene et større formål…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Undskyld mig, lille ven.\n"
	.string "Har du godt syn?\p"
	.string "Der er et underligt træ længere\n"
	.string "herfra, og for mine trætte øjne\n"
	.string "ser det ud til at bevæge sig.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Undskyld, du unge.\n"
	.string "Har du en god hukommelse?\p"
	.string "Jeg har denne følelse, at der engang\n"
	.string "var et mærkeligt træ her.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Jeg...\n"
	.string "Jeg så det!\p"
	.string "Der var en klæbrig slags POKéMON\n"
	.string "med en lang hale længere fremme!\p"
	.string "Den gemte sig under en sten, og\n"
	.string "den stirrede på mig hele tiden!$"

