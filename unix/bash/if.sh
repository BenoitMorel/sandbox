#!/bin/bash

var=10001

# spaces are mandatory
if [ $var -gt 100 ]
then
  echo "$var is greater than 100"
elif test $var -gt 10 
then
  echo "$var is greater than 10"
else
  echo "$var is lower than 10"
fi

# [ expression ] is an alias for test
# test expression evaluates the expression and 
# stores the results in the exit code (0 for true
# and 1 for false)
test $var -gt 100
echo $?

# and and or
if [ $var -gt 100 ] && [ $var -lt 1000 ]
then
  echo "$var is between 100 and 1000"
fi

arch=7avx
# switch
case $arch in
  avx)
    echo "this is avx"
    ;;
  sse)
    echo "this is sse"
    ;;
  *babar*)
    echo "this is something with babar"
    ;;
  [0-9]*)
    echo "this is something starting with a numeric"
    ;;
  *) 
    echo "this is something else"
    ;;
esac

# string comparison
test "001" = "1"
test "001" != "1"
# not empty string
test -n "notempty"
# is empty string
test -z ""
# numerical comparison (natural numbers)
test "001" -eq "1"
test 2 -gt 1
# directory exists and is a directory
test -d "../bash"
# file exists
test -e "if.sh"


