#!/bin/sh
rm -rf chatbot.o

if [ $1 == t ]
then
 clang -Wall -pedantic -fno-optimize-sibling-calls -fno-stack-protector main.c csv_process.c  learn/tst.c

elif [ $1 == d ]
then
 g++ -Wall -pedantic -fno-optimize-sibling-calls -fno-stack-protector lex.c main.c csv_process.c learn/tst.c

elif [ $1 == c ]
then
 g++ -std=c++20   -Wall -pedantic main.cpp csvfileop.cpp -o chatbot.o

elif [ $1 == e ]
then
 g++ -std=c++20  -Werror -Wall -pedantic main.cpp csvfileop.cpp -o chatbot.o
elif [ $1 == p ]
then
 clang -Werror -Wall -pedantic main.c csv_process.c learn/tst.c
fi
