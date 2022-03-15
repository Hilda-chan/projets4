#ifndef GRAPH_H_
#define GRAPH_H_


struct node {
    int vertex;
    struct node* next;
};
struct node* createNode(int v);

struct Graph {
    int numVertices;
    int *visited;
    struct node** adj;
};


struct node* createNode(int v);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int s, int d);
void printGraph(struct Graph* graph);
void free_graph(struct Graph* graph);


#endif

