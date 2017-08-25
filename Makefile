SOURCES=main.cpp edit_distance.cpp list_wrapper.cpp vector_wrapper.cpp set_wrapper.cpp map_wrapper.cpp custom_list_wrapper.cpp custom_list.cpp custom_tree_wrapper.cpp custom_tree.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(SOURCES:.cpp=.h)
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

