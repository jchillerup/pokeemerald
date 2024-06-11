// TRANSLATED
ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) static const u8 sText_Colon[] = _(":");
ALIGNED(4) static const u8 sText_ID[] = _("{ID}");
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("Ups! Ser ud til, at vi skal starte forfra.");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("Åh nej! Søgningen på WIRELESS KOMMUNIKATIONSSYSTEMET er blevet annulleret.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("Shhh... Venter på en hemmelig besked fra en anden spiller."); // Ikke brugt
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1}! Venter på\nen besked fra en anden spiller.");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1}! Venter på et link!\nTryk på START, når alle er klar.");
ALIGNED(4) static const u8 sJPText_SingleBattle[] = _("Let's have a Single Battle");
ALIGNED(4) static const u8 sJPText_DoubleBattle[] = _("How about a Double Battle?");
ALIGNED(4) static const u8 sJPText_MultiBattle[] = _("Time for a Multi Battle!");
ALIGNED(4) static const u8 sJPText_TradePokemon[] = _("Let's trade Pokémon");
ALIGNED(4) static const u8 sJPText_Chat[] = _("Fancy a Chat");
ALIGNED(4) static const u8 sJPText_DistWonderCard[] = _("Distributing a Mysterious Card");
ALIGNED(4) static const u8 sJPText_DistWonderNews[] = _("Spreading Mystery News");
ALIGNED(4) static const u8 sJPText_DistMysteryEvent[] = _("Getting ready for a Mysterious Event"); // Unused
ALIGNED(4) static const u8 sJPText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("1 spiller\nnødvendig.");
static const u8 sText_2PlayersNeeded[] = _("2 spillere\nnødvendige.");
static const u8 sText_3PlayersNeeded[] = _("3 spillere\nnødvendige.");
static const u8 sText_4PlayersNeeded[] = _("4 spillere\nnødvendige.");
static const u8 sText_2PlayerMode[] = _("2-SPILLER\nMODUS");
static const u8 sText_3PlayerMode[] = _("3-SPILLER\nMODUS");
static const u8 sText_4PlayerMode[] = _("4-SPILLER\nMODUS");
static const u8 sText_5PlayerMode[] = _("5-SPILLER\nMODUS");

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}ANNULLER");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} kontaktede dig for\n{STR_VAR_1}. Accepterer du?");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2} har kontaktet dig.\nVil du dele {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} har kontaktet dig.\nTilføj til medlemmerne?");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1}!\nEr disse medlemmer OK?");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("Annuller {STR_VAR_1} MODE\nmed disse medlemmer?");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("Der blev sendt et ”OK” til\n{STR_VAR_1}.");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("Den anden TRÆNER ser ikke ud til\nat være tilgængelig lige nu...\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("Du kan ikke transmittere med en TRÆNER,\nsom er for langt væk.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("Den anden TRÆNER(E) er/er ikke\nklar endnu.\p");

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("{STR_VAR_1} MODEt med\ndisse medlemmer vil blive annulleret.{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("Der er et medlem, som ikke\nlængere kan være tilgængeligt.\p");

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("Den anden TRÆNER virker\nutilgængelig...\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{STR_VAR_1} sendte et ”OK” tilbage!");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1} bekræftede din registrering som\nmedlem.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} svarede, ”Nej...”\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nVenter på andre medlemmer!");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("Vil du stoppe med at være medlem?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("Du er ikke længere medlem.\p");

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("WIRELESS KOMMUNIKATIONSSYSTEM forbindelsen er etableret.");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("WIRELESS KOMMUNIKATIONSSYSTEM forbindelsen er afbrudt...");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("Forbindelsen med din ven er blevet afbrudt...");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} svarede, Nej...");

static const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("Vil du have {STR_VAR_2}\nTILSTANDEN?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("Vil du have {STR_VAR_2}\nTILSTANDEN?");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("Kommunikerer...\nVent venligst."); // Ubegrugt
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _("Venter på {STR_VAR_1}'s svar om\nhandlen...");
ALIGNED(4) static const u8 sText_Communicating[] = _("Kommunikerer{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                     "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("Kommunikerer med {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                               "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("Vent venligst{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                        "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Hej! Er der noget, du\ngerne vil lave?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Hej!\nVil du gerne lave noget?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: Hej, vi mødes igen!\nHvad har du lyst til denne gang?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: Åh! {PLAYER}, hej!\nVil du gerne lave noget?");

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Har lyst til at lave noget?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Kunne du tænke dig at lave noget?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: Hvad har du lyst til at\nlave nu?");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}: Har du lyst til at lave\nmere?"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Nogen har kontaktet dig.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} har kontaktet dig.{PAUSE 60}");

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("Afventer svar fra\nden anden TRÆNER…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("Afventer svar fra\n{STR_VAR_1}…");

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("Den anden TRÆNER har vist\ndig deres TRÆNERKORT.\pVil du vise dit\nTRÆNERKORT?");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("Den anden TRÆNER udfordrer dig\npå kamp.\pVil du acceptere kamp-\nudfordringen?");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("Den anden TRÆNER inviterer dig\ntil at chatte.\pVil du acceptere chat-\ninvitationen?");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("Der er et tilbud om at bytte din\ntilmeldte Lv. {DYNAMIC 0} {DYNAMIC 1}\nmod en Lv. {DYNAMIC 2} {DYNAMIC 3}.\pVil du acceptere dette\nbyttetilbud?");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("Der er et tilbud om at bytte din\ntilmeldte ÆG.\lVil du acceptere dette\nbyttetilbud?");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("Chatten er afsluttet.\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("Du afslog tilbuddet.\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("Du afslog tilbuddet.\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("Chatten er slut.\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("Hej! Vi chatter lige nu.\nVil du være med?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Hej, {PLAYER}!\nVi chatter lige nu.\lHar du lyst til at være med?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Hej! Vi chatter lige nu.\nHar du lyst til at være med?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Hej, {PLAYER}!\nVi chatter lige nu.\lVil du være med?");

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("......\nTRÆNEREN ser ud til at være optaget…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("En kamp, huh?\nOkay, giv mig bare lidt tid.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("Vil du chatte, huh?\nSelvfølgelig, bare vent lidt.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("Selvfølgelig! Som min 'Hilsen'\nher er mit TRÆNINGSKORT.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("En kamp? Selvfølgelig, men jeg har\nbrug for tid til at forberede mig.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Ville du chatte?\nOkay, men vent venligst et øjeblik.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("Til min præsentation, vil jeg vise dig\nmit TRÆNINGSKORT.");

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("Vil du chatte, huh?\nSelvfølgelig, bare vent lidt."); // Ubrugt
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Tak fordi du ventede!\nLad os få vores kamp i gang!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("Super!\n Lad os chatte!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Undskyld, at jeg lod dig vente!\n Lad os komme i gang!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Undskyld, jeg fik dig til at vente!\nLad os sludre.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("Handlen vil blive startet.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("Kampen vil blive startet.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Går ind i chatten…{PAUSE 60}");

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Undskyld! Mine POKéMON virker\nikke helt friske lige nu.\lVi kan kæmpe en anden gang.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("Jeg er meget ked af det, men mine POKéMON\nhar det ikke så godt…\pVi kan kæmpe en anden gang.\p");

static const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("Hov? Mit TRÆNERKORT…\nHvor er det nu igen?\lBeklager! Jeg viser dig det en anden gang!\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Åh? Hvor mon jeg lagde mit\nTRÆNERKORT?…\lBeklager! Jeg viser dig det senere!\p");

static const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("Hvis du vil lave noget sammen\nmed mig, så råb bare!\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("Hvis du har lyst til at lave noget sammen\nmed mig, så vær ikke genert.\p");

static const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("Ups! Beklager, men jeg skal lige\nlave noget andet.\lEn anden gang, okay?\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("Hvis du vil kæmpe, skal du have\nto POKéMON, der er under\lLv. 30.\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("Til en kamp skal du have to\nPOKéMON, der er under Lv. 30.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("Nå, okay.\nKom bare forbi når som helst, okay?\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Åh…\nKom venligst forbi når som helst.\p");

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Åh, undskyld!\nJeg kan desværre ikke lige nu.\lVi kan sludre en anden gang.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Åh, undskyld.\nJeg har alt for meget at lave lige nu.\lLad os snakke en anden gang.\p");

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Whoa!\nJeg kan se, at du er ret sej!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("Du brugte den bevægelse?\nDet er en god strategi!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Godt klaret!\nDet var en øjenåbner!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Åh! Hvordan kunne du bruge den\nPOKéMON i den situation?\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("Den POKéMON…\nDen er virkelig blevet godt opdraget!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("Det er det!\nDet er det rigtige træk nu!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("Det er fantastisk!\nKan du kæmpe på den måde?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("Du har en udsøgt timing for\nat skifte POKéMON!\p");

static const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    },
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Åh, jeg forstår!\nDet er lærerigt!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("Sig ikke mere sjove ting!\nJeg har ondt af at grine!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Åh?\nNoget sådan skete.\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Hmhm… Hvad?\nEr det det, du siger?\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("Er det rigtigt?\nDet vidste jeg ikke.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Ahaha!\nHvad handler det om?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Ja, præcis!\nDet er hvad jeg mente.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("Med andre ord…\nJa! Præcis!\p");

static const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    },
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("Jeg viser bare mit TRÆNERKORT\nsom min måde at hilse på.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("Jeg håber, at jeg lærer dig bedre at kende!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("Vi viser hinanden vores\nTRÆNERKORT for at blive bekendte.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("Hyggeligt at møde dig.\nVær venlig ikke at være en fremmed!\p");

static const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    },
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Jaaaah!\nJeg ønskede virkelig denne POKéMON!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Endelig, en handel gav mig den\nPOKéMON, jeg havde ønsket i lang tid.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("Jeg handler POKéMON lige nu.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("Jeg fik endelig den POKéMON,\njeg ønskede i en handel!\p");

static const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    },
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1} checkede\nHANDELSTAVLEN.\p");
ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _("Velkommen til HANDELSTAVLEN.\pDu kan registrere din POKéMON\nog tilbyde den til handel.\nVil du registrere en af\ndine POKéMON'er?");
ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _("Denne BYTTETAVLE bruges til\n"
                                                        "at tilbyde en POKéMON til bytte.\p"
                                                        "Alt du skal gøre er at registrere en\n"
                                                        "POKéMON til bytte.\p"
                                                        "En anden TRÆNER kan tilbyde en POKéMON\n"
                                                        "i sin gruppe som bytte.\p"
                                                        "Vi håber, at du vil registrere POKéMON\n"
                                                        "og bytte dem med mange, mange\l"
                                                        "andre TRÆNERE.\p"
                                                        "Vil du registrere en af dine POKéMON?");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("Vi har registreret din POKéMON til\nhandel på HANDELSTAVLEN.\pTak fordi du benyttede denne service!\p"); // ubrugt
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("Ingen har registreret nogen POKéMON\ntil handel på HANDELSTAVLEN.\p\n"); // ubrugt
ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _("Vælg venligst typen af POKéMON,\nsom du ønsker at bytte med.\n");
ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _("Hvilken af dine POKéMON fra dit hold\nvil du tilbyde i bytte?\p");
ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("Tilmeldingen er blevet annulleret.\p");
ALIGNED(4) static const u8 sText_RegistraionCompleted[] = _("Tilmeldingen er gennemført.\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("Handlen er blevet annulleret.\p");
ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _("Vil du annullere tilmeldingen af din\nLv. {STR_VAR_2} {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _("Vil du annullere tilmeldingen af dit\nÆG?");
ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("Tilmeldingen er blevet annulleret.\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("TRÆNERE, der ønsker at handle,\nvil blive opført."); // unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("Vælg venligst TRÆNEREN, du gerne vil\nhandle POKéMON med."); // unused
ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _("Vil du bede {STR_VAR_1} om at\nlave en handel?");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("Venter på svar fra\nden anden TRÆNER…"); // unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("Du har ikke tilmeldt en POKéMON\ntil handel.\p"); // unused
ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _("Du har ikke en {STR_VAR_2}-type\nPOKéMON, som {STR_VAR_1} ønsker.\p");
ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _("Du har ikke et ÆG, som\n{STR_VAR_1} ønsker.\p");
ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1} kan ikke handle om\ndin POKéMON lige nu.\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("Du kan ikke handle om\n{STR_VAR_1}s POKéMON lige nu.\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("Dit handelstilbud blev afvist.\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("ÆG-HANDEL");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}VÆLG  {A_BUTTON}Deltag  {B_BUTTON}Annuller");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("Vælg venligst en TRÆNER.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Vælg venligst en TRÆNER til\nenkeltkamp.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Vælg venligst en TRÆNER til\ndobbeltkamp.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Vælg venligst LEDEREN\nfor en MULTIKAMP.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Vælg venligst TRÆNEREN at\nhandle med.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("Vælg venligst TRÆNEREN, som\ndeler VIDUNDERKORT med.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("Vælg venligst TRÆNEREN, som\ndeler VIDUNDERNYHEDER med.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Hopp med mini POKéMON!\nVælg venligst LEDEREN.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("BÆRKNUS!\nVælg venligst LEDEREN.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("DODRIO BÆRPLUKNING!\nVælg venligst LEDEREN.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("BÆRBLÆNDER!\nVælg venligst LEDEREN.");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("REKORDHJØRNET!\nVælg venligst LEDEREN.");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("FEDHEDSKONKURRENCEN!\nVælg venligst LEDEREN.");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("SKØNHEDSKONKURRENCEN!\nVælg venligst LEDEREN.");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("SØD KONKURRENCE!\nVælg venligst LEDEREN.");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("SMARTE KONKURRENCE!\nVælg venligst LEDEREN.");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("HÅRDE KONKURRENCE!\nVælg venligst LEDEREN.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("KAMP TOWER NIVEAU 50!\nVælg venligst LEDEREN.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("KAMP TOWER ÅBEN NIVEAU!\nVælg venligst LEDEREN.");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("Søger efter et TRÅDLØST\nKOMMUNIKATIONSSYSTEM. Vent...");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("For at have en DOPPELT KAMP, skal du have\nmindst to POKéMON.\p"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("Venter på {STR_VAR_1}'s svar...");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1} er blevet bedt om at registrere\ndig som medlem. Vent venligst.");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("Venter på svar fra det\nTRÅDLØSE KOMMUNIKATIONSSYSTEM.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("Vent venligst på, at de andre TRENERE\nsamler sig og gør sig klar."); // Unused
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("Der er ingen KORT som deles\nlige nu.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("Der er ingen NYHEDER som deles\nlige nu.");

static const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) static const u8 sText_Battle[] = _("KAMP");
ALIGNED(4) static const u8 sText_Chat2[] = _("CHAT");
ALIGNED(4) static const u8 sText_Greetings[] = _("HEJ");
ALIGNED(4) static const u8 sText_Exit[] = _("AFSLUT");
ALIGNED(4) static const u8 sText_Exit2[] = _("AFSLUT");
ALIGNED(4) static const u8 sText_Info[] = _("INFO");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("NAVN{CLEAR_TO 60}ØNSKET{CLEAR_TO 110}TILBUD{CLEAR_TO 198}NIV.");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("ENKELTKAMP");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("DOBBELTKAMP");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("FLERPERSONERSKAMP");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("POKéMON BYTTER");
ALIGNED(4) static const u8 sText_Chat[] = _("CHAT");
ALIGNED(4) static const u8 sText_Cards[] = _("KORT");
ALIGNED(4) static const u8 sText_WonderCards[] = _("WUNDERKORT");
ALIGNED(4) static const u8 sText_WonderNews[] = _("WUNDER-NYT");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("POKéMON HOPPER");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("BÆRKNUSE");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("BÆRPLUK");
ALIGNED(4) static const u8 sText_Search[] = _("SØG");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("BÆRBLÆNDER");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("REKORDHJØRNE");
ALIGNED(4) static const u8 sText_CoolContest[] = _("FED KONKURRENCE");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("SKØNHEDSKONKURRENCE");
ALIGNED(4) static const u8 sText_CuteContest[] = _("NUTTET KONKURRENCE");
ALIGNED(4) static const u8 sText_SmartContest[] = _("SMART KONKURRENCE");
ALIGNED(4) static const u8 sText_ToughContest[] = _("SEJ KONKURRENCE");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("KAMPENS TÅRN NIV. 50");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("KAMPENS TÅRN ÅBEN NIVEAU");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("Det er et NORMALT KORT.");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("Det er et BRONZE KORT!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("Det er et KOBBER KORT!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("Det er et SØLV KORT!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("Det er et GOUD KORT!");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("Dette er {DYNAMIC 0} {DYNAMIC 1}'s\nTRÆNER KORT…\lPOKÉDEX: {DYNAMIC 3}\nTID:    {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("KAMPE: SEJRE: {DYNAMIC 0}  TAB: {DYNAMIC 2}\nBYTTER: {DYNAMIC 3}\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: Dejligt at have mødt dig!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: Dejligt at have mødt dig!{PAUSE 60}");

static const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("Færdig med at tjekke {DYNAMIC 1}'s\nTRÆNERKORT.{PAUSE 60}");

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP]   = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP]   = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max)(((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity)(capacity & 0x0F)
#define GROUP_MIN(capacity)(capacity >> 4)
#define GROUP_MIN2(capacity)(capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_INVISIBLE
};

static const struct WindowTemplate sWindowTemplate_GroupList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_PlayerNameAndId = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00ee
};

static const struct ListMenuItem sUnionRoomGroupsMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = sUnionRoomGroupsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(sUnionRoomGroupsMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 5,
    .width = 16,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sInviteToActivityMenuItems[] = {
    { sText_Greetings, ACTIVITY_CARD | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Battle,    ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Chat2,     ACTIVITY_CHAT | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Exit,      ACTIVITY_NONE | IN_UNION_ROOM }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = sInviteToActivityMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sInviteToActivityMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0,
    .tilemapLeft = 18,
    .tilemapTop = 7,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardRequestType = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 16,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES] = {
    { gTypeNames[TYPE_NORMAL],   TYPE_NORMAL         },
    { gTypeNames[TYPE_FIRE],     TYPE_FIRE           },
    { gTypeNames[TYPE_WATER],    TYPE_WATER          },
    { gTypeNames[TYPE_ELECTRIC], TYPE_ELECTRIC       },
    { gTypeNames[TYPE_GRASS],    TYPE_GRASS          },
    { gTypeNames[TYPE_ICE],      TYPE_ICE            },
    { gTypeNames[TYPE_GROUND],   TYPE_GROUND         },
    { gTypeNames[TYPE_ROCK],     TYPE_ROCK           },
    { gTypeNames[TYPE_FLYING],   TYPE_FLYING         },
    { gTypeNames[TYPE_PSYCHIC],  TYPE_PSYCHIC        },
    { gTypeNames[TYPE_FIGHTING], TYPE_FIGHTING       },
    { gTypeNames[TYPE_POISON],   TYPE_POISON         },
    { gTypeNames[TYPE_BUG],      TYPE_BUG            },
    { gTypeNames[TYPE_GHOST],    TYPE_GHOST          },
    { gTypeNames[TYPE_DRAGON],   TYPE_DRAGON         },
    { gTypeNames[TYPE_STEEL],    TYPE_STEEL          },
    { gTypeNames[TYPE_DARK],     TYPE_DARK           },
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardHeader = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 2,
    .paletteNum = 13,
    .baseBlock = 0x0001
};

static const struct WindowTemplate sWindowTemplate_TradingBoardMain = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, LIST_HEADER },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// Unused
static const struct WindowTemplate sWindowTemplate_Unused = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sEmptyListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ItemPrintFunc_EmptyList,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

ALIGNED(4) static const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD,
    ACTIVITY_WONDER_NEWS,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

static const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};
