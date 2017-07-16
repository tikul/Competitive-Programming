#include <iostream>
#include <algorithm>
#include <cstring>

int N, M, dp[1 << 18][18];

struct edge {
	int a;
	int b;
	int weight;
} edges[320];

using namespace std;

int main() {
	memset(dp, -1, sizeof(dp));
	dp[1][0] = 0;
	scanf("%i %i", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%i %i %i", &edges[i].a, &edges[i].b, &edges[i].weight);
	}
	int u, v, w, k, best{ 0 };
	bool changed;
	for (int i = 0; i < N - 1; i++) {
	    changed = false;
		for (int j = 0; j < M; j++) {
			u = edges[j].a;
			v = edges[j].b;
			w = edges[j].weight;
			for (int z = 0; z < (1 << (N-1)); z++) {
				k = (z << 1) | 1;
				if ((k&(1 << u)) != 0 && (k&(1 << v)) == 0 && dp[k][u] != -1) {
					if (dp[k][u] + w > dp[k | (1 << v)][v]) {
						changed = true;
						dp[k | (1 << v)][v] = dp[k][u] + w;
						if (v == N - 1) {
							best = max(best, dp[k | (1 << v)][v]);
						}
					}
				}
			}
		}
		if (!changed)
			break;
	}
	printf("%i\n", best);
}