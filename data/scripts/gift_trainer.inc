@ TRANSLATED

MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Tak for at du bruger MYSTERY\n"
	.string "GAVE Systemet.\p"
	.string "Ved at holde dette VIDUNDE\n"
	.string "KORT kan du deltage i en\n"
	.string "undersøgelse på et\l"
	.string "POKéMON MARKED.\p"
	.string "Brug disse undersøgelser til at\n"
	.string "invitere TRÆNERE til SOOTOPOLIS\n"
	.string "BY.\p"
	.string "…Lad mig give dig en hemmelig\n"
	.string "kode til en undersøgelse:\p"
	.string "“GIV MIG\n"
	.string "EN SEJ TRÆNER”\p"
	.string "Skriv det på en undersøgelse og\n"
	.string "send det via DEN TRÅDLØSE\l"
	.string "KOMMUNIKATIONS SYSTEM.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Tak fordi du bruger MYSTERY\n"
	.string "GAVE Systemet.\p"
	.string "En TRÆNER er ankommet til\n"
	.string "SOOTOPOLIS BY, og leder efter dig.\p"
	.string "Vi håber, du vil nyde at\n"
	.string "kæmpe mod den besøgende TRÆNER.\p"
	.string "Du kan invitere andre TRÆNERE ved at\n"
	.string "indtaste andre adgangskoder.\p"
	.string "Prøv at finde andre adgangskoder,\n"
	.string "der måske virker.$"

