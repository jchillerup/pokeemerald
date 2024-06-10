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
	.string "Hihi!\n"
	.string "Jeg kan fortælle, hvad POKéMON tænker!\p"
	.string "Vær sød!\n"
	.string "Må jeg se dine POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Buuh!\n"
	.string "Billige!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan li' at kæmpe!\n"
	.string "Den vil kæmpe selvom den har mange\l"
	.string "smæld!$" 

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "Hmhm…\p"
	.string "Denne her siger, den godt kan lide at være snu!\n"
	.string "Men hvis den får nok auw,\l"
	.string "så slår den igen!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at kæmpe!\n"
	.string "Men hvis den får nok 'auvv',\l"
	.string "vil den bekymre sig om sig selv!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at kæmpe!\n"
	.string "Den vil kæmpe selvom den har mange\l"
	.string "småskrammer!$" 

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Men hvis den får nok 'av av',\l"
	.string "så slår den igen!$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at være snedig!\n"
	.string "Men hvis den får nok 'av, vil den tænke på sig selv!\l"
	.string "$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at kæmpe!\n"
	.string "Den vil kæmpe, selvom den har mange\n"
	.string "småskrammer!\p$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være snu!\n"
	.string "Men hvis den får nok 'av!'s,\l"
	.string "så vil den slå tilbage!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at kæmpe!\n"
	.string "Men hvis den får nok øv, \l"
	.string "vil den bekymre sig om sig selv!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være snu!\n"
	.string "Den siger, at den kan lide at være snu,\p"
	.string "selvom den har masser af smuttere!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan li' at kæmpe!\n"
	.string "Men hvis den får nok ømmer,\l"
	.string "bliver den snedig!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at kæmpe!\n"
	.string "Den vil kæmpe selvom den har mange\l"
	.string "småskrammer!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være snigende!\n"
	.string "Den siger, den kan lide at være snigende selv\l"
	.string "hvis den har mange ømme steder!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "Hmhm…\p"
	.string "Denne her siger, at den kan lide at være snedig!\n"
	.string "Men hvis den får nok ouchies,\l"
	.string "vil den bekymre sig om sig selv!$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Den siger, at den bekymrer sig om sig selv,\n"
	.string "uanset om den har masser af ømme pletter!$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Men hvis den får nok smæk,\l"
	.string "bliver den snu!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Den siger, at den bekymrer sig om sig selv\n"
	.string "selvom den har mange sår!$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at være snedig!\n"
	.string "Den siger, den kan lide at være snedig selv\l"
	.string "hvis den har masser af ømmer!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Den siger, at den bekymrer sig om sig selv selv\n"
	.string "hvis den har mange smutter!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "Hmhm…\p"
	.string "Denne her siger, den passer på sig selv!\n"
	.string "Men hvis den får nok øv-øv,\l"
	.string "vil den slå igen!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "Hmhm…\p"
	.string "Denne her siger, den kan lide at kæmpe!\n"
	.string "Men hvis den får nok 'auv',\l"
	.string "vil den blive lumsk!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "Hmhm…\p"
	.string "Denne her siger, at den passer på sig selv!\n"
	.string "Men hvis den får nok piv,\l"
	.string "bliver den snu!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Det er skørt! Et ÆG sover!\n"
	.string "Jeg kan ikke tale med det!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Hvor charmerende!\n"
	.string "Den lille frøken påstår, at hun kan\l"
	.string "forstå POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Jeg har en fornemmelse af, at den lille pige\n"
	.string "siger noget dybsindigt.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Jeg ved noget!\p"
	.string "Den lille pige leger ved det røde hus\n"
	.string "rigtig meget!$"



