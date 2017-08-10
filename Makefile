SOURCES=drawlib.c
OBJECTS=drawlib.o
HEADERS=*.h
PROGRAM=a.out
CFLAGS= -ansi -lm -pedantic -Wall -g -std=c++14
LDFLAGS= -ansi -lm -pedantic -Wall -g -std=c++14
CC=g++

all: $(PROGRAM)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY:clean archive debug rebuild

debug:clean all
debug:
CFLAGS+= -fsanitize=address -g

debug:
LDFLAGS+= -fsanitize=address -g

debug:
%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@

debug:
$(PROGRAM): $(OBJECTS)
	gcc $(LDFLAGS) -o $@ $^


clean:
	rm $(PROGRAM) $(OBJECTS)

archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) Makefile

rebuild: clean
	make
