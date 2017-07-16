#include <stdio.h>
#include <algorithm>

#define inf 1<<30

int n, dp[20001][2], pos[20001][2];

int main(){
    scanf("%i", &n);
    for(int i = 0 ; i < n; i++){
        scanf("%i %i", &pos[i][0], &pos[i][1]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            dp[i][j] = inf;
        }
    }
    dp[0][1] = pos[0][1]-1;
    dp[0][0] = 2*dp[0][1]-pos[0][0]+1;
    for(int row = 1; row < n; row++){
        int l_prev = pos[row-1][0];
        int r_prev = pos[row-1][1];
        if (pos[row][1] <= l_prev){
            dp[row][0] = dp[row-1][0]+(l_prev-pos[row][0]);
            dp[row][1] = inf;
        }else if(pos[row][0] >= l_prev){
            dp[row][1] = dp[row-1][0]+(pos[row][1]-l_prev);
            dp[row][0] = inf;
        }else{
            dp[row][0] = dp[row-1][0]+(pos[row][1]-pos[row][0])+(pos[row][1]-l_prev);
            dp[row][1] = dp[row-1][0]+(pos[row][1]-pos[row][0])+(l_prev - pos[row][0]);
        }

        if (pos[row][1] <= r_prev){
            dp[row][0] = std::min(dp[row][0], dp[row-1][1]+(r_prev-pos[row][0]));
            dp[row][1] = std::min(inf, dp[row][1]);
        }else if(pos[row][0] >= r_prev){
            dp[row][1] = std::min(dp[row][1], dp[row-1][1]+(pos[row][1]-r_prev));
            dp[row][0] = std::min(dp[row][0], inf);
        }else{
            dp[row][0] = std::min(dp[row][0], dp[row-1][1]+(pos[row][1]-pos[row][0])+(pos[row][1]-r_prev));
            dp[row][1] = std::min(dp[row][1], dp[row-1][1]+(pos[row][1]-pos[row][0])+(r_prev-pos[row][0]));
        }
        //printf("%i %i\n", dp[row][0], dp[row][1]);
    }
    int ans = std::min(dp[n-1][0]+(n-pos[n-1][0]), dp[n-1][1] + (n-pos[n-1][1]));
    printf("%i", ans+(n-1));
}