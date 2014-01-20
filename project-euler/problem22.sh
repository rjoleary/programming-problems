#!/bin/sh

# This script does some preprocessing on `names.txt` to make it easier to
#  parse. Namely, it removes unnecessary quotation marks and commas. It then
#  sorts the output.

# Replace the quotations and commas with newlines.
sed 's/\",\"/\n/g' names.txt | sed 's/\"//g' > problem22.txt

# Append a trailing newline.
echo "" >> problem22.txt

sort problem22.txt -o problem22.txt
