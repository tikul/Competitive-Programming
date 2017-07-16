#include <iostream>
#include <algorithm>

#define MAX_RESTO 150
#define MAX_TIME 300
#define MAX_FOOD 100
int M, U, R, dp[MAX_RESTO+1][MAX_TIME+1][MAX_FOOD+1], resto[MAX_RESTO+1][3];

int main(){
    scanf("%i", &M);
    scanf("%i", &U);
    scanf("%i", &R);
    for(int i = 1; i <= R; i++){
        for(int j = 0; j < 3; j++){
            scanf("%i", &resto[i][j]);
        }
    }
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= M; j++){
            for(int k = 1; k <= U; k++){
                dp[i][j][k] = dp[i-1][j][k];
                if (resto[i][1] <= j && resto[i][2] <= k){
                    dp[i][j][k] = std::max(dp[i-1][j - resto[i][1]][k - resto[i][2]] + resto[i][0], dp[i][j][k]);
                }
            }
        }
    }
    printf("%i", dp[R][M][U]);
}