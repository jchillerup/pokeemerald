@ TRANSLATED

PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Folk sagde, at de så en POKéMON flyve højt\n"
	.string "over HOENN.\p"
	.string "Flyver den rundt hele tiden? Skal den ikke\n"
	.string "hvile et sted?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "En himmel POKéMON! En himmel POKéMON!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
.string "Hvor kom du fra?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Ja? JA BYEN?\p"
	.string "Jeg har aldrig hørt om et sted som det.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Nej? Det giver ingen mening. Du skal komme\n"
	.string "et sted fra.\p"
	.string "Åh! Vent! Du skal ikke sige, at du blev født i\n"
	.string "bunden af havet?$"



