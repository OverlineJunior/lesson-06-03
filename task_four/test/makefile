all: main.exe run

main.exe: main.c ../int_set.c
	@clang -Wall -o main.exe main.c ../int_set.c

run: main.exe
	@./main.exe
