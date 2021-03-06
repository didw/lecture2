// 8_bfs.c
// 너비 우선 탐색 ( Breadth First Search )
// 1. 시작 정점을 "방문했음"으로 표시하고, 시작 정점을 큐에 삽입한다.
// 2. 큐로 부터 정점을 제거하고, 제거한 정점의 인접 정점 중 아직 방문하지 않은 정점을
//    "방문했음"으로 표시하고, 큐에 삽입한다.
// 3. 큐가 빌 때까지 반복한다.

#include "queue.h"
/*
7 16
0 1
0 2
0 6
0 3
1 0
1 4
1 2
2 0
2 1
2 5
3 0
4 1
5 2
5 6
6 0
6 5
*/
typedef struct _node
{
	int vertex;
	struct _node *next;
} node;

node *adj[100];
int visited[100];
int n;

void bfs(int i)
{
	node *t;
	int j;
	init_queue();

	put(i);
	visited[i] = 1;
	// visit(i);
	printf("%c\n", (char)(i + 'A'));

	// 1. 큐가 차있는 동안에
	// 2. 큐에서 값을 꺼낸다.
	// 3. 해당 정점과 인접한 정점들 중 방문하지 않은 정점들을 "방문했음"으로 표시하고
	//    큐에 추가한다.
	// 4. "방문했음"이라 함은 화면에 해당 정점을 출력하는 것을 의미한다.
	while (!is_empty())
	{
		j = get();
		for (t = adj[j]; t != NULL; t = t->next)
		{
			if (visited[t->vertex] == 0)
			{
				put(t->vertex);
				visited[t->vertex] = 1;
				printf("%c\n", (char)(t->vertex + 'A'));
			}
		}
	}
}

// 가중치가 없는 그래프에서의 최단 거리는
// 간선의 수를 말한다.
// 가중치가 없는 그래프에서의 최단 거리는 너비 우선 탐색만으로 해결할 수 있다.
int dist[100];
int parent[100];

void bfs2(int i)
{
	node *t;
	int j;
	init_queue();

	for (i = 0; i < n; i++)
	{
		dist[i] = -1;
		parent[i] = -1;
	}
	i = 0;
	put(i);
	dist[i] = 0;
	parent[i] = i;

	while (!is_empty())
	{
		j = get();
		for (t = adj[j]; t != NULL; t = t->next)
		{
			if (dist[t->vertex] == -1)
			{
				put(t->vertex);
				dist[t->vertex] = dist[j] + 1;	// 최단 경로 거리값
				parent[t->vertex] = j;			// 부모를 역추적하기 위한 값
			}
		}
	}
}

// 루트부터 u정점에 최단 경로를 구하는 함수
int path[100];
// A - B - C
// C - B - A
void shortest_path(int u)
{
	int idx = 0;
	int i;
	path[idx++] = u;
	printf("최단 거리 : %d\n", dist[u]);
	while (parent[u] != u)
	{
		u = parent[u];	// 자신의 부모를 찾는다. 자신이 부모가 될때까지
		path[idx++] = u;
	}

	for (i = idx - 1; i >= 0; i--)
		printf("%c\n", (char)(path[i] + 'A'));
}

int main()
{
	int i, j, k;
	int a = 0, b = 0;
	node *t, *s;
	scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &a, &b);
		t = (node*)malloc(sizeof(node));

		// 인접리스트를 만들어 보세요.
		// 1. t->vertex값에 b를 입력하고
		// 2. t->next 는 null 초기화
		t->vertex = b;
		t->next = NULL;

		s = adj[a];
		// 1. s == null이면 
		if (s == NULL)
			adj[a] = t;
		// adj[a] = t;
		// 2. s != null이면
		else
		{
			// 기존의 인접 정점이 있다는 의미기 때문에
			// loop를 돌면서, insert_back 실행
			// 리스트의 마지막에 새로운 정점을 추가한다.
			while (s->next != NULL)
			{
				s = s->next;
			}
			s->next = t;
		}
	}
	// 너비 우선 탐색 호출
	bfs2(0);
	shortest_path(4);
}