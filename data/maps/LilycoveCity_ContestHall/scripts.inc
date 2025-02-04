@ TRANSLATED

@ VAR_LAST_TALKED would have made all these direct references unnecessary
.set LOCALID_SMART_MC, 4
.set LOCALID_SMART_JUDGE, 5
.set LOCALID_SMART_CONTESTANT_1, 6
.set LOCALID_SMART_CONTESTANT_2, 7
.set LOCALID_SMART_CONTESTANT_3, 8
.set LOCALID_SMART_CONTESTANT_4, 9
.set LOCALID_SMART_AUDIENCE_4, 11
.set LOCALID_SMART_AUDIENCE_2, 12
.set LOCALID_BEAUTY_MC, 13
.set LOCALID_BEAUTY_JUDGE, 14
.set LOCALID_BEAUTY_CONTESTANT_1, 15
.set LOCALID_BEAUTY_CONTESTANT_2, 16
.set LOCALID_BEAUTY_CONTESTANT_3, 17
.set LOCALID_BEAUTY_CONTESTANT_4, 18
.set LOCALID_BEAUTY_AUDIENCE_1, 19
.set LOCALID_BEAUTY_AUDIENCE_3, 20
.set LOCALID_BEAUTY_AUDIENCE_2, 21
.set LOCALID_SMART_AUDIENCE_3, 22
.set LOCALID_CUTE_MC, 23
.set LOCALID_CUTE_JUDGE, 24
.set LOCALID_CUTE_CONTESTANT_1, 25
.set LOCALID_CUTE_CONTESTANT_2, 26
.set LOCALID_CUTE_CONTESTANT_3, 27
.set LOCALID_CUTE_CONTESTANT_4, 28
.set LOCALID_CUTE_AUDIENCE_1, 29
.set LOCALID_CUTE_AUDIENCE_3, 30
.set LOCALID_CUTE_AUDIENCE_2, 31

LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Denne POKéMON vandt\n"
	.string "SKØNHEDSKONKURRENCEN her tidligere.\p"
	.string "Nå, gæt hvad? I dag fik jeg den til at\n"
	.string "vinde en SMARTHEDSKONKURRENCE!\p"
	.string "Mine evner skræmmer endda mig…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "Jeg har deltaget i en masse\n"
	.string "KONKURRENCER, så jeg ser, hvordan\l"
	.string "tingene fungerer.\p"
	.string "Hvis du er med i en SEJHEDSKONKURRENCE,\n"
	.string "går seje træk godt hjem.\p"
	.string "Men smarte træk og søde træk går ikke\n"
	.string "så godt hjem, for eksempel.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Den unge mand, der vandt tidligere,\n"
	.string "havde en hel masse forskellige {POKEBLOCK}S.\p"
	.string "Kan du vinde, hvis du havde så mange af\n"
	.string "de ting?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Wow, er dette sted ikke kæmpestort!\p"
	.string "Spændingen i luften... Det er ikke\n"
	.string "ligesom en KONKURRENCESAL i provinsen.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "MC: Okay, SMART POKéMON og deres\n"
	.string "TRENERS, er I klar?!\p"
	.string "Giv jeres bedste fremvisning! Lad os\n"
	.string "imponere!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "DOMMER: Nyder I denne KONKURRENCE?\p"
	.string "Kom tilbage med tre venner, og alle kan\n"
	.string "deltage i en KONKURRENCE!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Av av av… Jeg meldte mig til den\n"
	.string "forkerte KONKURRENCE.\p"
	.string "Jeg tilmeldte denne seje POKéMON til\n"
	.string "SMARTHEDSKONKURRENCEN…\p"
	.string "Kom nu, imponér dem med et smart\n"
	.string "udseende ROCK SMASH.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Jeg har tilbragt mange år og al min\n"
	.string "visdom desuden, med at opdrage denne\l"
	.string "POKéMON til at være klog.\p"
	.string "Den vil ikke let lade sig besejre af en\n"
	.string "ung hvalps POKéMON.\p"
	.string "Min kære kone, ser du dette?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Der er det!\p"
	.string "Hvis min POKéMON laver et smart træk\n"
	.string "næste gang, vil publikums spænding nå\l"
	.string "sit højdepunkt!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Åh nej!\p"
	.string "Min kære ZUBAT's LEECH LIFE er så sød,\n"
	.string "så jeg bliver ved med at bruge den igen\l"
	.string "og igen!\p"
	.string "Men disse onde mennesker sætter slet\n"
	.string "ikke pris på den!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kiyaaah! Du er smuk, Bedstefar!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Selv når TRÆNERE har den samme type\n"
	.string "POKéMON, bruger de alle forskellige\l"
	.string "moves til opvisninger.\p"
	.string "Det er ligesom måden folk har\n"
	.string "forskellige stilarter til at kæmpe.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Jeg synes, at POKéMON ser mere\n"
	.string "intelligente ud end deres TRÆNERE. \l"
	.string "Langt mere.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Når alt er sagt og gjort, elsker jeg\n"
	.string "stadig SMARTHEDSKONKURRENCER.\p"
	.string "Den intellektuelle grønne farve… Den er\n"
	.string "så... Så... Cool.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "MC: Er du også med i\n"
	.string "SKØNHEDSKONKURRENCEN? God held!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "DOMMER: Åh, hver POKéMON her er et\n"
	.string "forbillede på enestående skønhed!\p"
	.string "Åh, jeg glemte næsten at give dem en\n"
	.string "bedømmelse!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "En POKéMON så smuk… Der findes ikke en\n"
	.string "sådan.\p"
	.string "Alle vil stirre på min skønhed.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Waaaah!\p"
	.string "Jeg børstede og plejede min POKéMON\n"
	.string "omhyggeligt til denne KONKURRENCE…\p"
	.string "Men jeg overgjorde det… Min POKéMONs\n"
	.string "pels blev helt pjusket…\p"
	.string "Hvad skal jeg gøre?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "Denne AURORA STRÅLE er så blendende,\n"
	.string "at DOMMEREN ikke vil kunne se den.\p"
	.string "Øh, vent lige et øjeblik… Det vil være\n"
	.string "meningsløst!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Denne smukke POKéMON ligner mig lige da\n"
	.string "jeg var yngre.\p"
	.string "Lige da jeg sagde det, spytte min mand\n"
	.string "kaffen han drak ud.\p"
	.string "Sagde jeg noget sjovt?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Du ved, hvis jeg vinder en\n"
	.string "SKØNHEDSKONKURRENCE, så gør det mig\l"
	.string "glad. Mere end sædvanligt, i hvert fald.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Hæ-hæ-hæ!\p"
	.string "Vil du se på alle de smukke POKéMON? Jeg\n"
	.string "elsker bare den bling-bling!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Du kan ikke altid vinde kun ved at være\n"
	.string "smuk alene.\p"
	.string "Du bliver nødt til at pleje din POKéMON,\n"
	.string "så den er flot og glansfuld ligesom min.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "MC: Åh-åh! Hej! Vi er midt i en\n"
	.string "KONKURRENCE!\p"
	.string "Gå venligst hen til vores registrerings\n"
	.string "skranke og kom ud, okay?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "DOMMER: Åh, så charmerende og søde\n"
	.string "argumenter!\p"
	.string "Åh, du godeste! Sikke en helt perfekt\n"
	.string "KÆRLIG VANDSPORT appel!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Åh nej... Min søde AZURILL blev afledt\n"
	.string "af en anden POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Min POKéMON har aldrig vundet i en kamp,\n"
	.string "men sæt den i en KONKURRENCE, og se på!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "Min POKéMONs BLOMSTERDANS er et under\n"
	.string "af elegance.\p"
	.string "Jeg vil ikke lade nogen forstyrre dens\n"
	.string "optræden.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Alle POKéMON er meget søde.\p"
	.string "Men hvis min POKéMON lavede en sød\n"
	.string "appel…\p"
	.string "Jeg er sikker på, at den ville være så\n"
	.string "meget sødere end de andre.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
.string "Mit barn er med i denne KONKURRENCE.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Kom nu, søde. Giv den gas! Din POKéMON\n"
	.string "er den bedste!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Jeg synes, at pigen derovre er den\n"
	.string "sødeste af dem alle.\p"
	.string "Hvad er det? Dømmer de POKéMON ud fra\n"
	.string "deres udseende?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Åh, at se alle disse søde POKéMON, de\n"
	.string "får mig til at få lyst til at få min egen!\p"
	.string "Jeg vil gå ud og fange nogle!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "SKØNHEDSKONKURRENCE SCENE LAD DIG\n"
	.string "FORFØRE AF SMUKKE POKÉMON!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "Sød konkurrence scene Bliv charmeret\n"
	.string "af søde POKéMON!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "KLOGSKABSKONKURRENCE TRIN BLIV\n"
	.string "IMPONERET AF KLOGE POKéMON!$"



