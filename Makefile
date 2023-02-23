ifeq ($(OS),Windows_NT) 
RM = del /Q /f		# enables clean on windows
CP = copy /Y
ifdef ComSpec
SHELL := $(ComSpec)
endif
ifdef COMSPEC
SHELL := $(COMSPEC)
endif
else
RM = rm -rf
CP = cp -f
endif
CC = gcc
CFLAGS = -g -Wall	#-g enables debug symbols

main: main.o
	$(CC) $(CFLAGS) main.o -o main
	./main.exe
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	-$(RM) main.exe *.o
