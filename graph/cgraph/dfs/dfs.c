#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#include <stdlib.h>
#include <stdio.h>

void __dfs(Agraph_t* G, Agnode_t* n, int* marks, GVC_t* gvc, FILE* dot)
{
    Agedge_t* e;
    *(marks+atoi(agget(n,"id"))) = 1;
    agsafeset(n,"color","red","");// CHANGE NODE COLOR TO BLUE
    gvLayout(gvc,G,"neato"); // NEW DOT WITH NODE COLOR CHANGED
    gvRender(gvc, G, "dot", dot); // NEW RENDER
    for(e=agfstedge(G,n);e;e=agnxtedge(G,e,n))
    {
        if(*(marks+atoi(agget(aghead(e),"id"))) == 0)
            __dfs(G,aghead(e),marks, gvc, dot);
    }
}


void dfs(Agraph_t* G, GVC_t* gvc, FILE* dot)
{
    Agnode_t *node;
    int *marks = calloc(sizeof(int*),agnnodes(G));
    memset(marks,0,agnnodes(G));
    printf("start dfs\n");
    //printf("id = %s\n",agget(n,"id"));
    for(node=agfstnode(G);node;node=agnxtnode(G,node))
    {
        if(*(marks+atoi(agget(node,"id"))) == 0)
        {
            gvLayout(gvc,G,"neato"); // NEW DOT WITH NODE COLOR CHANGED
            gvRender(gvc, G, "dot", dot); // NEW RENDER
            __dfs(G, node, marks, gvc, dot);
        }
    }
    gvLayout(gvc,G,"neato"); // NEW DOT WITH NODE COLOR CHANGED
    gvRender(gvc, G, "dot", dot); // NEW RENDER
    printf("end dfs\n");
    free(marks);
}

