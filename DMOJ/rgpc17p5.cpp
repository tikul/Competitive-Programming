#include <stdio.h>
#include <algorithm>

using namespace std;

char A[10005], B[10005];
int n, m, dp[3][10005], ans=0;
int main(){
    scanf("%i%i", &n, &m);
    scanf("%s", A);
    scanf("%s", B);
    for(int i = 0; i <= n; i++)
        dp[0][i] = i;
    
    for(int i = 1; i <= m; i++){
        dp[1][0] = i;
        for(int j = 1; j <= n; j++){
            if(A[j-1] == B[i-1]){
                dp[1][j] = dp[0][j-1];
            }else{
                int best = dp[0][j-1];
                best = min(best, dp[0][j]);
                best = min(best, dp[1][j-1]);
                dp[1][j] = 1+best;
            }
            if(j == n && i != m)
                ans += dp[1][j];
        }
        for(int j = 0; j <= n; j++){
            dp[0][j] = dp[1][j];
        }
    }
    printf("%i\n", ans);
}