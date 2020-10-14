#include <iostream>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

typedef struct nodes
{
    int dest;
    int cost;
} node;

class Graph
{
public:
    int n;
    list<node> *adjList;

    void showList(int src, list<node> lt)
    {
        list<node>::iterator i;
        node tempNode;

        for (i = lt.begin(); i != lt.end(); i++)
        {
            tempNode = *i;
            cout << "(" << src << ")---(" << tempNode.dest << "|" << tempNode.cost << ") ";
        }
        cout << endl;
    }

    Graph(int nodeCount)
    {
        n = nodeCount;
        adjList = new list<node>[n];
    }

    void addEdge(int source, int dest, int cost)
    {
        node newNode;
        newNode.dest = dest;
        newNode.cost = cost;
        adjList[source].push_back(newNode);
    }

    void displayEdges()
    {
        for (int i = 0; i < n; i++)
        {
            list<node> tempList = adjList[i];
            showList(i, tempList);
        }
    }

    friend void dijkstra(Graph g, int *dist, int *prev, int start);
};

void dijkstra(Graph g, int *dist, int *prev, int start, int stops){
    int k = stops;
    int n = g.n;
    bool *checked = new bool[n];

    for (int u = 0; u < n; u++)
    {
        dist[u] = 9999; //set as infinity
        prev[u] = -1;   //undefined previous
        checked[u] = false;
    }

    dist[start] = 0; //distance of start is 0
    set<int> S;      //create empty set S
    list<int> Q;

    for (int u = 0; u < n; u++)
    {
        Q.push_back(u); //add each node into queue
    }

    while (!Q.empty() && k >= 0)
    {
        list<int>::iterator i;
        i = min_element(Q.begin(), Q.end());
        int u = *i; //the minimum element from queue
        Q.remove(u);
        S.insert(u); //add u in the set
        list<node>::iterator it;

        for (it = g.adjList[u].begin(); it != g.adjList[u].end(); it++)
        {
            if ((dist[u] + (it->cost)) < dist[it->dest])
            { //relax (u,v)
                dist[it->dest] = (dist[u] + (it->cost));
                prev[it->dest] = u;    
                if (!checked[u])
                {
                    checked[u] = true;
                    k--;
                }
            }
        }
    }
}

int main()
{
    int from, to, wt;
    int n, source, stops; //stops: optional if only an given number of nodes wanted in the output
    cout << "Enter number of vertices: ";
    cin >> n;
    Graph g(n);
    int dist[n], prev[n];
    cout << "\nEnter edges (-1, -1, -1) to stop:" << endl;

    while (1)
    {
        cout << "(From, to, weight): ";
        cin >> from >> to >> wt;
        if (from != -1 && to != -1 && wt != -1)
            g.addEdge(from, to, wt);
        else
            break;
    }

    cout << "\nEnter source vertex: ";
    cin >> source;
    cout << "\nEnter number of stops: ";
    cin >> stops;
    cout << endl;

    dijkstra(g, dist, prev, source, stops);

    for (int i = 0; i < n; i++)
        if (i != source)
            cout << source << " to " << i << ", Cost: " << dist[i] << " Previous: " << prev[i] << endl;
            
    return 0;
}
