#!/bin/bash

echo "******BASH******";

myArray=(
	"0 2 4 1"
	"5 2 4 1" 
	"3 1 5 4"
	"3 4 1 6"
	"0 5 7 1 3"
	"8 5 7 1 3"
	"6 5 7 1 3"
	"4 5 7 1 3"
	"2 5 7 1 3"
	"0 7 1 3 5"
	"8 7 1 3 5"
	"6 7 1 3 5"
	"4 7 1 3 5"
	"2 7 1 3 5"
	"2 4 1 6 5"
	"7 8 5 2 9"
	"7 3 1 8 5"
	"0 1 5 2 4"
	"8 9 7 1 5"
	"6 1 5 3 4"
	"7 3 4 6 1"
	"5 3 4 6 1"
	"0 3 4 6 1"
	"6 5 7 1 3"
	"4 3 5 7 1"
	"23 3 87 4 67"
	"4 67 3 27 23"
	"984 167 3 87 23"
	"167 984 3 87 23"
);
default=(
	"2 1 3 6 5 8"
	"4 67 3 87 23"
	"1 5 2 4 3"
	 "3 2 1 0"
);
terminal_args=$1

if [[ $terminal_args == "t" ]]; then
	for i in ${!myArray[@]}; do
		echo "${myArray[$i]}"
		ARG=${myArray[$i]}; ./push_swap $ARG | wc -l
		ARG=${myArray[$i]}; ./push_swap $ARG | ./checker_Mac $ARG
	done
elif [[ $terminal_args == "s" ]]; then
	for i in ${!default[@]}; do
		echo "${default[$i]}"
		ARG=${default[$i]}; ./push_swap $ARG | wc -l
		ARG=${default[$i]}; ./push_swap $ARG | ./checker_Mac $ARG
	done	

else
	for i in ${!myArray[@]}; do
		echo "${myArray[$i]}"
		ARG=${myArray[$i]}; ./push_swap $ARG | wc -l
		ARG=${myArray[$i]}; ./push_swap $ARG | ./checker_Mac $ARG
	done
	for i in ${!default[@]}; do
		echo "${default[$i]}"
		ARG=${default[$i]}; ./push_swap $ARG | wc -l
		ARG=${default[$i]}; ./push_swap $ARG | ./checker_Mac $ARG
	done	
fi