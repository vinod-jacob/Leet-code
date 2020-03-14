#!/bin/bash

t()
{
    command=$(./palindromeNumber $1)
    if [ $command -eq $2 ]; then
        echo -e "\e[32m PASS \e[36m $1\e[0m"
    else 
        echo -e "\e[1m \e[31m FAIL --> input= $1 --- expected output= $2 --- actual output= $command \e[0m"
    fi
}

t 123 0
t -123 -0
t 0000 1
t 10000 0
t -1 0
t 010101010 0
t 01010101 1
t -2147483648 0
t 2147483647 0
t 2147483648 0
t 99999999999999 0