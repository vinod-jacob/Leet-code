#!/bin/bash

t()
{
    command=$(./lengthOfLongestSubstring $1)
    if [ $command -eq $2 ]; then
        echo -e "\e[32m PASS \e[36m $1\e[0m"
    else 
        echo -e "\e[1m \e[31m FAIL --> input= $1 --- expected output= $2 --- actual output= $command \e[0m"
    fi
}

t "asdaporridge" 6
t "kamikaze" 6
t "hello" 3
#t $\x00 0
#t " " 1
t "teeicups" 6

