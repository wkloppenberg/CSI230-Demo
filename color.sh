#!/bin/bash
red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
blue='\033[0;34m'
magenta='\033[0;35m'
default='\033[0m'

read -p "What is your favorite color? (red, green, blue, yellow or magenta) " color
color=${color^^}

case "${color}" in
      "RED")  selected_color=$red
              echo -e "${selected_color}Your selected color is ${color}${default}"
              ;;
    "GREEN")  selected_color=$green
              echo -e "${selected_color}Your selected color is ${color}${default}"
              ;;
     "BLUE")  selected_color=$blue
               echo -e "${selected_color}Your selected color is ${color}${default}"
              ;;
   "YELLOW")  selected_color=$yellow
              echo -e "${selected_color}Your selected color is ${color}${default}"
              ;;
  "MAGENTA")  selected_color=$magenta
              echo -e "${selected_color}Your selected color is ${color}${default}"
              ;;
          *)  echo "Invalid entry" $?
              exit 1
              ;;
esac
