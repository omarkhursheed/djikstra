#include <iostream>
#include <cstdlib>

using namespace std;

#define MAXV  1000 
struct edgenode
{
    int y;
    int weight;
    struct edgenode *next;
};

struct graph
{
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    bool directed; 
};

void initialize_graph(graph *g, bool directed)
{
    int i;

    g -> nvertices = 0;
    g -> nedges = 0;
    g -> directed = directed;
    for (i = 1; i<=MAXV; i++) g -> degree[i] = 0;
    for (i = 1; i<=MAXV; i++) g -> edges[i] = NULL:
}

void read_graph(graph *g, bool directed)
{
    int i;
    int  m; 
    int x, y;

    initialize_graph(g, directed);
    cout << "Enter number of vertices"
}

int * djikstra(graph *g, int start)
{
    int i;
    edgenode *p;
    bool intree[MAXV + 1];
    int distance[MAXV + 1];
    int v; 
    int w;
    int weight;
    int dist;

    for(i = 1; i <= g->nvertices; i++)
    {
        intree[i] = FALSE;
        distance[i] = MAXINT;
        parent[i] = -1;
    }
    distance[start] = 0;
    v = start;

    while(intree[v] == FALSE)
    {
        intree[v] = TRUE;
        p = g->edges[v];
        while(p != NULL)
        {
            w = p->y;
            weight = p->weight;
            if (distance[w] > (distance[v] + weight))
            {
                distance[w] = distance[v] + weight;
                parent[w] = v;
            }
            p = p -> next;
        }

        v = 1;
        dist = MAXINT;
        for (i = 1; i <= nvertices; i++)
        {
            if((intree[i]==FALSE) && (dist > distance[i]))
            {
                dist = distance[i];
                v = i;
            }
        }
    }
    return distance;
}