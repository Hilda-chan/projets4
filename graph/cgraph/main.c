#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#include <stdlib.h>
#include <stdio.h>



void __dfs(Agraph_t* G, Agnode_t* n, int* marks, GVC_t* gvc, FILE* dot)
{
    Agedge_t* e;
    *(marks+atoi(agget(n,"id"))) = 1;
    printf("id = %s\n",agget(n,"id"));
    agsafeset(n,"color","blue","");// CHANGE NODE COLOR TO BLUE
    gvLayout(gvc,G,"dot"); // NEW DOT WITH NODE COLOR CHANGED
    gvRender(gvc, G, "dot", dot); // NEW RENDER
    for(e=agfstedge(G,n);e;e=agnxtedge(G,e,n))
    {
        if(*(marks+atoi(agget(aghead(e),"id"))) == 0)
            __dfs(G,aghead(e),marks, gvc, dot);
    }
}


void dfs(Agraph_t * G, GVC_t* gvc, FILE* dot)
{
    Agnode_t *node;
    int *marks = calloc(sizeof(int*),agnnodes(G));
    memset(marks,0,agnnodes(G));
    printf("start dfs\n");
    //printf("id = %s\n",agget(n,"id"));
    for(node=agfstnode(G);node;node=agnxtnode(G,node))
    {
        //printf("id = %s\n marks = %d\n",agget(node,"id"),*(marks+atoi(agget(node,"id"))));
        if(*(marks+atoi(agget(node,"id"))) == 0)
            __dfs(G, node, marks, gvc, dot);
    }
    printf("end dfs\n");
    free(marks);
}



int main()
{
    Agraph_t* G;
    Agnode_t* node;
    GVC_t* gvc;
    FILE* fp;
    FILE* output = fopen("img.png","w");
    FILE* dot = fopen("dot2.dot","w");
    FILE* gif = fopen("result.gif","w");


    printf("start\n");
    fp = fopen("dot.dot","r");
    G = agread(fp,0);
    gvc=gvContext(); // CREATE CONTEXT
    Agsym_t* attr;
    Agsym_t* attr2;
    attr = agattr(G,AGNODE,"color","black");// SET DEFAULT NODE COLOR
    attr2 = agattr(G,AGNODE,"id","0");
    Agnode_t* n = agfstnode(G); //FIRST NODE
    
    gvLayout(gvc,G,"dot"); // NEW DOT WITH NODE COLOR CHANGED
    gvRender(gvc, G, "dot", dot); // NEW RENDER
    gvFreeLayout(gvc, G);

    gvLayout (gvc, G, "neato"); // NEW LAYOUT FOR PNG
    gvRender (gvc, G, "png", output);
    gvFreeLayout(gvc, G);

    int i = 0;
    char str[50];

    //printf("set id : \n");
    //printf("n id : %s\n",agget(n,"id"));

    for(node = n;node;node=agnxtnode(G,node))
    {
        sprintf(str,"%d",i);
        agset(node,"id",str);
        //printf("name :%s\n",agget(node,"id"));
        //printf("marks = %s\n",marks);
        i++;
    }
    //agsafeset(n,"color","blue","");// CHANGE NODE COLOR TO BLUE
  //  gvLayout(gvc,G,"dot"); // NEW DOT WITH NODE COLOR CHANGED
//    gvRender(gvc, G, "dot", dot); // NEW RENDER
    gvFreeLayout(gvc, G);

    gvLayout (gvc, G, "neato"); // NEW LAYOUT FOR PNG
    gvRender (gvc, G, "png", output);
    //gvRenderFilename (gvc, G, "gif", "dot2.dot");
    gvFreeLayout(gvc, G);

    //printf("dfs :\n");
    //printf("atoi(): %d\n",atoi("1"));
    dfs(G,gvc,dot);
    system("dot -Tpng dot2.dot -O");
    fclose(fp);
    fclose(gif);
    fclose(dot);
    fclose(output);
    agclose(G);
    return 0;
}




/*








 */
