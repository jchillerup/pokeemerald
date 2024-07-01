@ TRANSLATED

MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "Tak fordi du bruger MYSTERY GAVE\n"
	.string "Systemet.\p"
	.string "Du må være {PLAYER}. Der er en billet\n"
	.string "her til dig.$"

sText_MysticTicketUseAtPort:
	.string "Det ser ud til at være til brug ved\n"
	.string "LILYCOVE CITY havn.\p"
	.string "Hvorfor ikke prøve det og se hvad det\n"
	.string "handler om?$"

sText_MysticTicketThankYou:
	.string "Tak fordi du bruger MYSTERY GAVE\n"
	.string "System.$"

sText_MysticTicketBagFull:
	.string "Åh, undskyld, {PLAYER}. Din TASCHEs\n"
	.string "NØGLEGENSTANDE-LOMME er fuld.\p"
	.string "Gem venligst noget på din PC, og kom\n"
	.string "tilbage for dette.$"



