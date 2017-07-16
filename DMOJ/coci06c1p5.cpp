#include <iostream>
#include <algorithm>

using namespace std;

double cost[20][20];
double dp[1<<20] = {0};


int main(){
    int N;
    scanf("%i", &N);
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%lf", &cost[i][j]);
        }
    }
    for(int mask = 0; mask < (1<<N); mask++){
        int dude = __builtin_popcount(mask);
        for(int i =0; i < N; i++){
            if ((mask&(1<<i)) == 0){
                dp[mask|(1<<i)] = max(dp[mask|(1<<i)], dp[mask] * cost[dude][i]/100);
            }
        }
    }
    printf("%f", 100*dp[(1<<N)-1]);
}