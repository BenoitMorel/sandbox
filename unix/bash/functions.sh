#!/bin/bash


print_2_args()
{
  echo $1 $2
}


hello="hello"
world="world"

#print "hello world"
print_2_args $hello $world

#store the result of stdout in a variable with $(function)
helloworld=$(print_2_args $hello $world)
echo $helloworld

#also works with commands
pwdresult=$(pwd)
echo $pwdresult

# add quotes to store multi lines results
lsresult="$(ls -l)"
# quotes are also required to display newlines
echo "$lsresult"
