#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;		//<distance, point>

const int N = 150010;

int n, m;
int dist[N];
bool state[N];

//邻接表实现图 
//head, element, width, next 
int h[N], e[N], w[N], ne[N], idx;
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;
	
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({0, 1});
	
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		
		int point = t.second, distance = t.first;
		if (state[point]) continue;
		state[point] = true;
		
		for (int it = h[point]; it != -1; it = ne[it])
		{
			int p = e[it];
			if (dist[p] > distance + w[it])
			{
				dist[p] = distance + w[it];
				heap.push({dist[p], p});
			}
		}
	}
	
	return (dist[n] == 0x3f3f3f3f ? -1 : dist[n]);
}

int main(void)
{
	scanf("%d %d", &n, &m);
	memset(h, -1, sizeof(h));
	
	while (m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		add(a, b, c);
	}
	
	printf("%d", dijkstra());
	
	return 0;
}
