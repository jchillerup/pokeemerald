@ TRANSLATED

BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "Du kunne ikke gætte det ved at kigge på\n"
	.string "mig nu, men jeg var engang en sej TRÆNER.\p"
	.string "Jeg havde ry for at være den sejeste\n"
	.string "SKØNHED, jeg lover!\p"
	.string "… … … … … …\p"
	.string "Hvad er det nu? Tror du mig ikke.\p"
	.string "Jeg er ikke som den blærerøv af en\n"
	.string "kvinde derovre. Jeg er faktisk\l"
	.string "talentfuld!\p"
	.string "Lad mig bevise det for dig. Jeg kan lære\n"
	.string "dine POKéMON specielle og alligevel søde\l"
	.string "angreb.\p"
	.string "Men mine lektioner er ikke gratis. Hvad\n"
	.string "med at betale for de angreb jeg lærer dig\l"
	.string "med en smule Kamp Point?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Er du tilbage for at lære specielle og\n"
	.string "søde POKéMON-moves?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Fint, fint, se her! Hvilket træk skal jeg\n"
	.string "lære dig?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "Det træk {STR_VAR_1}, er det?\n"
	.string "{STR_VAR_2} Kamp Point, i orden?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Okay, okay, vælg nu POKéMON'en Jeg\n"
	.string "burde lære trækket til.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Hvad i… Du har ikke nok Kamp Point!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Kan du se, hvor dygtig jeg er nu? Jeg\n"
	.string "tager lige dine Kamp Point, tak!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Hvad er det? Du vil ikke…\p"
	.string "Hvis du vil se, hvor dygtig jeg er, så kom\n"
	.string "og besøg mig når som helst!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "Jeg ved, det er svært at se lige nu, men\n"
	.string "jeg var en fantastisk TRÆNER engang.\p"
	.string "Jeg havde ry som den mest\n"
	.string "uovervindelige SVØMMER, kan jeg\l"
	.string "fortælle dig!\p"
	.string "… … … … … …\p"
	.string "Hvad er der galt? Tror du ikke på mig.\p"
	.string "Jeg er ikke som den tåbelige kvinde\n"
	.string "dernede. Jeg har faktisk erfaring!\p"
	.string "Jeg kan bevise det for dig. Jeg kan lære\n"
	.string "dine POKéMON stærke og smukke angreb.\p"
	.string "Men mine lektioner er ikke gratis. Hvad\n"
	.string "med at betale for de angreb, jeg lærer\l"
	.string "dig, med en smule Kamp Point?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Er du kommet for at lære hårde og\n"
	.string "alligevel smukke POKéMON-tricks?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "De damer, måden de bagtaler hinanden\n"
	.string "på, får dig måske til at tro, at de ikke\l"
	.string "kan lide hinanden.\p"
	.string "Men hvis det var sandt, ville de vel ikke\n"
	.string "blive sammen herude,  ville de?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Da jeg var bare en lille KNÆGT, var de\n"
	.string "damer stærke og smukke.\p"
	.string "De var idoler blandt os TRÆNERE.\p"
	.string "Selv nu har alderen ikke sløvet deres\n"
	.string "evner.\p"
	.string "Faktisk er deres POKéMON-angreb\n"
	.string "blevet endnu mere raffinerede.\p"
	.string "Men... af en eller anden grund kan jeg\n"
	.string "ikke lade være med at føle dette...\p"
	.string "Tiden er så nådesløs...$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Gendanner op til halvdelen af brugerens\n"
	.string "maksimale HP.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Påfører skade identisk med brugerens\n"
	.string "niveau.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Gendanner halvdelen af skaden påført\n"
	.string "en sovende fjende.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Et stærkt slag kastet med utrolig\n"
	.string "kraft.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "En ekstremt kraftfuld spark med intens\n"
	.string "kraft.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Et fuldt kropsslam som kan forårsage\n"
	.string "lammelse.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Store sten bliver kastet. Kan få dig til\n"
	.string "at blive forskrækket.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Gengælder enhver fysisk angreb med\n"
	.string "dobbelt kraft.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "En svag stød af elektricitet, der lammer\n"
	.string "fjenden.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "En kampdans der skarpt øger ANGREBET.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Krøller sig sammen for at skjule svage\n"
	.string "punkter og hæve FORSVARET.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Et højt angreb som kun kan bruges mens\n"
	.string "man sover.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Kaster mudder i fjendens ansigt for at\n"
	.string "nedsætte dens præcision.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Sprøjter stjerne- formede stråler som\n"
	.string "aldrig rammer.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Et isnende angreb som sænker fjendens\n"
	.string "HASTIGHED.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Holder til hvilken- somhelst angreb i 1\n"
	.string "tur, efterlader 1HP.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Kopierer modstanderens effekt(er) og\n"
	.string "giver til brugeren.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "En iskold slag der kan fryse fjenden.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "En elektrificeret punch, der kan lamme\n"
	.string "modstanderen.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "En flammende knytnæve der måske kan\n"
	.string "brænde fjenden.$"



