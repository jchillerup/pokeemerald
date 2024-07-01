@ TRANSLATED

SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Vil du gerne forlade SAFARI ZONE lige\n"
	.string "nu?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong! Tiden er gået! Dit\n"
	.string "SAFARI-spil er slut.$"

SafariZone_Text_OutOfBalls:
	.string "Du er løbet tør for SAFARI-BOLDE. Dit\n"
	.string "SAFARI-spil er slut.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Vil du lægge en {POKEBLOCK} på {POKEBLOCK}\n"
	.string "FODEREN?$"

SafariZone_Text_PokeblockStillHere:
	.string "Den {STR_VAR_1} du efterlod\n"
	.string "tidligere, er stadig her.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "Den {STR_VAR_1} blev lagt på\n"
	.string "{POKEBLOCK}-foderautomaten.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Velkommen til SAFARI ZONEN!\p"
	.string "Her kan du opleve mange slags POKéMON\n"
	.string "sjældent set i HOENN.\p"
	.string "Og du vil se dem i deres vilde, uregerlige\n"
	.string "tilstand i naturlige habitater.\p"
	.string "Desuden har vi åbnet portene for\n"
	.string "POKéMON-TRÆNERE.\p"
	.string "Du opfordres til at fange POKéMON for\n"
	.string "at beholde dem!\p"
	.string "Kom ind og nyd SAFARI ZONEN!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Velkommen til SAFARI ZONE! Er det din\n"
	.string "første gang her?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
.string "Kom ind og nyd SAFARI ZONEN!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Når du træder ind i SAFARI ZONEN,\n"
	.string "starter du med 30 SAFARI BOLDE til at\l"
	.string "fange POKéMON.\p"
	.string "SAFARI-spillet er slut, når du løber tør\n"
	.string "for SAFARI BOLDE, eller når du har gået\l"
	.string "500 skridt.\p"
	.string "Kom ind og nyd SAFARI ZONEN!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Velkommen til SAFARI-OMRÅDET!\p"
	.string "Alt, hvad du kan fange, for kun ¥500! Vil\n"
	.string "du spille et SAFARI-spil?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Okay. Vil du spille en anden gang?$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Du har ikke nok penge. Beklager.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Det bliver ¥500, tak.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
.string "Her er dine SAFARI-KUGLER.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} modtog 30 SAFARI-BOLDE.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Vi giver dig besked, når dit spil er slut.\p"
	.string "Så indtil da, hyg dig, vær så venlig!\n"
	.string "Afsted på dit vilde eventyr!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Undskyld! Din PC-BOKS er fuld.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Undskyld! Du ser ud til at mangle en\n"
	.string "{POKEBLOCK} SAG.\p"
	.string "Dit SAFARI-spil vil være meget mere\n"
	.string "frugtbart, hvis du bruger {POKEBLOCK}S.\p"
	.string "Kom venligst tilbage med en {POKEBLOCK} SAG.\p"
	.string "Du kan få en {POKEBLOCK} SAG fra LILYCOVE\n"
	.string "KONKURRENCESALEN.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Du har stadig tid tilbage. Vil du gerne\n"
	.string "forlade SAFARI ZONE nu?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Værsgo' at nyde resten af din vilde\n"
	.string "eventyr!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Okay.\p"
	.string "Jeg vil tage dine resterende SAFARI\n"
	.string "BOLDE tilbage.\p"
	.string "Tak for at spille. Vi håber at se dig\n"
	.string "igen.$"

SafariZone_South_Text_GoodLuck:
	.string "God fornøjelse!\p"
	.string "Hvis du har brug for noget, så tøv ikke\n"
	.string "med at fortælle mig, tak!$"

SafariZone_South_Text_Boy:
	.string "Vidste du det?\p"
	.string "Hvis du lægger en {POKEBLOCK} i den\n"
	.string "firkantede kasse, samler POKéMON sig.$"

SafariZone_South_Text_Man:
	.string "Jeg vil gerne fortsætte længere ned,\n"
	.string "men jeg glemte at medbringe en CYKEL.\p"
	.string "Noget fortæller mig, at sjældne POKéMON\n"
	.string "bor i udkantsområderne.$"

SafariZone_Southwest_Text_Woman:
	.string "Nogle gange, når jeg kaster en {POKEBLOCK} \n"
	.string "til en POKéMON, bliver den ignoreret.\p"
	.string "Mon POKéMON har præferencer for,  hvad\n"
	.string "de spiser?$"

SafariZone_Northwest_Text_Man:
	.string "Puha… Puha… Jeg… klarede det ud\n"
	.string "her…men…\p"
	.string "Jeg er udmattet… Jeg har ikke energi til\n"
	.string "at fange POKéMON…$"

SafariZone_North_Text_Fisherman:
	.string "Jeg er på et mission for at finde VAND\n"
	.string "POKéMON du ikke ser i HOENN.\p"
	.string "Har du nogen idé om, hvor søen er?$"

SafariZone_North_Text_Man:
	.string "Jeg vil fange en masse sjældne POKéMON\n"
	.string "her og bytte dem med mine venner!$"

SafariZone_South_Text_Youngster:
	.string "Jeg lagde en {POKEBLOCK} på {POKEBLOCK}-foderet.\n"
	.string "Men det ser ud til at være forsvundet.\p"
	.string "Jeg gætter på, at POKéMON har spist det\n"
	.string "uden at jeg lagde mærke til det.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "SAFARI ZONE TRÆNER-TIP!\p"
	.string "Kast {POKEBLOCK}S på vilde POKéMON for at\n"
	.string "gøre dem mindre tilbøjelige til at\l"
	.string "flygte.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "Forkæl dine trætte fødder. HVILEHUS$"

SafariZone_RestHouse_Text_Youngster:
	.string "Jeg har ikke nogen {POKEBLOCK}S, men jeg\n"
	.string "fangede et godt antal POKéMON.\p"
	.string "Du kan forbedre dine chancer for at\n"
	.string "fange en ved at komme tættere på dem\l"
	.string "før du kaster en SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Hvis du bruger {POKEBLOCK}S, vil vilde\n"
	.string "POKéMON ikke løbe væk så hurtigt.\p"
	.string "Det er ikke til megen nytte at give\n"
	.string "{POKEBLOCK}S til POKéMON, der ikke flygter\l"
	.string "let.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Hvis du lægger en {POKEBLOCK} på FOEDEREN,\n"
	.string "bliver POKéMON tiltrukket af den.\p"
	.string "Jeg tror, at POKéMON med samme natur\n"
	.string "bliver tiltrukket af en bestemt {POKEBLOCK}.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Dette område er stadig under\n"
	.string "konstruktion. Det er ikke tilladt,\l"
	.string "undskyld!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "SAFARI ZONE's udvidelsesprojekt er nu\n"
	.string "færdigt.\p"
	.string "Vi håber, at du vil nyde detnye område.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Dette område er stadig under\n"
	.string "konstruktion. Beklager!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Wow! Whee! Jeg har ikke set nogen af\n"
	.string "disse POKéMON før!$"

SafariZone_Southeast_Text_FatMan:
	.string "De POKéMON i dette område er alle nye\n"
	.string "for mig.\p"
	.string "Og jeg har lov til at fange disse\n"
	.string "sjældne POKéMON! For fedt!$"

SafariZone_Southeast_Text_RichBoy:
	.string "De POKéMON heromkring synes at være\n"
	.string "fra et sted uden for HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Jeg har kun et par SAFARI BALLS\n"
	.string "tilbage.\p"
	.string "Jeg har svært ved at beslutte, hvad jeg\n"
	.string "skal fange.$"

SafariZone_Northeast_Text_Woman:
	.string "Jeg hørte, at du kan se PIKACHU her.\n"
	.string "Hvor mon den er?$"

SafariZone_Northeast_Text_Girl:
	.string "Åh, buh! Jeg kan ikke synes at fange\n"
	.string "noget!\p"
	.string "Jeg ender med at spilde entreprisen\n"
	.string "hvis jeg ikke fanger noget!$"



