@ TRANSLATED

LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Velkommen til URTEBUTIKKEN, hjemmet\n"
	.string "for effektiv og billig medicin!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "Du er kommet for at se på urtemedicin\n"
	.string "i LAVARIDGE?\p"
	.string "Det er ret prisværdigt.\p"
	.string "Jeg kan godt lide dig! Tag denne!\p$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "Den TRÆKUL, jeg gav dig, bliver\n"
	.string "brugt til at lave urtemedicin.\p"
	.string "Den gør også underværker, når den\n"
	.string "bliver holdt af en POKéMON.\p"
	.string "Den forstærker kraften af ILD-typernes\n"
	.string "angreb.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "Urtemedicin virker imponerende godt.\n"
	.string "Men dine POKéMON vil ikke bryde sig om det.\p"
	.string "Det må være forfærdeligt bittert!$"



