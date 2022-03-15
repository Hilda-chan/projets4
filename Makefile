CC=gcc
CPPFLAGS=
CFLAGS=-Wall -Wextra -pedantic -std=c99 -Igraph
LDFLAGS=
LDLIBS=
EXEC= prog

SRC= graph/graph.c
SRC2= 
OBJ= ${SRC:.c=.o}
OBJ2= ${SRC2:.c=.o}

all: ${EXEC}

${EXEC}: ${OBJ}




clean:
	${RM} graph/prog
	${RM} graph/*.o
