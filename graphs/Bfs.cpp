// BFS traversal from a given source vertex
#include<iostream> 
#include<list> 

using namespace std; 

// This class represents a directed graph using adjacency list representation
class Graph 
{ 
	int V; // No. of vertices 
	list<int> *adj; //adjacency lists

public: 
	Graph(int V);
	void addEdge(int v, int w); 
	void BFS(int s); 
}; 

Graph::Graph(int V){ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w){ 
	adj[v].push_back(w); // Add w to v�s list. 
} 

void Graph::BFS(int s) 
{ 
	// Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
	list<int> queue; 
	visited[s] = true; // Mark the current node as visited and enqueue it
	queue.push_back(s); 
	//list<int>::iterator i; 
	while(!queue.empty()){ 
		// Dequeue a vertex from queue and print it 
		s = queue.front(); 
		cout << s << " "; 
		queue.pop_front(); 

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited, 
		// then mark it visited and enqueue it 
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i){ 
			if (!visited[*i]){ 
				visited[*i] = true; 
				queue.push_back(*i); 
			} 
		} 
	} 
} 

int main() 
{ 
	int sel, choice, from, to, vert;
	cout << "Enter number of vertices: ";
	cin >> vert;
	Graph g(vert); 
	cout << "Enter edges in given format (-1 in both to exit)\n";
	while(1){
		cout << "(From, to): ";
		cin >> from >> to;
		if(from != -1 && to != -1)
			g.addEdge(from, to);
		else
			break;
	}
	cout << "Enter vertex to be selected as starting vertex: ";
	cin >> sel;
	cout << "Breadth First Traversal (starting from selected vertex) is : "; 
	g.BFS(sel);  

	return 0; 
} 
