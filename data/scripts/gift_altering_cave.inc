@ TRANSLATED

MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Tak fordi du bruger MYSTERY\n"
	.string "GIFT Systemet.\p"
	.string "Der ser ud til at være et rygte om\n"
	.string "sjældne POKéMON-syn.\p"
	.string "Rygtet siger, at de blev set ved\n"
	.string "the ALTERING CAVE på ROUTE 103.\p"
	.string "Måske ville det være værd at\n"
	.string "undersøge dette rygte.$"

