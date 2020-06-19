CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -std=c11
LDFLAGS=-lm
EXEC=raytracer
EXEC_DEBUG=$(EXEC)_debug
SRC= vec3d.c ray.c ppm.c raytracer.c
OBJ= $(SRC:.c=.o)

release: CFLAGS += -O2
release: $(OBJ)
	$(CC) -o $(EXEC) $^ $(LDFLAGS)

debug: CFLAGS += -DDEBUG -g -O0
debug: $(OBJ)
	$(CC) -o $(EXEC_DEBUG) $^ $(LDFLAGS)

ppm.o: vec3d.h ray.h
ray.o: vec3d.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
	rm -rf $(EXEC_DEBUG)
	rm output.ppm
