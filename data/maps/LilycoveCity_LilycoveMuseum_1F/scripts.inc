@ TRANSLATED

.set LOCALID_CURATOR, 2
.set LOCALID_ARTIST_2, 8

LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
	.string "Velkommen til LILYCOVE MUSEUM.\p"
	.string "Tag dig venligst tid til at nyde\n"
	.string "vores fantastiske samling af\n"
	.string "kunstværker med POKéMON.$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
	.string "Jeg er KURATOREN af dette MUSEUM for\n"
	.string "billedkunst.\p"
	.string "Det glæder mig at se nogen så\n"
	.string "ung som dig i vores MUSEUM.\p"
	.string "Har du allerede set vores samling af\n"
	.string "malerier?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
	.string "Åh, så lad mig ikke forstyrre dig.\n"
	.string "Tag dig god tid.$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
	.string "Åh? Jeg tror, at du virker som en\n"
	.string "POKéMON-TRÆNER.\p"
	.string "Har du også interesse i malerier?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
	.string "Jeg ser…\p"
	.string "Jeg er beæret over, at du ville\n"
	.string "besøge os trods det.$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
	.string "Åh, fantastisk!\n"
	.string "Du kan lide malerier!\p"
	.string "Vil du så følge med mig?$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
	.string "Det er et meget gammelt maleri.\n"
	.string "Malingen skaller af hist og her.$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
	.string "Det er et mærkeligt landskab med\n"
	.string "bizarre og fantastisk scenery.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
	.string "Det er et maleri af en smuk, smilende\n"
	.string "kvinde med en POKéMON på sit skød.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
	.string "Det er et maleri af en legendarisk POKéMON\n"
	.string "fra længe siden.\p"
	.string "Kunstneren malede dette ud fra\n"
	.string "fantasi.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
	.string "Det er et maleri af GRÆS POKéMON\n"
	.string "svajende i en brise.\p"
	.string "Det ser ud til, at de nyder vinden's\n"
	.string "blide kærtegn.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
	.string "Det er et lækkert udseende maleri\n"
	.string "af BÆR.\p"
	.string "Dette maleri kunne få dig til at blive sulten!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
	.string "Det er en replika af en berømt skulptur.\p"
	.string "Den forestiller en gammel FUGL POKéMON.$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
	.string "Det er en stor POKé BALL udskåret\n" \n
	.string "i sort sten.\p" \n
	.string "Den blev åbenbart brugt til fester\n" \n
	.string "i gamle dage.$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
	.string "Det er en kæmpestor stentavle med\l"
	.string "indskrifter om POKéMON og tæt tekst\l"
	.string "i de små karakterer af et gammelt,\l"
	.string "ulæseligt sprog.$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
	.string "Hmm…\n"
	.string "Hvilke værker af stor pragt…$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
	.string "At kæmpe med POKéMON er sjovt,\n"
	.string "det må jeg give dig ret i.\p"
	.string "Men man må ikke glemme vores kærlighed\n"
	.string "for de skønne kunstarter.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
	.string "Dette KUNSTMUSEUM… Nå, du kunne\n"
	.string "se mange fantastiske malerier.\p"
	.string "Og KURATOREN er en fantastisk person.\p"
	.string "Blandt kunstnere som mig selv, dette\n"
	.string "MUSEUM er en inspirasjon.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
	.string "Denne dame er smuk!\n"
	.string "Hun ligner mor!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
	.string "Denne POKéMON er uimodståelig!\n"
	.string "Præcis som vores lille dreng!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
	.string "Jeg havde hørt, at dette KUNSTMUSEUM\n"
	.string "havde fået nogle nye malerier.\p"
	.string "Så jeg skyndte mig naturligvis derhen.\p"
	.string "Er de nye malerier hængt op på\n"
	.string "anden sal?$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
	.string "For nylig har KURATOREN været\n"
	.string "usædvanligt glad.\p"
	.string "Jeg satser på, at noget godt er sket for ham.\n"
	.string "Helt sikkert.$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
	.string "Jeg håber at se mange fantastiske malerier\n"
	.string "her og lære af dem.\p"
	.string "Jeg drømmer om en dag at have mine\n"
	.string "kunstværker udstillet her.$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
	.string "Kunstmuseet er blevet en favorit\n"
	.string "turistdestination.\p"
	.string "Det er fantastisk for LILYCOVE…\n"
	.string "Nej, fantastisk for HOENN-regionen!\p"
	.string "Dette er hvad jeg har hørt--en enkelt\n"
	.string "TRÆNER erhvervede alle malerierne ovenpå.$"



