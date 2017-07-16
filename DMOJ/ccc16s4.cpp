#include <stdio.h>
#include <algorithm>

int n;
int pre[401];
bool dp[401][401];

int main(){
    scanf("%i", &n);
    int t, best=0;
    for(int i = 1; i <= n; i++){
        scanf("%i", &t);
        best = std::max(best, t);
        dp[i][i] = 1;
        pre[i] = t+pre[i-1];
    }
    for(int width = 1; width <= n-1; width++){
        for(int i = 1; i <= n-width; i++){
            for(int j = i; j <= i+width-1 && !dp[i][i+width]; j++){
                if (dp[i][j] && dp[j+1][i+width] && pre[j]-pre[i-1] == pre[i+width]-pre[j])
                    dp[i][i+width] = 1;
            }
            for(int j = i; j <= i+width-2 && !dp[i][i+width]; j++){
                for(int k = j+2; k <= i+width && !dp[i][i+width]; k++){
                    if(dp[i][j] && dp[k][i+width] && dp[j+1][k-1] && pre[j]-pre[i-1] == pre[i+width]-pre[k-1])
                        dp[i][i+width] = 1;
                }
            }
            if(dp[i][i+width]) best = std::max(best, pre[i+width]-pre[i-1]);
        }
    }
    printf("%i", best);
}