#include <iostream>
#include <algorithm>
#include <cstring>

int N, seq[1001], dp[1001][1001];

int solve(int i,int j){
    if (j > N)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int a = solve(i, j+1);
    if (seq[j] > seq[i]){
        a = std::max(a, seq[j]+solve(j, j+1));
    }
    dp[i][j] = a;
    return dp[i][j];
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%i", &N);
    for(int i = 1; i < N+1; i++){
        scanf("%i", &seq[i]);
    }
    seq[0] = 0;
    printf("%i", solve(0,1));
}