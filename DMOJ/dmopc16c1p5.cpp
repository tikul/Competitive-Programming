#include <stdio.h>
#include <algorithm>

int n, bit[500005];

void update(int x){
    for(; x <= n; x += x&-x){
        bit[x]++;
    }
}

int query(int x){
    int ret=0;
    for(; x > 0; x -= x&-x){
        ret += bit[x];
    }
    return ret;
}

int main(){
    scanf("%i", &n);
    int x;
    long long ans=0;
    for(int i = 0; i < n; i++){
        scanf("%i", &x);
        int a = query(x);
        int b = query(n);
        ans += std::min(a, b-a);
        update(x);
    }
    printf("%lli", ans);
}