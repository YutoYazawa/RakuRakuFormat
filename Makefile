# Makefile of the RakuRakuFormat.

default :
	make compile

rakuraku.out : main.c stredit.h Makefile
	gcc main.c -o rakuraku.out

compile :
	make rakuraku.out
