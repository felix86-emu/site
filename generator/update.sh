#!/bin/bash

# Generates compatibility.md
set -e

TEMP_DIR=$(mktemp -d)

# TODO: when not lazy, make this check the number of pages automatically
curl --silent -L \
  -H "Accept: application/vnd.github+json" \
  -H "X-GitHub-Api-Version: 2022-11-28" \
  "https://api.github.com/repos/felix86-emu/compatibility-list/issues?per_page=100&page=1" >> $TEMP_DIR/in1.txt

curl --silent -L \
  -H "Accept: application/vnd.github+json" \
  -H "X-GitHub-Api-Version: 2022-11-28" \
  "https://api.github.com/repos/felix86-emu/compatibility-list/issues?per_page=100&page=2" >> $TEMP_DIR/in2.txt

g++ parser.cpp -o $TEMP_DIR/a.out

$TEMP_DIR/a.out $TEMP_DIR/in1.txt > $TEMP_DIR/out1.txt
$TEMP_DIR/a.out $TEMP_DIR/in2.txt > $TEMP_DIR/out2.txt

cat prologue.txt
cat $TEMP_DIR/out1.txt
cat $TEMP_DIR/out2.txt
cat epilogue.txt

rm $TEMP_DIR/in1.txt
rm $TEMP_DIR/in2.txt
rm $TEMP_DIR/out1.txt
rm $TEMP_DIR/out2.txt
rm $TEMP_DIR/a.out
rmdir $TEMP_DIR