#!/bin/bash

t()
{
    command=$(./regexMatching "$1" "$2")
    if [ $command -eq $3 ]; then
        echo -e "\e[32m PASS \e[36m $1\e[0m"
    else 
        echo -e "\e[1m \e[31m FAIL --> $1  $2       expected= $3 --- actual= $command \e[0m"
    fi
}

t "vinod" "vinod" 1
t "vinod" "v.*s"  0
t "vvvvin" "ashley" 0
t "aaab" "a.*" 1
t "aa" "a" 0
t "a" "aa" 0
t "aab" "c*a*b" 1
t "vinod" "...." 0
t "vinod " "vinod " 1
t "vinod" "v*v*v*" 0
t "aaa" "a*a" 1
t "aaa" "ab*a*c*a" 1
t "aaca" "ab*a*c*a" 1
t "vinod" "vo*inod" 1
t "bbbba" ".*a*a" 1
t "ab" ".*.." 1
t "ab" ".*..." 0
t "ab" ".*..*." 1
t "a" ".*..a" 0
t "abcdede" "ab.*de" 1
t "abb" "a.*b" 1
 
