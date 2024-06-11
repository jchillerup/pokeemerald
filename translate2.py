import re
from rich.progress import track
import rich
from translate import PROMPT, client


MAPFILES = [
    'data/event_scripts.s',
    'data/scripts/gift_old_sea_map.inc',
    'data/scripts/gift_trainer.inc',
    'data/scripts/gift_pichu.inc',
    'data/scripts/contest_hall.inc',
    'data/scripts/lilycove_lady.inc',
    'data/scripts/gift_mystic_ticket.inc',
    'data/scripts/gift_aurora_ticket.inc',
    'data/scripts/secret_base.inc',
    'data/scripts/berry_blender.inc',
    'data/scripts/repel.inc',
    'data/scripts/profile_man.inc',
    'data/scripts/gift_altering_cave.inc',
    'data/scripts/test_signpost.inc',
    'data/scripts/day_care.inc',
    'data/scripts/gift_stamp_card.inc',
    'data/scripts/mauville_man.inc',
    'data/scripts/safari_zone.inc',
    'data/scripts/gift_battle_card.inc',
    'data/scripts/roulette.inc',
    'data/scripts/berry_tree.inc',
    'data/scripts/field_move_scripts.inc',
    'data/scripts/secret_power_tm.inc',
    'data/scripts/shared_secret_base.inc',
    'data/maps/MossdeepCity_Gym/scripts.inc',
    'data/maps/VerdanturfTown_WandasHouse/scripts.inc',
    'data/maps/LilycoveCity_DepartmentStore_4F/scripts.inc',
    'data/maps/DewfordTown_House2/scripts.inc',
    'data/maps/RustboroCity_DevonCorp_2F/scripts.inc',
    'data/maps/MossdeepCity_PokemonCenter_2F/scripts.inc',
    'data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.inc',
    'data/maps/AbandonedShip_HiddenFloorCorridors/scripts.inc',
    'data/maps/Route110_TrickHousePuzzle7/scripts.inc',
    'data/maps/MeteorFalls_1F_2R/scripts.inc',
    'data/maps/VictoryRoad_B2F/scripts.inc',
    'data/maps/BattleFrontier_BattlePyramidLobby/scripts.inc',
    'data/maps/MauvilleCity/scripts.inc',
    'data/maps/VictoryRoad_1F/scripts.inc',
    'data/maps/AbandonedShip_HiddenFloorRooms/scripts.inc',
    'data/maps/AquaHideout_B1F/scripts.inc',
    'data/maps/MtChimney/scripts.inc',
    'data/maps/PetalburgCity_House1/scripts.inc',
    'data/maps/ShoalCave_LowTideLowerRoom/scripts.inc',
    'data/maps/RustboroCity_DevonCorp_1F/scripts.inc',
    'data/maps/Route110_TrickHousePuzzle6/scripts.inc',
    'data/maps/MeteorFalls_StevensCave/scripts.inc',
    'data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.inc',
    'data/maps/DewfordTown_PokemonCenter_1F/scripts.inc',
    'data/maps/PacifidlogTown_House1/scripts.inc',
    'data/maps/Route110_TrickHousePuzzle8/scripts.inc',
    'data/maps/MossdeepCity_PokemonCenter_1F/scripts.inc',
    'data/maps/Route110_TrickHousePuzzle1/scripts.inc',
    'data/maps/DewfordTown/scripts.inc',
    'data/maps/SlateportCity_Mart/scripts.inc',
    'data/maps/VictoryRoad_B1F/scripts.inc',
    'data/maps/PacifidlogTown/scripts.inc',
    'data/maps/SlateportCity_Harbor/scripts.inc',
    'data/maps/BattleFrontier_BattleDomeLobby/scripts.inc',
    'data/maps/MeteorFalls_1F_1R/scripts.inc',
    'data/maps/Route113_GlassWorkshop/scripts.inc',
    'data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.inc',
    'data/maps/MossdeepCity_House1/scripts.inc',
    'data/maps/AquaHideout_B2F/scripts.inc',
    'data/maps/MauvilleCity_GameCorner/scripts.inc',
    'data/maps/RustboroCity_Flat2_3F/scripts.inc',
    'data/maps/LilycoveCity_House2/scripts.inc',
    'data/maps/RustboroCity_Flat1_1F/scripts.inc',
    'data/maps/EverGrandeCity_PokemonCenter_1F/scripts.inc',
    'data/maps/OldaleTown_House1/scripts.inc',
    'data/maps/FortreeCity_Mart/scripts.inc',
    'data/maps/OldaleTown_Mart/scripts.inc',
    'data/maps/PetalburgCity_PokemonCenter_1F/scripts.inc',
    'data/maps/NewMauville_Entrance/scripts.inc',
    'data/maps/AbandonedShip_Rooms2_1F/scripts.inc',
    'data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.inc',
    'data/maps/Route124/scripts.inc',
    'data/maps/BattleFrontier_BattleTowerLobby/scripts.inc',
    'data/maps/Route123/scripts.inc',
    'data/maps/SootopolisCity_House1/scripts.inc',
    'data/maps/BattleFrontier_ReceptionGate/scripts.inc',
    'data/maps/MossdeepCity_Mart/scripts.inc',
    'data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.inc',
    'data/maps/Route115/scripts.inc',
    'data/maps/Route112/scripts.inc',
    'data/maps/RustboroCity_Gym/scripts.inc',
    'data/maps/FarawayIsland_Interior/scripts.inc',
    'data/maps/MtPyre_2F/scripts.inc',
    'data/maps/RustboroCity_Flat1_2F/scripts.inc',
    'data/maps/SootopolisCity_House6/scripts.inc',
    'data/maps/RusturfTunnel/scripts.inc',
    'data/maps/LavaridgeTown_Mart/scripts.inc',
    'data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.inc',
    'data/maps/SlateportCity_PokemonFanClub/scripts.inc',
    'data/maps/MirageTower_4F/scripts.inc',
    'data/maps/LilycoveCity_House4/scripts.inc',
    'data/maps/EverGrandeCity_PokemonLeague_1F/scripts.inc',
    'data/maps/OldaleTown/scripts.inc',
    'data/maps/Route114_FossilManiacsTunnel/scripts.inc',
    'data/maps/LilycoveCity_House3/scripts.inc',
    'data/maps/AquaHideout_1F/scripts.inc',
    'data/maps/SootopolisCity_House7/scripts.inc',
    'data/maps/Route113/scripts.inc',
    'data/maps/Route116_TunnelersRestHouse/scripts.inc',
    'data/maps/Route114/scripts.inc',
    'data/maps/BattleFrontier_BattlePalaceCorridor/scripts.inc',
    'data/maps/BattleFrontier_BattlePyramidTop/scripts.inc',
    'data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.inc',
    'data/maps/MagmaHideout_1F/scripts.inc',
    'data/maps/MtPyre_1F/scripts.inc',
    'data/maps/BattleFrontier_PokemonCenter_1F/scripts.inc',
    'data/maps/RustboroCity_CuttersHouse/scripts.inc',
    'data/maps/LilycoveCity/scripts.inc',
    'data/maps/LilycoveCity_PokemonCenter_1F/scripts.inc',
    'data/maps/EverGrandeCity_HallOfFame/scripts.inc',
    'data/maps/Route109/scripts.inc',
    'data/maps/FallarborTown_MoveRelearnersHouse/scripts.inc',
    'data/maps/SlateportCity_NameRatersHouse/scripts.inc',
    'data/maps/MtPyre_5F/scripts.inc',
    'data/maps/SSTidalRooms/scripts.inc',
    'data/maps/Route119_WeatherInstitute_1F/scripts.inc',
    'data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.inc',
    'data/maps/FallarborTown_BattleTentLobby/scripts.inc',
    'data/maps/EverGrandeCity_DrakesRoom/scripts.inc',
    'data/maps/Route110_TrickHouseEntrance/scripts.inc',
    'data/maps/Route101/scripts.inc',
    'data/maps/Route106/scripts.inc',
    'data/maps/Route119_House/scripts.inc',
    'data/maps/VerdanturfTown_PokemonCenter_1F/scripts.inc',
    'data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.inc',
    'data/maps/EverGrandeCity_GlaciasRoom/scripts.inc',
    'data/maps/MtPyre_6F/scripts.inc',
    'data/maps/BattleFrontier_Mart/scripts.inc',
    'data/maps/Route119_WeatherInstitute_2F/scripts.inc',
    'data/maps/BattleFrontier_BattlePikeLobby/scripts.inc',
    'data/maps/BattleFrontier_Lounge3/scripts.inc',
    'data/maps/SlateportCity/scripts.inc',
    'data/maps/MauvilleCity_House1/scripts.inc',
    'data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.inc',
    'data/maps/FortreeCity_House1/scripts.inc',
    'data/maps/VerdanturfTown_House/scripts.inc',
    'data/maps/LavaridgeTown_House/scripts.inc',
    'data/maps/Route104_MrBrineysHouse/scripts.inc',
    'data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.inc',
    'data/maps/LilycoveCity_DepartmentStore_3F/scripts.inc',
    'data/maps/LittlerootTown_ProfessorBirchsLab/scripts.inc',
    'data/maps/MauvilleCity_PokemonCenter_2F/scripts.inc',
    'data/maps/GraniteCave_1F/scripts.inc',
    'data/maps/MtChimney_CableCarStation/scripts.inc',
    'data/maps/MossdeepCity_SpaceCenter_2F/scripts.inc',
    'data/maps/JaggedPass/scripts.inc',
    'data/maps/AbandonedShip_Rooms_1F/scripts.inc',
    'data/maps/Route110_TrickHousePuzzle4/scripts.inc',
    'data/maps/RustboroCity_House2/scripts.inc',
    'data/maps/BattleFrontier_Lounge4/scripts.inc',
    'data/maps/GraniteCave_StevensRoom/scripts.inc',
    'data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.inc',
    'data/maps/EverGrandeCity_SidneysRoom/scripts.inc',
    'data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.inc',
    'data/maps/RustboroCity_House3/scripts.inc',
    'data/maps/MauvilleCity_PokemonCenter_1F/scripts.inc',
    'data/maps/BattleFrontier_Lounge5/scripts.inc',
    'data/maps/BattleFrontier_BattleFactoryLobby/scripts.inc',
    'data/maps/AbandonedShip_Rooms_B1F/scripts.inc',
    'data/maps/SeafloorCavern_Room3/scripts.inc',
    'data/maps/BattleFrontier_BattlePalaceLobby/scripts.inc',
    'data/maps/SeafloorCavern_Room4/scripts.inc',
    'data/maps/Route110_TrickHouseEnd/scripts.inc',
    'data/maps/BattleFrontier_Lounge2/scripts.inc',
    'data/maps/MossdeepCity_SpaceCenter_1F/scripts.inc',
    'data/maps/RustboroCity_PokemonSchool/scripts.inc',
    'data/maps/InsideOfTruck/scripts.inc',
    'data/maps/BattleFrontier_BattlePikeThreePathRoom/scripts.inc',
    'data/maps/LilycoveCity_ContestHall/scripts.inc',
    'data/maps/FallarborTown_PokemonCenter_1F/scripts.inc',
    'data/maps/RustboroCity_Mart/scripts.inc',
    'data/maps/MossdeepCity_House4/scripts.inc',
    'data/maps/SlateportCity_BattleTentCorridor/scripts.inc',
    'data/maps/Route114_LanettesHouse/scripts.inc',
    'data/maps/LilycoveCity_DepartmentStore_1F/scripts.inc',
    'data/maps/SkyPillar_Outside/scripts.inc',
    'data/maps/PetalburgCity_House2/scripts.inc',
    'data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.inc',
    'data/maps/PetalburgWoods/scripts.inc',
    'data/maps/AbandonedShip_Rooms2_B1F/scripts.inc',
    'data/maps/BattleFrontier_BattleArenaCorridor/scripts.inc',
    'data/maps/Route111_OldLadysRestStop/scripts.inc',
    'data/maps/DewfordTown_House1/scripts.inc',
    'data/maps/OldaleTown_House2/scripts.inc',
    'data/maps/MossdeepCity_House3/scripts.inc',
    'data/maps/DewfordTown_Hall/scripts.inc',
    'data/maps/PacifidlogTown_House3/scripts.inc',
    'data/maps/PacifidlogTown_House4/scripts.inc',
    'data/maps/LavaridgeTown_PokemonCenter_1F/scripts.inc',
    'data/maps/MossdeepCity_GameCorner_1F/scripts.inc',
    'data/maps/FallarborTown_Mart/scripts.inc',
    'data/maps/MossdeepCity_House2/scripts.inc',
    'data/maps/Route110_TrickHousePuzzle3/scripts.inc',
    'data/maps/DesertUnderpass/scripts.inc',
    'data/maps/LavaridgeTown_HerbShop/scripts.inc',
    'data/maps/AbandonedShip_CaptainsOffice/scripts.inc',
    'data/maps/LilycoveCity_DepartmentStore_2F/scripts.inc',
    'data/maps/PacifidlogTown_House5/scripts.inc',
    'data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.inc',
    'data/maps/Route110_TrickHousePuzzle2/scripts.inc',
    'data/maps/PacifidlogTown_PokemonCenter_1F/scripts.inc',
    'data/maps/PacifidlogTown_House2/scripts.inc',
    'data/maps/BattleFrontier_BattlePyramidFloor/scripts.inc',
    'data/maps/EverGrandeCity_ChampionsRoom/scripts.inc',
    'data/maps/Route110_TrickHousePuzzle5/scripts.inc',
    'data/maps/NewMauville_Inside/scripts.inc',
    'data/maps/PetalburgCity_WallysHouse/scripts.inc',
    'data/maps/Route120/scripts.inc',
    'data/maps/Underwater_SeafloorCavern/scripts.inc',
    'data/maps/Route124_DivingTreasureHuntersHouse/scripts.inc',
    'data/maps/AbandonedShip_Corridors_B1F/scripts.inc',
    'data/maps/Route118/scripts.inc',
    'data/maps/PetalburgCity_Mart/scripts.inc',
    'data/maps/SootopolisCity_House5/scripts.inc',
    'data/maps/SeafloorCavern_Entrance/scripts.inc',
    'data/maps/Route111/scripts.inc',
    'data/maps/SootopolisCity_House2/scripts.inc',
    'data/maps/Route116/scripts.inc',
    'data/maps/SlateportCity_SternsShipyard_1F/scripts.inc',
    'data/maps/SkyPillar_Top/scripts.inc',
    'data/maps/LilycoveCity_House1/scripts.inc',
    'data/maps/BattleFrontier_BattleArenaLobby/scripts.inc',
    'data/maps/EverGrandeCity/scripts.inc',
    'data/maps/FortreeCity_DecorationShop/scripts.inc',
    'data/maps/SootopolisCity_Gym_B1F/scripts.inc',
    'data/maps/PetalburgCity/scripts.inc',
    'data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.inc',
    'data/maps/FortreeCity_PokemonCenter_1F/scripts.inc',
    'data/maps/AbandonedShip_Corridors_1F/scripts.inc',
    'data/maps/Route128/scripts.inc',
    'data/maps/SootopolisCity_House3/scripts.inc',
    'data/maps/SootopolisCity_House4/scripts.inc',
    'data/maps/Route117/scripts.inc',
    'data/maps/SootopolisCity_Gym_1F/scripts.inc',
    'data/maps/Route110/scripts.inc',
    'data/maps/BattleFrontier_OutsideEast/scripts.inc',
    'data/maps/MossdeepCity_StevensHouse/scripts.inc',
    'data/maps/SlateportCity_SternsShipyard_2F/scripts.inc',
    'data/maps/Route119/scripts.inc',
    'data/maps/Route121/scripts.inc',
    'data/maps/MtPyre_4F/scripts.inc',
    'data/maps/MagmaHideout_4F/scripts.inc',
    'data/maps/RustboroCity_PokemonCenter_1F/scripts.inc',
    'data/maps/FallarborTown_CozmosHouse/scripts.inc',
    'data/maps/MauvilleCity_Mart/scripts.inc',
    'data/maps/FortreeCity/scripts.inc',
    'data/maps/BattleFrontier_ScottsHouse/scripts.inc',
    'data/maps/LavaridgeTown/scripts.inc',
    'data/maps/FortreeCity_House4/scripts.inc',
    'data/maps/FortreeCity_House3/scripts.inc',
    'data/maps/MtPyre_Summit/scripts.inc',
    'data/maps/FallarborTown_BattleTentCorridor/scripts.inc',
    'data/maps/MagmaHideout_3F_1R/scripts.inc',
    'data/maps/RustboroCity_Flat2_1F/scripts.inc',
    'data/maps/PetalburgCity_Gym/scripts.inc',
    'data/maps/EverGrandeCity_PhoebesRoom/scripts.inc',
    'data/maps/SlateportCity_PokemonCenter_1F/scripts.inc',
    'data/maps/SlateportCity_OceanicMuseum_2F/scripts.inc',
    'data/maps/RustboroCity/scripts.inc',
    'data/maps/Route103/scripts.inc',
    'data/maps/LilycoveCity_Harbor/scripts.inc',
    'data/maps/LilycoveCity_ContestLobby/scripts.inc',
    'data/maps/MagmaHideout_2F_1R/scripts.inc',
    'data/maps/SootopolisCity/scripts.inc',
    'data/maps/Route104/scripts.inc',
    'data/maps/LavaridgeTown_Gym_1F/scripts.inc',
    'data/maps/RustboroCity_Flat2_2F/scripts.inc',
    'data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.inc',
    'data/maps/VerdanturfTown_BattleTentCorridor/scripts.inc',
    'data/maps/SSTidalLowerDeck/scripts.inc',
    'data/maps/Route109_SeashoreHouse/scripts.inc',
    'data/maps/VerdanturfTown_BattleTentLobby/scripts.inc',
    'data/maps/Route112_CableCarStation/scripts.inc',
    'data/maps/SSTidalCorridor/scripts.inc',
    'data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.inc',
    'data/maps/SlateportCity_OceanicMuseum_1F/scripts.inc',
    'data/maps/SlateportCity_House/scripts.inc',
    'data/maps/MagmaHideout_3F_2R/scripts.inc',
    'data/maps/FortreeCity_House2/scripts.inc',
    'data/maps/TrainerHill_Entrance/scripts.inc',
    'data/maps/FortreeCity_House5/scripts.inc',
    'data/maps/MagmaHideout_2F_2R/scripts.inc',
    'data/maps/SootopolisCity_PokemonCenter_1F/scripts.inc',
    'data/maps/VerdanturfTown_Mart/scripts.inc',
    'data/maps/MtPyre_3F/scripts.inc',
    'data/maps/CaveOfOrigin_B1F/scripts.inc',
    'data/maps/Route105/scripts.inc',
    'data/maps/Route102/scripts.inc',
    'data/maps/SeafloorCavern_Room1/scripts.inc',
    'data/maps/Route111_WinstrateFamilysHouse/scripts.inc',
    'data/maps/RustboroCity_House1/scripts.inc',
    'data/maps/SlateportCity_BattleTentLobby/scripts.inc',
    'data/maps/BattleFrontier_Lounge7/scripts.inc',
    'data/maps/MauvilleCity_BikeShop/scripts.inc',
    'data/maps/BattleFrontier_RankingHall/scripts.inc',
    'data/maps/SootopolisCity_Mart/scripts.inc',
    'data/maps/BattleFrontier_OutsideWest/scripts.inc',
    'data/maps/MauvilleCity_House2/scripts.inc',
    'data/maps/FallarborTown/scripts.inc',
    'data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.inc',
    'data/maps/BattleFrontier_Lounge6/scripts.inc',
    'data/maps/BattleFrontier_Lounge1/scripts.inc',
    'data/maps/OldaleTown_PokemonCenter_1F/scripts.inc',
    'data/maps/DewfordTown_Gym/scripts.inc',
    'data/maps/MossdeepCity/scripts.inc',
    'data/maps/LilycoveCity_DepartmentStore_5F/scripts.inc',
    'data/maps/RustboroCity_DevonCorp_3F/scripts.inc',
    'data/maps/VerdanturfTown/scripts.inc',
    'data/maps/SeafloorCavern_Room9/scripts.inc',
    'data/maps/BattleFrontier_Lounge8/scripts.inc',
    'data/maps/LilycoveCity_MoveDeletersHouse/scripts.inc',
    'data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.inc',
    'data/maps/FortreeCity_Gym/scripts.inc',
    'data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.inc',
    'data/maps/BattleFrontier_BattlePikeCorridor/scripts.inc',
    'data/maps/Route114_FossilManiacsHouse/scripts.inc',
    'data/maps/BattleFrontier_ExchangeServiceCorner/scripts.inc',
    'data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.inc',
    'data/maps/MauvilleCity_Gym/scripts.inc',
]




def process_part(part):
    if ".string" not in part: return part

    lines = part.split("\n")
    identifier = lines[0]
    tail = "\n".join(lines[1:])

    response = client.chat.completions.create(
        model="gpt-3.5-turbo-0125",
        messages=[
            {"role": "system", "content": PROMPT},
            {"role": "user", "content": tail}
        ]
    )

    assert( len(response.choices) == 1 )

    return identifier + "\n" + response.choices[0].message.content


def process_file(infile):
    with open(infile, 'r') as fp:
        parts = fp.read().split("\n\n")

        if "@ TRANSLATED" in parts[0]:
            rich.print(f"[red]{infile}[/red] already translated, skipping")
            return False

        fp = open("%s.translated" % infile, "w")
        fp.write("@ TRANSLATED\n\n")

        for part in parts:
            if ".string" not in part: 
                fp.write(part + "\n\n")
            else:
                fp.write(process_part(part) + "\n\n")
        
        return True
    
import subprocess
import os

def build():
    result = subprocess.Popen("make", stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    text = result.communicate()[0]
    return result.returncode

for mf in track(MAPFILES):
    
    created = process_file(mf)

    if created:
        # Replace it with the translated version
        os.system("cp %s.translated %s" % (mf, mf))

        # Try building
        return_code = build()

        if return_code == 0:
            print("Still builds, let's continue!")

            # If the build succeeded, we may remove the temporary files
            os.system("rm %s.translated" % mf)

            os.system("git add %s" % mf)
            os.system("git commit -m 'Auto-translated: %s'" % mf)
        else:
            print("Broke the build :(, let's restore the original file and continue!")

            # If it did not, restore the old file
            os.system("git checkout %s" % (mf))

            # Ensure we've restored order!
            new_return_code = build()
            assert(new_return_code == 0)