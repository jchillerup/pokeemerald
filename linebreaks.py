#!/usr/bin/python

import re
import functools
import json
import io

d = json.JSONDecoder()
widthsJson = io.open('font_config.json')
fonts = d.decode(widthsJson.read())
fontId = fonts['defaultFontId']
widths = fonts['fonts'][fontId]['widths']
maxLineLength = fonts['fonts'][fontId]['maxLineLength']

# a block is a labelled section in an .inc file
# blocks that aren't just .strings we will print unchanged
def parse_block(l):
    def collapse_strings(lines):
        def clean(l):
            s = " ".join(l)
            return s.replace("\\n", "").replace("\\l", "").replace("\\p", "").replace("$", "")
        res=[]
        acc=[]
        for l in lines:
            acc.append(l)
            if l.endswith("\\p") or l.endswith("$"):
                res.append(clean(acc))
                acc=[]
        # some scripts forget the $
        if acc: 
            res.append(clean(acc))

        return res

    def parse_body(b):
        theStrs = re.findall("\\s\\.string \"(.*)\"", b)
        if len(theStrs) == 0:
            return b
        else:
            return collapse_strings(theStrs)

    try:
        match = re.search("^(\\w+:?):\\n", l)
        header = match.group(1)
    except AttributeError:
        return ["", l]
    rest = match.string[match.end():]
    return [header, parse_body(rest)]

# a "line" here is a sentence that needs to be split across
# multiple lines to fit in the text box.
def format_line(line, theEnd):
    def measure_word(w):
        match = re.match("([^{}]*)({[A-Z0-9_]*})({[A-Z0-9_]*})?(.*)", w)
        if match:
            m = widths[match.group(2)]
            if (match.group(3)):
                m += widths[match.group(3)]
            m += functools.reduce(lambda acc, l: acc + widths[l], match.group(1), 0)
            m += functools.reduce(lambda acc, l: acc + widths[l], match.group(4), 0)
        else: 
            m = functools.reduce(lambda acc, l: acc + widths[l], w, 0)
        return m

    def split_line(line):
        width = 0
        acc = []
        lines = []
        for w in line.split(" "):
            m = measure_word(w)
            if m + width > maxLineLength:
                lines.append(acc)
                width = m
                acc = [w]
            else:
                acc.append(w)
                width += m
        if len(acc) > 0:
            lines.append(acc)
        return list(map(lambda l: " ".join(l), lines))

    lines = split_line(line)
    if len(lines) > 1:
        lines[0] += "\\n" 
    if len(lines) > 2:
        for i, l in enumerate(lines[1:-1]):
            lines[i+1] += "\\l"
    if theEnd:
        lines[-1] += "$"
    else:
        lines[-1] += "\\p"
    return "\n".join(list(map(lambda l: '\t.string \"' + l + "\"", lines)))

def print_block(b):
    [header, body] = parse_block(b)
    if header:
        print("{0}:".format(header))
    if isinstance(body,str):
        print(body)
        return
    for line in body[:-1]:
        print(format_line(line, False))
    print(format_line(body[-1], True))

def reformat_file(f):
    blocks = re.split("\\n\\n+", f)
    for b in blocks:
        print_block(b)
        print()

if __name__ == '__main__':
    import argparse
    import io
    import sys

    parse = argparse.ArgumentParser()
    parse.add_argument("filename")
    parse.add_argument("--replace", action=argparse.BooleanOptionalAction)
    args = parse.parse_args()


    print(args.filename)
    f = io.open(args.filename)
    c = f.read()

    out = sys.stdout
    if (args.replace):
        f.close()
        out = io.open(args.filename, "w")

    sys.stdout = out

    reformat_file(c)
