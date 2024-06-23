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
	.string "Denne her siger, den kan li' at kæmpe!\n"
	.string "Den vil kæmpe selvom den har mange\l"
	.string "smæld!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "Hmhm…\p"
	.string "Denne her siger, den godt kan lide at\n"
	.string "være snu! Men hvis den får nok auw, så\l"
	.string "slår den igen!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at\n"
	.string "kæmpe! Men hvis den får nok 'auvv', vil\l"
	.string "den bekymre sig om sig selv!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at\n"
	.string "kæmpe! Den vil kæmpe selvom den har\l"
	.string "mange småskrammer!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig\n"
	.string "selv! Men hvis den får nok 'av av', så\l"
	.string "slår den igen!$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at være\n"
	.string "snedig! Men hvis den får nok 'av, vil den\l"
	.string "tænke på sig selv! $"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at kæmpe!\n"
	.string "Den vil kæmpe, selvom den har mange\l"
	.string "småskrammer!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være\n"
	.string "snu! Men hvis den får nok 'av!'s, så vil\l"
	.string "den slå tilbage!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at kæmpe!\n"
	.string "Men hvis den får nok øv,  vil den bekymre\l"
	.string "sig om sig selv!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være\n"
	.string "snu! Den siger, at den kan lide at være\l"
	.string "snu,\p"
	.string "selvom den har masser af smuttere!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan li' at kæmpe!\n"
	.string "Men hvis den får nok ømmer, bliver den\l"
	.string "snedig!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at\n"
	.string "kæmpe! Den vil kæmpe selvom den har\l"
	.string "mange småskrammer!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være\n"
	.string "snigende! Den siger, den kan lide at være\l"
	.string "snigende selv hvis den har mange ømme\l"
	.string "steder!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at være\n"
	.string "snedig! Men hvis den får nok ouchies, vil\l"
	.string "den bekymre sig om sig selv!$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig\n"
	.string "selv! Den siger, at den bekymrer sig om\l"
	.string "sig selv, uanset om den har masser af\l"
	.string "ømme pletter!$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig\n"
	.string "selv! Men hvis den får nok smæk, bliver\l"
	.string "den snu!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig\n"
	.string "selv! Den siger, at den bekymrer sig om\l"
	.string "sig selv selvom den har mange sår!$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være\n"
	.string "snedig! Den siger, den kan lide at være\l"
	.string "snedig selv hvis den har masser af\l"
	.string "ømmer!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig\n"
	.string "selv! Den siger, at den bekymrer sig om\l"
	.string "sig selv selv hvis den har mange\l"
	.string "smutter!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "Hmhm…\p"
	.string "Denne her siger, den passer på sig selv!\n"
	.string "Men hvis den får nok øv-øv, vil den slå\l"
	.string "igen!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at kæmpe!\n"
	.string "Men hvis den får nok 'auv', vil den blive\l"
	.string "lumsk!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig\n"
	.string "selv! Men hvis den får nok piv, bliver den\l"
	.string "snu!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Det er skørt! Et ÆG sover! Jeg kan ikke\n"
	.string "tale med det!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Hvor charmerende! Den lille frøken\n"
	.string "påstår, at hun kan forstå POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Jeg har en fornemmelse af, at den lille\n"
	.string "pige siger noget dybsindigt.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Jeg ved noget!\p"
	.string "Den lille pige leger ved det røde hus\n"
	.string "rigtig meget!$"



