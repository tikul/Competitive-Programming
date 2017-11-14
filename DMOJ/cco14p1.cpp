#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int N, dp[2002], L[2002][2002], R[2002][2002];
char grid[2002][2002];

int main(){
    scanf("%i", &N);
    char x;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf(" %c", &grid[i][j]);
        }
    }
    //preprocess left
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j]=='.'){
                L[i][j] = 0;
                continue;
            }
            if(j == 0) L[i][j] = 1;
            else L[i][j] = 1+L[i][j-1];
        }
    }
    //preprocess right
    for(int i = 0; i < N; i++){
        for(int j = N-1; j >= 0; j--){
            if(grid[i][j]=='.'){
                R[i][j] = 0;
                continue;
            }
            if(j == N-1) R[i][j] = 1;
            else R[i][j] = 1+R[i][j+1];
        }
    }
    //dp
    memset(dp, 0, sizeof(dp));
    int tot = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int w = min(L[i][j], R[i][j]);
            if(w==0){
                dp[j] = 0;
            }else{
                int uw = min(dp[j], w-1);
                tot += uw+1;
                dp[j] = uw+1;
            }
        }
    }
    printf("%i", tot);
}