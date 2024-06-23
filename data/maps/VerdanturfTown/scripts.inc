@ TRANSLATED

.set LOCALID_TWIN, 2

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Min far fortalte mig.\p"
	.string "Han siger, at denne tunnel er fuld af\n"
	.string "bange POKéMON.\p"
	.string "De bliver skræmte af høje lyde og laver\n"
	.string "en stor ballade.\p"
	.string "Så de måtte stoppe det store tunnel-\n"
	.string "projekt.\p"
	.string "Men der er en mand. Han prøver at grave\n"
	.string "tunnelen selv!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Der var engang en mand, som gravede en\n"
	.string "tunnel til en dame, han elskede.\p"
	.string "Jeg fatter det ikke rigtigt, men hey!$"

VerdanturfTown_Text_AirCleanHere:
	.string "Vejret blæser, og vulkansk aske blæses\n"
	.string "aldrig i denne retning.\p"
	.string "Luften er ren og lækker her. At bo her\n"
	.string "burde gavne selv skrøbelige og sygelige\l"
	.string "personer.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Min POKéMON og jeg har været på en\n"
	.string "vindende stime.\p"
	.string "Så jeg besluttede mig for at gøre min\n"
	.string "debut i BATTLE TENTEN i denne by.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Har du set hulen ved siden af POKéMON\n"
	.string "MART?\p"
	.string "Der er en fyr derinde, der prøver at\n"
	.string "knuse sten for at komme ud på den anden\l"
	.string "side.\p"
	.string "Det ville være dejligt, hvis vi kunne gå\n"
	.string "igennem... Det gør det nemt at besøge\l"
	.string "RUSTBORO.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Den grotte ved siden af POKéMON-MARTE\n"
	.string "er nu en tunnel til den anden side.\p"
	.string "Det er fantastisk--det er nemt at gå\n"
	.string "shoppe efter nye DEVON-produkter i\l"
	.string "RUSTBORO nu.$"

VerdanturfTown_Text_TownSign:
	.string "VERDANTURF BY\p"
	.string "“De vindblæste højdedrag med den søde\n"
	.string "duft af græs.”$"

VerdanturfTown_Text_WandasHouse:
.string "WANDAS HUS$"

VerdanturfTown_Text_BattleTentSign:
	.string "KAMP TELT GRØNSKÆRM PLADS “Mæsk dine\n"
	.string "øjne i kampe!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "RUSTURF TUNNEL “Forbinder RUSTBORO og\n"
	.string "VERDANTURF.\p"
	.string "“Tunnelprojektet er blevet aflyst.”$"



