@ TRANSLATED

VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Lad mig se dine POKéMON. Jeg vil tjekke\n"
	.string "for at se, hvor meget det kan lide dig.\p"
	.string "Åh. Dit POKéMON…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "Den er vild med dig. Den kan ikke elske\n"
	.string "dig mere. Jeg bliver endda glad, når jeg\l"
	.string "ser det.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "Den ser ud til at være meget glad. Den\n"
	.string "kan tydeligvis rigtig godt lide dig.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "Den kan godt lide dig en hel masse. Den\n"
	.string "virker til at ville passes lidt på.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "Den vænner sig til dig. Den virker til at\n"
	.string "tro på dig.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "Det er ikke meget brugt til dig endnu.\n"
	.string "Det elsker eller hader dig ikke.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "Den er meget forsigtig. Den har\n"
	.string "skræmmende ondskab i sine øjne. Den kan\l"
	.string "ikke lide dig meget.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "Det her er lidt svært for mig at sige…\p"
	.string "Din POKéMON hader dig simpelthen. Gør\n"
	.string "det dig ikke utilpas?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pika pika!$"



