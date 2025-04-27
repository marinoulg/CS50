FILE ?= file

$(FILE): $(FILE).c
	clang $(FILE).c -lcs50 -o $(FILE)

scrabble:
	@clang 02-Arrays/scrabble/scrabble.c -lcs50 -o 02-Arrays/scrabble/scrabble

check-scrabble:
	cd 02-Arrays/scrabble \
		&& check50 cs50/problems/2024/x/scrabble \
		&& cd ../..
