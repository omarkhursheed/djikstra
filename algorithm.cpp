#include <iostream>
#include <cstdlib>

using namespace std;

#define MAXV  1000 
#define MAXINT 65555
int parent[MAXV + 1] = {-1};



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
    for (i = 1; i<=MAXV; i++) g -> edges[i] = NULL;
}

void insert_edge(graph *g, int x, int y, int weight, bool directed)
{
    edgenode *p;
    p = new edgenode;
    p -> weight = weight;
    p -> y = y;
    p -> next = g -> edges[x];

    g -> edges[x] = p;
    g -> degree[x]++;
    if (directed == false)
    {
        insert_edge(g, y, x, weight, true);
    }
    else
    {
        g -> nedges++;
    }
}


void read_graph(graph *g, bool directed)
{
    int i;
    int  m; 
    int x, y;
    int weight;
    initialize_graph(g, directed);
    cout << "Enter number of vertices";
    cin >> g ->  nvertices;
    cout << "Enter number of edges";
    cin >> m;
    for (i = 1; i <= m; i++)
    {
        cout << "Enter the vertex from: ";
        cin >> x;
        cout << "Enter the vertex to: ";
        cin >> y;
        cout << "Enter the weight of the edge: ";
        cin >> weight;
        insert_edge(g, x, y, weight, directed);
    }
}


void print_graph(graph *g)
{
    int i;
    edgenode *p;
    cout << "Vertex\tConnected " << endl;
    for (i = 1; i <= g->nvertices; i++)
    {
        cout << i << "\t";
        p = g -> edges[i];
        while (p != NULL)
        {
            cout << p->y << "\t" ;
            p = p -> next;
        }
        cout << endl;
    }
}

void find_path(int start, int end, int parents[])
{
    if ((start == end) || (end == -1))
        cout << endl << start;
    else
    {

        find_path(start,parents[end],parents);
        cout << " " << end;
    }
}

void djikstra(graph *g, int start)
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
        intree[i] = false;
        distance[i] = MAXINT;
        parent[i] = -1;
    }
    distance[start] = 0;
    v = start;

    while(intree[v] == false)
    {
        intree[v] = true;
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
        for (i = 1; i <= g->nvertices; i++)
        {
            if((intree[i]==false) && (dist > distance[i]))
            {
                dist = distance[i];
                v = i;
            }
        }
    }
    
}

int main(int argc, char const *argv[])
{
    graph g;
    int start;
    int end;
    read_graph(&g, false);
    print_graph(&g);
    cout << "Enter the node from which to start: ";
    cin >> start;
    cout << "Enter the destination node: ";
    cin >> end;
    djikstra(&g,start);

    if (parent[end] == -1 && start != end)
    {
        cout << "Path does not exist";
    }
    else
    {
        cout << "Path from " << start << " to " << end << ":";

        find_path(start,end,parent);
    }
    return 0;
}