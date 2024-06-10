@ TRANSLATED

LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
    .string "Jeg er SPILDESIGNEREN.\p"
    .string "Åh, er det sandt?\n"
    .string "Arbejder du på en POKéDEX?\p"
    .string "Det er svært at fuldføre den,\n"
    .string "men giv ikke op.\p"
    .string "Hvis du fuldfører den, så kom og\n"
    .string "vis mig.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wow! Det er fantastisk!\n"
	.string "Ja, det er helt fantastisk!\p"
	.string "Denne POKéDEX er helt fyldt!\n"
	.string "Du må virkelig elske POKéMON!\p"
	.string "Jeg er så imponeret!\p"
	.string "Lad mig give dig noget som\n"
	.string "anerkendelse af din bedrift!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Mig? Du taler til mig?\n"
	.string "Jeg er PROGRAMMØREN.\p"
	.string "Jeg undrer mig over, hvordan\n"
	.string "SPILLEAUTOMATERNE er her.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Jeg er GRAFISK DESIGNEREN! Er\n"
	.string "POKéMON fra HOENN ikke spændende?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Pigerne TUBERS, de er søde, ikk?\n"
	.string "At kæmpe mod en sød TUBER…\p"
	.string "Jubii, det er så fedt!\p"
	.string "Og tvillingerne! Er de ikke søde?\n"
	.string "En 2-mod-2 kamp med tvillingerne…\p"
	.string "Jubii, det er uudholdeligt sjovt!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "Havbrisen kilder mit hjerte.\n"\n
	.string "Det føles fantastisk her!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Man ved aldrig hvornår og hvor\n"
	.string "folk vil udfordre dig.\p"
	.string "Derfor forlader jeg aldrig hjemmet uden\n"
	.string "min GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Hva?!\n"
	.string "Åh, undskyld, undskyld! Jeg var lige\n"
	.string "druknet i søvn!\p"
	.string "Jeg kom for at tjekke denne POKéMON-\n"
	.string "KONKURRENCE ting ud.\p"
	.string "Jeg må indrømme, det ser ret\n"
	.string "underholdende ud, men…\p"
	.string "Betragt mig som en puritaner--jeg\n"
	.string "foretrækker kampe og seje TRÆNERE.\p"
	.string "Men det er bare mig.\p"
	.string "{PLAYER}{KUN}, jeg håber, du vil nyde\n"
	.string "alt som GYMS, KONKURRENCER,\n"
	.string "KAMP-TELTET, det hele!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: Jeg tror, det kræver strategi\n"
	.string "at vinde en KONKURRENCE.\p"
	.string "At udvikle KONKURRENCEstrategier er\n"
	.string "én måde at blive en bedre TRÆNER, vil jeg sige.$"



