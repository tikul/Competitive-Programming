#include <stdio.h>
#include <cstring>
#define max(a,b) a>b?a:b

int n, x, cnt[2000001];

int main(){
    memset(cnt, 0, sizeof(cnt));
    scanf("%i", &n);
    if(n==1){
        printf("0");
        return 0;
    }
    for(int i = 0; i < n; i++){
        scanf("%i", &x);
        cnt[x]++;
    }
    long long ans = n;
    for(int i = 2; i <= 2000000; i++){
        long long f = 0;
        for(int j = i; j <= 2000000; j += i){
            f += cnt[j];
        }
        if(f >= 2) ans = max(ans, f*i);
    }
    printf("%lli", ans);
}