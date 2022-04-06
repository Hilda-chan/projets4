#ifndef DFS_H_
#define DFS_H_


#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#include <stdlib.h>
#include <stdio.h>



void __dfs(Agraph_t* G, Agnode_t* n, int* marks, GVC_t* gvc, FILE* dot);
void dfs(Agraph_t * G, GVC_t* gvc, FILE* dot);


#endif
