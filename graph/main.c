#include <stdlib.h>
#include <stdio.h>
#include "base/graph.h"
#include "dfs/dfs.h"
#include "bfs/bfs.h"

int main() {
/*    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);

    printGraph(graph);
    DFS(graph,2);
*/
    struct Graph* graph2 = createGraph(5);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 0, 2);
    addEdge(graph2, 1, 2);
    addEdge(graph2, 1, 4);
    addEdge(graph2, 1, 3);
    addEdge(graph2, 2, 4);
    addEdge(graph2, 3, 4);

    printGraph(graph2);
//    bfs(graph2, 0);
    
 //   free_graph(graph);
    free_graph(graph2);

    return 0;
}
