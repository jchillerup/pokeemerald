@ TRANSLATED

BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Hej! Når det kommer til nyheder om\n"
	.string "BATTLE FRONTIER, er jeg nr. 1.\p"
	.string "Du kan betragte mig som\n"
	.string "FRONTIER MANIAC.\p"
	.string "Bare lige for at være sikker, du er en\n"
	.string "TRÆNER, ikke sandt?\p"
	.string "Jeg vil glædeligt dele de seneste nyheder\n"
	.string "jeg har samlet om BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Hej! Kom du forbi for at grille mig\n"
	.string "om det seneste ord? Nå, fint!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Nå? Nå? Nå?\p"
	.string "Jeg er sikker på, at mine\n"
	.string "informationer har været\n"
	.string "meget nyttige, ikke?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Lad os se nu…\p"
	.string "Det lyder som om {STR_VAR_1}\n"
	.string "er det hotteste sted lige nu.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Lad os se nu…\p"
	.string "Det lyder som KAMP-TÅRNET\n"
	.string "{STR_VAR_1} er den hotteste.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Vidste du ikke det!\p"
	.string "En af de top TRÆNERE, som SCOTT\n"
	.string "kalder FRONTIER BRAINS, er der.\p"
	.string "Det er denne mystiske TRÆNER kaldet\n"
	.string "SALONMAIDEN, der styrer stedet.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Har du kæmpet mod SALON MAIDEN?\p"
	.string "Når hun måler sin modstander op,\n"
	.string "bruger hun angiveligt disse POKéMON:\p"
	.string "En PSI POKéMON af PSYKISK type,\n"
	.string "en VULKAN POKéMON af ILD type,\l"
	.string "og en SOVEND POKéMON af NORMAL type.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Har du kæmpet mod SALON MAIDENEN\n"
	.string "når hun er seriøs?\p"
	.string "Når hun kæmper for alvor,\n"
	.string "bruger hun åbenbart disse POKéMON:\p"
	.string "En DRAGE- & PSYCHIC-typ EON POKéMON,\n"
	.string "en ELEKTRISK-type TORDEN POKéMON,\l"
	.string "og en NORMAL-type SOVENDE POKéMON.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Vidste du ikke det!\p"
	.string "En af de bedste TRÆNERE, som SCOTT\n"
	.string "kalder FRONTHJERNERNE, er der.\p"
	.string "Det er denne flamboyante TRÆNER\n"
	.string "kaldet DOME-ESS, der styrer stedet.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Har du kæmpet mod DOME ACE?\p"
	.string "Når han behandler modstanderen\n"
	.string "let, bruger han disse tre POKéMON:\p"
	.string "En DRAGE & FLYVENDE DRAGE POKéMON,\n"
	.string "en VAND & JORD MUD FISK POKéMON,\l"
	.string "og en ILD & FLYVENDE FLAMME POKéMON.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Har du kæmpet mod DOME ACE\n"
	.string "når han er seriøs?\p"
	.string "Når han demonstrerer sin strategi,\n"
	.string "bruger han disse tre POKéMON:\p"
	.string "En DRAGE- og FLYVENDE EON POKéMON,\n"
	.string "en VAND- og JORD MUD FISH POKéMON,\l"
	.string "og en STÅL- og PSYKISK-type IRON LEG\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Vidste du ikke dette!\p"
	.string "En af de øverste TRÆNERE, som SCOTT\n"
	.string "kalder FRONTIER BRAINS, er der.\p"
	.string "Det er denne mærkelige TRÆNER kaldet\n"
	.string "FABRIKKENS LEDER, der styrer stedet.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Har du allerede kæmpet mod FABRIKSDIREKTØREN\n"
	.string "?\p"
	.string "Lad mig tænke… Når han går i kamp, får han\n"
	.string "bare tre lejede POKéMON.\p"
	.string "Han kæmper under stort set de samme\n"
	.string "betingelser som dig.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Har du kæmpet mod FABRIKSOVERHOVEDEN\n"
	.string "når han er seriøs?\p"
	.string "Når han går seriøst til kamp,\n"
	.string "bruger han stadig tre lejede POKéMON.\p"
	.string "Han kæmper under næsten de samme\n"
	.string "betingelser som dig.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Vidste du ikke det her!\p"
	.string "En af de bedste TRÆNERE, som SCOTT\n"
	.string "kalder FRONTIER BRAINS, er der.\p"
	.string "Det er denne skræmmende TRÆNER kaldet\n"
	.string "PIKE QUEEN, som styrer stedet.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Har du kæmpet mod PIKE DRONNINGEN\n"
	.string "før?\p"
	.string "Når hun er i godt humør, siges det,\n"
	.string "at hun bruger disse tre POKéMON:\p"
	.string "En GIFT-type FANG SNAKE POKéMON,\n"
	.string "en BILLE & STEN MOLD POKéMON,\l"
	.string "og en VAND-type TENDER POKéMON.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Har du kæmpet mod PIKE QUEENEN\n"
	.string "når hun er seriøs?\p"
	.string "Når hun er virkelig irriteret, siger man,\n"
	.string "at hun bruger disse tre POKéMON:\p"
	.string "En GIFT-type GIFTSLANGE POKéMON,\n"
	.string "en STÅL- og JORD-type JERNSLANGE POKéMON,\l"
	.string "og en VAND- og FLYV-type GRUEFULDT\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Vidste du ikke dette!\p"
	.string "En af de bedste TRÆNERE, som SCOTT\n"
	.string "kalder FRONTEKSPERTERNE, er der.\p"
	.string "Det er denne søde TRÆNER kaldet\n"
	.string "ARENAEJEREN, som styrer stedet.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Har du kæmpet mod ARENA TYCOON'en\n"
	.string "før?\p"
	.string "Når hun vurderer modstanderens evne,\n"
	.string "bruger hun angiveligt disse POKéMON:\p"
	.string "En BUG & FIGHTING SINGLE HORN POKéMON,\n"
	.string "en DARK-type MOONLIGHT POKéMON,\l"
	.string "og en BUG & GHOST SHED POKéMON.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Har du kæmpet mod ARENA TYCOONEN\n"
	.string "når hun er seriøs?\p"
	.string "Når hun kæmper for alvor,\n"
	.string "bruger hun angiveligt disse POKéMON:\p"
	.string "En MØRKE-type MÅNESKIN POKéMON,\n"
	.string "en SPØGELSES- og GIFT SHADOW POKéMON\l"
	.string "og en GRÆS- & KAMP-type\l"
	.string "SVAMPE POKéMON.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Vidste du ikke dette!\p"
	.string "En af de der dygtige TRÆNERE, som SCOTT\n"
	.string "kalder FRONTIER BRAINS, er der.\p"
	.string "Det er denne ondskabsfulde TRÆNER kaldet\n"
	.string "PALACE MAVEN, der styrer stedet.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Har du tidligere kæmpet mod PALACE\n"
	.string "MAVEN før?\p"
	.string "Når han tester modstanderens ånd, siges\n"
	.string "han at bruge disse POKéMON:\p"
	.string "En GIFT & FLYV-type FUGLE-POKéMON,\n"
	.string "en NORMAL-type DOVEN POKéMON og en\n"
	.string "VAND & IS-type TRANSPORT POKéMON.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Har du kæmpet mod PALACE MAVENEN\n"
	.string "når han er seriøs?\p"
	.string "Når han kaster sin fulde kraft ind i\n"
	.string "kampen, siges det, at han bruger disse POKéMON:\p"
	.string "En ILD-type LEGENDARISK POKéMON,\n"
	.string "en NORMAL-type DOVEN POKéMON,\l"
	.string "og en VAND-type AURORA POKéMON.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Vidste du ikke dette!\p"
	.string "En af de der tophold \n"
	.string "TRÆNERE som SCOTT kalder \n"
	.string "FRONTIER BRAINS er der.\p"
	.string "Det er denne ildrøde TRÆNER kaldet\n"
	.string "PYRAMID KING, der styrer stedet.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Har du kæmpet mod PYRAMID KINGEN\n"
	.string "før?\p"
	.string "Når han tjekker modstanderens styrke,\n"
	.string "bruger han tilsyneladende disse POKéMON:\p"
	.string "En STEN-type STEN TOP POKéMON,\n"
	.string "en IS-type ISBJERG POKéMON,\l"
	.string "og en STÅL-type JERN POKéMON.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Har du kæmpet mod PYRAMID KING-en\n"
	.string "når han er seriøs?\p"
	.string "Når han er fyldt med varm energi,\n"
	.string "bruger han åbenbart disse POKéMON:\p"
	.string "En IS- OG FLYVENDE FROST POKéMON, en\n"
	.string "ELEKTRISK OG FLYVENDE ELEKTRISK POKéMON,\l"
	.string "og en Ild- OG FLYVENDE-type FLAMME\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Selvfølgelig! Der er flere steder, hvor\n"
	.string "du kan deltage i DOBBELTBATLER.\p"
	.string "Men DOBBELTBATLE RUMMENE i\n"
	.string "KAMPENS TOWER er ret så grundlæggende!\p"
	.string "Det er her, du bør lære om, hvordan\n"
	.string "DOBBELTBATLER spilles her\l"
	.string "i KAMPENS FRONT.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Pas på dig selv i kampene her.\p"
	.string "Jeg hører, at der er TRÆNERE, der har\n"
	.string "udviklet strategier specielt til\l"
	.string "DOBBELTKAMPE.$"  

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Når du er tryg og komfortabel\n"
	.string "med DOBBELTBATTLES her, bør du\l"
	.string "tænke på at udfordre andre steder\l"
	.string "som tilbyder DOBBELTBATTLES.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Alle slags TRÆNERE samles i\n"
	.string "KAMP SALONEN.\p"
	.string "Forestil dig bare—du kunne støde\n"
	.string "på dine venner eller følgere!\l"
	.string "Du bør kigge godt efter!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Hvis du er sammen med en ven, så gå til\n"
	.string "LINK MULTI BATTLE ROOM.\p"
	.string "Hvis du spiller med en stærk ven,\n"
	.string "kan du forvente at møde svære modstandere!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Hvilken fantastisk nyhedsindsamlingskraft!\n"
	.string "Min mentor er som ingen anden!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Hvilke fantastiske observationsevner!\n"
	.string "Min mentor er som ingen andre!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Hvilken fantastisk overbevisningskraft!\n"
	.string "Min mentor er helt unik!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "Hvad er dette sted?\n"
	.string "Det skræmmer mig…$"



