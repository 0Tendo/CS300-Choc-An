.PHONY: clean
CFLAGS=-ansi -pedantic -O0 -Wall


main:
	g++ -g -o main $(CFLAGS) providers.cpp members.cpp mainmenu.cpp Service.cpp

clean:
	rm -f main
