#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, dp[1005][1005];
char x[1005], y[1005];

int solve(int i, int j){
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i > N || j > M)
        return 999999;
    if (i == N)
        return ceil((M-j)/3.0);
    if (j == M)
        return ceil((N-i)/3.0);
    if (x[i] == y[j])
        return dp[i][j] = solve(i+1, j+1);
    int best = 999999;
    best = min(best, 1+solve(i+1, j));
    best = min(best, 1+solve(i+2, j));
    best = min(best, 1+solve(i+3, j));
    best = min(best, 1+solve(i, j+1));
    best = min(best, 1+solve(i, j+2));
    best = min(best, 1+solve(i, j+3));
    best = min(best, 1+solve(i+1, j+1));
    return dp[i][j] = best;
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%i %i", &N, &M);
    scanf("%s", x);
    scanf("%s", y);
    printf("%i", solve(0, 0));
}