#!/bin/bash

tens=(
    "13 6 19 4 16 7 12 11 15 3"
    "7 15 17 18 13 5 3 20 12 8"
    "16 2 17 18 19 0 12 4 5 10"
    "12 15 2 14 18 4 5 8 7 16"
    "3 13 14 9 4 2 0 12 6 5"
    "13 14 19 10 0 16 3 12 11 20"
    "2 13 10 14 7 1 4 17 18 3"
    "5 9 10 1 14 12 8 2 18 13 "
    "9 1 18 6 3 10 4 11 20 0"
    "6 1 7 3 15 16 5 19 12 13"
)
n=$4
if [[ $1 == '' ]]; then
    for i in ${!tens[@]}; do
        echo "${tens[$i]}"
        ./tester.sh .. -co ${tens[$i]}
    done
elif [[ $1 != '' && $2 != '' && $3 != '' ]]; then
    for ((i=0;i<n;i++))
    do
        ./tester.sh .. -r $1 $2 $3
    done
fi