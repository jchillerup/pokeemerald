@ TRANSLATED

ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Hej der, TRÆNER! Du har et fantastisk\n"
	.string "smil der.\p"
	.string "Jeg har en hobby--at samle profilerne\n"
	.string "af POKéMON TRÆNERE.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Så, hvad siger du? Må jeg se din profil?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Du laver din egen profil ved at sætte\n"
	.string "fire ord eller fraser sammen.\p"
	.string "Her viser jeg dig et eksempel på en\n"
	.string "profil ved hjælp af fire tekster.\p"
	.string "Du kan skifte de fire tekster ud med\n"
	.string "andre tekster på hvilken som helst måde,\l"
	.string "du ønsker, for at lave din egen profil.\p"
	.string "Der er masser af tekststykker, som du\n"
	.string "kan bruge.\p"
	.string "De er arrangeret i grupper som POKéMON,\n"
	.string "livsstil og hobbyer, så det er nemmere at\l"
	.string "finde dem frem.\p"
	.string "Så vælg først tekstgruppen for at vise\n"
	.string "en liste over valgmuligheder.\p"
	.string "Vælg derefter det valg, du ønsker.\p"
	.string "Gentag for de resterende tekstvalg, og\n"
	.string "du vil have din helt egen profil.$"

ProfileMan_Text_LetsSeeItThen:
	.string "Ja! Tak! Så lad os se det, så.$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Åh nej, virkelig?\p"
	.string "Jeg forestiller mig, at en person som\n"
	.string "dig ville have en fantastisk profil…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Nå? Har du ikke lyst lige nu?\p"
	.string "Nå, det passer mig fint når som helst!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Hej med dig, TRÆNER! Du har et\n"
	.string "fantastisk smil.$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Må jeg se din nye profil?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Ja! Tak!\p"
	.string "Jeg håber, det er endnu bedre end\n"
	.string "profilen du viste mig før.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Åh, du kan lide din profil, som den er.\p"
	.string "Jeg bebrejder dig ikke - det er en\n"
	.string "fantastisk profil, som den er nu.$"

ProfileMan_Text_FantasticProfile:
	.string "F-fantastisk!\p"
	.string "Din profil, den er vidunderlig! Den siger\n"
	.string "virkelig, hvem du er.\p"
	.string "Åh, enhver der hører denne profil ville\n"
	.string "blive draget af dig!\p"
	.string "Tak!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
    .string "Åh?\n"
    .string "Du kender det hemmelige ordsprog!\p"
    .string "Det betyder, at du nu er et medlem\n"
    .string "af MYSTERY EVENT CLUB!$"



