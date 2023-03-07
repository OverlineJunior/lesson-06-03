all: main.exe run

main.exe: main.c ../booking.c
	@clang -Wall -o main.exe main.c ../booking.c

run: main.exe
	@./main.exe
