#!/bin/bash

# file converter.sh
# brief Script to convert a file's contents to uppercase or lowercase
# author william.kloppenberg
# lab 6.2 iteration
# date 10/13/2020

# brief Outputs usage
usage()
{
  echo "$0 usage: [-f input file] [-c U(upper) or L(lower)"
  exit 1
}

while getopts ":f:c:" options;
do
  case "${options}" in
    f)
      f=${OPTARG}
      if [[ -f ${f} ]]; then
        echo "${f} exists"
      else
        usage
      fi
      ;;
    c)
      c=${OPTARG}
      if [[ ${c} == "U" || ${c} == "L" ]]; then
        echo "${f} - ${c}"
      else
        usage
      fi
      ;;
    *)
    usage
    ;;
  esac
done

# brief Conversion logic
while read line
do
  if [ ${c} == "U" ]; then
    echo $line | tr [:lower:] [:upper:]
  else
    echo $line | tr [:upper:] [:lower:]
  fi
done < $f

exit 0
