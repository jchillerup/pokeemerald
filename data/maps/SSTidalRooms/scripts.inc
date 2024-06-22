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
	.string "Der er en seng… Lad os hvile.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Jeg sejler ofte til LILYCOVE CITY.\p"
	.string "Jeg nyder at deltage i KONKURRENCER, kan du\n"
	.string "se.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Det var en fornøjelig kamp!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Jeg bliver så spændt, når jeg forestiller\n"
	.string "mig, hvilke slags POKéMON, jeg får at se i\l"
	.string "næste KONKURRENCE. Forventningen om det\l"
	.string "er bare så spændende!$"

SSTidalRooms_Text_MicahIntro:
.string "Er dine venner stærke?$"

SSTidalRooms_Text_MicahDefeat:
.string "Dine venner er virkelig stærke.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Venner behøver ikke være mennesker. For\n"
	.string "mig er POKéMON skattede venner!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Barn... Bankede du på døren?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Et tab skal accepteres uden hast eller\n"
	.string "panik.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "At aldrig lade sig bringe ud af fatning i\n"
	.string "enhver situation er GENTLEMAN'ens\l"
	.string "adfærdskodeks.$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Jeg føler mig lidt genert over dette,\n"
	.string "men... Vi vil vise dig vores\l"
	.string "kærligheds-power!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Suk…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: Det er første gang, at vores kærlige-\n"
	.string "duvende kraft ikke kunne sejre! Du må være\l"
	.string "en fantastisk TRÆNER!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: Har du kun én POKéMON? Er det ikke lidt\n"
	.string "ensomt?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Jeg føler mig lidt fjollet, men… Vi vil\n"
	.string "vise dig vores kærlighedskraft!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: Åh, buh!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: Jeg kan ikke tro det! Vores\n"
	.string "kærlighedsfulde kræfter svigtede… Du må\l"
	.string "være en fantastisk TRÆNER!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Jeg ville kæmpe… Men du har ikke engang\n"
	.string "to POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Åh, du er kommet lige til tiden.\p"
	.string "Jeg keder mig, ser du. Du kan underholde mig.$"

SSTidalRooms_Text_GarretDefeat:
.string "…Det er nok.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Måske jeg skulle få Far til at skaffe en\n"
	.string "yacht til mig selv.\p"
	.string "En yacht til mig selv og POKéMON!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Åh, du er sådan en bedårende TRÆNER. Vil du\n"
	.string "have te?\p"
	.string "Eller vil du hellere kæmpe?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Jeg forstår. Du er den aktive type.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "En verdensomsejling på et luksuriøst\n"
	.string "krydstogtskib har sine charmer, må jeg\l"
	.string "sige…\p"
	.string "Men, jeg vil indrømme, at der er en\n"
	.string "tiltrækkende side ved at tourne HOENN med\l"
	.string "færge.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Øh... Hej! Jeg... Jeg opfører mig ikke\n"
	.string "mistænksomt! Øh... Du kan få dette! Gratis!\p"
	.string "Jeg... Ærligt, jeg SNAPPED det ikke fra\n"
	.string "nogen! Jeg ville aldrig gøre sådan noget!\l"
	.string "Det er rent! Du kan bruge det!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "SNATCH stjæler de gavnlige effekter af\n"
	.string "visse bevægelser, før de kan bruges af en\l"
	.string "fjende eller allieret.$"



