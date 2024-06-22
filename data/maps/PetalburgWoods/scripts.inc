@ TRANSLATED

.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4

PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmm... Ikke en eneste at finde...$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Hej, har du set en POKéMON ved navn\n"
	.string "SHROOMISH her omkring?\p"
	.string "Jeg er virkelig vild med den POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Jeg var ved at lægge en baghold til dig, men du\n"
	.string "skulle slæbe rundt i PETALBURG SKOV for\l"
	.string "evigt, gjorde du ikke?\p"
	.string "Jeg blev træt af at vente, så her er jeg!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Du! DEVON-FORSKER!\p"
	.string "Aflever de papirer!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aiyeeeh!\p"
	.string "Du er en POKéMON TRÆNER, ikke sandt? Du er\n"
	.string "nødt til at hjælpe mig, vær sød!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:

	.string "Hvad laver du?\n"
	.string "Vil du beskytte ham?\p"
	.string "Ingen, der krydser TEAM AQUA\n"
	.string "får nogen nåde, ikke engang et barn!\p"
	.string "Kom så og kæmp mod mig!$"

PetalburgWoods_Text_YoureKiddingMe:
.string "Du må da tage mig! Du er sej!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Du har godt nok noget nervøsitet ved\n"
	.string "at blande dig med TEAM AQUA! Kom så og kæmp\l"
	.string "mod mig igen!\p"
	.string "Jeg ville ønske, jeg kunne sige det, men jeg\n"
	.string "er ude af POKéMON…\p"
	.string "Og hey, vi fra TEAM AQUA er også ude efter\n"
	.string "noget i RUSTBORO.\p"
	.string "Jeg lader dig gå i dag!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Puha...  Det var godt nok tæt på!\p"
	.string "Takket være dig, stjal han ikke disse\n"
	.string "vigtige papirer fra mig.\p"
	.string "Jeg ved det! Jeg vil give dig en FANTASTISK\n"
	.string "BOLD som tak!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Sagde den TEAM AQUA skurk ikke, at de var\n"
	.string "ude efter noget i RUSTBORO også?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Åh nej! Det er en krise! Jeg kan ikke spilde\n"
	.string "tid!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Du er fyldt med genstande. Jeg kan ikke give\n"
	.string "dig denne STORE BOLD.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Jeg har fanget en hel flok POKéMON! \p"
	.string "Kom så, kom så, kom så!  Mit INSEKT-POKéMON\n"
	.string "hold!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Jeg har alle disse POKéMON, men jeg kunne\n"
	.string "ikke vinde…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Jeg har fanget en masse POKéMON. Nu er jeg\n"
	.string "løbet tør for POKé BALLS.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Hvis du tager en BUG POKéMON med til skole,\n"
	.string "bliver du øjeblikkeligt populær!$"

PetalburgWoods_Text_CantBePopularIfILose:
.string "Jeg kan ikke være populær, hvis jeg taber.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Hvis du har en stor BILLE POKéMON,\n"
	.string "respekterer folk dig for det.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Jeg vil have en revanche, når min POKéMON\n"
	.string "vokser op!\p"
	.string "Jeg registrerer dig i min POKéNAV!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Jeg vil have en revanchekamp,  når min\n"
	.string "POKéMON vokser op!\p"
	.string "Jeg registrerer dig i min POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Mine BILLEDPAR POKéMON er vokset. Jeg vil\n"
	.string "være populær igen.$"

PetalburgWoods_Text_CantBePopularIfLose:
.string "Jeg kan ikke være populær, hvis jeg taber.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Man bliver populær, hvis man har stærke\n"
	.string "POKéMON, ikke sandt?\p"
	.string "Så jeg har trænet hårdt.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Hej med dig! Er dine POKéMON okay?\p"
	.string "Hvis dine POKéMON er svage og du vil undgå\n"
	.string "kampe, bør du blive ude af højt græs.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Nogle gange er der ting på jorden, selvom du\n"
	.string "ikke kan se dem.\p"
	.string "Derfor checker jeg altid, hvor jeg går.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Åh, sejt! Det er BADGET fra RUSTBORO GYM!\p"
	.string "Du må være en TRÆNER. Du burde prøve at\n"
	.string "bruge dette item.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "Det er et MIRAKELFRØ. Hvis en POKéMON har\n"
	.string "det item, bliver dens GRÆS-type angreb\l"
	.string "stærkere.\p"
	.string "Udover MIRAKELFRØ, tror jeg der er andre\n"
	.string "praktiske items for POKéMON at holde.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "TRÆNER TIPS\p"
	.string "Enhver POKéMON, der dukker op blot én\p"
	.string "gang i en kamp, får tildelt EXP Point.\p"
	.string "For at styrke en svag POKéMON, skal\p"
	.string "du placere den yderst til venstre på\p"
	.string "holdsammensætningen.\p"
	.string "Så snart kampen begynder, skal du\p"
	.string "skifte den ud. Den vil optjene EXP\p"
	.string "Point uden at blive udsat for nogen skade.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "TRÆNERTIPS\p"
	.string "Udover Hit Points (HP) har POKéMON også\n"
	.string "Power Points (PP), der bruges til at udføre\l"
	.string "angreb under slaget.\p"
	.string "Hvis en POKéMON løber tør for PP, skal den\n"
	.string "tages til et POKéMON CENTER.$"



