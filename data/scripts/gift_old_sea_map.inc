@ TRANSLATED

MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Tak fordi du bruger MYSTERY GAVE\n"
	.string "Systemet.\p"
	.string "Lad mig bekræfte -- du er {PLAYER}?\p"
	.string "Vi har modtaget dette GAMLE SØKORT\n"
	.string "adresseret til dig.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Det ser ud til at være til brug ved\n"
	.string "LILYCOVE CITY havn.\p"
	.string "Hvorfor ikke prøve det og se hvad det\n"
	.string "handler om?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Tak for at bruge MYSTERY GAVE System.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Åh, jeg beklager, {PLAYER}. Lommen til\n"
	.string "de VIGTIGE TING er fuld.\p"
	.string "Gem venligst noget på din PC, og kom\n"
	.string "tilbage for denne.$"



