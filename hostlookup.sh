#!/bin/bash

# file hostlookup.sh
# brief Script to look up hosts through a file
# author william.kloppenberg
# lab 6.2 iteration
# date 10/13/2020

if [[ -f hostnames.txt ]]; then
  echo "hostnames.txt exists"
  while read h;
  do
    out=$(host -W1 -t A $h)
    if [ $? -eq 0 ];then
      ip=$(echo $out | cut -d " " -f 4)
      echo ${h},$ip
    else
      echo "${h},not found"
    fi
  done < hostnames.txt
else
  echo "File does not exist"
  return 1
fi
