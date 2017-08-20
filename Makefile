SOURCES=main.cpp
OBJECTS=main.o
HEADERS=main.h
PROGRAM=a.out
CFLAGS=-lm -pedantic -Wall -std=c++14
LDFLAGS=-lm -pedantic -Wall -std=c++14 -lboost_program_options
CC=g++

all: $(PROGRAM)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY:clean archive debug rebuild

debug:clean all
debug:CFLAGS+= -fsanitize=address -g
debug:LDFLAGS+= -fsanitize=address -g

clean:
	rm $(PROGRAM) $(OBJECTS)

archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) Makefile

rebuild: clean
	make
