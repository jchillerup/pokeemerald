@ TRANSLATED

.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Åh, det er så svært hver dag…\p"
	.string "Hvad er svært? Du er nødt til at spørge?\p"
	.string "Det er svært at finde ud af, hvad man skal\n"
	.string "lave til måltider hver dag.\p"
	.string "Det er virkelig ikke nemt at finde på\n"
	.string "måltider hver dag.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Hej, hej! Velkommen til PEPPER-hjemmet.\p"
	.string "Jeg har et spørgsmål til dig. Har du\n"
	.string "nogensinde passet børn før?\p"
	.string "Ser du, jeg er en ny far, så at opdrage et barn\n"
	.string "er helt nyt for mig.\p"
	.string "Og jeg har et problem. Min datter WALDA ler\n"
	.string "ikke nok.\p"
	.string "Jeg tror, hun ville le for mig, hvis jeg\n"
	.string "fortalte hende noget sjovt.\p"
	.string "Kender du et sjovt ord eller en sætning, du\n"
	.string "kan fortælle mig?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Jeg har fået “{STR_VAR_1}” at more\n"
	.string "hende på det sidste.\p"
	.string "Kender du et bedre ord eller en sætning, der\n"
	.string "kunne virke?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Åh, det er vidunderligt. Så lad os høre det,\n"
	.string "dit forslag.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Åh, er det rigtigt?\p"
	.string "Nå, hvis du kommer med et godt forslag, så er\n"
	.string "jeg helt ører.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Åh, jeg forstår. Nå, lad os prøve det, hvad\n"
	.string "siger du?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}. {STR_VAR_1}.\p"
	.string "Åh, ja! Hun griner! Åh, jeg er lige så\n"
	.string "begejstret som hende!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Åh, jeg forstår. Nå, lad os prøve det, skal vi?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}. {STR_VAR_1}.\p"
	.string "Hmm... Hun smiler slet ikke. Måske er WALDA\n"
	.string "bare en alvorlig pige...$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Åh, så du kender ikke nogle gode ord. Jeg må\n"
	.string "hellere tænke selv, så.\p"
	.string "Hmm… Hvad med “{STR_VAR_1}”? Lad os\n"
	.string "se, om det vil virke.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}. {STR_VAR_1}.\p"
	.string "Hmm... Hun smiler overhovedet ikke. Måske er\n"
	.string "WALDA et meget alvorligt barn...$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Åh, så kender du ikke nogen gode ord. Jeg\n"
	.string "gætter på, at jeg vil forsøge at underholde\l"
	.string "hende med den sætning, jeg brugte før.\p"
	.string "Hvis du har et godt forslag, så tøv ikke med\n"
	.string "at fortælle mig, okay?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Tak!\p"
	.string "Takket være dig, min skat WALDA grinede for\n"
	.string "mig!\p"
	.string "Faktisk ser jeg måske ikke så speciel ud,\n"
	.string "men jeg er en af DEVON CORPORATION's top\l"
	.string "forskere.\p"
	.string "Så, hvad siger du til, at jeg gør noget til\n"
	.string "gengæld for dig?\p"
	.string "Jeg ved det, jeg vil tilføje nogle nye\n"
	.string "tapetmønstre til KASSERNE i PC POKéMON\l"
	.string "Opbevaringssystem.\p"
	.string "I tapetmønstermenuen, vælg “VENNER.”\p"
	.string "Det vil give dig adgang til de nye\n"
	.string "tapetmønstre.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
.string "Det er en POKéMON bamse DUKKE!$"



