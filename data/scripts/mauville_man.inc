@ TRANSLATED

MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, 0
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Hej, jeg er HANDLEREN.\n"
	.string "Vil du bytte dekorationer med mig?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Åh…\n"
	.string "Du har efterladt mig følelsen af blues…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Men vi har allerede byttet dekorationer,\n"
	.string "du og jeg.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Hvis du ser et dekorativt emne,\n"
	.string "du gerne vil have af mig, så sig det.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Du vil ikke have noget?\n"
	.string "Jeg føler mig uønsket...$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Den pyntegenstand tilhørte engang\n"
	.string "{STR_VAR_1}.\p"
	.string "Vil du have den?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Øh... Vent lige et øjeblik. Du har\n"
	.string "ikke en eneste pynteting!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Okay, vælg den dekoration, du vil\n"
	.string "handle med mig.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Vil du ikke handle med mig?\n"
	.string "Jeg føler mig uønsket...$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Du har alle de {STR_VAR_2}ER, der kan\n"
	.string "opbevares. Der er ikke plads til dette.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Okay, så vil vi bytte min {STR_VAR_3}\n"
	.string "for din {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Den udsmykning er i brug.\n"
	.string "Du kan ikke handle med den.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Så handler vi!\n"
	.string "Jeg sender min dekoration til din PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Ups! Undskyld! Det er virkelig en\n"
	.string "sjælden pyntegenstand.\l"
	.string "Den kan jeg ikke bytte væk!\p"
	.string "Kan jeg friste dig med noget andet?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Jeg er FORTÆLLEREN.\n"
	.string "Jeg vil fortælle dig historier om legendariske\l"
	.string "TRÆNERE.\p"
	.string "Vil du høre min historie?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Åh…\n"
	.string "Du har efterladt mig i blåstemning…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Jeg kender til disse legender.\n"
	.string "Hvilken fortælling ønsker du at høre?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Men jeg kender ikke til legendariske \nTRÆNERE.\n"
	.string "Derfor kender jeg ingen historier.\p"
	.string "Hvor finder man en TRÆNER værdig\n"
	.string "til en legendarisk fortælling?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Hvad er det?!\n"
	.string "Du… Du…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} gang(e)?!\p"
	.string "Det er virkelig storslået!\n"
	.string "Det er fødslen på en ny legende!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Det får mig til at tænke, kunne der\n"
	.string "være andre TRÆNERE med mere imponerende\l"
	.string "legender, der venter på at blive opdaget?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Er du en TRÆNER?\p"
	.string "Så fortæl mig, har du nogle historier,\n"
	.string "der er bare tilnærmelsesvis legendariske?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "For resten… Kunne du tænke dig\n"
	.string "at høre endnu en legendarisk fortælling?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm…\n"
	.string "Jeg er ikke tilfreds…\p"
	.string "Jeg ville ønske, at du kunne bringe mig\n"
	.string "nyheder værdige\n"
	.string "at blive kaldt en legende.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "Jeg ønsker, at flere ville være interesseret\n"
	.string "i at høre mine episke fortællinger om legendariske\l"
	.string "TRÆNERE.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
.string "Den gemmeglade TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Gemte spillet$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Dette er historien om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER reddede spillet\n"
	.string "{STR_VAR_1} gange!\p"
	.string "En mere forsigtig TRÆNER end\n"
	.string "{STR_VAR_3} findes ikke!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
.string "Trendsetter TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
.string "Startede tendenser$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER startede nye tendenser\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} sætter tendenser for alle\n"
	.string "i HOENN-regionen!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
.string "BÆR-Plantningstræneren$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
.string "Planted BÆR$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER plantede BÆR\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} er en legendarisk elsker af\n"
	.string "BÆR!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
.string "Den CYKEL-elskende TRÆNER$"  

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
.string "Byttede CYKLER$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER har skiftet CYKLER\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må virkelig elske CYKLER\n"
	.string "dybt og lidenskabeligt!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
.string "Den interviewede TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
.string "Blev interviewet$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER blev interviewet\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må være en TRÆNER, der\n"
	.string "tiltrækker meget opmærksomhed!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
.string "Den kampglade TRÆNER$" 

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
.string "Kæmpede$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER har kæmpet {STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må være en TRÆNER, der aldrig\n"
	.string "kan sige nej til en kamp!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
.string "POKéMON-Fangeren$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Fanget POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "med navnet {STR_VAR_3}.\p"
	.string "Denne TRÆNER fangede\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} er en legendarisk fanger af\n"
	.string "vilde POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
.string "Fiskeritræneren$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
.string "Fanget POKéMON med en STANG$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER fangede\n"
	.string "{STR_VAR_1} POKéMON mens han fiskede!\p"
	.string "{STR_VAR_3} er en legendarisk fiske\n"
	.string "ekspert!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
.string "Den ÆGGE-værmende TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
.string "Udrukkede \nÆG$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Dette er historien om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER udklækkede {STR_VAR_1} POKéMON-\n"
	.string "æg!\p"
	.string "{STR_VAR_3} er en legendarisk ud\n"
	.string "råner af æg!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
.string "The Evolver TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
.string "Udviklet POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Dette er fortællingen om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER fik {STR_VAR_1} POKéMON\n"
	.string "til at udvikle sig!\p"
	.string "{STR_VAR_3} er den ultimative udvikler\n"
	.string "af POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
.string "DEN POKéMON CENTER-Elskende TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
.string "Brugte POKéMON-centre$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER helbredte POKéMON\n"
	.string "{STR_VAR_1} gange på POKéMON-CENTRE!\p"
	.string "Der kunne ikke være en større elsker af\n"
	.string "POKéMON-CENTRE end {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
.string "Hjemme TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
.string "Rested POKéMON hjemme$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER helbredte POKéMON\n"
	.string "{STR_VAR_1} gange derhjemme!\p"
	.string "{STR_VAR_3} kunne simpelthen ikke\n"
	.string "lide at være ude!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
.string "Den SAFARI-Elskende TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
.string "Gik ind i SAFARI ZONE$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Dette er historien om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER besøgte SAFARI-ZONEN\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} er en TRÆNER, hvis vilde side\n"
	.string "skal komme frem i SAFARI-ZONEN!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
.string "CUT-Frenzy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
.string "Brugte SKÆR$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Dette er historien om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER brugte STYKKE\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} er en TRÆNER, som\n"
	.string "åbenbart elsker at STYKKE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
.string "Den STENSKJULLENDE TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
.string "Smadrede sten$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER brugte STENSMADRING\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må være en TRÆNER, der\n"
	.string "ikke kan lade en sten være usmurt!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
.string "Den Bevægelsesglade TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
.string "Flyttede den HEMMELIGE BASE$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Dette er historien om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER flyttede den\n"
	.string "HEMMLIGE BASE\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} er en TRÆNER, der elsker\n"
	.string "at flytte ofte!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
.string "Den Sjove TRÆNER-med-SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
.string "Brugt PLASK$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER brugte SPLASH\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} er en TRÆNER, der må elske\n"
	.string "at PLASKE rundt!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
.string "Den Hårdføre TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Gav op og tyede til at KÆMPE$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER måtte kæmpe sig igennem\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} er en sej TRÆNER\n"
	.string "der aldrig giver op overfor modgang!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
.string "The SLOT Champ$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
.string "Vandt jackpotten på SPILLEMASKINERNE$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER vandt jackpoten\n"
	.string "på SPILLEMASKINERNE {STR_VAR_1} gange.\p"
	.string "{STR_VAR_3} er en TRÆNER, der var heldig\n"
	.string "på SPILLEMASKINERNE!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
.string "Roulette-mesteren$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
.string "Havde på hinanden følgende GEVINSTer i ROULETTE på$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER vandt i ROULETTE\n"
	.string "{STR_VAR_1} gange i træk.\p"
	.string "{STR_VAR_3} var heldig, da bolden\n"
	.string "hoppede i ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
.string "Kamp Tårn Udfordrer$" 

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
.string "Took the BATTLE TOWER challenge$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER tog KAMPTÅRNETS\n"
	.string "udfordring {STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} er en TRÆNER, som stræber\n"
	.string "efter fremragende præstationer i\n"
	.string "KAMPTÅRNET!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
.string "Den Blændende ELSKER AF BLANDINGER$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "Lavet {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Dette er fortællingen om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER lavede {POKEBLOCK}S\n"
	.string "{STR_VAR_1} gange!\p"
	.string "Der er ingen, der er bedre til at bruge en BÆR\n"
	.string "BLANDER end {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
.string "Den KONKURRENCEelskende TRÆNER$ " 

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Deltog i KONKURRENCER$"


MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER deltog i KONKURRENCER\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må virkelig elske at vise\n"
	.string "POKéMON frem for andre!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
.string "Mesteren af KONKURRENCEN$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "Vandt KONKURRENCER$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER har vundet KONKURRENCER\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må være en utrolig\n"
	.string "KONKURRENCE mester!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
.string "Den Glade Handler$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
.string "Shopped$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER købte ting i\n"
	.string "butikker {STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må være en af de mennesker,\n"
	.string "der er født til at shoppe.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
.string "Træneren til at finde genstande$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
.string "Brugte en TINGFINDER$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER anvendte en TINGFINDER\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må nyde at lede på jorden\n"
	.string "efter skjulte genstande!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
.string "Den regnvåde TRÆNER$" 

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
.string "Blev våd af regn$\p$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER blev gennemblødt af regn\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3}'s karisma må tiltrække regn!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
.string "Den Ivrig POKéDEX Læser$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Tjekkede en POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER tjekkede en POKéDEX\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må virkelig elske at inspicere\n"
	.string "POKéMON i en POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
.string "Saml RIBBON'$n'Collector$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
.string "Modtaget SNORE$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER har modtaget BÅND\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må være en TRÆNER der\n"
	.string "elsker at samle på BÅND!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "Kanten-Hoppe TRÆNER$" 

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
.string "Sprang ned af kanterne$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER hoppede ned ad\n"
	.string "skrænter {STR_VAR_1} gange!\p"
	.string "Hvis der er en skrænt, der skal\n"
	.string "springes ned fra, kan {STR_VAR_3}\n"
	.string "ikke ignorere den!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
.string "Den Legendariske TV-seer$" 

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
.string "Så TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER har set TV\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må virkelig elske at se TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
.string "Den Tidsbevidste TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
.string "Tjekkede tiden$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Dette er fortællingen om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER checkede tiden\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må være en punktlig TRÆNER\n"
	.string "som er opmærksom på tiden.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
.string "Pokémon Lotteri Troldmanden$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
.string "Vandt POKéMON lotterier$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Dette er en historie om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER har vundet POKéMON-\n"
	.string "LOTTERIERNE {STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må have mange venner\n"
	.string "at bytte POKéMON med!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
.string "Børnehave-Træneren$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
.string "Left POKéMON at the DAY CARE$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Dette er fortællingen om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER har efterladt sine\n"
	.string "POKéMON hos DAGPLEJEN {STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må være en vaskeægte\n"
	.string "iværksætter, der opdrætter POKéMON\n"
	.string "med ildhu!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
.string "Den KABELBANE-Elskende TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
.string "Kørte svævebanen$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER kørte med SVÆVEBANEN\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må være en travl TRÆNER\n"
	.string "som er oppe og ned hele tiden!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
.string "Den Varme Kilde-Elskende TRÆNER$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "Dyppe i varme kilder$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Dette er en fortælling om en TRÆNER\n"
	.string "ved navn {STR_VAR_3}.\p"
	.string "Denne TRÆNER har badet i varme kilder\n"
	.string "{STR_VAR_1} gange!\p"
	.string "{STR_VAR_3} må være en TRÆNER med\n"
	.string "baby-blød hud!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Jeg er SPÆNDT!\n"
	.string "Jeg har en fortryllende historie til dig!\p"
	.string "Vil du høre min historie?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Åh…\n"
	.string "Du har fået mig til at føle mig lidt blå…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Og så tænkte jeg...\p$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Det var vist det, tror jeg…\p"
	.string "Vi skal snakkes ved igen!\n"
	.string "Hej-hej!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Hej, jeg er BARDEN.\n"
	.string "Vil du høre min sang?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Åh…\n"
	.string "Du har efterladt mig med blåt humør…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Åh, sikke en bevægende sang…\n"
	.string "Jeg ønsker, jeg kunne spille den for andre…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Så?\n"
	.string "Hvad synes du om min sang?\p"
	.string "Men jeg er ikke helt tilfreds med\n"
	.string "teksterne.\p"
	.string "Hvad siger du til at skrive nogle\n"
	.string "nye tekster for mig?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Åh…\n"
	.string "Du har efterladt mig med en sørgmodig stemning…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Mange tak!\n"
	.string "Lad mig synge det for dig.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Var det sådan, du ønskede din sang\n"
	.string "skulle gå?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Okay! Det er det, så.\n"
	.string "Jeg vil synge denne sang et stykke tid.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Hej, yo! De kalder mig HIPSTEREN.\n" 
	.string "Jeg vil lære dig, hvad der er moderne og sker.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Men hey, jeg har allerede lært dig,\n"
	.string "hvad der er cool og sker.\p"
	.string "Jeg vil gerne dele de gode nyheder\n"
	.string "med andre mennesker.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Men hey, du ved allerede en masse om\n"
	.string "det, der er cool og sker lige nu.\p"
	.string "Jeg har intet nyt at lære dig!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Hey, har du hørt om\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Hvad betyder det? Tja…\n"
	.string "Spørg din far eller mor, okay?$"

