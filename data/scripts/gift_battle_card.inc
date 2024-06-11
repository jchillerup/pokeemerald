@ TRANSLATED

MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Tak fordi du bruger MYSTERY\n"
	.string "GAVE Systemet.\p"
	.string "Dit KAMP ANTAL KORT holder styr\n"
	.string "på din kampoptegnelse mod\l"
	.string "TRÆNERE med det samme KORT.\p"
	.string "Find og kæmp mod TRÆNERE som\n"
	.string "har det samme KORT som dig.\p"
	.string "Du kan tjekke den overordnede\n"
	.string "rangliste ved at læse NYHEDERNE.\p"
	.string "Giv det endelig et forsøg!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Tak fordi du bruger MYSTERY\n"
	.string "GAVE Systemet.\p"
	.string "Tillykke!\p"
	.string "Du har vundet en pris for at vinde\n"
	.string "tre kampe!\p"
	.string "Vi håber, at du vil blive inspireret til\n"
	.string "at kæmpe mere.$"

