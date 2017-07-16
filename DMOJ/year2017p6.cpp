#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define INF 1LL<<40

int N, a, b;
ll dp[5000][5000];
struct card{
    int cost;
    int val;
} cards[5000];

ll solve(int cur, int end){
    if (end >= N-1)
        return 0;
    if (cur > end)
        return INF;
    if (dp[cur][end] != -1)
        return dp[cur][end];
    ll best = solve(cur+1, end);
    best = std::min(best, cards[cur].cost+solve(cur+1, end+cards[cur].val));
    return dp[cur][end] = best;
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%i", &N);
    for(int i =0; i <N; i++){
        scanf("%i %i", &a, &b);
        cards[i].cost = a;
        cards[i].val = b;
    }
    ll ans = solve(0, 0);
    printf("%lli", ans);
}