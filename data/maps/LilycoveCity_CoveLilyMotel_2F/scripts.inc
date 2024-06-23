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
	.string "Åh, er det sandt? Arbejder du på en\n"
	.string "POKéDEX?\p"
	.string "Det er svært at fuldføre den, men giv\n"
	.string "ikke op.\p"
	.string "Hvis du fuldfører den, så kom og vis mig.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wow! Det er fantastisk! Ja, det er helt\n"
	.string "fantastisk!\p"
	.string "Denne POKéDEX er helt fyldt! Du må\n"
	.string "virkelig elske POKéMON!\p"
	.string "Jeg er så imponeret!\p"
	.string "Lad mig give dig noget som anerkendelse\n"
	.string "af din bedrift!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Mig? Du taler til mig? Jeg er\n"
	.string "PROGRAMMØREN.\p"
	.string "Jeg undrer mig over, hvordan\n"
	.string "SPILLEAUTOMATERNE er her.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Jeg er GRAFISK DESIGNEREN! Er POKéMON\n"
	.string "fra HOENN ikke spændende?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Pigerne TUBERS, de er søde, ikk? At\n"
	.string "kæmpe mod en sød TUBER…\p"
	.string "Jubii, det er så fedt!\p"
	.string "Og tvillingerne! Er de ikke søde? En\n"
	.string "2-mod-2 kamp med tvillingerne…\p"
	.string "Jubii, det er uudholdeligt sjovt!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "Havbrisen kilder mit hjerte. Det føles\n"
	.string "fantastisk her!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Man ved aldrig hvornår og hvor folk vil\n"
	.string "udfordre dig.\p"
	.string "Derfor forlader jeg aldrig hjemmet uden\n"
	.string "min GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … … … … … … … Zzz…\p"
	.string "… … … … … Hva?! Åh, undskyld, undskyld!\n"
	.string "Jeg var lige druknet i søvn!\p"
	.string "Jeg kom for at tjekke denne POKéMON-\n"
	.string "KONKURRENCE ting ud.\p"
	.string "Jeg må indrømme, det ser ret\n"
	.string "underholdende ud, men…\p"
	.string "Betragt mig som en puritaner--jeg\n"
	.string "foretrækker kampe og seje TRÆNERE.\p"
	.string "Men det er bare mig.\p"
	.string "{PLAYER}{KUN}, jeg håber, du vil nyde alt\n"
	.string "som GYMS, KONKURRENCER, KAMP-TELTET,\l"
	.string "det hele!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: Jeg tror, det kræver strategi at\n"
	.string "vinde en KONKURRENCE.\p"
	.string "At udvikle KONKURRENCEstrategier er én\n"
	.string "måde at blive en bedre TRÆNER, vil jeg\l"
	.string "sige.$"



