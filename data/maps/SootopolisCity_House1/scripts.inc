@ TRANSLATED

SootopolisCity_House1_MapScripts::
	.byte 0

SootopolisCity_House1_EventScript_BrickBreakBlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_BRICK_BREAK, SootopolisCity_House1_EventScript_ReceivedBrickBreak
	msgbox SootopolisCity_House1_Text_DevelopedThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_BRICK_BREAK
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_ReceivedBrickBreak::
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox SootopolisCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House1_Text_DevelopedThisTM:
	.string "I tredive år har jeg forblivt i\n"
	.string "SOOTOPOLIS og finpudset mine\l"
	.string "færdigheder.\p"
	.string "Jeg har udviklet en knusende TM. Jeg\n"
	.string "efterlader den til dig!$"

SootopolisCity_House1_Text_ExplainBrickBreak:
	.string "TM31 indeholder MURBRYDER! Det er et\n"
	.string "træk så forfærdeligt, at jeg ikke kan\l"
	.string "beskrive det.$"

SootopolisCity_House1_Text_Kecleon:
.string "KECLEON: Puu puhyaah.$"



