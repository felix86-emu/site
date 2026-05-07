#!/bin/bash

# Because we are very lazy to fiddle with github pages and actions and web dev
# We just generate docs/ and the compatibility.md manually before pushing
# Run this script as ./generate-static-content.sh (ie. while in this dir)
set -e

SITE_DIR=$(pwd)
cd generator
./update.sh > $SITE_DIR/compatibility.md
cd ..

DOCS_DIR=$(mktemp -d)
git clone https://github.com/felix86-emu/docs $DOCS_DIR
cd $DOCS_DIR
mkdocs build -d $SITE_DIR/docs
