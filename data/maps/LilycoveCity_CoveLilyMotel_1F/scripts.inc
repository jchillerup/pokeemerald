@ TRANSLATED

.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hmm, så fordoblede de gæsterne ved at\n"
	.string "bruge POKéMON som attraktioner?\p"
	.string "Hmm, måske skulle jeg gøre en sød\n"
	.string "POKéMON til vores kro's maskot.\p"
	.string "Jeg undrer mig over, om det vil\n"
	.string "tiltrække flere gæster til at blive\n"
	.string "hos os?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Åh, undskyld, undskyld!\n"
	.string "Jeg var for meget optaget af at se tv!\p"
	.string "Siden HOLD AQUA kom til byen,\n"
	.string "har turisterne holdt sig væk.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Hej, nede foran!\n"
	.string "Jeg kan ikke se fjernsynet!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Fantastisk! Siger du, at en POKéMON\n"
	.string "har fundet en tabt genstand?\p"
	.string "Det er noget. Hvis vi havde nogle kloge\n"
	.string "POKéMON som den…\p"
	.string "Så kunne vi finde alt, vores gæster\n"
	.string "har tabt…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Åh, undskyld, undskyld!\n"
	.string "Jeg var alt for optaget af at se TV!\p"
	.string "Jeg hørte, at nogen bustede\n"
	.string "TEAM AQUA HIDEOUT.\p"
	.string "Takket være det har vi lige\n"
	.string "fået en reservation fra en stor gruppe.\p"
	.string "Det var et firma kaldet… Øh…\n"
	.string "GAME noget...$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Fantastisk! En husvagt POKéMON\n"
	.string "fangede en indbrudstyv?\p"
	.string "Det er noget. Hvis vi havde en robust\n"
	.string "POKéMON som vagthund…\p"
	.string "Kunne vi kunne give vores gæster\n"
	.string "bedre sikkerhed.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Åh, undskyld, undskyld!\n"
	.string "Jeg var for dybt optaget af at se TV.\p"
	.string "Åh, ja. En stor gruppe gæster ankom\n"
	.string "for lidt siden.\p"
	.string "De reserverede som GAME FREAK,\n"
	.string "så jeg antager, de laver spil.\p"
	.string "Åh-åh, jeg burde nok gå i gang med\n"
	.string "deres aftensmad!$"



