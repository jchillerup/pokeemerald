@ TRANSLATED

SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "Hvordan formåede du at komme her uden\n"
	.string "en ubåd? Hvor imponerende, lille ven!\p"
	.string "Men... Det er ikke acceptabelt, at du\n"
	.string "roder rundt her.\p"
	.string "Og jeg ønsker betaling for det, der\n"
	.string "skete på VEJRINSTITUTTET...\p"
	.string "Jeg vil give dig en smagsprøve på\n"
	.string "smerte!\p"
	.string "Gør dig klar til det!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Hahaha!\p"
	.string "Av!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Hahaha! Du er så forbandet stærk.\p"
	.string "Det er forfærdeligt skuffende, at du\n"
	.string "ikke er medlem af TEAM AQUA.\p"
	.string "Du kunne have nydt den fantastiske\n"
	.string "verden, vores BOSS har lovet os som en\l"
	.string "af os…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "For at vores drøm kan blive virkelig, har\n"
	.string "vi brug for POKéMONs kraft.\p"
	.string "Men blanderøve som dig bruger kraften\n"
	.string "af POKéMON til at rode med os selv her på\l"
	.string "et sted som dette!\p"
	.string "Livet fungerer bare ikke på den måde, vi\n"
	.string "har brug for!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Av av av!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Du ved, vi tør ikke at udfordre vores\n"
	.string "lederes motiver.\p"
	.string "Men her står du, bare en eller anden\n"
	.string "fjollehoved, der går imod vores BOSS.\p"
	.string "Måske...  Du må være noget...$"



