@ TRANSLATED

BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Hihi! Jeg kan fortælle, hvad POKéMON\n"
	.string "tænker!\p"
	.string "Vær sød! Må jeg se dine POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Buuh! Billige!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan li' at kæmpe! Den vil\n"
	.string "kæmpe selvom den har mange smæld!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "Hmhm…\p"
	.string "Denne her siger, den godt kan lide at være\n"
	.string "snu! Men hvis den får nok auw, så slår den\l"
	.string "igen!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at kæmpe!\n"
	.string "Men hvis den får nok 'auvv', vil den bekymre\l"
	.string "sig om sig selv!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at kæmpe!\n"
	.string "Den vil kæmpe selvom den har mange\l"
	.string "småskrammer!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Men hvis den får nok 'av av', så slår den igen!$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at være\n"
	.string "snedig! Men hvis den får nok 'av, vil den\l"
	.string "tænke på sig selv! $"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at kæmpe! Den\n"
	.string "vil kæmpe, selvom den har mange\l"
	.string "småskrammer!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være snu! Men\n"
	.string "hvis den får nok 'av!'s, så vil den slå tilbage!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at kæmpe! Men\n"
	.string "hvis den får nok øv,  vil den bekymre sig om sig\l"
	.string "selv!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være snu! Den\n"
	.string "siger, at den kan lide at være snu,\p"
	.string "selvom den har masser af smuttere!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan li' at kæmpe! Men\n"
	.string "hvis den får nok ømmer, bliver den snedig!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at kæmpe!\n"
	.string "Den vil kæmpe selvom den har mange\l"
	.string "småskrammer!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være\n"
	.string "snigende! Den siger, den kan lide at være\l"
	.string "snigende selv hvis den har mange ømme\l"
	.string "steder!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at være\n"
	.string "snedig! Men hvis den får nok ouchies, vil den\l"
	.string "bekymre sig om sig selv!$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Den siger, at den bekymrer sig om sig selv,\l"
	.string "uanset om den har masser af ømme pletter!$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Men hvis den får nok smæk, bliver den snu!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Den siger, at den bekymrer sig om sig selv\l"
	.string "selvom den har mange sår!$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være snedig!\n"
	.string "Den siger, den kan lide at være snedig selv\l"
	.string "hvis den har masser af ømmer!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Den siger, at den bekymrer sig om sig selv\l"
	.string "selv hvis den har mange smutter!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "Hmhm…\p"
	.string "Denne her siger, den passer på sig selv! Men\n"
	.string "hvis den får nok øv-øv, vil den slå igen!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at kæmpe! Men\n"
	.string "hvis den får nok 'auv', vil den blive lumsk!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Men hvis den får nok piv, bliver den snu!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Det er skørt! Et ÆG sover! Jeg kan ikke tale\n"
	.string "med det!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Hvor charmerende! Den lille frøken påstår,\n"
	.string "at hun kan forstå POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Jeg har en fornemmelse af, at den lille pige\n"
	.string "siger noget dybsindigt.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Jeg ved noget!\p"
	.string "Den lille pige leger ved det røde hus rigtig\n"
	.string "meget!$"



