from openai import OpenAI
from keys import *
import rich
from rich.progress import track


file = "data/text/tv.inc"
outfile = "data/text/tv.inc.da"

PROMPT = """
This conversation will concern translating a script for a computer game for kids into Danish. The files I will provide are a part of the source code, so the structure of the file is important and must be retained.

Besides that, the rules are:
- Only text inside double quotes may be translated. Text outside double quotes are retained in the output. It is very important that only text inside quotation marks gets translated.
- The game is for kids, so a playful and friendly tone is usually required. If the context is that someone wants to battle, it may be snarky. 
- `\\n` is a line break. These generally link a string of text to the next one, making a full sentence. In the translated version, `\\n` can be put in between words, so as to not make a single line longer than 35 characters.
- Text inside curly braces are variables, and must not be translated. The braces must also remain in the Danish translation.
- Text in all caps is proper names and need not be translated.
- `\\p` and `\\l` are special characters where the player must push a button to continue. It needs to be retained. 
- `$` is a special character which means the dialog is over. It needs to be retained.

The sections to be translated follows this message.
"""

client = OpenAI(api_key=OPENAI_KEY)


if __name__ == '__main__':
    out = open(outfile, 'w')

    with open(file, 'r') as text:
        dialogs = text.read().split("\n\n")

        for dialog in track(dialogs):
            response = client.chat.completions.create(
                model="gpt-3.5-turbo-0125",
                messages=[
                    {"role": "system", "content": PROMPT},
                    {"role": "user", "content": dialog}
                ]
            )

            assert( len(response.choices) == 1 )

            out.write(response.choices[0].message.content + "\n\n")
            out.flush()
