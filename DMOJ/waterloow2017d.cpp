#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define mod 1000000007
int dp[35][905], N, K;
int pt[50][50];
int lo[35];

int ncr(int n, int r){
    if(pt[n][r] != -1) return pt[n][r];
    if(r==0) return pt[n][r] = 1;
    if(r < 0 || r > n) return 0;
    return pt[n][r] = (ncr(n-1, r-1) + ncr(n-1, r))%mod;
}

int main(){
    scanf("%i %i", &N, &K);
    memset(pt, -1, sizeof(pt));
    memset(dp, 0, sizeof(dp));
    memset(lo, 0, sizeof(lo));
    lo[0] = 0;
    lo[1] = 1;
    for(int i = 2; i <= 36; i++){
        int m = i/2;
        lo[i] = i+lo[m]+lo[i-1-m];
    }
    dp[0][0] = 1;
    for(int n = 1; n <= N; n++){
        int to = min(K, n*(n+1)/2);
        for(int k = lo[n]; k <= to; k++){
            for(int i = 1; i <= n; i++){
                int big = n-i;
                int small = i-1;
                for(int j = 0; j <= k-n;j++){
                    dp[n][k] = (dp[n][k]+(((1LL*ncr(n-1, big)*dp[big][j])%mod)*dp[small][k-n-j])%mod)%mod;
                }
            }
        }
    }
    printf("%i", dp[N][K]);
}