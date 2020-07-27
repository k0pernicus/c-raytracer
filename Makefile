CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -std=c11
LDFLAGS=-lm
EXEC=raytracer
EXEC_DEBUG=$(EXEC)_debug
SRC= vec3d.c ray.c ppm.c raytracer.c objects/sphere.c objects/object.c
OBJ= $(SRC:.c=.o)

release: CFLAGS += -O2
release: $(OBJ)
	$(CC) -o $(EXEC) $^ $(LDFLAGS)

debug: CFLAGS += -DDEBUG -g -O0
debug: $(OBJ)
	$(CC) -o $(EXEC_DEBUG) $^ $(LDFLAGS)

ppm.o: vec3d.h ray.h
ray.o: vec3d.h
objects/sphere.o: vec3d.h ray.h
objects/object.o: objects/sphere.h


%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o objects/*.o

mrproper: clean
	rm -rf $(EXEC)
	rm -rf $(EXEC_DEBUG)
	rm output.ppm
