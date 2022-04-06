#ifndef BFS_H_
#define BFS_H_


#include <stdlib.h>
#include <stdio.h>
#include "queue/queue.h"
#include "bfs.h"
#include <graphviz/gvc.h>
#include <graphviz/cgraph.h>

void __bfs(Agraph_t* G, Agnode_t* n, int* marks, GVC_t* gvc, FILE* dot);
void bfs(Agraph_t* G,GVC_t* gvc, FILE* dot);


#endif
