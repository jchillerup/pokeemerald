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
	.string "Tak for at du bruger MYSTERY GAVE\n"
	.string "Systemet.\p"
	.string "Ved at holde dette VIDUNDE KORT kan du\n"
	.string "deltage i en undersøgelse på et POKéMON\l"
	.string "MARKED.\p"
	.string "Brug disse undersøgelser til at\n"
	.string "invitere TRÆNERE til SOOTOPOLIS BY.\p"
	.string "…Lad mig give dig en hemmelig kode til en\n"
	.string "undersøgelse:\p"
	.string "“GIV MIG EN SEJ TRÆNER”\p"
	.string "Skriv det på en undersøgelse og send\n"
	.string "det via DEN TRÅDLØSE KOMMUNIKATIONS\l"
	.string "SYSTEM.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Tak fordi du bruger MYSTERY GAVE\n"
	.string "Systemet.\p"
	.string "En TRÆNER er ankommet til SOOTOPOLIS\n"
	.string "BY, og leder efter dig.\p"
	.string "Vi håber, du vil nyde at kæmpe mod den\n"
	.string "besøgende TRÆNER.\p"
	.string "Du kan invitere andre TRÆNERE ved at\n"
	.string "indtaste andre adgangskoder.\p"
	.string "Prøv at finde andre adgangskoder, der\n"
	.string "måske virker.$"



