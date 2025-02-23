#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

#define ARR_SIZE 100001

vector<int> graph[ARR_SIZE];
bool visited[ARR_SIZE];

long long t, n, m, b, e, x, y;
long long cost, c;

int DFS(int v, bool visited[])
{

	visited[v] = 1;
	vector<int>::iterator it;

	for (it = graph[v].begin(); it != graph[v].end(); ++it)
	{
		if (!visited[*it])
		{
			DFS(*it, visited);
		}
	}

	return 1;
};

int getNumberOfconnectedComponents(int n)
{

	int count = 0;

	for (int v = 0; v < n; v++)
	{
		if (visited[v] == 0)
		{
			count += DFS(v, visited);
		}
	}

	return count;
};

int main(int argc, char** argv)
{
	cin >> t;

	while(t--)
	{

		cin >> n >> m >> b >> e;

		for (int v = 0; v < n; v++)
		{
			graph[v].clear();
			visited[v] = 0;
		}

		while(m--)
		{
			x = 0;
			y = 0;

			cin >> x >> y;

			graph[x - 1].push_back(y - 1);
			graph[y - 1].push_back(x - 1);
		}

		if(b <= e)
		{
			cout << (b*n) << endl;
		}
		else
		{
			c = 0;
			cost = 0;

			c = getNumberOfconnectedComponents(n);

			cost = ((c * b) + ((n - c) * e));

			cout << cost << endl;

		}

	}

	return 0;
}