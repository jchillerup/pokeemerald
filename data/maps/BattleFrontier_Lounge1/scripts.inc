@ TRANSLATED

BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "I 70 år har jeg opdrættet POKéMON!\n"
	.string "Jeg er manden, som de beundrer som\l"
	.string "den legendariske top POKéMON-OPDRÆTTER!\p"
	.string "Hvis du nogensinde bliver lige så erfar\n"
	.string "en som mig, vil du se POKéMONs evner\n"
	.string "på et øjeblik.\p"
	.string "Du er en TRÆNER. Interesserer det dig\n"
	.string "ikke at kende dine egne POKéMONs\l"
	.string "evner?\p"
	.string "Her!\n"
	.string "Lad os se på dine POKéMON!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "…Hmm…\p"
	.string "Generelt vil jeg beskrive denne\n"
	.string "som værende af gennemsnitlig evne.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "…Hmm…\p"
	.string "Generelt vil jeg beskrive denne som værende\n"
	.string "med bedre end gennemsnitlige evner.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "…Hmm…\p"
	.string "Denne her, generelt set, vil jeg sige\n"
	.string "er ret imponerende i evnerne!$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "…Hmm…\p"
	.string "Denne her, alt i alt, vil jeg sige \n"
	.string "er vidunderligt fremragende i \n"
	.string "evne!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "I øvrigt er det bedste ved det,\n"
	.string "vil jeg sige, dets HP…$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "Forresten er det bedste ved det,\n"
	.string "vil jeg sige, dets ANGREB…$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "For resten er det bedste ved det,\n"
	.string "vil jeg sige, dets FORSVAR…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "For resten, det bedste ved det er,\n"
	.string "vil jeg sige, dets SPECIELLE ANGREB…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "Forresten, det bedste ved det,\n"
	.string "ville jeg sige, er dens SPECIELLE FORSVAR…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "Forresten, det bedste ved det,\n"
	.string "vil jeg sige, er dets HASTIGHED…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "Den statistik er relativt god.\n"
	.string "…Hm… Det er hvad jeg kalder det.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "Den statistik er ret imponerende.\n"
	.string "…Hm… Sådan kalder jeg den.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "Den statistik er enestående!\n"
	.string "…Hm… Det er sådan, jeg kalder det.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "Det er fejlfrit! En ting af perfektion!\n"
	.string "…Hm… Det er sådan, jeg kalder det.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "Hvad?\n"
	.string "Har du ikke tid til min rådgivning?\p"
	.string "Du bør altid være ivrig efter at lære\n"
	.string "af dine ældres erfaringer!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Ja, hvad er det nu?\p"
	.string "Jeg har forretninger, der skal ordnes!\n"
	.string "Gem det til næste gang!$" 

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "Åh, unge! Fascinerer dine POKéMONs\n"
	.string "evner dig?\p"
	.string "Her, her!\n"
	.string "Lad os se på dine POKéMON!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "Jeg er en ekspert, men selv jeg kan ikke sige\n"
	.string "noget om en POKéMON, der ikke er klækket!\p"
	.string "Vis mig en POKéMON!\n"
	.string "Det er en POKéMON, jeg har brug for at se!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "Han sagde, at min POKéMON er fremragende!\n"
	.string "Jeg er glad for, at jeg opdrættede det omhyggeligt!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "Han sagde, at min POKéMON er enestående!\n"
	.string "Men jeg gjorde ikke noget specielt \l"
	.string "for at træne den...$"



