@ TRANSLATED

.set LOCALID_DAYCARE_LADY, 1

Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	waitstate
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "Jeg er DAGINSTITUTIONSMANDEN.\p"
	.string "Jeg hjælper med at passe de dyrebare\n"
	.string "POKéMON fra TRÆNERE.\p"
	.string "Hvis du vil have mig til at opfostre dit\n"
	.string "POKéMON, så tal med min kone.$"

Route117_Text_DoYouWantEgg:
	.string "Åh, det er dig!\p"
	.string "Vi passede din POKéMON, og puha, hvor vi\n"
	.string "blev overrasket!\p"
	.string "Din POKéMON havde et ÆG!\p"
	.string "Vi ved ikke, hvordan det kom derhen, men\n"
	.string "din POKéMON havde det.\p"
	.string "Vil du have det, ikke?$"

Route117_Text_YourMonIsDoingFine:
	.string "Åh, det er dig! Dejligt at se dig. Din\n"
	.string "{STR_VAR_1} har det godt.$"

Route117_Text_IllKeepIt:
	.string "Nå, så beholder jeg det. Tak!$"

Route117_Text_YouHaveNoRoomForIt:
	.string "Du har ikke plads til det… Kom tilbage,\n"
	.string "når du har lavet plads.$"

Route117_Text_ReceivedEgg:
	.string "{PLAYER} modtog ÆGGET fra\n"
	.string "DAGPLEJEMANDEN.$"

Route117_Text_TakeGoodCareOfIt:
.string "Pas godt på den.$"

Route117_Text_FriendlyWithOtherTrainersMon:
	.string "Forresten, angående din\n"
	.string "{STR_VAR_1}, den virkede venlig over\l"
	.string "for {STR_VAR_3} fra {STR_VAR_2}.\p"
	.string "Jeg tror endda, jeg så den modtage et\n"
	.string "brev.$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
	.string "Hvis du vil hente din POKéMON,\n"
	.string "skal du tale med min kone.$"

Route117_Text_YourMonsAreDoingFine:
	.string "Åh, det er dig! Din {STR_VAR_1} og\n"
	.string "{STR_VAR_2} har det godt.$"

Route117_Text_IWillKeepDoYouWantIt:
	.string "Jeg vil virkelig beholde det. Du vil have\n"
	.string "dette, ikke sandt?$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "Jeg er DAGPLEJE-DAMEN.\p"
	.string "Vi kan opdrætte POKéMON for dig.\p"
	.string "Vil du have os til at opdrætte en?$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "Hvilken POKéMON skal vi opdrætte til\n"
	.string "dig?$"

Route117_PokemonDayCare_Text_WellRaiseYourMon:
	.string "Okay, vi vil hæve din {STR_VAR_1} i et\n"
	.string "stykke tid.\p"
	.string "Kom tilbage senere for det.$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "Vi kan træne to af dine POKéMON. Vil du\n"
	.string "have os til at træne én mere?$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
.string "Min mand ledte efter dig.$"

Route117_PokemonDayCare_Text_FineThenComeAgain:
	.string "Åh, fint så. Kom igen.$"

Route117_PokemonDayCare_Text_NotEnoughMoney:
	.string "Du har ikke nok penge…$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "Vil du også tage den anden med, så?$"

Route117_PokemonDayCare_Text_ComeAgain:
	.string "Fint. Kom igen.$"

Route117_PokemonDayCare_Text_GoodToSeeYou:
	.string "Åh, det er dig! Dejligt at se dig. Dine\n"
	.string "POKéMON har det helt sikkert godt!$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "På level er din {STR_VAR_1} vokset\n"
	.string "med {STR_VAR_2}.$"

Route117_PokemonDayCare_Text_YourTeamIsFull:
	.string "Dit POKéMON-hold er fuldt. Lav plads, og\n"
	.string "kom så og se mig.$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
    .string "Hvilken POKéMON vil du tage tilbage?$"

Route117_PokemonDayCare_Text_ItWillCostX:
	.string "Hvis du ønsker din {STR_VAR_1}\n"
	.string "tilbage, vil det koste ¥{STR_VAR_2}.$"

Route117_PokemonDayCare_Text_HeresYourMon:
	.string "Perfekt! Her er din POKéMON.$"

Route117_PokemonDayCare_Text_TookBackMon:
	.string "{PLAYER} tog {STR_VAR_1} tilbage\n"
	.string "fra dagplejedamen.$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "Åh? Men du har kun én POKéMON.\p"
	.string "Kom tilbage en anden gang.$"

Route117_PokemonDayCare_Text_TakeYourMonBack:
.string "Vil du tage din POKéMON tilbage?$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "Hvis du forlader mig den POKéMON, hvad\n"
	.string "vil du kæmpe med?\p"
	.string "Kom tilbage en anden gang.$"

Text_EggHatchHuh:
.string "Hva'?$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "Hvad? Rolig nu.\p"
	.string "Hvis du efterlader den POKéMON hos mig,\n"
	.string "vil du kun have én tilbage.\p"
	.string "Du vil være bedre stillet, hvis du fanger\n"
	.string "nogle flere, tør jeg påstå.$"



