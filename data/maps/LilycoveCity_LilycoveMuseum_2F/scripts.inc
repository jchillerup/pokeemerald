@ TRANSLATED

.set LOCALID_CURATOR, 1

LilycoveCity_LilycoveMuseum_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_OnFrame
	.byte 0

LilycoveCity_LilycoveMuseum_2F_OnLoad:
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting::
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting::
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting::
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting::
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting::
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, TRUE
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting::
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, TRUE
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting::
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, TRUE
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting::
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, TRUE
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting::
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, TRUE
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, TRUE
	end

LilycoveCity_LilycoveMuseum_2F_OnFrame:
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall::
	lockall
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit, MSGBOX_SIGN
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft:
	walk_in_place_faster_left
	step_end

LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall:
	face_up
	delay_16
	step_end

LilycoveCity_LilycoveMuseum_2F_EventScript_Curator::
	lockall
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer::
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests, MSGBOX_DEFAULT
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament::
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude, MSGBOX_DEFAULT
	givedecoration DECOR_GLASS_ORNAMENT
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament::
	call Common_EventScript_NoRoomForDecor
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit, MSGBOX_NPC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting::
	lockall
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting::
	lockall
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting::
	lockall
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting::
	lockall
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting::
	lockall
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_Girl::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_COOL
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_BEAUTY
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_CUTE
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_SMART
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_TOUGH
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall:
	.string "Dette er vores særlige udstillingshal.$"

LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall:
	.string "Som du tydeligt kan se, er der ikke\n"
	.string "en eneste maleri udstillet.\p"
	.string "Her ønsker jeg ikke at udstille værker\n"
	.string "af såkaldt klassisk kunst.\p"
	.string "Den slags klassiske værker kan du se\n"
	.string "på vores stueetage.\p"
	.string "Jeg ønsker at udstille værker, der er langt\n"
	.string "forskellige fra klassikerne.\p"
	.string "Kunst er trods alt ikke begrænset til gamle,\n"
	.string "berømte værker!\p"
	.string "Denne udstillingssal vil jeg gerne fylde med…\p"
	.string "Moderne og livlige kunstværker af\n"
	.string "POKéMON, der tilsyneladende er klar til\n"
	.string "at springe frem i en herlig liv!$"

LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit:
	.string "Undskyld, jeg mente det ikke\n"
	.string "som om jeg monopoliserede samtalen.\p"
	.string "Nu, da du er ung, og dog\n"
	.string "åbenlyst velforbundet…\p"
	.string "Du støder sikkert på livlige\n"
	.string "POKéMON og kunstværker med dem.\p"
	.string "Hvis du skulle finde sådan\n"
	.string "et maleri, må vi bede dig om at\l"
	.string "få kunstnerens tilladelse til at\n"
	.string "udstille det her?$"

LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit:
	.string "Jeg ønsker at fylde denne udstillingssal med\n"
	.string "moderne og livlige malerier af\l"
	.string "POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting:
	.string "Takket være dig har vi tilføjet et\n"
	.string "nyt maleri til vores samling!\p"
	.string "Jeg har hørt, at det forestiller din\n"
	.string "POKéMON. Virkelig fantastisk!\p"
	.string "Mange, mange tak!$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer:
	.string "Åh! Det er dig!\n"
	.string "{PLAYER}!$"

LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests:
	.string "Er det ikke fantastisk,\n"
	.string "dette udvalg af malerier!\p"
	.string "Hver eneste af dem fejlfri!\n"
	.string "Ingen bedre end en anden!\p"
	.string "Disse malerier har tiltrukket\n"
	.string "flere gæster til vores KUNSTMUSEUM.\p"
	.string "Jeg takker oprigtigt dig,\n"
	.string "{PLAYER}.\n"
	.string "Dette er min drøm, der går i opfyldelse!$"

LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude:
	.string "Dette er blot et lille gave\n"
	.string "for min taknemmelighed.$"

LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou:
	.string "Jeg vil gemme dette for dig, indtil vi\n"
	.string "mødes igen.$"

LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit:
	.string "Åh, så godt at se dig, {PLAYER}!\p"
	.string "Det er en ære at have dig på besøg\n"
	.string "på dine travle rejser.\p"
	.string "Tag det roligt og nyd dit\n"
	.string "besøg hos os.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame:
	.string "Det er en billedramme med lyserøde\n"
	.string "ornamenter.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame:
	.string "Det er en billedramme med\n"
	.string "gule pyntegenstande.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame:
	.string "Det er et billedramme med\n"
	.string "blå farvede udsmykninger.$" 

LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame:
	.string "Det er en billedramme med\n"
	.string "røde pyntegjenstande.\p$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame:
	.string "Det er en billedramme med\n"
	.string "grønfarvede udsmykninger.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon:
	.string "Det er et maleri af POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe:
	.string "Jeg har været væk i et stykke tid, så de nye\n"
	.string "malerier heroppe overraskede mig.\p"
	.string "Jeg ville ønske, at nogen ville male mine POKéMON\n"
	.string "så smukt.$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing:
	.string "Nå... Så det her er, hvor de viser\n"
	.string "de aktuelle POKéMON-malerier.\p"
	.string "Jeg må sige, disse nye malerier er\n"
	.string "virkelig underholdende.$"

LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon:
	.string "Wow, er det sandt?\n"
	.string "Disse malerier er af din POKéMON.\p"
	.string "Er det ikke bare den ultimative glæde\n"
	.string "for en TRÆNER?$"



