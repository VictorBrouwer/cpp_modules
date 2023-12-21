#!/bin/bash
program="./convert"

echo "Compiling..."
make
echo "Compiling done"

echo "running tests..."
echo "input = c"
$program "c"
echo "input = 0"
$program "0"
echo "input = 42"
$program "42"
echo "input = inf"
$program "inf"
echo "input = inff"
$program "inff"
echo "input = nan"
$program "nan"
echo "input = nanf"
$program "nanf"
echo "input = 42.0f"
$program "42.0f"
echo "input = nanf"
$program "nanf"
echo "tests done now cleaning up..."
make fclean