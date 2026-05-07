#!/bin/bash

# Generates compatibility.md
set -e

TEMP_DIR=$(mktemp -d)

# Fetch up to 400 issues (4 pages)
g++ parser.cpp -o $TEMP_DIR/a.out

for p in {1..4}; do
  curl --silent -L \
    -H "Accept: application/vnd.github+json" \
    -H "X-GitHub-Api-Version: 2022-11-28" \
    "https://api.github.com/repos/felix86-emu/compatibility-list/issues?per_page=100&page=$p" > $TEMP_DIR/page.json
  
  # Check if page is empty array [] or invalid
  if [ ! -s $TEMP_DIR/page.json ] || [ "$(cat $TEMP_DIR/page.json)" == "[]" ]; then
    continue
  fi
  
  $TEMP_DIR/a.out $TEMP_DIR/page.json >> $TEMP_DIR/games_body.txt
done

cat prologue.txt > ../compatibility.md
if [ -f $TEMP_DIR/games_body.txt ]; then
  cat $TEMP_DIR/games_body.txt >> ../compatibility.md
fi
cat epilogue.txt >> ../compatibility.md

rm -rf $TEMP_DIR