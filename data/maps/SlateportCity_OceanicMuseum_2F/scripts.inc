@ TRANSLATED

.set LOCALID_CAPT_STERN, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_GRUNT_1, 3
.set LOCALID_GRUNT_2, 4

SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_GRUNT_1
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_GRUNT_2
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_ARCHIE
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Ja? Hvis du leder efter STERN,\n"
	.string "så er det mig.\p"
	.string "Åh! Det må være de dele, jeg bestilte\n"
	.string "fra HR. STONE fra DEVON.\p"
	.string "Tak! Det er fantastisk!\n"
	.string "Nu kan vi forberede os til vores ekspedition.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Hihihi, vent lige!\n"
	.string "Vi tager de dele!\p$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "Hvem er I folk?\n"
	.string "Jeg kan ikke forstå det.$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Vi er TEAM AQUA!\p"
	.string "Vores BOSS vil have de der dele!\n"
	.string "Hold din kæft og giv dem til os!$" 

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Åååh!\n"
	.string "Et barn slog mig!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Åh nej, sikke en katastrofe…\n"
	.string "BOSS'en bliver rasende…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Humph, ynkelig skvat!\n"
	.string "Lad mig klare det!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Hvad?!\n"
	.string "Jeg tabte også!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Hvad nu? Hvis vi ikke får delene,\n"
	.string "er vi på den!\p"
	.string "Arrgh, jeg havde ikke regnet med at blive\n"
	.string "blandet ind af en irriterende unge!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Jeg kom for at se hvad der tog så\n"
	.string "lang tid at skaffe nogle dele, og I\l"
	.string "simpler bliver holdt op af et barn?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Vi er TEAM AQUA,\n"
	.string "og vi elsker havet!\p"
	.string "Og jeg er TEAM AQUAs leder,\n"
	.string "ARCHIE!\p"
	.string "Hvorfor blander du dig i vores sager?\p"
	.string "…Nej! Du kan ikke være!\n"
	.string "Du er ikke en del af TEAM MAGMA?\p"
	.string "Vent, det kan ikke være rigtigt.\n"
	.string "Du er ikke klædt passende på.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, mennesker… Alt liv afhænger af\n"
	.string "havet.\p"
	.string "Så, TEAM AQUA dedikerer sig til\n"
	.string "at udvide havet.\p"
	.string "Er du ikke enig? Hvad vi gør\n"
	.string "er en storslået bedrift.\p"
	.string "Nå, så fint…\n"
	.string "Du er stadig for ung til at forstå\l"
	.string "vores ædle mål.\p"
	.string "Men jeg advarer dig, overvej ikke\p"
	.string "at blande dig i vores planer igen.\p"
	.string "Konsekvenserne vil koste dig\n"
	.string "dyrt!\p"
	.string "Og glem det ikke!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "KAPT. STERN: Du er…\n"
	.string "Åh, okay, du er {PLAYER}{KUN}…\p"
	.string "Uanset, det var en spændt situation!\n"
	.string "Tak for at redde os!\p"
	.string "Åh ja, jeg glemte næsten at du\n"
	.string "endda bragte dele fra DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "KAPT. STERN: Ups!\n"
	.string "Der er ingen tid at spilde!\p"
	.string "Vi skal afsted på vores ekspedition\n"
	.string "til havets bund rigtig snart.\p"
	.string "Tak igen, men nu må jeg gå!\p"
	.string "Du er velkommen til at udforske og\n"
	.string "se vores faciliteter.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "Jeg så en model af et skib her.\p"
	.string "Det mindede mig om DET FORLADTE SKIB\n"
	.string "nær DEWFORD BY…$"  

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "Løb ikke rundt inde\n"
	.string "i MUSEET!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Wow, ubåden er fantastisk!\n"
	.string "Jeg vil gerne en tur!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "“VANDKVALITETS PRØVE 1,” står der på\n"
	.string "etiketten.\p"
	.string "Havet er alt sammen forbundet, men\n"
	.string "vandet synes at variere efter region.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "“VANDKVALITETS PRØVE 2,” står der\n"
	.string "på etiketten.\p"
	.string "Er havvandets saltighed forskellig\n"
	.string "fra region til region, også?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "En gummibold udvider sig og\n"
	.string "skrumper.\p"
	.string "“I havet udøver vandets egenvægt\n"
	.string "tryk.\p"
	.string "“I lavt vand er trykket ikke særlig\n"
	.string "stort.\p"
	.string "“Dog, i ekstremt dybt vand, kan\n"
	.string "trykket nå op på endda titusindvis af\l"
	.string "ton på et lille område.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“MODEL AF HOENN REGIONEN”\p"
	.string "Det er en miniature diorama af\n"
	.string "HOENN regionen.\p"
	.string "Hvor er LITTLEROOT BYEN på dette?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "Det er en skærm om strømmen af \n"
	.string "havvand.\p"
	.string "“I nærheden af havets bund, \n"
	.string "strømmer vandet på grund af forskelle\n"
	.string "i faktorer som temperatur og saltholdighed.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "Det er en skærm om strømmen af havvand.\p"
	.string "“Mod overfladen strømmer havvandet\n"
	.string "som strømme drevet af vinden.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“FÆRGEN S.S. TIDAL\p"
	.string "“Et skalamodel af skibet under\n"
	.string "konstruktion på STERN'S SKIBSVÆRFT.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“UNDERSØISKE EVENTYRER 1\p”\n"
	.string "“En replika af den højtydende\n"
	.string "ubåd til at udforske havbunden.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“UNDERSØISK POD\p"
	.string "“En replika af en lille, ubemandet\n"
	.string "pod til udforskning af havbunden.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“S.S. ANNE\p"
	.string "“En kopi af luksuslineren, der\n" 
	.string "sejler rundt om jorden.”$"



