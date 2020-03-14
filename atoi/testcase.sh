#!/bin/bash

t()
{
    command=$(./atoi "$1")
    if [ $command -eq $2 ]; then
        echo -e "\e[32m PASS \e[36m $1\e[0m"
    else 
        echo -e "\e[1m \e[31m FAIL --> input= $1 --- expected output= $2 --- actual output= $command \e[0m"
    fi
}

t "123" 123
t "-123" -123
t "   was123" 0
t "www" 0
t " 567www" 567
t "   -567awww" -567
t "123333---aaa" 123333
t "12 121212" 12
t "-2147483648" -2147483648
t "2147483647" 2147483647
t "    -2147483647" -2147483647
t "    -2147483649999" -2147483648
t "   ww2147483648" 0
t " 2147483648www" 2147483647
t "-91283472332" -2147483648
t "999999999999" 2147483647
t "   -91283472332" -2147483648
t "   999999999999" 2147483647
t "-91283472332www" -2147483648
t "999999999999www" 2147483647
t "-91283472332  ww" -2147483648
t "999999999999  --" 2147483647
t "  ww -91283472332" 0
t " ----999999999999" 0
t "  0000000000012345678" 12345678