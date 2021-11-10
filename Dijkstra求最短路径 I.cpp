#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int graph[N][N];
int dist[N];
bool state[N];

int dijkstra()
{
	memset(dist, 0x3f3f3f3f, sizeof(dist));
	dist[1] = 0;
	
	for (int i = 1; i <= n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!state[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
				
		state[t] = true;
		
		for (int j = 1; j <= n; j++)
			if (!state[j])
				dist[j] = min(dist[j], dist[t] + graph[t][j]);
	}
	
	return (dist[n] == 0x3f3f3f3f ? -1 : dist[n]);
}

int main(void)
{
	scanf("%d %d", &n, &m);
	memset(graph, 0x3f3f3f3f, sizeof(graph));
	while (m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = min(graph[a][b], c);
	}
	
	printf("%d", dijkstra());
	
	return 0;
}
