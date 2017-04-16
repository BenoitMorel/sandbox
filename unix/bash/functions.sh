#!/bin/bash


print_2_args()
{
  echo $1 $2
}

params() 
{
  # access the second parameter
  second=$2

  # get the number of parameters
  param_numbers=$#

  # get all the parameters
  echo $@ 

  # get all the parameters in one string
  all=$*

  # this can be accessed with $? from the caller
  # and range from 0 to 255
  return 5

  # we can to the same with exit 5, but the 
  # application will exit
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
