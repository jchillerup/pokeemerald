@ TRANSLATED

.set LOCALID_VIVI, 1
.set LOCALID_VICTOR, 2
.set LOCALID_VICTORIA, 3
.set LOCALID_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Du er den første TRÆNER, jeg har set, der\n"
	.string "udsender POKéMON så mesterligt.\p"
	.string "Men jeg bliver nødt til at fortælledig -- min\n"
	.string "søn er stærkere end dig.\p"
	.string "Han har endda taget udfordringenPOKéMON\n"
	.string "LIGAEN, skal du vide.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Vi bruger dette MACHO-BRAS til at styrke\n"
	.string "vores POKéMON mere effektivt under\l"
	.string "træning.\p"
	.string "Da du har besejret os alle her, ved jeg ikke,\n"
	.string "om du har brug for det, men vi vil gerne give\l"
	.string "dig vores MACHO-BRAS.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Når det kommer til POKéMON-kampe, plejer vi\n"
	.string "at være ret passionerede.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Mor er stærkere end Far.\p"
	.string "Jeg er stærkere end Mor.\p"
	.string "Og Bedstemor er stærkere end mig!\p"
	.string "Men min storebror er endnu stærkere end\n"
	.string "Bedstemor.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Der er ingen tvivl om, at du er stærk.\p"
	.string "Men hvis du skulle kæmpe mod min barnebarn,\n"
	.string "ville du ende med at græde af frustration.\p"
	.string "Han er meget stærkere end nogen TRÆNER,\n"
	.string "vores familie kender.\p"
	.string "Han må være i gang med at udfordre POKéMON\n"
	.string "LIGAMESTEREN lige nu.\p"
	.string "Kender jeg mit barnebarn ret, så er han\n"
	.string "måske allerede MESTEREN!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Min barnebarn må udfordre POKéMON\n"
	.string "LIGAMESTEREN nu.\p"
	.string "Kender jeg mit barnebarn ret, så kunne han\n"
	.string "allerede være MESTER!$"



