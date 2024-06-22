@ TRANSLATED

MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Nå, nå, hvad har vi her? En meget energisk\n"
	.string "kunde!\p"
	.string "Mig? Du kan kalde mig RYDEL. Jeg er ejeren af\n"
	.string "denne cykelbutik.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Dine LØBESKO… De er forfærdeligt\n"
	.string "beskidte.\p"
	.string "Kom du langvejs fra?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Er det rigtigt?\p"
	.string "Så gætter jeg på, at du ikke har brug for\n"
	.string "nogen af mine CYKLER.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "Du siger, at du kom hele vejen fra\n"
	.string "LITTLEROOT?\p"
	.string "Min gode grød! Det er vanvittigt langt!\p"
	.string "Hvis du havde en af mine CYKLER, kunne du\n"
	.string "nemt komme rundt overalt og mærke den blide\l"
	.string "aircynding!\p"
	.string "Skal jeg sige dig noget! Jeg giver dig en\n"
	.string "CYKEL!\p"
	.string "Åh, vent et øjeblik!\p"
	.string "Jeg glemte at fortælle dig, at der er to slags\n"
	.string "CYKLER!\p"
	.string "Det er MACH-CYKLEN og ACRO-CYKLEN!\p"
	.string "MACH-CYKLEN er til cyklister, der vil mærke\n"
	.string "vinden med deres kroppe!\p"
	.string "Og en ACRO-CYKEL er til dem, der\n"
	.string "foretrækker tekniske ture!\p"
	.string "Jeg er en rigtig skat, så du kan få den, du\n"
	.string "bedst kan lide!\p"
	.string "Hvilken vil du vælge?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
.string "{PLAYER} valgte MACH-CYKLEN.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
.string "{PLAYER} valgte ACRO CYKEL."

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: Hvis du får lyst til at skifte cykler,\n"
	.string "så kom bare hen til mig!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL: Åh? Tænkte du på at skifte CYKLER?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL: Okay, intet problem! Jeg skifter\n"
	.string "CYKLER for dig!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} fik udvekslet MACH BIKE'en med\n"
	.string "en ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} fik udvekslet ACRO-BIKEN med\n"
	.string "en MACH-BIKE.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Godt, godt! Jeg er glad for, at du kan\n"
	.string "lide det!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Åh? Hvad skete der med den CYKEL jeg gav\n"
	.string "dig?\p"
	.string "Åh, jeg forstår, du gemte den ved hjælp af din\n"
	.string "PC.\p"
	.string "Nå, tag den ud af PC-lageret, og jeg vil med\n"
	.string "glæde bytte den tilbage!\p"
	.string "Må vinden altid være i din favør på dit\n"
	.string "eventyr!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Jeg lærer om CYKLER mens jeg arbejder her.\p"
	.string "Hvis du har brug for råd om, hvordan du kører\n"
	.string "på din CYKEL, er der et par håndbøger\l"
	.string "bagerst.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "Det er en vejledning til MACH BIKE.\p"
	.string "Hvilken side vil du læse?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "hvor + Kontrolpaden bliver trykket.\p"
	.string "Den vil accelerere, når den først ruller.\p"
	.string "For at stoppe, slip + Kontrolpaden. CYKLEN\n"
	.string "vil bremse og standse.\p"
	.string "Vil du læse en anden side?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "En MACH CYKEL er hurtig, men den kan ikke\n"
	.string "stoppe meget hurtigt.\p"
	.string "Det bliver lidt tricky at komme rundt om et\n"
	.string "hjørne.\p"
	.string "Lad + Kontrolpinden gå lidt før hjørnet og\n"
	.string "sænk farten.\p"
	.string "Vil du læse en anden side?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Der er små sandbakker overalt i\n"
	.string "HOENN-regionen.\p"
	.string "Den løse, smuldrende sand gør det umuligt\n"
	.string "at kravle op ad dem normalt.\p"
	.string "Men hvis du har en MACH CYKEL, kan du suse op\n"
	.string "ad en sandbakke.\p"
	.string "Vil du læse en anden side?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "Det er en håndbog om ACRO BIKE.\p"
	.string "Hvilken side vil du læse?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Tryk på B-knappen, mens du kører, og\n"
	.string "forhjulet løftes op.\p"
	.string "Du kan suse rundt med forhjulet oppe ved at\n"
	.string "bruge + kontrolpaden.\p"
	.string "Denne teknik kaldes en wheelie.\p"
	.string "Vil du læse en anden side?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Når du holder B-knappen nede, kan din CYKEL\n"
	.string "hoppe på stedet.\p"
	.string "Denne teknik kaldes en bunny hop.\p"
	.string "Du kan også ride mens du hopper.\p"
	.string "Vil du læse en anden side?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Tryk på B-knappen og + kontrol- puden på\n"
	.string "samme tid for at hoppe.\p"
	.string "Tryk på + kontrolpuden til siden for at\n"
	.string "hoppe sidelæns.\p"
	.string "Tryk bagud for at få CYKLEN til at skifte\n"
	.string "retning under hop.\p"
	.string "Vil du læse en anden side?$"



