all: main.exe run

main.exe: main.c ../int_set.c ../../libs/maybe_int.c
	@clang -Wall -o main.exe main.c ../int_set.c ../../libs/maybe_int.c

run: main.exe
	@./main.exe
