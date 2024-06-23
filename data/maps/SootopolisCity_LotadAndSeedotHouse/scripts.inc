@ TRANSLATED

SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Kender du POKéMON SEEDOT? Det er\n"
	.string "sjældent set i SOOTOPOLIS.\p"
	.string "Nå, jeg elsker store SEEDOT. Jo større,\n"
	.string "jo bedre.\p"
	.string "Men min lillebror, han siger at LOTAD er\n"
	.string "større.\p"
	.string "Det er latterligt. SEEDOT må være større\n"
	.string "end det!\p"
	.string "Hva'? Har du en SEEDOT med dig? V-v-vis\n"
	.string "mig den, vær så venlig!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2} tommer! Åh, min gosh,\n"
	.string "dette er en stor en!\p"
	.string "Den kunne endda slå den store LOTAD min\n"
	.string "yngre bror så!\p"
	.string "Tak for at vise mig. Dette er min tak!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} modtog en POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Hvad? Din TASCHE er proppet fuld.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2} tommer, er det så?\p"
	.string "Hmm… Jeg har set en større SEEDOT end\n"
	.string "denne.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Åh, det her er virkelig noget... Men det\n"
	.string "er ikke en SEEDOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "Du har ikke en stor SEEDOT? Det er\n"
	.string "ærgerligt…\p"
	.string "Hvis du får en stor SEEDOT, så kom og\n"
	.string "vis mig.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "Den største SEEDOT nogensinde!\n"
	.string "{STR_VAR_2}'s\l"
	.string "{STR_VAR_3}-tommer kæmpe!\p"
	.string "En SEEDOT større end en LOTAD altid\n"
	.string "ønsket!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Kender du POKéMON LOTAD? Det ses\n"
	.string "sjældent i SOOTOPOLIS.\p"
	.string "Jeg elsker, jeg mener virkelig elsker,\n"
	.string "store LOTAD!\p"
	.string "Min storebror siger, at SEEDOT er\n"
	.string "større.\p"
	.string "Men det er forkert! Alle ved, at LOTAD\n"
	.string "er meget større.\p"
	.string "Hvad? Har du en LOTAD? V-v-vis mig den,\n"
	.string "vær sød!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2} tommer! Wow, det er\n"
	.string "stort!\p"
	.string "Det kunne endda være større end den\n"
	.string "kæmpe SEEDOT, som min storebror så.\p"
	.string "Tak for at vise mig! Dette er min tak!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} modtog en POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Hvad? Din RYGSÆK er propfuld.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2} tommer?\p"
	.string "Hmm... Jeg har set en større LOTAD end\n"
	.string "denne her.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Nå, er det ikke noget! Men det er ingen\n"
	.string "LOTAD!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "Har du ikke en stor LOTAD? Hvor\n"
	.string "skuffende…\p"
	.string "Hvis du får en stor LOTAD, så kom og vis\n"
	.string "mig!$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "Den største LOTAD nogensinde!\n"
	.string "{STR_VAR_2}'s\l"
	.string "{STR_VAR_3}-tommer kolos!\p"
	.string "En LOTAD større end en SEEDOT altid\n"
	.string "ønsket!$"



