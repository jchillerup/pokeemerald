@ TRANSLATED

AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "Jeg undersøger dette skib på vegne af\n"
	.string "KAPT. STERN.\p"
	.string "Han bad mig også om at finde en\n"
	.string "SKANNER, men jeg har ikke haft nogen\l"
	.string "succes…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Åh! Det er en SCANNER!\p"
	.string "Hør her, kan jeg få dig til at levere den\n"
	.string "til KAPT. STERN?\p"
	.string "Jeg vil gerne undersøge dette skib lidt\n"
	.string "nærmere.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Denne skib hedder S.S. KAKTUS. Det ser\n"
	.string "ud til at være fra en tidligere æra.$"



