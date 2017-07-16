#include <iostream>
#include <deque>
#include <vector>
#include <cstring>

using namespace std;

int res[205][205];
int parent[205];
vector<int> conn[205];
bool valid[105];
int N, M, t, a, best, possible;
int u, v;

bool is_path() {
	bool visited[205];
	memset(visited, 0, sizeof(visited));
	deque<int> q;
	q.push_back(1);
	while (!q.empty()) {
		u = q.front();
		q.pop_front();
		for (int v : conn[u]) {
			if (!visited[v] && res[u][v] > 0) {
				q.push_back(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
	return visited[203];
}

int main()
{
	scanf("%i %i", &N, &M);
	scanf("%i", &t);
	possible = t;
	for (int i = 0; i < t; i++) {
		scanf("%i", &a);
		valid[a] = true;
	}
	for (int i = N + 1; i <= M + N; i++) {
		conn[i].push_back(203); //203 is sink
		res[i][203] = 1;
	}
	for (int i = 2; i <= N; i++) {
		conn[1].push_back(i);
		res[1][i] = 1;
		scanf("%i", &t);
		for (int j = 0; j < t; j++) {
			scanf("%i", &a);
			if (valid[a]) {
				res[i][N+a] = 1;
				conn[i].push_back(N+a);
				conn[N + a].push_back(i);
			}
		}
	}
	while (is_path()) {
		best++;
		v = 203;
		while (v != 1) {
			u = parent[v];
			res[u][v]--;
			res[v][u]++;
			v = u;
		}
	}
	printf("%i", possible-best);
}