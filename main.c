#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph/dfs/Gdfs.h"
#include "graph/bfs/Gbfs.h"
#include "tree/dfs/Tdfs.h"
#include "tree/bfs/Tbfs.h"
#include "tree/treeCheck/isTree/IsTree.h"

int main(int argc, char **argv)
{
    if(argc != 4)
        return 1;


    // Graph init
    Agraph_t* G;
    Agnode_t* node;
    GVC_t* gvc;
    //Agsym_t* attr;
    FILE* fp;
    FILE* dot;
    int i;
    char str[50];
    int isGraph=0;
    int isDfs=0;

    dot = fopen("result/result.dot","w");
    fp = fopen(argv[3],"r");
    G = agread(fp,0);
    gvc = gvContext(); // CREATE CONTEXT
    Agnode_t* n = agfstnode(G); //FIRST NODE
    //attr = agattr(G,AGNODE,"id","0");
    agattr(G,AGNODE,"id","0");
    agattr(G,AGNODE,"color","black");
    agattr(G,AGRAPH,"bgcolor","white");
    i = 0;

    // Init node id
    for(node = n;node;node=agnxtnode(G,node))
    {
        sprintf(str,"%d",i);
        agset(node,"id",str);
        i++;
    }


    // Check arg 
    if (strcmp(argv[1], "-g") == 0)
        isGraph = 1;

    if (strcmp(argv[2], "-dfs") == 0)
        isDfs = 1;



    // Function call
    if(isGraph == 1)
    {
        if(isDfs == 1)
            Gdfs(G,gvc,dot);
        else
            Gbfs(G,gvc,dot);

        system("neato -Tpng result/result.dot -O");
    }

    else
    {
        if( IsConnexe(G) == 1 || IsCycle(G) == 1)
            return 1;

        if(isDfs == 1)
            Tdfs(G,gvc,dot);
        else
            Tbfs(G,gvc,dot);

        system("dot -Tpng result/result.dot -O");
    }


    // Transform dot file into gif
    system("convert -resize 768x576 -delay 100 -loop 1  $(ls -v result/*.png) result/result.gif");
    system("rm result/*.png");
    agclose(G);
    fclose(fp);
    fclose(dot);
    system("eog result/result.gif");


    return 0;
}
