#include <stdio.h>
#include <algorithm>
#define mod 1000000007

using namespace std;

int n, m, c[105];

long long modpow(int b, int e){
    if(e == 0) return 1;
    long long res = 1;
    for(int i = 0; i < e; i++){
        res = (res*b)%mod;
    }
    return res;
}

int main(){
    scanf("%i %i", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%i", c+i);
    }
    sort(c, c+n);
    long long ans = 0;
    for(int x = n-1, e=0; x >= 0; x -= m, e++){
        int t = max(0, x-m+1);
        for(int i = x; i >= t; i--){
            ans = (ans + modpow(c[i], e))%mod;
        }
    }
    printf("%lli", ans);
}