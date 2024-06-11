import re
from rich.progress import track
import rich
from translate import client
from itertools import batched
import subprocess
import os

# rg --files-with-matches "static const u8 sText"
# halfway in src/battle_message.c already

SOURCE_FILES = [
    'src/pokenav_match_call_gfx.c',
    'src/union_room_chat.c',
    'src/union_room_battle.c',
    'src/berry_tag_screen.c',
    'src/berry_blender.c',
    'src/dodrio_berry_picking.c',
    'src/pokemon_storage_system.c',
    'src/battle_message.c',
    'src/data/trade.h',
    'src/data/union_room.h',
    'src/battle_main.c',
    'src/battle_pyramid_bag.c',
    'src/mystery_gift_menu.c',
    'src/naming_screen.c',
    'src/trainer_card.c',
    'src/pokenav_conditions_search_results.c',
    'src/starter_choose.c',
    'src/berry_fix_program.c',
    'src/frontier_pass.c',
    'src/main_menu.c',
    'src/evolution_scene.c',
    'src/pokemon_summary_screen.c',
    'src/pokenav_ribbons_list.c',
    'src/text_window.c',
    'src/link.c',
    'src/battle_records.c',
    'src/mystery_gift_scripts.c',
    'src/pokeblock.c',
    'src/berry_crush.c',
    'src/menu.c',
    'src/pokedex.c',
    'src/match_call.c',
    'src/mail.c',
    'src/map_name_popup.c',
    'src/easy_chat.c',
]

PROMPT = """
This conversation will concern translating a script for a computer game for kids into Danish. The strings are C code defining variables containing English text and control characters, and it is important that the control characters and template tags are retained verbatim. The variable names and signatures also need to be retained. That means that only text inside quotation marks may be translated, but template tags and control characters must be retained.

A template tag is a sequence of text inside curly braces. This is an example: {B_TRAINER1_LOSE_TEXT}
Control characters are: \\n, \\p, \\l and $. 

Besides that, the rules are:
- The game is for kids, so a playful and friendly tone is usually required. If the context is that someone wants to battle, it may be snarky. 
- Text in all caps is proper names and need not be translated.

The sections to be translated follows this message.
"""

def build():
    result = subprocess.Popen(["make", "-j1"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    text = result.communicate()[0]
    return result.returncode

assert(build() == 0)

for file in SOURCE_FILES:
    rich.print(f"[b]{file}[/b]")
    to_translate = dict()

    with open(file, 'r') as fp:
        lines = list(fp.readlines())

        if lines[0] == "// TRANSLATED\n":
            rich.print("[yellow]Already translated[/yellow]")
            continue

        for line in lines:
            if "= _(" in line:
                to_translate[line.strip()] = ""

    for lines in track(batched(to_translate.keys(), 16), total=len(to_translate.keys())/16):    
        response = client.chat.completions.create(
            model="gpt-3.5-turbo-0125",
            messages=[
                {"role": "system", "content": PROMPT},
                {"role": "user", "content": "\n".join(lines)}
            ]
        )

        assert( len(response.choices) == 1 )

        translated_lines = response.choices[0].message.content.split("\n")

        assert(len(lines) == len(translated_lines))

        for old, new in zip(lines, translated_lines):
            rich.print(f"[red]{old}[/red]\n[green]{new}[/green]\n\n")
            to_translate[old] = new

    with open(file, 'r') as fp:
        outfp = open(f"{file}.translated", 'w')
        outfp.write("// TRANSLATED\n")

        for line in fp.readlines():
            translation = to_translate.get(line.strip())

            if translation:
                outfp.write(translation.strip() + "\n")
            else:
                outfp.write(line)
        outfp.close()

    # try it out
    os.system(f"cp {file}.translated {file}")

    if build() == 0:
        os.system(f"git add {file}")
        rich.print("[green]Went well[/green]")
    else:
        os.system(f"git checkout {file}")
        rich.print("[red]Broke the build[/red]")
