#include <stdlib.h>
#include <stdio.h>
#include "queue/queue.h"
#include "bfs.h"
#include <graphviz/gvc.h>
#include <graphviz/cgraph.h>
#include <err.h>


int main(int argc, char **argv)
{
    argc = argc;
    if(argc != 2)
        err(1,NULL);
    
    FILE* dot;
    FILE* fp;

    int i;
    char str[50];

    Agraph_t* G;
    Agnode_t* n;
    Agnode_t* node;
    Agsym_t* attr;
    Agsym_t* attr2;
    Agsym_t* attr3;

    GVC_t* gvc;

    dot = fopen("bfsTest/dot2.dot","w");
    fp = fopen(argv[1],"r");
    G = agread(fp,0);
    gvc = gvContext(); // CREATE CONTEXT
    n = agfstnode(G); //FIRST NODE
    attr = agattr(G,AGNODE,"id","0");
    attr2 = agattr(G,AGNODE,"color","black");
    attr2 = agattr(G,AGRAPH,"bgcolor","white");
    i = 0;
    for(node = n;node;node=agnxtnode(G,node))
    {
        sprintf(str,"%d",i);
        agset(node,"id",str);
        i++;
    }

    bfs(G,gvc,dot);
    system("neato -Tpng bfsTest/dot2.dot -O");
    system("convert -resize 768x576 -delay 50 -loop 1 'bfsTest/dot2.dot.%d.png[0-17]' result.gif");
    system("rm bfsTest/*.png");
    fclose(fp);
    fclose(dot);
    agclose(G);
    system("eog result.gif");

    return 0;
}
