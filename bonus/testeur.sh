#!/usr/bin/env bash
##
## EPITECH PROJECT, 2022
## bsantman
## File description:
## antman
##

if [ $# -ne 1 ]; then
    echo -e "\x1B[33mUSAGE :"
    echo -e "\t\x1B[0m$0 <original file>"
    exit
fi
original=$(< $1)
../antman/antman $1 1 > compressed.data
f1=$(< compressed.data)
../giantman/giantman compressed.data > uncompressed.data
s2=$(< uncompressed.data)
if [[ "$original" == "$s2" ]];
then
    echo -e "\033[0;32mANTMAN OK"
    comp1=$(cat "compressed.data" | wc -c)
    comp2=$(cat "uncompressed.data" | wc -c)
    co=$(echo "($comp1 / $comp2) * 100" | bc -l)
    printf "%.2f" ${co}
    echo "% compressed !"
else
    echo -e "\033[0;31mANTMAN KO"
fi
echo -e "\033[0m"
rm compressed.data uncompressed.data
