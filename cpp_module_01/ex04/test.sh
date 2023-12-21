#!bin/bash
echo compiling
make
echo compiled
echo running tests
echo old text:
cat hallo.txt
./replace hallo.txt hallo kaas
echo
echo new text:
cat hallo.txt.replace
rm hallo.txt.replace

