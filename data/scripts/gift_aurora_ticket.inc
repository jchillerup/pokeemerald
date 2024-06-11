@ TRANSLATED

MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Tak fordi du bruger MYSTERY\n"
	.string "GAVE Systemet.\p"
	.string "Du må være {PLAYER}.\n"
	.string "Der ligger en billet til dig her.$"

sText_AuroraTicketUseAtPort:
	.string "Det ser ud til at være til brug på\n"
	.string "LILYCOVE CITY havn.\p"
	.string "Hvorfor ikke prøve det og se hvad\n"
	.string "det handler om?$"

sText_AuroraTicketThankYou:
	.string "Tak fordi du bruger MYSTERY\n"
	.string "GAVE System.$"

sText_AuroraTicketBagFull:
	.string "Åh, undskyld, {PLAYER}.\n"
	.string "Dit TASEs NØGLEGENSTANDE-Lomme er fuld.\p"
	.string "Gem venligst noget på din PC,\n"
	.string "og kom tilbage hertil.$"

