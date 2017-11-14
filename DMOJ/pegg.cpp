#include <stdio.h>
#include <cstring>

int T, N, K;
long long dp[33][33];

int main(){
    scanf("%i", &T);
    for(int i = 0; i <= 32; i++){
        dp[1][i] = i;
        dp[i][1] = 1;
    }
    for(int m = 2; m <= 32; m++){
        for(int n = 2; n <= 32; n++){
            dp[n][m] = dp[n-1][m-1] + dp[n][m-1] + 1;
        }
    }
    while(T--){
        scanf("%i %i", &N, &K);
        bool found = false;
        for(int i = 1; i <= 32; i++){
            if(dp[K][i] >= N){
                found = true;
                printf("%i\n", i);
                break;
            }
        }
        if(!found){
            printf("Impossible\n");
        }
    }

}