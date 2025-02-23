/*
    @autor: Toni Esteves;
    @data: 23/04/2023;
    @nome: Graph Cycle Detection;
    @description: Checks if a directed graph has cycle
 */

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

class Edge
{
	int vertex1, vertex2, weight;

public:

	Edge(int v1, int v2, int weight)
	{
		vertex1 = v1;
		vertex2 = v2;
		this->weight = weight;
	}

	int getVertex1()
	{
		return vertex1;
	}

	int getVertex2()
	{
		return vertex2;
	}

	int getWeight()
	{
		return weight;
	}

	// sobrescrita do operador "<"
	bool operator < (const Edge& edge2) const
	{
		return (weight < edge2.weight);
	}
};

class Graph
{

	int v;
	vector<Edge> edges;

public:

	Graph(int v)
	{
		this->v = v;
	}

	int findSet(int subset[], int v)
	{

		if(subset[v] == -1)
		{
			return v;
		}
		else
		{
			return findSet(subset, subset[v]);
		}
	}

	void unionAll(int subset[], int u, int v)
	{

		int u_set = findSet(subset, u);
		int v_set = findSet(subset, v);

		subset[u_set] = v_set;
	}


	// função que roda o algoritmo de Kruskal
	void kruskal()
	{
		vector<Edge> tree;
		int edge_quantity = edges.size();
		
		// aloca memória para criar "V" subconjuntos
		int * subset = new int[v];
		
		// inicializa todos os subconjuntos como conjuntos de um único elemento
		memset(subset, -1, sizeof(int) * v);

		for(int i; i < edge_quantity; i++)
		{
			int u = findSet(subset, edges[i].getVertex1());
			int v = findSet(subset, edges[i].getVertex2());

			if (v != u){
				// We don't have a cycle(belongs to MST) and push node in the vector
				tree.push_back(edges[i]);
				unionAll(subset, u, v);
			}
		}
		
		int tree_size = tree.size();
	}


};
//
//
// Graph::Graph(int v)
// {
//
// 	this->v = v;
// 	adj = new list<int>[v];
// }
//
// void Graph::addEdge(int v1, int v2)
// {
// 	adj[v1].push_back(v2);
// 	adj[v2].push_back(v1);
// }
//
// int Graph::findSet(int subset[], int v)
// {
//
// 	if(subset[v] == -1)
// 	{
// 		return v;
// 	}
// 	else
// 	{
// 		return findSet(subset, subset[v]);
// 	}
// }
//
// void Graph::unionAll(int subset[], int u, int v)
// {
//
// 	int u_set = findSet(subset, u);
// 	int v_set = findSet(subset, v);
//
// 	subset[u_set] = v_set;
// }
//
// void Graph::kruskal(int v)
// {
//
// 	vector<Edge> tree;
//
// }
//
// int main(int argc, char *argv[])
// {
//
// 	int num_nodes = 3;
//
// 	Graph graph(num_nodes);
//
// adicionando as arestas
// 	graph.addEdge(0, 1);
// 	graph.addEdge(1, 0);
// 	graph.addEdge(1, 2);
// 	graph.addEdge(2, 1);
// 	graph.addEdge(0, 2);
// 	graph.addEdge(2, 0);
//
// 	cout << "Grafo ok!";
//
// 	return 0;
// }
//
