#!/usr/bin/bash
# Script to compile assignments for chapter 4.
#
#  Created on: Sep 7, 2013
#      Author: Nathan Lane
#       Class: CSIS-2430

echo "Building chapter 4 problem 25 solution."
gcc -Wall -g3 -O0 -o chapter4_25 lists.h lists.c algorithmone.h algorithmone.c algorithmfive.h algorithmfive.c chapter4_25.c

echo "Building chapter 4 problem 26 solution."
gcc -Wall -g3 -O0 -o chapter4_26 lists.h lists.c algorithmone.h algorithmone.c algorithmfive.h algorithmfive.c chapter4_26.c

echo "Building chapter 4 problem 27 solution."
gcc -Wall -g3 -O0 -o chapter4_27 lists.h lists.c algorithmone.h algorithmone.c algorithmfive.h algorithmfive.c chapter4_27.c

echo "Building chapter 4 problem 28 solution."
gcc -Wall -g3 -O0 -o chapter4_28 lists.h lists.c algorithmone.h algorithmone.c algorithmfive.h algorithmfive.c chapter4_28.c
