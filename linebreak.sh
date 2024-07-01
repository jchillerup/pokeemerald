#!/bin/bash

IFS="
"

FILES=$(find data/{scripts,text} -name *.inc)

echo ${FILES}

for f in ${FILES}; do
  ./linebreaks.py --replace $f
  if [ $? -ne 0 ]; then
    echo $f >> errors.txt
    git checkout $f
  fi
done
