# Copyright © 2022  Neeraj Singhal
# All rights reserved

#!/bin/bash
# BAT / CMD goto function
#function goto() {
#    label=$1
#    cmd=$(sed -n "/^:[[:blank:]][[:blank:]]*${label}/{:a;n;p;ba};" $0 |
#        grep -v ':$')
#    eval "$cmd"
#    exit
#}

## Pre-Requistes Installs##
#$yay -Sy gcc clang make cmake cppcheck

### START ###
#* Note: Static code analysis can be done using cppcheck(prefered) or clang-tidy
echo -e '\033[0;33m' "\n>Static code analysis using cppcheck" '\033[0m'
cppcheck --enable=all --suppress=missingIncludeSystem ./*.cpp

#read -r -p "Do you want to execute code in gcc/clang? [Y/N] " response
#Check for the response
#if [[ "$response" =~ ^([yY][eE][sS]|[yY])$ ]]; then
#echo -e "\n executing code....."
#clear
#goto "$Start"
#else
#echo -e "No, Exit..... "
#exit 1
#fi

#Start Label
#: Start

### END ###
