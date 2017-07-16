#include <iostream>
#include <cstring>
#include <algorithm>

int cost[100000][4];
int dp[16][100000];
int N;

int solve(int mask,int act){
    if (act >= N || mask >= 16){
        return 0;
    }
    if (dp[mask][act] != -1){
        return dp[mask][act];
    }
    int a = 0;
    for(int place = 0; place < 4; place++){
        if (!(mask&(1<<place))){
            for(int i = act; i < N; i++){
                if (cost[i][place] != -1){
                    a = std::max(a, solve(mask|(1<<place), (N>90000?act:i)+1) + cost[i][place]);
                }
            }
        }
    }
    dp[mask][act] = a;
    return a;
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%i", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 4; j++){
            scanf("%i", &cost[i][j]);
        }
    }
    printf("%i", solve(0,0));
}