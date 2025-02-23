/*
	Implementa��o do algoritmo de Kosaraju
	Detecta componentes fortemente conectadas
*/

#include <iostream>
#include <stack>
#include <list>

using namespace std;

class Grafo
{
private:
	int V; // n�mero de v�rtices
	list<int> * adj; // lista de adjac�ncia

	void preenche(int v, bool visitados[], stack<int>& pilha)
	{
		// marca o v�rtice atual como visitado
		visitados[v] = true;

		// percorre os adjacentes de v
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); i++)
		{
			if(visitados[*i] == false)
				preenche(*i, visitados, pilha);
		}
		pilha.push(v);
	}

	// bem parecida com a fun��o preenche
	void DFS(int v, bool visitados[])
	{
		// marca o v�rtice atual como visitado
		visitados[v] = true;

		// imprime o v�rtice
		cout << v << " ";

		// percorre os adjacentes de v
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); i++)
		{
			if(visitados[*i] == false)
				DFS(*i, visitados);
		}
	}

public:

	// construtor
	Grafo(int V)
	{
		this->V = V;
		adj = new list<int>[V]; // cria as listas
	}

	// adiciona arestas
	void adicionarAresta(int i, int j)
	{
		// adiciona "j" � lista de adjac�ncia de "i"
		adj[i].push_back(j);
	}

	// obt�m o grafo transposto
	Grafo obterGrafoTransposto()
	{
		Grafo grafo_transposto(V);

		for(int v = 0; v < V; v++)
		{
			list<int>::iterator i;
			for(i = adj[v].begin(); i != adj[v].end(); i++)
			{
				// insere no novo grafo
				grafo_transposto.adj[*i].push_back(v);
			}
		}

		return grafo_transposto;
	}

	void imprimirComponentes()
	{
		stack<int> pilha;
		bool * visitados = new bool[V];

		// marca todos como n�o visitados
		for(int i = 0; i < V; i++)
			visitados[i] = false;

		// preenche a pilha
		for(int i = 0; i < V; i++)
		{
			if(visitados[i] == false)
				preenche(i, visitados, pilha);
		}

		// cria o grafo transposto
		Grafo gt = obterGrafoTransposto();

		// marca todos como n�o visitados novamente
		for(int i = 0; i < V; i++)
			visitados[i] = false;

		// processa os v�rtices de acordo com a pilha
		while(!pilha.empty())
		{
			// obt�m o elemento do topo
			int v = pilha.top();

			//remove o elemento
			pilha.pop();

			// imprime cada componente fortemente conexa
			if(visitados[v] == false)
			{
				gt.DFS(v, visitados);
				cout << "\n";
			}
		}
	}
};

int main(int argc, char *argv[])
{
	Grafo grafo(5);
	
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(1, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(2, 0);
	grafo.adicionarAresta(3, 4);
	
	
	grafo.imprimirComponentes();
	
	return 0;
}