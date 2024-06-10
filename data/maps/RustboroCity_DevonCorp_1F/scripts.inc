@ TRANSLATED

.set LOCALID_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Hej og velkommen til DEVON\n"
	.string "CORPORATION.\p"
	.string "Vi er stolte producenter af genstande\n"
	.string "og medicin, der forbedrer dit liv.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "En af vores forskningsmedarbejdere blev dumt\n"
	.string "ranet for en vigtig pakke.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Hej, de LØBESKO!\n"
	.string "Det er en af vores produkter!\p"
	.string "Det gør mig glad, når jeg ser nogen\n"
	.string "bruge noget, vi har lavet.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Den stjålne pakke…\p"
	.string "Ja, den er vigtig, men det er ikke\n"
	.string "noget, som nogen kan bruge.\p"
	.string "Efter min vurdering må den røver\n"
	.string "ikke have været særlig klog.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Det lyder som om de har fået\n"
	.string "de stjålne DEVON VARER.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Undskyld, kun autoriserede personer\n"
	.string "har lov til at komme ind her.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Det er fuldstændig latterligt.\n"
	.string "Hvordan kunne vi blive røvet?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Hej, med dig!\n"
	.string "Du er altid velkommen her!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Prøver af sten og metal er\n"
	.string "udstillet i glasmontren.\p"
	.string "Der er en panel med lidt skrift\n"
	.string "på det…\p"
	.string "“DEVON CORPORATION begyndte som\n"
	.string "en producent af sten fra stenbrud.\p"
	.string "“Virksomheden producerede også jern fra\n"
	.string "affald i sandet.\p"
	.string "“Fra den beskedne start med at være\n"
	.string "producent af råmaterialer, udviklede\n"
	.string "DEVON sig.\p"
	.string "“DEVON er nu en producent af en bred\n"
	.string "vifte af industriprodukter.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Prototyper og testprodukter fylder\n"
	.string "glasvitrinen.\p"
	.string "Der er en panel med en beskrivelse…\p"
	.string "“Udover industriprodukter markedsfører\n"
	.string "DEVON nu diverse ting og\n"
	.string "farmaceutiske produkter til bedre livsstil.\p"
	.string "“For nylig er DEVON begyndt at markedsføre\n"
	.string "værktøjer til POKéMON TRÆNERE, inklusive\l"
	.string "POKé BALLS og POKéNAV-systemer.”$"



