@ TRANSLATED

SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Der er en seng…\n"
	.string "Lad os hvile.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Jeg sejler ofte til LILYCOVE CITY.\p"
	.string "Jeg nyder at deltage i KONKURRENCER,\n"
	.string "kan du se.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Det var en fornøjelig kamp!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Jeg bliver så spændt, når jeg forestiller\n"
	.string "mig, hvilke slags POKéMON, jeg får at se\n"
	.string "i næste KONKURRENCE. Forventningen\n"
	.string "om det er bare så spændende!$"

SSTidalRooms_Text_MicahIntro:
.string "Er dine venner stærke?$"

SSTidalRooms_Text_MicahDefeat:
.string "Dine venner er virkelig stærke.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Venner behøver ikke være mennesker.\n"
	.string "For mig er POKéMON skattede venner!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Barn...\n"
	.string "Bankede du på døren?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Et tab skal accepteres uden hast\n"
	.string "eller panik.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "At aldrig lade sig bringe ud af fatning\n"
	.string "i enhver situation er GENTLEMAN'ens adfærdskodeks.$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Jeg føler mig lidt genert over dette, men...\n"
	.string "Vi vil vise dig vores kærligheds-power!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Suk…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: Det er første gang, at vores kærlige-\n"
	.string "duvende kraft ikke kunne sejre!\l"
	.string "Du må være en fantastisk TRÆNER!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: Har du kun én POKéMON?\n"
	.string "Er det ikke lidt ensomt?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Jeg føler mig lidt fjollet, men…\n"
	.string "Vi vil vise dig vores kærlighedskraft!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: Åh, buh!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: Jeg kan ikke tro det!\n"
	.string "Vores kærlighedsfulde kræfter svigtede…\l"
	.string "Du må være en fantastisk TRÆNER!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Jeg ville kæmpe…\n"
	.string "Men du har ikke engang to POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Åh, du er kommet lige til tiden.\p"
	.string "Jeg keder mig, ser du.\n"
	.string "Du kan underholde mig.$"

SSTidalRooms_Text_GarretDefeat:
.string "…Det er nok.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Måske jeg skulle få Far til at skaffe\n"
	.string "en yacht til mig selv.\p"
	.string "En yacht til mig selv og POKéMON!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Åh, du er sådan en bedårende TRÆNER.\n"
	.string "Vil du have te?\p"
	.string "Eller vil du hellere kæmpe?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Jeg forstår.\n"
	.string "Du er den aktive type.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "En verdensomsejling på et luksuriøst\n"
	.string "krydstogtskib har sine charmer, må jeg\n"
	.string "sige…\p"
	.string "Men, jeg vil indrømme, at der er en\n"
	.string "tiltrækkende side ved at tourne HOENN\n"
	.string "med færge.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Øh... Hej! Jeg... Jeg opfører mig ikke mistænksomt!\n"
	.string "Øh... Du kan få dette! Gratis!\p"
	.string "Jeg... Ærligt, jeg SNAPPED det ikke fra\n"
	.string "nogen! Jeg ville aldrig gøre sådan noget!\l"
	.string "Det er rent! Du kan bruge det!$" 

SSTidalRooms_Text_ExplainSnatch:
	.string "SNATCH stjæler de gavnlige effekter\n"
	.string "af visse bevægelser, før de kan\l"
	.string "bruges af en fjende eller allieret.$"



