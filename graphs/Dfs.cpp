// DFS traversal from a given source vertex.
#include<iostream> 
#include<list> 
#include<stack>
using namespace std; 

// This class represents a directed graph using adjacency list representation 
class Graph{ 
	int V; // No. of vertices 
	list<int> *adj; // adjacency lists 
	
public: 
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int s);
}; 

Graph::Graph(int V){ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w){ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

void Graph::DFS(int s){ 
	// Initially mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false;
	stack<int> stack; 
	stack.push(s); // Push the current source node. 
	while (!stack.empty()){  
		s = stack.top(); 
		stack.pop(); 
		if (!visited[s]){ 
			cout << s << " "; 
			visited[s] = true; 
		} 

		// Get all adjacent vertices of the popped vertex s 
		// If a adjacent has not been visited, then push it to the stack.
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i) 
			if (!visited[*i]) 
				stack.push(*i); 
	} 
} 

int main(){ 
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
	cout << "Depth First Traversal (starting from selected vertex) is : "; 
	g.DFS(sel); 

	return 0; 
} 
