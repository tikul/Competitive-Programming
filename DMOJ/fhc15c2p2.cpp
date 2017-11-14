#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;

int T, ncr[30][30];
double P, dp[12350][21], prob[22], iprob[22];


int main(){
    ncr[0][0] = 1;
    for(int i = 1; i < 21; i++){
        for(int c = 0; c <= i; c++){
            if(c==0) ncr[i][c] = 1;
            else ncr[i][c] = ncr[i-1][c] + ncr[i-1][c-1];
        }
    }
    prob[0] = 1;
    iprob[0] = 1;
    scanf("%i", &T);
    for(int t = 1; t <= T; t++){
        scanf("%lf", &P);
        for(int i = 1; i <= 20; i++){
            iprob[i] = iprob[i-1]*(1-P);
            prob[i] = prob[i-1]*P;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        double ans = 0;
        for(int i = 1; i <= 12345; i++){
            for(int j = 0; j <= 20; j++){
                for(int k = 0; k <= j; k++){
                    if(k==20) continue;
                    dp[i][j] += dp[i-1][k]*ncr[20-k][j-k]*prob[j-k]*iprob[20-j];
                }
            }
            ans += i*dp[i][20];
            //printf("%i: %lf. ", i, dp[i][0]);
            //printf("%.10lf", dp[0][1]);
        }
        //printf("\n");
        printf("Case #%i: %lf\n", t, ans);
    }
}