#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, sa[3][150001], A[3][150001], dp[8][3][150001];

int solve(int mask, int cur, int i) {
	if (mask == 7)
		return sa[cur][N] - sa[cur][i - 1];
	if (i >= N)
		return 999999;
	if (dp[mask][cur][i] != -1)
		return dp[mask][cur][i];
	int a = 999999;
	for (int j = 0; j < 3; j++) {
		if (j == cur || (mask& (1 << j)) == 0) {
			a = min(a, A[cur][i] + solve(mask | (1 << j), j, i + 1));
		}
	}
	dp[mask][cur][i] = a;
	return a;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%i", &N);
	for (int i = 0; i < 3; i++) {
		sa[i][0] = 0;
		for (int j = 1; j < N + 1; j++) {
			scanf("%i", &A[i][j]);
			sa[i][j] = sa[i][j - 1] + A[i][j];
		}
	}
	int ans = 999999;
	for (int i = 0; i < 3; i++) {
		ans = min(ans, solve(1 << i, i, 1));
	}
	printf("%i", ans);
}