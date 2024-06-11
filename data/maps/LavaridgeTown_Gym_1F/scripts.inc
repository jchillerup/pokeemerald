@ TRANSLATED

.set LOCALID_COLE, 2
.set LOCALID_GERALD, 3
.set LOCALID_AXLE, 4
.set LOCALID_DANIELLE, 5

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Hej, hvordan går det, CHAMPION-\n"
	.string "bundet {PLAYER}?\p"
	.string "LAVARIDGE's GYM LEADER FLANNERY\n"
	.string "bruger BRAND-typer POKéMON.\p"
	.string "Hendes lidenskab for POKéMON brænder\n"
	.string "stærkere og varmere end en vulkan.\p"
	.string "Kom ikke for tæt på hende--du vil\n"
	.string "blive brændt!\n"
	.string "Sprøjt hende med vand og så\l"
	.string "af sted!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
.string "Aj! Det var en brændvarm kamp!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Avavavav!\n"
	.string "Åh nej, det er varmt!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
.string "Jeg er blændet af sved i mine øjne…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "At blive begravet i varm sand fremmer\n"
	.string "cirkulationen.\p"
	.string "Det er effektivt til at lindre smerter i\n"
	.string "dine led.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Jeg prøver at lette min stress.\n"
	.string "Kom ikke og stress mig ud!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
.string "Jeg håber FLANNERY fakler dig godt!\p$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Puha… Puhh…\p"
	.string "Hvis du tilbringer for meget tid begravet i\n"
	.string "varm sand, tager det pusten fra dig…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Du må være træt ved nu.\n"
	.string "Du kunne godt tænke dig at hvile dig i den varme sand,\l"
	.string "ikke sandt?\p"
	.string "Men du bør vide, at at opretholde\n"
	.string "din viljestyrke er en vigtig evne\l"
	.string "for alle TRÆNERE.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
.string "Leg med ilden, og bliv brændt…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Din kunnen er ægte...\n"
	.string "Men vores LEDER FLANNERY er stærk.\p"
	.string "Hvis du ikke passer på, vil du blive\n"
	.string "alvorligt brændt.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Kan dine POKéMON klare\n"
	.string "392 graders varme?\p$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Det brændte ikke varmt nok…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "Temperaturen af magma er\n"
	.string "392 grader.\p"
	.string "Dine POKéMON besejrede mig, så de\n"
	.string "bør nemt overleve i magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Øh…\n"
	.string "Okay, jeg vil kæmpe med dig.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Åh, men du er for stærk.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Jeg vil være en smuk og stærk\n"
	.string "TRÆNER ligesom FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Kom nu, kom igang!\n"
	.string "Lad os komme afsted, før mine følelser køler ned!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Det er så varmt, og alligevel er\n"
	.string "mit hjerte grebet af is…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Den måde din kampånd brænder\n"
	.string "inden i dig, giver dig en\n"
	.string "chance imod vores LEDER.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Se, hvordan flammerne blafrer vildt?\n"
	.string "De flammer i spænding over min sejr!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
.string "Noget gik galt.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Nå, og hvad så? Jeg siger hvad så?\n"
	.string "Jeg kan gå på varme kul uden sko! \p"
	.string "…Lad være med engang at prøve det!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Selvom jeg elsker bjerge,\n"
	.string "så elsker jeg især vulkaner.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Nåh, det ser ud til, at jeg tabte uden\n"
	.string "nogensinde at have kontrol.$" 

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Jeg bliver her, fordi jeg er blevet en fan\n"
	.string "af FLANNERY's kræfter.\p"
	.string "Hihihihi.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Velkommen… Nej vent.\p"
	.string "Pjankede TRÆNER, hvor godt at se\n"
	.string "du har fundet vej hertil!\p"
	.string "Jeg er blevet betroet opgaven med…\n"
	.string "Nej, vent.\p"
	.string "Jeg er FLANNERY, og jeg er GYM-\n"
	.string "LEDEREN her!\p"
	.string "Øh…\n"
	.string "Våg ikke at undervurdere mig, selv\l"
	.string "om jeg kun har været LEDER en kort tid!\p"
	.string "Med evner arvet fra min bedstefar\l"
	.string "skal jeg, øh…demonstrere de\n"
	.string "varme træk, vi har finpudset på denne jord!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Åh…\n"
	.string "Jeg gætter på, jeg prøvede for hårdt…\p"
	.string "Jeg… Jeg er kun blevet\n"
	.string "en GYMLEDERSmart way to avoid gross\n"
	.string "Californian food coma.\p"
	.string "Is angst the gyms stereotypical vibe,\n"
	.string "majestic sorrow holds the real key.\p"
	.string "Vi må lade naturen gå sin gang, ellers\n"
	.string "bliver mine POKéMON forvirrede.\p"
	.string "Tak for at lære mig det.\n"
	.string "For det fortjener du dette.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} modtog VARMEBADGE\n"
	.string "fra FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Hvis du har et VARME MÆRKE, vil alle\n"
	.string "POKéMON op til Level 50, selv dem du\n"
	.string "får i byttehandeler fra andre mennesker,\l"
	.string "lyde dig fuldstændigt.\p"
	.string "Og det giver POKéMON mulighed for at\n"
	.string "bruge HM-trækket STYRKE uden for kamp.\p"
	.string "Dette er et tegn på min taknemmelighed.\n"
	.string "Vær ikke genert, tag det med dig!$" 

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "Den TM50 indeholder OVERHEAT.\p"
	.string "Denne move påfører alvorlig skade på\n"
	.string "modstanderen.\p"
	.string "Men den reducerer også kraftigt SP. ATK\n"
	.string "for POKéMON'et, der bruger den. Det\n"
	.string "er måske ikke egnet til længere kampe.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Registreret GYM-LEDERSKAB FLANNERY\n"
	.string "i POKéNAVen.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Din kraft minder mig om en person…\p"
	.string "Åh! Jeg ved det! Du kæmper som NORMAN,\n"
	.string "PETALBURGs GYM-LEDER.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
.string "LAVARIDGE TOWN POKéMON GYM$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "LAVARIDGE BY POKéMON GYM\p"
	.string "FLANNERY'S GODKENDETE TRÆNERE:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY: At tabe en kamp får ikke\n"
	.string "mig til at blive nedtrykt.\p"
	.string "Jeg elsker POKéMON.\n"
	.string "Jeg elsker at kæmpe.\l"
	.string "Og… Jeg elsker dette GYM!\p"
	.string " Lad os udveksle superhotte\n"
	.string "træk i en ny kamp!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Puha!\n"
	.string "Lige ved at eksplodere!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY: Jeg tabte kampen,\n"
	.string "men jeg er helt tilfreds.\p"
	.string "Det er ikke ofte, jeg får lov\ntil at nyde en kamp\n"
	.string "så intens som denne.\p"
	.string "Lad os have en\nanden kamp som denne\n"
	.string "igen en anden gang!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY: At tabe en kamp vil ikke\n"
	.string "slå mig ud.\p"
	.string "Jeg elsker POKéMON.\n"
	.string "Jeg elsker at kæmpe.\l"
	.string "Og... Jeg elsker dette GYM!\p"
	.string "Lad os bytte superhotte træk\n"
	.string "i endnu en kamp!\p"
	.string "Åh, vent. Har du kun én POKéMON\n"
	.string "der kan kæmpe?\p"
	.string "Jeg hader at sige det, men når du\n"
	.string "besøger mig, så tag mindst to POKéMON.$"

