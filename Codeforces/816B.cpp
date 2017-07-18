#include <stdio.h>
#include <cstring>
#include <algorithm>

int n, k, q;

int diff[200005], sa[200005];

int main(){
    scanf("%i%i%i", &n, &k, &q);
    memset(diff, 0, sizeof(diff));
    int l, r;
    for(int i = 0; i < n; i++){
        scanf("%i %i", &l, &r);
        diff[l]++;
        diff[r+1]--;
    }
    int cur = 0;
    sa[0] = 0;
    for(int i = 1; i <= 200000; i++){
        cur += diff[i];
        sa[i] = sa[i-1] + (cur>=k?1:0);
    }
    int a, b;
    for(int i = 0; i < q; i++){
        scanf("%i %i", &a, &b);
        printf("%i\n", sa[b]-sa[a-1]);
    }
}