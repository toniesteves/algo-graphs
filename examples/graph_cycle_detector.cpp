/*
    @autor: Toni Esteves;
    @data: 23/04/2023;
    @nome: Graph Cycle Detection;
    @description: Checks if a directed graph has cycle
 */

#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
	int v;
	list<int> *adj;


public:
	Graph(int v);

	void addEdge(int v1, int v2);

	//; Finds a cycle from some source(node)
	bool dfs(int s);

	// Check if the graph has cycle
	bool hasCycle();

};


Graph::Graph(int v){

	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v1, int v2)
{
	adj[v1].push_back(v2);
	// adj[v2].push_back(v1); // If we need a not direct graph
}

bool Graph::dfs(int v){
	stack<int> stck;
	bool visited[v], stack_rec[v];

	for(int i = 0; i < v; i++){
		visited[i] = stack_rec[i] = false;
	}

	while(true){

		bool find_kneighbor = false;
		list<int>::iterator it;

		if(!visited[v]){
			stck.push(v);
			visited[v] = stack_rec[v] = true;
		}

		for(it = adj[v].begin(); it != adj[v].end(); it++){
			
			// If neighbor is int the stack we have a cycle.
			if(stack_rec[*it]){
				return true;
			}
			// If neighbor isn't int the stack we find a neighbor.
			else if(!visited[*it]){ 
				find_kneighbor = true;
				break;
			}
		}
		
		if(!find_kneighbor){
			stack_rec[stck.top()] = false; // flag vertex as removed from stack.
			stck.pop();					   // remove vertex from stack.
			if(stck.empty()){
				break;
			}
			
			v = stck.top();
		}else{
			v = *it;
		}		
	}

	return false;
	
}

int main(int argc, char *argv[])
{
	
	int num_nodes = 4;

	Graph graph(num_nodes);

	// adicionando as arestas
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 3);
	graph.addEdge(3, 0);

	if(graph.dfs(0)){
		cout << "The Graph has Cycle!\n";
	}
	else{
		cout << "The Graph hasn't Cycle!\n";
	}

	return 0;
}	
