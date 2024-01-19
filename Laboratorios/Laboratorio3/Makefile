CC = g++
CFLAGS = -std=c++11

all: programa

programa: main.cpp Contacto.hpp Agenda.hpp
	$(CC) $(CCFLAGS) main.cpp -o agenda.exe
	./agenda.exe

clean:
	rm -rf agenda.exe
	del agenda.exe