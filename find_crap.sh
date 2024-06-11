#!/bin/bash

awk '
  BEGIN { DQ = "\042"; fmt = "%s:%d:%.80s\n"; }
  gsub (DQ, DQ) % 2 { printf (fmt, FILENAME, FNR, $0); }
' $1