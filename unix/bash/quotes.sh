#!/bin/bash

# print "ls pwd ls"
echo ls pwd ls

# print ls pwd and run ls (; is a terminator) 
echo ls pwd; ls

plop="plop"


#these are one param each (even if some of them contain space)
cat $plop
cat $plop$plop.txt
cat "yop.txt yip.txt" # will fail btw

#these are two param each (2 arguments for a command like cat)
cat yo.txt ya.txt
cat "yo."".txt" ya.txt
cat $plop $plop


#backslash escapes one character
echo \$oneparam #does not print the content of oneparam

# simple quote (strong quoting) displays everything literaly
# everything here is escaped, even the backslash and the $
echo '$plop \"$plop"'
# the only way to print a single quotes into single quotes is:
echo 'print the single quote:'\

# double quotes (weak quoting) displays the real meaning of variables
# here we print the content of plop
echo "$plop"
#here we escape $ with the backslash (because $ is a special character)
echo "\$plop"
#here we print the backslash and the a (a is not a special character)
echo "\a"

