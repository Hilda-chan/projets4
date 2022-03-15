// Adjascency List representation in C

#include <stdio.h>
#include <stdlib.h>
#include <graphviz/gvc.h>
#include <graphviz/cgraph.h>

// Create a node
struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a g
struct Graph* createGraph(int vertices)
{
    Agraph_t *Ag;
    Ag= agread("dot",NULL);
    struct Graph* g = malloc(sizeof(struct Graph));
    g->numVertices = vertices;

    g->adj = malloc(vertices * sizeof(struct node*));
    g->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        g->adj[i] = NULL;
        g->visited[i] = 0;
    }
    return g;
}

// Add edge
void addEdge(struct Graph* g, int s, int d)
{
    
    // Add edge from s to d
    struct node* newNode = createNode(d);
    struct node* cur = g->adj[s];
    struct node* prev;

    if(cur == NULL)
        g->adj[s] = newNode;
    else
    {
        while(cur->next && cur->vertex < d)
        {
            prev = cur;
            cur = cur->next;
        }
        if(cur->next == NULL && cur->vertex < d)
            cur->next = newNode;
        else if (cur->vertex > d)
        {
            prev->next = newNode;
            newNode->next = cur;
        }
    }
    // Add edge from d to s
     newNode = createNode(s);
     cur = g->adj[d];

    if(cur == NULL)
        g->adj[d] = newNode;
    else
    {
        while(cur->next && cur->vertex < s)
        {
            prev = cur;
            cur = cur->next;
        }
        if(cur->next == NULL && cur->vertex < s)
            cur->next = newNode;
        else if (cur->vertex > s)
        {
            prev->next = newNode;
            newNode->next = cur;
        }
    }
}

// Print the g
void printGraph(struct Graph* g) 
{
    int v;
    for (v = 0; v < g->numVertices; v++) 
    {
        struct node* temp = g->adj[v];
        printf("\n Vertex %d\n: ", v);
        while (temp) 
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

}

void free_graph(struct Graph* g)
{
    for (int v = 0; v < g->numVertices; v++)
    {
        struct node* temp = g->adj[v];
        while (temp)
        {
            struct node* tmp = temp->next;
            free(temp);
            temp = tmp;
        }
    }
    free(g->visited);
    free(g->adj);
    free(g);
}

