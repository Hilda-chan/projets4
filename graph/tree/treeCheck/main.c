#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include "isTree/IsTree.h"

int main(int argc, char** argv)
{
    if(argc != 2)
        err(1,NULL);

    Agraph_t* G;
    Agnode_t* node;
    GVC_t* gvc;
    Agsym_t* attr;
    FILE* fp;
    FILE* dot;
    int i;
    char str[50];

    dot = fopen("treeTest/dot2.dot","w");
    fp = fopen(argv[1],"r");
    G = agread(fp,0);
    gvc = gvContext(); // CREATE CONTEXT
    Agnode_t* n = agfstnode(G); //FIRST NODE
    attr = agattr(G,AGNODE,"id","0");
    i = 0;

    for(node = n;node;node=agnxtnode(G,node))
    {
        sprintf(str,"%d",i);
        agset(node,"id",str);
        i++;
    }

    printf("nb node = %d\n",agnnodes(G));
    int isCycle = IsCycle(G);
    printf("isCycle = %d\n",isCycle);
    int connexity = IsConnexe(G);
    printf("connexity = %d\n",connexity);
    printf("isCycle\n");
    if(isCycle != 0)
        err(1,"Your graph has cycle");
    printf("connexity\n");
    if(connexity != agnnodes(G))
        err(1,"Your graph is not connexe");
    //system("neato -Tpng dot2.dot -O");
    //system("convert -resize 768x576 -delay 50 -loop 1 *.png result.gif");
    //system("rm *.png");
    agclose(G);
    fclose(fp);
    fclose(dot);
    //system("eog result.gif");

    return 0;
}
