#include <string.h>
#include <iostream>
#include <list>
#include <queue>

#define ARR_SIZE 10000
#define INF 10000000
#define EDGE_COST 1

using namespace std;

vector<vector<int > > graph;
vector<int> distances;

int reverse(int i)
{
	int aux = 0;

	while (i)
	{
		aux *= 10;
		aux += i % 10;
		i /= 10;
	}
	return aux;
}

void dijkstra(int source)
{
	distances.assign(ARR_SIZE, INF);
	distances[source] = 0;

	priority_queue < pair<int, int>,
				   vector<pair<int, int> >,
				   greater<pair<int, int> > > pq;

	pq.push(make_pair(distances[source], source));


	while(!pq.empty())
	{
		pair<int, int> p = pq.top();
		int u = p.second;
		pq.pop();

		if (u < ARR_SIZE)
		{
			for(int i = 0 ; i < graph[u].size(); ++i)
			{
				int adj_vertex = graph[u][i];
				int next_vertex = p.first;

				// relax(u,v)
				if (adj_vertex < ARR_SIZE - 1 && (distances[adj_vertex] > next_vertex + EDGE_COST))
				{
					distances[adj_vertex] = next_vertex + EDGE_COST;
					pq.push(make_pair(distances[adj_vertex], adj_vertex));
				}
			}
		}
	}
};

int main(int argc, char** argv)
{
	int test_cases;

	int s, t;

	graph.assign(ARR_SIZE, vector<int>());

	for (int i = 0 ; i < ARR_SIZE; ++i)
	{
		graph[i].push_back(i + 1);
		graph[i].push_back(reverse(i));
	}

	cin >> test_cases;

	while (test_cases--)
	{
		cin >> s >> t;
		dijkstra(s);

		cout << distances[t] << endl;
		distances.clear();
	}
	return 0;
}
