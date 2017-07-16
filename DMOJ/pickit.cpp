#include <iostream>
#include <cstring>

int N, A[202], dp[202][202];

int solve(int i, int j){
    if (j < i)
        return 0;
    if (i == j)
        return dp[i][j]=(A[i-1]+A[i]+A[i+1]);
    if (dp[i][j] != -1)
        return dp[i][j];
    int best = 0;
    int temp;
    for(int last = i; last <= j; last++){
        temp = solve(i, last-1) + solve(last+1, j) + A[i-1] + A[last] + A[j+1];
        if (temp > best)
            best = temp;
    }
    return dp[i][j] = best;
}

int main(){
    scanf("%i", &N);
    while(N){
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < N; i++){
            scanf("%i", &A[i]);
        }
        int ans = solve(1, N-2);
        printf("%i\n", ans);
        scanf("%i", &N);
    }
}