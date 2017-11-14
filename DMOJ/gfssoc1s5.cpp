#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int R, C, S, B, K, M;
int dp[52][52][52][52];
int val[2502], cost[2502];
int snow[52][52];

int main(){
    memset(snow, -1, sizeof(snow));
    memset(dp, 0, sizeof(dp));
    scanf("%i %i %i %i %i %i", &R, &C, &S, &B, &K, &M);
    int t, v, c, r;
    for(int i = 0; i < S; i++){
        scanf("%i %i %i %i", &t, &v, &c, &r);
        cost[i] = t;
        val[i] = v;
        snow[r][c] = i;
    }
    for(int t = 1; t <= R; t++){
        for(int p = 1; p <= C; p++){
            if(p > t*M+1) continue;
            int x=0, y=0, s = snow[t][p];
            if(s != -1){
                x = val[s];
                y = cost[s];
            }
            int lo = max(1, p-M);
            int hi = min(t*M+1, min(C, p+M));
            for(int s = 1; s <= K; s++){
                for(int f = 0; f < B; f++){
                    for(int l = lo; l <= hi; l++){
                        dp[t][p][s][f] = max(dp[t][p][s][f], dp[t-1][l][s][f]);
                        if(f >= y){
                            dp[t][p][s][f] = max(dp[t][p][s][f], dp[t-1][l][s-1][f-y]+x);
                        }
                    }   
                }
            }

        }
    }
    int best = 0;
    for(int i = 1; i <= C; i++){
        for(int j = 1; j <= K; j++){
            for(int k = 0; k < B; k++){
                best = max(best, dp[R][i][j][k]);
            }
        }
    }
    printf("%i", best);
}