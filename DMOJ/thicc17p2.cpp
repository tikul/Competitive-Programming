#include <cmath>
#include <stdio.h>
#define mod 1000000007

long long sum, n, b, m, a;

int main(){
    scanf("%i %i %i %i", &n, &a, &b, &m);
    int last = a;
    sum = a;
    for(int i = 1; i < n; i++){
        last = (1LL*last*b)%m;
        sum = (sum + last)%mod;
    }
    long long res = 0;
    int cur = a;
    for(int i = 0; i < n; i++){
        if(i) cur = ((1LL*cur*b)%m)%mod;
        long long x = sum-cur;
        if(x < 0) x += mod;
        res = (res + x*cur)%mod;
    }
    printf("%lli", res);

}