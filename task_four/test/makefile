all: main.exe run

main.exe: main.c ../int_array.c
	@clang -Wall -o main.exe main.c ../int_array.c

run: main.exe
	@./main.exe
