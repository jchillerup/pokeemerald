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
    'src/data/pokemon/pokedex_text.h'
]

PROMPT = """
This conversation will concern translating a script for a computer game for kids into Danish. The strings are 
C code defining variables containing English text and control characters, and it is important that the control 
characters and template tags are retained verbatim. The variable names and signatures also need to be retained. 
That means that only text inside quotation marks may be translated, but template tags and control characters 
must be retained.

A template tag is a sequence of text inside curly braces. This is an example: {B_TRAINER1_LOSE_TEXT}
Control characters are: \\n, \\p, \\l and $. 

Besides that, the rules are:
- The game is for kids, so a playful and friendly tone is usually required. If the context is that someone wants to battle, it may be snarky. 
- Text in all caps is proper names and need not be translated.
- The translations must take up no longer than four lines of text, excluding the variable assignment.
- The first three lines end with an `\\n`.

The sections to be translated follow this message.
"""

def build():
    result = subprocess.Popen(["make", "-j1"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    text = result.communicate()[0]
    return result.returncode

assert(build() == 0)

for file in SOURCE_FILES:
    rich.print(f"[b]{file}[/b]")
    to_translate = dict()
    outfp = open(f"{file}.translated", 'w')
    outfp.write("// TRANSLATED\n")

    with open(file, 'r') as fp:
        content = fp.read()

        if "// TRANSLATED\n" in content:
            rich.print("[yellow]Already translated[/yellow]")
            continue

        blocks = content.split("\n\n")

    for batch in track(blocks):    
        response = client.chat.completions.create(
            model="gpt-3.5-turbo-0125",
            messages=[
                {"role": "system", "content": PROMPT},
                {"role": "user", "content": batch}
            ]
        )

        assert( len(response.choices) == 1 )

        translation = response.choices[0].message.content
        translated_lines = translation.split("\n")

        #assert(len(batch.split("\n")) == len(translated_lines))

        rich.print(f"[red]{batch}[/red]\n[green]{translation}[/green]")
        outfp.write(f"/*\n{batch}\n*/\n{translation}\n\n")
        outfp.flush()

    outfp.close()
    # try it out
    os.system(f"cp {file}.translated {file}")

    if build() == 0:
        os.system(f"git add {file}")
        rich.print("[green]Went well[/green]")
    else:
        os.system(f"git checkout {file}")
        rich.print("[red]Broke the build[/red]")
