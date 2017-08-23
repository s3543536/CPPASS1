SOURCES=main.cpp list_wrapper.cpp edit_distance.cpp custom_list_wrapper.cpp custom_list.cpp custom_tree_wrapper.cpp custom_tree.cpp vector_wrapper.cpp
OBJECTS=main.o list_wrapper.o edit_distance.o custom_list_wrapper.o custom_list.o custom_tree_wrapper.o custom_tree.o vector_wrapper.o
HEADERS=main.h list_wrapper.h edit_distance.h custom_list_wrapper.h custom_list.h custom_tree_wrapper.h custom_tree.h vector_wrapper.h
PROGRAM=a.out
DFILERULES=-MMD -MP
CFLAGS=-lm -pedantic -Wall -std=c++14 $(DFILERULES)
LDFLAGS=$(CFLAGS) -lboost_program_options
CC=g++


all: $(PROGRAM)

%.o: %.cpp #$(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

-include $(SOURCES:.cpp=.d)
.PHONY:clean archive debug rebuild

debug:all
debug:CFLAGS+= -fsanitize=address -g
debug:LDFLAGS+= -fsanitize=address -g

clean:
	rm $(PROGRAM) $(OBJECTS)

archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) Makefile

rebuild: clean
	make

