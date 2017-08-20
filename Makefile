SOURCES=main.cpp list_wrapper.cpp edit_distance.cpp custom_list_wrapper.cpp custom_list.cpp
OBJECTS=main.o list_wrapper.o edit_distance.o custom_list_wrapper.o custom_list.o
HEADERS=main.h list_wrapper.h edit_distance.h custom_list_wrapper.h custom_list.h
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
