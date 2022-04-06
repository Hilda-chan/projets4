CC=gcc
CPPFLAGS=
CFLAGS=-Wall -Wextra -pedantic -std=c99 -g `pkg-config libgvc --cflags`
LDLIBS=-lasan
LDFLAGS=`pkg-config  libgvc --cflags` -lcgraph -lgvc
EXEC= prog

SRC= bfs.c main.c queue/queue.c
OBJ= ${SRC:.c=.o}

all: ${EXEC}

${EXEC}: ${OBJ}

prog:${OBJ}
	${CC} $^ -o prog $(CFLAGS) $(LDFLAGS)


clean:
	${RM} prog
	${RM} *.o
	${RM} *.gif
	${RM} bfsTest/*.png
	${RM} queue/*.o
