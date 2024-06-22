@ TRANSLATED

.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Hør her, ven, arbejder du på en POKéDEX?\p"
	.string "Hmm… Gå til SAFARI ZONE. Det er mit forslag.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Har du gjort noget ved PLADEHJØRNET?\p"
	.string "Det er ret sjovt. Det blander og matcher\n"
	.string "TRÆNERES plader.\p"
	.string "Jeg ved ikke helt, hvordan det virker, men\n"
	.string "det er sejt. Det er spændende, endda!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Åh, wow, du har en POKéNAV! Og den ligner bare\n"
	.string "min!\p"
	.string "Ved du noget om POKéNAV's MATCH CALL\n"
	.string "system?\p"
	.string "Åbn det, og du kan chatte med registrerede\n"
	.string "TRÆNERE når som helst.\p"
	.string "Det viser også hvilke TRÆNERE der gerne vil\n"
	.string "udfordre dig igen.\p"
	.string "Det er virkelig smart! De DEVON-folk ved\n"
	.string "virkelig, hvad de laver!$"



